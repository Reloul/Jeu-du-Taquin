/*!
 *  \file list.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier permettant de définir les différentes fonctions concernant des listes
*/ 

#include "list.h"

/*!
 *  \fn void initList (list* myList)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 16 2023 - 14:48:29
 *  \brief procédure permettant d'initialiser une liste 
 *  \param list* myList pointeur vers une list permettant de l'initialiser 
*/

void initList(list** myList) {
    *myList = malloc(sizeof(list));
    if (*myList == NULL) {
        exit(EXIT_FAILURE);
    }
    (*myList)->head = NULL;  // Initialise le premier élément à NULL.
}

/*!
 *  \fn void addHead(list* myList, node* newNode)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 16 2023 - 14:53:48
 *  \brief procédure permettant de rajouter un élément dans une liste 
 *  \param myList pointeur vers une liste dont on souhaite un élément
 *  \param newNode pointeur d'un node que l'on souhaite ajouter à notre liste
*/

void addHead(list* myList, node* newNode) {
    if(myList == NULL || newNode == NULL){
        exit(EXIT_FAILURE);
    }
    newNode->next = myList->head;
    myList->head = newNode;
}


/*!
 *  \fn void deleteHead (list* myList)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 16 2023 - 15:03:42
 *  \brief procédure permettant de supprimer l'élément en tête de la liste 
 *  \param myList pointeur vers la liste dont on souhaite supprimer un élément
*/

void deleteHead (list* myList) {
    if(myList == NULL|| myList->head == NULL){
        exit(EXIT_FAILURE);
    }
    node *deleteNode = myList->head;
    myList->head = myList->head->next;
    free(deleteNode);
}
 
/*!
 *  \fn int isInL (list* myList, node* node)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 16 2023 - 15:14:56
 *  \brief fonciton permettant de savoir si un élément se trouve dans ma liste 
 *  \param myList pointeur vers une liste dont on souhaite savoir si elle possède un élément donné
 *  \param node pointeur vers un noeud dont on souahite savoir s'il est contenu dans notre liste
 *  \return verif = 1 si l'élément se trouve dans la liste et 0 sinon 
*/

int isInL (list* myList, node* myNode) { 
    //on créait un noeud temporaire permettant de parcourir notre liste
    node* nTemp = myList->head;
    int verif = 0;
    //Tant qu'on atteint pas la fin de notre liste ou que l'on ne trouve pas le noeud que l'on chercher on fait la boucle
    while(nTemp != NULL && verif == 0){
        if(nTemp == myNode){
            verif = 1;
        }
        nTemp = nTemp->next;
    }
    return (verif);
}
 
/*!
 *  \fn int emptyList (list* myList)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Fri 17 2023 - 10:40:56
 *  \brief fonction permettant de savoir si une liste est vide 
 *  \param myList pointeur d'une liste dont on souhaite savoir si elle est vide 
 *  \return 1 si elle est vide, 0 sinon 
*/

int emptyList (list* myList) { 
    return(myList->head == NULL); 
}

/*!
 *  \fn void printList (list* myList)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sat 18 2023 - 15:49:02
 *  \brief procédure permettant d'afficher le contenu d'une liste 
 *  \param myList pointeur d'une liste que l'on souhaite afficher 
*/

void printList (list* myList) {
    //on créait un noeud temporaire permettant de parcourir notre liste
    node* nTemp = myList->head;
    //Tant qu'on atteint pas la fin de notre liste ou que l'on ne trouve pas le noeud que l'on chercher on fait la boucle
    while(nTemp != NULL){
        printf("%d ", nTemp->numero);
        nTemp = nTemp->next;
    }
    printf(" \n");
    free(nTemp);
}


/*!
 *  \fn void delete (list* myListn, node* myNode)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Sat 18 2023 - 18:16:02
 *  \brief procédure permettant de supprimer un élément précis de notre liste 
 *  \param myList pointeur de liste dont on souhaite supprimer un élément
 *  \param myNode pointeur de noeud que l'on souhaite supprimer de notre liste
*/

void delete (list* myList, node* myNode) {

    if(isInL(myList, myNode)){
        //on créait un noeud temporaire permettant de parcourir notre liste
        node* nTemp = myList->head;
        //Tant qu'on atteint pas la fin de notre liste ou que l'on ne trouve pas le noeud que l'on chercher on fait la boucle
        while(nTemp != NULL){
            
            nTemp = nTemp->next;
        }
    }
}
 
 