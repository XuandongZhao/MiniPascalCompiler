#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "util.h"
#include "errormsg.h"


bool anyErrors = FALSE;

static string fileName = "";

static int lineNum = 1;
static int gnlines = 1;
static intList gline_pos = NULL;

int EM_tokPos = 0;

extern FILE *yyin;


static intList linePos = NULL;

void EM_newline(void) {
    lineNum++;
    linePos = IntList(EM_tokPos, linePos);
}

void EM_error(int pos, char *message, ...) {
    va_list ap;
    intList lines = linePos;
    int num = lineNum;


    anyErrors = TRUE;
    while (lines && lines->value >= pos) {
        lines = lines->next;
        num--;
    }

    if (fileName) fprintf(stderr, "%s:", fileName);
    if (lines) fprintf(stderr, "%d.%d: ", num, pos - lines->value);
    va_start(ap, message);
    vfprintf(stderr, message, ap);
    va_end(ap);
    fprintf(stderr, "\n");

}

void EM_reset(string fname) {
    anyErrors = FALSE;
    fileName = fname;
    lineNum = 1;
    linePos = IntList(0, NULL);
    yyin = fopen(fname, "r");
    if (!yyin) {
        EM_error(0, "cannot open");
        exit(1);
    }
}


void EM_IRError(int pos, char *msg, ...) {
    va_list ap;
    intList lines = gline_pos;
    int num = gnlines;
    for (intList lines = gline_pos; lines && lines->value >= pos; lines = lines->next) {
        num--;
    }

    if (lines) {
        fprintf(stderr, "[Error] %d.%d: \n        ", num, pos - lines->value);
    }

    va_start(ap, msg);
    vfprintf(stderr, msg, ap);
    va_end(ap);
    fprintf(stderr, "\n");

    exit(-1);
}