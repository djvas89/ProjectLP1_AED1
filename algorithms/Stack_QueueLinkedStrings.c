//
// Created by djvas89 on 13-01-2018.
//

#include "Stack_QueueLinkedStrings.h"


#include <stdio.h>

int isEmpty_LinkedStackOfStrings(struct LinkedStackOfStrings * s){
    return (s->first == 0);
}

void push_LinkedStackOfStrings(struct LinkedStackOfStrings * s, char * item) {
    struct LinkNodeString * oldfirst = s->first;
    s->first = newLinkNodeString();
    s->first->item = item;
    s->first->next = oldfirst;
}

char * pop_LinkedStackOfStrings(struct LinkedStackOfStrings * s){
    struct LinkNodeString * oldfirst = s->first;
    char * item = s->first->item;
    s->first = s->first->next;
    free(oldfirst);
    return item;
}


int isEmpty_LinkedQueueOfStrings(struct LinkedQueueOfStrings * q){
    return (q->first == 0);
}

void enqueue_LinkedQueueOfStrings(struct LinkedQueueOfStrings * q, char * item){
    struct LinkNodeString * oldlast = q->last;
    q->last = newLinkNodeString();
    q->last->item = item;
    q->last->next = 0;
    if (isEmpty_LinkedQueueOfStrings(q)) q->first = q->last;
    else oldlast->next = q->last;
}

char * dequeue_LinkedQueueOfStrings(struct LinkedQueueOfStrings * q){
    struct LinkNodeString * oldfirst = q->first;
    char * item = q->first->item;
    q->first = q->first->next;
    free(oldfirst);
    if (isEmpty_LinkedQueueOfStrings(q)) q->last = 0;
    return item;
}

struct LinkNodeString * newLinkNodeString(void){
    struct LinkNodeString * node;
    node = (struct LinkNodeString *)malloc(sizeof(struct LinkNodeString));
    return node;
}

void printListLinkNodeString(struct LinkNodeString * list){
    while (list !=NULL) {
        printf("(%s)", list->item);
        list=list->next;
    }
}

int sizeListLinkNodeString(struct LinkNodeString * list){
    int sz=0;
    while (list !=NULL) {
        sz = sz+1;
        list=list->next;
    }
    return sz;
}


void clientTest_LinkedStackOfStrings(void) {
    char * strings[] = {"it","was","the","best","of","times"};
    struct LinkedStackOfStrings s; // stack linked
    s.first = 0;
    push_LinkedStackOfStrings(&s, strings[0]);
    push_LinkedStackOfStrings(&s, strings[1]);
    push_LinkedStackOfStrings(&s, strings[2]);
    push_LinkedStackOfStrings(&s, strings[3]);
    push_LinkedStackOfStrings(&s, strings[4]);
    push_LinkedStackOfStrings(&s, strings[5]);
    while(!isEmpty_LinkedStackOfStrings(&s)){
        printf("%s\n", pop_LinkedStackOfStrings(&s));
    }
}

void clientTest_LinkedQueueOfStrings(void) {
    char * strings[] = {"it","was","the","best","of","times"};
    struct LinkedQueueOfStrings q; // queue linked
    q.first = 0;
    q.last = 0;
    enqueue_LinkedQueueOfStrings(&q, strings[0]);
    enqueue_LinkedQueueOfStrings(&q, strings[1]);
    enqueue_LinkedQueueOfStrings(&q, strings[2]);
    enqueue_LinkedQueueOfStrings(&q, strings[3]);
    enqueue_LinkedQueueOfStrings(&q, strings[4]);
    enqueue_LinkedQueueOfStrings(&q, strings[5]);
    while(!isEmpty_LinkedQueueOfStrings(&q)){
        printf("%s\n", dequeue_LinkedQueueOfStrings(&q));
    }
}
