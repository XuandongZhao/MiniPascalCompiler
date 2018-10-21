%{
#include<stdio.h>
#include "util.h"
#include "errormsg.h"
#include "symbol.h"
#include "absyn.h"
#include "y.tab.h"

void adjust(void);
int charPos;
%}
div             [dD][iI][vV]
mod             [mM][oO][dD]
integer         [0-9]+
char            [A-za-z\_\'\.\"]
string          \"char+\"
program         [pP][rR][oO][gG][rR][aA][mM]
const           [cC][oO][nN][sS][tT]
type            [tT][yY][pP][eE]
var             [vV][aA][rR]
array           [aA][rR][rR][aA][yY]
of              [oO][fF]
end             [eE][nN][dD]
function        [fF][uU][nN][cC][tT][iI][oO][nN]
procedure       [pP][rR][oO][cC][eE][dD][uU][rR][eE]
begin           [bB][eE][gG][iI][nN]
read            [rR][eE][aA][dD]
if              [iI][fF]
then            [tT][hH][eE][nN]
else            [eE][lL][sS][eE]
repeat          [rR][eE][pP][eE][aA][tT]
until           [uU][nN][tT][iI][lL]
while           [wW][hH][iI][lL][eE]
do              [dD][oO]
for             [fF][oO][rR]
to              [tT][oO]
downto          [dD][oO][wW][nN][tT][oO]
goto            [gG][oO][tT][oO]
and             [aA][nN][dD]
or              [oO][rR]
not             [nN][oO][tT]
false           [fF][aA][lL][sS][eE]
maxint          [mM][aA][xX][iI][nN][tT]
true            [tT][rR][uU][eE]
sys_con         false|maxint|true
abs             [aA][bB][sS]
chr             [cC][hH][rR]
odd             [oO][dD][dD]
ord             [oO][rR][dD]
pred            [pP][rR][eE][dD]
sqr             [sS][qQ][rR]
sqrt            [sS][qQ][rR][tT]
succ            [sS][uU[cC][cC]
sys_funct       abs|chr|odd|ord|pred|sqr|sqrt|succ
write           [wW][rR][iI][tT][eE]
writeln         [wW][rR][iI][tT][eE][lL][nN]
sys_proc        write|writeln
boolt           [bB][oO][oO][lL][eE][aA][nN]
cht             [cC][hH][aA][rR]
intt            [iI][nN][tT][eE][gG][eE][rR]
sys_type        boolt|cht|intt
%%

".."                {adjust(); return DOTDOT;}
"("                 {adjust(); return LP;}
")"                 {adjust(); return RP;}
"["                 {adjust(); return LB;}
"]"                 {adjust(); return RB;}
"."                 {adjust(); return DOT;}
","                 {adjust(); return COMMA; }
":"                 {adjust(); return COLON;}
";"                 {adjust(); return SEMI;}
"+"                 {adjust(); return PLUS;}
"-"                 {adjust(); return MINUS;}
"*"                 {adjust(); return MUL;}
"/"                 {adjust(); return REALDIV;}
{div}               {adjust(); return INTDIV;}
{mod}               {adjust(); return MOD; }
">="                {adjust(); return GE;}
">"                 {adjust(); return GT;}
"<="                {adjust(); return LE;}
"<"                 {adjust(); return LT;}
"="                 {adjust(); return EQUAL;}
"<>"                {adjust(); return UNEQUAL;}
":="                {adjust(); return ASSIGN;}
{program}             {adjust(); return PROGRAM;}
{const}               {adjust(); return CONST;}
{type}                {adjust(); return TYPE;}
{var}                 {adjust(); return VAR;}
{array}               {adjust(); return ARRAY;}
{of}                  {adjust(); return OF;}
{end}                 {adjust(); return END;}
{function}            {adjust(); return FUNCTION;}
{procedure}           {adjust(); return PROCEDURE;}
{begin}               {adjust(); return BEGIN_T;}
{read}                {adjust(); return READ;}
{if}                  {adjust(); return IF;}
{then}                {adjust(); return THEN;}
{else}                {adjust(); return ELSE;}
{repeat}              {adjust(); return REPEAT;}
{until}               {adjust(); return UNTIL;}
{while}               {adjust(); return WHILE;}
{do}                  {adjust(); return DO;}
{for}                 {adjust(); return FOR;}
{to}                  {adjust(); return TO;}
{downto}              {adjust(); return DOWNTO;}
{goto}                {adjust(); return GOTO;}
{and}                 {adjust(); return AND;}
{or}                  {adjust(); return OR;}
{not}                 {adjust(); return NOT;}
[a-zA-Z][0-9a-zA-Z]*  {adjust(); yylval.sval = yytext; return ID;}
{integer}         {
    adjust();
    int getNum;
    sscanf(yytext, "%d", &getNum);
    yylval.ival = getNum;
    return INTEGER;
}

{char}                {adjust(); yylval.cval = yytext[0]; return CHAR; }
{string}              {adjust(); yylval.sval = yytext; return STRING; }

\n                    {adjust(); EM_newline();}
\r\n                  {adjust(); EM_newline();}
[ \t+]                {adjust();}
.                     {adjust(); char message[100]; sprintf(message, "illegal token:%s", yytext);EM_error(EM_tokPos, message);}

%%

void adjust(void) {
    printf("%s",yytext);
    EM_tokPos = charPos;
    charPos += yyleng;
}

int yywrap(){
    charPos = 1;
    return 1;
}