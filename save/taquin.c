
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
 *  \param maxInt entier correspondant à l'entier maximal que l'on souhaite que l'utilisateur rentre
 *  \param minInt entier correspondant à l'entier minimum que l'on souhaite que l'utilisateur rentre
 *  \return la valeur choisie et valide
*/

int checkInteger(int maxInt, int minInt) { 
    int check;
    int value;
    check = scanf("%d", &value);
    while((check == 0) || ((value < minInt) || (value > maxInt))){
        printf("erreur de saisie veuillez recommencer \n");
        while(getchar() != '\n'){};
        check=scanf("%d", &value);
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

void printGrid (node** myGrid, int size) {
    int i,j;

    printf("┌");
    for(i=0; i<size-1; i++){
        printf("───┬");
    }
    printf("───┐\n");
    for(i=0;i<size;i++){
        for(j=0; j<size;j++){
            if( myGrid[i][j].numero == 0 ){
                printf("│   ");
            } else{
                if(myGrid[i][j].numero < 10){
                    printf("│ %d ", myGrid[i][j].numero);
                }else{
                    printf("│ %d", myGrid[i][j].numero);
                }
            }
        }
        printf("│\n");
        if(i< size-1){
            printf("├");
            for(j=0;j<size-1;j++){
                printf("───┼");
            }
            printf("───┤\n");
        }
    }
    printf("└");
    for(i=0;i<size-1;i++){
        printf("───┴");
    }
    printf("───┘\n");
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
    int count = 1;
    for(int i=0; i<size; i++){
        for(int j = 0; j<size; j++){
            myGrid[i][j].numero = count;
            myGrid[i][j].position = count;
            myGrid[i][j].next = NULL;
            count++;
        }
    }
    myGrid[size-1][size-1].numero = 0;
    myGrid[size-1][size-1].position = 0;
    myGrid[size-1][size-1].next = NULL;
}


/*!
 *  \fn void changePos (node** myGrid, node* cell)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Tue 21 2023 - 13:26:16
 *  \brief procédure permettant d'échanger les positions d'une cellule si c'est possible (elle possède une case vide à côté) 
 *  \param myGrid tableau 2d de noeuds représentant ma grille de jeu
 *  \param cell case du tableau que l'on souhaite échanger
 *  \param x entier représentant le numéro des lignes
 *  \param y entier représentant le numéro des colonnes 
*/

void changePos (node** myGrid, coord coordCell ,int size) {
    int verif = 0;
    int x = coordCell.coord_X;
    int y = coordCell.coord_Y;
    //while (verif == 0) {
        if(x > 0){
            verif += move(myGrid, &myGrid[x][y], x-1, y);
        }
        if( x < size-1){
            verif += move(myGrid, &myGrid[x][y], x+1, y);
        }
        if(y > 0){
            verif += move(myGrid, &myGrid[x][y], x, y-1);
        }
        if(y< size-1){
            verif += move(myGrid, &myGrid[x][y], x, y+1);
        }
        if(verif == 0){
            printf("Mauvais coup veuillez recommencer \n");
        }
    //}
}

/*!
 *  \fn int move (node** myGrid, node* cell, int x, int y)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Tue 21 2023 - 13:38:12
 *  \brief procédure permettant de faire un coup en fonction des paramètres passés 
 *  \param myGrid tableau 2d de noeuds représentant ma grille de jeu
 *  \param cell case du tableau que l'on souhaite échanger
 *  \param x entier représentant le numéro des lignes
 *  \param y entier représentant le numéro des colonnes 
 *  \result 1 si une case a bougée et 0 (la case ne peut pas bouger)
*/

int move (node** myGrid,node* cell,int x, int y) {
    node* nodeTemp = malloc(sizeof(node));
    int verif = 0;
    if(myGrid[x][y].numero == 0){
        nodeTemp->numero = cell->numero;
        cell->numero = 0;
        myGrid[x][y].numero = nodeTemp->numero;
        verif = 1;
    }
    return verif;
}


/*!
 *  \fn int searchCoordCell (node** myGrid, int numCell)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Tue 21 2023 - 14:40:04
 *  \brief fonction permettant de recherher les coordonnées d'une cellule à partie de son numéro  
 *  \param myGrid tableau 2d de pointeur de noeud représentant la grille de jeu
 *  \param numCell entier représentant le numéro de la case
 *  \param size entier représentant la taille de la grille de jeu
 *  \return les coordonnées de la case que l'on recherche 
*/

coord searchCoordCell (node** myGrid, int numCell, int size) { 
    coord coordCell;
    coordCell.coord_X = -1;
    coordCell.coord_Y = -1;
    int i = 0;
    while (i < size && coordCell.coord_X < 0){
        int j= 0;
        while (j < size && coordCell.coord_Y < 0)
        {
            if (myGrid[i][j].numero == numCell){
                coordCell.coord_X = i;
                coordCell.coord_Y = j;
            }
            j++;
        }
        i++;
    }
    return coordCell;
}


/*!
 *  \fn void jouer (node** myGrid)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Tue 21 2023 - 15:29:29
 *  \brief procédure permettant de jouer au jeu du taquin 
 *  \param myGrid tableau 2d de pointeur représentant ma grille de jeu 
 *  \param size entier représentant la taille de ma grille
*/

void jouer (node** myGrid, int size) {
    int numCell;
    coord coordCell;
    int win = 0;
    while(win == 0){
        printf("Veuillez sélectionner le numéro de la case que vous souhaitez bouger \n");
        numCell = checkInteger(size*size-1, 1);
        coordCell = searchCoordCell(myGrid, numCell, size);
        changePos(myGrid, coordCell, size);
        printGrid(myGrid, size);
        win = verifWin(myGrid, size);
    }
}

/*!
 *  \fn void mixGrid (node** myGrid, int size)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 22 2023 - 11:03:52
 *  \brief procédure permettant de faire une série de coup aléatoire pour mélanger la grille 
 *  \param myGrid tableau 2d de pointeur de node permettant de représenter la grille de jeu 
 *  \param size entier représentant la taille de la grille de jeu
*/

void mixGrid (node** myGrid, int size) {
    coord coordCell;
    srand(time(NULL));
    //On choisit un nombre de coup aléatoire pour mélanger notre grille de jeu, ce nombre est choisit par rapport à la taille de la grille et le *10 est choisis totalement arbitrairement pour obtenir un nombre de mélange assez élevé
    int mix = size*size*10;
    for(int i = 0; i <= mix;i++){
        //Tableau contenant les différents coups possibles soit haut, bas, gauche , droite
        int possibleMoves[4] = {0};
        //numPossibleMoves nombre de coup possible
        int numPossibleMoves = 0;
        //On récupère les coordonnées de la case qui vaut 0
        coordCell = searchCoordCell(myGrid, 0, size);
        //Si la case 0 ne se trouve pas sur la première ligne, alors on peut monter
        if (coordCell.coord_X > 0) {
            possibleMoves[numPossibleMoves++] = 0; 
        }
        //Si la case 0 ne se trouve pas sur la dernière ligne, alors on peut descendre
        if (coordCell.coord_X < size - 1) {
            possibleMoves[numPossibleMoves++] = 1; 
        }
        //Si la case 0 ne se trouve pas sur la première colonne, alors on peut aller gauche
        if (coordCell.coord_Y > 0) {
            possibleMoves[numPossibleMoves++] = 2; 
        }
        //Si la case 0 ne se trouve pas sur la dernière colonne, alors on peut aller à droite
        if (coordCell.coord_Y < size - 1) {
            possibleMoves[numPossibleMoves++] = 3; 
        }
        //Si un coup est possible alors
        if (numPossibleMoves > 0) {
            //On choisit un coup possibl parmis les coups possibles
            int randomMove = possibleMoves[rand() % numPossibleMoves];
            switch (randomMove) {
                //Cas pour monter
                case 0:
                    move(myGrid, &myGrid[coordCell.coord_X-1][coordCell.coord_Y], coordCell.coord_X, coordCell.coord_Y);
                    break;
                //Cas pour descendre
                case 1:
                    move(myGrid, &myGrid[coordCell.coord_X+1][coordCell.coord_Y], coordCell.coord_X, coordCell.coord_Y);
                    break;
                //Cas pour aller à gauche
                case 2:
                    move(myGrid, &myGrid[coordCell.coord_X][coordCell.coord_Y-1], coordCell.coord_X, coordCell.coord_Y);
                    break;
                //Cas pour aller à droite
                case 3:
                    move(myGrid, &myGrid[coordCell.coord_X][coordCell.coord_Y+1], coordCell.coord_X, coordCell.coord_Y);
                    break;
            }
        }
    }
}

/*!
 *  \fn int verifGrid (node** myGrid, int size)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 23 2023 - 16:14:41
 *  \brief fonction permettant de vérifier si le joueur a gagné le jeu du taquin 
 *  \param myGrid tableau 2d de pointeur de noeud représentant notre grile de jeu 
 *  \param size entier représentant la taille de notre grille
 *  \return 1 si le jeu est gagné et 0 sinnon 
*/

int verifWin (node** myGrid, int size) { 
    int i=0;
    int j = 0;
    int verif = 1;

    while (i< size && verif == 1){
        while (j < size && verif == 1){
            if(myGrid[i][j].position != myGrid[i][j].numero){
                verif = 0;
                printf("position : %d, numero: %d\n", myGrid[i][j].position, myGrid[i][j].position);
            }
            j++;
        }
        j = 0;
        i++;   
    }
    
    return verif; 
}
 
 