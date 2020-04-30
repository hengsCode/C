#include <stdio.h>
#include <stdlib.h>

char *numToMonth(int numMonth);

int main(int argc, char *argv[]) {
    int a, b, c, d, e, f, g, h, i, k, l, m, p, year;

    fprintf(stdout, "Enter Year: ");
    fscanf(stdin, "%d", &year);

    a = year % 19;
    b = year / 100;
    c = year % 100;
    d = b / 4;
    e = b % 4;
    f = (b + 8) / 25;
    g = (b - f + 1) / 3;
    h = (19 * a + b - d - g + 15) % 30;
    i = c / 4;
    k = c % 4;
    l = (32 + 2 * e + 2 * i - h - k) % 7;
    m = (a + 11 * h + 22 * l) / 451;
    int month = (h + l - 7 * m + 114) / 31;
    p = (h + l - 7 * m + 114) % 31;
    int date = p + 1;   

    char *wordMonth = malloc(sizeof(char));
    if (1 <= month <= 12) {
        wordMonth = numToMonth(month);
    }
    
    fprintf(stdout, "Easter is %s %d in %d.\n", wordMonth, date, year);

    return EXIT_SUCCESS;
}

char *numToMonth(int numMonth) {
    switch(numMonth) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";   
        default:
            return NULL;
    }
}