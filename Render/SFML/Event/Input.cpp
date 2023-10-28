//
// Created by youba on 28/10/2023.
//

#include "Input.hpp"

Input::Input(sf::Event &event) : _event(event) {}

void Input::update() {
    std::string name;

    switch (this->_event.type) {
        case sf::Event::KeyPressed:
            Input::_events.push_back("KEY_" + std::to_string(this->_event.key.code) + "_PRESSED");
            break;
        case sf::Event::KeyReleased:
            Input::_events.push_back("KEY_" + std::to_string(this->_event.key.code) + "_RELEASED");
            break;
        default:
            break;
    }
}

bool Input::isPressed(const std::string &key) {
    std::string name = key;
    for (auto &c: name)
        c = toupper(c);
    std::string eventName = "KEY_" + name + "_PRESSED";
    return std::find(Input::_events.begin(), Input::_events.end(), eventName) != Input::_events.end();
}

bool Input::isPressed(IInput::Key key) {
    std::string eventName = "KEY_" + std::to_string(key) + "_PRESSED";
    return std::find(Input::_events.begin(), Input::_events.end(), eventName) != Input::_events.end();
}

bool Input::isReleased(const std::string &key) {
    std::string name = key;
    for (auto &c: name)
        c = toupper(c);
    std::string eventName = "KEY_" + name + "_RELEASED";
    return std::find(Input::_events.begin(), Input::_events.end(), eventName) != Input::_events.end();
}

bool Input::isReleased(IInput::Key key) {
    std::string eventName = "KEY_" + std::to_string(key) + "_RELEASED";
    return std::find(Input::_events.begin(), Input::_events.end(), eventName) != Input::_events.end();
}

std::vector<std::string> &Input::getEvents() {
    return this->_events;
}

void Input::clearEvents() {
    this->_events.clear();
}
