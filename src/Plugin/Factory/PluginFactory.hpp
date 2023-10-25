//
// Created by youba on 25/10/2023.
//

#pragma once

#include <string>
#include <map>
#include <memory>
#include <stdexcept>

namespace Uniti {
    template<typename Handler, typename Interface>
    class PluginFactory {
    public:
        ~PluginFactory() = default;
        void add(const std::string &name, std::unique_ptr<Handler> handler) {
            this->_stock[name] = std::move(handler);
        }
        Interface &get(const std::string &name) {
            if (_stock.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            return this->_stock.at(name)->get();
        }
        void removeElement(const std::string &name, Interface &element) {
            if (_stock.count(name) == 0)
                throw std::runtime_error(name + " <- not found");
            this->_stock.at(name)->deleteElement(&element);
        }
        static PluginFactory<Handler, Interface> &getFactory() {
            if (_factory == nullptr) {
                _factory.reset(new PluginFactory<Handler, Interface>());
            }
            return *_factory;
        }
        void clearAll() {
            _stock.clear();
        }
    private:
        PluginFactory() = default;
        static std::unique_ptr<PluginFactory<Handler, Interface>> _factory;
        std::map<std::string, std::unique_ptr<Handler>> _stock;
    };
}
