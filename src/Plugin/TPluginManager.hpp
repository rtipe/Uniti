//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include "PluginFactory.hpp"
#include "json/value.h"

namespace Uniti {
    template<typename Handler, typename Interface, typename Parent>
    class TPluginManager {
    public:
        TPluginManager(TPluginManager &pluginManager):
        _parent(pluginManager._parent),
        _value(pluginManager._value) {
            for (const auto &plugin : pluginManager._value) {
                auto name = plugin["name"].asString();
                this->add(name, plugin);
            }
            this->preStart();
            this->start();
            this->postStart();
        }
        TPluginManager(const Json::Value &plugins, Parent &parent):
        _parent(parent),
        _value(plugins) {
            for (const Json::Value &plugin : plugins) {
                auto name = plugin["name"].asString();
                this->add(name, plugin);
            }
            this->preStart();
            this->start();
            this->postStart();
        }
        ~TPluginManager() {
            for (auto &element : this->_plugins)
                PluginFactory<Handler, Interface, Parent>::getFactory().removeElement(element.first, element.second.get());
        }
        void add(const std::string &name, const Json::Value &value) {
            this->_plugins.emplace(name, PluginFactory<Handler, Interface, Parent>::getFactory().get(name, _parent));
            this->_plugins.at(name).get().awake(value);
        }
        void remove(const std::string &name) {
            if (_plugins.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            PluginFactory<Handler, Interface, Parent>::getFactory().removeElement(name, this->_plugins.at(name).get());
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
        void preUpdate() {
            for (auto &element : this->_plugins)
                element.second.get().preUpdate();
        }
        void update() {
            for (auto &element : this->_plugins)
                element.second.get().update();
        }
        void postUpdate() {
            for (auto &element : this->_plugins)
                element.second.get().postUpdate();
        }
        void preStart() {
            for (auto &element : this->_plugins)
                element.second.get().preStart();
        }
        void start() {
            for (auto &element : this->_plugins)
                element.second.get().start();
        }
        void postStart() {
            for (auto &element : this->_plugins)
                element.second.get().postStart();
        }
        void preEnd() {
            for (auto &element : this->_plugins)
                element.second.get().preEnd();
        }
        void end() {
            for (auto &element : this->_plugins)
                element.second.get().end();
        }
        void postEnd() {
            for (auto &element : this->_plugins)
                element.second.get().postEnd();
        }
        void emitEvent(const std::string &name, const Json::Value &value) {
            for (auto &element : this->_plugins)
                element.second.get().getEvent().emitEvent(name, value);
        }
    private:
        Parent &_parent;
        Json::Value _value;
        std::map<std::string, std::reference_wrapper<Interface>> _plugins;
    };
}
