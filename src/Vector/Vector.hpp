//
// Created by youba on 25/10/2023.
//

#pragma once

#include "Vector2i.hpp"
#include "Vector2f.hpp"

namespace Uniti {
    class Vector {
    public:
        static float getDistance(const Uniti::Vector2i &a, const Uniti::Vector2i &b);
        static float getDistance(const Uniti::Vector2f &a, const Uniti::Vector2f &b);
        static Uniti::Vector2f getNormal(const Uniti::Vector2i &base, const Uniti::Vector2i &direction);
        static Uniti::Vector2f getNormal(const Uniti::Vector2f &base, const Uniti::Vector2f &direction);
    };
}
