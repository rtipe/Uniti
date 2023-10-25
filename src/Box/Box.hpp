//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Vector2f.hpp"
#include "Logger.hpp"

namespace Uniti {
    class Box {
        Box(const Json::Value &value);
        Box(float x, float y, float width, float height);
        const Vector2f &getPosition() const;
        Vector2f &getPosition();
        const Vector2f &getDimension() const;
        Vector2f &getDimension();
        const float &getX() const;
        float &getX();
        const float &getY() const;
        float &getY();
        const float &getWidth() const;
        float &getWidth();
        const float &getHeight() const;
        float &getHeight();
        bool isInside(const Vector2f &point) const;
        bool isInside(const Vector2f &point, const Vector2f &parent) const;
        bool isInside(const Box &box) const;
        bool isInside(const Box &box, const Vector2f &parentA, const Vector2f &parentB) const;
    };
}

std::ostream& operator<<(std::ostream& os, const Uniti::Box &box);
Uniti::Logger& operator<<(Uniti::Logger& os, const Uniti::Box &box);
