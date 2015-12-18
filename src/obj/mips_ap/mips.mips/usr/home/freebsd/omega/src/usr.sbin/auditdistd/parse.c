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

#line 2 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
/*-
 * Copyright (c) 2012 The FreeBSD Foundation
 * All rights reserved.
 *
 * This software was developed by Pawel Jakub Dawidek under sponsorship from
 * the FreeBSD Foundation.
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
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $P4: //depot/projects/trustedbsd/openbsm/bin/auditdistd/parse.y#5 $
 */

#include <config/config.h>

#include <sys/types.h>
#include <sys/queue.h>
#include <sys/sysctl.h>

#include <arpa/inet.h>

#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>
#ifndef HAVE_STRLCPY
#include <compat/strlcpy.h>
#endif

#include "auditdistd.h"
#include "pjdlog.h"

extern int depth;
extern int lineno;

extern FILE *yyin;
extern char *yytext;

static struct adist_config *lconfig;
static struct adist_host *curhost;
#define	SECTION_GLOBAL		0
#define	SECTION_SENDER		1
#define	SECTION_RECEIVER	2
static int cursection;

/* Sender section. */
static char depth1_source[ADIST_ADDRSIZE];
static int depth1_checksum;
static int depth1_compression;
/* Sender and receiver sections. */
static char depth1_directory[PATH_MAX];

static bool adjust_directory(char *path);
static bool family_supported(int family);

extern void yyrestart(FILE *);
#line 100 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
	int num;
	char *str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 111 "parse.c"

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

#define CB 257
#define CERTFILE 258
#define DIRECTORY 259
#define FINGERPRINT 260
#define HOST 261
#define KEYFILE 262
#define LISTEN 263
#define NAME 264
#define OB 265
#define PASSWORD 266
#define PIDFILE 267
#define RECEIVER 268
#define REMOTE 269
#define SENDER 270
#define SOURCE 271
#define TIMEOUT 272
#define NUM 273
#define STR 274
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    1,    1,    1,    2,    3,    4,
    5,    7,    8,    8,    9,    9,    9,    6,   13,   14,
   14,   15,   15,   15,   15,   15,   11,   10,   20,   21,
   17,   18,   16,   12,   19,   22,   23,   23,   25,   25,
   25,   25,   25,   24,   24,   27,   27,   27,   26,
};
static const YYINT yylen[] = {                            2,
    0,    2,    1,    1,    1,    1,    1,    2,    2,    2,
    4,    1,    0,    2,    1,    1,    1,    4,    1,    0,
    2,    1,    1,    1,    1,    1,    2,    2,    2,    2,
    2,    2,    2,    5,    5,    1,    0,    2,    1,    1,
    1,    1,    1,    0,    2,    1,    1,    1,    2,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    2,    3,    4,    5,
    6,    7,    8,    9,   19,   20,   12,   13,   10,    0,
    0,   18,    0,    0,    0,    0,    0,   23,   21,   22,
   24,   25,   26,   11,    0,    0,   14,   15,   16,   17,
   31,   27,   36,    0,   32,   33,    0,   28,   44,   37,
    0,    0,   35,    0,    0,   47,   48,   46,   45,   34,
    0,   39,   41,   42,   43,   38,   40,   30,   49,   29,
};
static const YYINT yydgoto[] = {                          1,
    7,    8,    9,   10,   11,   12,   18,   21,   37,   38,
   28,   40,   16,   20,   29,   30,   31,   32,   33,   64,
   57,   44,   52,   51,   66,   58,   59,
};
static const YYINT yysindex[] = {                         0,
 -235, -272, -268, -257, -254, -255,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -219,
 -252,    0, -258, -251, -249, -248, -247,    0,    0,    0,
    0,    0,    0,    0, -249, -246,    0,    0,    0,    0,
    0,    0,    0, -243,    0,    0, -231,    0,    0,    0,
 -245, -256,    0, -238, -233,    0,    0,    0,    0,    0,
 -229,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -35,
  -21,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -32,   11,    0,    0,    0,   -5,    0,
};
#define YYTABLESIZE 47
static const YYINT yytable[] = {                         39,
   60,   13,   24,   61,   34,   14,   24,   15,   35,   54,
   17,   53,   55,   24,   36,   41,   62,   19,   36,   65,
   54,   49,   42,   55,   43,   45,   46,   48,    2,   56,
   63,    3,    4,   50,    5,   68,    6,   22,   23,   24,
   69,   25,   26,   27,   70,   47,   67,
};
static const YYINT yycheck[] = {                         21,
  257,  274,  259,  260,  257,  274,  259,  265,  261,  266,
  265,  257,  269,  259,  271,  274,   52,  273,  271,   52,
  266,  265,  274,  269,  274,  274,  274,  274,  264,   51,
   52,  267,  268,  265,  270,  274,  272,  257,  258,  259,
  274,  261,  262,  263,  274,   35,   52,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 274
#define YYUNDFTOKEN 304
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"CB","CERTFILE","DIRECTORY",
"FINGERPRINT","HOST","KEYFILE","LISTEN","NAME","OB","PASSWORD","PIDFILE",
"RECEIVER","REMOTE","SENDER","SOURCE","TIMEOUT","NUM","STR",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : statements",
"statements :",
"statements : statements statement",
"statement : name_statement",
"statement : pidfile_statement",
"statement : timeout_statement",
"statement : sender_statement",
"statement : receiver_statement",
"name_statement : NAME STR",
"pidfile_statement : PIDFILE STR",
"timeout_statement : TIMEOUT NUM",
"sender_statement : SENDER sender_start sender_entries CB",
"sender_start : OB",
"sender_entries :",
"sender_entries : sender_entries sender_entry",
"sender_entry : source_statement",
"sender_entry : directory_statement",
"sender_entry : sender_host_statement",
"receiver_statement : RECEIVER receiver_start receiver_entries CB",
"receiver_start : OB",
"receiver_entries :",
"receiver_entries : receiver_entries receiver_entry",
"receiver_entry : listen_statement",
"receiver_entry : directory_statement",
"receiver_entry : certfile_statement",
"receiver_entry : keyfile_statement",
"receiver_entry : receiver_host_statement",
"directory_statement : DIRECTORY STR",
"source_statement : SOURCE STR",
"fingerprint_statement : FINGERPRINT STR",
"password_statement : PASSWORD STR",
"certfile_statement : CERTFILE STR",
"keyfile_statement : KEYFILE STR",
"listen_statement : LISTEN STR",
"sender_host_statement : HOST host_start OB sender_host_entries CB",
"receiver_host_statement : HOST host_start OB receiver_host_entries CB",
"host_start : STR",
"sender_host_entries :",
"sender_host_entries : sender_host_entries sender_host_entry",
"sender_host_entry : source_statement",
"sender_host_entry : remote_statement",
"sender_host_entry : directory_statement",
"sender_host_entry : fingerprint_statement",
"sender_host_entry : password_statement",
"receiver_host_entries :",
"receiver_host_entries : receiver_host_entries receiver_host_entry",
"receiver_host_entry : remote_statement",
"receiver_host_entry : directory_statement",
"receiver_host_entry : password_statement",
"remote_statement : REMOTE STR",

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
#line 697 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"

static bool
family_supported(int family)
{
	int sock;

	sock = socket(family, SOCK_STREAM, 0);
	if (sock == -1 && errno == EPROTONOSUPPORT)
		return (false);
	if (sock >= 0)
		(void)close(sock);
	return (true);
}

static bool
adjust_directory(char *path)
{
	size_t len;

	len = strlen(path);
	for (;;) {
		if (len == 0) {
			pjdlog_error("Directory path is empty.");
			return (false);
		}
		if (path[len - 1] != '/')
			break;
		len--;
		path[len] = '\0';
	}
	if (path[0] != '/') {
		pjdlog_error("Directory path must be absolute.");
		return (false);
	}
	return (true);
}

static int
my_name(char *name, size_t size)
{
	char buf[MAXHOSTNAMELEN];
	char *pos;

	if (gethostname(buf, sizeof(buf)) < 0) {
		pjdlog_errno(LOG_ERR, "gethostname() failed");
		return (-1);
	}

	/* First component of the host name. */
	pos = strchr(buf, '.');
	if (pos == NULL)
		(void)strlcpy(name, buf, size);
	else
		(void)strlcpy(name, buf, MIN((size_t)(pos - buf + 1), size));

	if (name[0] == '\0') {
		pjdlog_error("Empty host name.");
		return (-1);
	}

	return (0);
}

void
yyerror(const char *str)
{

	pjdlog_error("Unable to parse configuration file at line %d near '%s': %s",
	    lineno, yytext, str);
}

struct adist_config *
yy_config_parse(const char *config, bool exitonerror)
{
	int ret;

	curhost = NULL;
	cursection = SECTION_GLOBAL;
	depth = 0;
	lineno = 0;

	lconfig = calloc(1, sizeof(*lconfig));
	if (lconfig == NULL) {
		pjdlog_error("Unable to allocate memory for configuration.");
		if (exitonerror)
			exit(EX_TEMPFAIL);
		return (NULL);
	}
	TAILQ_INIT(&lconfig->adc_hosts);
	TAILQ_INIT(&lconfig->adc_listen);
	lconfig->adc_name[0] = '\0';
	lconfig->adc_timeout = -1;
	lconfig->adc_pidfile[0] = '\0';
	lconfig->adc_certfile[0] = '\0';
	lconfig->adc_keyfile[0] = '\0';

	yyin = fopen(config, "r");
	if (yyin == NULL) {
		pjdlog_errno(LOG_ERR, "Unable to open configuration file %s",
		    config);
		yy_config_free(lconfig);
		if (exitonerror)
			exit(EX_OSFILE);
		return (NULL);
	}
	yyrestart(yyin);
	ret = yyparse();
	fclose(yyin);
	if (ret != 0) {
		yy_config_free(lconfig);
		if (exitonerror)
			exit(EX_CONFIG);
		return (NULL);
	}

	/*
	 * Let's see if everything is set up.
	 */
	if (lconfig->adc_name[0] == '\0' && my_name(lconfig->adc_name,
	    sizeof(lconfig->adc_name)) == -1) {
		yy_config_free(lconfig);
		if (exitonerror)
			exit(EX_CONFIG);
		return (NULL);
	}
	if (lconfig->adc_timeout == -1)
		lconfig->adc_timeout = ADIST_TIMEOUT;
	if (lconfig->adc_pidfile[0] == '\0') {
		(void)strlcpy(lconfig->adc_pidfile, ADIST_PIDFILE,
		    sizeof(lconfig->adc_pidfile));
	}
	if (lconfig->adc_certfile[0] == '\0') {
		(void)strlcpy(lconfig->adc_certfile, ADIST_CERTFILE,
		    sizeof(lconfig->adc_certfile));
	}
	if (lconfig->adc_keyfile[0] == '\0') {
		(void)strlcpy(lconfig->adc_keyfile, ADIST_KEYFILE,
		    sizeof(lconfig->adc_keyfile));
	}

	return (lconfig);
}

void
yy_config_free(struct adist_config *config)
{
	struct adist_host *adhost;
	struct adist_listen *lst;

	while ((lst = TAILQ_FIRST(&config->adc_listen)) != NULL) {
		TAILQ_REMOVE(&config->adc_listen, lst, adl_next);
		free(lst);
	}
	while ((adhost = TAILQ_FIRST(&config->adc_hosts)) != NULL) {
		TAILQ_REMOVE(&config->adc_hosts, adhost, adh_next);
		bzero(adhost, sizeof(*adhost));
		free(adhost);
	}
	free(config);
}
#line 500 "parse.c"

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
#line 129 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_RASSERT(depth == 0,
		    "The name variable can only be specificed in the global section.");

		if (lconfig->adc_name[0] != '\0') {
			pjdlog_error("The name variable is specified twice.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		if (strlcpy(lconfig->adc_name, yystack.l_mark[0].str,
		    sizeof(lconfig->adc_name)) >=
		    sizeof(lconfig->adc_name)) {
			pjdlog_error("The name value is too long.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		free(yystack.l_mark[0].str);
	}
break;
case 9:
#line 150 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_RASSERT(depth == 0,
		    "The pidfile variable can only be specificed in the global section.");

		if (lconfig->adc_pidfile[0] != '\0') {
			pjdlog_error("The pidfile variable is specified twice.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		if (strcmp(yystack.l_mark[0].str, "none") != 0 && yystack.l_mark[0].str[0] != '/') {
			pjdlog_error("The pidfile variable must be set to absolute pathname or \"none\".");
			free(yystack.l_mark[0].str);
			return (1);
		}
		if (strlcpy(lconfig->adc_pidfile, yystack.l_mark[0].str,
		    sizeof(lconfig->adc_pidfile)) >=
		    sizeof(lconfig->adc_pidfile)) {
			pjdlog_error("The pidfile value is too long.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		free(yystack.l_mark[0].str);
	}
break;
case 10:
#line 176 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_ASSERT(depth == 0);

		lconfig->adc_timeout = yystack.l_mark[0].num;
	}
break;
case 11:
#line 184 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_ASSERT(depth == 0);
		PJDLOG_ASSERT(cursection == SECTION_SENDER);

		/* Configure defaults. */
		if (depth1_checksum == -1)
			depth1_checksum = ADIST_CHECKSUM_NONE;
		if (depth1_compression == -1)
			depth1_compression = ADIST_COMPRESSION_NONE;
		if (depth1_directory[0] == '\0') {
			(void)strlcpy(depth1_directory, ADIST_DIRECTORY_SENDER,
			    sizeof(depth1_directory));
		}
		/* Empty depth1_source is ok. */
		TAILQ_FOREACH(curhost, &lconfig->adc_hosts, adh_next) {
			if (curhost->adh_role != ADIST_ROLE_SENDER)
				continue;
			if (curhost->adh_checksum == -1)
				curhost->adh_checksum = depth1_checksum;
			if (curhost->adh_compression == -1)
				curhost->adh_compression = depth1_compression;
			if (curhost->adh_directory[0] == '\0') {
				(void)strlcpy(curhost->adh_directory,
				    depth1_directory,
				    sizeof(curhost->adh_directory));
			}
			if (curhost->adh_localaddr[0] == '\0') {
				(void)strlcpy(curhost->adh_localaddr,
				    depth1_source,
				    sizeof(curhost->adh_localaddr));
			}
		}
		cursection = SECTION_GLOBAL;
	}
break;
case 12:
#line 221 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_ASSERT(depth == 1);
		PJDLOG_ASSERT(cursection == SECTION_GLOBAL);

		cursection = SECTION_SENDER;
		depth1_checksum = -1;
		depth1_compression = -1;
		depth1_source[0] = '\0';
		depth1_directory[0] = '\0';

#ifndef HAVE_AUDIT_SYSCALLS
		pjdlog_error("Sender functionality is not available.");
		return (1);
#endif
	}
break;
case 18:
#line 258 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_ASSERT(depth == 0);
		PJDLOG_ASSERT(cursection == SECTION_RECEIVER);

		/*
		 * If not listen addresses were specified,
		 * configure default ones.
		 */
		if (TAILQ_EMPTY(&lconfig->adc_listen)) {
			struct adist_listen *lst;

			if (family_supported(AF_INET)) {
				lst = calloc(1, sizeof(*lst));
				if (lst == NULL) {
					pjdlog_error("Unable to allocate memory for listen address.");
					return (1);
				}
				(void)strlcpy(lst->adl_addr,
				    ADIST_LISTEN_TLS_TCP4,
				    sizeof(lst->adl_addr));
				TAILQ_INSERT_TAIL(&lconfig->adc_listen, lst, adl_next);
			} else {
				pjdlog_debug(1,
				    "No IPv4 support in the kernel, not listening on IPv4 address.");
			}
			if (family_supported(AF_INET6)) {
				lst = calloc(1, sizeof(*lst));
				if (lst == NULL) {
					pjdlog_error("Unable to allocate memory for listen address.");
					return (1);
				}
				(void)strlcpy(lst->adl_addr,
				    ADIST_LISTEN_TLS_TCP6,
				    sizeof(lst->adl_addr));
				TAILQ_INSERT_TAIL(&lconfig->adc_listen, lst, adl_next);
			} else {
				pjdlog_debug(1,
				    "No IPv6 support in the kernel, not listening on IPv6 address.");
			}
			if (TAILQ_EMPTY(&lconfig->adc_listen)) {
				pjdlog_error("No address to listen on.");
				return (1);
			}
		}
		/* Configure defaults. */
		if (depth1_directory[0] == '\0') {
			(void)strlcpy(depth1_directory,
			    ADIST_DIRECTORY_RECEIVER,
			    sizeof(depth1_directory));
		}
		TAILQ_FOREACH(curhost, &lconfig->adc_hosts, adh_next) {
			if (curhost->adh_role != ADIST_ROLE_RECEIVER)
				continue;
			if (curhost->adh_directory[0] == '\0') {
				if (snprintf(curhost->adh_directory,
				    sizeof(curhost->adh_directory), "%s/%s",
				    depth1_directory, curhost->adh_name) >=
				    (ssize_t)sizeof(curhost->adh_directory)) {
					pjdlog_error("Directory value is too long.");
					return (1);
				}
			}
		}
		cursection = SECTION_GLOBAL;
	}
break;
case 19:
#line 326 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_ASSERT(depth == 1);
		PJDLOG_ASSERT(cursection == SECTION_GLOBAL);

		cursection = SECTION_RECEIVER;
		depth1_directory[0] = '\0';
	}
break;
case 27:
#line 405 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_ASSERT(cursection == SECTION_SENDER ||
		    cursection == SECTION_RECEIVER);

		switch (depth) {
		case 1:
			if (strlcpy(depth1_directory, yystack.l_mark[0].str,
			    sizeof(depth1_directory)) >=
			    sizeof(depth1_directory)) {
				pjdlog_error("Directory value is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			if (!adjust_directory(depth1_directory))
				return (1);
			break;
		case 2:
			if (cursection == SECTION_SENDER || yystack.l_mark[0].str[0] == '/') {
				if (strlcpy(curhost->adh_directory, yystack.l_mark[0].str,
				    sizeof(curhost->adh_directory)) >=
				    sizeof(curhost->adh_directory)) {
					pjdlog_error("Directory value is too long.");
					free(yystack.l_mark[0].str);
					return (1);
				}
			} else /* if (cursection == SECTION_RECEIVER) */ {
				if (depth1_directory[0] == '\0') {
					pjdlog_error("Directory path must be absolute.");
					free(yystack.l_mark[0].str);
					return (1);
				}
				if (snprintf(curhost->adh_directory,
				    sizeof(curhost->adh_directory), "%s/%s",
				    depth1_directory, yystack.l_mark[0].str) >=
				    (ssize_t)sizeof(curhost->adh_directory)) {
					pjdlog_error("Directory value is too long.");
					free(yystack.l_mark[0].str);
					return (1);
				}
			}
			break;
		default:
			PJDLOG_ABORT("directory at wrong depth level");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 28:
#line 454 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_RASSERT(cursection == SECTION_SENDER,
		    "The source variable must be in sender section.");

		switch (depth) {
		case 1:
			if (strlcpy(depth1_source, yystack.l_mark[0].str,
			    sizeof(depth1_source)) >=
			    sizeof(depth1_source)) {
				pjdlog_error("Source value is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			break;
		case 2:
			if (strlcpy(curhost->adh_localaddr, yystack.l_mark[0].str,
			    sizeof(curhost->adh_localaddr)) >=
			    sizeof(curhost->adh_localaddr)) {
				pjdlog_error("Source value is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			break;
		}
		free(yystack.l_mark[0].str);
	}
break;
case 29:
#line 483 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_ASSERT(cursection == SECTION_SENDER);
		PJDLOG_ASSERT(depth == 2);

		if (strncasecmp(yystack.l_mark[0].str, "SHA256=", 7) != 0) {
			pjdlog_error("Invalid fingerprint value.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		if (strlcpy(curhost->adh_fingerprint, yystack.l_mark[0].str,
		    sizeof(curhost->adh_fingerprint)) >=
		    sizeof(curhost->adh_fingerprint)) {
			pjdlog_error("Fingerprint value is too long.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		free(yystack.l_mark[0].str);
	}
break;
case 30:
#line 504 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_ASSERT(cursection == SECTION_SENDER ||
		    cursection == SECTION_RECEIVER);
		PJDLOG_ASSERT(depth == 2);

		if (strlcpy(curhost->adh_password, yystack.l_mark[0].str,
		    sizeof(curhost->adh_password)) >=
		    sizeof(curhost->adh_password)) {
			pjdlog_error("Password value is too long.");
			bzero(yystack.l_mark[0].str, strlen(yystack.l_mark[0].str));
			free(yystack.l_mark[0].str);
			return (1);
		}
		bzero(yystack.l_mark[0].str, strlen(yystack.l_mark[0].str));
		free(yystack.l_mark[0].str);
	}
break;
case 31:
#line 523 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_ASSERT(cursection == SECTION_RECEIVER);
		PJDLOG_ASSERT(depth == 1);

		if (strlcpy(lconfig->adc_certfile, yystack.l_mark[0].str,
		    sizeof(lconfig->adc_certfile)) >=
		    sizeof(lconfig->adc_certfile)) {
			pjdlog_error("Certfile value is too long.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		free(yystack.l_mark[0].str);
	}
break;
case 32:
#line 539 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_ASSERT(cursection == SECTION_RECEIVER);
		PJDLOG_ASSERT(depth == 1);

		if (strlcpy(lconfig->adc_keyfile, yystack.l_mark[0].str,
		    sizeof(lconfig->adc_keyfile)) >=
		    sizeof(lconfig->adc_keyfile)) {
			pjdlog_error("Keyfile value is too long.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		free(yystack.l_mark[0].str);
	}
break;
case 33:
#line 555 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		struct adist_listen *lst;

		PJDLOG_ASSERT(depth == 1);
		PJDLOG_ASSERT(cursection == SECTION_RECEIVER);

		lst = calloc(1, sizeof(*lst));
		if (lst == NULL) {
			pjdlog_error("Unable to allocate memory for listen address.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		if (strlcpy(lst->adl_addr, yystack.l_mark[0].str, sizeof(lst->adl_addr)) >=
		    sizeof(lst->adl_addr)) {
			pjdlog_error("listen argument is too long.");
			free(yystack.l_mark[0].str);
			free(lst);
			return (1);
		}
		TAILQ_INSERT_TAIL(&lconfig->adc_listen, lst, adl_next);
		free(yystack.l_mark[0].str);
	}
break;
case 34:
#line 580 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		/* Put it onto host list. */
		TAILQ_INSERT_TAIL(&lconfig->adc_hosts, curhost, adh_next);
		curhost = NULL;
	}
break;
case 35:
#line 588 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		/* Put it onto host list. */
		TAILQ_INSERT_TAIL(&lconfig->adc_hosts, curhost, adh_next);
		curhost = NULL;
	}
break;
case 36:
#line 596 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		/* Check if there is no duplicate entry. */
		TAILQ_FOREACH(curhost, &lconfig->adc_hosts, adh_next) {
			if (strcmp(curhost->adh_name, yystack.l_mark[0].str) != 0)
				continue;
			if (curhost->adh_role == ADIST_ROLE_SENDER &&
			    cursection == SECTION_RECEIVER) {
				continue;
			}
			if (curhost->adh_role == ADIST_ROLE_RECEIVER &&
			    cursection == SECTION_SENDER) {
				continue;
			}
			pjdlog_error("%s host %s is configured more than once.",
			    curhost->adh_role == ADIST_ROLE_SENDER ?
			    "Sender" : "Receiver", curhost->adh_name);
			free(yystack.l_mark[0].str);
			return (1);
		}

		curhost = calloc(1, sizeof(*curhost));
		if (curhost == NULL) {
			pjdlog_error("Unable to allocate memory for host configuration.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		if (strlcpy(curhost->adh_name, yystack.l_mark[0].str, sizeof(curhost->adh_name)) >=
		    sizeof(curhost->adh_name)) {
			pjdlog_error("Host name is too long.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		free(yystack.l_mark[0].str);
		curhost->adh_role = cursection == SECTION_SENDER ?
		    ADIST_ROLE_SENDER : ADIST_ROLE_RECEIVER;
		curhost->adh_version = ADIST_VERSION;
		curhost->adh_localaddr[0] = '\0';
		curhost->adh_remoteaddr[0] = '\0';
		curhost->adh_remote = NULL;
		curhost->adh_directory[0] = '\0';
		curhost->adh_password[0] = '\0';
		curhost->adh_fingerprint[0] = '\0';
		curhost->adh_worker_pid = 0;
		curhost->adh_conn = NULL;
	}
break;
case 49:
#line 680 "/usr/home/freebsd/omega/src/usr.sbin/auditdistd/../../contrib/openbsm/bin/auditdistd/parse.y"
	{
		PJDLOG_ASSERT(depth == 2);
		PJDLOG_ASSERT(cursection == SECTION_SENDER ||
		    cursection == SECTION_RECEIVER);

		if (strlcpy(curhost->adh_remoteaddr, yystack.l_mark[0].str,
		    sizeof(curhost->adh_remoteaddr)) >=
		    sizeof(curhost->adh_remoteaddr)) {
			pjdlog_error("Remote value is too long.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		free(yystack.l_mark[0].str);
	}
break;
#line 1146 "parse.c"
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
