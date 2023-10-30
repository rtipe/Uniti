class Object {
    position = {
        x: 0,
        y: 0
    }
    rotation = 0;
    scale = {
        x: 0,
        y: 0
    }
    origin = {
        x: 0,
        y: 0
    }
    isEnable = true;
    children = [];
    name = "";
    scene = undefined;
    movement = undefined;
    collision = undefined;
    printable = undefined;
    _events = [];

    clone(scene) {
        this._events.push({
            "name": "clone",
            "scene": (scene) ? scene : false
        })
    }

    emitEvent(name, value) {
        this._events.push({
            "name": "emitEvent",
            "data": {name, value}
        })
    }
}