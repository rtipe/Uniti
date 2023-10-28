//
// Created by youba on 27/10/2023.
//

#pragma once

#include <string>
#include <filesystem>
#include <memory>
#include <iostream>
#include "PluginFactory.hpp"

namespace Uniti {
    class PluginLoader {
    public:
        void loadCorePlugin(const std::string &directory);

        void loadScenePlugin(const std::string &directory);

        void loadObjectPlugin(const std::string &directory);

        template<typename Handler, typename Interface, typename Parent>
        void load(const std::string &directory) {
            std::string directoryCopy = directory;
            std::string currentFilePath;
            std::string fileName;

            for (const auto &entry: std::filesystem::directory_iterator(directoryCopy)) {
                currentFilePath = entry.path().string();
                fileName = entry.path().filename().string();
                size_t found = fileName.find('.');
                std::replace(currentFilePath.begin(), currentFilePath.end(), '\\', '/');
                PluginFactory<Handler, Interface, Parent>::getFactory().add(fileName.substr(0, found),
                                                                            std::make_unique<Handler>(currentFilePath));
            }
        }
    };
}
