export class Scene {
    objects = [];
    name = "";

    addObject(value) {
        this._events.push({
            "name": "addObject",
            "data": value,
        })
    }

    removeObject(name) {
        this._events.push({
            "name": "removeObject",
            "data": name,
        })
    }

    emitEvent(name, value) {
        this._events.push({
            "name": "emitEvent",
            "data": {name, value}
        })
    }

    _events = [];
}