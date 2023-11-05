//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"

namespace Uniti {
    class Vector2f;

    class Vector2i {
    public:
        /** @brief Default constructor for Vector2i, initializes x and y to 0.
        */
        Vector2i();

        /** @brief Copy constructor for Vector2i.
            @param const Vector2i &vector: Another Vector2i to copy.
        */
        Vector2i(const Vector2i &vector);

        /** @brief Constructor for Vector2i from a Vector2f.
            @param const Vector2f &vector: Vector2f to convert to Vector2i.
        */
        Vector2i(const Vector2f &vector);

        /** @brief Constructor for Vector2i with specified x and y values.
            @param int x: The x-coordinate value.
            @param int y: The y-coordinate value.
        */
        Vector2i(int x, int y);

        /** @brief Constructor for Vector2i from a Json::Value object.
            @param const Json::Value &value: Json::Value containing x and y values.
        */
        Vector2i(const Json::Value &value);

        /** @brief Get the x-coordinate value of the vector as an integer.
            @return int: The x-coordinate value.
        */
        int getX() const;

        /** @brief Get a reference to the x-coordinate value of the vector, allowing modification.
            @return int&: Reference to the x-coordinate value.
        */
        int &getX();

        /** @brief Get the y-coordinate value of the vector as an integer.
            @return int: The y-coordinate value.
        */
        int getY() const;

        /** @brief Get a reference to the y-coordinate value of the vector, allowing modification.
            @return int&: Reference to the y-coordinate value.
        */
        int &getY();

        /** @brief Set both the x and y values of the vector.
            @param int x: The new x-coordinate value.
            @param int y: The new y-coordinate value.
        */
        void set(int x, int y);

        /** @brief Set the x-coordinate value of the vector.
            @param int value: The new x-coordinate value.
        */
        void setX(int value);

        /** @brief Set the y-coordinate value of the vector.
            @param int value: The new y-coordinate value.
        */
        void setY(int value);

        /** @brief Overloaded addition operator to add two Vector2i instances.
            @param const Vector2i &other: Another Vector2i to add.
            @return Vector2i: Result of the addition.
        */
        Vector2i operator+(const Vector2i &other) const;

        /** @brief Overloaded addition operator to add a Vector2f to a Vector2i.
            @param const Vector2f &other: Vector2f to add.
            @return Vector2i: Result of the addition.
        */
        Vector2i operator+(const Vector2f &other) const;

        /** @brief Overloaded addition operator to add an integer value to a Vector2i.
            @param const int &other: Integer value to add.
            @return Vector2i: Result of the addition.
        */
        Vector2i operator+(const int &other) const;

        /** @brief Overloaded subtraction operator to subtract two Vector2i instances.
            @param const Vector2i &other: Another Vector2i to subtract.
            @return Vector2i: Result of the subtraction.
        */
        Vector2i operator-(const Vector2i &other) const;

        /** @brief Overloaded subtraction operator to subtract a Vector2f from a Vector2i.
            @param const Vector2f &other: Vector2f to subtract.
            @return Vector2i: Result of the subtraction.
        */
        Vector2i operator-(const Vector2f &other) const;

        /** @brief Overloaded subtraction operator to subtract an integer value from a Vector2i.
            @param const int &other: Integer value to subtract.
            @return Vector2i: Result of the subtraction.
        */
        Vector2i operator-(const int &other) const;

        /** @brief Overloaded multiplication operator to multiply two Vector2i instances.
            @param const Vector2i &other: Another Vector2i to multiply.
            @return Vector2i: Result of the multiplication.
        */
        Vector2i operator*(const Vector2i &other) const;

        /** @brief Overloaded multiplication operator to multiply a Vector2f with a Vector2i.
            @param const Vector2f &other: Vector2f to multiply.
            @return Vector2i: Result of the multiplication.
        */
        Vector2i operator*(const Vector2f &other) const;

        /** @brief Overloaded multiplication operator to multiply a Vector2i by an integer value.
            @param const int &other: Integer value to multiply.
            @return Vector2i: Result of the multiplication.
        */
        Vector2i operator*(const int &other) const;

        /** @brief Overloaded division operator to divide two Vector2i instances.
            @param const Vector2i &other: Another Vector2i to divide.
            @return Vector2i: Result of the division.
        */
        Vector2i operator/(const Vector2i &other) const;

        /** @brief Overloaded division operator to divide a Vector2f by a Vector2i.
            @param const Vector2f &other: Vector2f to divide.
            @return Vector2i: Result of the division.
        */
        Vector2i operator/(const Vector2f &other) const;

        /** @brief Overloaded division operator to divide a Vector2i by an integer value.
            @param const int &other: Integer value to divide by.
            @return Vector2i: Result of the division.
        */
        Vector2i operator/(const int &other) const;

        /** @brief Overloaded assignment operator to copy the values from another Vector2i.
            @param const Vector2i &other: Another Vector2i to copy.
            @return Vector2i&: Reference to this Vector2i after the assignment.
        */
        Vector2i &operator=(const Vector2i &other);

        /** @brief Overloaded assignment operator to copy the values from a Vector2f.
            @param const Vector2f &other: Vector2f to copy.
            @return Vector2i&: Reference to this Vector2i after the assignment.
        */
        Vector2i &operator=(const Vector2f &other);

        /** @brief Overloaded assignment operator to set both x and y values to an integer value.
            @param const int &other: Integer value to set as both x and y.
            @return Vector2i&: Reference to this Vector2i after the assignment.
        */
        Vector2i &operator=(const int &other);

    private:
        int _x;
        int _y;
    };
}

