export class Collision {
    boxes = [];
    isOverlap = true;

    onOverlap(callback) {
        this._onOverlap.push(callback);
        return this._onOverlap.length - 1;
    }

    onCollision(callback) {
        this._onCollsion.push(callback);
        return this._onCollsion.length - 1;
    }

    removeOverlap(id) {
        this._onOverlap.splice(id, 1);
    }

    removeCollision(id) {
        this._onCollsion.splice(id, 1);
    }

    _onOverlap = [];
    _onCollsion = [];
}