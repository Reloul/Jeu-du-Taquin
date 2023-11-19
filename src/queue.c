
 /*!
 *  \file file.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier permettant de définir les fonctions pour les files
*/ 

#include "queue.h"



/*!
 *  \fn void initQueue (queue* myQueue)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sat 18 2023 - 17:04:52
 *  \brief procédure permettant d'initialiser une file 
 *  \param myQueue pointeur de pointeur d'une file que l'on souhaite initialiser 
*/

void initQueue (queue** myQueue) {
    *myQueue = malloc(sizeof(queue));
    if(*myQueue == NULL){
        exit(EXIT_FAILURE);
    }
    (*myQueue)->first = NULL;
}
 

/*!
 *  \fn void put (queue* myQueue, node* myNode)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sat 18 2023 - 16:52:02
 *  \brief procédure permettant de rajouter un noud à une file 
 *  \param myQueue pointeur d'une file dont on souhaite rajouter un élément
 *  \param myNode pointeur de noeud que l'on souhaite rajouter dans une file
*/

void put(queue* myQueue, node* myNode) {
    if(myQueue == NULL || myNode == NULL){
        exit(EXIT_FAILURE);
    }
    if( myQueue->first == NULL){
        myQueue->first = myNode;
    }else{
        node *currentNode = myQueue->first;
        while (currentNode->next != NULL){
            currentNode = currentNode->next;
        }
        currentNode->next = myNode; 
    }
}

/*!
 *  \fn void pass (queue* myQueue)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sat 18 2023 - 17:11:51
 *  \brief procédure permettant de supprimer le premier élément de ma file 
 *  \param myQueue pointeur de file dont on souhaite supprimer le premier élément 
*/

void pass (queue* myQueue) {
    if(myQueue == NULL || myQueue->first == NULL){
        exit(EXIT_FAILURE);
    }
    myQueue->first = myQueue->first->next;
}
 
/*!
 *  \fn int emptyQueue (queue* myQueue)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sat 18 2023 - 17:25:08
 *  \brief fonction permettant de déterminer si une file est vide ou non 
 *  \param myQueue pointeur de file dont on souhaite savoir si elle est vide 
 *  \return 1 si la fonction est vide et 0 sinon 
*/

int emptyQueue (queue* myQueue) { 
    return(myQueue->first == NULL); 
}

/*!
 *  \fn int isInQ (queue* myqueue, node* myNode)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sat 18 2023 - 17:28:24
 *  \brief fonction permettant de savoir si un élément est bien dans ma file ou non 
 *  \param myQueue pointeur d'une file dont on souhaite savoir si elle contient l'élément que l'on cherche
 *  \param myNode pointeur d'un noeud dont on souhaite savoir s'il appartien à notre file 
 *  \return 1 si l'élément est bien dans ma file et 0 sinon 
*/

int isInQ (queue* myQueue, node* myNode) { 
    node* nTemp = myQueue->first;
    int verif = 0;
    while (nTemp != NULL && verif == 0){
        if(nTemp == myNode){
            verif = 1;
        }
        nTemp = nTemp->next;
    } 
    return verif; 
}

/*!
 *  \fn void printQueue (queue* myQueue)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sat 18 2023 - 17:55:46
 *  \brief procédure permettant d'afficher les éléments de ma file 
 *  \param  myQueue pointeur de liste que l'on souhaite afficher
*/

void printQueue (queue* myQueue) {
    node* nTemp = myQueue->first;
    while (nTemp != NULL){
        printf("%d ", nTemp->numero);
        nTemp = nTemp->next;
    }
    printf("\n");
    free(nTemp);
}
 