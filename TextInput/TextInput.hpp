//
// Created by youba on 01/11/2023.
//

#pragma once

#include "IObjectPlugin.hpp"
#include "IWindow.hpp"

class TextInput : public Uniti::IObjectPlugin {
public:
    TextInput(Uniti::Object &object);

    Uniti::Object &getObject() override;

    void awake(const Json::Value &value) override;

    void preStart() override;

    void start() override;

    void postStart() override;

    void preUpdate() override;

    void update() override;

    void postUpdate() override;

    void preEnd() override;

    void end() override;

    void postEnd() override;

    const Uniti::Clock &getClock() const override;

    Uniti::Clock &getClock() override;

    const Uniti::Event &getEvent() const override;

    Uniti::Event &getEvent() override;

private:
    void checkActive();

    void writeInputField();

    std::optional<std::reference_wrapper<IWindow>> _window;
    Uniti::Object &_object;
    Uniti::Event _event;
    Uniti::Clock _clock;
    bool _active;
    float _height;
    float _width;
    int _maxChar;
    std::string _current;
};