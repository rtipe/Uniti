//
// Created by youba on 30/10/2023.
//

#pragma once

#include <boost/lockfree/queue.hpp>
#include <thread>
#include "ICorePlugin.hpp"
#include "sio_client.h"

class JavascriptPlugin : public Uniti::ICorePlugin {
public:
    JavascriptPlugin(Uniti::Core &core);

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

private:
    std::string _code;
    std::thread _thread;
    boost::lockfree::queue<std::string *> _queue;
    Uniti::Core &_core;
    Uniti::Event _event;
    Uniti::Clock _clock;
    sio::client client;
    int _port;
};
