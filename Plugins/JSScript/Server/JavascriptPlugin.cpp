//
// Created by youba on 30/10/2023.
//

#include "JavascriptPlugin.hpp"
#include <iostream>
#include <cstdlib>
#include "Core.hpp"
#include "json/json.h"

JavascriptPlugin::JavascriptPlugin(Uniti::Core &core) : _core(core), _queueLog(10000), _queueUpdate(10000) {}

Uniti::Core &JavascriptPlugin::getCore() {
    return this->_core;
}

void JavascriptPlugin::awake(const Json::Value &value) {
    this->_code = std::to_string(std::rand() % 100000);
    this->_port = value.get("port", 8000).asInt();
    this->_updateJS = 1 / value.get("fps", 10).asFloat();
    this->_path = value.get("path", "").asString();
    std::string port = std::to_string(this->_port);

    this->_thread = std::thread([](std::string code, std::string port, std::string path, JavascriptPlugin &plugin) {
#ifdef __linux__
        int result = std::system(std::string("./node/bin/node " + path + " " + port + " " + code).c_str());
#else
        int result = std::system(std::string(
                std::filesystem::current_path().string() + "/node/node.exe " + path + " " + port + " " + code).c_str());
#endif
        if (result != 0) {
            plugin._queueLog.push(new std::string("Error execution of node"));
        }
        plugin._queueLog.push(new std::string("Execution ended"));
    }, this->_code, port, this->_path, std::ref(*this));
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void JavascriptPlugin::preStart() {
    try {
        client.connect(std::string("http://127.0.0.1:" + std::to_string(this->_port)));

        client.socket()->on("update", [&](sio::event &message) {
            std::string *response = new std::string(message.get_message()->get_string());
            this->_queueUpdate.push(response);
            this->_queueLog.push(new std::string("receive JS update"));
        });
        client.socket()->on("log", [&](sio::event &message) {
            std::string *response = new std::string(message.get_message()->get_string());
            this->_queueLog.push(response);
        });
        client.socket()->emit("init", {this->_code});
    } catch (std::exception &e) {
        this->_core.log().Danger("Error while init socket.io");
        this->_core.log().Danger(e.what());
    }
}

void JavascriptPlugin::start() {

}

void JavascriptPlugin::postStart() {

}

void JavascriptPlugin::preUpdate() {
    this->_queueUpdate.consume_all([&](std::string *event) {
        Json::Value base;
        std::istringstream(*event) >> base;

        this->applyCoreEvent(base);
        delete event;
    });
}

void JavascriptPlugin::update() {
    this->_queueLog.consume_all([&](std::string *event) {
        try {
            Json::Value base;
            std::istringstream(*event) >> base;

            if (base["type"].asString() == "Danger") {
                this->_core.log().Danger(base["message"].asString());
            } else if (base["type"].asString() == "Info") {
                this->_core.log().Info(base["message"].asString());
            } else if (base["type"].asString() == "Warn") {
                this->_core.log().Warn(base["message"].asString());
            }
        } catch (std::exception &e) {
            this->_core.log().Danger(*event);
        }
        delete event;
    });
}

void JavascriptPlugin::postUpdate() {
    if (this->_clock.getMilliSeconds() < this->_updateJS) return;
    this->_clock.restart();
    Json::Value base;
    Json::Value sceneManager;
    Json::Value events;

    sceneManager["currentScene"] = this->getSceneJson(this->_core.getSceneManager().getCurrentScene());
    sceneManager["globalScene"] = this->getSceneJson(this->_core.getSceneManager().getGlobalScene());
    sceneManager["unloadScenes"] = this->getUnloadScenes();
    base["sceneManager"] = sceneManager;
    int i = 0;
    for (auto &event: this->_events) {
        if (event.second.empty()) continue;
        Json::Value eventJSON;
        eventJSON["name"] = event.first;
        int j = 0;
        for (const auto &eventInfo: event.second) {
            eventJSON["values"].insert(j, eventInfo);
            j++;
        }
        events.insert(i, eventJSON);
        i++;
        event.second.clear();
    }
    base["events"] = events;
    Json::FastWriter fastWriter;
    std::string output = fastWriter.write(base);
    client.socket()->emit("update", {output});
}

void JavascriptPlugin::preEnd() {
}

void JavascriptPlugin::end() {

}

void JavascriptPlugin::postEnd() {
    if (!this->client.opened()) {
        this->_core.log().Warn("Session nodeJS already closed...");
        return;
    }
    this->client.sync_close();
    this->_core.log().Info("Checking the end of node session");
    if (this->_thread.joinable()) {
        this->_core.log().Warn("Waiting the end of node session");
        this->_thread.join();
    }
    this->_core.log().Info("node session ended");
}

const Uniti::Clock &JavascriptPlugin::getClock() const {
    return this->_clock;
}

Uniti::Clock &JavascriptPlugin::getClock() {
    return this->_clock;
}

const Uniti::Event &JavascriptPlugin::getEvent() const {
    return this->_event;
}

Uniti::Event &JavascriptPlugin::getEvent() {
    return this->_event;
}

Json::Value JavascriptPlugin::getSceneJson(Uniti::Scene &scene) {
    Json::Value sceneJson;
    Json::Value objects;

    sceneJson["name"] = scene.getName();
    for (const auto &object: scene.getObjects().getObjects()) {
        objects[object->getName()] = this->getObjectJson(*object);
    }
    sceneJson["objects"] = objects;
    return sceneJson;
}

Json::Value JavascriptPlugin::getObjectJson(Uniti::Object &object) {
    Json::Value objectJson;
    Json::Value children;


    objectJson["position"]["x"] = object.getTransform().getPosition().getX();
    objectJson["position"]["y"] = object.getTransform().getPosition().getY();
    objectJson["rotation"] = object.getTransform().getRotation();
    objectJson["scale"]["x"] = object.getTransform().getScale().getX();
    objectJson["scale"]["y"] = object.getTransform().getScale().getY();
    objectJson["origin"]["x"] = object.getTransform().getOrigin().getX();
    objectJson["origin"]["y"] = object.getTransform().getOrigin().getY();
    objectJson["isEnable"] = object.isEnabled();
    objectJson["name"] = object.getName();
    for (const auto &child: object.getChildren().getObjects()) {
        children[child->getName()] = this->getObjectJson(*child);
    }
    objectJson["children"] = children;
    return objectJson;
}

Json::Value JavascriptPlugin::getUnloadScenes() {
    Json::Value unloadScenes;

    for (int i = 0; i < this->_core.getSceneManager().getAllScenes().size(); i++) {
        Json::Value sceneUnloaded;
        sceneUnloaded["name"] = this->_core.getSceneManager().getAllScenes()[i].name;
        sceneUnloaded["path"] = this->_core.getSceneManager().getAllScenes()[i].path;
        unloadScenes.insert(i, sceneUnloaded);
    }
    return unloadScenes;
}

void JavascriptPlugin::applyCoreEvent(const Json::Value &events) {
    std::map<std::string, std::function<void(const Json::Value &)>> functions;

    functions["emitEvent"] = [&](const Json::Value &value) {
        this->_core.emitEvent(value["name"].asString(), value["value"]);
    };
    for (const auto &event: events["events"]) {
        functions[event["name"].asString()](event["data"]);
    }
    this->applySceneManagerEvent(events["sceneManager"]);
    this->applyNetworkEvent(events["network"]);
}

void JavascriptPlugin::applySceneManagerEvent(const Json::Value &events) {
    std::map<std::string, std::function<void(const Json::Value &)>> functions;

    functions["emitEvent"] = [&](const Json::Value &value) {
        this->_core.getSceneManager().getGlobalScene().emitEvent(value["name"].asString(), value["value"]);
        this->_core.getSceneManager().getCurrentScene().emitEvent(value["name"].asString(), value["value"]);
    };
    functions["changeScene"] = [&](const Json::Value &value) {
        this->_core.getSceneManager().changeScene(value.asString());
    };
    for (const auto &event: events["events"]) {
        functions[event["name"].asString()](event["data"]);
    }
    this->applySceneEvent(this->_core.getSceneManager().getCurrentScene(), events["currentScene"]);
    this->applySceneEvent(this->_core.getSceneManager().getGlobalScene(), events["globalScene"]);
}

void JavascriptPlugin::applySceneEvent(Uniti::Scene &scene, const Json::Value &events) {
    std::map<std::string, std::function<void(const Json::Value &)>> functions;

    functions["emitEvent"] = [&](const Json::Value &value) {
        scene.emitEvent(value["name"].asString(), value["value"]);
    };
    functions["addObject"] = [&](const Json::Value &value) {
        scene.getObjects().add(value, scene);
    };
    functions["removeObject"] = [&](const Json::Value &value) {
        scene.getObjects().remove(value.asString());
    };
    for (const auto &event: events["events"]) {
        functions[event["name"].asString()](event["data"]);
    }
    for (const auto &object: events["objects"]) {
        auto element = Uniti::Object::find(object["name"].asString(), scene, false);
        if (!element) continue;
        this->applyObjectEvent(*element, object);
    }
}

void JavascriptPlugin::applyObjectEvent(Uniti::Object &object, const Json::Value &events) {
    std::map<std::string, std::function<void(const Json::Value &)>> functions;

    functions["clone"] = [&](const Json::Value &value) {
        object.getScene().getObjects().add(object);
    };
    functions["emitEvent"] = [&](const Json::Value &value) {
        object.emitEvent(value["name"].asString(), value["value"]);
    };
    object.getTransform().getPosition() = events["position"];
    object.getTransform().getRotation() = events["rotation"].asFloat();
    object.getTransform().getScale() = events["scale"];
    object.getTransform().getOrigin() = events["origin"];
    object.setEnable(events["isEnable"].asBool());
    for (const auto &event: events["events"]) {
        functions[event["name"].asString()](event["data"]);
    }
    for (const auto &child: events["children"]) {
        auto element = Uniti::Object::find(child["name"].asString(), object, false);
        if (!element) continue;
        this->applyObjectEvent(*element, child);
    }
}

void JavascriptPlugin::applyNetworkEvent(const Json::Value &events) {
    if (!this->_core.getPluginManager().has("NetworkPlugin")) return;
    for (const auto &event: events["events"])
        this->_core.getPluginManager().get("NetworkPlugin").getEvent().emitEvent(event["name"].asString(),
                                                                                 event["data"], this->_core.log());
}

void JavascriptPlugin::emitJSEvent(const std::string &name, const Json::Value &value) {
    if (!this->_events.contains(name))
        this->_events[name] = std::vector<Json::Value>();
    this->_events[name].push_back(value);
}
