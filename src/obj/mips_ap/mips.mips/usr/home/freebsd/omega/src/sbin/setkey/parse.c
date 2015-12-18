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

#line 34 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>

#include <net/route.h>
#include <netinet/in.h>
#include <net/pfkeyv2.h>
#include <netipsec/key_var.h>
#include <netipsec/ipsec.h>
#include <arpa/inet.h>

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <ctype.h>
#include <errno.h>

#include "libpfkey.h"
#include "vchar.h"

#define ATOX(c) \
  (isdigit(c) ? (c - '0') : (isupper(c) ? (c - 'A' + 10) : (c - 'a' + 10)))

u_int32_t p_spi;
u_int p_ext, p_alg_enc, p_alg_auth, p_replay, p_mode;
u_int32_t p_reqid;
u_int p_key_enc_len, p_key_auth_len;
caddr_t p_key_enc, p_key_auth;
time_t p_lt_hard, p_lt_soft;

static int p_aiflags = 0, p_aifamily = PF_UNSPEC;

static struct addrinfo *parse_addr(char *, char *);
static int fix_portstr(vchar_t *, vchar_t *, vchar_t *);
static int setvarbuf(char *, int *, struct sadb_ext *, int, caddr_t, int);
void parse_init(void);
void free_buffer(void);

int setkeymsg0(struct sadb_msg *, unsigned int, unsigned int, size_t);
static int setkeymsg_spdaddr(unsigned int, unsigned int, vchar_t *,
	struct addrinfo *, int, struct addrinfo *, int);
static int setkeymsg_addr(unsigned int, unsigned int,
	struct addrinfo *, struct addrinfo *, int);
static int setkeymsg_add(unsigned int, unsigned int,
	struct addrinfo *, struct addrinfo *);
extern int setkeymsg(char *, size_t *);
extern int sendkeymsg(char *, size_t);

extern int yylex(void);
extern void yyfatal(const char *);
extern void yyerror(const char *);
#line 88 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int num;
	unsigned long ulnum;
	vchar_t val;
	struct addrinfo *res;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 88 "y.tab.c"

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

#define EOT 257
#define SLASH 258
#define BLCL 259
#define ELCL 260
#define ADD 261
#define GET 262
#define DELETE 263
#define DELETEALL 264
#define FLUSH 265
#define DUMP 266
#define PR_ESP 267
#define PR_AH 268
#define PR_IPCOMP 269
#define PR_TCP 270
#define F_PROTOCOL 271
#define F_AUTH 272
#define F_ENC 273
#define F_REPLAY 274
#define F_COMP 275
#define F_RAWCPI 276
#define F_MODE 277
#define MODE 278
#define F_REQID 279
#define F_EXT 280
#define EXTENSION 281
#define NOCYCLICSEQ 282
#define ALG_AUTH 283
#define ALG_AUTH_NOKEY 284
#define ALG_ENC 285
#define ALG_ENC_NOKEY 286
#define ALG_ENC_DESDERIV 287
#define ALG_ENC_DES32IV 288
#define ALG_ENC_OLD 289
#define ALG_ENC_SALT 290
#define ALG_COMP 291
#define F_LIFETIME_HARD 292
#define F_LIFETIME_SOFT 293
#define DECSTRING 294
#define QUOTEDSTRING 295
#define HEXSTRING 296
#define STRING 297
#define ANY 298
#define SPDADD 299
#define SPDDELETE 300
#define SPDDUMP 301
#define SPDFLUSH 302
#define F_POLICY 303
#define PL_REQUESTS 304
#define F_AIFLAGS 305
#define TAGGED 306
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   11,   13,   14,   12,   15,   16,    2,    2,
    2,    2,    2,   22,   22,   24,   24,   24,   25,   25,
   26,   27,   27,   28,   28,   28,   28,   28,   28,   29,
   29,    5,    5,   23,   23,   30,   30,   30,   30,   30,
   30,   30,   30,   17,   17,   18,   19,   20,   21,   21,
   31,    9,    1,    1,    4,    4,    4,    4,    3,    3,
    3,    3,    3,    7,    7,    8,    6,
};
static const YYINT yylen[] = {                            2,
    0,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    9,    8,    6,    8,    3,    3,    0,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    4,    2,
    2,    2,    3,    1,    2,    1,    2,    2,    2,    2,
    1,    1,    1,    0,    2,    2,    2,    2,    2,    2,
    2,    2,    2,   12,    5,   12,    2,    2,    0,    2,
    1,    1,    0,    2,    0,    3,    3,    3,    1,    1,
    1,    1,    1,    0,    1,    2,    1,
};
static const YYINT yydefred[] = {                         1,
    0,   59,   59,   59,   59,    0,    0,    0,   59,    0,
    0,    2,    3,    4,    5,    6,    7,    8,    9,   10,
   11,   12,    0,    0,    0,    0,   20,   21,   22,   23,
    0,    0,    0,    0,    0,   57,   58,   62,   61,    0,
   60,    0,    0,    0,   17,   18,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   77,   76,   55,   64,    0,    0,    0,   24,
   25,   44,   44,   44,   15,    0,    0,    0,    0,    0,
    0,    0,    0,   67,   68,   66,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   26,   27,
   28,   45,   16,   14,    0,    0,    0,   41,   31,    0,
   34,    0,    0,   36,    0,    0,   51,    0,   48,   49,
   50,   46,   47,   52,   53,   13,   72,   71,   69,   73,
   70,    0,    0,   42,   43,   40,   35,   37,   38,   39,
    0,   33,   75,    0,    0,   29,    0,    0,   54,   56,
};
static const YYINT yydgoto[] = {                          1,
   57,   31,  132,   68,  136,   64,  144,   55,   40,   12,
   13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
   23,   72,   81,   98,   99,  100,  101,  116,  109,  102,
   41,
};
static const YYINT yysindex[] = {                         0,
 -260,    0,    0,    0,    0, -155, -155, -281,    0, -239,
 -223,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -289, -289, -289, -289,    0,    0,    0,    0,
 -220, -193, -194, -288, -286,    0,    0,    0,    0, -200,
    0, -200, -200, -200,    0,    0, -183, -133, -133, -155,
 -155, -155, -155, -178, -130, -166, -129, -129, -272, -272,
 -272, -128,    0,    0,    0,    0, -224, -165, -164,    0,
    0,    0,    0,    0,    0, -126, -125, -124, -133, -133,
 -197, -225, -221,    0,    0,    0, -129, -129, -269, -198,
 -163, -154, -271, -156, -173, -153, -152, -118,    0,    0,
    0,    0,    0,    0, -237, -237, -179,    0,    0, -179,
    0, -179, -179,    0, -179, -132,    0, -131,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -151, -151,    0,    0,    0,    0,    0,    0,    0,
 -269,    0,    0, -183, -183,    0, -114, -113,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0, -110, -110, -284,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -249, -249, -215,
 -215, -215, -110,    0,    0,    0, -149, -149,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -247, -247,
    0,    0,    0,    0,    0,    0, -232, -232,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -108,    0, -107,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -150, -150,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   14,   -7,   45,   11,  -84,    0,   19,  -26,   60,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  102,   61,   50,    0,    0,    0,    0,    0,   13,    0,
    0,
};
#define YYTABLESIZE 154
static const YYINT yytable[] = {                         32,
    2,    3,    4,    5,    6,    7,  119,   38,   48,   63,
   49,   63,   59,  107,  108,   39,   39,   36,   39,   63,
   59,   70,   63,   71,   33,  137,  120,  138,  139,  127,
  140,  103,  128,   37,   65,  104,   45,   65,    8,    9,
   10,   11,   59,   60,   61,   62,   63,   63,   91,   63,
   63,   93,   91,   94,   95,   93,  129,   94,   95,  130,
  131,   65,   58,   46,   65,   65,   96,   97,   69,   76,
   96,   97,   77,   78,   89,   90,   91,   92,   19,   93,
   19,   94,   95,   42,   43,   44,  110,  111,  112,  113,
  114,  115,   87,   88,   96,   97,   38,  105,  106,   50,
   47,   51,   52,   53,   24,   25,   26,  122,  123,   34,
   35,   27,   28,   29,   30,  134,  135,  147,  148,   54,
   73,   74,   82,   83,   56,   63,   65,   66,   75,   67,
  117,   79,   80,   84,   85,   86,  118,  121,  126,  141,
  124,  125,  149,  150,  142,  143,   19,   65,   30,   32,
  133,  145,   74,  146,
};
static const YYINT yycheck[] = {                          7,
  261,  262,  263,  264,  265,  266,  278,  297,  297,  259,
  297,  259,  297,  283,  284,  305,  305,  257,  305,  267,
  305,  294,  270,  296,  306,  110,  298,  112,  113,  267,
  115,  257,  270,  257,  267,  257,  257,  270,  299,  300,
  301,  302,   50,   51,   52,   53,  294,  297,  274,  297,
  298,  277,  274,  279,  280,  277,  294,  279,  280,  297,
  298,  294,   49,  257,  297,  298,  292,  293,   58,  294,
  292,  293,  297,  298,  272,  273,  274,  275,  294,  277,
  296,  279,  280,   24,   25,   26,  285,  286,  287,  288,
  289,  290,   79,   80,  292,  293,  297,   87,   88,   40,
  295,   42,   43,   44,    3,    4,    5,  281,  282,    8,
    9,  267,  268,  269,  270,  295,  296,  144,  145,  303,
   60,   61,   73,   74,  258,  304,  257,  294,  257,  259,
  294,  297,  297,  260,  260,  260,  291,  294,  257,  272,
  294,  294,  257,  257,  276,  297,  257,  297,  257,  257,
  106,  133,  303,  141,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
#define YYUNDFTOKEN 340
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"EOT","SLASH","BLCL","ELCL","ADD",
"GET","DELETE","DELETEALL","FLUSH","DUMP","PR_ESP","PR_AH","PR_IPCOMP","PR_TCP",
"F_PROTOCOL","F_AUTH","F_ENC","F_REPLAY","F_COMP","F_RAWCPI","F_MODE","MODE",
"F_REQID","F_EXT","EXTENSION","NOCYCLICSEQ","ALG_AUTH","ALG_AUTH_NOKEY",
"ALG_ENC","ALG_ENC_NOKEY","ALG_ENC_DESDERIV","ALG_ENC_DES32IV","ALG_ENC_OLD",
"ALG_ENC_SALT","ALG_COMP","F_LIFETIME_HARD","F_LIFETIME_SOFT","DECSTRING",
"QUOTEDSTRING","HEXSTRING","STRING","ANY","SPDADD","SPDDELETE","SPDDUMP",
"SPDFLUSH","F_POLICY","PL_REQUESTS","F_AIFLAGS","TAGGED",0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : commands",
"commands :",
"commands : commands command",
"command : add_command",
"command : get_command",
"command : delete_command",
"command : deleteall_command",
"command : flush_command",
"command : dump_command",
"command : spdadd_command",
"command : spddelete_command",
"command : spddump_command",
"command : spdflush_command",
"add_command : ADD ipaddropts ipaddr ipaddr protocol_spec spi extension_spec algorithm_spec EOT",
"delete_command : DELETE ipaddropts ipaddr ipaddr protocol_spec spi extension_spec EOT",
"deleteall_command : DELETEALL ipaddropts ipaddr ipaddr protocol_spec EOT",
"get_command : GET ipaddropts ipaddr ipaddr protocol_spec spi extension_spec EOT",
"flush_command : FLUSH protocol_spec EOT",
"dump_command : DUMP protocol_spec EOT",
"protocol_spec :",
"protocol_spec : PR_ESP",
"protocol_spec : PR_AH",
"protocol_spec : PR_IPCOMP",
"protocol_spec : PR_TCP",
"spi : DECSTRING",
"spi : HEXSTRING",
"algorithm_spec : esp_spec",
"algorithm_spec : ah_spec",
"algorithm_spec : ipcomp_spec",
"esp_spec : F_ENC enc_alg F_AUTH auth_alg",
"esp_spec : F_ENC enc_alg",
"ah_spec : F_AUTH auth_alg",
"ipcomp_spec : F_COMP ALG_COMP",
"ipcomp_spec : F_COMP ALG_COMP F_RAWCPI",
"enc_alg : ALG_ENC_NOKEY",
"enc_alg : ALG_ENC key_string",
"enc_alg : ALG_ENC_OLD",
"enc_alg : ALG_ENC_DESDERIV key_string",
"enc_alg : ALG_ENC_DES32IV key_string",
"enc_alg : ALG_ENC_SALT key_string",
"auth_alg : ALG_AUTH key_string",
"auth_alg : ALG_AUTH_NOKEY",
"key_string : QUOTEDSTRING",
"key_string : HEXSTRING",
"extension_spec :",
"extension_spec : extension_spec extension",
"extension : F_EXT EXTENSION",
"extension : F_EXT NOCYCLICSEQ",
"extension : F_MODE MODE",
"extension : F_MODE ANY",
"extension : F_REQID DECSTRING",
"extension : F_REPLAY DECSTRING",
"extension : F_LIFETIME_HARD DECSTRING",
"extension : F_LIFETIME_SOFT DECSTRING",
"spdadd_command : SPDADD ipaddropts STRING prefix portstr STRING prefix portstr upper_spec upper_misc_spec policy_spec EOT",
"spdadd_command : SPDADD TAGGED QUOTEDSTRING policy_spec EOT",
"spddelete_command : SPDDELETE ipaddropts STRING prefix portstr STRING prefix portstr upper_spec upper_misc_spec policy_spec EOT",
"spddump_command : SPDDUMP EOT",
"spdflush_command : SPDFLUSH EOT",
"ipaddropts :",
"ipaddropts : ipaddropts ipaddropt",
"ipaddropt : F_AIFLAGS",
"ipaddr : STRING",
"prefix :",
"prefix : SLASH DECSTRING",
"portstr :",
"portstr : BLCL ANY ELCL",
"portstr : BLCL DECSTRING ELCL",
"portstr : BLCL STRING ELCL",
"upper_spec : DECSTRING",
"upper_spec : ANY",
"upper_spec : PR_TCP",
"upper_spec : PR_ESP",
"upper_spec : STRING",
"upper_misc_spec :",
"upper_misc_spec : STRING",
"policy_spec : F_POLICY policy_requests",
"policy_requests : PL_REQUESTS",

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
#line 769 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"

int
setkeymsg0(msg, type, satype, l)
	struct sadb_msg *msg;
	unsigned int type;
	unsigned int satype;
	size_t l;
{

	msg->sadb_msg_version = PF_KEY_V2;
	msg->sadb_msg_type = type;
	msg->sadb_msg_errno = 0;
	msg->sadb_msg_satype = satype;
	msg->sadb_msg_reserved = 0;
	msg->sadb_msg_seq = 0;
	msg->sadb_msg_pid = getpid();
	msg->sadb_msg_len = PFKEY_UNIT64(l);
	return 0;
}

/* XXX NO BUFFER OVERRUN CHECK! BAD BAD! */
static int
setkeymsg_spdaddr(type, upper, policy, srcs, splen, dsts, dplen)
	unsigned int type;
	unsigned int upper;
	vchar_t *policy;
	struct addrinfo *srcs;
	int splen;
	struct addrinfo *dsts;
	int dplen;
{
	struct sadb_msg *msg;
	char buf[BUFSIZ];
	int l, l0;
	struct sadb_address m_addr;
	struct addrinfo *s, *d;
	int n;
	int plen;
	struct sockaddr *sa;
	int salen;

	msg = (struct sadb_msg *)buf;

	if (!srcs || !dsts)
		return -1;

	/* fix up length afterwards */
	setkeymsg0(msg, type, SADB_SATYPE_UNSPEC, 0);
	l = sizeof(struct sadb_msg);

	memcpy(buf + l, policy->buf, policy->len);
	l += policy->len;

	l0 = l;
	n = 0;

	/* do it for all src/dst pairs */
	for (s = srcs; s; s = s->ai_next) {
		for (d = dsts; d; d = d->ai_next) {
			/* rewind pointer */
			l = l0;

			if (s->ai_addr->sa_family != d->ai_addr->sa_family)
				continue;
			switch (s->ai_addr->sa_family) {
			case AF_INET:
				plen = sizeof(struct in_addr) << 3;
				break;
#ifdef INET6
			case AF_INET6:
				plen = sizeof(struct in6_addr) << 3;
				break;
#endif
			default:
				continue;
			}

			/* set src */
			sa = s->ai_addr;
			salen = s->ai_addr->sa_len;
			m_addr.sadb_address_len = PFKEY_UNIT64(sizeof(m_addr) +
			    PFKEY_ALIGN8(salen));
			m_addr.sadb_address_exttype = SADB_EXT_ADDRESS_SRC;
			m_addr.sadb_address_proto = upper;
			m_addr.sadb_address_prefixlen =
			    (splen >= 0 ? splen : plen);
			m_addr.sadb_address_reserved = 0;

			setvarbuf(buf, &l, (struct sadb_ext *)&m_addr,
			    sizeof(m_addr), (caddr_t)sa, salen);

			/* set dst */
			sa = d->ai_addr;
			salen = d->ai_addr->sa_len;
			m_addr.sadb_address_len = PFKEY_UNIT64(sizeof(m_addr) +
			    PFKEY_ALIGN8(salen));
			m_addr.sadb_address_exttype = SADB_EXT_ADDRESS_DST;
			m_addr.sadb_address_proto = upper;
			m_addr.sadb_address_prefixlen =
			    (dplen >= 0 ? dplen : plen);
			m_addr.sadb_address_reserved = 0;

			setvarbuf(buf, &l, (struct sadb_ext *)&m_addr,
			    sizeof(m_addr), (caddr_t)sa, salen);

			msg->sadb_msg_len = PFKEY_UNIT64(l);

			sendkeymsg(buf, l);

			n++;
		}
	}

	if (n == 0)
		return -1;
	else
		return 0;
}

/* XXX NO BUFFER OVERRUN CHECK! BAD BAD! */
static int
setkeymsg_addr(type, satype, srcs, dsts, no_spi)
	unsigned int type;
	unsigned int satype;
	struct addrinfo *srcs;
	struct addrinfo *dsts;
	int no_spi;
{
	struct sadb_msg *msg;
	char buf[BUFSIZ];
	int l, l0, len;
	struct sadb_sa m_sa;
	struct sadb_x_sa2 m_sa2;
	struct sadb_address m_addr;
	struct addrinfo *s, *d;
	int n;
	int plen;
	struct sockaddr *sa;
	int salen;

	msg = (struct sadb_msg *)buf;

	if (!srcs || !dsts)
		return -1;

	/* fix up length afterwards */
	setkeymsg0(msg, type, satype, 0);
	l = sizeof(struct sadb_msg);

	if (!no_spi) {
		len = sizeof(struct sadb_sa);
		m_sa.sadb_sa_len = PFKEY_UNIT64(len);
		m_sa.sadb_sa_exttype = SADB_EXT_SA;
		m_sa.sadb_sa_spi = htonl(p_spi);
		m_sa.sadb_sa_replay = p_replay;
		m_sa.sadb_sa_state = 0;
		m_sa.sadb_sa_auth = p_alg_auth;
		m_sa.sadb_sa_encrypt = p_alg_enc;
		m_sa.sadb_sa_flags = p_ext;

		memcpy(buf + l, &m_sa, len);
		l += len;

		len = sizeof(struct sadb_x_sa2);
		m_sa2.sadb_x_sa2_len = PFKEY_UNIT64(len);
		m_sa2.sadb_x_sa2_exttype = SADB_X_EXT_SA2;
		m_sa2.sadb_x_sa2_mode = p_mode;
		m_sa2.sadb_x_sa2_reqid = p_reqid;

		memcpy(buf + l, &m_sa2, len);
		l += len;
	}

	l0 = l;
	n = 0;

	/* do it for all src/dst pairs */
	for (s = srcs; s; s = s->ai_next) {
		for (d = dsts; d; d = d->ai_next) {
			/* rewind pointer */
			l = l0;

			if (s->ai_addr->sa_family != d->ai_addr->sa_family)
				continue;
			switch (s->ai_addr->sa_family) {
			case AF_INET:
				plen = sizeof(struct in_addr) << 3;
				break;
#ifdef INET6
			case AF_INET6:
				plen = sizeof(struct in6_addr) << 3;
				break;
#endif
			default:
				continue;
			}

			/* set src */
			sa = s->ai_addr;
			salen = s->ai_addr->sa_len;
			m_addr.sadb_address_len = PFKEY_UNIT64(sizeof(m_addr) +
			    PFKEY_ALIGN8(salen));
			m_addr.sadb_address_exttype = SADB_EXT_ADDRESS_SRC;
			m_addr.sadb_address_proto = IPSEC_ULPROTO_ANY;
			m_addr.sadb_address_prefixlen = plen;
			m_addr.sadb_address_reserved = 0;

			setvarbuf(buf, &l, (struct sadb_ext *)&m_addr,
			    sizeof(m_addr), (caddr_t)sa, salen);

			/* set dst */
			sa = d->ai_addr;
			salen = d->ai_addr->sa_len;
			m_addr.sadb_address_len = PFKEY_UNIT64(sizeof(m_addr) +
			    PFKEY_ALIGN8(salen));
			m_addr.sadb_address_exttype = SADB_EXT_ADDRESS_DST;
			m_addr.sadb_address_proto = IPSEC_ULPROTO_ANY;
			m_addr.sadb_address_prefixlen = plen;
			m_addr.sadb_address_reserved = 0;

			setvarbuf(buf, &l, (struct sadb_ext *)&m_addr,
			    sizeof(m_addr), (caddr_t)sa, salen);

			msg->sadb_msg_len = PFKEY_UNIT64(l);

			sendkeymsg(buf, l);

			n++;
		}
	}

	if (n == 0)
		return -1;
	else
		return 0;
}

/* XXX NO BUFFER OVERRUN CHECK! BAD BAD! */
static int
setkeymsg_add(type, satype, srcs, dsts)
	unsigned int type;
	unsigned int satype;
	struct addrinfo *srcs;
	struct addrinfo *dsts;
{
	struct sadb_msg *msg;
	char buf[BUFSIZ];
	int l, l0, len;
	struct sadb_sa m_sa;
	struct sadb_x_sa2 m_sa2;
	struct sadb_address m_addr;
	struct addrinfo *s, *d;
	int n;
	int plen;
	struct sockaddr *sa;
	int salen;

	msg = (struct sadb_msg *)buf;

	if (!srcs || !dsts)
		return -1;

	/* fix up length afterwards */
	setkeymsg0(msg, type, satype, 0);
	l = sizeof(struct sadb_msg);

	/* set encryption algorithm, if present. */
	if (satype != SADB_X_SATYPE_IPCOMP && p_key_enc) {
		struct sadb_key m_key;

		m_key.sadb_key_len =
			PFKEY_UNIT64(sizeof(m_key)
				   + PFKEY_ALIGN8(p_key_enc_len));
		m_key.sadb_key_exttype = SADB_EXT_KEY_ENCRYPT;
		m_key.sadb_key_bits = p_key_enc_len * 8;
		m_key.sadb_key_reserved = 0;

		setvarbuf(buf, &l,
			(struct sadb_ext *)&m_key, sizeof(m_key),
			(caddr_t)p_key_enc, p_key_enc_len);
	}

	/* set authentication algorithm, if present. */
	if (p_key_auth) {
		struct sadb_key m_key;

		m_key.sadb_key_len =
			PFKEY_UNIT64(sizeof(m_key)
				   + PFKEY_ALIGN8(p_key_auth_len));
		m_key.sadb_key_exttype = SADB_EXT_KEY_AUTH;
		m_key.sadb_key_bits = p_key_auth_len * 8;
		m_key.sadb_key_reserved = 0;

		setvarbuf(buf, &l,
			(struct sadb_ext *)&m_key, sizeof(m_key),
			(caddr_t)p_key_auth, p_key_auth_len);
	}

	/* set lifetime for HARD */
	if (p_lt_hard != 0) {
		struct sadb_lifetime m_lt;
		u_int slen = sizeof(struct sadb_lifetime);

		m_lt.sadb_lifetime_len = PFKEY_UNIT64(slen);
		m_lt.sadb_lifetime_exttype = SADB_EXT_LIFETIME_HARD;
		m_lt.sadb_lifetime_allocations = 0;
		m_lt.sadb_lifetime_bytes = 0;
		m_lt.sadb_lifetime_addtime = p_lt_hard;
		m_lt.sadb_lifetime_usetime = 0;

		memcpy(buf + l, &m_lt, slen);
		l += slen;
	}

	/* set lifetime for SOFT */
	if (p_lt_soft != 0) {
		struct sadb_lifetime m_lt;
		u_int slen = sizeof(struct sadb_lifetime);

		m_lt.sadb_lifetime_len = PFKEY_UNIT64(slen);
		m_lt.sadb_lifetime_exttype = SADB_EXT_LIFETIME_SOFT;
		m_lt.sadb_lifetime_allocations = 0;
		m_lt.sadb_lifetime_bytes = 0;
		m_lt.sadb_lifetime_addtime = p_lt_soft;
		m_lt.sadb_lifetime_usetime = 0;

		memcpy(buf + l, &m_lt, slen);
		l += slen;
	}

	len = sizeof(struct sadb_sa);
	m_sa.sadb_sa_len = PFKEY_UNIT64(len);
	m_sa.sadb_sa_exttype = SADB_EXT_SA;
	m_sa.sadb_sa_spi = htonl(p_spi);
	m_sa.sadb_sa_replay = p_replay;
	m_sa.sadb_sa_state = 0;
	m_sa.sadb_sa_auth = p_alg_auth;
	m_sa.sadb_sa_encrypt = p_alg_enc;
	m_sa.sadb_sa_flags = p_ext;

	memcpy(buf + l, &m_sa, len);
	l += len;

	len = sizeof(struct sadb_x_sa2);
	m_sa2.sadb_x_sa2_len = PFKEY_UNIT64(len);
	m_sa2.sadb_x_sa2_exttype = SADB_X_EXT_SA2;
	m_sa2.sadb_x_sa2_mode = p_mode;
	m_sa2.sadb_x_sa2_reqid = p_reqid;

	memcpy(buf + l, &m_sa2, len);
	l += len;

	l0 = l;
	n = 0;

	/* do it for all src/dst pairs */
	for (s = srcs; s; s = s->ai_next) {
		for (d = dsts; d; d = d->ai_next) {
			/* rewind pointer */
			l = l0;

			if (s->ai_addr->sa_family != d->ai_addr->sa_family)
				continue;
			switch (s->ai_addr->sa_family) {
			case AF_INET:
				plen = sizeof(struct in_addr) << 3;
				break;
#ifdef INET6
			case AF_INET6:
				plen = sizeof(struct in6_addr) << 3;
				break;
#endif
			default:
				continue;
			}

			/* set src */
			sa = s->ai_addr;
			salen = s->ai_addr->sa_len;
			m_addr.sadb_address_len = PFKEY_UNIT64(sizeof(m_addr) +
			    PFKEY_ALIGN8(salen));
			m_addr.sadb_address_exttype = SADB_EXT_ADDRESS_SRC;
			m_addr.sadb_address_proto = IPSEC_ULPROTO_ANY;
			m_addr.sadb_address_prefixlen = plen;
			m_addr.sadb_address_reserved = 0;

			setvarbuf(buf, &l, (struct sadb_ext *)&m_addr,
			    sizeof(m_addr), (caddr_t)sa, salen);

			/* set dst */
			sa = d->ai_addr;
			salen = d->ai_addr->sa_len;
			m_addr.sadb_address_len = PFKEY_UNIT64(sizeof(m_addr) +
			    PFKEY_ALIGN8(salen));
			m_addr.sadb_address_exttype = SADB_EXT_ADDRESS_DST;
			m_addr.sadb_address_proto = IPSEC_ULPROTO_ANY;
			m_addr.sadb_address_prefixlen = plen;
			m_addr.sadb_address_reserved = 0;

			setvarbuf(buf, &l, (struct sadb_ext *)&m_addr,
			    sizeof(m_addr), (caddr_t)sa, salen);

			msg->sadb_msg_len = PFKEY_UNIT64(l);

			sendkeymsg(buf, l);

			n++;
		}
	}

	if (n == 0)
		return -1;
	else
		return 0;
}

static struct addrinfo *
parse_addr(host, port)
	char *host;
	char *port;
{
	struct addrinfo hints, *res = NULL;
	int error;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = p_aifamily;
	hints.ai_socktype = SOCK_DGRAM;		/*dummy*/
	hints.ai_protocol = IPPROTO_UDP;	/*dummy*/
	hints.ai_flags = p_aiflags;
	error = getaddrinfo(host, port, &hints, &res);
	if (error != 0) {
		yyerror(gai_strerror(error));
		return NULL;
	}
	return res;
}

static int
fix_portstr(spec, sport, dport)
	vchar_t *spec, *sport, *dport;
{
	char *p, *p2;
	u_int l;

	l = 0;
	for (p = spec->buf; *p != ',' && *p != '\0' && l < spec->len; p++, l++)
		;
	if (*p == '\0') {
		p2 = "0";
	} else {
		if (*p == ',') {
			*p = '\0';
			p2 = ++p;
		}
		for (p = p2; *p != '\0' && l < spec->len; p++, l++)
			;
		if (*p != '\0' || *p2 == '\0') {
			yyerror("invalid an upper layer protocol spec");
			return -1;
		}
	}

	sport->buf = strdup(spec->buf);
	if (!sport->buf) {
		yyerror("insufficient memory");
		return -1;
	}
	sport->len = strlen(sport->buf);
	dport->buf = strdup(p2);
	if (!dport->buf) {
		yyerror("insufficient memory");
		return -1;
	}
	dport->len = strlen(dport->buf);

	return 0;
}

static int
setvarbuf(buf, off, ebuf, elen, vbuf, vlen)
	char *buf;
	int *off;
	struct sadb_ext *ebuf;
	int elen;
	caddr_t vbuf;
	int vlen;
{
	memset(buf + *off, 0, PFKEY_UNUNIT64(ebuf->sadb_ext_len));
	memcpy(buf + *off, (caddr_t)ebuf, elen);
	memcpy(buf + *off + elen, vbuf, vlen);
	(*off) += PFKEY_ALIGN8(elen + vlen);

	return 0;
}

void
parse_init()
{
	p_spi = 0;

	p_ext = SADB_X_EXT_CYCSEQ;
	p_alg_enc = SADB_EALG_NONE;
	p_alg_auth = SADB_AALG_NONE;
	p_mode = IPSEC_MODE_ANY;
	p_reqid = 0;
	p_replay = 0;
	p_key_enc_len = p_key_auth_len = 0;
	p_key_enc = p_key_auth = 0;
	p_lt_hard = p_lt_soft = 0;

	p_aiflags = 0;
	p_aifamily = PF_UNSPEC;

	return;
}

void
free_buffer()
{
	/* we got tons of memory leaks in the parser anyways, leave them */

	return;
}
#line 959 "y.tab.c"

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
#line 132 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			free_buffer();
			parse_init();
		}
break;
case 13:
#line 155 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			int status;

			status = setkeymsg_add(SADB_ADD, yystack.l_mark[-4].num, yystack.l_mark[-6].res, yystack.l_mark[-5].res);
			if (status < 0)
				return -1;
		}
break;
case 14:
#line 167 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			int status;

			if (yystack.l_mark[-5].res->ai_next || yystack.l_mark[-4].res->ai_next) {
				yyerror("multiple address specified");
				return -1;
			}
			if (p_mode != IPSEC_MODE_ANY)
				yyerror("WARNING: mode is obsolete");

			status = setkeymsg_addr(SADB_DELETE, yystack.l_mark[-3].num, yystack.l_mark[-5].res, yystack.l_mark[-4].res, 0);
			if (status < 0)
				return -1;
		}
break;
case 15:
#line 186 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			int status;

			status = setkeymsg_addr(SADB_DELETE, yystack.l_mark[-1].num, yystack.l_mark[-3].res, yystack.l_mark[-2].res, 1);
			if (status < 0)
				return -1;
		}
break;
case 16:
#line 198 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			int status;

			if (p_mode != IPSEC_MODE_ANY)
				yyerror("WARNING: mode is obsolete");

			status = setkeymsg_addr(SADB_GET, yystack.l_mark[-3].num, yystack.l_mark[-5].res, yystack.l_mark[-4].res, 0);
			if (status < 0)
				return -1;
		}
break;
case 17:
#line 213 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			struct sadb_msg msg;
			setkeymsg0(&msg, SADB_FLUSH, yystack.l_mark[-1].num, sizeof(msg));
			sendkeymsg((char *)&msg, sizeof(msg));
		}
break;
case 18:
#line 223 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			struct sadb_msg msg;
			setkeymsg0(&msg, SADB_DUMP, yystack.l_mark[-1].num, sizeof(msg));
			sendkeymsg((char *)&msg, sizeof(msg));
		}
break;
case 19:
#line 232 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			yyval.num = SADB_SATYPE_UNSPEC;
		}
break;
case 20:
#line 236 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			yyval.num = SADB_SATYPE_ESP;
			if (yystack.l_mark[0].num == 1)
				p_ext |= SADB_X_EXT_OLD;
			else
				p_ext &= ~SADB_X_EXT_OLD;
		}
break;
case 21:
#line 244 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			yyval.num = SADB_SATYPE_AH;
			if (yystack.l_mark[0].num == 1)
				p_ext |= SADB_X_EXT_OLD;
			else
				p_ext &= ~SADB_X_EXT_OLD;
		}
break;
case 22:
#line 252 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			yyval.num = SADB_X_SATYPE_IPCOMP;
		}
break;
case 23:
#line 256 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			yyval.num = SADB_X_SATYPE_TCPSIGNATURE;
		}
break;
case 24:
#line 262 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ p_spi = yystack.l_mark[0].ulnum; }
break;
case 25:
#line 264 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			char *ep;
			unsigned long v;

			ep = NULL;
			v = strtoul(yystack.l_mark[0].val.buf, &ep, 16);
			if (!ep || *ep) {
				yyerror("invalid SPI");
				return -1;
			}
			if (v & ~0xffffffff) {
				yyerror("SPI too big.");
				return -1;
			}

			p_spi = v;
		}
break;
case 32:
#line 300 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			if (yystack.l_mark[0].num < 0) {
				yyerror("unsupported algorithm");
				return -1;
			}
			p_alg_enc = yystack.l_mark[0].num;
		}
break;
case 33:
#line 308 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			if (yystack.l_mark[-1].num < 0) {
				yyerror("unsupported algorithm");
				return -1;
			}
			p_alg_enc = yystack.l_mark[-1].num;
			p_ext |= SADB_X_EXT_RAWCPI;
		}
break;
case 34:
#line 319 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			if (yystack.l_mark[0].num < 0) {
				yyerror("unsupported algorithm");
				return -1;
			}
			p_alg_enc = yystack.l_mark[0].num;

			p_key_enc_len = 0;
			p_key_enc = NULL;
			if (ipsec_check_keylen(SADB_EXT_SUPPORTED_ENCRYPT,
			    p_alg_enc, PFKEY_UNUNIT64(p_key_enc_len)) < 0) {
				yyerror(ipsec_strerror());
				return -1;
			}
		}
break;
case 35:
#line 334 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			if (yystack.l_mark[-1].num < 0) {
				yyerror("unsupported algorithm");
				return -1;
			}
			p_alg_enc = yystack.l_mark[-1].num;

			p_key_enc_len = yystack.l_mark[0].val.len;
			p_key_enc = yystack.l_mark[0].val.buf;
			if (ipsec_check_keylen(SADB_EXT_SUPPORTED_ENCRYPT,
			    p_alg_enc, PFKEY_UNUNIT64(p_key_enc_len)) < 0) {
				yyerror(ipsec_strerror());
				return -1;
			}
		}
break;
case 36:
#line 349 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			if (yystack.l_mark[0].num < 0) {
				yyerror("unsupported algorithm");
				return -1;
			}
			yyerror("WARNING: obsolete algorithm");
			p_alg_enc = yystack.l_mark[0].num;

			p_key_enc_len = 0;
			p_key_enc = NULL;
			if (ipsec_check_keylen(SADB_EXT_SUPPORTED_ENCRYPT,
			    p_alg_enc, PFKEY_UNUNIT64(p_key_enc_len)) < 0) {
				yyerror(ipsec_strerror());
				return -1;
			}
		}
break;
case 37:
#line 366 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			if (yystack.l_mark[-1].num < 0) {
				yyerror("unsupported algorithm");
				return -1;
			}
			p_alg_enc = yystack.l_mark[-1].num;
			if (p_ext & SADB_X_EXT_OLD) {
				yyerror("algorithm mismatched");
				return -1;
			}
			p_ext |= SADB_X_EXT_DERIV;

			p_key_enc_len = yystack.l_mark[0].val.len;
			p_key_enc = yystack.l_mark[0].val.buf;
			if (ipsec_check_keylen(SADB_EXT_SUPPORTED_ENCRYPT,
			    p_alg_enc, PFKEY_UNUNIT64(p_key_enc_len)) < 0) {
				yyerror(ipsec_strerror());
				return -1;
			}
		}
break;
case 38:
#line 387 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			if (yystack.l_mark[-1].num < 0) {
				yyerror("unsupported algorithm");
				return -1;
			}
			p_alg_enc = yystack.l_mark[-1].num;
			if (!(p_ext & SADB_X_EXT_OLD)) {
				yyerror("algorithm mismatched");
				return -1;
			}
			p_ext |= SADB_X_EXT_IV4B;

			p_key_enc_len = yystack.l_mark[0].val.len;
			p_key_enc = yystack.l_mark[0].val.buf;
			if (ipsec_check_keylen(SADB_EXT_SUPPORTED_ENCRYPT,
			    p_alg_enc, PFKEY_UNUNIT64(p_key_enc_len)) < 0) {
				yyerror(ipsec_strerror());
				return -1;
			}
		}
break;
case 39:
#line 408 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			if (yystack.l_mark[-1].num < 0) {
				yyerror("unsupported algorithm");
				return -1;
			}
			p_alg_enc = yystack.l_mark[-1].num;

			p_key_enc_len = yystack.l_mark[0].val.len;

			p_key_enc = yystack.l_mark[0].val.buf;
			/*
			 * Salted keys include a 4 byte value that is
			 * not part of the key.
			 */
			if (ipsec_check_keylen(SADB_EXT_SUPPORTED_ENCRYPT,
			    p_alg_enc, PFKEY_UNUNIT64(p_key_enc_len - 4)) < 0) {
				yyerror(ipsec_strerror());
				return -1;
			}
		}
break;
case 40:
#line 431 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			if (yystack.l_mark[-1].num < 0) {
				yyerror("unsupported algorithm");
				return -1;
			}
			p_alg_auth = yystack.l_mark[-1].num;

			p_key_auth_len = yystack.l_mark[0].val.len;
			p_key_auth = yystack.l_mark[0].val.buf;

			if (p_alg_auth == SADB_X_AALG_TCP_MD5) {
				if ((p_key_auth_len < 1) || (p_key_auth_len >
				    80))
					return -1;
			} else if (ipsec_check_keylen(SADB_EXT_SUPPORTED_AUTH,
			    p_alg_auth, PFKEY_UNUNIT64(p_key_auth_len)) < 0) {
				yyerror(ipsec_strerror());
				return -1;
			}
		}
break;
case 41:
#line 451 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			if (yystack.l_mark[0].num < 0) {
				yyerror("unsupported algorithm");
				return -1;
			}
			p_alg_auth = yystack.l_mark[0].num;

			p_key_auth_len = 0;
			p_key_auth = NULL;
		}
break;
case 42:
#line 465 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			yyval.val = yystack.l_mark[0].val;
		}
break;
case 43:
#line 469 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			caddr_t pp_key;
			caddr_t bp;
			caddr_t yp = yystack.l_mark[0].val.buf;
			int l;

			l = strlen(yp) % 2 + strlen(yp) / 2;
			if ((pp_key = malloc(l)) == 0) {
				yyerror("not enough core");
				return -1;
			}
			memset(pp_key, 0, l);

			bp = pp_key;
			if (strlen(yp) % 2) {
				*bp = ATOX(yp[0]);
				yp++, bp++;
			}
			while (*yp) {
				*bp = (ATOX(yp[0]) << 4) | ATOX(yp[1]);
				yp += 2, bp++;
			}

			yyval.val.len = l;
			yyval.val.buf = pp_key;
		}
break;
case 46:
#line 503 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ p_ext |= yystack.l_mark[0].num; }
break;
case 47:
#line 504 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ p_ext &= ~SADB_X_EXT_CYCSEQ; }
break;
case 48:
#line 505 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ p_mode = yystack.l_mark[0].num; }
break;
case 49:
#line 506 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ p_mode = IPSEC_MODE_ANY; }
break;
case 50:
#line 507 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ p_reqid = yystack.l_mark[0].ulnum; }
break;
case 51:
#line 509 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			if ((p_ext & SADB_X_EXT_OLD) != 0) {
				yyerror("replay prevention cannot be used with "
				    "ah/esp-old");
				return -1;
			}
			p_replay = yystack.l_mark[0].ulnum;
		}
break;
case 52:
#line 517 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ p_lt_hard = yystack.l_mark[0].ulnum; }
break;
case 53:
#line 518 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ p_lt_soft = yystack.l_mark[0].ulnum; }
break;
case 54:
#line 525 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			int status;
			struct addrinfo *src, *dst;

			/* fixed port fields if ulp is icmpv6 */
			if (yystack.l_mark[-2].val.buf != NULL) {
				if (yystack.l_mark[-3].num != IPPROTO_ICMPV6)
					return -1;
				free(yystack.l_mark[-7].val.buf);
				free(yystack.l_mark[-4].val.buf);
				if (fix_portstr(&yystack.l_mark[-2].val, &yystack.l_mark[-7].val, &yystack.l_mark[-4].val))
					return -1;
			}

			src = parse_addr(yystack.l_mark[-9].val.buf, yystack.l_mark[-7].val.buf);
			dst = parse_addr(yystack.l_mark[-6].val.buf, yystack.l_mark[-4].val.buf);
			if (!src || !dst) {
				/* yyerror is already called */
				return -1;
			}
			if (src->ai_next || dst->ai_next) {
				yyerror("multiple address specified");
				freeaddrinfo(src);
				freeaddrinfo(dst);
				return -1;
			}

			status = setkeymsg_spdaddr(SADB_X_SPDADD, yystack.l_mark[-3].num, &yystack.l_mark[-1].val,
			    src, yystack.l_mark[-8].num, dst, yystack.l_mark[-5].num);
			freeaddrinfo(src);
			freeaddrinfo(dst);
			if (status < 0)
				return -1;
		}
break;
case 55:
#line 560 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			return -1;
		}
break;
case 56:
#line 567 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			int status;
			struct addrinfo *src, *dst;

			/* fixed port fields if ulp is icmpv6 */
			if (yystack.l_mark[-2].val.buf != NULL) {
				if (yystack.l_mark[-3].num != IPPROTO_ICMPV6)
					return -1;
				free(yystack.l_mark[-7].val.buf);
				free(yystack.l_mark[-4].val.buf);
				if (fix_portstr(&yystack.l_mark[-2].val, &yystack.l_mark[-7].val, &yystack.l_mark[-4].val))
					return -1;
			}

			src = parse_addr(yystack.l_mark[-9].val.buf, yystack.l_mark[-7].val.buf);
			dst = parse_addr(yystack.l_mark[-6].val.buf, yystack.l_mark[-4].val.buf);
			if (!src || !dst) {
				/* yyerror is already called */
				return -1;
			}
			if (src->ai_next || dst->ai_next) {
				yyerror("multiple address specified");
				freeaddrinfo(src);
				freeaddrinfo(dst);
				return -1;
			}

			status = setkeymsg_spdaddr(SADB_X_SPDDELETE, yystack.l_mark[-3].num, &yystack.l_mark[-1].val,
			    src, yystack.l_mark[-8].num, dst, yystack.l_mark[-5].num);
			freeaddrinfo(src);
			freeaddrinfo(dst);
			if (status < 0)
				return -1;
		}
break;
case 57:
#line 605 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			struct sadb_msg msg;
			setkeymsg0(&msg, SADB_X_SPDDUMP, SADB_SATYPE_UNSPEC,
			    sizeof(msg));
			sendkeymsg((char *)&msg, sizeof(msg));
		}
break;
case 58:
#line 615 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			struct sadb_msg msg;
			setkeymsg0(&msg, SADB_X_SPDFLUSH, SADB_SATYPE_UNSPEC,
			    sizeof(msg));
			sendkeymsg((char *)&msg, sizeof(msg));
		}
break;
case 61:
#line 630 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			char *p;

			for (p = yystack.l_mark[0].val.buf + 1; *p; p++)
				switch (*p) {
				case '4':
					p_aifamily = AF_INET;
					break;
#ifdef INET6
				case '6':
					p_aifamily = AF_INET6;
					break;
#endif
				case 'n':
					p_aiflags = AI_NUMERICHOST;
					break;
				default:
					yyerror("invalid flag");
					return -1;
				}
		}
break;
case 62:
#line 655 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			yyval.res = parse_addr(yystack.l_mark[0].val.buf, NULL);
			if (yyval.res == NULL) {
				/* yyerror already called by parse_addr */
				return -1;
			}
		}
break;
case 63:
#line 665 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ yyval.num = -1; }
break;
case 64:
#line 666 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ yyval.num = yystack.l_mark[0].ulnum; }
break;
case 65:
#line 671 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			yyval.val.buf = strdup("0");
			if (!yyval.val.buf) {
				yyerror("insufficient memory");
				return -1;
			}
			yyval.val.len = strlen(yyval.val.buf);
		}
break;
case 66:
#line 680 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			yyval.val.buf = strdup("0");
			if (!yyval.val.buf) {
				yyerror("insufficient memory");
				return -1;
			}
			yyval.val.len = strlen(yyval.val.buf);
		}
break;
case 67:
#line 689 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			char buf[20];
			snprintf(buf, sizeof(buf), "%lu", yystack.l_mark[-1].ulnum);
			yyval.val.buf = strdup(buf);
			if (!yyval.val.buf) {
				yyerror("insufficient memory");
				return -1;
			}
			yyval.val.len = strlen(yyval.val.buf);
		}
break;
case 68:
#line 700 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			yyval.val = yystack.l_mark[-1].val;
		}
break;
case 69:
#line 706 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ yyval.num = yystack.l_mark[0].ulnum; }
break;
case 70:
#line 707 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ yyval.num = IPSEC_ULPROTO_ANY; }
break;
case 71:
#line 708 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ yyval.num = IPPROTO_TCP; }
break;
case 72:
#line 709 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ yyval.num = IPPROTO_ESP; }
break;
case 73:
#line 711 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			struct protoent *ent;

			ent = getprotobyname(yystack.l_mark[0].val.buf);
			if (ent)
				yyval.num = ent->p_proto;
			else {
				if (strcmp("icmp6", yystack.l_mark[0].val.buf) == 0) {
					yyval.num = IPPROTO_ICMPV6;
				} else if(strcmp("ip4", yystack.l_mark[0].val.buf) == 0) {
					yyval.num = IPPROTO_IPV4;
				} else {
					yyerror("invalid upper layer protocol");
					return -1;
				}
			}
			endprotoent();
		}
break;
case 74:
#line 733 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			yyval.val.buf = NULL;
			yyval.val.len = 0;
		}
break;
case 75:
#line 738 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			yyval.val.buf = strdup(yystack.l_mark[0].val.buf);
			if (!yyval.val.buf) {
				yyerror("insufficient memory");
				return -1;
			}
			yyval.val.len = strlen(yyval.val.buf);
		}
break;
case 76:
#line 750 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{
			char *policy;

			policy = ipsec_set_policy(yystack.l_mark[0].val.buf, yystack.l_mark[0].val.len);
			if (policy == NULL) {
				yyerror(ipsec_strerror());
				return -1;
			}

			yyval.val.buf = policy;
			yyval.val.len = ipsec_get_policylen(policy);
		}
break;
case 77:
#line 765 "/usr/home/freebsd/omega/src/sbin/setkey/parse.y"
	{ yyval.val = yystack.l_mark[0].val; }
break;
#line 1806 "y.tab.c"
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
