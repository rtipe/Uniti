//
// Created by youba on 25/10/2023.
//

#include "Object.hpp"

namespace Uniti {
    ObjectManager::ObjectManager(const Json::Value &value, Scene &scene) {
        for (const auto &object : value)
            this->_objects.push_back(std::make_unique<Object>(object, scene));
    }

    ObjectManager::ObjectManager(const std::vector<std::unique_ptr<Object>> &objects) {
        for (const auto &object : objects)
            this->_objects.push_back(std::make_unique<Object>(*object));
    }

    void ObjectManager::add(std::unique_ptr<Object> object) {
        this->_inObjects.push_back(std::move(object));
    }

    void ObjectManager::remove(const std::string &name) {
        this->_outObjects.push_back(name);
    }

    const std::vector<std::unique_ptr<Object>> &ObjectManager::getObjects() const {
        return this->_objects;
    }

    std::vector<std::unique_ptr<Object>> &ObjectManager::getObjects() {
        return this->_objects;
    }

    void ObjectManager::update() {
        while (!this->_outObjects.empty()) {
            std::erase_if(this->_objects, [&](const std::unique_ptr<Object> &object) {
                return object->getName() == this->_outObjects.front();
            });
            this->_outObjects.erase(this->_outObjects.begin());
        }
        for (const auto &object : this->_objects)
            object->update();
        while (!this->_inObjects.empty()) {
            this->_objects.push_back(std::move(this->_inObjects[0]));
            this->_inObjects.erase(this->_inObjects.begin());
        }
    }

    void ObjectManager::emitEvent(const std::string &name, const Json::Value &value) {
        for (const auto &object : this->_objects)
            object->emitEvent(name, value);
    }

    const Object &ObjectManager::operator[](const std::string &name) const {
        for (const auto &object : this->_objects) {
            if (object->getName() == name)
                return *object;
        }
        throw std::runtime_error(name + " <- not found");
    }

    Object &ObjectManager::operator[](const std::string &name) {
        for (const auto &object : this->_objects) {
            if (object->getName() == name)
                return *object;
        }
        throw std::runtime_error(name + " <- not found");
    }
} // Uniti