#include <stdio.h>

void escape (char *s, char* t) {
    while (*s != '\0') {
        switch(*s) {
            case '\t':
                *t++ = '\\';
                *t = 't';
                break;
            case '\n':
                *t++ = '\\';
                *t = 'n';
                break;
            default:
                *t = *s;
                break;
        }
        s++;
        t++;
    }
    *t = '\0';
}

void capture (char *s, char* t) {
    while (*s != '\0') {
        switch(*s) {
            case '\\':
                switch(*(s + 1)) {
                    case 'n':
                        *t = '\n';
                        s++;
                        break;
                    case 't':
                        *t = '\t';
                        s++;
                        break;
                    default:
                        *t = *s;
                        break;
                }
                break;
            default:
                *t = *s;
                break;
        }
        s++;
        t++;
    }
    *t = '\0';
}

void main () {
    char dest[] = "TEST STRING OF SUFFICIENT LENGTH";
    char dest2[] = "ANOTHER TEST STRING OF SUFFICIENT LENGTH";
    char *src = "A string wi\nth \n newlines\tand\ttabs";

    escape(src, dest);
    capture(dest, dest2);
    printf("SRC: %s\n", src);
    printf("DEST: %s\n", dest);
    printf("DEST2: %s\n", dest2);
}