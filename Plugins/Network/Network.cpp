//
// Created by youba on 29/10/2023.
//

#include "Network.hpp"
#include <iostream>
#include "zlib.h"
#include "json/json.h"
#include "Core.hpp"

Network::Network(unsigned int port, unsigned int latence, float timeout, const std::string &user, Uniti::Core &core) :
        _socketUDP(this->_ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)),
        _latence(latence),
        _port(port),
        _queue(10000),
        _user(user),
        _core(core),
        _timeout(timeout),
        _buffer(50000) {
    if (this->_user.empty())
        this->_user = "User" + this->_socketUDP.local_endpoint().address().to_string() + ":" +
                      std::to_string(this->_socketUDP.local_endpoint().port());
    this->_core.log().Warn("Your port is : " + std::to_string(this->_socketUDP.local_endpoint().port()));
    this->_core.log().Warn("Your id for network is : " + this->_user);
}

Network::~Network() {
    this->_ioService.stop();
    if (this->_ioThread.joinable())
        this->_ioThread.join();
}

void Network::start() {
    this->startReceive();
    this->_ioThread = std::thread([](boost::asio::io_context &ioContext) {
        ioContext.run();
    }, std::ref(this->_ioService));
    this->_core.log().Info("Network stated !");
}

void Network::update() {
    std::vector<std::string> toDelete;
    this->sendPackets();
    this->handlePackets();
    for (const auto &server: this->_servers) {
        server.second->updateEvent();
        if (server.second->isTimeout(this->_timeout))
            toDelete.push_back(server.first);
    }
    for (const auto &name: toDelete) {
        this->_core.log().Info("Connection lost with " + name);
        this->_core.getSceneManager().getCurrentScene().emitEvent("disconnectUser", name);
        this->_core.getSceneManager().getGlobalScene().emitEvent("disconnectUser", name);
        this->_servers.erase(name);
    }
}

void Network::addServer(const std::string &name, const std::string &ip, unsigned int port) {
    this->_servers[name] = std::make_unique<Server>(ip, port, this->_user, this->_core, name);
}

void Network::addServer(const std::string &name, boost::asio::ip::udp::endpoint &ip) {
    this->_servers[name] = std::make_unique<Server>(ip, this->_user, this->_core, name);
}

void Network::removeServer(const std::string &name) {
    this->_servers.erase(name);
}

const Server &Network::getServer(const std::string &name) const {
    if (!this->_servers.contains(name)) throw std::runtime_error("server not found : " + name);
    return *this->_servers.at(name);
}

Server &Network::getServer(const std::string &name) {
    if (!this->_servers.contains(name)) throw std::runtime_error("server not found : " + name);
    return *this->_servers.at(name);
}

std::map<boost::asio::ip::udp::endpoint, Json::Value> Network::getPacketToSend() {
    std::map<boost::asio::ip::udp::endpoint, Json::Value> packets;

    for (auto &server: this->_servers) {
        auto userPackets = server.second->getPacketToSend();
        for (const auto &userPacket: userPackets) {
            packets[server.second->getEndPoint()] = userPacket;
        }
    }
    return packets;
}

void Network::compressData(const std::string &input, std::vector<unsigned char> &output) {
    z_stream zs;
    int ret;

    zs.zalloc = Z_NULL;
    zs.zfree = Z_NULL;
    zs.opaque = Z_NULL;

    ret = deflateInit(&zs, Z_BEST_COMPRESSION);
    if (ret != Z_OK) {
        throw std::runtime_error("deflateInit failed");
    }

    zs.next_in = (Bytef *) input.data();
    zs.avail_in = input.size();

    output.resize(input.size() * 5);

    do {
        zs.next_out = output.data() + zs.total_out;
        zs.avail_out = output.size() - zs.total_out;
        ret = deflate(&zs, Z_FINISH);
    } while (ret == Z_OK);

    deflateEnd(&zs);

    if (ret != Z_STREAM_END) {
        throw std::runtime_error("zlib compression failed");
    }

    output.resize(zs.total_out);
}

void Network::decompressData(const std::vector<unsigned char> &input, std::string &output) {
    z_stream zs;
    int ret;

    zs.zalloc = Z_NULL;
    zs.zfree = Z_NULL;
    zs.opaque = Z_NULL;

    ret = inflateInit(&zs);
    if (ret != Z_OK) {
        throw std::runtime_error("inflateInit failed");
    }

    zs.next_in = const_cast<Bytef *>(input.data());
    zs.avail_in = input.size();

    output.resize(input.size() * 5);

    do {
        zs.next_out = (Bytef *) output.data() + zs.total_out;
        zs.avail_out = output.size() - zs.total_out;
        ret = inflate(&zs, Z_NO_FLUSH);
    } while (ret == Z_OK);

    inflateEnd(&zs);

    if (ret != Z_STREAM_END) {
        throw std::runtime_error("zlib decompression failed");
    }

    output.resize(zs.total_out);
}

void Network::sendPackets() {
    if (this->_clock.getMilliSeconds() < this->_latence)
        return;
    this->_clock.restart();
    auto packets = this->getPacketToSend();
    for (auto &pair: packets) {
        try {
            Json::FastWriter fastWriter;
            std::string output = fastWriter.write(pair.second);
            std::vector<unsigned char> compressedData;
            this->compressData(output, compressedData);
            this->_socketUDP.send_to(boost::asio::buffer(compressedData), pair.first);
        } catch (std::exception &e) {
            std::cerr << "error sent " << e.what() << std::endl;
        }
    }
}

void Network::receiveBuffer(const std::vector<unsigned char> &buffer, boost::asio::ip::udp::endpoint &senderEndPoint) {
    auto it = std::find_if(this->_servers.begin(), this->_servers.end(), [&](const auto &server) {
        return senderEndPoint == server.second->getEndPoint();
    });
    try {
        std::string originData;
        decompressData(buffer, originData);

        if (!originData.empty()) {
            Json::Value command;
            std::istringstream(originData) >> command;
            if (it == this->_servers.end()) {
                this->addServer(command["user"].asString(), senderEndPoint);
                this->_core.log().Info("New connection -> " + command["user"].asString() + " with " +
                                       senderEndPoint.address().to_string() + ":" +
                                       std::to_string(senderEndPoint.port()));
                it = std::find_if(this->_servers.begin(), this->_servers.end(), [&](const auto &server) {
                    return senderEndPoint == server.second->getEndPoint();
                });
                if (it == this->_servers.end())
                    throw std::runtime_error("error while creating server profile");
                Json::Value value;
                value["user"] = command["user"].asString();
                value["ip"] = senderEndPoint.address().to_string();
                value["port"] = senderEndPoint.port();
                this->_core.getSceneManager().getCurrentScene().emitEvent("newServerUser", value);
                this->_core.getSceneManager().getGlobalScene().emitEvent("newServerUser", value);
            }
            Json::Value receivedInfo = command["received"];

            it->second->addPacket(command);
            it->second->checkSentPacket(receivedInfo);
        }
    } catch (std::exception &e) {
        std::cerr << "error inside receiveBuffer" << std::endl;
        std::cerr << e.what() << std::endl;
    }
}

void Network::handlePackets() {
    this->_queue.consume_all([&](std::tuple<boost::asio::ip::udp::endpoint, std::vector<unsigned char>> *packet) {
        this->receiveBuffer(std::get<1>(*packet), std::get<0>(*packet));
        delete packet;
    });
}

void Network::startReceive() {
    this->_socketUDP.async_receive_from(
            boost::asio::buffer(this->_buffer),
            _senderEndPoint,
            [&](const boost::system::error_code &error, std::size_t length) {
                if (!error) {
                    auto copy = this->_buffer;
                    copy.resize(length);
                    auto *packet =
                            new std::tuple<boost::asio::ip::udp::endpoint, std::vector<unsigned char>>(_senderEndPoint,
                                                                                                       copy);
                    this->_queue.push(packet);
                } else {
                    std::cerr << "Error network : " << error.message() << std::endl;
                }
                this->startReceive();
            });
}

std::string &Network::getUser() {
    return this->_user;
}

void Network::changeUser(const std::string &value) {
    this->_user = value;
}

std::map<std::string, std::unique_ptr<Server>> &Network::getServers() {
    return this->_servers;
}
