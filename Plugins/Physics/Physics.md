explication de Physics.md

- Physics.md est un ObjectPlugin

il prend des paramètres :

- isOverlap
- boxes (tableau de box(x,y,width,height))

il reçoit des events :

- moveTo qui prend un json (position(x(float),y(float)),speed(float)) qui permet de déplacer l'object un à un point
  donné
- moveForward qui prend un json (deltaTime(float)(optionnel), speed(float)) qui permet de faire avancer l'objet
- moveBackward qui prend un json (deltaTime(float)(optionnel), speed(float)) qui permet de faire avancer l'objet
- moveLeft qui prend un json (deltaTime(float)(optionnel), speed(float)) qui permet de faire avancer l'objet
- moveRight qui prend un json (deltaTime(float)(optionnel), speed(float)) qui permet de faire avancer l'objet
- move qui prend un json (position(x(float),y(float)),deltaTime(float)(optionnel), speed(float)) qui permet de faire
  avancer l'objet à partir d'un normal (position)
- cancelMovement qui prend rien qui permet d'annuler le movement (pour moveTo)
- setspeed qui prend un json (float) qui permet de changer la vitesse de l'objet (pour moveTo)

elle emet des events :

- overlapped qui prend un json (string -> nom de l'objet) lorsqu'un objet à tranversé cette objet
- collided qui prend un json (string -> nom de l'objet) lorsqu'un objet à percuté cette objet

il traîtera la physique du jeu (collision movement...)

(mettre un lien vers plugin.md)