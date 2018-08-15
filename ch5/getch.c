#include <stdio.h>

#define BUF_SIZE 100

char buffer[BUF_SIZE];
int bufp = 0; // points to next free buffer slot

char getch() {
    if (bufp)
        return buffer[--bufp];
    else
        return getchar();
}

void ungetch(char c) {
    if (bufp < BUF_SIZE)
        buffer[bufp++] = c;
    else
        printf("UNGETCH error -- buffer full\n");
}
