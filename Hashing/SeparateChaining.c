// Separate Chaining Hashing example

#include <stdio.h>
#include <stdlib.h>

// Struct definition for List
struct _node {
    int val;
    struct _node *next;
};

typedef struct _node *List;
typedef struct _node *Node;

Node createNode(int val) {
    Node new = malloc(sizeof(struct _node));
    new->val = val;
    new->next = NULL;
}

Node getLastNode(List L) {
    Node tmp = L;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    return tmp;
}

// Append to end of arraylist
void insertNode(Node n, List *L) {
    if (!(*L)) {
        *L = n;
        return;
    }
    Node tmp = *L;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = n;
}

// Struct definition for hashtable
struct HashTabRep {
    List *array;
    int nslots;
    int nitems;
};

typedef struct HashTabRep *HashTable;

int hash(int keyVal) {
    return keyVal % 11;
}

HashTable createHashTable(int numItems) {
    HashTable newTable = malloc(sizeof(struct HashTabRep));
    newTable->array = malloc(numItems * sizeof(List));
    // Initialise arraylist
    for (int n; n < numItems; n++) {
        newTable->array[n] = NULL;
    }
    newTable->nslots = numItems;
    newTable->nitems = 0;
}

void insertHashTable(HashTable hash_table, int value) {
    int hashcode = hash(value);
    hash_table->nitems++;
    insertNode(createNode(value), &hash_table->array[hashcode]);
}

void printList(List L) {
    Node tmp = L;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
}


int main(void) {
    int array[11] = {11, 16, 27, 35, 22, 20, 15, 24, 29, 19, 13};
    HashTable newTable = createHashTable(sizeof(array)/sizeof(int));
    for (int i = 0; i < sizeof(array)/sizeof(int); i++) {
        insertHashTable(newTable, array[i]);
    }

    for (int i = 0; i < newTable->nitems; i++) {
        if (newTable->array[i]) {
            printf("%d: ", i);
            printList(newTable->array[i]);
            printf("\n");
        }
    }
    for (int i = 0; i < newTable->nitems; i++) {
        if (newTable->array[i]) {
            printf("%d: ", i);
            printList(newTable->array[i]);
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}
