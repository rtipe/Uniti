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
        /** @brief Constructor for the PluginFactory class.
            Scans the specified directory for plugin files and initializes the factory.
            @param const std::string &directory: Directory path to scan for plugin files.
        */
        PluginFactory(const std::string &directory) {
            if (directory.empty()) return;
            std::string directoryCopy = directory;
            std::string currentFilePath;
            std::string fileName;

            for (const auto &entry : std::filesystem::directory_iterator(directoryCopy)) {
                currentFilePath = entry.path().string();
                fileName = entry.path().filename().string();
                size_t found = fileName.find('.');
                std::replace(currentFilePath.begin(), currentFilePath.end(), '\\', '/');
                this->add(fileName.substr(0, found), std::make_unique<Handler>(currentFilePath));
            }
        }

        /** @brief Destructor for the PluginFactory class.
            Cleans up resources and handles memory deallocation.
        */
        ~PluginFactory() = default;

        /** @brief Adds a plugin handler to the factory.
            @param const std::string &name: Name of the plugin.
            @param std::unique_ptr<Handler> handler: Unique pointer to the plugin handler.
        */
        void add(const std::string &name, std::unique_ptr<Handler> handler) {
            this->_stock[name] = std::move(handler);
        }

        /** @brief Gets an instance of the Interface from the factory based on the specified name.
            @param const std::string &name: Name of the plugin to retrieve.
            @param Parent &parent: Reference to the parent object.
            @return Interface &: Reference to the Interface instance.
            @throw std::runtime_error if the specified plugin name is not found.
        */
        Interface &get(const std::string &name, Parent &parent) {
            if (_stock.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            return this->_stock.at(name)->get(parent);
        }

        /** @brief Removes an Interface element associated with a specific plugin name.
            @param const std::string &name: Name of the plugin to remove the element from.
            @param Interface &element: Reference to the Interface element to remove.
            @throw std::runtime_error if the specified plugin name is not found.
        */
        void removeElement(const std::string &name, Interface &element) {
            if (_stock.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            this->_stock.at(name)->deleteElement(&element);
        }

        /** @brief Clears all plugins and associated elements from the factory.
        */
        void clearAll() {
            _stock.clear();
        }
    private:
        std::map<std::string, std::unique_ptr<Handler>> _stock;
    };
}

