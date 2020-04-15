// Stack ADT (LINKED LIST IMPLEMENTATION)
// Uses LIFO
// Whatever was added last is popped first

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Linked List struct definition

typedef struct _node {
    int val;
    struct _node *next;
} node;

typedef node *List;
typedef node *Node;
typedef node *Stack;

// Initialisation

List createList() {
    return NULL;
}

Node createNode(int val) {
    Node newNode = malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Insertion (on top of the stack so...prepending the list)

void insertNode(Node n, List *L) {
    if (!(*L)) { // if L is empty
        *L = n;
        return;
    }

    // adding to head of L
    n->next = *L;
    *L = n;
}

// Pop (top of stack so, deleting the head)
void freeNode(Node n) {
    free(n);
}

void popStack(List *L) {
    Node tmp = *L;
    *L = (*L)->next;
    freeNode(tmp);
}

// Last Node (first node of stack)

Node lastNode(List L) {
    Node last = L;
    while (last->next != NULL) {
        last = last->next;
    }
    return last;
}

// Print Stack

void printStack(List L) {
    Node tmp = L;
    int counter = 0;
    printf("TOP:\n");
    while (tmp != NULL) {
        printf("%d: %d\n", counter, tmp->val);
        tmp = tmp->next;
        counter++;
    }
}

bool isEmpty(List L) {
    if (L == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Main

int main() {
    Stack newStack = createList();
    int array[10] = {2, 3, 4, 1, 5, 6, 7, 8, 10, 9};
    int arraySize = sizeof(array) / sizeof(int);
    for (int n = 0; n < arraySize; n++) {
        insertNode(createNode(array[n]), &newStack);
    }

    printStack(newStack);
    popStack(&newStack);
    popStack(&newStack);
    popStack(&newStack);
    popStack(&newStack);
    popStack(&newStack);
    popStack(&newStack);
    popStack(&newStack);
    popStack(&newStack);
    popStack(&newStack);
    popStack(&newStack);
    printStack(newStack);
    
    if (isEmpty(newStack)) {
        printf("EMPTY\n");
    }

    return EXIT_SUCCESS;
}