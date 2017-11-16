//
// Created by djvas on 16/11/2017.
//

#ifndef PROJECTLP1_AED1_STACK_CHARS_ARRAY_IMPL_H
#define PROJECTLP1_AED1_STACK_CHARS_ARRAY_IMPL_H

#include <stdio.h>

#define STACK_CAPACITY 10

struct StackCharsArrayImpl {
    char s[STACK_CAPACITY];
    int N;
};


void initStackChars(struct StackCharsArrayImpl *st);

int isEmptyStackChars(struct StackCharsArrayImpl *st);

int sizeStackChars(struct StackCharsArrayImpl *st);

void push(struct StackCharsArrayImpl *st, char item);

char pop(struct StackCharsArrayImpl *st);


#endif //PROJECTLP1_AED1_STACK_CHARS_ARRAY_IMPL_H
