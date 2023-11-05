//
// Created by youba on 05/11/2023.
//

#pragma once

#include "Window.hpp"
#include "IRenderPlugin.hpp"

class RenderPlugin : public IRenderPlugin {
public:
    RenderPlugin(Uniti::Core &core);

    Uniti::Core &getCore();

    const IWindow &getWindow() const;

    IWindow &getWindow();

    void awake(const Json::Value &value);

    void preStart();

    void start();

    void postStart();

    void preUpdate();

    void update();

    void postUpdate();

    void preEnd();

    void end();

    void postEnd();

    const Uniti::Clock &getClock() const;

    Uniti::Clock &getClock();

    const Uniti::Event &getEvent() const;

    Uniti::Event &getEvent();

private:
    Uniti::Core &_core;
    Uniti::Event _event;
    Uniti::Clock _clock;
    int _framerateLimit;
    Window _window;
};