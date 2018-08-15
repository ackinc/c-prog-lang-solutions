#include <stdio.h>

#define MAX_LINE_LEN 1000
#define CUTOFF 80

int min(int a, int b) { return (a < b ? a : b); }

int getLine(char store[], int capacity) {
    // reads a line from stdin and stores as much of it as possible in store
    // a line is defined as a sequence of characters ending in \n or EOF
    // returns length of line read, or -1 if EOF reached
    int c, len = 0;
    while (c = getchar()) {
        if (c == EOF)
            break;
        else {
            if (len < capacity) store[len] = c;
            len++;
            if (c == '\n') break;
        }
    }
    store[min(capacity - 1, len)] = '\0';
    return len;
}

void main() {
    int len;
    char line[MAX_LINE_LEN];
    while (len = getLine(line, MAX_LINE_LEN)) {
        if (len > CUTOFF) printf("%s\n", line);
    }
}
