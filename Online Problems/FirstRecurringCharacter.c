// First Recurring Character
// Assume that string contains only upper-case letters
// O(N) time 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(int c) { // O(1)
    return c % 26;
}

int firstRecurringChar(char *string) { // O(N)
    int *hashTable = malloc(sizeof(int) * 26);
    memset(hashTable, 0, 26);
    for (int c; string[c] != '\0'; c++) {
        int hashCode = hash(string[c]);
        if (hashTable[hashCode]) {
            return c; // return index of first recurring char
        } else {
            hashTable[hashCode]++;
        }
    }
    return -1;
}

int main(void) {
    char *string = "DACBEF";
    int index = firstRecurringChar(string);

    if (index != -1) {
        printf("%c is the first recurring character.\n", string[index]);
    } else {
        printf("No recurring characters.\n");
    }

    return EXIT_SUCCESS;
}