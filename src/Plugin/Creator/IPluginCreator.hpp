//
// Created by youba on 25/10/2023.
//

#pragma once

namespace Uniti {
    template<typename PLUGIN, typename PARENT>
    class IPluginCreator {
    public:
        /** @brief Default virtual destructor for the IPluginCreator class.
        */
        virtual ~IPluginCreator() = default;

        /** @brief Pure virtual function to remove a PLUGIN element.
            @param PLUGIN *element: A pointer to the PLUGIN element to remove.
        */
        virtual void remove(PLUGIN *element) = 0;

        /** @brief Pure virtual function to create a PLUGIN element.
            @param PARENT &parent: Reference to the parent of the PLUGIN element.
            @return PLUGIN *: Pointer to the newly created PLUGIN element.
        */
        virtual PLUGIN *create(PARENT &parent) = 0;
    };
}
