//
// Created by youba on 05/11/2023.
//

#pragma once

#include "IMouse.hpp"

class Mouse : public IMouse {
public:
    Mouse();

    void update() override;

    bool isMousePressed(const std::string &key) override;

    bool isMousePressed(KeyMouse keyMouse) override;

    bool isMouseReleased(const std::string &key) override;

    bool isMouseReleased(KeyMouse keyMouse) override;

    Uniti::Vector2f getPosition() override;

    std::vector<std::string> &getEvents() override;

    void clearEvents() override;

private:
    std::vector<std::string> _events;
};