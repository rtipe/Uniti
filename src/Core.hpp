//
// Created by youba on 25/10/2023.
//

#pragma once

#include <map>
#include <string>
#include <memory>
#include "json/value.h"
#include "SceneManager.hpp"
#include "ICorePlugin.hpp"

namespace Uniti {
    class Core {
    public:
        void start();
        void stop();
        static void initProject(const Json::Value &value);
        static Core &getInstance();
        Core &getSubInstance();
        std::map<std::string, std::unique_ptr<Core>> &getSubInstances();
        void openSubInstance(const std::string &name);
        void openSubInstance(const Json::Value &value);
        bool closeSubInstance(const std::string &name);
        const Core &operator[](const std::string &name) const;
        Core &operator[](const std::string &name);
        const SceneManager &getSceneManager() const;
        SceneManager &getSceneManager();
        const Json::Value &getData() const;
        Json::Value &getData();
        template<typename PLUGIN>
        PLUGIN &get(const std::string &name);
        void add(const std::string &name, std::unique_ptr<ICorePlugin> plugin);
        void addEventListener(const std::string &name, eventFunction);
        void emitEvent(const std::string &name, const Json::Value &value);
    };
}
