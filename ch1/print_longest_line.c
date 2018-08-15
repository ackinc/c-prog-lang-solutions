#include <stdio.h>

#define MAX_LINE_LEN 1000

int min(int a, int b) { return (a < b ? a : b); }

int getLine (char store[], int capacity) {
    // reads a line from stdin and stores as much of it as possible in store
    // a line is defined as a sequence of characters ending in \n or EOF
    // returns length of line read, or -1 if EOF reached
    int c, len = 0;
    while (c = getchar()) {
        if (c == EOF) break;
        else {
            if (len < capacity) store[len] = c;
            len++;
            if (c == '\n') break;
        }
    }
    store[min(capacity - 1, len)] = '\0';
    return len;
}

void copy (char src[], char dest[]) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') i++;
}

void main() {
    char curLine[MAX_LINE_LEN];
    char maxLine[MAX_LINE_LEN];
    int c, curLineLen = 0, curMaxLen = 0;

    while (curLineLen = getLine(curLine, MAX_LINE_LEN)) {
        if (curLineLen > curMaxLen) {
            curMaxLen = curLineLen;
            copy(curLine, maxLine);
        }
    }

    printf("\n");
    printf("Longest line has %d characters\n", curMaxLen);
    printf("%s", maxLine);
    printf("\n");
}
