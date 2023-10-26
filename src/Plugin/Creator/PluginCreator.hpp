//
// Created by youba on 25/10/2023.
//

#pragma once

#include <vector>
#include "IPluginCreator.hpp"

namespace Uniti {
    template<typename INTERFACE, typename PLUGIN, typename PARENT>
    class PluginCreator : public IPluginCreator<INTERFACE, PARENT> {
    public:
        ~PluginCreator() {
            for (PLUGIN *element : this->_elements)
                delete element;
        }
        void remove(PLUGIN *element) {
            this->_elements.erase(element);
            delete element;
        }
        INTERFACE *create(PARENT &parent) {
            PLUGIN *element = new PLUGIN(parent);
            this->_elements.push_back(element);
            return element;
        }
    private:
        std::vector<PLUGIN *> _elements;
    };
}