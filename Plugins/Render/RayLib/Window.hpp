//
// Created by youba on 05/11/2023.
//

#pragma once

#include "IWindow.hpp"
#include "Input.hpp"
#include "Mouse.hpp"
#include <vector>
#include <functional>

class Window : public IWindow {
public:
    Window();

    bool isOpen() const override;

    void close() override;

    void display() override;

    void create(const Json::Value &value) override;

    void print(IPrintable &printable) override;

    IInput &getInput() override;

    IMouse &getMouse() override;

private:
    std::vector<std::reference_wrapper<IPrintable>> _printable;
    Input _input;
    Mouse _mouse;
};