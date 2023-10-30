import {createServer} from "http";
import {Server} from "socket.io";

const http = createServer();
export const io = new Server(http);

const args = process.argv.slice(2);
const port = Number.parseInt(args[0]);
const code = args[1];

console.log(port, code);

if (Number.isNaN(port) || !code) process.exit(84);

io.on("connection", function (socket) {
    let isGood = false;
    socket.on("init", (response) => {
        if (response === code) isGood = true;
    })
    socket.on("disconnect", () => {
        if (isGood) process.exit(0);
    })
});
http.listen(port)