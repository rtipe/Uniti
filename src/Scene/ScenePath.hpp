//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <utility>

namespace Uniti {
    struct ScenePath {
        ScenePath(std::string _name, std::string _path): name(std::move(_name)), path(std::move(_path)) {}
        std::string name;
        std::string path;
    };
}
