//
// Created by youba on 28/10/2023.
//

#include "Window.hpp"
#include <iostream>

bool Window::isOpen() const {
    return this->_window.isOpen();
}

void Window::close() {
    this->_window.close();
}

void Window::display() {
    this->_input.clearEvents();
    this->_mouse.clearEvents();
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->close();
        this->_input.update();
        this->_mouse.update();
    }
    std::sort(
            this->_printable.begin(),
            this->_printable.end(),
            [](IPrintable &printable1, IPrintable &printable2) {
                return printable1.getZIndex() < printable2.getZIndex();
            });
    this->_window.clear({0, 0, 0});
    for (const auto &printable: this->_printable)
        printable.get().display();
    this->_window.display();
    this->_printable.clear();
}

void Window::create(const Json::Value &value) {
    int width = value.get("width", 1920).asInt();
    int height = value.get("height", 1080).asInt();
    std::string iconPath = value.get("icon", "").asString();
    std::string title = value.get("title", "undefined").asString();

    this->_window.create(sf::VideoMode(width, height), title);
    if (this->_icon.loadFromFile(iconPath))
        this->_window.setIcon(
                this->_icon.getSize().x,
                this->_icon.getSize().y,
                this->_icon.getPixelsPtr());
}

void Window::print(IPrintable &printable) {
    this->_printable.emplace_back(printable);
}

IInput &Window::getInput() {
    return this->_input;
}

IMouse &Window::getMouse() {
    return this->_mouse;
}

Window::Window() :
        _event(),
        _mouse(this->_event, this->_window),
        _input(this->_event) {}

sf::RenderWindow &Window::getRenderWindow() {
    return this->_window;
}