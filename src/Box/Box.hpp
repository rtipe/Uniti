//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Vector2f.hpp"
#include "Logger.hpp"

namespace Uniti {
    class Box {
    public:
        Box(const Json::Value &value);
        Box(float x, float y, float width, float height);
        const Vector2f &getPosition() const;
        Vector2f &getPosition();
        const Vector2f &getDimension() const;
        Vector2f &getDimension();
        const float getX() const;
        float getX();
        const float getY() const;
        float getY();
        const float getWidth() const;
        float getWidth();
        const float getHeight() const;
        float getHeight();
        void setPosition(const Vector2f &position);

        void setDimension(const Vector2f &dimension);
        void setX(float x);
        void setY(float y);
        void setWidth(float width);
        void setHeight(float height);
        bool isInside(const Vector2f &point) const;
        bool isInside(const Vector2f &point, const Vector2f &parent) const;
        bool isInside(const Box &box) const;
        bool isInside(const Box &box, const Vector2f &parentA, const Vector2f &parentB) const;
    private:
        Vector2f _position;
        Vector2f _dimension;
    };
}

std::ostream& operator<<(std::ostream& os, const Uniti::Box &box);
Uniti::Logger& operator<<(Uniti::Logger& os, const Uniti::Box &box);
