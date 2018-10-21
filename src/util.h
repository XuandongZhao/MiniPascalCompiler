#ifndef UTIL_H_
#define UTIL_H_

#include <assert.h>
#include <stdio.h>


typedef char *string;
typedef char bool;

#define TRUE 1
#define FALSE 0
#define DEBUG_ERROR assert(0)

void *checked_malloc(int);

string String(char *);

typedef struct U_boolList_ *U_boolList;
struct U_boolList_ {
    bool head;
    U_boolList tail;
};

U_boolList U_BoolList(bool head, U_boolList tail);

char *UT_itoa(int t);

char *UT_prefix_itoa(const char *str, int t);

void indent(FILE *out, int d);

typedef struct intList_ *intList;
struct intList_ {
    int value;
    intList next;
};

intList IntList(int i, intList next);

#endif
