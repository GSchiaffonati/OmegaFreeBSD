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

#line 45 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"

#include "defs.h"
#include "gdb_string.h"
#include "expression.h"
#include "value.h"
#include "parser-defs.h"
#include "language.h"
#include "f-lang.h"
#include "bfd.h" /* Required by objfiles.h.  */
#include "symfile.h" /* Required by objfiles.h.  */
#include "objfiles.h" /* For have_full_symbols and have_partial_symbols */
#include "block.h"
#include <ctype.h>

/* Remap normal yacc parser interface names (yyparse, yylex, yyerror, etc),
   as well as gratuitiously global symbol names, so we can have multiple
   yacc generated parsers in gdb.  Note that these are only the variables
   produced by yacc.  If other parser generators (bison, byacc, etc) produce
   additional global names that conflict at link time, then those parser
   generators need to be fixed instead of adding those names to this list. */

#define	yymaxdepth f_maxdepth
#define	yyparse	f_parse
#define	yylex	f_lex
#define	yyerror	f_error
#define	yylval	f_lval
#define	yychar	f_char
#define	yydebug	f_debug
#define	yypact	f_pact	
#define	yyr1	f_r1			
#define	yyr2	f_r2			
#define	yydef	f_def		
#define	yychk	f_chk		
#define	yypgo	f_pgo		
#define	yyact	f_act		
#define	yyexca	f_exca
#define yyerrflag f_errflag
#define yynerrs	f_nerrs
#define	yyps	f_ps
#define	yypv	f_pv
#define	yys	f_s
#define	yy_yys	f_yys
#define	yystate	f_state
#define	yytmp	f_tmp
#define	yyv	f_v
#define	yy_yyv	f_yyv
#define	yyval	f_val
#define	yylloc	f_lloc
#define yyreds	f_reds		/* With YYDEBUG defined */
#define yytoks	f_toks		/* With YYDEBUG defined */
#define yyname	f_name		/* With YYDEBUG defined */
#define yyrule	f_rule		/* With YYDEBUG defined */
#define yylhs	f_yylhs
#define yylen	f_yylen
#define yydefred f_yydefred
#define yydgoto	f_yydgoto
#define yysindex f_yysindex
#define yyrindex f_yyrindex
#define yygindex f_yygindex
#define yytable	 f_yytable
#define yycheck	 f_yycheck

#ifndef YYDEBUG
#define	YYDEBUG	1		/* Default to yydebug support */
#endif

#define YYFPRINTF parser_fprintf

int yyparse (void);

static int yylex (void);

void yyerror (char *);

static void growbuf_by_size (int);

static int match_string_literal (void);

#line 129 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
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
    } typed_val;
    DOUBLEST dval;
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
#line 152 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
/* YYSTYPE gets defined by %union */
static int parse_number (char *, int, int, YYSTYPE *);
#line 132 "f-exp.c"

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
#define STRING_LITERAL 259
#define BOOLEAN_LITERAL 260
#define NAME 261
#define TYPENAME 262
#define NAME_OR_INT 263
#define SIZEOF 264
#define ERROR 265
#define INT_KEYWORD 266
#define INT_S2_KEYWORD 267
#define LOGICAL_S1_KEYWORD 268
#define LOGICAL_S2_KEYWORD 269
#define LOGICAL_KEYWORD 270
#define REAL_KEYWORD 271
#define REAL_S8_KEYWORD 272
#define REAL_S16_KEYWORD 273
#define COMPLEX_S8_KEYWORD 274
#define COMPLEX_S16_KEYWORD 275
#define COMPLEX_S32_KEYWORD 276
#define BOOL_AND 277
#define BOOL_OR 278
#define BOOL_NOT 279
#define CHARACTER 280
#define VARIABLE 281
#define ASSIGN_MODIFY 282
#define ABOVE_COMMA 283
#define EQUAL 284
#define NOTEQUAL 285
#define LESSTHAN 286
#define GREATERTHAN 287
#define LEQ 288
#define GEQ 289
#define LSH 290
#define RSH 291
#define UNARY 292
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    2,    1,    1,    1,    1,    1,    1,    1,
   15,    1,   14,   14,   14,   14,   16,   17,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    4,   10,   10,    9,    9,    9,    9,    9,    8,    8,
    8,    7,    7,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    5,    5,    5,    5,   13,    6,    6,   11,
   11,   11,   12,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    3,    2,    2,    2,    2,    2,    2,
    0,    5,    0,    1,    1,    3,    3,    3,    3,    4,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    1,    1,    1,    1,    1,    4,    1,    1,    1,
    1,    1,    2,    1,    2,    1,    2,    1,    3,    2,
    1,    2,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    3,    1,
    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   42,   44,   49,   48,   83,   64,   43,    0,   65,   66,
   70,   69,   68,   71,   72,   73,   74,   75,   76,    0,
   67,   46,    0,    0,    0,    0,    0,    0,    0,    2,
   45,    3,    0,   51,   50,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   11,    0,    0,    0,
   61,    0,   53,    0,    0,    4,    0,   19,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   57,   55,   62,   78,    0,    0,    0,   60,    0,    0,
    0,    0,    0,   15,    0,   63,   59,    0,    0,   12,
   79,    0,    0,
};
static const YYINT yydgoto[] = {                         28,
   42,   30,   31,  104,   33,  105,   71,   72,   73,   34,
    0,   35,    0,  113,  100,  114,   44,
};
static const YYINT yysindex[] = {                      1080,
    0,    0,    0,    0,    0,    0,    0, 1044,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1105,
    0,    0, 1105, 1105, 1105, 1080, 1105,    0,  991,    0,
    0,    0,  -29,    0,    0, 1080,  -36,  -36,  -36,  -36,
  -36,  938,  -22,   -8,  -36, 1105, 1105, 1105, 1105, 1105,
 1105, 1105, 1105, 1105, 1105, 1105, 1105, 1105, 1105, 1105,
 1105, 1105, 1105, 1105, 1105, 1105,    0,  -29,  -29, 1123,
    0,  -34,    0,   -4, 1105,    0, 1105,    0,  898, 1006,
  991,  991,  951, 1029,   64,  681,  681,  -35,  -35,  -35,
  -35,  -15,  -15,  227,  145,  145,  -36,  -36,  -36, 1105,
    0,    0,    0,    0,  -41,   11, 1177,    0, 1159,  991,
  -36,  966,  -26,    0,  -47,    0,    0, 1105, 1105,    0,
    0,  991,  991,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   41,    0,
    0,    0,   35,    0,    0,    0,    1,   26,   55,   94,
  122,    0,    0,    0,  153,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   36,  133,    0,
    0,  134,    0,    0,    0,    0,    0,    0,   17,   47,
   16,   86,  535,   82,  199,  110,  562,  825,  871,  890,
  916,  617,  636,  590,  544,  571,  207,  414,  462,  -21,
    0,    0,    0,    0,    0,    0,    0,    0,  487,   12,
  516,  -20,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -10,   10,
};
static const YYINT yygindex[] = {                         0,
 1454,    0,    0,   14,    0,    0,  -16,    0,   77,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1573
static const YYINT yytable[] = {                        116,
   10,   66,  115,   67,   67,  107,   64,   62,   68,   63,
   70,   65,   69,   32,  120,   41,   38,  119,   77,   13,
   14,   66,   13,   14,   67,    8,   64,   62,   61,   63,
   17,   65,   78,   17,   52,   56,  109,   10,   10,   43,
    1,   10,   10,   10,   10,   10,   39,   10,   61,   74,
   16,  117,   18,   16,    6,  108,   41,   38,   10,   41,
   38,   10,    8,    8,   10,    0,    8,    8,    8,    8,
    8,    0,    8,   41,   38,   52,   56,   38,   52,   56,
    0,   36,    0,    8,    0,   40,    8,   39,    0,    8,
   39,    6,    6,    7,   10,    6,    6,    6,    6,    6,
   66,    6,    0,   67,   39,   64,   62,   39,   63,   29,
   65,    0,    6,    0,    0,    6,    0,    0,    6,    8,
    0,    5,   36,    0,   10,   36,   40,   61,  121,   40,
    7,    7,   54,   58,    7,    7,    7,    7,    7,   36,
    7,    0,   36,   40,  101,  102,  106,   29,    6,    8,
   29,    7,    9,   29,    7,    0,    0,    7,    5,    5,
    0,    0,    5,    5,    5,    5,    5,   29,    5,    0,
   29,    0,    0,   54,   58,   36,   54,   58,    6,    5,
    0,   66,    5,    0,   67,    5,   64,    7,    0,    9,
    9,   65,    0,    9,    9,    9,    9,    9,   35,    9,
    0,    0,    0,   29,    0,   36,   22,    0,    0,    0,
    9,    0,    0,    9,    6,    5,    9,    7,    9,   10,
   11,   12,   13,   14,   15,   16,   17,   18,   19,    0,
    0,    0,   21,   29,    0,    0,   35,    0,    0,   35,
    0,    0,   35,   22,   22,    5,    9,   22,   22,   22,
   22,   22,    0,   22,   59,   60,   35,    0,    0,   35,
    0,    0,    0,   66,   22,    0,   67,   22,   64,   62,
   22,   63,    0,   65,    0,    0,    9,   10,   10,    0,
    0,    0,   10,    0,   10,   10,   10,   10,   10,   10,
   10,   10,   35,   38,   38,    0,    0,    0,   38,    0,
   22,    0,    8,    8,    0,    0,    0,    8,    0,    8,
    8,    8,    8,    8,    8,    8,    8,    0,    0,    0,
    0,    0,   35,    0,   39,    0,    0,    0,   39,    0,
   22,    6,    6,    0,    0,    0,    6,    0,    6,    6,
    6,    6,    6,    6,    6,    6,    0,   53,   54,   55,
   56,   57,   58,   59,   60,    0,    0,    0,   36,   36,
    0,    0,    0,   36,    0,    0,    0,    0,    0,    0,
    7,    7,    0,    0,    0,    7,    0,    7,    7,    7,
    7,    7,    7,    7,    7,    0,   29,   29,    0,    0,
    0,   29,    0,   29,   29,    0,    0,    0,    5,    5,
    0,    0,    0,    5,    0,    5,    5,    5,    5,    5,
    5,    5,    5,   23,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    9,
    9,    0,    0,    0,    9,    0,    9,    9,    9,    9,
    9,    9,    9,    9,    0,    0,    0,    0,    0,    0,
   23,   23,    0,    0,   23,   23,   23,   23,   23,    0,
   23,   24,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   23,    0,    0,   23,   35,   35,   23,    0,    0,
   35,    0,    0,   22,   22,    0,   47,    0,   22,    0,
   22,   22,   22,   22,   22,   22,   22,   22,   24,   24,
    0,    0,   24,   24,   24,   24,   24,   23,   24,    0,
    0,    0,    0,    0,    0,   20,    0,    0,    0,   24,
    0,    0,   24,   47,   47,   24,    0,   47,   47,   47,
   47,   47,    0,   47,   37,    0,    0,   23,    0,    0,
    0,    0,    0,   25,   47,    0,    0,   47,    0,    0,
   47,    0,   20,   20,    0,   24,   20,   20,   20,   20,
   20,   30,   20,    0,    0,    0,    0,    0,    0,    0,
   26,    0,    0,   20,    0,   37,   20,    0,   37,   20,
   47,   25,    0,    0,   25,   24,   25,   25,   25,   21,
    0,    0,   37,    0,    0,   37,    0,    0,    0,   30,
    0,   25,   30,    0,   25,   30,    0,   25,   26,   20,
   47,   26,    0,   26,   26,   26,   27,    0,    0,   30,
    0,    0,   30,    0,    0,    0,    0,   21,   26,    0,
   21,   26,    0,   21,   26,   28,    0,   25,    0,   20,
    0,    0,    0,    0,    0,    0,    0,   21,    0,    0,
   21,    0,    0,   21,   27,   30,    0,   27,   37,    0,
   27,    0,    0,    0,   26,    0,    0,   25,    0,    0,
    0,    0,    0,   28,   27,    0,   28,   27,    0,   28,
    0,    0,    0,   21,    0,   30,    0,    0,    0,    0,
   23,   23,    0,   28,   26,   23,   28,   23,   23,   23,
   23,   23,   23,   23,   23,    0,    0,    0,    0,    0,
   27,    0,    0,   21,    0,    0,    0,   66,    0,    0,
   67,    0,   64,   62,    0,   63,    0,   65,    0,   28,
    0,    0,    0,    0,    0,    0,    0,    0,   24,   24,
   27,    0,    0,   24,   61,   24,   24,   24,   24,   24,
   24,   24,   24,    0,    0,    0,    0,    0,    0,   28,
    0,    0,    0,   47,   47,    0,    0,    0,   47,    0,
   47,   47,   47,   47,   47,   47,   47,   47,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   20,   20,    0,    0,    0,   20,    0,   20,
   20,   20,   20,   20,   20,   20,   20,    0,    0,    0,
    0,   37,   37,    0,    0,    0,   37,    0,    0,    0,
   25,   25,    0,    0,   33,   25,    0,   25,   25,   25,
   25,   25,   25,   25,   25,    0,    0,    0,   30,   30,
    0,    0,    0,   30,    0,   30,   30,   26,   26,    0,
    0,    0,   26,    0,   26,   26,   26,   26,   26,   26,
   26,   26,   33,    0,    0,   33,   21,   21,   33,    0,
   34,   21,    0,   21,   21,   21,   21,   21,   21,   21,
   21,    0,   33,    0,    0,   33,    0,    0,    0,   31,
    0,    0,    0,   27,   27,    0,    0,    0,   27,    0,
   27,   27,   27,   27,   27,   27,   27,   27,   34,    0,
    0,   34,   28,   28,   34,   32,    0,   28,   33,   28,
   28,   28,   28,   28,   28,   28,   28,   31,   34,    0,
   31,   34,    0,   31,   66,   52,    0,   67,    0,   64,
   62,    0,   63,    0,   65,    0,    0,   31,   33,    0,
   31,    0,    0,   32,    0,    0,   32,    0,    0,   32,
    0,   61,    0,    0,   34,    0,   55,   56,   57,   58,
   59,   60,    0,   32,   66,   52,   32,   67,   76,   64,
   62,   75,   63,   31,   65,    0,    0,   66,   52,    0,
   67,   51,   64,   62,   34,   63,    0,   65,   49,    0,
    0,   61,   66,   52,    0,   67,    0,   64,   62,   32,
   63,    0,   65,   31,   61,    0,    0,    0,    0,    0,
    0,   50,    0,  118,    0,    0,   49,   66,   52,   61,
   67,   51,   64,   62,    0,   63,    0,   65,    0,   32,
    0,    0,   66,   52,   51,   67,    0,   64,   62,    0,
   63,   49,   65,    0,   61,    0,    0,    0,    0,   51,
    0,   50,    0,    0,    0,   66,   52,    0,   67,   61,
   64,   62,    0,   63,    0,   65,    0,    0,    0,    0,
    0,   23,    0,   36,   51,   25,    0,    0,   24,   50,
    0,    0,   61,    0,    0,    0,    0,    0,    0,   51,
    0,   33,   33,    0,    0,    0,   33,    0,   33,   33,
   33,   33,   33,   33,   50,    0,    0,   23,    0,   26,
    0,   25,    0,    0,   24,    0,    0,    0,    0,   50,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   23,    0,   26,    0,   25,   34,   34,   24,
    0,    0,   34,    0,   34,   34,   34,   34,   34,   34,
   68,    0,   70,  103,   69,    0,   31,   31,    0,   27,
    0,   31,    0,   31,   31,   31,   31,   31,   31,    0,
    0,   53,   54,   55,   56,   57,   58,   59,   60,    0,
    0,    0,   32,   32,    0,    0,    0,   32,   26,   32,
   32,   32,   32,   32,   32,   27,    0,    0,    0,    0,
    0,    0,    0,    0,   46,   47,    0,  103,    0,   48,
    0,   53,   54,   55,   56,   57,   58,   59,   60,    0,
   27,    0,    0,    0,   53,   54,   55,   56,   57,   58,
   59,   60,   46,   47,    0,    0,    0,   48,    0,   53,
   54,   55,   56,   57,   58,   59,   60,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   46,   47,    0,
    0,    0,   48,    0,   53,   54,   55,   56,   57,   58,
   59,   60,   46,    0,   27,    0,    0,    0,    0,   53,
   54,   55,   56,   57,   58,   59,   60,    0,    0,    0,
    1,    2,    3,    4,    5,    0,    7,    8,    0,    0,
    0,    0,   53,   54,   55,   56,   57,   58,   59,   60,
    0,    0,   20,    0,   22,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    1,    2,    3,    4,
    5,    6,    7,    8,    0,    9,   10,   11,   12,   13,
   14,   15,   16,   17,   18,   19,    0,    0,   20,   21,
   22,    1,    2,    3,    4,    5,    0,    7,    8,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   20,    6,   22,    0,    0,    9,   10,
   11,   12,   13,   14,   15,   16,   17,   18,   19,    0,
    0,    0,   21,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    2,    3,    4,    5,
    0,    7,    8,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   20,    6,   22,
    0,    0,    9,   10,   11,   12,   13,   14,   15,   16,
   17,   18,   19,   29,    0,    0,   21,    0,    0,    0,
    0,   37,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   38,    0,    0,   39,   40,   41,    0,
   45,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
   90,   91,   92,   93,   94,   95,   96,   97,   98,   99,
    0,    0,    0,    0,    0,    0,    0,    0,  110,    0,
  111,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  112,    0,    0,    0,    0,    0,    0,
    0,    0,  111,    0,    0,    0,    0,    0,    0,    0,
    0,  122,  123,
};
static const YYINT yycheck[] = {                         41,
    0,   37,   44,   40,   40,   40,   42,   43,   38,   45,
   40,   47,   42,    0,   41,    0,    0,   44,   41,   41,
   41,   37,   44,   44,   40,    0,   42,   43,   64,   45,
   41,   47,   41,   44,    0,    0,   41,   37,   38,   26,
    0,   41,   42,   43,   44,   45,    0,   47,   64,   36,
   41,   41,   41,   44,    0,   72,   41,   41,   58,   44,
   44,   61,   37,   38,   64,   -1,   41,   42,   43,   44,
   45,   -1,   47,   58,   58,   41,   41,   61,   44,   44,
   -1,    0,   -1,   58,   -1,    0,   61,   41,   -1,   64,
   44,   37,   38,    0,   94,   41,   42,   43,   44,   45,
   37,   47,   -1,   40,   58,   42,   43,   61,   45,    0,
   47,   -1,   58,   -1,   -1,   61,   -1,   -1,   64,   94,
   -1,    0,   41,   -1,  124,   44,   41,   64,  115,   44,
   37,   38,    0,    0,   41,   42,   43,   44,   45,   58,
   47,   -1,   61,   58,   68,   69,   70,   38,   94,  124,
   41,   58,    0,   44,   61,   -1,   -1,   64,   37,   38,
   -1,   -1,   41,   42,   43,   44,   45,   58,   47,   -1,
   61,   -1,   -1,   41,   41,   94,   44,   44,  124,   58,
   -1,   37,   61,   -1,   40,   64,   42,   94,   -1,   37,
   38,   47,   -1,   41,   42,   43,   44,   45,    0,   47,
   -1,   -1,   -1,   94,   -1,  124,    0,   -1,   -1,   -1,
   58,   -1,   -1,   61,  262,   94,   64,  124,  266,  267,
  268,  269,  270,  271,  272,  273,  274,  275,  276,   -1,
   -1,   -1,  280,  124,   -1,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,   37,   38,  124,   94,   41,   42,   43,
   44,   45,   -1,   47,  290,  291,   58,   -1,   -1,   61,
   -1,   -1,   -1,   37,   58,   -1,   40,   61,   42,   43,
   64,   45,   -1,   47,   -1,   -1,  124,  277,  278,   -1,
   -1,   -1,  282,   -1,  284,  285,  286,  287,  288,  289,
  290,  291,   94,  277,  278,   -1,   -1,   -1,  282,   -1,
   94,   -1,  277,  278,   -1,   -1,   -1,  282,   -1,  284,
  285,  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,
   -1,   -1,  124,   -1,  278,   -1,   -1,   -1,  282,   -1,
  124,  277,  278,   -1,   -1,   -1,  282,   -1,  284,  285,
  286,  287,  288,  289,  290,  291,   -1,  284,  285,  286,
  287,  288,  289,  290,  291,   -1,   -1,   -1,  277,  278,
   -1,   -1,   -1,  282,   -1,   -1,   -1,   -1,   -1,   -1,
  277,  278,   -1,   -1,   -1,  282,   -1,  284,  285,  286,
  287,  288,  289,  290,  291,   -1,  277,  278,   -1,   -1,
   -1,  282,   -1,  284,  285,   -1,   -1,   -1,  277,  278,
   -1,   -1,   -1,  282,   -1,  284,  285,  286,  287,  288,
  289,  290,  291,    0,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  277,
  278,   -1,   -1,   -1,  282,   -1,  284,  285,  286,  287,
  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,   -1,
   37,   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,
   47,    0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   58,   -1,   -1,   61,  277,  278,   64,   -1,   -1,
  282,   -1,   -1,  277,  278,   -1,    0,   -1,  282,   -1,
  284,  285,  286,  287,  288,  289,  290,  291,   37,   38,
   -1,   -1,   41,   42,   43,   44,   45,   94,   47,   -1,
   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   58,
   -1,   -1,   61,   37,   38,   64,   -1,   41,   42,   43,
   44,   45,   -1,   47,    0,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   -1,    0,   58,   -1,   -1,   61,   -1,   -1,
   64,   -1,   37,   38,   -1,   94,   41,   42,   43,   44,
   45,    0,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
    0,   -1,   -1,   58,   -1,   41,   61,   -1,   44,   64,
   94,   38,   -1,   -1,   41,  124,   43,   44,   45,    0,
   -1,   -1,   58,   -1,   -1,   61,   -1,   -1,   -1,   38,
   -1,   58,   41,   -1,   61,   44,   -1,   64,   38,   94,
  124,   41,   -1,   43,   44,   45,    0,   -1,   -1,   58,
   -1,   -1,   61,   -1,   -1,   -1,   -1,   38,   58,   -1,
   41,   61,   -1,   44,   64,    0,   -1,   94,   -1,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   58,   -1,   -1,
   61,   -1,   -1,   64,   38,   94,   -1,   41,  124,   -1,
   44,   -1,   -1,   -1,   94,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   -1,   38,   58,   -1,   41,   61,   -1,   44,
   -1,   -1,   -1,   94,   -1,  124,   -1,   -1,   -1,   -1,
  277,  278,   -1,   58,  124,  282,   61,  284,  285,  286,
  287,  288,  289,  290,  291,   -1,   -1,   -1,   -1,   -1,
   94,   -1,   -1,  124,   -1,   -1,   -1,   37,   -1,   -1,
   40,   -1,   42,   43,   -1,   45,   -1,   47,   -1,   94,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  277,  278,
  124,   -1,   -1,  282,   64,  284,  285,  286,  287,  288,
  289,  290,  291,   -1,   -1,   -1,   -1,   -1,   -1,  124,
   -1,   -1,   -1,  277,  278,   -1,   -1,   -1,  282,   -1,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  277,  278,   -1,   -1,   -1,  282,   -1,  284,
  285,  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,
   -1,  277,  278,   -1,   -1,   -1,  282,   -1,   -1,   -1,
  277,  278,   -1,   -1,    0,  282,   -1,  284,  285,  286,
  287,  288,  289,  290,  291,   -1,   -1,   -1,  277,  278,
   -1,   -1,   -1,  282,   -1,  284,  285,  277,  278,   -1,
   -1,   -1,  282,   -1,  284,  285,  286,  287,  288,  289,
  290,  291,   38,   -1,   -1,   41,  277,  278,   44,   -1,
    0,  282,   -1,  284,  285,  286,  287,  288,  289,  290,
  291,   -1,   58,   -1,   -1,   61,   -1,   -1,   -1,    0,
   -1,   -1,   -1,  277,  278,   -1,   -1,   -1,  282,   -1,
  284,  285,  286,  287,  288,  289,  290,  291,   38,   -1,
   -1,   41,  277,  278,   44,    0,   -1,  282,   94,  284,
  285,  286,  287,  288,  289,  290,  291,   38,   58,   -1,
   41,   61,   -1,   44,   37,   38,   -1,   40,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   58,  124,   -1,
   61,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,
   -1,   64,   -1,   -1,   94,   -1,  286,  287,  288,  289,
  290,  291,   -1,   58,   37,   38,   61,   40,   41,   42,
   43,   44,   45,   94,   47,   -1,   -1,   37,   38,   -1,
   40,   94,   42,   43,  124,   45,   -1,   47,   61,   -1,
   -1,   64,   37,   38,   -1,   40,   -1,   42,   43,   94,
   45,   -1,   47,  124,   64,   -1,   -1,   -1,   -1,   -1,
   -1,  124,   -1,   58,   -1,   -1,   61,   37,   38,   64,
   40,   94,   42,   43,   -1,   45,   -1,   47,   -1,  124,
   -1,   -1,   37,   38,   94,   40,   -1,   42,   43,   -1,
   45,   61,   47,   -1,   64,   -1,   -1,   -1,   -1,   94,
   -1,  124,   -1,   -1,   -1,   37,   38,   -1,   40,   64,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,   38,   -1,   40,   94,   42,   -1,   -1,   45,  124,
   -1,   -1,   64,   -1,   -1,   -1,   -1,   -1,   -1,   94,
   -1,  277,  278,   -1,   -1,   -1,  282,   -1,  284,  285,
  286,  287,  288,  289,  124,   -1,   -1,   38,   -1,   40,
   -1,   42,   -1,   -1,   45,   -1,   -1,   -1,   -1,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   38,   -1,   40,   -1,   42,  277,  278,   45,
   -1,   -1,  282,   -1,  284,  285,  286,  287,  288,  289,
   38,   -1,   40,   41,   42,   -1,  277,  278,   -1,  126,
   -1,  282,   -1,  284,  285,  286,  287,  288,  289,   -1,
   -1,  284,  285,  286,  287,  288,  289,  290,  291,   -1,
   -1,   -1,  277,  278,   -1,   -1,   -1,  282,   40,  284,
  285,  286,  287,  288,  289,  126,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  277,  278,   -1,   41,   -1,  282,
   -1,  284,  285,  286,  287,  288,  289,  290,  291,   -1,
  126,   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,
  290,  291,  277,  278,   -1,   -1,   -1,  282,   -1,  284,
  285,  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  277,  278,   -1,
   -1,   -1,  282,   -1,  284,  285,  286,  287,  288,  289,
  290,  291,  277,   -1,  126,   -1,   -1,   -1,   -1,  284,
  285,  286,  287,  288,  289,  290,  291,   -1,   -1,   -1,
  257,  258,  259,  260,  261,   -1,  263,  264,   -1,   -1,
   -1,   -1,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,  279,   -1,  281,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,  263,  264,   -1,  266,  267,  268,  269,  270,
  271,  272,  273,  274,  275,  276,   -1,   -1,  279,  280,
  281,  257,  258,  259,  260,  261,   -1,  263,  264,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  279,  262,  281,   -1,   -1,  266,  267,
  268,  269,  270,  271,  272,  273,  274,  275,  276,   -1,
   -1,   -1,  280,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,
   -1,  263,  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  279,  262,  281,
   -1,   -1,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  275,  276,    0,   -1,   -1,  280,   -1,   -1,   -1,
   -1,    8,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   20,   -1,   -1,   23,   24,   25,   -1,
   27,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   46,
   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,
   57,   58,   59,   60,   61,   62,   63,   64,   65,   66,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   75,   -1,
   77,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  100,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  109,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  118,  119,
};
#define YYFINAL 28
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#define YYUNDFTOKEN 312
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,
0,0,"':'",0,0,"'='",0,"'?'","'@'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'|'",0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","FLOAT","STRING_LITERAL",
"BOOLEAN_LITERAL","NAME","TYPENAME","NAME_OR_INT","SIZEOF","ERROR",
"INT_KEYWORD","INT_S2_KEYWORD","LOGICAL_S1_KEYWORD","LOGICAL_S2_KEYWORD",
"LOGICAL_KEYWORD","REAL_KEYWORD","REAL_S8_KEYWORD","REAL_S16_KEYWORD",
"COMPLEX_S8_KEYWORD","COMPLEX_S16_KEYWORD","COMPLEX_S32_KEYWORD","BOOL_AND",
"BOOL_OR","BOOL_NOT","CHARACTER","VARIABLE","ASSIGN_MODIFY","ABOVE_COMMA",
"EQUAL","NOTEQUAL","LESSTHAN","GREATERTHAN","LEQ","GEQ","LSH","RSH","UNARY",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : exp",
"start : type_exp",
"type_exp : type",
"exp : '(' exp ')'",
"exp : '*' exp",
"exp : '&' exp",
"exp : '-' exp",
"exp : BOOL_NOT exp",
"exp : '~' exp",
"exp : SIZEOF exp",
"$$1 :",
"exp : exp '(' $$1 arglist ')'",
"arglist :",
"arglist : exp",
"arglist : substring",
"arglist : arglist ',' exp",
"substring : exp ':' exp",
"complexnum : exp ',' exp",
"exp : '(' complexnum ')'",
"exp : '(' type ')' exp",
"exp : exp '@' exp",
"exp : exp '*' exp",
"exp : exp '/' exp",
"exp : exp '%' exp",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : exp LSH exp",
"exp : exp RSH exp",
"exp : exp EQUAL exp",
"exp : exp NOTEQUAL exp",
"exp : exp LEQ exp",
"exp : exp GEQ exp",
"exp : exp LESSTHAN exp",
"exp : exp GREATERTHAN exp",
"exp : exp '&' exp",
"exp : exp '^' exp",
"exp : exp '|' exp",
"exp : exp BOOL_AND exp",
"exp : exp BOOL_OR exp",
"exp : exp '=' exp",
"exp : exp ASSIGN_MODIFY exp",
"exp : INT",
"exp : NAME_OR_INT",
"exp : FLOAT",
"exp : variable",
"exp : VARIABLE",
"exp : SIZEOF '(' type ')'",
"exp : BOOLEAN_LITERAL",
"exp : STRING_LITERAL",
"variable : name_not_typename",
"type : ptype",
"ptype : typebase",
"ptype : typebase abs_decl",
"abs_decl : '*'",
"abs_decl : '*' abs_decl",
"abs_decl : '&'",
"abs_decl : '&' abs_decl",
"abs_decl : direct_abs_decl",
"direct_abs_decl : '(' abs_decl ')'",
"direct_abs_decl : direct_abs_decl func_mod",
"direct_abs_decl : func_mod",
"func_mod : '(' ')'",
"func_mod : '(' nonempty_typelist ')'",
"typebase : TYPENAME",
"typebase : INT_KEYWORD",
"typebase : INT_S2_KEYWORD",
"typebase : CHARACTER",
"typebase : LOGICAL_KEYWORD",
"typebase : LOGICAL_S2_KEYWORD",
"typebase : LOGICAL_S1_KEYWORD",
"typebase : REAL_KEYWORD",
"typebase : REAL_S8_KEYWORD",
"typebase : REAL_S16_KEYWORD",
"typebase : COMPLEX_S8_KEYWORD",
"typebase : COMPLEX_S16_KEYWORD",
"typebase : COMPLEX_S32_KEYWORD",
"typename : TYPENAME",
"nonempty_typelist : type",
"nonempty_typelist : nonempty_typelist ',' type",
"name : NAME",
"name : TYPENAME",
"name : NAME_OR_INT",
"name_not_typename : NAME",

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
#line 635 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"

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
  LONGEST n = 0;
  LONGEST prevn = 0;
  int c;
  int base = input_radix;
  int unsigned_p = 0;
  int long_p = 0;
  ULONGEST high_bit;
  struct type *signed_type;
  struct type *unsigned_type;

  if (parsed_float)
    {
      /* It's a float since it contains a point or an exponent.  */
      /* [dD] is not understood as an exponent by atof, change it to 'e'.  */
      char *tmp, *tmp2;

      tmp = xstrdup (p);
      for (tmp2 = tmp; *tmp2; ++tmp2)
	if (*tmp2 == 'd' || *tmp2 == 'D')
	  *tmp2 = 'e';
      putithere->dval = atof (tmp);
      free (tmp);
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
      if (isupper (c))
	c = tolower (c);
      if (len == 0 && c == 'l')
	long_p = 1;
      else if (len == 0 && c == 'u')
	unsigned_p = 1;
      else
	{
	  int i;
	  if (c >= '0' && c <= '9')
	    i = c - '0';
	  else if (c >= 'a' && c <= 'f')
	    i = c - 'a' + 10;
	  else
	    return ERROR;	/* Char not a digit */
	  if (i >= base)
	    return ERROR;		/* Invalid digit in this base */
	  n *= base;
	  n += i;
	}
      /* Portably test for overflow (only works for nonzero values, so make
	 a second check for zero).  */
      if ((prevn >= n) && n != 0)
	unsigned_p=1;		/* Try something unsigned */
      /* If range checking enabled, portably test for unsigned overflow.  */
      if (RANGE_CHECK && n != 0)
	{
	  if ((unsigned_p && (unsigned)prevn >= (unsigned)n))
	    range_error("Overflow on numeric constant.");	 
	}
      prevn = n;
    }
  
  /* If the number is too big to be an int, or it's got an l suffix
     then it's a long.  Work out if this has to be a long by
     shifting right and and seeing if anything remains, and the
     target int size is different to the target long size.
     
     In the expression below, we could have tested
     (n >> TARGET_INT_BIT)
     to see if it was zero,
     but too many compilers warn about that, when ints and longs
     are the same size.  So we shift it twice, with fewer bits
     each time, for the same result.  */
  
  if ((TARGET_INT_BIT != TARGET_LONG_BIT 
       && ((n >> 2) >> (TARGET_INT_BIT-2)))   /* Avoid shift warning */
      || long_p)
    {
      high_bit = ((ULONGEST)1) << (TARGET_LONG_BIT-1);
      unsigned_type = builtin_type_unsigned_long;
      signed_type = builtin_type_long;
    }
  else 
    {
      high_bit = ((ULONGEST)1) << (TARGET_INT_BIT-1);
      unsigned_type = builtin_type_unsigned_int;
      signed_type = builtin_type_int;
    }    
  
  putithere->typed_val.val = n;
  
  /* If the high bit of the worked out type is set then this number
     has to be unsigned. */
  
  if (unsigned_p || (n & high_bit)) 
    putithere->typed_val.type = unsigned_type;
  else 
    putithere->typed_val.type = signed_type;
  
  return INT;
}

struct token
{
  char *operator;
  int token;
  enum exp_opcode opcode;
};

static const struct token dot_ops[] =
{
  { ".and.", BOOL_AND, BINOP_END },
  { ".AND.", BOOL_AND, BINOP_END },
  { ".or.", BOOL_OR, BINOP_END },
  { ".OR.", BOOL_OR, BINOP_END },
  { ".not.", BOOL_NOT, BINOP_END },
  { ".NOT.", BOOL_NOT, BINOP_END },
  { ".eq.", EQUAL, BINOP_END },
  { ".EQ.", EQUAL, BINOP_END },
  { ".eqv.", EQUAL, BINOP_END },
  { ".NEQV.", NOTEQUAL, BINOP_END },
  { ".neqv.", NOTEQUAL, BINOP_END },
  { ".EQV.", EQUAL, BINOP_END },
  { ".ne.", NOTEQUAL, BINOP_END },
  { ".NE.", NOTEQUAL, BINOP_END },
  { ".le.", LEQ, BINOP_END },
  { ".LE.", LEQ, BINOP_END },
  { ".ge.", GEQ, BINOP_END },
  { ".GE.", GEQ, BINOP_END },
  { ".gt.", GREATERTHAN, BINOP_END },
  { ".GT.", GREATERTHAN, BINOP_END },
  { ".lt.", LESSTHAN, BINOP_END },
  { ".LT.", LESSTHAN, BINOP_END },
  { NULL, 0, 0 }
};

struct f77_boolean_val 
{
  char *name;
  int value;
}; 

static const struct f77_boolean_val boolean_values[]  = 
{
  { ".true.", 1 },
  { ".TRUE.", 1 },
  { ".false.", 0 },
  { ".FALSE.", 0 },
  { NULL, 0 }
};

static const struct token f77_keywords[] = 
{
  { "complex_16", COMPLEX_S16_KEYWORD, BINOP_END },
  { "complex_32", COMPLEX_S32_KEYWORD, BINOP_END },
  { "character", CHARACTER, BINOP_END },
  { "integer_2", INT_S2_KEYWORD, BINOP_END },
  { "logical_1", LOGICAL_S1_KEYWORD, BINOP_END },
  { "logical_2", LOGICAL_S2_KEYWORD, BINOP_END },
  { "complex_8", COMPLEX_S8_KEYWORD, BINOP_END },
  { "integer", INT_KEYWORD, BINOP_END },
  { "logical", LOGICAL_KEYWORD, BINOP_END },
  { "real_16", REAL_S16_KEYWORD, BINOP_END },
  { "complex", COMPLEX_S8_KEYWORD, BINOP_END },
  { "sizeof", SIZEOF, BINOP_END },
  { "real_8", REAL_S8_KEYWORD, BINOP_END },
  { "real", REAL_KEYWORD, BINOP_END },
  { NULL, 0, 0 }
}; 

/* Implementation of a dynamically expandable buffer for processing input
   characters acquired through lexptr and building a value to return in
   yylval. Ripped off from ch-exp.y */ 

static char *tempbuf;		/* Current buffer contents */
static int tempbufsize;		/* Size of allocated buffer */
static int tempbufindex;	/* Current index into buffer */

#define GROWBY_MIN_SIZE 64	/* Minimum amount to grow buffer by */

#define CHECKBUF(size) \
  do { \
    if (tempbufindex + (size) >= tempbufsize) \
      { \
	growbuf_by_size (size); \
      } \
  } while (0);


/* Grow the static temp buffer if necessary, including allocating the first one
   on demand. */

static void
growbuf_by_size (count)
     int count;
{
  int growby;

  growby = max (count, GROWBY_MIN_SIZE);
  tempbufsize += growby;
  if (tempbuf == NULL)
    tempbuf = (char *) malloc (tempbufsize);
  else
    tempbuf = (char *) realloc (tempbuf, tempbufsize);
}

/* Blatantly ripped off from ch-exp.y. This routine recognizes F77 
   string-literals. 
   
   Recognize a string literal.  A string literal is a nonzero sequence
   of characters enclosed in matching single quotes, except that
   a single character inside single quotes is a character literal, which
   we reject as a string literal.  To embed the terminator character inside
   a string, it is simply doubled (I.E. 'this''is''one''string') */

static int
match_string_literal ()
{
  char *tokptr = lexptr;

  for (tempbufindex = 0, tokptr++; *tokptr != '\0'; tokptr++)
    {
      CHECKBUF (1);
      if (*tokptr == *lexptr)
	{
	  if (*(tokptr + 1) == *lexptr)
	    tokptr++;
	  else
	    break;
	}
      tempbuf[tempbufindex++] = *tokptr;
    }
  if (*tokptr == '\0'					/* no terminator */
      || tempbufindex == 0)				/* no string */
    return 0;
  else
    {
      tempbuf[tempbufindex] = '\0';
      yylval.sval.ptr = tempbuf;
      yylval.sval.length = tempbufindex;
      lexptr = ++tokptr;
      return STRING_LITERAL;
    }
}

/* Read one token, getting characters through lexptr.  */

static int
yylex ()
{
  int c;
  int namelen;
  unsigned int i,token;
  char *tokstart;
  
 retry:
 
  prev_lexptr = lexptr;
 
  tokstart = lexptr;
  
  /* First of all, let us make sure we are not dealing with the 
     special tokens .true. and .false. which evaluate to 1 and 0.  */
  
  if (*lexptr == '.')
    { 
      for (i = 0; boolean_values[i].name != NULL; i++)
	{
	  if (strncmp (tokstart, boolean_values[i].name,
		       strlen (boolean_values[i].name)) == 0)
	    {
	      lexptr += strlen (boolean_values[i].name); 
	      yylval.lval = boolean_values[i].value; 
	      return BOOLEAN_LITERAL;
	    }
	}
    }
  
  /* See if it is a special .foo. operator */
  
  for (i = 0; dot_ops[i].operator != NULL; i++)
    if (strncmp (tokstart, dot_ops[i].operator, strlen (dot_ops[i].operator)) == 0)
      {
	lexptr += strlen (dot_ops[i].operator);
	yylval.opcode = dot_ops[i].opcode;
	return dot_ops[i].token;
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
      token = match_string_literal ();
      if (token != 0)
	return (token);
      break;
      
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
	int got_dot = 0, got_e = 0, got_d = 0, toktype;
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
	    if (!hex && !got_e && (*p == 'e' || *p == 'E'))
	      got_dot = got_e = 1;
	    else if (!hex && !got_d && (*p == 'd' || *p == 'D'))
	      got_dot = got_d = 1;
	    else if (!hex && !got_dot && *p == '.')
	      got_dot = 1;
	    else if (((got_e && (p[-1] == 'e' || p[-1] == 'E'))
		     || (got_d && (p[-1] == 'd' || p[-1] == 'D')))
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
	toktype = parse_number (tokstart, p - tokstart, got_dot|got_e|got_d,
				&yylval);
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
    case '%':
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
    }
  
  if (!(c == '_' || c == '$'
	|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    /* We must have come across a bad character (e.g. ';').  */
    error ("Invalid character '%c' in expression.", c);
  
  namelen = 0;
  for (c = tokstart[namelen];
       (c == '_' || c == '$' || (c >= '0' && c <= '9') 
	|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')); 
       c = tokstart[++namelen]);
  
  /* The token "if" terminates the expression and is NOT 
     removed from the input stream.  */
  
  if (namelen == 2 && tokstart[0] == 'i' && tokstart[1] == 'f')
    return 0;
  
  lexptr += namelen;
  
  /* Catch specific keywords.  */
  
  for (i = 0; f77_keywords[i].operator != NULL; i++)
    if (strncmp (tokstart, f77_keywords[i].operator,
		 strlen(f77_keywords[i].operator)) == 0)
      {
	/* 	lexptr += strlen(f77_keywords[i].operator); */ 
	yylval.opcode = f77_keywords[i].opcode;
	return f77_keywords[i].token;
      }
  
  yylval.sval.ptr = tokstart;
  yylval.sval.length = namelen;
  
  if (*tokstart == '$')
    {
      write_dollar_variable (yylval.sval);
      return VARIABLE;
    }
  
  /* Use token-type TYPENAME for symbols that happen to be defined
     currently as names of types; NAME for other symbols.
     The caller is not constrained to care about the distinction.  */
  {
    char *tmp = copy_name (yylval.sval);
    struct symbol *sym;
    int is_a_field_of_this = 0;
    int hextype;
    
    sym = lookup_symbol (tmp, expression_context_block,
			 VAR_DOMAIN,
			 current_language->la_language == language_cplus
			 ? &is_a_field_of_this : NULL,
			 NULL);
    if (sym && SYMBOL_CLASS (sym) == LOC_TYPEDEF)
      {
	yylval.tsym.type = SYMBOL_TYPE (sym);
	return TYPENAME;
      }
    if ((yylval.tsym.type = lookup_primitive_typename (tmp)) != 0)
      return TYPENAME;
    
    /* Input names that aren't symbols but ARE valid hex numbers,
       when the input radix permits them, can be names or numbers
       depending on the parse.  Note we support radixes > 16 here.  */
    if (!sym
	&& ((tokstart[0] >= 'a' && tokstart[0] < 'a' + input_radix - 10)
	    || (tokstart[0] >= 'A' && tokstart[0] < 'A' + input_radix - 10)))
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
#line 1302 "f-exp.c"

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
case 3:
#line 233 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode(OP_TYPE);
			  write_exp_elt_type(yystack.l_mark[0].tval);
			  write_exp_elt_opcode(OP_TYPE); }
break;
case 4:
#line 239 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ }
break;
case 5:
#line 244 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (UNOP_IND); }
break;
case 6:
#line 248 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (UNOP_ADDR); }
break;
case 7:
#line 252 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (UNOP_NEG); }
break;
case 8:
#line 256 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (UNOP_LOGICAL_NOT); }
break;
case 9:
#line 260 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (UNOP_COMPLEMENT); }
break;
case 10:
#line 264 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (UNOP_SIZEOF); }
break;
case 11:
#line 273 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ start_arglist (); }
break;
case 12:
#line 275 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (OP_F77_UNDETERMINED_ARGLIST);
			  write_exp_elt_longcst ((LONGEST) end_arglist ());
			  write_exp_elt_opcode (OP_F77_UNDETERMINED_ARGLIST); }
break;
case 14:
#line 284 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ arglist_len = 1; }
break;
case 15:
#line 288 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ arglist_len = 2;}
break;
case 16:
#line 292 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ arglist_len++; }
break;
case 17:
#line 296 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ }
break;
case 18:
#line 301 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ }
break;
case 19:
#line 305 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode(OP_COMPLEX); }
break;
case 20:
#line 309 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (UNOP_CAST);
			  write_exp_elt_type (yystack.l_mark[-2].tval);
			  write_exp_elt_opcode (UNOP_CAST); }
break;
case 21:
#line 317 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_REPEAT); }
break;
case 22:
#line 321 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_MUL); }
break;
case 23:
#line 325 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_DIV); }
break;
case 24:
#line 329 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_REM); }
break;
case 25:
#line 333 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_ADD); }
break;
case 26:
#line 337 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_SUB); }
break;
case 27:
#line 341 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_LSH); }
break;
case 28:
#line 345 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_RSH); }
break;
case 29:
#line 349 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_EQUAL); }
break;
case 30:
#line 353 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_NOTEQUAL); }
break;
case 31:
#line 357 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_LEQ); }
break;
case 32:
#line 361 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_GEQ); }
break;
case 33:
#line 365 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_LESS); }
break;
case 34:
#line 369 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_GTR); }
break;
case 35:
#line 373 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_BITWISE_AND); }
break;
case 36:
#line 377 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_BITWISE_XOR); }
break;
case 37:
#line 381 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_BITWISE_IOR); }
break;
case 38:
#line 385 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_LOGICAL_AND); }
break;
case 39:
#line 390 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_LOGICAL_OR); }
break;
case 40:
#line 394 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_ASSIGN); }
break;
case 41:
#line 398 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (BINOP_ASSIGN_MODIFY);
			  write_exp_elt_opcode (yystack.l_mark[-1].opcode);
			  write_exp_elt_opcode (BINOP_ASSIGN_MODIFY); }
break;
case 42:
#line 404 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_type (yystack.l_mark[0].typed_val.type);
			  write_exp_elt_longcst ((LONGEST)(yystack.l_mark[0].typed_val.val));
			  write_exp_elt_opcode (OP_LONG); }
break;
case 43:
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ YYSTYPE val;
			  parse_number (yystack.l_mark[0].ssym.stoken.ptr, yystack.l_mark[0].ssym.stoken.length, 0, &val);
			  write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_type (val.typed_val.type);
			  write_exp_elt_longcst ((LONGEST)val.typed_val.val);
			  write_exp_elt_opcode (OP_LONG); }
break;
case 44:
#line 420 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (OP_DOUBLE);
			  write_exp_elt_type (builtin_type_f_real_s8);
			  write_exp_elt_dblcst (yystack.l_mark[0].dval);
			  write_exp_elt_opcode (OP_DOUBLE); }
break;
case 47:
#line 433 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (OP_LONG);
			  write_exp_elt_type (builtin_type_f_integer);
			  CHECK_TYPEDEF (yystack.l_mark[-1].tval);
			  write_exp_elt_longcst ((LONGEST) TYPE_LENGTH (yystack.l_mark[-1].tval));
			  write_exp_elt_opcode (OP_LONG); }
break;
case 48:
#line 441 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ write_exp_elt_opcode (OP_BOOL);
			  write_exp_elt_longcst ((LONGEST) yystack.l_mark[0].lval);
			  write_exp_elt_opcode (OP_BOOL);
			}
break;
case 49:
#line 448 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{
			  write_exp_elt_opcode (OP_STRING);
			  write_exp_string (yystack.l_mark[0].sval);
			  write_exp_elt_opcode (OP_STRING);
			}
break;
case 50:
#line 456 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
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
			      break;
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
case 53:
#line 504 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{
		  /* This is where the interesting stuff happens.  */
		  int done = 0;
		  int array_size;
		  struct type *follow_type = yystack.l_mark[-1].tval;
		  struct type *range_type;
		  
		  while (!done)
		    switch (pop_type ())
		      {
		      case tp_end:
			done = 1;
			break;
		      case tp_pointer:
			follow_type = lookup_pointer_type (follow_type);
			break;
		      case tp_reference:
			follow_type = lookup_reference_type (follow_type);
			break;
		      case tp_array:
			array_size = pop_type_int ();
			if (array_size != -1)
			  {
			    range_type =
			      create_range_type ((struct type *) NULL,
						 builtin_type_f_integer, 0,
						 array_size - 1);
			    follow_type =
			      create_array_type ((struct type *) NULL,
						 follow_type, range_type);
			  }
			else
			  follow_type = lookup_pointer_type (follow_type);
			break;
		      case tp_function:
			follow_type = lookup_function_type (follow_type);
			break;
		      }
		  yyval.tval = follow_type;
		}
break;
case 54:
#line 547 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ push_type (tp_pointer); yyval.voidval = 0; }
break;
case 55:
#line 549 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ push_type (tp_pointer); yyval.voidval = yystack.l_mark[0].voidval; }
break;
case 56:
#line 551 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ push_type (tp_reference); yyval.voidval = 0; }
break;
case 57:
#line 553 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ push_type (tp_reference); yyval.voidval = yystack.l_mark[0].voidval; }
break;
case 59:
#line 558 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.voidval = yystack.l_mark[-1].voidval; }
break;
case 60:
#line 560 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ push_type (tp_function); }
break;
case 61:
#line 562 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ push_type (tp_function); }
break;
case 62:
#line 566 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.voidval = 0; }
break;
case 63:
#line 568 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ free (yystack.l_mark[-1].tvec); yyval.voidval = 0; }
break;
case 64:
#line 573 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = yystack.l_mark[0].tsym.type; }
break;
case 65:
#line 575 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = builtin_type_f_integer; }
break;
case 66:
#line 577 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = builtin_type_f_integer_s2; }
break;
case 67:
#line 579 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = builtin_type_f_character; }
break;
case 68:
#line 581 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = builtin_type_f_logical;}
break;
case 69:
#line 583 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = builtin_type_f_logical_s2;}
break;
case 70:
#line 585 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = builtin_type_f_logical_s1;}
break;
case 71:
#line 587 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = builtin_type_f_real;}
break;
case 72:
#line 589 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = builtin_type_f_real_s8;}
break;
case 73:
#line 591 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = builtin_type_f_real_s16;}
break;
case 74:
#line 593 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = builtin_type_f_complex_s8;}
break;
case 75:
#line 595 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = builtin_type_f_complex_s16;}
break;
case 76:
#line 597 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tval = builtin_type_f_complex_s32;}
break;
case 78:
#line 605 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.tvec = (struct type **) malloc (sizeof (struct type *) * 2);
		  yyval.ivec[0] = 1;	/* Number of types in vector */
		  yyval.tvec[1] = yystack.l_mark[0].tval;
		}
break;
case 79:
#line 610 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ int len = sizeof (struct type *) * (++(yystack.l_mark[-2].ivec[0]) + 1);
		  yyval.tvec = (struct type **) realloc ((char *) yystack.l_mark[-2].tvec, len);
		  yyval.tvec[yyval.ivec[0]] = yystack.l_mark[0].tval;
		}
break;
case 80:
#line 617 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.sval = yystack.l_mark[0].ssym.stoken; }
break;
case 81:
#line 619 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.sval = yystack.l_mark[0].tsym.stoken; }
break;
case 82:
#line 621 "/usr/home/freebsd/omega/src/gnu/usr.bin/gdb/libgdb/../../../../contrib/gdb/gdb/f-exp.y"
	{ yyval.sval = yystack.l_mark[0].ssym.stoken; }
break;
#line 1910 "f-exp.c"
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
