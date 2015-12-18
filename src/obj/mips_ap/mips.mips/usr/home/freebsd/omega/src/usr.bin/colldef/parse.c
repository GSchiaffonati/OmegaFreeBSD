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

#line 2 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
/*-
 * Copyright (c) 1995 Alex Tatmanjants <alex@elvisti.kiev.ua>
 *		at Electronni Visti IA, Kiev, Ukraine.
 *			All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/types.h>
#include <arpa/inet.h>
#include <err.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sysexits.h>
#include "common.h"

extern FILE *yyin;
void yyerror(const char *fmt, ...) __printflike(1, 2);
int yyparse(void);
int yylex(void);
static void usage(void);
static void collate_print_tables(void);

#undef STR_LEN
#define STR_LEN 10
#undef TABLE_SIZE
#define TABLE_SIZE 100
#undef COLLATE_VERSION
#define COLLATE_VERSION    "1.0\n"
#undef COLLATE_VERSION_2
#define COLLATE_VERSION1_2 "1.2\n"

struct __collate_st_char_pri {
	int prim, sec;
};

struct __collate_st_chain_pri {
	u_char str[STR_LEN];
	int prim, sec;
};

char map_name[FILENAME_MAX] = ".";
char curr_chain[STR_LEN];

char __collate_version[STR_LEN];
u_char charmap_table[UCHAR_MAX + 1][CHARMAP_SYMBOL_LEN];

#undef __collate_substitute_table
u_char __collate_substitute_table[UCHAR_MAX + 1][STR_LEN];
#undef __collate_char_pri_table
struct __collate_st_char_pri __collate_char_pri_table[UCHAR_MAX + 1];
struct __collate_st_chain_pri *__collate_chain_pri_table;

int chain_index = 0;
int prim_pri = 1, sec_pri = 1;
#ifdef COLLATE_DEBUG
int debug;
#endif

const char *out_file = "LC_COLLATE";
#line 89 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	u_char ch;
	u_char str[BUFSIZE];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 120 "y.tab.c"

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

#define SUBSTITUTE 257
#define WITH 258
#define ORDER 259
#define RANGE 260
#define STRING 261
#define DEFN 262
#define CHAR 263
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    2,    2,    3,    4,    5,
    6,    6,    8,    8,    7,    7,    7,    7,    7,    9,
    9,   10,   10,   11,   11,   11,   12,   12,   12,
};
static const YYINT yylen[] = {                            2,
    1,    1,    3,    0,    1,    1,    1,    2,    4,    2,
    1,    3,    2,    2,    1,    1,    3,    3,    3,    1,
    3,    1,    3,    1,    3,    1,    1,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    2,    5,    6,    7,    0,
    0,    0,    0,    0,   11,    0,    8,    0,    0,    0,
   13,    0,    0,    0,   20,    0,    0,    0,   22,    0,
   14,    3,    9,   17,    0,   18,    0,    0,   19,    0,
   12,   25,   21,   28,   23,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,    9,   14,   15,   16,   24,   28,
   25,   29,
};
static const YYINT yysindex[] = {                      -246,
 -253,  -40, -248,    0,   18,    0,    0,    0,    0, -225,
 -243, -228, -227,  -22,    0, -224,    0, -246, -223, -222,
    0, -239, -224,  -43,    0, -238, -224,  -18,    0,  -40,
    0,    0,    0,    0, -221,    0, -228, -220,    0, -227,
    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         8,
    0,    0,    0,    0,   40,    0,    0,    0,    0,    0,
    2,    0,    0,    9,    0,    4,    0,    8,    0,    0,
    0,  -41,  -39,    0,    0,  -14,  -12,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,   26,    0,    0,    0,    0,   15,   -6,    0,    0,
   10,    6,
};
#define YYTABLESIZE 223
static const YYINT yytable[] = {                         13,
   37,   15,   24,   16,   26,   23,   27,    4,   10,   10,
    1,   15,    2,   16,   17,    3,   20,    4,   10,   21,
   35,   38,   39,   21,   21,   40,   27,   18,   29,   27,
   23,   29,   19,   27,   22,   26,   30,   33,   31,    1,
   34,   42,   44,   32,   41,   45,   43,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   15,    0,   16,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   36,   12,   24,    0,   26,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   11,
};
static const YYINT yycheck[] = {                         40,
   44,    0,   44,    0,   44,   12,   13,    0,    0,  263,
  257,   10,  259,   10,  263,  262,  260,   10,   10,  263,
  260,  260,   41,  263,  263,   44,   41,   10,   41,   44,
   37,   44,  258,   40,  263,  263,   59,  261,  263,    0,
  263,  263,  263,   18,   30,   40,   37,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  125,  123,  125,   -1,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  263,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 263
#define YYUNDFTOKEN 278
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"SUBSTITUTE","WITH","ORDER","RANGE","STRING","DEFN","CHAR",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : collate",
"collate : statment_list",
"statment_list : statment",
"statment_list : statment_list '\\n' statment",
"statment :",
"statment : charmap",
"statment : substitute",
"statment : order",
"charmap : DEFN CHAR",
"substitute : SUBSTITUTE CHAR WITH STRING",
"order : ORDER order_list",
"order_list : item",
"order_list : order_list ';' item",
"chain : CHAR CHAR",
"chain : chain CHAR",
"item : CHAR",
"item : chain",
"item : CHAR RANGE CHAR",
"item : '{' prim_order_list '}'",
"item : '(' sec_order_list ')'",
"prim_order_list : prim_sub_item",
"prim_order_list : prim_order_list ',' prim_sub_item",
"sec_order_list : sec_sub_item",
"sec_order_list : sec_order_list ',' sec_sub_item",
"prim_sub_item : CHAR",
"prim_sub_item : CHAR RANGE CHAR",
"prim_sub_item : chain",
"sec_sub_item : CHAR",
"sec_sub_item : CHAR RANGE CHAR",
"sec_sub_item : chain",

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
#line 321 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
int
main(int ac, char **av)
{
	int ch;

#ifdef COLLATE_DEBUG
	while((ch = getopt(ac, av, ":do:I:")) != -1) {
#else
	while((ch = getopt(ac, av, ":o:I:")) != -1) {
#endif
		switch (ch)
		{
#ifdef COLLATE_DEBUG
		  case 'd':
			debug++;
			break;
#endif
		  case 'o':
			out_file = optarg;
			break;

		  case 'I':
			strlcpy(map_name, optarg, sizeof(map_name));
			break;

		  default:
			usage();
		}
	}
	ac -= optind;
	av += optind;
	if (ac > 0) {
		if ((yyin = fopen(*av, "r")) == NULL)
			err(EX_UNAVAILABLE, "can't open source file %s", *av);
	}
	for (ch = 0; ch <= UCHAR_MAX; ch++)
		__collate_substitute_table[ch][0] = ch;
	yyparse();
	return 0;
}

static void
usage(void)
{
	fprintf(stderr, "usage: colldef [-I map_dir] [-o out_file] [filename]\n");
	exit(EX_USAGE);
}

void
yyerror(const char *fmt, ...)
{
	va_list ap;
	char msg[128];

	va_start(ap, fmt);
	vsnprintf(msg, sizeof(msg), fmt, ap);
	va_end(ap);
	errx(EX_UNAVAILABLE, "%s near line %d", msg, line_no);
}

#ifdef COLLATE_DEBUG
static void
collate_print_tables(void)
{
	int i;

	printf("Substitute table:\n");
	for (i = 0; i < UCHAR_MAX + 1; i++)
	    if (i != *__collate_substitute_table[i])
		printf("\t'%c' --> \"%s\"\n", i,
		       __collate_substitute_table[i]);
	printf("Chain priority table:\n");
	for (i = 0; i < chain_index - 1; i++)
		printf("\t\"%s\" : %d %d\n",
		    __collate_chain_pri_table[i].str,
		    __collate_chain_pri_table[i].prim,
		    __collate_chain_pri_table[i].sec);
	printf("Char priority table:\n");
	for (i = 0; i < UCHAR_MAX + 1; i++)
		printf("\t'%c' : %d %d\n", i, __collate_char_pri_table[i].prim,
		       __collate_char_pri_table[i].sec);
}
#endif
#line 424 "y.tab.c"

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
case 8:
#line 108 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	if (strlen(yystack.l_mark[-1].str) + 1 > CHARMAP_SYMBOL_LEN)
		yyerror("Charmap symbol name '%s' is too long", yystack.l_mark[-1].str);
	strcpy(charmap_table[yystack.l_mark[0].ch], yystack.l_mark[-1].str);
}
break;
case 9:
#line 114 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	if (yystack.l_mark[-2].ch == '\0')
		yyerror("NUL character can't be substituted");
	if (strchr(yystack.l_mark[0].str, yystack.l_mark[-2].ch) != NULL)
		yyerror("Char 0x%02x substitution is recursive", yystack.l_mark[-2].ch);
	if (strlen(yystack.l_mark[0].str) + 1 > STR_LEN)
		yyerror("Char 0x%02x substitution is too long", yystack.l_mark[-2].ch);
	strcpy(__collate_substitute_table[yystack.l_mark[-2].ch], yystack.l_mark[0].str);
}
break;
case 10:
#line 124 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	FILE *fp;
	int ch, substed, ordered;
	uint32_t u32;

	for (ch = 0; ch < UCHAR_MAX + 1; ch++) {
		substed = (__collate_substitute_table[ch][0] != ch);
		ordered = !!__collate_char_pri_table[ch].prim;
		if (!ordered && !substed)
			yyerror("Char 0x%02x not found", ch);
		if (substed && ordered)
			yyerror("Char 0x%02x can't be ordered since substituted", ch);
	}

	if ((__collate_chain_pri_table = realloc(__collate_chain_pri_table,
	     sizeof(*__collate_chain_pri_table) * (chain_index + 1))) == NULL)
		yyerror("can't grow chain table");
	(void)memset(&__collate_chain_pri_table[chain_index], 0,
		     sizeof(__collate_chain_pri_table[0]));
	chain_index++;

#ifdef COLLATE_DEBUG
	if (debug)
		collate_print_tables();
#endif
	if ((fp = fopen(out_file, "w")) == NULL)
		err(EX_UNAVAILABLE, "can't open destination file %s",
		    out_file);

	strcpy(__collate_version, COLLATE_VERSION1_2);
	if (fwrite(__collate_version, sizeof(__collate_version), 1, fp) != 1)
		err(EX_IOERR,
		"I/O error writing collate version to destination file %s",
		    out_file);
	u32 = htonl(chain_index);
	if (fwrite(&u32, sizeof(u32), 1, fp) != 1)
		err(EX_IOERR,
		"I/O error writing chains number to destination file %s",
		    out_file);
	if (fwrite(__collate_substitute_table,
		   sizeof(__collate_substitute_table), 1, fp) != 1)
		err(EX_IOERR,
		"I/O error writing substitution table to destination file %s",
		    out_file);
	for (ch = 0; ch < UCHAR_MAX + 1; ch++) {
		__collate_char_pri_table[ch].prim =
		    htonl(__collate_char_pri_table[ch].prim);
		__collate_char_pri_table[ch].sec =
		    htonl(__collate_char_pri_table[ch].sec);
	}
	if (fwrite(__collate_char_pri_table,
		   sizeof(__collate_char_pri_table), 1, fp) != 1)
		err(EX_IOERR,
		"I/O error writing char table to destination file %s",
		    out_file);
	for (ch = 0; ch < chain_index; ch++) {
		__collate_chain_pri_table[ch].prim =
		    htonl(__collate_chain_pri_table[ch].prim);
		__collate_chain_pri_table[ch].sec =
		    htonl(__collate_chain_pri_table[ch].sec);
	}
	if (fwrite(__collate_chain_pri_table,
		   sizeof(*__collate_chain_pri_table), chain_index, fp) !=
		   (size_t)chain_index)
		err(EX_IOERR,
		"I/O error writing chain table to destination file %s",
		    out_file);
	if (fclose(fp) != 0)
		err(EX_IOERR, "I/O error closing destination file %s",
		    out_file);
	exit(EX_OK);
}
break;
case 13:
#line 200 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	curr_chain[0] = yystack.l_mark[-1].ch;
	curr_chain[1] = yystack.l_mark[0].ch;
	if (curr_chain[0] == '\0' || curr_chain[1] == '\0')
		yyerror("\\0 can't be chained");
	curr_chain[2] = '\0';
}
break;
case 14:
#line 207 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	static char tb[2];

	tb[0] = yystack.l_mark[0].ch;
	if (tb[0] == '\0')
		yyerror("\\0 can't be chained");
	if (strlen(curr_chain) + 2 > STR_LEN)
		yyerror("Chain '%s' grows too long", curr_chain);
	(void)strcat(curr_chain, tb);
}
break;
case 15:
#line 218 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	if (__collate_char_pri_table[yystack.l_mark[0].ch].prim)
		yyerror("Char 0x%02x duplicated", yystack.l_mark[0].ch);
	__collate_char_pri_table[yystack.l_mark[0].ch].prim = prim_pri++;
}
break;
case 16:
#line 223 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	if ((__collate_chain_pri_table = realloc(__collate_chain_pri_table,
	     sizeof(*__collate_chain_pri_table) * (chain_index + 1))) == NULL)
		yyerror("can't grow chain table");
	(void)memset(&__collate_chain_pri_table[chain_index], 0,
		     sizeof(__collate_chain_pri_table[0]));
	(void)strcpy(__collate_chain_pri_table[chain_index].str, curr_chain);
	__collate_chain_pri_table[chain_index].prim = prim_pri++;
	chain_index++;
}
break;
case 17:
#line 233 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	u_int i;

	if (yystack.l_mark[0].ch <= yystack.l_mark[-2].ch)
		yyerror("Illegal range 0x%02x -- 0x%02x", yystack.l_mark[-2].ch, yystack.l_mark[0].ch);

	for (i = yystack.l_mark[-2].ch; i <= yystack.l_mark[0].ch; i++) {
		if (__collate_char_pri_table[(u_char)i].prim)
			yyerror("Char 0x%02x duplicated", (u_char)i);
		__collate_char_pri_table[(u_char)i].prim = prim_pri++;
	}
}
break;
case 18:
#line 245 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	prim_pri++;
}
break;
case 19:
#line 248 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	prim_pri++;
	sec_pri = 1;
}
break;
case 24:
#line 259 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	if (__collate_char_pri_table[yystack.l_mark[0].ch].prim)
		yyerror("Char 0x%02x duplicated", yystack.l_mark[0].ch);
	__collate_char_pri_table[yystack.l_mark[0].ch].prim = prim_pri;
}
break;
case 25:
#line 264 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	u_int i;

	if (yystack.l_mark[0].ch <= yystack.l_mark[-2].ch)
		yyerror("Illegal range 0x%02x -- 0x%02x",
			yystack.l_mark[-2].ch, yystack.l_mark[0].ch);

	for (i = yystack.l_mark[-2].ch; i <= yystack.l_mark[0].ch; i++) {
		if (__collate_char_pri_table[(u_char)i].prim)
			yyerror("Char 0x%02x duplicated", (u_char)i);
		__collate_char_pri_table[(u_char)i].prim = prim_pri;
	}
}
break;
case 26:
#line 277 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	if ((__collate_chain_pri_table = realloc(__collate_chain_pri_table,
	     sizeof(*__collate_chain_pri_table) * (chain_index + 1))) == NULL)
		yyerror("can't grow chain table");
	(void)memset(&__collate_chain_pri_table[chain_index], 0,
		     sizeof(__collate_chain_pri_table[0]));
	(void)strcpy(__collate_chain_pri_table[chain_index].str, curr_chain);
	__collate_chain_pri_table[chain_index].prim = prim_pri;
	chain_index++;
}
break;
case 27:
#line 288 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	if (__collate_char_pri_table[yystack.l_mark[0].ch].prim)
		yyerror("Char 0x%02x duplicated", yystack.l_mark[0].ch);
	__collate_char_pri_table[yystack.l_mark[0].ch].prim = prim_pri;
	__collate_char_pri_table[yystack.l_mark[0].ch].sec = sec_pri++;
}
break;
case 28:
#line 294 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	u_int i;

	if (yystack.l_mark[0].ch <= yystack.l_mark[-2].ch)
		yyerror("Illegal range 0x%02x -- 0x%02x",
			yystack.l_mark[-2].ch, yystack.l_mark[0].ch);

	for (i = yystack.l_mark[-2].ch; i <= yystack.l_mark[0].ch; i++) {
		if (__collate_char_pri_table[(u_char)i].prim)
			yyerror("Char 0x%02x duplicated", (u_char)i);
		__collate_char_pri_table[(u_char)i].prim = prim_pri;
		__collate_char_pri_table[(u_char)i].sec = sec_pri++;
	}
}
break;
case 29:
#line 308 "/usr/home/freebsd/omega/src/usr.bin/colldef/parse.y"
	{
	if ((__collate_chain_pri_table = realloc(__collate_chain_pri_table,
	     sizeof(*__collate_chain_pri_table) * (chain_index + 1))) == NULL)
		yyerror("can't grow chain table");
	(void)memset(&__collate_chain_pri_table[chain_index], 0,
		     sizeof(__collate_chain_pri_table[0]));
	(void)strcpy(__collate_chain_pri_table[chain_index].str, curr_chain);
	__collate_chain_pri_table[chain_index].prim = prim_pri;
	__collate_chain_pri_table[chain_index].sec = sec_pri++;
	chain_index++;
}
break;
#line 870 "y.tab.c"
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
