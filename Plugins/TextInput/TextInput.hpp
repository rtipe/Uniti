//
// Created by youba on 01/11/2023.
//

#pragma once

#include "IObjectPlugin.hpp"
#include "IWindow.hpp"
#include <optional>

/** @brief TextInput class for handling user input of text in the application.
*/
class TextInput : public Uniti::IObjectPlugin {
public:
    /** @brief Constructor for the TextInput class.
        @param Uniti::Object &object: The object to which this plugin is attached.
    */
    TextInput(Uniti::Object &object);

    /** @brief Get the object to which this plugin is attached.
        @return Uniti::Object&: Reference to the object.
    */
    Uniti::Object &getObject() override;

    // Lifecycle methods
    void awake(const Json::Value &value) override;
    void preStart() override;
    void start() override;
    void postStart() override;
    void preUpdate() override;
    void update() override;
    void postUpdate() override;
    void preEnd() override;
    void end() override;
    void postEnd() override;

    /** @brief Get the clock associated with this plugin.
        @return const Uniti::Clock&: Reference to the clock.
    */
    const Uniti::Clock &getClock() const override;

    /** @brief Get the clock associated with this plugin.
        @return Uniti::Clock&: Reference to the clock.
    */
    Uniti::Clock &getClock() override;

    /** @brief Get the event system associated with this plugin.
        @return const Uniti::Event&: Reference to the event system.
    */
    const Uniti::Event &getEvent() const override;

    /** @brief Get the event system associated with this plugin.
        @return Uniti::Event&: Reference to the event system.
    */
    Uniti::Event &getEvent() override;

private:
    /** @brief Check if the text input field is active for user input.
    */
    void checkActive();

    /** @brief Handle user input and update the input field.
    */
    void writeInputField();

    std::optional<std::reference_wrapper<IWindow>> _window;
    Uniti::Object &_object;
    Uniti::Event _event;
    Uniti::Clock _clock;
    bool _active;
    float _height; 
    float _width;
    int _maxChar;
    std::string _current;
};
