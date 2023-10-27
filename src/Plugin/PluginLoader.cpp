//
// Created by youba on 27/10/2023.
//

#include "PluginLoader.hpp"
#include "ICorePlugin.hpp"
#include "IScenePlugin.hpp"
#include "IObjectPlugin.hpp"
#include "IPluginCreator.hpp"
#include "Core.hpp"

namespace Uniti {
    void PluginLoader::loadCorePlugin(const std::string &directory) {
        this->load<PluginHandler<ICorePlugin, IPluginCreator<ICorePlugin, Core>, Core>, ICorePlugin, Core>(directory);
    }

    void PluginLoader::loadScenePlugin(const std::string &directory) {
        this->load<PluginHandler<IScenePlugin, IPluginCreator<IScenePlugin, Scene>, Scene>, IScenePlugin, Scene>(
                directory);
    }

    void PluginLoader::loadObjectPlugin(const std::string &directory) {
        this->load<PluginHandler<IObjectPlugin, IPluginCreator<IObjectPlugin, Object>, Object>, IObjectPlugin, Object>(
                directory);
    }
}