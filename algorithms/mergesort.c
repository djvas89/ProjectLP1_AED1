//
// Created by djvas on 16/11/2017.
//

#include <stdlib.h>
#include <stdio.h>

void clientMerge1();
void clientMerge2();
void clientMerge3();

void merge1(int v1[], int n1, int v2[], int n2, int v[]);
void merge2(int a[], int aux[], int lo, int mid, int hi);
void mergesort(int a[], int aux, int lo, int hi);

void printArray(int v[], int N);


void clientMerge1()
{
    int v1[] = {10, 15, 23, 24, 30};
    int n1 = 5;
    int v2[] = {18, 25, 42, 50};
    int n2 = 4;
    int v[n1 + n2];
    printf("Merge Sort 1:\n\n");
    merge1(v1, n1, v2, n2, v);
}
void clientMerge2()
{
    int v1[] = {10, 15, 24, 30, 12, 23, 25, 28, 29};
    int v2[9];
    int l = 0, m = 3, h = 8;
    printf("\nMerge Sort 2:\n\n");
    merge2(v1, v2, l, m, h);
}
void clientMerge3()
{
    int v1[] = {15, 24, 25, 18, 31, 10, 4, 5, 20, 40};
    int v2[10];
    printf("\nMerge Sort 3:\n\n");
    mergesort(v2, v1,0,9);
}

void merge1(int v1[], int n1, int v2[], int n2, int v[])
{

    int i = 0, j = 0, k = 0;

    while (k < (n1 + n2))
    {
        if (v1[i] > v2[j])
        {
            v[k] = v2[j];
            k++;
            j++;
        }
        else if (v1[i] < v2[j])
        {
            v[k] = v1[i];
            k++;
            i++;
        }
        else
        {
            v[k] = v1[i];
            k++;
            i++;
        }
    }
    printArray(v, 9);

}

void printArray(int v[], int N)
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        printf(" %d ", v[i]);
    }
    printf("\n");
}

void merge2(int a[], int aux[], int lo, int mid, int hi)   //v1[lo....mid] v2[mid+1....hi]
{
    int i = lo, j = mid + 1, k = lo;
    while (k <= hi)
    {
        if (i > mid)
        {
            aux[k++] = a[j++];
        }
        else if (j > hi)
        {
            aux[k++] = a[i++];
        }
        else if (a[i] < a[j])
        {
            aux[k++] = a[i++];
        }
        else
        {
            aux[k++] = a[j++];
        }
    }
    printArray(aux, 9);
}

void mergesort(int a[], int aux, int lo, int hi)
{
    if(hi<=lo) return;
    int mid=(lo+hi)/2; //calcular ponto medio
    mergesort(aux, a, lo, mid);

    mergesort(aux, a, mid+1, hi);
    merge2(a, aux, lo, mid, hi);
}

void insertionSort(int x[], int lo, int hi)
{
    //cutoff
    int i,k,y;
    for (k=lo+1; k<=hi; k++)
    {
        y=x[k];
        i=k-1;
        while (i>=lo && y<x[i])
        {
            x[i+1]=x[i];
            i=i-1;
        }
        x[i+1]=y;
    }
}

