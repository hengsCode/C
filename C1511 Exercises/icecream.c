#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int numScoops;
    int dollarPerScoop;

    int exists;

    fprintf(stdout, "How many scoops? ");
    exists = fscanf(stdin, "%d", &numScoops);
    if (exists != 1) {
        fprintf(stderr, "Please enter valid number of scoops.\n");
        return EXIT_FAILURE;
    }
    
    fprintf(stdout, "How much per scoop? ");
    exists = fscanf(stdin, "%d", &dollarPerScoop);
    if (exists != 1) {
        fprintf(stderr, "Please enter a valid dollar number.\n");
        return EXIT_FAILURE;
    }

    int amount = 10;
    int required = numScoops * dollarPerScoop;

    if (amount >= required) {
        fprintf(stdout, "You have enough money!\n");
    } else {
        fprintf(stdout, "Oh no, you don't have enough money :(\n");
    }

    return EXIT_SUCCESS;
}