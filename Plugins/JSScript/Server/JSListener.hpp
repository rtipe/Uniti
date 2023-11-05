//
// Created by youba on 31/10/2023.
//

#pragma once

#include "IObjectPlugin.hpp"
#include "JSEvent.hpp"

/** @brief JSListener class that extends the IObjectPlugin for listening to JavaScript events.
*/
class JSListener : public Uniti::IObjectPlugin {
public:
    /** @brief Constructor for the JSListener class.
        @param Uniti::Object &object: Reference to the Object associated with the listener.
    */
    JSListener(Uniti::Object &object);

    /** @brief Returns a reference to the associated Object.
        @return Uniti::Object&: Reference to the Object associated with the listener.
    */
    Uniti::Object &getObject() override;

    /** @brief Called when the listener is awakened and initializes it based on the provided JSON value.
        @param const Json::Value &value: JSON data used for initialization.
    */
    void awake(const Json::Value &value) override;

    /** @brief Called before the listener's main start() method. Can be used for pre-start setup.
    */
    void preStart() override;

    /** @brief Called when the listener is starting its functionality.
    */
    void start() override;

    /** @brief Called after the listener has started. Can be used for post-start actions.
    */
    void postStart() override;

    /** @brief Called before the update() method. Useful for pre-update preparations.
    */
    void preUpdate() override;

    /** @brief The main update method for the listener. Called to update the listener's behavior.
    */
    void update() override;

    /** @brief Called after the update() method. Can be used for post-update tasks.
    */
    void postUpdate() override;

    /** @brief Called before the listener is ending or being destroyed.
    */
    void preEnd() override;

    /** @brief The method to end the listener's functionality, typically called when it's being removed or deactivated.
    */
    void end() override;

    /** @brief Called after the end() method, used for post-end clean-up.
    */
    void postEnd() override;

    /** @brief Returns a constant reference to the Clock associated with the listener.
        @return const Uniti::Clock&: Constant reference to the Clock associated with the listener.
    */
    const Uniti::Clock &getClock() const override;

    /** @brief Returns a reference to the Clock associated with the listener.
        @return Uniti::Clock&: Reference to the Clock associated with the listener.
    */
    Uniti::Clock &getClock() override;

    /** @brief Returns a constant reference to the Event associated with the listener.
        @return const Uniti::Event&: Constant reference to the Event associated with the listener.
    */
    const Uniti::Event &getEvent() const override;

    /** @brief Returns a reference to the Event associated with the listener.
        @return Uniti::Event&: Reference to the Event associated with the listener.
    */
    Uniti::Event &getEvent() override;

private:
    Uniti::Object &_object;
    JSEvent _event;
    Uniti::Clock _clock;
};
