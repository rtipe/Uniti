//
// Created by youba on 29/10/2023.
//

#include "Movement.hpp"
#include "Vector.hpp"

Movement::Movement(Uniti::Object &object, Collision &collision) : _object(object), _collision(collision) {}

void Movement::moveTo(const Uniti::Vector2f &position, float speed) {
    this->_to = position;
    this->_speed = speed;
    this->_isTo = true;
}

void Movement::moveForward(float speed) {
    this->move({0, -1}, speed);
}

void Movement::moveForward(float speed, float deltaTime) {
    this->move({0, -1}, speed, deltaTime);
}

void Movement::moveBackward(float speed, float deltaTime) {
    this->move({0, -1}, speed, deltaTime);
}

void Movement::moveBackward(float speed) {
    this->move({0, -1}, speed);
}

void Movement::moveLeft(float speed, float deltaTime) {
    this->move({-1, 0}, speed, deltaTime);
}

void Movement::moveLeft(float speed) {
    this->move({-1, 0}, speed);
}

void Movement::moveRight(float speed, float deltaTime) {
    this->move({1, 0}, speed, deltaTime);
}

void Movement::moveRight(float speed) {
    this->move({1, 0}, speed);
}

void Movement::move(const Uniti::Vector2f &normal, float speed) {
    this->move(normal, speed, this->_clock.getSeconds());
}

void Movement::move(const Uniti::Vector2f &normal, float speed, float deltaTime) {
    this->_isTo = false;
    Uniti::Vector2f position(this->_object.getTransform().getPosition());
    Uniti::Vector2f newPosition = position + normal * speed * deltaTime;
    this->_object.getTransform().getPosition().setX(newPosition.getX());
    this->_object.getTransform().getPosition().setY(newPosition.getY());
    auto isCollided = Collision::isCollided(this->_object);
    auto isOverlapped = Collision::isOverlapped(this->_object);
    if (isCollided && !this->_collision.isOverlap()) {
        isCollided.value().get().emitEvent("collided", this->_object.getName());
        this->_object.getTransform().getPosition().operator=(position);
    }
    if (isOverlapped)
        isOverlapped.value().get().emitEvent("overlapped", this->_object.getName());
}

void Movement::cancelMovement() {
    this->_isTo = false;
}

bool Movement::isMoving() const {
    return this->_isTo;
}

float Movement::getSpeed() const {
    return this->_speed;
}

void Movement::setSpeed(float speed) {
    this->_speed = speed;
}

void Movement::update() {
    if (this->_isTo) {
        Uniti::Vector2f position = this->_object.getTransform().getPosition();
        Uniti::Vector2f normal = Uniti::Vector::getNormal({position.getX(), position.getY()}, this->_to);
        this->move(normal, this->_speed);
        this->_isTo = true;
        Uniti::Vector2f newPosition = this->_object.getTransform().getPosition();
        Uniti::Vector2f round = normal * this->_speed * this->_clock.getSeconds();
        round.set(abs(round.getX()) + 1, abs(round.getY()) + 1);
        Uniti::Vector2f roundPosition = newPosition - this->_to;
        roundPosition.set(abs(roundPosition.getX()), abs(roundPosition.getY()));
        if (round.getX() > roundPosition.getX() && round.getY() > roundPosition.getY())
            this->_isTo = false;
    }
}

const Uniti::Clock &Movement::getClock() const {
    return this->_clock;
}

Uniti::Clock &Movement::getClock() {
    return this->_clock;
}
