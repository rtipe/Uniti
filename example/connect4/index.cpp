//
// Created by youba on 26/10/2023.
//

#include <iostream>
#include "Core.hpp"

int main() {
    try {
        Uniti::Core mainInstance(Uniti::Object::openJsonFile("./json/project.json"));

        mainInstance.start();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}