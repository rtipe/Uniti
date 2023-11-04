//
// Created by youba on 29/10/2023.
//

#pragma once

#include <boost/asio.hpp>
#include <boost/lockfree/queue.hpp>
#include <string>
#include "json/value.h"
#include "Server.hpp"
#include "Clock.hpp"

class Network {
public:
    Network(unsigned int port, unsigned int latence, float timeout, const std::string &user, Uniti::Core &core);

    ~Network();

    void start();

    void update();

    void addServer(const std::string &name, const std::string &ip, unsigned int port);

    void addServer(const std::string &name, boost::asio::ip::udp::endpoint &ip);

    void removeServer(const std::string &name);

    const Server &getServer(const std::string &name) const;

    Server &getServer(const std::string &name);

    std::string &getUser();

    void changeUser(const std::string &value);

    std::map<std::string, std::unique_ptr<Server>> &getServers();
private:
    Uniti::Core &_core;
    std::string _user;

    std::map<boost::asio::ip::udp::endpoint, Json::Value> getPacketToSend();

    void compressData(const std::string &input, std::vector<unsigned char> &output);

    void decompressData(const std::vector<unsigned char> &input, std::string &output);
    void sendPackets();

    void startReceive();

    void receiveBuffer(const std::vector<unsigned char> &buffer, boost::asio::ip::udp::endpoint &senderEndPoint);

    void handlePackets();

    std::map<std::string, std::unique_ptr<Server>> _servers;
    boost::asio::io_service _ioService;
    boost::asio::ip::udp::socket _socketUDP;
    unsigned int _latence;
    unsigned int _port;
    float _timeout;
    std::thread _ioThread;
    Uniti::Clock _clock;
    int _size = 50000;
    std::vector<unsigned char> _buffer;
    boost::asio::ip::udp::endpoint _senderEndPoint;
    boost::lockfree::queue<std::tuple<boost::asio::ip::udp::endpoint, std::vector<unsigned char>> *> _queue;
};
