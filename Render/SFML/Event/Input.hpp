//
// Created by youba on 28/10/2023.
//

#pragma once

#include <SFML/Window/Event.hpp>
#include "IInput.hpp"

class Input : public IInput {
public:
    Input(sf::Event &event);

    void update() override;

    bool isPressed(const std::string &key) override;

    bool isPressed(Key key) override;

    bool isReleased(const std::string &key) override;

    bool isReleased(Key key) override;

    std::vector<std::string> &getEvents() override;

    void clearEvents() override;

private:
    sf::Event &_event;
    std::vector<std::string> _events;
};
