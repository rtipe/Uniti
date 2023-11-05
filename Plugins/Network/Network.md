explication de JSScript.md

- NetworkPlugin est un CorePlugin

il prend des paramètres :

- port
- latence
- timeout
- user (identifiant de l'utilisateur)

elle permet de lancer une session UDP

elle reçoit plusieurs events:

- addServer qui prend un json en paramètre (name(string),ip(string),port(int)) permet d'ajouter un serveur
- removeServer qui prend un json en paramètre (string) permet de supprimer un serveur
- sendEvent qui prend un json en paramètre (serverName(string),name(string),value(any)) elle permet d'envoyer des events
  au serveur en question
- changeUser qui prend un json en paramètre (string) qui permet de changer l'identifiant serveur
- sendAll qui prend un json en paramètre (name(string),id(string),value(any)) qui permet d'envoyer l'event à tout les
  serveurs

elle emet des events à tout le monde:

- disconnectUser qui reçoit un json (string)(le nom du serveur qui a close)
- newServerUser qui reçoit un json (user(string), ip(string), port(int))
- tout les events reçu à partir du serveur

(mettre un lien vers plugin.md)

(mettre le protocole)

- il faudra surement rajouter qu'il n'y a pas de condition d'erreur et que si il y a une erreur sur le packet le moteur
  emettra un texte sur la console et c tout