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

#line 30 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#ifdef __FreeBSD__
#include <sys/sysctl.h>
#endif
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/icmp6.h>
#include <net/pfvar.h>
#include <arpa/inet.h>
#include <net/altq/altq.h>
#include <net/altq/altq_cbq.h>
#include <net/altq/altq_codel.h>
#include <net/altq/altq_priq.h>
#include <net/altq/altq_hfsc.h>
#include <net/altq/altq_fairq.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <err.h>
#include <limits.h>
#include <pwd.h>
#include <grp.h>
#include <md5.h>

#include "pfctl_parser.h"
#include "pfctl.h"

static struct pfctl	*pf = NULL;
static int		 debug = 0;
static int		 rulestate = 0;
static u_int16_t	 returnicmpdefault =
			    (ICMP_UNREACH << 8) | ICMP_UNREACH_PORT;
static u_int16_t	 returnicmp6default =
			    (ICMP6_DST_UNREACH << 8) | ICMP6_DST_UNREACH_NOPORT;
static int		 blockpolicy = PFRULE_DROP;
static int		 require_order = 1;
static int		 default_statelock;

TAILQ_HEAD(files, file)		 files = TAILQ_HEAD_INITIALIZER(files);
static struct file {
	TAILQ_ENTRY(file)	 entry;
	FILE			*stream;
	char			*name;
	int			 lineno;
	int			 errors;
} *file;
struct file	*pushfile(const char *, int);
int		 popfile(void);
int		 check_file_secrecy(int, const char *);
int		 yyparse(void);
int		 yylex(void);
int		 yyerror(const char *, ...);
int		 kw_cmp(const void *, const void *);
int		 lookup(char *);
int		 lgetc(int);
int		 lungetc(int);
int		 findeol(void);

TAILQ_HEAD(symhead, sym)	 symhead = TAILQ_HEAD_INITIALIZER(symhead);
struct sym {
	TAILQ_ENTRY(sym)	 entry;
	int			 used;
	int			 persist;
	char			*nam;
	char			*val;
};
int		 symset(const char *, const char *, int);
char		*symget(const char *);

int		 atoul(char *, u_long *);

enum {
	PFCTL_STATE_NONE,
	PFCTL_STATE_OPTION,
	PFCTL_STATE_SCRUB,
	PFCTL_STATE_QUEUE,
	PFCTL_STATE_NAT,
	PFCTL_STATE_FILTER
};

struct node_proto {
	u_int8_t		 proto;
	struct node_proto	*next;
	struct node_proto	*tail;
};

struct node_port {
	u_int16_t		 port[2];
	u_int8_t		 op;
	struct node_port	*next;
	struct node_port	*tail;
};

struct node_uid {
	uid_t			 uid[2];
	u_int8_t		 op;
	struct node_uid		*next;
	struct node_uid		*tail;
};

struct node_gid {
	gid_t			 gid[2];
	u_int8_t		 op;
	struct node_gid		*next;
	struct node_gid		*tail;
};

struct node_icmp {
	u_int8_t		 code;
	u_int8_t		 type;
	u_int8_t		 proto;
	struct node_icmp	*next;
	struct node_icmp	*tail;
};

enum	{ PF_STATE_OPT_MAX, PF_STATE_OPT_NOSYNC, PF_STATE_OPT_SRCTRACK,
	    PF_STATE_OPT_MAX_SRC_STATES, PF_STATE_OPT_MAX_SRC_CONN,
	    PF_STATE_OPT_MAX_SRC_CONN_RATE, PF_STATE_OPT_MAX_SRC_NODES,
	    PF_STATE_OPT_OVERLOAD, PF_STATE_OPT_STATELOCK,
	    PF_STATE_OPT_TIMEOUT, PF_STATE_OPT_SLOPPY, };

enum	{ PF_SRCTRACK_NONE, PF_SRCTRACK, PF_SRCTRACK_GLOBAL, PF_SRCTRACK_RULE };

struct node_state_opt {
	int			 type;
	union {
		u_int32_t	 max_states;
		u_int32_t	 max_src_states;
		u_int32_t	 max_src_conn;
		struct {
			u_int32_t	limit;
			u_int32_t	seconds;
		}		 max_src_conn_rate;
		struct {
			u_int8_t	flush;
			char		tblname[PF_TABLE_NAME_SIZE];
		}		 overload;
		u_int32_t	 max_src_nodes;
		u_int8_t	 src_track;
		u_int32_t	 statelock;
		struct {
			int		number;
			u_int32_t	seconds;
		}		 timeout;
	}			 data;
	struct node_state_opt	*next;
	struct node_state_opt	*tail;
};

struct peer {
	struct node_host	*host;
	struct node_port	*port;
};

struct node_queue {
	char			 queue[PF_QNAME_SIZE];
	char			 parent[PF_QNAME_SIZE];
	char			 ifname[IFNAMSIZ];
	int			 scheduler;
	struct node_queue	*next;
	struct node_queue	*tail;
}	*queues = NULL;

struct node_qassign {
	char		*qname;
	char		*pqname;
};

struct filter_opts {
	int			 marker;
#define FOM_FLAGS	0x01
#define FOM_ICMP	0x02
#define FOM_TOS		0x04
#define FOM_KEEP	0x08
#define FOM_SRCTRACK	0x10
	struct node_uid		*uid;
	struct node_gid		*gid;
	struct {
		u_int8_t	 b1;
		u_int8_t	 b2;
		u_int16_t	 w;
		u_int16_t	 w2;
	} flags;
	struct node_icmp	*icmpspec;
	u_int32_t		 tos;
	u_int32_t		 prob;
	struct {
		int			 action;
		struct node_state_opt	*options;
	} keep;
	int			 fragment;
	int			 allowopts;
	char			*label;
	struct node_qassign	 queues;
	char			*tag;
	char			*match_tag;
	u_int8_t		 match_tag_not;
	u_int			 rtableid;
	struct {
		struct node_host	*addr;
		u_int16_t		port;
	}			 divert;
} filter_opts;

struct antispoof_opts {
	char			*label;
	u_int			 rtableid;
} antispoof_opts;

struct scrub_opts {
	int			 marker;
#define SOM_MINTTL	0x01
#define SOM_MAXMSS	0x02
#define SOM_FRAGCACHE	0x04
#define SOM_SETTOS	0x08
	int			 nodf;
	int			 minttl;
	int			 maxmss;
	int			 settos;
	int			 fragcache;
	int			 randomid;
	int			 reassemble_tcp;
	char			*match_tag;
	u_int8_t		 match_tag_not;
	u_int			 rtableid;
} scrub_opts;

struct queue_opts {
	int			marker;
#define QOM_BWSPEC	0x01
#define QOM_SCHEDULER	0x02
#define QOM_PRIORITY	0x04
#define QOM_TBRSIZE	0x08
#define QOM_QLIMIT	0x10
	struct node_queue_bw	queue_bwspec;
	struct node_queue_opt	scheduler;
	int			priority;
	int			tbrsize;
	int			qlimit;
} queue_opts;

struct table_opts {
	int			flags;
	int			init_addr;
	struct node_tinithead	init_nodes;
} table_opts;

struct pool_opts {
	int			 marker;
#define POM_TYPE		0x01
#define POM_STICKYADDRESS	0x02
	u_int8_t		 opts;
	int			 type;
	int			 staticport;
	struct pf_poolhashkey	*key;

} pool_opts;

struct codel_opts	 codel_opts;
struct node_hfsc_opts	 hfsc_opts;
struct node_fairq_opts	 fairq_opts;
struct node_state_opt	*keep_state_defaults = NULL;

int		 disallow_table(struct node_host *, const char *);
int		 disallow_urpf_failed(struct node_host *, const char *);
int		 disallow_alias(struct node_host *, const char *);
int		 rule_consistent(struct pf_rule *, int);
int		 filter_consistent(struct pf_rule *, int);
int		 nat_consistent(struct pf_rule *);
int		 rdr_consistent(struct pf_rule *);
int		 process_tabledef(char *, struct table_opts *);
void		 expand_label_str(char *, size_t, const char *, const char *);
void		 expand_label_if(const char *, char *, size_t, const char *);
void		 expand_label_addr(const char *, char *, size_t, u_int8_t,
		    struct node_host *);
void		 expand_label_port(const char *, char *, size_t,
		    struct node_port *);
void		 expand_label_proto(const char *, char *, size_t, u_int8_t);
void		 expand_label_nr(const char *, char *, size_t);
void		 expand_label(char *, size_t, const char *, u_int8_t,
		    struct node_host *, struct node_port *, struct node_host *,
		    struct node_port *, u_int8_t);
void		 expand_rule(struct pf_rule *, struct node_if *,
		    struct node_host *, struct node_proto *, struct node_os *,
		    struct node_host *, struct node_port *, struct node_host *,
		    struct node_port *, struct node_uid *, struct node_gid *,
		    struct node_icmp *, const char *);
int		 expand_altq(struct pf_altq *, struct node_if *,
		    struct node_queue *, struct node_queue_bw bwspec,
		    struct node_queue_opt *);
int		 expand_queue(struct pf_altq *, struct node_if *,
		    struct node_queue *, struct node_queue_bw,
		    struct node_queue_opt *);
int		 expand_skip_interface(struct node_if *);

int	 check_rulestate(int);
int	 getservice(char *);
int	 rule_label(struct pf_rule *, char *);
int	 rt_tableid_max(void);

void	 mv_rules(struct pf_ruleset *, struct pf_ruleset *);
void	 decide_address_family(struct node_host *, sa_family_t *);
void	 remove_invalid_hosts(struct node_host **, sa_family_t *);
int	 invalid_redirect(struct node_host *, sa_family_t);
u_int16_t parseicmpspec(char *, sa_family_t);

TAILQ_HEAD(loadanchorshead, loadanchors)
    loadanchorshead = TAILQ_HEAD_INITIALIZER(loadanchorshead);

struct loadanchors {
	TAILQ_ENTRY(loadanchors)	 entries;
	char				*anchorname;
	char				*filename;
};

typedef struct {
	union {
		int64_t			 number;
		double			 probability;
		int			 i;
		char			*string;
		u_int			 rtableid;
		struct {
			u_int8_t	 b1;
			u_int8_t	 b2;
			u_int16_t	 w;
			u_int16_t	 w2;
		}			 b;
		struct range {
			int		 a;
			int		 b;
			int		 t;
		}			 range;
		struct node_if		*interface;
		struct node_proto	*proto;
		struct node_icmp	*icmp;
		struct node_host	*host;
		struct node_os		*os;
		struct node_port	*port;
		struct node_uid		*uid;
		struct node_gid		*gid;
		struct node_state_opt	*state_opt;
		struct peer		 peer;
		struct {
			struct peer	 src, dst;
			struct node_os	*src_os;
		}			 fromto;
		struct {
			struct node_host	*host;
			u_int8_t		 rt;
			u_int8_t		 pool_opts;
			sa_family_t		 af;
			struct pf_poolhashkey	*key;
		}			 route;
		struct redirection {
			struct node_host	*host;
			struct range		 rport;
		}			*redirection;
		struct {
			int			 action;
			struct node_state_opt	*options;
		}			 keep_state;
		struct {
			u_int8_t	 log;
			u_int8_t	 logif;
			u_int8_t	 quick;
		}			 logquick;
		struct {
			int		 neg;
			char		*name;
		}			 tagged;
		struct pf_poolhashkey	*hashkey;
		struct node_queue	*queue;
		struct node_queue_opt	 queue_options;
		struct node_queue_bw	 queue_bwspec;
		struct node_qassign	 qassign;
		struct filter_opts	 filter_opts;
		struct antispoof_opts	 antispoof_opts;
		struct queue_opts	 queue_opts;
		struct scrub_opts	 scrub_opts;
		struct table_opts	 table_opts;
		struct pool_opts	 pool_opts;
		struct node_hfsc_opts	 hfsc_opts;
		struct node_fairq_opts	 fairq_opts;
		struct codel_opts	 codel_opts;
	} v;
	int lineno;
} YYSTYPE;

#define PPORT_RANGE	1
#define PPORT_STAR	2
int	parseport(char *, struct range *r, int);

#define DYNIF_MULTIADDR(addr) ((addr).type == PF_ADDR_DYNIFTL && \
	(!((addr).iflags & PFI_AFLAG_NOALIAS) ||		 \
	!isdigit((addr).v.ifname[strlen((addr).v.ifname)-1])))

#line 434 "parse.c"

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

#define PASS 257
#define BLOCK 258
#define SCRUB 259
#define RETURN 260
#define IN 261
#define OS 262
#define OUT 263
#define LOG 264
#define QUICK 265
#define ON 266
#define FROM 267
#define TO 268
#define FLAGS 269
#define RETURNRST 270
#define RETURNICMP 271
#define RETURNICMP6 272
#define PROTO 273
#define INET 274
#define INET6 275
#define ALL 276
#define ANY 277
#define ICMPTYPE 278
#define ICMP6TYPE 279
#define CODE 280
#define KEEP 281
#define MODULATE 282
#define STATE 283
#define PORT 284
#define RDR 285
#define NAT 286
#define BINAT 287
#define ARROW 288
#define NODF 289
#define MINTTL 290
#define ERROR 291
#define ALLOWOPTS 292
#define FASTROUTE 293
#define FILENAME 294
#define ROUTETO 295
#define DUPTO 296
#define REPLYTO 297
#define NO 298
#define LABEL 299
#define NOROUTE 300
#define URPFFAILED 301
#define FRAGMENT 302
#define USER 303
#define GROUP 304
#define MAXMSS 305
#define MAXIMUM 306
#define TTL 307
#define TOS 308
#define DROP 309
#define TABLE 310
#define REASSEMBLE 311
#define FRAGDROP 312
#define FRAGCROP 313
#define ANCHOR 314
#define NATANCHOR 315
#define RDRANCHOR 316
#define BINATANCHOR 317
#define SET 318
#define OPTIMIZATION 319
#define TIMEOUT 320
#define LIMIT 321
#define LOGINTERFACE 322
#define BLOCKPOLICY 323
#define RANDOMID 324
#define REQUIREORDER 325
#define SYNPROXY 326
#define FINGERPRINTS 327
#define NOSYNC 328
#define DEBUG 329
#define SKIP 330
#define HOSTID 331
#define ANTISPOOF 332
#define FOR 333
#define INCLUDE 334
#define BITMASK 335
#define RANDOM 336
#define SOURCEHASH 337
#define ROUNDROBIN 338
#define STATICPORT 339
#define PROBABILITY 340
#define ALTQ 341
#define CBQ 342
#define CODEL 343
#define PRIQ 344
#define HFSC 345
#define FAIRQ 346
#define BANDWIDTH 347
#define TBRSIZE 348
#define LINKSHARE 349
#define REALTIME 350
#define UPPERLIMIT 351
#define QUEUE 352
#define PRIORITY 353
#define QLIMIT 354
#define HOGS 355
#define BUCKETS 356
#define RTABLE 357
#define TARGET 358
#define INTERVAL 359
#define LOAD 360
#define RULESET_OPTIMIZATION 361
#define STICKYADDRESS 362
#define MAXSRCSTATES 363
#define MAXSRCNODES 364
#define SOURCETRACK 365
#define GLOBAL 366
#define RULE 367
#define MAXSRCCONN 368
#define MAXSRCCONNRATE 369
#define OVERLOAD 370
#define FLUSH 371
#define SLOPPY 372
#define TAGGED 373
#define TAG 374
#define IFBOUND 375
#define FLOATING 376
#define STATEPOLICY 377
#define STATEDEFAULTS 378
#define ROUTE 379
#define SETTOS 380
#define DIVERTTO 381
#define DIVERTREPLY 382
#define STRING 383
#define NUMBER 384
#define PORTBINARY 385
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  133,  146,  146,
  146,  146,  146,  146,   18,  134,  134,  134,  134,  134,
  134,  134,  134,  134,  134,  134,  134,  134,  134,  134,
  134,   76,   76,   79,   79,   80,   80,   81,   81,  143,
   78,   78,  152,  152,  152,  152,  154,  153,  153,  139,
  139,  139,  139,  140,   26,  135,  155,  122,  122,  124,
  124,  123,  123,  123,  123,  123,  123,  123,  123,  123,
   17,   17,   17,  144,   91,   91,   92,   92,   93,   93,
  157,  116,  116,  118,  118,  117,  117,   11,   11,  145,
  158,  125,  125,  127,  127,  126,  126,  126,  126,  141,
  142,  159,  119,  119,  121,  121,  120,  120,  120,  120,
  120,  112,  112,   98,   98,   98,   98,   98,   98,   98,
   98,   98,   98,   99,   99,  100,  101,  101,  102,  160,
  105,  103,  103,  104,  104,  104,  104,  104,  104,  104,
  161,  108,  106,  106,  107,  107,  107,  107,  107,  162,
  111,  109,  109,  110,  110,  110,   95,   95,   95,   96,
   96,   97,  138,  163,  113,  113,  115,  115,  114,  114,
  114,  114,  114,  114,  114,  114,  114,  114,  114,  114,
  114,  114,  114,  114,  114,   13,   13,   23,   23,   29,
   29,   29,   29,   29,   29,   29,   29,   29,   29,   43,
   43,   44,   44,   15,   15,   15,   87,   87,   86,   86,
   86,   86,   86,   88,   88,   89,   89,   90,   90,   90,
   90,    1,    1,    1,    2,    2,    3,    4,   16,   16,
   16,   34,   34,   34,   35,   35,   36,   37,   37,   45,
   45,   60,   60,   60,   61,   62,   62,   47,   47,   48,
   48,   46,   46,   46,  148,  148,   49,   49,   49,   50,
   50,   54,   54,   51,   51,   51,   52,   52,   52,   52,
   52,   52,   52,    5,    5,   53,   63,   63,   64,   64,
   65,   65,   65,   30,   32,   66,   66,   67,   67,   68,
   68,   68,    8,    8,   69,   69,   70,   70,   71,   71,
   71,    9,    9,   28,   27,   27,   27,   38,   38,   38,
   38,   39,   39,   41,   41,   40,   40,   40,   42,   42,
   42,    6,    6,    7,    7,   10,   10,   19,   19,   19,
   22,   22,   82,   82,   82,   82,   20,   20,   20,   83,
   83,   84,   84,   85,   85,   85,   85,   85,   85,   85,
   85,   85,   85,   85,   75,   94,   94,   94,   14,   14,
   31,   56,   56,   55,   55,   74,   74,   74,   33,   33,
  164,  128,  128,  130,  130,  129,  129,  129,  129,  129,
  129,   73,   73,   73,   25,   25,   25,   25,   24,   24,
  136,  137,   77,   77,  131,  131,  132,  132,   57,   57,
   58,   58,   59,   59,   72,   72,   72,   72,   72,  147,
  149,  149,  150,  151,  151,  156,  156,   12,   12,   21,
   21,   21,   21,   21,   21,
};
static const YYINT yylen[] = {                            2,
    0,    3,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    4,    3,    2,    2,    3,
    3,    3,    3,    3,    1,    3,    3,    3,    6,    3,
    6,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    1,    1,    2,    1,    2,    1,    1,    1,    3,
    1,    0,    0,    2,    3,    3,    0,    5,    0,   10,
    7,    7,    7,    5,    2,    8,    0,    2,    0,    2,
    1,    1,    2,    2,    2,    1,    2,    1,    2,    3,
    2,    2,    2,    5,    2,    5,    2,    4,    1,    3,
    0,    2,    0,    2,    1,    1,    2,    1,    0,    5,
    0,    2,    0,    2,    1,    1,    3,    4,    2,    5,
    5,    0,    2,    0,    2,    1,    2,    2,    2,    1,
    2,    1,    1,    1,    4,    1,    4,    1,    4,    1,
    4,    1,    4,    1,    3,    1,    1,    3,    1,    0,
    2,    1,    3,    2,    8,    2,    8,    2,    8,    1,
    0,    2,    1,    3,    2,    6,    2,    2,    1,    0,
    2,    1,    3,    2,    2,    1,    0,    1,    4,    2,
    4,    1,    9,    0,    2,    0,    2,    1,    2,    2,
    1,    1,    2,    1,    1,    1,    1,    1,    2,    3,
    2,    2,    2,    4,    1,    1,    1,    1,    2,    0,
    1,    1,    5,    1,    1,    4,    4,    6,    1,    1,
    1,    1,    1,    0,    1,    1,    0,    1,    0,    1,
    1,    2,    2,    1,    4,    1,    3,    1,    1,    1,
    2,    0,    2,    5,    2,    4,    2,    1,    0,    1,
    1,    0,    2,    5,    2,    4,    1,    1,    1,    1,
    3,    0,    2,    5,    1,    2,    4,    0,    2,    0,
    2,    1,    3,    2,    2,    0,    1,    1,    4,    2,
    0,    2,    4,    2,    2,    2,    1,    3,    3,    3,
    1,    3,    3,    1,    1,    3,    1,    4,    2,    4,
    1,    2,    3,    1,    1,    1,    4,    2,    4,    1,
    2,    3,    1,    1,    1,    4,    2,    4,    1,    2,
    3,    1,    1,    1,    4,    3,    2,    2,    5,    2,
    5,    2,    4,    2,    4,    1,    3,    3,    1,    3,
    3,    1,    1,    1,    1,    1,    1,    1,    2,    2,
    1,    1,    2,    3,    3,    3,    0,    1,    2,    3,
    0,    1,    3,    2,    1,    2,    2,    4,    5,    2,
    1,    1,    1,    2,    2,    2,    4,    6,    0,    1,
    1,    1,    4,    2,    4,    0,    2,    4,    0,    1,
    0,    2,    0,    2,    1,    1,    1,    2,    1,    1,
    1,    0,    2,    4,    0,    1,    2,    1,    3,    3,
   10,   13,    0,    2,    0,    3,    0,    2,    1,    4,
    2,    4,    1,    4,    0,    1,    3,    3,    3,    2,
    4,    2,    2,    4,    2,    1,    0,    1,    1,    1,
    2,    2,    1,    2,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,  198,    0,  370,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   19,    0,
    0,    0,    0,    0,    0,   17,  209,    0,    0,    0,
  201,  199,    0,   51,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   18,    0,    0,    0,
    0,    0,   65,    0,    0,    0,  215,  216,    0,    0,
    0,    2,    4,    5,    6,    7,    8,    9,   10,   11,
   12,   13,   14,   15,   24,   16,   22,   21,   23,   20,
    0,    0,    0,    0,    0,   44,    0,    0,    0,   26,
    0,    0,   28,    0,    0,   30,   43,   42,   32,   35,
   34,  428,  429,   36,   37,   39,   40,  285,  284,   33,
   27,   25,  341,  342,   38,    0,  355,    0,    0,    0,
    0,    0,    0,  363,    0,  361,  362,    0,  352,    0,
  223,    0,    0,  222,    0,   98,  233,    0,    0,    0,
    0,    0,   49,   48,   50,    0,    0,  400,  398,  399,
    0,    0,  240,  241,    0,    0,    0,  210,  211,    0,
  212,  213,    0,    0,  218,    0,    0,    0,    0,  420,
    0,    0,  423,    0,  354,  356,  360,  339,  340,  357,
    0,    0,  364,  426,    0,    0,  228,  229,  230,    0,
  226,  238,    0,    0,   89,   85,    0,    0,  237,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  120,
  116,    0,    0,    0,   46,  397,    0,    0,    0,    0,
    0,    0,  206,    0,  207,  100,    0,    0,    0,    0,
    0,  265,    0,    0,    0,    0,    0,    0,  353,  231,
  225,    0,    0,    0,   84,    0,    0,    0,  172,    0,
  110,  168,    0,  160,    0,  140,  151,  122,  123,  117,
  121,  118,  119,  115,  111,   64,    0,  416,    0,    0,
    0,    0,  248,  249,    0,  243,  247,    0,  250,    0,
    0,    0,  203,    0,    0,  106,    0,  105,    0,    0,
    0,    0,    0,  422,   29,    0,  425,   31,    0,  358,
    0,  227,    0,    0,   90,    0,    0,   96,   95,    0,
  234,    0,  235,    0,  136,    0,  134,    0,    0,  139,
    0,  137,    0,    0,    0,    0,    0,  409,    0,    0,
  413,    0,    0,    0,    0,    0,  267,    0,    0,    0,
  259,    0,  268,    0,    0,    0,    0,    0,  208,  109,
    0,  104,    0,    0,   61,   62,   63,    0,    0,    0,
  359,   86,    0,   87,  365,   97,   94,    0,    0,    0,
  125,    0,  133,    0,    0,  166,    0,  162,  127,    0,
  129,    0,    0,    0,  150,    0,  142,  131,    0,    0,
    0,  159,    0,  153,    0,    0,    0,  417,    0,  419,
  418,    0,    0,    0,    0,  430,    0,    0,    0,    0,
    0,  264,  287,  295,    0,  275,  276,    0,    0,    0,
    0,  274,    0,    0,  404,    0,    0,  255,    0,  253,
    0,  251,    0,  107,    0,    0,    0,  408,  421,  424,
  349,    0,  236,  169,    0,  170,  135,  165,  164,    0,
  138,    0,  144,    0,  146,    0,  148,    0,    0,  155,
  157,  158,    0,    0,    0,    0,    0,  386,  387,    0,
  389,  390,  391,  385,    0,    0,  244,    0,  245,    0,
  431,  432,  434,  292,    0,    0,    0,    0,    0,    0,
    0,    0,  263,    0,    0,    0,  261,   66,    0,  272,
  108,    0,    0,    0,   88,    0,  163,    0,    0,    0,
  143,    0,  154,    0,    0,  411,  414,    0,  410,  388,
  380,  384,  173,    0,    0,    0,  293,  269,  278,  279,
  280,  286,  283,  282,  406,    0,    0,    0,    0,   72,
    0,    0,    0,    0,   78,    0,    0,    0,   76,   71,
    0,    0,   57,   60,    0,    0,    0,    0,    0,  186,
    0,  185,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  195,    0,  181,  182,  187,  184,  188,  178,    0,
  171,    0,    0,    0,    0,  270,    0,    0,  246,  288,
    0,  289,    0,  372,    0,  401,  256,  254,    0,   73,
   81,   83,   82,   74,   77,   79,  336,  337,   75,    0,
   70,  273,    0,  317,  314,    0,    0,  332,  333,    0,
    0,  318,  334,  335,    0,    0,  320,    0,    0,  343,
  303,  304,    0,    0,    0,  179,  296,  312,  313,    0,
    0,    0,  180,  305,  183,    0,  196,  197,  191,  366,
    0,  192,  189,    0,  193,  294,    0,  177,    0,    0,
    0,    0,    0,  412,    0,    0,    0,    0,   80,   53,
  316,    0,    0,    0,    0,    0,    0,  344,  345,    0,
    0,  301,    0,    0,  310,  346,    0,    0,  190,    0,
    0,    0,  156,    0,  290,    0,    0,  378,  371,  257,
    0,  315,    0,    0,  327,  328,    0,    0,  330,  331,
    0,    0,    0,  302,    0,    0,  311,  367,    0,  194,
    0,    0,    0,    0,  402,  374,  373,    0,   54,   58,
    0,    0,  319,    0,  322,  321,    0,  324,  350,  297,
    0,  298,  306,    0,  307,    0,  145,  147,  149,    0,
    0,   55,   56,    0,    0,    0,    0,  368,    0,  375,
  323,  325,  299,  308,  394,
};
static const YYINT yydgoto[] = {                          2,
   79,  277,  167,  225,  140,  651,  656,  664,  671,  639,
  370,  134,  679,   21,   89,  185,  579,  141,  156,  391,
  440,  157,   22,   23,  178,   24,  604,  647,   52,  685,
  728,  441,  550,  250,  433,  306,  307,  605,  733,  652,
  737,  657,  190,  193,  310,  371,  311,  462,  372,  545,
  373,  452,  453,  466,  727,  625,  361,  496,  362,  377,
  460,  569,  442,  555,  443,  666,  742,  667,  673,  745,
  674,  302,  755,  567,  338,  129,  375,   55,   57,  175,
  444,  607,  708,  158,  159,   75,  196,   76,  220,  221,
  163,  333,  226,  608,  281,  399,  282,  240,  346,  347,
  351,  352,  416,  417,  353,  423,  424,  355,  407,  408,
  348,  290,  533,  609,  610,  275,  339,  340,  169,  241,
  242,  528,  580,  581,  256,  318,  319,  428,  504,  505,
  457,  385,   25,   26,   27,   28,   29,   30,   31,   32,
   33,   34,   35,   36,   37,    3,  123,  202,  264,  126,
  266,  731,  584,  643,  529,  215,  276,  257,  170,  354,
  356,  349,  534,  429,
};
static const YYINT yysindex[] = {                       -43,
    0,  746, 1358,   92,    0,  512,    0,   72, -277, -166,
 -166, -166, 1609, -144, -152,  -31, -135,  -59,  209,    0,
  474,  196,  -31,  196,  272,  280,  300,  308,  411,  427,
  435,  454,  479,  509,  526,  551,  562,  566,    0,  573,
  689,  601,  603,  605,  612,    0,    0,  431,  587,  591,
    0,    0,  275,    0,  196, -166,  -31,  -31,  -31,  291,
  -89,  -72, -227, -199, -231,  295,  302,  -31,  -35, -166,
  153, 1836,  650,  430,  372,  470,    0,   10,    0,  -31,
 -166,  316,    0,   -5,   -5,   -5,    0,    0, -144,  394,
 -144,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  419,  391,  463,  685,  476,    0,  394,  394,  394,    0,
  371,  758,    0,  401,  758,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  416,    0,  434,  450,  344,
  457,  467,  751,    0,  469,    0,    0,  795,    0,  620,
    0,  -12,  394,    0,  758,    0,    0,  485,  519, 1832,
    0,  607,    0,    0,    0,  316,  430,    0,    0,    0,
  -31,  -31,    0,    0,  604,  -31,  503,    0,    0,  481,
    0,    0,  850,    0,    0,  -31,  604,  604,  604,    0,
  758,  556,    0,  577,    0,    0,    0,    0,    0,    0,
  908,  586,    0,    0, 1836, -166,    0,    0,    0,  518,
    0,    0,  758,  485,    0,    0,    0,  963,    0,  -54,
  969,  973,  979, 1010, 1025,  511,  686,  704,  720,    0,
    0, 1832,  -54, -166,    0,    0,  394,  661,  -40, -158,
  394, 1066,    0,  463,    0,    0,  -81,  394, -158, -158,
 -158,    0,  758,   55,  758,   64,  725, 1052,    0,    0,
    0,  620,  -32, 1078,    0, -198,   71,  758,    0,  758,
    0,    0,  742,    0,  743,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  604,    0,   52,   52,
   52,  394,    0,    0,  758,    0,    0,  -26,    0,  754,
  873,  604,    0, 1095,  756,    0,  758,    0,  -81,  604,
  783,  783,  783,    0,    0,  556,    0,    0,  577,    0,
  773,    0,   79,  758,    0,  762,  764,    0,    0, -198,
    0,  963,    0,  763,    0,  679,    0, 1115,  301,    0,
  680,    0, 1116,  616, 1117,  529,  899,    0,  758,  787,
    0,    0,    0,    0,  604,  550,    0,   17,  758,  815,
    0,  888,    0,  790,  963,  -52,  909, -158,    0,    0,
   -6,    0, -158,  792,    0,    0,    0,  758,  758,  812,
    0,    0,  -32,    0,    0,    0,    0,  758,   81,  758,
    0,  742,    0,  -35,  -35,    0,  795,    0,    0,  743,
    0,   67,   98,  241,    0,  795,    0,    0,  324,  511,
  -35,    0,  795,    0,   86,   16,   86,    0,  848,    0,
    0, -158,   97,  758,  758,    0, 1120, 1133, 1136,  316,
  816,    0,    0,    0,    7,    0,    0,  459, 1153,  819,
  823,    0, 1168,   17,    0,  843,  783,    0,  758,    0,
  -26,    0,    0,    0,  758,  154,    0,    0,    0,    0,
    0,  758,    0,    0,  763,    0,    0,    0,    0,  301,
    0,  511,    0,  511,    0,  511,    0,  616,  511,    0,
    0,    0,  529,  949,  758,  163, 1178,    0,    0, -166,
    0,    0,    0,    0,  848,    0,    0,  550,    0,  117,
    0,    0,    0,    0,  316,  180,  844,  842,  851, 1190,
 1174,  866,    0, -166,  944,  868,    0,    0, 1344,    0,
    0,    7, 1141, 3355,    0,  758,    0,  795,  795,  795,
    0,  -35,    0,    7,  754,    0,    0,   16,    0,    0,
    0,    0,    0,  758,  194,  758,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  134,    0,  758,  230,    0,
  881,  811,  886,  889,    0,  893,  561,  900,    0,    0,
 1344,  758,    0,    0,  -21,  -30,   96,  996,  997,    0,
  999,    0,  130,  149,  561, 1009,  588,   28,  910, -166,
  617,    0,  922,    0,    0,    0,    0,    0,    0, 3355,
    0,  918,  919,  920,  511,    0,  963,  758,    0,    0,
  117,    0,  758,    0, 1021,    0,    0,    0,  868,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -166,
    0,    0, 1302,    0,    0,  930, 1272,    0,    0,  758,
 1040,    0,    0,    0,  758, 1041,    0, 1292, 1292,    0,
    0,    0,  758,  948,  622,    0,    0,    0,    0,  758,
  950,  633,    0,    0,    0, 1292,    0,    0,    0,    0,
  951,    0,    0, 1059,    0,    0, -166,    0,  795,  795,
  795, 1295,  783,    0,  758,   86,  316,  758,    0,    0,
    0,  930,  639,  642,  646,  652, 1836,    0,    0,  140,
  622,    0,  273,  633,    0,    0,  766,  316,    0,  511,
  511,  511,    0, 1061,    0,  758,  455,    0,    0,    0,
  757,    0,  538,  758,    0,    0,  572,  758,    0,    0,
  789,  576,  758,    0,  602,  758,    0,    0,  967,    0,
 1318, 1321, 1324,   86,    0,    0,    0,   86,    0,    0,
 1356, 1357,    0,  639,    0,    0,  646,    0,    0,    0,
  140,    0,    0,  273,    0, 1328,    0,    0,    0, 1086,
  758,    0,    0,  758,  758,  758,  758,    0,  316,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         6,
    0,  478,  847,    0,    0, 1543,    0,    0, 2613,    0,
    0,    0,    0, 1038,    0, 1510,    0,    0,    0,    0,
    0, 2163, 2138, 3842,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, 1611, 1734, 1858,
    0,    0,    0,    0, 2896, 1170,  413,  413,  413,    0,
    0,    0,    0,    0,    0,    0,    0, 1362,    0,    0,
    0,    0, 1049, 1296,    0, 1417,    0,  991, 1719,  915,
    0,    0,    0, 2218, 2218,  779,    0,    0, 2676, 3922,
 2830,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, 3013,    0,  569,  569,  569,    0,
    0,  993,    0,    0,  993,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   50,
    0,    0,    0,    0,    0,    0,    0,  265,    0,    0,
    0,    0,   13,    0,  -16,    0,    0,    0,    0,    0,
  943,    0,    0,    0,    0, 1368, 3964,    0,    0,    0,
  810, 2786,    0,    0, 2326, 3862,    0,    0,    0,  656,
    0,    0,    0,    4,    0, 3100,   74,   74,   74,    0,
  172,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  744,
    0,    0,   49,    0,    0,    0,   47,  991,    0, 1369,
  256,  635,  747,  807,  901,    0,    0,    0,    0,    0,
    0,    5, 1369,    0,    0,    0,   34, 3143,    0, 1684,
 3912,    0,    0,    0,    0,    0,    0, 3229,   15,   15,
   15,    0,   46,  787,   46,  787,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -14,  -20,    0,  993,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 1113,    0,    0,    0,
    0, 3315,    0,    0,  659,    0,    0,  892,    0,  103,
 2042, 1223,    0,    0,    0,    0,  207,    0,  526, 3423,
 1371, 1371, 1371,    0,    0,    0,    0,    0,    0,    0,
  177,    0,   60,   -9,    0,    0,    0,    0,    0,  272,
    0,  991,    0,    0,    0,  787,    0,    0,    0,    0,
  787,    0,    0,    0,    0,    0,    0,    0,   49,    0,
    0, 2376, 2376, 2376, 3466,    0,    0,    0,  190,    0,
    0, 1945,    0,    0,  442,    0, 2260, 1470,    0,    0,
  892,    0, 3509,    0,    0,    0,    0,   46,   46,  799,
    0,    0,    0,    0,    0,    0,    0,  -20,  787,   46,
    0,    0,    0,    0,    0,    0,  461,    0,    0,    0,
    0,    0,    0,    0,    0,  578,    0,    0,    0,    0,
    0,    0,  287,    0,    0,    0,    0,    0,    0,    0,
    0, 3552,  656,   44,  534,    0,    0,  674,  684,    0,
  611,    0,    0,    0,  892,    0,    0,  414,    0,    0,
    0,    0,  524,    0,    0,    0,  158,    0,  993,    0,
  892,    0, 1790,    0,   26, 1241, 3595,    0,    0,    0,
    0,   -9,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   20,   -9,   60,    0,    0,    0, 2486,
    0,    0,    0,    0, 3186, 3746,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1241,    0,    0,    0,    0,
    0,    0,    0,    0,  250,    0,    0,    0, 1017,    0,
    0,  892, 1373, 1017,    0,   46,    0, 1007, 1007, 1007,
    0,    0,    0,  892,   11,    0,    0,    0,    0,    0,
    0,    0,    0,   44,  805,   14,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  315,   46,  787,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   22,   26,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   19,
    0,    0,    0,    0,    0,    0,    8,   -9,    0,    0,
    0,    0,  143,    0,  407,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  659,
  839,    0,    0,    0,  659,  926,    0, 3638, 3638,    0,
    0,    0,  534,  104,    0,    0,    0,    0,    0,  534,
  729,    0,    0,    0,    0, 3638,    0,    0,    0,    0,
    0,    0,    0, 3706,    0,    0,    0,    0,  656,  656,
  656,    0,   12,    0,   14,    0,    0,   46,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  787,    0,    0,    0,
    0,    0,    0, 1385,    0,  537,  186,    0,    0,    0,
    0,    0,  656,   44,    0,    0,  656,   44,    0,    0,
 2354,  805,   14,    0,  805,   14,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, 1386,
  537,    0,    0,   44,   44,   14,   14,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
 1335,    0, -208,  285,  327,    0,    0, -422, -519,  802,
  -66,    0,    0, 1395,   80,  739,    0,    0,    0,    0,
 -529, 1329,    0,    0,  990,    0,    0, -171,    0,  681,
  613, -368,    0, 1043,    0, -320,    0,    0,    0, -640,
    0, -506,    0, 1150,  978,  946,    0,    0, -259,    0,
    0,  513,    0,  960,    0,    0, -372,    0,  796,    0,
 -474,    0,  955,    0, -428,    0,    0, -485,    0,    0,
 -308,    0,    0,    0, -479,    0,  867,    0,   -8, 1237,
  -80,    0, -547,  707, 1201,  516,    0,  857,    0, 1145,
    0,    0, -178,    0, 1175,    0, -305,    0,    0, 1018,
    0, 1011,    0,  931,    0,    0,  932,    0,    0,  953,
    0, 1245,  928,  814,    0,    0, 1088,    0, 1255, 1193,
    0,    0,  859,    0,    0, 1122,    0, -326,  937,    0,
  830, -313,    0,    0,    0, 1450, 1451,   -3,   -2,    0,
    0,    0,    0,    0,    0,    0, -169, -120,    0, -168,
    0,    0,    0,    0,    0, -179,    0,    0,    0,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 4338
static const YYINT yytable[] = {                         44,
   45,  176,   58,   59,  204,    1,  166,  224,  386,  387,
  254,  168,  266,  103,  113,    1,  266,  405,  427,  278,
  403,  407,  239,  266,  258,  646,  166,  224,  175,  271,
  266,   68,  263,  122,  266,  265,  430,  431,  400,  166,
  272,  317,  166,  403,  228,  434,  266,  116,  127,  437,
  125,  568,  271,  495,  606,  360,   93,  266,  266,  338,
  130,  142,  734,  665,  672,  266,  132,  681,  280,  266,
  459,  514,  172,  266,  266,  266,  438,  436,  439,    1,
  262,  556,  305,  242,  326,  266,  329,  266,  266,  266,
  338,  360,  650,  338,  334,  176,  369,  342,  214,  427,
  336,   46,  273,   91,  266,   54,  482,  214,  308,  131,
  223,  709,  403,  300,  214,  266,  369,  309,  464,   73,
   74,  465,  214,  784,  214,  450,  101,  113,  716,  369,
  606,   53,  165,  398,  115,  403,  300,  484,  266,  435,
  214,  175,  324,  525,  327,  451,  557,  300,  266,  437,
  266,  133,  715,  393,  698,  128,  388,  343,  337,  344,
  389,  168,  437,  300,  300,  300,  402,  407,  266,  536,
  266,  410,  437,  450,  359,  618,  438,  436,  439,  325,
  665,  437,  266,  672,  366,  465,  347,  554,  328,  438,
  436,  439,  695,  451,  747,  341,  381,  214,  738,  438,
  436,  439,  266,  392,  266,  474,  214,  270,  438,  436,
  439,  266,  315,  394,  472,  266,   56,  347,  655,  475,
  347,  507,  266,  214,  743,  427,  300,  480,  300,  266,
   77,  266,  266,  266,   78,  296,  488,  214,  426,  266,
  626,  665,  712,  493,  672,  427,  266,   80,  445,  266,
  367,  177,  663,  508,   81,  644,  623,  368,   73,  376,
  785,    1,    1,    1,    1,  124,  266,  469,  470,   82,
  367,  670,  582,  214,   41,  168,  258,  473,  531,  476,
  486,   92,  258,  367,  616,  786,  532,  547,  744,   93,
    1,    1,    1,  121,  266,  405,  266,  101,  403,  407,
  239,  316,  266,    1,  558,  437,  239,  271,  456,   94,
  124,  239,  266,  509,  510,    1,  548,   95,  620,    1,
    1,    1,    1,    1,  383,  266,  266,  152,  279,  266,
  458,  266,  438,  436,  439,  242,  532,    1,  526,    1,
  242,  242,  303,  304,  530,   91,    1,  138,  139,  242,
  222,  535,  648,  649,  628,  338,  113,    1,  612,  613,
  614,  645,  266,  489,  405,    1,  266,  403,  427,  239,
  222,  258,  300,  266,  546,  621,  271,  338,  124,  724,
   99,  300,  300,  403,  300,  300,  101,  113,    1,  629,
  403,   99,  271,  271,   99,  300,  266,  266,  358,  173,
  174,  300,  300,   91,  746,  300,  300,  300,  266,  266,
  680,  300,  338,  338,  338,  611,  377,  338,  338,  338,
   96,  338,  232,  277,  338,  338,  266,  266,  266,  300,
  242,  266,  338,  619,  358,  622,   97,  403,  403,  403,
  403,  403,  427,  300,   98,  407,  277,  627,  266,  288,
  289,  405,  229,  277,  277,  300,   87,  277,   88,  403,
  300,  642,  578,   99,  403,  787,  266,  603,  448,  449,
  111,  266,  266,  277,  701,  403,  300,  300,  653,  654,
  288,  289,  347,  266,  300,  300,  300,  300,  100,  266,
  266,  551,  407,  407,  407,  407,  407,  694,  214,  173,
  174,  161,  696,  517,  347,  518,  266,  266,  274,  720,
  721,  722,  661,  662,  578,  565,  448,  449,  101,  407,
  686,  253,  661,  662,  214,  266,  266,  143,  144,  703,
  732,  668,  669,  281,  705,  102,  277,  749,  277,  347,
  347,  347,  710,  603,  347,  347,  347,  758,  347,  713,
  456,  347,  347,  764,  266,  266,  281,  767,  271,  347,
  103,  214,  771,  281,  281,  774,  266,  281,  427,  427,
  427,  104,  266,  266,  725,  105,  266,  730,  239,  757,
  266,  214,  106,  281,  376,  376,  376,  376,  376,  266,
  266,  683,  427,  266,  266,  266,  266,  124,  124,  124,
  124,  124,  124,  124,  182,  756,  186,  124,  124,  124,
  107,  376,  108,  765,  109,  214,  729,  768,  141,  214,
  291,  110,  772,  288,  289,  775,  112,  427,  427,  427,
  113,  699,  427,  427,  427,  427,  427,  686,  124,  427,
  427,  427,  427,  291,  132,  214,  281,  427,  281,  381,
  381,  381,  381,  381,  291,  668,  669,  114,  404,  405,
  790,  266,  763,  791,  792,  793,  794,  183,  184,  427,
  291,  291,  291,  120,  232,  277,  381,  135,  719,  232,
  232,  277,  277,  406,  136,  232,  232,  232,  232,  160,
  277,  277,  277,   73,  277,  277,  766,  277,  173,  174,
  770,  277,  277,  277,  162,  277,  288,  289,  729,  208,
  209,  277,  277,  277,  277,  277,  277,  277,  277,  401,
  409,  277,  214,  214,  277,  187,  773,  761,  762,  405,
  478,  479,   83,  291,  164,  291,  369,  277,  309,  277,
  195,  377,  377,  377,  377,  377,  194,  492,  277,  277,
  277,  277,  277,  277,  200,   20,  126,  132,   84,   85,
   86,  309,  369,  369,  369,  277,  759,  201,  377,  232,
  277,   47,  309,  188,  189,  277,  405,  405,  405,  405,
  405,   48,   49,   50,  203,  281,  277,  277,  309,  309,
  309,  281,  281,  277,  277,  277,  277,  277,  405,  205,
  281,  281,  281,  405,  281,  281,  748,  281,  348,  214,
  212,  281,  281,  281,   99,  281,  128,  206,  427,  427,
   51,  281,  281,  281,  281,  281,  281,  281,  281,  769,
  239,  281,  214,  207,  281,  239,  239,  427,  214,  348,
  210,  239,  348,  427,  239,  191,  192,  281,  326,  281,
  211,  309,  213,  309,  450,  197,  198,  199,  281,  281,
  281,  281,  281,  281,  427,  427,  427,  222,  615,  126,
  230,  326,  291,  244,  451,  281,  249,  419,  291,  291,
  281,  760,  326,  420,  421,  281,  252,  216,  291,  291,
  255,  291,  291,  288,  289,  217,  281,  281,  291,  291,
  291,  227,  291,  281,  281,  281,  281,  281,  291,  291,
  130,  422,  291,  291,  291,  291,  266,  266,  291,  266,
  266,  291,  218,  219,  232,  239,  427,  427,  427,  128,
  161,   99,  303,  304,  291,  329,  291,  494,  121,  497,
  179,  179,  179,  637,  638,  291,  291,  291,  291,  291,
  291,   99,  114,  298,  267,  299,  300,  301,  329,  124,
  427,  326,  291,  326,  412,  413,  414,  291,  268,  329,
  677,  678,  291,   84,   85,   86,  132,  132,  132,  132,
  132,  132,  132,  291,  291,  297,  132,  132,  132,  312,
  291,  291,  291,  291,  291,  166,  320,  309,  415,  684,
  174,    4,    5,    6,  661,  662,  309,  309,  283,  309,
  309,  427,  284,    5,    6,  668,  669,  132,  285,  427,
  309,  648,  649,  130,  735,  736,  309,  309,  653,  654,
  309,  309,  309,  246,  739,  740,  309,  232,  427,  427,
  365,  266,  266,    7,  395,  395,  427,  427,  329,  286,
  329,  395,  395,  395,  309,    8,  433,  433,  224,    9,
   10,   11,   12,   13,  287,  114,  435,  435,  309,  291,
    9,   10,   11,   12,  180,  181,  232,   14,  624,   15,
  309,  224,  232,  232,  232,  309,   16,  292,  126,  126,
  126,  126,  126,  126,  126,  363,  364,   17,  126,  126,
  126,  309,  309,  293,  348,   18,  313,  326,  330,  309,
  309,  309,  309,  331,  446,  447,  326,  326,  335,  326,
  326,  631,  632,  633,  345,  350,  348,  374,   19,  126,
  326,  369,  369,  369,  376,  379,  326,  326,  380,  384,
  326,  326,  326,  390,  395,  279,  326,  396,  128,  128,
  128,  128,  128,  128,  128,  403,  411,  418,  128,  128,
  128,  348,  348,  348,  326,  425,  348,  348,  348,  427,
  348,  454,  455,  348,  348,  468,  461,  471,  326,   45,
  511,  348,  498,  499,  500,  501,  502,  427,  427,  128,
  326,   99,   99,  512,  329,  326,  513,  448,  449,  519,
  515,  520,   45,  329,  329,  521,  329,  329,  726,  503,
   45,  326,  326,   45,  522,  524,  544,  329,  549,  326,
  326,  326,  326,  329,  329,  560,  559,  329,  329,  329,
  562,  566,  242,  329,  561,  563,  321,  322,  323,  259,
  260,  261,  130,  130,  130,  130,  130,  130,  130,  564,
  458,  329,  130,  130,  130,  242,  232,  232,  232,  232,
  232,  232,  232,  583,  630,  329,  780,  232,  232,  634,
  781,  635,  640,  427,   99,   99,  636,  329,  658,  659,
  427,  660,  329,  130,  112,  112,  112,  112,  112,  112,
  112,  676,   45,  682,  687,  112,  112,  232,  329,  329,
  427,  689,  690,  691,  697,  221,  329,  329,  329,  329,
  224,  700,  645,  224,  224,  224,  224,  224,  702,  704,
  706,  224,  224,  224,  224,  114,  224,  224,  221,  224,
  224,  707,  711,  717,  714,  723,  224,  224,  224,  357,
  224,  224,  718,  224,  224,  224,  224,  224,  754,  776,
  224,  224,  224,  224,  378,  463,  224,   90,  777,  224,
  467,  778,  383,  427,  779,  782,  783,   39,  788,  789,
  219,  232,  224,   99,  224,  266,  166,   47,  167,  242,
  407,  224,   59,  224,  224,  224,  224,  224,  224,   99,
  427,  117,  118,  119,  392,  393,  675,   41,  750,  145,
  224,  795,  137,  314,  516,  224,  527,  432,  523,  506,
  224,  617,  245,  741,  171,  269,  332,  295,  541,  477,
  481,  224,  224,  688,  543,  243,  220,  397,  224,  224,
  224,   45,  537,  553,  294,   45,   45,   45,   45,  641,
  382,  552,   45,   45,   45,   45,  693,   45,   45,  220,
   45,   45,   42,   43,    0,    0,    0,   45,   45,   45,
    0,   45,    0,    0,    0,    0,    0,   45,   45,    0,
    0,   45,   45,   45,   45,    0,    0,   45,    0,  258,
   45,    0,   40,    0,  242,    0,    0,    0,    0,  242,
  242,    0,    0,   45,    0,   45,    0,    0,  242,    0,
    0,    0,  258,    0,   45,   45,   45,   45,   45,   45,
    0,  242,  242,    0,    0,  247,  248,  427,    0,    0,
  251,   45,    0,    0,  242,    0,   45,  242,    0,    0,
  258,   45,    0,  242,    0,    0,    0,    0,    0,    0,
  427,  427,   45,   45,    0,    0,  242,    0,    0,   45,
   45,   45,  200,    0,    0,    0,    0,  221,    0,    0,
    0,  221,  221,  221,  221,    0,    0,    0,  221,  221,
  221,  221,    0,  221,  221,  200,  221,  221,    0,  242,
    0,    0,    0,    0,  221,  221,    0,  221,  221,    0,
  221,  221,  221,  221,  221,  242,    0,  221,  221,  221,
  221,    0,  242,  221,    0,    0,  221,    0,    0,    0,
    0,    0,    0,   38,    5,    6,    0,    0,    0,  221,
  202,  221,    0,  427,  427,    0,    0,    0,  221,    0,
    0,    0,  570,  571,    0,  221,    0,    0,    0,    0,
    0,    0,    0,  202,    0,  572,    0,  221,  573,    0,
    0,    0,  221,    0,  574,    7,  483,  485,  487,    0,
    0,    0,    0,  490,  491,    0,    0,  575,  221,  221,
    0,    9,   10,   11,   12,  221,  221,  221,  220,    0,
    0,    0,  220,  220,  220,  220,    0,    0,    0,  220,
  220,  220,  220,  258,  220,  220,    0,  220,  220,    0,
  576,    0,    0,    0,    0,  220,  220,    0,  220,  220,
    0,  220,  220,  220,  220,  220,  258,    0,  220,  220,
  220,  220,    0,  577,  220,    0,  538,  220,  539,    0,
  540,  258,    0,  542,    0,    0,    0,  258,    0,    0,
  220,    0,  220,  204,    0,    0,    0,    0,    0,  220,
    0,    0,    0,    0,    0,    0,  220,    0,  258,  258,
    0,    0,    0,    0,    0,    0,  204,    0,  220,    0,
    0,  258,    0,  220,  258,    0,    0,    0,    0,    0,
  258,    0,    0,    0,    0,    0,    0,    0,    0,  220,
  220,    0,    0,  258,    0,    0,  220,  220,  220,   69,
    0,    0,    0,  200,  200,  200,  200,  200,  200,  200,
  200,  200,    0,    0,    0,  200,  200,  200,  200,    0,
  200,  200,   67,  200,  200,    0,  258,    0,    0,    0,
    0,    0,    0,    0,  200,  200,    0,  200,  200,  200,
  200,  200,  258,    0,  200,  200,  200,    0,    0,  258,
  200,  232,  232,  232,  232,  232,  232,  232,    0,  692,
    0,  232,  232,  232,    0,    0,    0,  205,  200,    0,
    0,  202,  202,  202,  202,  202,  202,  202,  202,  202,
    0,    0,  200,  202,  202,  202,  202,    0,  202,  202,
  205,  202,  202,    0,  200,    0,    0,    0,    0,  200,
    0,    0,  202,  202,    0,  202,  202,  202,  202,  202,
    0,    0,  202,  202,  202,  200,  200,    0,  202,    0,
    0,    0,    0,  200,  200,    0,    0,   60,   61,   62,
   63,   64,    0,   65,    0,   66,  202,   67,   68,   69,
    0,    0,    0,    0,    0,  258,    0,    0,    0,    0,
  202,  258,    0,    0,  262,    0,    0,    0,    0,    0,
    0,    0,  202,    0,  751,  752,  753,  202,    0,   70,
    0,  258,    0,    0,    0,    0,    0,  262,    0,    0,
    0,    0,    0,  202,  202,   71,   72,    0,    0,    0,
    0,  202,  202,    0,  204,  204,  204,  204,  204,  204,
  204,  204,  204,    0,    0,    0,  204,  204,  204,  204,
    0,  204,  204,    0,  204,  204,    0,    0,  258,  258,
  258,  258,  258,    0,    0,  204,  204,    0,  204,  204,
  204,  204,  204,    0,    0,  204,  204,  204,    0,    0,
  258,  204,    0,    0,    0,  258,    0,    0,    0,    0,
    0,  252,    0,    0,    0,    0,  258,  258,    0,  204,
  112,  112,  112,  112,  112,  112,  112,  262,    0,    0,
  114,  112,  112,  204,  252,    0,    0,    0,   67,   67,
    0,    0,    0,    0,    0,  204,    0,    0,    0,    0,
  204,   67,    0,    0,   67,    0,    0,    0,    0,    0,
   67,    0,    0,    0,    0,    0,  204,  204,    0,    0,
    0,    0,    0,   67,  204,  204,    0,    0,  205,  205,
  205,  205,  205,  205,  205,  205,  205,    0,    0,    0,
  205,  205,  205,  205,    0,  205,  205,    0,  205,  205,
    0,  146,    0,    0,    0,    0,   67,  232,    0,  205,
  205,    0,  205,  205,  205,  205,  205,    0,    0,  205,
  205,  205,   67,  147,  252,  205,    0,    0,    0,   67,
  232,    0,  214,  231,  232,  233,  234,  235,  236,  237,
    0,    0,    0,  205,  238,  239,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  214,    0,  205,  148,  149,
  150,    0,    0,  151,  152,  153,  262,  154,    0,  205,
  143,  144,  262,  262,  205,    0,    0,    0,  155,    0,
    0,    0,  262,  262,    0,  262,  262,  395,    0,    0,
  205,  205,  262,  262,  262,    0,  262,    0,  205,  205,
    0,    0,  262,  262,    0,    0,  262,  262,  262,  262,
  395,    0,  262,    0,    0,  262,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  262,  260,
  262,    0,    0,    0,    0,    0,    0,    0,    0,  262,
  262,  262,  262,  262,  262,    0,    0,    0,    0,    0,
    0,    0,  260,    0,    0,    0,  262,    0,    0,    0,
    0,  262,    0,    0,    0,    0,  262,    0,    0,  252,
  252,    0,    0,    0,    0,    0,    0,  262,  262,  252,
  252,    0,  252,  252,  262,  262,  262,    0,    0,  252,
  252,  252,    0,  252,    0,  242,    0,    0,    0,  252,
  252,    0,    0,  252,  252,  252,  252,    0,    0,  252,
    0,    0,  252,    0,    0,    0,    0,    0,  242,    0,
    0,    0,    0,    0,    0,  252,    0,  252,    0,    0,
    0,    0,    0,    0,    0,    0,  252,  252,  252,  252,
  252,  252,  260,    0,    0,  383,    0,    0,    0,    0,
    0,    0,    0,  252,    0,    0,    0,    0,  252,  232,
    0,    0,    0,  252,  232,  232,    0,    0,  383,    0,
  232,  232,  232,  232,  252,  252,    0,    0,    0,    0,
    0,  252,  252,  252,  214,  232,  214,  214,  214,  214,
  214,  214,    0,    0,    0,  214,  214,  214,  214,    0,
  214,  214,    0,  214,  214,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  214,  214,    0,  214,  214,  214,
  214,  214,    0,    0,  214,  214,  214,    0,    0,    0,
  214,    0,  232,  232,  232,  232,  232,    0,    0,  395,
    0,    0,    0,  395,  395,  395,    0,    0,  214,    0,
  395,  395,  395,  395,  232,  379,    0,    0,    0,  232,
    0,    0,  214,    0,    0,  395,    0,    0,    0,    0,
  232,  232,    0,    0,  214,    0,    0,    0,  379,  214,
    0,    0,    0,    0,    0,    0,    0,    0,  260,    0,
    0,    0,    0,    0,    0,  214,  214,  260,  260,    0,
  260,  260,    0,  214,  214,    0,    0,  260,  260,  260,
    0,  260,  395,  395,  395,  395,  395,  260,  260,    0,
    0,  260,  260,  260,  260,    0,    0,  260,    0,    0,
  260,    0,    0,    0,  395,    0,    0,    0,    0,  395,
    0,    0,    0,  260,    0,  260,    0,  242,    0,    0,
  395,  395,  242,  242,  260,  260,  260,  260,  260,  260,
    0,  242,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  260,    0,  242,    0,    0,  260,    0,    0,    0,
    0,  260,   52,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  260,  260,    0,    0,    0,  383,    0,  260,
  260,  260,  383,  383,  383,   52,    0,    0,  383,  383,
  383,  383,    0,  383,  383,    0,  383,  383,    0,  427,
  242,  242,  242,  242,  242,    0,    0,  383,    0,    0,
    0,    0,    0,  383,  383,    0,    0,  383,  383,  383,
    0,  427,  242,  383,    0,  219,    0,  242,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  242,  242,
    0,  383,    0,    0,    0,    0,    0,    0,  219,    0,
  381,  381,  381,  381,  381,  383,  427,  427,  427,    0,
    0,  427,  427,  427,    0,  427,    0,  383,  427,  427,
    0,    0,  383,    0,    0,   52,  427,  381,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  379,  383,  383,
    0,    0,  379,  379,  379,    0,  383,  383,  379,  379,
  379,  379,    0,  379,  379,    0,  379,  379,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  379,    0,    0,
    0,    0,    0,  379,  379,    0,    0,  379,  379,  379,
    0,    0,    0,  379,    0,  232,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  379,    0,    0,    0,    0,    0,    0,  232,    0,
  379,  379,  379,  379,  379,  379,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  379,    0,  219,
    0,    0,  379,    0,    0,    0,    0,  379,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  379,  379,
    0,    0,  219,    0,    0,    0,  379,  379,    0,    0,
    0,    0,    0,   52,   52,   52,    0,   52,   52,   52,
   52,   52,    0,    0,    0,   52,   52,   52,   52,    0,
   52,   52,    0,   52,   52,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   52,  214,    0,    0,    0,    0,
   52,   52,    0,    0,   52,   52,   52,    0,    0,    0,
   52,    0,    0,    0,    0,    0,    0,    0,  214,    0,
    0,    0,    0,    0,    0,    0,    0,  219,   52,    0,
    0,  219,  219,  219,  219,    0,    0,    0,  219,  219,
  219,  219,   52,  219,  219,    0,  219,  219,    0,    0,
    0,    0,    0,    0,   52,    0,    0,  219,  219,   52,
  219,  219,  219,  219,  219,    0,    0,  219,  219,  219,
    0,    0,    0,  219,    0,   52,   52,    0,    0,    0,
    0,    0,    0,   52,   52,    0,    0,    0,    0,    0,
    0,  219,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  219,    0,    0,  214,    0,
    0,    0,  217,    0,    0,    0,    0,  219,    0,    0,
    0,    0,  219,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  217,    0,  232,  219,  219,
    0,    0,  232,  232,  232,    0,  219,  219,  232,  232,
  232,  232,    0,  232,  232,    0,  232,  232,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  232,  232,    0,
  232,  232,  232,  232,  232,    0,    0,  232,  232,  232,
    0,  219,    0,  232,    0,  219,  219,  219,    0,    0,
    0,    0,  219,  219,  219,  219,    0,    0,    0,  232,
    0,  232,    0,    0,    0,    0,    0,    0,  219,  219,
    0,    0,    0,    0,    0,  232,    0,    0,    0,    0,
    0,  219,  232,    0,  219,  217,    0,  232,    0,    0,
  219,    0,  232,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  415,  219,    0,    0,    0,  214,  232,  232,
  214,  214,  214,  214,  214,    0,  232,  232,  214,  214,
  214,  214,    0,  214,  214,  415,  214,  214,    0,    0,
    0,    0,    0,    0,    0,    0,  219,  214,    0,    0,
    0,    0,    0,  214,  214,  382,    0,  214,  214,  214,
    0,    0,  219,  214,    0,    0,    0,    0,    0,  219,
    0,    0,    0,    0,    0,    0,    0,    0,  382,    0,
    0,  214,  232,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  214,    0,    0,  239,    0,
    0,    0,    0,    0,    0,    0,    0,  214,    0,    0,
    0,    0,  214,    0,    0,    0,    0,    0,    0,    0,
    0,  239,    0,    0,    0,    0,    0,    0,  214,  214,
    0,    0,    0,    0,  217,    0,  214,  214,  217,  217,
  217,  217,    0,    0,    0,  217,  217,  217,  217,    0,
  217,  217,    0,  217,  217,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  217,    0,    0,    0,    0,    0,
  217,  217,    0,    0,  217,  217,  217,    0,    0,    0,
  217,    0,    0,    0,  239,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  217,    0,
    0,    0,    0,    0,    0,    0,    0,  239,    0,    0,
    0,  239,  217,    0,    0,    0,    0,    0,    0,    0,
    0,  232,    0,    0,  217,    0,  232,  232,  232,  217,
    0,    0,  232,  232,  232,  232,    0,  232,  232,    0,
  232,  232,    0,    0,    0,  217,  217,  166,    0,    0,
    0,  232,    0,  217,  217,    0,    0,  232,  232,    0,
    0,  232,  232,  232,  415,    0,    0,  232,    0,  415,
  415,  415,    0,    0,    0,  415,  415,  415,  415,    0,
  415,  415,    0,  415,  415,  232,    0,    0,    0,    0,
    0,    0,  242,    0,  415,    0,    0,    0,    0,  232,
  415,  415,    0,    0,  415,  415,  415,  382,    0,    0,
  415,  232,  382,  382,  382,  242,  232,    0,  382,  382,
  382,  382,    0,  382,  382,    0,  382,  382,  415,    0,
    0,    0,  232,  232,    0,  242,    0,  382,    0,    0,
  232,  232,  415,  382,  382,    0,    0,  382,  382,  382,
  239,    0,    0,  382,  415,  239,  239,  239,  242,  415,
    0,  239,    0,    0,  239,    0,  239,  239,    0,  239,
  239,  382,    0,    0,    0,  415,  415,    0,  258,    0,
  239,    0,    0,  415,  415,  382,  239,  239,    0,    0,
  239,  239,  239,    0,    0,    0,  239,  382,    0,    0,
    0,  258,  382,    0,    0,  242,    0,    0,    0,    0,
    0,    0,    0,    0,  239,    0,    0,    0,  382,  382,
    0,  258,    0,    0,    0,    0,  382,  382,  239,    0,
    0,    0,    0,    0,    0,    0,  239,    0,    0,    0,
  239,  239,  239,  239,  258,  239,    0,  239,    0,    0,
  239,    0,  239,  239,    0,  239,  239,    0,    0,    0,
    0,  239,  239,    0,  176,    0,  239,    0,    0,  239,
  239,    0,  239,  239,    0,    0,  239,  239,  239,    0,
    0,    0,  239,  585,    0,    0,    0,  174,    0,    0,
    0,  258,  586,  587,    0,  588,  589,    0,    0,    0,
  239,    0,    0,    0,    0,    0,  590,  351,    0,    0,
    0,    0,  591,  336,  239,    0,  592,  593,  594,    0,
    0,    0,  595,    0,    0,    0,  239,    0,    0,    0,
  351,  239,    0,    0,    0,    0,    0,    0,    0,    0,
  596,    0,    0,    0,  242,    0,    0,  239,  239,  242,
  242,  242,    0,    0,  597,  239,  239,    0,  242,    0,
  242,  242,    0,  242,  242,    0,  598,    0,    0,    0,
    0,  599,    0,    0,  242,   49,    0,  176,    0,    0,
  242,  242,    0,    0,  242,  242,  242,  242,  600,    0,
  242,    0,  242,  242,  242,  601,  602,    0,   49,    0,
    0,  242,    0,  242,  242,    0,  242,  242,  242,    0,
    0,    0,    0,    0,    0,  176,    0,  242,    0,    0,
  351,    0,  242,  242,  242,    0,    0,  242,  242,  242,
  258,    0,    0,  242,  242,    0,  258,  258,  174,  242,
    0,    0,    0,    0,    0,    0,  258,  258,    0,  258,
  258,  242,    0,    0,    0,  242,  242,    0,    0,    0,
  258,    0,    0,  242,  242,  242,  258,  258,    0,    0,
  258,  258,  258,  258,    0,    0,  258,  242,    0,  258,
  258,    0,  242,    0,    0,    0,    0,    0,   49,  258,
  258,    0,  258,  258,  258,    0,    0,    0,  242,  242,
    0,    0,    0,  258,    0,    0,  242,  242,  258,  258,
  258,  214,    0,  258,  258,  258,    0,    0,    0,  258,
  258,    0,    0,  174,    0,  258,    0,    0,    0,    0,
    0,  232,  174,  174,  214,  174,  174,  258,    0,    0,
    0,  258,  258,    0,    0,    0,  174,    0,    0,  258,
  258,  258,  174,  174,  232,    0,  174,  174,  174,    0,
    0,    0,  174,  258,    0,    0,  351,    0,  258,    0,
    0,    0,    0,    0,    0,  351,  351,    0,  351,  351,
  174,  239,    0,    0,  258,  258,    0,    0,    0,  351,
    0,  239,  258,  258,  174,  351,  351,    0,    0,  351,
  351,  351,    0,    0,  239,  351,  174,    0,    0,    0,
    0,  174,    0,    0,  239,    0,    0,    0,    0,    0,
    0,    0,    0,  351,    0,    0,    0,  174,  174,    0,
    0,    0,    0,  396,   49,  174,  174,  351,    0,    0,
    0,    0,    0,   49,   49,    0,   49,   49,    0,  351,
    0,    0,    0,    0,  351,    0,  396,   49,    0,    0,
    0,    0,    0,   49,   49,    0,    0,   49,   49,   49,
  351,  351,    0,   49,  174,    0,    0,    0,  351,  351,
    0,    0,    0,  174,  174,    0,  174,  174,    0,    0,
    0,   49,    0,    0,    0,    0,    0,  174,    0,    0,
    0,    0,    0,  174,  174,   49,    0,  174,  174,  174,
    0,    0,    0,  174,    0,    0,    0,   49,    0,    0,
    0,    0,   49,    0,    0,    0,    0,    0,    0,    0,
    0,  174,    0,    0,    0,    0,    0,    0,   49,   49,
    0,    0,    0,    0,    0,  174,   49,   49,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  174,    0,    0,
    0,    0,  174,  214,    0,  214,  214,  214,  214,  214,
    0,    0,    0,    0,  214,  214,  214,  214,  174,  174,
    0,    0,    0,  232,    0,    0,  174,  174,  232,  232,
  214,  214,    0,    0,  232,  232,  232,  232,    0,    0,
    0,    0,    0,  214,    0,    0,  214,    0,    0,    0,
  232,  232,  214,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  232,    0,  214,  232,    0,    0,    0,
    0,    0,  232,  239,    0,    0,    0,    0,  239,  239,
    0,    0,    0,  239,  239,  232,    0,  239,  239,  239,
    0,    0,    0,    0,  239,    0,    0,  239,  214,    0,
  239,  239,    0,    0,    0,    0,    0,    0,    0,  239,
    0,    0,    0,  239,  214,    0,  239,    0,  232,    0,
    0,  214,  239,    0,    0,  396,    0,    0,    0,  396,
  396,  396,    0,    0,  232,  239,  396,  396,  396,  396,
    0,  232,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  396,    0,    0,    0,    0,  239,  239,  239,  239,
  239,    0,    0,    0,    0,    0,    0,    0,  239,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  239,    0,
    0,    0,    0,  239,  239,    0,    0,    0,    0,    0,
    0,  239,    0,    0,  239,  239,    0,    0,  396,  396,
  396,  396,  396,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  396,    0,    0,    0,    0,  396,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  396,  396,
};
static const YYINT yycheck[] = {                          3,
    3,   82,   11,   12,  125,    0,   33,   40,  322,  323,
  190,   78,   33,   10,   10,   10,   33,   10,   33,  228,
   10,   10,   10,   44,   10,   47,   33,   40,   10,   10,
   40,   10,  202,  123,   44,  204,  363,  364,  344,   33,
  220,  123,   33,   33,  165,  366,   33,   56,  276,   33,
  123,  526,   33,  426,  534,   40,   10,   44,   33,   10,
  260,   70,  703,  593,  594,   40,  298,   40,  123,   44,
  123,  440,   81,   60,   61,   62,   60,   61,   62,  123,
  201,  510,  123,   10,  264,   60,  266,   44,   40,   44,
   41,   40,  123,   44,  273,  176,  123,  277,   44,   40,
  299,   10,  223,   24,  125,  383,   40,   44,  267,  309,
  123,  659,   10,   10,   44,  125,  123,  276,  125,  264,
  265,  381,   44,  764,   44,   40,  123,  123,  676,  123,
  610,   60,  123,  342,   55,   33,   33,   40,  125,  123,
   44,  123,  263,  457,  265,   60,  515,   44,  123,   33,
  125,  383,  672,  333,  629,  383,  326,  278,  357,  280,
  329,  228,   33,   60,   61,   62,  346,   10,  125,  475,
  125,  351,   33,   40,  123,  548,   60,   61,   62,  125,
  710,   33,   40,  713,  305,  445,   10,  508,  125,   60,
   61,   62,  621,   60,  714,  125,  317,   44,  705,   60,
   61,   62,   60,  125,   33,  125,   44,  216,   60,   61,
   62,   40,  294,  334,  393,   44,  383,   41,  123,  399,
   44,  125,   33,   44,  710,   40,  123,  407,  125,   40,
  383,   60,   61,   62,  266,  244,  416,   44,  359,   33,
  567,  771,  665,  423,  774,   60,   40,  383,  369,   60,
  277,  257,  123,  433,  314,  277,  123,  284,  264,   10,
  767,  256,  257,  258,  259,   10,   60,  388,  389,   61,
  277,  123,  532,   44,   10,  342,  262,  398,  125,  400,
   40,   10,  268,  277,  544,  771,  466,  125,  711,   10,
  285,  286,  287,  383,  123,  288,  125,  294,  288,  288,
  267,  383,  277,  298,  125,   33,  273,  288,  375,   10,
  383,  299,  123,  434,  435,  310,  496,   10,  125,  314,
  315,  316,  317,  318,   10,  300,  301,   41,  383,  123,
  383,  125,   60,   61,   62,  262,  516,  332,  459,  334,
  267,  268,  383,  384,  465,  299,  341,  383,  384,  276,
  383,  472,  383,  384,  125,  306,  352,  352,  538,  539,
  540,  383,  383,   40,  357,  360,  383,  357,  383,  357,
  383,  357,  269,  383,  495,  555,  357,  328,  123,  693,
  373,  278,  279,  373,  281,  282,  383,  383,  383,  569,
  288,  373,  373,  374,  373,  292,  383,  384,  383,  383,
  384,  298,  299,  357,  713,  302,  303,  304,  383,  384,
  383,  308,  363,  364,  365,  536,   10,  368,  369,  370,
   10,  372,   10,   10,  375,  376,  383,  384,  383,  326,
  357,  383,  383,  554,  383,  556,   10,  335,  336,  337,
  338,  339,  383,  340,   10,  288,   33,  568,  277,  383,
  384,   10,  168,   40,   41,  352,  261,   44,  263,  357,
  357,  582,  529,   10,  362,  774,  277,  534,  383,  384,
   40,  300,  301,   60,  646,  373,  373,  374,  383,  384,
  383,  384,  306,  277,  381,  382,  383,  384,   10,  300,
  301,  500,  335,  336,  337,  338,  339,  618,   44,  383,
  384,   41,  623,   45,  328,   47,  300,  301,  224,  689,
  690,  691,  383,  384,  581,  524,  383,  384,   10,  362,
  601,   41,  383,  384,   44,  383,  384,  375,  376,  650,
  702,  383,  384,   10,  655,   10,  123,  717,  125,  363,
  364,  365,  663,  610,  368,  369,  370,  727,  372,  670,
  617,  375,  376,  733,  383,  384,   33,  737,   41,  383,
   10,   44,  742,   40,   41,  745,   33,   44,  383,  384,
  306,   10,  383,  384,  695,   10,   40,  698,   10,  125,
   44,   44,   10,   60,  335,  336,  337,  338,  339,  383,
  384,  600,  328,   60,   61,   62,   60,  342,  343,  344,
  345,  346,  347,  348,   89,  726,   91,  352,  353,  354,
   10,  362,   10,  734,   10,   44,  697,  738,   41,   44,
   10,   10,  743,  383,  384,  746,   40,  363,  364,  365,
   40,  640,  368,  369,  370,  349,  372,  718,  383,  375,
  376,  355,  356,   33,   10,   44,  123,  383,  125,  335,
  336,  337,  338,  339,   44,  383,  384,  383,  358,  359,
  781,  125,  125,  784,  785,  786,  787,  274,  275,  383,
   60,   61,   62,  383,  262,  262,  362,  383,  687,  267,
  268,  268,  269,  383,  383,  273,  274,  275,  276,   40,
  277,  278,  279,  264,  281,  282,  125,  284,  383,  384,
  125,  288,  289,  290,  333,  292,  383,  384,  789,  366,
  367,  298,  299,  300,  301,  302,  303,  304,  305,   41,
   41,  308,   44,   44,  311,  307,  125,  731,  731,  288,
  404,  405,  259,  123,  265,  125,  259,  324,   10,  326,
  265,  335,  336,  337,  338,  339,   62,  421,  335,  336,
  337,  338,  339,  340,  384,   10,   10,  123,  285,  286,
  287,   33,  285,  286,  287,  352,   10,   10,  362,  357,
  357,  260,   44,  383,  384,  362,  335,  336,  337,  338,
  339,  270,  271,  272,  384,  262,  373,  374,   60,   61,
   62,  268,  269,  380,  381,  382,  383,  384,  357,  384,
  277,  278,  279,  362,  281,  282,   41,  284,   10,   44,
   60,  288,  289,  290,  373,  292,   10,  384,  358,  359,
  309,  298,  299,  300,  301,  302,  303,  304,  305,   41,
  262,  308,   44,  384,  311,  267,  268,   33,   44,   41,
  384,  273,   44,  383,  276,  383,  384,  324,   10,  326,
  384,  123,  384,  125,   40,  117,  118,  119,  335,  336,
  337,  338,  339,  340,   60,   61,   62,  383,  542,  123,
  352,   33,  262,  267,   60,  352,  273,  349,  268,  269,
  357,  125,   44,  355,  356,  362,  384,  268,  278,  279,
   41,  281,  282,  383,  384,  276,  373,  374,  288,  289,
  290,  163,  292,  380,  381,  382,  383,  384,  298,  299,
   10,  383,  302,  303,  304,  305,  383,  384,  308,  383,
  384,  311,  303,  304,   10,  357,  349,  350,  351,  123,
   74,   40,  383,  384,  324,   10,  326,  425,  383,  427,
   84,   85,   86,  383,  384,  335,  336,  337,  338,  339,
  340,   60,   10,  293,   47,  295,  296,  297,   33,  383,
  383,  123,  352,  125,  349,  350,  351,  357,  383,   44,
  383,  384,  362,  285,  286,  287,  342,  343,  344,  345,
  346,  347,  348,  373,  374,  247,  352,  353,  354,  251,
  380,  381,  382,  383,  384,   33,  258,  269,  383,  383,
  384,  256,  257,  258,  383,  384,  278,  279,   40,  281,
  282,  268,   40,  257,  258,  383,  384,  383,   40,  276,
  292,  383,  384,  123,  383,  384,  298,  299,  383,  384,
  302,  303,  304,  177,  383,  384,  308,  123,  383,  384,
  302,  383,  384,  298,  266,  267,  303,  304,  123,   40,
  125,  273,  274,  275,  326,  310,  383,  384,   10,  314,
  315,  316,  317,  318,   40,  123,  383,  384,  340,  384,
  314,  315,  316,  317,   85,   86,  267,  332,  566,  334,
  352,   33,  273,  274,  275,  357,  341,  384,  342,  343,
  344,  345,  346,  347,  348,  300,  301,  352,  352,  353,
  354,  373,  374,  384,  306,  360,   41,  269,  384,  381,
  382,  383,  384,   62,  300,  301,  278,  279,   41,  281,
  282,  311,  312,  313,  383,  383,  328,  374,  383,  383,
  292,  285,  286,  287,  262,   41,  298,  299,  383,  357,
  302,  303,  304,  371,  383,  383,  308,  384,  342,  343,
  344,  345,  346,  347,  348,   41,   41,   41,  352,  353,
  354,  363,  364,  365,  326,  267,  368,  369,  370,  383,
  372,  284,  383,  375,  376,  384,  268,  366,  340,   10,
   61,  383,  335,  336,  337,  338,  339,  383,  384,  383,
  352,  300,  301,   61,  269,  357,   61,  383,  384,   47,
  385,  383,   33,  278,  279,  383,  281,  282,  696,  362,
   41,  373,  374,   44,   47,  373,  268,  292,   41,  381,
  382,  383,  384,  298,  299,  384,  383,  302,  303,  304,
   41,  288,   10,  308,  384,   62,  259,  260,  261,  197,
  198,  199,  342,  343,  344,  345,  346,  347,  348,  384,
  383,  326,  352,  353,  354,   33,  342,  343,  344,  345,
  346,  347,  348,  123,  384,  340,  754,  353,  354,  384,
  758,  383,  373,   33,  383,  384,  384,  352,  283,  283,
   40,  283,  357,  383,  342,  343,  344,  345,  346,  347,
  348,  283,  123,  384,  373,  353,  354,  383,  373,  374,
   60,  384,  384,  384,  284,   10,  381,  382,  383,  384,
  262,   10,  383,  265,  266,  267,  268,  269,   47,  280,
  280,  273,  274,  275,  276,  383,  278,  279,   33,  281,
  282,   40,  385,  383,  385,   41,  288,  289,  290,  297,
  292,  293,  284,  295,  296,  297,  298,  299,  288,  383,
  302,  303,  304,  305,  312,  378,  308,   23,   41,  311,
  383,   41,  320,  123,   41,   10,   10,   10,   41,  284,
  333,   10,  324,  383,  326,  383,   33,   10,   10,  267,
   10,  333,   10,  335,  336,  337,  338,  339,  340,  373,
  384,   57,   58,   59,   10,   10,  595,    3,  718,   71,
  352,  789,   68,  254,  445,  357,  461,  365,  454,  432,
  362,  545,  176,  707,   80,  215,  272,  243,  488,  402,
  410,  373,  374,  610,  493,  171,   10,  340,  380,  381,
  382,  262,  480,  506,  242,  266,  267,  268,  269,  581,
  319,  505,  273,  274,  275,  276,  617,  278,  279,   33,
  281,  282,    3,    3,   -1,   -1,   -1,  288,  289,  290,
   -1,  292,   -1,   -1,   -1,   -1,   -1,  298,  299,   -1,
   -1,  302,  303,  304,  305,   -1,   -1,  308,   -1,   10,
  311,   -1,  125,   -1,  262,   -1,   -1,   -1,   -1,  267,
  268,   -1,   -1,  324,   -1,  326,   -1,   -1,  276,   -1,
   -1,   -1,   33,   -1,  335,  336,  337,  338,  339,  340,
   -1,  289,  290,   -1,   -1,  181,  182,  277,   -1,   -1,
  186,  352,   -1,   -1,  302,   -1,  357,  305,   -1,   -1,
  196,  362,   -1,  311,   -1,   -1,   -1,   -1,   -1,   -1,
  300,  301,  373,  374,   -1,   -1,  324,   -1,   -1,  380,
  381,  382,   10,   -1,   -1,   -1,   -1,  262,   -1,   -1,
   -1,  266,  267,  268,  269,   -1,   -1,   -1,  273,  274,
  275,  276,   -1,  278,  279,   33,  281,  282,   -1,  357,
   -1,   -1,   -1,   -1,  289,  290,   -1,  292,  293,   -1,
  295,  296,  297,  298,  299,  373,   -1,  302,  303,  304,
  305,   -1,  380,  308,   -1,   -1,  311,   -1,   -1,   -1,
   -1,   -1,   -1,  256,  257,  258,   -1,   -1,   -1,  324,
   10,  326,   -1,  383,  384,   -1,   -1,   -1,  333,   -1,
   -1,   -1,  289,  290,   -1,  340,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   33,   -1,  302,   -1,  352,  305,   -1,
   -1,   -1,  357,   -1,  311,  298,  412,  413,  414,   -1,
   -1,   -1,   -1,  419,  420,   -1,   -1,  324,  373,  374,
   -1,  314,  315,  316,  317,  380,  381,  382,  262,   -1,
   -1,   -1,  266,  267,  268,  269,   -1,   -1,   -1,  273,
  274,  275,  276,   10,  278,  279,   -1,  281,  282,   -1,
  357,   -1,   -1,   -1,   -1,  289,  290,   -1,  292,  293,
   -1,  295,  296,  297,  298,  299,   33,   -1,  302,  303,
  304,  305,   -1,  380,  308,   -1,  482,  311,  484,   -1,
  486,  262,   -1,  489,   -1,   -1,   -1,  268,   -1,   -1,
  324,   -1,  326,   10,   -1,   -1,   -1,   -1,   -1,  333,
   -1,   -1,   -1,   -1,   -1,   -1,  340,   -1,  289,  290,
   -1,   -1,   -1,   -1,   -1,   -1,   33,   -1,  352,   -1,
   -1,  302,   -1,  357,  305,   -1,   -1,   -1,   -1,   -1,
  311,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  373,
  374,   -1,   -1,  324,   -1,   -1,  380,  381,  382,   10,
   -1,   -1,   -1,  261,  262,  263,  264,  265,  266,  267,
  268,  269,   -1,   -1,   -1,  273,  274,  275,  276,   -1,
  278,  279,   33,  281,  282,   -1,  357,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  292,  293,   -1,  295,  296,  297,
  298,  299,  373,   -1,  302,  303,  304,   -1,   -1,  380,
  308,  342,  343,  344,  345,  346,  347,  348,   -1,  615,
   -1,  352,  353,  354,   -1,   -1,   -1,   10,  326,   -1,
   -1,  261,  262,  263,  264,  265,  266,  267,  268,  269,
   -1,   -1,  340,  273,  274,  275,  276,   -1,  278,  279,
   33,  281,  282,   -1,  352,   -1,   -1,   -1,   -1,  357,
   -1,   -1,  292,  293,   -1,  295,  296,  297,  298,  299,
   -1,   -1,  302,  303,  304,  373,  374,   -1,  308,   -1,
   -1,   -1,   -1,  381,  382,   -1,   -1,  319,  320,  321,
  322,  323,   -1,  325,   -1,  327,  326,  329,  330,  331,
   -1,   -1,   -1,   -1,   -1,  262,   -1,   -1,   -1,   -1,
  340,  268,   -1,   -1,   10,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  352,   -1,  720,  721,  722,  357,   -1,  361,
   -1,  288,   -1,   -1,   -1,   -1,   -1,   33,   -1,   -1,
   -1,   -1,   -1,  373,  374,  377,  378,   -1,   -1,   -1,
   -1,  381,  382,   -1,  261,  262,  263,  264,  265,  266,
  267,  268,  269,   -1,   -1,   -1,  273,  274,  275,  276,
   -1,  278,  279,   -1,  281,  282,   -1,   -1,  335,  336,
  337,  338,  339,   -1,   -1,  292,  293,   -1,  295,  296,
  297,  298,  299,   -1,   -1,  302,  303,  304,   -1,   -1,
  357,  308,   -1,   -1,   -1,  362,   -1,   -1,   -1,   -1,
   -1,   10,   -1,   -1,   -1,   -1,  373,  374,   -1,  326,
  342,  343,  344,  345,  346,  347,  348,  123,   -1,   -1,
  352,  353,  354,  340,   33,   -1,   -1,   -1,  289,  290,
   -1,   -1,   -1,   -1,   -1,  352,   -1,   -1,   -1,   -1,
  357,  302,   -1,   -1,  305,   -1,   -1,   -1,   -1,   -1,
  311,   -1,   -1,   -1,   -1,   -1,  373,  374,   -1,   -1,
   -1,   -1,   -1,  324,  381,  382,   -1,   -1,  261,  262,
  263,  264,  265,  266,  267,  268,  269,   -1,   -1,   -1,
  273,  274,  275,  276,   -1,  278,  279,   -1,  281,  282,
   -1,  306,   -1,   -1,   -1,   -1,  357,   10,   -1,  292,
  293,   -1,  295,  296,  297,  298,  299,   -1,   -1,  302,
  303,  304,  373,  328,  123,  308,   -1,   -1,   -1,  380,
   33,   -1,   10,  342,  343,  344,  345,  346,  347,  348,
   -1,   -1,   -1,  326,  353,  354,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   33,   -1,  340,  363,  364,
  365,   -1,   -1,  368,  369,  370,  262,  372,   -1,  352,
  375,  376,  268,  269,  357,   -1,   -1,   -1,  383,   -1,
   -1,   -1,  278,  279,   -1,  281,  282,   10,   -1,   -1,
  373,  374,  288,  289,  290,   -1,  292,   -1,  381,  382,
   -1,   -1,  298,  299,   -1,   -1,  302,  303,  304,  305,
   33,   -1,  308,   -1,   -1,  311,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  324,   10,
  326,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  335,
  336,  337,  338,  339,  340,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   33,   -1,   -1,   -1,  352,   -1,   -1,   -1,
   -1,  357,   -1,   -1,   -1,   -1,  362,   -1,   -1,  268,
  269,   -1,   -1,   -1,   -1,   -1,   -1,  373,  374,  278,
  279,   -1,  281,  282,  380,  381,  382,   -1,   -1,  288,
  289,  290,   -1,  292,   -1,   10,   -1,   -1,   -1,  298,
  299,   -1,   -1,  302,  303,  304,  305,   -1,   -1,  308,
   -1,   -1,  311,   -1,   -1,   -1,   -1,   -1,   33,   -1,
   -1,   -1,   -1,   -1,   -1,  324,   -1,  326,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  335,  336,  337,  338,
  339,  340,  123,   -1,   -1,   10,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  352,   -1,   -1,   -1,   -1,  357,  262,
   -1,   -1,   -1,  362,  267,  268,   -1,   -1,   33,   -1,
  273,  274,  275,  276,  373,  374,   -1,   -1,   -1,   -1,
   -1,  380,  381,  382,  262,  288,  264,  265,  266,  267,
  268,  269,   -1,   -1,   -1,  273,  274,  275,  276,   -1,
  278,  279,   -1,  281,  282,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  292,  293,   -1,  295,  296,  297,
  298,  299,   -1,   -1,  302,  303,  304,   -1,   -1,   -1,
  308,   -1,  335,  336,  337,  338,  339,   -1,   -1,  262,
   -1,   -1,   -1,  266,  267,  268,   -1,   -1,  326,   -1,
  273,  274,  275,  276,  357,   10,   -1,   -1,   -1,  362,
   -1,   -1,  340,   -1,   -1,  288,   -1,   -1,   -1,   -1,
  373,  374,   -1,   -1,  352,   -1,   -1,   -1,   33,  357,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  269,   -1,
   -1,   -1,   -1,   -1,   -1,  373,  374,  278,  279,   -1,
  281,  282,   -1,  381,  382,   -1,   -1,  288,  289,  290,
   -1,  292,  335,  336,  337,  338,  339,  298,  299,   -1,
   -1,  302,  303,  304,  305,   -1,   -1,  308,   -1,   -1,
  311,   -1,   -1,   -1,  357,   -1,   -1,   -1,   -1,  362,
   -1,   -1,   -1,  324,   -1,  326,   -1,  262,   -1,   -1,
  373,  374,  267,  268,  335,  336,  337,  338,  339,  340,
   -1,  276,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  352,   -1,  288,   -1,   -1,  357,   -1,   -1,   -1,
   -1,  362,   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  373,  374,   -1,   -1,   -1,  262,   -1,  380,
  381,  382,  267,  268,  269,   33,   -1,   -1,  273,  274,
  275,  276,   -1,  278,  279,   -1,  281,  282,   -1,  306,
  335,  336,  337,  338,  339,   -1,   -1,  292,   -1,   -1,
   -1,   -1,   -1,  298,  299,   -1,   -1,  302,  303,  304,
   -1,  328,  357,  308,   -1,   10,   -1,  362,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  373,  374,
   -1,  326,   -1,   -1,   -1,   -1,   -1,   -1,   33,   -1,
  335,  336,  337,  338,  339,  340,  363,  364,  365,   -1,
   -1,  368,  369,  370,   -1,  372,   -1,  352,  375,  376,
   -1,   -1,  357,   -1,   -1,  123,  383,  362,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  373,  374,
   -1,   -1,  267,  268,  269,   -1,  381,  382,  273,  274,
  275,  276,   -1,  278,  279,   -1,  281,  282,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  292,   -1,   -1,
   -1,   -1,   -1,  298,  299,   -1,   -1,  302,  303,  304,
   -1,   -1,   -1,  308,   -1,   10,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  326,   -1,   -1,   -1,   -1,   -1,   -1,   33,   -1,
  335,  336,  337,  338,  339,  340,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  352,   -1,   10,
   -1,   -1,  357,   -1,   -1,   -1,   -1,  362,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  373,  374,
   -1,   -1,   33,   -1,   -1,   -1,  381,  382,   -1,   -1,
   -1,   -1,   -1,  261,  262,  263,   -1,  265,  266,  267,
  268,  269,   -1,   -1,   -1,  273,  274,  275,  276,   -1,
  278,  279,   -1,  281,  282,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  292,   10,   -1,   -1,   -1,   -1,
  298,  299,   -1,   -1,  302,  303,  304,   -1,   -1,   -1,
  308,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   33,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  326,   -1,
   -1,  266,  267,  268,  269,   -1,   -1,   -1,  273,  274,
  275,  276,  340,  278,  279,   -1,  281,  282,   -1,   -1,
   -1,   -1,   -1,   -1,  352,   -1,   -1,  292,  293,  357,
  295,  296,  297,  298,  299,   -1,   -1,  302,  303,  304,
   -1,   -1,   -1,  308,   -1,  373,  374,   -1,   -1,   -1,
   -1,   -1,   -1,  381,  382,   -1,   -1,   -1,   -1,   -1,
   -1,  326,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  340,   -1,   -1,  123,   -1,
   -1,   -1,   10,   -1,   -1,   -1,   -1,  352,   -1,   -1,
   -1,   -1,  357,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   33,   -1,  262,  373,  374,
   -1,   -1,  267,  268,  269,   -1,  381,  382,  273,  274,
  275,  276,   -1,  278,  279,   -1,  281,  282,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,   -1,
  295,  296,  297,  298,  299,   -1,   -1,  302,  303,  304,
   -1,  262,   -1,  308,   -1,  266,  267,  268,   -1,   -1,
   -1,   -1,  273,  274,  275,  276,   -1,   -1,   -1,   10,
   -1,  326,   -1,   -1,   -1,   -1,   -1,   -1,  289,  290,
   -1,   -1,   -1,   -1,   -1,  340,   -1,   -1,   -1,   -1,
   -1,  302,   33,   -1,  305,  123,   -1,  352,   -1,   -1,
  311,   -1,  357,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   10,  324,   -1,   -1,   -1,  262,  373,  374,
  265,  266,  267,  268,  269,   -1,  381,  382,  273,  274,
  275,  276,   -1,  278,  279,   33,  281,  282,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  357,  292,   -1,   -1,
   -1,   -1,   -1,  298,  299,   10,   -1,  302,  303,  304,
   -1,   -1,  373,  308,   -1,   -1,   -1,   -1,   -1,  380,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   33,   -1,
   -1,  326,  123,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  340,   -1,   -1,   10,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  352,   -1,   -1,
   -1,   -1,  357,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   33,   -1,   -1,   -1,   -1,   -1,   -1,  373,  374,
   -1,   -1,   -1,   -1,  262,   -1,  381,  382,  266,  267,
  268,  269,   -1,   -1,   -1,  273,  274,  275,  276,   -1,
  278,  279,   -1,  281,  282,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  292,   -1,   -1,   -1,   -1,   -1,
  298,  299,   -1,   -1,  302,  303,  304,   -1,   -1,   -1,
  308,   -1,   -1,   -1,   10,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  326,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   33,   -1,   -1,
   -1,  123,  340,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  262,   -1,   -1,  352,   -1,  267,  268,  269,  357,
   -1,   -1,  273,  274,  275,  276,   -1,  278,  279,   -1,
  281,  282,   -1,   -1,   -1,  373,  374,   33,   -1,   -1,
   -1,  292,   -1,  381,  382,   -1,   -1,  298,  299,   -1,
   -1,  302,  303,  304,  262,   -1,   -1,  308,   -1,  267,
  268,  269,   -1,   -1,   -1,  273,  274,  275,  276,   -1,
  278,  279,   -1,  281,  282,  326,   -1,   -1,   -1,   -1,
   -1,   -1,   10,   -1,  292,   -1,   -1,   -1,   -1,  340,
  298,  299,   -1,   -1,  302,  303,  304,  262,   -1,   -1,
  308,  352,  267,  268,  269,   33,  357,   -1,  273,  274,
  275,  276,   -1,  278,  279,   -1,  281,  282,  326,   -1,
   -1,   -1,  373,  374,   -1,   10,   -1,  292,   -1,   -1,
  381,  382,  340,  298,  299,   -1,   -1,  302,  303,  304,
  262,   -1,   -1,  308,  352,  267,  268,  269,   33,  357,
   -1,  273,   -1,   -1,  276,   -1,  278,  279,   -1,  281,
  282,  326,   -1,   -1,   -1,  373,  374,   -1,   10,   -1,
  292,   -1,   -1,  381,  382,  340,  298,  299,   -1,   -1,
  302,  303,  304,   -1,   -1,   -1,  308,  352,   -1,   -1,
   -1,   33,  357,   -1,   -1,  123,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  326,   -1,   -1,   -1,  373,  374,
   -1,   10,   -1,   -1,   -1,   -1,  381,  382,  340,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,   -1,   -1,   -1,
  352,  267,  268,  269,   33,  357,   -1,  273,   -1,   -1,
  276,   -1,  278,  279,   -1,  281,  282,   -1,   -1,   -1,
   -1,  373,  374,   -1,   10,   -1,  292,   -1,   -1,  381,
  382,   -1,  298,  299,   -1,   -1,  302,  303,  304,   -1,
   -1,   -1,  308,  269,   -1,   -1,   -1,   33,   -1,   -1,
   -1,  123,  278,  279,   -1,  281,  282,   -1,   -1,   -1,
  326,   -1,   -1,   -1,   -1,   -1,  292,   10,   -1,   -1,
   -1,   -1,  298,  299,  340,   -1,  302,  303,  304,   -1,
   -1,   -1,  308,   -1,   -1,   -1,  352,   -1,   -1,   -1,
   33,  357,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  326,   -1,   -1,   -1,  262,   -1,   -1,  373,  374,  267,
  268,  269,   -1,   -1,  340,  381,  382,   -1,  276,   -1,
  278,  279,   -1,  281,  282,   -1,  352,   -1,   -1,   -1,
   -1,  357,   -1,   -1,  292,   10,   -1,  123,   -1,   -1,
  298,  299,   -1,   -1,  302,  303,  304,  262,  374,   -1,
  308,   -1,  267,  268,  269,  381,  382,   -1,   33,   -1,
   -1,  276,   -1,  278,  279,   -1,  281,  282,  326,   -1,
   -1,   -1,   -1,   -1,   -1,   10,   -1,  292,   -1,   -1,
  123,   -1,  340,  298,  299,   -1,   -1,  302,  303,  304,
  262,   -1,   -1,  308,  352,   -1,  268,  269,   33,  357,
   -1,   -1,   -1,   -1,   -1,   -1,  278,  279,   -1,  281,
  282,  326,   -1,   -1,   -1,  373,  374,   -1,   -1,   -1,
  292,   -1,   -1,  381,  382,  340,  298,  299,   -1,   -1,
  302,  303,  304,  262,   -1,   -1,  308,  352,   -1,  268,
  269,   -1,  357,   -1,   -1,   -1,   -1,   -1,  123,  278,
  279,   -1,  281,  282,  326,   -1,   -1,   -1,  373,  374,
   -1,   -1,   -1,  292,   -1,   -1,  381,  382,  340,  298,
  299,   10,   -1,  302,  303,  304,   -1,   -1,   -1,  308,
  352,   -1,   -1,  269,   -1,  357,   -1,   -1,   -1,   -1,
   -1,   10,  278,  279,   33,  281,  282,  326,   -1,   -1,
   -1,  373,  374,   -1,   -1,   -1,  292,   -1,   -1,  381,
  382,  340,  298,  299,   33,   -1,  302,  303,  304,   -1,
   -1,   -1,  308,  352,   -1,   -1,  269,   -1,  357,   -1,
   -1,   -1,   -1,   -1,   -1,  278,  279,   -1,  281,  282,
  326,   10,   -1,   -1,  373,  374,   -1,   -1,   -1,  292,
   -1,   10,  381,  382,  340,  298,  299,   -1,   -1,  302,
  303,  304,   -1,   -1,   33,  308,  352,   -1,   -1,   -1,
   -1,  357,   -1,   -1,   33,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  326,   -1,   -1,   -1,  373,  374,   -1,
   -1,   -1,   -1,   10,  269,  381,  382,  340,   -1,   -1,
   -1,   -1,   -1,  278,  279,   -1,  281,  282,   -1,  352,
   -1,   -1,   -1,   -1,  357,   -1,   33,  292,   -1,   -1,
   -1,   -1,   -1,  298,  299,   -1,   -1,  302,  303,  304,
  373,  374,   -1,  308,  269,   -1,   -1,   -1,  381,  382,
   -1,   -1,   -1,  278,  279,   -1,  281,  282,   -1,   -1,
   -1,  326,   -1,   -1,   -1,   -1,   -1,  292,   -1,   -1,
   -1,   -1,   -1,  298,  299,  340,   -1,  302,  303,  304,
   -1,   -1,   -1,  308,   -1,   -1,   -1,  352,   -1,   -1,
   -1,   -1,  357,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  326,   -1,   -1,   -1,   -1,   -1,   -1,  373,  374,
   -1,   -1,   -1,   -1,   -1,  340,  381,  382,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  352,   -1,   -1,
   -1,   -1,  357,  262,   -1,  264,  265,  266,  267,  268,
   -1,   -1,   -1,   -1,  273,  274,  275,  276,  373,  374,
   -1,   -1,   -1,  262,   -1,   -1,  381,  382,  267,  268,
  289,  290,   -1,   -1,  273,  274,  275,  276,   -1,   -1,
   -1,   -1,   -1,  302,   -1,   -1,  305,   -1,   -1,   -1,
  289,  290,  311,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  302,   -1,  324,  305,   -1,   -1,   -1,
   -1,   -1,  311,  262,   -1,   -1,   -1,   -1,  267,  268,
   -1,   -1,   -1,  262,  273,  324,   -1,  276,  267,  268,
   -1,   -1,   -1,   -1,  273,   -1,   -1,  276,  357,   -1,
  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  288,
   -1,   -1,   -1,  302,  373,   -1,  305,   -1,  357,   -1,
   -1,  380,  311,   -1,   -1,  262,   -1,   -1,   -1,  266,
  267,  268,   -1,   -1,  373,  324,  273,  274,  275,  276,
   -1,  380,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  288,   -1,   -1,   -1,   -1,  335,  336,  337,  338,
  339,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  357,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  357,   -1,
   -1,   -1,   -1,  362,  373,   -1,   -1,   -1,   -1,   -1,
   -1,  380,   -1,   -1,  373,  374,   -1,   -1,  335,  336,
  337,  338,  339,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  357,   -1,   -1,   -1,   -1,  362,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  373,  374,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 385
#define YYUNDFTOKEN 552
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'!'",0,0,0,0,0,0,"'('","')'",0,0,"','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
0,"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"PASS","BLOCK","SCRUB","RETURN","IN","OS","OUT","LOG","QUICK",
"ON","FROM","TO","FLAGS","RETURNRST","RETURNICMP","RETURNICMP6","PROTO","INET",
"INET6","ALL","ANY","ICMPTYPE","ICMP6TYPE","CODE","KEEP","MODULATE","STATE",
"PORT","RDR","NAT","BINAT","ARROW","NODF","MINTTL","ERROR","ALLOWOPTS",
"FASTROUTE","FILENAME","ROUTETO","DUPTO","REPLYTO","NO","LABEL","NOROUTE",
"URPFFAILED","FRAGMENT","USER","GROUP","MAXMSS","MAXIMUM","TTL","TOS","DROP",
"TABLE","REASSEMBLE","FRAGDROP","FRAGCROP","ANCHOR","NATANCHOR","RDRANCHOR",
"BINATANCHOR","SET","OPTIMIZATION","TIMEOUT","LIMIT","LOGINTERFACE",
"BLOCKPOLICY","RANDOMID","REQUIREORDER","SYNPROXY","FINGERPRINTS","NOSYNC",
"DEBUG","SKIP","HOSTID","ANTISPOOF","FOR","INCLUDE","BITMASK","RANDOM",
"SOURCEHASH","ROUNDROBIN","STATICPORT","PROBABILITY","ALTQ","CBQ","CODEL",
"PRIQ","HFSC","FAIRQ","BANDWIDTH","TBRSIZE","LINKSHARE","REALTIME","UPPERLIMIT",
"QUEUE","PRIORITY","QLIMIT","HOGS","BUCKETS","RTABLE","TARGET","INTERVAL",
"LOAD","RULESET_OPTIMIZATION","STICKYADDRESS","MAXSRCSTATES","MAXSRCNODES",
"SOURCETRACK","GLOBAL","RULE","MAXSRCCONN","MAXSRCCONNRATE","OVERLOAD","FLUSH",
"SLOPPY","TAGGED","TAG","IFBOUND","FLOATING","STATEPOLICY","STATEDEFAULTS",
"ROUTE","SETTOS","DIVERTTO","DIVERTREPLY","STRING","NUMBER","PORTBINARY",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : ruleset",
"ruleset :",
"ruleset : ruleset include '\\n'",
"ruleset : ruleset '\\n'",
"ruleset : ruleset option '\\n'",
"ruleset : ruleset scrubrule '\\n'",
"ruleset : ruleset natrule '\\n'",
"ruleset : ruleset binatrule '\\n'",
"ruleset : ruleset pfrule '\\n'",
"ruleset : ruleset anchorrule '\\n'",
"ruleset : ruleset loadrule '\\n'",
"ruleset : ruleset altqif '\\n'",
"ruleset : ruleset queuespec '\\n'",
"ruleset : ruleset varset '\\n'",
"ruleset : ruleset antispoof '\\n'",
"ruleset : ruleset tabledef '\\n'",
"ruleset : '{' fakeanchor '}' '\\n'",
"ruleset : ruleset error '\\n'",
"include : INCLUDE STRING",
"fakeanchor : fakeanchor '\\n'",
"fakeanchor : fakeanchor anchorrule '\\n'",
"fakeanchor : fakeanchor binatrule '\\n'",
"fakeanchor : fakeanchor natrule '\\n'",
"fakeanchor : fakeanchor pfrule '\\n'",
"fakeanchor : fakeanchor error '\\n'",
"optimizer : string",
"option : SET OPTIMIZATION STRING",
"option : SET RULESET_OPTIMIZATION optimizer",
"option : SET TIMEOUT timeout_spec",
"option : SET TIMEOUT '{' optnl timeout_list '}'",
"option : SET LIMIT limit_spec",
"option : SET LIMIT '{' optnl limit_list '}'",
"option : SET LOGINTERFACE stringall",
"option : SET HOSTID number",
"option : SET BLOCKPOLICY DROP",
"option : SET BLOCKPOLICY RETURN",
"option : SET REQUIREORDER yesno",
"option : SET FINGERPRINTS STRING",
"option : SET STATEPOLICY statelock",
"option : SET DEBUG STRING",
"option : SET SKIP interface",
"option : SET STATEDEFAULTS state_opt_list",
"stringall : STRING",
"stringall : ALL",
"string : STRING string",
"string : STRING",
"varstring : numberstring varstring",
"varstring : numberstring",
"numberstring : NUMBER",
"numberstring : STRING",
"varset : STRING '=' varstring",
"anchorname : STRING",
"anchorname :",
"pfa_anchorlist :",
"pfa_anchorlist : pfa_anchorlist '\\n'",
"pfa_anchorlist : pfa_anchorlist pfrule '\\n'",
"pfa_anchorlist : pfa_anchorlist anchorrule '\\n'",
"$$1 :",
"pfa_anchor : '{' $$1 '\\n' pfa_anchorlist '}'",
"pfa_anchor :",
"anchorrule : ANCHOR anchorname dir quick interface af proto fromto filter_opts pfa_anchor",
"anchorrule : NATANCHOR string interface af proto fromto rtable",
"anchorrule : RDRANCHOR string interface af proto fromto rtable",
"anchorrule : BINATANCHOR string interface af proto fromto rtable",
"loadrule : LOAD ANCHOR string FROM string",
"scrubaction : no SCRUB",
"scrubrule : scrubaction dir logquick interface af proto fromto scrub_opts",
"$$2 :",
"scrub_opts : $$2 scrub_opts_l",
"scrub_opts :",
"scrub_opts_l : scrub_opts_l scrub_opt",
"scrub_opts_l : scrub_opt",
"scrub_opt : NODF",
"scrub_opt : MINTTL NUMBER",
"scrub_opt : MAXMSS NUMBER",
"scrub_opt : SETTOS tos",
"scrub_opt : fragcache",
"scrub_opt : REASSEMBLE STRING",
"scrub_opt : RANDOMID",
"scrub_opt : RTABLE NUMBER",
"scrub_opt : not TAGGED string",
"fragcache : FRAGMENT REASSEMBLE",
"fragcache : FRAGMENT FRAGCROP",
"fragcache : FRAGMENT FRAGDROP",
"antispoof : ANTISPOOF logquick antispoof_ifspc af antispoof_opts",
"antispoof_ifspc : FOR antispoof_if",
"antispoof_ifspc : FOR '{' optnl antispoof_iflst '}'",
"antispoof_iflst : antispoof_if optnl",
"antispoof_iflst : antispoof_iflst comma antispoof_if optnl",
"antispoof_if : if_item",
"antispoof_if : '(' if_item ')'",
"$$3 :",
"antispoof_opts : $$3 antispoof_opts_l",
"antispoof_opts :",
"antispoof_opts_l : antispoof_opts_l antispoof_opt",
"antispoof_opts_l : antispoof_opt",
"antispoof_opt : label",
"antispoof_opt : RTABLE NUMBER",
"not : '!'",
"not :",
"tabledef : TABLE '<' STRING '>' table_opts",
"$$4 :",
"table_opts : $$4 table_opts_l",
"table_opts :",
"table_opts_l : table_opts_l table_opt",
"table_opts_l : table_opt",
"table_opt : STRING",
"table_opt : '{' optnl '}'",
"table_opt : '{' optnl host_list '}'",
"table_opt : FILENAME STRING",
"altqif : ALTQ interface queue_opts QUEUE qassign",
"queuespec : QUEUE STRING interface queue_opts qassign",
"$$5 :",
"queue_opts : $$5 queue_opts_l",
"queue_opts :",
"queue_opts_l : queue_opts_l queue_opt",
"queue_opts_l : queue_opt",
"queue_opt : BANDWIDTH bandwidth",
"queue_opt : PRIORITY NUMBER",
"queue_opt : QLIMIT NUMBER",
"queue_opt : scheduler",
"queue_opt : TBRSIZE NUMBER",
"bandwidth : STRING",
"bandwidth : NUMBER",
"scheduler : CBQ",
"scheduler : CBQ '(' cbqflags_list ')'",
"scheduler : PRIQ",
"scheduler : PRIQ '(' priqflags_list ')'",
"scheduler : HFSC",
"scheduler : HFSC '(' hfsc_opts ')'",
"scheduler : FAIRQ",
"scheduler : FAIRQ '(' fairq_opts ')'",
"scheduler : CODEL",
"scheduler : CODEL '(' codel_opts ')'",
"cbqflags_list : cbqflags_item",
"cbqflags_list : cbqflags_list comma cbqflags_item",
"cbqflags_item : STRING",
"priqflags_list : priqflags_item",
"priqflags_list : priqflags_list comma priqflags_item",
"priqflags_item : STRING",
"$$6 :",
"hfsc_opts : $$6 hfscopts_list",
"hfscopts_list : hfscopts_item",
"hfscopts_list : hfscopts_list comma hfscopts_item",
"hfscopts_item : LINKSHARE bandwidth",
"hfscopts_item : LINKSHARE '(' bandwidth comma NUMBER comma bandwidth ')'",
"hfscopts_item : REALTIME bandwidth",
"hfscopts_item : REALTIME '(' bandwidth comma NUMBER comma bandwidth ')'",
"hfscopts_item : UPPERLIMIT bandwidth",
"hfscopts_item : UPPERLIMIT '(' bandwidth comma NUMBER comma bandwidth ')'",
"hfscopts_item : STRING",
"$$7 :",
"fairq_opts : $$7 fairqopts_list",
"fairqopts_list : fairqopts_item",
"fairqopts_list : fairqopts_list comma fairqopts_item",
"fairqopts_item : LINKSHARE bandwidth",
"fairqopts_item : LINKSHARE '(' bandwidth number bandwidth ')'",
"fairqopts_item : HOGS bandwidth",
"fairqopts_item : BUCKETS number",
"fairqopts_item : STRING",
"$$8 :",
"codel_opts : $$8 codelopts_list",
"codelopts_list : codelopts_item",
"codelopts_list : codelopts_list comma codelopts_item",
"codelopts_item : INTERVAL number",
"codelopts_item : TARGET number",
"codelopts_item : STRING",
"qassign :",
"qassign : qassign_item",
"qassign : '{' optnl qassign_list '}'",
"qassign_list : qassign_item optnl",
"qassign_list : qassign_list comma qassign_item optnl",
"qassign_item : STRING",
"pfrule : action dir logquick interface route af proto fromto filter_opts",
"$$9 :",
"filter_opts : $$9 filter_opts_l",
"filter_opts :",
"filter_opts_l : filter_opts_l filter_opt",
"filter_opts_l : filter_opt",
"filter_opt : USER uids",
"filter_opt : GROUP gids",
"filter_opt : flags",
"filter_opt : icmpspec",
"filter_opt : TOS tos",
"filter_opt : keep",
"filter_opt : FRAGMENT",
"filter_opt : ALLOWOPTS",
"filter_opt : label",
"filter_opt : qname",
"filter_opt : TAG string",
"filter_opt : not TAGGED string",
"filter_opt : PROBABILITY probability",
"filter_opt : RTABLE NUMBER",
"filter_opt : DIVERTTO portplain",
"filter_opt : DIVERTTO STRING PORT portplain",
"filter_opt : DIVERTREPLY",
"probability : STRING",
"probability : NUMBER",
"action : PASS",
"action : BLOCK blockspec",
"blockspec :",
"blockspec : DROP",
"blockspec : RETURNRST",
"blockspec : RETURNRST '(' TTL NUMBER ')'",
"blockspec : RETURNICMP",
"blockspec : RETURNICMP6",
"blockspec : RETURNICMP '(' reticmpspec ')'",
"blockspec : RETURNICMP6 '(' reticmp6spec ')'",
"blockspec : RETURNICMP '(' reticmpspec comma reticmp6spec ')'",
"blockspec : RETURN",
"reticmpspec : STRING",
"reticmpspec : NUMBER",
"reticmp6spec : STRING",
"reticmp6spec : NUMBER",
"dir :",
"dir : IN",
"dir : OUT",
"quick :",
"quick : QUICK",
"logquick :",
"logquick : log",
"logquick : QUICK",
"logquick : log QUICK",
"logquick : QUICK log",
"log : LOG",
"log : LOG '(' logopts ')'",
"logopts : logopt",
"logopts : logopts comma logopt",
"logopt : ALL",
"logopt : USER",
"logopt : GROUP",
"logopt : TO string",
"interface :",
"interface : ON if_item_not",
"interface : ON '{' optnl if_list '}'",
"if_list : if_item_not optnl",
"if_list : if_list comma if_item_not optnl",
"if_item_not : not if_item",
"if_item : STRING",
"af :",
"af : INET",
"af : INET6",
"proto :",
"proto : PROTO proto_item",
"proto : PROTO '{' optnl proto_list '}'",
"proto_list : proto_item optnl",
"proto_list : proto_list comma proto_item optnl",
"proto_item : protoval",
"protoval : STRING",
"protoval : NUMBER",
"fromto : ALL",
"fromto : from os to",
"os :",
"os : OS xos",
"os : OS '{' optnl os_list '}'",
"xos : STRING",
"os_list : xos optnl",
"os_list : os_list comma xos optnl",
"from :",
"from : FROM ipportspec",
"to :",
"to : TO ipportspec",
"ipportspec : ipspec",
"ipportspec : ipspec PORT portspec",
"ipportspec : PORT portspec",
"optnl : '\\n' optnl",
"optnl :",
"ipspec : ANY",
"ipspec : xhost",
"ipspec : '{' optnl host_list '}'",
"toipspec : TO ipspec",
"toipspec :",
"host_list : ipspec optnl",
"host_list : host_list comma ipspec optnl",
"xhost : not host",
"xhost : not NOROUTE",
"xhost : not URPFFAILED",
"host : STRING",
"host : STRING '-' STRING",
"host : STRING '/' NUMBER",
"host : NUMBER '/' NUMBER",
"host : dynaddr",
"host : dynaddr '/' NUMBER",
"host : '<' STRING '>'",
"number : NUMBER",
"number : STRING",
"dynaddr : '(' STRING ')'",
"portspec : port_item",
"portspec : '{' optnl port_list '}'",
"port_list : port_item optnl",
"port_list : port_list comma port_item optnl",
"port_item : portrange",
"port_item : unaryop portrange",
"port_item : portrange PORTBINARY portrange",
"portplain : numberstring",
"portrange : numberstring",
"uids : uid_item",
"uids : '{' optnl uid_list '}'",
"uid_list : uid_item optnl",
"uid_list : uid_list comma uid_item optnl",
"uid_item : uid",
"uid_item : unaryop uid",
"uid_item : uid PORTBINARY uid",
"uid : STRING",
"uid : NUMBER",
"gids : gid_item",
"gids : '{' optnl gid_list '}'",
"gid_list : gid_item optnl",
"gid_list : gid_list comma gid_item optnl",
"gid_item : gid",
"gid_item : unaryop gid",
"gid_item : gid PORTBINARY gid",
"gid : STRING",
"gid : NUMBER",
"flag : STRING",
"flags : FLAGS flag '/' flag",
"flags : FLAGS '/' flag",
"flags : FLAGS ANY",
"icmpspec : ICMPTYPE icmp_item",
"icmpspec : ICMPTYPE '{' optnl icmp_list '}'",
"icmpspec : ICMP6TYPE icmp6_item",
"icmpspec : ICMP6TYPE '{' optnl icmp6_list '}'",
"icmp_list : icmp_item optnl",
"icmp_list : icmp_list comma icmp_item optnl",
"icmp6_list : icmp6_item optnl",
"icmp6_list : icmp6_list comma icmp6_item optnl",
"icmp_item : icmptype",
"icmp_item : icmptype CODE STRING",
"icmp_item : icmptype CODE NUMBER",
"icmp6_item : icmp6type",
"icmp6_item : icmp6type CODE STRING",
"icmp6_item : icmp6type CODE NUMBER",
"icmptype : STRING",
"icmptype : NUMBER",
"icmp6type : STRING",
"icmp6type : NUMBER",
"tos : STRING",
"tos : NUMBER",
"sourcetrack : SOURCETRACK",
"sourcetrack : SOURCETRACK GLOBAL",
"sourcetrack : SOURCETRACK RULE",
"statelock : IFBOUND",
"statelock : FLOATING",
"keep : NO STATE",
"keep : KEEP STATE state_opt_spec",
"keep : MODULATE STATE state_opt_spec",
"keep : SYNPROXY STATE state_opt_spec",
"flush :",
"flush : FLUSH",
"flush : FLUSH GLOBAL",
"state_opt_spec : '(' state_opt_list ')'",
"state_opt_spec :",
"state_opt_list : state_opt_item",
"state_opt_list : state_opt_list comma state_opt_item",
"state_opt_item : MAXIMUM NUMBER",
"state_opt_item : NOSYNC",
"state_opt_item : MAXSRCSTATES NUMBER",
"state_opt_item : MAXSRCCONN NUMBER",
"state_opt_item : MAXSRCCONNRATE NUMBER '/' NUMBER",
"state_opt_item : OVERLOAD '<' STRING '>' flush",
"state_opt_item : MAXSRCNODES NUMBER",
"state_opt_item : sourcetrack",
"state_opt_item : statelock",
"state_opt_item : SLOPPY",
"state_opt_item : STRING NUMBER",
"label : LABEL STRING",
"qname : QUEUE STRING",
"qname : QUEUE '(' STRING ')'",
"qname : QUEUE '(' STRING comma STRING ')'",
"no :",
"no : NO",
"portstar : numberstring",
"redirspec : host",
"redirspec : '{' optnl redir_host_list '}'",
"redir_host_list : host optnl",
"redir_host_list : redir_host_list comma host optnl",
"redirpool :",
"redirpool : ARROW redirspec",
"redirpool : ARROW redirspec PORT portstar",
"hashkey :",
"hashkey : string",
"$$10 :",
"pool_opts : $$10 pool_opts_l",
"pool_opts :",
"pool_opts_l : pool_opts_l pool_opt",
"pool_opts_l : pool_opt",
"pool_opt : BITMASK",
"pool_opt : RANDOM",
"pool_opt : SOURCEHASH hashkey",
"pool_opt : ROUNDROBIN",
"pool_opt : STATICPORT",
"pool_opt : STICKYADDRESS",
"redirection :",
"redirection : ARROW host",
"redirection : ARROW host PORT portstar",
"natpasslog :",
"natpasslog : PASS",
"natpasslog : PASS log",
"natpasslog : log",
"nataction : no NAT natpasslog",
"nataction : no RDR natpasslog",
"natrule : nataction interface af proto fromto tag tagged rtable redirpool pool_opts",
"binatrule : no BINAT natpasslog interface af proto FROM host toipspec tag tagged rtable redirection",
"tag :",
"tag : TAG STRING",
"tagged :",
"tagged : not TAGGED string",
"rtable :",
"rtable : RTABLE NUMBER",
"route_host : STRING",
"route_host : '(' STRING host ')'",
"route_host_list : route_host optnl",
"route_host_list : route_host_list comma route_host optnl",
"routespec : route_host",
"routespec : '{' optnl route_host_list '}'",
"route :",
"route : FASTROUTE",
"route : ROUTETO routespec pool_opts",
"route : REPLYTO routespec pool_opts",
"route : DUPTO routespec pool_opts",
"timeout_spec : STRING NUMBER",
"timeout_list : timeout_list comma timeout_spec optnl",
"timeout_list : timeout_spec optnl",
"limit_spec : STRING NUMBER",
"limit_list : limit_list comma limit_spec optnl",
"limit_list : limit_spec optnl",
"comma : ','",
"comma :",
"yesno : NO",
"yesno : STRING",
"unaryop : '='",
"unaryop : '!' '='",
"unaryop : '<' '='",
"unaryop : '<'",
"unaryop : '>' '='",
"unaryop : '>'",

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
#line 4434 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"

int
yyerror(const char *fmt, ...)
{
	va_list		 ap;

	file->errors++;
	va_start(ap, fmt);
	fprintf(stderr, "%s:%d: ", file->name, yylval.lineno);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
	return (0);
}

int
disallow_table(struct node_host *h, const char *fmt)
{
	for (; h != NULL; h = h->next)
		if (h->addr.type == PF_ADDR_TABLE) {
			yyerror(fmt, h->addr.v.tblname);
			return (1);
		}
	return (0);
}

int
disallow_urpf_failed(struct node_host *h, const char *fmt)
{
	for (; h != NULL; h = h->next)
		if (h->addr.type == PF_ADDR_URPFFAILED) {
			yyerror(fmt);
			return (1);
		}
	return (0);
}

int
disallow_alias(struct node_host *h, const char *fmt)
{
	for (; h != NULL; h = h->next)
		if (DYNIF_MULTIADDR(h->addr)) {
			yyerror(fmt, h->addr.v.tblname);
			return (1);
		}
	return (0);
}

int
rule_consistent(struct pf_rule *r, int anchor_call)
{
	int	problems = 0;

	switch (r->action) {
	case PF_PASS:
	case PF_DROP:
	case PF_SCRUB:
	case PF_NOSCRUB:
		problems = filter_consistent(r, anchor_call);
		break;
	case PF_NAT:
	case PF_NONAT:
		problems = nat_consistent(r);
		break;
	case PF_RDR:
	case PF_NORDR:
		problems = rdr_consistent(r);
		break;
	case PF_BINAT:
	case PF_NOBINAT:
	default:
		break;
	}
	return (problems);
}

int
filter_consistent(struct pf_rule *r, int anchor_call)
{
	int	problems = 0;

	if (r->proto != IPPROTO_TCP && r->proto != IPPROTO_UDP &&
	    (r->src.port_op || r->dst.port_op)) {
		yyerror("port only applies to tcp/udp");
		problems++;
	}
	if (r->proto != IPPROTO_ICMP && r->proto != IPPROTO_ICMPV6 &&
	    (r->type || r->code)) {
		yyerror("icmp-type/code only applies to icmp");
		problems++;
	}
	if (!r->af && (r->type || r->code)) {
		yyerror("must indicate address family with icmp-type/code");
		problems++;
	}
	if (r->overload_tblname[0] &&
	    r->max_src_conn == 0 && r->max_src_conn_rate.seconds == 0) {
		yyerror("'overload' requires 'max-src-conn' "
		    "or 'max-src-conn-rate'");
		problems++;
	}
	if ((r->proto == IPPROTO_ICMP && r->af == AF_INET6) ||
	    (r->proto == IPPROTO_ICMPV6 && r->af == AF_INET)) {
		yyerror("proto %s doesn't match address family %s",
		    r->proto == IPPROTO_ICMP ? "icmp" : "icmp6",
		    r->af == AF_INET ? "inet" : "inet6");
		problems++;
	}
	if (r->allow_opts && r->action != PF_PASS) {
		yyerror("allow-opts can only be specified for pass rules");
		problems++;
	}
	if (r->rule_flag & PFRULE_FRAGMENT && (r->src.port_op ||
	    r->dst.port_op || r->flagset || r->type || r->code)) {
		yyerror("fragments can be filtered only on IP header fields");
		problems++;
	}
	if (r->rule_flag & PFRULE_RETURNRST && r->proto != IPPROTO_TCP) {
		yyerror("return-rst can only be applied to TCP rules");
		problems++;
	}
	if (r->max_src_nodes && !(r->rule_flag & PFRULE_RULESRCTRACK)) {
		yyerror("max-src-nodes requires 'source-track rule'");
		problems++;
	}
	if (r->action == PF_DROP && r->keep_state) {
		yyerror("keep state on block rules doesn't make sense");
		problems++;
	}
	if (r->rule_flag & PFRULE_STATESLOPPY &&
	    (r->keep_state == PF_STATE_MODULATE ||
	    r->keep_state == PF_STATE_SYNPROXY)) {
		yyerror("sloppy state matching cannot be used with "
		    "synproxy state or modulate state");
		problems++;
	}
	return (-problems);
}

int
nat_consistent(struct pf_rule *r)
{
	return (0);	/* yeah! */
}

int
rdr_consistent(struct pf_rule *r)
{
	int			 problems = 0;

	if (r->proto != IPPROTO_TCP && r->proto != IPPROTO_UDP) {
		if (r->src.port_op) {
			yyerror("src port only applies to tcp/udp");
			problems++;
		}
		if (r->dst.port_op) {
			yyerror("dst port only applies to tcp/udp");
			problems++;
		}
		if (r->rpool.proxy_port[0]) {
			yyerror("rpool port only applies to tcp/udp");
			problems++;
		}
	}
	if (r->dst.port_op &&
	    r->dst.port_op != PF_OP_EQ && r->dst.port_op != PF_OP_RRG) {
		yyerror("invalid port operator for rdr destination port");
		problems++;
	}
	return (-problems);
}

int
process_tabledef(char *name, struct table_opts *opts)
{
	struct pfr_buffer	 ab;
	struct node_tinit	*ti;

	bzero(&ab, sizeof(ab));
	ab.pfrb_type = PFRB_ADDRS;
	SIMPLEQ_FOREACH(ti, &opts->init_nodes, entries) {
		if (ti->file)
			if (pfr_buf_load(&ab, ti->file, 0, append_addr)) {
				if (errno)
					yyerror("cannot load \"%s\": %s",
					    ti->file, strerror(errno));
				else
					yyerror("file \"%s\" contains bad data",
					    ti->file);
				goto _error;
			}
		if (ti->host)
			if (append_addr_host(&ab, ti->host, 0, 0)) {
				yyerror("cannot create address buffer: %s",
				    strerror(errno));
				goto _error;
			}
	}
	if (pf->opts & PF_OPT_VERBOSE)
		print_tabledef(name, opts->flags, opts->init_addr,
		    &opts->init_nodes);
	if (!(pf->opts & PF_OPT_NOACTION) &&
	    pfctl_define_table(name, opts->flags, opts->init_addr,
	    pf->anchor->name, &ab, pf->anchor->ruleset.tticket)) {
		yyerror("cannot define table %s: %s", name,
		    pfr_strerror(errno));
		goto _error;
	}
	pf->tdirty = 1;
	pfr_buf_clear(&ab);
	return (0);
_error:
	pfr_buf_clear(&ab);
	return (-1);
}

struct keywords {
	const char	*k_name;
	int		 k_val;
};

/* macro gore, but you should've seen the prior indentation nightmare... */

#define FREE_LIST(T,r) \
	do { \
		T *p, *node = r; \
		while (node != NULL) { \
			p = node; \
			node = node->next; \
			free(p); \
		} \
	} while (0)

#define LOOP_THROUGH(T,n,r,C) \
	do { \
		T *n; \
		if (r == NULL) { \
			r = calloc(1, sizeof(T)); \
			if (r == NULL) \
				err(1, "LOOP: calloc"); \
			r->next = NULL; \
		} \
		n = r; \
		while (n != NULL) { \
			do { \
				C; \
			} while (0); \
			n = n->next; \
		} \
	} while (0)

void
expand_label_str(char *label, size_t len, const char *srch, const char *repl)
{
	char *tmp;
	char *p, *q;

	if ((tmp = calloc(1, len)) == NULL)
		err(1, "expand_label_str: calloc");
	p = q = label;
	while ((q = strstr(p, srch)) != NULL) {
		*q = '\0';
		if ((strlcat(tmp, p, len) >= len) ||
		    (strlcat(tmp, repl, len) >= len))
			errx(1, "expand_label: label too long");
		q += strlen(srch);
		p = q;
	}
	if (strlcat(tmp, p, len) >= len)
		errx(1, "expand_label: label too long");
	strlcpy(label, tmp, len);	/* always fits */
	free(tmp);
}

void
expand_label_if(const char *name, char *label, size_t len, const char *ifname)
{
	if (strstr(label, name) != NULL) {
		if (!*ifname)
			expand_label_str(label, len, name, "any");
		else
			expand_label_str(label, len, name, ifname);
	}
}

void
expand_label_addr(const char *name, char *label, size_t len, sa_family_t af,
    struct node_host *h)
{
	char tmp[64], tmp_not[66];

	if (strstr(label, name) != NULL) {
		switch (h->addr.type) {
		case PF_ADDR_DYNIFTL:
			snprintf(tmp, sizeof(tmp), "(%s)", h->addr.v.ifname);
			break;
		case PF_ADDR_TABLE:
			snprintf(tmp, sizeof(tmp), "<%s>", h->addr.v.tblname);
			break;
		case PF_ADDR_NOROUTE:
			snprintf(tmp, sizeof(tmp), "no-route");
			break;
		case PF_ADDR_URPFFAILED:
			snprintf(tmp, sizeof(tmp), "urpf-failed");
			break;
		case PF_ADDR_ADDRMASK:
			if (!af || (PF_AZERO(&h->addr.v.a.addr, af) &&
			    PF_AZERO(&h->addr.v.a.mask, af)))
				snprintf(tmp, sizeof(tmp), "any");
			else {
				char	a[48];
				int	bits;

				if (inet_ntop(af, &h->addr.v.a.addr, a,
				    sizeof(a)) == NULL)
					snprintf(tmp, sizeof(tmp), "?");
				else {
					bits = unmask(&h->addr.v.a.mask, af);
					if ((af == AF_INET && bits < 32) ||
					    (af == AF_INET6 && bits < 128))
						snprintf(tmp, sizeof(tmp),
						    "%s/%d", a, bits);
					else
						snprintf(tmp, sizeof(tmp),
						    "%s", a);
				}
			}
			break;
		default:
			snprintf(tmp, sizeof(tmp), "?");
			break;
		}

		if (h->not) {
			snprintf(tmp_not, sizeof(tmp_not), "! %s", tmp);
			expand_label_str(label, len, name, tmp_not);
		} else
			expand_label_str(label, len, name, tmp);
	}
}

void
expand_label_port(const char *name, char *label, size_t len,
    struct node_port *port)
{
	char	 a1[6], a2[6], op[13] = "";

	if (strstr(label, name) != NULL) {
		snprintf(a1, sizeof(a1), "%u", ntohs(port->port[0]));
		snprintf(a2, sizeof(a2), "%u", ntohs(port->port[1]));
		if (!port->op)
			;
		else if (port->op == PF_OP_IRG)
			snprintf(op, sizeof(op), "%s><%s", a1, a2);
		else if (port->op == PF_OP_XRG)
			snprintf(op, sizeof(op), "%s<>%s", a1, a2);
		else if (port->op == PF_OP_EQ)
			snprintf(op, sizeof(op), "%s", a1);
		else if (port->op == PF_OP_NE)
			snprintf(op, sizeof(op), "!=%s", a1);
		else if (port->op == PF_OP_LT)
			snprintf(op, sizeof(op), "<%s", a1);
		else if (port->op == PF_OP_LE)
			snprintf(op, sizeof(op), "<=%s", a1);
		else if (port->op == PF_OP_GT)
			snprintf(op, sizeof(op), ">%s", a1);
		else if (port->op == PF_OP_GE)
			snprintf(op, sizeof(op), ">=%s", a1);
		expand_label_str(label, len, name, op);
	}
}

void
expand_label_proto(const char *name, char *label, size_t len, u_int8_t proto)
{
	struct protoent *pe;
	char n[4];

	if (strstr(label, name) != NULL) {
		pe = getprotobynumber(proto);
		if (pe != NULL)
			expand_label_str(label, len, name, pe->p_name);
		else {
			snprintf(n, sizeof(n), "%u", proto);
			expand_label_str(label, len, name, n);
		}
	}
}

void
expand_label_nr(const char *name, char *label, size_t len)
{
	char n[11];

	if (strstr(label, name) != NULL) {
		snprintf(n, sizeof(n), "%u", pf->anchor->match);
		expand_label_str(label, len, name, n);
	}
}

void
expand_label(char *label, size_t len, const char *ifname, sa_family_t af,
    struct node_host *src_host, struct node_port *src_port,
    struct node_host *dst_host, struct node_port *dst_port,
    u_int8_t proto)
{
	expand_label_if("$if", label, len, ifname);
	expand_label_addr("$srcaddr", label, len, af, src_host);
	expand_label_addr("$dstaddr", label, len, af, dst_host);
	expand_label_port("$srcport", label, len, src_port);
	expand_label_port("$dstport", label, len, dst_port);
	expand_label_proto("$proto", label, len, proto);
	expand_label_nr("$nr", label, len);
}

int
expand_altq(struct pf_altq *a, struct node_if *interfaces,
    struct node_queue *nqueues, struct node_queue_bw bwspec,
    struct node_queue_opt *opts)
{
	struct pf_altq		 pa, pb;
	char			 qname[PF_QNAME_SIZE];
	struct node_queue	*n;
	struct node_queue_bw	 bw;
	int			 errs = 0;

	if ((pf->loadopt & PFCTL_FLAG_ALTQ) == 0) {
		FREE_LIST(struct node_if, interfaces);
		if (nqueues)
			FREE_LIST(struct node_queue, nqueues);
		return (0);
	}

	LOOP_THROUGH(struct node_if, interface, interfaces,
		memcpy(&pa, a, sizeof(struct pf_altq));
		if (strlcpy(pa.ifname, interface->ifname,
		    sizeof(pa.ifname)) >= sizeof(pa.ifname))
			errx(1, "expand_altq: strlcpy");

		if (interface->not) {
			yyerror("altq on ! <interface> is not supported");
			errs++;
		} else {
			if (eval_pfaltq(pf, &pa, &bwspec, opts))
				errs++;
			else
				if (pfctl_add_altq(pf, &pa))
					errs++;

			if (pf->opts & PF_OPT_VERBOSE) {
				print_altq(&pf->paltq->altq, 0,
				    &bwspec, opts);
				if (nqueues && nqueues->tail) {
					printf("queue { ");
					LOOP_THROUGH(struct node_queue, queue,
					    nqueues,
						printf("%s ",
						    queue->queue);
					);
					printf("}");
				}
				printf("\n");
			}

			if (pa.scheduler == ALTQT_CBQ ||
			    pa.scheduler == ALTQT_HFSC) {
				/* now create a root queue */
				memset(&pb, 0, sizeof(struct pf_altq));
				if (strlcpy(qname, "root_", sizeof(qname)) >=
				    sizeof(qname))
					errx(1, "expand_altq: strlcpy");
				if (strlcat(qname, interface->ifname,
				    sizeof(qname)) >= sizeof(qname))
					errx(1, "expand_altq: strlcat");
				if (strlcpy(pb.qname, qname,
				    sizeof(pb.qname)) >= sizeof(pb.qname))
					errx(1, "expand_altq: strlcpy");
				if (strlcpy(pb.ifname, interface->ifname,
				    sizeof(pb.ifname)) >= sizeof(pb.ifname))
					errx(1, "expand_altq: strlcpy");
				pb.qlimit = pa.qlimit;
				pb.scheduler = pa.scheduler;
				bw.bw_absolute = pa.ifbandwidth;
				bw.bw_percent = 0;
				if (eval_pfqueue(pf, &pb, &bw, opts))
					errs++;
				else
					if (pfctl_add_altq(pf, &pb))
						errs++;
			}

			LOOP_THROUGH(struct node_queue, queue, nqueues,
				n = calloc(1, sizeof(struct node_queue));
				if (n == NULL)
					err(1, "expand_altq: calloc");
				if (pa.scheduler == ALTQT_CBQ ||
				    pa.scheduler == ALTQT_HFSC)
					if (strlcpy(n->parent, qname,
					    sizeof(n->parent)) >=
					    sizeof(n->parent))
						errx(1, "expand_altq: strlcpy");
				if (strlcpy(n->queue, queue->queue,
				    sizeof(n->queue)) >= sizeof(n->queue))
					errx(1, "expand_altq: strlcpy");
				if (strlcpy(n->ifname, interface->ifname,
				    sizeof(n->ifname)) >= sizeof(n->ifname))
					errx(1, "expand_altq: strlcpy");
				n->scheduler = pa.scheduler;
				n->next = NULL;
				n->tail = n;
				if (queues == NULL)
					queues = n;
				else {
					queues->tail->next = n;
					queues->tail = n;
				}
			);
		}
	);
	FREE_LIST(struct node_if, interfaces);
	if (nqueues)
		FREE_LIST(struct node_queue, nqueues);

	return (errs);
}

int
expand_queue(struct pf_altq *a, struct node_if *interfaces,
    struct node_queue *nqueues, struct node_queue_bw bwspec,
    struct node_queue_opt *opts)
{
	struct node_queue	*n, *nq;
	struct pf_altq		 pa;
	u_int8_t		 found = 0;
	u_int8_t		 errs = 0;

	if ((pf->loadopt & PFCTL_FLAG_ALTQ) == 0) {
		FREE_LIST(struct node_queue, nqueues);
		return (0);
	}

	if (queues == NULL) {
		yyerror("queue %s has no parent", a->qname);
		FREE_LIST(struct node_queue, nqueues);
		return (1);
	}

	LOOP_THROUGH(struct node_if, interface, interfaces,
		LOOP_THROUGH(struct node_queue, tqueue, queues,
			if (!strncmp(a->qname, tqueue->queue, PF_QNAME_SIZE) &&
			    (interface->ifname[0] == 0 ||
			    (!interface->not && !strncmp(interface->ifname,
			    tqueue->ifname, IFNAMSIZ)) ||
			    (interface->not && strncmp(interface->ifname,
			    tqueue->ifname, IFNAMSIZ)))) {
				/* found ourself in queues */
				found++;

				memcpy(&pa, a, sizeof(struct pf_altq));

				if (pa.scheduler != ALTQT_NONE &&
				    pa.scheduler != tqueue->scheduler) {
					yyerror("exactly one scheduler type "
					    "per interface allowed");
					return (1);
				}
				pa.scheduler = tqueue->scheduler;

				/* scheduler dependent error checking */
				switch (pa.scheduler) {
				case ALTQT_PRIQ:
					if (nqueues != NULL) {
						yyerror("priq queues cannot "
						    "have child queues");
						return (1);
					}
					if (bwspec.bw_absolute > 0 ||
					    bwspec.bw_percent < 100) {
						yyerror("priq doesn't take "
						    "bandwidth");
						return (1);
					}
					break;
				default:
					break;
				}

				if (strlcpy(pa.ifname, tqueue->ifname,
				    sizeof(pa.ifname)) >= sizeof(pa.ifname))
					errx(1, "expand_queue: strlcpy");
				if (strlcpy(pa.parent, tqueue->parent,
				    sizeof(pa.parent)) >= sizeof(pa.parent))
					errx(1, "expand_queue: strlcpy");

				if (eval_pfqueue(pf, &pa, &bwspec, opts))
					errs++;
				else
					if (pfctl_add_altq(pf, &pa))
						errs++;

				for (nq = nqueues; nq != NULL; nq = nq->next) {
					if (!strcmp(a->qname, nq->queue)) {
						yyerror("queue cannot have "
						    "itself as child");
						errs++;
						continue;
					}
					n = calloc(1,
					    sizeof(struct node_queue));
					if (n == NULL)
						err(1, "expand_queue: calloc");
					if (strlcpy(n->parent, a->qname,
					    sizeof(n->parent)) >=
					    sizeof(n->parent))
						errx(1, "expand_queue strlcpy");
					if (strlcpy(n->queue, nq->queue,
					    sizeof(n->queue)) >=
					    sizeof(n->queue))
						errx(1, "expand_queue strlcpy");
					if (strlcpy(n->ifname, tqueue->ifname,
					    sizeof(n->ifname)) >=
					    sizeof(n->ifname))
						errx(1, "expand_queue strlcpy");
					n->scheduler = tqueue->scheduler;
					n->next = NULL;
					n->tail = n;
					if (queues == NULL)
						queues = n;
					else {
						queues->tail->next = n;
						queues->tail = n;
					}
				}
				if ((pf->opts & PF_OPT_VERBOSE) && (
				    (found == 1 && interface->ifname[0] == 0) ||
				    (found > 0 && interface->ifname[0] != 0))) {
					print_queue(&pf->paltq->altq, 0,
					    &bwspec, interface->ifname[0] != 0,
					    opts);
					if (nqueues && nqueues->tail) {
						printf("{ ");
						LOOP_THROUGH(struct node_queue,
						    queue, nqueues,
							printf("%s ",
							    queue->queue);
						);
						printf("}");
					}
					printf("\n");
				}
			}
		);
	);

	FREE_LIST(struct node_queue, nqueues);
	FREE_LIST(struct node_if, interfaces);

	if (!found) {
		yyerror("queue %s has no parent", a->qname);
		errs++;
	}

	if (errs)
		return (1);
	else
		return (0);
}

void
expand_rule(struct pf_rule *r,
    struct node_if *interfaces, struct node_host *rpool_hosts,
    struct node_proto *protos, struct node_os *src_oses,
    struct node_host *src_hosts, struct node_port *src_ports,
    struct node_host *dst_hosts, struct node_port *dst_ports,
    struct node_uid *uids, struct node_gid *gids, struct node_icmp *icmp_types,
    const char *anchor_call)
{
	sa_family_t		 af = r->af;
	int			 added = 0, error = 0;
	char			 ifname[IF_NAMESIZE];
	char			 label[PF_RULE_LABEL_SIZE];
	char			 tagname[PF_TAG_NAME_SIZE];
	char			 match_tagname[PF_TAG_NAME_SIZE];
	struct pf_pooladdr	*pa;
	struct node_host	*h;
	u_int8_t		 flags, flagset, keep_state;

	if (strlcpy(label, r->label, sizeof(label)) >= sizeof(label))
		errx(1, "expand_rule: strlcpy");
	if (strlcpy(tagname, r->tagname, sizeof(tagname)) >= sizeof(tagname))
		errx(1, "expand_rule: strlcpy");
	if (strlcpy(match_tagname, r->match_tagname, sizeof(match_tagname)) >=
	    sizeof(match_tagname))
		errx(1, "expand_rule: strlcpy");
	flags = r->flags;
	flagset = r->flagset;
	keep_state = r->keep_state;

	LOOP_THROUGH(struct node_if, interface, interfaces,
	LOOP_THROUGH(struct node_proto, proto, protos,
	LOOP_THROUGH(struct node_icmp, icmp_type, icmp_types,
	LOOP_THROUGH(struct node_host, src_host, src_hosts,
	LOOP_THROUGH(struct node_port, src_port, src_ports,
	LOOP_THROUGH(struct node_os, src_os, src_oses,
	LOOP_THROUGH(struct node_host, dst_host, dst_hosts,
	LOOP_THROUGH(struct node_port, dst_port, dst_ports,
	LOOP_THROUGH(struct node_uid, uid, uids,
	LOOP_THROUGH(struct node_gid, gid, gids,

		r->af = af;
		/* for link-local IPv6 address, interface must match up */
		if ((r->af && src_host->af && r->af != src_host->af) ||
		    (r->af && dst_host->af && r->af != dst_host->af) ||
		    (src_host->af && dst_host->af &&
		    src_host->af != dst_host->af) ||
		    (src_host->ifindex && dst_host->ifindex &&
		    src_host->ifindex != dst_host->ifindex) ||
		    (src_host->ifindex && *interface->ifname &&
		    src_host->ifindex != if_nametoindex(interface->ifname)) ||
		    (dst_host->ifindex && *interface->ifname &&
		    dst_host->ifindex != if_nametoindex(interface->ifname)))
			continue;
		if (!r->af && src_host->af)
			r->af = src_host->af;
		else if (!r->af && dst_host->af)
			r->af = dst_host->af;

		if (*interface->ifname)
			strlcpy(r->ifname, interface->ifname,
			    sizeof(r->ifname));
		else if (if_indextoname(src_host->ifindex, ifname))
			strlcpy(r->ifname, ifname, sizeof(r->ifname));
		else if (if_indextoname(dst_host->ifindex, ifname))
			strlcpy(r->ifname, ifname, sizeof(r->ifname));
		else
			memset(r->ifname, '\0', sizeof(r->ifname));

		if (strlcpy(r->label, label, sizeof(r->label)) >=
		    sizeof(r->label))
			errx(1, "expand_rule: strlcpy");
		if (strlcpy(r->tagname, tagname, sizeof(r->tagname)) >=
		    sizeof(r->tagname))
			errx(1, "expand_rule: strlcpy");
		if (strlcpy(r->match_tagname, match_tagname,
		    sizeof(r->match_tagname)) >= sizeof(r->match_tagname))
			errx(1, "expand_rule: strlcpy");
		expand_label(r->label, PF_RULE_LABEL_SIZE, r->ifname, r->af,
		    src_host, src_port, dst_host, dst_port, proto->proto);
		expand_label(r->tagname, PF_TAG_NAME_SIZE, r->ifname, r->af,
		    src_host, src_port, dst_host, dst_port, proto->proto);
		expand_label(r->match_tagname, PF_TAG_NAME_SIZE, r->ifname,
		    r->af, src_host, src_port, dst_host, dst_port,
		    proto->proto);

		error += check_netmask(src_host, r->af);
		error += check_netmask(dst_host, r->af);

		r->ifnot = interface->not;
		r->proto = proto->proto;
		r->src.addr = src_host->addr;
		r->src.neg = src_host->not;
		r->src.port[0] = src_port->port[0];
		r->src.port[1] = src_port->port[1];
		r->src.port_op = src_port->op;
		r->dst.addr = dst_host->addr;
		r->dst.neg = dst_host->not;
		r->dst.port[0] = dst_port->port[0];
		r->dst.port[1] = dst_port->port[1];
		r->dst.port_op = dst_port->op;
		r->uid.op = uid->op;
		r->uid.uid[0] = uid->uid[0];
		r->uid.uid[1] = uid->uid[1];
		r->gid.op = gid->op;
		r->gid.gid[0] = gid->gid[0];
		r->gid.gid[1] = gid->gid[1];
		r->type = icmp_type->type;
		r->code = icmp_type->code;

		if ((keep_state == PF_STATE_MODULATE ||
		    keep_state == PF_STATE_SYNPROXY) &&
		    r->proto && r->proto != IPPROTO_TCP)
			r->keep_state = PF_STATE_NORMAL;
		else
			r->keep_state = keep_state;

		if (r->proto && r->proto != IPPROTO_TCP) {
			r->flags = 0;
			r->flagset = 0;
		} else {
			r->flags = flags;
			r->flagset = flagset;
		}
		if (icmp_type->proto && r->proto != icmp_type->proto) {
			yyerror("icmp-type mismatch");
			error++;
		}

		if (src_os && src_os->os) {
			r->os_fingerprint = pfctl_get_fingerprint(src_os->os);
			if ((pf->opts & PF_OPT_VERBOSE2) &&
			    r->os_fingerprint == PF_OSFP_NOMATCH)
				fprintf(stderr,
				    "warning: unknown '%s' OS fingerprint\n",
				    src_os->os);
		} else {
			r->os_fingerprint = PF_OSFP_ANY;
		}

		TAILQ_INIT(&r->rpool.list);
		for (h = rpool_hosts; h != NULL; h = h->next) {
			pa = calloc(1, sizeof(struct pf_pooladdr));
			if (pa == NULL)
				err(1, "expand_rule: calloc");
			pa->addr = h->addr;
			if (h->ifname != NULL) {
				if (strlcpy(pa->ifname, h->ifname,
				    sizeof(pa->ifname)) >=
				    sizeof(pa->ifname))
					errx(1, "expand_rule: strlcpy");
			} else
				pa->ifname[0] = 0;
			TAILQ_INSERT_TAIL(&r->rpool.list, pa, entries);
		}

		if (rule_consistent(r, anchor_call[0]) < 0 || error)
			yyerror("skipping rule due to errors");
		else {
			r->nr = pf->astack[pf->asd]->match++;
			pfctl_add_rule(pf, r, anchor_call);
			added++;
		}

	))))))))));

	FREE_LIST(struct node_if, interfaces);
	FREE_LIST(struct node_proto, protos);
	FREE_LIST(struct node_host, src_hosts);
	FREE_LIST(struct node_port, src_ports);
	FREE_LIST(struct node_os, src_oses);
	FREE_LIST(struct node_host, dst_hosts);
	FREE_LIST(struct node_port, dst_ports);
	FREE_LIST(struct node_uid, uids);
	FREE_LIST(struct node_gid, gids);
	FREE_LIST(struct node_icmp, icmp_types);
	FREE_LIST(struct node_host, rpool_hosts);

	if (!added)
		yyerror("rule expands to no valid combination");
}

int
expand_skip_interface(struct node_if *interfaces)
{
	int	errs = 0;

	if (!interfaces || (!interfaces->next && !interfaces->not &&
	    !strcmp(interfaces->ifname, "none"))) {
		if (pf->opts & PF_OPT_VERBOSE)
			printf("set skip on none\n");
		errs = pfctl_set_interface_flags(pf, "", PFI_IFLAG_SKIP, 0);
		return (errs);
	}

	if (pf->opts & PF_OPT_VERBOSE)
		printf("set skip on {");
	LOOP_THROUGH(struct node_if, interface, interfaces,
		if (pf->opts & PF_OPT_VERBOSE)
			printf(" %s", interface->ifname);
		if (interface->not) {
			yyerror("skip on ! <interface> is not supported");
			errs++;
		} else
			errs += pfctl_set_interface_flags(pf,
			    interface->ifname, PFI_IFLAG_SKIP, 1);
	);
	if (pf->opts & PF_OPT_VERBOSE)
		printf(" }\n");

	FREE_LIST(struct node_if, interfaces);

	if (errs)
		return (1);
	else
		return (0);
}

#undef FREE_LIST
#undef LOOP_THROUGH

int
check_rulestate(int desired_state)
{
	if (require_order && (rulestate > desired_state)) {
		yyerror("Rules must be in order: options, normalization, "
		    "queueing, translation, filtering");
		return (1);
	}
	rulestate = desired_state;
	return (0);
}

int
kw_cmp(const void *k, const void *e)
{
	return (strcmp(k, ((const struct keywords *)e)->k_name));
}

int
lookup(char *s)
{
	/* this has to be sorted always */
	static const struct keywords keywords[] = {
		{ "all",		ALL},
		{ "allow-opts",		ALLOWOPTS},
		{ "altq",		ALTQ},
		{ "anchor",		ANCHOR},
		{ "antispoof",		ANTISPOOF},
		{ "any",		ANY},
		{ "bandwidth",		BANDWIDTH},
		{ "binat",		BINAT},
		{ "binat-anchor",	BINATANCHOR},
		{ "bitmask",		BITMASK},
		{ "block",		BLOCK},
		{ "block-policy",	BLOCKPOLICY},
		{ "buckets",		BUCKETS},
		{ "cbq",		CBQ},
		{ "code",		CODE},
		{ "codelq",		CODEL},
		{ "crop",		FRAGCROP},
		{ "debug",		DEBUG},
		{ "divert-reply",	DIVERTREPLY},
		{ "divert-to",		DIVERTTO},
		{ "drop",		DROP},
		{ "drop-ovl",		FRAGDROP},
		{ "dup-to",		DUPTO},
		{ "fairq",		FAIRQ},
		{ "fastroute",		FASTROUTE},
		{ "file",		FILENAME},
		{ "fingerprints",	FINGERPRINTS},
		{ "flags",		FLAGS},
		{ "floating",		FLOATING},
		{ "flush",		FLUSH},
		{ "for",		FOR},
		{ "fragment",		FRAGMENT},
		{ "from",		FROM},
		{ "global",		GLOBAL},
		{ "group",		GROUP},
		{ "hfsc",		HFSC},
		{ "hogs",		HOGS},
		{ "hostid",		HOSTID},
		{ "icmp-type",		ICMPTYPE},
		{ "icmp6-type",		ICMP6TYPE},
		{ "if-bound",		IFBOUND},
		{ "in",			IN},
		{ "include",		INCLUDE},
		{ "inet",		INET},
		{ "inet6",		INET6},
		{ "interval",		INTERVAL},
		{ "keep",		KEEP},
		{ "label",		LABEL},
		{ "limit",		LIMIT},
		{ "linkshare",		LINKSHARE},
		{ "load",		LOAD},
		{ "log",		LOG},
		{ "loginterface",	LOGINTERFACE},
		{ "max",		MAXIMUM},
		{ "max-mss",		MAXMSS},
		{ "max-src-conn",	MAXSRCCONN},
		{ "max-src-conn-rate",	MAXSRCCONNRATE},
		{ "max-src-nodes",	MAXSRCNODES},
		{ "max-src-states",	MAXSRCSTATES},
		{ "min-ttl",		MINTTL},
		{ "modulate",		MODULATE},
		{ "nat",		NAT},
		{ "nat-anchor",		NATANCHOR},
		{ "no",			NO},
		{ "no-df",		NODF},
		{ "no-route",		NOROUTE},
		{ "no-sync",		NOSYNC},
		{ "on",			ON},
		{ "optimization",	OPTIMIZATION},
		{ "os",			OS},
		{ "out",		OUT},
		{ "overload",		OVERLOAD},
		{ "pass",		PASS},
		{ "port",		PORT},
		{ "priority",		PRIORITY},
		{ "priq",		PRIQ},
		{ "probability",	PROBABILITY},
		{ "proto",		PROTO},
		{ "qlimit",		QLIMIT},
		{ "queue",		QUEUE},
		{ "quick",		QUICK},
		{ "random",		RANDOM},
		{ "random-id",		RANDOMID},
		{ "rdr",		RDR},
		{ "rdr-anchor",		RDRANCHOR},
		{ "realtime",		REALTIME},
		{ "reassemble",		REASSEMBLE},
		{ "reply-to",		REPLYTO},
		{ "require-order",	REQUIREORDER},
		{ "return",		RETURN},
		{ "return-icmp",	RETURNICMP},
		{ "return-icmp6",	RETURNICMP6},
		{ "return-rst",		RETURNRST},
		{ "round-robin",	ROUNDROBIN},
		{ "route",		ROUTE},
		{ "route-to",		ROUTETO},
		{ "rtable",		RTABLE},
		{ "rule",		RULE},
		{ "ruleset-optimization",	RULESET_OPTIMIZATION},
		{ "scrub",		SCRUB},
		{ "set",		SET},
		{ "set-tos",		SETTOS},
		{ "skip",		SKIP},
		{ "sloppy",		SLOPPY},
		{ "source-hash",	SOURCEHASH},
		{ "source-track",	SOURCETRACK},
		{ "state",		STATE},
		{ "state-defaults",	STATEDEFAULTS},
		{ "state-policy",	STATEPOLICY},
		{ "static-port",	STATICPORT},
		{ "sticky-address",	STICKYADDRESS},
		{ "synproxy",		SYNPROXY},
		{ "table",		TABLE},
		{ "tag",		TAG},
		{ "tagged",		TAGGED},
		{ "target",		TARGET},
		{ "tbrsize",		TBRSIZE},
		{ "timeout",		TIMEOUT},
		{ "to",			TO},
		{ "tos",		TOS},
		{ "ttl",		TTL},
		{ "upperlimit",		UPPERLIMIT},
		{ "urpf-failed",	URPFFAILED},
		{ "user",		USER},
	};
	const struct keywords	*p;

	p = bsearch(s, keywords, sizeof(keywords)/sizeof(keywords[0]),
	    sizeof(keywords[0]), kw_cmp);

	if (p) {
		if (debug > 1)
			fprintf(stderr, "%s: %d\n", s, p->k_val);
		return (p->k_val);
	} else {
		if (debug > 1)
			fprintf(stderr, "string: %s\n", s);
		return (STRING);
	}
}

#define MAXPUSHBACK	128

char	*parsebuf;
int	 parseindex;
char	 pushback_buffer[MAXPUSHBACK];
int	 pushback_index = 0;

int
lgetc(int quotec)
{
	int		c, next;

	if (parsebuf) {
		/* Read character from the parsebuffer instead of input. */
		if (parseindex >= 0) {
			c = parsebuf[parseindex++];
			if (c != '\0')
				return (c);
			parsebuf = NULL;
		} else
			parseindex++;
	}

	if (pushback_index)
		return (pushback_buffer[--pushback_index]);

	if (quotec) {
		if ((c = getc(file->stream)) == EOF) {
			yyerror("reached end of file while parsing quoted string");
			if (popfile() == EOF)
				return (EOF);
			return (quotec);
		}
		return (c);
	}

	while ((c = getc(file->stream)) == '\\') {
		next = getc(file->stream);
		if (next != '\n') {
			c = next;
			break;
		}
		yylval.lineno = file->lineno;
		file->lineno++;
	}

	while (c == EOF) {
		if (popfile() == EOF)
			return (EOF);
		c = getc(file->stream);
	}
	return (c);
}

int
lungetc(int c)
{
	if (c == EOF)
		return (EOF);
	if (parsebuf) {
		parseindex--;
		if (parseindex >= 0)
			return (c);
	}
	if (pushback_index < MAXPUSHBACK-1)
		return (pushback_buffer[pushback_index++] = c);
	else
		return (EOF);
}

int
findeol(void)
{
	int	c;

	parsebuf = NULL;

	/* skip to either EOF or the first real EOL */
	while (1) {
		if (pushback_index)
			c = pushback_buffer[--pushback_index];
		else
			c = lgetc(0);
		if (c == '\n') {
			file->lineno++;
			break;
		}
		if (c == EOF)
			break;
	}
	return (ERROR);
}

int
yylex(void)
{
	char	 buf[8096];
	char	*p, *val;
	int	 quotec, next, c;
	int	 token;

top:
	p = buf;
	while ((c = lgetc(0)) == ' ' || c == '\t')
		; /* nothing */

	yylval.lineno = file->lineno;
	if (c == '#')
		while ((c = lgetc(0)) != '\n' && c != EOF)
			; /* nothing */
	if (c == '$' && parsebuf == NULL) {
		while (1) {
			if ((c = lgetc(0)) == EOF)
				return (0);

			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
			}
			if (isalnum(c) || c == '_') {
				*p++ = (char)c;
				continue;
			}
			*p = '\0';
			lungetc(c);
			break;
		}
		val = symget(buf);
		if (val == NULL) {
			yyerror("macro '%s' not defined", buf);
			return (findeol());
		}
		parsebuf = val;
		parseindex = 0;
		goto top;
	}

	switch (c) {
	case '\'':
	case '"':
		quotec = c;
		while (1) {
			if ((c = lgetc(quotec)) == EOF)
				return (0);
			if (c == '\n') {
				file->lineno++;
				continue;
			} else if (c == '\\') {
				if ((next = lgetc(quotec)) == EOF)
					return (0);
				if (next == quotec || c == ' ' || c == '\t')
					c = next;
				else if (next == '\n')
					continue;
				else
					lungetc(next);
			} else if (c == quotec) {
				*p = '\0';
				break;
			}
			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
			}
			*p++ = (char)c;
		}
		yylval.v.string = strdup(buf);
		if (yylval.v.string == NULL)
			err(1, "yylex: strdup");
		return (STRING);
	case '<':
		next = lgetc(0);
		if (next == '>') {
			yylval.v.i = PF_OP_XRG;
			return (PORTBINARY);
		}
		lungetc(next);
		break;
	case '>':
		next = lgetc(0);
		if (next == '<') {
			yylval.v.i = PF_OP_IRG;
			return (PORTBINARY);
		}
		lungetc(next);
		break;
	case '-':
		next = lgetc(0);
		if (next == '>')
			return (ARROW);
		lungetc(next);
		break;
	}

#define allowed_to_end_number(x) \
	(isspace(x) || x == ')' || x ==',' || x == '/' || x == '}' || x == '=')

	if (c == '-' || isdigit(c)) {
		do {
			*p++ = c;
			if ((unsigned)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && isdigit(c));
		lungetc(c);
		if (p == buf + 1 && buf[0] == '-')
			goto nodigits;
		if (c == EOF || allowed_to_end_number(c)) {
			const char *errstr = NULL;

			*p = '\0';
			yylval.v.number = strtonum(buf, LLONG_MIN,
			    LLONG_MAX, &errstr);
			if (errstr) {
				yyerror("\"%s\" invalid number: %s",
				    buf, errstr);
				return (findeol());
			}
			return (NUMBER);
		} else {
nodigits:
			while (p > buf + 1)
				lungetc(*--p);
			c = *--p;
			if (c == '-')
				return (c);
		}
	}

#define allowed_in_string(x) \
	(isalnum(x) || (ispunct(x) && x != '(' && x != ')' && \
	x != '{' && x != '}' && x != '<' && x != '>' && \
	x != '!' && x != '=' && x != '/' && x != '#' && \
	x != ','))

	if (isalnum(c) || c == ':' || c == '_') {
		do {
			*p++ = c;
			if ((unsigned)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && (allowed_in_string(c)));
		lungetc(c);
		*p = '\0';
		if ((token = lookup(buf)) == STRING)
			if ((yylval.v.string = strdup(buf)) == NULL)
				err(1, "yylex: strdup");
		return (token);
	}
	if (c == '\n') {
		yylval.lineno = file->lineno;
		file->lineno++;
	}
	if (c == EOF)
		return (0);
	return (c);
}

int
check_file_secrecy(int fd, const char *fname)
{
	struct stat	st;

	if (fstat(fd, &st)) {
		warn("cannot stat %s", fname);
		return (-1);
	}
	if (st.st_uid != 0 && st.st_uid != getuid()) {
		warnx("%s: owner not root or current user", fname);
		return (-1);
	}
	if (st.st_mode & (S_IRWXG | S_IRWXO)) {
		warnx("%s: group/world readable/writeable", fname);
		return (-1);
	}
	return (0);
}

struct file *
pushfile(const char *name, int secret)
{
	struct file	*nfile;

	if ((nfile = calloc(1, sizeof(struct file))) == NULL ||
	    (nfile->name = strdup(name)) == NULL) {
		warn("malloc");
		return (NULL);
	}
	if (TAILQ_FIRST(&files) == NULL && strcmp(nfile->name, "-") == 0) {
		nfile->stream = stdin;
		free(nfile->name);
		if ((nfile->name = strdup("stdin")) == NULL) {
			warn("strdup");
			free(nfile);
			return (NULL);
		}
	} else if ((nfile->stream = fopen(nfile->name, "r")) == NULL) {
		warn("%s", nfile->name);
		free(nfile->name);
		free(nfile);
		return (NULL);
	} else if (secret &&
	    check_file_secrecy(fileno(nfile->stream), nfile->name)) {
		fclose(nfile->stream);
		free(nfile->name);
		free(nfile);
		return (NULL);
	}
	nfile->lineno = 1;
	TAILQ_INSERT_TAIL(&files, nfile, entry);
	return (nfile);
}

int
popfile(void)
{
	struct file	*prev;

	if ((prev = TAILQ_PREV(file, files, entry)) != NULL) {
		prev->errors += file->errors;
		TAILQ_REMOVE(&files, file, entry);
		fclose(file->stream);
		free(file->name);
		free(file);
		file = prev;
		return (0);
	}
	return (EOF);
}

int
parse_config(char *filename, struct pfctl *xpf)
{
	int		 errors = 0;
	struct sym	*sym;

	pf = xpf;
	errors = 0;
	rulestate = PFCTL_STATE_NONE;
	returnicmpdefault = (ICMP_UNREACH << 8) | ICMP_UNREACH_PORT;
	returnicmp6default =
	    (ICMP6_DST_UNREACH << 8) | ICMP6_DST_UNREACH_NOPORT;
	blockpolicy = PFRULE_DROP;
	require_order = 1;

	if ((file = pushfile(filename, 0)) == NULL) {
		warn("cannot open the main config file!");
		return (-1);
	}

	yyparse();
	errors = file->errors;
	popfile();

	/* Free macros and check which have not been used. */
	while ((sym = TAILQ_FIRST(&symhead))) {
		if ((pf->opts & PF_OPT_VERBOSE2) && !sym->used)
			fprintf(stderr, "warning: macro '%s' not "
			    "used\n", sym->nam);
		free(sym->nam);
		free(sym->val);
		TAILQ_REMOVE(&symhead, sym, entry);
		free(sym);
	}

	return (errors ? -1 : 0);
}

int
symset(const char *nam, const char *val, int persist)
{
	struct sym	*sym;

	for (sym = TAILQ_FIRST(&symhead); sym && strcmp(nam, sym->nam);
	    sym = TAILQ_NEXT(sym, entry))
		;	/* nothing */

	if (sym != NULL) {
		if (sym->persist == 1)
			return (0);
		else {
			free(sym->nam);
			free(sym->val);
			TAILQ_REMOVE(&symhead, sym, entry);
			free(sym);
		}
	}
	if ((sym = calloc(1, sizeof(*sym))) == NULL)
		return (-1);

	sym->nam = strdup(nam);
	if (sym->nam == NULL) {
		free(sym);
		return (-1);
	}
	sym->val = strdup(val);
	if (sym->val == NULL) {
		free(sym->nam);
		free(sym);
		return (-1);
	}
	sym->used = 0;
	sym->persist = persist;
	TAILQ_INSERT_TAIL(&symhead, sym, entry);
	return (0);
}

int
pfctl_cmdline_symset(char *s)
{
	char	*sym, *val;
	int	 ret;

	if ((val = strrchr(s, '=')) == NULL)
		return (-1);

	if ((sym = malloc(strlen(s) - strlen(val) + 1)) == NULL)
		err(1, "pfctl_cmdline_symset: malloc");

	strlcpy(sym, s, strlen(s) - strlen(val) + 1);

	ret = symset(sym, val + 1, 1);
	free(sym);

	return (ret);
}

char *
symget(const char *nam)
{
	struct sym	*sym;

	TAILQ_FOREACH(sym, &symhead, entry)
		if (strcmp(nam, sym->nam) == 0) {
			sym->used = 1;
			return (sym->val);
		}
	return (NULL);
}

void
mv_rules(struct pf_ruleset *src, struct pf_ruleset *dst)
{
	int i;
	struct pf_rule *r;

	for (i = 0; i < PF_RULESET_MAX; ++i) {
		while ((r = TAILQ_FIRST(src->rules[i].active.ptr))
		    != NULL) {
			TAILQ_REMOVE(src->rules[i].active.ptr, r, entries);
			TAILQ_INSERT_TAIL(dst->rules[i].active.ptr, r, entries);
			dst->anchor->match++;
		}
		src->anchor->match = 0;
		while ((r = TAILQ_FIRST(src->rules[i].inactive.ptr))
		    != NULL) {
			TAILQ_REMOVE(src->rules[i].inactive.ptr, r, entries);
			TAILQ_INSERT_TAIL(dst->rules[i].inactive.ptr,
				r, entries);
		}
	}
}

void
decide_address_family(struct node_host *n, sa_family_t *af)
{
	if (*af != 0 || n == NULL)
		return;
	*af = n->af;
	while ((n = n->next) != NULL) {
		if (n->af != *af) {
			*af = 0;
			return;
		}
	}
}

void
remove_invalid_hosts(struct node_host **nh, sa_family_t *af)
{
	struct node_host	*n = *nh, *prev = NULL;

	while (n != NULL) {
		if (*af && n->af && n->af != *af) {
			/* unlink and free n */
			struct node_host *next = n->next;

			/* adjust tail pointer */
			if (n == (*nh)->tail)
				(*nh)->tail = prev;
			/* adjust previous node's next pointer */
			if (prev == NULL)
				*nh = next;
			else
				prev->next = next;
			/* free node */
			if (n->ifname != NULL)
				free(n->ifname);
			free(n);
			n = next;
		} else {
			if (n->af && !*af)
				*af = n->af;
			prev = n;
			n = n->next;
		}
	}
}

int
invalid_redirect(struct node_host *nh, sa_family_t af)
{
	if (!af) {
		struct node_host *n;

		/* tables and dyniftl are ok without an address family */
		for (n = nh; n != NULL; n = n->next) {
			if (n->addr.type != PF_ADDR_TABLE &&
			    n->addr.type != PF_ADDR_DYNIFTL) {
				yyerror("address family not given and "
				    "translation address expands to multiple "
				    "address families");
				return (1);
			}
		}
	}
	if (nh == NULL) {
		yyerror("no translation address with matching address family "
		    "found.");
		return (1);
	}
	return (0);
}

int
atoul(char *s, u_long *ulvalp)
{
	u_long	 ulval;
	char	*ep;

	errno = 0;
	ulval = strtoul(s, &ep, 0);
	if (s[0] == '\0' || *ep != '\0')
		return (-1);
	if (errno == ERANGE && ulval == ULONG_MAX)
		return (-1);
	*ulvalp = ulval;
	return (0);
}

int
getservice(char *n)
{
	struct servent	*s;
	u_long		 ulval;

	if (atoul(n, &ulval) == 0) {
		if (ulval > 65535) {
			yyerror("illegal port value %lu", ulval);
			return (-1);
		}
		return (htons(ulval));
	} else {
		s = getservbyname(n, "tcp");
		if (s == NULL)
			s = getservbyname(n, "udp");
		if (s == NULL) {
			yyerror("unknown port %s", n);
			return (-1);
		}
		return (s->s_port);
	}
}

int
rule_label(struct pf_rule *r, char *s)
{
	if (s) {
		if (strlcpy(r->label, s, sizeof(r->label)) >=
		    sizeof(r->label)) {
			yyerror("rule label too long (max %d chars)",
			    sizeof(r->label)-1);
			return (-1);
		}
	}
	return (0);
}

u_int16_t
parseicmpspec(char *w, sa_family_t af)
{
	const struct icmpcodeent	*p;
	u_long				 ulval;
	u_int8_t			 icmptype;

	if (af == AF_INET)
		icmptype = returnicmpdefault >> 8;
	else
		icmptype = returnicmp6default >> 8;

	if (atoul(w, &ulval) == -1) {
		if ((p = geticmpcodebyname(icmptype, w, af)) == NULL) {
			yyerror("unknown icmp code %s", w);
			return (0);
		}
		ulval = p->code;
	}
	if (ulval > 255) {
		yyerror("invalid icmp code %lu", ulval);
		return (0);
	}
	return (icmptype << 8 | ulval);
}

int
parseport(char *port, struct range *r, int extensions)
{
	char	*p = strchr(port, ':');

	if (p == NULL) {
		if ((r->a = getservice(port)) == -1)
			return (-1);
		r->b = 0;
		r->t = PF_OP_NONE;
		return (0);
	}
	if ((extensions & PPORT_STAR) && !strcmp(p+1, "*")) {
		*p = 0;
		if ((r->a = getservice(port)) == -1)
			return (-1);
		r->b = 0;
		r->t = PF_OP_IRG;
		return (0);
	}
	if ((extensions & PPORT_RANGE)) {
		*p++ = 0;
		if ((r->a = getservice(port)) == -1 ||
		    (r->b = getservice(p)) == -1)
			return (-1);
		if (r->a == r->b) {
			r->b = 0;
			r->t = PF_OP_NONE;
		} else
			r->t = PF_OP_RRG;
		return (0);
	}
	return (-1);
}

int
pfctl_load_anchors(int dev, struct pfctl *pf, struct pfr_buffer *trans)
{
	struct loadanchors	*la;

	TAILQ_FOREACH(la, &loadanchorshead, entries) {
		if (pf->opts & PF_OPT_VERBOSE)
			fprintf(stderr, "\nLoading anchor %s from %s\n",
			    la->anchorname, la->filename);
		if (pfctl_rules(dev, la->filename, pf->opts, pf->optimize,
		    la->anchorname, trans) == -1)
			return (-1);
	}

	return (0);
}

int
rt_tableid_max(void)
{
#ifdef __FreeBSD__
	int fibs;
	size_t l = sizeof(fibs);

        if (sysctlbyname("net.fibs", &fibs, &l, NULL, 0) == -1)
		fibs = 16;	/* XXX RT_MAXFIBS, at least limit it some. */
	/*
	 * As the OpenBSD code only compares > and not >= we need to adjust
	 * here given we only accept values of 0..n and want to avoid #ifdefs
	 * in the grammer.
	 */
	return (fibs - 1);
#else
	return (RT_TABLEID_MAX);
#endif
}
#line 4102 "parse.c"

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
case 17:
#line 532 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ file->errors++; }
break;
case 18:
#line 535 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct file	*nfile;

			if ((nfile = pushfile(yystack.l_mark[0].v.string, 0)) == NULL) {
				yyerror("failed to include file %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);

			file = nfile;
			lungetc('\n');
		}
break;
case 25:
#line 562 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "none"))
				yyval.v.i = 0;
			else if (!strcmp(yystack.l_mark[0].v.string, "basic"))
				yyval.v.i = PF_OPTIMIZE_BASIC;
			else if (!strcmp(yystack.l_mark[0].v.string, "profile"))
				yyval.v.i = PF_OPTIMIZE_BASIC | PF_OPTIMIZE_PROFILE;
			else {
				yyerror("unknown ruleset-optimization %s", yystack.l_mark[0].v.string);
				YYERROR;
			}
		}
break;
case 26:
#line 576 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (check_rulestate(PFCTL_STATE_OPTION)) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			if (pfctl_set_optimization(pf, yystack.l_mark[0].v.string) != 0) {
				yyerror("unknown optimization %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 27:
#line 588 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!(pf->opts & PF_OPT_OPTIMIZE)) {
				pf->opts |= PF_OPT_OPTIMIZE;
				pf->optimize = yystack.l_mark[0].v.i;
			}
		}
break;
case 32:
#line 598 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (check_rulestate(PFCTL_STATE_OPTION)) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			if (pfctl_set_logif(pf, yystack.l_mark[0].v.string) != 0) {
				yyerror("error setting loginterface %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 33:
#line 610 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number == 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("hostid must be non-zero");
				YYERROR;
			}
			if (pfctl_set_hostid(pf, yystack.l_mark[0].v.number) != 0) {
				yyerror("error setting hostid %08x", yystack.l_mark[0].v.number);
				YYERROR;
			}
		}
break;
case 34:
#line 620 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (pf->opts & PF_OPT_VERBOSE)
				printf("set block-policy drop\n");
			if (check_rulestate(PFCTL_STATE_OPTION))
				YYERROR;
			blockpolicy = PFRULE_DROP;
		}
break;
case 35:
#line 627 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (pf->opts & PF_OPT_VERBOSE)
				printf("set block-policy return\n");
			if (check_rulestate(PFCTL_STATE_OPTION))
				YYERROR;
			blockpolicy = PFRULE_RETURN;
		}
break;
case 36:
#line 634 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (pf->opts & PF_OPT_VERBOSE)
				printf("set require-order %s\n",
				    yystack.l_mark[0].v.number == 1 ? "yes" : "no");
			require_order = yystack.l_mark[0].v.number;
		}
break;
case 37:
#line 640 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (pf->opts & PF_OPT_VERBOSE)
				printf("set fingerprints \"%s\"\n", yystack.l_mark[0].v.string);
			if (check_rulestate(PFCTL_STATE_OPTION)) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			if (!pf->anchor->name[0]) {
				if (pfctl_file_fingerprints(pf->dev,
				    pf->opts, yystack.l_mark[0].v.string)) {
					yyerror("error loading "
					    "fingerprints %s", yystack.l_mark[0].v.string);
					free(yystack.l_mark[0].v.string);
					YYERROR;
				}
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 38:
#line 658 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (pf->opts & PF_OPT_VERBOSE)
				switch (yystack.l_mark[0].v.i) {
				case 0:
					printf("set state-policy floating\n");
					break;
				case PFRULE_IFBOUND:
					printf("set state-policy if-bound\n");
					break;
				}
			default_statelock = yystack.l_mark[0].v.i;
		}
break;
case 39:
#line 670 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (check_rulestate(PFCTL_STATE_OPTION)) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			if (pfctl_set_debug(pf, yystack.l_mark[0].v.string) != 0) {
				yyerror("error setting debuglevel %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 40:
#line 682 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (expand_skip_interface(yystack.l_mark[0].v.interface) != 0) {
				yyerror("error setting skip interface(s)");
				YYERROR;
			}
		}
break;
case 41:
#line 688 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (keep_state_defaults != NULL) {
				yyerror("cannot redefine state-defaults");
				YYERROR;
			}
			keep_state_defaults = yystack.l_mark[0].v.state_opt;
		}
break;
case 42:
#line 697 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.string = yystack.l_mark[0].v.string; }
break;
case 43:
#line 698 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if ((yyval.v.string = strdup("all")) == NULL) {
				err(1, "stringall: strdup");
			}
		}
break;
case 44:
#line 705 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (asprintf(&yyval.v.string, "%s %s", yystack.l_mark[-1].v.string, yystack.l_mark[0].v.string) == -1)
				err(1, "string: asprintf");
			free(yystack.l_mark[-1].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 46:
#line 714 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (asprintf(&yyval.v.string, "%s %s", yystack.l_mark[-1].v.string, yystack.l_mark[0].v.string) == -1)
				err(1, "string: asprintf");
			free(yystack.l_mark[-1].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 48:
#line 723 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			char	*s;
			if (asprintf(&s, "%lld", (long long)yystack.l_mark[0].v.number) == -1) {
				yyerror("string: asprintf");
				YYERROR;
			}
			yyval.v.string = s;
		}
break;
case 50:
#line 734 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (pf->opts & PF_OPT_VERBOSE)
				printf("%s = \"%s\"\n", yystack.l_mark[-2].v.string, yystack.l_mark[0].v.string);
			if (symset(yystack.l_mark[-2].v.string, yystack.l_mark[0].v.string, 0) == -1)
				err(1, "cannot store variable %s", yystack.l_mark[-2].v.string);
			free(yystack.l_mark[-2].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 51:
#line 744 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.string = yystack.l_mark[0].v.string; }
break;
case 52:
#line 745 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.string = NULL; }
break;
case 57:
#line 755 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			char ta[PF_ANCHOR_NAME_SIZE];
			struct pf_ruleset *rs;

			/* steping into a brace anchor */
			pf->asd++;
			pf->bn++;
			pf->brace = 1;

			/* create a holding ruleset in the root */
			snprintf(ta, PF_ANCHOR_NAME_SIZE, "_%d", pf->bn);
			rs = pf_find_or_create_ruleset(ta);
			if (rs == NULL)
				err(1, "pfa_anchor: pf_find_or_create_ruleset");
			pf->astack[pf->asd] = rs->anchor;
			pf->anchor = rs->anchor;
		}
break;
case 58:
#line 772 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			pf->alast = pf->anchor;
			pf->asd--;
			pf->anchor = pf->astack[pf->asd];
		}
break;
case 60:
#line 782 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct pf_rule	r;
			struct node_proto	*proto;

			if (check_rulestate(PFCTL_STATE_FILTER)) {
				if (yystack.l_mark[-8].v.string)
					free(yystack.l_mark[-8].v.string);
				YYERROR;
			}

			if (yystack.l_mark[-8].v.string && (yystack.l_mark[-8].v.string[0] == '_' || strstr(yystack.l_mark[-8].v.string, "/_") != NULL)) {
				free(yystack.l_mark[-8].v.string);
				yyerror("anchor names beginning with '_' "
				    "are reserved for internal use");
				YYERROR;
			}

			memset(&r, 0, sizeof(r));
			if (pf->astack[pf->asd + 1]) {
				/* move inline rules into relative location */
				pf_anchor_setup(&r,
				    &pf->astack[pf->asd]->ruleset,
				    yystack.l_mark[-8].v.string ? yystack.l_mark[-8].v.string : pf->alast->name);
		
				if (r.anchor == NULL)
					err(1, "anchorrule: unable to "
					    "create ruleset");

				if (pf->alast != r.anchor) {
					if (r.anchor->match) {
						yyerror("inline anchor '%s' "
						    "already exists",
						    r.anchor->name);
						YYERROR;
					}
					mv_rules(&pf->alast->ruleset,
					    &r.anchor->ruleset);
				}
				pf_remove_if_empty_ruleset(&pf->alast->ruleset);
				pf->alast = r.anchor;
			} else {
				if (!yystack.l_mark[-8].v.string) {
					yyerror("anchors without explicit "
					    "rules must specify a name");
					YYERROR;
				}
			}
			r.direction = yystack.l_mark[-7].v.i;
			r.quick = yystack.l_mark[-6].v.logquick.quick;
			r.af = yystack.l_mark[-4].v.i;
			r.prob = yystack.l_mark[-1].v.filter_opts.prob;
			r.rtableid = yystack.l_mark[-1].v.filter_opts.rtableid;

			if (yystack.l_mark[-1].v.filter_opts.tag)
				if (strlcpy(r.tagname, yystack.l_mark[-1].v.filter_opts.tag,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			if (yystack.l_mark[-1].v.filter_opts.match_tag)
				if (strlcpy(r.match_tagname, yystack.l_mark[-1].v.filter_opts.match_tag,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			r.match_tag_not = yystack.l_mark[-1].v.filter_opts.match_tag_not;
			if (rule_label(&r, yystack.l_mark[-1].v.filter_opts.label))
				YYERROR;
			free(yystack.l_mark[-1].v.filter_opts.label);
			r.flags = yystack.l_mark[-1].v.filter_opts.flags.b1;
			r.flagset = yystack.l_mark[-1].v.filter_opts.flags.b2;
			if ((yystack.l_mark[-1].v.filter_opts.flags.b1 & yystack.l_mark[-1].v.filter_opts.flags.b2) != yystack.l_mark[-1].v.filter_opts.flags.b1) {
				yyerror("flags always false");
				YYERROR;
			}
			if (yystack.l_mark[-1].v.filter_opts.flags.b1 || yystack.l_mark[-1].v.filter_opts.flags.b2 || yystack.l_mark[-2].v.fromto.src_os) {
				for (proto = yystack.l_mark[-3].v.proto; proto != NULL &&
				    proto->proto != IPPROTO_TCP;
				    proto = proto->next)
					;	/* nothing */
				if (proto == NULL && yystack.l_mark[-3].v.proto != NULL) {
					if (yystack.l_mark[-1].v.filter_opts.flags.b1 || yystack.l_mark[-1].v.filter_opts.flags.b2)
						yyerror(
						    "flags only apply to tcp");
					if (yystack.l_mark[-2].v.fromto.src_os)
						yyerror(
						    "OS fingerprinting only "
						    "applies to tcp");
					YYERROR;
				}
			}

			r.tos = yystack.l_mark[-1].v.filter_opts.tos;

			if (yystack.l_mark[-1].v.filter_opts.keep.action) {
				yyerror("cannot specify state handling "
				    "on anchors");
				YYERROR;
			}

			if (yystack.l_mark[-1].v.filter_opts.match_tag)
				if (strlcpy(r.match_tagname, yystack.l_mark[-1].v.filter_opts.match_tag,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			r.match_tag_not = yystack.l_mark[-1].v.filter_opts.match_tag_not;

			decide_address_family(yystack.l_mark[-2].v.fromto.src.host, &r.af);
			decide_address_family(yystack.l_mark[-2].v.fromto.dst.host, &r.af);

			expand_rule(&r, yystack.l_mark[-5].v.interface, NULL, yystack.l_mark[-3].v.proto, yystack.l_mark[-2].v.fromto.src_os,
			    yystack.l_mark[-2].v.fromto.src.host, yystack.l_mark[-2].v.fromto.src.port, yystack.l_mark[-2].v.fromto.dst.host, yystack.l_mark[-2].v.fromto.dst.port,
			    yystack.l_mark[-1].v.filter_opts.uid, yystack.l_mark[-1].v.filter_opts.gid, yystack.l_mark[-1].v.filter_opts.icmpspec,
			    pf->astack[pf->asd + 1] ? pf->alast->name : yystack.l_mark[-8].v.string);
			free(yystack.l_mark[-8].v.string);
			pf->astack[pf->asd + 1] = NULL;
		}
break;
case 61:
#line 903 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct pf_rule	r;

			if (check_rulestate(PFCTL_STATE_NAT)) {
				free(yystack.l_mark[-5].v.string);
				YYERROR;
			}

			memset(&r, 0, sizeof(r));
			r.action = PF_NAT;
			r.af = yystack.l_mark[-3].v.i;
			r.rtableid = yystack.l_mark[0].v.rtableid;

			decide_address_family(yystack.l_mark[-1].v.fromto.src.host, &r.af);
			decide_address_family(yystack.l_mark[-1].v.fromto.dst.host, &r.af);

			expand_rule(&r, yystack.l_mark[-4].v.interface, NULL, yystack.l_mark[-2].v.proto, yystack.l_mark[-1].v.fromto.src_os,
			    yystack.l_mark[-1].v.fromto.src.host, yystack.l_mark[-1].v.fromto.src.port, yystack.l_mark[-1].v.fromto.dst.host, yystack.l_mark[-1].v.fromto.dst.port,
			    0, 0, 0, yystack.l_mark[-5].v.string);
			free(yystack.l_mark[-5].v.string);
		}
break;
case 62:
#line 924 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct pf_rule	r;

			if (check_rulestate(PFCTL_STATE_NAT)) {
				free(yystack.l_mark[-5].v.string);
				YYERROR;
			}

			memset(&r, 0, sizeof(r));
			r.action = PF_RDR;
			r.af = yystack.l_mark[-3].v.i;
			r.rtableid = yystack.l_mark[0].v.rtableid;

			decide_address_family(yystack.l_mark[-1].v.fromto.src.host, &r.af);
			decide_address_family(yystack.l_mark[-1].v.fromto.dst.host, &r.af);

			if (yystack.l_mark[-1].v.fromto.src.port != NULL) {
				yyerror("source port parameter not supported"
				    " in rdr-anchor");
				YYERROR;
			}
			if (yystack.l_mark[-1].v.fromto.dst.port != NULL) {
				if (yystack.l_mark[-1].v.fromto.dst.port->next != NULL) {
					yyerror("destination port list "
					    "expansion not supported in "
					    "rdr-anchor");
					YYERROR;
				} else if (yystack.l_mark[-1].v.fromto.dst.port->op != PF_OP_EQ) {
					yyerror("destination port operators"
					    " not supported in rdr-anchor");
					YYERROR;
				}
				r.dst.port[0] = yystack.l_mark[-1].v.fromto.dst.port->port[0];
				r.dst.port[1] = yystack.l_mark[-1].v.fromto.dst.port->port[1];
				r.dst.port_op = yystack.l_mark[-1].v.fromto.dst.port->op;
			}

			expand_rule(&r, yystack.l_mark[-4].v.interface, NULL, yystack.l_mark[-2].v.proto, yystack.l_mark[-1].v.fromto.src_os,
			    yystack.l_mark[-1].v.fromto.src.host, yystack.l_mark[-1].v.fromto.src.port, yystack.l_mark[-1].v.fromto.dst.host, yystack.l_mark[-1].v.fromto.dst.port,
			    0, 0, 0, yystack.l_mark[-5].v.string);
			free(yystack.l_mark[-5].v.string);
		}
break;
case 63:
#line 966 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct pf_rule	r;

			if (check_rulestate(PFCTL_STATE_NAT)) {
				free(yystack.l_mark[-5].v.string);
				YYERROR;
			}

			memset(&r, 0, sizeof(r));
			r.action = PF_BINAT;
			r.af = yystack.l_mark[-3].v.i;
			r.rtableid = yystack.l_mark[0].v.rtableid;
			if (yystack.l_mark[-2].v.proto != NULL) {
				if (yystack.l_mark[-2].v.proto->next != NULL) {
					yyerror("proto list expansion"
					    " not supported in binat-anchor");
					YYERROR;
				}
				r.proto = yystack.l_mark[-2].v.proto->proto;
				free(yystack.l_mark[-2].v.proto);
			}

			if (yystack.l_mark[-1].v.fromto.src.host != NULL || yystack.l_mark[-1].v.fromto.src.port != NULL ||
			    yystack.l_mark[-1].v.fromto.dst.host != NULL || yystack.l_mark[-1].v.fromto.dst.port != NULL) {
				yyerror("fromto parameter not supported"
				    " in binat-anchor");
				YYERROR;
			}

			decide_address_family(yystack.l_mark[-1].v.fromto.src.host, &r.af);
			decide_address_family(yystack.l_mark[-1].v.fromto.dst.host, &r.af);

			pfctl_add_rule(pf, &r, yystack.l_mark[-5].v.string);
			free(yystack.l_mark[-5].v.string);
		}
break;
case 64:
#line 1003 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct loadanchors	*loadanchor;

			if (strlen(pf->anchor->name) + 1 +
			    strlen(yystack.l_mark[-2].v.string) >= MAXPATHLEN) {
				yyerror("anchorname %s too long, max %u\n",
				    yystack.l_mark[-2].v.string, MAXPATHLEN - 1);
				free(yystack.l_mark[-2].v.string);
				YYERROR;
			}
			loadanchor = calloc(1, sizeof(struct loadanchors));
			if (loadanchor == NULL)
				err(1, "loadrule: calloc");
			if ((loadanchor->anchorname = malloc(MAXPATHLEN)) ==
			    NULL)
				err(1, "loadrule: malloc");
			if (pf->anchor->name[0])
				snprintf(loadanchor->anchorname, MAXPATHLEN,
				    "%s/%s", pf->anchor->name, yystack.l_mark[-2].v.string);
			else
				strlcpy(loadanchor->anchorname, yystack.l_mark[-2].v.string, MAXPATHLEN);
			if ((loadanchor->filename = strdup(yystack.l_mark[0].v.string)) == NULL)
				err(1, "loadrule: strdup");

			TAILQ_INSERT_TAIL(&loadanchorshead, loadanchor,
			    entries);

			free(yystack.l_mark[-2].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 65:
#line 1034 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = yyval.v.b.w = 0;
			if (yystack.l_mark[-1].v.i)
				yyval.v.b.b1 = PF_NOSCRUB;
			else
				yyval.v.b.b1 = PF_SCRUB;
		}
break;
case 66:
#line 1044 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct pf_rule	r;

			if (check_rulestate(PFCTL_STATE_SCRUB))
				YYERROR;

			memset(&r, 0, sizeof(r));

			r.action = yystack.l_mark[-7].v.b.b1;
			r.direction = yystack.l_mark[-6].v.i;

			r.log = yystack.l_mark[-5].v.logquick.log;
			r.logif = yystack.l_mark[-5].v.logquick.logif;
			if (yystack.l_mark[-5].v.logquick.quick) {
				yyerror("scrub rules do not support 'quick'");
				YYERROR;
			}

			r.af = yystack.l_mark[-3].v.i;
			if (yystack.l_mark[0].v.scrub_opts.nodf)
				r.rule_flag |= PFRULE_NODF;
			if (yystack.l_mark[0].v.scrub_opts.randomid)
				r.rule_flag |= PFRULE_RANDOMID;
			if (yystack.l_mark[0].v.scrub_opts.reassemble_tcp) {
				if (r.direction != PF_INOUT) {
					yyerror("reassemble tcp rules can not "
					    "specify direction");
					YYERROR;
				}
				r.rule_flag |= PFRULE_REASSEMBLE_TCP;
			}
			if (yystack.l_mark[0].v.scrub_opts.minttl)
				r.min_ttl = yystack.l_mark[0].v.scrub_opts.minttl;
			if (yystack.l_mark[0].v.scrub_opts.maxmss)
				r.max_mss = yystack.l_mark[0].v.scrub_opts.maxmss;
			if (yystack.l_mark[0].v.scrub_opts.marker & SOM_SETTOS) {
				r.rule_flag |= PFRULE_SET_TOS;
				r.set_tos = yystack.l_mark[0].v.scrub_opts.settos;
			}
			if (yystack.l_mark[0].v.scrub_opts.fragcache)
				r.rule_flag |= yystack.l_mark[0].v.scrub_opts.fragcache;
			if (yystack.l_mark[0].v.scrub_opts.match_tag)
				if (strlcpy(r.match_tagname, yystack.l_mark[0].v.scrub_opts.match_tag,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			r.match_tag_not = yystack.l_mark[0].v.scrub_opts.match_tag_not;
			r.rtableid = yystack.l_mark[0].v.scrub_opts.rtableid;

			expand_rule(&r, yystack.l_mark[-4].v.interface, NULL, yystack.l_mark[-2].v.proto, yystack.l_mark[-1].v.fromto.src_os,
			    yystack.l_mark[-1].v.fromto.src.host, yystack.l_mark[-1].v.fromto.src.port, yystack.l_mark[-1].v.fromto.dst.host, yystack.l_mark[-1].v.fromto.dst.port,
			    NULL, NULL, NULL, "");
		}
break;
case 67:
#line 1101 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
				bzero(&scrub_opts, sizeof scrub_opts);
				scrub_opts.rtableid = -1;
			}
break;
case 68:
#line 1106 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.scrub_opts = scrub_opts; }
break;
case 69:
#line 1107 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			bzero(&scrub_opts, sizeof scrub_opts);
			scrub_opts.rtableid = -1;
			yyval.v.scrub_opts = scrub_opts;
		}
break;
case 72:
#line 1118 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (scrub_opts.nodf) {
				yyerror("no-df cannot be respecified");
				YYERROR;
			}
			scrub_opts.nodf = 1;
		}
break;
case 73:
#line 1125 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (scrub_opts.marker & SOM_MINTTL) {
				yyerror("min-ttl cannot be respecified");
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("illegal min-ttl value %d", yystack.l_mark[0].v.number);
				YYERROR;
			}
			scrub_opts.marker |= SOM_MINTTL;
			scrub_opts.minttl = yystack.l_mark[0].v.number;
		}
break;
case 74:
#line 1137 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (scrub_opts.marker & SOM_MAXMSS) {
				yyerror("max-mss cannot be respecified");
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 65535) {
				yyerror("illegal max-mss value %d", yystack.l_mark[0].v.number);
				YYERROR;
			}
			scrub_opts.marker |= SOM_MAXMSS;
			scrub_opts.maxmss = yystack.l_mark[0].v.number;
		}
break;
case 75:
#line 1149 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (scrub_opts.marker & SOM_SETTOS) {
				yyerror("set-tos cannot be respecified");
				YYERROR;
			}
			scrub_opts.marker |= SOM_SETTOS;
			scrub_opts.settos = yystack.l_mark[0].v.number;
		}
break;
case 76:
#line 1157 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (scrub_opts.marker & SOM_FRAGCACHE) {
				yyerror("fragcache cannot be respecified");
				YYERROR;
			}
			scrub_opts.marker |= SOM_FRAGCACHE;
			scrub_opts.fragcache = yystack.l_mark[0].v.i;
		}
break;
case 77:
#line 1165 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (strcasecmp(yystack.l_mark[0].v.string, "tcp") != 0) {
				yyerror("scrub reassemble supports only tcp, "
				    "not '%s'", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
			if (scrub_opts.reassemble_tcp) {
				yyerror("reassemble tcp cannot be respecified");
				YYERROR;
			}
			scrub_opts.reassemble_tcp = 1;
		}
break;
case 78:
#line 1179 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (scrub_opts.randomid) {
				yyerror("random-id cannot be respecified");
				YYERROR;
			}
			scrub_opts.randomid = 1;
		}
break;
case 79:
#line 1186 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > rt_tableid_max()) {
				yyerror("invalid rtable id");
				YYERROR;
			}
			scrub_opts.rtableid = yystack.l_mark[0].v.number;
		}
break;
case 80:
#line 1193 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			scrub_opts.match_tag = yystack.l_mark[0].v.string;
			scrub_opts.match_tag_not = yystack.l_mark[-2].v.number;
		}
break;
case 81:
#line 1199 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 0; /* default */ }
break;
case 82:
#line 1200 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 0; }
break;
case 83:
#line 1201 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 0; }
break;
case 84:
#line 1204 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct pf_rule		 r;
			struct node_host	*h = NULL, *hh;
			struct node_if		*i, *j;

			if (check_rulestate(PFCTL_STATE_FILTER))
				YYERROR;

			for (i = yystack.l_mark[-2].v.interface; i; i = i->next) {
				bzero(&r, sizeof(r));

				r.action = PF_DROP;
				r.direction = PF_IN;
				r.log = yystack.l_mark[-3].v.logquick.log;
				r.logif = yystack.l_mark[-3].v.logquick.logif;
				r.quick = yystack.l_mark[-3].v.logquick.quick;
				r.af = yystack.l_mark[-1].v.i;
				if (rule_label(&r, yystack.l_mark[0].v.antispoof_opts.label))
					YYERROR;
				r.rtableid = yystack.l_mark[0].v.antispoof_opts.rtableid;
				j = calloc(1, sizeof(struct node_if));
				if (j == NULL)
					err(1, "antispoof: calloc");
				if (strlcpy(j->ifname, i->ifname,
				    sizeof(j->ifname)) >= sizeof(j->ifname)) {
					free(j);
					yyerror("interface name too long");
					YYERROR;
				}
				j->not = 1;
				if (i->dynamic) {
					h = calloc(1, sizeof(*h));
					if (h == NULL)
						err(1, "address: calloc");
					h->addr.type = PF_ADDR_DYNIFTL;
					set_ipmask(h, 128);
					if (strlcpy(h->addr.v.ifname, i->ifname,
					    sizeof(h->addr.v.ifname)) >=
					    sizeof(h->addr.v.ifname)) {
						free(h);
						yyerror(
						    "interface name too long");
						YYERROR;
					}
					hh = malloc(sizeof(*hh));
					if (hh == NULL)
						 err(1, "address: malloc");
					bcopy(h, hh, sizeof(*hh));
					h->addr.iflags = PFI_AFLAG_NETWORK;
				} else {
					h = ifa_lookup(j->ifname,
					    PFI_AFLAG_NETWORK);
					hh = NULL;
				}

				if (h != NULL)
					expand_rule(&r, j, NULL, NULL, NULL, h,
					    NULL, NULL, NULL, NULL, NULL,
					    NULL, "");

				if ((i->ifa_flags & IFF_LOOPBACK) == 0) {
					bzero(&r, sizeof(r));

					r.action = PF_DROP;
					r.direction = PF_IN;
					r.log = yystack.l_mark[-3].v.logquick.log;
					r.logif = yystack.l_mark[-3].v.logquick.logif;
					r.quick = yystack.l_mark[-3].v.logquick.quick;
					r.af = yystack.l_mark[-1].v.i;
					if (rule_label(&r, yystack.l_mark[0].v.antispoof_opts.label))
						YYERROR;
					r.rtableid = yystack.l_mark[0].v.antispoof_opts.rtableid;
					if (hh != NULL)
						h = hh;
					else
						h = ifa_lookup(i->ifname, 0);
					if (h != NULL)
						expand_rule(&r, NULL, NULL,
						    NULL, NULL, h, NULL, NULL,
						    NULL, NULL, NULL, NULL, "");
				} else
					free(hh);
			}
			free(yystack.l_mark[0].v.antispoof_opts.label);
		}
break;
case 85:
#line 1291 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[0].v.interface; }
break;
case 86:
#line 1292 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[-1].v.interface; }
break;
case 87:
#line 1295 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[-1].v.interface; }
break;
case 88:
#line 1296 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.interface->tail->next = yystack.l_mark[-1].v.interface;
			yystack.l_mark[-3].v.interface->tail = yystack.l_mark[-1].v.interface;
			yyval.v.interface = yystack.l_mark[-3].v.interface;
		}
break;
case 89:
#line 1303 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[0].v.interface; }
break;
case 90:
#line 1304 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-1].v.interface->dynamic = 1;
			yyval.v.interface = yystack.l_mark[-1].v.interface;
		}
break;
case 91:
#line 1310 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
				bzero(&antispoof_opts, sizeof antispoof_opts);
				antispoof_opts.rtableid = -1;
			}
break;
case 92:
#line 1315 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.antispoof_opts = antispoof_opts; }
break;
case 93:
#line 1316 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			bzero(&antispoof_opts, sizeof antispoof_opts);
			antispoof_opts.rtableid = -1;
			yyval.v.antispoof_opts = antispoof_opts;
		}
break;
case 96:
#line 1327 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (antispoof_opts.label) {
				yyerror("label cannot be redefined");
				YYERROR;
			}
			antispoof_opts.label = yystack.l_mark[0].v.string;
		}
break;
case 97:
#line 1334 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > rt_tableid_max()) {
				yyerror("invalid rtable id");
				YYERROR;
			}
			antispoof_opts.rtableid = yystack.l_mark[0].v.number;
		}
break;
case 98:
#line 1343 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.number = 1; }
break;
case 99:
#line 1344 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.number = 0; }
break;
case 100:
#line 1347 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct node_host	 *h, *nh;
			struct node_tinit	 *ti, *nti;

			if (strlen(yystack.l_mark[-2].v.string) >= PF_TABLE_NAME_SIZE) {
				yyerror("table name too long, max %d chars",
				    PF_TABLE_NAME_SIZE - 1);
				free(yystack.l_mark[-2].v.string);
				YYERROR;
			}
			if (pf->loadopt & PFCTL_FLAG_TABLE)
				if (process_tabledef(yystack.l_mark[-2].v.string, &yystack.l_mark[0].v.table_opts)) {
					free(yystack.l_mark[-2].v.string);
					YYERROR;
				}
			free(yystack.l_mark[-2].v.string);
			for (ti = SIMPLEQ_FIRST(&yystack.l_mark[0].v.table_opts.init_nodes);
			    ti != SIMPLEQ_END(&yystack.l_mark[0].v.table_opts.init_nodes); ti = nti) {
				if (ti->file)
					free(ti->file);
				for (h = ti->host; h != NULL; h = nh) {
					nh = h->next;
					free(h);
				}
				nti = SIMPLEQ_NEXT(ti, entries);
				free(ti);
			}
		}
break;
case 101:
#line 1377 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			bzero(&table_opts, sizeof table_opts);
			SIMPLEQ_INIT(&table_opts.init_nodes);
		}
break;
case 102:
#line 1382 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.table_opts = table_opts; }
break;
case 103:
#line 1384 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			bzero(&table_opts, sizeof table_opts);
			SIMPLEQ_INIT(&table_opts.init_nodes);
			yyval.v.table_opts = table_opts;
		}
break;
case 106:
#line 1395 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "const"))
				table_opts.flags |= PFR_TFLAG_CONST;
			else if (!strcmp(yystack.l_mark[0].v.string, "persist"))
				table_opts.flags |= PFR_TFLAG_PERSIST;
			else if (!strcmp(yystack.l_mark[0].v.string, "counters"))
				table_opts.flags |= PFR_TFLAG_COUNTERS;
			else {
				yyerror("invalid table option '%s'", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 107:
#line 1409 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ table_opts.init_addr = 1; }
break;
case 108:
#line 1410 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct node_host	*n;
			struct node_tinit	*ti;

			for (n = yystack.l_mark[-1].v.host; n != NULL; n = n->next) {
				switch (n->addr.type) {
				case PF_ADDR_ADDRMASK:
					continue; /* ok */
				case PF_ADDR_RANGE:
					yyerror("address ranges are not "
					    "permitted inside tables");
					break;
				case PF_ADDR_DYNIFTL:
					yyerror("dynamic addresses are not "
					    "permitted inside tables");
					break;
				case PF_ADDR_TABLE:
					yyerror("tables cannot contain tables");
					break;
				case PF_ADDR_NOROUTE:
					yyerror("\"no-route\" is not permitted "
					    "inside tables");
					break;
				case PF_ADDR_URPFFAILED:
					yyerror("\"urpf-failed\" is not "
					    "permitted inside tables");
					break;
				default:
					yyerror("unknown address type %d",
					    n->addr.type);
				}
				YYERROR;
			}
			if (!(ti = calloc(1, sizeof(*ti))))
				err(1, "table_opt: calloc");
			ti->host = yystack.l_mark[-1].v.host;
			SIMPLEQ_INSERT_TAIL(&table_opts.init_nodes, ti,
			    entries);
			table_opts.init_addr = 1;
		}
break;
case 109:
#line 1450 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct node_tinit	*ti;

			if (!(ti = calloc(1, sizeof(*ti))))
				err(1, "table_opt: calloc");
			ti->file = yystack.l_mark[0].v.string;
			SIMPLEQ_INSERT_TAIL(&table_opts.init_nodes, ti,
			    entries);
			table_opts.init_addr = 1;
		}
break;
case 110:
#line 1462 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct pf_altq	a;

			if (check_rulestate(PFCTL_STATE_QUEUE))
				YYERROR;

			memset(&a, 0, sizeof(a));
			if (yystack.l_mark[-2].v.queue_opts.scheduler.qtype == ALTQT_NONE) {
				yyerror("no scheduler specified!");
				YYERROR;
			}
			a.scheduler = yystack.l_mark[-2].v.queue_opts.scheduler.qtype;
			a.qlimit = yystack.l_mark[-2].v.queue_opts.qlimit;
			a.tbrsize = yystack.l_mark[-2].v.queue_opts.tbrsize;
			if (yystack.l_mark[0].v.queue == NULL && yystack.l_mark[-2].v.queue_opts.scheduler.qtype != ALTQT_CODEL) {
				yyerror("no child queues specified");
				YYERROR;
			}
			if (expand_altq(&a, yystack.l_mark[-3].v.interface, yystack.l_mark[0].v.queue, yystack.l_mark[-2].v.queue_opts.queue_bwspec,
			    &yystack.l_mark[-2].v.queue_opts.scheduler))
				YYERROR;
		}
break;
case 111:
#line 1486 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct pf_altq	a;

			if (check_rulestate(PFCTL_STATE_QUEUE)) {
				free(yystack.l_mark[-3].v.string);
				YYERROR;
			}

			memset(&a, 0, sizeof(a));

			if (strlcpy(a.qname, yystack.l_mark[-3].v.string, sizeof(a.qname)) >=
			    sizeof(a.qname)) {
				yyerror("queue name too long (max "
				    "%d chars)", PF_QNAME_SIZE-1);
				free(yystack.l_mark[-3].v.string);
				YYERROR;
			}
			free(yystack.l_mark[-3].v.string);
			if (yystack.l_mark[-1].v.queue_opts.tbrsize) {
				yyerror("cannot specify tbrsize for queue");
				YYERROR;
			}
			if (yystack.l_mark[-1].v.queue_opts.priority > 255) {
				yyerror("priority out of range: max 255");
				YYERROR;
			}
			a.priority = yystack.l_mark[-1].v.queue_opts.priority;
			a.qlimit = yystack.l_mark[-1].v.queue_opts.qlimit;
			a.scheduler = yystack.l_mark[-1].v.queue_opts.scheduler.qtype;
			if (expand_queue(&a, yystack.l_mark[-2].v.interface, yystack.l_mark[0].v.queue, yystack.l_mark[-1].v.queue_opts.queue_bwspec,
			    &yystack.l_mark[-1].v.queue_opts.scheduler)) {
				yyerror("errors in queue definition");
				YYERROR;
			}
		}
break;
case 112:
#line 1523 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			bzero(&queue_opts, sizeof queue_opts);
			queue_opts.priority = DEFAULT_PRIORITY;
			queue_opts.qlimit = DEFAULT_QLIMIT;
			queue_opts.scheduler.qtype = ALTQT_NONE;
			queue_opts.queue_bwspec.bw_percent = 100;
		}
break;
case 113:
#line 1531 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.queue_opts = queue_opts; }
break;
case 114:
#line 1532 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			bzero(&queue_opts, sizeof queue_opts);
			queue_opts.priority = DEFAULT_PRIORITY;
			queue_opts.qlimit = DEFAULT_QLIMIT;
			queue_opts.scheduler.qtype = ALTQT_NONE;
			queue_opts.queue_bwspec.bw_percent = 100;
			yyval.v.queue_opts = queue_opts;
		}
break;
case 117:
#line 1546 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (queue_opts.marker & QOM_BWSPEC) {
				yyerror("bandwidth cannot be respecified");
				YYERROR;
			}
			queue_opts.marker |= QOM_BWSPEC;
			queue_opts.queue_bwspec = yystack.l_mark[0].v.queue_bwspec;
		}
break;
case 118:
#line 1554 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (queue_opts.marker & QOM_PRIORITY) {
				yyerror("priority cannot be respecified");
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("priority out of range: max 255");
				YYERROR;
			}
			queue_opts.marker |= QOM_PRIORITY;
			queue_opts.priority = yystack.l_mark[0].v.number;
		}
break;
case 119:
#line 1566 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (queue_opts.marker & QOM_QLIMIT) {
				yyerror("qlimit cannot be respecified");
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 65535) {
				yyerror("qlimit out of range: max 65535");
				YYERROR;
			}
			queue_opts.marker |= QOM_QLIMIT;
			queue_opts.qlimit = yystack.l_mark[0].v.number;
		}
break;
case 120:
#line 1578 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (queue_opts.marker & QOM_SCHEDULER) {
				yyerror("scheduler cannot be respecified");
				YYERROR;
			}
			queue_opts.marker |= QOM_SCHEDULER;
			queue_opts.scheduler = yystack.l_mark[0].v.queue_options;
		}
break;
case 121:
#line 1586 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (queue_opts.marker & QOM_TBRSIZE) {
				yyerror("tbrsize cannot be respecified");
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 65535) {
				yyerror("tbrsize too big: max 65535");
				YYERROR;
			}
			queue_opts.marker |= QOM_TBRSIZE;
			queue_opts.tbrsize = yystack.l_mark[0].v.number;
		}
break;
case 122:
#line 1600 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			double	 bps;
			char	*cp;

			yyval.v.queue_bwspec.bw_percent = 0;

			bps = strtod(yystack.l_mark[0].v.string, &cp);
			if (cp != NULL) {
				if (!strcmp(cp, "b"))
					; /* nothing */
				else if (!strcmp(cp, "Kb"))
					bps *= 1000;
				else if (!strcmp(cp, "Mb"))
					bps *= 1000 * 1000;
				else if (!strcmp(cp, "Gb"))
					bps *= 1000 * 1000 * 1000;
				else if (!strcmp(cp, "%")) {
					if (bps < 0 || bps > 100) {
						yyerror("bandwidth spec "
						    "out of range");
						free(yystack.l_mark[0].v.string);
						YYERROR;
					}
					yyval.v.queue_bwspec.bw_percent = bps;
					bps = 0;
				} else {
					yyerror("unknown unit %s", cp);
					free(yystack.l_mark[0].v.string);
					YYERROR;
				}
			}
			free(yystack.l_mark[0].v.string);
			yyval.v.queue_bwspec.bw_absolute = (u_int32_t)bps;
		}
break;
case 123:
#line 1634 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("bandwidth number too big");
				YYERROR;
			}
			yyval.v.queue_bwspec.bw_percent = 0;
			yyval.v.queue_bwspec.bw_absolute = yystack.l_mark[0].v.number;
		}
break;
case 124:
#line 1644 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_CBQ;
			yyval.v.queue_options.data.cbq_opts.flags = 0;
		}
break;
case 125:
#line 1648 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_CBQ;
			yyval.v.queue_options.data.cbq_opts.flags = yystack.l_mark[-1].v.number;
		}
break;
case 126:
#line 1652 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_PRIQ;
			yyval.v.queue_options.data.priq_opts.flags = 0;
		}
break;
case 127:
#line 1656 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_PRIQ;
			yyval.v.queue_options.data.priq_opts.flags = yystack.l_mark[-1].v.number;
		}
break;
case 128:
#line 1660 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_HFSC;
			bzero(&yyval.v.queue_options.data.hfsc_opts,
			    sizeof(struct node_hfsc_opts));
		}
break;
case 129:
#line 1665 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_HFSC;
			yyval.v.queue_options.data.hfsc_opts = yystack.l_mark[-1].v.hfsc_opts;
		}
break;
case 130:
#line 1669 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_FAIRQ;
			bzero(&yyval.v.queue_options.data.fairq_opts,
				sizeof(struct node_fairq_opts));
		}
break;
case 131:
#line 1674 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_FAIRQ;
			yyval.v.queue_options.data.fairq_opts = yystack.l_mark[-1].v.fairq_opts;
		}
break;
case 132:
#line 1678 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_CODEL;
			bzero(&yyval.v.queue_options.data.codel_opts,
				sizeof(struct codel_opts));
		}
break;
case 133:
#line 1683 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue_options.qtype = ALTQT_CODEL;
			yyval.v.queue_options.data.codel_opts = yystack.l_mark[-1].v.codel_opts;
		}
break;
case 134:
#line 1689 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.number |= yystack.l_mark[0].v.number; }
break;
case 135:
#line 1690 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.number |= yystack.l_mark[0].v.number; }
break;
case 136:
#line 1693 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "default"))
				yyval.v.number = CBQCLF_DEFCLASS;
			else if (!strcmp(yystack.l_mark[0].v.string, "borrow"))
				yyval.v.number = CBQCLF_BORROW;
			else if (!strcmp(yystack.l_mark[0].v.string, "red"))
				yyval.v.number = CBQCLF_RED;
			else if (!strcmp(yystack.l_mark[0].v.string, "ecn"))
				yyval.v.number = CBQCLF_RED|CBQCLF_ECN;
			else if (!strcmp(yystack.l_mark[0].v.string, "rio"))
				yyval.v.number = CBQCLF_RIO;
			else if (!strcmp(yystack.l_mark[0].v.string, "codel"))
				yyval.v.number = CBQCLF_CODEL;
			else {
				yyerror("unknown cbq flag \"%s\"", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 137:
#line 1715 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.number |= yystack.l_mark[0].v.number; }
break;
case 138:
#line 1716 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.number |= yystack.l_mark[0].v.number; }
break;
case 139:
#line 1719 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "default"))
				yyval.v.number = PRCF_DEFAULTCLASS;
			else if (!strcmp(yystack.l_mark[0].v.string, "red"))
				yyval.v.number = PRCF_RED;
			else if (!strcmp(yystack.l_mark[0].v.string, "ecn"))
				yyval.v.number = PRCF_RED|PRCF_ECN;
			else if (!strcmp(yystack.l_mark[0].v.string, "rio"))
				yyval.v.number = PRCF_RIO;
			else if (!strcmp(yystack.l_mark[0].v.string, "codel"))
				yyval.v.number = PRCF_CODEL;
			else {
				yyerror("unknown priq flag \"%s\"", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 140:
#line 1739 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
				bzero(&hfsc_opts,
				    sizeof(struct node_hfsc_opts));
			}
break;
case 141:
#line 1743 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.hfsc_opts = hfsc_opts;
		}
break;
case 144:
#line 1752 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (hfsc_opts.linkshare.used) {
				yyerror("linkshare already specified");
				YYERROR;
			}
			hfsc_opts.linkshare.m2 = yystack.l_mark[0].v.queue_bwspec;
			hfsc_opts.linkshare.used = 1;
		}
break;
case 145:
#line 1761 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-3].v.number < 0 || yystack.l_mark[-3].v.number > INT_MAX) {
				yyerror("timing in curve out of range");
				YYERROR;
			}
			if (hfsc_opts.linkshare.used) {
				yyerror("linkshare already specified");
				YYERROR;
			}
			hfsc_opts.linkshare.m1 = yystack.l_mark[-5].v.queue_bwspec;
			hfsc_opts.linkshare.d = yystack.l_mark[-3].v.number;
			hfsc_opts.linkshare.m2 = yystack.l_mark[-1].v.queue_bwspec;
			hfsc_opts.linkshare.used = 1;
		}
break;
case 146:
#line 1775 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (hfsc_opts.realtime.used) {
				yyerror("realtime already specified");
				YYERROR;
			}
			hfsc_opts.realtime.m2 = yystack.l_mark[0].v.queue_bwspec;
			hfsc_opts.realtime.used = 1;
		}
break;
case 147:
#line 1784 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-3].v.number < 0 || yystack.l_mark[-3].v.number > INT_MAX) {
				yyerror("timing in curve out of range");
				YYERROR;
			}
			if (hfsc_opts.realtime.used) {
				yyerror("realtime already specified");
				YYERROR;
			}
			hfsc_opts.realtime.m1 = yystack.l_mark[-5].v.queue_bwspec;
			hfsc_opts.realtime.d = yystack.l_mark[-3].v.number;
			hfsc_opts.realtime.m2 = yystack.l_mark[-1].v.queue_bwspec;
			hfsc_opts.realtime.used = 1;
		}
break;
case 148:
#line 1798 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (hfsc_opts.upperlimit.used) {
				yyerror("upperlimit already specified");
				YYERROR;
			}
			hfsc_opts.upperlimit.m2 = yystack.l_mark[0].v.queue_bwspec;
			hfsc_opts.upperlimit.used = 1;
		}
break;
case 149:
#line 1807 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-3].v.number < 0 || yystack.l_mark[-3].v.number > INT_MAX) {
				yyerror("timing in curve out of range");
				YYERROR;
			}
			if (hfsc_opts.upperlimit.used) {
				yyerror("upperlimit already specified");
				YYERROR;
			}
			hfsc_opts.upperlimit.m1 = yystack.l_mark[-5].v.queue_bwspec;
			hfsc_opts.upperlimit.d = yystack.l_mark[-3].v.number;
			hfsc_opts.upperlimit.m2 = yystack.l_mark[-1].v.queue_bwspec;
			hfsc_opts.upperlimit.used = 1;
		}
break;
case 150:
#line 1821 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "default"))
				hfsc_opts.flags |= HFCF_DEFAULTCLASS;
			else if (!strcmp(yystack.l_mark[0].v.string, "red"))
				hfsc_opts.flags |= HFCF_RED;
			else if (!strcmp(yystack.l_mark[0].v.string, "ecn"))
				hfsc_opts.flags |= HFCF_RED|HFCF_ECN;
			else if (!strcmp(yystack.l_mark[0].v.string, "rio"))
				hfsc_opts.flags |= HFCF_RIO;
			else if (!strcmp(yystack.l_mark[0].v.string, "codel"))
				hfsc_opts.flags |= HFCF_CODEL;
			else {
				yyerror("unknown hfsc flag \"%s\"", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 151:
#line 1841 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
				bzero(&fairq_opts,
				    sizeof(struct node_fairq_opts));
			}
break;
case 152:
#line 1845 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.fairq_opts = fairq_opts;
		}
break;
case 155:
#line 1854 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (fairq_opts.linkshare.used) {
				yyerror("linkshare already specified");
				YYERROR;
			}
			fairq_opts.linkshare.m2 = yystack.l_mark[0].v.queue_bwspec;
			fairq_opts.linkshare.used = 1;
		}
break;
case 156:
#line 1862 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (fairq_opts.linkshare.used) {
				yyerror("linkshare already specified");
				YYERROR;
			}
			fairq_opts.linkshare.m1 = yystack.l_mark[-3].v.queue_bwspec;
			fairq_opts.linkshare.d = yystack.l_mark[-2].v.number;
			fairq_opts.linkshare.m2 = yystack.l_mark[-1].v.queue_bwspec;
			fairq_opts.linkshare.used = 1;
		}
break;
case 157:
#line 1872 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			fairq_opts.hogs_bw = yystack.l_mark[0].v.queue_bwspec;
		}
break;
case 158:
#line 1875 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			fairq_opts.nbuckets = yystack.l_mark[0].v.number;
		}
break;
case 159:
#line 1878 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "default"))
				fairq_opts.flags |= FARF_DEFAULTCLASS;
			else if (!strcmp(yystack.l_mark[0].v.string, "red"))
				fairq_opts.flags |= FARF_RED;
			else if (!strcmp(yystack.l_mark[0].v.string, "ecn"))
				fairq_opts.flags |= FARF_RED|FARF_ECN;
			else if (!strcmp(yystack.l_mark[0].v.string, "rio"))
				fairq_opts.flags |= FARF_RIO;
			else if (!strcmp(yystack.l_mark[0].v.string, "codel"))
				fairq_opts.flags |= FARF_CODEL;
			else {
				yyerror("unknown fairq flag \"%s\"", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 160:
#line 1898 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
				bzero(&codel_opts,
				    sizeof(struct codel_opts));
			}
break;
case 161:
#line 1902 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.codel_opts = codel_opts;
		}
break;
case 164:
#line 1911 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (codel_opts.interval) {
				yyerror("interval already specified");
				YYERROR;
			}
			codel_opts.interval = yystack.l_mark[0].v.number;
		}
break;
case 165:
#line 1918 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (codel_opts.target) {
				yyerror("target already specified");
				YYERROR;
			}
			codel_opts.target = yystack.l_mark[0].v.number;
		}
break;
case 166:
#line 1925 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "ecn"))
				codel_opts.ecn = 1;
			else {
				yyerror("unknown codel option \"%s\"", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 167:
#line 1937 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.queue = NULL; }
break;
case 168:
#line 1938 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.queue = yystack.l_mark[0].v.queue; }
break;
case 169:
#line 1939 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.queue = yystack.l_mark[-1].v.queue; }
break;
case 170:
#line 1942 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.queue = yystack.l_mark[-1].v.queue; }
break;
case 171:
#line 1943 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.queue->tail->next = yystack.l_mark[-1].v.queue;
			yystack.l_mark[-3].v.queue->tail = yystack.l_mark[-1].v.queue;
			yyval.v.queue = yystack.l_mark[-3].v.queue;
		}
break;
case 172:
#line 1950 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.queue = calloc(1, sizeof(struct node_queue));
			if (yyval.v.queue == NULL)
				err(1, "qassign_item: calloc");
			if (strlcpy(yyval.v.queue->queue, yystack.l_mark[0].v.string, sizeof(yyval.v.queue->queue)) >=
			    sizeof(yyval.v.queue->queue)) {
				yyerror("queue name '%s' too long (max "
				    "%d chars)", yystack.l_mark[0].v.string, sizeof(yyval.v.queue->queue)-1);
				free(yystack.l_mark[0].v.string);
				free(yyval.v.queue);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
			yyval.v.queue->next = NULL;
			yyval.v.queue->tail = yyval.v.queue;
		}
break;
case 173:
#line 1970 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct pf_rule		 r;
			struct node_state_opt	*o;
			struct node_proto	*proto;
			int			 srctrack = 0;
			int			 statelock = 0;
			int			 adaptive = 0;
			int			 defaults = 0;

			if (check_rulestate(PFCTL_STATE_FILTER))
				YYERROR;

			memset(&r, 0, sizeof(r));

			r.action = yystack.l_mark[-8].v.b.b1;
			switch (yystack.l_mark[-8].v.b.b2) {
			case PFRULE_RETURNRST:
				r.rule_flag |= PFRULE_RETURNRST;
				r.return_ttl = yystack.l_mark[-8].v.b.w;
				break;
			case PFRULE_RETURNICMP:
				r.rule_flag |= PFRULE_RETURNICMP;
				r.return_icmp = yystack.l_mark[-8].v.b.w;
				r.return_icmp6 = yystack.l_mark[-8].v.b.w2;
				break;
			case PFRULE_RETURN:
				r.rule_flag |= PFRULE_RETURN;
				r.return_icmp = yystack.l_mark[-8].v.b.w;
				r.return_icmp6 = yystack.l_mark[-8].v.b.w2;
				break;
			}
			r.direction = yystack.l_mark[-7].v.i;
			r.log = yystack.l_mark[-6].v.logquick.log;
			r.logif = yystack.l_mark[-6].v.logquick.logif;
			r.quick = yystack.l_mark[-6].v.logquick.quick;
			r.prob = yystack.l_mark[0].v.filter_opts.prob;
			r.rtableid = yystack.l_mark[0].v.filter_opts.rtableid;

			r.af = yystack.l_mark[-3].v.i;
			if (yystack.l_mark[0].v.filter_opts.tag)
				if (strlcpy(r.tagname, yystack.l_mark[0].v.filter_opts.tag,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			if (yystack.l_mark[0].v.filter_opts.match_tag)
				if (strlcpy(r.match_tagname, yystack.l_mark[0].v.filter_opts.match_tag,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			r.match_tag_not = yystack.l_mark[0].v.filter_opts.match_tag_not;
			if (rule_label(&r, yystack.l_mark[0].v.filter_opts.label))
				YYERROR;
			free(yystack.l_mark[0].v.filter_opts.label);
			r.flags = yystack.l_mark[0].v.filter_opts.flags.b1;
			r.flagset = yystack.l_mark[0].v.filter_opts.flags.b2;
			if ((yystack.l_mark[0].v.filter_opts.flags.b1 & yystack.l_mark[0].v.filter_opts.flags.b2) != yystack.l_mark[0].v.filter_opts.flags.b1) {
				yyerror("flags always false");
				YYERROR;
			}
			if (yystack.l_mark[0].v.filter_opts.flags.b1 || yystack.l_mark[0].v.filter_opts.flags.b2 || yystack.l_mark[-1].v.fromto.src_os) {
				for (proto = yystack.l_mark[-2].v.proto; proto != NULL &&
				    proto->proto != IPPROTO_TCP;
				    proto = proto->next)
					;	/* nothing */
				if (proto == NULL && yystack.l_mark[-2].v.proto != NULL) {
					if (yystack.l_mark[0].v.filter_opts.flags.b1 || yystack.l_mark[0].v.filter_opts.flags.b2)
						yyerror(
						    "flags only apply to tcp");
					if (yystack.l_mark[-1].v.fromto.src_os)
						yyerror(
						    "OS fingerprinting only "
						    "apply to tcp");
					YYERROR;
				}
#if 0
				if ((yystack.l_mark[0].v.filter_opts.flags.b1 & parse_flags("S")) == 0 &&
				    yystack.l_mark[-1].v.fromto.src_os) {
					yyerror("OS fingerprinting requires "
					    "the SYN TCP flag (flags S/SA)");
					YYERROR;
				}
#endif
			}

			r.tos = yystack.l_mark[0].v.filter_opts.tos;
			r.keep_state = yystack.l_mark[0].v.filter_opts.keep.action;
			o = yystack.l_mark[0].v.filter_opts.keep.options;

			/* 'keep state' by default on pass rules. */
			if (!r.keep_state && !r.action &&
			    !(yystack.l_mark[0].v.filter_opts.marker & FOM_KEEP)) {
				r.keep_state = PF_STATE_NORMAL;
				o = keep_state_defaults;
				defaults = 1;
			}

			while (o) {
				struct node_state_opt	*p = o;

				switch (o->type) {
				case PF_STATE_OPT_MAX:
					if (r.max_states) {
						yyerror("state option 'max' "
						    "multiple definitions");
						YYERROR;
					}
					r.max_states = o->data.max_states;
					break;
				case PF_STATE_OPT_NOSYNC:
					if (r.rule_flag & PFRULE_NOSYNC) {
						yyerror("state option 'sync' "
						    "multiple definitions");
						YYERROR;
					}
					r.rule_flag |= PFRULE_NOSYNC;
					break;
				case PF_STATE_OPT_SRCTRACK:
					if (srctrack) {
						yyerror("state option "
						    "'source-track' "
						    "multiple definitions");
						YYERROR;
					}
					srctrack =  o->data.src_track;
					r.rule_flag |= PFRULE_SRCTRACK;
					break;
				case PF_STATE_OPT_MAX_SRC_STATES:
					if (r.max_src_states) {
						yyerror("state option "
						    "'max-src-states' "
						    "multiple definitions");
						YYERROR;
					}
					if (o->data.max_src_states == 0) {
						yyerror("'max-src-states' must "
						    "be > 0");
						YYERROR;
					}
					r.max_src_states =
					    o->data.max_src_states;
					r.rule_flag |= PFRULE_SRCTRACK;
					break;
				case PF_STATE_OPT_OVERLOAD:
					if (r.overload_tblname[0]) {
						yyerror("multiple 'overload' "
						    "table definitions");
						YYERROR;
					}
					if (strlcpy(r.overload_tblname,
					    o->data.overload.tblname,
					    PF_TABLE_NAME_SIZE) >=
					    PF_TABLE_NAME_SIZE) {
						yyerror("state option: "
						    "strlcpy");
						YYERROR;
					}
					r.flush = o->data.overload.flush;
					break;
				case PF_STATE_OPT_MAX_SRC_CONN:
					if (r.max_src_conn) {
						yyerror("state option "
						    "'max-src-conn' "
						    "multiple definitions");
						YYERROR;
					}
					if (o->data.max_src_conn == 0) {
						yyerror("'max-src-conn' "
						    "must be > 0");
						YYERROR;
					}
					r.max_src_conn =
					    o->data.max_src_conn;
					r.rule_flag |= PFRULE_SRCTRACK |
					    PFRULE_RULESRCTRACK;
					break;
				case PF_STATE_OPT_MAX_SRC_CONN_RATE:
					if (r.max_src_conn_rate.limit) {
						yyerror("state option "
						    "'max-src-conn-rate' "
						    "multiple definitions");
						YYERROR;
					}
					if (!o->data.max_src_conn_rate.limit ||
					    !o->data.max_src_conn_rate.seconds) {
						yyerror("'max-src-conn-rate' "
						    "values must be > 0");
						YYERROR;
					}
					if (o->data.max_src_conn_rate.limit >
					    PF_THRESHOLD_MAX) {
						yyerror("'max-src-conn-rate' "
						    "maximum rate must be < %u",
						    PF_THRESHOLD_MAX);
						YYERROR;
					}
					r.max_src_conn_rate.limit =
					    o->data.max_src_conn_rate.limit;
					r.max_src_conn_rate.seconds =
					    o->data.max_src_conn_rate.seconds;
					r.rule_flag |= PFRULE_SRCTRACK |
					    PFRULE_RULESRCTRACK;
					break;
				case PF_STATE_OPT_MAX_SRC_NODES:
					if (r.max_src_nodes) {
						yyerror("state option "
						    "'max-src-nodes' "
						    "multiple definitions");
						YYERROR;
					}
					if (o->data.max_src_nodes == 0) {
						yyerror("'max-src-nodes' must "
						    "be > 0");
						YYERROR;
					}
					r.max_src_nodes =
					    o->data.max_src_nodes;
					r.rule_flag |= PFRULE_SRCTRACK |
					    PFRULE_RULESRCTRACK;
					break;
				case PF_STATE_OPT_STATELOCK:
					if (statelock) {
						yyerror("state locking option: "
						    "multiple definitions");
						YYERROR;
					}
					statelock = 1;
					r.rule_flag |= o->data.statelock;
					break;
				case PF_STATE_OPT_SLOPPY:
					if (r.rule_flag & PFRULE_STATESLOPPY) {
						yyerror("state sloppy option: "
						    "multiple definitions");
						YYERROR;
					}
					r.rule_flag |= PFRULE_STATESLOPPY;
					break;
				case PF_STATE_OPT_TIMEOUT:
					if (o->data.timeout.number ==
					    PFTM_ADAPTIVE_START ||
					    o->data.timeout.number ==
					    PFTM_ADAPTIVE_END)
						adaptive = 1;
					if (r.timeout[o->data.timeout.number]) {
						yyerror("state timeout %s "
						    "multiple definitions",
						    pf_timeouts[o->data.
						    timeout.number].name);
						YYERROR;
					}
					r.timeout[o->data.timeout.number] =
					    o->data.timeout.seconds;
				}
				o = o->next;
				if (!defaults)
					free(p);
			}

			/* 'flags S/SA' by default on stateful rules */
			if (!r.action && !r.flags && !r.flagset &&
			    !yystack.l_mark[0].v.filter_opts.fragment && !(yystack.l_mark[0].v.filter_opts.marker & FOM_FLAGS) &&
			    r.keep_state) {
				r.flags = parse_flags("S");
				r.flagset =  parse_flags("SA");
			}
			if (!adaptive && r.max_states) {
				r.timeout[PFTM_ADAPTIVE_START] =
				    (r.max_states / 10) * 6;
				r.timeout[PFTM_ADAPTIVE_END] =
				    (r.max_states / 10) * 12;
			}
			if (r.rule_flag & PFRULE_SRCTRACK) {
				if (srctrack == PF_SRCTRACK_GLOBAL &&
				    r.max_src_nodes) {
					yyerror("'max-src-nodes' is "
					    "incompatible with "
					    "'source-track global'");
					YYERROR;
				}
				if (srctrack == PF_SRCTRACK_GLOBAL &&
				    r.max_src_conn) {
					yyerror("'max-src-conn' is "
					    "incompatible with "
					    "'source-track global'");
					YYERROR;
				}
				if (srctrack == PF_SRCTRACK_GLOBAL &&
				    r.max_src_conn_rate.seconds) {
					yyerror("'max-src-conn-rate' is "
					    "incompatible with "
					    "'source-track global'");
					YYERROR;
				}
				if (r.timeout[PFTM_SRC_NODE] <
				    r.max_src_conn_rate.seconds)
					r.timeout[PFTM_SRC_NODE] =
					    r.max_src_conn_rate.seconds;
				r.rule_flag |= PFRULE_SRCTRACK;
				if (srctrack == PF_SRCTRACK_RULE)
					r.rule_flag |= PFRULE_RULESRCTRACK;
			}
			if (r.keep_state && !statelock)
				r.rule_flag |= default_statelock;

			if (yystack.l_mark[0].v.filter_opts.fragment)
				r.rule_flag |= PFRULE_FRAGMENT;
			r.allow_opts = yystack.l_mark[0].v.filter_opts.allowopts;

			decide_address_family(yystack.l_mark[-1].v.fromto.src.host, &r.af);
			decide_address_family(yystack.l_mark[-1].v.fromto.dst.host, &r.af);

			if (yystack.l_mark[-4].v.route.rt) {
				if (!r.direction) {
					yyerror("direction must be explicit "
					    "with rules that specify routing");
					YYERROR;
				}
				r.rt = yystack.l_mark[-4].v.route.rt;
				r.rpool.opts = yystack.l_mark[-4].v.route.pool_opts;
				if (yystack.l_mark[-4].v.route.key != NULL)
					memcpy(&r.rpool.key, yystack.l_mark[-4].v.route.key,
					    sizeof(struct pf_poolhashkey));
			}
			if (r.rt && r.rt != PF_FASTROUTE) {
				decide_address_family(yystack.l_mark[-4].v.route.host, &r.af);
				remove_invalid_hosts(&yystack.l_mark[-4].v.route.host, &r.af);
				if (yystack.l_mark[-4].v.route.host == NULL) {
					yyerror("no routing address with "
					    "matching address family found.");
					YYERROR;
				}
				if ((r.rpool.opts & PF_POOL_TYPEMASK) ==
				    PF_POOL_NONE && (yystack.l_mark[-4].v.route.host->next != NULL ||
				    yystack.l_mark[-4].v.route.host->addr.type == PF_ADDR_TABLE ||
				    DYNIF_MULTIADDR(yystack.l_mark[-4].v.route.host->addr)))
					r.rpool.opts |= PF_POOL_ROUNDROBIN;
				if ((r.rpool.opts & PF_POOL_TYPEMASK) !=
				    PF_POOL_ROUNDROBIN &&
				    disallow_table(yystack.l_mark[-4].v.route.host, "tables are only "
				    "supported in round-robin routing pools"))
					YYERROR;
				if ((r.rpool.opts & PF_POOL_TYPEMASK) !=
				    PF_POOL_ROUNDROBIN &&
				    disallow_alias(yystack.l_mark[-4].v.route.host, "interface (%s) "
				    "is only supported in round-robin "
				    "routing pools"))
					YYERROR;
				if (yystack.l_mark[-4].v.route.host->next != NULL) {
					if ((r.rpool.opts & PF_POOL_TYPEMASK) !=
					    PF_POOL_ROUNDROBIN) {
						yyerror("r.rpool.opts must "
						    "be PF_POOL_ROUNDROBIN");
						YYERROR;
					}
				}
			}
			if (yystack.l_mark[0].v.filter_opts.queues.qname != NULL) {
				if (strlcpy(r.qname, yystack.l_mark[0].v.filter_opts.queues.qname,
				    sizeof(r.qname)) >= sizeof(r.qname)) {
					yyerror("rule qname too long (max "
					    "%d chars)", sizeof(r.qname)-1);
					YYERROR;
				}
				free(yystack.l_mark[0].v.filter_opts.queues.qname);
			}
			if (yystack.l_mark[0].v.filter_opts.queues.pqname != NULL) {
				if (strlcpy(r.pqname, yystack.l_mark[0].v.filter_opts.queues.pqname,
				    sizeof(r.pqname)) >= sizeof(r.pqname)) {
					yyerror("rule pqname too long (max "
					    "%d chars)", sizeof(r.pqname)-1);
					YYERROR;
				}
				free(yystack.l_mark[0].v.filter_opts.queues.pqname);
			}
#ifdef __FreeBSD__
			r.divert.port = yystack.l_mark[0].v.filter_opts.divert.port;
#else
			if ((r.divert.port = yystack.l_mark[0].v.filter_opts.divert.port)) {
				if (r.direction == PF_OUT) {
					if (yystack.l_mark[0].v.filter_opts.divert.addr) {
						yyerror("address specified "
						    "for outgoing divert");
						YYERROR;
					}
					bzero(&r.divert.addr,
					    sizeof(r.divert.addr));
				} else {
					if (!yystack.l_mark[0].v.filter_opts.divert.addr) {
						yyerror("no address specified "
						    "for incoming divert");
						YYERROR;
					}
					if (yystack.l_mark[0].v.filter_opts.divert.addr->af != r.af) {
						yyerror("address family "
						    "mismatch for divert");
						YYERROR;
					}
					r.divert.addr =
					    yystack.l_mark[0].v.filter_opts.divert.addr->addr.v.a.addr;
				}
			}
#endif

			expand_rule(&r, yystack.l_mark[-5].v.interface, yystack.l_mark[-4].v.route.host, yystack.l_mark[-2].v.proto, yystack.l_mark[-1].v.fromto.src_os,
			    yystack.l_mark[-1].v.fromto.src.host, yystack.l_mark[-1].v.fromto.src.port, yystack.l_mark[-1].v.fromto.dst.host, yystack.l_mark[-1].v.fromto.dst.port,
			    yystack.l_mark[0].v.filter_opts.uid, yystack.l_mark[0].v.filter_opts.gid, yystack.l_mark[0].v.filter_opts.icmpspec, "");
		}
break;
case 174:
#line 2382 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
				bzero(&filter_opts, sizeof filter_opts);
				filter_opts.rtableid = -1;
			}
break;
case 175:
#line 2387 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.filter_opts = filter_opts; }
break;
case 176:
#line 2388 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			bzero(&filter_opts, sizeof filter_opts);
			filter_opts.rtableid = -1;
			yyval.v.filter_opts = filter_opts;
		}
break;
case 179:
#line 2399 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.uid)
				yystack.l_mark[0].v.uid->tail->next = filter_opts.uid;
			filter_opts.uid = yystack.l_mark[0].v.uid;
		}
break;
case 180:
#line 2404 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.gid)
				yystack.l_mark[0].v.gid->tail->next = filter_opts.gid;
			filter_opts.gid = yystack.l_mark[0].v.gid;
		}
break;
case 181:
#line 2409 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & FOM_FLAGS) {
				yyerror("flags cannot be redefined");
				YYERROR;
			}
			filter_opts.marker |= FOM_FLAGS;
			filter_opts.flags.b1 |= yystack.l_mark[0].v.b.b1;
			filter_opts.flags.b2 |= yystack.l_mark[0].v.b.b2;
			filter_opts.flags.w |= yystack.l_mark[0].v.b.w;
			filter_opts.flags.w2 |= yystack.l_mark[0].v.b.w2;
		}
break;
case 182:
#line 2420 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & FOM_ICMP) {
				yyerror("icmp-type cannot be redefined");
				YYERROR;
			}
			filter_opts.marker |= FOM_ICMP;
			filter_opts.icmpspec = yystack.l_mark[0].v.icmp;
		}
break;
case 183:
#line 2428 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & FOM_TOS) {
				yyerror("tos cannot be redefined");
				YYERROR;
			}
			filter_opts.marker |= FOM_TOS;
			filter_opts.tos = yystack.l_mark[0].v.number;
		}
break;
case 184:
#line 2436 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & FOM_KEEP) {
				yyerror("modulate or keep cannot be redefined");
				YYERROR;
			}
			filter_opts.marker |= FOM_KEEP;
			filter_opts.keep.action = yystack.l_mark[0].v.keep_state.action;
			filter_opts.keep.options = yystack.l_mark[0].v.keep_state.options;
		}
break;
case 185:
#line 2445 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			filter_opts.fragment = 1;
		}
break;
case 186:
#line 2448 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			filter_opts.allowopts = 1;
		}
break;
case 187:
#line 2451 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.label) {
				yyerror("label cannot be redefined");
				YYERROR;
			}
			filter_opts.label = yystack.l_mark[0].v.string;
		}
break;
case 188:
#line 2458 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.queues.qname) {
				yyerror("queue cannot be redefined");
				YYERROR;
			}
			filter_opts.queues = yystack.l_mark[0].v.qassign;
		}
break;
case 189:
#line 2465 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			filter_opts.tag = yystack.l_mark[0].v.string;
		}
break;
case 190:
#line 2468 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			filter_opts.match_tag = yystack.l_mark[0].v.string;
			filter_opts.match_tag_not = yystack.l_mark[-2].v.number;
		}
break;
case 191:
#line 2472 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			double	p;

			p = floor(yystack.l_mark[0].v.probability * UINT_MAX + 0.5);
			if (p < 0.0 || p > UINT_MAX) {
				yyerror("invalid probability: %lf", p);
				YYERROR;
			}
			filter_opts.prob = (u_int32_t)p;
			if (filter_opts.prob == 0)
				filter_opts.prob = 1;
		}
break;
case 192:
#line 2484 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > rt_tableid_max()) {
				yyerror("invalid rtable id");
				YYERROR;
			}
			filter_opts.rtableid = yystack.l_mark[0].v.number;
		}
break;
case 193:
#line 2491 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
#ifdef __FreeBSD__
			filter_opts.divert.port = yystack.l_mark[0].v.range.a;
			if (!filter_opts.divert.port) {
				yyerror("invalid divert port: %u", ntohs(yystack.l_mark[0].v.range.a));
				YYERROR;
			}
#endif
		}
break;
case 194:
#line 2500 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
#ifndef __FreeBSD__
			if ((filter_opts.divert.addr = host(yystack.l_mark[-2].v.string)) == NULL) {
				yyerror("could not parse divert address: %s",
				    yystack.l_mark[-2].v.string);
				free(yystack.l_mark[-2].v.string);
				YYERROR;
			}
#else
			if (yystack.l_mark[-2].v.string)
#endif
			free(yystack.l_mark[-2].v.string);
			filter_opts.divert.port = yystack.l_mark[0].v.range.a;
			if (!filter_opts.divert.port) {
				yyerror("invalid divert port: %u", ntohs(yystack.l_mark[0].v.range.a));
				YYERROR;
			}
		}
break;
case 195:
#line 2518 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
#ifdef __FreeBSD__
			yyerror("divert-reply has no meaning in FreeBSD pf(4)");
			YYERROR;
#else
			filter_opts.divert.port = 1;	/* some random value */
#endif
		}
break;
case 196:
#line 2528 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			char	*e;
			double	 p = strtod(yystack.l_mark[0].v.string, &e);

			if (*e == '%') {
				p *= 0.01;
				e++;
			}
			if (*e) {
				yyerror("invalid probability: %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
			yyval.v.probability = p;
		}
break;
case 197:
#line 2544 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.probability = (double)yystack.l_mark[0].v.number;
		}
break;
case 198:
#line 2550 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = PF_PASS; yyval.v.b.b2 = yyval.v.b.w = 0; }
break;
case 199:
#line 2551 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.b = yystack.l_mark[0].v.b; yyval.v.b.b1 = PF_DROP; }
break;
case 200:
#line 2554 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = blockpolicy;
			yyval.v.b.w = returnicmpdefault;
			yyval.v.b.w2 = returnicmp6default;
		}
break;
case 201:
#line 2559 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_DROP;
			yyval.v.b.w = 0;
			yyval.v.b.w2 = 0;
		}
break;
case 202:
#line 2564 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURNRST;
			yyval.v.b.w = 0;
			yyval.v.b.w2 = 0;
		}
break;
case 203:
#line 2569 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-1].v.number < 0 || yystack.l_mark[-1].v.number > 255) {
				yyerror("illegal ttl value %d", yystack.l_mark[-1].v.number);
				YYERROR;
			}
			yyval.v.b.b2 = PFRULE_RETURNRST;
			yyval.v.b.w = yystack.l_mark[-1].v.number;
			yyval.v.b.w2 = 0;
		}
break;
case 204:
#line 2578 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURNICMP;
			yyval.v.b.w = returnicmpdefault;
			yyval.v.b.w2 = returnicmp6default;
		}
break;
case 205:
#line 2583 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURNICMP;
			yyval.v.b.w = returnicmpdefault;
			yyval.v.b.w2 = returnicmp6default;
		}
break;
case 206:
#line 2588 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURNICMP;
			yyval.v.b.w = yystack.l_mark[-1].v.number;
			yyval.v.b.w2 = returnicmpdefault;
		}
break;
case 207:
#line 2593 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURNICMP;
			yyval.v.b.w = returnicmpdefault;
			yyval.v.b.w2 = yystack.l_mark[-1].v.number;
		}
break;
case 208:
#line 2598 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURNICMP;
			yyval.v.b.w = yystack.l_mark[-3].v.number;
			yyval.v.b.w2 = yystack.l_mark[-1].v.number;
		}
break;
case 209:
#line 2603 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.b.b2 = PFRULE_RETURN;
			yyval.v.b.w = returnicmpdefault;
			yyval.v.b.w2 = returnicmp6default;
		}
break;
case 210:
#line 2610 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!(yyval.v.number = parseicmpspec(yystack.l_mark[0].v.string, AF_INET))) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 211:
#line 2617 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			u_int8_t		icmptype;

			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("invalid icmp code %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			icmptype = returnicmpdefault >> 8;
			yyval.v.number = (icmptype << 8 | yystack.l_mark[0].v.number);
		}
break;
case 212:
#line 2629 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!(yyval.v.number = parseicmpspec(yystack.l_mark[0].v.string, AF_INET6))) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 213:
#line 2636 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			u_int8_t		icmptype;

			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("invalid icmp code %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			icmptype = returnicmp6default >> 8;
			yyval.v.number = (icmptype << 8 | yystack.l_mark[0].v.number);
		}
break;
case 214:
#line 2648 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_INOUT; }
break;
case 215:
#line 2649 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_IN; }
break;
case 216:
#line 2650 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OUT; }
break;
case 217:
#line 2653 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.quick = 0; }
break;
case 218:
#line 2654 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.quick = 1; }
break;
case 219:
#line 2657 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.log = 0; yyval.v.logquick.quick = 0; yyval.v.logquick.logif = 0; }
break;
case 220:
#line 2658 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick = yystack.l_mark[0].v.logquick; yyval.v.logquick.quick = 0; }
break;
case 221:
#line 2659 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.quick = 1; yyval.v.logquick.log = 0; yyval.v.logquick.logif = 0; }
break;
case 222:
#line 2660 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick = yystack.l_mark[-1].v.logquick; yyval.v.logquick.quick = 1; }
break;
case 223:
#line 2661 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick = yystack.l_mark[0].v.logquick; yyval.v.logquick.quick = 1; }
break;
case 224:
#line 2664 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.log = PF_LOG; yyval.v.logquick.logif = 0; }
break;
case 225:
#line 2665 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.logquick.log = PF_LOG | yystack.l_mark[-1].v.logquick.log;
			yyval.v.logquick.logif = yystack.l_mark[-1].v.logquick.logif;
		}
break;
case 226:
#line 2671 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick = yystack.l_mark[0].v.logquick; }
break;
case 227:
#line 2672 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.logquick.log = yystack.l_mark[-2].v.logquick.log | yystack.l_mark[0].v.logquick.log;
			yyval.v.logquick.logif = yystack.l_mark[0].v.logquick.logif;
			if (yyval.v.logquick.logif == 0)
				yyval.v.logquick.logif = yystack.l_mark[-2].v.logquick.logif;
		}
break;
case 228:
#line 2680 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.log = PF_LOG_ALL; yyval.v.logquick.logif = 0; }
break;
case 229:
#line 2681 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.log = PF_LOG_SOCKET_LOOKUP; yyval.v.logquick.logif = 0; }
break;
case 230:
#line 2682 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.logquick.log = PF_LOG_SOCKET_LOOKUP; yyval.v.logquick.logif = 0; }
break;
case 231:
#line 2683 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			const char	*errstr;
			u_int		 i;

			yyval.v.logquick.log = 0;
			if (strncmp(yystack.l_mark[0].v.string, "pflog", 5)) {
				yyerror("%s: should be a pflog interface", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			i = strtonum(yystack.l_mark[0].v.string + 5, 0, 255, &errstr);
			if (errstr) {
				yyerror("%s: %s", yystack.l_mark[0].v.string, errstr);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
			yyval.v.logquick.logif = i;
		}
break;
case 232:
#line 2704 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = NULL; }
break;
case 233:
#line 2705 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[0].v.interface; }
break;
case 234:
#line 2706 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[-1].v.interface; }
break;
case 235:
#line 2709 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[-1].v.interface; }
break;
case 236:
#line 2710 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.interface->tail->next = yystack.l_mark[-1].v.interface;
			yystack.l_mark[-3].v.interface->tail = yystack.l_mark[-1].v.interface;
			yyval.v.interface = yystack.l_mark[-3].v.interface;
		}
break;
case 237:
#line 2717 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.interface = yystack.l_mark[0].v.interface; yyval.v.interface->not = yystack.l_mark[-1].v.number; }
break;
case 238:
#line 2720 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct node_host	*n;

			yyval.v.interface = calloc(1, sizeof(struct node_if));
			if (yyval.v.interface == NULL)
				err(1, "if_item: calloc");
			if (strlcpy(yyval.v.interface->ifname, yystack.l_mark[0].v.string, sizeof(yyval.v.interface->ifname)) >=
			    sizeof(yyval.v.interface->ifname)) {
				free(yystack.l_mark[0].v.string);
				free(yyval.v.interface);
				yyerror("interface name too long");
				YYERROR;
			}

			if ((n = ifa_exists(yystack.l_mark[0].v.string)) != NULL)
				yyval.v.interface->ifa_flags = n->ifa_flags;

			free(yystack.l_mark[0].v.string);
			yyval.v.interface->not = 0;
			yyval.v.interface->next = NULL;
			yyval.v.interface->tail = yyval.v.interface;
		}
break;
case 239:
#line 2744 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 0; }
break;
case 240:
#line 2745 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = AF_INET; }
break;
case 241:
#line 2746 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = AF_INET6; }
break;
case 242:
#line 2749 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.proto = NULL; }
break;
case 243:
#line 2750 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.proto = yystack.l_mark[0].v.proto; }
break;
case 244:
#line 2751 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.proto = yystack.l_mark[-1].v.proto; }
break;
case 245:
#line 2754 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.proto = yystack.l_mark[-1].v.proto; }
break;
case 246:
#line 2755 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.proto->tail->next = yystack.l_mark[-1].v.proto;
			yystack.l_mark[-3].v.proto->tail = yystack.l_mark[-1].v.proto;
			yyval.v.proto = yystack.l_mark[-3].v.proto;
		}
break;
case 247:
#line 2762 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			u_int8_t	pr;

			pr = (u_int8_t)yystack.l_mark[0].v.number;
			if (pr == 0) {
				yyerror("proto 0 cannot be used");
				YYERROR;
			}
			yyval.v.proto = calloc(1, sizeof(struct node_proto));
			if (yyval.v.proto == NULL)
				err(1, "proto_item: calloc");
			yyval.v.proto->proto = pr;
			yyval.v.proto->next = NULL;
			yyval.v.proto->tail = yyval.v.proto;
		}
break;
case 248:
#line 2779 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct protoent	*p;

			p = getprotobyname(yystack.l_mark[0].v.string);
			if (p == NULL) {
				yyerror("unknown protocol %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			yyval.v.number = p->p_proto;
			free(yystack.l_mark[0].v.string);
		}
break;
case 249:
#line 2791 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("protocol outside range");
				YYERROR;
			}
		}
break;
case 250:
#line 2799 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.fromto.src.host = NULL;
			yyval.v.fromto.src.port = NULL;
			yyval.v.fromto.dst.host = NULL;
			yyval.v.fromto.dst.port = NULL;
			yyval.v.fromto.src_os = NULL;
		}
break;
case 251:
#line 2806 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.fromto.src = yystack.l_mark[-2].v.peer;
			yyval.v.fromto.src_os = yystack.l_mark[-1].v.os;
			yyval.v.fromto.dst = yystack.l_mark[0].v.peer;
		}
break;
case 252:
#line 2813 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.os = NULL; }
break;
case 253:
#line 2814 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.os = yystack.l_mark[0].v.os; }
break;
case 254:
#line 2815 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.os = yystack.l_mark[-1].v.os; }
break;
case 255:
#line 2818 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.os = calloc(1, sizeof(struct node_os));
			if (yyval.v.os == NULL)
				err(1, "os: calloc");
			yyval.v.os->os = yystack.l_mark[0].v.string;
			yyval.v.os->tail = yyval.v.os;
		}
break;
case 256:
#line 2827 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.os = yystack.l_mark[-1].v.os; }
break;
case 257:
#line 2828 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.os->tail->next = yystack.l_mark[-1].v.os;
			yystack.l_mark[-3].v.os->tail = yystack.l_mark[-1].v.os;
			yyval.v.os = yystack.l_mark[-3].v.os;
		}
break;
case 258:
#line 2835 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.peer.host = NULL;
			yyval.v.peer.port = NULL;
		}
break;
case 259:
#line 2839 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.peer = yystack.l_mark[0].v.peer;
		}
break;
case 260:
#line 2844 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.peer.host = NULL;
			yyval.v.peer.port = NULL;
		}
break;
case 261:
#line 2848 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (disallow_urpf_failed(yystack.l_mark[0].v.peer.host, "\"urpf-failed\" is "
			    "not permitted in a destination address"))
				YYERROR;
			yyval.v.peer = yystack.l_mark[0].v.peer;
		}
break;
case 262:
#line 2856 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.peer.host = yystack.l_mark[0].v.host;
			yyval.v.peer.port = NULL;
		}
break;
case 263:
#line 2860 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.peer.host = yystack.l_mark[-2].v.host;
			yyval.v.peer.port = yystack.l_mark[0].v.port;
		}
break;
case 264:
#line 2864 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.peer.host = NULL;
			yyval.v.peer.port = yystack.l_mark[0].v.port;
		}
break;
case 267:
#line 2874 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.host = NULL; }
break;
case 268:
#line 2875 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[0].v.host; }
break;
case 269:
#line 2876 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[-1].v.host; }
break;
case 270:
#line 2879 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[0].v.host; }
break;
case 271:
#line 2880 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.host = NULL; }
break;
case 272:
#line 2883 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[-1].v.host; }
break;
case 273:
#line 2884 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-1].v.host == NULL)
				yyval.v.host = yystack.l_mark[-3].v.host;
			else if (yystack.l_mark[-3].v.host == NULL)
				yyval.v.host = yystack.l_mark[-1].v.host;
			else {
				yystack.l_mark[-3].v.host->tail->next = yystack.l_mark[-1].v.host;
				yystack.l_mark[-3].v.host->tail = yystack.l_mark[-1].v.host->tail;
				yyval.v.host = yystack.l_mark[-3].v.host;
			}
		}
break;
case 274:
#line 2897 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct node_host	*n;

			for (n = yystack.l_mark[0].v.host; n != NULL; n = n->next)
				n->not = yystack.l_mark[-1].v.number;
			yyval.v.host = yystack.l_mark[0].v.host;
		}
break;
case 275:
#line 2904 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.host = calloc(1, sizeof(struct node_host));
			if (yyval.v.host == NULL)
				err(1, "xhost: calloc");
			yyval.v.host->addr.type = PF_ADDR_NOROUTE;
			yyval.v.host->next = NULL;
			yyval.v.host->not = yystack.l_mark[-1].v.number;
			yyval.v.host->tail = yyval.v.host;
		}
break;
case 276:
#line 2913 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.host = calloc(1, sizeof(struct node_host));
			if (yyval.v.host == NULL)
				err(1, "xhost: calloc");
			yyval.v.host->addr.type = PF_ADDR_URPFFAILED;
			yyval.v.host->next = NULL;
			yyval.v.host->not = yystack.l_mark[-1].v.number;
			yyval.v.host->tail = yyval.v.host;
		}
break;
case 277:
#line 2924 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if ((yyval.v.host = host(yystack.l_mark[0].v.string)) == NULL)	{
				/* error. "any" is handled elsewhere */
				free(yystack.l_mark[0].v.string);
				yyerror("could not parse host specification");
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);

		}
break;
case 278:
#line 2934 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct node_host *b, *e;

			if ((b = host(yystack.l_mark[-2].v.string)) == NULL || (e = host(yystack.l_mark[0].v.string)) == NULL) {
				free(yystack.l_mark[-2].v.string);
				free(yystack.l_mark[0].v.string);
				yyerror("could not parse host specification");
				YYERROR;
			}
			if (b->af != e->af ||
			    b->addr.type != PF_ADDR_ADDRMASK ||
			    e->addr.type != PF_ADDR_ADDRMASK ||
			    unmask(&b->addr.v.a.mask, b->af) !=
			    (b->af == AF_INET ? 32 : 128) ||
			    unmask(&e->addr.v.a.mask, e->af) !=
			    (e->af == AF_INET ? 32 : 128) ||
			    b->next != NULL || b->not ||
			    e->next != NULL || e->not) {
				free(b);
				free(e);
				free(yystack.l_mark[-2].v.string);
				free(yystack.l_mark[0].v.string);
				yyerror("invalid address range");
				YYERROR;
			}
			memcpy(&b->addr.v.a.mask, &e->addr.v.a.addr,
			    sizeof(b->addr.v.a.mask));
			b->addr.type = PF_ADDR_RANGE;
			yyval.v.host = b;
			free(e);
			free(yystack.l_mark[-2].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 279:
#line 2967 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			char	*buf;

			if (asprintf(&buf, "%s/%lld", yystack.l_mark[-2].v.string, (long long)yystack.l_mark[0].v.number) == -1)
				err(1, "host: asprintf");
			free(yystack.l_mark[-2].v.string);
			if ((yyval.v.host = host(buf)) == NULL)	{
				/* error. "any" is handled elsewhere */
				free(buf);
				yyerror("could not parse host specification");
				YYERROR;
			}
			free(buf);
		}
break;
case 280:
#line 2981 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			char	*buf;

			/* ie. for 10/8 parsing */
#ifdef __FreeBSD__
			if (asprintf(&buf, "%lld/%lld", (long long)yystack.l_mark[-2].v.number, (long long)yystack.l_mark[0].v.number) == -1)
#else
			if (asprintf(&buf, "%lld/%lld", yystack.l_mark[-2].v.number, yystack.l_mark[0].v.number) == -1)
#endif
				err(1, "host: asprintf");
			if ((yyval.v.host = host(buf)) == NULL)	{
				/* error. "any" is handled elsewhere */
				free(buf);
				yyerror("could not parse host specification");
				YYERROR;
			}
			free(buf);
		}
break;
case 282:
#line 3000 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct node_host	*n;

			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 128) {
				yyerror("bit number too big");
				YYERROR;
			}
			yyval.v.host = yystack.l_mark[-2].v.host;
			for (n = yystack.l_mark[-2].v.host; n != NULL; n = n->next)
				set_ipmask(n, yystack.l_mark[0].v.number);
		}
break;
case 283:
#line 3011 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (strlen(yystack.l_mark[-1].v.string) >= PF_TABLE_NAME_SIZE) {
				yyerror("table name '%s' too long", yystack.l_mark[-1].v.string);
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			yyval.v.host = calloc(1, sizeof(struct node_host));
			if (yyval.v.host == NULL)
				err(1, "host: calloc");
			yyval.v.host->addr.type = PF_ADDR_TABLE;
			if (strlcpy(yyval.v.host->addr.v.tblname, yystack.l_mark[-1].v.string,
			    sizeof(yyval.v.host->addr.v.tblname)) >=
			    sizeof(yyval.v.host->addr.v.tblname))
				errx(1, "host: strlcpy");
			free(yystack.l_mark[-1].v.string);
			yyval.v.host->next = NULL;
			yyval.v.host->tail = yyval.v.host;
		}
break;
case 285:
#line 3032 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			u_long	ulval;

			if (atoul(yystack.l_mark[0].v.string, &ulval) == -1) {
				yyerror("%s is not a number", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			} else
				yyval.v.number = ulval;
			free(yystack.l_mark[0].v.string);
		}
break;
case 286:
#line 3045 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			int	 flags = 0;
			char	*p, *op;

			op = yystack.l_mark[-1].v.string;
			if (!isalpha(op[0])) {
				yyerror("invalid interface name '%s'", op);
				free(op);
				YYERROR;
			}
			while ((p = strrchr(yystack.l_mark[-1].v.string, ':')) != NULL) {
				if (!strcmp(p+1, "network"))
					flags |= PFI_AFLAG_NETWORK;
				else if (!strcmp(p+1, "broadcast"))
					flags |= PFI_AFLAG_BROADCAST;
				else if (!strcmp(p+1, "peer"))
					flags |= PFI_AFLAG_PEER;
				else if (!strcmp(p+1, "0"))
					flags |= PFI_AFLAG_NOALIAS;
				else {
					yyerror("interface %s has bad modifier",
					    yystack.l_mark[-1].v.string);
					free(op);
					YYERROR;
				}
				*p = '\0';
			}
			if (flags & (flags - 1) & PFI_AFLAG_MODEMASK) {
				free(op);
				yyerror("illegal combination of "
				    "interface modifiers");
				YYERROR;
			}
			yyval.v.host = calloc(1, sizeof(struct node_host));
			if (yyval.v.host == NULL)
				err(1, "address: calloc");
			yyval.v.host->af = 0;
			set_ipmask(yyval.v.host, 128);
			yyval.v.host->addr.type = PF_ADDR_DYNIFTL;
			yyval.v.host->addr.iflags = flags;
			if (strlcpy(yyval.v.host->addr.v.ifname, yystack.l_mark[-1].v.string,
			    sizeof(yyval.v.host->addr.v.ifname)) >=
			    sizeof(yyval.v.host->addr.v.ifname)) {
				free(op);
				free(yyval.v.host);
				yyerror("interface name too long");
				YYERROR;
			}
			free(op);
			yyval.v.host->next = NULL;
			yyval.v.host->tail = yyval.v.host;
		}
break;
case 287:
#line 3099 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.port = yystack.l_mark[0].v.port; }
break;
case 288:
#line 3100 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.port = yystack.l_mark[-1].v.port; }
break;
case 289:
#line 3103 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.port = yystack.l_mark[-1].v.port; }
break;
case 290:
#line 3104 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.port->tail->next = yystack.l_mark[-1].v.port;
			yystack.l_mark[-3].v.port->tail = yystack.l_mark[-1].v.port;
			yyval.v.port = yystack.l_mark[-3].v.port;
		}
break;
case 291:
#line 3111 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.port = calloc(1, sizeof(struct node_port));
			if (yyval.v.port == NULL)
				err(1, "port_item: calloc");
			yyval.v.port->port[0] = yystack.l_mark[0].v.range.a;
			yyval.v.port->port[1] = yystack.l_mark[0].v.range.b;
			if (yystack.l_mark[0].v.range.t)
				yyval.v.port->op = PF_OP_RRG;
			else
				yyval.v.port->op = PF_OP_EQ;
			yyval.v.port->next = NULL;
			yyval.v.port->tail = yyval.v.port;
		}
break;
case 292:
#line 3124 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.range.t) {
				yyerror("':' cannot be used with an other "
				    "port operator");
				YYERROR;
			}
			yyval.v.port = calloc(1, sizeof(struct node_port));
			if (yyval.v.port == NULL)
				err(1, "port_item: calloc");
			yyval.v.port->port[0] = yystack.l_mark[0].v.range.a;
			yyval.v.port->port[1] = yystack.l_mark[0].v.range.b;
			yyval.v.port->op = yystack.l_mark[-1].v.i;
			yyval.v.port->next = NULL;
			yyval.v.port->tail = yyval.v.port;
		}
break;
case 293:
#line 3139 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-2].v.range.t || yystack.l_mark[0].v.range.t) {
				yyerror("':' cannot be used with an other "
				    "port operator");
				YYERROR;
			}
			yyval.v.port = calloc(1, sizeof(struct node_port));
			if (yyval.v.port == NULL)
				err(1, "port_item: calloc");
			yyval.v.port->port[0] = yystack.l_mark[-2].v.range.a;
			yyval.v.port->port[1] = yystack.l_mark[0].v.range.a;
			yyval.v.port->op = yystack.l_mark[-1].v.i;
			yyval.v.port->next = NULL;
			yyval.v.port->tail = yyval.v.port;
		}
break;
case 294:
#line 3156 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (parseport(yystack.l_mark[0].v.string, &yyval.v.range, 0) == -1) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 295:
#line 3165 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (parseport(yystack.l_mark[0].v.string, &yyval.v.range, PPORT_RANGE) == -1) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 296:
#line 3174 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.uid = yystack.l_mark[0].v.uid; }
break;
case 297:
#line 3175 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.uid = yystack.l_mark[-1].v.uid; }
break;
case 298:
#line 3178 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.uid = yystack.l_mark[-1].v.uid; }
break;
case 299:
#line 3179 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.uid->tail->next = yystack.l_mark[-1].v.uid;
			yystack.l_mark[-3].v.uid->tail = yystack.l_mark[-1].v.uid;
			yyval.v.uid = yystack.l_mark[-3].v.uid;
		}
break;
case 300:
#line 3186 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.uid = calloc(1, sizeof(struct node_uid));
			if (yyval.v.uid == NULL)
				err(1, "uid_item: calloc");
			yyval.v.uid->uid[0] = yystack.l_mark[0].v.number;
			yyval.v.uid->uid[1] = yystack.l_mark[0].v.number;
			yyval.v.uid->op = PF_OP_EQ;
			yyval.v.uid->next = NULL;
			yyval.v.uid->tail = yyval.v.uid;
		}
break;
case 301:
#line 3196 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number == UID_MAX && yystack.l_mark[-1].v.i != PF_OP_EQ && yystack.l_mark[-1].v.i != PF_OP_NE) {
				yyerror("user unknown requires operator = or "
				    "!=");
				YYERROR;
			}
			yyval.v.uid = calloc(1, sizeof(struct node_uid));
			if (yyval.v.uid == NULL)
				err(1, "uid_item: calloc");
			yyval.v.uid->uid[0] = yystack.l_mark[0].v.number;
			yyval.v.uid->uid[1] = yystack.l_mark[0].v.number;
			yyval.v.uid->op = yystack.l_mark[-1].v.i;
			yyval.v.uid->next = NULL;
			yyval.v.uid->tail = yyval.v.uid;
		}
break;
case 302:
#line 3211 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-2].v.number == UID_MAX || yystack.l_mark[0].v.number == UID_MAX) {
				yyerror("user unknown requires operator = or "
				    "!=");
				YYERROR;
			}
			yyval.v.uid = calloc(1, sizeof(struct node_uid));
			if (yyval.v.uid == NULL)
				err(1, "uid_item: calloc");
			yyval.v.uid->uid[0] = yystack.l_mark[-2].v.number;
			yyval.v.uid->uid[1] = yystack.l_mark[0].v.number;
			yyval.v.uid->op = yystack.l_mark[-1].v.i;
			yyval.v.uid->next = NULL;
			yyval.v.uid->tail = yyval.v.uid;
		}
break;
case 303:
#line 3228 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "unknown"))
				yyval.v.number = UID_MAX;
			else {
				struct passwd	*pw;

				if ((pw = getpwnam(yystack.l_mark[0].v.string)) == NULL) {
					yyerror("unknown user %s", yystack.l_mark[0].v.string);
					free(yystack.l_mark[0].v.string);
					YYERROR;
				}
				yyval.v.number = pw->pw_uid;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 304:
#line 3243 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number >= UID_MAX) {
				yyerror("illegal uid value %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			yyval.v.number = yystack.l_mark[0].v.number;
		}
break;
case 305:
#line 3252 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.gid = yystack.l_mark[0].v.gid; }
break;
case 306:
#line 3253 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.gid = yystack.l_mark[-1].v.gid; }
break;
case 307:
#line 3256 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.gid = yystack.l_mark[-1].v.gid; }
break;
case 308:
#line 3257 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.gid->tail->next = yystack.l_mark[-1].v.gid;
			yystack.l_mark[-3].v.gid->tail = yystack.l_mark[-1].v.gid;
			yyval.v.gid = yystack.l_mark[-3].v.gid;
		}
break;
case 309:
#line 3264 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.gid = calloc(1, sizeof(struct node_gid));
			if (yyval.v.gid == NULL)
				err(1, "gid_item: calloc");
			yyval.v.gid->gid[0] = yystack.l_mark[0].v.number;
			yyval.v.gid->gid[1] = yystack.l_mark[0].v.number;
			yyval.v.gid->op = PF_OP_EQ;
			yyval.v.gid->next = NULL;
			yyval.v.gid->tail = yyval.v.gid;
		}
break;
case 310:
#line 3274 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number == GID_MAX && yystack.l_mark[-1].v.i != PF_OP_EQ && yystack.l_mark[-1].v.i != PF_OP_NE) {
				yyerror("group unknown requires operator = or "
				    "!=");
				YYERROR;
			}
			yyval.v.gid = calloc(1, sizeof(struct node_gid));
			if (yyval.v.gid == NULL)
				err(1, "gid_item: calloc");
			yyval.v.gid->gid[0] = yystack.l_mark[0].v.number;
			yyval.v.gid->gid[1] = yystack.l_mark[0].v.number;
			yyval.v.gid->op = yystack.l_mark[-1].v.i;
			yyval.v.gid->next = NULL;
			yyval.v.gid->tail = yyval.v.gid;
		}
break;
case 311:
#line 3289 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-2].v.number == GID_MAX || yystack.l_mark[0].v.number == GID_MAX) {
				yyerror("group unknown requires operator = or "
				    "!=");
				YYERROR;
			}
			yyval.v.gid = calloc(1, sizeof(struct node_gid));
			if (yyval.v.gid == NULL)
				err(1, "gid_item: calloc");
			yyval.v.gid->gid[0] = yystack.l_mark[-2].v.number;
			yyval.v.gid->gid[1] = yystack.l_mark[0].v.number;
			yyval.v.gid->op = yystack.l_mark[-1].v.i;
			yyval.v.gid->next = NULL;
			yyval.v.gid->tail = yyval.v.gid;
		}
break;
case 312:
#line 3306 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "unknown"))
				yyval.v.number = GID_MAX;
			else {
				struct group	*grp;

				if ((grp = getgrnam(yystack.l_mark[0].v.string)) == NULL) {
					yyerror("unknown group %s", yystack.l_mark[0].v.string);
					free(yystack.l_mark[0].v.string);
					YYERROR;
				}
				yyval.v.number = grp->gr_gid;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 313:
#line 3321 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number >= GID_MAX) {
				yyerror("illegal gid value %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			yyval.v.number = yystack.l_mark[0].v.number;
		}
break;
case 314:
#line 3330 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			int	f;

			if ((f = parse_flags(yystack.l_mark[0].v.string)) < 0) {
				yyerror("bad flags %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
			yyval.v.b.b1 = f;
		}
break;
case 315:
#line 3343 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = yystack.l_mark[-2].v.b.b1; yyval.v.b.b2 = yystack.l_mark[0].v.b.b1; }
break;
case 316:
#line 3344 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = 0; yyval.v.b.b2 = yystack.l_mark[0].v.b.b1; }
break;
case 317:
#line 3345 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = 0; yyval.v.b.b2 = 0; }
break;
case 318:
#line 3348 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.icmp = yystack.l_mark[0].v.icmp; }
break;
case 319:
#line 3349 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.icmp = yystack.l_mark[-1].v.icmp; }
break;
case 320:
#line 3350 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.icmp = yystack.l_mark[0].v.icmp; }
break;
case 321:
#line 3351 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.icmp = yystack.l_mark[-1].v.icmp; }
break;
case 322:
#line 3354 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.icmp = yystack.l_mark[-1].v.icmp; }
break;
case 323:
#line 3355 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.icmp->tail->next = yystack.l_mark[-1].v.icmp;
			yystack.l_mark[-3].v.icmp->tail = yystack.l_mark[-1].v.icmp;
			yyval.v.icmp = yystack.l_mark[-3].v.icmp;
		}
break;
case 324:
#line 3362 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.icmp = yystack.l_mark[-1].v.icmp; }
break;
case 325:
#line 3363 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.icmp->tail->next = yystack.l_mark[-1].v.icmp;
			yystack.l_mark[-3].v.icmp->tail = yystack.l_mark[-1].v.icmp;
			yyval.v.icmp = yystack.l_mark[-3].v.icmp;
		}
break;
case 326:
#line 3370 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.icmp = calloc(1, sizeof(struct node_icmp));
			if (yyval.v.icmp == NULL)
				err(1, "icmp_item: calloc");
			yyval.v.icmp->type = yystack.l_mark[0].v.number;
			yyval.v.icmp->code = 0;
			yyval.v.icmp->proto = IPPROTO_ICMP;
			yyval.v.icmp->next = NULL;
			yyval.v.icmp->tail = yyval.v.icmp;
		}
break;
case 327:
#line 3380 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			const struct icmpcodeent	*p;

			if ((p = geticmpcodebyname(yystack.l_mark[-2].v.number-1, yystack.l_mark[0].v.string, AF_INET)) == NULL) {
				yyerror("unknown icmp-code %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}

			free(yystack.l_mark[0].v.string);
			yyval.v.icmp = calloc(1, sizeof(struct node_icmp));
			if (yyval.v.icmp == NULL)
				err(1, "icmp_item: calloc");
			yyval.v.icmp->type = yystack.l_mark[-2].v.number;
			yyval.v.icmp->code = p->code + 1;
			yyval.v.icmp->proto = IPPROTO_ICMP;
			yyval.v.icmp->next = NULL;
			yyval.v.icmp->tail = yyval.v.icmp;
		}
break;
case 328:
#line 3399 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("illegal icmp-code %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			yyval.v.icmp = calloc(1, sizeof(struct node_icmp));
			if (yyval.v.icmp == NULL)
				err(1, "icmp_item: calloc");
			yyval.v.icmp->type = yystack.l_mark[-2].v.number;
			yyval.v.icmp->code = yystack.l_mark[0].v.number + 1;
			yyval.v.icmp->proto = IPPROTO_ICMP;
			yyval.v.icmp->next = NULL;
			yyval.v.icmp->tail = yyval.v.icmp;
		}
break;
case 329:
#line 3415 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.icmp = calloc(1, sizeof(struct node_icmp));
			if (yyval.v.icmp == NULL)
				err(1, "icmp_item: calloc");
			yyval.v.icmp->type = yystack.l_mark[0].v.number;
			yyval.v.icmp->code = 0;
			yyval.v.icmp->proto = IPPROTO_ICMPV6;
			yyval.v.icmp->next = NULL;
			yyval.v.icmp->tail = yyval.v.icmp;
		}
break;
case 330:
#line 3425 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			const struct icmpcodeent	*p;

			if ((p = geticmpcodebyname(yystack.l_mark[-2].v.number-1, yystack.l_mark[0].v.string, AF_INET6)) == NULL) {
				yyerror("unknown icmp6-code %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);

			yyval.v.icmp = calloc(1, sizeof(struct node_icmp));
			if (yyval.v.icmp == NULL)
				err(1, "icmp_item: calloc");
			yyval.v.icmp->type = yystack.l_mark[-2].v.number;
			yyval.v.icmp->code = p->code + 1;
			yyval.v.icmp->proto = IPPROTO_ICMPV6;
			yyval.v.icmp->next = NULL;
			yyval.v.icmp->tail = yyval.v.icmp;
		}
break;
case 331:
#line 3444 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("illegal icmp-code %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			yyval.v.icmp = calloc(1, sizeof(struct node_icmp));
			if (yyval.v.icmp == NULL)
				err(1, "icmp_item: calloc");
			yyval.v.icmp->type = yystack.l_mark[-2].v.number;
			yyval.v.icmp->code = yystack.l_mark[0].v.number + 1;
			yyval.v.icmp->proto = IPPROTO_ICMPV6;
			yyval.v.icmp->next = NULL;
			yyval.v.icmp->tail = yyval.v.icmp;
		}
break;
case 332:
#line 3460 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			const struct icmptypeent	*p;

			if ((p = geticmptypebyname(yystack.l_mark[0].v.string, AF_INET)) == NULL) {
				yyerror("unknown icmp-type %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			yyval.v.number = p->type + 1;
			free(yystack.l_mark[0].v.string);
		}
break;
case 333:
#line 3471 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("illegal icmp-type %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			yyval.v.number = yystack.l_mark[0].v.number + 1;
		}
break;
case 334:
#line 3480 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			const struct icmptypeent	*p;

			if ((p = geticmptypebyname(yystack.l_mark[0].v.string, AF_INET6)) ==
			    NULL) {
				yyerror("unknown icmp6-type %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			yyval.v.number = p->type + 1;
			free(yystack.l_mark[0].v.string);
		}
break;
case 335:
#line 3492 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > 255) {
				yyerror("illegal icmp6-type %lu", yystack.l_mark[0].v.number);
				YYERROR;
			}
			yyval.v.number = yystack.l_mark[0].v.number + 1;
		}
break;
case 336:
#line 3501 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "lowdelay"))
				yyval.v.number = IPTOS_LOWDELAY;
			else if (!strcmp(yystack.l_mark[0].v.string, "throughput"))
				yyval.v.number = IPTOS_THROUGHPUT;
			else if (!strcmp(yystack.l_mark[0].v.string, "reliability"))
				yyval.v.number = IPTOS_RELIABILITY;
			else if (yystack.l_mark[0].v.string[0] == '0' && yystack.l_mark[0].v.string[1] == 'x')
				yyval.v.number = strtoul(yystack.l_mark[0].v.string, NULL, 16);
			else
				yyval.v.number = 0;		/* flag bad argument */
			if (!yyval.v.number || yyval.v.number > 255) {
				yyerror("illegal tos value %s", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 337:
#line 3519 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.number = yystack.l_mark[0].v.number;
			if (!yyval.v.number || yyval.v.number > 255) {
				yyerror("illegal tos value %s", yystack.l_mark[0].v.number);
				YYERROR;
			}
		}
break;
case 338:
#line 3528 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_SRCTRACK; }
break;
case 339:
#line 3529 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_SRCTRACK_GLOBAL; }
break;
case 340:
#line 3530 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_SRCTRACK_RULE; }
break;
case 341:
#line 3533 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.i = PFRULE_IFBOUND;
		}
break;
case 342:
#line 3536 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.i = 0;
		}
break;
case 343:
#line 3541 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.keep_state.action = 0;
			yyval.v.keep_state.options = NULL;
		}
break;
case 344:
#line 3545 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.keep_state.action = PF_STATE_NORMAL;
			yyval.v.keep_state.options = yystack.l_mark[0].v.state_opt;
		}
break;
case 345:
#line 3549 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.keep_state.action = PF_STATE_MODULATE;
			yyval.v.keep_state.options = yystack.l_mark[0].v.state_opt;
		}
break;
case 346:
#line 3553 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.keep_state.action = PF_STATE_SYNPROXY;
			yyval.v.keep_state.options = yystack.l_mark[0].v.state_opt;
		}
break;
case 347:
#line 3559 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 0; }
break;
case 348:
#line 3560 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_FLUSH; }
break;
case 349:
#line 3561 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.i = PF_FLUSH | PF_FLUSH_GLOBAL;
		}
break;
case 350:
#line 3566 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.state_opt = yystack.l_mark[-1].v.state_opt; }
break;
case 351:
#line 3567 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.state_opt = NULL; }
break;
case 352:
#line 3570 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.state_opt = yystack.l_mark[0].v.state_opt; }
break;
case 353:
#line 3571 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-2].v.state_opt->tail->next = yystack.l_mark[0].v.state_opt;
			yystack.l_mark[-2].v.state_opt->tail = yystack.l_mark[0].v.state_opt;
			yyval.v.state_opt = yystack.l_mark[-2].v.state_opt;
		}
break;
case 354:
#line 3578 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_MAX;
			yyval.v.state_opt->data.max_states = yystack.l_mark[0].v.number;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 355:
#line 3591 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_NOSYNC;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 356:
#line 3599 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_MAX_SRC_STATES;
			yyval.v.state_opt->data.max_src_states = yystack.l_mark[0].v.number;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 357:
#line 3612 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_MAX_SRC_CONN;
			yyval.v.state_opt->data.max_src_conn = yystack.l_mark[0].v.number;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 358:
#line 3625 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-2].v.number < 0 || yystack.l_mark[-2].v.number > UINT_MAX ||
			    yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_MAX_SRC_CONN_RATE;
			yyval.v.state_opt->data.max_src_conn_rate.limit = yystack.l_mark[-2].v.number;
			yyval.v.state_opt->data.max_src_conn_rate.seconds = yystack.l_mark[0].v.number;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 359:
#line 3640 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (strlen(yystack.l_mark[-2].v.string) >= PF_TABLE_NAME_SIZE) {
				yyerror("table name '%s' too long", yystack.l_mark[-2].v.string);
				free(yystack.l_mark[-2].v.string);
				YYERROR;
			}
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			if (strlcpy(yyval.v.state_opt->data.overload.tblname, yystack.l_mark[-2].v.string,
			    PF_TABLE_NAME_SIZE) >= PF_TABLE_NAME_SIZE)
				errx(1, "state_opt_item: strlcpy");
			free(yystack.l_mark[-2].v.string);
			yyval.v.state_opt->type = PF_STATE_OPT_OVERLOAD;
			yyval.v.state_opt->data.overload.flush = yystack.l_mark[0].v.i;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 360:
#line 3658 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_MAX_SRC_NODES;
			yyval.v.state_opt->data.max_src_nodes = yystack.l_mark[0].v.number;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 361:
#line 3671 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_SRCTRACK;
			yyval.v.state_opt->data.src_track = yystack.l_mark[0].v.i;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 362:
#line 3680 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_STATELOCK;
			yyval.v.state_opt->data.statelock = yystack.l_mark[0].v.i;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 363:
#line 3689 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_SLOPPY;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 364:
#line 3697 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			int	i;

			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			for (i = 0; pf_timeouts[i].name &&
			    strcmp(pf_timeouts[i].name, yystack.l_mark[-1].v.string); ++i)
				;	/* nothing */
			if (!pf_timeouts[i].name) {
				yyerror("illegal timeout name %s", yystack.l_mark[-1].v.string);
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			if (strchr(pf_timeouts[i].name, '.') == NULL) {
				yyerror("illegal state timeout %s", yystack.l_mark[-1].v.string);
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			free(yystack.l_mark[-1].v.string);
			yyval.v.state_opt = calloc(1, sizeof(struct node_state_opt));
			if (yyval.v.state_opt == NULL)
				err(1, "state_opt_item: calloc");
			yyval.v.state_opt->type = PF_STATE_OPT_TIMEOUT;
			yyval.v.state_opt->data.timeout.number = pf_timeouts[i].timeout;
			yyval.v.state_opt->data.timeout.seconds = yystack.l_mark[0].v.number;
			yyval.v.state_opt->next = NULL;
			yyval.v.state_opt->tail = yyval.v.state_opt;
		}
break;
case 365:
#line 3729 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.string = yystack.l_mark[0].v.string;
		}
break;
case 366:
#line 3734 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.qassign.qname = yystack.l_mark[0].v.string;
			yyval.v.qassign.pqname = NULL;
		}
break;
case 367:
#line 3738 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.qassign.qname = yystack.l_mark[-1].v.string;
			yyval.v.qassign.pqname = NULL;
		}
break;
case 368:
#line 3742 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.qassign.qname = yystack.l_mark[-3].v.string;
			yyval.v.qassign.pqname = yystack.l_mark[-1].v.string;
		}
break;
case 369:
#line 3748 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 0; }
break;
case 370:
#line 3749 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = 1; }
break;
case 371:
#line 3752 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (parseport(yystack.l_mark[0].v.string, &yyval.v.range, PPORT_RANGE|PPORT_STAR) == -1) {
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 372:
#line 3761 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[0].v.host; }
break;
case 373:
#line 3762 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[-1].v.host; }
break;
case 374:
#line 3765 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[-1].v.host; }
break;
case 375:
#line 3766 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yystack.l_mark[-3].v.host->tail->next = yystack.l_mark[-1].v.host;
			yystack.l_mark[-3].v.host->tail = yystack.l_mark[-1].v.host->tail;
			yyval.v.host = yystack.l_mark[-3].v.host;
		}
break;
case 376:
#line 3773 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.redirection = NULL; }
break;
case 377:
#line 3774 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.redirection = calloc(1, sizeof(struct redirection));
			if (yyval.v.redirection == NULL)
				err(1, "redirection: calloc");
			yyval.v.redirection->host = yystack.l_mark[0].v.host;
			yyval.v.redirection->rport.a = yyval.v.redirection->rport.b = yyval.v.redirection->rport.t = 0;
		}
break;
case 378:
#line 3781 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.redirection = calloc(1, sizeof(struct redirection));
			if (yyval.v.redirection == NULL)
				err(1, "redirection: calloc");
			yyval.v.redirection->host = yystack.l_mark[-2].v.host;
			yyval.v.redirection->rport = yystack.l_mark[0].v.range;
		}
break;
case 379:
#line 3791 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.hashkey = calloc(1, sizeof(struct pf_poolhashkey));
			if (yyval.v.hashkey == NULL)
				err(1, "hashkey: calloc");
			yyval.v.hashkey->key32[0] = arc4random();
			yyval.v.hashkey->key32[1] = arc4random();
			yyval.v.hashkey->key32[2] = arc4random();
			yyval.v.hashkey->key32[3] = arc4random();
		}
break;
case 380:
#line 3801 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!strncmp(yystack.l_mark[0].v.string, "0x", 2)) {
				if (strlen(yystack.l_mark[0].v.string) != 34) {
					free(yystack.l_mark[0].v.string);
					yyerror("hex key must be 128 bits "
						"(32 hex digits) long");
					YYERROR;
				}
				yyval.v.hashkey = calloc(1, sizeof(struct pf_poolhashkey));
				if (yyval.v.hashkey == NULL)
					err(1, "hashkey: calloc");

				if (sscanf(yystack.l_mark[0].v.string, "0x%8x%8x%8x%8x",
				    &yyval.v.hashkey->key32[0], &yyval.v.hashkey->key32[1],
				    &yyval.v.hashkey->key32[2], &yyval.v.hashkey->key32[3]) != 4) {
					free(yyval.v.hashkey);
					free(yystack.l_mark[0].v.string);
					yyerror("invalid hex key");
					YYERROR;
				}
			} else {
				MD5_CTX	context;

				yyval.v.hashkey = calloc(1, sizeof(struct pf_poolhashkey));
				if (yyval.v.hashkey == NULL)
					err(1, "hashkey: calloc");
				MD5Init(&context);
				MD5Update(&context, (unsigned char *)yystack.l_mark[0].v.string,
				    strlen(yystack.l_mark[0].v.string));
				MD5Final((unsigned char *)yyval.v.hashkey, &context);
				HTONL(yyval.v.hashkey->key32[0]);
				HTONL(yyval.v.hashkey->key32[1]);
				HTONL(yyval.v.hashkey->key32[2]);
				HTONL(yyval.v.hashkey->key32[3]);
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 381:
#line 3840 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ bzero(&pool_opts, sizeof pool_opts); }
break;
case 382:
#line 3842 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.pool_opts = pool_opts; }
break;
case 383:
#line 3843 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			bzero(&pool_opts, sizeof pool_opts);
			yyval.v.pool_opts = pool_opts;
		}
break;
case 386:
#line 3853 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (pool_opts.type) {
				yyerror("pool type cannot be redefined");
				YYERROR;
			}
			pool_opts.type =  PF_POOL_BITMASK;
		}
break;
case 387:
#line 3860 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (pool_opts.type) {
				yyerror("pool type cannot be redefined");
				YYERROR;
			}
			pool_opts.type = PF_POOL_RANDOM;
		}
break;
case 388:
#line 3867 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (pool_opts.type) {
				yyerror("pool type cannot be redefined");
				YYERROR;
			}
			pool_opts.type = PF_POOL_SRCHASH;
			pool_opts.key = yystack.l_mark[0].v.hashkey;
		}
break;
case 389:
#line 3875 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (pool_opts.type) {
				yyerror("pool type cannot be redefined");
				YYERROR;
			}
			pool_opts.type = PF_POOL_ROUNDROBIN;
		}
break;
case 390:
#line 3882 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (pool_opts.staticport) {
				yyerror("static-port cannot be redefined");
				YYERROR;
			}
			pool_opts.staticport = 1;
		}
break;
case 391:
#line 3889 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (filter_opts.marker & POM_STICKYADDRESS) {
				yyerror("sticky-address cannot be redefined");
				YYERROR;
			}
			pool_opts.marker |= POM_STICKYADDRESS;
			pool_opts.opts |= PF_POOL_STICKYADDR;
		}
break;
case 392:
#line 3899 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.redirection = NULL; }
break;
case 393:
#line 3900 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.redirection = calloc(1, sizeof(struct redirection));
			if (yyval.v.redirection == NULL)
				err(1, "redirection: calloc");
			yyval.v.redirection->host = yystack.l_mark[0].v.host;
			yyval.v.redirection->rport.a = yyval.v.redirection->rport.b = yyval.v.redirection->rport.t = 0;
		}
break;
case 394:
#line 3907 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.redirection = calloc(1, sizeof(struct redirection));
			if (yyval.v.redirection == NULL)
				err(1, "redirection: calloc");
			yyval.v.redirection->host = yystack.l_mark[-2].v.host;
			yyval.v.redirection->rport = yystack.l_mark[0].v.range;
		}
break;
case 395:
#line 3916 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = yyval.v.b.b2 = 0; yyval.v.b.w2 = 0; }
break;
case 396:
#line 3917 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = 1; yyval.v.b.b2 = 0; yyval.v.b.w2 = 0; }
break;
case 397:
#line 3918 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = 1; yyval.v.b.b2 = yystack.l_mark[0].v.logquick.log; yyval.v.b.w2 = yystack.l_mark[0].v.logquick.logif; }
break;
case 398:
#line 3919 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.b.b1 = 0; yyval.v.b.b2 = yystack.l_mark[0].v.logquick.log; yyval.v.b.w2 = yystack.l_mark[0].v.logquick.logif; }
break;
case 399:
#line 3922 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-2].v.i && yystack.l_mark[0].v.b.b1) {
				yyerror("\"pass\" not valid with \"no\"");
				YYERROR;
			}
			if (yystack.l_mark[-2].v.i)
				yyval.v.b.b1 = PF_NONAT;
			else
				yyval.v.b.b1 = PF_NAT;
			yyval.v.b.b2 = yystack.l_mark[0].v.b.b1;
			yyval.v.b.w = yystack.l_mark[0].v.b.b2;
			yyval.v.b.w2 = yystack.l_mark[0].v.b.w2;
		}
break;
case 400:
#line 3935 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-2].v.i && yystack.l_mark[0].v.b.b1) {
				yyerror("\"pass\" not valid with \"no\"");
				YYERROR;
			}
			if (yystack.l_mark[-2].v.i)
				yyval.v.b.b1 = PF_NORDR;
			else
				yyval.v.b.b1 = PF_RDR;
			yyval.v.b.b2 = yystack.l_mark[0].v.b.b1;
			yyval.v.b.w = yystack.l_mark[0].v.b.b2;
			yyval.v.b.w2 = yystack.l_mark[0].v.b.w2;
		}
break;
case 401:
#line 3952 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct pf_rule	r;

			if (check_rulestate(PFCTL_STATE_NAT))
				YYERROR;

			memset(&r, 0, sizeof(r));

			r.action = yystack.l_mark[-9].v.b.b1;
			r.natpass = yystack.l_mark[-9].v.b.b2;
			r.log = yystack.l_mark[-9].v.b.w;
			r.logif = yystack.l_mark[-9].v.b.w2;
			r.af = yystack.l_mark[-7].v.i;

			if (!r.af) {
				if (yystack.l_mark[-5].v.fromto.src.host && yystack.l_mark[-5].v.fromto.src.host->af &&
				    !yystack.l_mark[-5].v.fromto.src.host->ifindex)
					r.af = yystack.l_mark[-5].v.fromto.src.host->af;
				else if (yystack.l_mark[-5].v.fromto.dst.host && yystack.l_mark[-5].v.fromto.dst.host->af &&
				    !yystack.l_mark[-5].v.fromto.dst.host->ifindex)
					r.af = yystack.l_mark[-5].v.fromto.dst.host->af;
			}

			if (yystack.l_mark[-4].v.string != NULL)
				if (strlcpy(r.tagname, yystack.l_mark[-4].v.string, PF_TAG_NAME_SIZE) >=
				    PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}

			if (yystack.l_mark[-3].v.tagged.name)
				if (strlcpy(r.match_tagname, yystack.l_mark[-3].v.tagged.name,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			r.match_tag_not = yystack.l_mark[-3].v.tagged.neg;
			r.rtableid = yystack.l_mark[-2].v.rtableid;

			if (r.action == PF_NONAT || r.action == PF_NORDR) {
				if (yystack.l_mark[-1].v.redirection != NULL) {
					yyerror("translation rule with 'no' "
					    "does not need '->'");
					YYERROR;
				}
			} else {
				if (yystack.l_mark[-1].v.redirection == NULL || yystack.l_mark[-1].v.redirection->host == NULL) {
					yyerror("translation rule requires '-> "
					    "address'");
					YYERROR;
				}
				if (!r.af && ! yystack.l_mark[-1].v.redirection->host->ifindex)
					r.af = yystack.l_mark[-1].v.redirection->host->af;

				remove_invalid_hosts(&yystack.l_mark[-1].v.redirection->host, &r.af);
				if (invalid_redirect(yystack.l_mark[-1].v.redirection->host, r.af))
					YYERROR;
				if (check_netmask(yystack.l_mark[-1].v.redirection->host, r.af))
					YYERROR;

				r.rpool.proxy_port[0] = ntohs(yystack.l_mark[-1].v.redirection->rport.a);

				switch (r.action) {
				case PF_RDR:
					if (!yystack.l_mark[-1].v.redirection->rport.b && yystack.l_mark[-1].v.redirection->rport.t &&
					    yystack.l_mark[-5].v.fromto.dst.port != NULL) {
						r.rpool.proxy_port[1] =
						    ntohs(yystack.l_mark[-1].v.redirection->rport.a) +
						    (ntohs(
						    yystack.l_mark[-5].v.fromto.dst.port->port[1]) -
						    ntohs(
						    yystack.l_mark[-5].v.fromto.dst.port->port[0]));
					} else
						r.rpool.proxy_port[1] =
						    ntohs(yystack.l_mark[-1].v.redirection->rport.b);
					break;
				case PF_NAT:
					r.rpool.proxy_port[1] =
					    ntohs(yystack.l_mark[-1].v.redirection->rport.b);
					if (!r.rpool.proxy_port[0] &&
					    !r.rpool.proxy_port[1]) {
						r.rpool.proxy_port[0] =
						    PF_NAT_PROXY_PORT_LOW;
						r.rpool.proxy_port[1] =
						    PF_NAT_PROXY_PORT_HIGH;
					} else if (!r.rpool.proxy_port[1])
						r.rpool.proxy_port[1] =
						    r.rpool.proxy_port[0];
					break;
				default:
					break;
				}

				r.rpool.opts = yystack.l_mark[0].v.pool_opts.type;
				if ((r.rpool.opts & PF_POOL_TYPEMASK) ==
				    PF_POOL_NONE && (yystack.l_mark[-1].v.redirection->host->next != NULL ||
				    yystack.l_mark[-1].v.redirection->host->addr.type == PF_ADDR_TABLE ||
				    DYNIF_MULTIADDR(yystack.l_mark[-1].v.redirection->host->addr)))
					r.rpool.opts = PF_POOL_ROUNDROBIN;
				if ((r.rpool.opts & PF_POOL_TYPEMASK) !=
				    PF_POOL_ROUNDROBIN &&
				    disallow_table(yystack.l_mark[-1].v.redirection->host, "tables are only "
				    "supported in round-robin redirection "
				    "pools"))
					YYERROR;
				if ((r.rpool.opts & PF_POOL_TYPEMASK) !=
				    PF_POOL_ROUNDROBIN &&
				    disallow_alias(yystack.l_mark[-1].v.redirection->host, "interface (%s) "
				    "is only supported in round-robin "
				    "redirection pools"))
					YYERROR;
				if (yystack.l_mark[-1].v.redirection->host->next != NULL) {
					if ((r.rpool.opts & PF_POOL_TYPEMASK) !=
					    PF_POOL_ROUNDROBIN) {
						yyerror("only round-robin "
						    "valid for multiple "
						    "redirection addresses");
						YYERROR;
					}
				}
			}

			if (yystack.l_mark[0].v.pool_opts.key != NULL)
				memcpy(&r.rpool.key, yystack.l_mark[0].v.pool_opts.key,
				    sizeof(struct pf_poolhashkey));

			 if (yystack.l_mark[0].v.pool_opts.opts)
				r.rpool.opts |= yystack.l_mark[0].v.pool_opts.opts;

			if (yystack.l_mark[0].v.pool_opts.staticport) {
				if (r.action != PF_NAT) {
					yyerror("the 'static-port' option is "
					    "only valid with nat rules");
					YYERROR;
				}
				if (r.rpool.proxy_port[0] !=
				    PF_NAT_PROXY_PORT_LOW &&
				    r.rpool.proxy_port[1] !=
				    PF_NAT_PROXY_PORT_HIGH) {
					yyerror("the 'static-port' option can't"
					    " be used when specifying a port"
					    " range");
					YYERROR;
				}
				r.rpool.proxy_port[0] = 0;
				r.rpool.proxy_port[1] = 0;
			}

			expand_rule(&r, yystack.l_mark[-8].v.interface, yystack.l_mark[-1].v.redirection == NULL ? NULL : yystack.l_mark[-1].v.redirection->host, yystack.l_mark[-6].v.proto,
			    yystack.l_mark[-5].v.fromto.src_os, yystack.l_mark[-5].v.fromto.src.host, yystack.l_mark[-5].v.fromto.src.port, yystack.l_mark[-5].v.fromto.dst.host,
			    yystack.l_mark[-5].v.fromto.dst.port, 0, 0, 0, "");
			free(yystack.l_mark[-1].v.redirection);
		}
break;
case 402:
#line 4111 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			struct pf_rule		binat;
			struct pf_pooladdr	*pa;

			if (check_rulestate(PFCTL_STATE_NAT))
				YYERROR;
			if (disallow_urpf_failed(yystack.l_mark[-4].v.host, "\"urpf-failed\" is not "
			    "permitted as a binat destination"))
				YYERROR;

			memset(&binat, 0, sizeof(binat));

			if (yystack.l_mark[-12].v.i && yystack.l_mark[-10].v.b.b1) {
				yyerror("\"pass\" not valid with \"no\"");
				YYERROR;
			}
			if (yystack.l_mark[-12].v.i)
				binat.action = PF_NOBINAT;
			else
				binat.action = PF_BINAT;
			binat.natpass = yystack.l_mark[-10].v.b.b1;
			binat.log = yystack.l_mark[-10].v.b.b2;
			binat.logif = yystack.l_mark[-10].v.b.w2;
			binat.af = yystack.l_mark[-8].v.i;
			if (!binat.af && yystack.l_mark[-5].v.host != NULL && yystack.l_mark[-5].v.host->af)
				binat.af = yystack.l_mark[-5].v.host->af;
			if (!binat.af && yystack.l_mark[-4].v.host != NULL && yystack.l_mark[-4].v.host->af)
				binat.af = yystack.l_mark[-4].v.host->af;

			if (!binat.af && yystack.l_mark[0].v.redirection != NULL && yystack.l_mark[0].v.redirection->host)
				binat.af = yystack.l_mark[0].v.redirection->host->af;
			if (!binat.af) {
				yyerror("address family (inet/inet6) "
				    "undefined");
				YYERROR;
			}

			if (yystack.l_mark[-9].v.interface != NULL) {
				memcpy(binat.ifname, yystack.l_mark[-9].v.interface->ifname,
				    sizeof(binat.ifname));
				binat.ifnot = yystack.l_mark[-9].v.interface->not;
				free(yystack.l_mark[-9].v.interface);
			}

			if (yystack.l_mark[-3].v.string != NULL)
				if (strlcpy(binat.tagname, yystack.l_mark[-3].v.string,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			if (yystack.l_mark[-2].v.tagged.name)
				if (strlcpy(binat.match_tagname, yystack.l_mark[-2].v.tagged.name,
				    PF_TAG_NAME_SIZE) >= PF_TAG_NAME_SIZE) {
					yyerror("tag too long, max %u chars",
					    PF_TAG_NAME_SIZE - 1);
					YYERROR;
				}
			binat.match_tag_not = yystack.l_mark[-2].v.tagged.neg;
			binat.rtableid = yystack.l_mark[-1].v.rtableid;

			if (yystack.l_mark[-7].v.proto != NULL) {
				binat.proto = yystack.l_mark[-7].v.proto->proto;
				free(yystack.l_mark[-7].v.proto);
			}

			if (yystack.l_mark[-5].v.host != NULL && disallow_table(yystack.l_mark[-5].v.host, "invalid use of "
			    "table <%s> as the source address of a binat rule"))
				YYERROR;
			if (yystack.l_mark[-5].v.host != NULL && disallow_alias(yystack.l_mark[-5].v.host, "invalid use of "
			    "interface (%s) as the source address of a binat "
			    "rule"))
				YYERROR;
			if (yystack.l_mark[0].v.redirection != NULL && yystack.l_mark[0].v.redirection->host != NULL && disallow_table(
			    yystack.l_mark[0].v.redirection->host, "invalid use of table <%s> as the "
			    "redirect address of a binat rule"))
				YYERROR;
			if (yystack.l_mark[0].v.redirection != NULL && yystack.l_mark[0].v.redirection->host != NULL && disallow_alias(
			    yystack.l_mark[0].v.redirection->host, "invalid use of interface (%s) as the "
			    "redirect address of a binat rule"))
				YYERROR;

			if (yystack.l_mark[-5].v.host != NULL) {
				if (yystack.l_mark[-5].v.host->next) {
					yyerror("multiple binat ip addresses");
					YYERROR;
				}
				if (yystack.l_mark[-5].v.host->addr.type == PF_ADDR_DYNIFTL)
					yystack.l_mark[-5].v.host->af = binat.af;
				if (yystack.l_mark[-5].v.host->af != binat.af) {
					yyerror("binat ip versions must match");
					YYERROR;
				}
				if (check_netmask(yystack.l_mark[-5].v.host, binat.af))
					YYERROR;
				memcpy(&binat.src.addr, &yystack.l_mark[-5].v.host->addr,
				    sizeof(binat.src.addr));
				free(yystack.l_mark[-5].v.host);
			}
			if (yystack.l_mark[-4].v.host != NULL) {
				if (yystack.l_mark[-4].v.host->next) {
					yyerror("multiple binat ip addresses");
					YYERROR;
				}
				if (yystack.l_mark[-4].v.host->af != binat.af && yystack.l_mark[-4].v.host->af) {
					yyerror("binat ip versions must match");
					YYERROR;
				}
				if (check_netmask(yystack.l_mark[-4].v.host, binat.af))
					YYERROR;
				memcpy(&binat.dst.addr, &yystack.l_mark[-4].v.host->addr,
				    sizeof(binat.dst.addr));
				binat.dst.neg = yystack.l_mark[-4].v.host->not;
				free(yystack.l_mark[-4].v.host);
			}

			if (binat.action == PF_NOBINAT) {
				if (yystack.l_mark[0].v.redirection != NULL) {
					yyerror("'no binat' rule does not need"
					    " '->'");
					YYERROR;
				}
			} else {
				if (yystack.l_mark[0].v.redirection == NULL || yystack.l_mark[0].v.redirection->host == NULL) {
					yyerror("'binat' rule requires"
					    " '-> address'");
					YYERROR;
				}

				remove_invalid_hosts(&yystack.l_mark[0].v.redirection->host, &binat.af);
				if (invalid_redirect(yystack.l_mark[0].v.redirection->host, binat.af))
					YYERROR;
				if (yystack.l_mark[0].v.redirection->host->next != NULL) {
					yyerror("binat rule must redirect to "
					    "a single address");
					YYERROR;
				}
				if (check_netmask(yystack.l_mark[0].v.redirection->host, binat.af))
					YYERROR;

				if (!PF_AZERO(&binat.src.addr.v.a.mask,
				    binat.af) &&
				    !PF_AEQ(&binat.src.addr.v.a.mask,
				    &yystack.l_mark[0].v.redirection->host->addr.v.a.mask, binat.af)) {
					yyerror("'binat' source mask and "
					    "redirect mask must be the same");
					YYERROR;
				}

				TAILQ_INIT(&binat.rpool.list);
				pa = calloc(1, sizeof(struct pf_pooladdr));
				if (pa == NULL)
					err(1, "binat: calloc");
				pa->addr = yystack.l_mark[0].v.redirection->host->addr;
				pa->ifname[0] = 0;
				TAILQ_INSERT_TAIL(&binat.rpool.list,
				    pa, entries);

				free(yystack.l_mark[0].v.redirection);
			}

			pfctl_add_rule(pf, &binat, "");
		}
break;
case 403:
#line 4276 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.string = NULL; }
break;
case 404:
#line 4277 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.string = yystack.l_mark[0].v.string; }
break;
case 405:
#line 4280 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.tagged.neg = 0; yyval.v.tagged.name = NULL; }
break;
case 406:
#line 4281 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.tagged.neg = yystack.l_mark[-2].v.number; yyval.v.tagged.name = yystack.l_mark[0].v.string; }
break;
case 407:
#line 4284 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.rtableid = -1; }
break;
case 408:
#line 4285 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > rt_tableid_max()) {
				yyerror("invalid rtable id");
				YYERROR;
			}
			yyval.v.rtableid = yystack.l_mark[0].v.number;
		}
break;
case 409:
#line 4294 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.host = calloc(1, sizeof(struct node_host));
			if (yyval.v.host == NULL)
				err(1, "route_host: calloc");
			yyval.v.host->ifname = yystack.l_mark[0].v.string;
			set_ipmask(yyval.v.host, 128);
			yyval.v.host->next = NULL;
			yyval.v.host->tail = yyval.v.host;
		}
break;
case 410:
#line 4303 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.host = yystack.l_mark[-1].v.host;
			yyval.v.host->ifname = yystack.l_mark[-2].v.string;
		}
break;
case 411:
#line 4309 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[-1].v.host; }
break;
case 412:
#line 4310 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (yystack.l_mark[-3].v.host->af == 0)
				yystack.l_mark[-3].v.host->af = yystack.l_mark[-1].v.host->af;
			if (yystack.l_mark[-3].v.host->af != yystack.l_mark[-1].v.host->af) {
				yyerror("all pool addresses must be in the "
				    "same address family");
				YYERROR;
			}
			yystack.l_mark[-3].v.host->tail->next = yystack.l_mark[-1].v.host;
			yystack.l_mark[-3].v.host->tail = yystack.l_mark[-1].v.host->tail;
			yyval.v.host = yystack.l_mark[-3].v.host;
		}
break;
case 413:
#line 4324 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[0].v.host; }
break;
case 414:
#line 4325 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.host = yystack.l_mark[-1].v.host; }
break;
case 415:
#line 4328 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.route.host = NULL;
			yyval.v.route.rt = 0;
			yyval.v.route.pool_opts = 0;
		}
break;
case 416:
#line 4333 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.route.host = NULL;
			yyval.v.route.rt = PF_FASTROUTE;
			yyval.v.route.pool_opts = 0;
		}
break;
case 417:
#line 4338 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.route.host = yystack.l_mark[-1].v.host;
			yyval.v.route.rt = PF_ROUTETO;
			yyval.v.route.pool_opts = yystack.l_mark[0].v.pool_opts.type | yystack.l_mark[0].v.pool_opts.opts;
			if (yystack.l_mark[0].v.pool_opts.key != NULL)
				yyval.v.route.key = yystack.l_mark[0].v.pool_opts.key;
		}
break;
case 418:
#line 4345 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.route.host = yystack.l_mark[-1].v.host;
			yyval.v.route.rt = PF_REPLYTO;
			yyval.v.route.pool_opts = yystack.l_mark[0].v.pool_opts.type | yystack.l_mark[0].v.pool_opts.opts;
			if (yystack.l_mark[0].v.pool_opts.key != NULL)
				yyval.v.route.key = yystack.l_mark[0].v.pool_opts.key;
		}
break;
case 419:
#line 4352 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			yyval.v.route.host = yystack.l_mark[-1].v.host;
			yyval.v.route.rt = PF_DUPTO;
			yyval.v.route.pool_opts = yystack.l_mark[0].v.pool_opts.type | yystack.l_mark[0].v.pool_opts.opts;
			if (yystack.l_mark[0].v.pool_opts.key != NULL)
				yyval.v.route.key = yystack.l_mark[0].v.pool_opts.key;
		}
break;
case 420:
#line 4362 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (check_rulestate(PFCTL_STATE_OPTION)) {
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			if (pfctl_set_timeout(pf, yystack.l_mark[-1].v.string, yystack.l_mark[0].v.number, 0) != 0) {
				yyerror("unknown timeout %s", yystack.l_mark[-1].v.string);
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			free(yystack.l_mark[-1].v.string);
		}
break;
case 423:
#line 4385 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (check_rulestate(PFCTL_STATE_OPTION)) {
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("only positive values permitted");
				YYERROR;
			}
			if (pfctl_set_limit(pf, yystack.l_mark[-1].v.string, yystack.l_mark[0].v.number) != 0) {
				yyerror("unable to set limit %s %u", yystack.l_mark[-1].v.string, yystack.l_mark[0].v.number);
				free(yystack.l_mark[-1].v.string);
				YYERROR;
			}
			free(yystack.l_mark[-1].v.string);
		}
break;
case 428:
#line 4411 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.number = 0; }
break;
case 429:
#line 4412 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{
			if (!strcmp(yystack.l_mark[0].v.string, "yes"))
				yyval.v.number = 1;
			else {
				yyerror("invalid value '%s', expected 'yes' "
				    "or 'no'", yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[0].v.string);
		}
break;
case 430:
#line 4425 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OP_EQ; }
break;
case 431:
#line 4426 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OP_NE; }
break;
case 432:
#line 4427 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OP_LE; }
break;
case 433:
#line 4428 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OP_LT; }
break;
case 434:
#line 4429 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OP_GE; }
break;
case 435:
#line 4430 "/usr/home/freebsd/omega/src/sbin/pfctl/parse.y"
	{ yyval.v.i = PF_OP_GT; }
break;
#line 8940 "parse.c"
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
