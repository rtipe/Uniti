//
// Created by youba on 01/11/2023.
//

#pragma once

#include "IObjectPlugin.hpp"
#include "IWindow.hpp"

/** @brief Button class that implements the IObjectPlugin interface.
*/
class Button : public Uniti::IObjectPlugin {
public:
    /** @brief Constructor for the Button class.
        @param Uniti::Object &object: Reference to the associated Object.
    */
    Button(Uniti::Object &object);

    /** @brief Get the associated Object.
        @return Uniti::Object&: Reference to the associated Object.
    */
    Uniti::Object &getObject() override;

    /** @brief Called when the Button is awakened and initializes it based on the provided JSON value.
        @param const Json::Value &value: JSON configuration for the Button.
    */
    void awake(const Json::Value &value) override;

    /** @brief Called before the Button's main start() method. Can be used for pre-start setup.
    */
    void preStart() override;

    /** @brief Called when the Button is starting its functionality.
    */
    void start() override;

    /** @brief Called after the Button has started. Can be used for post-start actions.
    */
    void postStart() override;

    /** @brief Called before the update() method. Useful for pre-update preparations.
    */
    void preUpdate() override;

    /** @brief The main update method for the Button. Called to update the Button's behavior.
    */
    void update() override;

    /** @brief Called after the update() method. Can be used for post-update tasks.
    */
    void postUpdate() override;

    /** @brief Called before the Button is ending or being destroyed.
    */
    void preEnd() override;

    /** @brief The method to end the Button's functionality, typically called when it's being removed or deactivated.
    */
    void end() override;

    /** @brief Called after the end() method, used for post-end clean-up.
    */
    void postEnd() override;

    /** @brief Get associated Clock (constant reference).
        @return const Uniti::Clock&: Constant reference to the associated Clock.
    */
    const Uniti::Clock &getClock() const override;

    /** @brief Get associated Clock (reference).
        @return Uniti::Clock&: Reference to the associated Clock.
    */
    Uniti::Clock &getClock() override;

    /** @brief Get associated Event (constant reference).
        @return const Uniti::Event&: Constant reference to the associated Event.
    */
    const Uniti::Event &getEvent() const override;

    /** @brief Get associated Event (reference).
        @return Uniti::Event&: Reference to the associated Event.
    */
    Uniti::Event &getEvent() override;

private:
    Uniti::Object &_object;
    Uniti::Clock _clock;
    Uniti::Event _event;
    float _width;
    float _height;
};

