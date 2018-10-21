#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "symbol.h"
#include "absyn.h"
#include "temp.h"
#include "tree.h"
#include "assem.h"
#include "frame.h"
#include "errormsg.h"


static Temp_temp nthTemp(Temp_tempList list, int i) {
    assert(list);
    bool temp_condi = (i == 0);
    if (temp_condi)
        return list->head;
    else
        return nthTemp(list->tail, i - 1);
}

static Temp_label nthLabel(Temp_labelList list, int i) {
    assert(list);
    bool temp_condi = (i == 0);
    if (temp_condi)
        return list->head;
    else
        return nthLabel(list->tail, i - 1);
}

assem_instr assemOper(string assem, Temp_tempList destination, Temp_tempList source, assem_tar jump) {
    assem_instr p = (assem_instr) malloc(sizeof *p);
    p->type = type_oper;
    p->value.OPER.assem = assem;
    p->value.OPER.dst = destination;
    p->value.OPER.src = source;
    p->value.OPER.jumps = jump;
    return p;
}

assem_instr assemLabel(string assem, Temp_label label) {
    assem_instr p = (assem_instr) malloc(sizeof *p);
    p->type = type_label;
    p->value.LABEL.assem = assem;
    p->value.LABEL.label = label;
    return p;
}

assem_instr assemMove(string assem, Temp_tempList destination, Temp_tempList source) {
    assem_instr p = (assem_instr) malloc(sizeof *p);
    p->type = type_move;
    p->value.MOVE.assem = assem;
    p->value.MOVE.dst = destination;
    p->value.MOVE.src = source;
    return p;
}

assem_instr assemOther(string assem) {
    assem_instr p = (assem_instr) malloc(sizeof *p);
    p->type = type_other;
    p->value.assem = assem;
    return p;
}

assem_instr_list assemInstrList(assem_instr head, assem_instr_list tail) {
    assem_instr_list p = (assem_instr_list) malloc(sizeof *p);
    p->head = head;
    p->tail = tail;
    return p;
}

static void
format(char *result, string assem, Temp_tempList destination, Temp_tempList source, assem_tar jumps, Temp_map m) {
    int i = 0;
    char *deliver_p = NULL;
    for (deliver_p = assem; deliver_p && *deliver_p != '\0'; deliver_p++) {
        bool condition_begin_flag = (*deliver_p == '@');
        if (condition_begin_flag) {
            char replace_flag = *(++deliver_p);
            // source
            bool condition_follow_s = (replace_flag == 's');
            if (condition_follow_s) {
                int n = atoi(++deliver_p);
                string s = Temp_look(m, nthTemp(source, n));
                strcpy(result + i, s);
                i += strlen(s);
            }
            // estination
            bool condition_follow_d = (replace_flag == 'd');
            if (condition_follow_d) {
                int n = atoi(++deliver_p);
                string s = Temp_look(m, nthTemp(destination, n));
                strcpy(result + i, s);
                i += strlen(s);
            }
            // jump
            bool condition_follow_j = (replace_flag == 'j');
            if (condition_follow_j) {
                assert(jumps);
                int n = atoi(++deliver_p);
                string s = Temp_labelString(nthLabel(jumps->labels, n));
                strcpy(result + i, s);
                i += strlen(s);
            }
            bool condition_follow_at = (replace_flag == '@');
            if (condition_follow_at) {
                result[i] = '@';
                i++;
            }
            bool invalid_cond = !(condition_follow_s || condition_follow_d || condition_follow_j ||
                                  condition_follow_at);
            if (invalid_cond) {
                printf("The flag follows '@' is not valid!\n");
                assert(0);
            }
        } else {
            result[i] = *deliver_p;
            i++;
        }
    }
    result[i] = '\0';
}

void assemPrint(FILE *out, assem_instr i, Temp_map m) {
    char r[100];
    bool condi_i_type_oper = (i->type == type_oper);
    bool condi_i_type_label = (i->type == type_label);
    bool condi_i_type_move = (i->type == type_move);
    if (condi_i_type_oper) {
        format(r, i->value.OPER.assem, i->value.OPER.dst, i->value.OPER.src, i->value.OPER.jumps, m);
        fprintf(out, "%s\n", r);
    } else if (condi_i_type_label) {
        format(r, i->value.LABEL.assem, NULL, NULL, NULL, m);
        fprintf(out, "%s:\n", r);
    } else if (condi_i_type_move) {
        format(r, i->value.MOVE.assem, i->value.MOVE.dst, i->value.MOVE.src, NULL, m);
        fprintf(out, "%s\n", r);
    } else {
        fprintf(out, "%s\n", i->value.assem);
    }
}

void assemPrintInstrList(FILE *out, assem_instr_list iList, Temp_map m) {
    for (; iList; iList = iList->tail) {
        assemPrint(out, iList->head, m);
    }
}

assem_tar assemTar(Temp_labelList labels) {
    assem_tar p = malloc(sizeof *p);
    p->labels = labels;
    return p;
}
