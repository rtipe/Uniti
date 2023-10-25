//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"

namespace Uniti {
    class Vector2f;
    class Vector2i {
    public:
        Vector2i();
        Vector2i(const Vector2i &vector);
        Vector2i(const Vector2f &vector);
        Vector2i(int x, int y);
        Vector2i(const Json::Value &value);
        int getX() const;
        int &getX();
        int getY() const;
        int &getY();
        void setX(int value);
        void setY(int value);
        void set(int x, int y);
        Vector2i operator+(const Vector2i &other) const;
        Vector2i operator+(const Vector2f &other) const;
        Vector2i operator+(const int &other) const;
        Vector2i operator-(const Vector2i &other) const;
        Vector2i operator-(const Vector2f &other) const;
        Vector2i operator-(const int &other) const;
        Vector2i operator*(const Vector2i &other) const;
        Vector2i operator*(const Vector2f &other) const;
        Vector2i operator*(const int &other) const;
        Vector2i operator/(const Vector2i &other) const;
        Vector2i operator/(const Vector2f &other) const;
        Vector2i operator/(const int &other) const;
        Vector2i &operator=(const Vector2i &other);
        Vector2i &operator=(const Vector2f &other);
        Vector2i &operator=(const int &other);
    };
}
