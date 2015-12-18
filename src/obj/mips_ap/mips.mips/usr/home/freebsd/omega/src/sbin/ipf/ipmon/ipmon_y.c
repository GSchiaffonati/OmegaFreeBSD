/* original parser id follows */
/* ipmon_yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20141006

#define YYEMPTY        (-1)
#define ipmon_yyclearin      (ipmon_yychar = YYEMPTY)
#define ipmon_yyerrok        (ipmon_yyerrflag = 0)
#define YYRECOVERING() (ipmon_yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "ipmon_yy"

#define YYPURE 0

#line 9 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
#include "ipf.h"
#include <syslog.h>
#undef	OPT_NAT
#undef	OPT_VERBOSE
#include "ipmon_l.h"
#include "ipmon.h"

#include <dlfcn.h>

#define	YYDEBUG	1

extern	void	ipmon_yyerror __P((char *));
extern	int	ipmon_yyparse __P((void));
extern	int	ipmon_yylex __P((void));
extern	int	ipmon_yydebug;
extern	FILE	*ipmon_yyin;
extern	int	ipmon_yylineNum;
extern	int	ipmonopts;

typedef	struct	opt_s	{
	struct	opt_s	*o_next;
	int		o_line;
	int		o_type;
	int		o_num;
	char		*o_str;
	struct in_addr	o_ip;
	int		o_logfac;
	int		o_logpri;
} opt_t;

static	void	build_action __P((opt_t *, ipmon_doing_t *));
static	opt_t	*new_opt __P((int));
static	void	free_action __P((ipmon_action_t *));
static	void	print_action __P((ipmon_action_t *));
static	int	find_doing __P((char *));
static	ipmon_doing_t *build_doing __P((char *, char *));
static	void	print_match __P((ipmon_action_t *));
static	int	install_saver __P((char *, char *));

static	ipmon_action_t	*alist = NULL;

ipmon_saver_int_t	*saverlist = NULL;
#line 53 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union	{
	char	*str;
	u_32_t	num;
	struct in_addr	addr;
	struct opt_s	*opt;
	union	i6addr	ip6;
	struct ipmon_doing_s	*ipmd;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 80 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() ipmon_yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() ipmon_yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() ipmon_yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() ipmon_yylex(void *YYLEX_PARAM)
# define YYLEX ipmon_yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() ipmon_yylex(void)
# define YYLEX ipmon_yylex()
#endif

/* Parameters sent to ipmon_yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() ipmon_yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) ipmon_yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define YY_NUMBER 257
#define YY_HEX 258
#define YY_STR 259
#define YY_IPV6 260
#define YY_COMMENT 261
#define YY_CMP_EQ 262
#define YY_CMP_NE 263
#define YY_CMP_LE 264
#define YY_CMP_GE 265
#define YY_CMP_LT 266
#define YY_CMP_GT 267
#define YY_RANGE_OUT 268
#define YY_RANGE_IN 269
#define IPM_MATCH 270
#define IPM_BODY 271
#define IPM_COMMENT 272
#define IPM_DIRECTION 273
#define IPM_DSTIP 274
#define IPM_DSTPORT 275
#define IPM_EVERY 276
#define IPM_GROUP 277
#define IPM_INTERFACE 278
#define IPM_IN 279
#define IPM_NO 280
#define IPM_OUT 281
#define IPM_LOADACTION 282
#define IPM_PACKET 283
#define IPM_PACKETS 284
#define IPM_POOL 285
#define IPM_PROTOCOL 286
#define IPM_RESULT 287
#define IPM_RULE 288
#define IPM_SECOND 289
#define IPM_SECONDS 290
#define IPM_SRCIP 291
#define IPM_SRCPORT 292
#define IPM_LOGTAG 293
#define IPM_WITH 294
#define IPM_DO 295
#define IPM_DOING 296
#define IPM_TYPE 297
#define IPM_NAT 298
#define IPM_STATE 299
#define IPM_NATTAG 300
#define IPM_IPF 301
#define YYERRCODE 256
typedef int YYINT;
static const YYINT ipmon_yylhs[] = {                           -1,
    0,    0,   21,   21,   21,   21,   22,   22,   23,   24,
   14,   14,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   20,   20,   25,   19,
   19,    2,    2,    3,    4,    4,    5,    5,    5,    5,
    6,    6,    7,   13,   16,    8,    8,    9,   10,   11,
   12,   12,   17,   18,   18,   18,    1,
};
static const YYINT ipmon_yylen[] = {                            2,
    1,    2,    2,    2,    1,    1,   10,    3,    3,    1,
    1,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    3,    0,    5,
    1,    3,    3,    5,    3,    3,    2,    3,    2,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    5,
    3,    3,    3,    1,    1,    1,    7,
};
static const YYINT ipmon_yydefred[] = {                         0,
    0,    6,    0,    5,    0,    0,    1,    0,    0,   10,
    0,    0,    0,    2,    3,    4,    9,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   13,   14,   15,   16,   17,   18,   19,   20,   21,
   22,   23,   24,    0,    0,   25,   26,    8,    0,    0,
    0,    0,   39,   37,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   32,   33,    0,    0,
   35,   36,   40,   38,   41,   42,   43,   46,   47,   48,
   49,    0,   51,   52,   44,   55,   56,   54,   53,   45,
    0,   12,    0,    0,    0,    0,    0,   34,   50,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   28,    7,   57,    0,   30,
};
static const YYINT ipmon_yydgoto[] = {                          6,
   70,   32,   33,   34,   35,   36,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,   89,  103,  104,
    7,    8,    9,   11,  106,
};
static const YYINT ipmon_yysindex[] = {                      -248,
  -51,    0, -105,    0, -230, -248,    0,  -16,  -15,    0,
 -214, -272, -213,    0,    0,    0,    0,  -14,  -13,  -12,
 -257,  -11,  -10,   -9,   -8,   -7,   -6,   -5,   -4,   -3,
   -2,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    1,   17,    0,    0,    0, -244, -195,
 -250, -267,    0,    0, -221, -196, -218, -194, -193, -195,
 -217, -191, -268, -192,  -57, -272,    0,    0,   23,   24,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   25,    0,    0,    0,    0,    0,    0,    0,    0,
 -225,    0, -184, -183, -182,  -47,   31,    0,    0, -181,
 -178,    0,   36,   22,   37,   42, -181,  -41, -172, -173,
    0,    0,    0,   46,    0,
};
static const YYINT ipmon_yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   29,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -32,   30,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT ipmon_yygindex[] = {                         0,
   32,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   27,    0,    0,    0,    0,    0,  -17,
   85,    0,    0,    0,    0,
};
#define YYTABLESIZE 93
static const YYINT ipmon_yytable[] = {                         52,
   18,   19,   20,   21,   22,   23,   71,   29,   72,   10,
    1,   31,    2,   24,   25,   26,   73,   12,   27,   28,
   29,    3,   74,    4,   30,   53,   31,   31,   13,   86,
   87,   54,   88,    5,   67,   75,   68,   76,   78,   83,
   79,   84,   15,   16,   17,   48,   49,   50,   51,   55,
   56,   57,   58,   59,   60,   61,   62,   63,   64,   65,
   66,   69,   77,   81,   80,   85,   90,   91,   93,   96,
   94,   95,   97,   98,   99,  100,  101,  102,  105,  107,
  108,  110,  109,  112,  113,  114,  115,   11,   27,  111,
   14,   82,   92,
};
static const YYINT ipmon_yycheck[] = {                        257,
  273,  274,  275,  276,  277,  278,  257,   40,  259,   61,
  259,   44,  261,  286,  287,  288,  284,  123,  291,  292,
  293,  270,  290,  272,  297,  283,   59,  300,  259,  298,
  299,  289,  301,  282,  279,  257,  281,  259,  257,  257,
  259,  259,   59,   59,  259,  259,   61,   61,   61,   61,
   61,   61,   61,   61,   61,   61,   61,   61,   61,   59,
   44,  257,  259,  257,  259,  257,  259,  125,   46,  295,
   47,   47,  257,  257,  257,  123,   46,  259,  257,   44,
   59,   40,   46,  125,  257,  259,   41,   59,   59,  107,
    6,   60,   66,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 301
#define YYUNDFTOKEN 329
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const ipmon_yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,"'.'","'/'",0,0,0,0,0,0,0,0,0,0,0,"';'",0,
"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"YY_NUMBER","YY_HEX","YY_STR","YY_IPV6","YY_COMMENT","YY_CMP_EQ",
"YY_CMP_NE","YY_CMP_LE","YY_CMP_GE","YY_CMP_LT","YY_CMP_GT","YY_RANGE_OUT",
"YY_RANGE_IN","IPM_MATCH","IPM_BODY","IPM_COMMENT","IPM_DIRECTION","IPM_DSTIP",
"IPM_DSTPORT","IPM_EVERY","IPM_GROUP","IPM_INTERFACE","IPM_IN","IPM_NO",
"IPM_OUT","IPM_LOADACTION","IPM_PACKET","IPM_PACKETS","IPM_POOL","IPM_PROTOCOL",
"IPM_RESULT","IPM_RULE","IPM_SECOND","IPM_SECONDS","IPM_SRCIP","IPM_SRCPORT",
"IPM_LOGTAG","IPM_WITH","IPM_DO","IPM_DOING","IPM_TYPE","IPM_NAT","IPM_STATE",
"IPM_NATTAG","IPM_IPF",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const ipmon_yyrule[] = {
"$accept : file",
"file : action",
"file : file action",
"action : line ';'",
"action : assign ';'",
"action : IPM_COMMENT",
"action : YY_COMMENT",
"line : IPM_MATCH '{' matching ';' '}' IPM_DO '{' doing ';' '}'",
"line : IPM_LOADACTION YY_STR YY_STR",
"assign : YY_STR assigning YY_STR",
"assigning : '='",
"matching : matchopt",
"matching : matchopt ',' matching",
"matchopt : direction",
"matchopt : dstip",
"matchopt : dstport",
"matchopt : every",
"matchopt : group",
"matchopt : interface",
"matchopt : protocol",
"matchopt : result",
"matchopt : rule",
"matchopt : srcip",
"matchopt : srcport",
"matchopt : logtag",
"matchopt : nattag",
"matchopt : type",
"doing : doopt",
"doing : doopt ',' doing",
"$$1 :",
"doopt : YY_STR $$1 '(' YY_STR ')'",
"doopt : YY_STR",
"direction : IPM_DIRECTION '=' IPM_IN",
"direction : IPM_DIRECTION '=' IPM_OUT",
"dstip : IPM_DSTIP '=' ipv4 '/' YY_NUMBER",
"dstport : IPM_DSTPORT '=' YY_NUMBER",
"dstport : IPM_DSTPORT '=' YY_STR",
"every : IPM_EVERY IPM_SECOND",
"every : IPM_EVERY YY_NUMBER IPM_SECONDS",
"every : IPM_EVERY IPM_PACKET",
"every : IPM_EVERY YY_NUMBER IPM_PACKETS",
"group : IPM_GROUP '=' YY_NUMBER",
"group : IPM_GROUP '=' YY_STR",
"interface : IPM_INTERFACE '=' YY_STR",
"logtag : IPM_LOGTAG '=' YY_NUMBER",
"nattag : IPM_NATTAG '=' YY_STR",
"protocol : IPM_PROTOCOL '=' YY_NUMBER",
"protocol : IPM_PROTOCOL '=' YY_STR",
"result : IPM_RESULT '=' YY_STR",
"rule : IPM_RULE '=' YY_NUMBER",
"srcip : IPM_SRCIP '=' ipv4 '/' YY_NUMBER",
"srcport : IPM_SRCPORT '=' YY_NUMBER",
"srcport : IPM_SRCPORT '=' YY_STR",
"type : IPM_TYPE '=' typeopt",
"typeopt : IPM_IPF",
"typeopt : IPM_NAT",
"typeopt : IPM_STATE",
"ipv4 : YY_NUMBER '.' YY_NUMBER '.' YY_NUMBER '.' YY_NUMBER",

};
#endif

int      ipmon_yydebug;
int      ipmon_yynerrs;

int      ipmon_yyerrflag;
int      ipmon_yychar;
YYSTYPE  ipmon_yyval;
YYSTYPE  ipmon_yylval;

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
static YYSTACKDATA ipmon_yystack;
#line 252 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
static	struct	wordtab	ipmon_yywords[] = {
	{ "body",	IPM_BODY },
	{ "direction",	IPM_DIRECTION },
	{ "do",		IPM_DO },
	{ "dstip",	IPM_DSTIP },
	{ "dstport",	IPM_DSTPORT },
	{ "every",	IPM_EVERY },
	{ "group",	IPM_GROUP },
	{ "in",		IPM_IN },
	{ "interface",	IPM_INTERFACE },
	{ "ipf",	IPM_IPF },
	{ "load_action",IPM_LOADACTION },
	{ "logtag",	IPM_LOGTAG },
	{ "match",	IPM_MATCH },
	{ "nat",	IPM_NAT },
	{ "nattag",	IPM_NATTAG },
	{ "no",		IPM_NO },
	{ "out",	IPM_OUT },
	{ "packet",	IPM_PACKET },
	{ "packets",	IPM_PACKETS },
	{ "protocol",	IPM_PROTOCOL },
	{ "result",	IPM_RESULT },
	{ "rule",	IPM_RULE },
	{ "second",	IPM_SECOND },
	{ "seconds",	IPM_SECONDS },
	{ "srcip",	IPM_SRCIP },
	{ "srcport",	IPM_SRCPORT },
	{ "state",	IPM_STATE },
	{ "with",	IPM_WITH },
	{ NULL,		0 }
};

static int macflags[17][2] = {
	{ IPM_DIRECTION,	IPMAC_DIRECTION	},
	{ IPM_DSTIP,		IPMAC_DSTIP	},
	{ IPM_DSTPORT,		IPMAC_DSTPORT	},
	{ IPM_GROUP,		IPMAC_GROUP	},
	{ IPM_INTERFACE,	IPMAC_INTERFACE	},
	{ IPM_LOGTAG,		IPMAC_LOGTAG 	},
	{ IPM_NATTAG,		IPMAC_NATTAG 	},
	{ IPM_PACKET,		IPMAC_EVERY	},
	{ IPM_PROTOCOL,		IPMAC_PROTOCOL	},
	{ IPM_RESULT,		IPMAC_RESULT	},
	{ IPM_RULE,		IPMAC_RULE	},
	{ IPM_SECOND,		IPMAC_EVERY	},
	{ IPM_SRCIP,		IPMAC_SRCIP	},
	{ IPM_SRCPORT,		IPMAC_SRCPORT	},
	{ IPM_TYPE,		IPMAC_TYPE 	},
	{ IPM_WITH,		IPMAC_WITH 	},
	{ 0, 0 }
};

static opt_t *
new_opt(type)
	int type;
{
	opt_t *o;

	o = (opt_t *)calloc(1, sizeof(*o));
	o->o_type = type;
	o->o_line = ipmon_yylineNum;
	o->o_logfac = -1;
	o->o_logpri = -1;
	return o;
}

static void
build_action(olist, todo)
	opt_t *olist;
	ipmon_doing_t *todo;
{
	ipmon_action_t *a;
	opt_t *o;
	int i;

	a = (ipmon_action_t *)calloc(1, sizeof(*a));
	if (a == NULL)
		return;

	while ((o = olist) != NULL) {
		/*
		 * Check to see if the same comparator is being used more than
		 * once per matching statement.
		 */
		for (i = 0; macflags[i][0]; i++)
			if (macflags[i][0] == o->o_type)
				break;
		if (macflags[i][1] & a->ac_mflag) {
			fprintf(stderr, "%s redfined on line %d\n",
				ipmon_yykeytostr(o->o_type), ipmon_yylineNum);
			if (o->o_str != NULL)
				free(o->o_str);
			olist = o->o_next;
			free(o);
			continue;
		}

		a->ac_mflag |= macflags[i][1];

		switch (o->o_type)
		{
		case IPM_DIRECTION :
			a->ac_direction = o->o_num;
			break;
		case IPM_DSTIP :
			a->ac_dip = o->o_ip.s_addr;
			a->ac_dmsk = htonl(0xffffffff << (32 - o->o_num));
			break;
		case IPM_DSTPORT :
			a->ac_dport = htons(o->o_num);
			break;
		case IPM_INTERFACE :
			a->ac_iface = o->o_str;
			o->o_str = NULL;
			break;
		case IPM_GROUP :
			if (o->o_str != NULL)
				strncpy(a->ac_group, o->o_str, FR_GROUPLEN);
			else
				sprintf(a->ac_group, "%d", o->o_num);
			break;
		case IPM_LOGTAG :
			a->ac_logtag = o->o_num;
			break;
		case IPM_NATTAG :
			strncpy(a->ac_nattag, o->o_str, sizeof(a->ac_nattag));
			break;
		case IPM_PACKET :
			a->ac_packet = o->o_num;
			break;
		case IPM_PROTOCOL :
			a->ac_proto = o->o_num;
			break;
		case IPM_RULE :
			a->ac_rule = o->o_num;
			break;
		case IPM_RESULT :
			if (!strcasecmp(o->o_str, "pass"))
				a->ac_result = IPMR_PASS;
			else if (!strcasecmp(o->o_str, "block"))
				a->ac_result = IPMR_BLOCK;
			else if (!strcasecmp(o->o_str, "nomatch"))
				a->ac_result = IPMR_NOMATCH;
			else if (!strcasecmp(o->o_str, "log"))
				a->ac_result = IPMR_LOG;
			break;
		case IPM_SECOND :
			a->ac_second = o->o_num;
			break;
		case IPM_SRCIP :
			a->ac_sip = o->o_ip.s_addr;
			a->ac_smsk = htonl(0xffffffff << (32 - o->o_num));
			break;
		case IPM_SRCPORT :
			a->ac_sport = htons(o->o_num);
			break;
		case IPM_TYPE :
			a->ac_type = o->o_num;
			break;
		case IPM_WITH :
			break;
		default :
			break;
		}

		olist = o->o_next;
		if (o->o_str != NULL)
			free(o->o_str);
		free(o);
	}

	a->ac_doing = todo;
	a->ac_next = alist;
	alist = a;

	if (ipmonopts & IPMON_VERBOSE)
		print_action(a);
}


int
check_action(buf, log, opts, lvl)
	char *buf, *log;
	int opts, lvl;
{
	ipmon_action_t *a;
	struct timeval tv;
	ipmon_doing_t *d;
	ipmon_msg_t msg;
	ipflog_t *ipf;
	tcphdr_t *tcp;
	iplog_t *ipl;
	int matched;
	u_long t1;
	ip_t *ip;

	matched = 0;
	ipl = (iplog_t *)buf;
	ipf = (ipflog_t *)(ipl +1);
	ip = (ip_t *)(ipf + 1);
	tcp = (tcphdr_t *)((char *)ip + (IP_HL(ip) << 2));

	msg.imm_data = ipl;
	msg.imm_dsize = ipl->ipl_dsize;
	msg.imm_when = ipl->ipl_time.tv_sec;
	msg.imm_msg = log;
	msg.imm_msglen = strlen(log);
	msg.imm_loglevel = lvl;

	for (a = alist; a != NULL; a = a->ac_next) {
		verbose(0, "== checking config rule\n");
		if ((a->ac_mflag & IPMAC_DIRECTION) != 0) {
			if (a->ac_direction == IPM_IN) {
				if ((ipf->fl_flags & FR_INQUE) == 0) {
					verbose(8, "-- direction not in\n");
					continue;
				}
			} else if (a->ac_direction == IPM_OUT) {
				if ((ipf->fl_flags & FR_OUTQUE) == 0) {
					verbose(8, "-- direction not out\n");
					continue;
				}
			}
		}

		if ((a->ac_type != 0) && (a->ac_type != ipl->ipl_magic)) {
			verbose(8, "-- type mismatch\n");
			continue;
		}

		if ((a->ac_mflag & IPMAC_EVERY) != 0) {
			gettimeofday(&tv, NULL);
			t1 = tv.tv_sec - a->ac_lastsec;
			if (tv.tv_usec <= a->ac_lastusec)
				t1--;
			if (a->ac_second != 0) {
				if (t1 < a->ac_second) {
					verbose(8, "-- too soon\n");
					continue;
				}
				a->ac_lastsec = tv.tv_sec;
				a->ac_lastusec = tv.tv_usec;
			}

			if (a->ac_packet != 0) {
				if (a->ac_pktcnt == 0)
					a->ac_pktcnt++;
				else if (a->ac_pktcnt == a->ac_packet) {
					a->ac_pktcnt = 0;
					verbose(8, "-- packet count\n");
					continue;
				} else {
					a->ac_pktcnt++;
					verbose(8, "-- packet count\n");
					continue;
				}
			}
		}

		if ((a->ac_mflag & IPMAC_DSTIP) != 0) {
			if ((ip->ip_dst.s_addr & a->ac_dmsk) != a->ac_dip) {
				verbose(8, "-- dstip wrong\n");
				continue;
			}
		}

		if ((a->ac_mflag & IPMAC_DSTPORT) != 0) {
			if (ip->ip_p != IPPROTO_UDP &&
			    ip->ip_p != IPPROTO_TCP) {
				verbose(8, "-- not port protocol\n");
				continue;
			}
			if (tcp->th_dport != a->ac_dport) {
				verbose(8, "-- dport mismatch\n");
				continue;
			}
		}

		if ((a->ac_mflag & IPMAC_GROUP) != 0) {
			if (strncmp(a->ac_group, ipf->fl_group,
				    FR_GROUPLEN) != 0) {
				verbose(8, "-- group mismatch\n");
				continue;
			}
		}

		if ((a->ac_mflag & IPMAC_INTERFACE) != 0) {
			if (strcmp(a->ac_iface, ipf->fl_ifname)) {
				verbose(8, "-- ifname mismatch\n");
				continue;
			}
		}

		if ((a->ac_mflag & IPMAC_PROTOCOL) != 0) {
			if (a->ac_proto != ip->ip_p) {
				verbose(8, "-- protocol mismatch\n");
				continue;
			}
		}

		if ((a->ac_mflag & IPMAC_RESULT) != 0) {
			if ((ipf->fl_flags & FF_LOGNOMATCH) != 0) {
				if (a->ac_result != IPMR_NOMATCH) {
					verbose(8, "-- ff-flags mismatch\n");
					continue;
				}
			} else if (FR_ISPASS(ipf->fl_flags)) {
				if (a->ac_result != IPMR_PASS) {
					verbose(8, "-- pass mismatch\n");
					continue;
				}
			} else if (FR_ISBLOCK(ipf->fl_flags)) {
				if (a->ac_result != IPMR_BLOCK) {
					verbose(8, "-- block mismatch\n");
					continue;
				}
			} else {	/* Log only */
				if (a->ac_result != IPMR_LOG) {
					verbose(8, "-- log mismatch\n");
					continue;
				}
			}
		}

		if ((a->ac_mflag & IPMAC_RULE) != 0) {
			if (a->ac_rule != ipf->fl_rule) {
				verbose(8, "-- rule mismatch\n");
				continue;
			}
		}

		if ((a->ac_mflag & IPMAC_SRCIP) != 0) {
			if ((ip->ip_src.s_addr & a->ac_smsk) != a->ac_sip) {
				verbose(8, "-- srcip mismatch\n");
				continue;
			}
		}

		if ((a->ac_mflag & IPMAC_SRCPORT) != 0) {
			if (ip->ip_p != IPPROTO_UDP &&
			    ip->ip_p != IPPROTO_TCP) {
				verbose(8, "-- port protocol mismatch\n");
				continue;
			}
			if (tcp->th_sport != a->ac_sport) {
				verbose(8, "-- sport mismatch\n");
				continue;
			}
		}

		if ((a->ac_mflag & IPMAC_LOGTAG) != 0) {
			if (a->ac_logtag != ipf->fl_logtag) {
				verbose(8, "-- logtag %d != %d\n",
					a->ac_logtag, ipf->fl_logtag);
				continue;
			}
		}

		if ((a->ac_mflag & IPMAC_NATTAG) != 0) {
			if (strncmp(a->ac_nattag, ipf->fl_nattag.ipt_tag,
				    IPFTAG_LEN) != 0) {
				verbose(8, "-- nattag mismatch\n");
				continue;
			}
		}

		matched = 1;
		verbose(8, "++ matched\n");

		/*
		 * It matched so now perform the saves
		 */
		for (d = a->ac_doing; d != NULL; d = d->ipmd_next)
			(*d->ipmd_store)(d->ipmd_token, &msg);
	}

	return matched;
}


static void
free_action(a)
	ipmon_action_t *a;
{
	ipmon_doing_t *d;

	while ((d = a->ac_doing) != NULL) {
		a->ac_doing = d->ipmd_next;
		(*d->ipmd_saver->ims_destroy)(d->ipmd_token);
		free(d);
	}

	if (a->ac_iface != NULL) {
		free(a->ac_iface);
		a->ac_iface = NULL;
	}
	a->ac_next = NULL;
	free(a);
}


int
load_config(file)
	char *file;
{
	FILE *fp;
	char *s;

	unload_config();

	s = getenv("YYDEBUG");
	if (s != NULL)
		ipmon_yydebug = atoi(s);
	else
		ipmon_yydebug = 0;

	ipmon_yylineNum = 1;

	(void) ipmon_yysettab(ipmon_yywords);

	fp = fopen(file, "r");
	if (!fp) {
		perror("load_config:fopen:");
		return -1;
	}
	ipmon_yyin = fp;
	while (!feof(fp))
		ipmon_yyparse();
	fclose(fp);
	return 0;
}


void
unload_config()
{
	ipmon_saver_int_t *sav, **imsip;
	ipmon_saver_t *is;
	ipmon_action_t *a;

	while ((a = alist) != NULL) {
		alist = a->ac_next;
		free_action(a);
	}

	/*
	 * Look for savers that have been added in dynamically from the
	 * configuration file.
	 */
	for (imsip = &saverlist; (sav = *imsip) != NULL; ) {
		if (sav->imsi_handle == NULL)
			imsip = &sav->imsi_next;
		else {
			dlclose(sav->imsi_handle);

			*imsip = sav->imsi_next;
			is = sav->imsi_stor;
			free(sav);

			free(is->ims_name);
			free(is);
		}
	}
}


void
dump_config()
{
	ipmon_action_t *a;

	for (a = alist; a != NULL; a = a->ac_next) {
		print_action(a);

		printf("#\n");
	}
}


static void
print_action(a)
	ipmon_action_t *a;
{
	ipmon_doing_t *d;

	printf("match { ");
	print_match(a);
	printf("; }\n");
	printf("do {");
	for (d = a->ac_doing; d != NULL; d = d->ipmd_next) {
		printf("%s", d->ipmd_saver->ims_name);
		if (d->ipmd_saver->ims_print != NULL) {
			printf("(\"");
			(*d->ipmd_saver->ims_print)(d->ipmd_token);
			printf("\")");
		}
		printf(";");
	}
	printf("};\n");
}


void *
add_doing(saver)
	ipmon_saver_t *saver;
{
	ipmon_saver_int_t *it;

	if (find_doing(saver->ims_name) == IPM_DOING)
		return NULL;

	it = calloc(1, sizeof(*it));
	if (it == NULL)
		return NULL;
	it->imsi_stor = saver;
	it->imsi_next = saverlist;
	saverlist = it;
	return it;
}


static int
find_doing(string)
	char *string;
{
	ipmon_saver_int_t *it;

	for (it = saverlist; it != NULL; it = it->imsi_next) {
		if (!strcmp(it->imsi_stor->ims_name, string))
			return IPM_DOING;
	}
	return 0;
}


static ipmon_doing_t *
build_doing(target, options)
	char *target;
	char *options;
{
	ipmon_saver_int_t *it;
	char *strarray[2];
	ipmon_doing_t *d, *d1;
	ipmon_action_t *a;
	ipmon_saver_t *save;

	d = calloc(1, sizeof(*d));
	if (d == NULL)
		return NULL;

	for (it = saverlist; it != NULL; it = it->imsi_next) {
		if (!strcmp(it->imsi_stor->ims_name, target))
			break;
	}
	if (it == NULL) {
		free(d);
		return NULL;
	}

	strarray[0] = options;
	strarray[1] = NULL;

	d->ipmd_token = (*it->imsi_stor->ims_parse)(strarray);
	if (d->ipmd_token == NULL) {
		free(d);
		return NULL;
	}

	save = it->imsi_stor;
	d->ipmd_saver = save;
	d->ipmd_store = it->imsi_stor->ims_store;

	/*
	 * Look for duplicate do-things that need to be dup'd
	 */
	for (a = alist; a != NULL; a = a->ac_next) {
		for (d1 = a->ac_doing; d1 != NULL; d1 = d1->ipmd_next) {
			if (save != d1->ipmd_saver)
				continue;
			if (save->ims_match == NULL || save->ims_dup == NULL)
				continue;
			if ((*save->ims_match)(d->ipmd_token, d1->ipmd_token))
				continue;

			(*d->ipmd_saver->ims_destroy)(d->ipmd_token);
			d->ipmd_token = (*save->ims_dup)(d1->ipmd_token);
			break;
		}
	}

	return d;
}


static void
print_match(a)
	ipmon_action_t *a;
{
	char *coma = "";

	if ((a->ac_mflag & IPMAC_DIRECTION) != 0) {
		printf("direction = ");
		if (a->ac_direction == IPM_IN)
			printf("in");
		else if (a->ac_direction == IPM_OUT)
			printf("out");
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_DSTIP) != 0) {
		printf("%sdstip = ", coma);
		printhostmask(AF_INET, &a->ac_dip, &a->ac_dmsk);
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_DSTPORT) != 0) {
		printf("%sdstport = %hu", coma, ntohs(a->ac_dport));
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_GROUP) != 0) {
		char group[FR_GROUPLEN+1];

		strncpy(group, a->ac_group, FR_GROUPLEN);
		group[FR_GROUPLEN] = '\0';
		printf("%sgroup = %s", coma, group);
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_INTERFACE) != 0) {
		printf("%siface = %s", coma, a->ac_iface);
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_LOGTAG) != 0) {
		printf("%slogtag = %u", coma, a->ac_logtag);
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_NATTAG) != 0) {
		char tag[17];

		strncpy(tag, a->ac_nattag, 16);
		tag[16] = '\0';
		printf("%snattag = %s", coma, tag);
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_PROTOCOL) != 0) {
		printf("%sprotocol = %u", coma, a->ac_proto);
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_RESULT) != 0) {
		printf("%sresult = ", coma);
		switch (a->ac_result)
		{
		case IPMR_LOG :
			printf("log");
			break;
		case IPMR_PASS :
			printf("pass");
			break;
		case IPMR_BLOCK :
			printf("block");
			break;
		case IPMR_NOMATCH :
			printf("nomatch");
			break;
		}
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_RULE) != 0) {
		printf("%srule = %u", coma, a->ac_rule);
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_EVERY) != 0) {
		if (a->ac_packet > 1) {
			printf("%severy %d packets", coma, a->ac_packet);
			coma = ", ";
		} else if (a->ac_packet == 1) {
			printf("%severy packet", coma);
			coma = ", ";
		}
		if (a->ac_second > 1) {
			printf("%severy %d seconds", coma, a->ac_second);
			coma = ", ";
		} else if (a->ac_second == 1) {
			printf("%severy second", coma);
			coma = ", ";
		}
	}

	if ((a->ac_mflag & IPMAC_SRCIP) != 0) {
		printf("%ssrcip = ", coma);
		printhostmask(AF_INET, &a->ac_sip, &a->ac_smsk);
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_SRCPORT) != 0) {
		printf("%ssrcport = %hu", coma, ntohs(a->ac_sport));
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_TYPE) != 0) {
		printf("%stype = ", coma);
		switch (a->ac_type)
		{
		case IPL_LOGIPF :
			printf("ipf");
			break;
		case IPL_LOGSTATE :
			printf("state");
			break;
		case IPL_LOGNAT :
			printf("nat");
			break;
		}
		coma = ", ";
	}

	if ((a->ac_mflag & IPMAC_WITH) != 0) {
		printf("%swith ", coma);
		coma = ", ";
	}
}


static int
install_saver(name, path)
	char *name, *path;
{
	ipmon_saver_int_t *isi;
	ipmon_saver_t *is;
	char nbuf[80];

	if (find_doing(name) == IPM_DOING)
		return -1;

	isi = calloc(1, sizeof(*isi));
	if (isi == NULL)
		return -1;

	is = calloc(1, sizeof(*is));
	if (is == NULL)
		goto loaderror;

	is->ims_name = name;

#ifdef RTLD_LAZY
	isi->imsi_handle = dlopen(path, RTLD_LAZY);
#endif
#ifdef DL_LAZY
	isi->imsi_handle = dlopen(path, DL_LAZY);
#endif

	if (isi->imsi_handle == NULL)
		goto loaderror;

	snprintf(nbuf, sizeof(nbuf), "%sdup", name);
	is->ims_dup = (ims_dup_func_t)dlsym(isi->imsi_handle, nbuf);

	snprintf(nbuf, sizeof(nbuf), "%sdestroy", name);
	is->ims_destroy = (ims_destroy_func_t)dlsym(isi->imsi_handle, nbuf);
	if (is->ims_destroy == NULL)
		goto loaderror;

	snprintf(nbuf, sizeof(nbuf), "%smatch", name);
	is->ims_match = (ims_match_func_t)dlsym(isi->imsi_handle, nbuf);

	snprintf(nbuf, sizeof(nbuf), "%sparse", name);
	is->ims_parse = (ims_parse_func_t)dlsym(isi->imsi_handle, nbuf);
	if (is->ims_parse == NULL)
		goto loaderror;

	snprintf(nbuf, sizeof(nbuf), "%sprint", name);
	is->ims_print = (ims_print_func_t)dlsym(isi->imsi_handle, nbuf);
	if (is->ims_print == NULL)
		goto loaderror;

	snprintf(nbuf, sizeof(nbuf), "%sstore", name);
	is->ims_store = (ims_store_func_t)dlsym(isi->imsi_handle, nbuf);
	if (is->ims_store == NULL)
		goto loaderror;

	isi->imsi_stor = is;
	isi->imsi_next = saverlist;
	saverlist = isi;

	return 0;

loaderror:
	if (isi->imsi_handle != NULL)
		dlclose(isi->imsi_handle);
	free(isi);
	if (is != NULL)
		free(is);
	return -1;
}
#line 1178 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int ipmon_yygrowstack(YYSTACKDATA *data)
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
static void ipmon_yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define ipmon_yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto ipmon_yyabort
#define YYREJECT goto ipmon_yyabort
#define YYACCEPT goto ipmon_yyaccept
#define YYERROR  goto ipmon_yyerrlab

int
YYPARSE_DECL()
{
    int ipmon_yym, ipmon_yyn, ipmon_yystate;
#if YYDEBUG
    const char *ipmon_yys;

    if ((ipmon_yys = getenv("YYDEBUG")) != 0)
    {
        ipmon_yyn = *ipmon_yys;
        if (ipmon_yyn >= '0' && ipmon_yyn <= '9')
            ipmon_yydebug = ipmon_yyn - '0';
    }
#endif

    ipmon_yynerrs = 0;
    ipmon_yyerrflag = 0;
    ipmon_yychar = YYEMPTY;
    ipmon_yystate = 0;

#if YYPURE
    memset(&ipmon_yystack, 0, sizeof(ipmon_yystack));
#endif

    if (ipmon_yystack.s_base == NULL && ipmon_yygrowstack(&ipmon_yystack) == YYENOMEM) goto ipmon_yyoverflow;
    ipmon_yystack.s_mark = ipmon_yystack.s_base;
    ipmon_yystack.l_mark = ipmon_yystack.l_base;
    ipmon_yystate = 0;
    *ipmon_yystack.s_mark = 0;

ipmon_yyloop:
    if ((ipmon_yyn = ipmon_yydefred[ipmon_yystate]) != 0) goto ipmon_yyreduce;
    if (ipmon_yychar < 0)
    {
        if ((ipmon_yychar = YYLEX) < 0) ipmon_yychar = YYEOF;
#if YYDEBUG
        if (ipmon_yydebug)
        {
            ipmon_yys = ipmon_yyname[YYTRANSLATE(ipmon_yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, ipmon_yystate, ipmon_yychar, ipmon_yys);
        }
#endif
    }
    if ((ipmon_yyn = ipmon_yysindex[ipmon_yystate]) && (ipmon_yyn += ipmon_yychar) >= 0 &&
            ipmon_yyn <= YYTABLESIZE && ipmon_yycheck[ipmon_yyn] == ipmon_yychar)
    {
#if YYDEBUG
        if (ipmon_yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, ipmon_yystate, ipmon_yytable[ipmon_yyn]);
#endif
        if (ipmon_yystack.s_mark >= ipmon_yystack.s_last && ipmon_yygrowstack(&ipmon_yystack) == YYENOMEM)
        {
            goto ipmon_yyoverflow;
        }
        ipmon_yystate = ipmon_yytable[ipmon_yyn];
        *++ipmon_yystack.s_mark = ipmon_yytable[ipmon_yyn];
        *++ipmon_yystack.l_mark = ipmon_yylval;
        ipmon_yychar = YYEMPTY;
        if (ipmon_yyerrflag > 0)  --ipmon_yyerrflag;
        goto ipmon_yyloop;
    }
    if ((ipmon_yyn = ipmon_yyrindex[ipmon_yystate]) && (ipmon_yyn += ipmon_yychar) >= 0 &&
            ipmon_yyn <= YYTABLESIZE && ipmon_yycheck[ipmon_yyn] == ipmon_yychar)
    {
        ipmon_yyn = ipmon_yytable[ipmon_yyn];
        goto ipmon_yyreduce;
    }
    if (ipmon_yyerrflag) goto ipmon_yyinrecovery;

    YYERROR_CALL("syntax error");

    goto ipmon_yyerrlab;

ipmon_yyerrlab:
    ++ipmon_yynerrs;

ipmon_yyinrecovery:
    if (ipmon_yyerrflag < 3)
    {
        ipmon_yyerrflag = 3;
        for (;;)
        {
            if ((ipmon_yyn = ipmon_yysindex[*ipmon_yystack.s_mark]) && (ipmon_yyn += YYERRCODE) >= 0 &&
                    ipmon_yyn <= YYTABLESIZE && ipmon_yycheck[ipmon_yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (ipmon_yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *ipmon_yystack.s_mark, ipmon_yytable[ipmon_yyn]);
#endif
                if (ipmon_yystack.s_mark >= ipmon_yystack.s_last && ipmon_yygrowstack(&ipmon_yystack) == YYENOMEM)
                {
                    goto ipmon_yyoverflow;
                }
                ipmon_yystate = ipmon_yytable[ipmon_yyn];
                *++ipmon_yystack.s_mark = ipmon_yytable[ipmon_yyn];
                *++ipmon_yystack.l_mark = ipmon_yylval;
                goto ipmon_yyloop;
            }
            else
            {
#if YYDEBUG
                if (ipmon_yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *ipmon_yystack.s_mark);
#endif
                if (ipmon_yystack.s_mark <= ipmon_yystack.s_base) goto ipmon_yyabort;
                --ipmon_yystack.s_mark;
                --ipmon_yystack.l_mark;
            }
        }
    }
    else
    {
        if (ipmon_yychar == YYEOF) goto ipmon_yyabort;
#if YYDEBUG
        if (ipmon_yydebug)
        {
            ipmon_yys = ipmon_yyname[YYTRANSLATE(ipmon_yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, ipmon_yystate, ipmon_yychar, ipmon_yys);
        }
#endif
        ipmon_yychar = YYEMPTY;
        goto ipmon_yyloop;
    }

ipmon_yyreduce:
#if YYDEBUG
    if (ipmon_yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, ipmon_yystate, ipmon_yyn, ipmon_yyrule[ipmon_yyn]);
#endif
    ipmon_yym = ipmon_yylen[ipmon_yyn];
    if (ipmon_yym)
        ipmon_yyval = ipmon_yystack.l_mark[1-ipmon_yym];
    else
        memset(&ipmon_yyval, 0, sizeof ipmon_yyval);
    switch (ipmon_yyn)
    {
case 7:
#line 94 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ build_action(ipmon_yystack.l_mark[-7].opt, ipmon_yystack.l_mark[-2].ipmd);
						  resetlexer();
						}
break;
case 8:
#line 97 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ if (install_saver(ipmon_yystack.l_mark[-1].str, ipmon_yystack.l_mark[0].str))
						ipmon_yyerror("install saver");
					}
break;
case 9:
#line 102 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ set_variable(ipmon_yystack.l_mark[-2].str, ipmon_yystack.l_mark[0].str);
						  resetlexer();
						  free(ipmon_yystack.l_mark[-2].str);
						  free(ipmon_yystack.l_mark[0].str);
						  ipmon_yyvarnext = 0;
						}
break;
case 10:
#line 111 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyvarnext = 1; }
break;
case 11:
#line 115 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 12:
#line 116 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yystack.l_mark[-2].opt->o_next = ipmon_yystack.l_mark[0].opt; ipmon_yyval.opt = ipmon_yystack.l_mark[-2].opt; }
break;
case 13:
#line 120 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 14:
#line 121 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 15:
#line 122 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 16:
#line 123 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 17:
#line 124 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 18:
#line 125 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 19:
#line 126 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 20:
#line 127 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 21:
#line 128 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 22:
#line 129 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 23:
#line 130 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 24:
#line 131 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 25:
#line 132 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 26:
#line 133 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = ipmon_yystack.l_mark[0].opt; }
break;
case 27:
#line 137 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.ipmd = ipmon_yystack.l_mark[0].ipmd; }
break;
case 28:
#line 138 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yystack.l_mark[-2].ipmd->ipmd_next = ipmon_yystack.l_mark[0].ipmd; ipmon_yyval.ipmd = ipmon_yystack.l_mark[-2].ipmd; }
break;
case 29:
#line 142 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ if (find_doing(ipmon_yystack.l_mark[0].str) != IPM_DOING)
						ipmon_yyerror("unknown action");
					}
break;
case 30:
#line 145 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.ipmd = build_doing(ipmon_yystack.l_mark[-4].str, ipmon_yystack.l_mark[-1].str);
					  if (ipmon_yyval.ipmd == NULL)
						ipmon_yyerror("action building");
					}
break;
case 31:
#line 149 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ if (find_doing(ipmon_yystack.l_mark[0].str) == IPM_DOING)
						ipmon_yyval.ipmd = build_doing(ipmon_yystack.l_mark[0].str, NULL);
					}
break;
case 32:
#line 155 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_DIRECTION);
						  ipmon_yyval.opt->o_num = IPM_IN; }
break;
case 33:
#line 157 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_DIRECTION);
						  ipmon_yyval.opt->o_num = IPM_OUT; }
break;
case 34:
#line 161 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_DSTIP);
						  ipmon_yyval.opt->o_ip = ipmon_yystack.l_mark[-2].addr;
						  ipmon_yyval.opt->o_num = ipmon_yystack.l_mark[0].num; }
break;
case 35:
#line 167 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_DSTPORT);
						  ipmon_yyval.opt->o_num = ipmon_yystack.l_mark[0].num; }
break;
case 36:
#line 169 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_DSTPORT);
						  ipmon_yyval.opt->o_str = ipmon_yystack.l_mark[0].str; }
break;
case 37:
#line 173 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_SECOND);
						  ipmon_yyval.opt->o_num = 1; }
break;
case 38:
#line 175 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_SECOND);
						  ipmon_yyval.opt->o_num = ipmon_yystack.l_mark[-1].num; }
break;
case 39:
#line 177 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_PACKET);
						  ipmon_yyval.opt->o_num = 1; }
break;
case 40:
#line 179 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_PACKET);
						  ipmon_yyval.opt->o_num = ipmon_yystack.l_mark[-1].num; }
break;
case 41:
#line 183 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_GROUP);
						  ipmon_yyval.opt->o_num = ipmon_yystack.l_mark[0].num; }
break;
case 42:
#line 185 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_GROUP);
						  ipmon_yyval.opt->o_str = ipmon_yystack.l_mark[0].str; }
break;
case 43:
#line 190 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_INTERFACE);
						  ipmon_yyval.opt->o_str = ipmon_yystack.l_mark[0].str; }
break;
case 44:
#line 194 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_LOGTAG);
						  ipmon_yyval.opt->o_num = ipmon_yystack.l_mark[0].num; }
break;
case 45:
#line 198 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_NATTAG);
						  ipmon_yyval.opt->o_str = ipmon_yystack.l_mark[0].str; }
break;
case 46:
#line 203 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_PROTOCOL);
						  ipmon_yyval.opt->o_num = ipmon_yystack.l_mark[0].num; }
break;
case 47:
#line 205 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_PROTOCOL);
						  ipmon_yyval.opt->o_num = getproto(ipmon_yystack.l_mark[0].str);
						  free(ipmon_yystack.l_mark[0].str);
						}
break;
case 48:
#line 211 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_RESULT);
						  ipmon_yyval.opt->o_str = ipmon_yystack.l_mark[0].str; }
break;
case 49:
#line 215 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_RULE);
						  ipmon_yyval.opt->o_num = YY_NUMBER; }
break;
case 50:
#line 219 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_SRCIP);
						  ipmon_yyval.opt->o_ip = ipmon_yystack.l_mark[-2].addr;
						  ipmon_yyval.opt->o_num = ipmon_yystack.l_mark[0].num; }
break;
case 51:
#line 225 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_SRCPORT);
						  ipmon_yyval.opt->o_num = ipmon_yystack.l_mark[0].num; }
break;
case 52:
#line 227 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_SRCPORT);
						  ipmon_yyval.opt->o_str = ipmon_yystack.l_mark[0].str; }
break;
case 53:
#line 231 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.opt = new_opt(IPM_TYPE);
						  ipmon_yyval.opt->o_num = ipmon_yystack.l_mark[0].num; }
break;
case 54:
#line 236 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.num = IPL_MAGIC; }
break;
case 55:
#line 237 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.num = IPL_MAGIC_NAT; }
break;
case 56:
#line 238 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ ipmon_yyval.num = IPL_MAGIC_STATE; }
break;
case 57:
#line 244 "/usr/home/freebsd/omega/src/sbin/ipf/ipmon/../../../contrib/ipfilter/tools/ipmon_y.y"
	{ if (ipmon_yystack.l_mark[-6].num > 255 || ipmon_yystack.l_mark[-4].num > 255 || ipmon_yystack.l_mark[-2].num > 255 || ipmon_yystack.l_mark[0].num > 255) {
			ipmon_yyerror("Invalid octet string for IP address");
			return 0;
		  }
		  ipmon_yyval.addr.s_addr = (ipmon_yystack.l_mark[-6].num << 24) | (ipmon_yystack.l_mark[-4].num << 16) | (ipmon_yystack.l_mark[-2].num << 8) | ipmon_yystack.l_mark[0].num;
		  ipmon_yyval.addr.s_addr = htonl(ipmon_yyval.addr.s_addr);
		}
break;
#line 1632 "y.tab.c"
    }
    ipmon_yystack.s_mark -= ipmon_yym;
    ipmon_yystate = *ipmon_yystack.s_mark;
    ipmon_yystack.l_mark -= ipmon_yym;
    ipmon_yym = ipmon_yylhs[ipmon_yyn];
    if (ipmon_yystate == 0 && ipmon_yym == 0)
    {
#if YYDEBUG
        if (ipmon_yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        ipmon_yystate = YYFINAL;
        *++ipmon_yystack.s_mark = YYFINAL;
        *++ipmon_yystack.l_mark = ipmon_yyval;
        if (ipmon_yychar < 0)
        {
            if ((ipmon_yychar = YYLEX) < 0) ipmon_yychar = YYEOF;
#if YYDEBUG
            if (ipmon_yydebug)
            {
                ipmon_yys = ipmon_yyname[YYTRANSLATE(ipmon_yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, ipmon_yychar, ipmon_yys);
            }
#endif
        }
        if (ipmon_yychar == YYEOF) goto ipmon_yyaccept;
        goto ipmon_yyloop;
    }
    if ((ipmon_yyn = ipmon_yygindex[ipmon_yym]) && (ipmon_yyn += ipmon_yystate) >= 0 &&
            ipmon_yyn <= YYTABLESIZE && ipmon_yycheck[ipmon_yyn] == ipmon_yystate)
        ipmon_yystate = ipmon_yytable[ipmon_yyn];
    else
        ipmon_yystate = ipmon_yydgoto[ipmon_yym];
#if YYDEBUG
    if (ipmon_yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *ipmon_yystack.s_mark, ipmon_yystate);
#endif
    if (ipmon_yystack.s_mark >= ipmon_yystack.s_last && ipmon_yygrowstack(&ipmon_yystack) == YYENOMEM)
    {
        goto ipmon_yyoverflow;
    }
    *++ipmon_yystack.s_mark = (YYINT) ipmon_yystate;
    *++ipmon_yystack.l_mark = ipmon_yyval;
    goto ipmon_yyloop;

ipmon_yyoverflow:
    YYERROR_CALL("yacc stack overflow");

ipmon_yyabort:
    ipmon_yyfreestack(&ipmon_yystack);
    return (1);

ipmon_yyaccept:
    ipmon_yyfreestack(&ipmon_yystack);
    return (0);
}
