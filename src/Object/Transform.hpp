//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Vector2f.hpp"
#include "Logger.hpp"

namespace Uniti {
    class Transform {
    public:
        Transform();
        Transform(const Transform &transform);
        Transform(const Json::Value &value);
        const Vector2f &getPosition() const;
        Vector2f &getPosition();
        const Vector2f &getScale() const;
        Vector2f &getScale();
        const Vector2f &getOrigin() const;
        Vector2f &getOrigin();
        float getRotation() const;
        float &getRotation();
        void setPosition(Vector2f &value);
        void setScale(Vector2f &value);
        void setRotation(float value);
        void setOrigin(Vector2f &value);
    private:
        Vector2f _position;
        Vector2f _scale;
        Vector2f _origin;
        float _rotation = 0;
    };
}

std::ostream& operator<<(std::ostream& os, const Uniti::Transform &transform);
Uniti::Logger& operator<<(Uniti::Logger& os, const Uniti::Transform &transform);
