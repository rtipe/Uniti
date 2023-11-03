//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Clock.hpp"
#include "Event.hpp"

namespace Uniti {
    class IPlugin {
    public:
        virtual ~IPlugin() = default;
        virtual void awake(const Json::Value &value) = 0;
        virtual void preStart() = 0;
        virtual void start() = 0;
        virtual void postStart() = 0;
        virtual void preUpdate() = 0;
        virtual void update() = 0;
        virtual void postUpdate() = 0;
        virtual void preEnd() = 0;
        virtual void end() = 0;
        virtual void postEnd() = 0;
        virtual const Clock &getClock() const = 0;
        virtual Clock &getClock() = 0;
        virtual const Event &getEvent() const = 0;
        virtual Event &getEvent() = 0;
    };
}