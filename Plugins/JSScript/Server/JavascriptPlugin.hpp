//
// Created by youba on 30/10/2023.
//

#pragma once

#include <boost/lockfree/queue.hpp>
#include <thread>
#include "ICorePlugin.hpp"
#include "sio_client.h"
#include "Scene.hpp"

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

    void emitJSEvent(const std::string &name, const Json::Value &value);

private:
    Json::Value getSceneJson(Uniti::Scene &scene);

    Json::Value getObjectJson(Uniti::Object &object);

    Json::Value getUnloadScenes();

    void applyCoreEvent(const Json::Value &events);

    void applySceneManagerEvent(const Json::Value &events);

    void applySceneEvent(Uniti::Scene &scene, const Json::Value &events);

    void applyObjectEvent(Uniti::Object &object, const Json::Value &events);

    void applyNetworkEvent(const Json::Value &events);
    std::string _code;
    std::string _path;
    std::thread _thread;
    boost::lockfree::queue<std::string *> _queueUpdate;
    boost::lockfree::queue<std::string *> _queueLog;
    std::map<std::string, std::vector<Json::Value>> _events;
    Uniti::Core &_core;
    Uniti::Event _event;
    Uniti::Clock _clock;
    sio::client client;
    int _port;
    float _updateJS;
};
