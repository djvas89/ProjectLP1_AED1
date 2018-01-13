#include <stdlib.h>
#include <stdio.h>
#include "filaPQ.h"


void initFilaPQ(struct FilaPQ * pq, int capacidade) {
    pq->fila = (int *)malloc(sizeof(int)*(capacidade + 1));
    pq->fila[0] = 0;
    pq->n = 0;
    pq->capacidade = capacidade;
}


void insertFilaPQ(struct FilaPQ * pq, int elem) {
    pq->n += 1;
    pq->fila[pq->n] = elem;
    swimFilaPQ(pq, pq->n);
}

int delMaxFilaPQ(struct FilaPQ * pq) {
    int maxElem = pq->fila[1]; // max element
    pq->fila[1] = pq->fila[pq->n];
    pq->n -= 1;
    sinkFilaPQ(pq, 1);
    return maxElem;
}


void swimFilaPQ(struct FilaPQ * pq, int k) {
    int auxElem;
    while (k > 1 && pq->fila[k/2] < pq->fila[k]) {
        auxElem = pq->fila[k/2];
        pq->fila[k/2] = pq->fila[k];
        pq->fila[k] = auxElem;
        k = k/2;
    }
}


void sinkFilaPQ(struct FilaPQ * pq, int k) {
    int j, auxElem;
    while (2*k <= pq->n) {
        j = 2*k; // j idx do filho esq do elemento de idx k
        if (j < pq->n && pq->fila[j] < pq->fila[j+1]) j++;
        if (pq->fila[k] >= pq->fila[j]) break;
        auxElem = pq->fila[k];
        pq->fila[k] = pq->fila[j];
        pq->fila[j] = auxElem;
        k = j;
    }
}

void printFilaPQ(struct FilaPQ * pq){
    int i;
    for (i=1; i <= pq->n; i++)
        printf("%d ",pq->fila[i]);
}


