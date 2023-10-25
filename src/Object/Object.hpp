//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Transform.hpp"
#include "IObjectPlugin.hpp"
#include "PluginManager.hpp"

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
        Object();
        Object(Object &object);
        Object(const Json::Value &value, Scene &scene);
        Object(const std::string &fileName);
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
        PLUGIN &get(const std::string &name);
        void add(const std::string &name, std::unique_ptr<IObjectPlugin> plugin);
        const Object &operator[](const std::string &name) const;
        Object &operator[](const std::string &name);
        void emitEvent(const std::string &name, const Json::Value &value);
        const PluginManager<IObjectPlugin> &getPluginManager() const;
        PluginManager<IObjectPlugin> &getPluginManager();
        Object &operator=(const Object &other);
    };
}
