//
// Created by youba on 28/10/2023.
//

#include "API.hpp"
#include "Core.hpp"
#include "PluginCreator.hpp"
#include "ICorePlugin.hpp"
#include "RenderPlugin.hpp"

extern "C" {
void *getCreator(void) {
    return new Uniti::PluginCreator<Uniti::ICorePlugin, RenderPlugin, Uniti::Core>();
}

void deleteCreator(void *creator) {
    delete static_cast<Uniti::PluginCreator<Uniti::ICorePlugin, RenderPlugin, Uniti::Core> *>(creator);
}
}
