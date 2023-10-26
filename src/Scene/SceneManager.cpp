//
// Created by youba on 25/10/2023.
//

#include "SceneManager.hpp"
#include <filesystem>
#include <fstream>
#include <json/json.h>


namespace Uniti {
    SceneManager::SceneManager(const Json::Value &value): _sceneFolderPath(value["sceneFolder"].asString()) {
        for (const auto &entry: std::filesystem::recursive_directory_iterator(this->_sceneFolderPath)) {
            std::string fullPath = entry.path().string();
            std::string directoryPath, fileType, fileName;
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
                    this->_scenes.emplace_back(fileName, directoryPath);
                }
            }
        }
        auto globalScenePath = this->getScenePath(value["startScene"].asString());
        auto startScenePath  = this->getScenePath(value["globalScene"].asString());;
        this->_globalScene =
            std::make_unique<Scene>(this->getSceneValue(globalScenePath), globalScenePath.name);
        this->_currentScene =
            std::make_unique<Scene>(this->getSceneValue(startScenePath), startScenePath.name);
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
        if (this->_nextScene != std::nullopt) {
            this->_currentScene = std::make_unique<Scene>(
            this->getSceneValue(this->_nextScene.value()), this->_nextScene->name);
            this->_nextScene = std::nullopt;
        }
        this->_currentScene->update();
        this->_globalScene->update();
    }

    Json::Value SceneManager::getSceneValue(const ScenePath &scenePath) const {
        std::ifstream file(scenePath.path);
        Json::Value scene;
        file >> scene;
        return scene;
    }
} // Uniti