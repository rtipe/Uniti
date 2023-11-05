explication de Render.md

- RenderPlugin est un CorePlugin

il prend des paramètres :

- width
- height
- icon (chemin vers l'image)
- title

elle emet des events :

- MOUSE_XX_RELEASED qui envoie la position de la souris
- MOUSE_XX_POUSSED qui envoie la position de la souris
- KEY_XX_RELEASED qui envoie rien
- KEY_XX_PRESSED qui envoie rien

Elle gère toute la logique de rendu (création de l'objet, gestion de la profondeur...)

- PrintablePlugin est un ObjectPlugin

il prend des paramètres :

- type (sprite ou text)
- zIndex (float) (la profondeur de l'objet)

si c'est un sprite :

- texture -> (path,smooth,repeat)
- textureRect -> (x,y,width,height)

si c'est un texte:

- font -> (path)
- text -> text qui sera affiché
- color -> (r,g,b,a)
- style ->(regular,bold,italic)
- size

elle reçoit des events :

- setString qui reçoit un json (string) change le texte d'affichage
- setFont qui reçoit un json (string -> path) change le chemin de la font
- setCharacterSize qui reçoit un json (int)
- setStyle qui reçoit un json (string)
- setColor qui reçoit un json (string)
- setTexture qui reçoit un json (path(string),smooth(bool),repeat(bool))
- changeZIndex qui reçoit un json (float)

Elle permet de dire à RenderPlugin d'afficher cette objet là avec les paramètres données

(mettre un lien vers plugin.md)