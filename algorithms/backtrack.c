//
// Created by djvas on 16/11/2017.
//

//
//  main.c
//  project_aed1_1617
//
//  Created by José Manuel Torres on 15/10/16.
//  Copyright (c) 2016 ___JOSETORRES___. All rights reserved.
//

#include <stdio.h>

#include "lib_util.h"

/**
 *  estado definido por variáveis Var[i] com valores do dominio Val[i]
 *  consideramos que as variaveis vão ser atribuidas numa
 */
struct assignment {
    int Vars_domain_size; // todas as variaveis têm o mesmo domínio de valores
    int N; // numero de variaveis. Indices: 0..N-1
    int N_Assing; // numero de atribuicoes feitas no estado atual
    int * Assing_Vars; // sequencias de variaveis (indices) atribuidas
    int * Assing_Values; // sequencia de valores (indices) atribuidos
};

#define ASSIGNMENT_FAILURE 0
#define ASSIGNMENT_COMPLETE 1
#define ASSIGNMENT_CONSISTENT 10

void createAssignment(struct assignment * a, int N, int Vars_domain_size);
void freeAssignment(struct assignment * a);

int recursive_backtrack(struct assignment * a);
int select_next_variable (struct assignment * a);
int is_current_assignment_consistent(struct assignment * a);
void test_backtrack_search();

void test_backtrack_searchn_queens();
int select_next_variable_nqueens(struct assignment * a);
int is_current_assignment_consistent_nqueens(struct assignment * a);

int main(int argc, const char * argv[]) {
    test_backtrack_searchn_queens();
    return 0;
}

void createAssignment(struct assignment * a, int N, int Vars_domain_size){
    a->Vars_domain_size = Vars_domain_size;
    a->N_Assing = 0;
    a->N = N;
    a->Assing_Vars = newIntArray(N);
    a->Assing_Values = newIntArray(N);
}

void freeAssignment(struct assignment * a){
    free(a->Assing_Values);
    free(a->Assing_Vars);
    return;
}

/**
 *  Teste de backtracking search
 */
void test_backtrack_search() {
    int num_vars = 0; // peças do jogo de mão (to do model)
    int vars_domain_size = 0; // peças do domino (to do model)
    struct assignment a;
    printf("test_backtrack_search()\n");
    createAssignment(&a, num_vars, vars_domain_size);
    recursive_backtrack(&a);
    freeAssignment(&a);
}

int recursive_backtrack(struct assignment * a) {
    int var, value, i, var_assignment_order, result;
    if (a->N_Assing == a->N)
        return ASSIGNMENT_COMPLETE;
    var = select_next_variable(a);
    var_assignment_order = a->N_Assing;
    a->Assing_Vars[var_assignment_order] = var;
    for (i=0; i<a->Vars_domain_size; i++) {
        value = i;
        a->Assing_Values[var_assignment_order] = value;
        if (is_current_assignment_consistent(a) == ASSIGNMENT_CONSISTENT) {
            a->N_Assing++;
            result = recursive_backtrack(a);
            if (result != ASSIGNMENT_FAILURE)
                return result;
            // remove from assignment (failure)
            a->N_Assing--;
        }
    }
    return ASSIGNMENT_FAILURE;
}


int select_next_variable (struct assignment * a){
    // To do
    return select_next_variable_nqueens(a);
    //return 0;
}

int is_current_assignment_consistent(struct assignment * a){
    // To do
    return is_current_assignment_consistent_nqueens(a);
    //return ASSIGNMENT_CONSISTENT;
}



/**
 *  Teste de backtracking search (nqueens demo)
 * https://en.wikipedia.org/wiki/Eight_queens_puzzle
 * http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/
 */
void test_backtrack_searchn_queens() {
    int num_vars = 8; // peças do jogo de mão
    int vars_domain_size = 8; // peças do domino
    int var, val;
    struct assignment a;
    printf("test_backtrack_search(): NQueens demo for %d queens\n",num_vars);
    createAssignment(&a, num_vars, vars_domain_size);
    recursive_backtrack(&a);
    printf("Values assigned to variable 0...%d (solution proposed): ",num_vars);
    printArray(a.Assing_Values, num_vars);
    for (val=0;val<vars_domain_size; val++) {
        for (var=0;var<num_vars; var++) {
            if (a.Assing_Values[var]==val)
                printf("Q");
            else printf(".");
        }
        printf("\n");
    }
    freeAssignment(&a);
}

int select_next_variable_nqueens(struct assignment * a){
    return a->N_Assing;
}

int is_current_assignment_consistent_nqueens(struct assignment * a){
    int i = a->N_Assing-1, value, d;
    while (i>=0) {
        d = a->N_Assing - i;
        value = a->Assing_Values[i];
        if (value == a->Assing_Values[a->N_Assing] ||
            value == a->Assing_Values[a->N_Assing] - d ||
            value == a->Assing_Values[a->N_Assing] + d)
            return ASSIGNMENT_FAILURE;
        i--;
    }
    return ASSIGNMENT_CONSISTENT;
}
