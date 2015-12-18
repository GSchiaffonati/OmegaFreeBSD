/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20141006

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 23 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
#include "bconfig.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "gengtype.h"
#define YYERROR_VERBOSE
#line 31 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  type_p t;
  pair_p p;
  options_p o;
  const char *s;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 42 "gengtype-yacc.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ENT_TYPEDEF_STRUCT 257
#define ENT_STRUCT 258
#define ENT_EXTERNSTATIC 259
#define ENT_YACCUNION 260
#define GTY_TOKEN 261
#define UNION 262
#define STRUCT 263
#define ENUM 264
#define ALIAS 265
#define NESTED_PTR 266
#define PARAM_IS 267
#define NUM 268
#define PERCENTPERCENT 269
#define SCALAR 271
#define ID 272
#define STRING 273
#define ARRAY 274
#define PERCENT_ID 275
#define CHAR 276
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,   16,   13,   17,   13,   14,   14,
   14,    5,   18,   18,   15,    3,    3,    3,    2,    2,
    2,    1,    1,    1,    1,    1,   19,   19,   20,   20,
    4,    4,    4,    4,    4,    4,    4,    4,    4,   21,
   21,   21,   21,    6,    6,    7,   11,   11,    8,    8,
    8,    8,    9,    9,   10,   10,   12,   12,
};
static const YYINT yylen[] = {                            2,
    0,    2,    2,    2,    0,    8,    0,    7,    5,    6,
    7,    1,    1,    1,    6,    0,    3,    6,    0,    2,
    2,    0,    6,    6,    7,    5,    0,    2,    1,    1,
    1,    1,    2,    5,    2,    5,    2,    2,    5,    0,
    5,    3,    2,    0,    1,    6,    1,    1,    1,    4,
    4,    8,    1,    3,    0,    1,    1,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    2,    3,    4,    0,    0,    0,    0,
    0,    0,   31,   32,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   33,    0,   16,    0,    0,   45,
   47,    0,   48,    0,   53,    0,    0,    0,    0,    7,
    0,    0,    0,    0,   13,   14,    9,    0,   29,   30,
    0,    0,    0,    0,    0,    0,    0,    5,    0,    0,
    0,    0,    0,    0,   10,   15,    0,    0,    0,    0,
    0,    0,   57,    0,   54,   46,    0,    0,    8,   36,
   34,    0,    0,   43,   39,   11,    0,    0,   26,    0,
    0,   28,    0,    0,   58,   50,   51,    6,    0,   42,
    0,   20,   21,    0,   24,   23,    0,    0,   19,   25,
    0,   41,    0,    0,   52,
};
static const YYINT yydgoto[] = {                          5,
   27,   98,   58,   28,   26,   39,   10,   45,   46,   47,
   48,   84,    6,    7,    8,   88,   69,   57,   81,   61,
   73,
};
static const YYINT yysindex[] = {                      -180,
 -222, -222, -222, -222,    0, -180, -180, -180,    2,  -67,
  -61, -226, -226,    0,    0,    0,   30, -226, -226, -198,
 -184, -183,    0,    0,   48, -181,  -33,  -37, -213,  -32,
  -31,  -26,  -25,  -23,    0,  -28,    0, -207, -177,    0,
    0,   56,    0,   62,    0,   59,   63,   65, -166,    0,
 -226, -226, -165,  -27,    0,    0,    0, -212,    0,    0,
   49,  -49, -226, -164, -213,   69, -226,    0,   52,  -11,
  -10,  -42,   -9,   25,    0,    0,   53, -226,  -46, -207,
   58,   43,    0,  -41,    0,    0,  -12,   60,    0,    0,
    0, -150, -165,    0,    0,    0, -152, -205,    0,   64,
 -226,    0, -226, -164,    0,    0,    0,    0,   77,    0,
   66,    0,    0, -226,    0,    0,  -29, -165,    0,    0,
 -164,    0, -205,  -40,    0,
};
static const YYINT yyrindex[] = {                       122,
    0,    0,    0,    0,    0,  122,  122,  122,    0,    0,
    0,    0,   -1,    0,    0,    0,    0,   -1,   -1,    0,
    0,    0,    0,    0, -147,    0,    0, -146,   86,    0,
    0,  -38,  -34,  -30,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   31,    0,   88,    0,    0,    0,    0,
   -1,   -1,    5,    0,    0,    0,    0,    0,    0,    0,
    0,   72,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    5,    0,    0,    0,    0, -228,   -1,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    5,    0,    0,    0,    0, -211,    0,    0,
   -1,    0,   -1,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   -1,    0,    0,    0,    5,    0,    0,
    0,    0, -209,    0,    0,
};
static const YYINT yygindex[] = {                        75,
   -2,   13,    0,    6,    0,    0,   23,   68,    0,    0,
    0,  -81,    0,    0,    0,    0,    0,  -19,    0,   54,
  -50,
};
#define YYTABLESIZE 247
static const YYINT yytable[] = {                        106,
  125,   93,   37,   37,   35,   37,   35,   35,   80,   35,
   38,   38,  101,   38,  121,   30,   31,   25,   92,   37,
   38,   94,  117,   35,   11,   12,   13,   38,  107,   35,
   55,   55,   56,   56,   75,   20,   21,   22,    9,  124,
   19,   17,  110,   19,   23,   24,   19,   19,   70,   71,
   40,   41,   42,   43,   96,   18,   76,   17,   44,   18,
   59,   19,   77,   17,   60,   18,  112,  122,   82,   29,
  113,   49,   87,   32,   49,   99,    1,    2,    3,    4,
   14,   15,   16,   55,   35,   56,  104,   33,   34,   35,
   36,   37,   49,   50,   62,   63,   51,   52,  115,   53,
  116,   64,   65,   66,   67,   68,   72,   78,   83,   86,
   89,  120,   97,   90,   91,   95,  103,  109,  108,  111,
  118,    1,  114,   22,   12,   44,   55,  119,   56,   40,
   27,  123,   85,  102,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   37,    9,   79,    0,   35,  100,    0,   72,
   38,  105,  105,   37,    0,    0,    0,   35,    0,    0,
    0,   38,    0,  105,    0,   54,   74,
};
static const YYINT yycheck[] = {                         41,
   41,   44,   41,   42,   42,   44,   41,   42,   58,   44,
   41,   42,   59,   44,   44,   18,   19,   12,   61,   58,
   58,   72,  104,   58,    2,    3,    4,   58,   41,   42,
   59,   59,   61,   61,   54,  262,  263,  264,  261,  121,
  269,   40,   93,  272,  271,  272,  275,  276,   51,   52,
   28,  265,  266,  267,   74,  123,  269,  269,  272,  269,
  268,  123,  275,  275,  272,  275,  272,  118,   63,   40,
  276,   41,   67,  272,   44,   78,  257,  258,  259,  260,
    6,    7,    8,   59,   42,   61,   44,  272,  272,   42,
  272,  125,  125,  125,  272,   40,  123,  123,  101,  123,
  103,   40,   44,   41,   40,  272,  272,   59,  273,   41,
   59,  114,   60,  125,  125,  125,   59,  268,   59,  272,
   44,    0,   59,  125,  272,  272,   41,   62,   41,  125,
   59,  119,   65,   80,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  261,  261,  274,   -1,  261,  274,   -1,  272,
  261,  273,  273,  272,   -1,   -1,   -1,  272,   -1,   -1,
   -1,  272,   -1,  273,   -1,  274,  274,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 276
#define YYUNDFTOKEN 300
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'",0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,"':'","';'",
"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"ENT_TYPEDEF_STRUCT","ENT_STRUCT","ENT_EXTERNSTATIC",
"ENT_YACCUNION","GTY_TOKEN","UNION","STRUCT","ENUM","ALIAS","NESTED_PTR",
"PARAM_IS","NUM","PERCENTPERCENT","\"%%\"","SCALAR","ID","STRING","ARRAY",
"PERCENT_ID","CHAR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start :",
"start : typedef_struct start",
"start : externstatic start",
"start : yacc_union start",
"$$1 :",
"typedef_struct : ENT_TYPEDEF_STRUCT options '{' struct_fields '}' ID $$1 ';'",
"$$2 :",
"typedef_struct : ENT_STRUCT options '{' struct_fields '}' $$2 ';'",
"externstatic : ENT_EXTERNSTATIC options lasttype ID semiequal",
"externstatic : ENT_EXTERNSTATIC options lasttype ID ARRAY semiequal",
"externstatic : ENT_EXTERNSTATIC options lasttype ID ARRAY ARRAY semiequal",
"lasttype : type",
"semiequal : ';'",
"semiequal : '='",
"yacc_union : ENT_YACCUNION options struct_fields '}' yacc_typematch PERCENTPERCENT",
"yacc_typematch :",
"yacc_typematch : yacc_typematch PERCENT_ID yacc_ids",
"yacc_typematch : yacc_typematch PERCENT_ID '<' ID '>' yacc_ids",
"yacc_ids :",
"yacc_ids : yacc_ids ID",
"yacc_ids : yacc_ids CHAR",
"struct_fields :",
"struct_fields : type optionsopt ID bitfieldopt ';' struct_fields",
"struct_fields : type optionsopt ID ARRAY ';' struct_fields",
"struct_fields : type optionsopt ID ARRAY ARRAY ';' struct_fields",
"struct_fields : type ':' bitfieldlen ';' struct_fields",
"bitfieldopt :",
"bitfieldopt : ':' bitfieldlen",
"bitfieldlen : NUM",
"bitfieldlen : ID",
"type : SCALAR",
"type : ID",
"type : type '*'",
"type : STRUCT ID '{' struct_fields '}'",
"type : STRUCT ID",
"type : UNION ID '{' struct_fields '}'",
"type : UNION ID",
"type : ENUM ID",
"type : ENUM ID '{' enum_items '}'",
"enum_items :",
"enum_items : ID '=' NUM ',' enum_items",
"enum_items : ID ',' enum_items",
"enum_items : ID enum_items",
"optionsopt :",
"optionsopt : options",
"options : GTY_TOKEN '(' '(' optionseqopt ')' ')'",
"type_option : ALIAS",
"type_option : PARAM_IS",
"option : ID",
"option : ID '(' stringseq ')'",
"option : type_option '(' type ')'",
"option : NESTED_PTR '(' type ',' stringseq ',' stringseq ')'",
"optionseq : option",
"optionseq : optionseq ',' option",
"optionseqopt :",
"optionseqopt : optionseq",
"stringseq : STRING",
"stringseq : stringseq STRING",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 5:
#line 72 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
		     new_structure (yystack.l_mark[-5].t->u.s.tag, UNION_P (yystack.l_mark[-5].t), &lexer_line,
				    yystack.l_mark[-2].p, yystack.l_mark[-4].o);
		     do_typedef (yystack.l_mark[0].s, yystack.l_mark[-5].t, &lexer_line);
		     lexer_toplevel_done = 1;
		   }
break;
case 6:
#line 79 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{}
break;
case 7:
#line 81 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
		     new_structure (yystack.l_mark[-4].t->u.s.tag, UNION_P (yystack.l_mark[-4].t), &lexer_line,
				    yystack.l_mark[-1].p, yystack.l_mark[-3].o);
		     lexer_toplevel_done = 1;
		   }
break;
case 8:
#line 87 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{}
break;
case 9:
#line 91 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	           note_variable (yystack.l_mark[-1].s, adjust_field_type (yystack.l_mark[-2].t, yystack.l_mark[-3].o), yystack.l_mark[-3].o,
				  &lexer_line);
	         }
break;
case 10:
#line 96 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	           note_variable (yystack.l_mark[-2].s, create_array (yystack.l_mark[-3].t, yystack.l_mark[-1].s),
	      		    yystack.l_mark[-4].o, &lexer_line);
	         }
break;
case 11:
#line 101 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	           note_variable (yystack.l_mark[-3].s, create_array (create_array (yystack.l_mark[-4].t, yystack.l_mark[-1].s),
	      				      yystack.l_mark[-2].s),
	      		    yystack.l_mark[-5].o, &lexer_line);
	         }
break;
case 12:
#line 109 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	      lexer_toplevel_done = 1;
	      yyval.t = yystack.l_mark[0].t;
	    }
break;
case 15:
#line 121 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	        note_yacc_type (yystack.l_mark[-4].o, yystack.l_mark[-3].p, yystack.l_mark[-1].p, &lexer_line);
	      }
break;
case 16:
#line 127 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.p = NULL; }
break;
case 17:
#line 129 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
		     pair_p p;
		     for (p = yystack.l_mark[0].p; p->next != NULL; p = p->next)
		       {
		         p->name = NULL;
			 p->type = NULL;
		       }
		     p->name = NULL;
		     p->type = NULL;
		     p->next = yystack.l_mark[-2].p;
		     yyval.p = yystack.l_mark[0].p;
		   }
break;
case 18:
#line 142 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
		     pair_p p;
		     type_p newtype = NULL;
		     if (strcmp (yystack.l_mark[-4].s, "type") == 0)
		       newtype = (type_p) 1;
		     for (p = yystack.l_mark[0].p; p->next != NULL; p = p->next)
		       {
		         p->name = yystack.l_mark[-2].s;
		         p->type = newtype;
		       }
		     p->name = yystack.l_mark[-2].s;
		     p->next = yystack.l_mark[-5].p;
		     p->type = newtype;
		     yyval.p = yystack.l_mark[0].p;
		   }
break;
case 19:
#line 160 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.p = NULL; }
break;
case 20:
#line 162 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	  pair_p p = XCNEW (struct pair);
	  p->next = yystack.l_mark[-1].p;
	  p->line = lexer_line;
	  p->opt = XNEW (struct options);
	  p->opt->name = "tag";
	  p->opt->next = NULL;
	  p->opt->info = (char *)yystack.l_mark[0].s;
	  yyval.p = p;
	}
break;
case 21:
#line 173 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	  pair_p p = XCNEW (struct pair);
	  p->next = yystack.l_mark[-1].p;
	  p->line = lexer_line;
	  p->opt = XNEW (struct options);
	  p->opt->name = "tag";
	  p->opt->next = NULL;
	  p->opt->info = xasprintf ("'%s'", yystack.l_mark[0].s);
	  yyval.p = p;
	}
break;
case 22:
#line 185 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.p = NULL; }
break;
case 23:
#line 187 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	            pair_p p = XNEW (struct pair);
		    p->type = adjust_field_type (yystack.l_mark[-5].t, yystack.l_mark[-4].o);
		    p->opt = yystack.l_mark[-4].o;
		    p->name = yystack.l_mark[-3].s;
		    p->next = yystack.l_mark[0].p;
		    p->line = lexer_line;
		    yyval.p = p;
		  }
break;
case 24:
#line 197 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	            pair_p p = XNEW (struct pair);
		    p->type = adjust_field_type (create_array (yystack.l_mark[-5].t, yystack.l_mark[-2].s), yystack.l_mark[-4].o);
		    p->opt = yystack.l_mark[-4].o;
		    p->name = yystack.l_mark[-3].s;
		    p->next = yystack.l_mark[0].p;
		    p->line = lexer_line;
		    yyval.p = p;
		  }
break;
case 25:
#line 207 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	            pair_p p = XNEW (struct pair);
		    p->type = create_array (create_array (yystack.l_mark[-6].t, yystack.l_mark[-2].s), yystack.l_mark[-3].s);
		    p->opt = yystack.l_mark[-5].o;
		    p->name = yystack.l_mark[-4].s;
		    p->next = yystack.l_mark[0].p;
		    p->line = lexer_line;
		    yyval.p = p;
		  }
break;
case 26:
#line 217 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.p = yystack.l_mark[0].p; }
break;
case 30:
#line 225 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ }
break;
case 31:
#line 229 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.t = yystack.l_mark[0].t; }
break;
case 32:
#line 231 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.t = resolve_typedef (yystack.l_mark[0].s, &lexer_line); }
break;
case 33:
#line 233 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.t = create_pointer (yystack.l_mark[-1].t); }
break;
case 34:
#line 235 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.t = new_structure (yystack.l_mark[-3].s, 0, &lexer_line, yystack.l_mark[-1].p, NULL); }
break;
case 35:
#line 237 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.t = find_structure (yystack.l_mark[0].s, 0); }
break;
case 36:
#line 239 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.t = new_structure (yystack.l_mark[-3].s, 1, &lexer_line, yystack.l_mark[-1].p, NULL); }
break;
case 37:
#line 241 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.t = find_structure (yystack.l_mark[0].s, 1); }
break;
case 38:
#line 243 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.t = create_scalar_type (yystack.l_mark[0].s, strlen (yystack.l_mark[0].s)); }
break;
case 39:
#line 245 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.t = create_scalar_type (yystack.l_mark[-3].s, strlen (yystack.l_mark[-3].s)); }
break;
case 41:
#line 250 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ }
break;
case 42:
#line 252 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ }
break;
case 43:
#line 254 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ }
break;
case 44:
#line 257 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.o = NULL; }
break;
case 45:
#line 258 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.o = yystack.l_mark[0].o; }
break;
case 46:
#line 262 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.o = yystack.l_mark[-2].o; }
break;
case 47:
#line 266 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.s = "ptr_alias"; }
break;
case 48:
#line 268 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.s = yystack.l_mark[0].s; }
break;
case 49:
#line 272 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.o = create_option (NULL, yystack.l_mark[0].s, (void *)""); }
break;
case 50:
#line 274 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.o = create_option (NULL, yystack.l_mark[-3].s, (void *)yystack.l_mark[-1].s); }
break;
case 51:
#line 276 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.o = create_option (NULL, yystack.l_mark[-3].s, adjust_field_type (yystack.l_mark[-1].t, NULL)); }
break;
case 52:
#line 278 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	      struct nested_ptr_data d;

	      d.type = adjust_field_type (yystack.l_mark[-5].t, NULL);
	      d.convert_to = yystack.l_mark[-3].s;
	      d.convert_from = yystack.l_mark[-1].s;
	      yyval.o = create_option (NULL, "nested_ptr",
				  xmemdup (&d, sizeof (d), sizeof (d)));
	    }
break;
case 53:
#line 290 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	        yystack.l_mark[0].o->next = NULL;
		yyval.o = yystack.l_mark[0].o;
	      }
break;
case 54:
#line 295 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	        yystack.l_mark[0].o->next = yystack.l_mark[-2].o;
		yyval.o = yystack.l_mark[0].o;
	      }
break;
case 55:
#line 301 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.o = NULL; }
break;
case 56:
#line 302 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.o = yystack.l_mark[0].o; }
break;
case 57:
#line 306 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{ yyval.s = yystack.l_mark[0].s; }
break;
case 58:
#line 308 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/gengtype-yacc.y"
	{
	       size_t l1 = strlen (yystack.l_mark[-1].s);
	       size_t l2 = strlen (yystack.l_mark[0].s);
	       char *s = XRESIZEVEC (char, yystack.l_mark[-1].s, l1 + l2 + 1);
	       memcpy (s + l1, yystack.l_mark[0].s, l2 + 1);
	       XDELETE (yystack.l_mark[0].s);
	       yyval.s = s;
	     }
break;
#line 847 "gengtype-yacc.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
