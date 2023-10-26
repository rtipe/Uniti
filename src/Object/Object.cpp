//
// Created by youba on 25/10/2023.
//

#include <filesystem>
#include <fstream>
#include <string>
#include "json/json.h"
#include "Object.hpp"
#include "Core.hpp"

namespace Uniti {
    Object::Object(const std::string &name, Scene &scene):
    _objectManager({}, scene),
    _name(name),
    _objectPluginManager({}, *this),
    _scene(scene) {
        Logger::Info("Empty object created : " + name);
    }

    Object::Object(Object &object):
    _value(object.getValue()),
    _name(object.getName() + std::string("_clone")),
    _objectManager(object.getChildren().getObjects()),
    _objectPluginManager(object.getPluginManager()),
    _transform(object.getTransform()),
    _scene(object.getScene()) {
        Logger::Info("Clone object created : " + object.getName() + std::string("_clone"));
    }

    Object::Object(const Json::Value &value, Scene &scene):
    _value(value),
    _name(value["name"].asString()),
    _objectManager(value["children"], scene),
    _objectPluginManager(value["plugins"], *this),
    _transform(value["transform"]),
    _isEnabled(value.get("isEnable", true).asBool()),
    _scene(scene) {
        Logger::Info("Object created : " + value["name"].asString());
    }

    Object::Object(Scene &scene, const std::string &fileName):
    _value(openJsonFile(fileName)),
    _name(_value["name"].asString()),
    _objectManager(_value["children"], scene),
    _objectPluginManager(_value["plugins"], *this),
    _transform(_value["transform"]),
    _isEnabled(_value.get("isEnable", true).asBool()),
    _scene(scene) {
        Logger::Info("object created by prefab : " + _value["name"].asString() + " path : " + fileName);
    }

    void Object::update() {
        if (!this->_isEnabled) return;
        std::string oldPath = Logger::getPath();
        Logger::changePath(Logger::getPath() + " > Object:" + this->_name);
        this->_objectPluginManager.preUpdate();
        this->_objectManager.update();
        this->_objectPluginManager.update();
        this->_objectPluginManager.postUpdate();
        Logger::changePath(oldPath);
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

    std::optional<std::reference_wrapper<Object>> Object::find(const std::string &name, bool recursive)
    {
        auto global = find(name, Uniti::Core::getInstance().getSceneManager().getGlobalScene(), recursive);
        if (global)
            return global;
        auto current = find(name, Uniti::Core::getInstance().getSceneManager().getCurrentScene(), recursive);
        if (current)
            return current;
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>>
    Object::find(const std::string &name, const Scene &scene, bool recursive)
    {
        auto object = find(name, scene.getObjects(), recursive);
        if (object)
            return object;
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>>
    Object::find(const std::string &name, const ObjectManager &objectManager, bool recursive)
    {
        for (const auto &object : objectManager.getObjects()) {
            if (object->getName() == name)
                return *object;
            if (!recursive)
                continue;
            auto child = find(name, object->getChildren(), recursive);
            if (child)
                return child;
        }
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>>
    Object::find(const std::string &name, const Object &object, bool recursive)
    {
        auto child = find(name, object.getChildren(), recursive);
        if (child)
            return child;
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>>
    Object::find_if(std::function<bool(const Object &object)> function, bool recursive)
    {
        auto global = find_if(Uniti::Core::getInstance().getSceneManager().getGlobalScene(), function, recursive);
        if (global)
            return global;
        auto current = find_if(Uniti::Core::getInstance().getSceneManager().getCurrentScene(), function, recursive);
        if (current)
            return current;
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>>
    Object::find_if(const Scene &scene, std::function<bool(const Object &)> function, bool recursive)
    {
        auto object = find_if(scene.getObjects(), function, recursive);
        if (object)
            return object;
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>> Object::find_if(
            const ObjectManager &objectManager,
            std::function<bool(const Object &)> function,
            bool recursive)
    {
        for (const auto &object : objectManager.getObjects()) {
            if (function(*object))
                return *object;
            if (!recursive)
                continue;
            auto child = find_if(object->getChildren(), function, recursive);
            if (child)
                return child;
        }
        return std::nullopt;
    }

    std::optional<std::reference_wrapper<Object>>
    Object::find_if(const Object &object, std::function<bool(const Object &)> function, bool recursive)
    {
        auto child = find_if(object.getChildren(), function, recursive);
        if (child)
            return child;
        return std::nullopt;
    }

    void Object::end() {
        std::string oldPath = Logger::getPath();
        Logger::changePath(Logger::getPath() + " > Object:" + this->_name);
        this->_objectPluginManager.preEnd();
        this->_objectManager.end();
        this->_objectPluginManager.end();
        this->_objectPluginManager.postEnd();
        Logger::changePath(oldPath);
    }
}