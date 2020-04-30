// SelectionSort.c

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// sorts by finding minimum element and inserting it to the beginning
// one loop to loop through sorted array (i)
// another loop to find minimum element of unsorted array (j)
// Loop through array and look for minimum element in Array[i...sizeArray - 1] to replace with array[i]
// Loop through array at j = i + 1 to find minimum element in unsorted array and then perform swap with array[i]
// increment i so that Array[0] is sorted and now we find a minimum element in the unsorted array to swap with Array[1]

void selectionSort(int *array, int sizeArray) {
    for (int i = 0; i < sizeArray - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < sizeArray; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        if (i != min_index) {
            swap(&array[min_index], &array[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    int array[10] = {2, 3, 4, 1, 5, 10, 7, 8, 9, 2};
    int sizeArray = sizeof(array)/sizeof(int);
    selectionSort(array, sizeArray);
    for (int i = 0; i < sizeArray; i++) {
        printf("%d\n", array[i]);
    }
    return EXIT_SUCCESS;
}