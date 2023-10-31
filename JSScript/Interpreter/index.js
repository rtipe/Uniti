import {createServer} from "http";
import {Server} from "socket.io";
import {Uniti} from "./Uniti/Uniti.js";
import * as util from "util";
import * as fs from "fs";

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

function executeScript(path, app) {
    fs.readdir(path, {withFileTypes: true, encoding: 'utf8', flag: 'r'}, (err, files) => {
        if (err) throw err
        for (let i = 0; i < files.length; i++) {
            if (files[i].isDirectory()) {
                executeScript(path + '/' + files[i].name);
                continue;
            }
            let extension = files[i].name.split('.').pop();

            if (extension === 'js') {
                import("./" + path + '/' + files[i].name).then((controller) => {
                    controller.default(app)
                })
            }
        }
    })
    return false;
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
        executeScript("scripts", game);
        socket.emit("update", JSON.stringify(game.createJson()));
    })
    socket.on("disconnect", () => {
        if (isGood) process.exit(0);
    })
});
http.listen(port)