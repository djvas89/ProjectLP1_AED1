//
// Created by djvas on 16/11/2017.
//

#ifndef PROJECTLP1_AED1_STACK_INT_ARRAY_H
#define PROJECTLP1_AED1_STACK_INT_ARRAY_H

struct StackIntArray {
    int *s;
    int N;
    int capacity;
};

void init_StackIntArray(struct StackIntArray *st, int capacity);

void push_StackIntArray(struct StackIntArray *st, int v);

int pop_StackIntArray(struct StackIntArray *st);

int isEmpty_StackIntArray(struct StackIntArray *st);

void print_StackIntArray(struct StackIntArray *st);

int size_StackIntArray(struct StackIntArray *st);

void testClient_StackIntArray();


#endif //PROJECTLP1_AED1_STACK_INT_ARRAY_H
