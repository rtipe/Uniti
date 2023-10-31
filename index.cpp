//
// Created by youba on 26/10/2023.
//

#include <iostream>
#include "Core.hpp"
#include "PluginLoader.hpp"

int main() {
    try {
        Uniti::PluginLoader loader;
        loader.loadCorePlugin("../../CorePlugin");
        loader.loadObjectPlugin("../../ObjectPlugin");
        Uniti::Core mainInstance(Uniti::Object::openJsonFile("../../test.json"));

        mainInstance.start();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}