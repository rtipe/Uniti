export class Clock {
    startTime = new Date();

    start() {

    }

    restart() {
        this.startTime = new Date();
    }

    getMilliSeconds() {
        const endTime = new Date();
        return endTime - this.startTime;
    }

    getSeconds() {
        return this.getMilliSeconds() / 1000;
    }
}