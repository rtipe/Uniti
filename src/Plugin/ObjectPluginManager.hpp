//
// Created by youba on 25/10/2023.
//

#pragma once

#include "PluginHandler.hpp"
#include "IObjectPlugin.hpp"
#include "IPluginCreator.hpp"
#include "TPluginManager.hpp"

namespace Uniti {
    class ObjectPluginManager : public TPluginManager<PluginHandler<IObjectPlugin, IPluginCreator<IObjectPlugin>>, IObjectPlugin> {};
}