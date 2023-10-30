export class Movement {
    moveTo(position, speed) {
        this._events.push({
            "name": "moveTo",
            "data": {position, speed}
        })
    }

    moveForward(speed, deltaTime = -1) {
        this._events.push({
            "name": "moveForward",
            "data": {speed, deltaTime}
        })
    }

    moveBackward(speed, deltaTime = -1) {
        this._events.push({
            "name": "moveBackward",
            "data": {speed, deltaTime}
        })
    }

    moveLeft(speed, deltaTime = -1) {
        this._events.push({
            "name": "moveLeft",
            "data": {speed, deltaTime}
        })
    }

    moveRight(speed, deltaTime = -1) {
        this._events.push({
            "name": "moveRight",
            "data": {speed, deltaTime}
        })
    }

    move(position, speed, deltaTime = -1) {
        this._events.push({
            "name": "move",
            "data": {position, speed, deltaTime}
        })
    }

    cancelMovement() {
        this._events.push({
            "name": "cancelMovement"
        })
    }

    isMoving() {
        return this._isMoving;
    }

    getSpeed() {
        return this._speed;
    }

    setSpeed(speed) {
        this._events.push({
            "name": "setSpeed",
            data: speed
        })
    }

    _speed = 0;
    _isMoving = false;
    _events = [];
}