#include <userlibc.h>
#include <stdarg.h>
#include <stdio.h>

int string_compare(const char * s1, const char * s2) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') return 0;
    }
    return s1[i] - s2[i];
}

