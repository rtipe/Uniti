//
// Created by youba on 25/10/2023.
//

#include "Core.hpp"

namespace Uniti {
    void Core::start() {
        std::unique_lock<std::mutex> lock(this->_mutexForStop);

        std::string oldPath = Logger::getPath();
        Logger::changePath(Logger::getPath() + " > Core:" + this->_value.get("name", "").asString());
        while (this->_stop) {
            lock.unlock();
            this->_pluginManager.preUpdate();
            this->_sceneManager.update();
            this->_pluginManager.update();
            this->_queue.consume_all([&](std::tuple<std::string, Json::Value> *event) {
                std::string oldPath = Logger::getPath();
                Logger::changePath(
                        Logger::getPath() + " > (CoreEvent -> core:" + this->_value.get("name", "").asString() +
                        " Event:" + std::get<0>(*event) + ")");
                try {
                    this->_event.emitEvent(std::get<0>(*event), std::get<1>(*event));
                } catch (std::exception &e) {
                    Logger::Danger(e.what());
                }
                Logger::changePath(oldPath);
                delete event;
            });
            this->_pluginManager.postUpdate();
            lock.lock();
        }
        this->_pluginManager.preEnd();
        this->_sceneManager.end();
        this->_pluginManager.end();
        this->_pluginManager.postEnd();
        Logger::Warn("bye !");
        Logger::changePath(oldPath);
    }

    void Core::stop() {
        const std::lock_guard<std::mutex> lock(this->_mutexForStop);
        Logger::Warn("Shutdown request");
        this->_stop = true;
    }

    void Core::initProject(const Json::Value &value) {
        Logger::Info("Starting project : " + value.get("name", "").asString());
        _instance.reset(new Core(value));
    }

    void Core::initProject(const std::string &fileName) {
        _instance.reset(new Core(Object::openJsonFile(fileName)));
    }

    Core &Core::getInstance() {
        return *_instance;
    }

    Core &Core::getSubInstance(const std::string &name) {
        return *std::get<0>(this->_subInstances.at(name));
    }

    std::map<std::string, std::tuple<std::unique_ptr<Core>, std::thread>> &Core::getSubInstances() {
        return this->_subInstances;
    }

    void Core::openSubInstance(const std::string &name) {
        this->openSubInstance(Object::openJsonFile(name));
    }

    void Core::openSubInstance(const Json::Value &value) {
        std::unique_ptr<Core> core = std::make_unique<Core>(value);
        std::thread thread = std::thread([](Core &core) {
            core.start();
        }, std::ref(*core.get()));
        this->_subInstances[value["name"].asString()] = {std::move(core), std::move(thread)};
    }

    bool Core::closeSubInstance(const std::string &name) {
        if (!this->_subInstances.contains(name)) return false;
        std::get<0>(this->_subInstances[name])->stop();
        std::get<1>(this->_subInstances[name]).join();
        this->_subInstances.erase(name);
        return true;
    }

    const Core &Core::operator[](const std::string &name) const {
        if (!this->_subInstances.contains(name)) throw std::runtime_error("Invalid subInstance name (" + name + ")");
        return *std::get<0>(this->_subInstances.at(name));
    }

    Core &Core::operator[](const std::string &name) {
        if (!this->_subInstances.contains(name)) throw std::runtime_error("Invalid subInstance name (" + name + ")");
        return *std::get<0>(this->_subInstances.at(name));
    }

    const SceneManager &Core::getSceneManager() const {
        return this->_sceneManager;
    }

    SceneManager &Core::getSceneManager() {
        return this->_sceneManager;
    }

    const Json::Value &Core::getData() const {
        return this->_value;
    }

    Json::Value &Core::getData() {
        return this->_value;
    }

    void Core::addEventListener(const std::string &name, eventFunction function) {
        this->_event.addEvent(name, function);
    }

    void Core::emitEvent(const std::string &name, const Json::Value &value) {
        auto *event = new std::tuple<std::string, Json::Value>(name, value);
        this->_queue.push(event);
    }

    Core::Core(const Json::Value &value):
    _value(value),
    _queue(10000),
    _pluginManager(value["plugins"], *this),
    _sceneManager(value) {}

    Core::~Core() {
        std::vector<std::string> keys;

        for (const auto &subInstance : this->_subInstances)
            keys.push_back(subInstance.first);
        for (const auto &key : keys)
            this->closeSubInstance(key);
    }
}