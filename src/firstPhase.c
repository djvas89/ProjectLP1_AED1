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
    char **sentencesM = NULL; //put the sentences matrix at NULL
    char **wordsM = NULL; //put the words matrix at NULL
    char **bagofwordsM = NULL; //put the bagofwords matrix at NULL
    char **map = NULL; //put the sentences matrix at NULL
    int size = 0;
    ppnomes = create_dynarray_strings(ppnomes, &size);
    int size = 0, index = 0;


    showmenuPh1();
    selectMenu();


    return 0;
}

/**
 * @brief It displays a Menu
 */
void showmenuPh1() {

    printf("=================================\n");
    printf(" Menu LP1 & AED1\n");
    printf("=================================\n");
    printf("1.Insert to Matrix\n");

    printf("0.Exit\n");

}

void selectMenu() {
    int val, pos, ch;
    char yes = 'y';
    while (yes == 'y') {
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insertIntoMatrix();
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 0:
                exit(0);

            default:
                "Invalid choice";

        }
        printf("Continue? Type: y/n:\n");
        scanf("%s", &yes);
    }
}


/**
 * @brief Creates a sentences Matrix
 */
void insertIntoMatrix() {
    char **ppnomes = NULL; //put the ppnomes at NULL
    int size = 0;
    ppnomes = create_dynarray_strings(ppnomes, &size);
    int size = 0, index = 0;

    char input[M200] = "";
    printf("Input a string, (Finish with '.'):\n");
    do {
        fgets(input, M200, stdin);
        if (strcmp(input, ".\n") == 0)
            break;
        insert_string_dynarray_strings(ppnomes, &size, input, &index);
        index++;
        if (index == (size - 1)) {
            create_dynarray_strings(ppnomes, &size);
            index++;
        }
    } while (1);
    print_dynarray_strings(index, ppnomes);
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
        printf("String on Array num [ %d ] = %s \n", i, *(pps + i));
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
 * @param *i - pointer to i which indicates the index
 * @return pps - the new dyn array fully inserted
 */
void insert_string_dynarray_strings(char **pps, int *psize, char s[], int *i) {
    if (*i >= *psize) create_dynarray_strings(pps, psize);
    *(pps + ((*i)++)) = create_copy_dyn_string(s);
}

/**
 * @brief it creates a copy of the dynamic string
 * @param str - receives a static array of char
 * @return t - the new dynamic array of char
 */
char *create_copy_dyn_string(char *str) {
    char *t;
    t = (char *) malloc(sizeof(char) * strlen(str));
    strcpy(t, str);
    return t;
}


