#ifndef __LIST_H_
#define __LIST_H_


 /*!
 *  \file list.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier de déclaration des fonctions pour les listes
*/ 

#include "declarationStruct.h"

// Structure permettant de représenter une liste
typedef struct list {
    node* head;
} list;

void addHead(list* myList, node* n);
void deleteHead(list* myList);
void initList(list** myList);
int isInL(list* myList, node* n);
int emptyList(list* myList);
void printList(list* myList);
void delete(list* myList, node* myNode);
void addSortNode(list* myList, node* n);
void freeList (list* myList);


#endif