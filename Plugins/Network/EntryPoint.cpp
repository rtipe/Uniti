//
// Created by youba on 29/10/2023.
//

#include "NetworkPlugin.hpp"
#include "API.hpp"
#include "PluginCreator.hpp"
#include "ICorePlugin.hpp"

extern "C" {
void *getCreator(void) {
    return new Uniti::PluginCreator<Uniti::ICorePlugin, NetworkPlugin, Uniti::Core>();
}

void deleteCreator(void *creator) {
    delete static_cast<Uniti::PluginCreator<Uniti::ICorePlugin, NetworkPlugin, Uniti::Core> *>(creator);
}
}