//
// Created by youba on 28/10/2023.
//

#pragma once

#include <string>
#include "Vector2f.hpp"

/** @brief Interface for printable objects, such as graphics or text.
*/
class IPrintable {
public:
    /** @brief Virtual destructor for the IPrintable interface.
    */
    virtual ~IPrintable() = default;

    /** @brief Display the printable object.
    */
    virtual void display() = 0;

    /** @brief Get the type name of the printable object.
        @return const std::string&: A constant reference to the type name.
    */
    virtual const std::string &getTypeName() const = 0;

    /** @brief Get the position of the printable object.
        @return const Uniti::Vector2f&: A constant reference to the 2D position vector.
    */
    virtual const Uniti::Vector2f &getPosition() const = 0;

    /** @brief Get the scale of the printable object.
        @return const Uniti::Vector2f&: A constant reference to the 2D scale vector.
    */
    virtual const Uniti::Vector2f &getScale() const = 0;

    /** @brief Get the rotation of the printable object.
        @return const float: The rotation angle in degrees.
    */
    virtual const float getRotation() const = 0;

    /** @brief Get the Z-index (depth) of the printable object.
        @return const float: The Z-index value.
    */
    virtual const float getZIndex() const = 0;

    /** @brief Set the position of the printable object.
        @param const Uniti::Vector2f &position: The new 2D position vector.
    */
    virtual void setPosition(const Uniti::Vector2f &position) = 0;

    /** @brief Set the scale of the printable object.
        @param const Uniti::Vector2f &scale: The new 2D scale vector.
    */
    virtual void setScale(const Uniti::Vector2f &scale) = 0;

    /** @brief Set the rotation of the printable object.
        @param float rotation: The new rotation angle in degrees.
    */
    virtual void setRotation(float rotation) = 0;

    /** @brief Set the Z-index (depth) of the printable object.
        @param float zIndex: The new Z-index value.
    */
    virtual void setZIndex(float zIndex) = 0;

    /** @brief Set the origin of the printable object.
        @param const Uniti::Vector2f &origin: The new 2D origin vector.
    */
    virtual void setOrigin(const Uniti::Vector2f &origin) = 0;
};

