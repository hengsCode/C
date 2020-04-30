#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declarations
char *integerToWords(int num) {
    char *word = malloc(sizeof(char));
    char *numWord = malloc(sizeof(char));

    int tempNum = 0;
    if (num < 0) {
        tempNum = num;
        num = num * - 1;
        strcpy(word, "negative ");
    } 

    if (num == 0) {
        strcpy(numWord, "zero"); 
    } else if (num == 1) {
        strcpy(numWord, "one"); 
    } else if (num == 2) {
        strcpy(numWord, "two"); 
    } else if (num == 3) {
        strcpy(numWord, "three"); 
    } else if (num == 4) {
        strcpy(numWord, "four"); 
    } else if (num == 5) {
        strcpy(numWord, "five"); 
    } else if (num == 6) {
        strcpy(numWord, "six"); 
    } else if (num == 7) {
        strcpy(numWord, "seven"); 
    } else if (num == 8) {
        strcpy(numWord, "eight"); 
    } else if (num == 9) {
        strcpy(numWord, "nine"); 
    } else {
        strcpy(numWord, "ten"); 
    }

    if (tempNum) {
        numWord = strcat(word, numWord);
    }

    return numWord;
}


int main(int argc, char **argv) {
    fprintf(stdout, "Please enter two integers: ");
    int integer1, integer2, sum;

    int exists = fscanf(stdin, "%d %d", &integer1, &integer2);
    
    if (exists != 2) {
        fprintf(stderr, "Please enter two valid integers.\n");
        return EXIT_FAILURE;
    }

    sum = integer1 + integer2;

    if (integer1 > 10 || integer1 < -10) {
        fprintf(stdout, "%d + ", integer1);
    } else {
        char *word1 = integerToWords(integer1);
        fprintf(stdout, "%s + ", word1);
    }

    if (integer2 > 10 || integer2 < -10) {
        fprintf(stdout, "%d = ", integer2);
    } else {
        char *word2 = integerToWords(integer2);
        fprintf(stdout, "%s = ", word2);
    }

    if (sum > 10 || sum < -10) {
        fprintf(stdout, "%d\n", sum);
    } else {
        char *word3 = integerToWords(sum);
        fprintf(stdout, "%s\n", word3);
    }

    return EXIT_SUCCESS;

}