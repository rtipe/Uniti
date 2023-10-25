//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <vector>

namespace Uniti {
    template<typename Interface, typename Creator>
    class PluginHandler {
    public:
        PluginHandler(const std::string &filePath);
        ~PluginHandler();
        Interface &get();
        void deleteElement(Interface &element);
    protected:
        template<typename T, typename... Args>
        T getResult(const std::string &name, Args&&... __args) {

        }
        Creator *_creator;
        std::vector<Interface *> _elements;
        std::string _filePath;
        void *_handler;
    };
}