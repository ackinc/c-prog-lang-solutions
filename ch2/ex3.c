#include <stdio.h>
#include <string.h>

unsigned int htoi(char *hex) {
    unsigned int ret = 0;
    char c;

    if (strlen(hex) > 2 && (hex[1] == 'x' || hex[1] == 'X')) {
        hex += 2; // skip optional 0(X|x)
    }

    while ((c = *hex++) != '\0') {
        unsigned int val;

        if (c >= '0' && c <= '9')
            val = c - '0';
        else if (c >= 'A' && c <= 'F')
            val = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            val = c - 'a' + 10;
        else
            val = 0;

        ret = ret * 16 + val;
    }
    return ret;
}

void main() {
    printf("%ud\n", htoi("1"));
    printf("%ud\n", htoi("B"));
    printf("%ud\n", htoi("F7"));
    printf("%ud\n", htoi("0xFF"));
    printf("%ud\n", htoi("0XFF"));
    printf("%ud\n", htoi("FF"));
    printf("%ud\n", htoi("0x4E8CA1F8"));
}
