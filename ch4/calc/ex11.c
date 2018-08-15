#include <ctype.h>
#include <stdbool.h>

#include "calc.h" // for NUMBER, STRING

// puts next input in s
// if it is a number, returns NUMBER
// if it is a string, returns STRING
// if it is an operator, or \n, returns it
int getop(char s[]) {
    int i = 0;
    static bool processed_extra_char = false;
    static char c;
    char d;

    if (!processed_extra_char) c = getch();

    while (c == ' ' || c == '\t') c = getch(); // skip whitespace
    s[i] = c;

    if (isalpha(c)) { // input is a string (could be a variable or a function)
        while (isalnum(s[++i] = c = getch())) ; // read rest of string

        processed_extra_char = true;
        s[i] = '\0';

        return STRING;
    }

    if (isdigit(c) || c == '.' || c == '-') { // input could be a number
        if (!(c == '-' && !isdigit(d = getch()))) { // input is a number
            if (c == '-') ungetch(d); // we had to read one extra char to verify that input is a number in this case

            while (isdigit(s[++i] = c = getch())) ; // read next digits until space or decimal pt
            if (c == '.') while (isdigit(s[++i] = c = getch())) ; // read rest of number

            processed_extra_char = true;
            s[i] = '\0';

            return NUMBER;
        } else {
            ungetch(d);
        }
    }

    // input is an operator, or \n, or EOF
    processed_extra_char = false;
    s[1] = '\0';
    return c;
}
