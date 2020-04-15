// Hashing
// Uses a hash function to map a given value with a particular key 
// we need: a set of key values, each key identifies one item
// an array to store items
// a hash function h(x): converts a given key type to a hashcode and to an int index
// note that there could be the same hashcode for unique key values (i.e. collision) so we need to use a collision resolution method
// e.g. double hashing, linear probing, separate chaining
// one benefit is that it removes the need for linear search which would be extremely inefficient if say the element was at the end of the array
// instead you can pass it through the hash function and grab the element using the hashcode instead 
// a collision resolution method (for similar values returned by the hash function)
// converts Key value to index value
// uses mod function to map hash value to index value
// spreads key values uniformly over address range


// Hash Functions
/*
int hash(Key key, int N) {
    int val = convert key to int
    return val % N;
}
*/
// For strings you could possible add the ascii codes for each character and then use the remainder when divided by a number
// Index Number = sum ASCII codes MOD size of array

// Simple hashing: no collisions
// Using struct definition:

typedef struct HashTabRep {
    int *array;
    int nslots;
    int nitems;
} HashTabRep;

typedef HashTabRep *HashTable;

#include <stdio.h>
#include <stdlib.h>

int hash(int keyValue, int sizeofArray) {
    return keyValue % sizeofArray;
}
// good idea to have NoItem values to replace empty slots
HashTable createHashTable(int sizeofArray) {
    HashTable newTable = malloc(sizeof(HashTabRep));
    newTable->array = malloc(sizeofArray * sizeof(int));
    for (int n = 0; n < sizeofArray; n++) {
        newTable->array[n] = -1;
    }
    newTable->nslots = sizeofArray;
    newTable->nitems = 0;
}

void insertHashElement(HashTable hash_table, int value) {
    int hashcode = hash(value, hash_table->nslots);
    hash_table->array[hashcode] = value;
    hash_table->nitems++;
}

int *searchHash(HashTable hash_table, int value) {
    int hashcode = hash(value, hash_table->nslots);
    return &hash_table->array[hashcode];
}

int main(int argc, char *argv[]) {
    int array[10] = {2, 3, 4, 1, 5, 6, 7, 8, 10, 9};
    int arraySize = sizeof(array)/sizeof(int);
    HashTable newTable = createHashTable(arraySize);
    for (int i = 0; i < arraySize; i++) {
        insertHashElement(newTable, array[i]);
    }

    printf("Slots (should be 11): %d, Items (should be 11): %d \n", newTable->nslots, newTable->nitems);

    for (int i = 0; i < newTable->nitems; i++) {
        printf("i: %d, hashtable[i]: %d\n", i, newTable->array[i]);
    }

    printf("Finding value 4: \n");

    int *found = searchHash(newTable, 4);

    printf("%d\n", *found);

    return EXIT_SUCCESS;
}


