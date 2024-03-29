//
// Created by youba on 25/10/2023.
//

#pragma once

#include "PluginHandler.hpp"
#include "IScenePlugin.hpp"
#include "IPluginCreator.hpp"
#include "TPluginManager.hpp"
#include "PluginFactory.hpp"

namespace Uniti {
    class Scene;
    class ScenePluginManager : public TPluginManager<PluginHandler<IScenePlugin, IPluginCreator<IScenePlugin, Scene>, Scene>, IScenePlugin, Scene> {
    public:
        ScenePluginManager(const Json::Value &plugins, Scene &parent, Logger &logger,
                           PluginFactory<PluginHandler<IScenePlugin, IPluginCreator<IScenePlugin, Scene>, Scene>, IScenePlugin, Scene> &factory)
                : TPluginManager(plugins, parent,
                                 logger, factory) {}
        ScenePluginManager(ScenePluginManager &pluginManager) : TPluginManager(pluginManager) {}
    };
}
