#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int yourAge;
    fprintf(stdout, "Enter your age: ");
    int exists;
    exists = fscanf(stdin, "%d", &yourAge);
    if (exists != 1 || yourAge <= 0) {
        fprintf(stderr, "Please enter an age between 1-99");
        return EXIT_FAILURE;
    }

    if (yourAge <= 12) {
        fprintf(stdout, "You are too young to be dating.\n");
        return EXIT_SUCCESS;
    }

    int upperRange = (yourAge - 7) * 2;
    int lowerRange = yourAge / 2 + 7;

    fprintf(stdout, "Your dating range is %d to %d years old.\n", lowerRange, upperRange);
    
    return EXIT_SUCCESS;
}