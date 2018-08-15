#include <stdio.h>

int strLen(char *s) {
    int length = 0;
    while (*s++ != '\0') length++;
    return length;
}

// if t is a prefix of s, returns 1, else returns 0
int isPrefixOf(char *s, char *t) {
    while (*s == *t && *s != '\0' && *t != '\0') s++, t++;
    return *t == '\0';
}

// returns index of last occurrence of t in s,
//   or -1 if t cannot be found in s
int strRevIndex(char *s, char *t) {
    int s_len = strLen(s), t_len = strLen(t);
    if (t_len > s_len) return -1;

    char *u = s + s_len - t_len;
    while (u >= s) {
        if (isPrefixOf(u, t))
            return u - s;
        else
            u -= 1;
    }
    return -1;
}

void main() {
    printf("%d\n", strRevIndex("AnirudhAnirudh", "ani"));
    printf("%d\n", strRevIndex("Anirudhanirudh", "Ani"));
    printf("%d\n", strRevIndex("AnirudhAnirudh", "Ani"));
}
