//
// Created by youba on 25/10/2023.
//

#pragma once

#include "IPlugin.hpp"

namespace Uniti {
    class Scene;
    class IScenePlugin : public IPlugin {
    public:
        virtual Scene &getScene() = 0;
    };
}