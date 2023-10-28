//
// Created by youba on 28/10/2023.
//

#include "Text.hpp"

Text::Text(sf::RenderWindow &window) : _window(window) {}

void Text::setString(const std::string &text) {
    this->_text.setString(text);
}

void Text::setFont(const std::string &path) {
    this->_font.loadFromFile(path);
    this->_text.setFont(this->_font);
}

void Text::setCharacterSize(unsigned int size) {
    this->_text.setCharacterSize(size);
}

void Text::setStyle(IText::TextStyle style) {
    sf::Text::Style sfStyle;
    switch (style) {
        case REGULAR:
            sfStyle = sf::Text::Regular;
            break;
        case BOLD:
            sfStyle = sf::Text::Bold;
            break;
        case ITALIC:
            sfStyle = sf::Text::Italic;
            break;
        default:
            sfStyle = sf::Text::Regular;
            break;
    }
    this->_text.setStyle(sfStyle);
}

void Text::setColor(const Uniti::Color &color) {
    this->_text.setFillColor(
            {static_cast<sf::Uint8>(color.getR()),
             static_cast<sf::Uint8>(color.getG()),
             static_cast<sf::Uint8>(color.getB())});
}

const std::string Text::getString() const {
    return this->_text.getString();
}

void Text::display() {
    this->_text.setPosition(this->_position.getX(), this->_position.getY());
    this->_text.setRotation(this->_rotation);
    this->_text.setOrigin(this->_origin.getX(), this->_origin.getY());
    this->_text.setScale(this->_scale.getX(), this->_scale.getY());
    this->_window.draw(this->_text);
}

const std::string &Text::getTypeName() const {
    return this->_type;
}

const Uniti::Vector2f &Text::getPosition() const {
    return this->_position;
}

const Uniti::Vector2f &Text::getScale() const {
    return this->_scale;
}

const float Text::getRotation() const {
    return this->_rotation;
}

const float Text::getZIndex() const {
    return this->_zIndex;
}

void Text::setPosition(const Uniti::Vector2f &position) {
    this->_position = position;
}

void Text::setScale(const Uniti::Vector2f &scale) {
    this->_scale = scale;
}

void Text::setRotation(float rotation) {
    this->_rotation = rotation;
}

void Text::setZIndex(float zIndex) {
    this->_zIndex = zIndex;
}

void Text::setOrigin(const Uniti::Vector2f &origin) {
    this->_origin = origin;
}
