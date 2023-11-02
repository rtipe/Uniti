//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <filesystem>
#include <string>
#include <map>
#include <memory>
#include <stdexcept>
#include "Logger.hpp"

namespace Uniti {
    template<typename Handler, typename Interface, typename Parent>
    class PluginFactory {
    public:
        PluginFactory(const std::string &directory) {
            if (directory.empty()) return;
            std::string directoryCopy = directory;
            std::string currentFilePath;
            std::string fileName;

            for (const auto &entry: std::filesystem::directory_iterator(directoryCopy)) {
                currentFilePath = entry.path().string();
                fileName = entry.path().filename().string();
                size_t found = fileName.find('.');
                std::replace(currentFilePath.begin(), currentFilePath.end(), '\\', '/');
                this->add(fileName.substr(0, found), std::make_unique<Handler>(currentFilePath));
            }
        }
        ~PluginFactory() = default;
        void add(const std::string &name, std::unique_ptr<Handler> handler) {
            this->_stock[name] = std::move(handler);
        }
        Interface &get(const std::string &name, Parent &parent) {
            if (_stock.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            return this->_stock.at(name)->get(parent);
        }
        void removeElement(const std::string &name, Interface &element) {
            if (_stock.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            this->_stock.at(name)->deleteElement(&element);
        }
        void clearAll() {
            _stock.clear();
        }
    private:
        std::map<std::string, std::unique_ptr<Handler>> _stock;
    };
}
