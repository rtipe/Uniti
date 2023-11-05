//
// Created by youba on 28/10/2023.
//

#pragma once

#include "Object.hpp"
#include "Core.hpp"
#include "IPrintablePlugin.hpp"
#include "Sprite.hpp"
#include "RenderPlugin.hpp"
#include "Text.hpp"

/** @brief PrintablePlugin class for handling printable objects in the game.
*/
class PrintablePlugin : public IPrintablePlugin {
public:
    /** @brief Constructor for the PrintablePlugin class.
        @param Uniti::Object &object: Reference to the associated game object.
    */
    PrintablePlugin(Uniti::Object &object);

    /** @brief Get a reference to the associated game object.
        @return Uniti::Object&: Reference to the associated game object.
    */
    Uniti::Object &getObject();

    /** @brief Get a constant reference to the printable object.
        @return const IPrintable&: Constant reference to the printable object.
    */
    IPrintable &getPrintable() const;

    /** @brief Get a reference to the printable object.
        @return IPrintable&: Reference to the printable object.
    */
    IPrintable &getPrintable();

    // Functions for object lifecycle and behavior:

    void awake(const Json::Value &value);

    void preStart();

    void start();

    void postStart();

    void preUpdate();

    void update();

    void postUpdate();

    void preEnd();

    void end();

    void postEnd();

    /** @brief Get the game clock associated with this printable object.
        @return const Uniti::Clock&: Constant reference to the game clock.
    */
    const Uniti::Clock &getClock() const;

    /** @brief Get the game clock associated with this printable object.
        @return Uniti::Clock&: Reference to the game clock.
    */
    Uniti::Clock &getClock();

    /** @brief Get the game event associated with this printable object.
        @return const Uniti::Event&: Constant reference to the game event.
    */
    const Uniti::Event &getEvent() const;

    /** @brief Get the game event associated with this printable object.
        @return Uniti::Event&: Reference to the game event.
    */
    Uniti::Event &getEvent();

private:
    std::optional<std::reference_wrapper<IWindow>> _window;
    Uniti::Object &_object;
    Uniti::Event _event;
    Uniti::Clock _clock;
    std::unique_ptr<IPrintable> _printable;
};

