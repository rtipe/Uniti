//
// Created by youba on 29/10/2023.
//

#pragma once

#include "Object.hpp"
#include "Box.hpp"

/** @brief Collision class for handling collision detection and checking collision-related information.
*/
class Collision {
public:
    /** @brief Constructor for the Collision class.
        @param Uniti::Object &object: Reference to the associated object for collision checks.
    */
    Collision(Uniti::Object &object);

    /** @brief Load collision data from a JSON value.
        @param const Json::Value &value: JSON value containing collision data.
    */
    void load(const Json::Value &value);

    /** @brief Add a bounding box to the list of collision boxes.
        @param const Uniti::Box &box: Bounding box to add.
    */
    void addBox(const Uniti::Box &box);

    /** @brief Get a constant reference to the list of collision boxes.
        @return const std::vector<Uniti::Box>&: Constant reference to the list of collision boxes.
    */
    const std::vector<Uniti::Box> &getBox() const;

    /** @brief Get a reference to the list of collision boxes.
        @return std::vector<Uniti::Box>&: Reference to the list of collision boxes.
    */
    std::vector<Uniti::Box> &getBox();

    /** @brief Check if a given point is inside any of the collision boxes.
        @param const Uniti::Vector2f &point: Point to check for collision.
        @return bool: True if the point is inside any collision box, false otherwise.
    */
    bool isInside(const Uniti::Vector2f &point) const;

    /** @brief Check if a given box at a specified position is inside any of the collision boxes.
        @param const Uniti::Box &box: Box to check for collision.
        @param const Uniti::Vector2f &position: Position of the box.
        @return bool: True if the box is inside any collision box, false otherwise.
    */
    bool isInside(const Uniti::Box &box, const Uniti::Vector2f &position) const;

    /** @brief Check if the associated object is colliding with any other objects.
        @return bool: True if the object is colliding with other objects, false otherwise.
    */
    bool isInside(const Uniti::Object &object) const;

    /** @brief Check if the associated object is overlapping with other objects.
        @return bool: True if the object is overlapping with other objects, false otherwise.
    */
    bool isOverlap() const;

    /** @brief Set the overlap status for the associated object.
        @param bool isOverlap: True to set the object as overlapping, false otherwise.
    */
    void setOverlap(bool isOverlap);

    /** @brief Check if any object is collided with a point within the Core.
        @param const Uniti::Vector2f &position: Point position to check for collisions.
        @param const Uniti::Core &core: Reference to the Core.
        @return std::optional<std::reference_wrapper<Uniti::Object>>: Optional reference to the collided object.
    */
    static std::optional<std::reference_wrapper<Uniti::Object>> isCollided(const Uniti::Vector2f &position, const Uniti::Core &core);

    /** @brief Check if any object is collided with a box within the Core.
        @param const Uniti::Box &position: Bounding box to check for collisions.
        @param const Uniti::Vector2f &parent: Position of the parent object.
        @param const Uniti::Core &core: Reference to the Core.
        @return std::optional<std::reference_wrapper<Uniti::Object>>: Optional reference to the collided object.
    */
    static std::optional<std::reference_wrapper<Uniti::Object>> isCollided(const Uniti::Box &position, const Uniti::Vector2f &parent, const Uniti::Core &core);

    /** @brief Check if any object is overlapping with a specified object within the Core.
        @param const Uniti::Object &position: Object to check for overlaps.
        @return std::optional<std::reference_wrapper<Uniti::Object>>: Optional reference to the overlapped object.
    */
    static std::optional<std::reference_wrapper<Uniti::Object>> isCollided(const Uniti::Object &position);

    /** @brief Check if any object is overlapped with a point within the Core.
        @param const Uniti::Vector2f &position: Point position to check for overlaps.
        @param const Uniti::Core &core: Reference to the Core.
        @return std::optional<std::reference_wrapper<Uniti::Object>>: Optional reference to the overlapped object.
    */
    static std::optional<std::reference_wrapper<Uniti::Object>> isOverlapped(const Uniti::Vector2f &position, const Uniti::Core &core);

    /** @brief Check if any object is overlapped with a box within the Core.
        @param const Uniti::Box &position: Bounding box to check for overlaps.
        @param const Uniti::Vector2f &parent: Position of the parent object.
        @param const Uniti::Core &core: Reference to the Core.
        @return std::optional<std::reference_wrapper<Uniti::Object>>: Optional reference to the overlapped object.
    */
    static std::optional<std::reference_wrapper<Uniti::Object>> isOverlapped(const Uniti::Box &position, const Uniti::Vector2f &parent, const Uniti::Core &core);

    /** @brief Check if any object is overlapped with a specified object within the Core.
        @param const Uniti::Object &position: Object to check for overlaps.
        @return std::optional<std::reference_wrapper<Uniti::Object>>: Optional reference to the overlapped object.
    */
    static std::optional<std::reference_wrapper<Uniti::Object>> isOverlapped(const Uniti::Object &position);

private:
    std::vector<Uniti::Box> _collisions;
    Uniti::Object &_object;
    bool _isOverlap = false;
};
