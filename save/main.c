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
    printf("Choisissez le nombre de ligne de votre grille de jeu. Il doit être compris entre 2 et 10.\n");
    myvalue = checkInteger(10, 2);

    node** myGrid;
    initGridGame(&myGrid, myvalue);

    setGrid(myGrid, myvalue);
    mixGrid(myGrid, myvalue);

    printGrid(myGrid, myvalue);
    jouer(myGrid, myvalue);
    printf("Bien joué vous avez gagné votre jeu du Taquin ! \n");
    return(0);
}
