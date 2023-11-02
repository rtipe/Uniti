export class Movement {
    constructor(object) {
        this.gameObject = object;
    }

    createJson() {
        let events = this._events;
        this._events = [];
        return {
            events: events
        }
    }
    moveTo(position, speed) {
        this.gameObject.emitEvent("moveTo", {position, speed})
    }

    moveForward(speed, deltaTime = -1) {
        this.gameObject.emitEvent("moveForward", {speed, deltaTime})
    }

    moveBackward(speed, deltaTime = -1) {
        this.gameObject.emitEvent("moveBackward", {speed, deltaTime})
    }

    moveLeft(speed, deltaTime = -1) {
        this.gameObject.emitEvent("moveLeft", {speed, deltaTime})
    }

    moveRight(speed, deltaTime = -1) {
        this.gameObject.emitEvent("moveRight", {speed, deltaTime})
    }

    move(position, speed, deltaTime = -1) {
        this.gameObject.emitEvent("move", {position, speed, deltaTime})
    }

    cancelMovement() {
        this.gameObject.emitEvent("cancelMovement", {})
    }

    setSpeed(speed) {
        this.gameObject.emitEvent("setSpeed", speed)
    }
    _events = [];
}