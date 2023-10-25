//
// Created by youba on 25/10/2023.
//

#pragma once

#include "IPlugin.hpp"

namespace Uniti {
    class Object;
    class IObjectPlugin : public IPlugin {
    public:
        virtual Object &getObject() = 0;
    };
}