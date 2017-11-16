//
// Created by djvas on 16/11/2017.
//

#include "queue_chars_array_impl.h"

//
//  main.c
//  queue_chars_array_impl
//
//  Created by José Manuel Torres on 26/11/14.
//  Copyright (c) 2014 ___JOSETORRES___. All rights reserved.
//

#include <stdio.h>
#include <string.h>


void initQueueChars(struct QueueCharsArrayImpl *q) {
    q->head = 0;
    q->N = 0;
    q->tail = 0;
}

int isEmptyQueueChars(struct QueueCharsArrayImpl *q) {
    return q->N == 0;
}

int sizeQueueChars(struct QueueCharsArrayImpl *q) {
    return q->N;
}

void printQueueChars(struct QueueCharsArrayImpl *q) {
    int j = 0, i = (q->tail - 1 + QUEUE_CAPACITY) % QUEUE_CAPACITY;
    printf("->[T] ");
    while (j < q->N) {
        printf("%c ", q->s[i]);
        i = (i - 1 + QUEUE_CAPACITY) % QUEUE_CAPACITY;
        j++;
    }
    printf("[H]->\n");
}

void enqueue(struct QueueCharsArrayImpl *q, char item) {
    q->s[q->tail] = item;
    q->tail = (q->tail + 1) % QUEUE_CAPACITY;
    q->N++;
}

char dequeue(struct QueueCharsArrayImpl *q) {
    char item;
    item = q->s[q->head];
    q->head = (q->head + 1) % QUEUE_CAPACITY;
    q->N--;
    return item;
}


