export class Uniti {
    sceneManager = undefined;

    emitEvent(name, value) {
        this._events.push({
            "name": "emitEvent",
            "data": {name, value}
        })
    }

    addEvent(name, callback) {
        this._callbacks.push(callback);
        this._events.push({
            "name": "addEvent",
            "data": name
        })
    }

    _callbacks = [];
    _events = [];
}