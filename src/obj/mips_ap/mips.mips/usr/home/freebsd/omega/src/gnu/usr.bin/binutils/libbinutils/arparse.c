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

#line 2 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
/* arparse.y - Stange script language parser */

/*   Copyright 1992, 1993, 1995, 1997, 1999, 2002, 2003, 2007
     Free Software Foundation, Inc.

This file is part of GNU Binutils.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */


/* Contributed by Steve Chamberlain
   		  sac@cygnus.com

*/
#define DONTDECLARE_MALLOC
#include "sysdep.h"
#include "bfd.h"
#include "arsup.h"
extern int verbose;
extern int yylex (void);
static int yyerror (const char *);
#line 37 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  char *name;
struct list *list ;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 68 "arparse.c"

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

#define NEWLINE 257
#define VERBOSE 258
#define FILENAME 259
#define ADDLIB 260
#define LIST 261
#define ADDMOD 262
#define CLEAR 263
#define CREATE 264
#define DELETE 265
#define DIRECTORY 266
#define END 267
#define EXTRACT 268
#define FULLDIR 269
#define HELP 270
#define QUIT 271
#define REPLACE 272
#define SAVE 273
#define OPEN 274
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    5,    0,    4,    4,    6,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,   16,   17,   13,   18,   14,   19,   15,    8,    9,
   12,   11,    3,    3,    1,    1,    2,    2,   20,   20,
   10,
};
static const YYINT yylen[] = {                            2,
    0,    2,    2,    0,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    0,    2,    2,    1,    2,    2,    1,    1,    2,    2,
    3,    4,    1,    0,    3,    0,    3,    0,    1,    0,
    1,
};
static const YYINT yydefred[] = {                         1,
    0,    4,    0,   19,   41,   20,    0,   27,   38,   24,
    0,   38,    0,   18,   38,   38,   28,    0,    3,    0,
    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
   16,   17,    0,    0,   30,    0,    0,    0,    0,   29,
    5,   38,   31,   39,    0,    0,    0,   37,   33,   32,
   35,
};
static const YYINT yydgoto[] = {                          1,
   43,   34,   50,    3,    2,   19,   20,   21,   22,   23,
   24,   25,   26,   27,   28,   29,   30,   31,   32,   45,
};
static const YYINT yysindex[] = {                         0,
    0,    0, -251,    0,    0,    0, -257,    0,    0,    0,
 -253,    0, -240,    0,    0,    0,    0, -234,    0, -221,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -3,   -6,    0,   -6,   -3,   -6,   -6,    0,
    0,    0,    0,    0, -220, -219,  -17,    0,    0,    0,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -216, -239,    0, -231, -228, -225, -224,    0,
    0,    0,    0,    0,    0, -215, -234,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
    6,  -12,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 258
static const YYINT yytable[] = {                         36,
    2,   33,   38,   39,    4,   35,    5,    6,    7,    8,
    9,   10,   11,   12,   13,   14,   15,   26,   37,   40,
   16,   17,   18,   51,   40,   25,   44,   40,   36,   47,
   36,   22,   23,   40,   40,   41,   42,   44,   48,   49,
   36,   34,   46,    0,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   21,
};
static const YYINT yycheck[] = {                         12,
    0,  259,   15,   16,  256,  259,  258,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  257,  259,  259,
  272,  273,  274,   41,  259,  257,   44,  259,  257,   42,
  259,  257,  257,  259,  259,  257,   40,   44,  259,  259,
  257,  257,   37,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 274
#define YYUNDFTOKEN 297
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NEWLINE","VERBOSE",
"FILENAME","ADDLIB","LIST","ADDMOD","CLEAR","CREATE","DELETE","DIRECTORY","END",
"EXTRACT","FULLDIR","HELP","QUIT","REPLACE","SAVE","OPEN",0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"$$1 :",
"start : $$1 session",
"session : session command_line",
"session :",
"command_line : command NEWLINE",
"command : open_command",
"command : create_command",
"command : verbose_command",
"command : directory_command",
"command : addlib_command",
"command : clear_command",
"command : addmod_command",
"command : save_command",
"command : extract_command",
"command : replace_command",
"command : delete_command",
"command : list_command",
"command : END",
"command : error",
"command : FILENAME",
"command :",
"extract_command : EXTRACT modulename",
"replace_command : REPLACE modulename",
"clear_command : CLEAR",
"delete_command : DELETE modulename",
"addmod_command : ADDMOD modulename",
"list_command : LIST",
"save_command : SAVE",
"open_command : OPEN FILENAME",
"create_command : CREATE FILENAME",
"addlib_command : ADDLIB FILENAME modulelist",
"directory_command : DIRECTORY FILENAME modulelist optional_filename",
"optional_filename : FILENAME",
"optional_filename :",
"modulelist : '(' modulename ')'",
"modulelist :",
"modulename : modulename optcomma FILENAME",
"modulename :",
"optcomma : ','",
"optcomma :",
"verbose_command : VERBOSE",

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
#line 195 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"

static int
yyerror (const char *x ATTRIBUTE_UNUSED)
{
  extern int linenumber;

  printf (_("Syntax error in archive script, line %d\n"), linenumber + 1);
  return 0;
}
#line 335 "arparse.c"

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
#line 68 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ prompt(); }
break;
case 5:
#line 77 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ prompt(); }
break;
case 18:
#line 93 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ ar_end(); return 0; }
break;
case 20:
#line 95 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ yyerror("foo"); }
break;
case 22:
#line 102 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ ar_extract(yystack.l_mark[0].list); }
break;
case 23:
#line 107 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ ar_replace(yystack.l_mark[0].list); }
break;
case 24:
#line 112 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ ar_clear(); }
break;
case 25:
#line 117 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ ar_delete(yystack.l_mark[0].list); }
break;
case 26:
#line 121 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ ar_addmod(yystack.l_mark[0].list); }
break;
case 27:
#line 126 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ ar_list(); }
break;
case 28:
#line 131 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ ar_save(); }
break;
case 29:
#line 138 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ ar_open(yystack.l_mark[0].name,0); }
break;
case 30:
#line 143 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ ar_open(yystack.l_mark[0].name,1); }
break;
case 31:
#line 149 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ ar_addlib(yystack.l_mark[-1].name,yystack.l_mark[0].list); }
break;
case 32:
#line 153 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ ar_directory(yystack.l_mark[-2].name, yystack.l_mark[-1].list, yystack.l_mark[0].name); }
break;
case 33:
#line 160 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ yyval.name = yystack.l_mark[0].name; }
break;
case 34:
#line 161 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ yyval.name = 0; }
break;
case 35:
#line 166 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ yyval.list = yystack.l_mark[-1].list; }
break;
case 36:
#line 168 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ yyval.list = 0; }
break;
case 37:
#line 173 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ 	struct list *n  = (struct list *) malloc(sizeof(struct list));
			n->next = yystack.l_mark[-2].list; 
			n->name = yystack.l_mark[0].name;
			yyval.list = n;
		 }
break;
case 38:
#line 178 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ yyval.list = 0; }
break;
case 41:
#line 190 "/usr/home/freebsd/omega/src/gnu/usr.bin/binutils/libbinutils/../../../../contrib/binutils/binutils/arparse.y"
	{ verbose = !verbose; }
break;
#line 629 "arparse.c"
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
