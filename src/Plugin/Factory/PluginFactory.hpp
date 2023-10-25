//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <memory>

namespace Uniti {
    template<typename Handler, typename Interface>
    class PluginFactory {
    public:
        ~PluginFactory() = default;
        void add(const std::string &name, std::unique_ptr<Handler> handler);
        Interface &get(const std::string &name);
        static PluginFactory<Handler, Interface> &getFactory();
        void clearAll();
    };
}
