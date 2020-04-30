// Queue Linked List Implementation

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