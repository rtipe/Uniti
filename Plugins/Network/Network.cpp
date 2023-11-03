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
        _timeout(timeout) {
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
        this->_servers.erase(name);
    }
}

void Network::addServer(const std::string &name, const std::string &ip, unsigned int port) {
    this->_servers[name] = std::make_unique<Server>(ip, port, this->_user, this->_core);
}

void Network::addServer(const std::string &name, boost::asio::ip::udp::endpoint &ip) {
    this->_servers[name] = std::make_unique<Server>(ip, this->_user, this->_core);
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

void Network::sendPackets() {
    if (this->_clock.getMilliSeconds() < this->_latence)
        return;
    this->_clock.restart();
    auto packets = this->getPacketToSend();
    for (auto &pair: packets) {
        try {
            Json::FastWriter fastWriter;
            std::string output = fastWriter.write(pair.second);
            std::vector<unsigned char> compressedData(output.size() * 2);
            uLong destLength = compressedData.size();
            int result = compress(&compressedData[0], &destLength, (const Bytef *) output.c_str(), output.size());
            if (result == Z_OK) {
                compressedData.resize(destLength);
                this->_socketUDP.async_send_to(boost::asio::buffer(compressedData), pair.first,
                                               [](const boost::system::error_code &error,
                                                  std::size_t bytes_transferred) {
                                                   if (error) std::cerr << error.what() << std::endl;
                                               });
            } else {
                std::cerr << "error compression " << result << std::endl;
            }
        } catch (std::exception &e) {
            std::cerr << "error sent " << e.what() << std::endl;
        }
    }
}

void Network::receiveBuffer(const std::string &buffer, boost::asio::ip::udp::endpoint &senderEndPoint) {
    auto it = std::find_if(this->_servers.begin(), this->_servers.end(), [&](const auto &server) {
        return senderEndPoint == server.second->getEndPoint();
    });
    try {
        std::vector<unsigned char> decompressedData(buffer.size() * 2);
        uLong decompressedLength = decompressedData.size();
        int result = uncompress(&decompressedData[0], &decompressedLength, &decompressedData[0], buffer.size());

        if (result == Z_OK) {
            std::string originData(decompressedData.begin(), decompressedData.begin() + decompressedLength);
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
        } else {
            std::cerr << "error decompression " << result << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "error inside receiveBuffer" << std::endl;
        std::cerr << e.what() << std::endl;
    }
}

void Network::handlePackets() {
    this->_queue.consume_all([&](std::tuple<boost::asio::ip::udp::endpoint, std::string> *packet) {
        this->receiveBuffer(std::get<1>(*packet), std::get<0>(*packet));
        delete packet;
    });
}

void Network::startReceive() {
    this->_socketUDP.async_receive_from(
            boost::asio::buffer(this->_buffer, this->_size),
            _senderEndPoint,
            [&](const boost::system::error_code &error, std::size_t length) {
                if (!error) {
                    std::string text(this->_buffer, length);
                    memset(this->_buffer, 0, this->_size);
                    auto *packet =
                            new std::tuple<boost::asio::ip::udp::endpoint, std::string>(_senderEndPoint, text);
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
