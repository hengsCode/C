// Binary Search Trees ADT 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Struct definition of a BST 
// Consists of nodes that can have linking leaf nodes

struct _node {
    int data;
    struct _node *left;
    struct _node *right;
};

// Redefinitions

typedef struct _node Node;
typedef struct _node *BSTree;
typedef BSTree BSTNode;

// Initialisation

BSTree newBSTree() {
    return NULL;
}

BSTNode newNode(int data) {
    BSTNode new = malloc(sizeof(Node));
    if (new == NULL) {
        fprintf(stderr, "Unable to allocate memory to node.\n");
        exit(1);
    }

    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

BSTree insertNode(BSTNode n, BSTree T) {
    if (T == NULL) {
        T = n;
    } else if (n->data > T->data) {
        T->right = insertNode(n, T->right);
    } else if (n->data < T->data) {
        T->left = insertNode(n, T->left);
    }
    return T;
}

// prefixTraversal
void prefixTraversal(BSTree T) {
    if (T != NULL) {
        printf("%d ", T->data);
        prefixTraversal(T->left);
        prefixTraversal(T->right);
    }
}

int numNodes(BSTree T) {
    if (T == NULL) {
        return 0;
    } else {
        return (1 + numNodes(T->left) + numNodes(T->right));
    }
}

// Using ternary operator
int depth(BSTree T) {
    if (T == NULL) {
        return 0;
    } else {
        int L = depth(T->left) + 1;
        int R = depth(T->right) + 1;
        return (L < R) ? R:L;
    }
}

BSTNode findNode(BSTree T, int target) {
    if (target > T->data) {
        return findNode(T->right, target);
    } else if (target < T->data) {
        return findNode(T->left, target);
    } else {
        return T;
    }
}

int main(int argc, char *argv[]) {
    BSTree newTree = newBSTree();
    int array[10] = {2, 3, 4, 1, 5, 10, 7, 8, 9, 2};
    for (int i = 0; i < 10; i++) {
        newTree = insertNode(newNode(array[i]), newTree);
    }

    printf("Prefix Traversal: \n");
    prefixTraversal(newTree);

    BSTNode testNode = findNode(newTree, 10);
    assert(testNode->data == 10);

    int nNodes = numNodes(newTree);
    assert(nNodes == 9);

    int treeDepth = depth(newTree);

    printf("\nTree Depth: %d\n", treeDepth);

    return EXIT_SUCCESS;
}



