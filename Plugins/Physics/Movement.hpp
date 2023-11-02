//
// Created by youba on 29/10/2023.
//

#pragma once

#include "Object.hpp"
#include "Collision.hpp"

class Movement {
public:
    Movement(Uniti::Object &object, Collision &collision);

    void moveTo(const Uniti::Vector2f &position, float speed);

    void moveForward(float speed);

    void moveForward(float speed, float deltaTime);

    void moveBackward(float speed, float deltaTime);

    void moveBackward(float speed);

    void moveLeft(float speed, float deltaTime);

    void moveLeft(float speed);

    void moveRight(float speed, float deltaTime);

    void moveRight(float speed);

    void move(const Uniti::Vector2f &normal, float speed);

    void move(const Uniti::Vector2f &normal, float speed, float deltaTime);

    void cancelMovement();

    bool isMoving() const;

    float getSpeed() const;

    void setSpeed(float speed);

    void update();

    const Uniti::Clock &getClock() const;

    Uniti::Clock &getClock();

private:
    Collision &_collision;
    Uniti::Object &_object;
    float _speed = 0;
    Uniti::Vector2f _to;
    bool _isTo = false;
    Uniti::Clock _clock;
};
