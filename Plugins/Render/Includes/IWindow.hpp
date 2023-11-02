//
// Created by youba on 28/10/2023.
//

#pragma once

#include "json/value.h"
#include "IPrintable.hpp"
#include "IInput.hpp"
#include "IMouse.hpp"

class IWindow {
public:
    virtual ~IWindow() = default;

    virtual bool isOpen() const = 0;

    virtual void close() = 0;

    virtual void display() = 0;

    virtual void create(const Json::Value &value) = 0;

    virtual void print(IPrintable &printable) = 0;

    virtual IInput &getInput() = 0;

    virtual IMouse &getMouse() = 0;
};
