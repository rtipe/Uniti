# Physics.md

## Explanation of Physics.md

Physics.md is an ObjectPlugin that governs the physics behavior of objects within the environment. It accepts the following parameters:

- `isOverlap`
- `boxes` (an array of boxes containing `x`, `y`, `width`, and `height` properties)

### Received Events

- `moveTo`: Takes a JSON parameter (`position`[object with `x`[float], `y`[float]], `speed`[float]) to move the object to a specific point.
- `moveForward`: Takes a JSON parameter (`deltaTime`[float](optional), `speed`[float]) to move the object forward.
- `moveBackward`: Takes a JSON parameter (`deltaTime`[float](optional), `speed`[float]) to move the object backward.
- `moveLeft`: Takes a JSON parameter (`deltaTime`[float](optional), `speed`[float]) to move the object left.
- `moveRight`: Takes a JSON parameter (`deltaTime`[float](optional), `speed`[float]) to move the object right.
- `move`: Takes a JSON parameter (`position`[object with `x`[float], `y`[float]], `deltaTime`[float](optional), `speed`[float]) to move the object from a specified position.
- `cancelMovement`: Takes no parameter and cancels any ongoing movement (for `moveTo`).
- `setSpeed`: Takes a JSON parameter (`float`) to change the speed of the object (for `moveTo`).

### Emitted Events

- `overlapped`: Takes a JSON parameter (`string` -> object name) when another object passes through this object.
- `collided`: Takes a JSON parameter (`string` -> object name) when another object collides with this object.

The plugin manages the physics aspects of the game, including collision and movement.

For further information about plugins, please refer to [plugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Plugin.md).
