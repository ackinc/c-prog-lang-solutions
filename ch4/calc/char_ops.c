#include <stdio.h>
#include <string.h>

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

void reverse(char s[]) {
    int i = 0, j = strlen(s) - 1;
    char c;

    while (i < j) {
        c = s[i], s[i] = s[j], s[j] = c; // swap s[i] and s[j]
        i++, j--;
    }
}

void ungets(char s[]) {
    int len = strlen(s);
    char dest[len];
    strcpy(s, dest);
    reverse(dest);
    for (int i = 0; i < len; i++) ungetch(dest[i]);
}
