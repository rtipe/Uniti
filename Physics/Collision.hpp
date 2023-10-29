//
// Created by youba on 29/10/2023.
//

#pragma once

#include "Object.hpp"
#include "Box.hpp"

class Collision {
public:
    Collision(Uniti::Object &object);

    void load(const Json::Value &value);

    void addBox(const Uniti::Box &box);

    const std::vector<Uniti::Box> &getBox() const;

    std::vector<Uniti::Box> &getBox();

    bool isInside(const Uniti::Vector2f &point) const;

    bool isInside(const Uniti::Box &box, const Uniti::Vector2f &position) const;

    bool isInside(const Uniti::Object &object) const;

    bool isOverlap() const;

    void setOverlap(bool isOverlap);

    static std::optional<std::reference_wrapper<Uniti::Object>>
    isCollided(const Uniti::Vector2f &position, const Uniti::Core &core);

    static std::optional<std::reference_wrapper<Uniti::Object>>
    isCollided(const Uniti::Box &position, const Uniti::Vector2f &parent, const Uniti::Core &core);

    static std::optional<std::reference_wrapper<Uniti::Object>> isCollided(const Uniti::Object &position);

    static std::optional<std::reference_wrapper<Uniti::Object>>
    isOverlapped(const Uniti::Vector2f &position, const Uniti::Core &core);

    static std::optional<std::reference_wrapper<Uniti::Object>>
    isOverlapped(const Uniti::Box &position, const Uniti::Vector2f &parent, const Uniti::Core &core);

    static std::optional<std::reference_wrapper<Uniti::Object>> isOverlapped(const Uniti::Object &position);

private:
    std::vector<Uniti::Box> _collisions;
    Uniti::Object &_object;
    bool _isOverlap = false;
};
