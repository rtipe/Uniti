//
// Created by youba on 01/11/2023.
//

#pragma once

#include "IObjectPlugin.hpp"
#include "IWindow.hpp"

class Button : public Uniti::IObjectPlugin {
public:
    Button(Uniti::Object &object);
    // Constructor for the Button class.

    Uniti::Object &getObject() override;
    // Returns a reference to the associated Object.

    void awake(const Json::Value &value) override;
    // Called when the Button is awakened and initializes it based on the provided JSON value.

    void preStart() override;
    // Called before the Button's main start() method. Can be used for pre-start setup.

    void start() override;
    // Called when the Button is starting its functionality.

    void postStart() override;
    // Called after the Button has started. Can be used for post-start actions.

    void preUpdate() override;
    // Called before the update() method. Useful for pre-update preparations.

    void update() override;
    // The main update method for the Button. Called to update the Button's behavior.

    void postUpdate() override;
    // Called after the update() method. Can be used for post-update tasks.

    void preEnd() override;
    // Called before the Button is ending or being destroyed.

    void end() override;
    // The method to end the Button's functionality, typically called when it's being removed or deactivated.

    void postEnd() override;
    // Called after the end() method, used for post-end clean-up.

    const Uniti::Clock &getClock() const override;
    // Returns a constant reference to the Clock associated with the Button.

    Uniti::Clock &getClock() override;
    // Returns a reference to the Clock associated with the Button.

    const Uniti::Event &getEvent() const override;
    // Returns a constant reference to the Event associated with the Button.

    Uniti::Event &getEvent() override;
    // Returns a reference to the Event associated with the Button.

private:
    Uniti::Object &_object;
    Uniti::Clock _clock;
    Uniti::Event _event;
    float _width;
    float _height;
};
