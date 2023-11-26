# Jeu-du-Taquin
Bienvenue dans ce jeu du Taquin où vous pourrez jouer au jeu du Taquin ou laisser l'algorithme A* le résoudre.
## Exécuter le programme
Pour exécuter le programme il vous faut :

-Décompresser l'archive du projet une fois installée

-Ouvrez votre terminal et vous rendre à la racine du projet (au même endroit que le Makefile)

-Exécuter la commande : 
```bash
./bin/exe
```
-Vous pourrez accèder au menu du programme et choisir la taille de la grille de jeu (entre 2x2 et 10x10)
## Problème du programme
J'ai rencontré beaucoup de problème avec cet algorithme et par conséquent l'algorithme A* ne fonctionne que pour certaines configurations d'une grille 2x2. Si par chance vous tombez sur l'une d'elle, il vous faut lire (à l'envers) les instructions données par le programme. Par exemple si le programme vous donne : 2 1 3 0, il faudra jouer 3 1 2.

Pour le reste le programme tombe dans une boucle infinie que je n'ai pas eu le temps de régler et l'algorithme ne prends pas en compte le fait qu'une case ne peux pas être déplacée sans que la case à côté soit une case vide.
