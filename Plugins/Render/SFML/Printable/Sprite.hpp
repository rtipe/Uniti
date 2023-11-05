//
// Created by youba on 28/10/2023.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "ISprite.hpp"

/** @brief Sprite class for handling and rendering sprite-based objects.
*/
class Sprite : public ISprite {
public:
    /** @brief Constructor for the Sprite class.
        @param sf::RenderWindow &window: Reference to the game window for rendering.
    */
    Sprite(sf::RenderWindow &window);

    /** @brief Set the texture for the sprite from a JSON value.
        @param const Json::Value &value: JSON value specifying the texture.
    */
    void setTexture(const Json::Value &value);

    /** @brief Set the texture rectangle for the sprite.
        @param const Uniti::Box &box: Box specifying the texture rectangle.
    */
    void setTextureRect(const Uniti::Box &box);

    /** @brief Set the color of the sprite.
        @param const Uniti::Color &color: Color to apply to the sprite.
    */
    void setColor(const Uniti::Color &color);

    // IPrintable interface implementation:

    /** @brief Display and render the sprite on the game window.
    */
    void display();

    /** @brief Get the type name of the sprite.
        @return const std::string&: Constant reference to the type name.
    */
    const std::string &getTypeName() const;

    /** @brief Get the position of the sprite.
        @return const Uniti::Vector2f&: Constant reference to the position.
    */
    const Uniti::Vector2f &getPosition() const;

    /** @brief Get the scale of the sprite.
        @return const Uniti::Vector2f&: Constant reference to the scale.
    */
    const Uniti::Vector2f &getScale() const;

    /** @brief Get the rotation of the sprite.
        @return const float: Constant float representing the rotation.
    */
    const float getRotation() const;

    /** @brief Get the Z-index of the sprite.
        @return const float: Constant float representing the Z-index.
    */
    const float getZIndex() const;

    /** @brief Set the position of the sprite.
        @param const Uniti::Vector2f &position: New position for the sprite.
    */
    void setPosition(const Uniti::Vector2f &position);

    /** @brief Set the scale of the sprite.
        @param const Uniti::Vector2f &scale: New scale for the sprite.
    */
    void setScale(const Uniti::Vector2f &scale);

    /** @brief Set the rotation of the sprite.
        @param float rotation: New rotation for the sprite.
    */
    void setRotation(float rotation);

    /** @brief Set the Z-index of the sprite.
        @param float zIndex: New Z-index for the sprite.
    */
    void setZIndex(float zIndex);

    /** @brief Set the origin point of the sprite.
        @param const Uniti::Vector2f &origin: New origin point for the sprite.
    */
    void setOrigin(const Uniti::Vector2f &origin);

private:
    sf::RenderWindow &_window;
    sf::Sprite _sprite;
    sf::Texture _texture;
    const std::string _type = "sprite";
    Uniti::Vector2f _position;
    Uniti::Vector2f _scale;
    Uniti::Vector2f _origin;
    float _zIndex = 0;
    float _rotation = 0;
};
