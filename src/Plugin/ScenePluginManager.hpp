//
// Created by youba on 25/10/2023.
//

#pragma once

#include "PluginHandler.hpp"
#include "IScenePlugin.hpp"
#include "IPluginCreator.hpp"
#include "TPluginManager.hpp"

namespace Uniti {
    class ScenePluginManager : public TPluginManager<PluginHandler<IScenePlugin, IPluginCreator<IScenePlugin>>, IScenePlugin> {};
}
