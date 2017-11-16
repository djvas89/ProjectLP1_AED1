//
// Created by djvas on 16/11/2017.
//

#ifndef PROJECTLP1_AED1_LINKLIST_H
#define PROJECTLP1_AED1_LINKLIST_H

#include <stdio.h>

struct LinkedListInts_Node {
    int item;
    struct LinkedListInts_Node *next;
};

struct LinkedListInts_Node *createListInts_Node(int item_value);

void printLinkedListInts(struct LinkedListInts_Node *lista);


/* cria uma lista ligada com base num vector de n inteiros */
struct LinkedListInts_Node *createListInts(int v[], int n);

int sizeLinkedListInts(struct LinkedListInts_Node *lista);

int getElement(struct LinkedListInts_Node *lista, int idx);

void setElement(struct LinkedListInts_Node *lista, int idx, int newValue);

struct LinkedListInts_Node *removeElement(struct LinkedListInts_Node *lista, int idx);


int maxSizeLinkedListInts(struct LinkedListInts_Node *lista);

int minSizeLinkedListInts(struct LinkedListInts_Node *lista);

#endif //PROJECTLP1_AED1_LINKLIST_H
