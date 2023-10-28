//
// Created by youba on 28/10/2023.
//

#include "Sprite.hpp"
#include <iostream>

Sprite::Sprite(sf::RenderWindow &window) : _window(window) {}

void Sprite::setTexture(const Json::Value &value) {
    this->_texture.loadFromFile(value.get("path", "").asString());
    this->_texture.setSmooth(value.get("smooth", false).asBool());
    this->_texture.setRepeated(value.get("repeat", false).asBool());
    this->_sprite.setTexture(this->_texture);
}

void Sprite::setTextureRect(const Uniti::Box &rect) {
    sf::Rect<int> box;

    box.left = rect.getPosition().getX();
    box.top = rect.getPosition().getY();
    box.width = rect.getDimension().getX();
    box.height = rect.getDimension().getY();
    this->_sprite.setTextureRect(box);
}

void Sprite::setColor(const Uniti::Color &color) {
    this->_sprite.setColor(sf::Color(color.getR(), color.getG(), color.getB()));
}

void Sprite::display() {
    this->_sprite.setPosition(this->_position.getX(), this->_position.getY());
    this->_sprite.setRotation(this->_rotation);
    this->_sprite.setOrigin(this->_origin.getX(), this->_origin.getY());
    this->_sprite.setScale(this->_scale.getX(), this->_scale.getY());
    this->_window.draw(this->_sprite);
}

const std::string &Sprite::getTypeName() const {
    return this->_type;
}

const Uniti::Vector2f &Sprite::getPosition() const {
    return this->_position;
}

const Uniti::Vector2f &Sprite::getScale() const {
    return this->_scale;
}

const float Sprite::getRotation() const {
    return this->_rotation;
}

const float Sprite::getZIndex() const {
    return this->_zIndex;
}

void Sprite::setPosition(const Uniti::Vector2f &position) {
    this->_position = position;
}

void Sprite::setScale(const Uniti::Vector2f &scale) {
    this->_scale = scale;
}

void Sprite::setRotation(float rotation) {
    this->_rotation = rotation;
}

void Sprite::setZIndex(float zIndex) {
    this->_zIndex = zIndex;
}

void Sprite::setOrigin(const Uniti::Vector2f &origin) {
    this->_origin = origin;
}
