export class Network {
    createJson() {
        return {
            events: this._events
        }
    }

    addServer(name, ip, port) {
        this._events.push({
            "name": "addServer",
            "data": {name, ip, port}
        })
    }

    removeServer(name) {
        this._events.push({
            "name": "removeServer",
            "data": name
        })
    }

    sendEvent(serverName, name, value) {
        this._events.push({
            "name": "sendEvent",
            "data": {serverName, name, value}
        })
    }

    _events = [];

    changeUser(name) {
        this._events.push({
            "name": "changeUser",
            "data": name
        })
    }
}
