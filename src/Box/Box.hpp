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
        /** @brief Constructor of the Box class taking a JSON object as an argument.
            @param const Json::Value &value : JSON object for initialization.
        */
        Box(const Json::Value &value);

        /** @brief Constructor of the Box class taking coordinates and dimensions.
            @param float x : X-coordinate.
            @param float y : Y-coordinate.
            @param float width : Width.
            @param float height : Height.
        */
        Box(float x, float y, float width, float height);

        /** @brief Returns the current position of the box (read-only).
            @return const Vector2f & : Box position.
        */
        const Vector2f &getPosition() const;

        /** @brief Returns the current position of the box (read/write).
            @return Vector2f & : Box position.
        */
        Vector2f &getPosition();

        /** @brief Returns the current dimensions of the box (read-only).
            @return const Vector2f & : Box dimensions.
        */
        const Vector2f &getDimension() const;

        /** @brief Returns the current dimensions of the box (read/write).
            @return Vector2f & : Box dimensions.
        */
        Vector2f &getDimension();

        /** @brief Returns the X-coordinate of the position (read-only).
            @return const float : X-coordinate of the position.
        */
        const float getX() const;

        /** @brief Returns the X-coordinate of the position (read/write).
            @return float : X-coordinate of the position.
        */
        float getX();

        /** @brief Returns the Y-coordinate of the position (read-only).
            @return const float : Y-coordinate of the position.
        */
        const float getY() const;

        /** @brief Returns the Y-coordinate of the position (read/write).
            @return float : Y-coordinate of the position.
        */
        float getY();

        /** @brief Returns the width of the box (read-only).
            @return const float : Width of the box.
        */
        const float getWidth() const;

        /** @brief Returns the width of the box (read/write).
            @return float : Width of the box.
        */
        float getWidth();

        /** @brief Returns the height of the box (read-only).
            @return const float : Height of the box.
        */
        const float getHeight() const;

        /** @brief Returns the height of the box (read/write).
            @return float : Height of the box.
        */
        float getHeight();

        /** @brief Sets the position of the box based on a given Vector2f object.
            @param const Vector2f &position : New position of the box.
        */
        void setPosition(const Vector2f &position);

        /** @brief Sets the dimensions of the box based on a given Vector2f object.
            @param const Vector2f &dimension : New dimensions of the box.
        */
        void setDimension(const Vector2f &dimension);

        /** @brief Sets the X-coordinate of the position of the box.
            @param float x : New X-coordinate.
        */
        void setX(float x);

        /** @brief Sets the Y-coordinate of the position of the box.
            @param float y : New Y-coordinate.
        */
        void setY(float y);

        /** @brief Sets the width of the box.
            @param float width : New width.
        */
        void setWidth(float width);

        /** @brief Sets the height of the box.
            @param float height : New height.
        */
        void setHeight(float height);

        /** @brief Checks if a given point is inside the box.
            @param const Vector2f &point : Point to check.
            @return bool : True if the point is inside the box, otherwise false.
        */
        bool isInside(const Vector2f &point) const;

        /** @brief Checks if a given point is inside the box relative to a parent.
            @param const Vector2f &point : Point to check.
            @param const Vector2f &parent : Reference parent.
            @return bool : True if the point is inside the box, otherwise false.
        */
        bool isInside(const Vector2f &point, const Vector2f &parent) const;

        /** @brief Checks if another box is entirely inside this box.
            @param const Box &box : Box to check.
            @return bool : True if the other box is entirely inside, otherwise false.
        */
        bool isInside(const Box &box) const;

        /** @brief Checks if another box is entirely inside this box relative to two parents.
            @param const Box &box : Box to check.
            @param const Vector2f &parentA : First reference parent.
            @param const Vector2f &parentB : Second reference parent.
            @return bool : True if the other box is entirely inside, otherwise false.
        */
        bool isInside(const Box &box, const Vector2f &parentA, const Vector2f &parentB) const;

    private:
        Vector2f _position;
        Vector2f _dimension;
    };
}

/** @brief Overload of the output operator to display the box in a standard output stream.
    @param std::ostream& os : Output stream.
    @param const Uniti::Box &box : Box to display.
    @return std::ostream& : Reference to the output stream.
*/
std::ostream& operator<<(std::ostream& os, const Uniti::Box &box);

/** @brief Overload of the output operator to display the box in a specific logging object (Logger).
    @param Uniti::Logger& os : Logging object.
    @param const Uniti::Box &box : Box to display.
    @return Uniti::Logger& : Reference to the logging object.
*/
Uniti::Logger& operator<<(Uniti::Logger& os, const Uniti::Box &box);
