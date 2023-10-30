export class Text {
    setString(text) {
        this._events.push({
            "name": "setString",
            "data": text
        })
    }

    _text = "";

    getString() {
        return this._text;
    }

    setFont(path) {
        this._events.push({
            "name": "setFont",
            "data": path
        })
    }

    setCharacterSize(size) {
        this._events.push({
            "name": "setCharacterSize",
            "data": size
        })
    }

    setStyle(style) {
        this._events.push({
            "name": "setStyle",
            "data": style
        })
    }

    setColor(color) {
        this._events.push({
            "name": "setColor",
            "data": color
        })
    }

    changeZIndex(zIndex) {
        this._events.push({
            "name": "changeZIndex",
            "data": zIndex
        })
    }

    _zIndex = 0;

    getZIndex() {
        return this._zIndex;
    }

    _events = [];
}

export class Sprite {
    setTexture(information) {
        this._events.push({
            "name": "setTexture",
            "data": information
        })
    }

    changeTextureRect(box) {
        this._events.push({
            "name": "changeTextureRect",
            "data": box
        })
    }

    changeColor(color) {
        this._events.push({
            "name": "changeColor",
            "data": color
        })
    }

    changeZIndex(zIndex) {
        this._events.push({
            "name": "changeZIndex",
            "data": zIndex
        })
    }

    _zIndex = 0;

    getZIndex() {
        return this._zIndex;
    }

    _events = [];
}