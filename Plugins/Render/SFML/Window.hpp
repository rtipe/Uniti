//
// Created by youba on 28/10/2023.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "IWindow.hpp"
#include "Input.hpp"
#include "Mouse.hpp"

/** @brief Window class responsible for managing the application window and user input.
*/
class Window : public IWindow {
public:
    /** @brief Constructor for the Window class.
    */
    Window();

    /** @brief Check if the window is open.
        @return bool: True if the window is open, otherwise false.
    */
    bool isOpen() const override;

    /** @brief Close the application window.
    */
    void close() override;

    /** @brief Display the contents of the window.
    */
    void display() override;

    /** @brief Create the application window based on the provided configuration.
        @param Json::Value &value: JSON configuration data for window creation.
    */
    void create(const Json::Value &value) override;

    /** @brief Print a drawable object to the window.
        @param IPrintable &printable: The object to be drawn to the window.
    */
    void print(IPrintable &printable) override;

    /** @brief Get a reference to the input system for user input.
        @return IInput&: Reference to the input system.
    */
    IInput &getInput() override;

    /** @brief Get a reference to the mouse input system.
        @return IMouse&: Reference to the mouse input system.
    */
    IMouse &getMouse() override;

    /** @brief Get a reference to the underlying SFML render window.
        @return sf::RenderWindow&: Reference to the SFML render window.
    */
    sf::RenderWindow &getRenderWindow();

private:
    sf::Event _event;
    sf::Image _icon;
    sf::RenderWindow _window;
    std::vector<std::reference_wrapper<IPrintable>> _printable;
    Input _input;
    Mouse _mouse;
};

