//
// Created by djvas89 on 13-01-2018.
//

#ifndef FILAPQ_H_INCLUDED
#define FILAPQ_H_INCLUDED

struct FilaPQ {
    int n;
    int capacidade;
    int * fila;
};

void initFilaPQ(struct FilaPQ * pq, int cap);
void insertFilaPQ(struct FilaPQ * pq, int elem);
int delMaxFilaPQ(struct FilaPQ * pq);
void swimFilaPQ(struct FilaPQ * pq, int elem);
void sinkFilaPQ(struct FilaPQ * pq, int elem);
void printFilaPQ(struct FilaPQ * pq);

#endif // FILAPQ_H_INCLUDED