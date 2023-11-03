export class Printable {
    constructor(object) {
        this.gameObject = object;
    }

    createJson() {
        let events = this._events;
        this._events = [];
        return {
            events: events
        }
    }
    setString(text) {
        this.gameObject.emitEvent("setString", text)
    }

    setTexture(information) {
        this.gameObject.emitEvent("setTexture", information)
    }

    changeTextureRect(box) {
        this.gameObject.emitEvent("changeTextureRect", box)
    }
    setFont(path) {
        this.gameObject.emitEvent("setFont", path)
    }

    setCharacterSize(size) {
        this.gameObject.emitEvent("setCharacterSize", size)
    }

    setStyle(style) {
        this.gameObject.emitEvent("setStyle", style)
    }

    setColor(color) {
        this.gameObject.emitEvent("setColor", color)
    }

    changeZIndex(zIndex) {
        this.gameObject.emitEvent("changeZIndex", zIndex)
    }

    _events = [];
}
