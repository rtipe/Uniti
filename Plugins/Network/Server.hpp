//
// Created by youba on 29/10/2023.
//

#pragma once

#include <boost/asio/ip/udp.hpp>
#include <json/value.h>
#include <list>
#include "Core.hpp"

/** @brief Server class for managing network communication with a remote server.
*/
class Server {
public:
    /** @brief Constructor for the Server class with IP, port, user, Core, and an ID.
        @param const std::string &ip: IP address of the server.
        @param unsigned int port: Port number for communication.
        @param const std::string &user: User associated with the server.
        @param Uniti::Core &core: Reference to the Core.
        @param const std::string &id: Unique identifier for the server.
    */
    Server(const std::string &ip, unsigned int port, const std::string &user, Uniti::Core &core, const std::string &id);

    /** @brief Constructor for the Server class with an endpoint, user, Core, and an ID.
        @param boost::asio::ip::udp::endpoint &ip: Endpoint for communication.
        @param const std::string &user: User associated with the server.
        @param Uniti::Core &core: Reference to the Core.
        @param const std::string &id: Unique identifier for the server.
    */
    Server(boost::asio::ip::udp::endpoint &ip, const std::string &user, Uniti::Core &core, const std::string &id);

    /** @brief Send an event with a name and JSON value to the server.
        @param const std::string &name: Name of the event.
        @param const Json::Value &value: JSON value associated with the event.
    */
    void sendEvent(const std::string &name, const Json::Value &value);

    /** @brief Get a reference to the map of events to be sent.
        @return std::map<std::string, Json::Value>&: Reference to the map of events.
    */
    std::map<std::string, Json::Value> &getSendEvents();

    /** @brief Get a constant reference to the endpoint associated with the server.
        @return const boost::asio::ip::udp::endpoint&: Constant reference to the endpoint.
    */
    const boost::asio::ip::udp::endpoint &getEndPoint() const;

    /** @brief Get a reference to the endpoint associated with the server.
        @return boost::asio::ip::udp::endpoint&: Reference to the endpoint.
    */
    boost::asio::ip::udp::endpoint &getEndPoint();

    /** @brief Add a packet to the server.
        @param const Json::Value &packet: JSON packet to be added.
    */
    void addPacket(const Json::Value &packet);

    /** @brief Update events associated with the server.
    */
    void updateEvent();

    /** @brief Check sent packets and update their status.
        @param const Json::Value &sent: JSON packet that has been sent.
    */
    void checkSentPacket(const Json::Value &sent);

    /** @brief Get a list of packets to be sent.
        @return std::vector<Json::Value>: List of JSON packets to be sent.
    */
    std::vector<Json::Value> getPacketToSend();

    /** @brief Check if the server has timed out based on the given time.
        @param float time: Time value to check for a timeout.
        @return bool: True if a timeout has occurred, false otherwise.
    */
    bool isTimeout(float time);

private:
    Uniti::Clock _time;
    Uniti::Core &_core;

    /** @brief Create a JSON packet for communication.
        @return Json::Value: JSON packet.
    */
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
