//
// Created by youba on 25/10/2023.
//

#pragma once

#include "Scene.hpp"
#include "ScenePath.hpp"

namespace Uniti {
    class SceneManager {
    public:
        SceneManager(const Json::Value &value);
        const Scene &getCurrentScene() const;
        Scene &getCurrentScene();
        const Scene &getGlobalScene() const;
        Scene &getGlobalScene();
        const std::vector<ScenePath> &getAllScenes() const;
        const ScenePath &getScenePath(const std::string &name) const;
        void addScenePath(ScenePath &scenePath);
        bool changeScene(const std::string &name);
        void update();
        Json::Value getSceneValue(const ScenePath &scenePath) const;
    };
}
