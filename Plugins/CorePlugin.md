# CorePlugin

A CorePlugin is an extension that provides additional functionality around the game scene and is connected to it.

## Usage

### Example : [Network](https://github.com/rtipe/Uniti/blob/36b2abf216c797e43e6ecb4b544f549e35ad6ad2/Plugins/Network/Network.md)

A CorePlugin can be used to add post-processing effects to the scene, such as blur or color filters. This enhances the visual quality of the scene.

### Example 2: Managing Dynamic Lighting

A CorePlugin can also be used to manage dynamic lighting in the scene by adjusting the intensities or colors of lights based on certain events.

## Creating a CorePlugin

To create a CorePlugin, follow these steps:

1. Create a class that inherits from the `ICorePlugin` interface.

2. Implement the functions from the API defined in `API.hpp`. These functions allow you to interact with the scene and add the desired features.

3. Use `PluginCreator` to compile your plugin as a dynamic library.

4. Place the generated dynamic library in the folder where you want to store the plugins.

## Plugin Structure

A CorePlugin must have the following structure:

- `MyCorePlugin/`
  - `src/`
    - `MyCorePlugin.cpp` (Implementation of the MyCorePlugin class)
    - `MyCorePlugin.hpp`
    - `API.hpp` (Definition of the API functions)
  - `CMakeLists.txt` (Compilation configuration)

## Link to Plugin.md

For more information about plugins, refer to [plugin.md](https://github.com/rtipe/Uniti/blob/36b2abf216c797e43e6ecb4b544f549e35ad6ad2/Plugins/Plugin.md).

## Creating an CorePlugin

To create an CorePlugin, follow these steps:

1. Create a class that inherits from the `ICorePlugin` interface.

2. Implement the functions from the API defined in `API.hpp` and use `PluginCreator` to compile your plugin as a dynamic library.

3. Place the generated dynamic library in the folder where you want to store the objects.
