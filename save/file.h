#ifndef __FILE_H_
#define __FILE_H_

 /*!
 *  \file file.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier de déclaratin des fonctions pour les files
*/ 

#include "declarationStruct.h"


// Structure permettant de représenter une file
typedef struct file {
    struct node* premier;
} file;

void enfiler(file* myFile, node* n);
void defiler(file* myFile);
void emptyFile(file* myFile);
int isInF(file* myFile, node* n);
void initFile(file* myFile);
node* first(file* myFile);
void printFile(file* myFile);


#endif