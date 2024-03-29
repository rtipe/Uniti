//
// Created by youba on 25/10/2023.
//

#pragma once

#include "PluginHandler.hpp"
#include "IObjectPlugin.hpp"
#include "IPluginCreator.hpp"
#include "TPluginManager.hpp"

namespace Uniti {
    class Object;
    class ObjectPluginManager : public TPluginManager<PluginHandler<IObjectPlugin, IPluginCreator<IObjectPlugin, Object>, Object>, IObjectPlugin, Object> {
    public:
        ObjectPluginManager(const Json::Value &plugins, Object &parent, Logger &logger,
                            PluginFactory<PluginHandler<IObjectPlugin, IPluginCreator<IObjectPlugin, Object>, Object>, IObjectPlugin, Object> &factory)
                : TPluginManager(plugins,
                                                                                                         parent,
                                 logger, factory) {}
        ObjectPluginManager(ObjectPluginManager &pluginManager) : TPluginManager(pluginManager) {}
    };
}