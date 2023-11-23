#ifndef __DECLARATION_STRUCT_H_
#define __DECLARATION_STRUCT_H_
 
 /*!
 *  \file declarationStruct.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier permettant de déclarer les différentes structures utiles pour notre programme
*/ 

/*Inclusion de la librairie stdio.h qui permet à l'utilisateur de faire un printf*/
#include <stdio.h>
/*Inclusion de la librairie stdlib.h qui permet à l'utilisateur de gérer la mémoire de façon dynamique ou encore de pouvoir intéragir avec le système d'exploitation*/
#include <stdlib.h>
#include <time.h>

// Structure d'un noeud possédant un numéro, une position et un pointeur sur un suivant
typedef struct node {
    int numero;
    int position;
    int cost;
    int heuristique;
    struct node* next;
} node;

#endif