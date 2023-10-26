//
// Created by youba on 25/10/2023.
//

#include "Vector.hpp"
#include <cmath>

namespace Uniti {
    static float getDistance(const Uniti::Vector2i &a, const Uniti::Vector2i &b) {
        auto dx = static_cast<float>(a.getX() - b.getX());
        auto dy = static_cast<float>(a.getY() - b.getY());
        return std::sqrt(dx * dx + dy * dy);
    }

    static float getDistance(const Uniti::Vector2f &a, const Uniti::Vector2f &b) {
        float dx = a.getX() - b.getX();
        float dy = a.getY() - b.getY();
        return std::sqrt(dx * dx + dy * dy);
    }

    static Uniti::Vector2f getNormal(const Uniti::Vector2i &base, const Uniti::Vector2i &direction) {
        Vector2i normalVector = direction - base;
        Vector2f result(static_cast<float>(normalVector.getX()), static_cast<float>(normalVector.getY()));
        auto length = std::sqrt(result.getX() * result.getX() + result.getY() * result.getY());
        if (length != 0) {
            result.setX(result.getX() / length);
            result.setY(result.getY() / length);
        } else {
            return {0, 0};
        }
        return result;
    }

    static Uniti::Vector2f getNormal(const Uniti::Vector2f &base, const Uniti::Vector2f &direction) {
        Vector2f normalVector = direction - base;
        auto length = std::sqrt(
            normalVector.getX() * normalVector.getX() + normalVector.getY() * normalVector.getY());
        if (length != 0) {
            normalVector.setX(normalVector.getX() / length);
            normalVector.setY(normalVector.getY() / length);
        } else {
            return {0, 0};
        }
        return normalVector;
    }
} // Uniti