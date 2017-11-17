//
// Created by djvas on 16/11/2017.
//

#ifndef PROJECTLP1_AED1_FIRSTPHASE_H
#define PROJECTLP1_AED1_FIRSTPHASE_H

#define M10 10
#define M200 200

#include <malloc.h>
#include <mem.h>
#include <stdio.h>
#include <stdlib.h>

int firstPhase(int argc, const char *argv[]);

char **clone_argv(int argc, const char *argv[]);

void print_dynarray_strings(int size, char **pps);

void free_dynarray_strings(int size, char **pps);

char **create_dynarray_strings(char **pps, int *psize);

char **insert_string_dynarray_strings(char **pps, int *psize, char s[]);

char *create_copy_dyn_string(char str[]);

#endif //PROJECTLP1_AED1_FIRSTPHASE_H
