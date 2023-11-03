//
// Created by youba on 29/10/2023.
//

#include "NetworkPlugin.hpp"

NetworkPlugin::NetworkPlugin(Uniti::Core &core) : _core(core) {
    this->_event.addEvent("addServer", [&](const Json::Value &value) {
        this->_network->addServer(
                value.get("name", "").asString(),
                value.get("ip", "").asString(),
                value.get("port", 0).asInt()
        );
    });
    this->_event.addEvent("removeServer", [&](const Json::Value &value) {
        this->_network->removeServer(value.asString());
    });
    this->_event.addEvent("sendEvent", [&](const Json::Value &value) {
        this->_network->getServer(value["serverName"].asString()).sendEvent(value["name"].asString(), value["value"]);
    });
    this->_event.addEvent("changeUser", [&](const Json::Value &value) {
        this->_network->changeUser(value["changeUser"].asString());
    });
}

Uniti::Core &NetworkPlugin::getCore() {
    return this->_core;
}

void NetworkPlugin::awake(const Json::Value &value) {
    this->_network = std::make_unique<Network>(
            value.get("port", 0).asInt(),
            value.get("latence", 10).asInt(),
            value.get("timeout", 10).asInt(),
            value.get("user", "").asString(),
            this->_core
    );
}

void NetworkPlugin::preStart() {
    this->_network->start();
}

void NetworkPlugin::start() {

}

void NetworkPlugin::postStart() {

}

void NetworkPlugin::preUpdate() {

}

void NetworkPlugin::update() {

}

void NetworkPlugin::postUpdate() {
    this->_network->update();
}

void NetworkPlugin::preEnd() {

}

void NetworkPlugin::end() {

}

void NetworkPlugin::postEnd() {

}

const Uniti::Clock &NetworkPlugin::getClock() const {
    return this->_clock;
}

Uniti::Clock &NetworkPlugin::getClock() {
    return this->_clock;
}

const Uniti::Event &NetworkPlugin::getEvent() const {
    return this->_event;
}

Uniti::Event &NetworkPlugin::getEvent() {
    return this->_event;
}

Network &NetworkPlugin::getNetwork() {
    if (!this->_network) throw std::runtime_error("Network not ready");
    return *this->_network;
}
