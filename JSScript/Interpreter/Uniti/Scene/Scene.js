import {GameObject} from "../Object/Object.js";

export class Scene {
    constructor(json) {
        this.name = json.name;
        for (const key in json.objects)
            this.objects[key] = new GameObject(json.objects[key], this);
    }

    createJson() {
        let events = this._events;
        this._events = [];
        let objects = [];
        for (const key in this.objects) {
            objects.push(this.objects[key].createJson());
        }
        return {
            objects,
            events: events
        }
    }

    load(json) {
        this.name = json.name;
        this.objects = Object.fromEntries(Object.entries(this.objects).filter(([key]) => !(key in json.objects)));
        for (const key in json.objects) {
            if (!(key in this.objects)) {
                this.objects[key] = new GameObject(json.objects[key], this);
            } else {
                this.objects[key].load(json.objects[key]);
            }
        }
    }

    objects = {};
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