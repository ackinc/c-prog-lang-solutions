#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // atof
#include <string.h>

#include "calc.h"

#define MAX_INPUT_SIZE 100

bool isFunction(char s[]) {
    return !strcmp(s, "sin") || !strcmp(s, "cos") || !strcmp(s, "tan") ||
           !strcmp(s, "atan2") || !strcmp(s, "exp") || !strcmp(s, "pow");
}

double applyFunction(char s[]) {
    double x, y, result;
    if (strcmp(s, "sin") == 0)
        result = sin(pop());
    else if (strcmp(s, "cos") == 0)
        result = cos(pop());
    else if (strcmp(s, "tan") == 0)
        result = tan(pop());
    else if (strcmp(s, "atan2") == 0) {
        y = pop();
        x = pop();
        result = atan2(x, y);
    } else if (strcmp(s, "exp") == 0)
        result = exp(pop());
    else if (strcmp(s, "pow") == 0) {
        y = pop();
        x = pop();
        result = pow(x, y);
    }

    return result;
}

void main() {
    char s[MAX_INPUT_SIZE];
    int type;
    double operand2;

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case STRING:
            if (!strcmp(s, VAR_LAST_PRINTED)) {
                push(getLastPrintedVal());
            } else if (isFunction(s)) {
                push(applyFunction(s));
            } else if (isset(s[0])) {
                push(getvar(s[0]));
            } else {
                setvar(s[0], peek());
            }
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            operand2 = pop();
            push(pop() - operand2);
            break;
        case '/':
            operand2 = pop();
            if (!operand2)
                printf("Div by 0 error\n");
            else
                push(pop() / operand2);
            break;
        case '%':
            operand2 = pop();
            if (!operand2)
                printf("Div by 0 error\n");
            else
                push((int)pop() % (int)operand2);
            break;
        case '\n':
            printVal(pop());
            break;
        default:
            printf("MAIN -- unknown input %s\n", s);
            break;
        }
    }
}
