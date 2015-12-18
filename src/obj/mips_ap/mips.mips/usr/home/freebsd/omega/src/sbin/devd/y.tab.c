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

#line 2 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
/*-
 * DEVD (Device action daemon)
 *
 * Copyright (c) 2002 M. Warner Losh <imp@freebsd.org>.
 * All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#include <sys/cdefs.h>
#include "devd.h"
#include <stdio.h>
#include <string.h>

#line 39 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char *str;
	int i;
	struct eps *eps;	/* EventProcStatement */
	struct event_proc *eventproc;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 71 "y.tab.c"

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

#define SEMICOLON 257
#define BEGINBLOCK 258
#define ENDBLOCK 259
#define COMMA 260
#define NUMBER 261
#define STRING 262
#define ID 263
#define OPTIONS 264
#define SET 265
#define DIRECTORY 266
#define PID_FILE 267
#define DEVICE_NAME 268
#define ACTION 269
#define MATCH 270
#define ATTACH 271
#define DETACH 272
#define NOMATCH 273
#define NOTIFY 274
#define MEDIA_TYPE 275
#define CLASS 276
#define SUBDEVICE 277
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    5,    5,    6,    6,    6,    6,    6,    7,
   12,   12,   13,   13,   13,   14,   15,   16,    8,    8,
    9,    9,   10,   10,   11,   11,    1,    1,    2,    2,
    3,    3,    3,    3,    3,    4,
};
static const YYINT yylen[] = {                            2,
    1,    0,    1,    2,    1,    1,    1,    1,    1,    5,
    1,    2,    1,    1,    1,    3,    3,    4,    6,    5,
    6,    5,    6,    5,    6,    5,    1,    2,    1,    1,
    4,    3,    3,    3,    3,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    3,    5,    6,
    7,    8,    9,    0,    0,    0,    0,    0,    4,    0,
    0,    0,    0,   11,   13,   14,   15,    0,    0,    0,
    0,    0,    0,    0,    0,   12,    0,    0,    0,    0,
    0,    0,    0,    0,   27,   29,   30,    0,    0,    0,
    0,    0,    0,    0,   16,   17,   10,   20,    0,    0,
    0,    0,    0,    0,    0,   28,   22,    0,   24,    0,
   26,    0,   18,   32,   36,    0,   33,   34,   35,   19,
   21,   23,   25,   31,
};
static const YYINT yydgoto[] = {                          6,
   44,   45,   46,   47,    7,    8,    9,   10,   11,   12,
   13,   23,   24,   25,   26,   27,
};
static const YYINT yysindex[] = {                      -195,
 -257, -254, -253, -239, -238,    0, -195,    0,    0,    0,
    0,    0,    0, -261, -230, -224, -223, -209,    0, -234,
 -260, -212, -175,    0,    0,    0,    0, -259, -256, -244,
 -232, -207, -201, -196, -171,    0, -169, -200, -168, -167,
 -166, -165, -164, -229,    0,    0,    0, -158, -217, -157,
 -205, -156, -202, -155,    0,    0,    0,    0, -154, -153,
 -152, -151, -150, -149, -148,    0,    0, -146,    0, -145,
    0, -144,    0,    0,    0, -143,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                        93,
    0,    0,    0,    0,    0,    0,  105,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   52,   36,    0,    0,    0,  108,    0,    0,    0,    0,
    0,    0,   94,    0,    0,    0,
};
#define YYTABLESIZE 117
static const YYINT yytable[] = {                         37,
   14,   33,   48,   20,   21,   22,   15,   16,   38,   39,
   40,   38,   39,   40,   50,   41,   42,   43,   41,   42,
   43,   17,   18,   38,   39,   40,   52,   28,   32,   65,
   41,   42,   43,   29,   30,   38,   39,   40,   38,   39,
   40,   68,   41,   42,   43,   41,   42,   43,   31,   34,
   38,   39,   40,   70,   54,   55,   72,   41,   42,   43,
   56,   59,   38,   39,   40,   38,   39,   40,    1,   41,
   42,   43,   41,   42,   43,    2,    3,    4,    5,   66,
   49,   51,   53,   35,   66,   57,   66,   58,   66,   20,
   21,   22,    2,   60,   61,   62,   63,   64,   67,   69,
   71,   73,   74,   75,    1,   77,   78,   79,   80,   76,
   81,   82,   83,   84,   19,    0,   36,
};
static const YYINT yycheck[] = {                        259,
  258,  262,  259,  265,  266,  267,  261,  261,  268,  269,
  270,  268,  269,  270,  259,  275,  276,  277,  275,  276,
  277,  261,  261,  268,  269,  270,  259,  258,  263,  259,
  275,  276,  277,  258,  258,  268,  269,  270,  268,  269,
  270,  259,  275,  276,  277,  275,  276,  277,  258,  262,
  268,  269,  270,  259,  262,  257,  259,  275,  276,  277,
  257,  262,  268,  269,  270,  268,  269,  270,  264,  275,
  276,  277,  275,  276,  277,  271,  272,  273,  274,   44,
   29,   30,   31,  259,   49,  257,   51,  257,   53,  265,
  266,  267,    0,  262,  262,  262,  262,  262,  257,  257,
  257,  257,  257,  257,    0,  257,  257,  257,  257,  262,
  257,  257,  257,  257,    7,   -1,   23,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 277
#define YYUNDFTOKEN 296
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SEMICOLON","BEGINBLOCK",
"ENDBLOCK","COMMA","NUMBER","STRING","ID","OPTIONS","SET","DIRECTORY",
"PID_FILE","DEVICE_NAME","ACTION","MATCH","ATTACH","DETACH","NOMATCH","NOTIFY",
"MEDIA_TYPE","CLASS","SUBDEVICE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : config_file",
"config_file : config_list",
"config_file :",
"config_list : config",
"config_list : config_list config",
"config : option_block",
"config : attach_block",
"config : detach_block",
"config : nomatch_block",
"config : notify_block",
"option_block : OPTIONS BEGINBLOCK options ENDBLOCK SEMICOLON",
"options : option",
"options : options option",
"option : directory_option",
"option : pid_file_option",
"option : set_option",
"directory_option : DIRECTORY STRING SEMICOLON",
"pid_file_option : PID_FILE STRING SEMICOLON",
"set_option : SET ID STRING SEMICOLON",
"attach_block : ATTACH NUMBER BEGINBLOCK match_or_action_list ENDBLOCK SEMICOLON",
"attach_block : ATTACH NUMBER BEGINBLOCK ENDBLOCK SEMICOLON",
"detach_block : DETACH NUMBER BEGINBLOCK match_or_action_list ENDBLOCK SEMICOLON",
"detach_block : DETACH NUMBER BEGINBLOCK ENDBLOCK SEMICOLON",
"nomatch_block : NOMATCH NUMBER BEGINBLOCK match_or_action_list ENDBLOCK SEMICOLON",
"nomatch_block : NOMATCH NUMBER BEGINBLOCK ENDBLOCK SEMICOLON",
"notify_block : NOTIFY NUMBER BEGINBLOCK match_or_action_list ENDBLOCK SEMICOLON",
"notify_block : NOTIFY NUMBER BEGINBLOCK ENDBLOCK SEMICOLON",
"match_or_action_list : match_or_action",
"match_or_action_list : match_or_action_list match_or_action",
"match_or_action : match",
"match_or_action : action",
"match : MATCH STRING STRING SEMICOLON",
"match : DEVICE_NAME STRING SEMICOLON",
"match : MEDIA_TYPE STRING SEMICOLON",
"match : CLASS STRING SEMICOLON",
"match : SUBDEVICE STRING SEMICOLON",
"action : ACTION STRING SEMICOLON",

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
case 16:
#line 91 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ add_directory(yystack.l_mark[-1].str); }
break;
case 17:
#line 95 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ set_pidfile(yystack.l_mark[-1].str); }
break;
case 18:
#line 99 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ set_variable(yystack.l_mark[-2].str, yystack.l_mark[-1].str); }
break;
case 19:
#line 104 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ add_attach(yystack.l_mark[-4].i, yystack.l_mark[-2].eventproc); }
break;
case 21:
#line 110 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ add_detach(yystack.l_mark[-4].i, yystack.l_mark[-2].eventproc); }
break;
case 23:
#line 116 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ add_nomatch(yystack.l_mark[-4].i, yystack.l_mark[-2].eventproc); }
break;
case 25:
#line 122 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ add_notify(yystack.l_mark[-4].i, yystack.l_mark[-2].eventproc); }
break;
case 27:
#line 127 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ yyval.eventproc = add_to_event_proc( NULL, yystack.l_mark[0].eps); }
break;
case 28:
#line 129 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ yyval.eventproc = add_to_event_proc(yystack.l_mark[-1].eventproc, yystack.l_mark[0].eps); }
break;
case 31:
#line 138 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ yyval.eps = new_match(yystack.l_mark[-2].str, yystack.l_mark[-1].str); }
break;
case 32:
#line 140 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ yyval.eps = new_match(strdup("device-name"), yystack.l_mark[-1].str); }
break;
case 33:
#line 142 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ yyval.eps = new_media(strdup("media-type"), yystack.l_mark[-1].str); }
break;
case 34:
#line 144 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ yyval.eps = new_match(strdup("class"), yystack.l_mark[-1].str); }
break;
case 35:
#line 146 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ yyval.eps = new_match(strdup("subdevice"), yystack.l_mark[-1].str); }
break;
case 36:
#line 150 "/usr/home/freebsd/omega/src/sbin/devd/parse.y"
	{ yyval.eps = new_action(yystack.l_mark[-1].str); }
break;
#line 567 "y.tab.c"
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
