//
// Created by youba on 05/11/2023.
//

#pragma once

#include "Object.hpp"
#include "Core.hpp"
#include "IPrintablePlugin.hpp"
#include "Sprite.hpp"
#include "RenderPlugin.hpp"
#include "Text.hpp"
#include "IWindow.hpp"

class PrintablePlugin : public IPrintablePlugin {
public:
    PrintablePlugin(Uniti::Object &object);

    Uniti::Object &getObject();

    IPrintable &getPrintable() const;

    IPrintable &getPrintable();

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
    std::optional<std::reference_wrapper<IWindow>> _window;
    Uniti::Object &_object;
    Uniti::Event _event;
    Uniti::Clock _clock;
    std::unique_ptr<IPrintable> _printable;

};

