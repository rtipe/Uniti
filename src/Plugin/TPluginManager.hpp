//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include "PluginFactory.hpp"
#include "json/value.h"

namespace Uniti {
    template<typename Handler, typename Interface>
    class TPluginManager {
    public:
        void add(const std::string &name, const Json::Value &value) {
            this->_plugins[name] = PluginFactory<Handler, Interface>::getFactory().get();
            this->_plugins[name].awake(value);
        }
        void remove(const std::string &name) {
            if (_plugins.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            PluginFactory<Handler, Interface>::getFactory().removeElement(name, this->_plugins.at(name).get());
            this->_plugins.erase(name);
        }
        const Interface &get(const std::string &name) const {
            if (_plugins.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            return this->_plugins.at(name).get();
        }
        Interface &get(const std::string &name) {
            if (_plugins.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            return this->_plugins.at(name).get();
        }
        bool has(const std::string &name) const {
            return this->_plugins.contains(name);
        }
        void update() {
            for (auto &element : this->_plugins)
                element.second.get().preUpdate();
            for (auto &element : this->_plugins)
                element.second.get().update();
            for (auto &element : this->_plugins)
                element.second.get().postUpdate();
        }
        void start() {
            for (auto &element : this->_plugins)
                element.second.get().preStart();
            for (auto &element : this->_plugins)
                element.second.get().start();
            for (auto &element : this->_plugins)
                element.second.get().postStart();
        }
        void end() {
            for (auto &element : this->_plugins)
                element.second.get().preEnd();
            for (auto &element : this->_plugins)
                element.second.get().end();
            for (auto &element : this->_plugins)
                element.second.get().postEnd();
        }
        void emitEvent(const std::string &name, const Json::Value &value) {
            for (auto &element : this->_plugins)
                element.second.get().getEvent().emitEvent(name, value);
        }
    private:
        std::map<std::string, std::reference_wrapper<Interface>> _plugins;
    };
}
