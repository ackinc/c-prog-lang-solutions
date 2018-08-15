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

int isWhitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\0');
}

int trimLine(char line[], int len) {
    int first_char_pos = 0, last_char_pos = len - 1, trimmed_len = 0;

    while (isWhitespace(line[first_char_pos])) first_char_pos++;
    while (isWhitespace(line[last_char_pos])) last_char_pos--;
    trimmed_len = last_char_pos - first_char_pos + 1;

    for (int i = 0; i < trimmed_len; i++) line[i] = line[first_char_pos + i];
    line[trimmed_len] = '\0';
    return trimmed_len;
}

void main() {
    char line[MAX_LEN];
    int len, trimmed_len;
    while (len = getLine(line, MAX_LEN))
        if ((trimmed_len = trimLine(line, len)) > 0) printf("%s\n", line);
}
