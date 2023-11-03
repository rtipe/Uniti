//
// Created by youba on 28/10/2023.
//

#pragma once

#include <string>
#include "Vector2f.hpp"

class IMouse {
public:
    enum KeyMouse {
        LEFT,
        RIGHT,
        MIDDLE
    };

    virtual ~IMouse() = default;

    virtual void update() = 0;
    virtual bool isMousePressed(const std::string &key) = 0;

    virtual bool isMousePressed(KeyMouse keyMouse) = 0;

    virtual bool isMouseReleased(const std::string &key) = 0;

    virtual bool isMouseReleased(KeyMouse keyMouse) = 0;

    virtual Uniti::Vector2f getPosition() = 0;

    virtual std::vector<std::string> &getEvents() = 0;

    virtual void clearEvents() = 0;
};
