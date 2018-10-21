#ifndef _TIGER_CANON_H
#define _TIGER_CANON_H

struct stm_exp {
    T_stm s;
    T_exp e;
};
typedef struct canon_exp_list_ *canon_exp_list;
struct canon_exp_list_ {
    T_exp *head;
    canon_exp_list tail;
};
typedef struct canon_stm_list_ *canon_stm_list;
struct canon_block {
    canon_stm_list stmLists;
    Temp_label label;
};
struct canon_stm_list_ {
    T_stmList head;
    canon_stm_list tail;
};

static S_table block_env;
static struct canon_block global_block;

static T_stm do_stm(T_stm stm);

static struct stm_exp do_exp(T_exp exp);

static canon_stm_list mkBlocks(T_stmList stms, Temp_label done);

static T_stmList getNext(void);

static canon_stm_list canon_Stm_List(T_stmList head, canon_stm_list tail);

T_stmList canon_linearize(T_stm stm);

#endif
