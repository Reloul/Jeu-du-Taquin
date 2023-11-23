#ifndef __TAQUIN_H_
#define __TAQUIN_H_

 /*!
 *  \file taquin.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier permettant de déclarer les fonctions pour jouer au jeu du taquin
*/ 

#include "declarationStruct.h"

void initGridGame(node*** myGrid, int taille);
void setGrid(node** myGrid, int size);
void printGrid(node** myGrid, int size);
void changePos(node** myGrid, node* cell, int pos);
int verifWin(node** myGrid);
void jouer(node** myGrid);
int checkInteger();
#endif