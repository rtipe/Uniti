//
// Created by youba on 01/11/2023.
//

#include "Button.hpp"
#include "RenderPlugin.hpp"
#include "Box.hpp"
#include "API.hpp"
#include "PluginCreator.hpp"

Button::Button(Uniti::Object &object) : _object(object) {
    this->_event.addEvent("MOUSE_0_PRESSED", [&](const Json::Value &value) {
        Uniti::Box box(0, 0, this->_width, this->_height);
        box.getPosition() = this->_object.getTransform().getPosition();
        Uniti::Vector2f positionMouse = value;

        if (box.isInside(positionMouse)) {
            this->_object.emitEvent("onClick", value);
        }
    });
}

Uniti::Object &Button::getObject() {
    return this->_object;
}

void Button::awake(const Json::Value &value) {
    this->_width = value.get("width", 0).asFloat();
    this->_height = value.get("height", 0).asFloat();
}

void Button::preStart() {

}

void Button::start() {

}

void Button::postStart() {

}

void Button::preUpdate() {

}

void Button::update() {

}

void Button::postUpdate() {

}

void Button::preEnd() {

}

void Button::end() {

}

void Button::postEnd() {

}

const Uniti::Clock &Button::getClock() const {
    return this->_clock;
}

Uniti::Clock &Button::getClock() {
    return this->_clock;
}

const Uniti::Event &Button::getEvent() const {
    return this->_event;
}

Uniti::Event &Button::getEvent() {
    return this->_event;
}

extern "C" {
void *getCreator(void) {
    return new Uniti::PluginCreator<Uniti::IObjectPlugin, Button, Uniti::Object>();
}

void deleteCreator(void *creator) {
    delete static_cast<Uniti::PluginCreator<Uniti::IObjectPlugin, Button, Uniti::Object> *>(creator);
}
}