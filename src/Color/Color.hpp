//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Logger.hpp"

namespace Uniti {
    class Color {
    public:
        /** @brief Default constructor of the Color class.
        */
        Color();

        /** @brief Constructor of the Color class taking a JSON object as an argument.
            @param const Json::Value &value : JSON object for initialization.
        */
        Color(const Json::Value &value);

        /** @brief Copy constructor of the Color class.
            @param const Color &color : Color to copy.
        */
        Color(const Color &color);

        /** @brief Constructor of the Color class taking RGB components.
            @param int r : Red component.
            @param int g : Green component.
            @param int b : Blue component.
        */
        Color(int r, int g, int b);

        /** @brief Constructor of the Color class taking RGBA components.
            @param int r : Red component.
            @param int g : Green component.
            @param int b : Blue component.
            @param int a : Alpha component (transparency).
        */
        Color(int r, int g, int b, int a);

        /** @brief Returns the red component of the color (read-only).
            @return int : Red component.
        */
        int getR() const;

        /** @brief Returns the red component of the color (read/write).
            @return int & : Red component.
        */
        int &getR();

        /** @brief Returns the green component of the color (read-only).
            @return int : Green component.
        */
        int getG() const;

        /** @brief Returns the green component of the color (read/write).
            @return int & : Green component.
        */
        int &getG();

        /** @brief Returns the blue component of the color (read-only).
            @return int : Blue component.
        */
        int getB() const;

        /** @brief Returns the blue component of the color (read/write).
            @return int & : Blue component.
        */
        int &getB();

        /** @brief Returns the alpha (transparency) component of the color (read-only).
            @return int : Alpha component.
        */
        int getA() const;

        /** @brief Returns the alpha (transparency) component of the color (read/write).
            @return int & : Alpha component.
        */
        int &getA();

        /** @brief Sets the red component of the color.
            @param int value : New value of the red component.
        */
        void setR(int value);

        /** @brief Sets the green component of the color.
            @param int value : New value of the green component.
        */
        void setG(int value);

        /** @brief Sets the blue component of the color.
            @param int value : New value of the blue component.
        */
        void setB(int value);

        /** @brief Sets the alpha (transparency) component of the color.
            @param int value : New value of the alpha component.
        */
        void setA(int value);

        /** @brief Sets the RGB components of the color.
            @param int r : Red component.
            @param int g : Green component.
            @param int b : Blue component.
        */
        void set(int r, int g, int b);

        /** @brief Sets the RGBA components of the color.
            @param int r : Red component.
            @param int g : Green component.
            @param int b : Blue component.
            @param int a : Alpha component (transparency).
        */
        void set(int r, int g, b, int a);

    private:
        int _r;
        int _g;
        int _b;
        int _a;
    };
}

/** @brief Overload of the output operator to display the color in a standard output stream.
    @param std::ostream& os : Output stream.
    @param const Uniti::Color &color : Color to display.
    @return std::ostream& : Reference to the output stream.
*/
std::ostream &operator<<(std::ostream &os, const Uniti::Color &color);

/** @brief Overload of the output operator to display the color in a specific logging object (Logger).
    @param Uniti::Logger& os : Logging object.
    @param const Uniti::Color &color : Color to display.
    @return Uniti::Logger& : Reference to the logging object.
*/
Uniti::Logger &operator<<(Uniti::Logger &os, const Uniti::Color &color);
