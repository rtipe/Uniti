//
// Created by youba on 27/10/2023.
//

#pragma once

#include "ICorePlugin.hpp"

class test : public Uniti::ICorePlugin {
public:
    test(Uniti::Core &core) : _core(core) {}

    Uniti::Core &getCore();

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
};
