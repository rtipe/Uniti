//
// Created by youba on 30/10/2023.
//

#include "JavascriptPlugin.hpp"
#include "API.hpp"
#include "PluginCreator.hpp"

extern "C" {
void *getCreator(void) {
    return new Uniti::PluginCreator<Uniti::ICorePlugin, JavascriptPlugin, Uniti::Core>();
}

void deleteCreator(void *creator) {
    delete static_cast<Uniti::PluginCreator<Uniti::ICorePlugin, JavascriptPlugin, Uniti::Core> *>(creator);
}
}