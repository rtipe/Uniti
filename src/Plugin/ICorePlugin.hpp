//
// Created by youba on 25/10/2023.
//

#pragma once

#include "IPlugin.hpp"

namespace Uniti {
    class Core;
    class ICorePlugin : public IPlugin {
    public:
        virtual Core &getCore() = 0;
    };
}