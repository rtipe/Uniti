//
// Created by youba on 25/10/2023.
//

#pragma once

#include <optional>
#include "Scene.hpp"
#include "ScenePath.hpp"

namespace Uniti {
    class Core;
    class SceneManager {
    public:
        /** @brief Constructor for the SceneManager class.
            @param const Json::Value &value: JSON configuration data for scenes.
            @param Core &core: Reference to the Core instance.
        */
        SceneManager(const Json::Value &value, Core &core);

        /** @brief Get a constant reference to the current scene.
            @return const Scene &: Constant reference to the current scene.
        */
        const Scene &getCurrentScene() const;

        /** @brief Get a reference to the current scene.
            @return Scene &: Reference to the current scene.
        */
        Scene &getCurrentScene();

        /** @brief Get a constant reference to the global scene.
            @return const Scene &: Constant reference to the global scene.
        */
        const Scene &getGlobalScene() const;

        /** @brief Get a reference to the global scene.
            @return Scene &: Reference to the global scene.
        */
        Scene &getGlobalScene();

        /** @brief Get a constant reference to a vector of all scene paths.
            @return const std::vector<ScenePath> &: Constant reference to all scene paths.
        */
        const std::vector<ScenePath> &getAllScenes() const;

        /** @brief Get a constant reference to a specific scene path by name.
            @param const std::string &name: Name of the scene path.
            @return const ScenePath &: Constant reference to the specified scene path.
        */
        const ScenePath &getScenePath(const std::string &name) const;

        /** @brief Add a scene path to the list of available scenes.
            @param ScenePath &scenePath: The scene path to add.
        */
        void addScenePath(ScenePath &scenePath);

        /** @brief Change the current scene to the scene with the given name.
            @param const std::string &name: Name of the scene to change to.
            @return bool: True if the scene change was successful, false otherwise.
        */
        bool changeScene(const std::string &name);

        /** @brief Update the current scene, typically called once per frame.
        */
        void update();

        /** @brief End the current scene, perform cleanup.
        */
        void end();

        /** @brief Get the JSON configuration data for a specific scene path.
            @param const ScenePath &scenePath: The scene path for which to retrieve the data.
            @return Json::Value: JSON data for the specified scene path.
        */
        Json::Value getSceneValue(const ScenePath &scenePath) const;

        /** @brief Get a constant reference to the Core instance.
            @return const Core &: Constant reference to the Core instance.
        */
        const Core &getCore() const;

        /** @brief Get a reference to the Core instance.
            @return Core &: Reference to the Core instance.
        */
        Core &getCore();
    private:
        Core &_core;
        std::unique_ptr<Scene> _globalScene;
        std::unique_ptr<Scene> _currentScene;
        std::optional<ScenePath> _nextScene = std::nullopt;
        std::vector<ScenePath> _scenes;
        const std::string _sceneFolderPath;
    };
}
