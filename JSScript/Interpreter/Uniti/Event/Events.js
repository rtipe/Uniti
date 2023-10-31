export class Events {
    addEvent(name, callback) {
        if (name in this._callbacks)
            this._callbacks[name].push(callback);
        else
            this._callbacks[name] = [callback];
        return this._callbacks.length - 1;
    }

    removeEvent(name, i) {
        if (i === undefined) {
            this._callbacks[name].clear();
        } else {
            this._callbacks[name].splice(i, 1);
        }
    }

    emitEvent(name, value) {
        for (const key in this._callbacks) {
            for (const callback of this._callbacks[key]) {
                callback(value);
            }
        }
    }

    _callbacks = {};
}