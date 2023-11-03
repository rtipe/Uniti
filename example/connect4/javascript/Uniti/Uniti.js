import {SceneManager} from "./Scene/SceneManager.js";
import {Network} from "./Network/Network.js";
import {Events} from "./Event/Events.js";

export class Uniti {
    sceneManager = undefined;
    network = undefined;
    events = new Events();

    constructor(json) {
        this.sceneManager = new SceneManager(json.sceneManager);
        this.network = new Network();
    }

    load(json) {
        this.sceneManager.load(json.sceneManager);
        if (!json.events) return;
        this.events.eventsCalled = json.events;
        for (const event of json.events) {
            let name = event.name;
            if (!event.values) continue;
            for (const value of event.values) {
                this.events.emitEvent(name, value);
            }
        }
    }

    createJson() {
        let events = this._events;
        this._events = [];
        return {
            events: events,
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