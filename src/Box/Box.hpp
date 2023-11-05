//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Vector2f.hpp"
#include "Logger.hpp"

namespace Uniti {
    class Box {
    public:
        /**
         * @brief Construct a new Box object
         *
         */
        Box(const Json::Value &value);
        /**
         * @brief Construct a new Box object
         *
         * @param x
         * @param y
         * @param width
         * @param height
         */
        Box(float x, float y, float width, float height);
        /**
         * @brief Construct a new Box object
         *
         * @param position
         * @param dimension
         */
        const Vector2f &getPosition() const;
        /**
         * @brief Get the Position object
         *
         * @return Vector2f&
         */
        Vector2f &getPosition();
        /**
         * @brief Get the Dimension object
         *
         * @return Vector2f&
         */
        const Vector2f &getDimension() const;
        /**
         * @brief Get the Dimension object
         *
         * @return Vector2f&
         */
        Vector2f &getDimension();
/**
         * @brief Get the X object
         *
         * @return float
         */
        const float getX() const;
        /**
         * @brief Get the X object
         *
         * @return float
         */
        float getX();
        /**
         * @brief Get the Y object
         *
         * @return float
         */
        const float getY() const;
        /**
         * @brief Get the Y object
         *
         * @return float
         */
        float getY();
        /**
         * @brief Get the Width object
         *
         * @return float
         */
        const float getWidth() const;
        /**
         * @brief Get the Width object
         *
         * @return float
         */
        float getWidth();
        /**
         * @brief Get the Height object
         *
         * @return float
         */
        const float getHeight() const;
        /**
         * @brief Get the Height object
         *
         * @return float
         */
        float getHeight();
        /**
         * @brief Set the Position object
         *
         * @param position
         */
        void setPosition(const Vector2f &position);
        /**
         * @brief Set the Dimension object
         *
         * @param dimension
         */
        void setDimension(const Vector2f &dimension);
        /**
         * @brief Set the X object
         *
         * @param x
         */
        void setX(float x);
        /**
         * @brief Set the Y object
         *
         * @param y
         */
        void setY(float y);
        /**
         * @brief Set the Width object
         *
         * @param width
         */
        void setWidth(float width);
        /**
         * @brief Set the Height object
         *
         * @param height
         */
        void setHeight(float height);
        /**
         * @brief Get the Center object
         *
         * @return Vector2f
         */
        bool isInside(const Vector2f &point) const;
        /**
         * @brief Get the Center object
         *
         * @return Vector2f
         */
        bool isInside(const Vector2f &point, const Vector2f &parent) const;
        /**
         * @brief Get the Center object
         *
         * @return Vector2f
         */
        bool isInside(const Box &box) const;
        /**
         * @brief Get the Center object
         *
         * @return Vector2f
         */
        bool isInside(const Box &box, const Vector2f &parentA, const Vector2f &parentB) const;
    private:
        Vector2f _position;
        Vector2f _dimension;
    };
}

std::ostream& operator<<(std::ostream& os, const Uniti::Box &box);
Uniti::Logger& operator<<(Uniti::Logger& os, const Uniti::Box &box);
