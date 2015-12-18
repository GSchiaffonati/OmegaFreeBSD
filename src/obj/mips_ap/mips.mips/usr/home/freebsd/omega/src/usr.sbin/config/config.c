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

#line 1 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char	*str;
	int	val;
	struct	file_list *file;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 38 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"

/*
 * Copyright (c) 1988, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)config.y	8.1 (Berkeley) 6/6/93
 * $FreeBSD$
 */

#include <assert.h>
#include <ctype.h>
#include <err.h>
#include <stdio.h>
#include <string.h>

#include "config.h"

struct	device_head dtab;
char	*ident;
char	*env;
int	envmode;
int	hintmode;
int	yyline;
const	char *yyfile;
struct  file_list_head ftab;
struct  files_name_head fntab;
char	errbuf[80];
int	maxusers;

#define ns(s)	strdup(s)
int include(const char *, int);
void yyerror(const char *s);
int yywrap(void);

static void newdev(char *name);
static void newfile(char *name);
static void rmdev_schedule(struct device_head *dh, char *name);
static void newopt(struct opt_head *list, char *name, char *value, int append);
static void rmopt_schedule(struct opt_head *list, char *name);

static char *
devopt(char *dev)
{
	char *ret = malloc(strlen(dev) + 5);
	
	sprintf(ret, "DEV_%s", dev);
	raisestr(ret);
	return ret;
}

#line 109 "y.tab.c"

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

#define ARCH 257
#define COMMA 258
#define CONFIG 259
#define CPU 260
#define NOCPU 261
#define DEVICE 262
#define NODEVICE 263
#define ENV 264
#define EQUALS 265
#define PLUSEQUALS 266
#define HINTS 267
#define IDENT 268
#define MAXUSERS 269
#define PROFILE 270
#define OPTIONS 271
#define NOOPTION 272
#define MAKEOPTIONS 273
#define NOMAKEOPTION 274
#define SEMICOLON 275
#define INCLUDE 276
#define FILES 277
#define ID 278
#define NUMBER 279
#define PATH 280
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    4,    4,    5,    5,    5,    5,    5,    5,    5,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,   11,   11,   12,   13,   13,    8,
    8,    9,    9,   14,   14,   15,    2,    2,    1,   10,
   10,   16,   16,   16,   16,    3,    6,    6,   17,   17,
   18,   18,   19,   20,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    2,    2,    3,    3,    3,    1,    2,
    2,    3,    2,    2,    2,    2,    2,    2,    2,    1,
    2,    2,    2,    2,    3,    2,    1,    2,    1,    3,
    1,    3,    1,    1,    3,    1,    1,    1,    1,    3,
    1,    1,    2,    3,    3,    1,    2,    2,    3,    1,
    3,    1,    1,    1,
};
static const YYINT yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    9,    0,
    0,    2,    0,    0,   20,   10,   39,    0,   27,    0,
   13,   14,   46,   53,    0,   50,   54,    0,   52,   23,
   24,   19,   21,   22,    0,    0,   31,   36,    0,   33,
    0,    0,   41,   18,    0,    0,    0,    4,    5,   12,
   29,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    7,    6,    8,   28,   49,   51,   37,   38,   35,   30,
   32,   44,   45,   40,
};
static const YYINT yydgoto[] = {                          1,
   45,   79,   34,    2,   22,   23,   24,   46,   49,   52,
   25,   30,   62,   47,   50,   53,   35,   38,   36,   39,
};
static const YYINT yysindex[] = {                         0,
    0, -241, -269, -267, -267, -267, -267, -261, -261, -235,
 -234, -233, -232, -231, -267, -267, -267, -267,    0, -273,
 -229,    0, -225, -224,    0,    0,    0, -267,    0, -226,
    0,    0,    0,    0, -212,    0,    0, -205,    0,    0,
    0,    0,    0,    0, -209, -201,    0,    0, -200,    0,
 -256, -198,    0,    0, -214, -213, -211,    0,    0,    0,
    0, -210, -261, -261, -239, -267, -267, -239, -239, -267,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,   65,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -208,    0, -269,
    0,    0,    0,    0, -206,    0,    0, -204,    0,    0,
    0,    0,    0,    0, -250, -203,    0,    0, -202,    0,
 -221, -199,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -197,    0,    0,    0,    0,    0, -220,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   -4,  -27,   -5,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    4,    7,    5,    0,    0,   14,   15,
};
#define YYTABLESIZE 79
static const YYINT yytable[] = {                         28,
   29,   31,   32,   37,   55,   26,   56,   34,   68,   69,
   27,   48,   51,   54,    3,    4,   33,    5,    6,    7,
    8,    9,   10,   60,   34,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   42,   43,   77,   78,
   82,   83,   40,   41,   42,   63,   43,   44,   57,   58,
   59,   61,   64,   42,   43,   65,   66,   67,   37,   70,
   71,   72,   48,   73,    1,   51,   11,   74,   47,   80,
   48,   15,   16,   81,   84,   17,   75,   25,   76,
};
static const YYINT yycheck[] = {                          4,
    5,    6,    7,    9,  278,  275,  280,  258,  265,  266,
  278,   16,   17,   18,  256,  257,  278,  259,  260,  261,
  262,  263,  264,   28,  275,  267,  268,  269,  270,  271,
  272,  273,  274,  275,  276,  277,  258,  258,  278,  279,
   68,   69,  278,  278,  278,  258,  279,  279,  278,  275,
  275,  278,  258,  275,  275,  265,  258,  258,   64,  258,
  275,  275,   67,  275,    0,   70,  275,  278,  275,   66,
  275,  275,  275,   67,   70,  275,   63,  275,   64,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 303
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ARCH","COMMA","CONFIG","CPU",
"NOCPU","DEVICE","NODEVICE","ENV","EQUALS","PLUSEQUALS","HINTS","IDENT",
"MAXUSERS","PROFILE","OPTIONS","NOOPTION","MAKEOPTIONS","NOMAKEOPTION",
"SEMICOLON","INCLUDE","FILES","ID","NUMBER","PATH",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : Configuration",
"Configuration : Many_specs",
"Many_specs : Many_specs Spec",
"Many_specs :",
"Spec : Device_spec SEMICOLON",
"Spec : Config_spec SEMICOLON",
"Spec : INCLUDE PATH SEMICOLON",
"Spec : INCLUDE ID SEMICOLON",
"Spec : FILES ID SEMICOLON",
"Spec : SEMICOLON",
"Spec : error SEMICOLON",
"Config_spec : ARCH Save_id",
"Config_spec : ARCH Save_id Save_id",
"Config_spec : CPU Save_id",
"Config_spec : NOCPU Save_id",
"Config_spec : OPTIONS Opt_list",
"Config_spec : NOOPTION NoOpt_list",
"Config_spec : MAKEOPTIONS Mkopt_list",
"Config_spec : NOMAKEOPTION Save_id",
"Config_spec : IDENT ID",
"Config_spec : System_spec",
"Config_spec : MAXUSERS NUMBER",
"Config_spec : PROFILE NUMBER",
"Config_spec : ENV ID",
"Config_spec : HINTS ID",
"System_spec : CONFIG System_id System_parameter_list",
"System_spec : CONFIG System_id",
"System_id : Save_id",
"System_parameter_list : System_parameter_list ID",
"System_parameter_list : ID",
"Opt_list : Opt_list COMMA Option",
"Opt_list : Option",
"NoOpt_list : NoOpt_list COMMA NoOption",
"NoOpt_list : NoOption",
"Option : Save_id",
"Option : Save_id EQUALS Opt_value",
"NoOption : Save_id",
"Opt_value : ID",
"Opt_value : NUMBER",
"Save_id : ID",
"Mkopt_list : Mkopt_list COMMA Mkoption",
"Mkopt_list : Mkoption",
"Mkoption : Save_id",
"Mkoption : Save_id EQUALS",
"Mkoption : Save_id EQUALS Opt_value",
"Mkoption : Save_id PLUSEQUALS Opt_value",
"Dev : ID",
"Device_spec : DEVICE Dev_list",
"Device_spec : NODEVICE NoDev_list",
"Dev_list : Dev_list COMMA Device",
"Dev_list : Device",
"NoDev_list : NoDev_list COMMA NoDevice",
"NoDev_list : NoDevice",
"Device : Dev",
"NoDevice : Dev",

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
#line 314 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"

void
yyerror(const char *s)
{

	errx(1, "%s:%d: %s", yyfile, yyline + 1, s);
}

int
yywrap(void)
{
	if (found_defaults) {
		if (freopen(PREFIX, "r", stdin) == NULL)
			err(2, "%s", PREFIX);		
		yyfile = PREFIX;
		yyline = 0;
		found_defaults = 0;
		return 0;
	}
	return 1;
}

/*
 * Add a new file to the list of files.
 */
static void
newfile(char *name)
{
	struct files_name *nl;
	
	nl = (struct files_name *) calloc(1, sizeof *nl);
	if (nl == NULL)
		err(EXIT_FAILURE, "calloc");
	nl->f_name = name;
	STAILQ_INSERT_TAIL(&fntab, nl, f_next);
}
	
/*
 * Find a device in the list of devices.
 */
static struct device *
finddev(struct device_head *dlist, char *name)
{
	struct device *dp;

	STAILQ_FOREACH(dp, dlist, d_next)
		if (eq(dp->d_name, name))
			return (dp);

	return (NULL);
}
	
/*
 * Add a device to the list of devices.
 */
static void
newdev(char *name)
{
	struct device *np;

	if (finddev(&dtab, name)) {
		fprintf(stderr,
		    "WARNING: duplicate device `%s' encountered.\n", name);
		return;
	}

	np = (struct device *) calloc(1, sizeof *np);
	if (np == NULL)
		err(EXIT_FAILURE, "calloc");
	np->d_name = name;
	STAILQ_INSERT_TAIL(&dtab, np, d_next);
}

/*
 * Schedule a device to removal.
 */
static void
rmdev_schedule(struct device_head *dh, char *name)
{
	struct device *dp;

	dp = finddev(dh, name);
	if (dp != NULL) {
		STAILQ_REMOVE(dh, dp, device, d_next);
		free(dp->d_name);
		free(dp);
	}
}

/*
 * Find an option in the list of options.
 */
static struct opt *
findopt(struct opt_head *list, char *name)
{
	struct opt *op;

	SLIST_FOREACH(op, list, op_next)
		if (eq(op->op_name, name))
			return (op);

	return (NULL);
}

/*
 * Add an option to the list of options.
 */
static void
newopt(struct opt_head *list, char *name, char *value, int append)
{
	struct opt *op, *op2;

	/*
	 * Ignore inclusions listed explicitly for configuration files.
	 */
	if (eq(name, OPT_AUTOGEN)) {
		incignore = 1;
		return;
	}

	op2 = findopt(list, name);
	if (op2 != NULL && !append) {
		fprintf(stderr,
		    "WARNING: duplicate option `%s' encountered.\n", name);
		return;
	}

	op = (struct opt *)calloc(1, sizeof (struct opt));
	if (op == NULL)
		err(EXIT_FAILURE, "calloc");
	op->op_name = name;
	op->op_ownfile = 0;
	op->op_value = value;
	if (op2 != NULL) {
		while (SLIST_NEXT(op2, op_append) != NULL)
			op2 = SLIST_NEXT(op2, op_append);
		SLIST_NEXT(op2, op_append) = op;
	} else
		SLIST_INSERT_HEAD(list, op, op_next);
}

/*
 * Remove an option from the list of options.
 */
static void
rmopt_schedule(struct opt_head *list, char *name)
{
	struct opt *op;

	op = findopt(list, name);
	if (op != NULL) {
		SLIST_REMOVE(list, op, opt, op_next);
		free(op->op_name);
		free(op);
	}
}
#line 518 "y.tab.c"

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
case 6:
#line 129 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		if (incignore == 0)
			include(yystack.l_mark[-1].str, 0);
		}
break;
case 7:
#line 134 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
	          if (incignore == 0)
		  	include(yystack.l_mark[-1].str, 0);
		}
break;
case 8:
#line 139 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ newfile(yystack.l_mark[-1].str); }
break;
case 11:
#line 147 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		if (machinename != NULL && !eq(yystack.l_mark[0].str, machinename))
		    errx(1, "%s:%d: only one machine directive is allowed",
			yyfile, yyline);
		machinename = yystack.l_mark[0].str;
		machinearch = yystack.l_mark[0].str;
	      }
break;
case 12:
#line 154 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		if (machinename != NULL &&
		    !(eq(yystack.l_mark[-1].str, machinename) && eq(yystack.l_mark[0].str, machinearch)))
		    errx(1, "%s:%d: only one machine directive is allowed",
			yyfile, yyline);
		machinename = yystack.l_mark[-1].str;
		machinearch = yystack.l_mark[0].str;
	      }
break;
case 13:
#line 162 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		struct cputype *cp =
		    (struct cputype *)calloc(1, sizeof (struct cputype));
		if (cp == NULL)
			err(EXIT_FAILURE, "calloc");
		cp->cpu_name = yystack.l_mark[0].str;
		SLIST_INSERT_HEAD(&cputype, cp, cpu_next);
	      }
break;
case 14:
#line 170 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		struct cputype *cp, *cp2;
		SLIST_FOREACH_SAFE(cp, &cputype, cpu_next, cp2) {
			if (eq(cp->cpu_name, yystack.l_mark[0].str)) {
				SLIST_REMOVE(&cputype, cp, cputype, cpu_next);
				free(cp);
			}
		}
	      }
break;
case 18:
#line 184 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ rmopt_schedule(&mkopt, yystack.l_mark[0].str); }
break;
case 19:
#line 185 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ ident = yystack.l_mark[0].str; }
break;
case 21:
#line 188 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ maxusers = yystack.l_mark[0].val; }
break;
case 22:
#line 189 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ profiling = yystack.l_mark[0].val; }
break;
case 23:
#line 190 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		env = yystack.l_mark[0].str;
		envmode = 1;
		}
break;
case 24:
#line 194 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		struct hint *hint;

		hint = (struct hint *)calloc(1, sizeof (struct hint));
		if (hint == NULL)
			err(EXIT_FAILURE, "calloc");	
		hint->hint_name = yystack.l_mark[0].str;
		STAILQ_INSERT_TAIL(&hints, hint, hint_next);
		hintmode = 1;
	        }
break;
case 25:
#line 206 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		errx(1, "%s:%d: root/dump/swap specifications obsolete",
		      yyfile, yyline);
		}
break;
case 27:
#line 215 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ newopt(&mkopt, ns("KERNEL"), yystack.l_mark[0].str, 0); }
break;
case 34:
#line 234 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		newopt(&opt, yystack.l_mark[0].str, NULL, 0);
		if (strchr(yystack.l_mark[0].str, '=') != NULL)
			errx(1, "%s:%d: The `=' in options should not be "
			    "quoted", yyfile, yyline);
	      }
break;
case 35:
#line 240 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		newopt(&opt, yystack.l_mark[-2].str, yystack.l_mark[0].str, 0);
	      }
break;
case 36:
#line 245 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		rmopt_schedule(&opt, yystack.l_mark[0].str);
		}
break;
case 37:
#line 250 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ yyval.str = yystack.l_mark[0].str; }
break;
case 38:
#line 251 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
			char buf[80];

			(void) snprintf(buf, sizeof(buf), "%d", yystack.l_mark[0].val);
			yyval.str = ns(buf);
		}
break;
case 39:
#line 259 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ yyval.str = yystack.l_mark[0].str; }
break;
case 42:
#line 269 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ newopt(&mkopt, yystack.l_mark[0].str, ns(""), 0); }
break;
case 43:
#line 270 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ newopt(&mkopt, yystack.l_mark[-1].str, ns(""), 0); }
break;
case 44:
#line 271 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ newopt(&mkopt, yystack.l_mark[-2].str, yystack.l_mark[0].str, 0); }
break;
case 45:
#line 272 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ newopt(&mkopt, yystack.l_mark[-2].str, yystack.l_mark[0].str, 1); }
break;
case 46:
#line 275 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{ yyval.str = yystack.l_mark[0].str; }
break;
case 53:
#line 297 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		newopt(&opt, devopt(yystack.l_mark[0].str), ns("1"), 0);
		/* and the device part */
		newdev(yystack.l_mark[0].str);
		}
break;
case 54:
#line 304 "/usr/home/freebsd/omega/src/usr.sbin/config/config.y"
	{
		char *s = devopt(yystack.l_mark[0].str);

		rmopt_schedule(&opt, s);
		free(s);
		/* and the device part */
		rmdev_schedule(&dtab, yystack.l_mark[0].str);
		}
break;
#line 906 "y.tab.c"
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
