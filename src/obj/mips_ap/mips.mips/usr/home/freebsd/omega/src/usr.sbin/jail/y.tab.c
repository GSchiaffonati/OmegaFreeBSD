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

#line 2 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
/*-
 * Copyright (c) 2011 James Gritton
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
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <stdlib.h>
#include <string.h>

#include "jailp.h"

#ifdef DEBUG
#define YYDEBUG 1
#endif
#line 41 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct cfjail		*j;
	struct cfparams		*pp;
	struct cfparam		*p;
	struct cfstrings	*ss;
	struct cfstring		*s;
	char			*cs;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 75 "y.tab.c"

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

#define PLEQ 257
#define STR 258
#define STR1 259
#define VAR 260
#define VAR1 261
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    1,    2,    2,    2,    3,    3,
    3,    3,    3,    4,    4,    5,    5,    6,    6,    6,
    6,
};
static const YYINT yylen[] = {                            2,
    0,    2,    3,    2,    4,    0,    3,    2,    1,    3,
    3,    2,    1,    1,    1,    1,    3,    1,    1,    2,
    2,
};
static const YYINT yydefred[] = {                         1,
    0,   13,    0,   15,    4,    2,    0,    0,    6,    3,
    0,   18,   19,    0,    0,    0,    0,    0,    0,    0,
   20,   21,   14,    8,    5,    0,    0,    7,
};
static const YYINT yydgoto[] = {                          1,
    6,   17,    7,    8,   15,   16,
};
static const YYINT yysindex[] = {                         0,
  -52,    0, -120,    0,    0,    0,  -49,  -48,    0,    0,
 -249,    0,    0, -249,  -29, -247,  -59,  -29,  -29, -249,
    0,    0,    0,    0,    0,  -41, -247,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,  -55,    0,    0,    0,    0,  -40,    0,    0,
    0,    0,    0,    0,  -39,  -43,    0,  -38,  -49,    0,
    0,    0,    0,    0,    0,    0,  -42,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    5,    0,   -6,    3,
};
#define YYTABLESIZE 212
static const YYINT yytable[] = {                         24,
   16,   17,    9,   14,   18,   14,    5,   19,   12,   10,
   13,   21,   14,   22,   20,   16,   17,   28,    9,   12,
   11,   26,   27,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   25,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    2,    0,   23,    0,
    4,   14,   14,    2,   14,    3,    0,    4,   11,   12,
    0,   13,
};
static const YYINT yycheck[] = {                         59,
   44,   44,  123,   59,   11,   61,   59,   14,  258,   59,
  260,  259,   61,  261,   44,   59,   59,   59,   59,   59,
   59,   17,   20,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,  256,   -1,  258,   -1,
  260,  257,  258,  256,  260,  258,   -1,  260,  257,  258,
   -1,  260,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 261
#define YYUNDFTOKEN 270
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,"'='",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"PLEQ","STR",
"STR1","VAR","VAR1",0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : conf",
"conf :",
"conf : conf jail",
"conf : conf param ';'",
"conf : conf ';'",
"jail : STR '{' param_l '}'",
"param_l :",
"param_l : param_l param ';'",
"param_l : param_l ';'",
"param : name",
"param : name '=' value",
"param : name PLEQ value",
"param : name value",
"param : error",
"name : STR",
"name : VAR",
"value : string",
"value : value ',' string",
"string : STR",
"string : VAR",
"string : string STR1",
"string : string VAR1",

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
case 3:
#line 70 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		struct cfjail *j;

		j = TAILQ_LAST(&cfjails, cfjails);
		if (!j || strcmp(j->name, "*")) {
			j = add_jail();
			j->name = estrdup("*");
		}
		TAILQ_INSERT_TAIL(&j->params, yystack.l_mark[-1].p, tq);
	}
break;
case 5:
#line 83 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		yyval.j = add_jail();
		yyval.j->name = yystack.l_mark[-3].cs;
		TAILQ_CONCAT(&yyval.j->params, yystack.l_mark[-1].pp, tq);
		free(yystack.l_mark[-1].pp);
	}
break;
case 6:
#line 92 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		yyval.pp = emalloc(sizeof(struct cfparams));
		TAILQ_INIT(yyval.pp);
	}
break;
case 7:
#line 97 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		yyval.pp = yystack.l_mark[-2].pp;
		TAILQ_INSERT_TAIL(yyval.pp, yystack.l_mark[-1].p, tq);
	}
break;
case 9:
#line 109 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		yyval.p = yystack.l_mark[0].p;
	}
break;
case 10:
#line 113 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		yyval.p = yystack.l_mark[-2].p;
		TAILQ_CONCAT(&yyval.p->val, yystack.l_mark[0].ss, tq);
		free(yystack.l_mark[0].ss);
	}
break;
case 11:
#line 119 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		yyval.p = yystack.l_mark[-2].p;
		TAILQ_CONCAT(&yyval.p->val, yystack.l_mark[0].ss, tq);
		yyval.p->flags |= PF_APPEND;
		free(yystack.l_mark[0].ss);
	}
break;
case 12:
#line 126 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		yyval.p = yystack.l_mark[-1].p;
		TAILQ_CONCAT(&yyval.p->val, yystack.l_mark[0].ss, tq);
		free(yystack.l_mark[0].ss);
	}
break;
case 13:
#line 132 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
	}
break;
case 14:
#line 141 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		yyval.p = emalloc(sizeof(struct cfparam));
		yyval.p->name = yystack.l_mark[0].cs;
		TAILQ_INIT(&yyval.p->val);
		yyval.p->flags = 0;
	}
break;
case 15:
#line 148 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		yyval.p = emalloc(sizeof(struct cfparam));
		yyval.p->name = yystack.l_mark[0].cs;
		TAILQ_INIT(&yyval.p->val);
		yyval.p->flags = PF_VAR;
	}
break;
case 16:
#line 157 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		yyval.ss = emalloc(sizeof(struct cfstrings));
		TAILQ_INIT(yyval.ss);
		TAILQ_INSERT_TAIL(yyval.ss, yystack.l_mark[0].s, tq);
	}
break;
case 17:
#line 163 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		yyval.ss = yystack.l_mark[-2].ss;
		TAILQ_INSERT_TAIL(yyval.ss, yystack.l_mark[0].s, tq);
	}
break;
case 18:
#line 174 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		yyval.s = emalloc(sizeof(struct cfstring));
		yyval.s->s = yystack.l_mark[0].cs;
		yyval.s->len = strlen(yystack.l_mark[0].cs);
		STAILQ_INIT(&yyval.s->vars);
	}
break;
case 19:
#line 181 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		struct cfvar *v;

		yyval.s = emalloc(sizeof(struct cfstring));
		yyval.s->s = estrdup("");
		yyval.s->len = 0;
		STAILQ_INIT(&yyval.s->vars);
		v = emalloc(sizeof(struct cfvar));
		v->name = yystack.l_mark[0].cs;
		v->pos = 0;
		STAILQ_INSERT_TAIL(&yyval.s->vars, v, tq);
	}
break;
case 20:
#line 194 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		size_t len1;

		yyval.s = yystack.l_mark[-1].s;
		len1 = strlen(yystack.l_mark[0].cs);
		yyval.s->s = erealloc(yyval.s->s, yyval.s->len + len1 + 1);
		strcpy(yyval.s->s + yyval.s->len, yystack.l_mark[0].cs);
		free(yystack.l_mark[0].cs);
		yyval.s->len += len1;
	}
break;
case 21:
#line 205 "/usr/home/freebsd/omega/src/usr.sbin/jail/jailparse.y"
	{
		struct cfvar *v;

		yyval.s = yystack.l_mark[-1].s;
		v = emalloc(sizeof(struct cfvar));
		v->name = yystack.l_mark[0].cs;
		v->pos = yyval.s->len;
		STAILQ_INSERT_TAIL(&yyval.s->vars, v, tq);
	}
break;
#line 629 "y.tab.c"
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
