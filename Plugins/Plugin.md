# plugin.md

## Introduction to Plugins

A plugin is a dynamic library that is dynamically loaded at the moment the engine is launched. It extends the functionality of the engine by providing additional features and capabilities.

### List of Created Plugins:

- [Button.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Button/Button.md)
- [TextInput.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/TextInput/TextInput.md)
- [ScenePlugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/ScenePlugin.md)
- [JSScript.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/JSScript/JSScript.md)
- [NetworkPlugin.md](https://github.com/rtipe/Uniti/tree/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Network)
- [Physics.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Physics/Physics.md)
- [Render.md](https://github.com/rtipe/Uniti/tree/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Render)
- [ObjectPlugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/ObjectPlugin.md)
- [CorePlugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/CorePlugin.md)

## Structure of a Plugin

A plugin follows a specific lifecycle sequence, with methods executed in a defined order:

### Startup:

- `preStart` for corePlugins
- `start` for corePlugins
- `postStart` for corePlugins
- `preStart` for scenePlugins
- `start` for scenePlugins
- `postStart` for scenePlugins
- `preStart` for objectPlugins
- `start` for objectPlugins
- `postStart` for objectPlugins

### Engine Loop:

- `preUpdate` for corePlugins
- `preUpdate` for scenePlugins
- `preUpdate` for objectPlugins
- `update` for objectPlugins
- `update` for scenePlugins
- `update` for corePlugins
- `postUpdate` for objectPlugins
- `postUpdate` for scenePlugins
- `postUpdate` for corePlugins

### Shutdown:

- `preEnd` for corePlugins
- `preEnd` for scenePlugins
- `preEnd` for objectPlugins
- `end` for objectPlugins
- `end` for scenePlugins
- `end` for corePlugins
- `postEnd` for objectPlugins
- `postEnd` for scenePlugins
- `postEnd` for corePlugins

For detailed explanations of each type of plugin (CorePlugin, ObjectPlugin, etc.), refer to their respective documentation.

- [Button.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Button/Button.md)
- [TextInput.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/TextInput/TextInput.md)
- [ScenePlugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/ScenePlugin.md)
- [JSScript.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/JSScript/JSScript.md)
- [NetworkPlugin.md](https://github.com/rtipe/Uniti/tree/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Network)
- [Physics.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Physics/Physics.md)
- [Render.md](https://github.com/rtipe/Uniti/tree/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Render)
- [ObjectPlugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/ObjectPlugin.md)
- [CorePlugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/CorePlugin.md)
