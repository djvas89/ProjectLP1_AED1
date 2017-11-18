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
    ppnomes = clone_argv(argc, argv);
    print_dynarray_strings(argc, ppnomes);
    free_dynarray_strings(argc, ppnomes);

    /*char str[M200] = "";
    char **ppnomes = NULL;
    int size = 0;
    int index = 0;
    ppnomes = create_dynarray_strings(ppnomes, &size);
    printf("Inserir Nomes (Terminar c/ \".\")\n");
    do {
        fgets(str,
              M200, stdin);
        if (
                strcmp(str,
                       ".\n") == 0)
            break;
        if (index == (size - 1)) {
            create_dynarray_strings(ppnomes,
                                    &size);
        }
    } while (1);*/
    return 0;
    
    /** main bernardo
    char** create_dyn_array_strings(char** ppstr, int *psize){

    if(ppstr==NULL){
       
        return calloc(10, sizeof(char*));// zera todas as posições a 0
        
    }
    
    return realloc(ppstr, (psize + 10) * sizeof(char));  // realoca e copia do anterior para o novo e faz o free
    
}
*//

}


//one possibility
/*
char str[] = "John|Doe|Melbourne|6270|AU";
char* tempstr = calloc(strlen(str)+1, sizeof(char));
strcpy(tempstr, str);*/

//another

//http://www.martinbroadhurst.com/dynamic-array-in-c.html

/*
typedef void(*split_fn)(const char *, size_t, void *);
 
void split(const char *str, char sep, split_fn fun, void *data)
{
    unsigned int start = 0, i;
    for (i = 0; str[i]; i++) {
        if (str[i] == sep[i]) { //if finds any delimiter
            fun(str + start, i - start, data);
            start = i + 1;
        }
    }
    fun(str + start, stop - start, data);
}


#include <stdio.h>
 
#include <split.h>
 
void print(const char *str, size_t len, void *data)
{
    printf("%.*s\n", (int)len, str);
}
 
int main(void)
{
    char str[] = "first,second,third,fourth";
    split(str, ',', print, NULL);
    return 0;
}

For example, here’s how to add the tokens to a dynamic array:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include <split.h>
#include <dynarray.h>
 
void add_to_dynarray(const char *str, size_t len, void *data)
{
    dynarray *array = data;
    char *token = calloc(len + 1, 1);
    memcpy(token, str, len);
    dynarray_add_tail(array, token);
}
 
int main(void)
{
    char str[] = "first,second,third,fourth";
    dynarray *array = dynarray_create(0);
    split(str, ',', add_to_dynarray, array);
    dynarray_for_each(array, (dynarray_forfn)puts);
    dynarray_for_each(array, free);
    dynarray_delete(array);
    return 0;
}


*/


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
        printf("String %d = %s \n", i, *(pps + i));
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
        ppnew = (char **) calloc(*psize, sizeof(char **));
        return ppnew;
    }
    *psize += M10;
    ppnew = (char **) realloc(pps, *psize);
    for (int i = *psize - 1; i >= (*psize - M10); --i) {
        *(ppnew + i) = NULL;
    }
    return ppnew;
}

//other implementation of createDynArray
char** create_dyn_array_strings(char** ppstr, int *psize){

    if(ppstr==NULL){
       
        return calloc(10, sizeof(char*));// zera todas as posições a 0
        
    }
    
    return realloc(ppstr, (psize + 10) * sizeof(char));  // realoca e copia do anterior para o novo e faz o free
    
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
char *create_copy_dyn_string(char str[]) {
    char *t;
    t = (char *) malloc(sizeof(char) * strlen(str));
    strcpy(t, str);
    return t;
}

//char ** order_dynarray_strings(char *pps, int size)

//strcmp(*(pps+i),*(pps+j))<0 ou >0


