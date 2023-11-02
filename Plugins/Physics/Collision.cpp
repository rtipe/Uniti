//
// Created by youba on 29/10/2023.
//

#include "PhysicsPlugin.hpp"
#include "Core.hpp"

Collision::Collision(Uniti::Object &object) : _object(object) {}

void Collision::load(const Json::Value &value) {
    this->_isOverlap = value.get("isOverlap", false).asBool();
    for (const auto &box: value["boxes"])
        this->_collisions.emplace_back(box);
}

void Collision::addBox(const Uniti::Box &box) {
    this->_collisions.push_back(box);
}

const std::vector<Uniti::Box> &Collision::getBox() const {
    return this->_collisions;
}

std::vector<Uniti::Box> &Collision::getBox() {
    return this->_collisions;
}

bool Collision::isInside(const Uniti::Vector2f &point) const {
    for (const auto &box: this->_collisions) {
        if (box.isInside(point, this->_object.getTransform().getPosition()))
            return true;
    }
    return false;
}

bool Collision::isInside(const Uniti::Box &box, const Uniti::Vector2f &position) const {
    for (const auto &inBox: this->_collisions) {
        if (inBox.isInside(box, this->_object.getTransform().getPosition(), position))
            return true;
    }
    return false;
}

bool Collision::isInside(const Uniti::Object &object) const {
    try {
        const PhysicsPlugin &plugin = object.get<const PhysicsPlugin &>("PhysicsPlugin");
        const Collision &otherCollision = plugin.getCollision();
        for (const auto &inBox: this->_collisions) {
            for (const auto &outBox: otherCollision.getBox()) {
                if (inBox.isInside(
                        outBox,
                        this->_object.getTransform().getPosition(),
                        object.getTransform().getPosition()))
                    return true;
            }
        }
    } catch (std::exception &e) {}
    return false;
}

bool Collision::isOverlap() const {
    return this->_isOverlap;
}

void Collision::setOverlap(bool isOverlap) {
    this->_isOverlap = isOverlap;
}

std::optional<std::reference_wrapper<Uniti::Object>>
Collision::isCollided(const Uniti::Vector2f &position, const Uniti::Core &core) {
    for (const auto &object: core.getSceneManager().getGlobalScene().getObjects().getObjects()) {
        try {
            const PhysicsPlugin &plugin = object->get<const PhysicsPlugin &>("PhysicsPlugin");
            const Collision &collision = plugin.getCollision();
            if (collision.isOverlap())
                continue;
            if (collision.isInside(position))
                return *object;
        } catch (std::exception &e) {}
    }
    for (const auto &object: core.getSceneManager().getCurrentScene().getObjects().getObjects()) {
        try {
            const PhysicsPlugin &plugin = object->get<const PhysicsPlugin &>("PhysicsPlugin");
            const Collision &collision = plugin.getCollision();
            if (collision.isOverlap())
                continue;
            if (collision.isInside(position))
                return *object;
        } catch (std::exception &e) {}
    }
    return std::nullopt;
}

std::optional<std::reference_wrapper<Uniti::Object>>
Collision::isCollided(const Uniti::Box &position, const Uniti::Vector2f &parent, const Uniti::Core &core) {
    for (const auto &object: core.getSceneManager().getGlobalScene().getObjects().getObjects()) {
        try {
            const PhysicsPlugin &plugin = object->get<const PhysicsPlugin &>("PhysicsPlugin");
            const Collision &collision = plugin.getCollision();

            if (collision.isOverlap())
                continue;
            if (collision.isInside(position, parent))
                return *object;
        } catch (std::exception &e) {}
    }
    for (const auto &object: core.getSceneManager().getCurrentScene().getObjects().getObjects()) {
        try {
            const PhysicsPlugin &plugin = object->get<const PhysicsPlugin &>("PhysicsPlugin");
            const Collision &collision = plugin.getCollision();

            if (collision.isOverlap())
                continue;
            if (collision.isInside(position, parent))
                return *object;
        } catch (std::exception &e) {}
    }
    return std::nullopt;
}

std::optional<std::reference_wrapper<Uniti::Object>> Collision::isCollided(const Uniti::Object &position) {
    for (const auto &object: position.getCore().getSceneManager().getGlobalScene().getObjects().getObjects()) {
        try {
            const PhysicsPlugin &plugin = object->get<const PhysicsPlugin &>("PhysicsPlugin");
            const Collision &collision = plugin.getCollision();
            if (object->getName() == position.getName())
                continue;
            if (collision.isOverlap())
                continue;
            if (collision.isInside(position))
                return *object;
        } catch (std::exception &e) {}
    }
    for (const auto &object: position.getCore().getSceneManager().getCurrentScene().getObjects().getObjects()) {
        try {
            const PhysicsPlugin &plugin = object->get<const PhysicsPlugin &>("PhysicsPlugin");
            const Collision &collision = plugin.getCollision();
            if (object->getName() == position.getName())
                continue;
            if (collision.isOverlap())
                continue;
            if (collision.isInside(position))
                return *object;
        } catch (std::exception &e) {}
    }
    return std::nullopt;
}

std::optional<std::reference_wrapper<Uniti::Object>>
Collision::isOverlapped(const Uniti::Vector2f &position, const Uniti::Core &core) {
    for (const auto &object: core.getSceneManager().getGlobalScene().getObjects().getObjects()) {
        try {
            const PhysicsPlugin &plugin = object->get<const PhysicsPlugin &>("PhysicsPlugin");
            const Collision &collision = plugin.getCollision();
            if (!collision.isOverlap())
                continue;
            if (collision.isInside(position))
                return *object;
        } catch (std::exception &e) {}
    }
    for (const auto &object: core.getSceneManager().getCurrentScene().getObjects().getObjects()) {
        try {
            const PhysicsPlugin &plugin = object->get<const PhysicsPlugin &>("PhysicsPlugin");
            const Collision &collision = plugin.getCollision();
            if (!collision.isOverlap())
                continue;
            if (collision.isInside(position))
                return *object;
        } catch (std::exception &e) {}
    }
    return std::nullopt;
}

std::optional<std::reference_wrapper<Uniti::Object>>
Collision::isOverlapped(const Uniti::Box &position, const Uniti::Vector2f &parent, const Uniti::Core &core) {
    for (const auto &object: core.getSceneManager().getGlobalScene().getObjects().getObjects()) {
        try {
            const PhysicsPlugin &plugin = object->get<const PhysicsPlugin &>("PhysicsPlugin");
            const Collision &collision = plugin.getCollision();
            if (!collision.isOverlap())
                continue;
            if (collision.isInside(position, parent))
                return *object;
        } catch (std::exception &e) {}
    }
    for (const auto &object: core.getSceneManager().getCurrentScene().getObjects().getObjects()) {
        try {
            const PhysicsPlugin &plugin = object->get<const PhysicsPlugin &>("PhysicsPlugin");
            const Collision &collision = plugin.getCollision();
            if (!collision.isOverlap())
                continue;
            if (collision.isInside(position, parent))
                return *object;
        } catch (std::exception &e) {}
    }
    return std::nullopt;
}

std::optional<std::reference_wrapper<Uniti::Object>> Collision::isOverlapped(const Uniti::Object &position) {
    for (const auto &object: position.getCore().getSceneManager().getGlobalScene().getObjects().getObjects()) {
        try {
            const PhysicsPlugin &plugin = object->get<const PhysicsPlugin &>("PhysicsPlugin");
            const Collision &collision = plugin.getCollision();
            if (object->getName() == position.getName())
                continue;
            if (!collision.isOverlap())
                continue;
            if (collision.isInside(position))
                return *object;
        } catch (std::exception &e) {}
    }
    for (const auto &object: position.getCore().getSceneManager().getCurrentScene().getObjects().getObjects()) {
        try {
            const PhysicsPlugin &plugin = object->get<const PhysicsPlugin &>("PhysicsPlugin");
            const Collision &collision = plugin.getCollision();
            if (object->getName() == position.getName())
                continue;
            if (!collision.isOverlap())
                continue;
            if (collision.isInside(position))
                return *object;
        } catch (std::exception &e) {}
    }
    return std::nullopt;
}
