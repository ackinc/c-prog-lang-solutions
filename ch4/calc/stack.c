#include <stdio.h>

#define STACK_SIZE 100

double stack[STACK_SIZE];
int p = 0; // next free index in stack

void push(double val) {
    if (p < STACK_SIZE)
        stack[p++] = val;
    else
        printf("PUSH error -- stack is full\n");
}

double pop() {
    if (p > 0)
        return stack[--p];
    else {
        printf("POP error -- stack is empty\n");
        return 0;
    }
}

double peek() {
    if (p > 0)
        return stack[p - 1];
    else {
        printf("PEEK error -- stack is empty\n");
        return 0;
    }
}

void duplicate() {
    if (p > 0)
        push(peek());
    else
        printf("DUPLICATE error -- stack is empty\n");
}

void swap() {
    if (p < 2)
        printf("SWAP error -- stack has fewer than two elements\n");
    else {
        double tmp1 = pop(), tmp2 = pop();
        push(tmp1), push(tmp2);
    }
}

void clear() { p = 0; }
