#ifndef __QUEUE_H_
#define __QUEUE_H_

 /*!
 *  \queue queue.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier de déclaratin des fonctions pour les queues
*/ 

#include "declarationStruct.h"


// Structure permettant de représenter une queue
typedef struct queue {
    struct node* first;
} queue;

void put(queue* myQueue, node* n);
void pass(queue* myQueue);
int emptyQueue(queue* myQueue);
int isInQ(queue* myQueue, node* n);
void initQueue(queue** myQueue);
void printQueue(queue* myQueue);
void freeQueue (queue* myQueue);

#endif