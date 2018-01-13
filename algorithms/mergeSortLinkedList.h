//
// Created by djvas89 on 13-01-2018.
//

//
// Created by André Pinto on 11/12/17.
//

#ifndef MERGESORTLINKEDLIST_MERGESORTLINKEDLIST_H
#define MERGESORTLINKEDLIST_MERGESORTLINKEDLIST_H

/* Link list node */
struct Node
{
    char * data;
    int id;
    struct Node* next;
};

/* function prototypes */
struct Node* Merge(struct Node *a, struct Node *b, int flag);
void FrontBackSplit(struct Node* source,
                    struct Node** frontRef, struct Node** backRef);
void printList(struct Node *node);
void MergeSort(struct Node** list, int flag);
void addElement(struct Node** list, char * new_data, int key);

#endif //MERGESORTLINKEDLIST_MERGESORTLINKEDLIST_H