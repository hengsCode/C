#include <stdio.h>
#include <stdlib.h>

// We'll work with binarySort

// BinarySearch to find the index which val belongs in the ordered part of the array 
int binarySearch(int lo, int hi, int val, int *array);
void insertionSort(int *array, int arraySize);

int main(int argc, char *argv[]) {

    int value;
    int index;
    int arraySize;

    fprintf(stdout, "Enter array size: ");
    fscanf(stdin, "%d", &arraySize);

    int array[arraySize];
    // use this instead:

    //int *array = malloc(sizeof(int) * arraySize);

    for (index = 0; index < arraySize; index++) {
        fscanf(stdin, "%d", &value);
        array[index] = value;
    }

    insertionSort(array, arraySize);
    
    for (index = 0; index < arraySize; index++) {
        fprintf(stdout, "%d ", array[index]);
    }

    fprintf(stdout, "\n");
    
    return EXIT_SUCCESS;
} 

// lo is the starting index of ordered partition
// hi is the end index of ordered partition
// val is the value that is to be inserted

int binarySearch(int lo, int hi, int val, int *array) {

    if (hi <= lo) {
        return ((val > array[lo]) ? lo + 1 : lo);
    }

    int middle = (hi + lo) / 2;
    if (val > array[middle]) {
        return binarySearch(middle + 1, hi, val, array);
    } else if (val < array[middle]) {
        return binarySearch(lo, middle - 1, val, array);
    } else {
        // do middle + 1 instead of middle to reduce the number of shifts later on (this is like saying you insert duplicates after each other)
        return middle + 1; 
    }
}

// Sort using insertion sort O(n^2)

void insertionSort(int *array, int arraySize) {

    int tempValue;
    int initIndex;
    int secIndex;
    int position;
    
    // First loop to iterate through the array once (can assume that array[0] is already in order)
    for (initIndex = 1; initIndex < arraySize; initIndex++) {
        // Save value to tempValue
        tempValue = array[initIndex];
        // Find the position of value in ordered partition
        position = binarySearch(0, initIndex - 1, tempValue, array);
        // Second loop to shift elements across 
        for (secIndex = initIndex; secIndex > position; secIndex--) {
            array[secIndex] = array[secIndex - 1];
        }
        // Swap array[position] value with the tempValue so it is in the correct order
        array[position] = tempValue;
    }
}
