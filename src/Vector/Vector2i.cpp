//
// Created by youba on 25/10/2023.
//

#include "Vector2i.hpp"
#include "Vector2f.hpp"

namespace Uniti {
    Vector2i::Vector2i() : _x(0), _y(0) {};

    Vector2i::Vector2i(const Vector2i &vector) : _x(vector.getX()), _y(vector.getY()) {};

    Vector2i::Vector2i(int x, int y) : _x(x), _y(y) {};

    Vector2i::Vector2i(const Json::Value &value) {
        this->_x = value.get("x", 0).asInt();
        this->_y = value.get("y", 0).asInt();
    }

    int Vector2i::getX() const {
        return this->_x;
    }

    int Vector2i::getY() const {
        return this->_y;
    }

    void Vector2i::setX(int value) {
        this->_x = value;
    }

    void Vector2i::setY(int value) {
        this->_y = value;
    }

    void Vector2i::set(int x, int y) {
        this->_x = x;
        this->_y = y;
    }

    Vector2i::Vector2i(const Vector2f &vector) : _x(vector.getX()), _y(vector.getY()) {}

    int &Vector2i::getX() {
        return this->_x;
    }

    int &Vector2i::getY() {
        return this->_y;
    }

    Vector2i Vector2i::operator+(const Vector2i &other) const {
        return {this->_x + other.getX(), this->_y + other.getY()};
    }

    Vector2i Vector2i::operator+(const Vector2f &other) const {
        return {this->_x + static_cast<int>(other.getX()), this->_y + static_cast<int>(other.getY())};
    }

    Vector2i Vector2i::operator+(const int &other) const {
        return {this->_x + other, this->_y + other};
    }

    Vector2i Vector2i::operator-(const Vector2i &other) const {
        return {this->_x - other.getX(), this->_y - other.getY()};
    }

    Vector2i Vector2i::operator-(const Vector2f &other) const {
        return {this->_x - static_cast<int>(other.getX()), this->_y - static_cast<int>(other.getY())};
    }

    Vector2i Vector2i::operator-(const int &other) const {
        return {this->_x - other, this->_y - other};
    }

    Vector2i Vector2i::operator*(const Vector2i &other) const {
        return {this->_x * other.getX(), this->_y * other.getY()};
    }

    Vector2i Vector2i::operator*(const Vector2f &other) const {
        return {this->_x * static_cast<int>(other.getX()), this->_y * static_cast<int>(other.getY())};
    }

    Vector2i Vector2i::operator*(const int &other) const {
        return {this->_x * other, this->_y * other};
    }

    Vector2i Vector2i::operator/(const Vector2i &other) const {
        return {this->_x / other.getX(), this->_y / other.getY()};
    }

    Vector2i Vector2i::operator/(const Vector2f &other) const {
        return {this->_x / static_cast<int>(other.getX()), this->_y / static_cast<int>(other.getY())};
    }

    Vector2i Vector2i::operator/(const int &other) const {
        return {this->_x / other, this->_y / other};
    }

    Vector2i &Vector2i::operator=(const Vector2i &other) {
        this->_x = other._x;
        this->_y = other._y;
        return *this;
    }

    Vector2i &Vector2i::operator=(const Vector2f &other) {
        this->_x = static_cast<int>(other.getX());
        this->_y = static_cast<int>(other.getY());
        return *this;
    }

    Vector2i &Vector2i::operator=(const int &other) {
        this->_x = other;
        this->_y = other;
        return *this;
    }
}