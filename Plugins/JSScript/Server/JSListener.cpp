//
// Created by youba on 31/10/2023.
//

#include "JSListener.hpp"

JSListener::JSListener(Uniti::Object &object) : _object(object), _event(object) {}

Uniti::Object &JSListener::getObject() {
    return this->_object;
}

void JSListener::awake(const Json::Value &value) {

}

void JSListener::preStart() {

}

void JSListener::start() {

}

void JSListener::postStart() {

}

void JSListener::preUpdate() {

}

void JSListener::update() {

}

void JSListener::postUpdate() {

}

void JSListener::preEnd() {

}

void JSListener::end() {

}

void JSListener::postEnd() {

}

const Uniti::Clock &JSListener::getClock() const {
    return this->_clock;
}

Uniti::Clock &JSListener::getClock() {
    return this->_clock;
}

const Uniti::Event &JSListener::getEvent() const {
    return this->_event;
}

Uniti::Event &JSListener::getEvent() {
    return this->_event;
}
