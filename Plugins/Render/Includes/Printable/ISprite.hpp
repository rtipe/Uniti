//
// Created by youba on 28/10/2023.
//

#pragma once

#include "IPrintable.hpp"
#include "Box.hpp"
#include "Color.hpp"

/** @brief Interface for sprite objects implementing IPrintable functionality.
*/
class ISprite : public IPrintable {
public:
    /** @brief Virtual destructor for the ISprite interface.
    */
    virtual ~ISprite() = default;

    /** @brief Set the texture of the sprite based on the provided JSON value.
        @param value: A JSON value describing the sprite's texture.
    */
    virtual void setTexture(const Json::Value &value) = 0;

    /** @brief Set the texture rectangle of the sprite using a bounding box.
        @param box: A bounding box defining the area of the texture to be displayed.
    */
    virtual void setTextureRect(const Uniti::Box &box) = 0;

    /** @brief Set the color of the sprite.
        @param color: The color to apply to the sprite.
    */
    virtual void setColor(const Uniti::Color &color) = 0;
};

