//
// Created by djvas on 16/11/2017.
//


#include "stack_int_array.h"

void testClient_StackIntArray() {
    struct StackIntArray stk;
    init_StackIntArray(&stk, 6);
    push_StackIntArray(&stk, 4);
    push_StackIntArray(&stk, 8);
    push_StackIntArray(&stk, 16);
    pop_StackIntArray(&stk);
    print_StackIntArray(&stk);
}

void init_StackIntArray(struct StackIntArray *st, int capacity) {
    st->s = (int *) malloc(capacity * sizeof(int));
    st->capacity = capacity;
    st->N = 0;
}

void push_StackIntArray(struct StackIntArray *st, int v) {
    st->s[st->N] = v;
    st->N++;
}

int pop_StackIntArray(struct StackIntArray *st) {
    int item;
    st->N--;
    item = st->s[st->N];
    return item;
}

void print_StackIntArray(struct StackIntArray *st) {
    int i;
    printf("Stack: ");
    for (i = 0; i < st->N; i++) {
        printf("%d ", st->s[i]);
    }
    printf("\n");
}
