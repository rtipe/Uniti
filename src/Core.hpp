//
// Created by youba on 25/10/2023.
//

#pragma once

#include <map>
#include <string>
#include <memory>
#include <thread>
#include <boost/lockfree/queue.hpp>
#include <mutex>
#include "Logger.hpp"
#include "json/value.h"
#include "SceneManager.hpp"
#include "ICorePlugin.hpp"
#include "CorePluginManager.hpp"

namespace Uniti {
    class Core {
    public:
        Core(const Json::Value &value);
        ~Core();
        void start();
        void stop();
        Core &getSubInstance(const std::string &name);
        std::map<std::string, std::tuple<std::unique_ptr<Core>, std::thread>> &getSubInstances();
        void openSubInstance(const std::string &name);
        void openSubInstance(const Json::Value &value);
        bool closeSubInstance(const std::string &name);
        const Core &operator[](const std::string &name) const;
        Core &operator[](const std::string &name);
        const SceneManager &getSceneManager() const;
        SceneManager &getSceneManager();
        const Json::Value &getData() const;
        Json::Value &getData();
        template<typename PLUGIN>
        PLUGIN &get(const std::string &name) {
            return dynamic_cast<PLUGIN>(this->_pluginManager.get(name));
        }

        template<typename PLUGIN>
        const PLUGIN &get(const std::string &name) const {
            return dynamic_cast<PLUGIN>(this->_pluginManager.get(name));
        }
        void addEventListener(const std::string &name, eventFunction);
        void emitEvent(const std::string &name, const Json::Value &value);

        const Logger &log() const;

        Logger &log();
    private:
        Logger _logger;
        std::map<std::string, std::tuple<std::unique_ptr<Core>, std::thread>> _subInstances;
        CorePluginManager _pluginManager;
        SceneManager _sceneManager;
        Json::Value _value;
        boost::lockfree::queue<std::tuple<std::string, Json::Value> *> _queue;
        bool _stop = false;
        std::mutex _mutexForStop;
        Event _event;
    };
}
