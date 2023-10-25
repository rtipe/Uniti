//
// Created by youba on 25/10/2023.
//

#pragma once

namespace Uniti {
    template<typename PLUGIN>
    class IPluginCreator {
    public:
        virtual ~IPluginCreator() = default;
        virtual PLUGIN *create() = 0;
    };
}