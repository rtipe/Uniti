//
// Created by youba on 29/10/2023.
//

#pragma once

#include <boost/asio/ip/udp.hpp>
#include <json/value.h>
#include <list>
#include "Core.hpp"

class Server {
public:
    Server(const std::string &ip, unsigned int port, const std::string &user, Uniti::Core &core, const std::string &id);

    Server(boost::asio::ip::udp::endpoint &ip, const std::string &user, Uniti::Core &core, const std::string &id);

    void sendEvent(const std::string &name, const Json::Value &value);

    std::map<std::string, Json::Value> &getSendEvents();

    const boost::asio::ip::udp::endpoint &getEndPoint() const;

    boost::asio::ip::udp::endpoint &getEndPoint();

    void addPacket(const Json::Value &packet);

    void updateEvent();

    void checkSentPacket(const Json::Value &sent);

    std::vector<Json::Value> getPacketToSend();

    bool isTimeout(float time);

private:
    Uniti::Clock _time;
    Uniti::Core &_core;

    Json::Value createPacket();

    std::map<std::string, Json::Value> _events;
    boost::asio::ip::udp::endpoint _endpoint;
    std::vector<Json::Value> _packetToHandle;
    std::list<int> _packetHandled;
    std::vector<std::tuple<Json::Value, int>> _sentPacket;
    std::vector<Json::Value> _packetToSend;
    std::list<int> _receivedPacket;
    int _waitedId = 0;
    int _sendId = 0;
    std::string _user;
    std::string _id;
};
