//
// Created by youba on 28/10/2023.
//

#pragma once

#include <string>
#include "Vector2f.hpp"

/** @brief Interface for handling mouse input.
*/
class IMouse {
public:
    /** @brief Enumeration of supported mouse buttons.
    */
    enum KeyMouse {
        LEFT,
        RIGHT,
        MIDDLE
    };

    /** @brief Virtual destructor for the IMouse class.
    */
    virtual ~IMouse() = default;

    /** @brief Update method to process and update mouse input state.
    */
    virtual void update() = 0;

    /** @brief Check if a specific mouse button (by string representation) is currently pressed.
        @param const std::string &key: The key to check.
        @return bool: True if the mouse button is currently pressed; otherwise, false.
    */
    virtual bool isMousePressed(const std::string &key) = 0;

    /** @brief Check if a specific mouse button is currently pressed.
        @param KeyMouse keyMouse: The mouse button to check.
        @return bool: True if the mouse button is currently pressed; otherwise, false.
    */
    virtual bool isMousePressed(KeyMouse keyMouse) = 0;

    /** @brief Check if a specific mouse button (by string representation) is currently released.
        @param const std::string &key: The key to check.
        @return bool: True if the mouse button is currently released; otherwise, false.
    */
    virtual bool isMouseReleased(const std::string &key) = 0;

    /** @brief Check if a specific mouse button is currently released.
        @param KeyMouse keyMouse: The mouse button to check.
        @return bool: True if the mouse button is currently released; otherwise, false.
    */
    virtual bool isMouseReleased(KeyMouse keyMouse) = 0;

    /** @brief Get the current mouse cursor position.
        @return Uniti::Vector2f: A 2D vector representing the mouse cursor position.
    */
    virtual Uniti::Vector2f getPosition() = 0;

    /** @brief Get a reference to a list of mouse input events.
        @return std::vector<std::string>&: Reference to the list of mouse input events.
    */
    virtual std::vector<std::string> &getEvents() = 0;

    /** @brief Clear the list of mouse input events.
    */
    virtual void clearEvents() = 0;
};

