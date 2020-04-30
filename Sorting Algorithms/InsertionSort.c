// INSERTIONSORT.C

#include <stdio.h>
#include <stdlib.h>

// Sorts by inserting minimum elements to an "ordered" part of the array
// i.e. it sorts as it goes 
// the sorting algorithm goes as follows:
// while the element in consideration is less than the prior element:
// save the element and shift prior elements one index across until the while statement is not true
// exit loop and insert the element in consideration in the index where it is greater than the element in the previous index
void insertionSort(int *array, int sizeArray) {
    for (int i = 1; i < sizeArray; i++) {
        int j = i - 1;
        int tmp = array[i];
        // you do j >= 0 here because we want to also consider the initial index of the array 
        // if the element is still smaller than the first element
        // j would be -1, hence element will be inserted in array[-1 + 1] = array[0]
        while (tmp < array[j] && j >= 0) {
            array[j + 1] = array[j];
            j--;
        }
        // the element after the one being considered as j
        array[j + 1] = tmp;
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