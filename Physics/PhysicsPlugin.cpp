//
// Created by youba on 29/10/2023.
//

#include "PhysicsPlugin.hpp"

PhysicsPlugin::PhysicsPlugin(Uniti::Object &object) :
        _object(object),
        _collision(object),
        _movement(object, _collision) {}

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
