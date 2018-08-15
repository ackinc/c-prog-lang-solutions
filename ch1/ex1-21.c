#include <stdio.h>

#define TAB_STOP 4
#define MAX_LEN 1024

int max(int a, int b) { return (a > b ? a : b); }
int min(int a, int b) { return (a < b ? a : b); }

int n_tabstops_between(int pos1, int pos2) {
    int n = 0;
    for (int i = pos1 + 1; i <= pos2; i++) if (i % TAB_STOP == 0) n++;
    return n;
}

int next_tabstop(int pos) {
    pos += TAB_STOP;
    while (pos % TAB_STOP) pos--;
    return pos;
}

int prev_tabstop(int pos) {
    while (pos % TAB_STOP) pos--;
    return pos;
}

int getLine(char store[], int max_len) {
    char c;
    int len = 0, print_len = 0;
    int in_whitespace = 0, cur_whitespace_len = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            in_whitespace = 1;
            cur_whitespace_len++;
        } else {
            if (in_whitespace) {
                int n_tabs, n_spaces;
                if (cur_whitespace_len == 1) {
                    n_tabs = 0;
                    n_spaces = 1;
                } else {
                    n_tabs = n_tabstops_between(print_len, print_len + cur_whitespace_len);
                    n_spaces = print_len + cur_whitespace_len - max(print_len, prev_tabstop(print_len + cur_whitespace_len));
                }

                int old_len = len;

                while (n_tabs-- > 0 && len < max_len - 1) {
                    store[len++] = '\t';
                    print_len = next_tabstop(print_len);
                }
                while (n_spaces-- > 0 && len < max_len - 1) {
                    store[len++] = ' ';
                    print_len++;
                }

                len = max(len, old_len + n_tabs + n_spaces);
                in_whitespace = 0;
                cur_whitespace_len = 0;
            }

            if (len < max_len - 1) {
                store[len] = c;

                if (c == '\t') print_len = next_tabstop(print_len);
                else print_len++;
            }
            len++;
            if (c == '\n') break;
        }
    }
    store[min(len, max_len - 1)] = '\0';
    return len;
}

void main () {
    int len;
    char line[MAX_LEN];
    while (len = getLine(line, MAX_LEN)) {
        printf("%s", line);
    }
}
