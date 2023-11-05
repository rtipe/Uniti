//
// Created by youba on 28/10/2023.
//

#pragma once

#include "IObjectPlugin.hpp"
#include "IPrintable.hpp"

/** @brief Interface for plugins that provide printable objects.
*/
class IPrintablePlugin : public Uniti::IObjectPlugin {
public:
    /** @brief Virtual destructor for the IPrintablePlugin interface.
    */
    virtual ~IPrintablePlugin() = default;

    /** @brief Get a constant reference to the printable object provided by the plugin.
        @return const IPrintable&: A constant reference to the printable object.
    */
    virtual const IPrintable &getPrintable() const = 0;

    /** @brief Get a reference to the printable object provided by the plugin.
        @return IPrintable&: A reference to the printable object.
    */
    virtual IPrintable &getPrintable() = 0;
};
