import {createServer} from "http";
import {Server} from "socket.io";
import {Uniti} from "./Uniti/Uniti.js";
import * as util from "util";

const http = createServer();
export const io = new Server(http);

const args = process.argv.slice(2);
const port = Number.parseInt(args[0]);
const code = args[1];

console.log(port, code);

if (Number.isNaN(port) || !code) process.exit(84);

let com = undefined;

console.log = function () {
    com.emit("log", JSON.stringify({message: util.format.apply(null, arguments) + "", type: "Info"}));
}
console.error = function () {
    com.emit("log", JSON.stringify({message: util.format.apply(null, arguments) + "", type: "Danger"}));
}
console.warn = function () {
    com.emit("log", JSON.stringify({message: util.format.apply(null, arguments) + "", type: "Warn"}));
}

io.on("connection", function (socket) {
    let isGood = false;
    let game = undefined;
    socket.on("init", (response) => {
        if (response === code) {
            isGood = true;
            com = socket;
        }
    })
    socket.on("update", (response) => {
        if (!isGood) return;
        if (!game) {
            game = new Uniti(JSON.parse(response));
        } else {
            game.load(JSON.parse(response));
        }
        socket.emit("update", JSON.stringify(game.createJson()));
    })
    socket.on("disconnect", () => {
        if (isGood) process.exit(0);
    })
});
http.listen(port)