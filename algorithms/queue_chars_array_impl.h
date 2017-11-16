//
// Created by djvas on 16/11/2017.
//

#ifndef PROJECTLP1_AED1_QUEUE_CHARS_ARRAY_IMPL_H
#define PROJECTLP1_AED1_QUEUE_CHARS_ARRAY_IMPL_H

#define QUEUE_CAPACITY 100

struct QueueCharsArrayImpl {
    char s[QUEUE_CAPACITY];
    int tail, head, N;
};

void initQueueChars(struct QueueCharsArrayImpl *q);

int isEmptyQueueChars(struct QueueCharsArrayImpl *q);

int sizeQueueChars(struct QueueCharsArrayImpl *q);

void printQueueChars(struct QueueCharsArrayImpl *q);

void enqueue(struct QueueCharsArrayImpl *q, char item);

char dequeue(struct QueueCharsArrayImpl *q);

#endif //PROJECTLP1_AED1_QUEUE_CHARS_ARRAY_IMPL_H
