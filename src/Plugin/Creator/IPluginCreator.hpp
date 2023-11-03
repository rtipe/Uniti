//
// Created by youba on 25/10/2023.
//

#pragma once

namespace Uniti {
    template<typename PLUGIN, typename PARENT>
    class IPluginCreator {
    public:
        virtual ~IPluginCreator() = default;
        virtual void remove(PLUGIN *element) = 0;
        virtual PLUGIN *create(PARENT &parent) = 0;
    };
}