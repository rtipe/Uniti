//
// Created by youba on 28/10/2023.
//

#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "IMouse.hpp"

class Mouse : public IMouse {
public:
    Mouse(sf::Event &event, sf::RenderWindow &window);

    void update() override;

    bool isMousePressed(const std::string &key) override;

    bool isMousePressed(KeyMouse keyMouse) override;

    bool isMouseReleased(const std::string &key) override;

    bool isMouseReleased(KeyMouse keyMouse) override;

    Uniti::Vector2f getPosition() override;

    std::vector<std::string> &getEvents() override;

    void clearEvents() override;

private:
    sf::RenderWindow &_window;
    sf::Event &_event;
    std::vector<std::string> _events;
};
