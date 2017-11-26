//
// Created by djvas on 22/11/2017.
//

#include "file.h"
#include "firstPhase.h"

/**
 * @brief writes to file from matrix
 * @param pps - matrix
 * @param i - index of each line of the matrix
 * @return 0 or 1 if succ or fail
 */
int writeTo(char **pps, int *i) {
    char *sentence;
    FILE *fptr;

    fptr = fopen("bagofwords.txt", "w");
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    sentence = *(pps + ((*i)++));

    fprintf(fptr, "%s", sentence);
    fclose(fptr);
    return 0;
}

/**
 * @brief reads from file to console line
 * @param pps
 * @return null
 */
char **readFrom(char *filenamePath, char **pps, int index) {

    FILE *fp = fopen(filenamePath, "r");
    //char **frases = NULL;
    int x = 0;
    int size = 5;
    //frases = (char **) malloc(sizeof(char *) * size);
    char line[M200]; //var for read from file
    while (fgets(line, M200, fp)) {
        if (x == (size / 2)) {
            size *= 2;
            //pps = (char **) realloc(frases, sizeof(char *) * (size));
            for (index = size / 2; index < size; index++) {
                *(pps + index) = (char *) malloc(sizeof(char));
            }
        }
        *(pps + x) = (char *) malloc(sizeof(int) * strlen(line));
        //insert_string_dynarray_strings(pps, &size, line, &index);
        strcpy(*(pps + x), line);
        x++;
    }
    for (index = 0; index < x; index++) {
        char *str;
        str = strtok(*(pps + index), ",.!? ");
        while (str != NULL) {
            printf("%s\n", str);
            str = strtok(NULL, " .!?");
        }
    }
    fclose(fp);
    return NULL;
}