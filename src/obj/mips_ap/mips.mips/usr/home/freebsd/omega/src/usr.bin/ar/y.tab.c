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

#line 2 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
/*-
 * Copyright (c) 2008 Kai Wang
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer
 *    in this position and unchanged.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/mman.h>
#include <sys/param.h>
#include <sys/queue.h>
#include <sys/stat.h>
#include <archive.h>
#include <archive_entry.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

#include "ar.h"

#define TEMPLATE "arscp.XXXXXXXX"

struct list {
	char		*str;
	struct list	*next;
};


extern int	yylex(void);

static void	yyerror(const char *);
static void	arscp_addlib(char *archive, struct list *list);
static void	arscp_addmod(struct list *list);
static void	arscp_clear(void);
static int	arscp_copy(int ifd, int ofd);
static void	arscp_create(char *in, char *out);
static void	arscp_delete(struct list *list);
static void	arscp_dir(char *archive, struct list *list, char *rlt);
static void	arscp_end(int eval);
static void	arscp_extract(struct list *list);
static void	arscp_free_argv(void);
static void	arscp_free_mlist(struct list *list);
static void	arscp_list(void);
static struct list *arscp_mlist(struct list *list, char *str);
static void	arscp_mlist2argv(struct list *list);
static int	arscp_mlist_len(struct list *list);
static void	arscp_open(char *fname);
static void	arscp_prompt(void);
static void	arscp_replace(struct list *list);
static void	arscp_save(void);
static int	arscp_target_exist(void);

extern int		 lineno;

static struct bsdar	*bsdar;
static char		*target;
static char		*tmpac;
static int		 interactive;
static int		 verbose;

#line 110 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char		*str;
	struct list	*list;
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

#define ADDLIB 257
#define ADDMOD 258
#define CLEAR 259
#define CREATE 260
#define DELETE 261
#define DIRECTORY 262
#define END 263
#define EXTRACT 264
#define LIST 265
#define OPEN 266
#define REPLACE 267
#define VERBOSE 268
#define SAVE 269
#define LP 270
#define RP 271
#define COMMA 272
#define EOL 273
#define FNAME 274
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    3,    0,    2,    2,    1,    1,    5,    5,    4,    4,
    6,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    8,    8,    9,
   10,   11,   12,   13,   13,   13,   14,   15,   16,   17,
   18,   20,   19,   22,   21,
};
static const YYINT yylen[] = {                            2,
    0,    2,    1,    0,    1,    3,    1,    0,    1,    2,
    2,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    5,    2,    2,
    1,    2,    2,    2,    5,    6,    1,    2,    1,    2,
    2,    1,    1,    0,    1,
};
static const YYINT yydefred[] = {                         1,
    0,    0,   27,    0,    0,   31,    0,    0,    0,   37,
    0,   39,    0,    0,   43,   42,   45,    2,    0,    9,
    0,   12,   13,   14,   15,   16,   17,   18,   19,   20,
   21,   22,   23,   24,   25,   26,    0,    5,    0,   32,
    0,    0,    0,   40,    0,   10,   11,    0,    7,    0,
    0,    0,    6,    0,   28,    0,   36,
};
static const YYINT yydgoto[] = {                          1,
   39,   18,    2,   19,   50,   20,   21,   22,   23,   24,
   25,   26,   27,   28,   29,   30,   31,   32,   33,   34,
   35,   36,
};
static const YYINT yysindex[] = {                         0,
    0, -249,    0, -251, -240,    0, -239, -240, -238,    0,
 -240,    0, -237, -240,    0,    0,    0,    0, -249,    0,
 -235,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -246,    0, -233,    0,
 -233, -229, -233,    0, -233,    0,    0, -240,    0, -232,
 -240, -267,    0, -250,    0, -230,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    2,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -228,    0, -247,    0,
 -245, -227, -243,    0, -241,    0,    0,    0,    0,    0,
    0, -226,    0, -226,    0, -224,    0,
};
static const YYINT yygindex[] = {                         0,
   -8,    0,    0,    0,    0,   28,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
#define YYTABLESIZE 275
static const YYINT yytable[] = {                         41,
    4,    3,   43,   55,   49,   45,    3,    4,    5,    6,
    7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
   56,   49,   37,   48,   17,   30,    8,   33,    8,   38,
    8,   41,    8,   38,   40,   42,   44,   47,   49,   52,
   51,   53,   54,   57,   29,   34,   46,    8,   35,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   44,   44,
};
static const YYINT yycheck[] = {                          8,
    0,    0,   11,  271,  272,   14,  256,  257,  258,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  269,
  271,  272,  274,  270,  274,  273,  274,  273,  274,  273,
  274,  273,  274,  274,  274,  274,  274,  273,  272,   48,
  270,  274,   51,  274,  273,  273,   19,  274,  273,   -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  273,  273,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 274
#define YYUNDFTOKEN 299
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ADDLIB","ADDMOD","CLEAR",
"CREATE","DELETE","DIRECTORY","END","EXTRACT","LIST","OPEN","REPLACE","VERBOSE",
"SAVE","LP","RP","COMMA","EOL","FNAME",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : begin",
"$$1 :",
"begin : $$1 ar_script",
"ar_script : cmd_list",
"ar_script :",
"mod_list : FNAME",
"mod_list : mod_list separator FNAME",
"separator : COMMA",
"separator :",
"cmd_list : rawcmd",
"cmd_list : cmd_list rawcmd",
"rawcmd : cmd EOL",
"cmd : addlib_cmd",
"cmd : addmod_cmd",
"cmd : clear_cmd",
"cmd : create_cmd",
"cmd : delete_cmd",
"cmd : directory_cmd",
"cmd : end_cmd",
"cmd : extract_cmd",
"cmd : list_cmd",
"cmd : open_cmd",
"cmd : replace_cmd",
"cmd : verbose_cmd",
"cmd : save_cmd",
"cmd : invalid_cmd",
"cmd : empty_cmd",
"cmd : error",
"addlib_cmd : ADDLIB FNAME LP mod_list RP",
"addlib_cmd : ADDLIB FNAME",
"addmod_cmd : ADDMOD mod_list",
"clear_cmd : CLEAR",
"create_cmd : CREATE FNAME",
"delete_cmd : DELETE mod_list",
"directory_cmd : DIRECTORY FNAME",
"directory_cmd : DIRECTORY FNAME LP mod_list RP",
"directory_cmd : DIRECTORY FNAME LP mod_list RP FNAME",
"end_cmd : END",
"extract_cmd : EXTRACT mod_list",
"list_cmd : LIST",
"open_cmd : OPEN FNAME",
"replace_cmd : REPLACE mod_list",
"save_cmd : SAVE",
"verbose_cmd : VERBOSE",
"empty_cmd :",
"invalid_cmd : FNAME",

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
#line 228 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"

/* ARGSUSED */
static void
yyerror(const char *s)
{

	(void) s;
	printf("Syntax error in archive script, line %d\n", lineno);
}

/*
 * arscp_open first open an archive and check its validity. If the archive
 * format is valid, it calls arscp_create to create a temporary copy of
 * the archive.
 */
static void
arscp_open(char *fname)
{
	struct archive		*a;
	struct archive_entry	*entry;
	int			 r;

	if ((a = archive_read_new()) == NULL)
		bsdar_errc(bsdar, EX_SOFTWARE, 0, "archive_read_new failed");
	archive_read_support_format_ar(a);
	AC(archive_read_open_filename(a, fname, DEF_BLKSZ));
	if ((r = archive_read_next_header(a, &entry)))
		bsdar_warnc(bsdar, 0, "%s", archive_error_string(a));
	AC(archive_read_close(a));
	AC(archive_read_free(a));
	if (r != ARCHIVE_OK)
		return;
	arscp_create(fname, fname);
}

/*
 * Create archive. in != NULL indicate it's a OPEN cmd, and resulting
 * archive is based on modification of an existing one. If in == NULL,
 * we are in CREATE cmd and a new empty archive will be created.
 */
static void
arscp_create(char *in, char *out)
{
	struct archive		*a;
	int			 ifd, ofd;

	/* Delete previously created temporary archive, if any. */
	if (tmpac) {
		if (unlink(tmpac) < 0)
			bsdar_errc(bsdar, EX_IOERR, errno, "unlink failed");
		free(tmpac);
	}

	tmpac = strdup(TEMPLATE);
	if (tmpac == NULL)
		bsdar_errc(bsdar, EX_SOFTWARE, errno, "strdup failed");
	if ((ofd = mkstemp(tmpac)) < 0)
		bsdar_errc(bsdar, EX_IOERR, errno, "mkstemp failed");

	if (in) {
		/*
		 * Command OPEN creates a temporary copy of the
		 * input archive.
		 */
		if ((ifd = open(in, O_RDONLY)) < 0) {
			bsdar_warnc(bsdar, errno, "open failed");
			return;
		}
		if (arscp_copy(ifd, ofd)) {
			bsdar_warnc(bsdar, 0, "arscp_copy failed");
			return;
		}
		close(ifd);
		close(ofd);
	} else {
		/*
		 * Command CREATE creates an "empty" archive.
		 * (archive with only global header)
		 */
		if ((a = archive_write_new()) == NULL)
			bsdar_errc(bsdar, EX_SOFTWARE, 0,
			    "archive_write_new failed");
		archive_write_set_format_ar_svr4(a);
		AC(archive_write_open_fd(a, ofd));
		AC(archive_write_close(a));
		AC(archive_write_free(a));
	}

	/* Override previous target, if any. */
	if (target)
		free(target);

	target = out;
	bsdar->filename = tmpac;
}

/* A file copying implementation using mmap. */
static int
arscp_copy(int ifd, int ofd)
{
	struct stat		 sb;
	char			*buf, *p;
	ssize_t			 w;
	size_t			 bytes;

	if (fstat(ifd, &sb) < 0) {
		bsdar_warnc(bsdar, errno, "fstate failed");
		return (1);
	}
	if ((p = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, ifd,
	    (off_t)0)) == MAP_FAILED) {
		bsdar_warnc(bsdar, errno, "mmap failed");
		return (1);
	}
	for (buf = p, bytes = sb.st_size; bytes > 0; bytes -= w) {
		w = write(ofd, buf, bytes);
		if (w <= 0) {
			bsdar_warnc(bsdar, errno, "write failed");
			break;
		}
	}
	if (munmap(p, sb.st_size) < 0)
		bsdar_errc(bsdar, EX_SOFTWARE, errno, "munmap failed");
	if (bytes > 0)
		return (1);

	return (0);
}

/*
 * Add all modules of archive to current archive, if list != NULL,
 * only those modules specified in 'list' will be added.
 */
static void
arscp_addlib(char *archive, struct list *list)
{

	if (!arscp_target_exist())
		return;
	arscp_mlist2argv(list);
	bsdar->addlib = archive;
	ar_mode_A(bsdar);
	arscp_free_argv();
	arscp_free_mlist(list);
}

/* Add modules into current archive. */
static void
arscp_addmod(struct list *list)
{

	if (!arscp_target_exist())
		return;
	arscp_mlist2argv(list);
	ar_mode_q(bsdar);
	arscp_free_argv();
	arscp_free_mlist(list);
}

/* Delete modules from current archive. */
static void
arscp_delete(struct list *list)
{

	if (!arscp_target_exist())
		return;
	arscp_mlist2argv(list);
	ar_mode_d(bsdar);
	arscp_free_argv();
	arscp_free_mlist(list);
}

/* Extract modules from current archive. */
static void
arscp_extract(struct list *list)
{

	if (!arscp_target_exist())
		return;
	arscp_mlist2argv(list);
	ar_mode_x(bsdar);
	arscp_free_argv();
	arscp_free_mlist(list);
}

/* List modules of archive. (Simple Mode) */
static void
arscp_list(void)
{

	if (!arscp_target_exist())
		return;
	bsdar->argc = 0;
	bsdar->argv = NULL;
	/* Always verbose. */
	bsdar->options |= AR_V;
	ar_mode_t(bsdar);
	bsdar->options &= ~AR_V;
}

/* List modules of archive. (Advance Mode) */
static void
arscp_dir(char *archive, struct list *list, char *rlt)
{
	FILE	*out;

	/* If rlt != NULL, redirect output to it */
	out = NULL;
	if (rlt) {
		out = stdout;
		if ((stdout = fopen(rlt, "w")) == NULL)
			bsdar_errc(bsdar, EX_IOERR, errno,
			    "fopen %s failed", rlt);
	}

	bsdar->filename = archive;
	if (list)
		arscp_mlist2argv(list);
	else {
		bsdar->argc = 0;
		bsdar->argv = NULL;
	}
	if (verbose)
		bsdar->options |= AR_V;
	ar_mode_t(bsdar);
	bsdar->options &= ~AR_V;

	if (rlt) {
		if (fclose(stdout) == EOF)
			bsdar_errc(bsdar, EX_IOERR, errno,
			    "fclose %s failed", rlt);
		stdout = out;
		free(rlt);
	}
	free(archive);
	bsdar->filename = tmpac;
	arscp_free_argv();
	arscp_free_mlist(list);
}


/* Replace modules of current archive. */
static void
arscp_replace(struct list *list)
{

	if (!arscp_target_exist())
		return;
	arscp_mlist2argv(list);
	ar_mode_r(bsdar);
	arscp_free_argv();
	arscp_free_mlist(list);
}

/* Rename the temporary archive to the target archive. */
static void
arscp_save(void)
{
	mode_t mask;

	if (target) {
		if (rename(tmpac, target) < 0)
			bsdar_errc(bsdar, EX_IOERR, errno, "rename failed");
		/*
		 * mkstemp creates temp files with mode 0600, here we
		 * set target archive mode per process umask.
		 */
		mask = umask(0);
		umask(mask);
		if (chmod(target, 0666 & ~mask) < 0)
			bsdar_errc(bsdar, EX_IOERR, errno, "chmod failed");
		free(tmpac);
		free(target);
		tmpac = NULL;
		target= NULL;
		bsdar->filename = NULL;
	} else
		bsdar_warnc(bsdar, 0, "no open output archive");
}

/*
 * Discard all the contents of current archive. This is achieved by
 * invoking CREATE cmd on current archive.
 */
static void
arscp_clear(void)
{
	char		*new_target;

	if (target) {
		new_target = strdup(target);
		if (new_target == NULL)
			bsdar_errc(bsdar, EX_SOFTWARE, errno, "strdup failed");
		arscp_create(NULL, new_target);
	}
}

/*
 * Quit ar(1). Note that END cmd will not SAVE current archive
 * before exit.
 */
static void
arscp_end(int eval)
{

	if (target)
		free(target);
	if (tmpac) {
		if (unlink(tmpac) == -1)
			bsdar_errc(bsdar, EX_IOERR, errno, "unlink %s failed",
			    tmpac);
		free(tmpac);
	}

	exit(eval);
}

/*
 * Check if target specified, i.e, whether OPEN or CREATE has been
 * issued by user.
 */
static int
arscp_target_exist(void)
{

	if (target)
		return (1);

	bsdar_warnc(bsdar, 0, "no open output archive");
	return (0);
}

/* Construct module list. */
static struct list *
arscp_mlist(struct list *list, char *str)
{
	struct list *l;

	l = malloc(sizeof(*l));
	if (l == NULL)
		bsdar_errc(bsdar, EX_SOFTWARE, errno, "malloc failed");
	l->str = str;
	l->next = list;

	return (l);
}

/* Calculate the length of a mlist. */
static int
arscp_mlist_len(struct list *list)
{
	int len;

	for(len = 0; list; list = list->next)
		len++;

	return (len);
}

/* Free the space allocated for mod_list. */
static void
arscp_free_mlist(struct list *list)
{
	struct list *l;

	/* Note that list->str was freed in arscp_free_argv. */
	for(; list; list = l) {
		l = list->next;
		free(list);
	}
}

/* Convert mlist to argv array. */
static void
arscp_mlist2argv(struct list *list)
{
	char	**argv;
	int	  i, n;

	n = arscp_mlist_len(list);
	argv = malloc(n * sizeof(*argv));
	if (argv == NULL)
		bsdar_errc(bsdar, EX_SOFTWARE, errno, "malloc failed");

	/* Note that module names are stored in reverse order in mlist. */
	for(i = n - 1; i >= 0; i--, list = list->next) {
		if (list == NULL)
			bsdar_errc(bsdar, EX_SOFTWARE, errno, "invalid mlist");
		argv[i] = list->str;
	}

	bsdar->argc = n;
	bsdar->argv = argv;
}

/* Free space allocated for argv array and its elements. */
static void
arscp_free_argv(void)
{
	int i;

	for(i = 0; i < bsdar->argc; i++)
		free(bsdar->argv[i]);

	free(bsdar->argv);
}

/* Show a prompt if we are in interactive mode */
static void
arscp_prompt(void)
{

	if (interactive) {
		printf("AR >");
		fflush(stdout);
	}
}

/* Main function for ar script mode. */
void
ar_mode_script(struct bsdar *ar)
{

	bsdar = ar;
	interactive = isatty(fileno(stdin));
	while(yyparse()) {
		if (!interactive)
			arscp_end(1);
	}

	/* Script ends without END */
	arscp_end(EX_OK);
}
#line 821 "y.tab.c"

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
#line 118 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_prompt(); }
break;
case 5:
#line 127 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ yyval.list = arscp_mlist(NULL, yystack.l_mark[0].str); }
break;
case 6:
#line 128 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ yyval.list = arscp_mlist(yystack.l_mark[-2].list, yystack.l_mark[0].str); }
break;
case 11:
#line 142 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_prompt(); }
break;
case 28:
#line 165 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_addlib(yystack.l_mark[-3].str, yystack.l_mark[-1].list); }
break;
case 29:
#line 166 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_addlib(yystack.l_mark[0].str, NULL); }
break;
case 30:
#line 170 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_addmod(yystack.l_mark[0].list); }
break;
case 31:
#line 174 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_clear(); }
break;
case 32:
#line 178 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_create(NULL, yystack.l_mark[0].str); }
break;
case 33:
#line 182 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_delete(yystack.l_mark[0].list); }
break;
case 34:
#line 186 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_dir(yystack.l_mark[0].str, NULL, NULL); }
break;
case 35:
#line 187 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_dir(yystack.l_mark[-3].str, yystack.l_mark[-1].list, NULL); }
break;
case 36:
#line 188 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_dir(yystack.l_mark[-4].str, yystack.l_mark[-2].list, yystack.l_mark[0].str); }
break;
case 37:
#line 192 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_end(EX_OK); }
break;
case 38:
#line 196 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_extract(yystack.l_mark[0].list); }
break;
case 39:
#line 200 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_list(); }
break;
case 40:
#line 204 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_open(yystack.l_mark[0].str); }
break;
case 41:
#line 208 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_replace(yystack.l_mark[0].list); }
break;
case 42:
#line 212 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ arscp_save(); }
break;
case 43:
#line 216 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ verbose = !verbose; }
break;
case 45:
#line 224 "/usr/home/freebsd/omega/src/usr.bin/ar/acpyacc.y"
	{ yyerror(NULL); }
break;
#line 1107 "y.tab.c"
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
