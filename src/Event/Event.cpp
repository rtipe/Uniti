//
// Created by youba on 25/10/2023.
//

#include "Event.hpp"

namespace Uniti {
    std::size_t Event::addEvent(const std::string &name, eventFunction function) {
        if (!this->_events.contains(name))
            this->_events[name] = std::vector<eventFunction>();
        this->_events[name].push_back(function);
        return this->_events[name].size() - 1;
    }

    void Event::removeEvent(const std::string &name) {
        this->_events.erase(name);
    }

    void Event::removeEvent(const std::string &name, std::size_t id) {
        this->_events[name].erase(this->_events[name].begin() + id);
    }

    void Event::emitEvent(const std::string &name, const Json::Value &value) {
        auto it = _events.find(name);
        if (it != _events.end()) {
            for (auto &function : it->second) {
                function(value);
            }
        }
    }
}