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
        _value(pluginManager._value),
        _logger(pluginManager._logger),
        _factory(pluginManager.getFactory()) {
            for (const auto &plugin : pluginManager._value) {
                auto name = plugin["name"].asString();
                this->add(name, plugin);
            }
            this->preStart();
            this->start();
            this->postStart();
        }

        TPluginManager(const Json::Value &plugins, Parent &parent, Logger &logger,
                       PluginFactory<Handler, Interface, Parent> &factory) :
        _parent(parent),
        _value(plugins),
        _logger(logger),
        _factory(factory) {
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
                this->_factory.removeElement(element.first, element.second.get());
        }

        /** @brief Add a new plugin using configuration data.
            @param const std::string &name: The name of the plugin.
            @param const Json::Value &value: JSON configuration data for the plugin.
        */
        void add(const std::string &name, const Json::Value &value) {
            std::string oldPath = this->_logger.getPath();
            this->_logger.changePath(this->_logger.getPath() + " > Plugin:" + name + " awake()");
            try {
                this->_plugins.emplace(name, this->_factory.get(name, _parent));
                this->_logger.Info("start");
                this->_plugins.at(name).get().awake(value);
            } catch (std::exception &e) {
                this->_logger.Danger(e.what());
            }
            this->_logger.changePath(oldPath);
        }

        /** @brief Add a new plugin using an existing Interface element.
            @param const std::string &name: The name of the plugin.
            @param Interface &element: An existing plugin element.
            @param const Json::Value &value: JSON configuration data for the plugin.
        */
        void add(const std::string &name, Interface &element, const Json::Value &value) {
            std::string oldPath = this->_logger.getPath();
            this->_logger.changePath(this->_logger.getPath() + " > Plugin:" + name + " awake()");
            try {
                this->_plugins.emplace(name, element);
                this->_logger.Info("start");
                this->_plugins.at(name).get().awake(value);
            } catch (std::exception &e) {
                this->_logger.Danger(e.what());
            }
            this->_logger.changePath(oldPath);
        }

        /** @brief Remove a plugin by name.
            @param const std::string &name: The name of the plugin to remove.
        */
        void remove(const std::string &name) {
            if (_plugins.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            this->_factory.removeElement(name, this->_plugins.at(name).get());
            this->_plugins.erase(name);
        }

        /** @brief Get a constant reference to a plugin by name.
            @param const std::string &name: The name of the plugin to retrieve.
            @return const Interface &: Constant reference to the plugin.
        */
        const Interface &get(const std::string &name) const {
            if (_plugins.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            return this->_plugins.at(name).get();
        }

        /** @brief Get a reference to a plugin by name.
            @param const std::string &name: The name of the plugin to retrieve.
            @return Interface &: Reference to the plugin.
        */
        Interface &get(const std::string &name) {
            if (_plugins.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            return this->_plugins.at(name).get();
        }

        /** @brief Check if a plugin exists by name.
            @param const std::string &name: The name of the plugin to check.
            @return bool: True if the plugin exists, false otherwise.
        */
        bool has(const std::string &name) const {
            return this->_plugins.contains(name);
        }

        /** @brief Perform pre-update actions for all plugins.
        */
        void preUpdate() {
            for (auto &element: this->_plugins) {
                std::string oldPath = this->_logger.getPath();
                this->_logger.changePath(this->_logger.getPath() + " > Plugin:" + element.first + " preUpdate()");
                try {
                    element.second.get().preUpdate();
                } catch (std::exception &e) {
                    this->_logger.Danger(e.what());
                }
                this->_logger.changePath(oldPath);
            }
        }

        /** @brief Perform update actions for all plugins.
        */
        void update() {
            for (auto &element: this->_plugins) {
                std::string oldPath = this->_logger.getPath();
                this->_logger.changePath(this->_logger.getPath() + " > Plugin:" + element.first + " update()");
                try {
                    element.second.get().update();
                } catch (std::exception &e) {
                    this->_logger.Danger(e.what());
                }
                this->_logger.changePath(oldPath);
            }
        }

        /** @brief Perform post-update actions for all plugins.
        */
        void postUpdate() {
            for (auto &element: this->_plugins) {
                std::string oldPath = this->_logger.getPath();
                this->_logger.changePath(this->_logger.getPath() + " > Plugin:" + element.first + " postUpdate()");
                try {
                    element.second.get().postUpdate();
                } catch (std::exception &e) {
                    this->_logger.Danger(e.what());
                }
                this->_logger.changePath(oldPath);
            }
        }

        /** @brief Perform pre-start actions for all plugins.
        */
        void preStart() {
            for (auto &element: this->_plugins) {
                std::string oldPath = this->_logger.getPath();
                this->_logger.changePath(this->_logger.getPath() + " > Plugin:" + element.first + " preStart()");
                try {
                    element.second.get().preStart();
                } catch (std::exception &e) {
                    this->_logger.Danger(e.what());
                }
                this->_logger.changePath(oldPath);
            }
        }

        /** @brief Start all plugins.
        */
        void start() {
            for (auto &element: this->_plugins) {
                std::string oldPath = this->_logger.getPath();
                this->_logger.changePath(this->_logger.getPath() + " > Plugin:" + element.first + " start()");
                try {
                    element.second.get().start();
                } catch (std::exception &e) {
                    this->_logger.Danger(e.what());
                }
                this->_logger.changePath(oldPath);
            }
        }

        /** @brief Perform post-start actions for all plugins.
        */
        void postStart() {
            for (auto &element: this->_plugins) {
                std::string oldPath = this->_logger.getPath();
                this->_logger.changePath(this->_logger.getPath() + " > Plugin:" + element.first + " postStart()");
                try {
                    element.second.get().postStart();
                } catch (std::exception &e) {
                    this->_logger.Danger(e.what());
                }
                this->_logger.changePath(oldPath);
            }
        }

        /** @brief Perform pre-end actions for all plugins.
        */
        void preEnd() {
            for (auto &element: this->_plugins) {
                std::string oldPath = this->_logger.getPath();
                this->_logger.changePath(this->_logger.getPath() + " > Plugin:" + element.first + " preEnd()");
                try {
                    element.second.get().preEnd();
                } catch (std::exception &e) {
                    this->_logger.Danger(e.what());
                }
                this->_logger.changePath(oldPath);
            }
        }

        /** @brief End all plugins.
        */
        void end() {
            for (auto &element: this->_plugins) {
                std::string oldPath = this->_logger.getPath();
                this->_logger.changePath(this->_logger.getPath() + " > Plugin:" + element.first + " end()");
                try {
                    element.second.get().end();
                } catch (std::exception &e) {
                    this->_logger.Danger(e.what());
                }
                this->_logger.changePath(oldPath);
            }
        }

        /** @brief Perform post-end actions for all plugins.
        */
        void postEnd() {
            for (auto &element: this->_plugins) {
                std::string oldPath = this->_logger.getPath();
                this->_logger.changePath(this->_logger.getPath() + " > Plugin:" + element.first + " postEnd()");
                try {
                    element.second.get().postEnd();
                } catch (std::exception &e) {
                    this->_logger.Danger(e.what());
                }
                this->_logger.changePath(oldPath);
            }
        }

        /** @brief Emit an event to all plugins.
            @param const std::string &name: The name of the event.
            @param const Json::Value &value: JSON data associated with the event.
        */
        void emitEvent(const std::string &name, const Json::Value &value) {
            for (auto &element: this->_plugins) {
                std::string oldPath = this->_logger.getPath();
                this->_logger.changePath(this->_logger.getPath() + " > Plugin:" + element.first + " Event:" + name);
                element.second.get().getEvent().emitEvent(name, value, _logger);
                this->_logger.changePath(oldPath);
            }
        }

        /** @brief Get the factory for creating plugins.
            @return PluginFactory<Handler, Interface, Parent> &: Reference to the plugin factory.
        */
        PluginFactory<Handler, Interface, Parent> &getFactory() {
            return this->_factory;
        }
    private:
        Parent &_parent;
        Logger &_logger;
        Json::Value _value;
        PluginFactory<Handler, Interface, Parent> &_factory;
        std::map<std::string, std::reference_wrapper<Interface>> _plugins;
    };
}
