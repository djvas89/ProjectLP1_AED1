//
// Created by djvas on 16/11/2017.
//


#include "library_pqbh.h" //priority queue with binary heaps

void
swimPQ(struct PQ *f, int k) // comparar a prioridade do pai e se a prioridade do pai for menor troca, sucessivamente
{
    int aux;
    while (k > 1 && f->pq[k / 2] < f->pq[k]) {
        printf("swim...\n");
        aux = f->pq[k / 2];
        f->pq[k / 2] = f->pq[k];
        f->pq[k] = aux;
        k = k / 2;
    }
}

void insertPQ(struct PQ *f, int x) //inserir novo elemento fila prioritaria acrescentar pessoa *p
{
    f->N++;
    f->pq[f->N] = x;
    swimPQ(f, f->N);
}

void sinkPQ(struct PQ *f, int k) {
    int aux, j;
    while (2 * k <= f->N) {
        printf("sink...\n");
        j = 2 * k;
        if (j < f->N && f->pq[j] < f->pq[j + 1]) j++;
        if (!(f->pq[k] < f->pq[j])) break;
        aux = f->pq[k];
        f->pq[k] = f->pq[j];
        f->pq[j] = aux;
        k = j;
    }
}

int delMaxPQ(struct PQ *f) {
    int max = f->pq[1];
    f->pq[1] = f->pq[f->N];
    f->N--;
    sinkPQ(f, 1);
    return max;
}

void printPQ(struct PQ *f) {
    int i;
    printf("\nPQ: \n");
    for (i = 1; i <= f->N; i++) {
        printf("%d\n", f->pq[i]);
    }
    printf("\n");
}

int isEmptyPQ(struct PQ *f) {
    if (f->N == 0)
        return f->N = 1;
    else
        return f->N = 0;
}

int sizePQ(struct PQ *f) {
    return f->N;
}

void initPQ(struct PQ *f) {
    f->N = 0;
}

void printPrettyPQ(struct PQ *f) {
    int i, node_level_idx = 1, max_num_nodes_level = 1;
    printf("PQ:\n");
    for (i = 1; i <= f->N; i++) {
        if (node_level_idx == 1) printf("("); // first
        else if (node_level_idx % 2 == 1) printf(")(");
        else printf(" "); // separator
        printf("%2d", f->pq[i]); // print node
        node_level_idx++;
        if (node_level_idx > max_num_nodes_level) {
            node_level_idx = 1;
            max_num_nodes_level *= 2;
            printf(")\n"); //last
        } else if (i == f->N) {
            printf(")\n"); //last node of tree
        }
    }
    printf("\n");
}

/** verifica se satisfaz bin heap */
int verifyBinaryHeapPropPQ(struct PQ *f) {
    int k;
    for (k = 2; k <= f->N; k++)
        if (f->pq[k] > f->pq[k / 2])
            return 0;
    return 1;
}

void clientPQ_1()
{
    int i,del, opPQ[]= {250,100,300,400,150,-1,-1,220,-1};

    struct PQ pq1;
    initPQ(&pq1);

    for (i=0; i<=9; i++)
    {
        if (opPQ[i]>=0)
        {
            printf("\nInsert %d\n", opPQ[i]);
            insertPQ(&pq1,opPQ[i]);
            printPQ(&pq1);
        }
        else
        {

            del=delMaxPQ(&pq1);
            printf("\nDelmax = %d\n", del);
            printPQ(&pq1);
        }
    }
}
