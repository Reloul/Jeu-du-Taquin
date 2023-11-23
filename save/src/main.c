/*!
 *  \mainpage Programme pour
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \section INFO
 *     Voici le code fais par Valentin Serres qui permet d'appliquer l'algorithme A* sur le jeu de Taquin
*/


 /*!
 *  \file main.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief 
*/ 

#include "aEtoile.h"
#include "taquin.h"


int main(){
    int myvalue;
    printf("Choisissez un entier\n");
    myvalue = checkInteger();
    printf("ma valeur : %d \n", myvalue);

    node** myGrid;
    initGridGame(&myGrid, myvalue);

    setGrid(myGrid, myvalue);

    printGrid(myGrid, myvalue);
    return(0);
}
