//
// Created by youba on 28/10/2023.
//

#pragma once

#include "IObjectPlugin.hpp"
#include "IPrintable.hpp"

class IPrintablePlugin : public Uniti::IObjectPlugin {
public:
    virtual ~IPrintablePlugin() = default;

    virtual const IPrintable &getPrintable() const = 0;

    virtual IPrintable &getPrintable() = 0;
};
