import {Clock} from "../Uniti/Time/Clock.js";

let start = false;
let gameEnded = false;
let winner = "";

let connect4 = {
    "column1": [],
    "column2": [],
    "column3": [],
    "column4": [],
    "column5": [],
    "column6": [],
    "column7": []
}

let columnPosition = {
    "column1": 30,
    "column2": 30 + 80,
    "column3": 30 + 80 * 2,
    "column4": 25 + 80 * 3,
    "column5": 20 + 80 * 4,
    "column6": 20 + 80 * 5,
    "column7": 20 + 80 * 6
}

let clock = new Clock();

let iCoin = 0;

let isRed = true;

function checkWin(player) {
    const columns = Object.values(connect4);
    const numRows = 6;
    const numCols = 7;

    for (let row = 0; row < numRows; row++) {
        for (let col = 0; col <= numCols - 4; col++) {
            if (
                columns[col][row] === player &&
                columns[col + 1][row] === player &&
                columns[col + 2][row] === player &&
                columns[col + 3][row] === player
            ) {
                return true;
            }
        }
    }

    for (let col = 0; col < numCols; col++) {
        for (let row = 0; row <= numRows - 4; row++) {
            if (
                columns[col][row] === player &&
                columns[col][row + 1] === player &&
                columns[col][row + 2] === player &&
                columns[col][row + 3] === player
            ) {
                return true;
            }
        }
    }

    for (let col = 0; col <= numCols - 4; col++) {
        for (let row = 0; row <= numRows - 4; row++) {
            if (
                columns[col][row] === player &&
                columns[col + 1][row + 1] === player &&
                columns[col + 2][row + 2] === player &&
                columns[col + 3][row + 3] === player
            ) {
                return true;
            }
        }
    }

    for (let col = 3; col < numCols; col++) {
        for (let row = 0; row <= numRows - 4; row++) {
            if (
                columns[col][row] === player &&
                columns[col - 1][row + 1] === player &&
                columns[col - 2][row + 2] === player &&
                columns[col - 3][row + 3] === player
            ) {
                return true;
            }
        }
    }
    return false;
}

export default function index(game) {
    if (!start) {
        start = false;
        game.events.addEvent("onClick", (value) => {
            if (clock.getSeconds() < 0.2) return;
            clock.restart();
            if (gameEnded === true) return;
            if (connect4[value["id"]].length >= 6) return;
            game.sceneManager.currentScene.addObject({
                "name": "coin" + iCoin,
                "transform": {
                    "scale": {
                        "x": 0.4,
                        "y": 0.4
                    },
                    "position": {
                        "x": columnPosition[value["id"]],
                        "y": 465 - (connect4[value["id"]].length * 79)
                    }
                },
                "plugins": [
                    {
                        "name": "PrintablePlugin",
                        "type": "sprite",
                        "texture": {
                            "path": "./assets/" + ((isRed) ? "red" : "yellow") + "_coin.png"
                        }
                    }
                ],
                "children": []
            })
            connect4[value["id"]].push((isRed) ? "red" : "yellow");
            iCoin++;
            isRed = !isRed;
            if (checkWin("red")) {
                winner = "Winner is red !";
                gameEnded = true;
            } else if (checkWin("yellow")) {
                winner = "Winner is yellow !";
                gameEnded = true;
            }
        });
        game.sceneManager.currentScene.objects["status"].printable.setString(winner);
    }
}