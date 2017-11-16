//
// Created by djvas on 16/11/2017.
//

#ifndef PROJECTLP1_AED1_QUICKUNION_H
#define PROJECTLP1_AED1_QUICKUNION_H

void initQU(int *id, int n);

void initWQU(int *id, int *sz, int n);

int findQU(int *id, int i);

int distance2rootQU(int *id, int i);

void printDistances2rootQU(int *id, int i, int n);

int connectedQU(int *id, int p, int q);

void unionQU(int *id, int p, int q);

void unionWQU(int *id, int *sz, int p, int q);

#endif //PROJECTLP1_AED1_QUICKUNION_H
