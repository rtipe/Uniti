//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include "json/value.h"

namespace Uniti {
    template<typename PLUGIN>
    class PluginManager {
    public:
        void add(const std::string &name, const Json::Value &value);
        void remove(const std::string &name);
        const PLUGIN &get(const std::string &name) const;
        PLUGIN &get(const std::string &name);
        bool has(const std::string &name) const;
        void update();
        void start();
        void end();
        void emitEvent(const std::string &name, const Json::Value &value);
    private:
        std::map<std::string, std::reference_wrapper<PLUGIN>> _plugins;
    };
}
