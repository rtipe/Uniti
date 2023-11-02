//
// Created by youba on 29/10/2023.
//

#pragma once

#include "IObjectPlugin.hpp"
#include "Collision.hpp"
#include "Movement.hpp"

class PhysicsPlugin : public Uniti::IObjectPlugin {
public:
    PhysicsPlugin(Uniti::Object &object);

    Uniti::Object &getObject() override;

    void awake(const Json::Value &value) override;

    void preStart() override;

    void start() override;

    void postStart() override;

    void preUpdate() override;

    void update() override;

    void postUpdate() override;

    void preEnd() override;

    void end() override;

    void postEnd() override;

    const Uniti::Clock &getClock() const override;

    Uniti::Clock &getClock() override;

    const Uniti::Event &getEvent() const override;

    Uniti::Event &getEvent() override;

    const Collision &getCollision() const;

    Collision &getCollision();

    const Movement &getMovement() const;

    Movement &getMovement();

private:
    Uniti::Object &_object;
    Collision _collision;
    Movement _movement;
    Uniti::Clock _clock;
    Uniti::Event _event;
};
