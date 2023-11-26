 /*!
 *  \file aEtoile.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief 
*/ 

#include "aEtoile.h"
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
*/

void shortestWay (node** myGrid, node* goal, node* start, int size) {
    queue* myQueue;
    initQueue(&myQueue);
    list* myList;
    initList(&myList);
    int verif = 0;
    int* numMove = malloc(sizeof(int));

    addSortNode(myList, start);
    while (!(emptyList(myList)) && verif == 0){
        node* u = malloc(sizeof(node));
        u->numero = myList->head->numero;
        u->position = myList->head->position;
        u->cost = myList->head->cost;
        u->heuristique = myList->head->heuristique;
        u->parent = myList->head->parent;
        
        deleteHead(myList);
        if(u->position == goal->position){
            buildPath(u);
            verif = 1;
        }else{
            *numMove = 0;
            node** neighbor = getNeighbor(myGrid, u, size, numMove);
            int i = 0;
            while (i < *numMove && verif == 0){
                node* v = neighbor[i];
                if(v != NULL){
                    if (!(isInQ(myQueue, v)) || (v->cost + 1 < u->cost)) {
                        v->cost = u->cost + 1;
                        v->heuristique = v->cost + distanceManhattan(myGrid, v, goal, size);
                        v->parent = u;
                        addSortNode(myList, v);
                    }
                }
                i++;
            }
        }
        put(myQueue, u);
    }
    free(myList);
    free(myQueue);
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

    int calcX = coordYNode.coord_X - coordXNode.coord_X;
    int calcY = coordYNode.coord_Y - coordXNode.coord_Y;

    if(calcX < 0)
        calcX = -calcX;
    if(calcY < 0)
        calcY = -calcY;

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
 *  \return une liste de noeud réprésentant les voisins de myNode 
*/

node** getNeighbor(node** myGrid, node* myNode, int size, int* numMove) { 
    coord coordMyNode = searchCoordCell(myGrid, myNode->numero, size);
    node** tabNeighbor = malloc(4 * sizeof(node*));

    if (coordMyNode.coord_X > 0 && myGrid[coordMyNode.coord_X - 1][coordMyNode.coord_Y].numero == 0) {
        tabNeighbor[(*numMove)++] = &myGrid[coordMyNode.coord_X - 1][coordMyNode.coord_Y];
    }
    if (coordMyNode.coord_X < size - 1 && myGrid[coordMyNode.coord_X + 1][coordMyNode.coord_Y].numero == 0) {
        tabNeighbor[(*numMove)++] = &myGrid[coordMyNode.coord_X + 1][coordMyNode.coord_Y];
    }
    if (coordMyNode.coord_Y > 0 && myGrid[coordMyNode.coord_X][coordMyNode.coord_Y - 1].numero == 0) {
        tabNeighbor[(*numMove)++] = &myGrid[coordMyNode.coord_X][coordMyNode.coord_Y - 1];
    }
    if (coordMyNode.coord_Y < size - 1 && myGrid[coordMyNode.coord_X][coordMyNode.coord_Y + 1].numero == 0) {
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
 *  \param goal noeud représentant le noeud de départ 
*/

void buildPath (node* goal) {
    list* path;
    initList(&path);
    node* current = goal;

    while( current != NULL){
        node* pathNode = malloc(sizeof(node));
        pathNode->numero = current->numero;
        pathNode->position = current->position;

        addHead(path, pathNode);

        current = current->parent;
    }

    printf("Chemin optimal : ");
    printList(path);
    
}

/*!
 *  \fn void resolveTaquin (node** myGrid, int size)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sun 26 2023 - 13:37:46
 *  \brief procédure permettant d'éxecuter l'algorithme A* afin de résoudre le jeu du taquin 
 *  \param myGrid tableau 2 d de pointeur de node représentant notre grille de jue à résoudre
 *  \param size entier correspondant à la taille de notre rille de jeu 
*/

void resolveTaquin(node** myGrid, int size) {
    //int win = 0;
    int i = 0;
    int j = 0;
    int count = 1;
    //while(win == 0){
        //i = 0;
        coord coordCell = searchCoordCell(myGrid, 0, size);
        shortestWay(myGrid, &myGrid[size-1][size-1], &myGrid[coordCell.coord_X][coordCell.coord_Y], size );
        while( i < size-2){
            j=0;
            while( j < size-2){
                coord coordCell = searchCoordCell(myGrid, count, size);
                shortestWay(myGrid, &myGrid[i][j], &myGrid[coordCell.coord_X][coordCell.coord_Y], size );
                j++;
                count++;
            }
            i++;
        }
  //  }
}
