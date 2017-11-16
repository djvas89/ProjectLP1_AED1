//
// Created by djvas on 16/11/2017.
//

#include "stack_chars_array_impl.h"

//
//  stack_chars_array_impl.c
//  queue_chars_array_impl
//
//  Created by José Manuel Torres on 28/11/14.
//  Copyright (c) 2014 ___JOSETORRES___. All rights reserved.
//


void initStackChars(struct StackCharsArrayImpl *st) {
    st->N = 0;
}


int isEmptyStackChars(struct StackCharsArrayImpl *st) {
    return st->N == 0;
}

/** Returns size (number of elements) of the stack st */
int sizeStackChars(struct StackCharsArrayImpl *st) {
    return st->N;
}

void push(struct StackCharsArrayImpl *st, char item) {
    st->s[st->N] = item;
    st->N++;
}

char pop(struct StackCharsArrayImpl *st) {
    char item;
    st->N--;
    item = st->s[st->N];
    return item;
}
