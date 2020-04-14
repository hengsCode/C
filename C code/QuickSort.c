// Implementation of QuickSort
// HENRY FANG
// Essentially, we choose a pivot point (can be first, last, middle or random, usually you want to choose the median)
// Using the pivot, sort elements less than that pivot on the left and those greater than pivot on the right

#include <stdio.h>
#include <stdlib.h>

// Returns sorted array (uses last element as pivot)
// Recursion function that partitions the array initially
// then partitions the left side then the right side of the chosen pivot recursively (this continues until startingIndex == lastIndex)
// i.e. the pivot is the startingIndex 
// upon backtracking, the array will then be sorted
void quickSort(int *array, int startingIndex, int lastIndex);

// Returns the pivot index
// Takes startingIndex and index of chosen pivot
// Goes through the array and sorts all elements left of the pivot (last element)
// It has two indexes: a sortedArrayIndex which keeps track of the index of the last element sorted and the arrayIndex
// which is used to iterate through the array
// For each element array[arrayIndex] that is less than pivot, it is swapped with array[sortedArrayIndex]
// so that the smaller elements are placed on the far left of the array 
// This continues until arrayIndex reaches the pivotIndex (the last element) 
// The array will then be sorted such that all the elements smaller than the pivot will be on the far left while the ones greater are on
// the far right (but still before the pivot)
// Finally, the array[pivotIndex] is swapped with the array[sortedArrayIndex + 1] which puts the pivot in the correct spot
// i.e. now all elements on the left of the pivot are smaller and all elements on the right are larger
// partition then returns the correct index of the pivot (sortedArrayIndex + 1)
int partition(int *array, int startingIndex, int pivotIndex);

// Swaps elements a and b 
void swap(int *a, int *b);


// TEST
int main(int argc, char *argv[]) {
    int array[6] = {3, 5, 2, 1, 4, 3};
    quickSort(array, 0, 5);
    for (int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}

void quickSort(int *array, int startingIndex, int lastIndex) {
    // sets pivot in the correct spot 
    // need to make sure that startingIndex < lastIndex 
    // since startingIndex and lastIndex may be the same index (i.e. only 1 element)
    if (startingIndex < lastIndex) {
        int pivot = partition(array, startingIndex, lastIndex);
        quickSort(array, startingIndex, pivot - 1);
        quickSort(array, pivot + 1, lastIndex);
    }
}

int partition(int *array, int startingIndex, int pivotIndex) {
    int pivot = array[pivotIndex];

    int sortedArrayIndex = startingIndex - 1;
    int arrayIndex;

    for (arrayIndex = startingIndex; arrayIndex < pivotIndex; arrayIndex++) {
        if (array[arrayIndex] <= pivot) {
            sortedArrayIndex++;
            swap(&array[arrayIndex], &array[sortedArrayIndex]);
        }
    }

    swap(&array[pivotIndex], &array[sortedArrayIndex + 1]);

    return sortedArrayIndex + 1;
}

void swap(int *a, int *b) {
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
} 
