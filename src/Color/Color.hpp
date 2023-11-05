//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Logger.hpp"

namespace Uniti {
    class Color {
    public:
        /**
         * @brief Construct a new Color object
         *
         */
        Color();
        /**
         * @brief Construct a new Color object
         *
         * @param value
         */
        Color(const Json::Value &value);
        /**
         * @brief Construct a new Color object
         *
         * @param color
         */
        Color(const Color &color);
        /**
         * @brief Construct a new Color object
         *
         * @param r
         * @param g
         * @param b
         */
        Color(int r, int g, int b);
        /**
         * @brief Construct a new Color object
         *
         * @param r
         * @param g
         * @param b
         * @param a
         */
        Color(int r, int g, int b, int a);
        /**
         * @brief Destroy the Color object
         *
         */
        int getR() const;
        /**
         * @brief Get the R object
         *
         * @return int
         */
        int &getR();
        /**
         * @brief Get the G object
         *
         * @return int
         */
        int getG() const;
        /**
         * @brief Get the G object
         *
         * @return int
         */
        int &getG();
        /**
         * @brief Get the B object
         *
         * @return int
         */
        int getB() const;
        /**
         * @brief Get the B object
         *
         * @return int
         */
        int &getB();
        /**
         * @brief Get the A object
         *
         * @return int
         */
        int getA() const;
        /**
         * @brief Get the A object
         *
         * @return int
         */
        int &getA();
        /**
         * @brief Set the R object
         *
         * @param value
         */
        void setR(int value);
        /**
         * @brief Set the G object
         *
         * @param value
         */
        void setG(int value);
        /**
         * @brief Set the B object
         *
         * @param value
         */
        void setB(int value);
        /**
         * @brief Set the A object
         *
         * @param value
         */
        void setA(int value);
        /**
         * @brief Set the object
         *
         * @param r
         * @param g
         * @param b
         */
        void set(int r, int g, int b);
        /**
         * @brief Set the object
         *
         * @param r
         * @param g
         * @param b
         * @param a
         */
        void set(int r, int g, int b, int a);
    private:
        int _r;
        int _g;
        int _b;
        int _a;
    };
}

std::ostream &operator<<(std::ostream &os, const Uniti::Color &color);
Uniti::Logger &operator<<(Uniti::Logger &os, const Uniti::Color &color);
