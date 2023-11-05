//
// Created by youba on 05/11/2023.
//

#pragma once

#include "ISprite.hpp"

extern "C"
{
#include <raylib.h>
}

class Sprite : public ISprite {
public:
    Sprite();

    ~Sprite();

    void setTexture(const Json::Value &value);

    void setTextureRect(const Uniti::Box &box);

    void setColor(const Uniti::Color &color);

    void display();

    const std::string &getTypeName() const;

    const Uniti::Vector2f &getPosition() const;

    const Uniti::Vector2f &getScale() const;

    const float getRotation() const;

    const float getZIndex() const;

    void setPosition(const Uniti::Vector2f &position);

    void setScale(const Uniti::Vector2f &scale);

    void setRotation(float rotation);

    void setZIndex(float zIndex);

    void setOrigin(const Uniti::Vector2f &origin);

private:
    Texture2D _texture;
    const std::string _type = "sprite";
    Uniti::Box _textureRect = {0, 0, 0, 0};
    Uniti::Vector2f _position;
    Uniti::Vector2f _scale;
    Uniti::Vector2f _origin;
    float _zIndex = 0;
    float _rotation = 0;
};