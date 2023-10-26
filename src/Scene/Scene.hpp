//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Object.hpp"
#include "IScenePlugin.hpp"
#include "ScenePluginManager.hpp"

namespace Uniti {
    class Scene {
    public:
        Scene(const Json::Value &scene, const std::string &name = "");
        void update();
        const ObjectManager &getObjects() const;
        ObjectManager &getObjects();
        const std::string &getName() const;
        template<typename PLUGIN>
        PLUGIN &get(const std::string &name) {
            return dynamic_cast<PLUGIN &>(this->_pluginManager.get(name));
        }
        void addEventListener(const std::string &name, eventFunction);
        void emitEvent(const std::string &name, const Json::Value &value);
        const ScenePluginManager &getPluginManager() const;
        ScenePluginManager &getPluginManager();
        const Object &operator[](const std::string &name) const;
        Object &operator[](const std::string &name);
    private:
        Event _event;
        ObjectManager _objectManager;
        ScenePluginManager _pluginManager;
        std::string _name;
        Json::Value _value;
    };
}
