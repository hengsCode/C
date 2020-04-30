// Double Hashing
// Apply another hash function on top of the intial hash function on collision
// First hash function is generally: 
// hash1(key) = key % TABLE_SIZE;
// Second hash function:
// hash2(key) = PRIME - (key % PRIME);
// where prime is the last prime number less than TABLE_SIZE
// Can also be done using:
// (hash1(key) + i * hash2(key)) % TABLE_SIZE
// increment i every time there is a collision

// This program uses
// hash1(key) = key % TABLE_SIZE;
// hash2(key) = (key % 3) + 1;
// newhash = (original.hash1(key) + hash2(key) * increment) % TABLE_SIZE;

#include <stdio.h>
#include <stdlib.h>

int hash1(int val) {
    return val % 11;
}

int hash2(int val) {
    return (val % 3) + 1;
}

// Struct definition for hashtable

typedef struct HashTabRep {
    int *array;
    int nitems;
    int nslots;
} HashTabRep;

typedef HashTabRep *HashTable;

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
    int hashcode = hash1(val);
    int updatedHashCode = hashcode;
    int increment = 0;
    while (table->array[updatedHashCode] != -1) {
        increment++;
        updatedHashCode = (hashcode + increment * hash2(val)) % 11;
    }
    table->array[updatedHashCode] = val;
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