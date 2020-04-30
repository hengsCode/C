#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int listCount;

    fprintf(stdout, "Enter size of list: ");
    fscanf(stdin, "%d", &listCount);

    for (int number = 1; number < listCount; number++) {
        if (!(number % 3) || !(number % 5)) {
            fprintf(stdout, "%d\n", number);
        }
    }

    return EXIT_SUCCESS;
}