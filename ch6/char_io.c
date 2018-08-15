#include <ctype.h>
#include <stdbool.h>

#include "char_io.h"

#define SENTINEL_CHAR -2

static int LATEST_CHAR_READ;

int getch() {
    char c;

    if (LATEST_CHAR_READ != SENTINEL_CHAR) {
        c = LATEST_CHAR_READ;
        LATEST_CHAR_READ = SENTINEL_CHAR;
    } else {
        c = getchar();
    }

    return c;
}

void ungetch(char c) {
    LATEST_CHAR_READ = c;
}

// A WordChar is in [a-zA-Z0-9_]
static bool isWordChar (int c) {
    return isalpha(c) || isdigit(c) || c == '_';
}

// A Word is one of:
//   - sequence of WordChars starting with an alphabet or '_'
//   - string constant
//   - single non-alphabetical character
//   - C comment (single- or multi-line)

// Reads a Word (of maximum length n) from stdin and copies it into <word>
// Returns one of:
// - EOF (if next input EOF)
// - first char read (if next input not EOF)
int getword(char *word, int n) {
    char *w;
    int c;

    while (isspace(c = getch())) ;

    if (c == EOF) {
        return c;
    } else {
        *w++ = c;
        if (isalpha(c) || c == '_') { // Word
            while (isWordChar(c = getch()) && w - word < n - 1) *w++ = c;
            ungetch(c);
        } else if (c == '"') { // string constant (also a Word)

            while ((*w++ = c = getch()) != '"' && w - word < n - 2) ;

            // if the last char read was not a double-quote, it means we
            //   stopped because we ran out of space in <word>, rather
            //   than because the string ended
            // in this case, we should close the string manually
            if (c != '"') *w++ = '"';

        } else if (c == '/') {
            char d = getch();

            if (d == '/') { // single-line comment

                // WARNING: assumed that single-line comments end with newline,
                //   and not EOF
                while ((*w++ = d) != '\n' && w - word < n - 1) d = getch();

            } else if (d == '*') { // multi-line comment

                // this flag is used in ensuring that '/*/' is not treated as a
                //   full multi-line comment
                bool in_comment = false;

                // WARNING: assumed that multi-line comments are well-formed
                //   i.e no cases of a multi-line comment ending with
                //   EOF instead of '*/'
                while (!(d == '*' && (*w++ = c = getch()) == '/' && in_comment) &&
                       !(c == '*' && (*w++ = d = getch()) == '/') &&
                       w - word < n - 3) in_comment = true;

                // if RHS of the condition 'w - word < n - 3' above is changed to
                //   'n - 2', there is a possibility of writing past end of <word>
                //   array

                if (!((c == '*' && d == '/') || (c == '/' && d == '*'))) {
                    *w++ = '*';
                    *w++  '/';
                }

            } else { // not a C comment
                ungetch(d);
            }

        }

        *w = '\0';
        return *word;
    }
}

// Maybe a better way to write a getword that deals with
//   string constants, comments, and preprocessor control lines
//   is to return numeric codes instead of the first char of input
// Ex: if next input is the string constant "anirudh",
//       getword should put '"' in <word>, and return -2 (code for string)
//     further calls to getword should extract the string contents as words
// That way, the user of getword can decide how to deal with content
//   inside string quotes, comments, etc.
