//
// Created by youba on 31/10/2023.
//

#include "JavascriptPlugin.hpp"
#include "JSEvent.hpp"
#include "Core.hpp"

void JSEvent::emitEvent(const std::string &name, const Json::Value &value, Uniti::Logger &logger) {
    try {
        JavascriptPlugin &plugin = this->_object.getCore().get<JavascriptPlugin &>("JSScriptPlugin");
        Json::Value newValue;
        newValue["data"] = value;
        newValue["id"] = this->_object.getName();
        plugin.emitJSEvent(name, newValue);
    } catch (std::exception &e) {
        logger.Danger("Error while catching event for JS...");
    }
    Event::emitEvent(name, value, logger);
}

JSEvent::JSEvent(Uniti::Object &object) : _object(object) {}
