#include <stdio.h>
#include <stdlib.h>

// insert number dynamically (until a non number is entered)

int *sortArray(int *array);

int main(int argc, char *argv[]) {

    int number;
    int *array;
    for (int i = 0; i < 3; i++) {
        fscanf(stdin, "%d", &number);
        array[i] = number;
    }

    for (int i = 0; i < 3; i++) {
        fprintf(stdout, "%d\n", array[i]);
    }
    
    return EXIT_SUCCESS;
}

int *sortArray(int *array) {
    int max;
    for (int i = 0; i < 3; i++) {
        max = array[0];
    }
}