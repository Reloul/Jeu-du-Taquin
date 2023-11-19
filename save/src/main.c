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


int main(){
    node* e;
    e = malloc(sizeof(node));
    e->numero = 1;
    e->position = 1;
    e->next = NULL;

    node* new;
    new = malloc(sizeof(node));
    new->numero = 2;
    new->position = 2;
    new->next = e;
    //printf("%d \n", new->next->numero);
    list* myList;
    initList(&myList);
    //printf("%d \n", emptyList(myList));
    addHead(myList, new);
    //printf("%d \n", emptyList(myList));
    printList(myList);

    free(myList->premier);
    free(myList);
    free(new);
    free(e);
    return(0);
}
