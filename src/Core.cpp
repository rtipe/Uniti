//
// Created by youba on 25/10/2023.
//

#include <filesystem>
#include "Core.hpp"

namespace Uniti {
    void Core::start() {
        std::unique_lock<std::mutex> lock(this->_mutexForStop);

        srand(time(NULL));
        this->_logger.changePath("Core:" + this->_value.get("name", "").asString());
        while (!this->_stop) {
            lock.unlock();
            this->_pluginManager.preUpdate();
            this->_sceneManager.update();
            this->_pluginManager.update();
            this->_queue.consume_all([&](std::tuple<std::string, Json::Value> *event) {
                std::string oldPath = this->_logger.getPath();
                this->_logger.changePath(
                        this->_logger.getPath() + " > (CoreEvent -> core:" + this->_value.get("name", "").asString() +
                        " Event:" + std::get<0>(*event) + ")");
                try {
                    this->_event.emitEvent(std::get<0>(*event), std::get<1>(*event), _logger);
                } catch (std::exception &e) {
                    this->_logger.Danger(e.what());
                }
                this->_logger.changePath(oldPath);
                delete event;
            });
            this->_pluginManager.postUpdate();
            lock.lock();
        }
        this->_pluginManager.preEnd();
        this->_sceneManager.end();
        this->_pluginManager.end();
        this->_pluginManager.postEnd();
        this->_logger.Warn("bye !");
    }

    void Core::stop() {
        const std::lock_guard<std::mutex> lock(this->_mutexForStop);
        this->_logger.Warn("Shutdown request");
        this->_stop = true;
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
        }, std::ref(*core));
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
            _coreFactory(value.get("CorePlugins", "").asString()),
            _objectFactory(value.get("ObjectPlugins", "").asString()),
            _sceneFactory(value.get("ScenePlugins", "").asString()),
            _logger(),
    _value(value),
    _queue(10000),
            _pluginManager(value["plugins"], *this, _logger, this->_coreFactory),
            _sceneManager(value, *this) {
    }

    Core::~Core() {
        std::vector<std::string> keys;

        for (const auto &subInstance : this->_subInstances)
            keys.push_back(subInstance.first);
        for (const auto &key : keys)
            this->closeSubInstance(key);
    }

    const Logger &Core::log() const {
        return this->_logger;
    }

    Logger &Core::log() {
        return this->_logger;
    }

    const CorePluginManager &Core::getPluginManager() const {
        return this->_pluginManager;
    }

    CorePluginManager &Core::getPluginManager() {
        return this->_pluginManager;
    }

    PluginFactory<PluginHandler<ICorePlugin, IPluginCreator<ICorePlugin, Core>, Core>, ICorePlugin, Core>
    &Core::getCoreFactory() {
        return this->_coreFactory;
    }

    PluginFactory<PluginHandler<IObjectPlugin, IPluginCreator<IObjectPlugin, Object>, Object>, IObjectPlugin, Object>
    &Core::getObjectFactory() {
        return this->_objectFactory;
    }

    PluginFactory<PluginHandler<IScenePlugin, IPluginCreator<IScenePlugin, Scene>, Scene>, IScenePlugin, Scene>
    &Core::getSceneFactory() {
        return this->_sceneFactory;
    }

    void Core::loadCoreFactory(const std::string &directory) {
        this->load<PluginHandler<ICorePlugin, IPluginCreator<ICorePlugin, Core>, Core>, ICorePlugin, Core>(directory,
                                                                                                           this->_coreFactory);
    }

    void Core::loadObjectFactory(const std::string &directory) {
        this->load<PluginHandler<IObjectPlugin, IPluginCreator<IObjectPlugin, Object>, Object>, IObjectPlugin, Object>(
                directory, this->_objectFactory);
    }

    void Core::loadSceneFactory(const std::string &directory) {
        this->load<PluginHandler<IScenePlugin, IPluginCreator<IScenePlugin, Scene>, Scene>, IScenePlugin, Scene>(
                directory, this->_sceneFactory);
    }
}