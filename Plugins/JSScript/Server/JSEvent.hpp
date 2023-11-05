//
// Created by youba on 31/10/2023.
//

#pragma once

#include "Event.hpp"
#include "Object.hpp"

/** @brief JSEvent class that extends the Event class to emit JavaScript events for an Object.
*/
class JSEvent : public Uniti::Event {
public:
    /** @brief Constructor for the JSEvent class.
        @param Uniti::Object &object: Reference to the Object associated with the event.
    */
    JSEvent(Uniti::Object &object);

    /** @brief Emit a custom event from an Object.
        @param const std::string &name: Name of the custom event.
        @param const Json::Value &value: JSON data associated with the event.
        @param Uniti::Logger &logger: Reference to the logger for logging event details.
    */
    void emitEvent(const std::string &name, const Json::Value &value, Uniti::Logger &logger);

private:
    Uniti::Object &_object;
};

