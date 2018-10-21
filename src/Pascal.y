%{

#include <stdio.h>
#include "util.h" 
#include "errormsg.h"
#include "symbol.h"
#include "absyn.h"

int yyerror(char* msg);
int yylex(void);
// root for parsed abstract syntax tree
A_exp ABSTRoot;

A_fieldList A_linkFieldList(A_fieldList front, A_fieldList tail);
A_fieldList A_setFieldListType(A_fieldList fieldList, A_ty ty);

A_decList A_linkDecList(A_decList front, A_decList tail);
A_decList A_setDecListType(A_decList decList, A_ty ty);

A_decList A_unDecList(A_fieldList fieldList);

%}
%token  LP RP LB RB DOT COMMA COLON SEMI
        PLUS MINUS MUL REALDIV INTDIV MOD AND OR NOT
        GE GT LE LT EQUAL UNEQUAL
        ASSIGN PROGRAM FUNCTION PROCEDURE BEGIN_T END  
        TYPE ARRAY OF VAR
        IF THEN ELSE
        REPEAT TO DOWNTO UNTIL WHILE DO FOR
        CASE GOTO 
        READ
        CONST DOTDOT
%union {
    int pos;
    int ival;
    char cval;
    string sval;
    A_var var;
    A_exp exp;
    S_symbol sym;
    A_dec dec;
    A_decList declist;
    A_expList explist;
    A_ty ty;
    A_fieldList fieldlist;
    A_fundec fundec;
    A_fundecList fundeclist;
    A_namety namety;
    A_nametyList nametylist;
}
%token<ival> INTEGER
%token<cval> CHAR 
%token<sval> ID STRING SYS_CON SYS_FUNCT SYS_PROC SYS_TYPE

%type <cval> direction
%type <exp> program routine sub_routine routine_body const_value stmt compound_stmt non_label_stmt assign_stmt proc_stmt if_stmt else_clause repeat_stmt while_stmt for_stmt goto_stmt expression expr term factor
%type <declist> routine_head label_part const_part const_expr_list type_part var_part var_decl_list var_decl
%type <fundec> function_decl function_head procedure_decl procedure_head
%type <fundeclist> routine_part
%type <namety> type_definition
%type <nametylist> type_decl_list 
%type <explist> stmt_list expression_list args_list
%type <sym> id sys_con sys_funct sys_proc sys_type
%type <ty> type_decl simple_type_decl array_type_decl
%type <fieldlist> name_list parameters para_type_list para_decl_list var_para_list val_para_list
%type <cval> stat;

%start program

%%
program : program_head routine DOT {ABSTRoot = $2;}
program_head : PROGRAM id SEMI {}
routine : routine_head routine_body {$$ = A_LetExp(EM_tokPos, $1, $2);}
routine_head    : label_part const_part type_part var_part routine_part {
        A_decList decList = A_DecList(A_TypeDec(0, NULL), NULL);
        if ($2) 
            A_linkDecList(decList, $2);
        if ($3)
            A_linkDecList(decList, $3);
        if ($4) 
            A_linkDecList(decList, $4);
        if ($5)
            A_linkDecList(decList, A_DecList(A_FunctionDec(EM_tokPos, $5), NULL));
        $$ = decList->tail;
    }

const_part  : CONST const_expr_list {$$ = $2;}
            |  {$$ = NULL;}
const_expr_list : id EQUAL const_value SEMI const_expr_list  {$$ = A_DecList(A_ConstDec(EM_tokPos, $1, $3),$5);}
                | id EQUAL const_value SEMI {$$ = A_DecList(A_ConstDec(EM_tokPos, $1, $3), NULL);}
const_value : INTEGER {$$ = A_IntExp(EM_tokPos, $1);}
            | CHAR{$$ = A_CharExp(EM_tokPos, $1);}
            | STRING {$$ = A_StringExp(EM_tokPos, $1);}
            | sys_con {/*$$ = A_SysConstExp(EM_tokPos, $1);*/}

type_part   : TYPE type_decl_list {$$ = A_DecList(A_TypeDec(EM_tokPos, $2), NULL);}
            | {$$ = NULL;}
type_decl_list  : type_definition type_decl_list   {$$ = A_NametyList($1, $2);}
                | type_definition {$$ = A_NametyList($1, NULL);}
type_definition : id  EQUAL  type_decl  SEMI {$$ =A_Namety($1, $3);}
type_decl   :  simple_type_decl  {$$ = $1;}
            |  array_type_decl  {$$ = $1;}
simple_type_decl    :  sys_type {$$ = A_NameTy(EM_tokPos, $1);}
                    |  id  {$$ = A_NameTy(EM_tokPos, $1);}
                    |  LP  name_list  RP  {$$ = A_EnumType(EM_tokPos, $2);}
                    |  const_value  DOTDOT  const_value  {$$ = A_RangeTy(EM_tokPos, $1, $3);}
                    |  id  DOTDOT  id {A_RangeTy(EM_tokPos, A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, $1)), A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, $3)));}
array_type_decl : ARRAY  LB  simple_type_decl  RB  OF  type_decl {$$ = A_ArrayTy(EM_tokPos, $3, $6->u.name);}
name_list   : name_list  COMMA  id  {$$ = A_linkFieldList($1, A_FieldList(A_Field(EM_tokPos, $3, NULL), NULL));}
            |  id {$$ = A_FieldList(A_Field(EM_tokPos, $1, NULL), NULL);}
var_part    : VAR  var_decl_list {$$ = $2;}
            |  {$$ = NULL;}
var_decl_list   : var_decl var_decl_list  {$$ = A_linkDecList($1, $2);} 
                | var_decl {$$ = $1;}
var_decl :  name_list  COLON  type_decl  SEMI {$$ = A_setDecListType(A_unDecList($1), $3);}

routine_part: function_decl  routine_part {$$ = A_FundecList($1, $2);}
            |  procedure_decl routine_part  {$$ = A_FundecList($1, $2);}
            |  {$$ = NULL;}
    
function_decl : function_head  SEMI  sub_routine  SEMI {$$ = $1; $$->body = $3;}
function_head :  FUNCTION  id  parameters  COLON  simple_type_decl {$$ = A_Fundec(EM_tokPos, $2, $3, $5->u.name, NULL);}
procedure_decl :  procedure_head  SEMI  sub_routine  SEMI {$$ = $1; $$->body = $3;}
procedure_head :  PROCEDURE id parameters {$$ = A_Fundec(EM_tokPos, $2, $3, NULL, NULL);}
sub_routine : routine_head routine_body {$$ = A_LetExp(EM_tokPos, $1, $2);}
parameters : LP  para_decl_list  RP  {$$ = $2;}
            | {$$ = NULL;}
para_decl_list : para_decl_list  SEMI  para_type_list {$$ = A_linkFieldList($1, $3);}
                | para_type_list {$$ = $1;}
para_type_list : var_para_list COLON  simple_type_decl  {$$ = A_setFieldListType($1, $3);}
                |  val_para_list  COLON  simple_type_decl {$$ = A_setFieldListType($1, $3);}
var_para_list : VAR  name_list {$$ = $2;}
val_para_list : name_list {$$ = $1;}

routine_body : compound_stmt {$$ = $1;}
compound_stmt : BEGIN_T  stmt_list  END {$$ = A_SeqExp(EM_tokPos, $2);}
stmt_list : stmt  SEMI stmt_list {$$ = A_ExpList($1, $3);}
            | {$$ = NULL;}
            | stat {$$ = NULL;}

stmt : INTEGER  COLON  non_label_stmt  {$$ = $3;}
        |  non_label_stmt { $$ = $1;}
non_label_stmt  : assign_stmt { $$ = $1;}
                | proc_stmt {$$ = $1;}
                | compound_stmt {$$ = $1;}
                | if_stmt {$$ = $1;}
                | repeat_stmt {  $$ = $1;}
                | while_stmt {$$ = $1;}
                | for_stmt {$$ = $1;}
                | goto_stmt {$$ = $1;}
assign_stmt : id  ASSIGN  expression {$$ = A_AssignExp(EM_tokPos,A_SimpleVar(EM_tokPos, $1), $3);}
            | id LB expression RB ASSIGN expression {$$ = A_AssignExp(EM_tokPos, A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, $1), $3),$6);}
proc_stmt :  id {$$ = A_CallExp(EM_tokPos, $1, NULL);}
          |  id LP  args_list  RP {$$ = A_CallExp(EM_tokPos, $1, $3);} 
          |  sys_proc {$$ = A_CallExp(EM_tokPos, $1, NULL);}
          |  sys_proc  LP  expression_list  RP {$$ = A_CallExp(EM_tokPos, $1, $3);}
          |  READ  LP  factor  RP {}
if_stmt : IF  expression  THEN  stmt  else_clause {$$ = A_IfExp(EM_tokPos, $2, $4, $5);}
else_clause : ELSE stmt {$$ = $2;}
            |  {$$ = NULL;}
repeat_stmt : REPEAT  stmt  UNTIL  expression {$$ = A_RepeatExp(EM_tokPos, $2, $4);} 
while_stmt : WHILE  expression  DO stmt {$$ = A_WhileExp(EM_tokPos, $2, $4);}
for_stmt : FOR  id  ASSIGN  expression  direction  expression  DO stmt {
    A_var var =  A_SimpleVar(EM_tokPos, $2);
    if (!($5)) {
        $$ = A_SeqExp(EM_tokPos, A_ExpList(A_AssignExp(EM_tokPos, var, $4),
        A_ExpList(A_WhileExp(EM_tokPos, A_OpExp(EM_tokPos, A_ltOp, A_VarExp(EM_tokPos, var), $6), $8), NULL )));
    } else {
        $$ = A_SeqExp(EM_tokPos, A_ExpList(A_AssignExp(EM_tokPos, var, $4),
        A_ExpList(A_WhileExp(EM_tokPos, A_OpExp(EM_tokPos, A_gtOp, A_VarExp(EM_tokPos ,var), $6), $8), NULL )));
    }  
}
direction   : TO {$$ = 0;}
            | DOWNTO {$$ = 1;}
goto_stmt : GOTO  INTEGER {$$ = A_GotoExp(EM_tokPos, A_IntExp(EM_tokPos, $2));}

expression_list : expression COMMA   expression_list {$$ = A_ExpList($1, $3);}
                | expression {$$ = A_ExpList($1, NULL);}
expression  :  expression  GE  expr  {$$ = A_OpExp(EM_tokPos, A_geOp, $1, $3);}
            |  expression  GT  expr  {$$ = A_OpExp(EM_tokPos, A_gtOp, $1, $3);}
            |  expression  LE  expr {$$ = A_OpExp(EM_tokPos, A_leOp, $1, $3); }
            |  expression  LT  expr  {$$ = A_OpExp(EM_tokPos, A_ltOp, $1, $3);}
            |  expression  EQUAL  expr  {$$ = A_OpExp(EM_tokPos, A_eqOp, $1, $3);}
            |  expression  UNEQUAL  expr  {$$ = A_OpExp(EM_tokPos, A_neqOp, $1, $3);}
            |  expr{ $$ = $1;}

expr    :  expr  PLUS  term {$$ = A_OpExp(EM_tokPos, A_plusOp, $1, $3);} 
        |  expr  MINUS  term  {$$ = A_OpExp(EM_tokPos, A_minusOp, $1, $3);} 
        |  expr  OR  term  {$$ = A_IfExp(EM_tokPos, $1, A_IntExp(EM_tokPos, 1), $3);} 
        |  term {$$ = $1;}
term    :  term  MUL  factor {$$ = A_OpExp(EM_tokPos, A_timesOp, $1, $3);} 
        |  term  INTDIV  factor  {$$ = A_OpExp(EM_tokPos, A_divideOp, $1, $3); }
        |  term  AND  factor  {$$ = A_IfExp(EM_tokPos, $1, $3, A_IntExp(EM_tokPos, 0));}
        |  factor { $$ = $1;}
factor  :  id {$$ = A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, $1));}
        |  id LP  args_list  RP {$$ = A_CallExp(EM_tokPos, $1, $3);}
        |  sys_funct {$$ = A_CallExp(EM_tokPos, $1, NULL);}
        |  sys_funct  LP  args_list  RP  {$$ = A_CallExp(EM_tokPos, $1, $3);}
        |  const_value  {$$ = $1;}
        |  LP  expression  RP {$$ = $2;}
        |  NOT  factor  {$$ = A_IfExp(EM_tokPos, $2, A_IntExp(EM_tokPos, 0), A_IntExp(EM_tokPos,1));} 
        |  MINUS  factor {$$ = A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), $2);}
        |  id  DOT  id {$$ = A_VarExp(EM_tokPos, A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, $1), $3));}
args_list   :  args_list  COMMA  expression  {$$ = $1; $1->tail = A_ExpList($3, NULL);}
            |  expression {$$ = A_ExpList($1, NULL);}

id       :  ID          {$$ = S_Symbol($1);}
sys_con  :  SYS_CON     {$$ = S_Symbol($1);}
sys_funct:  SYS_FUNCT   {$$ = S_Symbol($1);}
sys_proc:   SYS_PROC    {$$ = S_Symbol($1);}
sys_type:   SYS_TYPE    {$$ = S_Symbol($1);} 

stat: error SEMI

%%
int yyerror(char* msg) {
    EM_error(EM_tokPos, "%s", msg);
    return 0;   
}

A_fieldList A_linkFieldList(A_fieldList front, A_fieldList tail) {
    if (!front)
        return tail;
    A_fieldList pos = front;
    for (;pos->tail;pos = pos->tail);
    pos->tail = tail; 

    return front;
}

A_fieldList A_setFieldListType(A_fieldList fieldList, A_ty ty) {
    A_fieldList front = fieldList;
    for (;fieldList;fieldList = fieldList->tail) {
        fieldList->head->_type = ty->u.name;
    }

    return front;
}

A_decList A_linkDecList(A_decList front, A_decList tail) {
    if (!front)
        return tail;
    A_decList pos = front;
    for (;pos->tail;pos = pos->tail);
    pos->tail = tail;

    return front;
}

A_decList A_setDecListType(A_decList decList, A_ty ty) {
    A_decList front = decList;
    for (;decList;decList = decList->tail) {
        decList->head->u.var._type = ty->u.name;
    }

    return front;
}

A_decList A_unDecList(A_fieldList fieldList) {
    if (!fieldList)
        return NULL;

    A_field field = fieldList->head;
    A_decList decList = A_DecList(A_VarDec(field->pos, field->name, field->_type, NULL), NULL);
    A_decList front = decList;

    for(fieldList= fieldList->tail;fieldList;fieldList = fieldList->tail, decList = decList->tail) {
        field = fieldList->head;
        decList->tail = A_DecList(A_VarDec(field->pos, field->name, field->_type, NULL), NULL);
    }

    return front;
}
