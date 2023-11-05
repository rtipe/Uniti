//
// Created by youba on 25/10/2023.
//

#pragma once

#include "Vector2i.hpp"
#include "Vector2f.hpp"

namespace Uniti {
    class Vector {
    public:
        /** @brief Calculate the Euclidean distance between two 2D integer vectors.
            @param const Uniti::Vector2i &a: First vector.
            @param const Uniti::Vector2i &b: Second vector.
            @return float: Euclidean distance between the two vectors.
        */
        static float getDistance(const Uniti::Vector2i &a, const Uniti::Vector2i &b);

        /** @brief Calculate the Euclidean distance between two 2D floating-point vectors.
            @param const Uniti::Vector2f &a: First vector.
            @param const Uniti::Vector2f &b: Second vector.
            @return float: Euclidean distance between the two vectors.
        */
        static float getDistance(const Uniti::Vector2f &a, const Uniti::Vector2f &b);

        /** @brief Calculate the normalized vector from a base vector to a direction vector (2D integer vectors).
            @param const Uniti::Vector2i &base: Base vector.
            @param const Uniti::Vector2i &direction: Direction vector.
            @return Uniti::Vector2f: Normalized vector from base to direction.
        */
        static Uniti::Vector2f getNormal(const Uniti::Vector2i &base, const Uniti::Vector2i &direction);

        /** @brief Calculate the normalized vector from a base vector to a direction vector (2D floating-point vectors).
            @param const Uniti::Vector2f &base: Base vector.
            @param const Uniti::Vector2f &direction: Direction vector.
            @return Uniti::Vector2f: Normalized vector from base to direction.
        */
        static Uniti::Vector2f getNormal(const Uniti::Vector2f &base, const Uniti::Vector2f &direction);
    };
}
