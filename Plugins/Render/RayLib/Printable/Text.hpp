//
// Created by youba on 05/11/2023.
//

#pragma once

extern "C"
{
#include <raylib.h>
}

#include "IText.hpp"

class Text : public IText {
public:
    Text();

    ~Text();

    void setString(const std::string &text);

    void setFont(const std::string &path);

    void setCharacterSize(unsigned int size);

    void setStyle(TextStyle style);

    void setColor(const Uniti::Color &color);

    const std::string getString() const;

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
    Font _font;
    Uniti::Color _color;
    std::string _text;
    const std::string _type = "text";
    Uniti::Vector2f _position;
    Uniti::Vector2f _scale;
    Uniti::Vector2f _origin;
    float _fontSize;
    float _zIndex = 0;
    float _rotation = 0;
};
