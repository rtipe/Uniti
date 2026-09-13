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
        /** @brief Default constructor for the Transform class.
        */
        Transform();

        /** @brief Copy constructor for the Transform class.
            @param const Transform &transform: Another Transform object to copy.
        */
        Transform(const Transform &transform);

        /** @brief Constructor for the Transform class taking a JSON object for initialization.
            @param const Json::Value &value: JSON object for initialization.
        */
        Transform(const Json::Value &value);

        /** @brief Gets the position as a constant reference.
            @return const Vector2f &: Constant reference to the position.
        */
        const Vector2f &getPosition() const;

        /** @brief Gets the position as a non-constant reference.
            @return Vector2f &: Reference to the position.
        */
        Vector2f &getPosition();

        /** @brief Gets the scale as a constant reference.
            @return const Vector2f &: Constant reference to the scale.
        */
        const Vector2f &getScale() const;

        /** @brief Gets the scale as a non-constant reference.
            @return Vector2f &: Reference to the scale.
        */
        Vector2f &getScale();

        /** @brief Gets the origin as a constant reference.
            @return const Vector2f &: Constant reference to the origin.
        */
        const Vector2f &getOrigin() const;

        /** @brief Gets the origin as a non-constant reference.
            @return Vector2f &: Reference to the origin.
        */
        Vector2f &getOrigin();

        /** @brief Gets the rotation.
            @return float: The rotation value.
        */
        float getRotation() const;

        /** @brief Gets the rotation as a non-constant reference.
            @return float &: Reference to the rotation.
        */
        float &getRotation();

        /** @brief Sets the position.
            @param Vector2f &value: New position value.
        */
        void setPosition(Vector2f &value);

        /** @brief Sets the scale.
            @param Vector2f &value: New scale value.
        */
        void setScale(Vector2f &value);

        /** @brief Sets the rotation.
            @param float value: New rotation value.
        */
        void setRotation(float value);

        /** @brief Sets the origin.
            @param Vector2f &value: New origin value.
        */
        void setOrigin(Vector2f &value);

    private:
        Vector2f _position;
        Vector2f _scale;
        Vector2f _origin;
        float _rotation = 0;
    };
}

/** @brief Overload of the output operator to display the Transform in a standard output stream.
    @param std::ostream &os: Output stream.
    @param const Uniti::Transform &transform: Transform to display.
    @return std::ostream &: Reference to the output stream.
*/
std::ostream& operator<<(std::ostream& os, const Uniti::Transform &transform);

/** @brief Overload of the output operator to display the Transform in a specific logging object (Logger).
    @param Uniti::Logger &os: Logging object.
    @param const Uniti::Transform &transform: Transform to display.
    @return Uniti::Logger &: Reference to the logging object.
*/
Uniti::Logger& operator<<(Uniti::Logger& os, const Uniti::Transform &transform);
