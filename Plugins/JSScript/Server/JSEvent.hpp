//
// Created by youba on 31/10/2023.
//

#pragma once

#include "Event.hpp"
#include "Object.hpp"

class JSEvent : public Uniti::Event {
public:
    JSEvent(Uniti::Object &object);

    void emitEvent(const std::string &name, const Json::Value &value, Uniti::Logger &logger);

private:
    Uniti::Object &_object;
};
