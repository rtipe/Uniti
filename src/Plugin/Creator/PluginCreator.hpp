//
// Created by youba on 25/10/2023.
//

#pragma once

#include <vector>
#include <algorithm>
#include "IPluginCreator.hpp"

namespace Uniti {
    template<typename Interface, typename PLUGIN, typename PARENT>
    class PluginCreator : public IPluginCreator<Interface, PARENT> {
    public:
        /** @brief Destructor for the PluginCreator class.
            Deletes all elements and frees memory.
        */
        ~PluginCreator() {
            for (PLUGIN *element : this->_elements)
                delete element;
        }

        /** @brief Removes an Interface element from the elements list.
            @param Interface *element: A pointer to the Interface element to remove.
        */
        void remove(Interface *element) {
            this->_elements.erase(std::find(this->_elements.begin(), this->_elements.end(), element));
            delete element;
        }

        /** @brief Creates a new Interface element and adds it to the elements list.
            @param PARENT &parent: Reference to the parent of the new Interface element.
            @return Interface *: Pointer to the newly created Interface element.
        */
        Interface *create(PARENT &parent) {
            PLUGIN *element = new PLUGIN(parent);
            this->_elements.push_back(element);
            return element;
        }
    private:
        std::vector<PLUGIN *> _elements;
    };
}
