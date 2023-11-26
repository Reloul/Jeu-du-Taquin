 /*!
 *  \file aStar.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief 
*/ 

#include "aStar.h"
#include "taquin.h"

/*!
 *  \fn void shortestWay ( node** myGrid, node* goal, node* start)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 23 2023 - 21:14:24
 *  \brief procédure permettant de trouver le chemin le plus court en partant d'un noeud de départ jus'à celui d'arriver
 *  \param myGrid tableau 2d de pointeur de noeud représentant la grille de jeu du Taquin
 *  \param goal pointeur de noeud représentant le noeud que l'on souhaite atteindre
 *  \param start pointeur de noeud représentant le noeud de départ
 *  \param size entier représentant la taille de notre grille de jeu
*/

void shortestWay(node **myGrid, node *goal, node *start, int size) {
    //Initialisation de mes files et listes
    queue *myQueue;
    initQueue(&myQueue);
    list *myList;
    initList(&myList);

    //entier CountMax servant normalement à arrêter le programme si la boucle countMax tourne trop longtemps
    int countMax = 0;
    //pointeur d'entier servant à compter le nb de voisin d'un noeud
    int *numMove = malloc(sizeof(int));
    *numMove = 0;
    //On range dans notre liste notre noeuds de départ
    addSortNode(myList, start);

    while (!emptyList(myList) && countMax < 1000) {
        //Notre noeud u prends la valeur de la te de la liste
        node *u = myList->head;
        deleteHead(myList);
        countMax++;
        //On vérifie que u est ou non le noeuf que l'on cherche
        if (u->position == goal->position) {
            //Si c'est le cas on construit notre chemin
            buildPath(u);
            free(numMove);
            freeList(myList);
            freeQueue(myQueue);
            //return dans la boucle => Illégal mais un peu la flemme de faire autrement (j'aurais pû ajouter une variable verif)
            return;
        //si u n'est pas le noeud recherché alors on va vérifier parmisses voisins et choisir celuiqui nous en rapproche
        } else {
            //Tableau de noeud représentant les voisins de u
            node **neighbors = getNeighbor(myGrid, u, size, numMove);
            //Pour tous les voisins de u
            for (int i = 0; i < *numMove; i++) {
                node *v = neighbors[i];
                //On vérifie si nous avons déjà consulté le voisin et si non on vérifie si le coût de son voisin est moins important que u
                if (v != NULL && (!isInQ(myQueue, v) || v->cost + 1 < u->cost)) {
                    //On augmente son coût et son coput heuristique, pas eu le temps de faire la distance de Hamming
                    v->cost = u->cost + 1;
                    v->heuristique = v->cost + distanceManhattan(myGrid, v, goal, size);
                    v->parent = u;
                    //On ajout v à notre liste triée pour pouvoir consulter ses voisins
                    addSortNode(myList, v);
                }
            }
            free(neighbors);
        }

        put(myQueue, u);
    }

    free(numMove);
    freeList(myList);
    freeQueue(myQueue);
    //Si on arrive ici la résolution du taquin est impossible
    fprintf(stderr, "Impossible de résoudre le taquin.\n");
}

/*!
 *  \fn int distanceManhattan (node** myGrid, node* nX, node* nYn int size)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sat 25 2023 - 14:23:40
 *  \brief fonction permettant de calculer la distance entre 2 noeuds d'après la distance de Manhattan 
 *  \param myGrid tableau 2d représentant la grille de jeu du jeu du Taquin
 *  \param nX pointeur d'un noeud
 *  \param nY pointeur d'un noeud
 *  \param size entier représentant la taille de la grille de jeu
 *  \return la distance entre 2 noeuds 
*/

int distanceManhattan (node** myGrid, node* nX, node* nY, int size) { 
    coord coordXNode = searchCoordCell(myGrid, nX->numero, size);
    coord coordYNode = searchCoordCell(myGrid, nY->numero, size);

    int calcX = abs(coordYNode.coord_X - coordXNode.coord_X);
    int calcY = abs(coordYNode.coord_Y - coordXNode.coord_Y);

    return calcX + calcY; 
}


/*!
 *  \fn int getNeighbor (node** myGrid, node* myNode)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sat 25 2023 - 14:54:07
 *  \brief fonction permettant de retourner une liste des voisins d'un noeud, c'est à dire des coups possible 
 *  \param myGrid tableau 2d de pointeur de noeud représentant la grille de jeu
 *  \param myNode noeud dont on souhaite récupérer ses voisins
 *  \param size entier représentant la taille de la grille de jeu 
 *  \param numMove pointeur d'entier servant à représenter les voisins de notre noeud
 *  \return une liste de noeud réprésentant les voisins de myNode 
*/

node** getNeighbor(node** myGrid, node* myNode, int size, int* numMove) { 
    coord coordMyNode = searchCoordCell(myGrid, myNode->numero, size);
    node** tabNeighbor = malloc(4 * sizeof(node*));
    //On vérifie si le noeud est sur un des bords de la grille de jeu
    if (coordMyNode.coord_X > 0) {
        tabNeighbor[(*numMove)++] = &myGrid[coordMyNode.coord_X - 1][coordMyNode.coord_Y];
    }
    if (coordMyNode.coord_X < size - 1) {
        tabNeighbor[(*numMove)++] = &myGrid[coordMyNode.coord_X + 1][coordMyNode.coord_Y];
    }
    if (coordMyNode.coord_Y > 0) {
        tabNeighbor[(*numMove)++] = &myGrid[coordMyNode.coord_X][coordMyNode.coord_Y - 1];
    }
    if (coordMyNode.coord_Y < size - 1) {
        tabNeighbor[(*numMove)++] = &myGrid[coordMyNode.coord_X][coordMyNode.coord_Y + 1];
    }

    return tabNeighbor;
}
/*!
 *  \fn void buildPath (node* goal)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sat 25 2023 - 17:01:16
 *  \brief procédure permettant de reconstituer le chemin allant de notre noeud de départ à celui d'arriver 
 *  \param goal noeud représentant le noeud voulu
*/

void buildPath(node *goal) {
    list *path;
    initList(&path);

    node *current = goal;
    //On va chercher tous les noeuds parents afin de reformer le chemin pour résoudre le jeu du taquin
    while (current != NULL) {
        node *pathNode = malloc(sizeof(node));
        pathNode->numero = current->numero;
        pathNode->position = current->position;
        addHead(path, pathNode);

        node *parent = current->parent;

        current = parent;
    }

    printf("Chemin optimal : ");
    printList(path);

    freeList(path); 
}


/*!
 *  \fn void resolveTaquin(node** myGrid, int size)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sun 26 2023 - 13:37:46
 *  \brief procédure permettant d'éxecuter l'algorithme A* afin de résoudre le jeu du taquin 
 *  \param myGrid tableau 2 d de pointeur de node représentant notre grille de jue à résoudre
 *  \param size entier correspondant à la taille de notre grille de jeu 
*/

void resolveTaquin(node** myGrid, int size) {
    int i, j;
    int count = 1;

    // Résoudre pour la case 0
    coord coordCell = searchCoordCell(myGrid, 0, size);
    shortestWay(myGrid, &myGrid[size - 1][size - 1], &myGrid[coordCell.coord_X][coordCell.coord_Y], size);

    // Résoudre pour les autres cases
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1; j++) {
            coordCell = searchCoordCell(myGrid, count, size);
            shortestWay(myGrid, &myGrid[i][j], &myGrid[coordCell.coord_X][coordCell.coord_Y], size);
            count++;
        }
    }
}
