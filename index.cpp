//
// Created by youba on 26/10/2023.
//

#include <iostream>
#include "Core.hpp"
#include "PluginLoader.hpp"

int main() {
    try {
        Uniti::Core mainInstance(Uniti::Object::openJsonFile("../../test.json"));
        Uniti::PluginLoader loader;


    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}