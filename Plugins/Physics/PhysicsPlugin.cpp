//
// Created by youba on 29/10/2023.
//

#include "PhysicsPlugin.hpp"

PhysicsPlugin::PhysicsPlugin(Uniti::Object &object) :
        _object(object),
        _collision(object),
        _movement(object, _collision) {
    this->_event.addEvent("moveTo", [&](const Json::Value &value) {
        this->_movement.moveTo(value["position"], value["speed"].asFloat());
    });
    this->_event.addEvent("moveForward", [&](const Json::Value &value) {
        if (value.get("deltaTime", -1).asFloat() != -1)
            this->_movement.moveForward(value["speed"].asFloat(), value["deltaTime"].asFloat());
        else
            this->_movement.moveForward(value["speed"].asFloat());
    });
    this->_event.addEvent("moveBackward", [&](const Json::Value &value) {
        if (value.get("deltaTime", -1).asFloat() != -1)
            this->_movement.moveBackward(value["speed"].asFloat(), value["deltaTime"].asFloat());
        else
            this->_movement.moveBackward(value["speed"].asFloat());
    });
    this->_event.addEvent("moveLeft", [&](const Json::Value &value) {
        if (value.get("deltaTime", -1).asFloat() != -1)
            this->_movement.moveLeft(value["speed"].asFloat(), value["deltaTime"].asFloat());
        else
            this->_movement.moveLeft(value["speed"].asFloat());
    });
    this->_event.addEvent("moveRight", [&](const Json::Value &value) {
        if (value.get("deltaTime", -1).asFloat() != -1)
            this->_movement.moveRight(value["speed"].asFloat(), value["deltaTime"].asFloat());
        else
            this->_movement.moveRight(value["speed"].asFloat());
    });
    this->_event.addEvent("move", [&](const Json::Value &value) {
        if (value.get("deltaTime", -1).asFloat() != -1)
            this->_movement.move(value["position"], value["speed"].asFloat(), value["deltaTime"].asFloat());
        else
            this->_movement.move(value["position"], value["speed"].asFloat());
    });
    this->_event.addEvent("cancelMovement", [&](const Json::Value &value) {
        this->_movement.cancelMovement();
    });
    this->_event.addEvent("setSpeed", [&](const Json::Value &value) {
        this->_movement.setSpeed(value.asFloat());
    });
}

Uniti::Object &PhysicsPlugin::getObject() {
    return this->_object;
}

void PhysicsPlugin::awake(const Json::Value &value) {
    this->_collision.load(value);
}

void PhysicsPlugin::preStart() {

}

void PhysicsPlugin::start() {

}

void PhysicsPlugin::postStart() {

}

void PhysicsPlugin::preUpdate() {

}

void PhysicsPlugin::update() {

}

void PhysicsPlugin::postUpdate() {
    this->_movement.update();
    this->_movement.getClock().restart();
}

void PhysicsPlugin::preEnd() {

}

void PhysicsPlugin::end() {

}

void PhysicsPlugin::postEnd() {

}

const Uniti::Clock &PhysicsPlugin::getClock() const {
    return this->_movement.getClock();
}

Uniti::Clock &PhysicsPlugin::getClock() {
    return this->_movement.getClock();
}

const Uniti::Event &PhysicsPlugin::getEvent() const {
    return this->_event;
}

Uniti::Event &PhysicsPlugin::getEvent() {
    return this->_event;
}

const Collision &PhysicsPlugin::getCollision() const {
    return this->_collision;
}

Collision &PhysicsPlugin::getCollision() {
    return this->_collision;
}

const Movement &PhysicsPlugin::getMovement() const {
    return this->_movement;
}

Movement &PhysicsPlugin::getMovement() {
    return this->_movement;
}
