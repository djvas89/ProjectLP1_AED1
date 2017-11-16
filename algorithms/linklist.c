//
// Created by djvas on 16/11/2017.
//

#include "linklist.h"

//
//  linklist.c
//  linklists_19nov2014
//
//  Created by José Manuel Torres on 19/11/14.
//  Copyright (c) 2014 ___JOSETORRES___. All rights reserved.
//
#include <stdlib.h>


struct LinkedListInts_Node *createListInts_Node(int item_value) {
    struct LinkedListInts_Node *node;
    node = (struct LinkedListInts_Node *) malloc(sizeof(struct LinkedListInts_Node));
    node->item = item_value;
    node->next = NULL;
    return node;
}

void printLinkedListInts(struct LinkedListInts_Node *lista) {
    while (lista != NULL) {
        printf("%d ", lista->item);
        lista = lista->next;
    }
}


/* cria uma lista ligada com base num vector de n inteiros */
struct LinkedListInts_Node *createListInts(int v[], int n) {
    struct LinkedListInts_Node *lista = NULL, *last = NULL;
    int i;
    // adiciona primeiro elemento da lista
    if (n > 0) {
        lista = createListInts_Node(v[0]);
        last = lista;
    }
    // adiciona restantes elementos da lista
    for (i = 1; i < n; i++) {
        last->next = createListInts_Node(v[i]);
        last = last->next;
    }
    return lista;
}


int sizeLinkedListInts(struct LinkedListInts_Node *lista) {
    int sz = 0;
    while (lista != NULL) {
        lista = lista->next;
        sz++;
    }
    return sz;
}


int getElement(struct LinkedListInts_Node *lista, int idx) {
    int i = 0;
    while (lista != NULL) {
        if (i == idx)
            return lista->item; // retorna o valor correspondente a esse índice
        lista = lista->next;
        i++;
    }
    return -1; // Erro! Elemento não existente
}


void setElement(struct LinkedListInts_Node *lista, int idx, int newValue) {
    int i = 0;
    while (lista != NULL) {
        if (i == idx) {
            lista->item = newValue; // retorna o valor correspondente a esse índice
            return;
        }
        lista = lista->next;
        i++;
    }
}


struct LinkedListInts_Node *removeElement(struct LinkedListInts_Node *lista, int idx) {
    struct LinkedListInts_Node *aux = NULL, *aux2 = NULL;
    int i = 0;
    aux = lista;
    // caso 1: lista já estava vazia
    if (lista == NULL)
        return lista; // retorna NULL
    // caso 2: remover o primeiro elemento da lista
    if (idx == 0) {
        lista = lista->next;
        free(aux);
        return lista; // cabeça da lista passa a ser o segundo elemento
    }
    // caso geral: remover elemento no interior da lista
    while (aux != NULL) {
        if (i == idx) {
            aux2->next = aux->next;
            free(aux);
            return lista;
        }
        aux2 = aux; // aux2 aponta para elemento anterior a aux
        aux = aux->next;
        i++;
    }
    return lista; // elemento não encontrado
}

int maxSizeLinkedListInts(struct LinkedListInts_Node *lista) {
    int max = 0;
    while (lista != NULL) {
        if (max <= lista->item) {
            max = lista->item;
        }
        lista = lista->next;
    }
    return max;
}

int minSizeLinkedListInts(struct LinkedListInts_Node *lista) {
    int min = 10;
    while (lista != NULL) {
        if (min >= lista->item) {
            min = lista->item;
        }
        lista = lista->next;
    }
    return min;
}
