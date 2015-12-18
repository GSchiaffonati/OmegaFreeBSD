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

#line 2 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
/*-
 * Copyright (c) 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Paul Borman at Krystal Technologies.
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
 */

#ifndef lint
#if 0
static char sccsid[] = "@(#)yacc.y	8.1 (Berkeley) 6/6/93";
#endif /* 0 */
#endif /* not lint */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <arpa/inet.h>

#include <ctype.h>
#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ldef.h"
#include "extern.h"
#include "runefile.h"

static void *xmalloc(unsigned int sz);
static uint32_t *xlalloc(unsigned int sz);
void yyerror(const char *s);
static uint32_t *xrelalloc(uint32_t *old, unsigned int sz);
static void dump_tables(void);
static void cleanout(void);

const char	*locale_file = "<stdout>";

rune_map	maplower = { { 0 }, NULL };
rune_map	mapupper = { { 0 }, NULL };
rune_map	types = { { 0 }, NULL };

_FileRuneLocale	new_locale = { "", "", {}, {}, {}, 0, 0, 0, 0 };
char		*variable = NULL;

void set_map(rune_map *, rune_list *, uint32_t);
void set_digitmap(rune_map *, rune_list *);
void add_map(rune_map *, rune_list *, uint32_t);
static void usage(void);
#line 79 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union	{
    int32_t	rune;
    int		i;
    char	*str;

    rune_list	*list;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 112 "y.tab.c"

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

#define RUNE 257
#define LBRK 258
#define RBRK 259
#define THRU 260
#define MAPLOWER 261
#define MAPUPPER 262
#define DIGITMAP 263
#define LIST 264
#define VARIABLE 265
#define ENCODING 266
#define INVALID 267
#define STRING 268
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    3,    3,    4,    4,    4,    4,    4,    4,
    4,    1,    1,    1,    1,    2,    2,    2,    2,
};
static const YYINT yylen[] = {                            2,
    0,    1,    1,    2,    2,    1,    2,    2,    2,    2,
    2,    1,    3,    2,    4,    4,    5,    7,    8,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    6,    0,    0,    0,    0,    3,
    0,    0,    0,    0,    0,    0,    5,    7,    4,    0,
    0,    0,    0,    0,    0,    0,   13,    0,   16,    0,
    0,    0,   15,    0,   17,    0,    0,    0,   18,    0,
   19,
};
static const YYINT yydgoto[] = {                          8,
   16,   12,    9,   10,
};
static const YYINT yysindex[] = {                      -259,
 -258, -258, -258, -248,    0, -251, -239,    0, -259,    0,
 -237, -236, -236, -236, -235, -234,    0,    0,    0, -247,
 -233, -230, -232, -238, -228, -246,    0, -227,    0,  -27,
 -225, -222,    0, -221,    0,  -26, -220, -219,    0, -218,
    0,
};
static const YYINT yyrindex[] = {                        37,
    0,    0,    0,    0,    0,    0,    0,    0,   42,    0,
    0,   19,   26,   33,    1,   40,    0,    0,    0,    0,
    0,    0,   12,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
    0,   13,    0,   34,
};
#define YYTABLESIZE 307
static const YYINT yytable[] = {                         11,
   12,    1,    2,    3,    4,    5,    6,    7,   15,   24,
   31,   14,   25,   32,   13,   14,   17,   18,    9,   20,
   29,   21,   23,   26,   22,   10,   27,   28,   30,   33,
   34,   38,   11,   35,   36,   37,    1,   40,   39,    8,
   41,    2,   19,    0,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,   12,    0,    0,
    0,   12,   12,   12,   12,   12,   12,   12,   14,    0,
    0,    0,   14,   14,   14,   14,   14,   14,   14,    9,
    9,    9,    9,    9,    9,    9,   10,   10,   10,   10,
   10,   10,   10,   11,   11,   11,   11,   11,   11,   11,
    8,    8,    8,    8,    8,    8,    8,
};
static const YYINT yycheck[] = {                        258,
    0,  261,  262,  263,  264,  265,  266,  267,  257,  257,
  257,    0,  260,  260,    2,    3,  268,  257,    0,  257,
  259,  258,  257,  257,  260,    0,  257,  260,  257,  257,
   58,   58,    0,  259,  257,  257,    0,  257,  259,    0,
  259,    0,    9,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,
   -1,  261,  262,  263,  264,  265,  266,  267,  257,   -1,
   -1,   -1,  261,  262,  263,  264,  265,  266,  267,  261,
  262,  263,  264,  265,  266,  267,  261,  262,  263,  264,
  265,  266,  267,  261,  262,  263,  264,  265,  266,  267,
  261,  262,  263,  264,  265,  266,  267,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 268
#define YYUNDFTOKEN 275
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"':'",0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"RUNE","LBRK","RBRK","THRU",
"MAPLOWER","MAPUPPER","DIGITMAP","LIST","VARIABLE","ENCODING","INVALID",
"STRING",0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : locale",
"locale :",
"locale : table",
"table : entry",
"table : table entry",
"entry : ENCODING STRING",
"entry : VARIABLE",
"entry : INVALID RUNE",
"entry : LIST list",
"entry : MAPLOWER map",
"entry : MAPUPPER map",
"entry : DIGITMAP map",
"list : RUNE",
"list : RUNE THRU RUNE",
"list : list RUNE",
"list : list RUNE THRU RUNE",
"map : LBRK RUNE RUNE RBRK",
"map : map LBRK RUNE RUNE RBRK",
"map : LBRK RUNE THRU RUNE ':' RUNE RBRK",
"map : map LBRK RUNE THRU RUNE ':' RUNE RBRK",

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
#line 209 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"

int debug;
FILE *fp;

static void
cleanout(void)
{
    if (fp != NULL)
	unlink(locale_file);
}

int
main(int ac, char *av[])
{
    int x;

    fp = stdout;

    while ((x = getopt(ac, av, "do:")) != -1) {
	switch(x) {
	case 'd':
	    debug = 1;
	    break;
	case 'o':
	    locale_file = optarg;
	    if ((fp = fopen(locale_file, "w")) == NULL)
		err(1, "%s", locale_file);
	    atexit(cleanout);
	    break;
	default:
	    usage();
	}
    }

    switch (ac - optind) {
    case 0:
	break;
    case 1:
	if (freopen(av[optind], "r", stdin) == 0)
	    err(1, "%s", av[optind]);
	break;
    default:
	usage();
    }
    for (x = 0; x < _CACHED_RUNES; ++x) {
	mapupper.map[x] = x;
	maplower.map[x] = x;
    }
    memcpy(new_locale.magic, _FILE_RUNE_MAGIC_1, sizeof(new_locale.magic));

    yyparse();

    return(0);
}

static void
usage(void)
{
    fprintf(stderr, "usage: mklocale [-d] [-o output] [source]\n");
    exit(1);
}

void
yyerror(const char *s)
{
    fprintf(stderr, "%s\n", s);
}

static void *
xmalloc(unsigned int sz)
{
    void *r = malloc(sz);
    if (!r)
	errx(1, "xmalloc");
    return(r);
}

static uint32_t *
xlalloc(unsigned int sz)
{
    uint32_t *r = (uint32_t *)malloc(sz * sizeof(uint32_t));
    if (!r)
	errx(1, "xlalloc");
    return(r);
}

static uint32_t *
xrelalloc(uint32_t *old, unsigned int sz)
{
    uint32_t *r = (uint32_t *)realloc((char *)old,
						sz * sizeof(uint32_t));
    if (!r)
	errx(1, "xrelalloc");
    return(r);
}

void
set_map(rune_map *map, rune_list *list, uint32_t flag)
{
    while (list) {
	rune_list *nlist = list->next;
	add_map(map, list, flag);
	list = nlist;
    }
}

void
set_digitmap(rune_map *map, rune_list *list)
{
    int32_t i;

    while (list) {
	rune_list *nlist = list->next;
	for (i = list->min; i <= list->max; ++i) {
	    if (list->map + (i - list->min)) {
		rune_list *tmp = (rune_list *)xmalloc(sizeof(rune_list));
		tmp->min = i;
		tmp->max = i;
		add_map(map, tmp, list->map + (i - list->min));
	    }
	}
	free(list);
	list = nlist;
    }
}

void
add_map(rune_map *map, rune_list *list, uint32_t flag)
{
    int32_t i;
    rune_list *lr = 0;
    rune_list *r;
    int32_t run;

    while (list->min < _CACHED_RUNES && list->min <= list->max) {
	if (flag)
	    map->map[list->min++] |= flag;
	else
	    map->map[list->min++] = list->map++;
    }

    if (list->min > list->max) {
	free(list);
	return;
    }

    run = list->max - list->min + 1;

    if (!(r = map->root) || (list->max < r->min - 1)
			 || (!flag && list->max == r->min - 1)) {
	if (flag) {
	    list->types = xlalloc(run);
	    for (i = 0; i < run; ++i)
		list->types[i] = flag;
	}
	list->next = map->root;
	map->root = list;
	return;
    }

    for (r = map->root; r && r->max + 1 < list->min; r = r->next)
	lr = r;

    if (!r) {
	/*
	 * We are off the end.
	 */
	if (flag) {
	    list->types = xlalloc(run);
	    for (i = 0; i < run; ++i)
		list->types[i] = flag;
	}
	list->next = 0;
	lr->next = list;
	return;
    }

    if (list->max < r->min - 1) {
	/*
	 * We come before this range and we do not intersect it.
	 * We are not before the root node, it was checked before the loop
	 */
	if (flag) {
	    list->types = xlalloc(run);
	    for (i = 0; i < run; ++i)
		list->types[i] = flag;
	}
	list->next = lr->next;
	lr->next = list;
	return;
    }

    /*
     * At this point we have found that we at least intersect with
     * the range pointed to by `r', we might intersect with one or
     * more ranges beyond `r' as well.
     */

    if (!flag && list->map - list->min != r->map - r->min) {
	/*
	 * There are only two cases when we are doing case maps and
	 * our maps needn't have the same offset.  When we are adjoining
	 * but not intersecting.
	 */
	if (list->max + 1 == r->min) {
	    lr->next = list;
	    list->next = r;
	    return;
	}
	if (list->min - 1 == r->max) {
	    list->next = r->next;
	    r->next = list;
	    return;
	}
	errx(1, "error: conflicting map entries");
    }

    if (list->min >= r->min && list->max <= r->max) {
	/*
	 * Subset case.
	 */

	if (flag) {
	    for (i = list->min; i <= list->max; ++i)
		r->types[i - r->min] |= flag;
	}
	free(list);
	return;
    }
    if (list->min <= r->min && list->max >= r->max) {
	/*
	 * Superset case.  Make him big enough to hold us.
	 * We might need to merge with the guy after him.
	 */
	if (flag) {
	    list->types = xlalloc(list->max - list->min + 1);

	    for (i = list->min; i <= list->max; ++i)
		list->types[i - list->min] = flag;

	    for (i = r->min; i <= r->max; ++i)
		list->types[i - list->min] |= r->types[i - r->min];

	    free(r->types);
	    r->types = list->types;
	} else {
	    r->map = list->map;
	}
	r->min = list->min;
	r->max = list->max;
	free(list);
    } else if (list->min < r->min) {
	/*
	 * Our tail intersects his head.
	 */
	if (flag) {
	    list->types = xlalloc(r->max - list->min + 1);

	    for (i = r->min; i <= r->max; ++i)
		list->types[i - list->min] = r->types[i - r->min];

	    for (i = list->min; i < r->min; ++i)
		list->types[i - list->min] = flag;

	    for (i = r->min; i <= list->max; ++i)
		list->types[i - list->min] |= flag;

	    free(r->types);
	    r->types = list->types;
	} else {
	    r->map = list->map;
	}
	r->min = list->min;
	free(list);
	return;
    } else {
	/*
	 * Our head intersects his tail.
	 * We might need to merge with the guy after him.
	 */
	if (flag) {
	    r->types = xrelalloc(r->types, list->max - r->min + 1);

	    for (i = list->min; i <= r->max; ++i)
		r->types[i - r->min] |= flag;

	    for (i = r->max+1; i <= list->max; ++i)
		r->types[i - r->min] = flag;
	}
	r->max = list->max;
	free(list);
    }

    /*
     * Okay, check to see if we grew into the next guy(s)
     */
    while ((lr = r->next) && r->max >= lr->min) {
	if (flag) {
	    if (r->max >= lr->max) {
		/*
		 * Good, we consumed all of him.
		 */
		for (i = lr->min; i <= lr->max; ++i)
		    r->types[i - r->min] |= lr->types[i - lr->min];
	    } else {
		/*
		 * "append" him on to the end of us.
		 */
		r->types = xrelalloc(r->types, lr->max - r->min + 1);

		for (i = lr->min; i <= r->max; ++i)
		    r->types[i - r->min] |= lr->types[i - lr->min];

		for (i = r->max+1; i <= lr->max; ++i)
		    r->types[i - r->min] = lr->types[i - lr->min];

		r->max = lr->max;
	    }
	} else {
	    if (lr->max > r->max)
		r->max = lr->max;
	}

	r->next = lr->next;

	if (flag)
	    free(lr->types);
	free(lr);
    }
}

static void
dump_tables(void)
{
    int x, first_d, curr_d;
    rune_list *list;

    /*
     * See if we can compress some of the istype arrays
     */
    for(list = types.root; list; list = list->next) {
	list->map = list->types[0];
	for (x = 1; x < list->max - list->min + 1; ++x) {
	    if ((int32_t)list->types[x] != list->map) {
		list->map = 0;
		break;
	    }
	}
    }

    first_d = curr_d = -1;
    for (x = 0; x < _CACHED_RUNES; ++x) {
	uint32_t r = types.map[x];

	if (r & _CTYPE_D) {
		if (first_d < 0)
			first_d = curr_d = x;
		else if (x != curr_d + 1)
			errx(1, "error: DIGIT range is not contiguous");
		else if (x - first_d > 9)
			errx(1, "error: DIGIT range is too big");
		else
			curr_d++;
		if (!(r & _CTYPE_X))
			errx(1,
			"error: DIGIT range is not a subset of XDIGIT range");
	}
    }
    if (first_d < 0)
	errx(1, "error: no DIGIT range defined in the single byte area");
    else if (curr_d - first_d < 9)
	errx(1, "error: DIGIT range is too small in the single byte area");

    /*
     * Fill in our tables.  Do this in network order so that
     * diverse machines have a chance of sharing data.
     * (Machines like Crays cannot share with little machines due to
     *  word size.  Sigh.  We tried.)
     */
    for (x = 0; x < _CACHED_RUNES; ++x) {
	new_locale.runetype[x] = htonl(types.map[x]);
	new_locale.maplower[x] = htonl(maplower.map[x]);
	new_locale.mapupper[x] = htonl(mapupper.map[x]);
    }

    /*
     * Count up how many ranges we will need for each of the extents.
     */
    list = types.root;

    while (list) {
	new_locale.runetype_ext_nranges++;
	list = list->next;
    }
    new_locale.runetype_ext_nranges =
         htonl(new_locale.runetype_ext_nranges);

    list = maplower.root;

    while (list) {
	new_locale.maplower_ext_nranges++;
	list = list->next;
    }
    new_locale.maplower_ext_nranges =
        htonl(new_locale.maplower_ext_nranges);

    list = mapupper.root;

    while (list) {
	new_locale.mapupper_ext_nranges++;
	list = list->next;
    }
    new_locale.mapupper_ext_nranges =
        htonl(new_locale.mapupper_ext_nranges);

    new_locale.variable_len = htonl(new_locale.variable_len);

    /*
     * Okay, we are now ready to write the new locale file.
     */

    /*
     * PART 1: The _FileRuneLocale structure
     */
    if (fwrite((char *)&new_locale, sizeof(new_locale), 1, fp) != 1) {
	perror(locale_file);
	exit(1);
    }
    /*
     * PART 2: The runetype_ext structures (not the actual tables)
     */
    list = types.root;

    while (list) {
	_FileRuneEntry re;

	re.min = htonl(list->min);
	re.max = htonl(list->max);
	re.map = htonl(list->map);

	if (fwrite((char *)&re, sizeof(re), 1, fp) != 1) {
	    perror(locale_file);
	    exit(1);
	}

        list = list->next;
    }
    /*
     * PART 3: The maplower_ext structures
     */
    list = maplower.root;

    while (list) {
	_FileRuneEntry re;

	re.min = htonl(list->min);
	re.max = htonl(list->max);
	re.map = htonl(list->map);

	if (fwrite((char *)&re, sizeof(re), 1, fp) != 1) {
	    perror(locale_file);
	    exit(1);
	}

        list = list->next;
    }
    /*
     * PART 4: The mapupper_ext structures
     */
    list = mapupper.root;

    while (list) {
	_FileRuneEntry re;

	re.min = htonl(list->min);
	re.max = htonl(list->max);
	re.map = htonl(list->map);

	if (fwrite((char *)&re, sizeof(re), 1, fp) != 1) {
	    perror(locale_file);
	    exit(1);
	}

        list = list->next;
    }
    /*
     * PART 5: The runetype_ext tables
     */
    list = types.root;

    while (list) {
	for (x = 0; x < list->max - list->min + 1; ++x)
	    list->types[x] = htonl(list->types[x]);

	if (!list->map) {
	    if (fwrite((char *)list->types,
		       (list->max - list->min + 1) * sizeof(uint32_t),
		       1, fp) != 1) {
		perror(locale_file);
		exit(1);
	    }
	}
        list = list->next;
    }
    /*
     * PART 6: And finally the variable data
     */
    if (new_locale.variable_len != 0 &&
	fwrite(variable, ntohl(new_locale.variable_len), 1, fp) != 1) {
	perror(locale_file);
	exit(1);
    }
    if (fclose(fp) != 0) {
	perror(locale_file);
	exit(1);
    }
    fp = NULL;

    if (!debug)
	return;

    if (new_locale.encoding[0])
	fprintf(stderr, "ENCODING	%s\n", new_locale.encoding);
    if (variable)
	fprintf(stderr, "VARIABLE	%s\n", variable);

    fprintf(stderr, "\nMAPLOWER:\n\n");

    for (x = 0; x < _CACHED_RUNES; ++x) {
	if (isprint(maplower.map[x]))
	    fprintf(stderr, " '%c'", (int)maplower.map[x]);
	else if (maplower.map[x])
	    fprintf(stderr, "%04x", maplower.map[x]);
	else
	    fprintf(stderr, "%4x", 0);
	if ((x & 0xf) == 0xf)
	    fprintf(stderr, "\n");
	else
	    fprintf(stderr, " ");
    }
    fprintf(stderr, "\n");

    for (list = maplower.root; list; list = list->next)
	fprintf(stderr, "\t%04x - %04x : %04x\n", list->min, list->max, list->map);

    fprintf(stderr, "\nMAPUPPER:\n\n");

    for (x = 0; x < _CACHED_RUNES; ++x) {
	if (isprint(mapupper.map[x]))
	    fprintf(stderr, " '%c'", (int)mapupper.map[x]);
	else if (mapupper.map[x])
	    fprintf(stderr, "%04x", mapupper.map[x]);
	else
	    fprintf(stderr, "%4x", 0);
	if ((x & 0xf) == 0xf)
	    fprintf(stderr, "\n");
	else
	    fprintf(stderr, " ");
    }
    fprintf(stderr, "\n");

    for (list = mapupper.root; list; list = list->next)
	fprintf(stderr, "\t%04x - %04x : %04x\n", list->min, list->max, list->map);


    fprintf(stderr, "\nTYPES:\n\n");

    for (x = 0; x < _CACHED_RUNES; ++x) {
	uint32_t r = types.map[x];

	if (r) {
	    if (isprint(x))
		fprintf(stderr, " '%c': %2d", x, (int)(r & 0xff));
	    else
		fprintf(stderr, "%04x: %2d", x, (int)(r & 0xff));

	    fprintf(stderr, " %4s", (r & _CTYPE_A) ? "alph" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_C) ? "ctrl" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_D) ? "dig" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_G) ? "graf" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_L) ? "low" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_P) ? "punc" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_S) ? "spac" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_U) ? "upp" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_X) ? "xdig" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_B) ? "blnk" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_R) ? "prnt" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_I) ? "ideo" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_T) ? "spec" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_Q) ? "phon" : "");
	    fprintf(stderr, "\n");
	}
    }

    for (list = types.root; list; list = list->next) {
	if (list->map && list->min + 3 < list->max) {
	    uint32_t r = list->map;

	    fprintf(stderr, "%04x: %2d",
		(uint32_t)list->min, (int)(r & 0xff));

	    fprintf(stderr, " %4s", (r & _CTYPE_A) ? "alph" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_C) ? "ctrl" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_D) ? "dig" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_G) ? "graf" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_L) ? "low" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_P) ? "punc" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_S) ? "spac" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_U) ? "upp" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_X) ? "xdig" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_B) ? "blnk" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_R) ? "prnt" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_I) ? "ideo" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_T) ? "spec" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_Q) ? "phon" : "");
	    fprintf(stderr, "\n...\n");

	    fprintf(stderr, "%04x: %2d",
		(uint32_t)list->max, (int)(r & 0xff));

	    fprintf(stderr, " %4s", (r & _CTYPE_A) ? "alph" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_C) ? "ctrl" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_D) ? "dig" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_G) ? "graf" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_L) ? "low" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_P) ? "punc" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_S) ? "spac" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_U) ? "upp" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_X) ? "xdig" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_B) ? "blnk" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_R) ? "prnt" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_I) ? "ideo" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_T) ? "spec" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_Q) ? "phon" : "");
	    fprintf(stderr, "\n");
	} else 
	for (x = list->min; x <= list->max; ++x) {
	    uint32_t r = ntohl(list->types[x - list->min]);

	    if (r) {
		fprintf(stderr, "%04x: %2d", x, (int)(r & 0xff));

		fprintf(stderr, " %4s", (r & _CTYPE_A) ? "alph" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_C) ? "ctrl" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_D) ? "dig" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_G) ? "graf" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_L) ? "low" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_P) ? "punc" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_S) ? "spac" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_U) ? "upp" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_X) ? "xdig" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_B) ? "blnk" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_R) ? "prnt" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_I) ? "ideo" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_T) ? "spec" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_Q) ? "phon" : "");
		fprintf(stderr, "\n");
	    }
	}
    }
}
#line 1001 "y.tab.c"

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
case 2:
#line 108 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{ dump_tables(); }
break;
case 5:
#line 116 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{ if (strcmp(yystack.l_mark[0].str, "NONE") &&
		      strcmp(yystack.l_mark[0].str, "ASCII") &&
		      strcmp(yystack.l_mark[0].str, "UTF-8") &&
		      strcmp(yystack.l_mark[0].str, "EUC") &&
		      strcmp(yystack.l_mark[0].str, "GBK") &&
		      strcmp(yystack.l_mark[0].str, "GB18030") &&
		      strcmp(yystack.l_mark[0].str, "GB2312") &&
		      strcmp(yystack.l_mark[0].str, "BIG5") &&
		      strcmp(yystack.l_mark[0].str, "MSKanji"))
			warnx("ENCODING %s is not supported by libc", yystack.l_mark[0].str);
		strncpy(new_locale.encoding, yystack.l_mark[0].str,
		    sizeof(new_locale.encoding)); }
break;
case 6:
#line 129 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{ new_locale.variable_len = strlen(yystack.l_mark[0].str) + 1;
		  variable = xmalloc(new_locale.variable_len);
		  strcpy(variable, yystack.l_mark[0].str);
		}
break;
case 7:
#line 134 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{ warnx("the INVALID keyword is deprecated"); }
break;
case 8:
#line 136 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{ set_map(&types, yystack.l_mark[0].list, yystack.l_mark[-1].i); }
break;
case 9:
#line 138 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{ set_map(&maplower, yystack.l_mark[0].list, 0); }
break;
case 10:
#line 140 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{ set_map(&mapupper, yystack.l_mark[0].list, 0); }
break;
case 11:
#line 142 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{ set_digitmap(&types, yystack.l_mark[0].list); }
break;
case 12:
#line 146 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)xmalloc(sizeof(rune_list));
		    yyval.list->min = yystack.l_mark[0].rune;
		    yyval.list->max = yystack.l_mark[0].rune;
		    yyval.list->next = 0;
		}
break;
case 13:
#line 153 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)xmalloc(sizeof(rune_list));
		    yyval.list->min = yystack.l_mark[-2].rune;
		    yyval.list->max = yystack.l_mark[0].rune;
		    yyval.list->next = 0;
		}
break;
case 14:
#line 160 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)xmalloc(sizeof(rune_list));
		    yyval.list->min = yystack.l_mark[0].rune;
		    yyval.list->max = yystack.l_mark[0].rune;
		    yyval.list->next = yystack.l_mark[-1].list;
		}
break;
case 15:
#line 167 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)xmalloc(sizeof(rune_list));
		    yyval.list->min = yystack.l_mark[-2].rune;
		    yyval.list->max = yystack.l_mark[0].rune;
		    yyval.list->next = yystack.l_mark[-3].list;
		}
break;
case 16:
#line 176 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)xmalloc(sizeof(rune_list));
		    yyval.list->min = yystack.l_mark[-2].rune;
		    yyval.list->max = yystack.l_mark[-2].rune;
		    yyval.list->map = yystack.l_mark[-1].rune;
		    yyval.list->next = 0;
		}
break;
case 17:
#line 184 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)xmalloc(sizeof(rune_list));
		    yyval.list->min = yystack.l_mark[-2].rune;
		    yyval.list->max = yystack.l_mark[-2].rune;
		    yyval.list->map = yystack.l_mark[-1].rune;
		    yyval.list->next = yystack.l_mark[-4].list;
		}
break;
case 18:
#line 192 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)xmalloc(sizeof(rune_list));
		    yyval.list->min = yystack.l_mark[-5].rune;
		    yyval.list->max = yystack.l_mark[-3].rune;
		    yyval.list->map = yystack.l_mark[-1].rune;
		    yyval.list->next = 0;
		}
break;
case 19:
#line 200 "/usr/home/freebsd/omega/src/usr.bin/mklocale/yacc.y"
	{
		    yyval.list = (rune_list *)xmalloc(sizeof(rune_list));
		    yyval.list->min = yystack.l_mark[-5].rune;
		    yyval.list->max = yystack.l_mark[-3].rune;
		    yyval.list->map = yystack.l_mark[-1].rune;
		    yyval.list->next = yystack.l_mark[-7].list;
		}
break;
#line 1325 "y.tab.c"
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
