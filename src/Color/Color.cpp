//
// Created by youba on 25/10/2023.
//

#include "Color.hpp"

namespace Uniti {
    Color::Color(): _r(0), _g(0), _b(0), _a(0) {};

    Color::Color(const Json::Value &value) {
        this->_r = value.get("r", 0).asInt();
        this->_g = value.get("g", 0).asInt();
        this->_b = value.get("b", 0).asInt();
        this->_a = value.get("a", 0).asInt();
    }

    Color::Color(const Color &color) {
        this->_r = color._r;
        this->_g = color._g;
        this->_b = color._b;
        this->_a = color._a;
    }

    Color::Color(int r, int g, int b): _r(r), _g(g), _b(b), _a(0) {};

    Color::Color(int r, int g, int b, int a): _r(r), _g(g), _b(b), _a(a) {};

    int Color::getR() const {
        return (this->_r);
    }

    int &Color::getR() {
        return (this->_r);
    }

    int Color::getG() const {
        return (this->_g);
    }

    int &Color::getG() {
        return (this->_g);
    }

    int Color::getB() const {
        return (this->_b);
    }

    int &Color::getB() {
        return (this->_b);
    }

    int Color::getA() const {
        return (this->_a);
    }

    int &Color::getA() {
        return (this->_a);
    }

    void Color::setR(int value) {
        this->_r = value;
    }

    void Color::setG(int value) {
        this->_g = value;
    }

    void Color::setB(int value) {
        this->_b = value;
    }

    void Color::setA(int value) {
        this->_a = value;
    }

    void Color::set(int r, int g, int b) {
        this->_r = r;
        this->_g = g;
        this->_b = b;
    }

    void Color::set(int r, int g, int b, int a) {
        this->_r = r;
        this->_g = g;
        this->_b = b;
        this->_a = a;
    }
} // Uniti

std::ostream &operator<<(std::ostream &os, const Uniti::Color &color) {
    os << "Red = " << color.getR() << " Green = " << color.getG() << " Blue = " << color.getB() << " Alpha = " << color.getA();
    return os;
}

/* TODO a voir ?? proto pas bon et pas sûr
Uniti::Logger &operator<<(Uniti::Logger &os, const Uniti::Color &color) {
    os << "Red = " << color.getR() << " Green = " << color.getG() << " Blue = " << color.getB() << " Alpha = " << color.getA();
    return os;
}
*/
