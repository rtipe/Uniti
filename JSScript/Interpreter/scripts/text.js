export default function index(game) {
    console.log(game.sceneManager.currentScene.objects["lol"].position)
    game.sceneManager.currentScene.objects["lol"].position.x += 1;
    console.log(game.sceneManager.currentScene.objects["lol"].position)
}