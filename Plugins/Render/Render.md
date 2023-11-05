# Render.md

## Explanation of RenderPlugin

RenderPlugin is a CorePlugin responsible for handling rendering logic, including object creation and depth management. It accepts the following parameters:

- `width`
- `height`
- `icon` (path to the image)
- `title`

### Emitted Events

- `MOUSE_XX_RELEASED`: Sends the mouse position upon release.
- `MOUSE_XX_PRESSED`: Sends the mouse position upon press.
- `KEY_XX_RELEASED`: Does not send any information.
- `KEY_XX_PRESSED`: Does not send any information.

RenderPlugin manages the entire rendering logic, from creating objects to handling depth.

## Explanation of PrintablePlugin

PrintablePlugin is an ObjectPlugin responsible for defining printable objects within the environment. It accepts the following parameters:

- `type` (sprite or text)
- `zIndex` (float, representing object depth)

### If it's a sprite:

- `texture` -> (path, smooth, repeat)
- `textureRect` -> (x, y, width, height)

### If it's text:

- `font` -> (path)
- `text` -> the displayed text
- `color` -> (r, g, b, a)
- `style` -> (regular, bold, italic)
- `size`

### Received Events

- `setString`: Receives a JSON parameter (`string`) to change the displayed text.
- `setFont`: Receives a JSON parameter (`string` -> path) to change the font path.
- `setCharacterSize`: Receives a JSON parameter (`int`).
- `setStyle`: Receives a JSON parameter (`string`).
- `setColor`: Receives a JSON parameter (`string`).
- `setTexture`: Receives a JSON parameter (`path`[string], `smooth`[bool], `repeat`[bool]).
- `changeZIndex`: Receives a JSON parameter (`float`).

PrintablePlugin instructs RenderPlugin to display the specified object with the provided parameters.

For more detailed information about plugins, please refer to [plugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Plugin.md).
