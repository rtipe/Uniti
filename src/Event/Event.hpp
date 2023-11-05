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
        /**
         * @brief Construct a new Event object
         * @param name
         * @param function
         */
        std::size_t addEvent(const std::string &name, eventFunction function);
        /**
         * @brief Destroy the Event object
         * @param name
         */
        void removeEvent(const std::string &name);
        /**
         * @brief Destroy the Event object
         * @param name
         * @param id
         */
        void removeEvent(const std::string &name, std::size_t id);
        virtual void emitEvent(const std::string &name, const Json::Value &value, Logger &logger);
    private:
        std::map<std::string, std::vector<eventFunction>> _events;
    };
}
