//
// Created by djvas on 16/11/2017.
//

#include "threesum.h"

#include <string.h>
#include "lib_util.h"
#include "lib_stats.h"


/**
 *  print distinct triples (i, j, k) such that a[i] + a[j] + a[k] = 0
 *
 *  @param a int array
 *  @param N size of array
 */
void printAll(int *a, int N) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            for (k = j + 1; k < N; k++) {
                if (a[i] + a[j] + a[k] == 0) {
                    printf("%d %d %d\n", a[i], a[j], a[k]);
                }
            }
        }
    }
}

// return number of distinct triples (i, j, k) such that a[i] + a[j] + a[k] = 0
int countTriples(int *a, int N, int *cost_model) {
    int i, j, k;

    int cnt = 0;
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            for (k = j + 1; k < N; k++) {
                *cost_model += 3; // foram feitos mais 3 acessos ao vector
                if (a[i] + a[j] + a[k] == 0) {
                    cnt++;
                }

            }

        }

    }
    return cnt;
}


// returns true if the sorted array a[] contains any duplicated integers
int containsDuplicates(int *a, int N) {
    int i;
    for (i = 1; i < N; i++)
        if (a[i] == a[i - 1]) return 1;
    return 0;
}

/**
 * Exemplo de invocação (cmd dentro da pasta <aed1_project_root>\bin\Debug):
 * ..\..\data\30ints.txt 30
 */
int mainClienteThreeSum(int N, char *filename) {
    int *v;
    long long time_usec_init;
    long long time_usec_end;
    long elapsed_time;
    v = newIntArray(N);
    N = readInts(filename, v, N);
    printf("\n\nLidos %d valores\n", N);
    gettimeuseconds(&time_usec_init); // init time
    int cnt = countTriples(v, N, N);
    gettimeuseconds(&time_usec_end); // init time
    printAll(v, N); // imprime todos os triplos
    //printArray(v,N);
    elapsed_time = (long) (time_usec_end - time_usec_init);
    printf("elapsed time (usec) = %ld\ntriples = %d\n", elapsed_time, cnt);
    freeIntArray(v);
    return 0;
}



