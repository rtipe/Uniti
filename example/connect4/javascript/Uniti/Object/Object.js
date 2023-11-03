import {Movement} from "./Movement.js";
import {Collision} from "./Collision.js";
import {Printable} from "./Printable.js";

export class GameObject {
    constructor(json, scene) {
        this.position = json.position;
        this.rotation = json.rotation;
        this.scale = json.scale;
        this.origin = json.origin;
        this.isEnable = json.isEnable;
        this.name = json.name;
        this.scene = scene;
        this.movement = new Movement(this);
        this.printable = new Printable(this);
        for (const key in json.children)
            this.children[key] = new GameObject(json.children[key], this);
    }

    createJson() {
        let events = this._events;
        this._events = [];
        let children = [];
        for (const key in this.children) {
            children.push(this.children[key].createJson());
        }
        return {
            events: events,
            position: this.position,
            rotation: this.rotation,
            scale: this.scale,
            origin: this.origin,
            isEnable: this.isEnable,
            name: this.name,
            children
        }
    }

    load(json) {
        this.position = json.position;
        this.rotation = json.rotation;
        this.scale = json.scale;
        this.origin = json.origin;
        this.isEnable = json.isEnable;
        this.children = Object.fromEntries(Object.entries(this.children).filter(([key]) => !(key in json.children)));
        for (const key in json.children) {
            if (!(key in this.children)) {
                this.children[key] = new GameObject(json.children[key], this);
            } else {
                this.children[key].load(json.children[key]);
            }
        }
    }
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
    children = {};
    name = "";
    scene = undefined;
    movement = undefined;
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