//
// Created by youba on 25/10/2023.
//

#pragma once

#include "PluginHandler.hpp"
#include "ICorePlugin.hpp"
#include "IPluginCreator.hpp"
#include "TPluginManager.hpp"

namespace Uniti {
    class Core;
    class CorePluginManager : public TPluginManager<PluginHandler<ICorePlugin, IPluginCreator<ICorePlugin, Core>, Core>, ICorePlugin, Core> {
    public:
        CorePluginManager(const Json::Value &plugins, Core &parent, Logger &logger,
                          PluginFactory<PluginHandler<ICorePlugin, IPluginCreator<ICorePlugin, Core>, Core>, ICorePlugin, Core> &factory)
                : TPluginManager(plugins, parent,
                                 logger, factory) {}
        CorePluginManager(CorePluginManager &pluginManager) : TPluginManager(pluginManager) {}
    };
}
