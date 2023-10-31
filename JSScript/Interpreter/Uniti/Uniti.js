import {SceneManager} from "./Scene/SceneManager.js";
import {Network} from "./Network/Network.js";

export class Uniti {
    sceneManager = undefined;
    network = undefined;

    constructor(json) {
        this.sceneManager = new SceneManager(json.sceneManager);
        this.network = new Network();
    }

    load(json) {
        this.sceneManager.load(json.sceneManager);
    }

    createJson() {
        return {
            events: this._events,
            sceneManager: this.sceneManager.createJson(),
            network: this.network.createJson(),
        }
    }
    emitEvent(name, value) {
        this._events.push({
            "name": "emitEvent",
            "data": {name, value}
        })
    }
    _events = [];
}