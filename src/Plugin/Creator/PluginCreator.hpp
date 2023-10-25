//
// Created by youba on 25/10/2023.
//

#pragma once

#include <vector>
#include "IPluginCreator.hpp"

namespace Uniti {
    template<typename INTERFACE, typename PLUGIN>
    class PluginCreator : public IPluginCreator<INTERFACE> {
    public:
        ~PluginCreator() {
            for (PLUGIN *element : this->_elements)
                delete element;
        }
        void remove(PLUGIN *element) {
            this->_elements.erase(element);
            delete element;
        }
        INTERFACE *create() {
            PLUGIN *element = new PLUGIN();
            this->_elements.push_back(element);
            return element;
        }
    private:
        std::vector<PLUGIN *> _elements;
    };
}