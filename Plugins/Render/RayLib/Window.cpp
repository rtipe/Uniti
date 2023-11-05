//
// Created by youba on 05/11/2023.
//

extern "C"
{
#include <raylib.h>
}

#include "Window.hpp"
#include <iostream>
#include <algorithm>

bool Window::isOpen() const {
    return WindowShouldClose();
}

void Window::close() {
    CloseWindow();
}

void Window::display() {
    this->_input.clearEvents();
    this->_mouse.clearEvents();
    this->_input.update();
    this->_mouse.update();
    std::sort(
            this->_printable.begin(),
            this->_printable.end(),
            [](IPrintable &printable1, IPrintable &printable2) {
                return printable1.getZIndex() < printable2.getZIndex();
            });
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for (const auto &printable: this->_printable)
        printable.get().display();
    EndDrawing();
    this->_printable.clear();
}

void Window::create(const Json::Value &value) {
    int width = value.get("width", 1920).asInt();
    int height = value.get("height", 1080).asInt();
    std::string iconPath = value.get("icon", "").asString();
    std::string title = value.get("title", "undefined").asString();

    InitWindow(width, height, title.c_str());
    if (!iconPath.empty()) {
        Image iconImage = LoadImage(iconPath.c_str());
        SetWindowIcon(iconImage);
        UnloadImage(iconImage);
    }
}

void Window::print(IPrintable &printable) {
    this->_printable.emplace_back(printable);
}

IInput &Window::getInput() {
    return this->_input;
}

IMouse &Window::getMouse() {
    return this->_mouse;
}

Window::Window() :
        _mouse(),
        _input() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT);
}