//
// Created by youba on 28/10/2023.
//

#pragma once

#include "ICorePlugin.hpp"
#include "IWindow.hpp"

class IRenderPlugin : public Uniti::ICorePlugin {
public:
    virtual ~IRenderPlugin() = default;

    virtual const IWindow &getWindow() const = 0;

    virtual IWindow &getWindow() = 0;
};
