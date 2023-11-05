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
        /** @brief Add an event function associated with a given name.
            @param const std::string &name : Event name.
            @param eventFunction function : Event function to add.
            @return std::size_t : Unique identifier of the added event function.
        */
        std::size_t addEvent(const std::string &name, eventFunction function);

        /** @brief Remove all event functions associated with a given name.
            @param const std::string &name : Event name to remove.
        */
        void removeEvent(const std::string &name);

        /** @brief Remove a specific event function associated with a given name.
            @param const std::string &name : Event name.
            @param std::size_t id : Unique identifier of the event function to remove.
        */
        void removeEvent(const std::string &name, std::size_t id);

        /** @brief Emit a specific event with associated JSON data.
            @param const std::string &name : Name of the event to emit.
            @param const Json::Value &value : JSON data associated with the event.
            @param Logger &logger : Logging object to record information.
        */
        virtual void emitEvent(const std::string &name, const Json::Value &value, Logger &logger);

    private:
        std::map<std::string, std::vector<eventFunction>> _events;
    };
}
