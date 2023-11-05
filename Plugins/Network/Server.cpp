//
// Created by youba on 29/10/2023.
//

#include "Server.hpp"
#include <algorithm>

Server::Server(const std::string &ip, unsigned int port, const std::string &user, Uniti::Core &core,
               const std::string &id) :
        _endpoint(boost::asio::ip::address::from_string(ip), port),
        _user(user),
        _core(core),
        _id(id) {}

Server::Server(boost::asio::ip::udp::endpoint &ip, const std::string &user, Uniti::Core &core, const std::string &id) :
        _endpoint(ip),
        _user(user),
        _core(core),
        _id(id) {}

void Server::sendEvent(const std::string &name, const Json::Value &value) {
    this->_events[name] = value;
}

const boost::asio::ip::udp::endpoint &Server::getEndPoint() const {
    return this->_endpoint;
}

boost::asio::ip::udp::endpoint &Server::getEndPoint() {
    return this->_endpoint;
}

void Server::addPacket(const Json::Value &packet) {
    int id = packet.get("id", -1).asInt();

    if (id == -1)
        return;
    auto itToHandle = std::find_if(
            this->_packetToHandle.begin(),
            this->_packetToHandle.end(),
            [&](const auto &value) {
                int otherId = value.get("id", -1).asInt();
                return id == otherId;
            });
    if (itToHandle != this->_packetToHandle.end())
        return;
    auto itHandled = std::find(this->_packetHandled.begin(), this->_packetHandled.end(), id);
    if (itHandled != this->_packetHandled.end())
        return;
    this->_packetToHandle.push_back(packet);
}

void Server::updateEvent() {
    int nextId = (this->_waitedId + 1 >= 100) ? 0 : this->_waitedId + 1;

    auto itToHandle = std::find_if(
            this->_packetToHandle.begin(),
            this->_packetToHandle.end(),
            [&](const auto &value) {
                int id = value.get("id", -1).asInt();
                return nextId == id;
            });
    if (itToHandle == this->_packetToHandle.end())
        return;
    this->_time.restart();
    Json::Value events = itToHandle.operator*()["events"];

    for (const auto &event: events) {
        Json::Value newData = event;
        const std::string &name = event.get("name", "undefined").asString();
        newData["idUser"] = this->_id;
        this->_core.getSceneManager().getCurrentScene().emitEvent(name, newData);
        this->_core.getSceneManager().getGlobalScene().emitEvent(name, newData);
    }
    if (this->_packetHandled.size() > 16)
        this->_packetHandled.pop_front();
    this->_packetHandled.push_back(nextId);
    this->_packetToHandle.erase(itToHandle);
    this->_waitedId = nextId;
    this->updateEvent();
}

void Server::checkSentPacket(const Json::Value &sent) {
    std::erase_if(this->_sentPacket, [&](auto &packet) {
        Json::Value info = std::get<0>(packet);
        int id = info.get("id", -1).asInt();
        return std::any_of(sent.begin(), sent.end(), [&](const auto &sentId) {
            return sentId.asInt() == id;
        });
    });
    for (auto &packet: this->_sentPacket) {
        if (std::get<1>(packet) > 0)
            std::get<1>(packet) = std::get<1>(packet) - 1;
        else
            this->_packetToSend.push_back(std::get<0>(packet));
    }
    std::erase_if(this->_sentPacket, [&](auto &packet) {
        return std::get<1>(packet) <= 0;
    });
}

std::vector<Json::Value> Server::getPacketToSend() {
    std::vector<Json::Value> packets;

    packets.insert(packets.end(), this->_packetToSend.begin(), this->_packetToSend.end());
    packets.push_back(createPacket());
    this->_packetToSend.clear();
    return packets;
}

Json::Value Server::createPacket() {
    Json::Value packet;
    Json::Value events;
    Json::Value received;
    Json::Value id = this->_sendId;
    int i = 0;

    this->_sendId = (this->_sendId + 1 < 100) ? this->_sendId + 1 : 0;
    for (const auto &eventRow: this->_events) {
        Json::Value event;
        event["name"] = eventRow.first;
        event["data"] = eventRow.second;
        events.insert(i, event);
        i++;
    }
    i = 0;
    for (const auto &idPacket: this->_receivedPacket) {
        received.insert(i, idPacket);
        i++;
    }
    this->_events.clear();
    this->_receivedPacket.clear();
    packet["events"] = events;
    packet["received"] = received;
    packet["id"] = id;
    packet["user"] = this->_user;
    return packet;
}

bool Server::isTimeout(float time) {
    return this->_time.getSeconds() > time;
}

std::map<std::string, Json::Value> &Server::getSendEvents() {
    return this->_events;
}
