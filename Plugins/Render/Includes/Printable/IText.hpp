//
// Created by youba on 28/10/2023.
//

#pragma once

#include "IPrintable.hpp"
#include "Color.hpp"

class IText : public IPrintable {
public:
    enum TextStyle {
        BOLD,
        ITALIC,
        REGULAR
    };

    virtual ~IText() = default;

    virtual void setString(const std::string &text) = 0;

    virtual void setFont(const std::string &path) = 0;

    virtual void setCharacterSize(unsigned int size) = 0;

    virtual void setStyle(TextStyle style) = 0;

    virtual void setColor(const Uniti::Color &color) = 0;

    virtual const std::string getString() const = 0;
};
