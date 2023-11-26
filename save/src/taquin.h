#ifndef __TAQUIN_H_
#define __TAQUIN_H_

 /*!
 *  \file taquin.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier permettant de déclarer les fonctions pour jouer au jeu du taquin
*/ 

#include "declarationStruct.h"

typedef struct coord
{
    int coord_X;
    int coord_Y;
}coord;


void initGridGame(node*** myGrid, int taille);
void setGrid(node** myGrid, int size);
void mixGrid(node** myGrid, int size);
void printGrid(node** myGrid, int size);
void changePos(node** myGrid, coord coordCell, int size);
int move(node** myGrid, node* cell, int x, int y);
int verifWin(node** myGrid, int size);
void jouer(node** myGrid, int size);
int checkInteger(int maxInt, int minInt);
coord searchCoordCell(node** myGrid, int numCell, int size);

#endif