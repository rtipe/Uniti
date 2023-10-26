//
// Created by youba on 25/10/2023.
//

#include "Transform.hpp"

namespace Uniti {
    Transform::Transform() = default;

    Transform::Transform(const Json::Value &value):
        _position(value["position"]),
        _scale(value["scale"]),
        _origin(value["origin"]),
        _rotation(value.get("rotation", 0).asFloat()) {};

    Transform::Transform(const Transform &transform):
        _rotation(transform.getRotation()),
        _origin(transform.getOrigin()),
        _scale(transform.getScale()),
        _position(transform.getPosition()) {};

    const Vector2f &Transform::Transform::getPosition() const {
        return this->_position;
    }

    Vector2f &Transform::getPosition() {
        return this->_position;
    }

    const Vector2f &Transform::getScale() const {
        return this->_scale;
    }

    Vector2f &Transform::getScale() {
        return this->_scale;
    }

    const Vector2f &Transform::getOrigin() const {
        return this->_origin;
    }

    Vector2f &Transform::getOrigin() {
        return this->_origin;
    }

    float Transform::getRotation() const {
        return this->_rotation;
    }

    float &Transform::getRotation() {
        return this->_rotation;
    }

    void Transform::setPosition(Vector2f value) {
        this->_position.setX(value.getX());
        this->_position.setY(value.getY());
    }

    void Transform::setScale(Vector2f value) {
        this->_scale.setX(value.getX());
        this->_scale.setY(value.getY());
    }

    void Transform::setRotation(float value) {
        this->_rotation = value;
    }
} // Uniti