//
// Created by djvas on 16/11/2017.
//

#include <stdio.h>
#include <stdlib.h>

#define XSIZE 10
void preKMP(char *x, int m, int kmpNext[]);
void KMP(char *x, int m, char *y, int n);


void preKMP(char *x, int m, int kmpNext[])
{
    int i, j;

    i = 0;
    j = kmpNext[0] = -1;
    while (i < m)
    {
        while (j > -1 && x[i] != x[j])
            j = kmpNext[j];
        i++;
        j++;
        if (x[i] == x[j])
            kmpNext[i] = kmpNext[j];
        else
            kmpNext[i] = j;
    }
}


void KMP(char *x, int m, char *y, int n)
{
    int i, j, kmpNext[XSIZE];

    /* Preprocessing */
    preKMP(x, m, kmpNext);

    /* Searching */
    i = j = 0;
    while (j < n)
    {
        while (i > -1 && x[i] != y[j])
            i = kmpNext[i];
        i++;
        j++;
        if (i >= m)
        {
            OUTPUT(j - i);
            i = kmpNext[i];
        }
    }
}
