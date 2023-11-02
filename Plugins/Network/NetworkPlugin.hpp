//
// Created by youba on 29/10/2023.
//

#pragma once

#include "Network.hpp"
#include "ICorePlugin.hpp"

class NetworkPlugin : public Uniti::ICorePlugin {
public:
    NetworkPlugin(Uniti::Core &core);

    Uniti::Core &getCore() override;

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

    Network &getNetwork();

private:
    std::unique_ptr<Network> _network;
    Uniti::Core &_core;
    Uniti::Clock _clock;
    Uniti::Event _event;
};
