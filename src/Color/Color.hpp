//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Logger.hpp"

namespace Uniti {
    class Color {
    public:
        Color();
        Color(const Json::Value &value);
        Color(const Color &color);
        Color(int r, int g, int b);
        Color(int r, int g, int b, int a);
        int getR() const;
        int &getR();
        int getG() const;
        int &getG();
        int getB() const;
        int &getB();
        int getA() const;
        int &getA();
        void setR(int value);
        void setG(int value);
        void setB(int value);
        void setA(int value);
        void set(int r, int g, int b);
        void set(int r, int g, int b, int a);
    };
}

std::ostream &operator<<(std::ostream& os, const Uniti::Color &color);
Uniti::Logger &operator<<(Uniti::Logger &os, const Uniti::Color &color);
