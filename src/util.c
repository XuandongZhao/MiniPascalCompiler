
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void *checked_malloc(int len) {
    void *p = malloc(len);
    if (!p) {
        fprintf(stderr, "\nRan out of memory!\n");
        exit(1);
    }
    return p;
}

string String(char *s) {
    string p = checked_malloc(strlen(s) + 1);
    strcpy(p, s);
    return p;
}

intList IntList(int i, intList next) {
    intList l = (intList) malloc(sizeof *l);
    l->value = i;
    l->next = next;
    return l;
}


static inline int intlen(int t) {
    int res = 0;
    while (t != 0) {
        res += 1;
        t /= 10;
    }
    return res;
}


char *UT_itoa(int t) {

    int len = intlen(t);
    char *res = (char *) malloc((len + 1) * sizeof(char));

    for (int i = len - 1; i >= 0; i--) {
        res[i] = '0' + t % 10;
        t /= 10;
    }
    res[len] = '\0';
    return res;
}


char *UT_prefix_itoa(const char *str, int t) {
    int len = intlen(t);
    char *number = UT_itoa(t);
    char *res = (char *) malloc((len + 1 + strlen(str)) * sizeof(char));
    strcat(res, str);
    strcat(res, number);
    return res;
}

void indent(FILE *out, int d) {
    for (int i = 0; i <= d; i++) {
        fprintf(out, " ");
    }
}

