/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LP = 258,
     RP = 259,
     LB = 260,
     RB = 261,
     DOT = 262,
     COMMA = 263,
     COLON = 264,
     SEMI = 265,
     PLUS = 266,
     MINUS = 267,
     MUL = 268,
     REALDIV = 269,
     INTDIV = 270,
     MOD = 271,
     AND = 272,
     OR = 273,
     NOT = 274,
     GE = 275,
     GT = 276,
     LE = 277,
     LT = 278,
     EQUAL = 279,
     UNEQUAL = 280,
     ASSIGN = 281,
     PROGRAM = 282,
     FUNCTION = 283,
     PROCEDURE = 284,
     BEGIN_T = 285,
     END = 286,
     TYPE = 287,
     ARRAY = 288,
     OF = 289,
     VAR = 290,
     IF = 291,
     THEN = 292,
     ELSE = 293,
     REPEAT = 294,
     TO = 295,
     DOWNTO = 296,
     UNTIL = 297,
     WHILE = 298,
     DO = 299,
     FOR = 300,
     CASE = 301,
     GOTO = 302,
     READ = 303,
     CONST = 304,
     DOTDOT = 305,
     INTEGER = 306,
     CHAR = 307,
     ID = 308,
     STRING = 309,
     SYS_CON = 310,
     SYS_FUNCT = 311,
     SYS_PROC = 312,
     SYS_TYPE = 313
   };
#endif
/* Tokens.  */
#define LP 258
#define RP 259
#define LB 260
#define RB 261
#define DOT 262
#define COMMA 263
#define COLON 264
#define SEMI 265
#define PLUS 266
#define MINUS 267
#define MUL 268
#define REALDIV 269
#define INTDIV 270
#define MOD 271
#define AND 272
#define OR 273
#define NOT 274
#define GE 275
#define GT 276
#define LE 277
#define LT 278
#define EQUAL 279
#define UNEQUAL 280
#define ASSIGN 281
#define PROGRAM 282
#define FUNCTION 283
#define PROCEDURE 284
#define BEGIN_T 285
#define END 286
#define TYPE 287
#define ARRAY 288
#define OF 289
#define VAR 290
#define IF 291
#define THEN 292
#define ELSE 293
#define REPEAT 294
#define TO 295
#define DOWNTO 296
#define UNTIL 297
#define WHILE 298
#define DO 299
#define FOR 300
#define CASE 301
#define GOTO 302
#define READ 303
#define CONST 304
#define DOTDOT 305
#define INTEGER 306
#define CHAR 307
#define ID 308
#define STRING 309
#define SYS_CON 310
#define SYS_FUNCT 311
#define SYS_PROC 312
#define SYS_TYPE 313




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 39 "Pascal.y"
{
    int pos;
    int ival; 
    double rval;
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
/* Line 1529 of yacc.c.  */
#line 186 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

