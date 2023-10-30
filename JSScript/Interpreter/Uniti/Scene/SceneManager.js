export class SceneManager {
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