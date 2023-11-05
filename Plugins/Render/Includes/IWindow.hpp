//
// Created by youba on 28/10/2023.
//

#pragma once

#include "json/value.h"
#include "IPrintable.hpp"
#include "IInput.hpp"
#include "IMouse.hpp"

/** @brief Interface for managing a graphical window and user input.
*/
class IWindow {
public:
    /** @brief Virtual destructor for the IWindow interface.
    */
    virtual ~IWindow() = default;

    /** @brief Check if the window is open.
        @return bool: True if the window is open, otherwise false.
    */
    virtual bool isOpen() const = 0;

    /** @brief Close the window.
    */
    virtual void close() = 0;

    /** @brief Display the window.
    */
    virtual void display() = 0;

    /** @brief Create a window based on the provided JSON configuration.
        @param const Json::Value &value: JSON configuration for window creation.
    */
    virtual void create(const Json::Value &value) = 0;

    /** @brief Print a printable object on the window.
        @param IPrintable &printable: The printable object to be displayed.
    */
    virtual void print(IPrintable &printable) = 0;

    /** @brief Get the input manager for the window.
        @return IInput&: A reference to the input manager.
    */
    virtual IInput &getInput() = 0;

    /** @brief Get the mouse manager for the window.
        @return IMouse&: A reference to the mouse manager.
    */
    virtual IMouse &getMouse() = 0;
};

