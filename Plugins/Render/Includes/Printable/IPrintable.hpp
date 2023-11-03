//
// Created by youba on 28/10/2023.
//

#pragma once

#include <string>
#include "Vector2f.hpp"

class IPrintable {
public:
    virtual ~IPrintable() = default;

    virtual void display() = 0;

    virtual const std::string &getTypeName() const = 0;

    virtual const Uniti::Vector2f &getPosition() const = 0;

    virtual const Uniti::Vector2f &getScale() const = 0;

    virtual const float getRotation() const = 0;

    virtual const float getZIndex() const = 0;

    virtual void setPosition(const Uniti::Vector2f &position) = 0;

    virtual void setScale(const Uniti::Vector2f &scale) = 0;

    virtual void setRotation(float rotation) = 0;

    virtual void setZIndex(float zIndex) = 0;

    virtual void setOrigin(const Uniti::Vector2f &origin) = 0;
};
