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
        /** @brief Constructor for the Core class that initializes it with JSON configuration.
            @param const Json::Value &value: JSON configuration for Core.
        */
        Core(const Json::Value &value);

        /** @brief Destructor for the Core class.
        */
        ~Core();

        /** @brief Start the Core and its sub-instances.
        */
        void start();

        /** @brief Stop the Core and its sub-instances.
        */
        void stop();

        /** @brief Get a reference to a sub-instance of the Core by name.
            @param const std::string &name: The name of the sub-instance.
            @return Core&: Reference to the sub-instance.
        */
        Core &getSubInstance(const std::string &name);

        /** @brief Get a map of sub-instances of the Core along with their associated threads.
            @return std::map<std::string, std::tuple<std::unique_ptr<Core>, std::thread>>&: Reference to the map of sub-instances.
        */
        std::map<std::string, std::tuple<std::unique_ptr<Core>, std::thread>> &getSubInstances();

        /** @brief Open a sub-instance of the Core by name.
            @param const std::string &name: The name of the sub-instance to open.
        */
        void openSubInstance(const std::string &name);

        /** @brief Open a sub-instance of the Core using JSON configuration.
            @param const Json::Value &value: JSON configuration for the sub-instance.
        */
        void openSubInstance(const Json::Value &value);

        /** @brief Close a sub-instance of the Core by name.
            @param const std::string &name: The name of the sub-instance to close.
            @return bool: True if the sub-instance was successfully closed, false otherwise.
        */
        bool closeSubInstance(const std::string &name);

        /** @brief Get a constant reference to a sub-instance of the Core by name using array subscript operator.
            @param const std::string &name: The name of the sub-instance.
            @return const Core&: Constant reference to the sub-instance.
        */
        const Core &operator[](const std::string &name) const;

        /** @brief Get a reference to a sub-instance of the Core by name using array subscript operator.
            @param const std::string &name: The name of the sub-instance.
            @return Core&: Reference to the sub-instance.
        */
        Core &operator[](const std::string &name);

        /** @brief Get a constant reference to the SceneManager associated with the Core.
            @return const SceneManager&: Constant reference to the SceneManager.
        */
        const SceneManager &getSceneManager() const;

        /** @brief Get a reference to the SceneManager associated with the Core.
            @return SceneManager&: Reference to the SceneManager.
        */
        SceneManager &getSceneManager();

        /** @brief Get a constant reference to the JSON configuration data of the Core.
            @return const Json::Value&: Constant reference to the JSON configuration data.
        */
        const Json::Value &getData() const;

        /** @brief Get a reference to the JSON configuration data of the Core.
            @return Json::Value&: Reference to the JSON configuration data.
        */
        Json::Value &getData();

        /** @brief Get a reference to a plugin by name and type.
            @tparam PLUGIN: The type of plugin to retrieve.
            @param const std::string &name: The name of the plugin.
            @return PLUGIN&: Reference to the plugin of the specified type and name.
        */
        template<typename PLUGIN>
        PLUGIN &get(const std::string &name) {
            return dynamic_cast<PLUGIN>(this->_pluginManager.get(name));
        }

        /** @brief Get a constant reference to a plugin by name and type.
            @tparam PLUGIN: The type of plugin to retrieve.
            @param const std::string &name: The name of the plugin.
            @return const PLUGIN&: Constant reference to the plugin of the specified type and name.
        */
        template<typename PLUGIN>
        const PLUGIN &get(const std::string &name) const {
            return dynamic_cast<PLUGIN>(this->_pluginManager.get(name));
        }

        /** @brief Add an event listener to the Core.
            @param const std::string &name: The name of the event to listen for.
            @param eventFunction: The function to call when the event occurs.
        */
        void addEventListener(const std::string &name, eventFunction);

        /** @brief Emit an event with a name and JSON value to the Core.
            @param const std::string &name: The name of the event to emit.
            @param const Json::Value &value: The JSON value associated with the event.
        */
        void emitEvent(const std::string &name, const Json::Value &value);

        /** @brief Get a constant reference to the Logger associated with the Core.
            @return const Logger&: Constant reference to the Logger.
        */
        const Logger &log() const;

        /** @brief Get a reference to the Logger associated with the Core.
            @return Logger&: Reference to the Logger.
        */
        Logger &log();

        /** @brief Get a constant reference to the CorePluginManager associated with the Core.
            @return const CorePluginManager&: Constant reference to the CorePluginManager.
        */
        const CorePluginManager &getPluginManager() const;

        /** @brief Get a reference to the CorePluginManager associated with the Core.
            @return CorePluginManager&: Reference to the CorePluginManager.
        */
        CorePluginManager &getPluginManager();

        /** @brief Get a reference to the Core's plugin factory for core plugins.
            @return PluginFactory<PluginHandler<ICorePlugin, IPluginCreator<ICorePlugin, Core>, Core>>&: Reference to the plugin factory.
        */
        PluginFactory<PluginHandler<ICorePlugin, IPluginCreator<ICorePlugin, Core>, Core>> &getCoreFactory();

        /** @brief Get a reference to the Core's plugin factory for object plugins.
            @return PluginFactory<PluginHandler<IObjectPlugin, IPluginCreator<IObjectPlugin, Object>, Object>>&: Reference to the plugin factory.
        */
        PluginFactory<PluginHandler<IObjectPlugin, IPluginCreator<IObjectPlugin, Object>, Object>> &getObjectFactory();

        /** @brief Get a reference to the Core's plugin factory for scene plugins.
            @return PluginFactory<PluginHandler<IScenePlugin, IPluginCreator<IScenePlugin, Scene>, Scene>>&: Reference to the plugin factory.
        */
        PluginFactory<PluginHandler<IScenePlugin, IPluginCreator<IScenePlugin, Scene>, Scene>> &getSceneFactory();

        /** @brief Load core plugins from a specified directory into the Core's plugin factory.
            @param const std::string &directory: The directory to load core plugins from.
        */
        void loadCoreFactory(const std::string &directory);

        /** @brief Load object plugins from a specified directory into the Core's plugin factory.
            @param const std::string &directory: The directory to load object plugins from.
        */
        void loadObjectFactory(const std::string &directory);

        /** @brief Load scene plugins from a specified directory into the Core's plugin factory.
            @param const std::string &directory: The directory to load scene plugins from.
        */
        void loadSceneFactory(const std::string &directory);

        /** @brief Load plugins of a specified type from a directory into the given plugin factory.
            @tparam Handler: The plugin handler type.
            @tparam Interface: The plugin interface type.
            @tparam Parent: The parent type.
            @param const std::string &directory: The directory to load plugins from.
            @param PluginFactory<Handler, Interface, Parent> &factory: The plugin factory to load plugins into.
        */
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
        Logger _logger;  // Logger associated with the Core.
        std::map<std::string, std::tuple<std::unique_ptr<Core>, std::thread>> _subInstances;  // Sub-instances of the Core.
        PluginFactory<PluginHandler<ICorePlugin, IPluginCreator<ICorePlugin, Core>, Core>, ICorePlugin, Core> _coreFactory;  // Plugin factory for Core plugins.
        PluginFactory<PluginHandler<IObjectPlugin, IPluginCreator<IObjectPlugin, Object>, Object>, IObjectPlugin, Object> _objectFactory;  // Plugin factory for Object plugins.
        PluginFactory<PluginHandler<IScenePlugin, IPluginCreator<IScenePlugin, Scene>, Scene>, IScenePlugin, Scene> _sceneFactory;  // Plugin factory for Scene plugins.
        CorePluginManager _pluginManager;  // CorePluginManager associated with the Core.
        SceneManager _sceneManager;  // SceneManager associated with the Core.
        Json::Value _value;  // JSON configuration data for the Core.
        boost::lockfree::queue<std::tuple<std::string, Json::Value> *> _queue;  // Lock-free queue for event handling.
        bool _stop = false;  // Flag to stop the Core.
        std::mutex _mutexForStop;  // Mutex for managing stopping the Core.
        Event _event;  // Event manager associated with the Core.
    };
}

