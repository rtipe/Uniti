# ScenePlugin

A ScenePlugin is an extension that allows adding functionalities or effects around the scene of an environment.

## Creating a ScenePlugin

To create a ScenePlugin, follow these steps:

1. Create a class that inherits from the `IScenePlugin` interface.

2. Implement the functions from the API defined in `API.hpp`. These functions allow you to interact with the scene and add the functionalities you desire.

3. Use `PluginCreator` to compile your plugin as a dynamic library.

4. Place the generated dynamic library in the folder where you want to store the plugins.

## Plugin Structure

A ScenePlugin should have the following structure:

- `MyScenePlugin/`
  - `src/`
    - `MyScenePlugin.cpp` (Implementation of the MyScenePlugin class)
    - `MyScenePlugin.hpp`
    - `EntryPoint.cpp` (Definition of the API functions)
  - `CMakeLists.txt` (Compilation configuration)

## Link to Plugin.md

For more information about plugins, refer to [plugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Plugin.md).

## Creating an ScenePlugin

To create an ScenePlugin, follow these steps:

1. Create a class that inherits from the `IScenePlugin` interface.

2. Implement the functions defined in `API.hpp` and use `PluginCreator` to compile your plugin as a dynamic library.

3. Place the generated dynamic library in the folder where you want to store the objects.
