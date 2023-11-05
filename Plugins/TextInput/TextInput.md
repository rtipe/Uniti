# TextInput.md

TextInput est un ObjectPlugin qui permet à l'utilisateur de saisir du texte.

## Paramètres

- `active` : Détermine si le champ de texte est actif dès le début.
- `height` : La hauteur du champ de texte.
- `width` : La largeur du champ de texte.
- `maxChar` : Le nombre maximum de caractères autorisés.

## Événement

Lorsque du texte est saisi, il émet un événement `inputchange` qui envoie un JSON contenant la chaîne de caractères.

## Dépendances

TextInput nécessite l'utilisation du composant `Render` ainsi qu'un élément imprimable de type texte.

Pour en savoir plus sur les plugins, consultez [plugin.md](https://github.com/rtipe/Uniti/blob/d83db8477333b3260975e19cee6697aea1c5bf38/Plugins/Plugin.md).
