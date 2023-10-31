//
// Created by youba on 25/10/2023.
//

#include "SceneManager.hpp"
#include <filesystem>
#include <fstream>
#include <json/json.h>
#include "Core.hpp"

namespace Uniti {
    SceneManager::SceneManager(const Json::Value &value, Core &core) :
            _sceneFolderPath(value["sceneFolder"].asString()),
            _core(core) {
        this->_core.log().changePath("SceneManager");
        this->_core.log().Info("Start loading directory scenes : " + this->_sceneFolderPath);
        for (const auto &entry: std::filesystem::recursive_directory_iterator(this->_sceneFolderPath)) {
            std::string fullPath = entry.path().string();
            std::string directoryPath, fileType, fileName;
            std::replace(fullPath.begin(), fullPath.end(), '\\', '/');
            auto pos = fullPath.find_last_of('/');

            if (pos != std::string::npos) {
                directoryPath = fullPath.substr(0, pos);
                directoryPath += '/';
                auto posFileType = fullPath.find_last_of('.');
                fileType = fullPath.substr(posFileType, fullPath.size());
                if (fileType == ".json") {
                    pos += 1;
                    fileName = fullPath.substr(pos, posFileType - pos) += ".json";
                    directoryPath += fileName;
                    this->_core.log().Info("Add scene -> " + fileName);
                    this->_scenes.emplace_back(fileName, directoryPath);
                }
            }
        }
        auto globalScenePath = this->getScenePath(value["globalScene"].asString());
        auto startScenePath = this->getScenePath(value["startScene"].asString());
        this->_core.log().Info("Loading global scene -> " + globalScenePath.name);
        this->_globalScene =
                std::make_unique<Scene>(this->getSceneValue(globalScenePath), core, globalScenePath.name);
        this->_core.log().Info("Loading start scene -> " + startScenePath.name);
        this->_currentScene =
                std::make_unique<Scene>(this->getSceneValue(startScenePath), core, startScenePath.name);
        this->_core.log().changePath("");
    }

    const Scene &SceneManager::getCurrentScene() const {
        return *this->_currentScene;
    }

    Scene &SceneManager::getCurrentScene() {
        return *this->_currentScene;
    }

    const Scene &SceneManager::getGlobalScene() const {
        return *this->_globalScene;
    }

    Scene &SceneManager::getGlobalScene() {
        return *this->_globalScene;
    }

    const std::vector<ScenePath> &SceneManager::getAllScenes() const {
        return this->_scenes;
    }

    const ScenePath &SceneManager::getScenePath(const std::string &name) const {
        auto it = std::find_if(
        this->getAllScenes().begin(),
        this->getAllScenes().end(),
        [&](const ScenePath &path) {
                return path.name == name;
            }
        );
        if (it == this->getAllScenes().end()) throw std::runtime_error("ScenePath not found > " + name);
        return *it;
    }

    void SceneManager::addScenePath(ScenePath &scenePath) {
        this->_scenes.push_back((scenePath));
    }

    bool SceneManager::changeScene(const std::string &name) {
        auto it = std::find_if(
            this->getAllScenes().begin(),
            this->getAllScenes().end(),
            [&](const ScenePath &path) {
                return path.name == name;
            }
        );
        if (it == this->getAllScenes().end())
            return false;
        this->_nextScene = *it;
        return true;
    }

    void SceneManager::update() {
        std::string oldPath = this->_core.log().getPath();
        this->_core.log().changePath(this->_core.log().getPath() + " > SceneManager");
        if (this->_nextScene != std::nullopt) {
            this->_core.log().Info(
                    "Changing scene : " + this->_currentScene.get()->getName() + " to " + this->_nextScene->name);
            try {
                this->_currentScene = std::make_unique<Scene>(
                        this->getSceneValue(this->_nextScene.value()), this->_core, this->_nextScene->name);
                this->_nextScene = std::nullopt;
            } catch (std::exception &e) {
                this->_core.log().Danger(e.what());
            }
        }
        this->_currentScene->update();
        this->_globalScene->update();
        this->_core.log().changePath(oldPath);
    }

    Json::Value SceneManager::getSceneValue(const ScenePath &scenePath) const {
        std::ifstream file(scenePath.path);
        Json::Value scene;
        file >> scene;
        return scene;
    }

    void SceneManager::end() {
        std::string oldPath = this->_core.log().getPath();
        this->_core.log().changePath(this->_core.log().getPath() + " > SceneManager");
        this->_currentScene->end();
        this->_globalScene->end();
        this->_core.log().changePath(oldPath);
    }

    const Core &SceneManager::getCore() const {
        return this->_core;
    }

    Core &SceneManager::getCore() {
        return this->_core;
    }
}