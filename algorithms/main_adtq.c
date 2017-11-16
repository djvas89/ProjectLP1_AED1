//
// Created by djvas on 16/11/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_int_array.h"
#include "linklist.h"
#include "queue_chars_array_impl.h"
#include "stack_chars_array_impl.h"


void clientStack();

void clientINTqueue();

int main() {
    //clientINTqueue();
    testClient_StackIntArray();

    return 0;
}

void clientINTqueue() {
    struct LinkedListInts_Node *list = NULL;
    int v1[] = {53, 24, 25, 5, 15};
    int n = 5;
    list = createListInts(v1, n);
    printLinkedListInts(list);
    printf("\n\nMax Value: %d\n", maxSizeLinkedListInts(list));
    printf("\nMin Value: %d\n", minSizeLinkedListInts(list));
}


void clientStack() {
    char c;//item
    struct StackCharsArrayImpl stk;
    initStackChars(stk);

    push(stk, 'D');
    push(stk, 'A');
    push(stk, 'B');
    c = pop(stk);
    printf("%c", c);
}