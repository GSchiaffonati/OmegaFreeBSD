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

#line 22 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
#include <stdio.h>

#include "dtc.h"
#include "srcpos.h"

YYLTYPE yylloc;

extern int yylex(void);
extern void print_error(char const *fmt, ...);
extern void yyerror(char const *s);

extern struct boot_info *the_boot_info;
extern bool treesource_error;
#line 37 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char *propnodename;
	char *labelref;
	unsigned int cbase;
	uint8_t byte;
	struct data data;

	struct {
		struct data	data;
		int		bits;
	} array;

	struct property *prop;
	struct property *proplist;
	struct node *node;
	struct node *nodelist;
	struct reserve_info *re;
	uint64_t integer;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 62 "dtc-parser.tab.c"

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

#define DT_V1 257
#define DT_MEMRESERVE 258
#define DT_LSHIFT 259
#define DT_RSHIFT 260
#define DT_LE 261
#define DT_GE 262
#define DT_EQ 263
#define DT_NE 264
#define DT_AND 265
#define DT_OR 266
#define DT_BITS 267
#define DT_DEL_PROP 268
#define DT_DEL_NODE 269
#define DT_PROPNODENAME 270
#define DT_LITERAL 271
#define DT_CHAR_LITERAL 272
#define DT_BASE 273
#define DT_BYTE 274
#define DT_STRING 275
#define DT_LABEL 276
#define DT_REF 277
#define DT_INCBIN 278
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    4,    4,    3,    3,    9,    9,    9,    9,   10,
    8,    8,    7,    7,    7,    7,    1,    1,    1,    1,
    1,    1,    1,    2,    2,    2,    5,    5,    5,    5,
    5,   13,   13,   13,   26,   25,   25,   24,   24,   23,
   23,   22,   22,   21,   21,   20,   20,   19,   19,   19,
   18,   18,   18,   18,   18,   17,   17,   17,   16,   16,
   16,   15,   15,   15,   15,   14,   14,   14,   14,    6,
    6,    6,   12,   12,   12,   11,   11,   11,
};
static const YYINT yylen[] = {                            2,
    4,    0,    2,    4,    2,    2,    3,    3,    4,    5,
    0,    2,    4,    2,    3,    2,    2,    3,    4,    2,
    9,    5,    2,    0,    2,    2,    3,    1,    2,    2,
    2,    1,    1,    3,    1,    1,    5,    1,    3,    1,
    3,    1,    3,    1,    3,    1,    3,    1,    3,    3,
    1,    3,    3,    3,    3,    3,    3,    1,    3,    3,
    1,    3,    3,    3,    1,    1,    2,    2,    2,    0,
    2,    2,    0,    2,    2,    2,    3,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,   32,   33,    0,
    0,    5,    3,    0,    0,    0,    0,    0,   66,   65,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   35,    0,    0,   11,    6,    0,    0,    0,   67,   68,
   69,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   34,    4,    0,    0,    8,    7,   63,   62,   64,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   12,
    0,    0,    9,    0,    0,    0,   14,   24,   76,   16,
   78,   75,   74,    0,   37,   15,   77,    0,    0,   10,
   23,   13,   25,    0,   17,   26,   20,    0,   70,   28,
    0,    0,    0,    0,   31,   30,   18,   29,   27,    0,
   71,   72,   19,    0,   22,    0,    0,    0,   21,
};
static const YYINT yydgoto[] = {                          2,
  108,  109,    6,    7,  121,  124,   90,   63,   15,   35,
   91,   92,   19,   20,   21,   22,   23,   24,   25,   26,
   27,   28,   29,   30,   31,   32,
};
static const YYINT yysindex[] = {                      -243,
  -29,    0, -245,  -39, -245, -245,  -27,    0,    0,  -33,
  -39,    0,    0,  -86,  -32,  -33,  -33,  -33,    0,    0,
   77,    5, -203,  -51, -184,    4,  -31,  -66, -198,  -58,
    0,   32,   23,    0,    0, -185,  -86,  -86,    0,    0,
    0,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,
    0,    0, -120,   39,    0,    0,    0,    0,    0,   77,
   77,    5,    5, -203, -203, -203, -203,  -51,  -51, -184,
    4,  -31,  -66, -198,   44, -158, -142,  -40, -120,    0,
 -120,   16,    0,  -33,   80,   84,    0,    0,    0,    0,
    0,    0,    0,  100,    0,    0,    0,  -42,  222,    0,
    0,    0,    0, -117,    0,    0,    0,  125,    0,    0,
  -36,  102, -102,  -75,    0,    0,    0,    0,    0,   -6,
    0,    0,    0,  -39,    0,  130,  -39,  138,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  136,    0,    0,  136,    0,    0,    0,    0,
    0,    0,    0,    0,  187,    0,    0,    0,    0,    0,
  -35,   14,   43,  311,  334,   53,  -17,   88,  -19,  -25,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   63,    0,    0,    0,    0,    0,    0,   -9,
    2,   28,   37,   72,   82,   95,  122,  332,  338,  340,
  269,   46,  134,  123,    0,    0,    0,    0,    0,    0,
   63,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  185,  189,    0,    0,   36,    0,    0,   33,
  104,  107,   57,  242,  126,   70,  153,  115,  145,  151,
  152,  154,  155,    0,  119,  157,
};
#define YYTABLESIZE 606
static const YYINT yytable[] = {                         18,
   10,  113,   61,   10,   60,   61,   10,   61,   52,   61,
   51,   16,    4,    1,   38,   36,  112,  133,   97,   14,
   98,   38,   61,   42,   61,  127,   61,   61,   59,    3,
    5,   59,   36,   59,  135,   59,   34,  134,   38,   60,
   42,   55,   60,   38,   60,   42,   60,   45,   59,   46,
   59,   58,   59,   59,   58,   47,   48,   57,   61,   60,
   11,   60,   56,   60,   60,   56,   58,   33,   56,   65,
   66,   58,   61,   58,   57,   58,   58,   57,   53,   54,
   51,   62,   34,   51,   59,   56,   43,   56,   61,   56,
   56,   64,   17,   44,   57,   60,   57,   93,   57,   57,
   51,   94,   51,   43,   51,   51,   42,   58,   43,   54,
   44,   95,   54,   44,   59,   44,   72,   73,   43,   55,
   99,   56,   55,   42,  100,   60,  102,   96,   40,   54,
   57,   54,   53,   54,   54,   53,   51,   58,  106,   55,
  104,   55,  107,   55,   55,   40,   44,   86,   87,   88,
   40,   56,   53,  122,   53,   89,   53,   53,  110,   52,
   57,  129,   52,   39,  123,   54,   51,   78,   79,   43,
   70,   71,  130,  137,   41,   55,   44,  128,  139,   52,
   39,   52,    2,   52,   52,   39,    1,   73,   53,   12,
  136,   41,  101,  138,   13,   54,   41,  103,  131,   80,
  132,   74,   75,   76,   77,   55,   81,   59,   82,   49,
   50,   83,  105,   84,    0,   52,   85,    0,   53,    0,
    0,    0,    0,   61,   61,   61,   61,   61,   61,   61,
   61,    8,    9,  111,    8,    9,   36,    8,    9,  125,
  126,    0,    0,    0,   37,   52,   38,   42,   42,   59,
   59,   59,   59,   59,   59,   59,   59,   39,   40,   41,
   60,   60,   60,   60,   60,   60,   60,   60,    0,    0,
    0,    0,   58,   58,   58,   58,   58,   58,   58,   58,
    0,  120,    0,   67,   68,   69,   56,   56,   56,   56,
   56,   56,   56,   56,    0,   57,   57,   57,   57,   57,
   57,   57,   57,   51,   51,   51,   51,   51,   51,   45,
   43,   43,  119,    0,    0,    0,    0,   44,   44,    0,
    0,    0,    0,    0,    0,    0,   45,    0,    0,    0,
    0,   45,   54,   54,   54,   54,   54,   54,    0,    0,
    0,    0,   55,   55,   55,   55,   55,   55,   48,    0,
    0,   48,   40,   40,    0,   53,   53,   53,   53,   53,
   53,    0,   45,    0,    0,    0,    0,    0,   48,   49,
    0,   46,   49,   48,   46,   50,    0,   47,   50,    0,
   47,    0,   52,   52,   52,   52,   52,   52,   39,   49,
    0,   46,   45,    0,   49,   50,   46,   47,   41,   41,
   50,    0,   47,    0,   48,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   49,    0,   46,    0,    0,
    0,   50,    0,   47,   48,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   49,    0,   46,    0,    0,
    0,   50,    0,   47,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  114,    0,
    0,    0,    0,    0,    0,    0,  115,  116,  117,  118,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   45,   45,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   48,   48,   48,   48,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   49,   49,   49,   49,   46,   46,
   50,   50,   50,   50,   47,   47,
};
static const YYINT yycheck[] = {                         33,
   40,   44,   38,   40,   63,   41,   40,   43,   60,   45,
   62,   45,  258,  257,   47,   41,   59,   93,   59,   47,
   61,   41,   58,   41,   60,   62,   62,   63,   38,   59,
  276,   41,   58,   43,   41,   45,  123,   44,   58,   38,
   58,   38,   41,   63,   43,   63,   45,   43,   58,   45,
   60,   38,   62,   63,   41,  259,  260,  124,   94,   58,
    4,   60,   94,   62,   63,   38,  265,   11,   41,   37,
   38,   58,   41,   60,   38,   62,   63,   41,  263,  264,
   38,   59,  123,   41,   94,   58,   41,   60,  124,   62,
   63,  277,  126,   41,   58,   94,   60,   59,   62,   63,
   58,   58,   60,   58,   62,   63,  124,   94,   63,   38,
   58,  270,   41,   37,  124,   63,   47,   48,   42,   38,
   88,   94,   41,   47,   89,  124,   91,  270,   41,   58,
   94,   60,   38,   62,   63,   41,   94,  124,   59,   58,
  125,   60,   59,   62,   63,   58,   94,  268,  269,  270,
   63,  124,   58,  271,   60,  276,   62,   63,   59,   38,
  124,   60,   41,   41,   40,   94,  124,   53,   54,  124,
   45,   46,  275,   44,   41,   94,  124,  121,   41,   58,
   58,   60,   47,   62,   63,   63,    0,  125,   94,    5,
  134,   58,   89,  137,    6,  124,   63,   91,  274,   55,
  276,   49,   50,   51,   52,  124,   56,  266,   57,  261,
  262,   58,   94,   59,   -1,   94,   60,   -1,  124,   -1,
   -1,   -1,   -1,  259,  260,  261,  262,  263,  264,  265,
  266,  271,  272,  276,  271,  272,  269,  271,  272,  276,
  277,   -1,   -1,   -1,  277,  124,  266,  265,  266,  259,
  260,  261,  262,  263,  264,  265,  266,   16,   17,   18,
  259,  260,  261,  262,  263,  264,  265,  266,   -1,   -1,
   -1,   -1,  259,  260,  261,  262,  263,  264,  265,  266,
   -1,   60,   -1,   42,   43,   44,  259,  260,  261,  262,
  263,  264,  265,  266,   -1,  259,  260,  261,  262,  263,
  264,  265,  266,  261,  262,  263,  264,  265,  266,   41,
  265,  266,   91,   -1,   -1,   -1,   -1,  265,  266,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   58,   -1,   -1,   -1,
   -1,   63,  261,  262,  263,  264,  265,  266,   -1,   -1,
   -1,   -1,  261,  262,  263,  264,  265,  266,   38,   -1,
   -1,   41,  265,  266,   -1,  261,  262,  263,  264,  265,
  266,   -1,   94,   -1,   -1,   -1,   -1,   -1,   58,   38,
   -1,   38,   41,   63,   41,   38,   -1,   38,   41,   -1,
   41,   -1,  261,  262,  263,  264,  265,  266,  266,   58,
   -1,   58,  124,   -1,   63,   58,   63,   58,  265,  266,
   63,   -1,   63,   -1,   94,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   94,   -1,   94,   -1,   -1,
   -1,   94,   -1,   94,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  124,   -1,  124,   -1,   -1,
   -1,  124,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  275,  276,  277,  278,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  265,  266,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  263,  264,  265,  266,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  263,  264,  265,  266,  265,  266,
  263,  264,  265,  266,  265,  266,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#define YYUNDFTOKEN 307
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,"':'","';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"DT_V1",
"DT_MEMRESERVE","DT_LSHIFT","DT_RSHIFT","DT_LE","DT_GE","DT_EQ","DT_NE",
"DT_AND","DT_OR","DT_BITS","DT_DEL_PROP","DT_DEL_NODE","DT_PROPNODENAME",
"DT_LITERAL","DT_CHAR_LITERAL","DT_BASE","DT_BYTE","DT_STRING","DT_LABEL",
"DT_REF","DT_INCBIN",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : sourcefile",
"sourcefile : DT_V1 ';' memreserves devicetree",
"memreserves :",
"memreserves : memreserve memreserves",
"memreserve : DT_MEMRESERVE integer_prim integer_prim ';'",
"memreserve : DT_LABEL memreserve",
"devicetree : '/' nodedef",
"devicetree : devicetree '/' nodedef",
"devicetree : devicetree DT_REF nodedef",
"devicetree : devicetree DT_DEL_NODE DT_REF ';'",
"nodedef : '{' proplist subnodes '}' ';'",
"proplist :",
"proplist : proplist propdef",
"propdef : DT_PROPNODENAME '=' propdata ';'",
"propdef : DT_PROPNODENAME ';'",
"propdef : DT_DEL_PROP DT_PROPNODENAME ';'",
"propdef : DT_LABEL propdef",
"propdata : propdataprefix DT_STRING",
"propdata : propdataprefix arrayprefix '>'",
"propdata : propdataprefix '[' bytestring ']'",
"propdata : propdataprefix DT_REF",
"propdata : propdataprefix DT_INCBIN '(' DT_STRING ',' integer_prim ',' integer_prim ')'",
"propdata : propdataprefix DT_INCBIN '(' DT_STRING ')'",
"propdata : propdata DT_LABEL",
"propdataprefix :",
"propdataprefix : propdata ','",
"propdataprefix : propdataprefix DT_LABEL",
"arrayprefix : DT_BITS DT_LITERAL '<'",
"arrayprefix : '<'",
"arrayprefix : arrayprefix integer_prim",
"arrayprefix : arrayprefix DT_REF",
"arrayprefix : arrayprefix DT_LABEL",
"integer_prim : DT_LITERAL",
"integer_prim : DT_CHAR_LITERAL",
"integer_prim : '(' integer_expr ')'",
"integer_expr : integer_trinary",
"integer_trinary : integer_or",
"integer_trinary : integer_or '?' integer_expr ':' integer_trinary",
"integer_or : integer_and",
"integer_or : integer_or DT_OR integer_and",
"integer_and : integer_bitor",
"integer_and : integer_and DT_AND integer_bitor",
"integer_bitor : integer_bitxor",
"integer_bitor : integer_bitor '|' integer_bitxor",
"integer_bitxor : integer_bitand",
"integer_bitxor : integer_bitxor '^' integer_bitand",
"integer_bitand : integer_eq",
"integer_bitand : integer_bitand '&' integer_eq",
"integer_eq : integer_rela",
"integer_eq : integer_eq DT_EQ integer_rela",
"integer_eq : integer_eq DT_NE integer_rela",
"integer_rela : integer_shift",
"integer_rela : integer_rela '<' integer_shift",
"integer_rela : integer_rela '>' integer_shift",
"integer_rela : integer_rela DT_LE integer_shift",
"integer_rela : integer_rela DT_GE integer_shift",
"integer_shift : integer_shift DT_LSHIFT integer_add",
"integer_shift : integer_shift DT_RSHIFT integer_add",
"integer_shift : integer_add",
"integer_add : integer_add '+' integer_mul",
"integer_add : integer_add '-' integer_mul",
"integer_add : integer_mul",
"integer_mul : integer_mul '*' integer_unary",
"integer_mul : integer_mul '/' integer_unary",
"integer_mul : integer_mul '%' integer_unary",
"integer_mul : integer_unary",
"integer_unary : integer_prim",
"integer_unary : '-' integer_unary",
"integer_unary : '~' integer_unary",
"integer_unary : '!' integer_unary",
"bytestring :",
"bytestring : bytestring DT_BYTE",
"bytestring : bytestring DT_LABEL",
"subnodes :",
"subnodes : subnode subnodes",
"subnodes : subnode propdef",
"subnode : DT_PROPNODENAME nodedef",
"subnode : DT_DEL_NODE DT_PROPNODENAME ';'",
"subnode : DT_LABEL subnode",

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
#line 463 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"

void print_error(char const *fmt, ...)
{
	va_list va;

	va_start(va, fmt);
	srcpos_verror(&yylloc, "Error", fmt, va);
	va_end(va);

	treesource_error = true;
}

void yyerror(char const *s) {
	print_error("%s", s);
}
#line 481 "dtc-parser.tab.c"

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
case 1:
#line 106 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			the_boot_info = build_boot_info(yystack.l_mark[-1].re, yystack.l_mark[0].node,
							guess_boot_cpuid(yystack.l_mark[0].node));
		}
break;
case 2:
#line 114 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.re = NULL;
		}
break;
case 3:
#line 118 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.re = chain_reserve_entry(yystack.l_mark[-1].re, yystack.l_mark[0].re);
		}
break;
case 4:
#line 125 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.re = build_reserve_entry(yystack.l_mark[-2].integer, yystack.l_mark[-1].integer);
		}
break;
case 5:
#line 129 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			add_label(&yystack.l_mark[0].re->labels, yystack.l_mark[-1].labelref);
			yyval.re = yystack.l_mark[0].re;
		}
break;
case 6:
#line 137 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.node = name_node(yystack.l_mark[0].node, "");
		}
break;
case 7:
#line 141 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.node = merge_nodes(yystack.l_mark[-2].node, yystack.l_mark[0].node);
		}
break;
case 8:
#line 145 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			struct node *target = get_node_by_ref(yystack.l_mark[-2].node, yystack.l_mark[-1].labelref);

			if (target)
				merge_nodes(target, yystack.l_mark[0].node);
			else
				print_error("label or path, '%s', not found", yystack.l_mark[-1].labelref);
			yyval.node = yystack.l_mark[-2].node;
		}
break;
case 9:
#line 155 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			struct node *target = get_node_by_ref(yystack.l_mark[-3].node, yystack.l_mark[-1].labelref);

			if (!target)
				print_error("label or path, '%s', not found", yystack.l_mark[-1].labelref);
			else
				delete_node(target);

			yyval.node = yystack.l_mark[-3].node;
		}
break;
case 10:
#line 169 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.node = build_node(yystack.l_mark[-3].proplist, yystack.l_mark[-2].nodelist);
		}
break;
case 11:
#line 176 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.proplist = NULL;
		}
break;
case 12:
#line 180 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.proplist = chain_property(yystack.l_mark[0].prop, yystack.l_mark[-1].proplist);
		}
break;
case 13:
#line 187 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.prop = build_property(yystack.l_mark[-3].propnodename, yystack.l_mark[-1].data);
		}
break;
case 14:
#line 191 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.prop = build_property(yystack.l_mark[-1].propnodename, empty_data);
		}
break;
case 15:
#line 195 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.prop = build_property_delete(yystack.l_mark[-1].propnodename);
		}
break;
case 16:
#line 199 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			add_label(&yystack.l_mark[0].prop->labels, yystack.l_mark[-1].labelref);
			yyval.prop = yystack.l_mark[0].prop;
		}
break;
case 17:
#line 207 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_merge(yystack.l_mark[-1].data, yystack.l_mark[0].data);
		}
break;
case 18:
#line 211 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_merge(yystack.l_mark[-2].data, yystack.l_mark[-1].array.data);
		}
break;
case 19:
#line 215 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_merge(yystack.l_mark[-3].data, yystack.l_mark[-1].data);
		}
break;
case 20:
#line 219 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_add_marker(yystack.l_mark[-1].data, REF_PATH, yystack.l_mark[0].labelref);
		}
break;
case 21:
#line 223 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			FILE *f = srcfile_relative_open(yystack.l_mark[-5].data.val, NULL);
			struct data d;

			if (yystack.l_mark[-3].integer != 0)
				if (fseek(f, yystack.l_mark[-3].integer, SEEK_SET) != 0)
					die("Couldn't seek to offset %llu in \"%s\": %s",
					    (unsigned long long)yystack.l_mark[-3].integer, yystack.l_mark[-5].data.val,
					    strerror(errno));

			d = data_copy_file(f, yystack.l_mark[-1].integer);

			yyval.data = data_merge(yystack.l_mark[-8].data, d);
			fclose(f);
		}
break;
case 22:
#line 239 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			FILE *f = srcfile_relative_open(yystack.l_mark[-1].data.val, NULL);
			struct data d = empty_data;

			d = data_copy_file(f, -1);

			yyval.data = data_merge(yystack.l_mark[-4].data, d);
			fclose(f);
		}
break;
case 23:
#line 249 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_add_marker(yystack.l_mark[-1].data, LABEL, yystack.l_mark[0].labelref);
		}
break;
case 24:
#line 256 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = empty_data;
		}
break;
case 25:
#line 260 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = yystack.l_mark[-1].data;
		}
break;
case 26:
#line 264 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_add_marker(yystack.l_mark[-1].data, LABEL, yystack.l_mark[0].labelref);
		}
break;
case 27:
#line 271 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			unsigned long long bits;

			bits = yystack.l_mark[-1].integer;

			if ((bits !=  8) && (bits != 16) &&
			    (bits != 32) && (bits != 64))
			{
				print_error("Only 8, 16, 32 and 64-bit elements"
					    " are currently supported");
				bits = 32;
			}

			yyval.array.data = empty_data;
			yyval.array.bits = bits;
		}
break;
case 28:
#line 288 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.array.data = empty_data;
			yyval.array.bits = 32;
		}
break;
case 29:
#line 293 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			if (yystack.l_mark[-1].array.bits < 64) {
				uint64_t mask = (1ULL << yystack.l_mark[-1].array.bits) - 1;
				/*
				 * Bits above mask must either be all zero
				 * (positive within range of mask) or all one
				 * (negative and sign-extended). The second
				 * condition is true if when we set all bits
				 * within the mask to one (i.e. | in the
				 * mask), all bits are one.
				 */
				if ((yystack.l_mark[0].integer > mask) && ((yystack.l_mark[0].integer | mask) != -1ULL))
					print_error(
						"integer value out of range "
						"%016lx (%d bits)", yystack.l_mark[-1].array.bits);
			}

			yyval.array.data = data_append_integer(yystack.l_mark[-1].array.data, yystack.l_mark[0].integer, yystack.l_mark[-1].array.bits);
		}
break;
case 30:
#line 313 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			uint64_t val = ~0ULL >> (64 - yystack.l_mark[-1].array.bits);

			if (yystack.l_mark[-1].array.bits == 32)
				yystack.l_mark[-1].array.data = data_add_marker(yystack.l_mark[-1].array.data,
							  REF_PHANDLE,
							  yystack.l_mark[0].labelref);
			else
				print_error("References are only allowed in "
					    "arrays with 32-bit elements.");

			yyval.array.data = data_append_integer(yystack.l_mark[-1].array.data, val, yystack.l_mark[-1].array.bits);
		}
break;
case 31:
#line 327 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.array.data = data_add_marker(yystack.l_mark[-1].array.data, LABEL, yystack.l_mark[0].labelref);
		}
break;
case 34:
#line 336 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.integer = yystack.l_mark[-1].integer;
		}
break;
case 37:
#line 347 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-4].integer ? yystack.l_mark[-2].integer : yystack.l_mark[0].integer; }
break;
case 39:
#line 352 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer || yystack.l_mark[0].integer; }
break;
case 41:
#line 357 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer && yystack.l_mark[0].integer; }
break;
case 43:
#line 362 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer | yystack.l_mark[0].integer; }
break;
case 45:
#line 367 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer ^ yystack.l_mark[0].integer; }
break;
case 47:
#line 372 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer & yystack.l_mark[0].integer; }
break;
case 49:
#line 377 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer == yystack.l_mark[0].integer; }
break;
case 50:
#line 378 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer != yystack.l_mark[0].integer; }
break;
case 52:
#line 383 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer < yystack.l_mark[0].integer; }
break;
case 53:
#line 384 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer > yystack.l_mark[0].integer; }
break;
case 54:
#line 385 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer <= yystack.l_mark[0].integer; }
break;
case 55:
#line 386 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer >= yystack.l_mark[0].integer; }
break;
case 56:
#line 390 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer << yystack.l_mark[0].integer; }
break;
case 57:
#line 391 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer >> yystack.l_mark[0].integer; }
break;
case 59:
#line 396 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer + yystack.l_mark[0].integer; }
break;
case 60:
#line 397 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer - yystack.l_mark[0].integer; }
break;
case 62:
#line 402 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer * yystack.l_mark[0].integer; }
break;
case 63:
#line 403 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer / yystack.l_mark[0].integer; }
break;
case 64:
#line 404 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = yystack.l_mark[-2].integer % yystack.l_mark[0].integer; }
break;
case 67:
#line 410 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = -yystack.l_mark[0].integer; }
break;
case 68:
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = ~yystack.l_mark[0].integer; }
break;
case 69:
#line 412 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{ yyval.integer = !yystack.l_mark[0].integer; }
break;
case 70:
#line 417 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = empty_data;
		}
break;
case 71:
#line 421 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_append_byte(yystack.l_mark[-1].data, yystack.l_mark[0].byte);
		}
break;
case 72:
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.data = data_add_marker(yystack.l_mark[-1].data, LABEL, yystack.l_mark[0].labelref);
		}
break;
case 73:
#line 432 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.nodelist = NULL;
		}
break;
case 74:
#line 436 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.nodelist = chain_node(yystack.l_mark[-1].node, yystack.l_mark[0].nodelist);
		}
break;
case 75:
#line 440 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			print_error("syntax error: properties must precede subnodes");
			YYERROR;
		}
break;
case 76:
#line 448 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.node = name_node(yystack.l_mark[0].node, yystack.l_mark[-1].propnodename);
		}
break;
case 77:
#line 452 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			yyval.node = name_node(build_node_delete(), yystack.l_mark[-1].propnodename);
		}
break;
case 78:
#line 456 "/usr/home/freebsd/omega/src/gnu/usr.bin/dtc/../../../contrib/dtc/dtc-parser.y"
	{
			add_label(&yystack.l_mark[0].node->labels, yystack.l_mark[-1].labelref);
			yyval.node = yystack.l_mark[0].node;
		}
break;
#line 1093 "dtc-parser.tab.c"
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
