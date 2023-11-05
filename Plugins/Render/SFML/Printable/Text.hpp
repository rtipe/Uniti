//
// Created by youba on 28/10/2023.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "IText.hpp"

/** @brief Text class for handling and rendering text-based objects.
*/
class Text : public IText {
public:
    /** @brief Constructor for the Text class.
        @param sf::RenderWindow &window: Reference to the game window for rendering.
    */
    Text(sf::RenderWindow &window);

    /** @brief Set the string content of the text.
        @param const std::string &text: New text string.
    */
    void setString(const std::string &text);

    /** @brief Set the font for rendering the text from a file path.
        @param const std::string &path: File path to the font.
    */
    void setFont(const std::string &path);

    /** @brief Set the character size of the text.
        @param unsigned int size: New character size.
    */
    void setCharacterSize(unsigned int size);

    /** @brief Set the style of the text (e.g., bold, italic, regular).
        @param TextStyle style: Text style to apply.
    */
    void setStyle(TextStyle style);

    /** @brief Set the color of the text.
        @param const Uniti::Color &color: Color to apply to the text.
    */
    void setColor(const Uniti::Color &color);

    // IPrintable interface implementation:

    /** @brief Get the string content of the text.
        @return const std::string: Constant reference to the text string.
    */
    const std::string getString() const;

    /** @brief Display and render the text on the game window.
    */
    void display();

    /** @brief Get the type name of the text.
        @return const std::string&: Constant reference to the type name.
    */
    const std::string &getTypeName() const;

    /** @brief Get the position of the text.
        @return const Uniti::Vector2f&: Constant reference to the position.
    */
    const Uniti::Vector2f &getPosition() const;

    /** @brief Get the scale of the text.
        @return const Uniti::Vector2f&: Constant reference to the scale.
    */
    const Uniti::Vector2f &getScale() const;

    /** @brief Get the rotation of the text.
        @return const float: Constant float representing the rotation.
    */
    const float getRotation() const;

    /** @brief Get the Z-index of the text.
        @return const float: Constant float representing the Z-index.
    */
    const float getZIndex() const;

    /** @brief Set the position of the text.
        @param const Uniti::Vector2f &position: New position for the text.
    */
    void setPosition(const Uniti::Vector2f &position);

    /** @brief Set the scale of the text.
        @param const Uniti::Vector2f &scale: New scale for the text.
    */
    void setScale(const Uniti::Vector2f &scale);

    /** @brief Set the rotation of the text.
        @param float rotation: New rotation for the text.
    */
    void setRotation(float rotation);

    /** @brief Set the Z-index of the text.
        @param float zIndex: New Z-index for the text.
    */
    void setZIndex(float zIndex);

    /** @brief Set the origin point of the text.
        @param const Uniti::Vector2f &origin: New origin point for the text.
    */
    void setOrigin(const Uniti::Vector2f &origin);

private:
    sf::RenderWindow &_window;
    sf::Text _text;
    sf::Font _font;
    const std::string _type = "text";
    Uniti::Vector2f _position;
    Uniti::Vector2f _scale;
    Uniti::Vector2f _origin;
    float _zIndex = 0;
    float _rotation = 0;
};
