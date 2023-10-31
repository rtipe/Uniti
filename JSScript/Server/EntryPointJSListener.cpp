//
// Created by youba on 31/10/2023.
//

#include "JSListener.hpp"
#include "API.hpp"
#include "PluginCreator.hpp"

extern "C" {
void *getCreator(void) {
    return new Uniti::PluginCreator<Uniti::IObjectPlugin, JSListener, Uniti::Object>();
}

void deleteCreator(void *creator) {
    delete static_cast<Uniti::PluginCreator<Uniti::IObjectPlugin, JSListener, Uniti::Object> *>(creator);
}
}