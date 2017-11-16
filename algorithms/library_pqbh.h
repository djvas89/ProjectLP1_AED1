//
// Created by djvas on 16/11/2017.
//

#ifndef PROJECTLP1_AED1_LIBRARY_PQBH_H
#define PROJECTLP1_AED1_LIBRARY_PQBH_H

#include <stdio.h>
#include <stdlib.h>

#define  MAX_PQ 100

struct PQ {
    int pq[MAX_PQ];//ELEMENTO NA FILA (suas prioridades)
    int N; //número de elementos na PQ
    //pessoa * pessoas[MAX_PQ];
};

void
swimPQ(struct PQ *f, int k); // comparar a prioridade do pai e se a prioridade do pai for menor troca, sucessivamente
void insertPQ(struct PQ *f, int x); //inserir novo elemento fila prioritaria acrescentar pessoa *p
void sinkPQ(struct PQ *f, int k);

int delMaxPQ(struct PQ *f);

void printPQ(struct PQ *f);

int isEmptyPQ(struct PQ *f);

int sizePQ(struct PQ *f);

void initPQ(struct PQ *f);

void clientPQ_1();

#endif //PROJECTLP1_AED1_LIBRARY_PQBH_H
