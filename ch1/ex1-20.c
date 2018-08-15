#include <stdio.h>

#define TAB_STOP 4
#define MAX_LEN 1024

int min(int a, int b) { return (a < b ? a : b); }

int getLine(char store[], int max_len) {
    char c;
    int len = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int next_tab_stop = len + TAB_STOP;
            while (next_tab_stop % TAB_STOP != 0) next_tab_stop--;
            while (len < next_tab_stop && len < max_len -1) store[len++] = ' ';
            len = next_tab_stop;
        } else {
            if (len < max_len - 1) store[len] = c;
            len++;
        }
        if (c == '\n') break;
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
