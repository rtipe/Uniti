//
// Created by youba on 29/10/2023.
//

#pragma once

#include "Object.hpp"
#include "Collision.hpp"

/** @brief Movement class for controlling an object's movement and collision detection.
*/
class Movement {
public:
    /** @brief Constructor for the Movement class.
        @param Uniti::Object &object: Reference to the associated object for movement control.
        @param Collision &collision: Reference to the Collision component for collision detection.
    */
    Movement(Uniti::Object &object, Collision &collision);

    /** @brief Move the object to a specified position at a given speed.
        @param const Uniti::Vector2f &position: Destination position.
        @param float speed: Movement speed.
    */
    void moveTo(const Uniti::Vector2f &position, float speed);

    /** @brief Move the object forward at a given speed.
        @param float speed: Movement speed.
    */
    void moveForward(float speed);

    /** @brief Move the object forward at a given speed and update based on deltaTime.
        @param float speed: Movement speed.
        @param float deltaTime: Time interval.
    */
    void moveForward(float speed, float deltaTime);

    /** @brief Move the object backward at a given speed and update based on deltaTime.
        @param float speed: Movement speed.
        @param float deltaTime: Time interval.
    */
    void moveBackward(float speed, float deltaTime);

    /** @brief Move the object backward at a given speed.
        @param float speed: Movement speed.
    */
    void moveBackward(float speed);

    /** @brief Move the object to the left at a given speed and update based on deltaTime.
        @param float speed: Movement speed.
        @param float deltaTime: Time interval.
    */
    void moveLeft(float speed, float deltaTime);

    /** @brief Move the object to the left at a given speed.
        @param float speed: Movement speed.
    */
    void moveLeft(float speed);

    /** @brief Move the object to the right at a given speed and update based on deltaTime.
        @param float speed: Movement speed.
        @param float deltaTime: Time interval.
    */
    void moveRight(float speed, float deltaTime);

    /** @brief Move the object to the right at a given speed.
        @param float speed: Movement speed.
    */
    void moveRight(float speed);

    /** @brief Move the object in a specified direction with a given speed.
        @param const Uniti::Vector2f &normal: Direction vector.
        @param float speed: Movement speed.
    */
    void move(const Uniti::Vector2f &normal, float speed);

    /** @brief Move the object in a specified direction with a given speed and update based on deltaTime.
        @param const Uniti::Vector2f &normal: Direction vector.
        @param float speed: Movement speed.
        @param float deltaTime: Time interval.
    */
    void move(const Uniti::Vector2f &normal, float speed, float deltaTime);

    /** @brief Cancel any ongoing movement of the object.
    */
    void cancelMovement();

    /** @brief Check if the object is currently in motion.
        @return bool: True if the object is moving, false otherwise.
    */
    bool isMoving() const;

    /** @brief Get the current movement speed of the object.
        @return float: Current movement speed.
    */
    float getSpeed() const;

    /** @brief Set the movement speed of the object.
        @param float speed: New movement speed.
    */
    void setSpeed(float speed);

    /** @brief Update the movement status, check for collisions, and execute movements.
    */
    void update();

    /** @brief Get a constant reference to the Clock component associated with the Movement.
        @return const Uniti::Clock&: Constant reference to the Clock component.
    */
    const Uniti::Clock &getClock() const;

    /** @brief Get a reference to the Clock component associated with the Movement.
        @return Uniti::Clock&: Reference to the Clock component.
    */
    Uniti::Clock &getClock();

private:
    Collision &_collision;
    Uniti::Object &_object;
    float _speed = 0;
    Uniti::Vector2f _to;
    bool _isTo = false;
    Uniti::Clock _clock;
};
