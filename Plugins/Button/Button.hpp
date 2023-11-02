//
// Created by youba on 01/11/2023.
//

#pragma once

#include "IObjectPlugin.hpp"
#include "IWindow.hpp"

class Button : public Uniti::IObjectPlugin {
public:
    Button(Uniti::Object &object);

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
    Uniti::Object &_object;
    Uniti::Clock _clock;
    Uniti::Event _event;
    float _width;
    float _height;
};