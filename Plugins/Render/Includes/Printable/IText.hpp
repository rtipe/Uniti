//
// Created by youba on 28/10/2023.
//

#pragma once

#include "IPrintable.hpp"
#include "Color.hpp"

/** @brief Interface for text objects implementing IPrintable functionality.
*/
class IText : public IPrintable {
public:
    /** @brief Enumerates different text styles.
    */
    enum TextStyle {
        BOLD,
        ITALIC,
        REGULAR
    };

    /** @brief Virtual destructor for the IText interface.
    */
    virtual ~IText() = default;

    /** @brief Set the string content of the text.
        @param text: The string to be displayed as text.
    */
    virtual void setString(const std::string &text) = 0;

    /** @brief Set the font for rendering the text using a file path.
        @param path: The path to the font file.
    */
    virtual void setFont(const std::string &path) = 0;

    /** @brief Set the character size for the text.
        @param size: The size of the characters in the text.
    */
    virtual void setCharacterSize(unsigned int size) = 0;

    /** @brief Set the text style (e.g., bold, italic, regular).
        @param style: The style to apply to the text.
    */
    virtual void setStyle(TextStyle style) = 0;

    /** @brief Set the color of the text.
        @param color: The color to apply to the text.
    */
    virtual void setColor(const Uniti::Color &color) = 0;

    /** @brief Get the current string content of the text.
        @return std::string: The string content of the text.
    */
    virtual const std::string getString() const = 0;
};
