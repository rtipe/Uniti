//
// Created by youba on 28/10/2023.
//

#pragma once

#include <string>
#include <vector>

class IInput {
public:
    enum Key {
        Unknown = -1,
        A = 0,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        Num0,
        Num1,
        Num2,
        Num3,
        Num4,
        Num5,
        Num6,
        Num7,
        Num8,
        Num9,
        Escape,
        LControl,
        LShift,
        LAlt,
        LSystem,
        RControl,
        RShift,
        RAlt,
        RSystem,
        Menu,
        LBracket,
        RBracket,
        Semicolon,
        Comma,
        Period,
        Apostrophe,
        Slash,
        Backslash,
        Grave,
        Equal,
        Hyphen,
        Space,
        Enter,
        Backspace,
        Tab,
        PageUp,
        PageDown,
        End,
        Home,
        Insert,
        Delete,
        Add,
        Subtract,
        Multiply,
        Divide,
        Left,
        Right,
        Up,
        Down,
        Numpad0,
        Numpad1,
        Numpad2,
        Numpad3,
        Numpad4,
        Numpad5,
        Numpad6,
        Numpad7,
        Numpad8,
        Numpad9,
        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        F13,
        F15,
        F14,
        Pause
    };

    /** @brief Virtual destructor for the IInput class.
    */
    virtual ~IInput() = default;

    /** @brief Update method to process and update input state.
    */
    virtual void update() = 0;

    /** @brief Check if a specific key (by string representation) is currently pressed.
        @param const std::string &key: The key to check.
        @return bool: True if the key is currently pressed; otherwise, false.
    */
    virtual bool isPressed(const std::string &key) = 0;

    /** @brief Check if a specific keyboard key is currently pressed.
        @param Key key: The keyboard key to check.
        @return bool: True if the key is currently pressed; otherwise, false.
    */
    virtual bool isPressed(Key key) = 0;

    /** @brief Check if a specific key (by string representation) is currently released.
        @param const std::string &key: The key to check.
        @return bool: True if the key is currently released; otherwise, false.
    */
    virtual bool isReleased(const std::string &key) = 0;

    /** @brief Check if a specific keyboard key is currently released.
        @param Key key: The keyboard key to check.
        @return bool: True if the key is currently released; otherwise, false.
    */
    virtual bool isReleased(Key key) = 0;

    /** @brief Get a reference to a list of input events.
        @return std::vector<std::string>&: Reference to the list of input events.
    */
    virtual std::vector<std::string> &getEvents() = 0;

    /** @brief Clear the list of input events.
    */
    virtual void clearEvents() = 0;
};
