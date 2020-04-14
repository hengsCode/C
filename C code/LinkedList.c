// Linked List ADT
// HENRY FANG
#include <stdio.h>
#include <stdlib.h>

// struct (structure) is a data type that can hold
// data items of different kinds (types)
// typedef (type redefinition)
typedef struct _nodeList {
    int val;
    struct _nodeList *next;
} *node;

typedef node List;

// Creating a new List (return NULL)
List newList() {
    return NULL;
}

// Creating a new node 
node newNode(int val) {
    node n = malloc(sizeof(struct _nodeList));
    n->val = val;
    n->next = NULL;

    return n;
}

// Returns the last node of list
node lastNode(List L) {
    node last = L;
    while (last->next != NULL) {
        last = last->next;
    }
    return last;
}

// Appends to end of list
List appendList(node n, List L) {
    if (L == NULL) {
        return n;
    }
    node last = lastNode(L);
    last->next = n;
    return L;
}

// Appends to beginning of list 
List prependList(node n, List L) {
    if (L == NULL) {
        return n;
    }

    n->next = L;
    return n;
}

// Search for node given value (iterative)
node findNode(int target, List L) {
    node tmp = L;

    while (tmp != NULL && tmp->val != target) {
        tmp = tmp->next;
    }
    // see if you can return NULL here 
    return tmp;
}

// Search for node given value (recursive)
node findNodeR(int target, List L) {
    if (L == NULL) {
        return NULL;
    } else if (L->val == target) {
        return L;
    }
    return findNodeR(target, L->next);
}

// Free node
// Note free contents always (those with memory)
void freeNode(node n) {
    free(n);
}

// Popping a List (removing first item)
void popList(List *L) {
    if (*L == NULL) {
        return;
    }
    node tmp = *L;
    *L = (*L)->next;
    // Note that you should free contents of list 
    freeNode(tmp);
}

// Removing last node
void removeLast(List *L) {
    // If no items
    if ((*L) == NULL) {
        return;
    }
    // If only one item
    if ((*L)->next == NULL) {
        freeNode((*L));
    }
    // need to grab second last
    node tmp = (*L);
    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    node last = tmp->next->next;
    tmp->next = NULL;
    freeNode(last);
}

// Removing specific node
// Recursive
void removeSpecific(int target, List *L) {
    if (!findNodeR(target, *L)) {
        return;
    }
    // need to get node before target node
    node tmp = *L;
    
    // no need to check for null since we know that it exists in the list
    while (tmp->next->val != target) {
        tmp = tmp->next;
    }
    node targetNode = tmp->next;
    node before = tmp;
    node newNext = tmp->next->next;
    freeNode(targetNode);
    before->next = newNext;
}

// Reversing a List
List reverseList(List L) {
    if (L == NULL) { // no elements
        return NULL;
    } else if (L->next == NULL) { // one element
        return L;
    }
    // more than one element
    List reversedList = newList();
    node tmp = L;
    while (tmp != NULL) {
        reversedList = prependList(newNode(tmp->val), reversedList);
        tmp = tmp->next;
    }    
    return reversedList;
}

// Insert into ordered list
List addToOrderedList(node n, List L_ordered) {
    if (L_ordered == NULL) {
        return n;
    }
    int value = n->val;
    node tmp = lastNode(L_ordered);

    if (value >= tmp->val) {
        return appendList(n, L_ordered);
    } else if (value <= L_ordered->val) {
        return prependList(n, L_ordered);
    }

    tmp = L_ordered;
   
    while (value >= tmp->next->val) {
        tmp = tmp->next;
    }

    n->next = tmp->next;
    tmp->next = n;

    return L_ordered;
}

// Display elements of list 
void printList(List list) {
    node tmp = list;

    while (tmp != NULL) {
        printf("%d -> ", tmp->val);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

// Display node
void printNode(node n) {
    printf("node with value: %d\n", n->val);
}


// TEST
int main(int argc, char *argv[]) {
    
    printf("Creating a new list with two nodes:\n");
    List newL = newList();
    newL = appendList(newNode(2), newL);
    newL = appendList(newNode(3), newL);
    printList(newL);

    printf("Joining two lists:\n");
    List newL2 = newList();
    newL2 = appendList(newNode(1), newL2);
    newL2 = appendList(newNode(2), newL2);
    printf("Joining...\n");
    appendList(newL2, newL);
    printList(newL);

    printf("Reversing List:\n");
    printList(newL);
    printList(reverseList(newL));

    printf("Removing last node:\n");
    printList(newL);
    removeLast(&newL);
    printList(newL);

    printf("Removing specific node:\n");
    printList(newL);
    removeSpecific(3, &newL);
    printList(newL);

    printf("Removing first node:\n");
    printList(newL);
    popList(&newL);
    printList(newL);

    printf("Creating an ordered list:\n");
    List orderedL = newList();
    orderedL = appendList(newNode(1), orderedL);
    orderedL = appendList(newNode(2), orderedL);
    orderedL = appendList(newNode(3), orderedL);
    orderedL = appendList(newNode(5), orderedL);
    orderedL = appendList(newNode(6), orderedL);
    printList(orderedL);
    orderedL = addToOrderedList(newNode(4), orderedL);
    orderedL = addToOrderedList(newNode(3), orderedL);
    orderedL = addToOrderedList(newNode(4), orderedL);
    orderedL = addToOrderedList(newNode(6), orderedL);
    orderedL = addToOrderedList(newNode(-1), orderedL);
    printList(orderedL);

    printf("Find specific node:\n");
    printNode(findNode(6, orderedL));
    printNode(findNodeR(-1, orderedL));
    printNode(findNodeR(5, orderedL));
    

    return EXIT_SUCCESS;
}