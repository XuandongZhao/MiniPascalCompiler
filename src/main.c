#include "util.h"
#include "symbol.h"
#include "absyn.h"
#include "errormsg.h"
#include "types.h"
#include "table.h"
#include "temp.h"
#include "tree.h"
#include "frame.h"
#include "translate.h"
#include "semant.h"
#include "prirtree.h"
#include "assem.h"
#include "canon.h"
#include "codegen.h"
#include "prabsyn.h"
#include <stdio.h>
#include <stdlib.h>

extern A_exp ABSTRoot;

extern int yyparse(void);

static int fp_base = 4;
typedef struct _FILES {
    FILE *fragment;
    FILE *expr;
    FILE *abst;
} FILES;

FILES fileInit() {
    FILES test;
    test.fragment = fopen("../test/fragment.json", "w");
    test.expr = fopen("../test/IRTree.json", "w");
    test.abst = fopen("../test/ASTree.json", "w");
    return test;
}

int parse(string fname) {
    EM_reset(fname);
    int res = yyparse();
    if (!res) {
    } else {
        printf("Syntax not passed! Please check your syntax.\n");
    }
    fclose(stdin);
    return res;
}

static void parseExprOut(Tr_exp expr, FILE *out_json) {
    switch (expr->tr_exp_type) {
        case Tr_ex: {
            printTreeJson(out_json, unEx(expr), 0);
            break;
        }
        case Tr_nx: {
            printStmJson(out_json, unNx(expr), 0);
            break;
        }
        case Tr_cx: {
            printStmJson(out_json, unCx(expr).stm, 0);
            break;
        }
    }
}

static bool parseFragOut(F_fragList fl, FILE *out_json) {
    if (!fl)
        return FALSE;

    while (fl) {
        F_frag f = fl->head;
        switch (f->frag_type) {
            case F_stringFrag: {
                parseExprOut(Tr_Ex(T_Name(f->frag_value.string_frag.label)), out_json);
                break;
            }
            case F_procFrag: {
                parseExprOut(Tr_Nx(f->frag_value.proc_frag.body), out_json);
                break;
            }
        }
        fl = fl->tail;
    }
    return TRUE;
}


static void doProcedure(FILE *out, F_frame frame, T_stm body) {
    T_stmList stmList;
    assem_instr_list iList;

    stmList = canon_linearize(body);
    iList = code_generate(frame, stmList);
    if (frame)
        fprintf(out, "BEGIN %s\n", Temp_labelString(F_name(frame)));
    assemPrintInstrList(out, iList, Temp_layerMap(F_tempMap, Temp_name()));
    if (frame) {
        fprintf(out, "jr $ra\n");
        fprintf(out, "END %s\n\n", Temp_labelString(F_name(frame)));
    }

}

static void simulate_fp(FILE *out) {
    fprintf(out, "lui  $%d, 0x7fff\n", fp_base);
    fprintf(out, "ori $%d, $%d, 0xf4c0\n", fp_base, fp_base);
    fprintf(out, "sw $%d, 0($%d)\n", fp_base, fp_base);
}

int main(int argc, char *argv[]) {

    parse(argv[1]);

    FILES test = fileInit();

    pr_exp(test.abst, ABSTRoot, 0);
    printf("\n###AST done.###\n");

    if (ABSTRoot) {
        SEM_expfrag expfrag = SEM_AST2IRT(ABSTRoot);
        printf("\n###AST2IRT done.###\n");

        if (parseFragOut(expfrag->fragList, test.fragment) == TRUE) {
            printf("\nSuccessful Write to \"fragment.json\"\n");
        } else {
            printf("No fragment in the program\n");
        }
        parseExprOut(expfrag->exp, test.expr);
        printf("\nSuccessful Write to \"IRTree.json\"\n");

        FILE *out = stdout;
        char outfile[100];
        sprintf(outfile, "../test/result.s");
        out = fopen(outfile, "w");
        F_fragList frags = expfrag->fragList;
        for (; frags; frags = frags->tail) {
            if (frags->head->frag_type == F_procFrag) {
                doProcedure(out, frags->head->frag_value.proc_frag.frame, frags->head->frag_value.proc_frag.body);
            } else if (frags->head->frag_type == F_stringFrag) {
                fprintf(out, "%s: %s\n", Temp_labelString(frags->head->frag_value.string_frag.label),
                        frags->head->frag_value.string_frag.str);
            } else
                assert(0);
        }
        Tr_exp IR_tree = expfrag->exp;
        if (IR_tree->tr_exp_type == Tr_ex) {
            printf("Tr_ex, change it to stm\n");
            T_stm wrap_IR_tree = (T_stm) malloc(sizeof(struct T_stm_));
            wrap_IR_tree->stm_type = T_EXP;
            wrap_IR_tree->stm_value.EXP = IR_tree->tr_exp_storage.ex;
            fprintf(out, "main:\n");
            simulate_fp(out);
            doProcedure(out, NULL, wrap_IR_tree);
        }
        if (IR_tree->tr_exp_type == Tr_nx) {
            printf("Tr_nx, satisfy\n");
            fprintf(out, "main:\n");
            simulate_fp(out);
            doProcedure(out, NULL, IR_tree->tr_exp_storage.nx);
        }
        if (IR_tree->tr_exp_type == Tr_cx) {
            printf("Tr_cx, change it to stm\n");
        }
        printf("\nSuccessful Write to \"%s\"\n", outfile);
    }

    fclose(test.abst);
    fclose(test.expr);
    fclose(test.fragment);
    return 0;
}