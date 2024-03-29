//
// Created by youba on 25/10/2023.
//

#include "Scene.hpp"
#include "Core.hpp"

namespace Uniti {
    Scene::Scene(const Json::Value &scene, Core &core, const std::string &name) :
            _core(core),
    _value(scene),
    _name(name),
    _objectManager(scene["objects"], *this),
            _pluginManager(scene["plugins"], *this, _core.log(), this->_core.getSceneFactory()) {}

    void Scene::update() {
        std::string oldPath = this->_core.log().getPath();
        this->_core.log().changePath(this->_core.log().getPath() + " > Scene:" + this->_name);
        this->_pluginManager.postUpdate();
        this->_objectManager.update();
        this->_pluginManager.update();
        this->_pluginManager.preUpdate();
        this->_core.log().changePath(oldPath);
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
        std::string oldPath = this->_core.log().getPath();
        this->_core.log().changePath(
                this->_core.log().getPath() + " > (SceneEvent -> Scene:" + this->_name + " Event:" + name + ")");
        this->_event.emitEvent(name, value, this->_core.log());
        this->_core.log().changePath(oldPath);
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
        std::string oldPath = this->_core.log().getPath();
        this->_core.log().changePath(this->_core.log().getPath() + " > Scene:" + this->_name);
        this->_pluginManager.postEnd();
        this->_objectManager.end();
        this->_pluginManager.end();
        this->_pluginManager.postEnd();
        this->_core.log().changePath(oldPath);
    }

    const Core &Scene::getCore() const {
        return this->_core;
    }

    Core &Scene::getCore() {
        return this->_core;
    }
}