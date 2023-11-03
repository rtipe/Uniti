//
// Created by youba on 28/10/2023.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "IWindow.hpp"
#include "Input.hpp"
#include "Mouse.hpp"

class Window : public IWindow {
public:
    Window();

    bool isOpen() const override;

    void close() override;

    void display() override;

    void create(const Json::Value &value) override;

    void print(IPrintable &printable) override;

    IInput &getInput() override;

    IMouse &getMouse() override;

    sf::RenderWindow &getRenderWindow();

private:
    sf::Event _event;
    sf::Image _icon;
    sf::RenderWindow _window;
    std::vector<std::reference_wrapper<IPrintable>> _printable;
    Input _input;
    Mouse _mouse;
};
