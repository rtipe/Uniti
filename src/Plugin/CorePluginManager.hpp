//
// Created by youba on 25/10/2023.
//

#pragma once

#include "PluginHandler.hpp"
#include "ICorePlugin.hpp"
#include "IPluginCreator.hpp"
#include "TPluginManager.hpp"

namespace Uniti {
    class CorePluginManager : public TPluginManager<PluginHandler<ICorePlugin, IPluginCreator<ICorePlugin>>, ICorePlugin> {};
}
