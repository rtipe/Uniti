//
// Created by youba on 28/10/2023.
//

#pragma once

#include "Core.hpp"
#include "IRenderPlugin.hpp"
#include "Window.hpp"

/** @brief RenderPlugin class responsible for managing rendering functionality.
*/
class RenderPlugin : public IRenderPlugin {
public:
    /** @brief Constructor for the RenderPlugin class.
        @param Uniti::Core &core: Reference to the core of the application.
    */
    RenderPlugin(Uniti::Core &core);

    /** @brief Get a reference to the core of the application.
        @return Uniti::Core&: Reference to the core.
    */
    Uniti::Core &getCore();

    /** @brief Get a constant reference to the window.
        @return const IWindow&: Constant reference to the window.
    */
    const IWindow &getWindow() const;

    /** @brief Get a reference to the window.
        @return IWindow&: Reference to the window.
    */
    IWindow &getWindow();

    /** @brief Perform actions when the plugin is awakened.
        Typically used for initialization.
    */
    void awake(const Json::Value &value);

    /** @brief Perform actions before the start phase.
    */
    void preStart();

    /** @brief Perform actions during the start phase.
    */
    void start();

    /** @brief Perform actions after the start phase.
    */
    void postStart();

    /** @brief Perform actions before the update phase.
    */
    void preUpdate();

    /** @brief Perform actions during the update phase.
    */
    void update();

    /** @brief Perform actions after the update phase.
    */
    void postUpdate();

    /** @brief Perform actions before the end phase.
    */
    void preEnd();

    /** @brief Perform actions during the end phase.
    */
    void end();

    /** @brief Perform actions after the end phase.
    */
    void postEnd();

    /** @brief Get a constant reference to the clock.
        @return const Uniti::Clock&: Constant reference to the clock.
    */
    const Uniti::Clock &getClock() const;

    /** @brief Get a reference to the clock.
        @return Uniti::Clock&: Reference to the clock.
    */
    Uniti::Clock &getClock();

    /** @brief Get a constant reference to the event manager.
        @return const Uniti::Event&: Constant reference to the event manager.
    */
    const Uniti::Event &getEvent() const;

    /** @brief Get a reference to the event manager.
        @return Uniti::Event&: Reference to the event manager.
    */
    Uniti::Event &getEvent();

private:
    Uniti::Core &_core;
    Uniti::Event _event;
    Uniti::Clock _clock;
    int _framerateLimit;
    Window _window;
};
