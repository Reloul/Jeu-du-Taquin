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

#include "aStar.h"
#include "taquin.h"
#include <unistd.h>

int main(){
    
    int myvalue;
    printf("Choisissez le nombre de ligne de votre grille de jeu. Il doit être compris entre 2 et 10.\n");
    myvalue = checkInteger(10, 2);
    printf("Voulez-vous jouer au jeu du Taquin ou voulez vous laisser A* le résoudre?\n 1 : jouer\n 2 : A* \n\n");
    int choice = checkInteger(2,1);

    node** myGrid;
    initGridGame(&myGrid, myvalue);

    setGrid(myGrid, myvalue);
    mixGrid(myGrid, myvalue);

    printGrid(myGrid, myvalue);
    coord coordCellZero = searchCoordCell(myGrid, 0, myvalue);

    switch (choice)
    {
    case 1:
        jouer(myGrid, myvalue);
        printf("Bien joué vous avez gagné votre jeu du Taquin ! \n");
        break;
    case 2 :
        resolveTaquin(myGrid, myvalue);
        sleep(2);
        jouer(myGrid, myvalue);
        printf("Bien joué vous avez gagné votre jeu du Taquin ! \n");
        break;
    default:
        break;
    }
    return(0);
}
