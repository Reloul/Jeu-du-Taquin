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
    new->next = NULL;
    //printf("%d \n", new->next->numero);
    queue* myQueue;
    initQueue(&myQueue);
    put(myQueue, new);
    put(myQueue, e);
    printQueue(myQueue);
    pass(myQueue);
    printQueue(myQueue);
    printf("%d \n", emptyQueue(myQueue));
    printf("2 dans ma file? %d \n", isInQ(myQueue, new));
    printf("1 dans ma file? %d \n", isInQ(myQueue, e));
    free(myQueue->first);
    free(myQueue);
    return(0);
}
