//
// Created by djvas89 on 13-01-2018.
//

#ifndef STACKQUEUELINKEDSTRINGS_H_INCLUDED
#define STACKQUEUELINKEDSTRINGS_H_INCLUDED

#include <stdlib.h>

struct LinkNodeString {
    char * item;
    struct LinkNodeString * next;
};

struct LinkedStackOfStrings {
    struct LinkNodeString * first;
};

struct LinkedQueueOfStrings {
    struct LinkNodeString * first, * last;
};

// stack API
int isEmpty_LinkedStackOfStrings(struct LinkedStackOfStrings * s);
void push_LinkedStackOfStrings(struct LinkedStackOfStrings * s, char * item);
char * pop_LinkedStackOfStrings(struct LinkedStackOfStrings * s);

// queue API
int isEmpty_LinkedQueueOfStrings(struct LinkedQueueOfStrings * q);
void enqueue_LinkedQueueOfStrings(struct LinkedQueueOfStrings * q, char * item);
char * dequeue_LinkedQueueOfStrings(struct LinkedQueueOfStrings * q);

//generic linked list API
struct LinkNodeString * newLinkNodeString(void);
void printListLinkNodeString(struct LinkNodeString * list);
int sizeListLinkNodeString(struct LinkNodeString * list);

//clients for testing
void clientTest_LinkedStackOfStrings(void);
void clientTest_LinkedQueueOfStrings(void);

#endif // STACKQUEUELINKEDSTRINGS_H_INCLUDED