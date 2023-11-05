//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Clock.hpp"
#include "Event.hpp"

namespace Uniti {
    class IPlugin {
    public:
        /** @brief Destructor for IPlugin.
            Destroys an instance of the IPlugin class.
        */
        virtual ~IPlugin() = default;
        
        /** @brief Initialization function to perform actions when the plugin awakens.
            @param const Json::Value &value: JSON configuration data.
        */
        virtual void awake(const Json::Value &value) = 0;

        /** @brief Function called before the plugin's main start function.
            Use this for pre-start actions.
        */
        virtual void preStart() = 0;

        /** @brief Main start function for the plugin.
            Implement plugin-specific startup logic here.
        */
        virtual void start() = 0;

        /** @brief Function called after the plugin's main start function.
            Use this for post-start actions.
        */
        virtual void postStart() = 0;

        /** @brief Function called before the plugin's main update loop.
            Use this for pre-update actions.
        */
        virtual void preUpdate() = 0;

        /** @brief Main update function for the plugin.
            Implement the plugin's main update logic here.
        */
        virtual void update() = 0;

        /** @brief Function called after the plugin's main update loop.
            Use this for post-update actions.
        */
        virtual void postUpdate() = 0;

        /** @brief Function called before the plugin's main end function.
            Use this for pre-end actions.
        */
        virtual void preEnd() = 0;

        /** @brief Main end function for the plugin.
            Implement plugin-specific cleanup or shutdown logic here.
        */
        virtual void end() = 0;

        /** @brief Function called after the plugin's main end function.
            Use this for post-end actions.
        */
        virtual void postEnd() = 0;

        /** @brief Get the constant reference to the plugin's clock.
            @return const Clock &: Constant reference to the plugin's clock.
        */
        virtual const Clock &getClock() const = 0;

        /** @brief Get a reference to the plugin's clock.
            @return Clock &: Reference to the plugin's clock.
        */
        virtual Clock &getClock() = 0;

        /** @brief Get the constant reference to the plugin's event manager.
            @return const Event &: Constant reference to the plugin's event manager.
        */
        virtual const Event &getEvent() const = 0;

        /** @brief Get a reference to the plugin's event manager.
            @return Event &: Reference to the plugin's event manager.
        */
        virtual Event &getEvent() = 0;
    };
}
