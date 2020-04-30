#include <stdio.h>
#include <stdlib.h>

// a number is perfect if 
// sumFactors(number) / 2 = number

int main(int argc, char *argv[]) {
    int number;

    fprintf(stdout, "Enter a number: ");
    fscanf(stdin, "%d", &number);

    fprintf(stdout, "Factors of %d are: \n", number);

    int sumFactors = 0;

    for (int element = 1; element <= number; element++) {
        if (!(number % element)) {
            sumFactors += element;
            fprintf(stdout, "%d\n", element);
        }
    }

    fprintf(stdout, "Sum of factors: %d\n", sumFactors);

    if (sumFactors / 2 == number) {
        fprintf(stdout, "%d is a perfect number.\n", number);
    } else {
        fprintf(stdout, "%d is not a perfect number.\n", number);
    }

    return EXIT_SUCCESS;
}