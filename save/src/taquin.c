
 /*!
 *  \file taquin.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief définition des différentes fonctions permettant de jouer au jeu du Taquin
*/ 

#include "taquin.h"

/*!
 *  \fn void initGridGame (node**- myGrid)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sun 19 2023 - 11:12:18
 *  \brief procédure permettant d'initialiser la grille de jeu et de la ramplir de façon aléatoire 
 *  \param myGrid pointeur de pointeur d'un tableau de noeud qui sert à représenter ma grille de jeu
 *  \param size entier représentant le nombre de case de chaque côté de ma grille
*/

void initGridGame(node*** myGrid, int size) {
    int i;
    *myGrid = malloc(size*sizeof(node*));
    for(i = 0; i<size; i++){
        (*myGrid)[i] = malloc(size*sizeof(node));
    }
}

/*!
 *  \fn int checkInteger()
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sun 19 2023 - 11:21:11
 *  \brief fonction permettant de vérifier que l'élément choisit est bien un entier 
 *  \return la valeur choisie et valide
*/

int checkInteger() { 
    int check;
    int value;
    check = scanf("%d", &value);
    while((check == 0) || ((value < 2) && (value > 10))){
        printf("erreur de saisie veuillez recommencer \n");
        while(getchar() != '\n'){};
        check=scanf("%d", &value);
        printf(" valeur : %d \n", value);
    }
    return(value); 
}

/*!
 *  \fn void printGrid (node** myGrid, int size)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Mon 20 2023 - 16:11:15
 *  \brief procédure permettant d'afficher la grille du jeu 
 *  \param myGrid pointeur de pointeur de noeud représentant un tableau 2d de noeuds pour pouvoir faire la grille de jeu 
 *  \param size entier représentant la taille des côtés de notre grille
*/

void printGrid(node** myGrid, int size) {
    int i, j;
    int maxNum = size * size - 1; // Le premier nombre est 0

    // On calcule la taille maximale d'une case
    int cellWidth = 1;
    while (maxNum > 9) {
        maxNum /= 10;
        cellWidth++;
    }

    printf("┌");
    for (i = 0; i < size - 1; i++) {
        printf("%*s", cellWidth + 1, "───┬");
    }
    printf("%*s\n", cellWidth + 1, "───┐");

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (myGrid[i][j].numero == 0) {
                printf("│%*s", cellWidth + 1, " ");
            } else {
                printf("│ %-*d", cellWidth, myGrid[i][j].numero);
            }
        }
        printf("│\n");

        if (i < size - 1) {
            printf("├");
            for (j = 0; j < size - 1; j++) {
                printf("%*s", cellWidth + 1, "───┼");
            }
            printf("%*s\n", cellWidth + 1, "───┤");
        }
    }

    printf("└");
    for (i = 0; i < size - 1; i++) {
        printf("%*s", cellWidth + 1, "───┴");
    }
    printf("%*s\n", cellWidth + 1, "───┘");
}


/*!
 *  \fn void setGrid (node** myGrid)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Mon 20 2023 - 17:16:02
 *  \brief procédure permettant d'initialiser toutes les cases de la grille de jeu 
 *  \param myGrid tableau 2d de pointeur de noeud représentant la grille de jeu 
 *  \param size entier représentant la taille de chaque côté de ma grille
*/

void setGrid (node** myGrid, int size) {
    int count = 0;
    for(int i=0; i<size; i++){
        for(int j = 0; j<size; j++){
            myGrid[i][j].numero = count;
            myGrid[i][j].position = count;
            myGrid[i][j].next = NULL;
            count++;
        }
    }
}
 


 