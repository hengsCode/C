// Factorial.c
// C Program to find factorial of a number

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int factorial(int n) {
    return n > 0 ? n * factorial(n-1) : 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Enter a number in command line\n");
        exit(1);
    }
    int num = atoi(argv[1]);
    printf("Factorial of: %d is %d\n", num, factorial(num));
    return EXIT_SUCCESS;
}