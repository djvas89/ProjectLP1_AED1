//
// Created by djvas on 16/11/2017.
//

#include "threesumfast.h"

//
//  ThreeSumFast.c
//
//
//  Created by José Manuel Torres on 19/09/16.
//
//
#include <stdio.h>
#include "threesum.h"
#include "threesumfast.h"
#include "lib_util.h"

int countTriplesFast(int *a, int N, int *cost_model) {
    int k, cnt, i, j;
    sortIntArray(a, N);
    if (containsDuplicates(a, N))
        return -1;
    cnt = 0;
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            *cost_model += 2; // foram feitos mais 2 acessos ao vector
            k = binarySearch(a, N, -(a[i] + a[j]));
            if (k > j) cnt++;
        }
    }
    return cnt;
}
