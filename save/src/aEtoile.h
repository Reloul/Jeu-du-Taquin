#ifndef __AETOILE_H_
#define __AETOILE_H_


 /*!
 *  \file aEtoile.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier permettant de déclarer les fonctions nécessaires à résoudre l'algorithme A*
*/ 

#include "list.h"
#include "queue.h"
#include "taquin.h"

void shortestWay(node** myGrid, node* goal, node* start, int size);

int distanceManhattan(node** myGrid, node* nX, node* nY, int size);
node** getNeighbor(node** myGride, node* myNode, int size, int* numMove);
void buildPath (node* goal);

void resolveTaquin(node** myGrid, int size);
#endif