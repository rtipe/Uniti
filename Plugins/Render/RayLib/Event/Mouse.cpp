//
// Created by youba on 05/11/2023.
//

#include "Mouse.hpp"
#include "raylib.h"

static const std::map<IMouse::KeyMouse, int> mouseButtonToRaylibKey = {
        {IMouse::KeyMouse::LEFT,   MOUSE_LEFT_BUTTON},
        {IMouse::KeyMouse::RIGHT,  MOUSE_RIGHT_BUTTON},
        {IMouse::KeyMouse::MIDDLE, MOUSE_MIDDLE_BUTTON}
};

Mouse::Mouse() {}

void Mouse::update() {
    std::string name;

    for (const auto &element: mouseButtonToRaylibKey) {
        if (IsMouseButtonPressed(element.second))
            _events.push_back("MOUSE_" + std::to_string(element.first) + "_PRESSED");
        if (IsMouseButtonReleased(element.second))
            _events.push_back("MOUSE_" + std::to_string(element.first) + "_RELEASED");
    }
}

bool Mouse::isMousePressed(const std::string &key) {
    std::string name = key;
    for (auto &c: name)
        c = toupper(c);
    std::string eventName = "MOUSE_" + name + "_PRESSED";
    return std::find(Mouse::_events.begin(), Mouse::_events.end(), eventName) != Mouse::_events.end();
}

bool Mouse::isMousePressed(IMouse::KeyMouse keyMouse) {
    std::string eventName = "MOUSE_" + std::to_string(keyMouse) + "_PRESSED";
    return std::find(Mouse::_events.begin(), Mouse::_events.end(), eventName) != Mouse::_events.end();
}

bool Mouse::isMouseReleased(const std::string &key) {
    std::string name = key;
    for (auto &c: name)
        c = toupper(c);
    std::string eventName = "MOUSE_" + name + "_RELEASED";
    return std::find(Mouse::_events.begin(), Mouse::_events.end(), eventName) != Mouse::_events.end();
}

bool Mouse::isMouseReleased(IMouse::KeyMouse keyMouse) {
    std::string eventName = "MOUSE_" + std::to_string(keyMouse) + "_RELEASED";
    return std::find(Mouse::_events.begin(), Mouse::_events.end(), eventName) != Mouse::_events.end();
}

Uniti::Vector2f Mouse::getPosition() {
    Vector2 mousePosition = GetMousePosition();
    return {mousePosition.x, mousePosition.y};
}

std::vector<std::string> &Mouse::getEvents() {
    return this->_events;
}

void Mouse::clearEvents() {
    this->_events.clear();
}