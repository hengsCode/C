// swapNum.c
// Swap two numbers without using a third variable

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x, y;
    printf("Enter two numbers:\n");
    if (scanf("%d %d", &x, &y) == 2) {
        x = y + x;
        y = x - y;
        x = x - y;

        printf("%d %d\n", x, y);
    } else {
        fprintf(stderr, "Please enter 2 numebrs:\n");
        exit(1);
    }

    return EXIT_SUCCESS;
} 



