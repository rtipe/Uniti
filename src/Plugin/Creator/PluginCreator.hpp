//
// Created by youba on 25/10/2023.
//

#pragma once

#include <vector>
#include "IPluginCreator.hpp"

namespace Uniti {
    template<typename Interface, typename PLUGIN, typename PARENT>
    class PluginCreator : public IPluginCreator<Interface, PARENT> {
    public:
        ~PluginCreator() {
            for (PLUGIN *element : this->_elements)
                delete element;
        }

        void remove(Interface *element) {
            this->_elements.erase(std::find(this->_elements.begin(), this->_elements.end(), element));
            delete element;
        }

        Interface *create(PARENT &parent) {
            PLUGIN *element = new PLUGIN(parent);
            this->_elements.push_back(element);
            return element;
        }
    private:
        std::vector<PLUGIN *> _elements;
    };
}