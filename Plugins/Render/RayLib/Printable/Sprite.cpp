//
// Created by youba on 05/11/2023.
//

#include "Sprite.hpp"

#include <iostream>

Sprite::Sprite() {}

void Sprite::setTexture(const Json::Value &value) {
    UnloadTexture(this->_texture);
    this->_texture = LoadTexture(value.get("path", "").asString().c_str());
}

void Sprite::setTextureRect(const Uniti::Box &rect) {
    this->_textureRect = rect;
}

void Sprite::setColor(const Uniti::Color &color) {
}

void Sprite::display() {
    struct Rectangle sourceRect = {this->_textureRect.getX(), this->_textureRect.getY(), this->_textureRect.getWidth(),
                                   this->_textureRect.getHeight()};
    struct Rectangle destRect = {this->_position.getX(), this->_position.getY(), this->_scale.getX(),
                                 this->_scale.getY()};
    struct Vector2 origin = {this->_origin.getX(), this->_origin.getY()};
    DrawTexturePro(this->_texture, sourceRect, destRect, origin, this->_rotation, WHITE);
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

Sprite::~Sprite() {
    UnloadTexture(this->_texture);
}
