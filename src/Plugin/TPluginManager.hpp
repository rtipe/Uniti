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
            std::string oldPath = Logger::getPath();
            Logger::changePath(Logger::getPath() + " > Plugin:" + this->_name + " awake()");
            try {
                this->_plugins.emplace(name,
                                       PluginFactory<Handler, Interface, Parent>::getFactory().get(name, _parent));
                Logger::Info("start");
                this->_plugins.at(name).get().awake(value);
            } catch (std::exception &e) {
                Logger::Danger(e.what());
            }
            Logger::changePath(oldPath);
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
            for (auto &element: this->_plugins) {
                std::string oldPath = Logger::getPath();
                Logger::changePath(Logger::getPath() + " > Plugin:" + element.first + " preUpdate()");
                try {
                    element.second.get().preUpdate();
                } catch (std::exception &e) {
                    Logger::Danger(e.what());
                }
                Logger::changePath(oldPath);
            }
        }
        void update() {
            for (auto &element: this->_plugins) {
                std::string oldPath = Logger::getPath();
                Logger::changePath(Logger::getPath() + " > Plugin:" + element.first + " update()");
                try {
                    element.second.get().update();
                } catch (std::exception &e) {
                    Logger::Danger(e.what());
                }
                Logger::changePath(oldPath);
            }
        }
        void postUpdate() {
            for (auto &element: this->_plugins) {
                std::string oldPath = Logger::getPath();
                Logger::changePath(Logger::getPath() + " > Plugin:" + element.first + " postUpdate()");
                try {
                    element.second.get().postUpdate();
                } catch (std::exception &e) {
                    Logger::Danger(e.what());
                }
                Logger::changePath(oldPath);
            }
        }
        void preStart() {
            for (auto &element: this->_plugins) {
                std::string oldPath = Logger::getPath();
                Logger::changePath(Logger::getPath() + " > Plugin:" + element.first + " preStart()");
                try {
                    element.second.get().preStart();
                } catch (std::exception &e) {
                    Logger::Danger(e.what());
                }
                Logger::changePath(oldPath);
            }
        }
        void start() {
            for (auto &element: this->_plugins) {
                std::string oldPath = Logger::getPath();
                Logger::changePath(Logger::getPath() + " > Plugin:" + element.first + " start()");
                try {
                    element.second.get().start();
                } catch (std::exception &e) {
                    Logger::Danger(e.what());
                }
                Logger::changePath(oldPath);
            }
        }
        void postStart() {
            for (auto &element: this->_plugins) {
                std::string oldPath = Logger::getPath();
                Logger::changePath(Logger::getPath() + " > Plugin:" + element.first + " postStart()");
                try {
                    element.second.get().postStart();
                } catch (std::exception &e) {
                    Logger::Danger(e.what());
                }
                Logger::changePath(oldPath);
            }
        }
        void preEnd() {
            for (auto &element: this->_plugins) {
                std::string oldPath = Logger::getPath();
                Logger::changePath(Logger::getPath() + " > Plugin:" + element.first + " preEnd()");
                try {
                    element.second.get().preEnd();
                } catch (std::exception &e) {
                    Logger::Danger(e.what());
                }
                Logger::changePath(oldPath);
            }
        }
        void end() {
            for (auto &element: this->_plugins) {
                std::string oldPath = Logger::getPath();
                Logger::changePath(Logger::getPath() + " > Plugin:" + element.first + " end()");
                try {
                    element.second.get().end();
                } catch (std::exception &e) {
                    Logger::Danger(e.what());
                }
                Logger::changePath(oldPath);
            }
        }
        void postEnd() {
            for (auto &element: this->_plugins) {
                std::string oldPath = Logger::getPath();
                Logger::changePath(Logger::getPath() + " > Plugin:" + element.first + " postEnd()");
                try {
                    element.second.get().postEnd();
                } catch (std::exception &e) {
                    Logger::Danger(e.what());
                }
                Logger::changePath(oldPath);
            }
        }
        void emitEvent(const std::string &name, const Json::Value &value) {
            for (auto &element: this->_plugins) {
                std::string oldPath = Logger::getPath();
                Logger::changePath(Logger::getPath() + " > Plugin:" + element.first + " Event:" + name);
                element.second.get().getEvent().emitEvent(name, value);
                Logger::changePath(oldPath);
            }
        }
    private:
        Parent &_parent;
        Json::Value _value;
        std::map<std::string, std::reference_wrapper<Interface>> _plugins;
    };
}
