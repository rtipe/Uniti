//
// Created by youba on 28/10/2023.
//

#pragma once

#include "ICorePlugin.hpp"
#include "IWindow.hpp"

/** @brief Interface for rendering plugin management.
*/
class IRenderPlugin : public Uniti::ICorePlugin {
public:
    /** @brief Virtual destructor for the IRenderPlugin interface.
    */
    virtual ~IRenderPlugin() = default;

    /** @brief Get a constant reference to the Window associated with the rendering plugin.
        @return const IWindow&: Constant reference to the associated Window.
    */
    virtual const IWindow &getWindow() const = 0;

    /** @brief Get a reference to the Window associated with the rendering plugin.
        @return IWindow&: Reference to the associated Window.
    */
    virtual IWindow &getWindow() = 0;
};
