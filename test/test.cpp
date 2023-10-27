//
// Created by youba on 27/10/2023.
//

#include "test.hpp"
#include "API.hpp"
#include "PluginCreator.hpp"
#include "Core.hpp"

Uniti::Core &test::getCore() {
    return this->_core;
}

void test::awake(const Json::Value &value) {

}

void test::preStart() {

}

void test::start() {

}

void test::postStart() {

}

void test::preUpdate() {

}

void test::update() {
    this->_core.log().Danger("JE PASSE !");
}

void test::postUpdate() {

}

void test::preEnd() {

}

void test::end() {

}

void test::postEnd() {

}

const Uniti::Clock &test::getClock() const {
    return this->_clock;
}

Uniti::Clock &test::getClock() {
    return this->_clock;
}

const Uniti::Event &test::getEvent() const {
    return this->_event;
}

Uniti::Event &test::getEvent() {
    return this->_event;
}

extern "C" {
void *getCreator(void) {
    return new Uniti::PluginCreator<Uniti::ICorePlugin, test, Uniti::Core>();
}

void deleteCreator(void *creator) {
    delete static_cast<Uniti::PluginCreator<Uniti::ICorePlugin, test, Uniti::Core> *>(creator);
}
}
