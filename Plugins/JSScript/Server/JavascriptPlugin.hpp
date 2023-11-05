//
// Created by youba on 30/10/2023.
//

#pragma once

#include <boost/lockfree/queue.hpp>
#include <thread>
#include "ICorePlugin.hpp"
#include "sio_client.h"
#include "Scene.hpp"

/** @brief JavascriptPlugin class that implements the ICorePlugin interface for JavaScript integration.
*/
class JavascriptPlugin : public Uniti::ICorePlugin {
public:
    /** @brief Constructor for the JavascriptPlugin class.
        @param Uniti::Core &core: Reference to the Core instance.
    */
    JavascriptPlugin(Uniti::Core &core);

    /** @brief Get the associated Core instance.
        @return Uniti::Core&: Reference to the Core instance.
    */
    Uniti::Core &getCore() override;

    /** @brief Called when the plugin is awakened and initializes it based on the provided JSON value.
        @param const Json::Value &value: JSON configuration for the plugin.
    */
    void awake(const Json::Value &value) override;

    /** @brief Called before the plugin's main start() method. Can be used for pre-start setup.
    */
    void preStart() override;

    /** @brief Called when the plugin is starting its functionality.
    */
    void start() override;

    /** @brief Called after the plugin has started. Can be used for post-start actions.
    */
    void postStart() override;

    /** @brief Called before the update() method. Useful for pre-update preparations.
    */
    void preUpdate() override;

    /** @brief The main update method for the plugin. Called to update the plugin's behavior.
    */
    void update() override;

    /** @brief Called after the update() method. Can be used for post-update tasks.
    */
    void postUpdate() override;

    /** @brief Called before the plugin is ending or being destroyed.
    */
    void preEnd() override;

    /** @brief The method to end the plugin's functionality, typically called when it's being removed or deactivated.
    */
    void end() override;

    /** @brief Called after the end() method, used for post-end clean-up.
    */
    void postEnd() override;

    /** @brief Get associated Clock (constant reference).
        @return const Uniti::Clock&: Constant reference to the associated Clock.
    */
    const Uniti::Clock &getClock() const override;

    /** @brief Get associated Clock (reference).
        @return Uniti::Clock&: Reference to the associated Clock.
    */
    Uniti::Clock &getClock() override;

    /** @brief Get associated Event (constant reference).
        @return const Uniti::Event&: Constant reference to the associated Event.
    */
    const Uniti::Event &getEvent() const override;

    /** @brief Get associated Event (reference).
        @return Uniti::Event&: Reference to the associated Event.
    */
    Uniti::Event &getEvent() override;

    /** @brief Emit a JavaScript event with a name and JSON value.
        @param const std::string &name: Name of the event.
        @param const Json::Value &value: JSON value to send with the event.
    */
    void emitJSEvent(const std::string &name, const Json::Value &value);

private:
    /** @brief Convert a Scene instance to a JSON representation.
        @param Uniti::Scene &scene: Reference to the Scene to be converted.
        @return Json::Value: JSON representation of the Scene.
    */
    Json::Value getSceneJson(Uniti::Scene &scene);

    /** @brief Convert an Object instance to a JSON representation.
        @param Uniti::Object &object: Reference to the Object to be converted.
        @return Json::Value: JSON representation of the Object.
    */
    Json::Value getObjectJson(Uniti::Object &object);

    /** @brief Retrieve a JSON representation of scenes to be unloaded.
        @return Json::Value: JSON representation of scenes to be unloaded.
    */
    Json::Value getUnloadScenes();

    /** @brief Apply core-related events from JSON data.
        @param const Json::Value &events: JSON data containing core-related events.
    */
    void applyCoreEvent(const Json::Value &events);

    /** @brief Apply scene manager-related events from JSON data.
        @param const Json::Value &events: JSON data containing scene manager-related events.
    */
    void applySceneManagerEvent(const Json::Value &events);

    /** @brief Apply scene-related events from JSON data for a specific scene.
        @param Uniti::Scene &scene: Reference to the Scene to apply events to.
        @param const Json::Value &events: JSON data containing scene-related events.
    */
    void applySceneEvent(Uniti::Scene &scene, const Json::Value &events);

    /** @brief Apply object-related events from JSON data for a specific object.
        @param Uniti::Object &object: Reference to the Object to apply events to.
        @param const Json::Value &events: JSON data containing object-related events.
    */
    void applyObjectEvent(Uniti::Object &object, const Json::Value &events);

    /** @brief Apply network-related events from JSON data.
        @param const Json::Value &events: JSON data containing network-related events.
    */
    void applyNetworkEvent(const Json::Value &events);

    std::string _code;
    std::string _path;
    std::thread _thread;
    boost::lockfree::queue<std::string *> _queueUpdate;
    boost::lockfree::queue<std::string *> _queueLog;
    std::map<std::string, std::vector<Json::Value>> _events;
    Uniti::Core &_core;
    Uniti::Event _event;
    Uniti::Clock _clock;
    sio::client client;
    int _port;
    float _updateJS;
};
