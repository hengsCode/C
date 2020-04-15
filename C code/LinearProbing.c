// Linear Probing
// Searches for the next empty slot
// Else it goes back to the beginning of the table/array

#include <stdio.h>
#include <stdlib.h>

// struct definition for hashtable
typedef struct HashTabRep {
    int *array;
    int nitems;
    int nslots;
} HashTabRep;

typedef HashTabRep *HashTable;

int hash(int val) {
    return val % 11;
}

HashTable createHashTable(int arraySize) {
    HashTable newTable = malloc(sizeof(HashTabRep));
    newTable->array = malloc(arraySize * sizeof(int));
    for (int n = 0; n < arraySize; n++) {
        newTable->array[n] = -1;
    }
    newTable->nitems = 0;
    newTable->nslots = arraySize;

    return newTable;
}

void insertHashTable(int val, HashTable table) {
    int hashcode = hash(val);
    int counter = hashcode;
    while (table->array[counter] != -1) {
        counter++;
    }

    table->array[counter] = val;
    table->nitems++;
}

int main(int argc, char *argv[]) {
    int array[11] = {11, 16, 27, 35, 22, 20, 15, 24, 29, 19, 13};
    HashTable newTable = createHashTable(sizeof(array)/sizeof(int));
    for (int i = 0; i < sizeof(array)/sizeof(int); i++) {
        insertHashTable(array[i], newTable);
    }

    for (int i = 0; i < newTable->nitems; i++) {
        printf("%d: %d\n", i, newTable->array[i]);
    }

    return EXIT_SUCCESS;
}