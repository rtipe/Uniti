//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Transform.hpp"
#include "IObjectPlugin.hpp"
#include "ObjectPluginManager.hpp"
#include <optional>

namespace Uniti {
    class Object;
    class Scene;

    class Core;
    class ObjectManager {
    public:
        /**
         * @brief Construct a new Object Manager object
         *
         * @param scene
         */
        ObjectManager(const Json::Value &value, Scene &scene);
        /**
         * @brief Construct a new Object Manager object
         *
         * @param objects
         * @param core
         */
        ObjectManager(const std::vector<std::unique_ptr<Object>> &objects, Core &core);

        template<typename... Args>
        void add(Args &&... __args) {
            this->add(std::make_unique<Object>(__args...));
        }
        /**
         * @brief Add a object object
         *
         * @param object
         */
        void add(std::unique_ptr<Object> object);
        /**
         * @brief Remove a object object
         *
         * @param name
         */
        void remove(const std::string &name);
        /**
         * @brief Get the Object object
         *
         * @param name
         * @return Object&
         */
        const std::vector<std::unique_ptr<Object>> &getObjects() const;
        /**
         * @brief Get the Object object
         *
         * @param name
         * @return Object&
         */
        std::vector<std::unique_ptr<Object>> &getObjects();
        /**
         * @brief Get the Object object
         *
         * @param name
         * @return Object&
         */
        void update();
        /**
         * @brief Get the Object object
         *
         * @param name
         * @return Object&
         */
        void end();
        /**
         * @brief Get the Object object
         *
         * @param name
         * @return Object&
         */
        void emitEvent(const std::string &name, const Json::Value &value);
        /**
         * @brief Get the Object object
         *
         * @param name
         * @return Object&
         */
        const Object &operator[](const std::string &name) const;
        /**
         * @brief Get the Object object
         *
         * @param name
         * @return Object&
         */
        Object &operator[](const std::string &name);
        /**
         * @brief Get the Object object
         *
         * @param name
         * @return Object&
         */
        const Core &getCore() const;
        /**
         * @brief Get the Object object
         *
         * @param name
         * @return Object&
         */
        Core &getCore();
    private:
        Core &_core;
        std::vector<std::unique_ptr<Object>> _objects;
        std::vector<std::unique_ptr<Object>> _inObjects;
        std::vector<std::string> _outObjects;
    };
    class Object {
    public:
        Object(const std::string &name, Scene &scene);
        Object(Object &object);
        Object(const Json::Value &value, Scene &scene);
        Object(Scene &scene, const std::string &fileName);
        void update();
        void end();
        void setName(const std::string &name);
        const std::string &getName() const;
        std::string &getName();
        void setEnable(bool value);
        bool isEnabled() const;
        const Transform &getTransform() const;
        Transform &getTransform();
        const ObjectManager &getChildren() const;
        ObjectManager &getChildren();
        const Scene &getScene() const;
        Scene &getScene();
        template<typename PLUGIN>
        PLUGIN &get(const std::string &name) {
            return dynamic_cast<PLUGIN &>(this->_objectPluginManager.get(name));
        }

        template<typename PLUGIN>
        const PLUGIN &get(const std::string &name) const {
            return dynamic_cast<PLUGIN &>(this->_objectPluginManager.get(name));
        }
        const Object &operator[](const std::string &name) const;
        Object &operator[](const std::string &name);
        void emitEvent(const std::string &name, const Json::Value &value);
        const ObjectPluginManager &getPluginManager() const;
        ObjectPluginManager &getPluginManager();
        const Json::Value &getValue() const;
        Json::Value &getValue();

        static std::optional<std::reference_wrapper<Object>>
        find(const std::string &name, const Core &core, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const Scene &scene, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const ObjectManager &objectManager, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const Object &object, bool recursive = true);

        static std::optional<std::reference_wrapper<Object>>
        find_if(const Core &core, std::function<bool(const Object &object)>, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find_if(const Scene &scene, std::function<bool(const Object &object)> function, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find_if(const ObjectManager &objectManager, std::function<bool(const Object &object)> function, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find_if(const Object &object, std::function<bool(const Object &object)> function, bool recursive = true);
        static Json::Value openJsonFile(const std::string &fileName);

        const Core &getCore() const;

        Core &getCore();
    private:
        Core &_core;
        Json::Value _value;
        Scene &_scene;
        ObjectManager _objectManager;
        std::string _name;
        ObjectPluginManager _objectPluginManager;
        Transform _transform;
        bool _isEnabled = true;
    };
}
