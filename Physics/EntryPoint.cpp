//
// Created by youba on 29/10/2023.
//

#include "API.hpp"
#include "PluginCreator.hpp"
#include "IObjectPlugin.hpp"
#include "PhysicsPlugin.hpp"

extern "C" {
void *getCreator(void) {
    return new Uniti::PluginCreator<Uniti::IObjectPlugin, PhysicsPlugin, Uniti::Object>();
}

void deleteCreator(void *creator) {
    delete static_cast<Uniti::PluginCreator<Uniti::IObjectPlugin, PhysicsPlugin, Uniti::Object> *>(creator);
}
}