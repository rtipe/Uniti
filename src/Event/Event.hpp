//
// Created by youba on 25/10/2023.
//

#pragma once

#include <functional>
#include "json/value.h"
#include "Logger.hpp"

namespace Uniti {
    using eventFunction = std::function<void(const Json::Value &value)>;
    class Event {
    public:
        std::size_t addEvent(const std::string &name, eventFunction function);
        void removeEvent(const std::string &name);
        void removeEvent(const std::string &name, std::size_t id);

        void emitEvent(const std::string &name, const Json::Value &value, Logger &logger);
    private:
        std::map<std::string, std::vector<eventFunction>> _events;
    };
}
