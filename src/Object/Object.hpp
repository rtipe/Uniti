//
// Created by youba on 25/10/2023.
//

#pragma once

#include "json/value.h"
#include "Transform.hpp"
#include "IObjectPlugin.hpp"
#include "ObjectPluginManager.hpp"
#include <optional>

namespace Uniti {
    class Object;
    class Scene;

    class Core;
    class ObjectManager {
    public:
        /** @brief Constructor for ObjectManager, initializes it with a JSON value and a Scene.
         *  @param const Json::Value &value: JSON value for initialization.
         *  @param Scene &scene: Reference to the Scene to associate with.
         */
        ObjectManager(const Json::Value &value, Scene &scene);

        /** @brief Constructor for ObjectManager, initializes it with a vector of unique pointers to objects and a Core.
         *  @param const std::vector<std::unique_ptr<Object>> &objects: Vector of unique pointers to objects.
         *  @param Core &core: Reference to the Core to associate with.
         */
        ObjectManager(const std::vector<std::unique_ptr<Object>> &objects, Core &core);

        /** @brief Template function to add objects of various types to the manager.
         *  @param Args &&... __args: Arguments to create the Object.
         */
        template<typename... Args>
        void add(Args &&... __args) {
            this->add(std::make_unique<Object>(__args...));
        }

        /** @brief Adds a unique pointer to an Object to the manager.
         *  @param std::unique_ptr<Object> object: Unique pointer to the Object to add.
         */
        void add(std::unique_ptr<Object> object);

        /** @brief Removes an Object from the manager by its name.
         *  @param const std::string &name: Name of the Object to remove.
         */
        void remove(const std::string &name);

        /** @brief Gets a constant reference to the vector of unique pointers to objects.
         *  @return const std::vector<std::unique_ptr<Object>> &: Constant reference to the vector of objects.
         */
        const std::vector<std::unique_ptr<Object>> &getObjects() const;

        /** @brief Gets a reference to the vector of unique pointers to objects.
         *  @return std::vector<std::unique_ptr<Object>> &: Reference to the vector of objects.
         */
        std::vector<std::unique_ptr<Object>> &getObjects();

        /** @brief Updates all objects in the manager.
         */
        void update();

        /** @brief Ends the object manager, removing all objects.
         */
        void end();

        /** @brief Emits an event with a given name and JSON value.
         *  @param const std::string &name: Name of the event.
         *  @param const Json::Value &value: JSON value associated with the event.
         */
        void emitEvent(const std::string &name, const Json::Value &value);

        /** @brief Overload of the [] operator to access an Object by its name (constant version).
         *  @param const std::string &name: Name of the Object to access.
         *  @return const Object &: Constant reference to the accessed Object.
         */
        const Object &operator[](const std::string &name) const;

        /** @brief Overload of the [] operator to access an Object by its name.
         *  @param const std::string &name: Name of the Object to access.
         *  @return Object &: Reference to the accessed Object.
         */
        Object &operator[](const std::string &name);

        /** @brief Gets a constant reference to the associated Core.
         *  @return const Core &: Constant reference to the Core associated with the ObjectManager.
         */
        const Core &getCore() const;


        Core &getCore();
    private:
        Core &_core;
        std::vector<std::unique_ptr<Object>> _objects;
        std::vector<std::unique_ptr<Object>> _inObjects;
        std::vector<std::string> _outObjects;
    };
    class Object {
    public:
        /** @brief Constructor for Object, initializes it with a name and a Scene.
         *  @param const std::string &name: Name of the Object.
         *  @param Scene &scene: Reference to the Scene to associate with.
         */
        Object(const std::string &name, Scene &scene);
    
        /** @brief Copy constructor for Object, creates a copy of an existing Object.
         *  @param Object &object: Object to copy.
         */
        Object(Object &object);
    
        /** @brief Constructor for Object, initializes it with a JSON value and a Scene.
         *  @param const Json::Value &value: JSON value for initialization.
         *  @param Scene &scene: Reference to the Scene to associate with.
         */
        Object(const Json::Value &value, Scene &scene);
    
        /** @brief Constructor for Object, initializes it with a Scene and a filename.
         *  @param Scene &scene: Reference to the Scene to associate with.
         *  @param const std::string &fileName: Filename to load Object data from.
         */
        Object(Scene &scene, const std::string &fileName);
    
        /** @brief Updates the Object.
         */
        void update();
    
        /** @brief Ends the Object, removing it from the scene.
         */
        void end();
    
        /** @brief Sets the name of the Object.
         *  @param const std::string &name: New name for the Object.
         */
        void setName(const std::string &name);
    
        /** @brief Gets a constant reference to the name of the Object.
         *  @return const std::string &: Constant reference to the name of the Object.
         */
        const std::string &getName() const;
    
        /** @brief Gets a reference to the name of the Object.
         *  @return std::string &: Reference to the name of the Object.
         */
        std::string &getName();
    
        /** @brief Sets the enable state of the Object.
         *  @param bool value: New enable state (true or false).
         */
        void setEnable(bool value);
    
        /** @brief Checks if the Object is enabled.
         *  @return bool: True if the Object is enabled, false otherwise.
         */
        bool isEnabled() const;
    
        /** @brief Gets a constant reference to the Transform component of the Object.
         *  @return const Transform &: Constant reference to the Transform component.
         */
        const Transform &getTransform() const;
    
        /** @brief Gets a reference to the Transform component of the Object.
         *  @return Transform &: Reference to the Transform component.
         */
        Transform &getTransform();
    
        /** @brief Gets a constant reference to the children of the Object.
         *  @return const ObjectManager &: Constant reference to the children of the Object.
         */
        const ObjectManager &getChildren() const;
    
        /** @brief Gets a reference to the children of the Object.
         *  @return ObjectManager &: Reference to the children of the Object.
         */
        ObjectManager &getChildren();
    
        /** @brief Gets a constant reference to the Scene associated with the Object.
         *  @return const Scene &: Constant reference to the associated Scene.
         */
        const Scene &getScene() const;
    
        /** @brief Gets a reference to the Scene associated with the Object.
         *  @return Scene &: Reference to the associated Scene.
         */
        Scene &getScene();
        template<typename PLUGIN>
        PLUGIN &get(const std::string &name) {
            return dynamic_cast<PLUGIN &>(this->_objectPluginManager.get(name));
        }

        template<typename PLUGIN>
        const PLUGIN &get(const std::string &name) const {
            return dynamic_cast<PLUGIN &>(this->_objectPluginManager.get(name));
        }
        const Object &operator[](const std::string &name) const;
        Object &operator[](const std::string &name);
        void emitEvent(const std::string &name, const Json::Value &value);
        /** @brief Gets a constant reference to the ObjectPluginManager.
         *  @return const ObjectPluginManager &: Constant reference to the ObjectPluginManager.
         */
        const ObjectPluginManager &getPluginManager() const;

        /** @brief Gets a reference to the ObjectPluginManager.
         *  @return ObjectPluginManager &: Reference to the ObjectPluginManager.
         */
        ObjectPluginManager &getPluginManager();

        /** @brief Gets a constant reference to the JSON value.
         *  @return const Json::Value &: Constant reference to the JSON value.
         */
        const Json::Value &getValue() const;

        /** @brief Gets a reference to the JSON value.
         *  @return Json::Value &: Reference to the JSON value.
         */
        Json::Value &getValue();

        /** @brief Finds an Object by name within a Core.
         *  @param const std::string &name: Name to search for.
         *  @param const Core &core: Core to search within.
         *  @param bool recursive: Flag to indicate if the search should be recursive (default: true).
         *  @return std::optional<std::reference_wrapper<Object>>: An optional reference to the found Object.
         */
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const Core &core, bool recursive = true);

        /** @brief Finds an Object by name within a Scene.
         *  @param const std::string &name: Name to search for.
         *  @param const Scene &scene: Scene to search within.
         *  @param bool recursive: Flag to indicate if the search should be recursive (default: true).
         *  @return std::optional<std::reference_wrapper<Object>>: An optional reference to the found Object.
         */
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const Scene &scene, bool recursive = true);

        /** @brief Finds an Object by name within an ObjectManager.
         *  @param const std::string &name: Name to search for.
         *  @param const ObjectManager &objectManager: ObjectManager to search within.
         *  @param bool recursive: Flag to indicate if the search should be recursive (default: true).
         *  @return std::optional<std::reference_wrapper<Object>>: An optional reference to the found Object.
         */
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const ObjectManager &objectManager, bool recursive = true);

        /** @brief Finds an Object by name within another Object.
         *  @param const std::string &name: Name to search for.
         *  @param const Object &object: Object to search within.
         *  @param bool recursive: Flag to indicate if the search should be recursive (default: true).
         *  @return std::optional<std::reference_wrapper<Object>>: An optional reference to the found Object.
         */
        static std::optional<std::reference_wrapper<Object>> find(const std::string &name, const Object &object, bool recursive = true);

        /** @brief Finds an Object based on a custom predicate within a Core.
         *  @param const Core &core: Core to search within.
         *  @param std::function<bool(const Object &object)> function: Custom predicate function.
         *  @param bool recursive: Flag to indicate if the search should be recursive (default: true).
         *  @return std::optional<std::reference_wrapper<Object>>: An optional reference to the found Object.
         */
        static std::optional<std::reference_wrapper<Object>> find_if(const Core &core, std::function<bool(const Object &object)> function, bool recursive = true);

        /** @brief Finds an Object based on a custom predicate within a Scene.
         *  @param const Scene &scene: Scene to search within.
         *  @param std::function<bool(const Object &object)> function: Custom predicate function.
         *  @param bool recursive: Flag to indicate if the search should be recursive (default: true).
         *  @return std::optional<std::reference_wrapper<Object>>: An optional reference to the found Object.
         */
        static std::optional<std::reference_wrapper<Object>> find_if(const Scene &scene, std::function<bool(const Object &object)> function, bool recursive = true);

        /** @brief Finds an Object based on a custom predicate within an ObjectManager.
         *  @param const ObjectManager &objectManager: ObjectManager to search within.
         *  @param std::function<bool(const Object &object)> function: Custom predicate function.
         *  @param bool recursive: Flag to indicate if the search should be recursive (default: true).
         *  @return std::optional<std::reference_wrapper<Object>>: An optional reference to the found Object.
         */
        static std::optional<std::reference_wrapper<Object>> find_if(const ObjectManager &objectManager, std::function<bool(const Object &object)> function, bool recursive = true);

        /** @brief Finds an Object based on a custom predicate within another Object.
         *  @param const Object &object: Object to search within.
         *  @param std::function<bool(const Object &object)> function: Custom predicate function.
         *  @param bool recursive: Flag to indicate if the search should be recursive (default: true).
         *  @return std::optional<std::reference_wrapper<Object>>: An optional reference to the found Object.
         */
        static std::optional<std::reference_wrapper<Object>> find_if(const Object &object, std::function<bool(const Object &object)> function, bool recursive = true);

        /** @brief Opens and reads a JSON file, returning the JSON data.
         *  @param const std::string &fileName: The filename to open.
         *  @return Json::Value: The JSON data from the file.
         */
        static Json::Value openJsonFile(const std::string &fileName);

        /** @brief Gets a constant reference to the Core associated with the Object.
         *  @return const Core &: Constant reference to the associated Core.
         */
        const Core &getCore() const;

        /** @brief Gets a reference to the Core associated with the Object.
         *  @return Core &: Reference to the associated Core.
         */
        Core &getCore();

    private:
        Core &_core;
        Json::Value _value;
        Scene &_scene;
        ObjectManager _objectManager;
        std::string _name;
        ObjectPluginManager _objectPluginManager;
        Transform _transform;
        bool _isEnabled = true;
    };
}
