Expliquer que le plugin c'est une lib dynamique qui sera importé dynamiquement
au moment de lancer le moteur.

mettre des liens vers les différents plugins crée (Button.md...)

expliquer la structure d'un plugin :

(méthode executé dans l'ordre)
Démarrage :

- preStart des corePlugin
- start des corePlugin
- postStart des corePlugin
- preStart des scenePlugin
- start des scenePlugin
- postStart des scenePlugin
- preStart des objectPlugin
- start des objectPlugin
- postStart des objectPlugin

Boucle du moteur :

- preUpdate corePlugin
- preUpdate scenePlugin
- preUpdate objectPlugin
- update objectPlugin
- update scenePlugin
- update corePlugin
- postUpdate objectPlugin
- postUpdate scenePlugin
- postUpdate corePlugin

fin :

- preEnd corePlugin
- preEnd scenePlugin
- preEnd objectPlugin
- end objectPlugin
- end scenePlugin
- end corePlugin
- postEnd objectPlugin
- postEnd scenePlugin
- postEnd corePlugin

mettre des liens vers les différentes explication (CorePlugin, ObjectPlugin...)