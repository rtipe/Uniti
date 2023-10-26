//
// Created by youba on 25/10/2023.
//

#include <filesystem>
#include <fstream>
#include <string>
#include "json/json.h"
#include "Object.hpp"

namespace Uniti {
    Object::Object(const std::string &name, Scene &scene):
    _objectManager({}, scene),
    _name(name),
    _objectPluginManager({}, *this),
    _scene(scene) {}

    Object::Object(Object &object):
    _value(object.getValue()),
    _name(object.getName() + std::string("_clone")),
    _objectManager(object.getChildren().getObjects()),
    _objectPluginManager(object.getPluginManager()),
    _transform(object.getTransform()),
    _scene(object.getScene()) {}

    Object::Object(const Json::Value &value, Scene &scene):
    _value(value),
    _name(value["name"].asString()),
    _objectManager(value["children"], scene),
    _objectPluginManager(value["plugins"], *this),
    _transform(value["transform"]),
    _isEnabled(value.get("isEnable", true).asBool()),
    _scene(scene) {}

    Object::Object(Scene &scene, const std::string &fileName):
    _value(openJsonFile(fileName)),
    _name(_value["name"].asString()),
    _objectManager(_value["children"], scene),
    _objectPluginManager(_value["plugins"], *this),
    _transform(_value["transform"]),
    _isEnabled(_value.get("isEnable", true).asBool()),
    _scene(scene) {}

    void Object::update() {
        if (!this->_isEnabled) return;
        this->_objectPluginManager.update();
        this->_objectManager.update();
    }

    void Object::setName(const std::string &name) {
        this->_name = name;
    }

    const std::string &Object::getName() const {
        return this->_name;
    }

    std::string &Object::getName() {
        return this->_name;
    }

    void Object::setEnable(bool value) {
        this->_isEnabled = value;
    }

    bool Object::isEnabled() const {
        return this->_isEnabled;
    }

    const Transform &Object::getTransform() const {
        return this->_transform;
    }

    Transform &Object::getTransform() {
        return this->_transform;
    }

    const ObjectManager &Object::getChildren() const {
        return this->_objectManager;
    }

    ObjectManager &Object::getChildren() {
        return this->_objectManager;
    }

    const Scene &Object::getScene() const {
        return this->_scene;
    }

    Scene &Object::getScene() {
        return this->_scene;
    }

    const Object &Object::operator[](const std::string &name) const {
        return this->_objectManager.operator[](name);
    }

    Object &Object::operator[](const std::string &name) {
        return this->_objectManager.operator[](name);
    }

    void Object::emitEvent(const std::string &name, const Json::Value &value) {
        this->_objectPluginManager.emitEvent(name, value);
        this->_objectManager.emitEvent(name, value);
    }

    const ObjectPluginManager &Object::getPluginManager() const {
        return this->_objectPluginManager;
    }

    ObjectPluginManager &Object::getPluginManager() {
        return this->_objectPluginManager;
    }

    const Json::Value &Object::getValue() const {
        return this->_value;
    }

    Json::Value &Object::getValue() {
        return this->_value;
    }

    Json::Value Object::openJsonFile(const std::string &fileName) {
        std::ifstream file(fileName);
        Json::Value project;
        file >> project;
        return project;
    }
}