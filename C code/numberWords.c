#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    fprintf(stdout, "Please enter an integer: ");
    int numberEntered;
    int exists;

    exists = fscanf(stdin, "%d", &numberEntered);

    if (exists != 1) {
        fprintf(stderr, "Please enter a number.\n");
        return EXIT_FAILURE;
    }

    if (numberEntered < 1) {
        fprintf(stdout, "You entered a number less than one.\n");
    } else if (numberEntered > 5) {
        fprintf(stdout, "You entered a number greater than five.\n");
    } else {
// switch statements only work for equivalence expressions not for inequalities
        switch (numberEntered) {
            case 1:
                fprintf(stdout, "You entered one.\n");
                break;
            case 2:
                fprintf(stdout, "You entered two.\n");
                break;
            case 3:
                fprintf(stdout, "You entered three.\n");
                break;
            case 4:
                fprintf(stdout, "You entered four.\n");
                break;
            case 5:
                fprintf(stdout, "You entered five.\n");
                break;
            default:
                fprintf(stderr, "You should not have reached here!\n");
        }
    }

    return EXIT_SUCCESS;
}