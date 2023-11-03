import {createServer} from "http";
import {Server} from "socket.io";
import {Uniti} from "./Uniti/Uniti.js";
import * as util from "util";
import * as fs from "fs/promises";
import {dirname} from 'path';
import {fileURLToPath} from 'url';
import * as connect4 from "./scripts/connect4.js";

const __dirname = dirname(fileURLToPath(import.meta.url));

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

async function executeScript(path, app) {
    try {
        const files = await fs.readdir(path, {withFileTypes: true, encoding: 'utf8', flag: 'r'});

        for (let i = 0; i < files.length; i++) {
            if (files[i].isDirectory()) {
                await executeScript(path + '/' + files[i].name, app);
                continue;
            }

            let extension = files[i].name.split('.').pop();

            if (extension === 'js') {
                const controller = await import(path + '/' + files[i].name);
                await controller.default(app);
            }
        }
    } catch (err) {
        throw err;
    }
}

export let game = undefined;

io.on("connection", function (socket) {
    let isGood = false;
    socket.on("init", (response) => {
        if (response === code) {
            isGood = true;
            com = socket;
        }
    })
    socket.on("update", async (response) => {
        if (!isGood) return;
        if (!game) {
            game = new Uniti(JSON.parse(response));
        } else {
            game.load(JSON.parse(response));
        }
        connect4.default(game);
        socket.emit("update", JSON.stringify(game.createJson()));
    })
    socket.on("disconnect", () => {
        if (isGood) process.exit(0);
    })
});
http.listen(port)