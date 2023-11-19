#ifndef __AETOILE_H_
#define __AETOILE_H_


 /*!
 *  \file aEtoile.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier permettant de déclarer les fonctions nécessaires à résoudre l'algorithme A*
*/ 

#include "list.h"
#include "file.h"

list astar(node e);

list chemin(node e, node f);

int solution(node e);

list succ(node e);

int cost( node e, node f);

int h(node e);


#endif