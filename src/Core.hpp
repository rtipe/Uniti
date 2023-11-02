//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <filesystem>
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

        const CorePluginManager &getPluginManager() const;

        CorePluginManager &getPluginManager();

        PluginFactory<PluginHandler<ICorePlugin, IPluginCreator<ICorePlugin, Core>, Core>, ICorePlugin, Core> &
        getCoreFactory();

        PluginFactory<PluginHandler<IObjectPlugin, IPluginCreator<IObjectPlugin, Object>, Object>, IObjectPlugin, Object> &
        getObjectFactory();

        PluginFactory<PluginHandler<IScenePlugin, IPluginCreator<IScenePlugin, Scene>, Scene>, IScenePlugin, Scene> &
        getSceneFactory();

        void loadCoreFactory(const std::string &directory);

        void loadObjectFactory(const std::string &directory);

        void loadSceneFactory(const std::string &directory);

        template<typename Handler, typename Interface, typename Parent>
        void load(const std::string &directory, PluginFactory<Handler, Interface, Parent> &factory) {
            if (directory.empty()) return;
            std::string directoryCopy = directory;
            std::string currentFilePath;
            std::string fileName;

            for (const auto &entry: std::filesystem::directory_iterator(directoryCopy)) {
                currentFilePath = entry.path().string();
                fileName = entry.path().filename().string();
                size_t found = fileName.find('.');
                std::replace(currentFilePath.begin(), currentFilePath.end(), '\\', '/');
                factory.add(fileName.substr(0, found), std::make_unique<Handler>(currentFilePath));
            }
        }
    private:
        Logger _logger;
        std::map<std::string, std::tuple<std::unique_ptr<Core>, std::thread>> _subInstances;
        PluginFactory<PluginHandler<ICorePlugin, IPluginCreator<ICorePlugin, Core>, Core>, ICorePlugin, Core> _coreFactory;
        PluginFactory<PluginHandler<IObjectPlugin, IPluginCreator<IObjectPlugin, Object>, Object>, IObjectPlugin, Object> _objectFactory;
        PluginFactory<PluginHandler<IScenePlugin, IPluginCreator<IScenePlugin, Scene>, Scene>, IScenePlugin, Scene> _sceneFactory;
        CorePluginManager _pluginManager;
        SceneManager _sceneManager;
        Json::Value _value;
        boost::lockfree::queue<std::tuple<std::string, Json::Value> *> _queue;
        bool _stop = false;
        std::mutex _mutexForStop;
        Event _event;
    };
}
