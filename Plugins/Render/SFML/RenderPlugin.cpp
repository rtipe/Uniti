//
// Created by youba on 28/10/2023.
//

#include "RenderPlugin.hpp"

RenderPlugin::RenderPlugin(Uniti::Core &core) : _core(core) {}

Uniti::Core &RenderPlugin::getCore() {
    return this->_core;
}

const IWindow &RenderPlugin::getWindow() const {
    return this->_window;
}

IWindow &RenderPlugin::getWindow() {
    return this->_window;
}

void RenderPlugin::awake(const Json::Value &value) {
    this->_core.log().Info("Creating window...");
    try {
        this->_window.create(value);
    } catch (std::exception &e) {
        this->_core.log().Danger("Error while creating window :");
        this->_core.log().Danger(e.what());
    }
    this->_framerateLimit = value.get("frameRateLimit", -1).asInt();
    this->_core.log().Info("window created !");
}

void RenderPlugin::preStart() {

}

void RenderPlugin::start() {

}

void RenderPlugin::postStart() {

}

void RenderPlugin::preUpdate() {

}

void RenderPlugin::update() {

}

void RenderPlugin::postUpdate() {
    if (this->_framerateLimit > 0) {
        if (this->_clock.getSeconds() < 1 / this->_framerateLimit) return;
        this->_clock.restart();
    }
    try {
        this->_window.display();
        for (const auto &event: this->_window.getInput().getEvents()) {
            this->_core.getSceneManager().getGlobalScene().emitEvent(event, {});
            this->_core.getSceneManager().getCurrentScene().emitEvent(event, {});
        }
        Uniti::Vector2f positionMouse = this->_window.getMouse().getPosition();
        Json::Value position;
        position["x"] = positionMouse.getX();
        position["y"] = positionMouse.getY();
        for (const auto &event: this->_window.getMouse().getEvents()) {
            this->_core.getSceneManager().getGlobalScene().emitEvent(event, position);
            this->_core.getSceneManager().getCurrentScene().emitEvent(event, position);
        }
    } catch (std::exception &e) {
        this->_core.log().Danger("Error while displaying :");
        this->_core.log().Danger(e.what());
    }
    if (!this->_window.isOpen()) {
        this->_core.log().Warn("Window closed, asking for close instance...");
        this->_core.stop();
    }
}

void RenderPlugin::preEnd() {

}

void RenderPlugin::end() {

}

void RenderPlugin::postEnd() {

}

const Uniti::Clock &RenderPlugin::getClock() const {
    return this->_clock;
}

Uniti::Clock &RenderPlugin::getClock() {
    return this->_clock;
}

const Uniti::Event &RenderPlugin::getEvent() const {
    return this->_event;
}

Uniti::Event &RenderPlugin::getEvent() {
    return this->_event;
}
