// BubbleSort.c
// HENRY FANG
// Swaps pairs of elements 

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int *array, int sizeArray) {
    for (int i = 0; i < sizeArray; i++) {
        for (int j = 0; j < sizeArray; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int array[10] = {2, 3, 4, 1, 5, 7, 8, 9, 2, 10};
    int sizeArray = sizeof(array)/sizeof(int);
    bubbleSort(array, sizeArray);
    for (int i = 0; i < sizeArray; i++) {
        printf("%d\n", array[i]);
    }
    return EXIT_SUCCESS;
}