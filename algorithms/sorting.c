//
// Created by djvas on 12/12/2017.
//

#include "sorting.h"

void merge_sort_td(int a[], int aux[], int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    if (hi <= lo) return;
    merge_sort_td(a, aux, lo, mid);
    merge_sort_td(a, aux, mid+1, hi);
    merge_arrays(a, aux, lo, mid, hi);
}

void merge_arrays(int a[], int aux[], int lo, int mid, int hi) {
    int i = lo, j = mid+1, k;
    for (k = lo; k <= hi; k++) // copy
        aux[k] = a[k];
    for (k = lo; k <= hi; k++) { // merge
        if      (i > mid)          a[k] = aux[j++];
        else if (j > hi)           a[k] = aux[i++];
        else if (aux[j] < aux[i])  a[k] = aux[j++];
        else                       a[k] = aux[i++];
    }
}