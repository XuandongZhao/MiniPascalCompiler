/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "Pascal.y"


#include <stdio.h>
#include "util.h" 
#include "errormsg.h"
#include "symbol.h"
#include "absyn.h"

int yyerror(char* msg);
int yylex(void);
// root for parsed abstract syntax tree
A_exp ABSTRoot;

// helper function for constructing abstract tree
// link fieldlists
A_fieldList A_linkFieldList(A_fieldList front, A_fieldList tail);
// set type for fieldlist
A_fieldList A_setFieldListType(A_fieldList fieldList, A_ty ty);

// link declists
A_decList A_linkDecList(A_decList front, A_decList tail);
// set type for declist
A_decList A_setDecListType(A_decList decList, A_ty ty);

// convert fieldlist to declist
A_decList A_unDecList(A_fieldList fieldList);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 262 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 275 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNRULES -- Number of states.  */
#define YYNSTATES  234

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    14,    20,    21,    24,    25,
      31,    36,    38,    40,    42,    44,    47,    48,    51,    53,
      58,    60,    62,    64,    66,    70,    74,    79,    85,    89,
      96,   100,   102,   105,   106,   109,   111,   116,   119,   122,
     123,   128,   134,   139,   143,   146,   150,   151,   155,   157,
     161,   165,   168,   170,   172,   176,   180,   181,   183,   187,
     189,   191,   193,   195,   197,   199,   201,   203,   205,   209,
     216,   218,   223,   225,   230,   235,   241,   244,   245,   250,
     255,   264,   266,   268,   271,   275,   277,   281,   285,   289,
     293,   297,   301,   303,   307,   311,   315,   317,   321,   325,
     329,   331,   333,   338,   340,   345,   347,   351,   354,   357,
     362,   366,   370,   372,   374,   376,   378,   380,   382
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    61,    62,     7,    -1,    27,   109,    10,
      -1,    63,    89,    -1,    64,    65,    68,    75,    78,    -1,
      -1,    49,    66,    -1,    -1,   109,    24,    67,    10,    66,
      -1,   109,    24,    67,    10,    -1,    51,    -1,    52,    -1,
      54,    -1,   110,    -1,    32,    69,    -1,    -1,    70,    69,
      -1,    70,    -1,   109,    24,    71,    10,    -1,    72,    -1,
      73,    -1,   113,    -1,   109,    -1,     3,    74,     4,    -1,
      67,    50,    67,    -1,    12,    67,    50,    67,    -1,    12,
      67,    50,    12,    67,    -1,   109,    50,   109,    -1,    33,
       5,    72,     6,    34,    71,    -1,    74,     8,   109,    -1,
     109,    -1,    35,    76,    -1,    -1,    77,    76,    -1,    77,
      -1,    74,     9,    71,    10,    -1,    79,    78,    -1,    81,
      78,    -1,    -1,    80,    10,    83,    10,    -1,    28,   109,
      84,     9,    72,    -1,    82,    10,    83,    10,    -1,    29,
     109,    84,    -1,    63,    89,    -1,     3,    85,     4,    -1,
      -1,    85,    10,    86,    -1,    86,    -1,    87,     9,    72,
      -1,    88,     9,    72,    -1,    35,    74,    -1,    74,    -1,
      90,    -1,    30,    91,    31,    -1,    92,    10,    91,    -1,
      -1,   114,    -1,    51,     9,    93,    -1,    93,    -1,    94,
      -1,    95,    -1,    90,    -1,    96,    -1,    98,    -1,    99,
      -1,   100,    -1,   102,    -1,   109,    26,   104,    -1,   109,
       5,   104,     6,    26,   104,    -1,   109,    -1,   109,     3,
     108,     4,    -1,   112,    -1,   112,     3,   103,     4,    -1,
      48,     3,   107,     4,    -1,    36,   104,    37,    92,    97,
      -1,    38,    92,    -1,    -1,    39,    92,    42,   104,    -1,
      43,   104,    44,    92,    -1,    45,   109,    26,   104,   101,
     104,    44,    92,    -1,    40,    -1,    41,    -1,    47,    51,
      -1,   104,     8,   103,    -1,   104,    -1,   104,    20,   105,
      -1,   104,    21,   105,    -1,   104,    22,   105,    -1,   104,
      23,   105,    -1,   104,    24,   105,    -1,   104,    25,   105,
      -1,   105,    -1,   105,    11,   106,    -1,   105,    12,   106,
      -1,   105,    18,   106,    -1,   106,    -1,   106,    13,   107,
      -1,   106,    15,   107,    -1,   106,    17,   107,    -1,   107,
      -1,   109,    -1,   109,     3,   108,     4,    -1,   111,    -1,
     111,     3,   108,     4,    -1,    67,    -1,     3,   104,     4,
      -1,    19,   107,    -1,    12,   107,    -1,   109,     5,   104,
       6,    -1,   109,     7,   109,    -1,   108,     8,   104,    -1,
     104,    -1,    53,    -1,    55,    -1,    56,    -1,    57,    -1,
      58,    -1,     1,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    80,    81,    82,    95,    98,    99,   100,
     101,   102,   103,   104,   105,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   132,   133,   134,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   151,   152,   153,   154,   155,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   189,   190,   191,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   203,   204,   205,   206,   207,   208,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   225,   226,   227,   228,   229,   231
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LP", "RP", "LB", "RB", "DOT", "COMMA",
  "COLON", "SEMI", "PLUS", "MINUS", "MUL", "REALDIV", "INTDIV", "MOD",
  "AND", "OR", "NOT", "GE", "GT", "LE", "LT", "EQUAL", "UNEQUAL", "ASSIGN",
  "PROGRAM", "FUNCTION", "PROCEDURE", "BEGIN_T", "END", "TYPE", "ARRAY",
  "OF", "VAR", "IF", "THEN", "ELSE", "REPEAT", "TO", "DOWNTO", "UNTIL",
  "WHILE", "DO", "FOR", "CASE", "GOTO", "READ", "CONST", "DOTDOT",
  "INTEGER", "CHAR", "ID", "STRING", "SYS_CON", "SYS_FUNCT", "SYS_PROC",
  "SYS_TYPE", "$accept", "program", "program_head", "routine",
  "routine_head", "label_part", "const_part", "const_expr_list",
  "const_value", "type_part", "type_decl_list", "type_definition",
  "type_decl", "simple_type_decl", "array_type_decl", "name_list",
  "var_part", "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "sub_routine",
  "parameters", "para_decl_list", "para_type_list", "var_para_list",
  "val_para_list", "routine_body", "compound_stmt", "stmt_list", "stmt",
  "non_label_stmt", "assign_stmt", "proc_stmt", "if_stmt", "else_clause",
  "repeat_stmt", "while_stmt", "for_stmt", "direction", "goto_stmt",
  "expression_list", "expression", "expr", "term", "factor", "args_list",
  "id", "sys_con", "sys_funct", "sys_proc", "sys_type", "stat", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    62,    63,    64,    65,    65,    66,
      66,    67,    67,    67,    67,    68,    68,    69,    69,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    73,
      74,    74,    75,    75,    76,    76,    77,    78,    78,    78,
      79,    80,    81,    82,    83,    84,    84,    85,    85,    86,
      86,    87,    88,    89,    90,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      95,    95,    95,    95,    95,    96,    97,    97,    98,    99,
     100,   101,   101,   102,   103,   103,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   106,   106,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   109,   110,   111,   112,   113,   114
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     5,     0,     2,     0,     5,
       4,     1,     1,     1,     1,     2,     0,     2,     1,     4,
       1,     1,     1,     1,     3,     3,     4,     5,     3,     6,
       3,     1,     2,     0,     2,     1,     4,     2,     2,     0,
       4,     5,     4,     3,     2,     3,     0,     3,     1,     3,
       3,     2,     1,     1,     3,     3,     0,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     6,
       1,     4,     1,     4,     4,     5,     2,     0,     4,     4,
       8,     1,     1,     2,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       1,     1,     4,     1,     4,     1,     3,     2,     2,     4,
       3,     3,     1,     1,     1,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,   113,     0,     1,     0,     0,     8,
       3,     2,     0,     4,    53,     0,    16,     0,     0,     0,
       0,     0,     0,     0,     0,   116,    62,     0,     0,    59,
      60,    61,    63,    64,    65,    66,    67,    70,    72,    57,
       7,     0,     0,    33,   118,     0,     0,     0,    11,    12,
      13,   114,   115,   105,     0,    92,    96,   100,   101,    14,
     103,     0,     0,     0,    83,     0,     0,    54,     0,     0,
       0,     0,     0,     0,    15,    18,     0,     0,    39,     0,
     108,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    55,   112,     0,     0,    68,     0,
      85,     0,    17,     0,     0,    32,    35,    31,     0,     0,
       5,    39,     0,    39,     0,   106,    86,    87,    88,    89,
      90,    91,    77,    93,    94,    95,    97,    98,    99,     0,
       0,   110,     0,    78,    79,     0,    74,    71,     0,     0,
      73,     0,    10,     0,     0,     0,   117,     0,     0,    20,
      21,    23,    22,     0,     0,    34,    46,    46,    37,     6,
      38,     6,     0,    75,   102,   109,   104,    81,    82,     0,
     111,     0,    84,     9,     0,     0,     0,     0,    19,     0,
      30,     0,     0,     0,    43,     0,     0,     0,    76,     0,
      69,    24,     0,     0,    25,    28,    36,     0,    52,     0,
      48,     0,     0,     0,    44,    40,    42,     0,     0,    26,
       0,    51,    45,     0,     0,     0,    41,    80,    27,     0,
      47,    49,    50,    29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,   195,     9,    16,    40,    53,    43,
      74,    75,   158,   159,   160,   114,    78,   115,   116,   120,
     121,   122,   123,   124,   196,   193,   209,   210,   211,   212,
      13,    26,    27,    28,    29,    30,    31,    32,   173,    33,
      34,    35,   179,    36,   109,   105,    55,    56,    57,   106,
      58,    59,    60,    38,   162,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -181
static const yytype_int16 yypact[] =
{
      13,   -44,    47,  -181,  -181,    53,  -181,    73,    58,    62,
    -181,  -181,    77,  -181,  -181,   -44,    66,   111,   178,   157,
     178,   -44,    78,   120,   122,  -181,  -181,   101,   125,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,    12,   137,  -181,
    -181,   124,   -44,   114,  -181,   178,   178,   178,  -181,  -181,
    -181,  -181,  -181,  -181,   289,    25,    49,  -181,    68,  -181,
     150,   113,   243,   130,  -181,   178,   205,  -181,    77,   178,
     178,   178,   178,    51,  -181,   -44,   134,   -44,    72,   277,
    -181,  -181,   178,   178,   178,   178,   178,   178,   157,   178,
     178,   178,   178,   178,   178,   178,   178,   -44,   178,   178,
     157,   178,   155,  -181,  -181,   296,    31,     2,   296,   156,
     307,   151,  -181,    39,   118,  -181,   -44,  -181,   -44,   -44,
    -181,    72,   159,    72,   160,  -181,    25,    25,    25,    25,
      25,    25,   127,    49,    49,    49,  -181,  -181,  -181,    75,
     283,  -181,    81,   296,  -181,   255,  -181,  -181,   178,   141,
    -181,   178,   -44,   -44,    51,   167,  -181,   126,   164,  -181,
    -181,   128,  -181,   -44,    39,  -181,   172,   172,  -181,  -181,
    -181,  -181,   157,  -181,  -181,  -181,  -181,  -181,  -181,   178,
     296,   178,  -181,  -181,   106,   132,    92,    51,  -181,   -44,
    -181,   173,   -19,   168,  -181,    58,   176,   182,  -181,   249,
     296,  -181,    -2,   188,  -181,  -181,  -181,   -44,   187,    44,
    -181,   189,   192,    92,  -181,  -181,  -181,   157,    51,  -181,
     169,   187,  -181,   -19,    92,    92,  -181,  -181,  -181,    39,
    -181,  -181,  -181,  -181
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,  -181,  -181,   204,  -181,  -181,    57,   -45,  -181,
     136,  -181,  -160,  -180,  -181,  -146,  -181,    97,  -181,  -102,
    -181,  -181,  -181,  -181,    46,    52,  -181,    -8,  -181,  -181,
      23,    -6,   152,   -18,   161,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,    70,   -15,   251,    48,   -34,   -66,
      -1,  -181,  -181,  -181,  -181,  -181
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -57
static const yytype_int16 yytable[] =
{
       5,    61,    14,    54,   191,    62,   203,   184,   149,     4,
     218,    37,    80,    81,    41,    69,   207,    70,    37,   168,
      63,   170,    82,    83,    84,    85,    86,    87,   111,   139,
      79,   102,   142,   226,     4,   147,    89,    90,    71,   148,
       1,    76,   153,    91,   231,   232,   208,     6,   222,    48,
      49,   154,    50,    51,   223,   107,   108,   110,   136,   137,
     138,   221,    92,    10,    93,    37,    94,    37,   157,   233,
     132,    95,   155,    96,    76,    97,   117,   208,    17,   174,
      11,   140,   144,   148,   143,   176,   145,    37,    12,   148,
      48,    49,     4,    50,    51,   153,   141,   156,    42,    37,
     118,   119,    48,    49,   154,    50,    51,    12,   -56,   185,
     201,    15,   161,    18,   163,   117,    19,   166,   167,   157,
      20,    44,    21,    65,    22,    23,   163,   164,    24,    64,
       4,    66,    67,   180,    25,    68,   110,   133,   134,   135,
      72,   157,   204,    48,    49,     4,    50,    51,    73,    77,
     156,    41,   117,    98,   198,    99,   101,   219,   113,   146,
     150,   152,   190,   161,   199,   172,   200,   181,   157,   169,
     171,    37,   186,   228,   188,   192,   187,   213,   189,   157,
     157,    45,   202,   206,   157,   161,   215,    12,   205,    14,
      46,   117,   216,    18,   220,   163,    19,    47,   224,   227,
      20,   225,    21,   229,    22,    23,   117,     8,    24,   183,
       4,   112,   161,   165,    25,   230,    37,   197,   214,   194,
     104,   182,   117,   161,   161,     0,     0,   103,   161,    48,
      49,     4,    50,    51,    52,    12,     0,     0,     0,     0,
       0,    18,     0,     0,    19,     0,     0,     0,    20,     0,
      21,     0,    22,    23,     0,     0,     0,     0,     4,     0,
       0,     0,    25,    82,    83,    84,    85,    86,    87,    82,
      83,    84,    85,    86,    87,    82,    83,    84,    85,    86,
      87,   125,     0,     0,     0,     0,     0,   100,     0,   175,
       0,     0,     0,   217,     0,   177,   178,    82,    83,    84,
      85,    86,    87,    82,    83,    84,    85,    86,    87,    82,
      83,    84,    85,    86,    87,   151,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,    88,    82,    83,    84,
      85,    86,    87,   126,   127,   128,   129,   130,   131
};

static const yytype_int16 yycheck[] =
{
       1,    19,     8,    18,   164,    20,   186,   153,     6,    53,
      12,    12,    46,    47,    15,     3,    35,     5,    19,   121,
      21,   123,    20,    21,    22,    23,    24,    25,    73,    95,
      45,    65,    98,   213,    53,     4,    11,    12,    26,     8,
      27,    42,     3,    18,   224,   225,   192,     0,     4,    51,
      52,    12,    54,    55,    10,    70,    71,    72,    92,    93,
      94,   207,    13,    10,    15,    66,    17,    68,   113,   229,
      88,     3,    33,     5,    75,     7,    77,   223,     1,     4,
       7,    96,   100,     8,    99,     4,   101,    88,    30,     8,
      51,    52,    53,    54,    55,     3,    97,    58,    32,   100,
      28,    29,    51,    52,    12,    54,    55,    30,    31,   154,
       4,    49,   113,    36,     8,   116,    39,   118,   119,   164,
      43,    10,    45,     3,    47,    48,     8,     9,    51,    51,
      53,     9,    31,   148,    57,    10,   151,    89,    90,    91,
       3,   186,   187,    51,    52,    53,    54,    55,    24,    35,
      58,   152,   153,     3,   172,    42,    26,   202,    24,     4,
       4,    10,   163,   164,   179,    38,   181,    26,   213,    10,
      10,   172,     5,   218,    10,     3,    50,     9,    50,   224,
     225,     3,    50,    10,   229,   186,    10,    30,   189,   195,
      12,   192,    10,    36,     6,     8,    39,    19,     9,   217,
      43,     9,    45,    34,    47,    48,   207,     3,    51,   152,
      53,    75,   213,   116,    57,   223,   217,   171,   195,   167,
      68,   151,   223,   224,   225,    -1,    -1,    66,   229,    51,
      52,    53,    54,    55,    56,    30,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    39,    -1,    -1,    -1,    43,    -1,
      45,    -1,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    57,    20,    21,    22,    23,    24,    25,    20,
      21,    22,    23,    24,    25,    20,    21,    22,    23,    24,
      25,     4,    -1,    -1,    -1,    -1,    -1,    44,    -1,     6,
      -1,    -1,    -1,    44,    -1,    40,    41,    20,    21,    22,
      23,    24,    25,    20,    21,    22,    23,    24,    25,    20,
      21,    22,    23,    24,    25,     8,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    37,    20,    21,    22,
      23,    24,    25,    82,    83,    84,    85,    86,    87
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    60,    61,    53,   109,     0,    62,    63,    64,
      10,     7,    30,    89,    90,    49,    65,     1,    36,    39,
      43,    45,    47,    48,    51,    57,    90,    91,    92,    93,
      94,    95,    96,    98,    99,   100,   102,   109,   112,   114,
      66,   109,    32,    68,    10,     3,    12,    19,    51,    52,
      54,    55,    56,    67,   104,   105,   106,   107,   109,   110,
     111,    92,   104,   109,    51,     3,     9,    31,    10,     3,
       5,    26,     3,    24,    69,    70,   109,    35,    75,   104,
     107,   107,    20,    21,    22,    23,    24,    25,    37,    11,
      12,    18,    13,    15,    17,     3,     5,     7,     3,    42,
      44,    26,   107,    93,    91,   104,   108,   104,   104,   103,
     104,    67,    69,    24,    74,    76,    77,   109,    28,    29,
      78,    79,    80,    81,    82,     4,   105,   105,   105,   105,
     105,   105,    92,   106,   106,   106,   107,   107,   107,   108,
     104,   109,   108,   104,    92,   104,     4,     4,     8,     6,
       4,     8,    10,     3,    12,    33,    58,    67,    71,    72,
      73,   109,   113,     8,     9,    76,   109,   109,    78,    10,
      78,    10,    38,    97,     4,     6,     4,    40,    41,   101,
     104,    26,   103,    66,    74,    67,     5,    50,    10,    50,
     109,    71,     3,    84,    84,    63,    83,    83,    92,   104,
     104,     4,    50,    72,    67,   109,    10,    35,    74,    85,
      86,    87,    88,     9,    89,    10,    10,    44,    12,    67,
       6,    74,     4,    10,     9,     9,    72,    92,    67,    34,
      86,    72,    72,    71
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 79 "Pascal.y"
    {ABSTRoot = (yyvsp[(2) - (3)].exp);}
    break;

  case 3:
#line 80 "Pascal.y"
    {}
    break;

  case 4:
#line 81 "Pascal.y"
    {(yyval.exp) = A_LetExp(EM_tokPos, (yyvsp[(1) - (2)].declist), (yyvsp[(2) - (2)].exp));}
    break;

  case 5:
#line 82 "Pascal.y"
    {
        A_decList decList = A_DecList(A_TypeDec(0, NULL), NULL);
        if ((yyvsp[(2) - (5)].declist)) 
            A_linkDecList(decList, (yyvsp[(2) - (5)].declist));
        if ((yyvsp[(3) - (5)].declist))
            A_linkDecList(decList, (yyvsp[(3) - (5)].declist));
        if ((yyvsp[(4) - (5)].declist)) 
            A_linkDecList(decList, (yyvsp[(4) - (5)].declist));
        if ((yyvsp[(5) - (5)].fundeclist))
            A_linkDecList(decList, A_DecList(A_FunctionDec(EM_tokPos, (yyvsp[(5) - (5)].fundeclist)), NULL));
        (yyval.declist) = decList->tail;
    }
    break;

  case 6:
#line 95 "Pascal.y"
    {(yyval.declist) = NULL;}
    break;

  case 7:
#line 98 "Pascal.y"
    {(yyval.declist) = (yyvsp[(2) - (2)].declist);}
    break;

  case 8:
#line 99 "Pascal.y"
    {(yyval.declist) = NULL;}
    break;

  case 9:
#line 100 "Pascal.y"
    {(yyval.declist) = A_DecList(A_ConstDec(EM_tokPos, (yyvsp[(1) - (5)].sym), (yyvsp[(3) - (5)].exp)),(yyvsp[(5) - (5)].declist));}
    break;

  case 10:
#line 101 "Pascal.y"
    {(yyval.declist) = A_DecList(A_ConstDec(EM_tokPos, (yyvsp[(1) - (4)].sym), (yyvsp[(3) - (4)].exp)), NULL);}
    break;

  case 11:
#line 102 "Pascal.y"
    {(yyval.exp) = A_IntExp(EM_tokPos, (yyvsp[(1) - (1)].ival));}
    break;

  case 12:
#line 103 "Pascal.y"
    {(yyval.exp) = A_CharExp(EM_tokPos, (yyvsp[(1) - (1)].cval));}
    break;

  case 13:
#line 104 "Pascal.y"
    {(yyval.exp) = A_StringExp(EM_tokPos, (yyvsp[(1) - (1)].sval));}
    break;

  case 14:
#line 105 "Pascal.y"
    {/*$$ = A_SysConstExp(EM_tokPos, $1);*/}
    break;

  case 15:
#line 108 "Pascal.y"
    {(yyval.declist) = A_DecList(A_TypeDec(EM_tokPos, (yyvsp[(2) - (2)].nametylist)), NULL);}
    break;

  case 16:
#line 109 "Pascal.y"
    {(yyval.declist) = NULL;}
    break;

  case 17:
#line 110 "Pascal.y"
    {(yyval.nametylist) = A_NametyList((yyvsp[(1) - (2)].namety), (yyvsp[(2) - (2)].nametylist));}
    break;

  case 18:
#line 111 "Pascal.y"
    {(yyval.nametylist) = A_NametyList((yyvsp[(1) - (1)].namety), NULL);}
    break;

  case 19:
#line 112 "Pascal.y"
    {(yyval.namety) =A_Namety((yyvsp[(1) - (4)].sym), (yyvsp[(3) - (4)].ty));}
    break;

  case 20:
#line 113 "Pascal.y"
    {(yyval.ty) = (yyvsp[(1) - (1)].ty);}
    break;

  case 21:
#line 114 "Pascal.y"
    {(yyval.ty) = (yyvsp[(1) - (1)].ty);}
    break;

  case 22:
#line 115 "Pascal.y"
    {(yyval.ty) = A_NameTy(EM_tokPos, (yyvsp[(1) - (1)].sym));}
    break;

  case 23:
#line 116 "Pascal.y"
    {(yyval.ty) = A_NameTy(EM_tokPos, (yyvsp[(1) - (1)].sym));}
    break;

  case 24:
#line 117 "Pascal.y"
    {(yyval.ty) = A_EnumType(EM_tokPos, (yyvsp[(2) - (3)].fieldlist));}
    break;

  case 25:
#line 118 "Pascal.y"
    {(yyval.ty) = A_RangeTy(EM_tokPos, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 26:
#line 119 "Pascal.y"
    {A_RangeTy(EM_tokPos, A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), (yyvsp[(2) - (4)].exp)), (yyvsp[(4) - (4)].exp));}
    break;

  case 27:
#line 120 "Pascal.y"
    {A_RangeTy(EM_tokPos, A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), (yyvsp[(2) - (5)].exp)), A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), (yyvsp[(5) - (5)].exp)));}
    break;

  case 28:
#line 121 "Pascal.y"
    {A_RangeTy(EM_tokPos, A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[(1) - (3)].sym))), A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[(3) - (3)].sym))));}
    break;

  case 29:
#line 122 "Pascal.y"
    {(yyval.ty) = A_ArrayTy(EM_tokPos, (yyvsp[(3) - (6)].ty), (yyvsp[(6) - (6)].ty)->u.name);}
    break;

  case 30:
#line 123 "Pascal.y"
    {(yyval.fieldlist) = A_linkFieldList((yyvsp[(1) - (3)].fieldlist), A_FieldList(A_Field(EM_tokPos, (yyvsp[(3) - (3)].sym), NULL), NULL));}
    break;

  case 31:
#line 124 "Pascal.y"
    {(yyval.fieldlist) = A_FieldList(A_Field(EM_tokPos, (yyvsp[(1) - (1)].sym), NULL), NULL);}
    break;

  case 32:
#line 125 "Pascal.y"
    {(yyval.declist) = (yyvsp[(2) - (2)].declist);}
    break;

  case 33:
#line 126 "Pascal.y"
    {(yyval.declist) = NULL;}
    break;

  case 34:
#line 127 "Pascal.y"
    {(yyval.declist) = A_linkDecList((yyvsp[(1) - (2)].declist), (yyvsp[(2) - (2)].declist));}
    break;

  case 35:
#line 128 "Pascal.y"
    {(yyval.declist) = (yyvsp[(1) - (1)].declist);}
    break;

  case 36:
#line 129 "Pascal.y"
    {(yyval.declist) = A_setDecListType(A_unDecList((yyvsp[(1) - (4)].fieldlist)), (yyvsp[(3) - (4)].ty));}
    break;

  case 37:
#line 132 "Pascal.y"
    {(yyval.fundeclist) = A_FundecList((yyvsp[(1) - (2)].fundec), (yyvsp[(2) - (2)].fundeclist));}
    break;

  case 38:
#line 133 "Pascal.y"
    {(yyval.fundeclist) = A_FundecList((yyvsp[(1) - (2)].fundec), (yyvsp[(2) - (2)].fundeclist));}
    break;

  case 39:
#line 134 "Pascal.y"
    {(yyval.fundeclist) = NULL;}
    break;

  case 40:
#line 136 "Pascal.y"
    {(yyval.fundec) = (yyvsp[(1) - (4)].fundec); (yyval.fundec)->body = (yyvsp[(3) - (4)].exp);}
    break;

  case 41:
#line 137 "Pascal.y"
    {(yyval.fundec) = A_Fundec(EM_tokPos, (yyvsp[(2) - (5)].sym), (yyvsp[(3) - (5)].fieldlist), (yyvsp[(5) - (5)].ty)->u.name, NULL);}
    break;

  case 42:
#line 138 "Pascal.y"
    {(yyval.fundec) = (yyvsp[(1) - (4)].fundec); (yyval.fundec)->body = (yyvsp[(3) - (4)].exp);}
    break;

  case 43:
#line 139 "Pascal.y"
    {(yyval.fundec) = A_Fundec(EM_tokPos, (yyvsp[(2) - (3)].sym), (yyvsp[(3) - (3)].fieldlist), NULL, NULL);}
    break;

  case 44:
#line 140 "Pascal.y"
    {(yyval.exp) = A_LetExp(EM_tokPos, (yyvsp[(1) - (2)].declist), (yyvsp[(2) - (2)].exp));}
    break;

  case 45:
#line 141 "Pascal.y"
    {(yyval.fieldlist) = (yyvsp[(2) - (3)].fieldlist);}
    break;

  case 46:
#line 142 "Pascal.y"
    {(yyval.fieldlist) = NULL;}
    break;

  case 47:
#line 143 "Pascal.y"
    {(yyval.fieldlist) = A_linkFieldList((yyvsp[(1) - (3)].fieldlist), (yyvsp[(3) - (3)].fieldlist));}
    break;

  case 48:
#line 144 "Pascal.y"
    {(yyval.fieldlist) = (yyvsp[(1) - (1)].fieldlist);}
    break;

  case 49:
#line 145 "Pascal.y"
    {(yyval.fieldlist) = A_setFieldListType((yyvsp[(1) - (3)].fieldlist), (yyvsp[(3) - (3)].ty));}
    break;

  case 50:
#line 146 "Pascal.y"
    {(yyval.fieldlist) = A_setFieldListType((yyvsp[(1) - (3)].fieldlist), (yyvsp[(3) - (3)].ty));}
    break;

  case 51:
#line 147 "Pascal.y"
    {(yyval.fieldlist) = (yyvsp[(2) - (2)].fieldlist);}
    break;

  case 52:
#line 148 "Pascal.y"
    {(yyval.fieldlist) = (yyvsp[(1) - (1)].fieldlist);}
    break;

  case 53:
#line 151 "Pascal.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 54:
#line 152 "Pascal.y"
    {(yyval.exp) = A_SeqExp(EM_tokPos, (yyvsp[(2) - (3)].explist));}
    break;

  case 55:
#line 153 "Pascal.y"
    {(yyval.explist) = A_ExpList((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].explist));}
    break;

  case 56:
#line 154 "Pascal.y"
    {(yyval.explist) = NULL;}
    break;

  case 57:
#line 155 "Pascal.y"
    {(yyval.explist) = NULL;}
    break;

  case 58:
#line 157 "Pascal.y"
    {(yyval.exp) = (yyvsp[(3) - (3)].exp);}
    break;

  case 59:
#line 158 "Pascal.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 60:
#line 159 "Pascal.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 61:
#line 160 "Pascal.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 62:
#line 161 "Pascal.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 63:
#line 162 "Pascal.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 64:
#line 163 "Pascal.y"
    {  (yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 65:
#line 164 "Pascal.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 66:
#line 165 "Pascal.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 67:
#line 166 "Pascal.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 68:
#line 167 "Pascal.y"
    {(yyval.exp) = A_AssignExp(EM_tokPos,A_SimpleVar(EM_tokPos, (yyvsp[(1) - (3)].sym)), (yyvsp[(3) - (3)].exp));}
    break;

  case 69:
#line 168 "Pascal.y"
    {(yyval.exp) = A_AssignExp(EM_tokPos, A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[(1) - (6)].sym)), (yyvsp[(3) - (6)].exp)),(yyvsp[(6) - (6)].exp));}
    break;

  case 70:
#line 169 "Pascal.y"
    {(yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[(1) - (1)].sym), NULL);}
    break;

  case 71:
#line 170 "Pascal.y"
    {(yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[(1) - (4)].sym), (yyvsp[(3) - (4)].explist));}
    break;

  case 72:
#line 171 "Pascal.y"
    {(yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[(1) - (1)].sym), NULL);}
    break;

  case 73:
#line 172 "Pascal.y"
    {(yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[(1) - (4)].sym), (yyvsp[(3) - (4)].explist));}
    break;

  case 74:
#line 173 "Pascal.y"
    {}
    break;

  case 75:
#line 174 "Pascal.y"
    {(yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[(2) - (5)].exp), (yyvsp[(4) - (5)].exp), (yyvsp[(5) - (5)].exp));}
    break;

  case 76:
#line 175 "Pascal.y"
    {(yyval.exp) = (yyvsp[(2) - (2)].exp);}
    break;

  case 77:
#line 176 "Pascal.y"
    {(yyval.exp) = NULL;}
    break;

  case 78:
#line 177 "Pascal.y"
    {(yyval.exp) = A_RepeatExp(EM_tokPos, (yyvsp[(2) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 79:
#line 178 "Pascal.y"
    {(yyval.exp) = A_WhileExp(EM_tokPos, (yyvsp[(2) - (4)].exp), (yyvsp[(4) - (4)].exp));}
    break;

  case 80:
#line 179 "Pascal.y"
    {
    A_var var =  A_SimpleVar(EM_tokPos, (yyvsp[(2) - (8)].sym));
    if (!((yyvsp[(5) - (8)].cval))) {
        // to 
        (yyval.exp) = A_SeqExp(EM_tokPos, A_ExpList(A_AssignExp(EM_tokPos, var, (yyvsp[(4) - (8)].exp)), A_ExpList(A_WhileExp(EM_tokPos, A_OpExp(EM_tokPos, A_ltOp, A_VarExp(EM_tokPos, var), (yyvsp[(6) - (8)].exp)), (yyvsp[(8) - (8)].exp)), NULL )));
    } else {
        // downto 
        (yyval.exp) = A_SeqExp(EM_tokPos, A_ExpList(A_AssignExp(EM_tokPos, var, (yyvsp[(4) - (8)].exp)), A_ExpList(A_WhileExp(EM_tokPos, A_OpExp(EM_tokPos, A_gtOp, A_VarExp(EM_tokPos ,var), (yyvsp[(6) - (8)].exp)), (yyvsp[(8) - (8)].exp)), NULL )));
    }  
}
    break;

  case 81:
#line 189 "Pascal.y"
    {(yyval.cval) = 0;}
    break;

  case 82:
#line 190 "Pascal.y"
    {(yyval.cval) = 1;}
    break;

  case 83:
#line 191 "Pascal.y"
    {(yyval.exp) = A_GotoExp(EM_tokPos, A_IntExp(EM_tokPos, (yyvsp[(2) - (2)].ival)));}
    break;

  case 84:
#line 193 "Pascal.y"
    {(yyval.explist) = A_ExpList((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].explist));}
    break;

  case 85:
#line 194 "Pascal.y"
    {(yyval.explist) = A_ExpList((yyvsp[(1) - (1)].exp), NULL);}
    break;

  case 86:
#line 195 "Pascal.y"
    {(yyval.exp) = A_OpExp(EM_tokPos, A_geOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 87:
#line 196 "Pascal.y"
    {(yyval.exp) = A_OpExp(EM_tokPos, A_gtOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 88:
#line 197 "Pascal.y"
    {(yyval.exp) = A_OpExp(EM_tokPos, A_leOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 89:
#line 198 "Pascal.y"
    {(yyval.exp) = A_OpExp(EM_tokPos, A_ltOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 90:
#line 199 "Pascal.y"
    {(yyval.exp) = A_OpExp(EM_tokPos, A_eqOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 91:
#line 200 "Pascal.y"
    {(yyval.exp) = A_OpExp(EM_tokPos, A_neqOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 92:
#line 201 "Pascal.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 93:
#line 203 "Pascal.y"
    {(yyval.exp) = A_OpExp(EM_tokPos, A_plusOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 94:
#line 204 "Pascal.y"
    {(yyval.exp) = A_OpExp(EM_tokPos, A_minusOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 95:
#line 205 "Pascal.y"
    {(yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[(1) - (3)].exp), A_IntExp(EM_tokPos, 1), (yyvsp[(3) - (3)].exp));}
    break;

  case 96:
#line 206 "Pascal.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 97:
#line 207 "Pascal.y"
    {(yyval.exp) = A_OpExp(EM_tokPos, A_timesOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));}
    break;

  case 98:
#line 208 "Pascal.y"
    {(yyval.exp) = A_OpExp(EM_tokPos, A_divideOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 99:
#line 210 "Pascal.y"
    {(yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), A_IntExp(EM_tokPos, 0));}
    break;

  case 100:
#line 211 "Pascal.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 101:
#line 212 "Pascal.y"
    {(yyval.exp) = A_VarExp(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[(1) - (1)].sym)));}
    break;

  case 102:
#line 213 "Pascal.y"
    {(yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[(1) - (4)].sym), (yyvsp[(3) - (4)].explist));}
    break;

  case 103:
#line 214 "Pascal.y"
    {(yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[(1) - (1)].sym), NULL);}
    break;

  case 104:
#line 215 "Pascal.y"
    {(yyval.exp) = A_CallExp(EM_tokPos, (yyvsp[(1) - (4)].sym), (yyvsp[(3) - (4)].explist));}
    break;

  case 105:
#line 216 "Pascal.y"
    {(yyval.exp) = (yyvsp[(1) - (1)].exp);}
    break;

  case 106:
#line 217 "Pascal.y"
    {(yyval.exp) = (yyvsp[(2) - (3)].exp);}
    break;

  case 107:
#line 218 "Pascal.y"
    {(yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[(2) - (2)].exp), A_IntExp(EM_tokPos, 0), A_IntExp(EM_tokPos,1));}
    break;

  case 108:
#line 219 "Pascal.y"
    {(yyval.exp) = A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), (yyvsp[(2) - (2)].exp));}
    break;

  case 109:
#line 220 "Pascal.y"
    {(yyval.exp) = A_VarExp(EM_tokPos,A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[(1) - (4)].sym)), (yyvsp[(3) - (4)].exp)));}
    break;

  case 110:
#line 221 "Pascal.y"
    {(yyval.exp) = A_VarExp(EM_tokPos, A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, (yyvsp[(1) - (3)].sym)), (yyvsp[(3) - (3)].sym)));}
    break;

  case 111:
#line 222 "Pascal.y"
    {(yyval.explist) = (yyvsp[(1) - (3)].explist); (yyvsp[(1) - (3)].explist)->tail = A_ExpList((yyvsp[(3) - (3)].exp), NULL);}
    break;

  case 112:
#line 223 "Pascal.y"
    {(yyval.explist) = A_ExpList((yyvsp[(1) - (1)].exp), NULL);}
    break;

  case 113:
#line 225 "Pascal.y"
    {(yyval.sym) = S_Symbol((yyvsp[(1) - (1)].sval));}
    break;

  case 114:
#line 226 "Pascal.y"
    {(yyval.sym) = S_Symbol((yyvsp[(1) - (1)].sval));}
    break;

  case 115:
#line 227 "Pascal.y"
    {(yyval.sym) = S_Symbol((yyvsp[(1) - (1)].sval));}
    break;

  case 116:
#line 228 "Pascal.y"
    {(yyval.sym) = S_Symbol((yyvsp[(1) - (1)].sval));}
    break;

  case 117:
#line 229 "Pascal.y"
    {(yyval.sym) = S_Symbol((yyvsp[(1) - (1)].sval));}
    break;

  case 118:
#line 231 "Pascal.y"
    {/*jump to next semi after error */}
    break;


/* Line 1267 of yacc.c.  */
#line 2314 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 233 "Pascal.y"

int yyerror(char* msg) {
    EM_error(EM_tokPos, "%s", msg);
    return 0;   
}

A_fieldList A_linkFieldList(A_fieldList front, A_fieldList tail) { // link two fieldlists 
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
