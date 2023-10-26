//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Transform.hpp"
#include "IObjectPlugin.hpp"
#include "ObjectPluginManager.hpp"

namespace Uniti {
    class Object;
    class Scene;
    class ObjectManager {
    public:
        ObjectManager(const Json::Value &value, Scene &scene);
        ObjectManager(const std::vector<std::unique_ptr<Object>> &objects);
        void add(std::unique_ptr<Object> object);
        void remove(const std::string &name);
        const std::vector<std::unique_ptr<Object>> &getObjects() const;
        std::vector<std::unique_ptr<Object>> &getObjects();
        void update();
        void emitEvent(const std::string &name, const Json::Value &value);
        const Object &operator[](const std::string &name) const;
        Object &operator[](const std::string &name);
    };
    class Object {
    public:
        Object(const std::string &name, Scene &scene);
        Object(Object &object);
        Object(const Json::Value &value, Scene &scene);
        Object(Scene &scene, const std::string &fileName);
        void update();
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
        const Object &operator[](const std::string &name) const;
        Object &operator[](const std::string &name);
        void emitEvent(const std::string &name, const Json::Value &value);
        const ObjectPluginManager &getPluginManager() const;
        ObjectPluginManager &getPluginManager();
        const Json::Value &getValue() const;
        Json::Value &getValue();
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const Scene &scene, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const ObjectManager &objectManager, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const Object &object, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find_if(std::function<bool(const Object &object)>, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find_if(const Scene &scene, std::function<bool(const Object &object)> function, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find_if(const ObjectManager &objectManager, std::function<bool(const Object &object)> function, bool recursive = true);
        static std::optional<std::reference_wrapper<Object>> find_if(const Object &object, std::function<bool(const Object &object)> function, bool recursive = true);
    private:
        static Json::Value openJsonFile(const std::string &fileName);
        Json::Value _value;
        Scene &_scene;
        ObjectManager _objectManager;
        std::string _name;
        ObjectPluginManager _objectPluginManager;
        Transform _transform;
        bool _isEnabled = true;
    };
}
