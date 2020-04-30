#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int integer1, integer2;
    fprintf(stdout, "Please enter two integers: ");
    int exists;
    exists = fscanf(stdin, "%d %d", &integer1, &integer2);

    if (exists != 2) {
        fprintf(stderr, "Pleas enter two integers.\n");
        return EXIT_FAILURE;
    }

    int sum = integer1 + integer2;

    fprintf(stdout, "%d + %d = %d", integer1, integer2, sum);

    return EXIT_SUCCESS;
}