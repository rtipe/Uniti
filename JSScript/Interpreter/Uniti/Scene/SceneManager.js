import {Scene} from "./Scene.js";

export class SceneManager {
    constructor(json) {
        this.currentScene = new Scene(json.currentScene);
        this.globalScene = new Scene(json.globalScene);
        this.unloadScenes = json.unloadScenes;
    }

    createJson() {
        let events = this._events;
        this._events = [];
        return {
            events: events,
            currentScene: this.currentScene.createJson(),
            globalScene: this.globalScene.createJson(),
        }
    }

    load(json) {
        this.currentScene.load(json.currentScene);
        this.globalScene.load(json.globalScene);
        this.unloadScenes = json.unloadScenes;
    }
    currentScene = undefined;
    globalScene = undefined;

    changeScene(name) {
        this._events.push({
            "name": "changeScene",
            "data": name
        })
    }

    unloadScenes = [];

    emitEvent(name, value) {
        this._events.push({
            "name": "emitEvent",
            "data": {name, value}
        })
    }

    _events = [];
}