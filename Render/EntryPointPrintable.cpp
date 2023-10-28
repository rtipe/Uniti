//
// Created by youba on 28/10/2023.
//

#include "API.hpp"
#include "PluginCreator.hpp"
#include "IObjectPlugin.hpp"
#include "PrintablePlugin.hpp"

extern "C" {
void *getCreator(void) {
    return new Uniti::PluginCreator<Uniti::IObjectPlugin, PrintablePlugin, Uniti::Object>();
}

void deleteCreator(void *creator) {
    delete static_cast<Uniti::PluginCreator<Uniti::IObjectPlugin, PrintablePlugin, Uniti::Object> *>(creator);
}
}