//
// Created by youba on 29/10/2023.
//

#include "NetworkPlugin.hpp"

NetworkPlugin::NetworkPlugin(Uniti::Core &core) : _core(core) {}

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
