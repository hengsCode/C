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

// Goes through array 
void bubbleSort(int *array, int sizeArray) {
    // sizeArray - 1 since we need to consider only until the second last index
    // if considering the last index, array[j + 1] won't exist
    for (int i = 0; i < sizeArray - 1; i++) {
        // we do sizeArray - i - 1 since bubbleSort brings the largest element of the array to the end
        // so we needn't have to consider the last swapped element at the end
        for (int j = 0; j < sizeArray - i - 1; j++) {
            // Perform swap if the prior element is greater than the next element
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

// TEST
int main(int argc, char *argv[]) {
    int array[10] = {2, 3, 4, 1, 5, 10, 7, 8, 9, 2};
    int sizeArray = sizeof(array)/sizeof(int);
    printf("%d\n", sizeArray);
    bubbleSort(array, sizeArray);
    for (int i = 0; i < sizeArray; i++) {
        printf("%d\n", array[i]);
    }
    return EXIT_SUCCESS;
}