//
// Created by youba on 05/11/2023.
//

#include "Text.hpp"

Text::Text() {}

void Text::setString(const std::string &text) {
    this->_text = text;
}

void Text::setFont(const std::string &path) {
    UnloadFont(this->_font);
    this->_font = LoadFont(path.c_str());
}

void Text::setCharacterSize(unsigned int size) {
    this->_fontSize = size;
    this->_font.baseSize = size;
}

void Text::setStyle(IText::TextStyle style) {

}

void Text::setColor(const Uniti::Color &color) {
    this->_color = color;
}

const std::string Text::getString() const {
    return this->_text;
}

void Text::display() {
    Color textColor = {
            static_cast<unsigned char>(this->_color.getR()),
            static_cast<unsigned char>(this->_color.getG()),
            static_cast<unsigned char>(this->_color.getB()),
            static_cast<unsigned char>(this->_color.getA())};
    Vector2 textPosition = {this->_position.getX(), this->_position.getY()};
    DrawTextEx(this->_font, this->_text.c_str(), textPosition, this->_fontSize, 2, textColor);
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

Text::~Text() {
    UnloadFont(this->_font);
}
