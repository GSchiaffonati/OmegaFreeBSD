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

#line 47 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"

#include "defs.h"
#include "gdb_string.h"
#include <ctype.h>
#include "expression.h"
#include "value.h"
#include "parser-defs.h"
#include "language.h"
#include "p-lang.h"
#include "bfd.h" /* Required by objfiles.h.  */
#include "symfile.h" /* Required by objfiles.h.  */
#include "objfiles.h" /* For have_full_symbols and have_partial_symbols */
#include "block.h"

/* Remap normal yacc parser interface names (yyparse, yylex, yyerror, etc),
   as well as gratuitiously global symbol names, so we can have multiple
   yacc generated parsers in gdb.  Note that these are only the variables
   produced by yacc.  If other parser generators (bison, byacc, etc) produce
   additional global names that conflict at link time, then those parser
   generators need to be fixed instead of adding those names to this list. */

#define	yymaxdepth pascal_maxdepth
#define	yyparse	pascal_parse
#define	yylex	pascal_lex
#define	yyerror	pascal_error
#define	yylval	pascal_lval
#define	yychar	pascal_char
#define	yydebug	pascal_debug
#define	yypact	pascal_pact	
#define	yyr1	pascal_r1			
#define	yyr2	pascal_r2			
#define	yydef	pascal_def		
#define	yychk	pascal_chk		
#define	yypgo	pascal_pgo		
#define	yyact	pascal_act
#define	yyexca	pascal_exca
#define yyerrflag pascal_errflag
#define yynerrs	pascal_nerrs
#define	yyps	pascal_ps
#define	yypv	pascal_pv
#define	yys	pascal_s
#define	yy_yys	pascal_yys
#define	yystate	pascal_state
#define	yytmp	pascal_tmp
#define	yyv	pascal_v
#define	yy_yyv	pascal_yyv
#define	yyval	pascal_val
#define	yylloc	pascal_lloc
#define yyreds	pascal_reds		/* With YYDEBUG defined */
#define yytoks	pascal_toks		/* With YYDEBUG defined */
#define yyname	pascal_name		/* With YYDEBUG defined */
#define yyrule	pascal_rule		/* With YYDEBUG defined */
#define yylhs	pascal_yylhs
#define yylen	pascal_yylen
#define yydefred pascal_yydefred
#define yydgoto	pascal_yydgoto
#define yysindex pascal_yysindex
#define yyrindex pascal_yyrindex
#define yygindex pascal_yygindex
#define yytable	 pascal_yytable
#define yycheck	 pascal_yycheck

#ifndef YYDEBUG
#define	YYDEBUG 1		/* Default to yydebug support */
#endif

#define YYFPRINTF parser_fprintf

int yyparse (void);

static int yylex (void);

void
yyerror (char *);

static char * uptok (char *, int);
#line 129 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
  {
    LONGEST lval;
    struct {
      LONGEST val;
      struct type *type;
    } typed_val_int;
    struct {
      DOUBLEST dval;
      struct type *type;
    } typed_val_float;
    struct symbol *sym;
    struct type *tval;
    struct stoken sval;
    struct ttype tsym;
    struct symtoken ssym;
    int voidval;
    struct block *bval;
    enum exp_opcode opcode;
    struct internalvar *ivar;

    struct type **tvec;
    int *ivec;
  } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 155 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
/* YYSTYPE gets defined by %union */
static int
parse_number (char *, int, int, YYSTYPE *);

static struct type *current_type;

static void push_current_type (void);
static void pop_current_type (void);
static int search_field;
#line 140 "p-exp.c"

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

#define INT 257
#define FLOAT 258
#define STRING 259
#define FIELDNAME 260
#define NAME 261
#define TYPENAME 262
#define NAME_OR_INT 263
#define STRUCT 264
#define CLASS 265
#define SIZEOF 266
#define COLONCOLON 267
#define ERROR 268
#define VARIABLE 269
#define THIS 270
#define TRUEKEYWORD 271
#define FALSEKEYWORD 272
#define ABOVE_COMMA 273
#define ASSIGN 274
#define NOT 275
#define OR 276
#define XOR 277
#define ANDAND 278
#define NOTEQUAL 279
#define LEQ 280
#define GEQ 281
#define LSH 282
#define RSH 283
#define DIV 284
#define MOD 285
#define UNARY 286
#define INCREMENT 287
#define DECREMENT 288
#define ARROW 289
#define BLOCKNAME 290
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
   13,    0,    4,    4,    3,    2,    2,    1,    1,    1,
    1,    1,    1,   14,    1,   15,    1,   17,    1,   16,
   16,   16,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,   12,   12,    5,    6,    5,    5,    5,    9,
    7,    7,    8,    8,    8,    8,   10,   10,   10,   10,
   11,   11,
};
static const YYINT yylen[] = {                            2,
    0,    2,    1,    1,    1,    1,    3,    2,    2,    2,
    2,    4,    4,    0,    4,    0,    5,    0,    5,    0,
    1,    3,    4,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    1,    1,    1,    1,    1,    1,    1,    4,
    1,    1,    1,    3,    3,    3,    1,    2,    1,    1,
    1,    3,    2,    1,    2,    2,    1,    1,    1,    1,
    1,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,   45,   47,   51,   71,   64,   46,    0,    0,
    0,    0,   49,   52,   43,   44,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    4,    2,   48,   57,
    0,    0,   61,   59,    0,   67,   69,   70,   68,   65,
   66,    0,   58,    0,    0,    0,    0,    0,    0,    0,
   63,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   14,
   16,   18,    8,    0,    0,    0,    0,    0,    0,    0,
    0,   24,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   62,   56,    0,   50,    0,
   12,   13,   15,    0,    0,    0,   23,   17,    0,   19,
    0,
};
static const YYINT yydgoto[] = {                          1,
   25,   26,   27,   28,   29,   30,   45,   32,   33,   40,
   34,   35,    2,  101,  102,  116,  103,
};
static const YYINT yysindex[] = {                         0,
    0,  534,    0,    0,    0,    0,    0,    0,  -28,  -28,
  -35,  -28,    0,    0,    0,    0,  534,  534,  534,  -27,
  -22,  534,  -86,    0,  599,  -11,    0,    0,    0,    0,
   -5, -230,    0,    0, -229,    0,    0,    0,    0,    0,
    0,  -86,    0,   70,   -5,   70,   70,  534,  534,  -24,
    0,  534,  534,  534,  534,  534,  534,  534,  534,  534,
  534,  534,  534,  534,  534,  534,  534,  534,  534,    0,
    0,    0,    0,  534,  534,  -40,  -28,    9, -228,  549,
  561,    0,  599,  611,  623,  825,  875,  875,  -36,  -36,
  -36,  -36,  494,  494,  494,  494,  536,  536,   70,   70,
 -209,  534,  534,  599,  573,    0,    0,    0,    0,   30,
    0,    0,    0,  -41,  599,  -19,    0,    0,  534,    0,
  599,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    1,   12,   74,    0,    0,    0,    0,
   75,   14,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   36,    0,   59,   89,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   50,    0,
    0,    0,   32,  504,   49,   16,   82,  491,  445,  456,
  469,  482,  170,  183,  196,  287,  146,  158,  112,  124,
    0,    0,  -15,  229,    0,    0,    0,   24,    0,    0,
    0,    0,    0,    0,  -14,    0,    0,    0,    0,    0,
  -13,
};
static const YYINT yygindex[] = {                         0,
  893,   -3,    0,    0,    0,    0,   -2,   -8,    0,   11,
    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1160
static const YYINT yytable[] = {                         31,
   72,  106,   74,   72,   42,   68,   66,   23,   67,   70,
   69,    6,   48,   60,   51,   39,   82,   49,   50,   74,
   41,  120,   43,   55,  119,   20,   21,   22,   20,   21,
   22,   42,   74,   79,   75,   11,   76,   77,  110,   78,
   72,   72,   72,   72,   72,   72,   72,   72,   40,  109,
  113,  118,    6,   60,   71,    6,   39,   73,    9,   39,
   72,   72,   72,   55,   55,   55,   55,   55,   55,   55,
   55,  106,   42,    3,    5,   42,   11,   11,   11,   11,
   11,   33,   11,   55,   55,   55,  107,  108,   10,   40,
   60,   72,   40,   72,   72,   11,   11,   11,  114,    9,
    9,    9,    9,    9,    6,    9,    0,    0,   39,   72,
    0,   25,    0,    0,   55,   70,   55,   55,    9,    9,
    9,    0,   33,   26,   42,   33,    0,    0,   11,   10,
   10,   10,   10,   10,    0,   10,    0,    0,    0,    0,
    0,   40,   33,    0,    0,   29,    0,    0,   10,   10,
   10,    9,   25,   25,   25,   25,   25,   30,   25,    0,
   71,    0,    0,   73,   26,   26,   26,   26,   26,   31,
   26,   25,   25,   25,   33,    7,    0,    9,   10,    0,
    0,   10,   32,   26,   26,   26,   29,    0,   29,   29,
   29,    0,    0,    0,    0,   27,    0,    0,   30,    0,
   30,   30,   30,    0,   25,   29,   29,   29,    0,    0,
   31,    0,    0,   31,    0,    0,   26,   30,   30,   30,
   36,   37,   38,   32,    0,    0,   32,    0,    7,   31,
   31,   31,   36,   37,   38,    0,   27,    0,   29,   27,
    0,    0,   32,   32,   32,   62,   63,   64,   65,   39,
   30,    0,    0,    0,    0,   27,   27,   27,    0,    0,
    0,   39,   31,    0,    0,    0,    0,   53,    0,    7,
    0,    0,    7,    0,   72,   32,   72,   72,   72,   72,
   72,   72,   72,   72,   72,   72,   28,    0,   27,   39,
   54,   39,   39,   39,    0,    0,    0,   55,    0,   55,
   55,   55,   55,   55,   55,   55,   55,   55,   55,   11,
    0,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,    7,   40,    0,   40,   40,    0,   28,    0,    0,
   28,    0,    9,    0,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    0,    0,   28,   28,   28,    0,
    0,    0,    0,    0,    0,   33,    0,   33,   33,   33,
   33,    0,   10,    0,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   10,    0,    0,    0,    0,    0,   28,
    0,    0,    0,    0,    0,   25,    0,   25,   25,   25,
   25,   25,   25,   25,   25,   25,   25,   26,    0,   26,
   26,   26,   26,   26,   26,   26,   26,   26,   26,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   29,
    0,   29,   29,   29,   29,   29,   29,   29,   29,   29,
   29,   30,    0,   30,   30,   30,   30,   30,   30,   30,
   30,   30,   30,   31,   37,   31,   31,   31,   31,   31,
   31,   31,   31,   31,   31,   38,   32,    0,   32,   32,
   32,   32,   32,   32,   32,   32,   32,   32,   35,   27,
    0,   27,   27,   27,   27,   27,   27,   27,   27,   27,
   27,   36,    0,    0,    0,   37,    0,    0,   37,    0,
   34,    0,    0,    0,    0,    0,   38,    0,    0,   38,
    0,    0,    0,   41,   37,   37,   37,    0,    0,   35,
    0,    0,   35,    0,    0,   38,   38,   38,    0,    0,
    0,    0,   36,    0,    0,   36,    0,    0,   35,   35,
   35,   34,    0,   72,   34,   68,   66,   37,   67,   70,
   69,   36,   36,   36,   41,    0,    0,   41,   38,    0,
    0,   34,    0,    0,    0,    0,    0,    0,    0,    0,
   28,   35,   28,   28,   28,   28,   28,   28,   28,   28,
   28,   28,    0,   22,   36,   72,    0,   68,   19,    0,
    0,   70,   69,   34,   71,    0,    0,   73,   72,  111,
   68,   66,    0,   67,   70,   69,   41,   18,    0,    0,
   72,  112,   68,   66,    0,   67,   70,   69,   58,   56,
   59,    0,   72,  117,   68,   66,    0,   67,   70,   69,
   58,   56,   59,    0,    0,    0,   71,   23,    0,   73,
    0,    0,   58,   56,   59,    0,    0,    0,   72,   71,
   68,   66,   73,   67,   70,   69,    0,    0,    0,    0,
   72,   71,   68,   66,   73,   67,   70,   69,   58,   56,
   59,    0,   72,   71,   68,   66,   73,   67,   70,   69,
   58,   56,   59,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   58,   56,   59,    0,    0,    0,    0,   71,
    0,    0,   73,    0,    0,    0,    0,    0,    0,    0,
    0,   71,    0,    0,   73,    0,    0,    0,    0,    0,
    0,    0,    0,   71,    0,    0,   73,    0,   37,    0,
   37,   37,   37,   37,   37,   37,    0,    0,    0,   38,
    0,   38,   38,   38,   38,   38,   38,    0,    0,    0,
    0,    0,   35,    0,   35,   35,   35,   35,   35,   35,
    0,    0,    0,    0,    0,   36,    0,   36,   36,   36,
   36,   36,   36,    0,   34,    0,   34,   34,   34,   34,
    0,    0,    0,    0,    0,    0,    0,   41,    0,   41,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    3,    4,    5,    0,    6,    7,    8,    9,   10,   11,
   12,    0,   13,   14,   15,   16,    0,    0,   17,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   20,   21,   52,   24,   53,   54,   55,   57,   60,   61,
   62,   63,   64,   65,   52,    0,   53,   54,   55,   57,
   60,   61,   62,   63,   64,   65,   52,    0,   53,   54,
   55,   57,   60,   61,   62,   63,   64,   65,    0,    0,
    0,    0,    0,    0,   72,    0,   68,   66,    0,   67,
   70,   69,   52,    0,   53,   54,   55,   57,   60,   61,
   62,   63,   64,   65,   58,   56,   59,   54,   55,   57,
   60,   61,   62,   63,   64,   65,    0,    0,    0,    0,
   55,   57,   60,   61,   62,   63,   64,   65,    0,   44,
   46,   47,    0,    0,   72,   71,   68,   66,   73,   67,
   70,   69,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   58,    0,   59,    0,    0,    0,
   80,   81,    0,    0,   83,   84,   85,   86,   87,   88,
   89,   90,   91,   92,   93,   94,   95,   96,   97,   98,
   99,  100,    0,    0,    0,   71,  104,  105,   73,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  115,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  121,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   57,   60,   61,   62,   63,   64,   65,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   60,   61,   62,   63,   64,   65,
};
static const YYINT yycheck[] = {                          2,
    0,   42,   44,   40,   40,   42,   43,   94,   45,   46,
   47,    0,   40,    0,   23,    0,   41,   40,   22,   44,
   10,   41,   12,    0,   44,   41,   41,   41,   44,   44,
   44,    0,   44,   42,   40,    0,  267,  267,  267,   42,
   40,   41,   42,   43,   44,   45,   46,   47,    0,   41,
  260,   93,   41,   40,   91,   44,   41,   94,    0,   44,
   60,   61,   62,   40,   41,   42,   43,   44,   45,   46,
   47,   42,   41,    0,    0,   44,   41,   42,   43,   44,
   45,    0,   47,   60,   61,   62,   76,   77,    0,   41,
   41,   91,   44,   93,   94,   60,   61,   62,  102,   41,
   42,   43,   44,   45,   93,   47,   -1,   -1,   93,   40,
   -1,    0,   -1,   -1,   91,   46,   93,   94,   60,   61,
   62,   -1,   41,    0,   93,   44,   -1,   -1,   93,   41,
   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,   93,   61,   -1,   -1,    0,   -1,   -1,   60,   61,
   62,   93,   41,   42,   43,   44,   45,    0,   47,   -1,
   91,   -1,   -1,   94,   41,   42,   43,   44,   45,    0,
   47,   60,   61,   62,   93,  262,   -1,  264,  265,   -1,
   -1,   93,    0,   60,   61,   62,   41,   -1,   43,   44,
   45,   -1,   -1,   -1,   -1,    0,   -1,   -1,   41,   -1,
   43,   44,   45,   -1,   93,   60,   61,   62,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,   93,   60,   61,   62,
  261,  262,  263,   41,   -1,   -1,   44,   -1,    0,   60,
   61,   62,  261,  262,  263,   -1,   41,   -1,   93,   44,
   -1,   -1,   60,   61,   62,  282,  283,  284,  285,  290,
   93,   -1,   -1,   -1,   -1,   60,   61,   62,   -1,   -1,
   -1,  290,   93,   -1,   -1,   -1,   -1,  267,   -1,   41,
   -1,   -1,   44,   -1,  274,   93,  276,  277,  278,  279,
  280,  281,  282,  283,  284,  285,    0,   -1,   93,  274,
  267,  276,  277,  278,   -1,   -1,   -1,  274,   -1,  276,
  277,  278,  279,  280,  281,  282,  283,  284,  285,  274,
   -1,  276,  277,  278,  279,  280,  281,  282,  283,  284,
  285,   93,  274,   -1,  276,  277,   -1,   41,   -1,   -1,
   44,   -1,  274,   -1,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  285,   -1,   -1,   60,   61,   62,   -1,
   -1,   -1,   -1,   -1,   -1,  274,   -1,  276,  277,  278,
  279,   -1,  274,   -1,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  285,   -1,   -1,   -1,   -1,   -1,   93,
   -1,   -1,   -1,   -1,   -1,  274,   -1,  276,  277,  278,
  279,  280,  281,  282,  283,  284,  285,  274,   -1,  276,
  277,  278,  279,  280,  281,  282,  283,  284,  285,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
   -1,  276,  277,  278,  279,  280,  281,  282,  283,  284,
  285,  274,   -1,  276,  277,  278,  279,  280,  281,  282,
  283,  284,  285,  274,    0,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  285,    0,  274,   -1,  276,  277,
  278,  279,  280,  281,  282,  283,  284,  285,    0,  274,
   -1,  276,  277,  278,  279,  280,  281,  282,  283,  284,
  285,    0,   -1,   -1,   -1,   41,   -1,   -1,   44,   -1,
    0,   -1,   -1,   -1,   -1,   -1,   41,   -1,   -1,   44,
   -1,   -1,   -1,    0,   60,   61,   62,   -1,   -1,   41,
   -1,   -1,   44,   -1,   -1,   60,   61,   62,   -1,   -1,
   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   60,   61,
   62,   41,   -1,   40,   44,   42,   43,   93,   45,   46,
   47,   60,   61,   62,   41,   -1,   -1,   44,   93,   -1,
   -1,   61,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  274,   93,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  285,   -1,   40,   93,   40,   -1,   42,   45,   -1,
   -1,   46,   47,   93,   91,   -1,   -1,   94,   40,   41,
   42,   43,   -1,   45,   46,   47,   93,   64,   -1,   -1,
   40,   41,   42,   43,   -1,   45,   46,   47,   60,   61,
   62,   -1,   40,   41,   42,   43,   -1,   45,   46,   47,
   60,   61,   62,   -1,   -1,   -1,   91,   94,   -1,   94,
   -1,   -1,   60,   61,   62,   -1,   -1,   -1,   40,   91,
   42,   43,   94,   45,   46,   47,   -1,   -1,   -1,   -1,
   40,   91,   42,   43,   94,   45,   46,   47,   60,   61,
   62,   -1,   40,   91,   42,   43,   94,   45,   46,   47,
   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   60,   61,   62,   -1,   -1,   -1,   -1,   91,
   -1,   -1,   94,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   91,   -1,   -1,   94,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   91,   -1,   -1,   94,   -1,  274,   -1,
  276,  277,  278,  279,  280,  281,   -1,   -1,   -1,  274,
   -1,  276,  277,  278,  279,  280,  281,   -1,   -1,   -1,
   -1,   -1,  274,   -1,  276,  277,  278,  279,  280,  281,
   -1,   -1,   -1,   -1,   -1,  274,   -1,  276,  277,  278,
  279,  280,  281,   -1,  274,   -1,  276,  277,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,   -1,  276,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,   -1,  261,  262,  263,  264,  265,  266,
  267,   -1,  269,  270,  271,  272,   -1,   -1,  275,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  287,  288,  274,  290,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  285,  274,   -1,  276,  277,  278,  279,
  280,  281,  282,  283,  284,  285,  274,   -1,  276,  277,
  278,  279,  280,  281,  282,  283,  284,  285,   -1,   -1,
   -1,   -1,   -1,   -1,   40,   -1,   42,   43,   -1,   45,
   46,   47,  274,   -1,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  285,   60,   61,   62,  277,  278,  279,
  280,  281,  282,  283,  284,  285,   -1,   -1,   -1,   -1,
  278,  279,  280,  281,  282,  283,  284,  285,   -1,   17,
   18,   19,   -1,   -1,   40,   91,   42,   43,   94,   45,
   46,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,
   48,   49,   -1,   -1,   52,   53,   54,   55,   56,   57,
   58,   59,   60,   61,   62,   63,   64,   65,   66,   67,
   68,   69,   -1,   -1,   -1,   91,   74,   75,   94,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  103,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  119,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  279,  280,  281,  282,  283,  284,  285,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  280,  281,  282,  283,  284,  285,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 310
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,0,0,0,0,0,
0,0,"'<'","'='","'>'",0,"'@'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","FLOAT","STRING","FIELDNAME","NAME","TYPENAME",
"NAME_OR_INT","STRUCT","CLASS","SIZEOF","COLONCOLON","ERROR","VARIABLE","THIS",
"TRUEKEYWORD","FALSEKEYWORD","ABOVE_COMMA","ASSIGN","NOT","OR","XOR","ANDAND",
"NOTEQUAL","LEQ","GEQ","LSH","RSH","DIV","MOD","UNARY","INCREMENT","DECREMENT",
"ARROW","BLOCKNAME",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"$$1 :",
"start : $$1 normal_start",
"normal_start : exp1",
"normal_start : type_exp",
"type_exp : type",
"exp1 : exp",
"exp1 : exp1 ',' exp",
"exp : exp '^'",
"exp : '@' exp",
"exp : '-' exp",
"exp : NOT exp",
"exp : INCREMENT '(' exp ')'",
"exp : DECREMENT '(' exp ')'",
"$$2 :",
"exp : exp '.' $$2 FIELDNAME",
"$$3 :",
"exp : exp '[' $$3 exp1 ']'",
"$$4 :",
"exp : exp '(' $$4 arglist ')'",
"arglist :",
"arglist : exp",
"arglist : arglist ',' exp",
"exp : type '(' exp ')'",
"exp : '(' exp1 ')'",
"exp : exp '*' exp",
"exp : exp '/' exp",
"exp : exp DIV exp",
"exp : exp MOD exp",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : exp LSH exp",
"exp : exp RSH exp",
"exp : exp '=' exp",
"exp : exp NOTEQUAL exp",
"exp : exp LEQ exp",
"exp : exp GEQ exp",
"exp : exp '<' exp",
"exp : exp '>' exp",
"exp : exp ANDAND exp",
"exp : exp XOR exp",
"exp : exp OR exp",
"exp : exp ASSIGN exp",
"exp : TRUEKEYWORD",
"exp : FALSEKEYWORD",
"exp : INT",
"exp : NAME_OR_INT",
"exp : FLOAT",
"exp : variable",
"exp : VARIABLE",
"exp : SIZEOF '(' type ')'",
"exp : STRING",
"exp : THIS",
"block : BLOCKNAME",
"block : block COLONCOLON name",
"variable : block COLONCOLON name",
"qualified_name : typebase COLONCOLON name",
"variable : qualified_name",
"variable : COLONCOLON name",
"variable : name_not_typename",
"ptype : typebase",
"type : ptype",
"type : typebase COLONCOLON '*'",
"typebase : '^' typebase",
"typebase : TYPENAME",
"typebase : STRUCT name",
"typebase : CLASS name",
"name : NAME",
"name : BLOCKNAME",
"name : TYPENAME",
"name : NAME_OR_INT",
"name_not_typename : NAME",
"name_not_typename : BLOCKNAME",

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
#line 758 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"

/* Take care of parsing a number (anything that starts with a digit).
   Set yylval and return the token type; update lexptr.
   LEN is the number of characters in it.  */

/*** Needs some error checking for the float case ***/

static int
parse_number (p, len, parsed_float, putithere)
     char *p;
     int len;
     int parsed_float;
     YYSTYPE *putithere;
{
  /* FIXME: Shouldn't these be unsigned?  We don't deal with negative values
     here, and we do kind of silly things like cast to unsigned.  */
  LONGEST n = 0;
  LONGEST prevn = 0;
  ULONGEST un;

  int i = 0;
  int c;
  int base = input_radix;
  int unsigned_p = 0;

  /* Number of "L" suffixes encountered.  */
  int long_p = 0;

  /* We have found a "L" or "U" suffix.  */
  int found_suffix = 0;

  ULONGEST high_bit;
  struct type *signed_type;
  struct type *unsigned_type;

  if (parsed_float)
    {
      /* It's a float since it contains a point or an exponent.  */
      char c;
      int num = 0;	/* number of tokens scanned by scanf */
      char saved_char = p[len];

      p[len] = 0;	/* null-terminate the token */
      if (sizeof (putithere->typed_val_float.dval) <= sizeof (float))
	num = sscanf (p, "%g%c", (float *) &putithere->typed_val_float.dval,&c);
      else if (sizeof (putithere->typed_val_float.dval) <= sizeof (double))
	num = sscanf (p, "%lg%c", (double *) &putithere->typed_val_float.dval,&c);
      else
	{
#ifdef SCANF_HAS_LONG_DOUBLE
	  num = sscanf (p, "%Lg%c", &putithere->typed_val_float.dval,&c);
#else
	  /* Scan it into a double, then assign it to the long double.
	     This at least wins with values representable in the range
	     of doubles. */
	  double temp;
	  num = sscanf (p, "%lg%c", &temp,&c);
	  putithere->typed_val_float.dval = temp;
#endif
	}
      p[len] = saved_char;	/* restore the input stream */
      if (num != 1) 		/* check scanf found ONLY a float ... */
	return ERROR;
      /* See if it has `f' or `l' suffix (float or long double).  */

      c = tolower (p[len - 1]);

      if (c == 'f')
	putithere->typed_val_float.type = builtin_type_float;
      else if (c == 'l')
	putithere->typed_val_float.type = builtin_type_long_double;
      else if (isdigit (c) || c == '.')
	putithere->typed_val_float.type = builtin_type_double;
      else
	return ERROR;

      return FLOAT;
    }

  /* Handle base-switching prefixes 0x, 0t, 0d, 0 */
  if (p[0] == '0')
    switch (p[1])
      {
      case 'x':
      case 'X':
	if (len >= 3)
	  {
	    p += 2;
	    base = 16;
	    len -= 2;
	  }
	break;

      case 't':
      case 'T':
      case 'd':
      case 'D':
	if (len >= 3)
	  {
	    p += 2;
	    base = 10;
	    len -= 2;
	  }
	break;

      default:
	base = 8;
	break;
      }

  while (len-- > 0)
    {
      c = *p++;
      if (c >= 'A' && c <= 'Z')
	c += 'a' - 'A';
      if (c != 'l' && c != 'u')
	n *= base;
      if (c >= '0' && c <= '9')
	{
	  if (found_suffix)
	    return ERROR;
	  n += i = c - '0';
	}
      else
	{
	  if (base > 10 && c >= 'a' && c <= 'f')
	    {
	      if (found_suffix)
		return ERROR;
	      n += i = c - 'a' + 10;
	    }
	  else if (c == 'l')
	    {
	      ++long_p;
	      found_suffix = 1;
	    }
	  else if (c == 'u')
	    {
	      unsigned_p = 1;
	      found_suffix = 1;
	    }
	  else
	    return ERROR;	/* Char not a digit */
	}
      if (i >= base)
	return ERROR;		/* Invalid digit in this base */

      /* Portably test for overflow (only works for nonzero values, so make
	 a second check for zero).  FIXME: Can't we just make n and prevn
	 unsigned and avoid this?  */
      if (c != 'l' && c != 'u' && (prevn >= n) && n != 0)
	unsigned_p = 1;		/* Try something unsigned */

      /* Portably test for unsigned overflow.
	 FIXME: This check is wrong; for example it doesn't find overflow
	 on 0x123456789 when LONGEST is 32 bits.  */
      if (c != 'l' && c != 'u' && n != 0)
	{	
	  if ((unsigned_p && (ULONGEST) prevn >= (ULONGEST) n))
	    error ("Numeric constant too large.");
	}
      prevn = n;
    }

  /* An integer constant is an int, a long, or a long long.  An L
     suffix forces it to be long; an LL suffix forces it to be long
     long.  If not forced to a larger size, it gets the first type of
     the above that it fits in.  To figure out whether it fits, we
     shift it right and see whether anything remains.  Note that we
     can't shift sizeof (LONGEST) * HOST_CHAR_BIT bits or more in one
     operation, because many compilers will warn about such a shift
     (which always produces a zero result).  Sometimes TARGET_INT_BIT
     or TARGET_LONG_BIT will be that big, sometimes not.  To deal with
     the case where it is we just always shift the value more than
     once, with fewer bits each time.  */

  un = (ULONGEST)n >> 2;
  if (long_p == 0
      && (un >> (TARGET_INT_BIT - 2)) == 0)
    {
      high_bit = ((ULONGEST)1) << (TARGET_INT_BIT-1);

      /* A large decimal (not hex or octal) constant (between INT_MAX
	 and UINT_MAX) is a long or unsigned long, according to ANSI,
	 never an unsigned int, but this code treats it as unsigned
	 int.  This probably should be fixed.  GCC gives a warning on
	 such constants.  */

      unsigned_type = builtin_type_unsigned_int;
      signed_type = builtin_type_int;
    }
  else if (long_p <= 1
	   && (un >> (TARGET_LONG_BIT - 2)) == 0)
    {
      high_bit = ((ULONGEST)1) << (TARGET_LONG_BIT-1);
      unsigned_type = builtin_type_unsigned_long;
      signed_type = builtin_type_long;
    }
  else
    {
      int shift;
      if (sizeof (ULONGEST) * HOST_CHAR_BIT < TARGET_LONG_LONG_BIT)
	/* A long long does not fit in a LONGEST.  */
	shift = (sizeof (ULONGEST) * HOST_CHAR_BIT - 1);
      else
	shift = (TARGET_LONG_LONG_BIT - 1);
      high_bit = (ULONGEST) 1 << shift;
      unsigned_type = builtin_type_unsigned_long_long;
      signed_type = builtin_type_long_long;
    }

   putithere->typed_val_int.val = n;

   /* If the high bit of the worked out type is set then this number
      has to be unsigned. */

   if (unsigned_p || (n & high_bit))
     {
       putithere->typed_val_int.type = unsigned_type;
     }
   else
     {
       putithere->typed_val_int.type = signed_type;
     }

   return INT;
}


struct type_push
{
  struct type *stored;
  struct type_push *next;
};

static struct type_push *tp_top = NULL;

static void
push_current_type (void)
{
  struct type_push *tpnew;
  tpnew = (struct type_push *) malloc (sizeof (struct type_push));
  tpnew->next = tp_top;
  tpnew->stored = current_type;
  current_type = NULL;
  tp_top = tpnew; 
}

static void
pop_current_type (void)
{
  struct type_push *tp = tp_top;
  if (tp)
    {
      current_type = tp->stored;
      tp_top = tp->next;
      xfree (tp);
    }
}

struct token
{
  char *operator;
  int token;
  enum exp_opcode opcode;
};

static const struct token tokentab3[] =
  {
    {"shr", RSH, BINOP_END},
    {"shl", LSH, BINOP_END},
    {"and", ANDAND, BINOP_END},
    {"div", DIV, BINOP_END},
    {"not", NOT, BINOP_END},
    {"mod", MOD, BINOP_END},
    {"inc", INCREMENT, BINOP_END},
    {"dec", DECREMENT, BINOP_END},
    {"xor", XOR, BINOP_END}
  };

static const struct token tokentab2[] =
  {
    {"or", OR, BINOP_END},
    {"<>", NOTEQUAL, BINOP_END},
    {"<=", LEQ, BINOP_END},
    {">=", GEQ, BINOP_END},
    {":=", ASSIGN, BINOP_END},
    {"::", COLONCOLON, BINOP_END} };

/* Allocate uppercased var */
/* make an uppercased copy of tokstart */
static char * uptok (tokstart, namelen)
  char *tokstart;
  int namelen;
{
  int i;
  char *uptokstart = (char *)malloc(namelen+1);
  for (i = 0;i <= namelen;i++)
    {
      if ((tokstart[i]>='a' && tokstart[i]<='z'))
        uptokstart[i] = tokstart[i]-('a'-'A');
      else
        uptokstart[i] = tokstart[i];
    }
  uptokstart[namelen]='\0';
  return uptokstart;
}
/* Read one token, getting characters through lexptr.  */


static int
yylex ()
{
  int c;
  int namelen;
  unsigned int i;
  char *tokstart;
  char *uptokstart;
  char *tokptr;
  char *p;
  int explen, tempbufindex;
  static char *tempbuf;
  static int tempbufsize;

 retry:

  prev_lexptr = lexptr;

  tokstart = lexptr;
  explen = strlen (lexptr);
  /* See if it is a special token of length 3.  */
  if (explen > 2)
    for (i = 0; i < sizeof (tokentab3) / sizeof (tokentab3[0]); i++)
      if (strncasecmp (tokstart, tokentab3[i].operator, 3) == 0
          && (!isalpha (tokentab3[i].operator[0]) || explen == 3
              || (!isalpha (tokstart[3]) && !isdigit (tokstart[3]) && tokstart[3] != '_')))
        {
          lexptr += 3;
          yylval.opcode = tokentab3[i].opcode;
          return tokentab3[i].token;
        }

  /* See if it is a special token of length 2.  */
  if (explen > 1)
  for (i = 0; i < sizeof (tokentab2) / sizeof (tokentab2[0]); i++)
      if (strncasecmp (tokstart, tokentab2[i].operator, 2) == 0
          && (!isalpha (tokentab2[i].operator[0]) || explen == 2
              || (!isalpha (tokstart[2]) && !isdigit (tokstart[2]) && tokstart[2] != '_')))
        {
          lexptr += 2;
          yylval.opcode = tokentab2[i].opcode;
          return tokentab2[i].token;
        }

  switch (c = *tokstart)
    {
    case 0:
      return 0;

    case ' ':
    case '\t':
    case '\n':
      lexptr++;
      goto retry;

    case '\'':
      /* We either have a character constant ('0' or '\177' for example)
	 or we have a quoted symbol reference ('foo(int,int)' in object pascal
	 for example). */
      lexptr++;
      c = *lexptr++;
      if (c == '\\')
	c = parse_escape (&lexptr);
      else if (c == '\'')
	error ("Empty character constant.");

      yylval.typed_val_int.val = c;
      yylval.typed_val_int.type = builtin_type_char;

      c = *lexptr++;
      if (c != '\'')
	{
	  namelen = skip_quoted (tokstart) - tokstart;
	  if (namelen > 2)
	    {
	      lexptr = tokstart + namelen;
	      if (lexptr[-1] != '\'')
		error ("Unmatched single quote.");
	      namelen -= 2;
              tokstart++;
              uptokstart = uptok(tokstart,namelen);
	      goto tryname;
	    }
	  error ("Invalid character constant.");
	}
      return INT;

    case '(':
      paren_depth++;
      lexptr++;
      return c;

    case ')':
      if (paren_depth == 0)
	return 0;
      paren_depth--;
      lexptr++;
      return c;

    case ',':
      if (comma_terminates && paren_depth == 0)
	return 0;
      lexptr++;
      return c;

    case '.':
      /* Might be a floating point number.  */
      if (lexptr[1] < '0' || lexptr[1] > '9')
	goto symbol;		/* Nope, must be a symbol. */
      /* FALL THRU into number case.  */

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      {
	/* It's a number.  */
	int got_dot = 0, got_e = 0, toktype;
	char *p = tokstart;
	int hex = input_radix > 10;

	if (c == '0' && (p[1] == 'x' || p[1] == 'X'))
	  {
	    p += 2;
	    hex = 1;
	  }
	else if (c == '0' && (p[1]=='t' || p[1]=='T' || p[1]=='d' || p[1]=='D'))
	  {
	    p += 2;
	    hex = 0;
	  }

	for (;; ++p)
	  {
	    /* This test includes !hex because 'e' is a valid hex digit
	       and thus does not indicate a floating point number when
	       the radix is hex.  */
	    if (!hex && !got_e && (*p == 'e' || *p == 'E'))
	      got_dot = got_e = 1;
	    /* This test does not include !hex, because a '.' always indicates
	       a decimal floating point number regardless of the radix.  */
	    else if (!got_dot && *p == '.')
	      got_dot = 1;
	    else if (got_e && (p[-1] == 'e' || p[-1] == 'E')
		     && (*p == '-' || *p == '+'))
	      /* This is the sign of the exponent, not the end of the
		 number.  */
	      continue;
	    /* We will take any letters or digits.  parse_number will
	       complain if past the radix, or if L or U are not final.  */
	    else if ((*p < '0' || *p > '9')
		     && ((*p < 'a' || *p > 'z')
				  && (*p < 'A' || *p > 'Z')))
	      break;
	  }
	toktype = parse_number (tokstart, p - tokstart, got_dot|got_e, &yylval);
        if (toktype == ERROR)
	  {
	    char *err_copy = (char *) alloca (p - tokstart + 1);

	    memcpy (err_copy, tokstart, p - tokstart);
	    err_copy[p - tokstart] = 0;
	    error ("Invalid number \"%s\".", err_copy);
	  }
	lexptr = p;
	return toktype;
      }

    case '+':
    case '-':
    case '*':
    case '/':
    case '|':
    case '&':
    case '^':
    case '~':
    case '!':
    case '@':
    case '<':
    case '>':
    case '[':
    case ']':
    case '?':
    case ':':
    case '=':
    case '{':
    case '}':
    symbol:
      lexptr++;
      return c;

    case '"':

      /* Build the gdb internal form of the input string in tempbuf,
	 translating any standard C escape forms seen.  Note that the
	 buffer is null byte terminated *only* for the convenience of
	 debugging gdb itself and printing the buffer contents when
	 the buffer contains no embedded nulls.  Gdb does not depend
	 upon the buffer being null byte terminated, it uses the length
	 string instead.  This allows gdb to handle C strings (as well
	 as strings in other languages) with embedded null bytes */

      tokptr = ++tokstart;
      tempbufindex = 0;

      do {
	/* Grow the static temp buffer if necessary, including allocating
	   the first one on demand. */
	if (tempbufindex + 1 >= tempbufsize)
	  {
	    tempbuf = (char *) realloc (tempbuf, tempbufsize += 64);
	  }

	switch (*tokptr)
	  {
	  case '\0':
	  case '"':
	    /* Do nothing, loop will terminate. */
	    break;
	  case '\\':
	    tokptr++;
	    c = parse_escape (&tokptr);
	    if (c == -1)
	      {
		continue;
	      }
	    tempbuf[tempbufindex++] = c;
	    break;
	  default:
	    tempbuf[tempbufindex++] = *tokptr++;
	    break;
	  }
      } while ((*tokptr != '"') && (*tokptr != '\0'));
      if (*tokptr++ != '"')
	{
	  error ("Unterminated string in expression.");
	}
      tempbuf[tempbufindex] = '\0';	/* See note above */
      yylval.sval.ptr = tempbuf;
      yylval.sval.length = tempbufindex;
      lexptr = tokptr;
      return (STRING);
    }

  if (!(c == '_' || c == '$'
	|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    /* We must have come across a bad character (e.g. ';').  */
    error ("Invalid character '%c' in expression.", c);

  /* It's a name.  See how long it is.  */
  namelen = 0;
  for (c = tokstart[namelen];
       (c == '_' || c == '$' || (c >= '0' && c <= '9')
	|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '<');)
    {
      /* Template parameter lists are part of the name.
	 FIXME: This mishandles `print $a<4&&$a>3'.  */
      if (c == '<')
	{
	  int i = namelen;
	  int nesting_level = 1;
	  while (tokstart[++i])
	    {
	      if (tokstart[i] == '<')
		nesting_level++;
	      else if (tokstart[i] == '>')
		{
		  if (--nesting_level == 0)
		    break;
		}
	    }
	  if (tokstart[i] == '>')
	    namelen = i;
	  else
	    break;
	}

      /* do NOT uppercase internals because of registers !!! */
      c = tokstart[++namelen];
    }

  uptokstart = uptok(tokstart,namelen);

  /* The token "if" terminates the expression and is NOT
     removed from the input stream.  */
  if (namelen == 2 && uptokstart[0] == 'I' && uptokstart[1] == 'F')
    {
      return 0;
    }

  lexptr += namelen;

  tryname:

  /* Catch specific keywords.  Should be done with a data structure.  */
  switch (namelen)
    {
    case 6:
      if (DEPRECATED_STREQ (uptokstart, "OBJECT"))
	return CLASS;
      if (DEPRECATED_STREQ (uptokstart, "RECORD"))
	return STRUCT;
      if (DEPRECATED_STREQ (uptokstart, "SIZEOF"))
	return SIZEOF;
      break;
    case 5:
      if (DEPRECATED_STREQ (uptokstart, "CLASS"))
	return CLASS;
      if (DEPRECATED_STREQ (uptokstart, "FALSE"))
	{
          yylval.lval = 0;
          return FALSEKEYWORD;
        }
      break;
    case 4:
      if (DEPRECATED_STREQ (uptokstart, "TRUE"))
	{
          yylval.lval = 1;
  	  return TRUEKEYWORD;
        }
      if (DEPRECATED_STREQ (uptokstart, "SELF"))
        {
          /* here we search for 'this' like
             inserted in FPC stabs debug info */
	  static const char this_name[] = "this";

	  if (lookup_symbol (this_name, expression_context_block,
			     VAR_DOMAIN, (int *) NULL,
			     (struct symtab **) NULL))
	    return THIS;
	}
      break;
    default:
      break;
    }

  yylval.sval.ptr = tokstart;
  yylval.sval.length = namelen;

  if (*tokstart == '$')
    {
      /* $ is the normal prefix for pascal hexadecimal values
        but this conflicts with the GDB use for debugger variables
        so in expression to enter hexadecimal values
        we still need to use C syntax with 0xff  */
      write_dollar_variable (yylval.sval);
      return VARIABLE;
    }

  /* Use token-type BLOCKNAME for symbols that happen to be defined as
     functions or symtabs.  If this is not so, then ...
     Use token-type TYPENAME for symbols that happen to be defined
     currently as names of types; NAME for other symbols.
     The caller is not constrained to care about the distinction.  */
  {
    char *tmp = copy_name (yylval.sval);
    struct symbol *sym;
    int is_a_field_of_this = 0;
    int is_a_field = 0;
    int hextype;


    if (search_field && current_type)
      is_a_field = (lookup_struct_elt_type (current_type, tmp, 1) != NULL);	
    if (is_a_field)
      sym = NULL;
    else
      sym = lookup_symbol (tmp, expression_context_block,
			   VAR_DOMAIN,
			   &is_a_field_of_this,
			   (struct symtab **) NULL);
    /* second chance uppercased (as Free Pascal does).  */
    if (!sym && !is_a_field_of_this && !is_a_field)
      {
       for (i = 0; i <= namelen; i++)
         {
           if ((tmp[i] >= 'a' && tmp[i] <= 'z'))
             tmp[i] -= ('a'-'A');
         }
       if (search_field && current_type)
	 is_a_field = (lookup_struct_elt_type (current_type, tmp, 1) != NULL);	
       if (is_a_field)
	 sym = NULL;
       else
	 sym = lookup_symbol (tmp, expression_context_block,
                        VAR_DOMAIN,
                        &is_a_field_of_this,
                        (struct symtab **) NULL);
       if (sym || is_a_field_of_this || is_a_field)
         for (i = 0; i <= namelen; i++)
           {
             if ((tokstart[i] >= 'a' && tokstart[i] <= 'z'))
               tokstart[i] -= ('a'-'A');
           }
      }
    /* Third chance Capitalized (as GPC does).  */
    if (!sym && !is_a_field_of_this && !is_a_field)
      {
       for (i = 0; i <= namelen; i++)
         {
           if (i == 0)
             {
              if ((tmp[i] >= 'a' && tmp[i] <= 'z'))
                tmp[i] -= ('a'-'A');
             }
           else
           if ((tmp[i] >= 'A' && tmp[i] <= 'Z'))
             tmp[i] -= ('A'-'a');
          }
       if (search_field && current_type)
	 is_a_field = (lookup_struct_elt_type (current_type, tmp, 1) != NULL);	
       if (is_a_field)
	 sym = NULL;
       else
	 sym = lookup_symbol (tmp, expression_context_block,
                         VAR_DOMAIN,
                         &is_a_field_of_this,
                         (struct symtab **) NULL);
       if (sym || is_a_field_of_this || is_a_field)
          for (i = 0; i <= namelen; i++)
            {
              if (i == 0)
                {
                  if ((tokstart[i] >= 'a' && tokstart[i] <= 'z'))
                    tokstart[i] -= ('a'-'A');
                }
              else
                if ((tokstart[i] >= 'A' && tokstart[i] <= 'Z'))
                  tokstart[i] -= ('A'-'a');
            }
      }

    if (is_a_field)
      {
	tempbuf = (char *) realloc (tempbuf, namelen + 1);
	strncpy (tempbuf, tokstart, namelen); tempbuf [namelen] = 0;
	yylval.sval.ptr = tempbuf;
	yylval.sval.length = namelen; 
	return FIELDNAME;
      } 
    /* Call lookup_symtab, not lookup_partial_symtab, in case there are
       no psymtabs (coff, xcoff, or some future change to blow away the
       psymtabs once once symbols are read).  */
    if ((sym && SYMBOL_CLASS (sym) == LOC_BLOCK) ||
        lookup_symtab (tmp))
      {
	yylval.ssym.sym = sym;
	yylval.ssym.is_a_field_of_this = is_a_field_of_this;
	return BLOCKNAME;
      }
    if (sym && SYMBOL_CLASS (sym) == LOC_TYPEDEF)
        {
#if 1
	  /* Despite the following flaw, we need to keep this code enabled.
	     Because we can get called from check_stub_method, if we don't
	     handle nested types then it screws many operations in any
	     program which uses nested types.  */
	  /* In "A::x", if x is a member function of A and there happens
	     to be a type (nested or not, since the stabs don't make that
	     distinction) named x, then this code incorrectly thinks we
	     are dealing with nested types rather than a member function.  */

	  char *p;
	  char *namestart;
	  struct symbol *best_sym;

	  /* Look ahead to detect nested types.  This probably should be
	     done in the grammar, but trying seemed to introduce a lot
	     of shift/reduce and reduce/reduce conflicts.  It's possible
	     that it could be done, though.  Or perhaps a non-grammar, but
	     less ad hoc, approach would work well.  */

	  /* Since we do not currently have any way of distinguishing
	     a nested type from a non-nested one (the stabs don't tell
	     us whether a type is nested), we just ignore the
	     containing type.  */

	  p = lexptr;
	  best_sym = sym;
	  while (1)
	    {
	      /* Skip whitespace.  */
	      while (*p == ' ' || *p == '\t' || *p == '\n')
		++p;
	      if (*p == ':' && p[1] == ':')
		{
		  /* Skip the `::'.  */
		  p += 2;
		  /* Skip whitespace.  */
		  while (*p == ' ' || *p == '\t' || *p == '\n')
		    ++p;
		  namestart = p;
		  while (*p == '_' || *p == '$' || (*p >= '0' && *p <= '9')
			 || (*p >= 'a' && *p <= 'z')
			 || (*p >= 'A' && *p <= 'Z'))
		    ++p;
		  if (p != namestart)
		    {
		      struct symbol *cur_sym;
		      /* As big as the whole rest of the expression, which is
			 at least big enough.  */
		      char *ncopy = alloca (strlen (tmp)+strlen (namestart)+3);
		      char *tmp1;

		      tmp1 = ncopy;
		      memcpy (tmp1, tmp, strlen (tmp));
		      tmp1 += strlen (tmp);
		      memcpy (tmp1, "::", 2);
		      tmp1 += 2;
		      memcpy (tmp1, namestart, p - namestart);
		      tmp1[p - namestart] = '\0';
		      cur_sym = lookup_symbol (ncopy, expression_context_block,
					       VAR_DOMAIN, (int *) NULL,
					       (struct symtab **) NULL);
		      if (cur_sym)
			{
			  if (SYMBOL_CLASS (cur_sym) == LOC_TYPEDEF)
			    {
			      best_sym = cur_sym;
			      lexptr = p;
			    }
			  else
			    break;
			}
		      else
			break;
		    }
		  else
		    break;
		}
	      else
		break;
	    }

	  yylval.tsym.type = SYMBOL_TYPE (best_sym);
#else /* not 0 */
	  yylval.tsym.type = SYMBOL_TYPE (sym);
#endif /* not 0 */
	  return TYPENAME;
        }
    if ((yylval.tsym.type = lookup_primitive_typename (tmp)) != 0)
	return TYPENAME;

    /* Input names that aren't symbols but ARE valid hex numbers,
       when the input radix permits them, can be names or numbers
       depending on the parse.  Note we support radixes > 16 here.  */
    if (!sym &&
        ((tokstart[0] >= 'a' && tokstart[0] < 'a' + input_radix - 10) ||
         (tokstart[0] >= 'A' && tokstart[0] < 'A' + input_radix - 10)))
      {
 	YYSTYPE newlval;	/* Its value is ignored.  */
	hextype = parse_number (tokstart, namelen, 0, &newlval);
	if (hextype == INT)
	  {
	    yylval.ssym.sym = sym;
	    yylval.ssym.is_a_field_of_this = is_a_field_of_this;
	    return NAME_OR_INT;
	  }
      }

    free(uptokstart);
    /* Any other kind of symbol */
    yylval.ssym.sym = sym;
    yylval.ssym.is_a_field_of_this = is_a_field_of_this;
    return NAME;
  }
}

void
yyerror (msg)
     char *msg;
{
  if (prev_lexptr)
    lexptr = prev_lexptr;

  error ("A %s in expression, near `%s'.", (msg ? msg : "error"), lexptr);
}
#line 1547 "p-exp.c"

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
#line 234 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ current_type = NULL;
		  search_field = 0;
		}
break;
case 2:
#line 237 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{}
break;
case 5:
#line 246 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode(OP_TYPE);
			  write_exp_elt_type(yystack.l_mark[0].tval);
			  write_exp_elt_opcode(OP_TYPE);
			  current_type = yystack.l_mark[0].tval; }
break;
case 7:
#line 254 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_COMMA); }
break;
case 8:
#line 259 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (UNOP_IND);
			  if (current_type) 
			    current_type = TYPE_TARGET_TYPE (current_type); }
break;
case 9:
#line 265 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (UNOP_ADDR); 
			  if (current_type)
			    current_type = TYPE_POINTER_TYPE (current_type); }
break;
case 10:
#line 271 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (UNOP_NEG); }
break;
case 11:
#line 275 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (UNOP_LOGICAL_NOT); }
break;
case 12:
#line 279 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (UNOP_PREINCREMENT); }
break;
case 13:
#line 283 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (UNOP_PREDECREMENT); }
break;
case 14:
#line 286 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ search_field = 1; }
break;
case 15:
#line 289 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (STRUCTOP_STRUCT);
			  write_exp_string (yystack.l_mark[0].sval); 
			  write_exp_elt_opcode (STRUCTOP_STRUCT);
			  search_field = 0; 
			  if (current_type)
			    { while (TYPE_CODE (current_type) == TYPE_CODE_PTR)
				current_type = TYPE_TARGET_TYPE (current_type);
			      current_type = lookup_struct_elt_type (
				current_type, yystack.l_mark[0].sval.ptr, 0); };
			 }
break;
case 16:
#line 301 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ char *arrayname; 
			  int arrayfieldindex;
			  arrayfieldindex = is_pascal_string_type (
				current_type, NULL, NULL,
				NULL, NULL, &arrayname); 
			  if (arrayfieldindex) 
			    {
			      struct stoken stringsval;
			      stringsval.ptr = alloca (strlen (arrayname) + 1);
			      stringsval.length = strlen (arrayname);
			      strcpy (stringsval.ptr, arrayname);
			      current_type = TYPE_FIELD_TYPE (current_type,
				arrayfieldindex - 1); 
			      write_exp_elt_opcode (STRUCTOP_STRUCT);
			      write_exp_string (stringsval); 
			      write_exp_elt_opcode (STRUCTOP_STRUCT);
			    }
			  push_current_type ();  }
break;
case 17:
#line 320 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ pop_current_type ();
			  write_exp_elt_opcode (BINOP_SUBSCRIPT);
			  if (current_type)
			    current_type = TYPE_TARGET_TYPE (current_type); }
break;
case 18:
#line 329 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ push_current_type ();
			  start_arglist (); }
break;
case 19:
#line 332 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (OP_FUNCALL);
			  write_exp_elt_longcst ((LONGEST) end_arglist ());
			  write_exp_elt_opcode (OP_FUNCALL); 
			  pop_current_type (); }
break;
case 21:
#line 340 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ arglist_len = 1; }
break;
case 22:
#line 342 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ arglist_len++; }
break;
case 23:
#line 346 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ if (current_type)
			    {
			      /* Allow automatic dereference of classes.  */
			      if ((TYPE_CODE (current_type) == TYPE_CODE_PTR)
				  && (TYPE_CODE (TYPE_TARGET_TYPE (current_type)) == TYPE_CODE_CLASS)
				  && (TYPE_CODE (yystack.l_mark[-3].tval) == TYPE_CODE_CLASS))
				write_exp_elt_opcode (UNOP_IND);
			    }
			  write_exp_elt_opcode (UNOP_CAST);
			  write_exp_elt_type (yystack.l_mark[-3].tval);
			  write_exp_elt_opcode (UNOP_CAST); 
			  current_type = yystack.l_mark[-3].tval; }
break;
case 24:
#line 361 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ }
break;
case 25:
#line 367 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_MUL); }
break;
case 26:
#line 371 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_DIV); }
break;
case 27:
#line 375 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_INTDIV); }
break;
case 28:
#line 379 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_REM); }
break;
case 29:
#line 383 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_ADD); }
break;
case 30:
#line 387 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_SUB); }
break;
case 31:
#line 391 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_LSH); }
break;
case 32:
#line 395 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_RSH); }
break;
case 33:
#line 399 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_EQUAL); }
break;
case 34:
#line 403 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_NOTEQUAL); }
break;
case 35:
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_LEQ); }
break;
case 36:
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_GEQ); }
break;
case 37:
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_LESS); }
break;
case 38:
#line 419 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_GTR); }
break;
case 39:
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_BITWISE_AND); }
break;
case 40:
#line 427 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_BITWISE_XOR); }
break;
case 41:
#line 431 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_BITWISE_IOR); }
break;
case 42:
#line 435 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (BINOP_ASSIGN); }
break;
case 43:
#line 439 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (OP_BOOL);
			  write_exp_elt_longcst ((LONGEST) yystack.l_mark[0].lval);
			  write_exp_elt_opcode (OP_BOOL); }
break;
case 44:
#line 445 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (OP_BOOL);
			  write_exp_elt_longcst ((LONGEST) yystack.l_mark[0].lval);
			  write_exp_elt_opcode (OP_BOOL); }
break;
case 45:
#line 451 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_type (yystack.l_mark[0].typed_val_int.type);
			  write_exp_elt_longcst ((LONGEST)(yystack.l_mark[0].typed_val_int.val));
			  write_exp_elt_opcode (OP_LONG); }
break;
case 46:
#line 458 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ YYSTYPE val;
			  parse_number (yystack.l_mark[0].ssym.stoken.ptr, yystack.l_mark[0].ssym.stoken.length, 0, &val);
			  write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_type (val.typed_val_int.type);
			  write_exp_elt_longcst ((LONGEST)val.typed_val_int.val);
			  write_exp_elt_opcode (OP_LONG);
			}
break;
case 47:
#line 469 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (OP_DOUBLE);
			  write_exp_elt_type (yystack.l_mark[0].typed_val_float.type);
			  write_exp_elt_dblcst (yystack.l_mark[0].typed_val_float.dval);
			  write_exp_elt_opcode (OP_DOUBLE); }
break;
case 50:
#line 483 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_type (builtin_type_int);
			  CHECK_TYPEDEF (yystack.l_mark[-1].tval);
			  write_exp_elt_longcst ((LONGEST) TYPE_LENGTH (yystack.l_mark[-1].tval));
			  write_exp_elt_opcode (OP_LONG); }
break;
case 51:
#line 491 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ /* C strings are converted into array constants with
			     an explicit null byte added at the end.  Thus
			     the array upper bound is the string length.
			     There is no such thing in C as a completely empty
			     string. */
			  char *sp = yystack.l_mark[0].sval.ptr; int count = yystack.l_mark[0].sval.length;
			  while (count-- > 0)
			    {
			      write_exp_elt_opcode (OP_LONG);
			      write_exp_elt_type (builtin_type_char);
			      write_exp_elt_longcst ((LONGEST)(*sp++));
			      write_exp_elt_opcode (OP_LONG);
			    }
			  write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_type (builtin_type_char);
			  write_exp_elt_longcst ((LONGEST)'\0');
			  write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_opcode (OP_ARRAY);
			  write_exp_elt_longcst ((LONGEST) 0);
			  write_exp_elt_longcst ((LONGEST) (yystack.l_mark[0].sval.length));
			  write_exp_elt_opcode (OP_ARRAY); }
break;
case 52:
#line 516 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ 
			  struct value * this_val;
			  struct type * this_type;
			  write_exp_elt_opcode (OP_THIS);
			  write_exp_elt_opcode (OP_THIS); 
			  /* we need type of this */
			  this_val = value_of_this (0); 
			  if (this_val)
			    this_type = this_val->type;
			  else
			    this_type = NULL;
			  if (this_type)
			    {
			      if (TYPE_CODE (this_type) == TYPE_CODE_PTR)
				{
				  this_type = TYPE_TARGET_TYPE (this_type);
				  write_exp_elt_opcode (UNOP_IND);
				}
			    }
		
			  current_type = this_type;
			}
break;
case 53:
#line 543 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{
			  if (yystack.l_mark[0].ssym.sym != 0)
			      yyval.bval = SYMBOL_BLOCK_VALUE (yystack.l_mark[0].ssym.sym);
			  else
			    {
			      struct symtab *tem =
				  lookup_symtab (copy_name (yystack.l_mark[0].ssym.stoken));
			      if (tem)
				yyval.bval = BLOCKVECTOR_BLOCK (BLOCKVECTOR (tem), STATIC_BLOCK);
			      else
				error ("No file or function \"%s\".",
				       copy_name (yystack.l_mark[0].ssym.stoken));
			    }
			}
break;
case 54:
#line 560 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ struct symbol *tem
			    = lookup_symbol (copy_name (yystack.l_mark[0].sval), yystack.l_mark[-2].bval,
					     VAR_DOMAIN, (int *) NULL,
					     (struct symtab **) NULL);
			  if (!tem || SYMBOL_CLASS (tem) != LOC_BLOCK)
			    error ("No function \"%s\" in specified context.",
				   copy_name (yystack.l_mark[0].sval));
			  yyval.bval = SYMBOL_BLOCK_VALUE (tem); }
break;
case 55:
#line 571 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ struct symbol *sym;
			  sym = lookup_symbol (copy_name (yystack.l_mark[0].sval), yystack.l_mark[-2].bval,
					       VAR_DOMAIN, (int *) NULL,
					       (struct symtab **) NULL);
			  if (sym == 0)
			    error ("No symbol \"%s\" in specified context.",
				   copy_name (yystack.l_mark[0].sval));

			  write_exp_elt_opcode (OP_VAR_VALUE);
			  /* block_found is set by lookup_symbol.  */
			  write_exp_elt_block (block_found);
			  write_exp_elt_sym (sym);
			  write_exp_elt_opcode (OP_VAR_VALUE); }
break;
case 56:
#line 587 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{
			  struct type *type = yystack.l_mark[-2].tval;
			  if (TYPE_CODE (type) != TYPE_CODE_STRUCT
			      && TYPE_CODE (type) != TYPE_CODE_UNION)
			    error ("`%s' is not defined as an aggregate type.",
				   TYPE_NAME (type));

			  write_exp_elt_opcode (OP_SCOPE);
			  write_exp_elt_type (type);
			  write_exp_string (yystack.l_mark[0].sval);
			  write_exp_elt_opcode (OP_SCOPE);
			}
break;
case 58:
#line 603 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{
			  char *name = copy_name (yystack.l_mark[0].sval);
			  struct symbol *sym;
			  struct minimal_symbol *msymbol;

			  sym =
			    lookup_symbol (name, (const struct block *) NULL,
					   VAR_DOMAIN, (int *) NULL,
					   (struct symtab **) NULL);
			  if (sym)
			    {
			      write_exp_elt_opcode (OP_VAR_VALUE);
			      write_exp_elt_block (NULL);
			      write_exp_elt_sym (sym);
			      write_exp_elt_opcode (OP_VAR_VALUE);
			      break;
			    }

			  msymbol = lookup_minimal_symbol (name, NULL, NULL);
			  if (msymbol != NULL)
			    {
			      write_exp_msymbol (msymbol,
						 lookup_function_type (builtin_type_int),
						 builtin_type_int);
			    }
			  else
			    if (!have_full_symbols () && !have_partial_symbols ())
			      error ("No symbol table is loaded.  Use the \"file\" command.");
			    else
			      error ("No symbol \"%s\" in current context.", name);
			}
break;
case 59:
#line 637 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ struct symbol *sym = yystack.l_mark[0].ssym.sym;

			  if (sym)
			    {
			      if (symbol_read_needs_frame (sym))
				{
				  if (innermost_block == 0 ||
				      contained_in (block_found,
						    innermost_block))
				    innermost_block = block_found;
				}

			      write_exp_elt_opcode (OP_VAR_VALUE);
			      /* We want to use the selected frame, not
				 another more inner frame which happens to
				 be in the same block.  */
			      write_exp_elt_block (NULL);
			      write_exp_elt_sym (sym);
			      write_exp_elt_opcode (OP_VAR_VALUE);
			      current_type = sym->type; }
			  else if (yystack.l_mark[0].ssym.is_a_field_of_this)
			    {
			      struct value * this_val;
			      struct type * this_type;
			      /* Object pascal: it hangs off of `this'.  Must
			         not inadvertently convert from a method call
				 to data ref.  */
			      if (innermost_block == 0 ||
				  contained_in (block_found, innermost_block))
				innermost_block = block_found;
			      write_exp_elt_opcode (OP_THIS);
			      write_exp_elt_opcode (OP_THIS);
			      write_exp_elt_opcode (STRUCTOP_PTR);
			      write_exp_string (yystack.l_mark[0].ssym.stoken);
			      write_exp_elt_opcode (STRUCTOP_PTR);
			      /* we need type of this */
			      this_val = value_of_this (0); 
			      if (this_val)
				this_type = this_val->type;
			      else
				this_type = NULL;
			      if (this_type)
				current_type = lookup_struct_elt_type (
				  this_type,
				  copy_name (yystack.l_mark[0].ssym.stoken), 0);
			      else
				current_type = NULL; 
			    }
			  else
			    {
			      struct minimal_symbol *msymbol;
			      char *arg = copy_name (yystack.l_mark[0].ssym.stoken);

			      msymbol =
				lookup_minimal_symbol (arg, NULL, NULL);
			      if (msymbol != NULL)
				{
				  write_exp_msymbol (msymbol,
						     lookup_function_type (builtin_type_int),
						     builtin_type_int);
				}
			      else if (!have_full_symbols () && !have_partial_symbols ())
				error ("No symbol table is loaded.  Use the \"file\" command.");
			      else
				error ("No symbol \"%s\" in current context.",
				       copy_name (yystack.l_mark[0].ssym.stoken));
			    }
			}
break;
case 62:
#line 721 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ yyval.tval = lookup_member_type (builtin_type_int, yystack.l_mark[-2].tval); }
break;
case 63:
#line 726 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ yyval.tval = lookup_pointer_type (yystack.l_mark[0].tval); }
break;
case 64:
#line 728 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ yyval.tval = yystack.l_mark[0].tsym.type; }
break;
case 65:
#line 730 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ yyval.tval = lookup_struct (copy_name (yystack.l_mark[0].sval),
					      expression_context_block); }
break;
case 66:
#line 733 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ yyval.tval = lookup_struct (copy_name (yystack.l_mark[0].sval),
					      expression_context_block); }
break;
case 67:
#line 740 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ yyval.sval = yystack.l_mark[0].ssym.stoken; }
break;
case 68:
#line 741 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ yyval.sval = yystack.l_mark[0].ssym.stoken; }
break;
case 69:
#line 742 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ yyval.sval = yystack.l_mark[0].tsym.stoken; }
break;
case 70:
#line 743 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/p-exp.y"
	{ yyval.sval = yystack.l_mark[0].ssym.stoken; }
break;
#line 2249 "p-exp.c"
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
