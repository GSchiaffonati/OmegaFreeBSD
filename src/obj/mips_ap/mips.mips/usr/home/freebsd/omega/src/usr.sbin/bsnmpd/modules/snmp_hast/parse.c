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

#line 2 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
/*-
 * Copyright (c) 2009-2010 The FreeBSD Foundation
 * Copyright (c) 2011 Pawel Jakub Dawidek <pawel@dawidek.net>
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
 * $FreeBSD$
 */

#include <sys/param.h>	/* MAXHOSTNAMELEN */
#include <sys/queue.h>
#include <sys/socket.h>
#include <sys/sysctl.h>

#include <arpa/inet.h>

#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

#include <pjdlog.h>

#include "hast.h"

extern int depth;
extern int lineno;

extern FILE *yyin;
extern char *yytext;

static struct hastd_config *lconfig;
static struct hast_resource *curres;
static bool mynode, hadmynode;

static char depth0_control[HAST_ADDRSIZE];
static char depth0_pidfile[PATH_MAX];
static char depth0_listen_tcp4[HAST_ADDRSIZE];
static char depth0_listen_tcp6[HAST_ADDRSIZE];
static TAILQ_HEAD(, hastd_listen) depth0_listen;
static int depth0_replication;
static int depth0_checksum;
static int depth0_compression;
static int depth0_timeout;
static char depth0_exec[PATH_MAX];
static int depth0_metaflush;

static char depth1_provname[PATH_MAX];
static char depth1_localpath[PATH_MAX];
static int depth1_metaflush;

extern void yyerror(const char *);
extern int yylex(void);
extern void yyrestart(FILE *);

static int isitme(const char *name);
static bool family_supported(int family);
static int node_names(char **namesp);
#line 98 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
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
#line 118 "y.tab.c"

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

#define CONTROL 257
#define PIDFILE 258
#define LISTEN 259
#define REPLICATION 260
#define CHECKSUM 261
#define COMPRESSION 262
#define METAFLUSH 263
#define TIMEOUT 264
#define EXEC 265
#define RESOURCE 266
#define NAME 267
#define LOCAL 268
#define REMOTE 269
#define SOURCE 270
#define ON 271
#define OFF 272
#define FULLSYNC 273
#define MEMSYNC 274
#define ASYNC 275
#define NONE 276
#define CRC32 277
#define SHA256 278
#define HOLE 279
#define LZF 280
#define NUM 281
#define STR 282
#define OB 283
#define CB 284
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    7,    8,    9,   10,    2,    2,    2,
   11,    3,    3,    3,   12,    4,    4,    4,   13,   14,
   15,    5,    5,   16,   18,   19,   19,   20,   20,   20,
   17,   21,   22,   22,   23,   23,   23,   23,   23,   23,
   23,   23,   23,   24,   25,   26,   27,   28,   28,   29,
   29,   29,   29,   29,   30,    1,    1,   31,
};
static const YYINT yylen[] = {                            2,
    0,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    2,    2,    2,    1,    1,    1,
    2,    1,    1,    1,    2,    1,    1,    1,    2,    2,
    2,    1,    1,    5,    1,    0,    2,    1,    1,    1,
    5,    1,    0,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    2,    5,    1,    0,    2,    1,
    1,    1,    1,    1,    2,    1,    1,    2,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,   12,   13,   14,   15,   16,   18,   19,   20,
   17,   22,   23,   24,   21,   26,   27,   28,   25,   32,
   33,   31,   29,   30,   42,    0,   35,    0,   43,   36,
    0,    0,    0,    0,    0,   41,   45,   46,   47,   48,
   49,   50,   44,   51,   52,   53,   34,   38,   39,   40,
   37,   54,   55,   57,    0,   58,    0,    0,    0,   56,
   64,   60,   61,   59,   62,   63,   66,   67,   65,   68,
};
static const YYINT yydgoto[] = {                          1,
   89,   31,   35,   39,   42,   13,   14,   15,   16,   17,
   18,   19,   20,   21,   22,   23,   24,   48,   52,   71,
   46,   51,   63,   64,   65,   66,   75,   77,   84,   85,
   86,
};
static const YYINT yysindex[] = {                         0,
 -222, -268, -234, -232, -243, -231, -255, -249, -248, -230,
 -229, -228,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -227,    0, -226,    0,    0,
 -256, -257, -224, -223, -221,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -220,    0, -250, -266, -218,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,  -26,   -1,    3,    9,
   11,   14,   15,   16,  -48,    0,    0,    0,    0,    0,
    0,    0,    0,   -9,   -8,    0,    0,    0,    0,    0,
    0,
};
#define YYTABLESIZE 69
static const YYINT yytable[] = {                          2,
    3,    4,   62,    5,    6,    7,    8,    9,   10,   87,
   53,   54,    8,   25,   55,   88,   53,   54,   78,   79,
   36,   40,   41,   37,   38,   68,   67,   56,   81,   28,
   29,   30,   43,   80,    2,    3,    4,    5,    6,    7,
    8,    9,   10,   11,   32,   33,   34,   26,   12,   27,
   69,   44,   45,   47,   70,   49,   50,   72,   73,   57,
   74,   58,   76,   90,   59,   60,   61,   82,   83,
};
static const YYINT yycheck[] = {                        257,
  258,  259,   51,  260,  261,  262,  263,  264,  265,  276,
  267,  268,  263,  282,  271,  282,  267,  268,  269,  270,
  276,  271,  272,  279,  280,   52,  284,  284,   77,  273,
  274,  275,  281,  284,  257,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  276,  277,  278,  282,  271,  282,
   52,  282,  282,  282,   52,  283,  283,  282,  282,   51,
  282,   51,  283,  282,   51,   51,   51,   77,   77,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 284
#define YYUNDFTOKEN 318
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"CONTROL","PIDFILE","LISTEN",
"REPLICATION","CHECKSUM","COMPRESSION","METAFLUSH","TIMEOUT","EXEC","RESOURCE",
"NAME","LOCAL","REMOTE","SOURCE","ON","OFF","FULLSYNC","MEMSYNC","ASYNC","NONE",
"CRC32","SHA256","HOLE","LZF","NUM","STR","OB","CB",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : statements",
"statements :",
"statements : statements statement",
"statement : control_statement",
"statement : pidfile_statement",
"statement : listen_statement",
"statement : replication_statement",
"statement : checksum_statement",
"statement : compression_statement",
"statement : timeout_statement",
"statement : exec_statement",
"statement : metaflush_statement",
"statement : node_statement",
"statement : resource_statement",
"control_statement : CONTROL STR",
"pidfile_statement : PIDFILE STR",
"listen_statement : LISTEN STR",
"replication_statement : REPLICATION replication_type",
"replication_type : FULLSYNC",
"replication_type : MEMSYNC",
"replication_type : ASYNC",
"checksum_statement : CHECKSUM checksum_type",
"checksum_type : NONE",
"checksum_type : CRC32",
"checksum_type : SHA256",
"compression_statement : COMPRESSION compression_type",
"compression_type : NONE",
"compression_type : HOLE",
"compression_type : LZF",
"timeout_statement : TIMEOUT NUM",
"exec_statement : EXEC STR",
"metaflush_statement : METAFLUSH boolean",
"boolean : ON",
"boolean : OFF",
"node_statement : ON node_start OB node_entries CB",
"node_start : STR",
"node_entries :",
"node_entries : node_entries node_entry",
"node_entry : control_statement",
"node_entry : pidfile_statement",
"node_entry : listen_statement",
"resource_statement : RESOURCE resource_start OB resource_entries CB",
"resource_start : STR",
"resource_entries :",
"resource_entries : resource_entries resource_entry",
"resource_entry : replication_statement",
"resource_entry : checksum_statement",
"resource_entry : compression_statement",
"resource_entry : timeout_statement",
"resource_entry : exec_statement",
"resource_entry : metaflush_statement",
"resource_entry : name_statement",
"resource_entry : local_statement",
"resource_entry : resource_node_statement",
"name_statement : NAME STR",
"local_statement : LOCAL STR",
"resource_node_statement : ON resource_node_start OB resource_node_entries CB",
"resource_node_start : STR",
"resource_node_entries :",
"resource_node_entries : resource_node_entries resource_node_entry",
"resource_node_entry : name_statement",
"resource_node_entry : local_statement",
"resource_node_entry : remote_statement",
"resource_node_entry : source_statement",
"resource_node_entry : metaflush_statement",
"remote_statement : REMOTE remote_str",
"remote_str : NONE",
"remote_str : STR",
"source_statement : SOURCE STR",

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
#line 727 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"

static int
isitme(const char *name)
{
	char buf[MAXHOSTNAMELEN];
	unsigned long hostid;
	char *pos;
	size_t bufsize;

	/*
	 * First check if the given name matches our full hostname.
	 */
	if (gethostname(buf, sizeof(buf)) < 0) {
		pjdlog_errno(LOG_ERR, "gethostname() failed");
		return (-1);
	}
	if (strcmp(buf, name) == 0)
		return (1);

	/*
	 * Check if it matches first part of the host name.
	 */
	pos = strchr(buf, '.');
	if (pos != NULL && (size_t)(pos - buf) == strlen(name) &&
	    strncmp(buf, name, pos - buf) == 0) {
		return (1);
	}

	/*
	 * Check if it matches host UUID.
	 */
	bufsize = sizeof(buf);
	if (sysctlbyname("kern.hostuuid", buf, &bufsize, NULL, 0) < 0) {
		pjdlog_errno(LOG_ERR, "sysctlbyname(kern.hostuuid) failed");
		return (-1);
	}
	if (strcasecmp(buf, name) == 0)
		return (1);

	/*
	 * Check if it matches hostid.
	 */
	bufsize = sizeof(hostid);
	if (sysctlbyname("kern.hostid", &hostid, &bufsize, NULL, 0) < 0) {
		pjdlog_errno(LOG_ERR, "sysctlbyname(kern.hostid) failed");
		return (-1);
	}
	(void)snprintf(buf, sizeof(buf), "hostid%lu", hostid);
	if (strcmp(buf, name) == 0)
		return (1);

	/*
	 * Looks like this isn't about us.
	 */
	return (0);
}

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

static int
node_names(char **namesp)
{
	static char names[MAXHOSTNAMELEN * 3];
	char buf[MAXHOSTNAMELEN];
	unsigned long hostid;
	char *pos;
	size_t bufsize;

	if (gethostname(buf, sizeof(buf)) < 0) {
		pjdlog_errno(LOG_ERR, "gethostname() failed");
		return (-1);
	}

	/* First component of the host name. */
	pos = strchr(buf, '.');
	if (pos != NULL && pos != buf) {
		(void)strlcpy(names, buf, MIN((size_t)(pos - buf + 1),
		    sizeof(names)));
		(void)strlcat(names, ", ", sizeof(names));
	}

	/* Full host name. */
	(void)strlcat(names, buf, sizeof(names));
	(void)strlcat(names, ", ", sizeof(names));

	/* Host UUID. */
	bufsize = sizeof(buf);
	if (sysctlbyname("kern.hostuuid", buf, &bufsize, NULL, 0) < 0) {
		pjdlog_errno(LOG_ERR, "sysctlbyname(kern.hostuuid) failed");
		return (-1);
	}
	(void)strlcat(names, buf, sizeof(names));
	(void)strlcat(names, ", ", sizeof(names));

	/* Host ID. */
	bufsize = sizeof(hostid);
	if (sysctlbyname("kern.hostid", &hostid, &bufsize, NULL, 0) < 0) {
		pjdlog_errno(LOG_ERR, "sysctlbyname(kern.hostid) failed");
		return (-1);
	}
	(void)snprintf(buf, sizeof(buf), "hostid%lu", hostid);
	(void)strlcat(names, buf, sizeof(names));

	*namesp = names;

	return (0);
}

void
yyerror(const char *str)
{

	pjdlog_error("Unable to parse configuration file at line %d near '%s': %s",
	    lineno, yytext, str);
}

struct hastd_config *
yy_config_parse(const char *config, bool exitonerror)
{
	int ret;

	curres = NULL;
	mynode = false;
	depth = 0;
	lineno = 0;

	depth0_timeout = HAST_TIMEOUT;
	depth0_replication = HAST_REPLICATION_MEMSYNC;
	depth0_checksum = HAST_CHECKSUM_NONE;
	depth0_compression = HAST_COMPRESSION_HOLE;
	strlcpy(depth0_control, HAST_CONTROL, sizeof(depth0_control));
	strlcpy(depth0_pidfile, HASTD_PIDFILE, sizeof(depth0_pidfile));
	TAILQ_INIT(&depth0_listen);
	strlcpy(depth0_listen_tcp4, HASTD_LISTEN_TCP4,
	    sizeof(depth0_listen_tcp4));
	strlcpy(depth0_listen_tcp6, HASTD_LISTEN_TCP6,
	    sizeof(depth0_listen_tcp6));
	depth0_exec[0] = '\0';
	depth0_metaflush = 1;

	lconfig = calloc(1, sizeof(*lconfig));
	if (lconfig == NULL) {
		pjdlog_error("Unable to allocate memory for configuration.");
		if (exitonerror)
			exit(EX_TEMPFAIL);
		return (NULL);
	}

	TAILQ_INIT(&lconfig->hc_listen);
	TAILQ_INIT(&lconfig->hc_resources);

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
	if (lconfig->hc_controladdr[0] == '\0') {
		strlcpy(lconfig->hc_controladdr, depth0_control,
		    sizeof(lconfig->hc_controladdr));
	}
	if (lconfig->hc_pidfile[0] == '\0') {
		strlcpy(lconfig->hc_pidfile, depth0_pidfile,
		    sizeof(lconfig->hc_pidfile));
	}
	if (!TAILQ_EMPTY(&depth0_listen))
		TAILQ_CONCAT(&lconfig->hc_listen, &depth0_listen, hl_next);
	if (TAILQ_EMPTY(&lconfig->hc_listen)) {
		struct hastd_listen *lst;

		if (family_supported(AF_INET)) {
			lst = calloc(1, sizeof(*lst));
			if (lst == NULL) {
				pjdlog_error("Unable to allocate memory for listen address.");
				yy_config_free(lconfig);
				if (exitonerror)
					exit(EX_TEMPFAIL);
				return (NULL);
			}
			(void)strlcpy(lst->hl_addr, depth0_listen_tcp4,
			    sizeof(lst->hl_addr));
			TAILQ_INSERT_TAIL(&lconfig->hc_listen, lst, hl_next);
		} else {
			pjdlog_debug(1,
			    "No IPv4 support in the kernel, not listening on IPv4 address.");
		}
		if (family_supported(AF_INET6)) {
			lst = calloc(1, sizeof(*lst));
			if (lst == NULL) {
				pjdlog_error("Unable to allocate memory for listen address.");
				yy_config_free(lconfig);
				if (exitonerror)
					exit(EX_TEMPFAIL);
				return (NULL);
			}
			(void)strlcpy(lst->hl_addr, depth0_listen_tcp6,
			    sizeof(lst->hl_addr));
			TAILQ_INSERT_TAIL(&lconfig->hc_listen, lst, hl_next);
		} else {
			pjdlog_debug(1,
			    "No IPv6 support in the kernel, not listening on IPv6 address.");
		}
		if (TAILQ_EMPTY(&lconfig->hc_listen)) {
			pjdlog_error("No address to listen on.");
			yy_config_free(lconfig);
			if (exitonerror)
				exit(EX_TEMPFAIL);
			return (NULL);
		}
	}
	TAILQ_FOREACH(curres, &lconfig->hc_resources, hr_next) {
		PJDLOG_ASSERT(curres->hr_provname[0] != '\0');
		PJDLOG_ASSERT(curres->hr_localpath[0] != '\0');
		PJDLOG_ASSERT(curres->hr_remoteaddr[0] != '\0');

		if (curres->hr_replication == -1) {
			/*
			 * Replication is not set at resource-level.
			 * Use global or default setting.
			 */
			curres->hr_replication = depth0_replication;
			curres->hr_original_replication = depth0_replication;
		}
		if (curres->hr_checksum == -1) {
			/*
			 * Checksum is not set at resource-level.
			 * Use global or default setting.
			 */
			curres->hr_checksum = depth0_checksum;
		}
		if (curres->hr_compression == -1) {
			/*
			 * Compression is not set at resource-level.
			 * Use global or default setting.
			 */
			curres->hr_compression = depth0_compression;
		}
		if (curres->hr_timeout == -1) {
			/*
			 * Timeout is not set at resource-level.
			 * Use global or default setting.
			 */
			curres->hr_timeout = depth0_timeout;
		}
		if (curres->hr_exec[0] == '\0') {
			/*
			 * Exec is not set at resource-level.
			 * Use global or default setting.
			 */
			strlcpy(curres->hr_exec, depth0_exec,
			    sizeof(curres->hr_exec));
		}
		if (curres->hr_metaflush == -1) {
			/*
			 * Metaflush is not set at resource-level.
			 * Use global or default setting.
			 */
			curres->hr_metaflush = depth0_metaflush;
		}
	}

	return (lconfig);
}

void
yy_config_free(struct hastd_config *config)
{
	struct hastd_listen *lst;
	struct hast_resource *res;

	while ((lst = TAILQ_FIRST(&depth0_listen)) != NULL) {
		TAILQ_REMOVE(&depth0_listen, lst, hl_next);
		free(lst);
	}
	while ((lst = TAILQ_FIRST(&config->hc_listen)) != NULL) {
		TAILQ_REMOVE(&config->hc_listen, lst, hl_next);
		free(lst);
	}
	while ((res = TAILQ_FIRST(&config->hc_resources)) != NULL) {
		TAILQ_REMOVE(&config->hc_resources, res, hr_next);
		free(res);
	}
	free(config);
}
#line 704 "y.tab.c"

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
case 14:
#line 139 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		switch (depth) {
		case 0:
			if (strlcpy(depth0_control, yystack.l_mark[0].str,
			    sizeof(depth0_control)) >=
			    sizeof(depth0_control)) {
				pjdlog_error("control argument is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			break;
		case 1:
			if (!mynode)
				break;
			if (strlcpy(lconfig->hc_controladdr, yystack.l_mark[0].str,
			    sizeof(lconfig->hc_controladdr)) >=
			    sizeof(lconfig->hc_controladdr)) {
				pjdlog_error("control argument is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			break;
		default:
			PJDLOG_ABORT("control at wrong depth level");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 15:
#line 169 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		switch (depth) {
		case 0:
			if (strlcpy(depth0_pidfile, yystack.l_mark[0].str,
			    sizeof(depth0_pidfile)) >=
			    sizeof(depth0_pidfile)) {
				pjdlog_error("pidfile argument is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			break;
		case 1:
			if (!mynode)
				break;
			if (strlcpy(lconfig->hc_pidfile, yystack.l_mark[0].str,
			    sizeof(lconfig->hc_pidfile)) >=
			    sizeof(lconfig->hc_pidfile)) {
				pjdlog_error("pidfile argument is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			break;
		default:
			PJDLOG_ABORT("pidfile at wrong depth level");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 16:
#line 199 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		struct hastd_listen *lst;

		lst = calloc(1, sizeof(*lst));
		if (lst == NULL) {
			pjdlog_error("Unable to allocate memory for listen address.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		if (strlcpy(lst->hl_addr, yystack.l_mark[0].str, sizeof(lst->hl_addr)) >=
		    sizeof(lst->hl_addr)) {
			pjdlog_error("listen argument is too long.");
			free(yystack.l_mark[0].str);
			free(lst);
			return (1);
		}
		switch (depth) {
		case 0:
			TAILQ_INSERT_TAIL(&depth0_listen, lst, hl_next);
			break;
		case 1:
			if (mynode)
				TAILQ_INSERT_TAIL(&depth0_listen, lst, hl_next);
			else
				free(lst);
			break;
		default:
			PJDLOG_ABORT("listen at wrong depth level");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 17:
#line 233 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		switch (depth) {
		case 0:
			depth0_replication = yystack.l_mark[0].num;
			break;
		case 1:
			PJDLOG_ASSERT(curres != NULL);
			curres->hr_replication = yystack.l_mark[0].num;
			curres->hr_original_replication = yystack.l_mark[0].num;
			break;
		default:
			PJDLOG_ABORT("replication at wrong depth level");
		}
	}
break;
case 18:
#line 250 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ yyval.num = HAST_REPLICATION_FULLSYNC; }
break;
case 19:
#line 252 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ yyval.num = HAST_REPLICATION_MEMSYNC; }
break;
case 20:
#line 254 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ yyval.num = HAST_REPLICATION_ASYNC; }
break;
case 21:
#line 258 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		switch (depth) {
		case 0:
			depth0_checksum = yystack.l_mark[0].num;
			break;
		case 1:
			PJDLOG_ASSERT(curres != NULL);
			curres->hr_checksum = yystack.l_mark[0].num;
			break;
		default:
			PJDLOG_ABORT("checksum at wrong depth level");
		}
	}
break;
case 22:
#line 274 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ yyval.num = HAST_CHECKSUM_NONE; }
break;
case 23:
#line 276 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ yyval.num = HAST_CHECKSUM_CRC32; }
break;
case 24:
#line 278 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ yyval.num = HAST_CHECKSUM_SHA256; }
break;
case 25:
#line 282 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		switch (depth) {
		case 0:
			depth0_compression = yystack.l_mark[0].num;
			break;
		case 1:
			PJDLOG_ASSERT(curres != NULL);
			curres->hr_compression = yystack.l_mark[0].num;
			break;
		default:
			PJDLOG_ABORT("compression at wrong depth level");
		}
	}
break;
case 26:
#line 298 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ yyval.num = HAST_COMPRESSION_NONE; }
break;
case 27:
#line 300 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ yyval.num = HAST_COMPRESSION_HOLE; }
break;
case 28:
#line 302 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ yyval.num = HAST_COMPRESSION_LZF; }
break;
case 29:
#line 306 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		if (yystack.l_mark[0].num <= 0) {
			pjdlog_error("Negative or zero timeout.");
			return (1);
		}
		switch (depth) {
		case 0:
			depth0_timeout = yystack.l_mark[0].num;
			break;
		case 1:
			PJDLOG_ASSERT(curres != NULL);
			curres->hr_timeout = yystack.l_mark[0].num;
			break;
		default:
			PJDLOG_ABORT("timeout at wrong depth level");
		}
	}
break;
case 30:
#line 326 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		switch (depth) {
		case 0:
			if (strlcpy(depth0_exec, yystack.l_mark[0].str, sizeof(depth0_exec)) >=
			    sizeof(depth0_exec)) {
				pjdlog_error("Exec path is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			break;
		case 1:
			PJDLOG_ASSERT(curres != NULL);
			if (strlcpy(curres->hr_exec, yystack.l_mark[0].str,
			    sizeof(curres->hr_exec)) >=
			    sizeof(curres->hr_exec)) {
				pjdlog_error("Exec path is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			break;
		default:
			PJDLOG_ABORT("exec at wrong depth level");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 31:
#line 354 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		switch (depth) {
		case 0:
			depth0_metaflush = yystack.l_mark[0].num;
			break;
		case 1:
			PJDLOG_ASSERT(curres != NULL);
			depth1_metaflush = yystack.l_mark[0].num;
			break;
		case 2:
			if (!mynode)
				break;
			PJDLOG_ASSERT(curres != NULL);
			curres->hr_metaflush = yystack.l_mark[0].num;
			break;
		default:
			PJDLOG_ABORT("metaflush at wrong depth level");
		}
	}
break;
case 32:
#line 376 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ yyval.num = 1; }
break;
case 33:
#line 378 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ yyval.num = 0; }
break;
case 34:
#line 382 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		mynode = false;
	}
break;
case 35:
#line 388 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		switch (isitme(yystack.l_mark[0].str)) {
		case -1:
			free(yystack.l_mark[0].str);
			return (1);
		case 0:
			break;
		case 1:
			mynode = true;
			break;
		default:
			PJDLOG_ABORT("invalid isitme() return value");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 41:
#line 419 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		if (curres != NULL) {
			/*
			 * There must be section for this node, at least with
			 * remote address configuration.
			 */
			if (!hadmynode) {
				char *names;

				if (node_names(&names) != 0)
					return (1);
				pjdlog_error("No resource %s configuration for this node (acceptable node names: %s).",
				    curres->hr_name, names);
				return (1);
			}

			/*
			 * Let's see if there are some resource-level settings
			 * that we can use for node-level settings.
			 */
			if (curres->hr_provname[0] == '\0' &&
			    depth1_provname[0] != '\0') {
				/*
				 * Provider name is not set at node-level,
				 * but is set at resource-level, use it.
				 */
				strlcpy(curres->hr_provname, depth1_provname,
				    sizeof(curres->hr_provname));
			}
			if (curres->hr_localpath[0] == '\0' &&
			    depth1_localpath[0] != '\0') {
				/*
				 * Path to local provider is not set at
				 * node-level, but is set at resource-level,
				 * use it.
				 */
				strlcpy(curres->hr_localpath, depth1_localpath,
				    sizeof(curres->hr_localpath));
			}
			if (curres->hr_metaflush == -1 && depth1_metaflush != -1) {
				/*
				 * Metaflush is not set at node-level,
				 * but is set at resource-level, use it.
				 */
				curres->hr_metaflush = depth1_metaflush;
			}

			/*
			 * If provider name is not given, use resource name
			 * as provider name.
			 */
			if (curres->hr_provname[0] == '\0') {
				strlcpy(curres->hr_provname, curres->hr_name,
				    sizeof(curres->hr_provname));
			}

			/*
			 * Remote address has to be configured at this point.
			 */
			if (curres->hr_remoteaddr[0] == '\0') {
				pjdlog_error("Remote address not configured for resource %s.",
				    curres->hr_name);
				return (1);
			}
			/*
			 * Path to local provider has to be configured at this
			 * point.
			 */
			if (curres->hr_localpath[0] == '\0') {
				pjdlog_error("Path to local component not configured for resource %s.",
				    curres->hr_name);
				return (1);
			}

			/* Put it onto resource list. */
			TAILQ_INSERT_TAIL(&lconfig->hc_resources, curres, hr_next);
			curres = NULL;
		}
	}
break;
case 42:
#line 501 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		/* Check if there is no duplicate entry. */
		TAILQ_FOREACH(curres, &lconfig->hc_resources, hr_next) {
			if (strcmp(curres->hr_name, yystack.l_mark[0].str) == 0) {
				pjdlog_error("Resource %s configured more than once.",
				    curres->hr_name);
				free(yystack.l_mark[0].str);
				return (1);
			}
		}

		/*
		 * Clear those, so we can tell if they were set at
		 * resource-level or not.
		 */
		depth1_provname[0] = '\0';
		depth1_localpath[0] = '\0';
		depth1_metaflush = -1;
		hadmynode = false;

		curres = calloc(1, sizeof(*curres));
		if (curres == NULL) {
			pjdlog_error("Unable to allocate memory for resource.");
			free(yystack.l_mark[0].str);
			return (1);
		}
		if (strlcpy(curres->hr_name, yystack.l_mark[0].str,
		    sizeof(curres->hr_name)) >=
		    sizeof(curres->hr_name)) {
			pjdlog_error("Resource name is too long.");
			free(curres);
			free(yystack.l_mark[0].str);
			return (1);
		}
		free(yystack.l_mark[0].str);
		curres->hr_role = HAST_ROLE_INIT;
		curres->hr_previous_role = HAST_ROLE_INIT;
		curres->hr_replication = -1;
		curres->hr_original_replication = -1;
		curres->hr_checksum = -1;
		curres->hr_compression = -1;
		curres->hr_version = 1;
		curres->hr_timeout = -1;
		curres->hr_exec[0] = '\0';
		curres->hr_provname[0] = '\0';
		curres->hr_localpath[0] = '\0';
		curres->hr_localfd = -1;
		curres->hr_localflush = true;
		curres->hr_metaflush = -1;
		curres->hr_remoteaddr[0] = '\0';
		curres->hr_sourceaddr[0] = '\0';
		curres->hr_ggateunit = -1;
	}
break;
case 54:
#line 582 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		switch (depth) {
		case 1:
			if (strlcpy(depth1_provname, yystack.l_mark[0].str,
			    sizeof(depth1_provname)) >=
			    sizeof(depth1_provname)) {
				pjdlog_error("name argument is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			break;
		case 2:
			if (!mynode)
				break;
			PJDLOG_ASSERT(curres != NULL);
			if (strlcpy(curres->hr_provname, yystack.l_mark[0].str,
			    sizeof(curres->hr_provname)) >=
			    sizeof(curres->hr_provname)) {
				pjdlog_error("name argument is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			break;
		default:
			PJDLOG_ABORT("name at wrong depth level");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 55:
#line 613 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		switch (depth) {
		case 1:
			if (strlcpy(depth1_localpath, yystack.l_mark[0].str,
			    sizeof(depth1_localpath)) >=
			    sizeof(depth1_localpath)) {
				pjdlog_error("local argument is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			break;
		case 2:
			if (!mynode)
				break;
			PJDLOG_ASSERT(curres != NULL);
			if (strlcpy(curres->hr_localpath, yystack.l_mark[0].str,
			    sizeof(curres->hr_localpath)) >=
			    sizeof(curres->hr_localpath)) {
				pjdlog_error("local argument is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
			break;
		default:
			PJDLOG_ABORT("local at wrong depth level");
		}
		free(yystack.l_mark[0].str);
	}
break;
case 56:
#line 644 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		mynode = false;
	}
break;
case 57:
#line 650 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		if (curres != NULL) {
			switch (isitme(yystack.l_mark[0].str)) {
			case -1:
				free(yystack.l_mark[0].str);
				return (1);
			case 0:
				break;
			case 1:
				mynode = hadmynode = true;
				break;
			default:
				PJDLOG_ABORT("invalid isitme() return value");
			}
		}
		free(yystack.l_mark[0].str);
	}
break;
case 65:
#line 687 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		PJDLOG_ASSERT(depth == 2);
		if (mynode) {
			PJDLOG_ASSERT(curres != NULL);
			if (strlcpy(curres->hr_remoteaddr, yystack.l_mark[0].str,
			    sizeof(curres->hr_remoteaddr)) >=
			    sizeof(curres->hr_remoteaddr)) {
				pjdlog_error("remote argument is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
		}
		free(yystack.l_mark[0].str);
	}
break;
case 66:
#line 704 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ yyval.str = strdup("none"); }
break;
case 67:
#line 706 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{ }
break;
case 68:
#line 710 "/usr/home/freebsd/omega/src/usr.sbin/bsnmpd/modules/snmp_hast/../../../../sbin/hastd/parse.y"
	{
		PJDLOG_ASSERT(depth == 2);
		if (mynode) {
			PJDLOG_ASSERT(curres != NULL);
			if (strlcpy(curres->hr_sourceaddr, yystack.l_mark[0].str,
			    sizeof(curres->hr_sourceaddr)) >=
			    sizeof(curres->hr_sourceaddr)) {
				pjdlog_error("source argument is too long.");
				free(yystack.l_mark[0].str);
				return (1);
			}
		}
		free(yystack.l_mark[0].str);
	}
break;
#line 1455 "y.tab.c"
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
