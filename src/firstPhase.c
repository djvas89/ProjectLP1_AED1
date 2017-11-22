//
// Created by djvas on 16/11/2017.
//


#include "firstPhase.h"

/**
 * @brief firsPhase is the main for the first phase of the project LP1&AED1
 * @param argc - receives the copy from the main argc
 * @param argv - receives the copy from the main argv
 * @return 0 if there is no error
 */
int firstPhase(int argc, const char *argv[]) {
    char **ppnomes = NULL; //put the ppnomes at NULL
    int index = 0, size = 0;
    ppnomes = create_dynarray_strings(ppnomes, &size);
    char *input = (char *) malloc(sizeof(char) * M200);

    //check if allocation is success or fail
    if (input == NULL) {
        printf("Could not allocate memory");
        exit(1);
    }

    printf("Input a string, (Finish with '.'): ");
    do {
        realloc(input, (sizeof(char)));
        fgets(input, M200, stdin);
        if (strcmp(input, ".\n") == 0)
            break;
        if (index == (size - 1)) {
            create_dynarray_strings(ppnomes, &size);
            index++;
        }
    } while (1);
    print_dynarray_strings(index, ppnomes);
    return 0;
}

//http://www.martinbroadhurst.com/trim-a-string-in-c.html
//http://www.martinbroadhurst.com/dynamic-array-in-c.html

/**
 * @brief Clone_argv makes a dynamic copy of argv
 * @param argc - receives the argc integer from main
 * @param argv - receives the argv char from the main
 * @return ppnew - is the new cloned dynamic array of argv
 */
char **clone_argv(int argc, const char *argv[]) {
    char **ppnew = (char **) malloc(sizeof(char *) * argc); // ppnew aponta para o primeiro endereço do argv
    for (int i = 0; i < argc; ++i) {
        *(ppnew + i) = (char *) malloc(
                strlen(argv[i]) + 1); // for each "box" of char it allocates memory, creating a dynamic array
        strcpy(*(ppnew + i), argv[i]); //copies the string from the argv to the newly created dyn array
    }
    return ppnew;
}

/**
 * @brief Prints the dynamic array of strings
 * @param size - size of the array
 * @param pps - dynamic matrix of char
 */
void print_dynarray_strings(int size, char **pps) {
    for (int i = 0; i < size; ++i) {
        printf("String on Array nº [ %d ] = %s \n", i, *(pps + i));
    }
}

/**
 * @brief Frees the "lock" of the pps in the memory
 *
 * It frees the "lock" state that pps has. Now any other program can use that memory space
 * @param size - size of the array
 * @param pps - dynamic array to be freed
 */
void free_dynarray_strings(int size, char **pps) {
    for (int i = 0; i < size; ++i) {
        free(*(pps + i));
    }
    free(pps);
}

/**
 * @brief It creates a dynamic array of char
 * @param pps - dynamic array to be created
 * @param psize - size of the array
 * @return ppnew - the new dynamic array of strings
 */
char **create_dynarray_strings(char **pps, int *psize) {
    char **ppnew = NULL;
    if (pps == NULL) {
        *psize = M10;
        ppnew = (char **) calloc(*psize, sizeof(char *));
        return ppnew;
    }
    *psize += M10;
    ppnew = (char **) realloc(pps, *psize);
    for (int i = *psize - 1; i >= (*psize - M10); --i) {
        *(ppnew + i) = NULL;
    }
    return ppnew;
}

/**
 * @brief It will insert a string on a dynamic array of strings
 * @param pps - dynamic array where insertions will occur
 * @param psize - size of the array
 * @param s - array of char to be used in create_copy_dyn_string
 * @return pps - the new dyn array fully inserted
 */
char **insert_string_dynarray_strings(char **pps, int *psize, char s[]) {
    for (int i = 0; i < *psize; ++i) {
        if (*(pps + i) == NULL) {
            *(pps + i) = create_copy_dyn_string(s);
        }
    }
    return pps;
}

/**
 * @brief it creates a copy of the dynamic string
 * @param str - receives a static array of char
 * @return t - the new dynamic array of char
 */
char *create_copy_dyn_string(char *str[]) {
    char *t;
    t = (char *) malloc(sizeof(char) * strlen(str));
    strcpy(t, str);
    return t;
}

//char ** order_dynarray_strings(char *pps, int size)

//strcmp(*(pps+i),*(pps+j))<0 ou >0


