// Binary Insertion Sort
/* Recall the insertion sort algorithm:
1. Traverse through array and insert elements into the ordered 'side' of the array 
2. Shift elements across one then insert the element in the correct position
*/
// We can use binary search to find where the element goes 

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int val, int *array, int lo, int hi) {

    // when hi is less or equal 0
    if (hi <= lo) {
        return (val > array[lo]) ? (lo + 1) : lo;
    }
    int mid = (lo + hi)/2;

    if (val == array[mid]) {
        return mid + 1;
    }

    if (val > array[mid]) {
        return binarySearch(val, array, mid + 1, hi);
    } else {
        return binarySearch(val, array, lo, mid - 1);
    }
}

void insertionSort(int *array, int arraySize) {
    // assume i = 0 is in the correct position
    int lo = 0;

    for (int i = 1; i < arraySize; i++) {
        int value = array[i];
        int index = binarySearch(value, array, lo, i - 1);
        for (int j = i - 1; j >= index; j--) {
            array[j + 1] = array[j];
        }
        array[index] = value;
    }
}

int main(int argc, char *argv[]) {
    int array[10] = {2, 3, 4, 1, 5, 10, 7, 8, 9, 2};
    int sizeArray = sizeof(array)/sizeof(int);
    insertionSort(array, sizeArray);

    for (int i = 0; i < sizeArray; i++) {
        printf("%d\n", array[i]);
    }

    return EXIT_SUCCESS;
}