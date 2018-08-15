#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define ALPHABET_SIZE 26

double vars[ALPHABET_SIZE];
double last_printed_val;

double getvar(char var) {
    if (islower(var)) {
        return vars[var - 'a'];
    } else {
        printf("GETVAR error -- bad var %c\n", var);
        return 0;
    }
}

bool isset(char var) {
    if (islower(var))
        return vars[var - 'a'] != 0;
    else
        printf("ISSET error -- bad var %c\n", var);
}

void setvar(char var, double val) {
    if (islower(var))
        vars[var - 'a'] = val;
    else
        printf("SETVAR error -- bad var %c\n", var);
}

void printVal(double val) {
    last_printed_val = val;
    printf("%f\n", val);
}

double getLastPrintedVal() { return last_printed_val; }
