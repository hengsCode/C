// Tells the compiler to insert contents of stio.h header file for standard input and ouput
// Allows the use of standard input/output functions
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int numRead;
    int exists;
    // fscanf returns the number of input items succesfully matched
    // else it would return 0 in the event of an early matching failure
    exists = fscanf(stdin, "%d", &numRead);
    if (exists != 1) {
        fprintf(stderr, "Enter a number please\n");
        return EXIT_FAILURE;
    }

    if (numRead > 0) {
        fprintf(stdout, "You have entered a positive number.\n");
    } else if (numRead == 0) {
        fprintf(stdout, "You have entered zero.\n");
    } else if (numRead < 0) {
        fprintf(stdout, "Don't be so negative!\n");
    }
    
    return EXIT_SUCCESS;
}