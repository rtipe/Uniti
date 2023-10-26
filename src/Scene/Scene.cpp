//
// Created by youba on 25/10/2023.
//

#include "Scene.hpp"

namespace Uniti {
    Scene::Scene(const Json::Value &scene, const std::string &name):
    _value(scene),
    _name(name),
    _objectManager(scene["objects"], *this),
    _pluginManager(scene["plugins"], *this) {}

    void Scene::update() {
        this->_pluginManager.postUpdate();
        this->_objectManager.update();
        this->_pluginManager.update();
        this->_pluginManager.preUpdate();
    }

    const ObjectManager &Scene::getObjects() const {
        return this->_objectManager;
    }

    ObjectManager &Scene::getObjects() {
        return this->_objectManager;
    }

    const std::string &Scene::getName() const {
        return this->_name;
    }

    void Scene::addEventListener(const std::string &name, eventFunction function) {
        this->_event.addEvent(name, function);
    }

    void Scene::emitEvent(const std::string &name, const Json::Value &value) {
        this->_event.emitEvent(name, value);
        this->_pluginManager.emitEvent(name, value);
        this->_objectManager.emitEvent(name, value);
    }

    const ScenePluginManager &Scene::getPluginManager() const {
        return this->_pluginManager;
    }

    ScenePluginManager &Scene::getPluginManager() {
        return this->_pluginManager;
    }

    const Object &Scene::operator[](const std::string &name) const {
        return this->_objectManager.operator[](name);
    }

    Object &Scene::operator[](const std::string &name) {
        return this->_objectManager.operator[](name);
    }

    void Scene::end() {
        this->_pluginManager.postEnd();
        this->_objectManager.end();
        this->_pluginManager.end();
        this->_pluginManager.postEnd();
    }
}