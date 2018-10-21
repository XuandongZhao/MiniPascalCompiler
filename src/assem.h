#ifndef _TIGER_ASSEM_H
#define _TIGER_ASSEM_H

static Temp_temp nthTemp(Temp_tempList list, int i);

static Temp_label nthLabel(Temp_labelList list, int i);

typedef struct {
    Temp_labelList labels;
} *assem_tar;
typedef struct assem_instr_ *assem_instr;
struct assem_instr_ {
    enum {
        type_oper, type_label, type_move, type_other
    } type;
    union {
        struct {
            string assem;
            Temp_tempList dst, src;
            assem_tar jumps;
        } OPER;
        struct {
            string assem;
            Temp_label label;
        } LABEL;
        struct {
            string assem;
            Temp_tempList dst, src;
        } MOVE;
        string assem;
    } value;
};
typedef struct assem_instr_list_ *assem_instr_list;
struct assem_instr_list_ {
    assem_instr head;
    assem_instr_list tail;
};
typedef struct assem_proc_ *assem_proc;
struct assem_proc_ {
    string prolog;
    assem_instr_list body;
    string epilog;
};

assem_tar assemTar(Temp_labelList labels);

assem_instr assemOper(string a, Temp_tempList d, Temp_tempList s, assem_tar j);

assem_instr assemLabel(string a, Temp_label label);

assem_instr assemMove(string a, Temp_tempList d, Temp_tempList s);

assem_instr assemOther(string assem);

void assemPrint(FILE *out, assem_instr i, Temp_map m);

assem_instr_list assemInstrList(assem_instr head, assem_instr_list tail);

void assemPrintInstrList(FILE *out, assem_instr_list iList, Temp_map m);

#endif
