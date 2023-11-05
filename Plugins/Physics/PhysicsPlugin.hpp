//
// Created by youba on 29/10/2023.
//

#pragma once

#include "IObjectPlugin.hpp"
#include "Collision.hpp"
#include "Movement.hpp"

/** @brief PhysicsPlugin class for handling physics-related functionality of an object.
*/
class PhysicsPlugin : public Uniti::IObjectPlugin {
public:
    /** @brief Constructor for the PhysicsPlugin class.
        @param Uniti::Object &object: Reference to the associated object for physics control.
    */
    PhysicsPlugin(Uniti::Object &object);

    /** @brief Get a reference to the associated object.
        @return Uniti::Object&: Reference to the associated object.
    */
    Uniti::Object &getObject() override;

    /** @brief Called when the PhysicsPlugin is awakened and initializes it based on the provided JSON value.
        @param const Json::Value &value: JSON configuration data for the plugin.
    */
    void awake(const Json::Value &value) override;

    /** @brief Called before the object's main start() method. Can be used for pre-start setup.
    */
    void preStart() override;

    /** @brief Called when the object is starting its functionality.
    */
    void start() override;

    /** @brief Called after the object has started. Can be used for post-start actions.
    */
    void postStart() override;

    /** @brief Called before the object's main update() method. Useful for pre-update preparations.
    */
    void preUpdate() override;

    /** @brief The main update method for the PhysicsPlugin. Called to update the object's physics behavior.
    */
    void update() override;

    /** @brief Called after the object's main update() method. Can be used for post-update tasks.
    */
    void postUpdate() override;

    /** @brief Called before the object is ending or being destroyed.
    */
    void preEnd() override;

    /** @brief The method to end the object's functionality, typically called when it's being removed or deactivated.
    */
    void end() override;

    /** @brief Called after the end() method, used for post-end clean-up.
    */
    void postEnd() override;

    /** @brief Get a constant reference to the Clock component associated with the PhysicsPlugin.
        @return const Uniti::Clock&: Constant reference to the Clock component.
    */
    const Uniti::Clock &getClock() const override;

    /** @brief Get a reference to the Clock component associated with the PhysicsPlugin.
        @return Uniti::Clock&: Reference to the Clock component.
    */
    Uniti::Clock &getClock() override;

    /** @brief Get a constant reference to the Event component associated with the PhysicsPlugin.
        @return const Uniti::Event&: Constant reference to the Event component.
    */
    const Uniti::Event &getEvent() const override;

    /** @brief Get a reference to the Event component associated with the PhysicsPlugin.
        @return Uniti::Event&: Reference to the Event component.
    */
    Uniti::Event &getEvent() override;

    /** @brief Get a constant reference to the Collision component associated with the PhysicsPlugin.
        @return const Collision&: Constant reference to the Collision component.
    */
    const Collision &getCollision() const;

    /** @brief Get a reference to the Collision component associated with the PhysicsPlugin.
        @return Collision&: Reference to the Collision component.
    */
    Collision &getCollision();

    /** @brief Get a constant reference to the Movement component associated with the PhysicsPlugin.
        @return const Movement&: Constant reference to the Movement component.
    */
    const Movement &getMovement() const;

    /** @brief Get a reference to the Movement component associated with the PhysicsPlugin.
        @return Movement&: Reference to the Movement component.
    */
    Movement &getMovement();

private:
    Uniti::Object &_object;
    Collision _collision;
    Movement _movement;
    Uniti::Clock _clock;
    Uniti::Event _event;
};
