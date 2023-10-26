//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"

namespace Uniti {
    class Vector2i;
    class Vector2f {
    public:
        Vector2f();
        Vector2f(const Vector2f &vector);
        Vector2f(const Vector2i &vector);
        Vector2f(float x, float y);
        Vector2f(const Json::Value &value);
        float getX() const;
        float &getX();
        float getY() const;
        float &getY();
        void setX(float value);
        void setY(float value);
        void set(float x, float y);
        Vector2f operator+(const Vector2f &other) const;
        Vector2f operator+(const Vector2i &other) const;
        Vector2f operator+(const float &other) const;
        Vector2f operator-(const Vector2f &other) const;
        Vector2f operator-(const Vector2i &other) const;
        Vector2f operator-(const float &other) const;
        Vector2f operator*(const Vector2f &other) const;
        Vector2f operator*(const Vector2i &other) const;
        Vector2f operator*(const float &other) const;
        Vector2f operator/(const Vector2f &other) const;
        Vector2f operator/(const Vector2i &other) const;
        Vector2f operator/(const float &other) const;
        Vector2f &operator=(const Vector2f &other);
        Vector2f &operator=(const Vector2i &other);
        Vector2f &operator=(const float &other);
    private:
        float _x;
        float _y;
    };
}
