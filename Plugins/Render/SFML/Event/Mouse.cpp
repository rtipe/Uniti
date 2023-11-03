//
// Created by youba on 28/10/2023.
//

#include "Mouse.hpp"

Mouse::Mouse(sf::Event &event, sf::RenderWindow &window) : _event(event), _window(window) {}

void Mouse::update() {
    std::string name;

    switch (this->_event.type) {
        case sf::Event::MouseButtonPressed:
            Mouse::_events.push_back(
                    "MOUSE_" + std::to_string(this->_event.mouseButton.button) + "_PRESSED");
            break;
        case sf::Event::MouseButtonReleased:
            Mouse::_events.push_back(
                    "MOUSE_" + std::to_string(this->_event.mouseButton.button) + "_RELEASED");
            break;
        default:
            break;
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
    sf::Vector2<int> position = sf::Mouse::getPosition(this->_window);
    return {static_cast<float>(position.x), static_cast<float>(position.y)};
}

std::vector<std::string> &Mouse::getEvents() {
    return this->_events;
}

void Mouse::clearEvents() {
    this->_events.clear();
}
