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

#line 35 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
#include <sys/param.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <sys/queue.h>

#include <net/if.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/icmp6.h>

#include <limits.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>

#include "rrenumd.h"

struct config_is_set {
	u_short cis_dest : 1;
} cis;

struct dst_list *dl_head;
struct payload_list *pl_head, ple_cur;
u_int retry;
char errbuf[LINE_MAX];

extern int lineno;
extern void yyerror(const char *s);
extern int yylex(void);
static struct payload_list * pllist_lookup(int seqnum);
static void pllist_enqueue(struct payload_list *pl_entry);

#define MAX_RETRYNUM 10 /* upper limit of retry in this rrenumd program */
#define MAX_SEQNUM 256 /* upper limit of seqnum in this rrenumd program */
#define NOSPEC	-1

#line 75 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	u_long num;
	struct {
		char *cp;
		int len;
	} cs;
	struct in_addr addr4;
	struct in6_addr addr6;
	struct {
		struct in6_addr addr;
		u_char plen;
	} prefix;
	struct dst_list *dl;
	struct payload_list *pl;
	struct sockaddr *sa;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 84 "y.tab.c"

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

#define ADD 257
#define CHANGE 258
#define SETGLOBAL 259
#define DEBUG_CMD 260
#define DEST_CMD 261
#define RETRY_CMD 262
#define SEQNUM_CMD 263
#define MATCH_PREFIX_CMD 264
#define MAXLEN_CMD 265
#define MINLEN_CMD 266
#define USE_PREFIX_CMD 267
#define KEEPLEN_CMD 268
#define VLTIME_CMD 269
#define PLTIME_CMD 270
#define RAF_ONLINK_CMD 271
#define RAF_AUTO_CMD 272
#define RAF_DECRVALID_CMD 273
#define RAF_DECRPREFD_CMD 274
#define DAYS 275
#define HOURS 276
#define MINUTES 277
#define SECONDS 278
#define INFINITY 279
#define ON 280
#define OFF 281
#define BCL 282
#define ECL 283
#define EOS 284
#define ERROR 285
#define NAME 286
#define HOSTNAME 287
#define QSTRING 288
#define DECSTRING 289
#define IPV4ADDR 290
#define IPV6ADDR 291
#define PREFIXLEN 292
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   28,   28,   29,   29,   29,   29,   29,   29,
   30,   31,   21,   21,   22,   22,   22,   22,   23,   24,
   26,   26,    1,    1,   34,   33,    2,    2,   32,   25,
   35,    3,    3,    3,    3,   27,    4,    4,    5,    5,
    6,    6,   36,   36,   37,   37,    7,    7,    8,    8,
    9,    9,   16,   16,   17,   17,   18,   18,   19,   19,
   20,   20,   10,   10,   10,   11,   11,   12,   12,   13,
   13,   14,   14,   15,
};
static const YYINT yylen[] = {                            2,
    0,    1,    1,    2,    1,    1,    1,    1,    2,    1,
    3,    4,    1,    2,    1,    1,    2,    1,    1,    1,
    1,    1,    0,    2,    0,    8,    0,    1,    2,    2,
    5,    0,    1,    1,    1,    2,    0,    1,    0,    2,
    0,    2,    0,    4,    0,    8,    0,    2,    0,    2,
    0,    2,    0,    2,    0,    2,    0,    2,    0,    2,
    1,    1,    1,    1,    4,    0,    1,    0,    1,    0,
    1,    0,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,   33,   34,   35,    0,    0,    0,   10,    0,    0,
    0,    0,    3,    5,    6,    7,    8,    0,    9,   61,
   62,    0,   18,   19,   20,    0,   13,   15,    0,   74,
   25,   28,    0,   29,    4,    0,   30,   11,    0,    0,
   14,   21,   22,   17,    0,    0,    0,    0,   24,   12,
    0,   38,   36,    0,    0,    0,    0,    0,   40,    0,
   31,   48,    0,   44,    0,   42,    0,    0,    0,   67,
   64,   50,    0,   63,    0,    0,   26,   69,    0,   52,
    0,    0,   71,    0,   54,    0,    0,   73,   65,   56,
    0,    0,   58,    0,    0,   60,   46,
};
static const YYINT yydgoto[] = {                          9,
   40,   31,   10,   53,   55,   61,   57,   68,   76,   72,
   73,   79,   84,   89,   74,   82,   87,   92,   95,   22,
   26,   27,   28,   29,   11,   44,   47,   12,   13,   14,
   15,   16,   17,   45,   18,   37,   64,
};
static const YYINT yysindex[] = {                      -244,
 -266,    0,    0,    0, -215, -199, -265,    0,    0, -233,
 -247, -244,    0,    0,    0,    0,    0, -208,    0,    0,
    0, -197,    0,    0,    0, -252,    0,    0, -238,    0,
    0,    0, -240,    0,    0, -240,    0,    0, -265, -191,
    0,    0,    0,    0, -175, -218, -171, -160,    0,    0,
 -213,    0,    0, -265, -153, -265, -167, -166,    0, -265,
    0,    0, -152,    0, -159,    0, -253, -142, -155,    0,
    0,    0, -146,    0, -253, -140,    0,    0, -144,    0,
 -215, -138,    0, -143,    0, -215, -137,    0,    0,    0,
 -215, -136,    0, -215, -141,    0,    0,
};
static const YYINT yyrindex[] = {                         1,
    0,    0,    0,    0,    0,    0, -145,    0,    0,    0,
    0,    2,    0,    0,    0,    0,    0, -139,    0,    0,
    0,    0,    0,    0,    0, -135,    0,    0, -257,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -259, -263, -172,    0,    0,
 -125,    0,    0,    0, -256,    0, -134,    0,    0,    0,
    0,    0, -174,    0,    0,    0, -216, -194,    0,    0,
    0,    0, -202,    0, -151, -231,    0,    0, -188,    0,
    0, -210,    0, -169,    0,    0, -254,    0,    0,    0,
    0, -132,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   65,
    0,    0,    0,    0,   -7,    0,    0,    0,    0,   25,
    0,  115,    0,    0,   92,    0,  108,    0,  134,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 266
static const YYINT yytable[] = {                         32,
    1,    2,   39,   39,   16,   37,   37,   37,   37,   39,
   41,    1,    2,    3,    4,    5,    6,   19,    7,   57,
   39,   70,   37,   30,   37,   71,   16,   41,   57,   16,
   33,   49,   16,   16,   23,   30,   34,   24,   25,    8,
   53,   53,   53,    2,    3,    4,   59,   42,   62,   43,
   46,   53,   66,   66,   66,   66,   66,   66,   36,   66,
   66,   66,   55,   55,   20,   21,   66,   68,   68,   68,
   68,   68,   55,   52,   68,   68,   51,   51,   51,   51,
   68,   70,   70,   70,   70,   70,   38,   23,   51,   70,
   24,   25,   50,   54,   70,   49,   49,   49,   49,   49,
   72,   72,   72,   72,   72,   85,   51,   56,   49,   47,
   90,   47,   60,   72,   63,   93,   67,   65,   96,   66,
   66,   66,   66,   69,   66,   66,   66,   75,   77,   78,
   81,   66,   83,   86,   88,   91,   27,   94,   32,   80,
   41,   97,   58,   48,   43,   35,    0,    0,   23,   45,
   59,    0,    0,    0,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,   32,   32,
};
static const YYINT yycheck[] = {                          7,
    0,    0,  266,  267,  262,  265,  266,  267,  268,  262,
  267,  256,  257,  258,  259,  260,  261,  284,  263,  274,
  284,  275,  282,  289,  284,  279,  284,  284,  283,  287,
  264,   39,  290,  291,  287,  289,  284,  290,  291,  284,
  272,  273,  274,  257,  258,  259,   54,  286,   56,  288,
  291,  283,   60,  270,  271,  272,  273,  274,  267,  276,
  277,  278,  273,  274,  280,  281,  283,  270,  271,  272,
  273,  274,  283,  292,  277,  278,  271,  272,  273,  274,
  283,  270,  271,  272,  273,  274,  284,  287,  283,  278,
  290,  291,  284,  265,  283,  270,  271,  272,  273,  274,
  270,  271,  272,  273,  274,   81,  282,  268,  283,  282,
   86,  284,  266,  283,  282,   91,  269,  284,   94,  271,
  272,  273,  274,  283,  276,  277,  278,  270,  284,  276,
  271,  283,  277,  272,  278,  273,  282,  274,  264,   75,
   26,  283,   51,   36,  284,   12,   -1,   -1,  284,  284,
  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,  264,  264,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#define YYUNDFTOKEN 332
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ADD","CHANGE","SETGLOBAL",
"DEBUG_CMD","DEST_CMD","RETRY_CMD","SEQNUM_CMD","MATCH_PREFIX_CMD","MAXLEN_CMD",
"MINLEN_CMD","USE_PREFIX_CMD","KEEPLEN_CMD","VLTIME_CMD","PLTIME_CMD",
"RAF_ONLINK_CMD","RAF_AUTO_CMD","RAF_DECRVALID_CMD","RAF_DECRPREFD_CMD","DAYS",
"HOURS","MINUTES","SECONDS","INFINITY","ON","OFF","BCL","ECL","EOS","ERROR",
"NAME","HOSTNAME","QSTRING","DECSTRING","IPV4ADDR","IPV6ADDR","PREFIXLEN",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : config",
"config :",
"config : statements",
"statements : statement",
"statements : statements statement",
"statement : debug_statement",
"statement : destination_statement",
"statement : rrenum_statement_without_seqnum",
"statement : rrenum_statement_with_seqnum",
"statement : error EOS",
"statement : EOS",
"debug_statement : DEBUG_CMD flag EOS",
"destination_statement : DEST_CMD dest_addrs retrynum EOS",
"dest_addrs : dest_addr",
"dest_addrs : dest_addrs dest_addr",
"dest_addr : sin",
"dest_addr : sin6",
"dest_addr : sin6 ifname",
"dest_addr : HOSTNAME",
"sin : IPV4ADDR",
"sin6 : IPV6ADDR",
"ifname : NAME",
"ifname : QSTRING",
"retrynum :",
"retrynum : RETRY_CMD decstring",
"$$1 :",
"rrenum_statement_with_seqnum : SEQNUM_CMD seqnum $$1 BCL rrenum_statement EOS ECL EOS",
"seqnum :",
"seqnum : decstring",
"rrenum_statement_without_seqnum : rrenum_statement EOS",
"rrenum_statement : match_prefix_definition use_prefix_definition",
"match_prefix_definition : rrenum_cmd MATCH_PREFIX_CMD prefixval maxlen minlen",
"rrenum_cmd :",
"rrenum_cmd : ADD",
"rrenum_cmd : CHANGE",
"rrenum_cmd : SETGLOBAL",
"prefixval : IPV6ADDR prefixlen",
"prefixlen :",
"prefixlen : PREFIXLEN",
"maxlen :",
"maxlen : MAXLEN_CMD decstring",
"minlen :",
"minlen : MINLEN_CMD decstring",
"use_prefix_definition :",
"use_prefix_definition : USE_PREFIX_CMD prefixval keeplen use_prefix_values",
"use_prefix_values :",
"use_prefix_values : BCL vltime pltime raf_onlink raf_auto raf_decrvalid raf_decrprefd ECL",
"keeplen :",
"keeplen : KEEPLEN_CMD decstring",
"vltime :",
"vltime : VLTIME_CMD lifetime",
"pltime :",
"pltime : PLTIME_CMD lifetime",
"raf_onlink :",
"raf_onlink : RAF_ONLINK_CMD flag",
"raf_auto :",
"raf_auto : RAF_AUTO_CMD flag",
"raf_decrvalid :",
"raf_decrvalid : RAF_DECRVALID_CMD flag",
"raf_decrprefd :",
"raf_decrprefd : RAF_DECRPREFD_CMD flag",
"flag : ON",
"flag : OFF",
"lifetime : decstring",
"lifetime : INFINITY",
"lifetime : days hours minutes seconds",
"days :",
"days : DAYS",
"hours :",
"hours : HOURS",
"minutes :",
"minutes : MINUTES",
"seconds :",
"seconds : SECONDS",
"decstring : DECSTRING",

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
#line 646 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"

static struct payload_list *
pllist_lookup(int seqnum)
{
	struct payload_list *pl;
	for (pl = pl_head; pl && pl->pl_irr.rr_seqnum != seqnum;
	     pl = pl->pl_next)
		continue;
	return (pl);
}

static void
pllist_enqueue(struct payload_list *pl_entry)
{
	struct payload_list *pl, *pl_last;

	pl_last = NULL;
	for (pl = pl_head;
	     pl && pl->pl_irr.rr_seqnum < pl_entry->pl_irr.rr_seqnum;
	     pl_last = pl, pl = pl->pl_next)
		continue;
	if (pl_last)
		pl_last->pl_next = pl_entry;
	else
		pl_head = pl_entry;

	return;
}
#line 449 "y.tab.c"

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
case 9:
#line 133 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyerrok;
		}
break;
case 11:
#line 141 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
#ifdef YYDEBUG
			yydebug = yystack.l_mark[-1].num;
#endif /* YYDEBUG */
		}
break;
case 12:
#line 150 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			dl_head = yystack.l_mark[-2].dl;
			retry = yystack.l_mark[-1].num;
		}
break;
case 14:
#line 159 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yystack.l_mark[0].dl->dl_next = yystack.l_mark[-1].dl;
			yyval.dl = yystack.l_mark[0].dl;
		}
break;
case 15:
#line 167 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			with_v4dest = 1;
		}
break;
case 16:
#line 171 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			with_v6dest = 1;
		}
break;
case 17:
#line 175 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			struct sockaddr_in6 *sin6;

			sin6 = (struct sockaddr_in6 *)yystack.l_mark[-1].dl->dl_dst;
			sin6->sin6_scope_id = if_nametoindex(yystack.l_mark[0].cs.cp);
			with_v6dest = 1;
			yyval.dl = yystack.l_mark[-1].dl;
		}
break;
case 18:
#line 184 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			struct sockaddr_storage *ss;
			struct addrinfo hints, *res;
			int error;

			memset(&hints, 0, sizeof(hints));
			hints.ai_flags = AI_CANONNAME;
			hints.ai_family = AF_UNSPEC;
			hints.ai_socktype = SOCK_RAW;
			hints.ai_protocol = 0;
			error = getaddrinfo(yystack.l_mark[0].cs.cp, 0, &hints, &res);
			if (error) {
				snprintf(errbuf, sizeof(errbuf),
				    "name resolution failed for %s:%s",
				    yystack.l_mark[0].cs.cp, gai_strerror(error));
				yyerror(errbuf);
			}
			ss = (struct sockaddr_storage *)malloc(sizeof(*ss));
			memset(ss, 0, sizeof(*ss));
			memcpy(ss, res->ai_addr, res->ai_addr->sa_len);
			freeaddrinfo(res);

			yyval.dl = (struct dst_list *)
			     malloc(sizeof(struct dst_list));
			memset(yyval.dl, 0, sizeof(struct dst_list));
			yyval.dl->dl_dst = (struct sockaddr *)ss;
		}
break;
case 19:
#line 215 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			struct sockaddr_in *sin;

			sin = (struct sockaddr_in *)malloc(sizeof(*sin));
			memset(sin, 0, sizeof(*sin));
			sin->sin_len = sizeof(*sin);
			sin->sin_family = AF_INET;
			sin->sin_addr = yystack.l_mark[0].addr4;

			yyval.dl = (struct dst_list *)
			     malloc(sizeof(struct dst_list));
			memset(yyval.dl, 0, sizeof(struct dst_list));
			yyval.dl->dl_dst = (struct sockaddr *)sin;
		}
break;
case 20:
#line 233 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			struct sockaddr_in6 *sin6;

			sin6 = (struct sockaddr_in6 *)malloc(sizeof(*sin6));
			memset(sin6, 0, sizeof(*sin6));
			sin6->sin6_len = sizeof(*sin6);
			sin6->sin6_family = AF_INET6;
			sin6->sin6_addr = yystack.l_mark[0].addr6;

			yyval.dl = (struct dst_list *)
			     malloc(sizeof(struct dst_list));
			memset(yyval.dl, 0, sizeof(struct dst_list));
			yyval.dl->dl_dst = (struct sockaddr *)sin6;
		}
break;
case 21:
#line 250 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.cs.cp = strdup(yystack.l_mark[0].cs.cp);
			yyval.cs.len = yystack.l_mark[0].cs.len;
		}
break;
case 22:
#line 255 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yystack.l_mark[0].cs.cp[yystack.l_mark[0].cs.len - 1] = 0;
			yyval.cs.cp = strdup(&yystack.l_mark[0].cs.cp[1]);
			yyval.cs.len = yystack.l_mark[0].cs.len - 2;
		}
break;
case 23:
#line 264 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = 2;
		}
break;
case 24:
#line 268 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			if (yystack.l_mark[0].num > MAX_RETRYNUM)
				yystack.l_mark[0].num = MAX_RETRYNUM;
			yyval.num = yystack.l_mark[0].num;
		}
break;
case 25:
#line 277 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			if (pllist_lookup(yystack.l_mark[0].num)) {
				snprintf(errbuf, sizeof(errbuf),
				    "duplicate seqnum %ld specified at %d",
				    yystack.l_mark[0].num, lineno);
				yyerror(errbuf);
			}
		}
break;
case 26:
#line 286 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yystack.l_mark[-3].pl->pl_irr.rr_seqnum = yystack.l_mark[-6].num;
			pllist_enqueue(yystack.l_mark[-3].pl);
		}
break;
case 27:
#line 294 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = 0;
		}
break;
case 28:
#line 298 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			if (yystack.l_mark[0].num > MAX_SEQNUM) {
				snprintf(errbuf, sizeof(errbuf),
				    "seqnum %ld is illegal for this  program. "
				    "should be between 0 and %d",
				    yystack.l_mark[0].num, MAX_SEQNUM);
				yyerror(errbuf);
			}
			yyval.num = yystack.l_mark[0].num;
		}
break;
case 29:
#line 312 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			if (pllist_lookup(0)) {
				snprintf(errbuf, sizeof(errbuf),
				    "duplicate seqnum %d specified  at %d",
				    0, lineno);
				yyerror(errbuf);
			}
			yystack.l_mark[-1].pl->pl_irr.rr_seqnum = 0;
			pllist_enqueue(yystack.l_mark[-1].pl);
		}
break;
case 30:
#line 326 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.pl = (struct payload_list *)
			     malloc(sizeof(struct payload_list));
			memcpy(yyval.pl, &ple_cur, sizeof(ple_cur));
		}
break;
case 31:
#line 335 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			struct icmp6_router_renum *irr;
			struct rr_pco_match *rpm;

			irr = (struct icmp6_router_renum *)&ple_cur.pl_irr;
			rpm = (struct rr_pco_match *)(irr + 1);
			memset(rpm, 0, sizeof(*rpm));

			rpm->rpm_code = yystack.l_mark[-4].num;
			rpm->rpm_prefix = yystack.l_mark[-2].prefix.addr;
			rpm->rpm_matchlen = yystack.l_mark[-2].prefix.plen;
			rpm->rpm_maxlen = yystack.l_mark[-1].num;
			rpm->rpm_minlen = yystack.l_mark[0].num;
		}
break;
case 32:
#line 353 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = RPM_PCO_ADD;
		}
break;
case 36:
#line 363 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.prefix.addr = yystack.l_mark[-1].addr6;
			yyval.prefix.plen = yystack.l_mark[0].num;
		}
break;
case 37:
#line 371 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = 64;
		}
break;
case 39:
#line 379 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = 128;
		}
break;
case 40:
#line 383 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			if (yystack.l_mark[0].num > 128)
				yystack.l_mark[0].num = 128;
			yyval.num = yystack.l_mark[0].num;
		}
break;
case 41:
#line 392 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = 0;
		}
break;
case 42:
#line 396 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			if (yystack.l_mark[0].num > 128)
				yystack.l_mark[0].num = 128;
			yyval.num = yystack.l_mark[0].num;
		}
break;
case 43:
#line 405 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			struct icmp6_router_renum *irr;
			struct rr_pco_match *rpm;
			struct rr_pco_use *rpu;

			irr = (struct icmp6_router_renum *)&ple_cur.pl_irr;
			rpm = (struct rr_pco_match *)(irr + 1);
			rpu = (struct rr_pco_use *)(rpm + 1);
			memset(rpu, 0, sizeof(*rpu));
		}
break;
case 44:
#line 416 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			struct icmp6_router_renum *irr;
			struct rr_pco_match *rpm;
			struct rr_pco_use *rpu;

			irr = (struct icmp6_router_renum *)&ple_cur.pl_irr;
			rpm = (struct rr_pco_match *)(irr + 1);
			rpu = (struct rr_pco_use *)(rpm + 1);

			rpu->rpu_prefix = yystack.l_mark[-2].prefix.addr;
			rpu->rpu_uselen = yystack.l_mark[-2].prefix.plen;
			rpu->rpu_keeplen = yystack.l_mark[-1].num;
		}
break;
case 45:
#line 433 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			struct icmp6_router_renum *irr;
			struct rr_pco_match *rpm;
			struct rr_pco_use *rpu;

			irr = (struct icmp6_router_renum *)&ple_cur.pl_irr;
			rpm = (struct rr_pco_match *)(irr + 1);
			rpu = (struct rr_pco_use *)(rpm + 1);
			memset(rpu, 0, sizeof(*rpu));

			rpu->rpu_vltime = htonl(DEF_VLTIME);
			rpu->rpu_pltime = htonl(DEF_PLTIME);
			rpu->rpu_ramask = 0;
			rpu->rpu_flags = 0;
		}
break;
case 46:
#line 449 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			struct icmp6_router_renum *irr;
			struct rr_pco_match *rpm;
			struct rr_pco_use *rpu;

			irr = (struct icmp6_router_renum *)&ple_cur.pl_irr;
			rpm = (struct rr_pco_match *)(irr + 1);
			rpu = (struct rr_pco_use *)(rpm + 1);
			memset(rpu, 0, sizeof(*rpu));

			rpu->rpu_vltime = yystack.l_mark[-6].num;
			rpu->rpu_pltime = yystack.l_mark[-5].num;
			if (yystack.l_mark[-4].num == NOSPEC) {
				rpu->rpu_ramask &=
				    ~ICMP6_RR_PCOUSE_RAFLAGS_ONLINK;
			} else {
				rpu->rpu_ramask |=
				    ICMP6_RR_PCOUSE_RAFLAGS_ONLINK;
				if (yystack.l_mark[-4].num == ON) {
					rpu->rpu_raflags |=
					    ICMP6_RR_PCOUSE_RAFLAGS_ONLINK;
				} else {
					rpu->rpu_raflags &=
					    ~ICMP6_RR_PCOUSE_RAFLAGS_ONLINK;
				}
			}
			if (yystack.l_mark[-3].num == NOSPEC) {
				rpu->rpu_ramask &=
				    ICMP6_RR_PCOUSE_RAFLAGS_AUTO;
			} else {
				rpu->rpu_ramask |=
				    ICMP6_RR_PCOUSE_RAFLAGS_AUTO;
				if (yystack.l_mark[-3].num == ON) {
					rpu->rpu_raflags |=
					    ICMP6_RR_PCOUSE_RAFLAGS_AUTO;
				} else {
					rpu->rpu_raflags &=
					    ~ICMP6_RR_PCOUSE_RAFLAGS_AUTO;
				}
			}
			rpu->rpu_flags = 0;
			if (yystack.l_mark[-2].num == ON) {
				rpu->rpu_flags |=
				    ICMP6_RR_PCOUSE_FLAGS_DECRVLTIME;
			}
			if (yystack.l_mark[-1].num == ON) {
				rpu->rpu_flags |=
				    ICMP6_RR_PCOUSE_FLAGS_DECRPLTIME;
			}
		}
break;
case 47:
#line 503 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = 0;
		}
break;
case 48:
#line 507 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			if (yystack.l_mark[0].num > 128)
				yystack.l_mark[0].num = 128;
			yyval.num = yystack.l_mark[0].num;
		}
break;
case 49:
#line 517 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = htonl(DEF_VLTIME);
		}
break;
case 50:
#line 521 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = htonl(yystack.l_mark[0].num);
		}
break;
case 51:
#line 528 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = htonl(DEF_PLTIME);
		}
break;
case 52:
#line 532 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = htonl(yystack.l_mark[0].num);
		}
break;
case 53:
#line 538 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = NOSPEC;
		}
break;
case 54:
#line 542 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = yystack.l_mark[0].num;
		}
break;
case 55:
#line 549 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = NOSPEC;
		}
break;
case 56:
#line 553 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = yystack.l_mark[0].num;
		}
break;
case 57:
#line 560 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = NOSPEC;
		}
break;
case 58:
#line 564 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = yystack.l_mark[0].num;
		}
break;
case 59:
#line 571 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = NOSPEC;
		}
break;
case 60:
#line 575 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = yystack.l_mark[0].num;
		}
break;
case 61:
#line 581 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{ yyval.num = ON; }
break;
case 62:
#line 582 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{ yyval.num = OFF; }
break;
case 64:
#line 588 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = 0xffffffff;
		}
break;
case 65:
#line 592 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			int d, h, m, s;

			d = yystack.l_mark[-3].num * 24 * 60 * 60;
			h = yystack.l_mark[-2].num * 60 * 60;
			m = yystack.l_mark[-1].num * 60;
			s = yystack.l_mark[0].num;
			yyval.num = d + h + m + s;
		}
break;
case 66:
#line 605 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = 0;
		}
break;
case 68:
#line 613 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = 0;
		}
break;
case 70:
#line 621 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = 0;
		}
break;
case 72:
#line 629 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			yyval.num = 0;
		}
break;
case 74:
#line 637 "/usr/home/freebsd/omega/src/usr.sbin/rrenumd/parser.y"
	{
			int dval;

			dval = atoi(yystack.l_mark[0].cs.cp);
			yyval.num = dval;
		}
break;
#line 1162 "y.tab.c"
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
