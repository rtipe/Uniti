//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Object.hpp"
#include "IScenePlugin.hpp"
#include "ScenePluginManager.hpp"

namespace Uniti {
    class Core;
    class Scene {
    public:
        /** @brief Constructor for the Scene class.
            @param const Json::Value &scene: JSON configuration data for the scene.
            @param Core &core: Reference to the Core instance.
            @param const std::string &name: Name of the scene (optional).
        */
        Scene(const Json::Value &scene, Core &core, const std::string &name = "");

        /** @brief Update the scene, typically called once per frame.
        */
        void update();

        /** @brief End the scene, perform cleanup.
        */
        void end();

        /** @brief Get a constant reference to the ObjectManager of the scene.
            @return const ObjectManager &: Constant reference to the ObjectManager.
        */
        const ObjectManager &getObjects() const;

        /** @brief Get a reference to the ObjectManager of the scene.
            @return ObjectManager &: Reference to the ObjectManager.
        */
        ObjectManager &getObjects();

        /** @brief Get the name of the scene.
            @return const std::string &: Constant reference to the scene's name.
        */
        const std::string &getName() const;

        /** @brief Get a plugin of a specific type by name.
            @tparam PLUGIN: The type of the plugin.
            @param const std::string &name: Name of the plugin.
            @return PLUGIN &: Reference to the plugin of the specified type.
        */
        template<typename PLUGIN>
        PLUGIN &get(const std::string &name) {
            return dynamic_cast<PLUGIN &>(this->_pluginManager.get(name));
        }

        /** @brief Get a constant plugin of a specific type by name.
            @tparam PLUGIN: The type of the plugin.
            @param const std::string &name: Name of the plugin.
            @return const PLUGIN &: Constant reference to the plugin of the specified type.
        */
        template<typename PLUGIN>
        const PLUGIN &get(const std::string &name) const {
            return dynamic_cast<const PLUGIN &>(this->_pluginManager.get(name));
        }

        /** @brief Add an event listener to the scene.
            @param const std::string &name: Name of the event to listen for.
            @param eventFunction: A function to handle the event.
        */
        void addEventListener(const std::string &name, eventFunction);

        /** @brief Emit an event to the scene.
            @param const std::string &name: Name of the event to emit.
            @param const Json::Value &value: JSON data associated with the event.
        */
        void emitEvent(const std::string &name, const Json::Value &value);

        /** @brief Get a constant reference to the ScenePluginManager.
            @return const ScenePluginManager &: Constant reference to the ScenePluginManager.
        */
        const ScenePluginManager &getPluginManager() const;

        /** @brief Get a reference to the ScenePluginManager.
            @return ScenePluginManager &: Reference to the ScenePluginManager.
        */
        ScenePluginManager &getPluginManager();

        /** @brief Get a constant reference to an Object by name.
            @param const std::string &name: Name of the Object to retrieve.
            @return const Object &: Constant reference to the Object.
        */
        const Object &operator[](const std::string &name) const;

        /** @brief Get a reference to an Object by name.
            @param const std::string &name: Name of the Object to retrieve.
            @return Object &: Reference to the Object.
        */
        Object &operator[](const std::string &name);

        /** @brief Get a constant reference to the Core instance.
            @return const Core &: Constant reference to the Core instance.
        */
        const Core &getCore() const;

        /** @brief Get a reference to the Core instance.
            @return Core &: Reference to the Core instance.
        */
        Core &getCore();
    private:
        Core &_core;
        Event _event;
        ObjectManager _objectManager;
        ScenePluginManager _pluginManager;
        std::string _name;
        Json::Value _value;
    };
}
