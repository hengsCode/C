// Stack (ARRAY IMPLEMENTATION)

#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS (50)

// STRUCT DEFINITION FOR STACK

typedef struct Stack {
    int top; // index of top element
    int nitems;
    int *stack;
} Stack;

// Create stack

Stack *createStack() {
    Stack *newStack = malloc(sizeof(Stack));
    newStack->stack = malloc(sizeof(int) * MAX_ITEMS);
    newStack->nitems = 0;
    newStack->top = -1;
    return newStack;
}

// Push

void push(int val, Stack *stack) {
    stack->nitems++;
    stack->top++;
    stack->stack[stack->top] = val;
}

// Pop

void pop(Stack *stack) {
    stack->nitems--;
    stack->top--;
}

// Print stack

void displayStack(Stack *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d: %d\n", (stack->top - i), stack->stack[i]);
    }
}


// Main

int main() {
    Stack *newStack = createStack();
    int array[10] = {2, 3, 4, 1, 5, 6, 7, 8, 10, 9};
    int arraySize = sizeof(array) / sizeof(int);
    for (int n = 0; n < arraySize; n++) {
        push(array[n], newStack);
    }

    printf("%d\n", newStack->nitems);
    printf("%d\n", newStack->top);
    displayStack(newStack);

    printf("Popping Stack\n");
    pop(newStack);
    printf("%d\n", newStack->nitems);
    printf("%d\n", newStack->top);
    displayStack(newStack);
    return EXIT_SUCCESS;
}