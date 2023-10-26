//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <map>
#include <memory>
#include <stdexcept>

namespace Uniti {
    template<typename Handler, typename Interface, typename Parent>
    class PluginFactory {
    public:
        ~PluginFactory() = default;
        void add(const std::string &name, std::unique_ptr<Handler> handler) {
            Logger::Info("add plugin -> " + name);
            this->_stock[name] = std::move(handler);
        }
        Interface &get(const std::string &name, Parent &parent) {
            Logger::Info("creating new instance of -> " + name);
            if (_stock.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            return this->_stock.at(name)->get(parent);
        }
        void removeElement(const std::string &name, Interface &element) {
            Logger::Info("removing instance of -> " + name);
            if (_stock.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            this->_stock.at(name)->deleteElement(&element);
        }
        static PluginFactory<Handler, Interface, Parent> &getFactory() {
            if (_factory == nullptr) {
                _factory.reset(new PluginFactory<Handler, Interface, Parent>());
            }
            return *_factory;
        }
        void clearAll() {
            _stock.clear();
        }
    private:
        PluginFactory() = default;
        static std::unique_ptr<PluginFactory<Handler, Interface, Parent>> _factory;
        std::map<std::string, std::unique_ptr<Handler>> _stock;
    };
}
