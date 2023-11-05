//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"

namespace Uniti {
    class Vector2i;

    class Vector2f {
    public:
        /** @brief Default constructor for Vector2f, initializes x and y to 0.
        */
        Vector2f();

        /** @brief Copy constructor for Vector2f.
            @param const Vector2f &vector: Another Vector2f to copy.
        */
        Vector2f(const Vector2f &vector);

        /** @brief Constructor for Vector2f from a Vector2i.
            @param const Vector2i &vector: Vector2i to convert to Vector2f.
        */
        Vector2f(const Vector2i &vector);

        /** @brief Constructor for Vector2f with specified x and y values.
            @param float x: The x-coordinate value.
            @param float y: The y-coordinate value.
        */
        Vector2f(float x, float y);

        /** @brief Constructor for Vector2f from a Json::Value object.
            @param const Json::Value &value: Json::Value containing x and y values.
        */
        Vector2f(const Json::Value &value);

        /** @brief Get the x-coordinate value of the vector.
            @return float: The x-coordinate value.
        */
        float getX() const;

        /** @brief Get a reference to the x-coordinate value of the vector, allowing modification.
            @return float&: Reference to the x-coordinate value.
        */
        float &getX();

        /** @brief Get the y-coordinate value of the vector.
            @return float: The y-coordinate value.
        */
        float getY() const;

        /** @brief Get a reference to the y-coordinate value of the vector, allowing modification.
            @return float&: Reference to the y-coordinate value.
        */
        float &getY();

        /** @brief Set both the x and y values of the vector.
            @param float x: The new x-coordinate value.
            @param float y: The new y-coordinate value.
        */
        void set(float x, float y);

        /** @brief Set the x-coordinate value of the vector.
            @param float value: The new x-coordinate value.
        */
        void setX(float value);

        /** @brief Set the y-coordinate value of the vector.
            @param float value: The new y-coordinate value.
        */
        void setY(float value);
        void set(float x, float y);

        /** @brief Overloaded addition operator to add two Vector2f instances.
            @param const Vector2f &other: Another Vector2f to add.
            @return Vector2f: Result of the addition.
        */
        Vector2f operator+(const Vector2f &other) const;

        /** @brief Overloaded addition operator to add a Vector2i to a Vector2f.
            @param const Vector2i &other: Vector2i to add.
            @return Vector2f: Result of the addition.
        */
        Vector2f operator+(const Vector2i &other) const;

        /** @brief Overloaded addition operator to add a float value to a Vector2f.
            @param const float &other: Float value to add.
            @return Vector2f: Result of the addition.
        */
        Vector2f operator+(const float &other) const;

        /** @brief Overloaded subtraction operator to subtract two Vector2f instances.
            @param const Vector2f &other: Another Vector2f to subtract.
            @return Vector2f: Result of the subtraction.
        */
        Vector2f operator-(const Vector2f &other) const;

        /** @brief Overloaded subtraction operator to subtract a Vector2i from a Vector2f.
            @param const Vector2i &other: Vector2i to subtract.
            @return Vector2f: Result of the subtraction.
        */
        Vector2f operator-(const Vector2i &other) const;

        /** @brief Overloaded subtraction operator to subtract a float value from a Vector2f.
            @param const float &other: Float value to subtract.
            @return Vector2f: Result of the subtraction.
        */
        Vector2f operator-(const float &other) const;

        /** @brief Overloaded multiplication operator to multiply two Vector2f instances.
            @param const Vector2f &other: Another Vector2f to multiply.
            @return Vector2f: Result of the multiplication.
        */
        Vector2f operator*(const Vector2f &other) const;

        /** @brief Overloaded multiplication operator to multiply a Vector2i with a Vector2f.
            @param const Vector2i &other: Vector2i to multiply.
            @return Vector2f: Result of the multiplication.
        */
        Vector2f operator*(const Vector2i &other) const;

        /** @brief Overloaded multiplication operator to multiply a Vector2f by a float value.
            @param const float &other: Float value to multiply.
            @return Vector2f: Result of the multiplication.
        */
        Vector2f operator*(const float &other) const;

        /** @brief Overloaded division operator to divide two Vector2f instances.
            @param const Vector2f &other: Another Vector2f to divide.
            @return Vector2f: Result of the division.
        */
        Vector2f operator/(const Vector2f &other) const;

        /** @brief Overloaded division operator to divide a Vector2i by a Vector2f.
            @param const Vector2i &other: Vector2i to divide.
            @return Vector2f: Result of the division.
        */
        Vector2f operator/(const Vector2i &other) const;

        /** @brief Overloaded division operator to divide a Vector2f by a float value.
            @param const float &other: Float value to divide by.
            @return Vector2f: Result of the division.
        */
        Vector2f operator/(const float &other) const;

        /** @brief Overloaded assignment operator to copy the values from another Vector2f.
            @param const Vector2f &other: Another Vector2f to copy.
            @return Vector2f&: Reference to this Vector2f after the assignment.
        */
        Vector2f &operator=(const Vector2f &other);

        /** @brief Overloaded assignment operator to copy the values from a Vector2i.
            @param const Vector2i &other: Vector2i to copy.
            @return Vector2f&: Reference to this Vector2f after the assignment.
        */
        Vector2f &operator=(const Vector2i &other);

        /** @brief Overloaded assignment operator to set both x and y values to a float value.
            @param const float &other: Float value to set as both x and y.
            @return Vector2f&: Reference to this Vector2f after the assignment.
        */
        Vector2f &operator=(const float &other);

    private:
        float _x;
        float _y;
    };
}
