//
// Created by youba on 29/10/2023.
//

#pragma once

#include "Network.hpp"
#include "ICorePlugin.hpp"

/** @brief NetworkPlugin class for managing network-related functionality within the Core.
*/
class NetworkPlugin : public Uniti::ICorePlugin {
public:
    /** @brief Constructor for the NetworkPlugin class.
        @param Uniti::Core &core: Reference to the Core.
    */
    NetworkPlugin(Uniti::Core &core);

    /** @brief Get a reference to the associated Core.
        @return Uniti::Core&: Reference to the Core.
    */
    Uniti::Core &getCore() override;

    /** @brief Called when the NetworkPlugin is awakened and initializes it based on the provided JSON value.
        @param const Json::Value &value: JSON configuration data.
    */
    void awake(const Json::Value &value) override;

    /** @brief Called before the NetworkPlugin's main start() method. Can be used for pre-start setup.
    */
    void preStart() override;

    /** @brief Called when the NetworkPlugin is starting its functionality.
    */
    void start() override;

    /** @brief Called after the NetworkPlugin has started. Can be used for post-start actions.
    */
    void postStart() override;

    /** @brief Called before the update() method. Useful for pre-update preparations.
    */
    void preUpdate() override;

    /** @brief The main update method for the NetworkPlugin. Called to update the NetworkPlugin's behavior.
    */
    void update() override;

    /** @brief Called after the update() method. Can be used for post-update tasks.
    */
    void postUpdate() override;

    /** @brief Called before the NetworkPlugin is ending or being destroyed.
    */
    void preEnd() override;

    /** @brief The method to end the NetworkPlugin's functionality, typically called when it's being removed or deactivated.
    */
    void end() override;

    /** @brief Called after the end() method, used for post-end clean-up.
    */
    void postEnd() override;

    /** @brief Get a constant reference to the Clock associated with the NetworkPlugin.
        @return const Uniti::Clock&: Constant reference to the Clock.
    */
    const Uniti::Clock &getClock() const override;

    /** @brief Get a reference to the Clock associated with the NetworkPlugin.
        @return Uniti::Clock&: Reference to the Clock.
    */
    Uniti::Clock &getClock() override;

    /** @brief Get a constant reference to the Event associated with the NetworkPlugin.
        @return const Uniti::Event&: Constant reference to the Event.
    */
    const Uniti::Event &getEvent() const override;

    /** @brief Get a reference to the Event associated with the NetworkPlugin.
        @return Uniti::Event&: Reference to the Event.
    */
    Uniti::Event &getEvent() override;

    /** @brief Get a reference to the Network instance associated with the NetworkPlugin.
        @return Network&: Reference to the Network instance.
    */
    Network &getNetwork();

private:
    std::unique_ptr<Network> _network;
    Uniti::Core &_core;
    Uniti::Clock _clock;
    Uniti::Event _event;
};
