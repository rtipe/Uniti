# JSScript.md

## Explanation of JSScript

JSScript is a CorePlugin that provides the capability to incorporate JavaScript scripts into the game engine. It accepts the following parameters:

- `port`
- `fps`
- `path` (path to the `index.js` file)

This plugin enables the integration of JavaScript scripts within the game engine, allowing for dynamic scripting functionalities.

### Example : Connect4

For example, our [Connect4](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/example/connect4.md) game was made with our JSScript.

## JSListener ObjectPlugin

JSListener is an ObjectPlugin that does not take any parameters. It serves the purpose of capturing and returning all events received by the object it is linked to.

For more detailed information about plugins, please refer to [plugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Plugin.md).
