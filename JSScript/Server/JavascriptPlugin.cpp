//
// Created by youba on 30/10/2023.
//

#include "JavascriptPlugin.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Core.hpp"

JavascriptPlugin::JavascriptPlugin(Uniti::Core &core) : _core(core), _queue(10000) {}

Uniti::Core &JavascriptPlugin::getCore() {
    return this->_core;
}

void JavascriptPlugin::awake(const Json::Value &value) {
    this->_code = std::to_string(std::rand() % 100000);
    this->_port = value.get("port", 8000).asInt();
    std::string port = std::to_string(this->_port);

    this->_thread = std::thread([](std::string code, std::string port, JavascriptPlugin &plugin) {
        int result = std::system(std::string("node ../../JSScript/Interpreter/index.js " + port + " " + code).c_str());

        if (result != 0) {
            plugin._queue.push(new std::string("Error execution of node"));
        }
        plugin._queue.push(new std::string("Execution ended"));
    }, this->_code, port, std::ref(*this));
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void JavascriptPlugin::preStart() {
    try {
        client.connect(std::string("http://127.0.0.1:" + std::to_string(this->_port)));

        client.socket()->on("update", [&](sio::event &message) {
            std::string response = message.get_message()->get_string();
        });
        client.socket()->emit("init", {this->_code});
    } catch (std::exception &e) {
        this->_core.log().Danger("Error while init socket.io");
        this->_core.log().Danger(e.what());
    }
}

void JavascriptPlugin::start() {

}

void JavascriptPlugin::postStart() {

}

void JavascriptPlugin::preUpdate() {

}

void JavascriptPlugin::update() {
    this->_queue.consume_all([&](std::string *event) {
        this->_core.log().Danger(*event);
        delete event;
    });
}

void JavascriptPlugin::postUpdate() {

}

void JavascriptPlugin::preEnd() {
}

void JavascriptPlugin::end() {

}

void JavascriptPlugin::postEnd() {
    this->client.close();
    this->_core.log().Info("Checking the end of node session");
    if (this->_thread.joinable()) {
        this->_core.log().Warn("Waiting the end of node session");
        this->_thread.join();
    }
    this->_core.log().Info("node session ended");
}

const Uniti::Clock &JavascriptPlugin::getClock() const {
    return this->_clock;
}

Uniti::Clock &JavascriptPlugin::getClock() {
    return this->_clock;
}

const Uniti::Event &JavascriptPlugin::getEvent() const {
    return this->_event;
}

Uniti::Event &JavascriptPlugin::getEvent() {
    return this->_event;
}
