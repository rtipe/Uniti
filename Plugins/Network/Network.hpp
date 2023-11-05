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

/** @brief Network class for managing network communication.
*/
class Network {
public:
    /** @brief Constructor for the Network class.
        @param unsigned int port: The port to use for network communication.
        @param unsigned int latence: The latency value.
        @param float timeout: The network timeout duration.
        @param const std::string &user: The user identifier.
        @param Uniti::Core &core: Reference to the Core.
    */
    Network(unsigned int port, unsigned int latence, float timeout, const std::string &user, Uniti::Core &core);

    /** @brief Destructor for the Network class.
    */
    ~Network();

    /** @brief Start the network communication.
    */
    void start();

    /** @brief Update the network status and handle communication.
    */
    void update();

    /** @brief Add a server with a given name, IP, and port.
        @param const std::string &name: The server's name.
        @param const std::string &ip: The IP address of the server.
        @param unsigned int port: The port of the server.
    */
    void addServer(const std::string &name, const std::string &ip, unsigned int port);

    /** @brief Add a server with a given name and endpoint.
        @param const std::string &name: The server's name.
        @param boost::asio::ip::udp::endpoint &ip: The server's endpoint.
    */
    void addServer(const std::string &name, boost::asio::ip::udp::endpoint &ip);

    /** @brief Remove a server by name.
        @param const std::string &name: The name of the server to remove.
    */
    void removeServer(const std::string &name);

    /** @brief Get a constant reference to a server by name.
        @param const std::string &name: The name of the server.
        @return const Server&: Constant reference to the server.
    */
    const Server &getServer(const std::string &name) const;

    /** @brief Get a reference to a server by name.
        @param const std::string &name: The name of the server.
        @return Server&: Reference to the server.
    */
    Server &getServer(const std::string &name);

    /** @brief Get the user identifier.
        @return std::string&: Reference to the user identifier.
    */
    std::string &getUser();

    /** @brief Change the user identifier to the specified value.
        @param const std::string &value: The new user identifier.
    */
    void changeUser(const std::string &value);

    /** @brief Get a reference to the map of servers.
        @return std::map<std::string, std::unique_ptr<Server>>&: Reference to the map of servers.
    */
    std::map<std::string, std::unique_ptr<Server>> &getServers();

private:
    Uniti::Core &_core;
    std::string _user;
    
    /** @brief Get a map of packets to send.
        @return std::map<boost::asio::ip::udp::endpoint, Json::Value>: Map of packets to send.
    */
    std::map<boost::asio::ip::udp::endpoint, Json::Value> getPacketToSend();

    /** @brief Compress input data and store it in the output vector.
        @param const std::string &input: Input data to be compressed.
        @param std::vector<unsigned char> &output: Output vector to store the compressed data.
    */
    void compressData(const std::string &input, std::vector<unsigned char> &output);

    /** @brief Decompress input data and store it in the output string.
        @param const std::vector<unsigned char> &input: Input data to be decompressed.
        @param std::string &output: Output string to store the decompressed data.
    */
    void decompressData(const std::vector<unsigned char> &input, std::string &output);

    /** @brief Send packets to connected servers.
    */
    void sendPackets();

    /** @brief Start receiving network data.
    */
    void startReceive();

    /** @brief Receive network data and store it in the buffer.
        @param const std::vector<unsigned char> &buffer: Data received from the network.
        @param boost::asio::ip::udp::endpoint &senderEndPoint: The endpoint from which data was received.
    */
    void receiveBuffer(const std::vector<unsigned char> &buffer, boost::asio::ip::udp::endpoint &senderEndPoint);

    /** @brief Handle received packets.
    */
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
