# ObjectPlugin

An ObjectPlugin is an extension that provides additional functionality around a game object and is connected to it, similar to a Unity script.

## Usage

### Example 1: Adding Custom Behavior to an Object

An ObjectPlugin can be used to add custom behavior to a specific object in the scene. For example, it can be used to implement unique movement patterns for enemies or define special interactions for collectible items.

### Example 2: Handling Input for a Specific Object

You can use an ObjectPlugin to handle input events specifically for a particular object. This allows for object-specific interactions with the user.

## Creating an ObjectPlugin

To create an ObjectPlugin, follow these steps:

1. Create a class that inherits from the `IObjectPlugin` interface.

2. Implement the functions from the API defined in `API.hpp`. These functions allow you to interact with the object and add the desired features.

3. Use `PluginCreator` to compile your plugin as a dynamic library.

4. Place the generated dynamic library in the folder where you want to store the objects.

## Plugin Structure

An ObjectPlugin must have the following structure:

- `MyObjectPlugin/`
  - `src/`
    - `MyObjectPlugin.cpp` (Implementation of the MyObjectPlugin class)
    - `MyObjectPlugin.hpp`
    - `API.hpp` (Definition of the API functions)
  - `CMakeLists.txt` (Compilation configuration)

## Link to Plugin.md

For more information about plugins, refer to [plugin.md](https://github.com/rtipe/Uniti/blob/36b2abf216c797e43e6ecb4b544f549e35ad6ad2/Plugins/Plugin.md).

## Creating a ObjectPlugin

To create a ObjectPlugin, follow these steps:

1. Create a class that inherits from the `IObjectPlugin` interface.

2. Implement the functions from the API defined in `API.hpp` and use `PluginCreator` to compile your plugin as a dynamic library.

3. Place the generated dynamic library in the folder where you want to store the core plugins.
