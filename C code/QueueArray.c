// QUEUE (ARRAY)

#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 50

// STRUCT DEFINITION FOR QUEUE
typedef struct Queue {
    int next; 
    int last;
    int nitems;
    int *queue;
} Queue;

// Create new Queue

Queue *newQueue() {
    Queue *newQ = malloc(sizeof(Queue));
    newQ->next = -1;
    newQ->last = -1;
    newQ->nitems = 0;
    newQ->queue = malloc(MAX_ITEMS * sizeof(int));
    return newQ;
}

// Enqueue

void enqueue(int val, Queue *q) {
    if (!q->nitems) {
        q->next++;
        q->last++;
        q->nitems++;
        q->queue[q->next] = val;
        return;
    }
    q->last++;
    q->nitems++;
    q->queue[q->last] = val;
}

// Dequeue

void dequeue(Queue *q) {
    for (int i = 1; i <= q->last; i++) {
        q->queue[i - 1] = q->queue[i];
    }
    q->last--;
    q->nitems--;
}

// Display Queue

void displayQueue(Queue *q) {
    for (int i = q->next; i <= q->last; i++) {
        printf("%d: %d\n", i, q->queue[i]);
    }
}


// Main

int main() {
    Queue *newQ = newQueue();
    int array[10] = {2, 3, 4, 1, 5, 6, 7, 8, 10, 9};
    int arraySize = sizeof(array) / sizeof(int);
    for (int n = 0; n < arraySize; n++) {
        enqueue(array[n], newQ);
    }

    displayQueue(newQ);

    printf("Dequeueing...\n");

    dequeue(newQ);

    displayQueue(newQ);

    return EXIT_SUCCESS;
}