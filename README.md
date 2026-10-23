# Projet C

Éditeur de formes 2D au format SVG via ligne de commande, avec sauvegarde et
visualisation.

## Présentation

Ce projet est un éditeur de dessin. L'utilisateur  peut créer, modifier et supprimer
des formes via des menus en ligne de commande dans le terminal.
Il a aussi la possibilitée de sauvegarder son travail au format SVG pour le visualiser
dans n'importe quel naviguateur.

## Architecture

Le projet est organisé en trois couches, une par dossier :

- `modele/` : la structure de données et les règles : le document (une liste chaînée de
  formes), la forme (une union de géométries), les couleurs et l'état de
  transformation. C'est ici que sont mise en place l'insertion, la suppression, la
  recherche et l'attribution des identifiants liés aux formes.
- `cli/` : les menus et la saisie : les questions à l'utilisateur, la
  validation patiente des entrées (entiers, couleurs, identifiants), les
  boucles de menu d'édition et les messages d'erreurs.
- `svg/` : la vue : traduit chaque forme du document en balise SVG lors de
  la sauvegarde.

Le flux est à sens unique : le CLI pilote le modèle, le modèle ne connaît ni
les menus ni le SVG, et le module SVG ne lit que le modèle.

## Compilation

Le projet se compile avec le Makefile fourni :

    make build      compile le projet (produit l'exécutable `projet`)
    make run        compile puis lance le programme
    make clean      supprime l'exécutable

Prérequis : GCC (norme C99), sous Linux (la visualisation utilise `xdg-open`).

## Utilisation

Lancer le programme :

    ./projet

Menu principal :

- `2. Nouveau` : crée un dessin vierge ; le nom du fichier SVG est demandé,
  le dessin sera rangé dans le dossier `dessins/`.
- `0. Quitter`

Menu d'édition :
- `1. Afficher le contenu de la liste` : toutes les formes, avec leurs
  couleurs et leur état de transformation.
- `2. Afficher un élément` : affiches toutes les informations d'un élément au choix.
- `3. Ajouter une forme` : cercle, ellipse, rectangle, carré ou ligne, à la
  position choisie dans la liste.
- `4. Supprimer une forme` : par identifiant.
- `5. Modifier une forme` : chaque champ de géométrie, les couleurs, la 
  rotation (pivot) et l'inversion (miroir X/Y).
- `6. Visualiser` : ouvre le fichier SVG du disque dans le navigateur
  (Il faut d'abord avoir sauvegardé les modifications).
- `7. Sauvegarder` : écrit le dessin courant dans `dessins/<nom>.svg`.

À n'importe quelle question, `-1` (ou Ctrl+D) annule l'opération en cours.

## Fonctionnalités

- Formes : cercle, ellipse, rectangle, carré, ligne.
- Ajout à n'importe quelle position de la liste.
- Couleurs RGB de fond et de trait par forme (le fond d'une ligne n'a pas
  de sens visuel : seul le trait est affiché et exporté).
- Modification complète : géométrie, couleurs, rotation autour du centre de
  la forme, inversion selon X ou Y.
- Sauvegarde SVG avec transformation géométrique calculée par le navigateur
  (attribut `transform`).
- Visualisation du fichier SVG.
- Saisie patiente : les entrées invalides sont re-demandées.

## Limites

- L'ouverture de fichier existant (option `1. Ouvrir`) n'est pas implémentée.
- La visualisation ouvre le fichier tel qu'il est sur le disque : les
  modifications non sauvegardées n'y apparaissent pas.
- Beaucoup de formes et d'options de style ne sont pas supportés.