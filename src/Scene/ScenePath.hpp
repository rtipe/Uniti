//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <utility>

namespace Uniti {
    struct ScenePath {
        /** @brief Constructor for the ScenePath struct.
            @param std::string _name: The name of the scene path.
            @param std::string _path: The file path associated with the scene.
        */
        ScenePath(std::string _name, std::string _path): name(std::move(_name)), path(std::move(_path)) {}

        std::string name;
        std::string path;
    };
}

