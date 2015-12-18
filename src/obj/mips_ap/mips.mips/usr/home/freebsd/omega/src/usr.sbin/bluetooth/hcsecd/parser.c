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

#line 2 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/hcsecd/parser.y"
/*
 * parser.y
 *
 * Copyright (c) 2001-2002 Maksim Yevmenkin <m_evmenkin@yahoo.com>
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
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id: parser.y,v 1.5 2003/06/07 21:22:30 max Exp $
 * $FreeBSD$
 */

#include <sys/fcntl.h>
#include <sys/queue.h>
#define L2CAP_SOCKET_CHECKED
#include <bluetooth.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>
#include "hcsecd.h"

	int	yyparse  (void);
	int	yylex    (void);

static	void	free_key (link_key_p key);
static	int	hexa2int4(char *a);
static	int	hexa2int8(char *a);

extern	int			 yylineno;
static	LIST_HEAD(, link_key)	 link_keys;
	char			*config_file = "/etc/bluetooth/hcsecd.conf";

static	link_key_p		 key = NULL;
#line 61 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/hcsecd/parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char	*string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 90 "parser.c"

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

#define T_BDADDRSTRING 257
#define T_HEXSTRING 258
#define T_STRING 259
#define T_DEVICE 260
#define T_BDADDR 261
#define T_NAME 262
#define T_KEY 263
#define T_PIN 264
#define T_NOKEY 265
#define T_NOPIN 266
#define T_JUNK 267
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    2,    1,    3,    3,    4,    4,    4,    4,
    5,    6,    7,    7,    8,    8,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    5,    2,    3,    1,    1,    1,    1,
    2,    2,    2,    2,    2,    2,
};
static const YYINT yydefred[] = {                         0,
    3,    0,    1,    0,    2,    0,    0,    0,    0,    0,
    0,    0,    7,    8,    9,   10,   11,   12,   13,   14,
   15,   16,    4,    0,    5,    6,
};
static const YYINT yydgoto[] = {                          2,
    3,    4,   11,   12,   13,   14,   15,   16,
};
static const YYINT yysindex[] = {                      -258,
    0, -258,    0, -119,    0, -250, -252, -253, -257, -256,
 -125,  -52,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -50,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   13,    0,    0,    5,    0,    0,    0,    0,
};
#define YYTABLESIZE 139
static const YYINT yytable[] = {                         23,
   19,    1,   21,    6,   17,   18,   25,   20,   26,   22,
    7,    8,    9,   10,    5,   24,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    7,    8,    9,   10,
};
static const YYINT yycheck[] = {                        125,
  258,  260,  259,  123,  257,  259,   59,  265,   59,  266,
  261,  262,  263,  264,    2,   11,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,   -1,  261,  262,  263,  264,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 267
#define YYUNDFTOKEN 278
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_BDADDRSTRING",
"T_HEXSTRING","T_STRING","T_DEVICE","T_BDADDR","T_NAME","T_KEY","T_PIN",
"T_NOKEY","T_NOPIN","T_JUNK",0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : config",
"config : line",
"config : config line",
"$$1 :",
"line : T_DEVICE $$1 '{' options '}'",
"options : option ';'",
"options : options option ';'",
"option : bdaddr",
"option : name",
"option : key",
"option : pin",
"bdaddr : T_BDADDR T_BDADDRSTRING",
"name : T_NAME T_STRING",
"key : T_KEY T_HEXSTRING",
"key : T_KEY T_NOKEY",
"pin : T_PIN T_STRING",
"pin : T_PIN T_NOPIN",

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
#line 187 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/hcsecd/parser.y"

/* Display parser error message */
void
yyerror(char const *message)
{
	syslog(LOG_ERR, "%s in line %d", message, yylineno);
}

/* Re-read config file */
void
read_config_file(void)
{
	extern FILE	*yyin;

	if (config_file == NULL) {
		syslog(LOG_ERR, "Unknown config file name!");
		exit(1);
	}

	if ((yyin = fopen(config_file, "r")) == NULL) {
		syslog(LOG_ERR, "Could not open config file '%s'. %s (%d)",
				config_file, strerror(errno), errno);
		exit(1);
	}

	clean_config();
	if (yyparse() < 0) {
		syslog(LOG_ERR, "Could not parse config file '%s'",config_file);
		exit(1);
	}

	fclose(yyin);
	yyin = NULL;

#if __config_debug__
	dump_config();
#endif
}

/* Clean config */
void
clean_config(void)
{
	link_key_p	key = NULL;

	while ((key = LIST_FIRST(&link_keys)) != NULL) {
		LIST_REMOVE(key, next);
		free_key(key);
	}
}

/* Find link key entry in the list. Return exact or default match */
link_key_p
get_key(bdaddr_p bdaddr, int exact_match)
{
	link_key_p	key = NULL, defkey = NULL;

	LIST_FOREACH(key, &link_keys, next) {
		if (memcmp(bdaddr, &key->bdaddr, sizeof(key->bdaddr)) == 0)
			break;

		if (!exact_match)
			if (memcmp(NG_HCI_BDADDR_ANY, &key->bdaddr,
					sizeof(key->bdaddr)) == 0)
				defkey = key;
	}

	return ((key != NULL)? key : defkey);
}

#if __config_debug__
/* Dump config */
void
dump_config(void)
{
	link_key_p	key = NULL;
	char		buffer[64];

	LIST_FOREACH(key, &link_keys, next) {
		if (key->key != NULL)
			snprintf(buffer, sizeof(buffer),
"0x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
				key->key[0], key->key[1], key->key[2],
				key->key[3], key->key[4], key->key[5],
				key->key[6], key->key[7], key->key[8],
				key->key[9], key->key[10], key->key[11],
				key->key[12], key->key[13], key->key[14],
				key->key[15]);

		syslog(LOG_DEBUG, 
"device %s " \
"bdaddr %s " \
"pin %s " \
"key %s",
			(key->name != NULL)? key->name : "noname",
			bt_ntoa(&key->bdaddr, NULL),
			(key->pin != NULL)? key->pin : "nopin",
			(key->key != NULL)? buffer : "nokey");
	}
}
#endif

/* Read keys file */
int
read_keys_file(void)
{
	FILE		*f = NULL;
	link_key_t	*key = NULL;
	char		 buf[HCSECD_BUFFER_SIZE], *p = NULL, *cp = NULL;
	bdaddr_t	 bdaddr;
	int		 i, len;

	if ((f = fopen(HCSECD_KEYSFILE, "r")) == NULL) {
		if (errno == ENOENT)
			return (0);

		syslog(LOG_ERR, "Could not open keys file %s. %s (%d)\n",
				HCSECD_KEYSFILE, strerror(errno), errno);

		return (-1);
	}

	while ((p = fgets(buf, sizeof(buf), f)) != NULL) {
		if (*p == '#')
			continue;
		if ((cp = strpbrk(p, " ")) == NULL)
			continue;

		*cp++ = '\0';

		if (!bt_aton(p, &bdaddr))
			continue;

		if ((key = get_key(&bdaddr, 1)) == NULL)
			continue;

		if (key->key == NULL) {
			key->key = (uint8_t *) malloc(NG_HCI_KEY_SIZE);
			if (key->key == NULL) {
				syslog(LOG_ERR, "Could not allocate link key");
				exit(1);
			}
		}

		memset(key->key, 0, NG_HCI_KEY_SIZE);

		len = strlen(cp) / 2;
		if (len > NG_HCI_KEY_SIZE)
			len = NG_HCI_KEY_SIZE;

		for (i = 0; i < len; i ++)
			key->key[i] = hexa2int8(cp + 2*i);

		syslog(LOG_DEBUG, "Restored link key for the entry, " \
				"remote bdaddr %s, name '%s'",
				bt_ntoa(&key->bdaddr, NULL),
				(key->name != NULL)? key->name : "No name");
	}

	fclose(f);

	return (0);
}

/* Dump keys file */
int
dump_keys_file(void)
{
	link_key_p	key = NULL;
	char		tmp[PATH_MAX], buf[HCSECD_BUFFER_SIZE];
	int		f;

	snprintf(tmp, sizeof(tmp), "%s.tmp", HCSECD_KEYSFILE);
	if ((f = open(tmp, O_RDWR|O_CREAT|O_TRUNC|O_EXCL, 0600)) < 0) {
		syslog(LOG_ERR, "Could not create temp keys file %s. %s (%d)\n",
				tmp, strerror(errno), errno);
		return (-1);
	}

	LIST_FOREACH(key, &link_keys, next) {
		if (key->key == NULL)
			continue;

		snprintf(buf, sizeof(buf),
"%s %02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\n",
			bt_ntoa(&key->bdaddr, NULL),
			key->key[0],  key->key[1],  key->key[2],  key->key[3],
			key->key[4],  key->key[5],  key->key[6],  key->key[7],
			key->key[8],  key->key[9],  key->key[10], key->key[11],
			key->key[12], key->key[13], key->key[14], key->key[15]);

		if (write(f, buf, strlen(buf)) < 0) {
			syslog(LOG_ERR, "Could not write temp keys file. " \
					"%s (%d)\n", strerror(errno), errno);
			break;
		}
	}

	close(f);

	if (rename(tmp, HCSECD_KEYSFILE) < 0) {
		syslog(LOG_ERR, "Could not rename(%s, %s). %s (%d)\n",
				tmp, HCSECD_KEYSFILE, strerror(errno), errno);
		unlink(tmp);
		return (-1);
	}

	return (0);
}

/* Free key entry */
static void
free_key(link_key_p key)
{
	if (key->name != NULL)
		free(key->name);
	if (key->key != NULL)
		free(key->key);
	if (key->pin != NULL)
		free(key->pin);

	memset(key, 0, sizeof(*key));
	free(key);
}

/* Convert hex ASCII to int4 */
static int
hexa2int4(char *a)
{
	if ('0' <= *a && *a <= '9')
		return (*a - '0');

	if ('A' <= *a && *a <= 'F')
		return (*a - 'A' + 0xa);

	if ('a' <= *a && *a <= 'f')
		return (*a - 'a' + 0xa);

	syslog(LOG_ERR, "Invalid hex character: '%c' (%#x)", *a, *a);
	exit(1);
}

/* Convert hex ASCII to int8 */
static int
hexa2int8(char *a)
{
	return ((hexa2int4(a) << 4) | hexa2int4(a + 1));
}

#line 523 "parser.c"

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
#line 75 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/hcsecd/parser.y"
	{
			key = (link_key_p) malloc(sizeof(*key));
			if (key == NULL) {
				syslog(LOG_ERR, "Could not allocate new " \
						"config entry");
				exit(1);
			}

			memset(key, 0, sizeof(*key));
			}
break;
case 4:
#line 86 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/hcsecd/parser.y"
	{
			if (get_key(&key->bdaddr, 1) != NULL) {
				syslog(LOG_ERR, "Ignoring duplicated entry " \
						"for bdaddr %s",
						bt_ntoa(&key->bdaddr, NULL));
				free_key(key);
			} else 
				LIST_INSERT_HEAD(&link_keys, key, next);

			key = NULL;
			}
break;
case 11:
#line 110 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/hcsecd/parser.y"
	{
			if (!bt_aton(yystack.l_mark[0].string, &key->bdaddr)) {
				syslog(LOG_ERR, "Cound not parse BD_ADDR " \
						"'%s'", yystack.l_mark[0].string);
				exit(1);
			}
			}
break;
case 12:
#line 120 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/hcsecd/parser.y"
	{
			if (key->name != NULL)
				free(key->name);

			key->name = strdup(yystack.l_mark[0].string);
			if (key->name == NULL) {
				syslog(LOG_ERR, "Could not allocate new " \
						"device name");
				exit(1);
			}
			}
break;
case 13:
#line 134 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/hcsecd/parser.y"
	{
			int	i, len;

			if (key->key != NULL)
				free(key->key);

			key->key = (uint8_t *) malloc(NG_HCI_KEY_SIZE);
			if (key->key == NULL) {
				syslog(LOG_ERR, "Could not allocate new " \
						"link key");
				exit(1);
			}

			memset(key->key, 0, NG_HCI_KEY_SIZE);

			len = strlen(yystack.l_mark[0].string) / 2;
			if (len > NG_HCI_KEY_SIZE)
				len = NG_HCI_KEY_SIZE;

			for (i = 0; i < len; i ++)
				key->key[i] = hexa2int8((char *)(yystack.l_mark[0].string) + 2*i);
			}
break;
case 14:
#line 157 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/hcsecd/parser.y"
	{
			if (key->key != NULL)
				free(key->key);

			key->key = NULL;
			}
break;
case 15:
#line 166 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/hcsecd/parser.y"
	{
			if (key->pin != NULL)
				free(key->pin);

			key->pin = strdup(yystack.l_mark[0].string);
			if (key->pin == NULL) {
				syslog(LOG_ERR, "Could not allocate new " \
						"PIN code");
				exit(1);
			}
			}
break;
case 16:
#line 178 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/hcsecd/parser.y"
	{
			if (key->pin != NULL)
				free(key->pin);

			key->pin = NULL;
			}
break;
#line 833 "parser.c"
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
