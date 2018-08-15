#include <stdio.h>

#define MAX_LEN 1024

int min(int a, int b) { return (a < b ? a : b); }

int getLine(char store[], int max_len) {
    char c;
    int len = 0;
    while ((c = getchar()) != EOF) {
        if (len < max_len - 1) store[len] = c;
        len++;
        if (c == '\n') break;
    }
    store[min(len, max_len - 1)] = '\0';
    return len;
}

int strLen(char str[]) {
    int n = 0;
    while (str[n] != '\0') n++;
    return n;
}

void reverse(char str[]) {
    char c;
    int len = strLen(str);
    int i = 0, j = len - 1;

    if (str[j] == '\n') j--; // leave line-ending newlines alone
    while (i < j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
}

void main () {
    char line[MAX_LEN];
    int len;
    while (len = getLine(line, MAX_LEN)) {
        reverse(line);
        printf("%s", line);
    }
}