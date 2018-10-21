#ifndef ABSYN_H
#define ABSYN_H

#include "util.h"
#include "symbol.h"

typedef int A_pos;

typedef struct A_var_ *A_var;
typedef struct A_exp_ *A_exp;
typedef struct A_dec_ *A_dec;
typedef struct A_ty_ *A_ty;

typedef struct A_decList_ *A_decList;
typedef struct A_expList_ *A_expList;
typedef struct A_field_ *A_field;
typedef struct A_fieldList_ *A_fieldList;
typedef struct A_fundec_ *A_fundec;
typedef struct A_fundecList_ *A_fundecList;
typedef struct A_namety_ *A_namety;
typedef struct A_nametyList_ *A_nametyList;

typedef enum {
    A_plusOp, A_minusOp, A_timesOp, A_divideOp, A_eqOp, A_neqOp, A_ltOp, A_leOp, A_gtOp, A_geOp
} A_oper;

struct A_var_ {
    enum {
        A_simpleVar, A_fieldVar, A_subscriptVar
    } kind;
    A_pos pos;
    union {
        S_symbol simple;
        struct {
            A_var var;
            S_symbol sym;
        } field;
        struct {
            A_var var;
            A_exp exp;
        } subscript;
    } u;
    int isret;
};

struct A_exp_ {
    enum {
        A_varExp, A_nilExp, A_intExp, A_realExp, A_charExp, A_boolExp, A_stringExp, A_callExp,
        A_opExp,A_seqExp, A_assignExp, A_ifExp,
        A_whileExp, A_repeatExp, A_forExp, A_gotoExp, A_breakExp, A_letExp, A_arrayExp
    } kind;
    A_pos pos;
    union {
        A_var _var;
        int _ival;
        char charr;
        string _sval;
        bool booll;
        struct {
            S_symbol func;
            A_expList args;
        } _call;
        struct {
            A_oper oper;
            A_exp left;
            A_exp right;
        } _op;
        A_expList _seq;
        struct {
            A_var var;
            A_exp exp;
        } _assign;
        struct {
            A_exp test, then, _else;
        } _if;
        struct {
            A_exp test, body;
        } _while;
        struct {
            A_exp body, test;
        } _repeat;
        struct {
            S_symbol var;
            A_exp low, high, body;
            bool escape;
        } _for;
        struct {
            A_exp label;
        } gotoo;
        struct {
            A_decList decs;
            A_exp body;
        } _let;
        struct {
            S_symbol _type;
            A_exp size, init;
        } _array;
    } u;
};

struct A_dec_ {
    enum {
        A_functionDec, A_constDec, A_varDec, A_typeDec
    } kind;
    A_pos pos;
    union {
        A_fundecList function;
        struct {
            S_symbol var;
            S_symbol _type;
            A_exp init;
            bool escape;
        } var;
        struct {
            S_symbol constt;
            A_exp init;
            bool escape;
        } constt;
        A_nametyList _type;
    } u;
};

struct A_ty_ {
    enum {
        A_nameTy, A_arrayTy, A_rangeTy, A_enumType
    } kind;
    A_pos pos;
    union {
        S_symbol name;
        struct {
            struct A_ty_ *range;
            S_symbol element;
        } _array;
        struct {
            A_exp lo, hi;
        } rangee;
        A_fieldList enumm;
    } u;
};

struct A_field_ {
    S_symbol name, _type;
    A_pos pos;
    bool escape;
};
struct A_fieldList_ {
    A_field head;
    A_fieldList tail;
};
struct A_expList_ {
    A_exp head;
    A_expList tail;
};
struct A_fundec_ {
    A_pos pos;
    S_symbol name;
    A_fieldList params;
    S_symbol result;
    A_exp body;
};

struct A_fundecList_ {
    A_fundec head;
    A_fundecList tail;
};
struct A_decList_ {
    A_dec head;
    A_decList tail;
};
struct A_namety_ {
    S_symbol name;
    A_ty ty;
};
struct A_nametyList_ {
    A_namety head;
    A_nametyList tail;
};

A_var A_SimpleVar(A_pos pos, S_symbol sym);

A_var A_FieldVar(A_pos pos, A_var var, S_symbol sym);

A_var A_SubscriptVar(A_pos pos, A_var var, A_exp exp);

A_exp A_VarExp(A_pos pos, A_var var);

A_exp A_IntExp(A_pos pos, int i);

A_exp A_CharExp(A_pos pos, char c);

A_exp A_StringExp(A_pos pos, string s);

A_exp A_CallExp(A_pos pos, S_symbol func, A_expList args);

A_exp A_OpExp(A_pos pos, A_oper oper, A_exp left, A_exp right);

A_exp A_SeqExp(A_pos pos, A_expList seq);

A_exp A_AssignExp(A_pos pos, A_var var, A_exp exp);

A_exp A_IfExp(A_pos pos, A_exp test, A_exp then, A_exp elsee);

A_exp A_WhileExp(A_pos pos, A_exp test, A_exp body);

A_exp A_RepeatExp(A_pos pos, A_exp body, A_exp test);

A_exp A_GotoExp(A_pos pos, A_exp label);

A_exp A_LetExp(A_pos pos, A_decList decs, A_exp body);

A_expList A_ExpList(A_exp head, A_expList tail);

A_dec A_ConstDec(A_pos pos, S_symbol constt, A_exp init);

A_dec A_VarDec(A_pos pos, S_symbol var, S_symbol typ, A_exp init);

A_dec A_TypeDec(A_pos pos, A_nametyList type);

A_dec A_FunctionDec(A_pos pos, A_fundecList function);

A_decList A_DecList(A_dec head, A_decList tail);

A_ty A_NameTy(A_pos pos, S_symbol name);

A_ty A_ArrayTy(A_pos pos, A_ty range, S_symbol element);

A_ty A_RangeTy(A_pos pos, A_exp lo, A_exp hi);

A_ty A_EnumType(A_pos pos, A_fieldList valueList);

A_field A_Field(A_pos pos, S_symbol name, S_symbol typ);

A_fieldList A_FieldList(A_field head, A_fieldList tail);

A_fundec A_Fundec(A_pos pos, S_symbol name, A_fieldList params, S_symbol result,
                  A_exp body);

A_fundecList A_FundecList(A_fundec head, A_fundecList tail);

A_namety A_Namety(S_symbol name, A_ty ty);

A_nametyList A_NametyList(A_namety head, A_nametyList tail);

#endif  