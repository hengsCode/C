#include <stdio.h>
#include <stdlib.h>


int *orderedArray(int *unorderedArray, int size);

int main(int argc, char *argv[]) {
    fprintf(stdout, "Please enter numbers here: ");

    int number;
    int *unorderedArray = malloc(sizeof(int));
    int length;
    int exists = fscanf(stdin, "%d", &number);

    for (length = 0; exists; length++) {
        unorderedArray[length] = number;
        exists = fscanf(stdin, "%d", &number);
    }

    int *ordered = orderedArray(unorderedArray, length + 1);

    for (int i = 0; i < length; i++) {
        fprintf(stdout, "Array[%d] = %d\n", i, unorderedArray[i]);
    }

    return EXIT_SUCCESS;
}

int *orderedArray(int *unorderedArray, int size) {
    int *ordered;
    memset(ordered, 0, size);
    for (int i = 0; i < size - 1; i++) {
        
    }
}