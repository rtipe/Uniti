# Uniti

(une image si possible)

Expliquer que le game engine s'inspire de uniti (on reprenant des éléments d'avant)

et dire qu'on peut crée un serveur à partir du game engine et que tout est
modulable au runtime à partir de plugin et que tout est configurable à partir d'un json

mettre un exemple de comment init le projet :

int main() {
try {
Uniti::Core mainInstance(Uniti::Object::openJsonFile("./json/project.json"));

        mainInstance.start();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}
(le code je l'ai trouvé sur example/connect4/index.cpp)
(et que c'est aussi simple que ça)

exemple de project.json :

{
"plugins": [
{
"name": "plugin"
},
{
"name": "RenderPlugin",
"width": 600,
"height": 600
},
{
"name": "NetworkPlugin"
},
{
"name": "JSScriptPlugin",
"path": "./javascript/index.js",
"fps": 5
}
],
"name": "name",
"sceneFolder": "./json",
"startScene": "startScene.json",
"globalScene": "globalScene.json",
"ObjectPlugins": "./ObjectPlugin",
"CorePlugins": "./CorePlugin"
}

expliquer ensuite les paramètres que prend le project.json:

- name -> nom du projet
- sceneFolder -> le chemin où se trouvera tout les scènes (il prendra de façon recursive)
- startScene -> le nom de la scène (avec .json à la fin attention !)
- globalScene -> le nom de la scène (avec .json à la fin attention !)
- ObjectPlugins -> le chemin du dossier où se trouvera tout les plugins ObjectPlugin(mettre un petit lien sur
  ObjectPlugin) (c pas récursive)
- CorePlugins -> le chemin du dossier où se trouvera tout les plugins scenePlugin(mettre un petit lien sur
  scenePlugin) (c pas récursive)
- ScenePlugins -> le chemin du dossier où se trouvera tout les plugins CorePlugin(mettre un petit lien sur corePlugin) (
  c pas récursive)

expliquer comment fonctionne les scènes :

globalScene -> est une scène qui va reste tout le temps pendant que le moteur tourne il ne peut pas être changé
il est utile de stock des informations de jeu comme la vie du joueur ou mettre les objets qui gére les inputs de
l'utilisateur en fonction de ses paramètres

startScene -> est une scène qui peut être changer pendant le cycle du moteur
il est utile de l'utiliser pour afficher la map du jeu

faire une navbar qui permet d'aller sur Plugin.md

exemple de jeu crée :

mettre connect4 et un lien avec connect4.md (et une image)

mettre rtype et un lien vers le repo rtype (et une image)

expliquer que pour tout problème il faudrait faire un issue sur github

mettre les contacts

mettre les contributeurs

mettre la license