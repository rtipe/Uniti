//
// Created by youba on 28/10/2023.
//

#pragma once

#include "IPrintable.hpp"
#include "Box.hpp"
#include "Color.hpp"

class ISprite : public IPrintable {
public:
    virtual ~ISprite() = default;

    virtual void setTexture(const Json::Value &value) = 0;

    virtual void setTextureRect(const Uniti::Box &box) = 0;

    virtual void setColor(const Uniti::Color &color) = 0;
};
