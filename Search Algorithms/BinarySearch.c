// Binary Search
#include <stdio.h>
#include <stdlib.h>

// return the index 
int binarySearch(int val, int *array, int lo, int hi) {
    // Get midpoint of array
    int mid = (lo + hi) / 2;
    
    // Check if mid is the val
    if (array[mid] == val) {
        return mid;
    }
    // In an ordered array (ascending), we rlly only need to check one side of the array split at the midpoint
    // Check right side
    if (val > array[mid]) {
        return binarySearch(val, array, mid + 1, hi);
    } else {
        return binarySearch(val, array, lo, mid - 1);
    }
} 


int main(void) {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int lo = 0, hi = 9;

    printf("%d\n", binarySearch(4, array, lo, hi));

    return EXIT_SUCCESS;
}