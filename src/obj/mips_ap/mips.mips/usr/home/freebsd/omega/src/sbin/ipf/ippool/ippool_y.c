/* original parser id follows */
/* ippool_yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20141006

#define YYEMPTY        (-1)
#define ippool_yyclearin      (ippool_yychar = YYEMPTY)
#define ippool_yyerrok        (ippool_yyerrflag = 0)
#define YYRECOVERING() (ippool_yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "ippool_yy"

#define YYPURE 0

#line 9 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
#include <sys/types.h>
#include <sys/time.h>
#include <sys/param.h>
#include <sys/socket.h>
#if defined(BSD) && (BSD >= 199306)
# include <sys/cdefs.h>
#endif
#include <sys/ioctl.h>

#include <net/if.h>
#include <netinet/in.h>

#include <arpa/inet.h>

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <ctype.h>
#include <unistd.h>

#include "ipf.h"
#include "netinet/ip_lookup.h"
#include "netinet/ip_pool.h"
#include "netinet/ip_htable.h"
#include "netinet/ip_dstlist.h"
#include "ippool_l.h"
#include "kmem.h"

#define	YYDEBUG	1
#define	YYSTACKSIZE	0x00ffffff

extern	int	ippool_yyparse __P((void));
extern	int	ippool_yydebug;
extern	FILE	*ippool_yyin;

static	iphtable_t	ipht;
static	iphtent_t	iphte;
static	ip_pool_t	iplo;
static	ippool_dst_t	ipld;
static	ioctlfunc_t	poolioctl = NULL;
static	char		poolname[FR_GROUPLEN];

static iphtent_t *add_htablehosts __P((char *));
static ip_pool_node_t *add_poolhosts __P((char *));
static ip_pool_node_t *read_whoisfile __P((char *));
static void setadflen __P((addrfamily_t *));

#line 60 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union	{
	char	*str;
	u_32_t	num;
	struct	in_addr	ip4;
	struct	alist_s	*alist;
	addrfamily_t	adrmsk[2];
	iphtent_t	*ipe;
	ip_pool_node_t	*ipp;
	ipf_dstnode_t	*ipd;
	addrfamily_t	ipa;
	i6addr_t	ip6;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 91 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() ippool_yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() ippool_yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() ippool_yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() ippool_yylex(void *YYLEX_PARAM)
# define YYLEX ippool_yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() ippool_yylex(void)
# define YYLEX ippool_yylex()
#endif

/* Parameters sent to ippool_yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() ippool_yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) ippool_yyerror(msg)
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
#define IPT_IPF 270
#define IPT_NAT 271
#define IPT_COUNT 272
#define IPT_AUTH 273
#define IPT_IN 274
#define IPT_OUT 275
#define IPT_ALL 276
#define IPT_TABLE 277
#define IPT_GROUPMAP 278
#define IPT_HASH 279
#define IPT_SRCHASH 280
#define IPT_DSTHASH 281
#define IPT_ROLE 282
#define IPT_TYPE 283
#define IPT_TREE 284
#define IPT_GROUP 285
#define IPT_SIZE 286
#define IPT_SEED 287
#define IPT_NUM 288
#define IPT_NAME 289
#define IPT_POLICY 290
#define IPT_POOL 291
#define IPT_DSTLIST 292
#define IPT_ROUNDROBIN 293
#define IPT_WEIGHTED 294
#define IPT_RANDOM 295
#define IPT_CONNECTION 296
#define IPT_WHOIS 297
#define IPT_FILE 298
#define YYERRCODE 256
typedef int YYINT;
static const YYINT ippool_yylhs[] = {                           -1,
    0,    0,    0,    0,   27,   27,   27,   27,   27,   29,
   28,   32,    2,   30,    3,    3,    1,    4,    4,    4,
    4,    4,    7,   12,   11,   11,   21,   21,   21,   22,
   22,   35,   35,   35,   35,    9,    9,    9,   17,   17,
   17,   17,   17,   17,   16,   16,   16,   15,    8,    8,
    8,    8,   13,   13,   13,   14,   14,   10,   10,   18,
   18,   18,   19,   19,   19,   36,   37,   20,   38,   33,
   34,   31,   31,   31,   31,   31,   23,   23,   39,   39,
   39,   40,   40,   26,   26,   25,   25,   24,   24,    5,
    5,    5,    5,    5,    5,    5,    6,
};
static const YYINT ippool_yylen[] = {                            2,
    1,    1,    2,    2,    4,    4,    5,    1,    2,    1,
    4,    1,    1,    2,    1,    1,    3,    1,    1,    1,
    1,    1,    7,    8,    5,    4,    3,    3,    0,    3,
    3,    0,    1,    1,    2,    1,    3,    2,    1,    3,
    3,    2,    2,    1,    1,    2,    3,    3,    1,    2,
    1,    3,    1,    2,    3,    1,    1,    3,    1,    1,
    1,    1,    1,    1,    1,    3,    3,    7,    1,    1,
    1,   12,   11,    8,   12,   10,    2,    2,    0,    2,
    4,    2,    2,    1,    1,    2,    3,    3,    1,    0,
    3,    4,    3,    3,    3,    3,    1,
};
static const YYINT ippool_yydefred[] = {                         0,
    0,    8,   13,    0,    0,    0,    0,    1,    2,    0,
    0,   12,    0,   15,   16,    0,   14,   18,   19,   21,
   20,   22,    0,    0,    3,    4,    0,    0,    0,   10,
    9,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   11,   78,   77,    0,    0,    0,
    0,    0,   17,    0,    5,    6,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   34,    0,    0,    0,    0,
    0,    0,    0,   27,   28,    0,    0,    0,    7,    0,
   70,    0,   35,    0,    0,    0,    0,    0,    0,    0,
   31,   30,   66,   67,    0,    0,   62,   45,    0,    0,
    0,    0,   60,    0,   51,    0,   36,    0,    0,    0,
   49,    0,    0,    0,    0,    0,   44,   39,    0,    0,
    0,    0,    0,   69,    0,   71,   26,    0,    0,    0,
   50,    0,   74,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   25,    0,   48,   47,    0,   65,
   58,   64,    0,   52,   37,   82,   83,    0,    0,   80,
    0,    0,    0,    0,    0,    0,    0,    0,   57,   53,
   56,    0,    0,   23,   41,   40,    0,   76,    0,    0,
    0,   94,   95,   96,   91,   97,    0,   93,    0,   24,
    0,    0,   81,    0,   73,   92,    0,   85,   89,    0,
   84,    0,   55,    0,   75,    0,    0,   72,   68,   88,
   87,
};
static const YYINT ippool_yydgoto[] = {                          6,
   28,    7,   17,   24,  140,  187,   40,  109,  110,  111,
   62,   41,  172,  173,  100,  101,  121,  102,  151,  103,
   44,   63,   35,  200,  201,  202,    8,    9,   31,   10,
   11,   13,   82,  127,   64,   65,   66,  125,  136,  137,
};
static const YYINT ippool_yysindex[] = {                      -220,
  -46,    0,    0,  -36,  -39, -220, -254,    0,    0, -254,
  -11,    0, -216,    0,    0, -253,    0,    0,    0,    0,
    0,    0, -253,   13,    0,    0,   24, -176, -191,    0,
    0,   33, -142, -140,   66,   75, -198, -159,   74,  -11,
  -11,   76,   77, -163,    0,    0,    0, -148,   95,   99,
  100,  101,    0, -247,    0,    0, -115, -116,   83,   84,
   85,  -11, -185,   25, -138,    0,   88,   25, -253, -253,
 -253, -191, -191,    0,    0, -149, -107, -106,    0,   25,
    0,  -48,    0,  111,  -33,   94,   96,   97, -185,   25,
    0,    0,    0,    0,  -57,  108,    0,    0,  113,  102,
   35,  112,    0,   25,    0, -136,    0, -173,  102,   35,
    0, -158,  117, -127,   25,  -33,    0,    0,   29,  102,
   35,  -93, -114,    0,  -48,    0,    0, -154,  -48,  -89,
    0,  -33,    0,  -85,  -84,  -19,  115,   25, -204,  134,
  -53,   35,  -57,  -57,    0,  130,    0,    0,  108,    0,
    0,    0,   35,    0,    0,    0,    0, -158,   25,    0,
  -33,  118,  119,  120,  121, -113,  122,   25,    0,    0,
    0,   35,  102,    0,    0,    0,  -73,    0,  123,  -53,
   35,    0,    0,    0,    0,    0,  126,    0,  -49,    0,
  -53,  140,    0,   35,    0,    0,  129,    0,    0,  102,
    0,   35,    0,  -69,    0, -173, -139,    0,    0,    0,
    0,
};
static const YYINT ippool_yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -120,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   67,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   67,    0,   68,    0,    0,    0,    0,    0,
    0, -118,   69,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   67,    0,
    0,    0,    0,    0,    0,   23,    0,    0,    0,    0,
    0,   34,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -12,    0,  148,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   70,    0,    0,    0,    0,    0,
    0,   71,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   72,   73,    0,    0,    0,    0,   36,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   80,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   89,    0,    0,    0,
    0,
};
static const YYINT ippool_yygindex[] = {                         0,
  183,    0,  146,  161,    0,    0,    0,    0, -102,  -75,
    0,    0, -153,    0,  -82,  -76,  -13, -155,    0,   87,
   60,   78,   -6,    0,    6,    0,  210,  211,  -16,    0,
    0,    0,  -59,  -98,  -47,    0,  153, -101,    0,   61,
};
#define YYTABLESIZE 264
static const YYINT ippool_yytable[] = {                        108,
   23,  118,   29,   16,   29,  170,   99,  132,   85,  198,
   98,  133,  120,  142,   12,   80,   36,  143,  144,  119,
   95,  159,  145,   55,   56,  107,  194,   27,   79,  155,
  116,   72,  131,  199,   33,   34,   73,  203,    1,  158,
    2,  115,   32,  174,  129,   79,   79,   30,  148,   99,
  210,  199,  153,   99,  178,  141,    3,    4,  181,   37,
  120,  120,   86,   87,   88,  171,   61,  119,  119,   61,
    5,  191,  123,  190,  162,  163,  164,   59,  161,   63,
   50,   61,  195,   96,   38,   51,   97,  124,  165,  166,
  167,   45,   59,   52,   63,  205,   42,   43,  207,  180,
   60,   61,  149,  208,  171,  150,   39,   91,  189,   92,
   18,   19,   20,   21,   46,  171,   22,   96,   47,  197,
   97,   59,   60,   61,   48,   14,   15,  134,  135,  175,
  176,   89,   90,   49,   54,   68,   57,   58,   69,   70,
   71,   74,   75,   76,   77,   78,   84,   81,   61,   93,
   94,  104,  112,  122,  113,  114,  123,  138,  128,  126,
  124,  130,  139,  146,   29,   29,   29,   29,   29,  154,
   59,  156,  157,  160,  168,  177,  182,  183,  184,  185,
  188,  193,  186,  192,  196,  204,  206,  209,   90,   32,
   33,   29,   29,   67,   46,   38,   43,   42,   53,   96,
  147,  117,   97,   96,   54,  169,   97,   96,   96,  197,
   97,   97,  211,   86,  152,   25,   26,   83,  179,    0,
    0,    0,    0,   96,    0,  105,   97,    0,    0,    0,
   18,   19,   20,   21,    0,    0,   22,   14,   15,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  106,
};
static const YYINT ippool_yycheck[] = {                         33,
   40,   59,  123,   40,  123,   59,   82,  109,   68,   59,
   59,  110,   95,  116,   61,   63,   23,  119,  120,   95,
   80,   41,  121,   40,   41,   59,  180,  282,   41,  132,
   90,  279,  108,  189,  288,  289,  284,  191,  259,   59,
  261,   89,  259,  142,  104,   62,   59,   59,  125,  125,
  206,  207,  129,  129,  153,  115,  277,  278,  161,   47,
  143,  144,   69,   70,   71,  141,   44,  143,  144,   47,
  291,  173,   44,  172,  279,  280,  281,   44,  138,   44,
  279,   59,  181,  257,   61,  284,  260,   59,  293,  294,
  295,   59,   59,  292,   59,  194,  288,  289,  200,  159,
  286,  287,  257,  202,  180,  260,  283,  257,  168,  259,
  270,  271,  272,  273,  257,  191,  276,  257,  259,  259,
  260,  285,  286,  287,   59,  274,  275,  286,  287,  143,
  144,   72,   73,   59,   61,   41,   61,   61,   40,   40,
   40,  257,  259,   61,   61,   61,   59,  123,  287,  257,
  257,   41,   59,   46,   59,   59,   44,   41,   47,  125,
   59,  298,  290,  257,  285,  286,  287,  286,  287,  259,
  285,  257,  257,   59,   41,   46,   59,   59,   59,   59,
   59,   59,  296,  257,   59,   46,   58,  257,   41,  123,
  123,  123,   10,   48,  125,  125,  125,  125,   38,  257,
  123,  259,  260,  257,  125,  259,  260,  257,  257,  259,
  260,  260,  207,  125,  128,    6,    6,   65,  158,   -1,
   -1,   -1,   -1,  257,   -1,  259,  260,   -1,   -1,   -1,
  270,  271,  272,  273,   -1,   -1,  276,  274,  275,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  297,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 298
#define YYUNDFTOKEN 341
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const ippool_yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,0,0,0,"'('","')'",0,0,"','",0,"'.'","'/'",0,0,0,0,0,0,0,0,0,0,"':'",
"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"YY_NUMBER","YY_HEX","YY_STR","YY_IPV6","YY_COMMENT","YY_CMP_EQ",
"YY_CMP_NE","YY_CMP_LE","YY_CMP_GE","YY_CMP_LT","YY_CMP_GT","YY_RANGE_OUT",
"YY_RANGE_IN","IPT_IPF","IPT_NAT","IPT_COUNT","IPT_AUTH","IPT_IN","IPT_OUT",
"IPT_ALL","IPT_TABLE","IPT_GROUPMAP","IPT_HASH","IPT_SRCHASH","IPT_DSTHASH",
"IPT_ROLE","IPT_TYPE","IPT_TREE","IPT_GROUP","IPT_SIZE","IPT_SEED","IPT_NUM",
"IPT_NAME","IPT_POLICY","IPT_POOL","IPT_DSTLIST","IPT_ROUNDROBIN",
"IPT_WEIGHTED","IPT_RANDOM","IPT_CONNECTION","IPT_WHOIS","IPT_FILE",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const ippool_yyrule[] = {
"$accept : file",
"file : line",
"file : assign",
"file : file line",
"file : file assign",
"line : table role ipftree eol",
"line : table role ipfhash eol",
"line : groupmap role number ipfgroup eol",
"line : YY_COMMENT",
"line : poolline eol",
"eol : ';'",
"assign : YY_STR assigning YY_STR ';'",
"assigning : '='",
"table : IPT_TABLE",
"groupmap : IPT_GROUPMAP inout",
"inout : IPT_IN",
"inout : IPT_OUT",
"role : IPT_ROLE '=' unit",
"unit : IPT_IPF",
"unit : IPT_NAT",
"unit : IPT_AUTH",
"unit : IPT_COUNT",
"unit : IPT_ALL",
"ipftree : IPT_TYPE '=' IPT_TREE number start addrlist end",
"ipfhash : IPT_TYPE '=' IPT_HASH number hashopts start hashlist end",
"ipfgroup : setgroup hashopts start grouplist end",
"ipfgroup : hashopts start setgrouplist end",
"number : IPT_NUM '=' YY_NUMBER",
"number : IPT_NAME '=' YY_STR",
"number :",
"setgroup : IPT_GROUP '=' YY_STR",
"setgroup : IPT_GROUP '=' YY_NUMBER",
"hashopts :",
"hashopts : size",
"hashopts : seed",
"hashopts : size seed",
"addrlist : ';'",
"addrlist : range next addrlist",
"addrlist : range next",
"grouplist : ';'",
"grouplist : groupentry next grouplist",
"grouplist : addrmask next grouplist",
"grouplist : groupentry next",
"grouplist : addrmask next",
"grouplist : YY_STR",
"setgrouplist : ';'",
"setgrouplist : groupentry next",
"setgrouplist : groupentry next setgrouplist",
"groupentry : addrmask ',' setgroup",
"range : addrmask",
"range : '!' addrmask",
"range : YY_STR",
"range : IPT_WHOIS IPT_FILE YY_STR",
"hashlist : ';'",
"hashlist : hashentry next",
"hashlist : hashentry next hashlist",
"hashentry : addrmask",
"hashentry : YY_STR",
"addrmask : ipaddr '/' mask",
"addrmask : ipaddr",
"ipaddr : ipv4",
"ipaddr : YY_NUMBER",
"ipaddr : YY_IPV6",
"mask : YY_NUMBER",
"mask : ipv4",
"mask : YY_IPV6",
"size : IPT_SIZE '=' YY_NUMBER",
"seed : IPT_SEED '=' YY_NUMBER",
"ipv4 : YY_NUMBER '.' YY_NUMBER '.' YY_NUMBER '.' YY_NUMBER",
"next : ';'",
"start : '{'",
"end : '}'",
"poolline : IPT_POOL unit '/' IPT_DSTLIST '(' name ';' dstopts ')' start dstlist end",
"poolline : IPT_POOL unit '/' IPT_TREE '(' name ';' ')' start addrlist end",
"poolline : IPT_POOL '(' name ';' ')' start addrlist end",
"poolline : IPT_POOL unit '/' IPT_HASH '(' name ';' hashoptlist ')' start hashlist end",
"poolline : IPT_GROUPMAP '(' name ';' inout ';' ')' start setgrouplist end",
"name : IPT_NAME YY_STR",
"name : IPT_NUM YY_NUMBER",
"hashoptlist :",
"hashoptlist : hashopt ';'",
"hashoptlist : hashoptlist ';' hashopt ';'",
"hashopt : IPT_SIZE YY_NUMBER",
"hashopt : IPT_SEED YY_NUMBER",
"dstlist : dstentries",
"dstlist : ';'",
"dstentries : dstentry next",
"dstentries : dstentry next dstentries",
"dstentry : YY_STR ':' ipaddr",
"dstentry : ipaddr",
"dstopts :",
"dstopts : IPT_POLICY IPT_ROUNDROBIN ';'",
"dstopts : IPT_POLICY IPT_WEIGHTED weighting ';'",
"dstopts : IPT_POLICY IPT_RANDOM ';'",
"dstopts : IPT_POLICY IPT_HASH ';'",
"dstopts : IPT_POLICY IPT_SRCHASH ';'",
"dstopts : IPT_POLICY IPT_DSTHASH ';'",
"weighting : IPT_CONNECTION",

};
#endif

int      ippool_yydebug;
int      ippool_yynerrs;

int      ippool_yyerrflag;
int      ippool_yychar;
YYSTYPE  ippool_yyval;
YYSTYPE  ippool_yylval;

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
static YYSTACKDATA ippool_yystack;
#line 564 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
static	wordtab_t	ippool_yywords[] = {
	{ "all",		IPT_ALL },
	{ "auth",		IPT_AUTH },
	{ "connection",		IPT_CONNECTION },
	{ "count",		IPT_COUNT },
	{ "dst-hash",		IPT_DSTHASH },
	{ "dstlist",		IPT_DSTLIST },
	{ "file",		IPT_FILE },
	{ "group",		IPT_GROUP },
	{ "group-map",		IPT_GROUPMAP },
	{ "hash",		IPT_HASH },
	{ "in",			IPT_IN },
	{ "ipf",		IPT_IPF },
	{ "name",		IPT_NAME },
	{ "nat",		IPT_NAT },
	{ "number",		IPT_NUM },
	{ "out",		IPT_OUT },
	{ "policy",		IPT_POLICY },
	{ "pool",		IPT_POOL },
	{ "random",		IPT_RANDOM },
	{ "round-robin",	IPT_ROUNDROBIN },
	{ "role",		IPT_ROLE },
	{ "seed",		IPT_SEED },
	{ "size",		IPT_SIZE },
	{ "src-hash",		IPT_SRCHASH },
	{ "table",		IPT_TABLE },
	{ "tree",		IPT_TREE },
	{ "type",		IPT_TYPE },
	{ "weighted",		IPT_WEIGHTED },
	{ "whois",		IPT_WHOIS },
	{ NULL,			0 }
};


int ippool_parsefile(fd, filename, iocfunc)
int fd;
char *filename;
ioctlfunc_t iocfunc;
{
	FILE *fp = NULL;
	char *s;

	ippool_yylineNum = 1;
	(void) ippool_yysettab(ippool_yywords);

	s = getenv("YYDEBUG");
	if (s)
		ippool_yydebug = atoi(s);
	else
		ippool_yydebug = 0;

	if (strcmp(filename, "-")) {
		fp = fopen(filename, "r");
		if (!fp) {
			fprintf(stderr, "fopen(%s) failed: %s\n", filename,
				STRERROR(errno));
			return -1;
		}
	} else
		fp = stdin;

	while (ippool_parsesome(fd, fp, iocfunc) == 1)
		;
	if (fp != NULL)
		fclose(fp);
	return 0;
}


int ippool_parsesome(fd, fp, iocfunc)
int fd;
FILE *fp;
ioctlfunc_t iocfunc;
{
	char *s;
	int i;

	poolioctl = iocfunc;

	if (feof(fp))
		return 0;
	i = fgetc(fp);
	if (i == EOF)
		return 0;
	if (ungetc(i, fp) == EOF)
		return 0;
	if (feof(fp))
		return 0;
	s = getenv("YYDEBUG");
	if (s)
		ippool_yydebug = atoi(s);
	else
		ippool_yydebug = 0;

	ippool_yyin = fp;
	ippool_yyparse();
	return 1;
}


static iphtent_t *
add_htablehosts(url)
char *url;
{
	iphtent_t *htop, *hbot, *h;
	alist_t *a, *hlist;

	if (!strncmp(url, "file://", 7) || !strncmp(url, "http://", 7)) {
		hlist = load_url(url);
	} else {
		use_inet6 = 0;

		hlist = calloc(1, sizeof(*hlist));
		if (hlist == NULL)
			return NULL;

		if (gethost(hlist->al_family, url, &hlist->al_i6addr) == -1) {
			ippool_yyerror("Unknown hostname");
		}
	}

	hbot = NULL;
	htop = NULL;

	for (a = hlist; a != NULL; a = a->al_next) {
		h = calloc(1, sizeof(*h));
		if (h == NULL)
			break;

		h->ipe_family = a->al_family;
		h->ipe_addr = a->al_i6addr;
		h->ipe_mask = a->al_i6mask;

		if (hbot != NULL)
			hbot->ipe_next = h;
		else
			htop = h;
		hbot = h;
	}

	alist_free(hlist);

	return htop;
}


static ip_pool_node_t *
add_poolhosts(url)
char *url;
{
	ip_pool_node_t *ptop, *pbot, *p;
	alist_t *a, *hlist;

	if (!strncmp(url, "file://", 7) || !strncmp(url, "http://", 7)) {
		hlist = load_url(url);
	} else {
		use_inet6 = 0;

		hlist = calloc(1, sizeof(*hlist));
		if (hlist == NULL)
			return NULL;

		if (gethost(hlist->al_family, url, &hlist->al_i6addr) == -1) {
			ippool_yyerror("Unknown hostname");
		}
	}

	pbot = NULL;
	ptop = NULL;

	for (a = hlist; a != NULL; a = a->al_next) {
		p = calloc(1, sizeof(*p));
		if (p == NULL)
			break;
		p->ipn_mask.adf_addr = a->al_i6mask;

		if (a->al_family == AF_INET) {
			p->ipn_addr.adf_family = AF_INET;
#ifdef USE_INET6
		} else if (a->al_family == AF_INET6) {
			p->ipn_addr.adf_family = AF_INET6;
#endif
		}
		setadflen(&p->ipn_addr);
		p->ipn_addr.adf_addr = a->al_i6addr;
		p->ipn_info = a->al_not;
		p->ipn_mask.adf_len = p->ipn_addr.adf_len;

		if (pbot != NULL)
			pbot->ipn_next = p;
		else
			ptop = p;
		pbot = p;
	}

	alist_free(hlist);

	return ptop;
}


ip_pool_node_t *
read_whoisfile(file)
	char *file;
{
	ip_pool_node_t *ntop, *ipn, node, *last;
	char line[1024];
	FILE *fp;

	fp = fopen(file, "r");
	if (fp == NULL)
		return NULL;

	last = NULL;
	ntop = NULL;
	while (fgets(line, sizeof(line) - 1, fp) != NULL) {
		line[sizeof(line) - 1] = '\0';

		if (parsewhoisline(line, &node.ipn_addr, &node.ipn_mask))
			continue;
		ipn = calloc(1, sizeof(*ipn));
		if (ipn == NULL)
			continue;
		ipn->ipn_addr = node.ipn_addr;
		ipn->ipn_mask = node.ipn_mask;
		if (last == NULL)
			ntop = ipn;
		else
			last->ipn_next = ipn;
		last = ipn;
	}
	fclose(fp);
	return ntop;
}


static void
setadflen(afp)
	addrfamily_t *afp;
{
	afp->adf_len = offsetof(addrfamily_t, adf_addr);
	switch (afp->adf_family)
	{
	case AF_INET :
		afp->adf_len += sizeof(struct in_addr);
		break;
#ifdef USE_INET6
	case AF_INET6 :
		afp->adf_len += sizeof(struct in6_addr);
		break;
#endif
	default :
		break;
	}
}
#line 754 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int ippool_yygrowstack(YYSTACKDATA *data)
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
static void ippool_yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define ippool_yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto ippool_yyabort
#define YYREJECT goto ippool_yyabort
#define YYACCEPT goto ippool_yyaccept
#define YYERROR  goto ippool_yyerrlab

int
YYPARSE_DECL()
{
    int ippool_yym, ippool_yyn, ippool_yystate;
#if YYDEBUG
    const char *ippool_yys;

    if ((ippool_yys = getenv("YYDEBUG")) != 0)
    {
        ippool_yyn = *ippool_yys;
        if (ippool_yyn >= '0' && ippool_yyn <= '9')
            ippool_yydebug = ippool_yyn - '0';
    }
#endif

    ippool_yynerrs = 0;
    ippool_yyerrflag = 0;
    ippool_yychar = YYEMPTY;
    ippool_yystate = 0;

#if YYPURE
    memset(&ippool_yystack, 0, sizeof(ippool_yystack));
#endif

    if (ippool_yystack.s_base == NULL && ippool_yygrowstack(&ippool_yystack) == YYENOMEM) goto ippool_yyoverflow;
    ippool_yystack.s_mark = ippool_yystack.s_base;
    ippool_yystack.l_mark = ippool_yystack.l_base;
    ippool_yystate = 0;
    *ippool_yystack.s_mark = 0;

ippool_yyloop:
    if ((ippool_yyn = ippool_yydefred[ippool_yystate]) != 0) goto ippool_yyreduce;
    if (ippool_yychar < 0)
    {
        if ((ippool_yychar = YYLEX) < 0) ippool_yychar = YYEOF;
#if YYDEBUG
        if (ippool_yydebug)
        {
            ippool_yys = ippool_yyname[YYTRANSLATE(ippool_yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, ippool_yystate, ippool_yychar, ippool_yys);
        }
#endif
    }
    if ((ippool_yyn = ippool_yysindex[ippool_yystate]) && (ippool_yyn += ippool_yychar) >= 0 &&
            ippool_yyn <= YYTABLESIZE && ippool_yycheck[ippool_yyn] == ippool_yychar)
    {
#if YYDEBUG
        if (ippool_yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, ippool_yystate, ippool_yytable[ippool_yyn]);
#endif
        if (ippool_yystack.s_mark >= ippool_yystack.s_last && ippool_yygrowstack(&ippool_yystack) == YYENOMEM)
        {
            goto ippool_yyoverflow;
        }
        ippool_yystate = ippool_yytable[ippool_yyn];
        *++ippool_yystack.s_mark = ippool_yytable[ippool_yyn];
        *++ippool_yystack.l_mark = ippool_yylval;
        ippool_yychar = YYEMPTY;
        if (ippool_yyerrflag > 0)  --ippool_yyerrflag;
        goto ippool_yyloop;
    }
    if ((ippool_yyn = ippool_yyrindex[ippool_yystate]) && (ippool_yyn += ippool_yychar) >= 0 &&
            ippool_yyn <= YYTABLESIZE && ippool_yycheck[ippool_yyn] == ippool_yychar)
    {
        ippool_yyn = ippool_yytable[ippool_yyn];
        goto ippool_yyreduce;
    }
    if (ippool_yyerrflag) goto ippool_yyinrecovery;

    YYERROR_CALL("syntax error");

    goto ippool_yyerrlab;

ippool_yyerrlab:
    ++ippool_yynerrs;

ippool_yyinrecovery:
    if (ippool_yyerrflag < 3)
    {
        ippool_yyerrflag = 3;
        for (;;)
        {
            if ((ippool_yyn = ippool_yysindex[*ippool_yystack.s_mark]) && (ippool_yyn += YYERRCODE) >= 0 &&
                    ippool_yyn <= YYTABLESIZE && ippool_yycheck[ippool_yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (ippool_yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *ippool_yystack.s_mark, ippool_yytable[ippool_yyn]);
#endif
                if (ippool_yystack.s_mark >= ippool_yystack.s_last && ippool_yygrowstack(&ippool_yystack) == YYENOMEM)
                {
                    goto ippool_yyoverflow;
                }
                ippool_yystate = ippool_yytable[ippool_yyn];
                *++ippool_yystack.s_mark = ippool_yytable[ippool_yyn];
                *++ippool_yystack.l_mark = ippool_yylval;
                goto ippool_yyloop;
            }
            else
            {
#if YYDEBUG
                if (ippool_yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *ippool_yystack.s_mark);
#endif
                if (ippool_yystack.s_mark <= ippool_yystack.s_base) goto ippool_yyabort;
                --ippool_yystack.s_mark;
                --ippool_yystack.l_mark;
            }
        }
    }
    else
    {
        if (ippool_yychar == YYEOF) goto ippool_yyabort;
#if YYDEBUG
        if (ippool_yydebug)
        {
            ippool_yys = ippool_yyname[YYTRANSLATE(ippool_yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, ippool_yystate, ippool_yychar, ippool_yys);
        }
#endif
        ippool_yychar = YYEMPTY;
        goto ippool_yyloop;
    }

ippool_yyreduce:
#if YYDEBUG
    if (ippool_yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, ippool_yystate, ippool_yyn, ippool_yyrule[ippool_yyn]);
#endif
    ippool_yym = ippool_yylen[ippool_yyn];
    if (ippool_yym)
        ippool_yyval = ippool_yystack.l_mark[1-ippool_yym];
    else
        memset(&ippool_yyval, 0, sizeof ippool_yyval);
    switch (ippool_yyn)
    {
case 5:
#line 103 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ip_pool_node_t *n;
					  iplo.ipo_unit = ippool_yystack.l_mark[-2].num;
					  iplo.ipo_list = ippool_yystack.l_mark[-1].ipp;
					  load_pool(&iplo, poolioctl);
					  while ((n = ippool_yystack.l_mark[-1].ipp) != NULL) {
						ippool_yystack.l_mark[-1].ipp = n->ipn_next;
						free(n);
					  }
					  resetlexer();
					  use_inet6 = 0;
					}
break;
case 6:
#line 114 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ iphtent_t *h;
					  ipht.iph_unit = ippool_yystack.l_mark[-2].num;
					  ipht.iph_type = IPHASH_LOOKUP;
					  load_hash(&ipht, ippool_yystack.l_mark[-1].ipe, poolioctl);
					  while ((h = ippool_yystack.l_mark[-1].ipe) != NULL) {
						ippool_yystack.l_mark[-1].ipe = h->ipe_next;
						free(h);
					  }
					  resetlexer();
					  use_inet6 = 0;
					}
break;
case 7:
#line 126 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ iphtent_t *h;
					  ipht.iph_unit = ippool_yystack.l_mark[-3].num;
					  strncpy(ipht.iph_name, ippool_yystack.l_mark[-2].str,
						  sizeof(ipht.iph_name));
					  ipht.iph_type = IPHASH_GROUPMAP;
					  load_hash(&ipht, ippool_yystack.l_mark[-1].ipe, poolioctl);
					  while ((h = ippool_yystack.l_mark[-1].ipe) != NULL) {
						ippool_yystack.l_mark[-1].ipe = h->ipe_next;
						free(h);
					  }
					  resetlexer();
					  use_inet6 = 0;
					}
break;
case 11:
#line 146 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ set_variable(ippool_yystack.l_mark[-3].str, ippool_yystack.l_mark[-1].str);
					  resetlexer();
					  free(ippool_yystack.l_mark[-3].str);
					  free(ippool_yystack.l_mark[-1].str);
					  ippool_yyvarnext = 0;
					}
break;
case 12:
#line 155 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyvarnext = 1; }
break;
case 13:
#line 158 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ bzero((char *)&ipht, sizeof(ipht));
				  bzero((char *)&iphte, sizeof(iphte));
				  bzero((char *)&iplo, sizeof(iplo));
				  bzero((char *)&ipld, sizeof(ipld));
				  *ipht.iph_name = '\0';
				  iplo.ipo_flags = IPHASH_ANON;
				  iplo.ipo_name[0] = '\0';
				}
break;
case 14:
#line 169 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ bzero((char *)&ipht, sizeof(ipht));
				  bzero((char *)&iphte, sizeof(iphte));
				  *ipht.iph_name = '\0';
				  ipht.iph_unit = IPHASH_GROUPMAP;
				  ipht.iph_flags = ippool_yystack.l_mark[0].num;
				}
break;
case 15:
#line 177 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = FR_INQUE; }
break;
case 16:
#line 178 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = FR_OUTQUE; }
break;
case 17:
#line 181 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = ippool_yystack.l_mark[0].num; }
break;
case 18:
#line 184 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = IPL_LOGIPF; }
break;
case 19:
#line 185 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = IPL_LOGNAT; }
break;
case 20:
#line 186 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = IPL_LOGAUTH; }
break;
case 21:
#line 187 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = IPL_LOGCOUNT; }
break;
case 22:
#line 188 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = IPL_LOGALL; }
break;
case 23:
#line 193 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ strncpy(iplo.ipo_name, ippool_yystack.l_mark[-3].str,
						  sizeof(iplo.ipo_name));
					  ippool_yyval.ipp = ippool_yystack.l_mark[-1].ipp;
					}
break;
case 24:
#line 201 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ strncpy(ipht.iph_name, ippool_yystack.l_mark[-4].str,
						  sizeof(ipht.iph_name));
					  ippool_yyval.ipe = ippool_yystack.l_mark[-1].ipe;
					}
break;
case 25:
#line 209 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ iphtent_t *e;
					  for (e = ippool_yystack.l_mark[-1].ipe; e != NULL;
					       e = e->ipe_next)
						if (e->ipe_group[0] == '\0')
							strncpy(e->ipe_group,
								ippool_yystack.l_mark[-4].str,
								FR_GROUPLEN);
					  ippool_yyval.ipe = ippool_yystack.l_mark[-1].ipe;
					  free(ippool_yystack.l_mark[-4].str);
					}
break;
case 26:
#line 220 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = ippool_yystack.l_mark[-1].ipe; }
break;
case 27:
#line 223 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ sprintf(poolname, "%u", ippool_yystack.l_mark[0].num);
						  ippool_yyval.str = poolname;
						}
break;
case 28:
#line 226 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ strncpy(poolname, ippool_yystack.l_mark[0].str,
							  FR_GROUPLEN);
						  poolname[FR_GROUPLEN-1]='\0';
						  free(ippool_yystack.l_mark[0].str);
						  ippool_yyval.str = poolname;
						}
break;
case 29:
#line 232 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.str = ""; }
break;
case 30:
#line 236 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ char tmp[FR_GROUPLEN+1];
					  strncpy(tmp, ippool_yystack.l_mark[0].str, FR_GROUPLEN);
					  ippool_yyval.str = strdup(tmp);
					  free(ippool_yystack.l_mark[0].str);
					}
break;
case 31:
#line 241 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ char tmp[FR_GROUPLEN+1];
					  sprintf(tmp, "%u", ippool_yystack.l_mark[0].num);
					  ippool_yyval.str = strdup(tmp);
					}
break;
case 36:
#line 254 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipp = NULL; }
break;
case 37:
#line 255 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipp = ippool_yystack.l_mark[-2].ipp;
					  while (ippool_yystack.l_mark[-2].ipp->ipn_next != NULL)
						ippool_yystack.l_mark[-2].ipp = ippool_yystack.l_mark[-2].ipp->ipn_next;
					  ippool_yystack.l_mark[-2].ipp->ipn_next = ippool_yystack.l_mark[0].ipp;
					}
break;
case 38:
#line 260 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipp = ippool_yystack.l_mark[-1].ipp; }
break;
case 39:
#line 264 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = NULL; }
break;
case 40:
#line 265 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = ippool_yystack.l_mark[-2].ipe; ippool_yystack.l_mark[-2].ipe->ipe_next = ippool_yystack.l_mark[0].ipe; }
break;
case 41:
#line 266 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = calloc(1, sizeof(iphtent_t));
					  ippool_yyval.ipe->ipe_addr = ippool_yystack.l_mark[-2].adrmsk[0].adf_addr;
					  ippool_yyval.ipe->ipe_mask = ippool_yystack.l_mark[-2].adrmsk[1].adf_addr;
					  ippool_yyval.ipe->ipe_family = ippool_yystack.l_mark[-2].adrmsk[0].adf_family;
					  ippool_yyval.ipe->ipe_next = ippool_yystack.l_mark[0].ipe;
					}
break;
case 42:
#line 272 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = ippool_yystack.l_mark[-1].ipe; }
break;
case 43:
#line 273 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = calloc(1, sizeof(iphtent_t));
					  ippool_yyval.ipe->ipe_addr = ippool_yystack.l_mark[-1].adrmsk[0].adf_addr;
					  ippool_yyval.ipe->ipe_mask = ippool_yystack.l_mark[-1].adrmsk[1].adf_addr;
#ifdef AF_INET6
					  if (use_inet6)
						ippool_yyval.ipe->ipe_family = AF_INET6;
					  else
#endif
						ippool_yyval.ipe->ipe_family = AF_INET;
					}
break;
case 44:
#line 283 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = add_htablehosts(ippool_yystack.l_mark[0].str);
					  free(ippool_yystack.l_mark[0].str);
					}
break;
case 45:
#line 289 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = NULL; }
break;
case 46:
#line 290 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = ippool_yystack.l_mark[-1].ipe; }
break;
case 47:
#line 291 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yystack.l_mark[-2].ipe->ipe_next = ippool_yystack.l_mark[0].ipe; ippool_yyval.ipe = ippool_yystack.l_mark[-2].ipe; }
break;
case 48:
#line 295 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = calloc(1, sizeof(iphtent_t));
					  ippool_yyval.ipe->ipe_addr = ippool_yystack.l_mark[-2].adrmsk[0].adf_addr;
					  ippool_yyval.ipe->ipe_mask = ippool_yystack.l_mark[-2].adrmsk[1].adf_addr;
					  strncpy(ippool_yyval.ipe->ipe_group, ippool_yystack.l_mark[0].str,
						  FR_GROUPLEN);
#ifdef AF_INET6
					  if (use_inet6)
						ippool_yyval.ipe->ipe_family = AF_INET6;
					  else
#endif
						ippool_yyval.ipe->ipe_family = AF_INET;
					  free(ippool_yystack.l_mark[0].str);
					}
break;
case 49:
#line 310 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipp = calloc(1, sizeof(*ippool_yyval.ipp));
					  ippool_yyval.ipp->ipn_info = 0;
					  ippool_yyval.ipp->ipn_addr = ippool_yystack.l_mark[0].adrmsk[0];
					  ippool_yyval.ipp->ipn_mask = ippool_yystack.l_mark[0].adrmsk[1];
					}
break;
case 50:
#line 315 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipp = calloc(1, sizeof(*ippool_yyval.ipp));
					  ippool_yyval.ipp->ipn_info = 1;
					  ippool_yyval.ipp->ipn_addr = ippool_yystack.l_mark[0].adrmsk[0];
					  ippool_yyval.ipp->ipn_mask = ippool_yystack.l_mark[0].adrmsk[1];
					}
break;
case 51:
#line 320 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipp = add_poolhosts(ippool_yystack.l_mark[0].str);
					  free(ippool_yystack.l_mark[0].str);
					}
break;
case 52:
#line 323 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipp = read_whoisfile(ippool_yystack.l_mark[0].str);
					  free(ippool_yystack.l_mark[0].str);
					}
break;
case 53:
#line 329 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = NULL; }
break;
case 54:
#line 330 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = ippool_yystack.l_mark[-1].ipe; }
break;
case 55:
#line 331 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yystack.l_mark[-2].ipe->ipe_next = ippool_yystack.l_mark[0].ipe; ippool_yyval.ipe = ippool_yystack.l_mark[-2].ipe; }
break;
case 56:
#line 335 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = calloc(1, sizeof(iphtent_t));
				  ippool_yyval.ipe->ipe_addr = ippool_yystack.l_mark[0].adrmsk[0].adf_addr;
				  ippool_yyval.ipe->ipe_mask = ippool_yystack.l_mark[0].adrmsk[1].adf_addr;
#ifdef USE_INET6
				  if (use_inet6)
					ippool_yyval.ipe->ipe_family = AF_INET6;
				  else
#endif
					ippool_yyval.ipe->ipe_family = AF_INET;
				}
break;
case 57:
#line 345 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipe = add_htablehosts(ippool_yystack.l_mark[0].str);
				  free(ippool_yystack.l_mark[0].str);
				}
break;
case 58:
#line 351 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.adrmsk[0] = ippool_yystack.l_mark[-2].ipa;
				  setadflen(&ippool_yyval.adrmsk[0]);
				  ippool_yyval.adrmsk[1] = ippool_yystack.l_mark[0].ipa;
				  ippool_yyval.adrmsk[1].adf_len = ippool_yyval.adrmsk[0].adf_len;
				}
break;
case 59:
#line 356 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.adrmsk[0] = ippool_yystack.l_mark[0].ipa;
				  setadflen(&ippool_yyval.adrmsk[1]);
				  ippool_yyval.adrmsk[1].adf_len = ippool_yyval.adrmsk[0].adf_len;
#ifdef USE_INET6
				  if (use_inet6)
					memset(&ippool_yyval.adrmsk[1].adf_addr, 0xff,
					       sizeof(ippool_yyval.adrmsk[1].adf_addr.in6));
				  else
#endif
					memset(&ippool_yyval.adrmsk[1].adf_addr, 0xff, 
					       sizeof(ippool_yyval.adrmsk[1].adf_addr.in4));
				}
break;
case 60:
#line 370 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipa.adf_addr.in4 = ippool_yystack.l_mark[0].ip4;
				  ippool_yyval.ipa.adf_family = AF_INET;
				  setadflen(&ippool_yyval.ipa);
				  use_inet6 = 0;
				}
break;
case 61:
#line 375 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipa.adf_addr.in4.s_addr = htonl(ippool_yystack.l_mark[0].num);
				  ippool_yyval.ipa.adf_family = AF_INET;
				  setadflen(&ippool_yyval.ipa);
				  use_inet6 = 0;
				}
break;
case 62:
#line 380 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipa.adf_addr = ippool_yystack.l_mark[0].ip6;
				  ippool_yyval.ipa.adf_family = AF_INET6;
				  setadflen(&ippool_yyval.ipa);
				  use_inet6 = 1;
				}
break;
case 63:
#line 387 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ bzero(&ippool_yyval.ipa, sizeof(ippool_yyval.ipa));
			  if (use_inet6) {
				if (ntomask(AF_INET6, ippool_yystack.l_mark[0].num,
					    (u_32_t *)&ippool_yyval.ipa.adf_addr) == -1)
					ippool_yyerror("bad bitmask");
			  } else {
				if (ntomask(AF_INET, ippool_yystack.l_mark[0].num,
					    (u_32_t *)&ippool_yyval.ipa.adf_addr.in4) == -1)
					ippool_yyerror("bad bitmask");
			  }
			}
break;
case 64:
#line 398 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ bzero(&ippool_yyval.ipa, sizeof(ippool_yyval.ipa));
			  ippool_yyval.ipa.adf_addr.in4 = ippool_yystack.l_mark[0].ip4;
			}
break;
case 65:
#line 401 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ bzero(&ippool_yyval.ipa, sizeof(ippool_yyval.ipa));
			  ippool_yyval.ipa.adf_addr = ippool_yystack.l_mark[0].ip6;
			}
break;
case 66:
#line 406 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ipht.iph_size = ippool_yystack.l_mark[0].num; }
break;
case 67:
#line 409 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ipht.iph_seed = ippool_yystack.l_mark[0].num; }
break;
case 68:
#line 413 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ if (ippool_yystack.l_mark[-6].num > 255 || ippool_yystack.l_mark[-4].num > 255 || ippool_yystack.l_mark[-2].num > 255 || ippool_yystack.l_mark[0].num > 255) {
			ippool_yyerror("Invalid octet string for IP address");
			return 0;
		  }
		  ippool_yyval.ip4.s_addr = (ippool_yystack.l_mark[-6].num << 24) | (ippool_yystack.l_mark[-4].num << 16) | (ippool_yystack.l_mark[-2].num << 8) | ippool_yystack.l_mark[0].num;
		  ippool_yyval.ip4.s_addr = htonl(ippool_yyval.ip4.s_addr);
		}
break;
case 69:
#line 422 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyexpectaddr = 1; }
break;
case 70:
#line 425 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyexpectaddr = 1; }
break;
case 71:
#line 428 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyexpectaddr = 0; }
break;
case 72:
#line 434 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ bzero((char *)&ipld, sizeof(ipld));
					  strncpy(ipld.ipld_name, ippool_yystack.l_mark[-6].str,
						  sizeof(ipld.ipld_name));
					  ipld.ipld_unit = ippool_yystack.l_mark[-10].num;
					  ipld.ipld_policy = ippool_yystack.l_mark[-4].num;
					  load_dstlist(&ipld, poolioctl, ippool_yystack.l_mark[-1].ipd);
					  resetlexer();
					  use_inet6 = 0;
					  free(ippool_yystack.l_mark[-6].str);
					}
break;
case 73:
#line 446 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ bzero((char *)&iplo, sizeof(iplo));
					  strncpy(iplo.ipo_name, ippool_yystack.l_mark[-5].str,
						  sizeof(iplo.ipo_name));
					  iplo.ipo_list = ippool_yystack.l_mark[-1].ipp;
					  iplo.ipo_unit = ippool_yystack.l_mark[-9].num;
					  load_pool(&iplo, poolioctl);
					  resetlexer();
					  use_inet6 = 0;
					  free(ippool_yystack.l_mark[-5].str);
					}
break;
case 74:
#line 457 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ bzero((char *)&iplo, sizeof(iplo));
					  strncpy(iplo.ipo_name, ippool_yystack.l_mark[-5].str,
						  sizeof(iplo.ipo_name));
					  iplo.ipo_list = ippool_yystack.l_mark[-1].ipp;
					  iplo.ipo_unit = IPL_LOGALL;
					  load_pool(&iplo, poolioctl);
					  resetlexer();
					  use_inet6 = 0;
					  free(ippool_yystack.l_mark[-5].str);
					}
break;
case 75:
#line 469 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ iphtent_t *h;
					  bzero((char *)&ipht, sizeof(ipht));
					  strncpy(ipht.iph_name, ippool_yystack.l_mark[-6].str,
						  sizeof(ipht.iph_name));
					  ipht.iph_unit = ippool_yystack.l_mark[-10].num;
					  load_hash(&ipht, ippool_yystack.l_mark[-1].ipe, poolioctl);
					  while ((h = ipht.iph_list) != NULL) {
						ipht.iph_list = h->ipe_next;
						free(h);
					  }
					  resetlexer();
					  use_inet6 = 0;
					  free(ippool_yystack.l_mark[-6].str);
					}
break;
case 76:
#line 485 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ iphtent_t *h;
					  bzero((char *)&ipht, sizeof(ipht));
					  strncpy(ipht.iph_name, ippool_yystack.l_mark[-7].str,
						  sizeof(ipht.iph_name));
					  ipht.iph_type = IPHASH_GROUPMAP;
					  ipht.iph_unit = IPL_LOGIPF;
					  ipht.iph_flags = ippool_yystack.l_mark[-5].num;
					  load_hash(&ipht, ippool_yystack.l_mark[-1].ipe, poolioctl);
					  while ((h = ipht.iph_list) != NULL) {
						ipht.iph_list = h->ipe_next;
						free(h);
					  }
					  resetlexer();
					  use_inet6 = 0;
					  free(ippool_yystack.l_mark[-7].str);
					}
break;
case 77:
#line 503 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.str = ippool_yystack.l_mark[0].str; }
break;
case 78:
#line 504 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ char name[80];
					  sprintf(name, "%d", ippool_yystack.l_mark[0].num);
					  ippool_yyval.str = strdup(name);
					}
break;
case 84:
#line 520 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipd = ippool_yystack.l_mark[0].ipd; }
break;
case 85:
#line 521 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipd = NULL; }
break;
case 86:
#line 525 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipd = ippool_yystack.l_mark[-1].ipd; }
break;
case 87:
#line 526 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yystack.l_mark[-2].ipd->ipfd_next = ippool_yystack.l_mark[0].ipd; ippool_yyval.ipd = ippool_yystack.l_mark[-2].ipd; }
break;
case 88:
#line 530 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ int size = sizeof(*ippool_yyval.ipd) + strlen(ippool_yystack.l_mark[-2].str) + 1;
				  ippool_yyval.ipd = calloc(1, size);
				  if (ippool_yyval.ipd != NULL) {
					ippool_yyval.ipd->ipfd_dest.fd_name = strlen(ippool_yystack.l_mark[-2].str) + 1;
					bcopy(ippool_yystack.l_mark[-2].str, ippool_yyval.ipd->ipfd_names,
					      ippool_yyval.ipd->ipfd_dest.fd_name);
					ippool_yyval.ipd->ipfd_dest.fd_addr = ippool_yystack.l_mark[0].ipa;
					ippool_yyval.ipd->ipfd_size = size;
				  }
				  free(ippool_yystack.l_mark[-2].str);
				}
break;
case 89:
#line 541 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.ipd = calloc(1, sizeof(*ippool_yyval.ipd));
				  if (ippool_yyval.ipd != NULL) {
					ippool_yyval.ipd->ipfd_dest.fd_name = -1;
					ippool_yyval.ipd->ipfd_dest.fd_addr = ippool_yystack.l_mark[0].ipa;
					ippool_yyval.ipd->ipfd_size = sizeof(*ippool_yyval.ipd);
				  }
				}
break;
case 90:
#line 551 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = IPLDP_NONE; }
break;
case 91:
#line 552 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = IPLDP_ROUNDROBIN; }
break;
case 92:
#line 553 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = ippool_yystack.l_mark[-1].num; }
break;
case 93:
#line 554 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = IPLDP_RANDOM; }
break;
case 94:
#line 555 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = IPLDP_HASHED; }
break;
case 95:
#line 556 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = IPLDP_SRCHASH; }
break;
case 96:
#line 557 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = IPLDP_DSTHASH; }
break;
case 97:
#line 561 "/usr/home/freebsd/omega/src/sbin/ipf/ippool/../../../contrib/ipfilter/tools/ippool_y.y"
	{ ippool_yyval.num = IPLDP_CONNECTION; }
break;
#line 1534 "y.tab.c"
    }
    ippool_yystack.s_mark -= ippool_yym;
    ippool_yystate = *ippool_yystack.s_mark;
    ippool_yystack.l_mark -= ippool_yym;
    ippool_yym = ippool_yylhs[ippool_yyn];
    if (ippool_yystate == 0 && ippool_yym == 0)
    {
#if YYDEBUG
        if (ippool_yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        ippool_yystate = YYFINAL;
        *++ippool_yystack.s_mark = YYFINAL;
        *++ippool_yystack.l_mark = ippool_yyval;
        if (ippool_yychar < 0)
        {
            if ((ippool_yychar = YYLEX) < 0) ippool_yychar = YYEOF;
#if YYDEBUG
            if (ippool_yydebug)
            {
                ippool_yys = ippool_yyname[YYTRANSLATE(ippool_yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, ippool_yychar, ippool_yys);
            }
#endif
        }
        if (ippool_yychar == YYEOF) goto ippool_yyaccept;
        goto ippool_yyloop;
    }
    if ((ippool_yyn = ippool_yygindex[ippool_yym]) && (ippool_yyn += ippool_yystate) >= 0 &&
            ippool_yyn <= YYTABLESIZE && ippool_yycheck[ippool_yyn] == ippool_yystate)
        ippool_yystate = ippool_yytable[ippool_yyn];
    else
        ippool_yystate = ippool_yydgoto[ippool_yym];
#if YYDEBUG
    if (ippool_yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *ippool_yystack.s_mark, ippool_yystate);
#endif
    if (ippool_yystack.s_mark >= ippool_yystack.s_last && ippool_yygrowstack(&ippool_yystack) == YYENOMEM)
    {
        goto ippool_yyoverflow;
    }
    *++ippool_yystack.s_mark = (YYINT) ippool_yystate;
    *++ippool_yystack.l_mark = ippool_yyval;
    goto ippool_yyloop;

ippool_yyoverflow:
    YYERROR_CALL("yacc stack overflow");

ippool_yyabort:
    ippool_yyfreestack(&ippool_yystack);
    return (1);

ippool_yyaccept:
    ippool_yyfreestack(&ippool_yystack);
    return (0);
}
