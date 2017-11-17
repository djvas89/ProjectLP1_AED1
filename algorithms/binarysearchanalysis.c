//
// Created by djvas on 16/11/2017.
//

#include "binarysearchanalysis.h"

//
// Created by arpinto on 24-09-2016.
//

/**
 *
 * @param a array
 * @param n size of arrray
 * @param key value to search
 * @param cost_model number of iteration of this algorithm
 * @return -1 if value doesn't exist
 */
int binarySearchAnalysis(int a[], int n, int key, int *cost_model) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        *cost_model += 1;
        int mid = (lo + hi) / 2;
        if (key < a[mid]) hi = mid - 1;
        else if (key > a[mid]) lo = mid + 1;
        else return mid;

    }
    return -1;
}


#include <time.h>
#include "lib_util.h"
#include "binarySearchAnalysis.h"
#include <string.h>

/**
 * It records the elapsed time and the number of iterations BinarySearch algorithm
 * @param N size.
 * @param filename path to folder
 * @return
 */

int mainClientBinarySearch(int N, char *filename) {

    int *v, custo = 0;
    long long unsigned time_usec_init, time_usec_end;
    long elapsed_time;

    int key = 123414;

    v = newIntArray(N);
    N = readInts(filename, v, N);
    printf("\nLidos %d valores\n", N);
    sortIntArray(v, N);
    /*printf("\nValor a procurar:");
    scanf("%d",&key);*/

    gettimeuseconds(&time_usec_init); // init time
    int pos = binarySearchAnalysis(v, N, key, &custo);
    gettimeuseconds(&time_usec_end); // end time

    elapsed_time = (long) (time_usec_end - time_usec_init);

    if (pos != -1) printf("Posição no vetor ordenado: %d\n", pos);
    else printf("\tValor não encontrado\n");
    printf("\tTempo de execução: %ld\t (usec) \n\tPosição no vetor ordenado: %d\n", elapsed_time, pos);
    printf("\tNumero de iterações: %d\n\n", custo);

    freeIntArray(v);
    return 0;
}

/**
 *
 * @return
 */

int mainBinarySearchEx() {

    char *path2datafolder = "/home/arpinto/ClionProjects/AEDI/data/";
    char *datafiles[] = {"250ints.txt", "500ints.txt", "1Kints.txt", "2Kints.txt", "4Kints.txt", "8Kints.txt",
                         "16Kints.txt"};
    int tam[] = {250, 500, 1000, 2000, 4000, 8000, 16000};

    int i, k = 6;
    char filename[300];

    srand((unsigned) time(0));

    for (i = 0; i <= k; i++) {
        strcpy(filename, path2datafolder);
        strcat(filename, datafiles[i]);
        mainClientBinarySearch(tam[i], filename);
    }

    return 0;
}