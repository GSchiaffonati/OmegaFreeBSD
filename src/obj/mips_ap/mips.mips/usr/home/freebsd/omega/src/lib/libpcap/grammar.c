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

#ifndef yyparse
#define yyparse    pcapyyparse
#endif /* yyparse */

#ifndef yylex
#define yylex      pcapyylex
#endif /* yylex */

#ifndef yyerror
#define yyerror    pcapyyerror
#endif /* yyerror */

#ifndef yychar
#define yychar     pcapyychar
#endif /* yychar */

#ifndef yyval
#define yyval      pcapyyval
#endif /* yyval */

#ifndef yylval
#define yylval     pcapyylval
#endif /* yylval */

#ifndef yydebug
#define yydebug    pcapyydebug
#endif /* yydebug */

#ifndef yynerrs
#define yynerrs    pcapyynerrs
#endif /* yynerrs */

#ifndef yyerrflag
#define yyerrflag  pcapyyerrflag
#endif /* yyerrflag */

#ifndef yylhs
#define yylhs      pcapyylhs
#endif /* yylhs */

#ifndef yylen
#define yylen      pcapyylen
#endif /* yylen */

#ifndef yydefred
#define yydefred   pcapyydefred
#endif /* yydefred */

#ifndef yydgoto
#define yydgoto    pcapyydgoto
#endif /* yydgoto */

#ifndef yysindex
#define yysindex   pcapyysindex
#endif /* yysindex */

#ifndef yyrindex
#define yyrindex   pcapyyrindex
#endif /* yyrindex */

#ifndef yygindex
#define yygindex   pcapyygindex
#endif /* yygindex */

#ifndef yytable
#define yytable    pcapyytable
#endif /* yytable */

#ifndef yycheck
#define yycheck    pcapyycheck
#endif /* yycheck */

#ifndef yyname
#define yyname     pcapyyname
#endif /* yyname */

#ifndef yyrule
#define yyrule     pcapyyrule
#endif /* yyrule */
#define YYPREFIX "pcapyy"

#define YYPURE 0

#line 2 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
/*
 * Copyright (c) 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that: (1) source code distributions
 * retain the above copyright notice and this paragraph in its entirety, (2)
 * distributions including binary code include the above copyright notice and
 * this paragraph in its entirety in the documentation or other materials
 * provided with the distribution, and (3) all advertising materials mentioning
 * features or use of this software display the following acknowledgement:
 * ``This product includes software developed by the University of California,
 * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of
 * the University nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior
 * written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * $FreeBSD$
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef WIN32
#include <pcap-stdinc.h>
#else /* WIN32 */
#include <sys/types.h>
#include <sys/socket.h>
#endif /* WIN32 */

#include <stdlib.h>

#ifndef WIN32
#if __STDC__
struct mbuf;
struct rtentry;
#endif

#include <netinet/in.h>
#include <arpa/inet.h>
#endif /* WIN32 */

#include <stdio.h>

#include "pcap-int.h"

#include "gencode.h"
#ifdef HAVE_NET_PFVAR_H
#include <net/if.h>
#include <netpfil/pf/pf.h>
#include <net/if_pflog.h>
#endif
#include "llc.h"
#include "ieee80211.h"
#include <pcap/namedb.h>

#ifdef HAVE_OS_PROTO_H
#include "os-proto.h"
#endif

#define QSET(q, p, d, a) (q).proto = (p),\
			 (q).dir = (d),\
			 (q).addr = (a)

struct tok {
	int v;			/* value */
	const char *s;		/* string */
};

static const struct tok ieee80211_types[] = {
	{ IEEE80211_FC0_TYPE_DATA, "data" },
	{ IEEE80211_FC0_TYPE_MGT, "mgt" },
	{ IEEE80211_FC0_TYPE_MGT, "management" },
	{ IEEE80211_FC0_TYPE_CTL, "ctl" },
	{ IEEE80211_FC0_TYPE_CTL, "control" },
	{ 0, NULL }
};
static const struct tok ieee80211_mgt_subtypes[] = {
	{ IEEE80211_FC0_SUBTYPE_ASSOC_REQ, "assocreq" },
	{ IEEE80211_FC0_SUBTYPE_ASSOC_REQ, "assoc-req" },
	{ IEEE80211_FC0_SUBTYPE_ASSOC_RESP, "assocresp" },
	{ IEEE80211_FC0_SUBTYPE_ASSOC_RESP, "assoc-resp" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_REQ, "reassocreq" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_REQ, "reassoc-req" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_RESP, "reassocresp" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_RESP, "reassoc-resp" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_REQ, "probereq" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_REQ, "probe-req" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_RESP, "proberesp" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_RESP, "probe-resp" },
	{ IEEE80211_FC0_SUBTYPE_BEACON, "beacon" },
	{ IEEE80211_FC0_SUBTYPE_ATIM, "atim" },
	{ IEEE80211_FC0_SUBTYPE_DISASSOC, "disassoc" },
	{ IEEE80211_FC0_SUBTYPE_DISASSOC, "disassociation" },
	{ IEEE80211_FC0_SUBTYPE_AUTH, "auth" },
	{ IEEE80211_FC0_SUBTYPE_AUTH, "authentication" },
	{ IEEE80211_FC0_SUBTYPE_DEAUTH, "deauth" },
	{ IEEE80211_FC0_SUBTYPE_DEAUTH, "deauthentication" },
	{ 0, NULL }
};
static const struct tok ieee80211_ctl_subtypes[] = {
	{ IEEE80211_FC0_SUBTYPE_PS_POLL, "ps-poll" },
	{ IEEE80211_FC0_SUBTYPE_RTS, "rts" },
	{ IEEE80211_FC0_SUBTYPE_CTS, "cts" },
	{ IEEE80211_FC0_SUBTYPE_ACK, "ack" },
	{ IEEE80211_FC0_SUBTYPE_CF_END, "cf-end" },
	{ IEEE80211_FC0_SUBTYPE_CF_END_ACK, "cf-end-ack" },
	{ 0, NULL }
};
static const struct tok ieee80211_data_subtypes[] = {
	{ IEEE80211_FC0_SUBTYPE_DATA, "data" },
	{ IEEE80211_FC0_SUBTYPE_CF_ACK, "data-cf-ack" },
	{ IEEE80211_FC0_SUBTYPE_CF_POLL, "data-cf-poll" },
	{ IEEE80211_FC0_SUBTYPE_CF_ACPL, "data-cf-ack-poll" },
	{ IEEE80211_FC0_SUBTYPE_NODATA, "null" },
	{ IEEE80211_FC0_SUBTYPE_NODATA_CF_ACK, "cf-ack" },
	{ IEEE80211_FC0_SUBTYPE_NODATA_CF_POLL, "cf-poll"  },
	{ IEEE80211_FC0_SUBTYPE_NODATA_CF_ACPL, "cf-ack-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_DATA, "qos-data" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_CF_ACK, "qos-data-cf-ack" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_CF_POLL, "qos-data-cf-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_CF_ACPL, "qos-data-cf-ack-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_NODATA, "qos" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_NODATA_CF_POLL, "qos-cf-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_NODATA_CF_ACPL, "qos-cf-ack-poll" },
	{ 0, NULL }
};
static const struct tok llc_s_subtypes[] = {
	{ LLC_RR, "rr" },
	{ LLC_RNR, "rnr" },
	{ LLC_REJ, "rej" },
	{ 0, NULL }
};
static const struct tok llc_u_subtypes[] = {
	{ LLC_UI, "ui" },
	{ LLC_UA, "ua" },
	{ LLC_DISC, "disc" },
	{ LLC_DM, "dm" },
	{ LLC_SABME, "sabme" },
	{ LLC_TEST, "test" },
	{ LLC_XID, "xid" },
	{ LLC_FRMR, "frmr" },
	{ 0, NULL }
};
struct type2tok {
	int type;
	const struct tok *tok;
};
static const struct type2tok ieee80211_type_subtypes[] = {
	{ IEEE80211_FC0_TYPE_MGT, ieee80211_mgt_subtypes },
	{ IEEE80211_FC0_TYPE_CTL, ieee80211_ctl_subtypes },
	{ IEEE80211_FC0_TYPE_DATA, ieee80211_data_subtypes },
	{ 0, NULL }
};

static int
str2tok(const char *str, const struct tok *toks)
{
	int i;

	for (i = 0; toks[i].s != NULL; i++) {
		if (pcap_strcasecmp(toks[i].s, str) == 0)
			return (toks[i].v);
	}
	return (-1);
}

int n_errors = 0;

static struct qual qerr = { Q_UNDEF, Q_UNDEF, Q_UNDEF, Q_UNDEF };

static void
yyerror(const char *msg)
{
	++n_errors;
	bpf_error("%s", msg);
	/* NOTREACHED */
}

#ifdef NEED_YYPARSE_WRAPPER
int yyparse(void);

int
pcap_parse()
{
	return (yyparse());
}
#endif

#ifdef HAVE_NET_PFVAR_H
static int
pfreason_to_num(const char *reason)
{
	const char *reasons[] = PFRES_NAMES;
	int i;

	for (i = 0; reasons[i]; i++) {
		if (pcap_strcasecmp(reason, reasons[i]) == 0)
			return (i);
	}
	bpf_error("unknown PF reason");
	/*NOTREACHED*/
}

static int
pfaction_to_num(const char *action)
{
	if (pcap_strcasecmp(action, "pass") == 0 ||
	    pcap_strcasecmp(action, "accept") == 0)
		return (PF_PASS);
	else if (pcap_strcasecmp(action, "drop") == 0 ||
		pcap_strcasecmp(action, "block") == 0)
		return (PF_DROP);
#if HAVE_PF_NAT_THROUGH_PF_NORDR
	else if (pcap_strcasecmp(action, "rdr") == 0)
		return (PF_RDR);
	else if (pcap_strcasecmp(action, "nat") == 0)
		return (PF_NAT);
	else if (pcap_strcasecmp(action, "binat") == 0)
		return (PF_BINAT);
	else if (pcap_strcasecmp(action, "nordr") == 0)
		return (PF_NORDR);
#endif
	else {
		bpf_error("unknown PF action");
		/*NOTREACHED*/
	}
}
#else /* !HAVE_NET_PFVAR_H */
static int
pfreason_to_num(const char *reason)
{
	bpf_error("libpcap was compiled on a machine without pf support");
	/*NOTREACHED*/

	/* this is to make the VC compiler happy */
	return -1;
}

static int
pfaction_to_num(const char *action)
{
	bpf_error("libpcap was compiled on a machine without pf support");
	/*NOTREACHED*/

	/* this is to make the VC compiler happy */
	return -1;
}
#endif /* HAVE_NET_PFVAR_H */
#line 257 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;
	bpf_u_int32 h;
	u_char *e;
	char *s;
	struct stmt *stmt;
	struct arth *a;
	struct {
		struct qual q;
		int atmfieldtype;
		int mtp3fieldtype;
		struct block *b;
	} blk;
	struct block *rblk;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 378 "grammar.c"

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

#define DST 257
#define SRC 258
#define HOST 259
#define GATEWAY 260
#define NET 261
#define NETMASK 262
#define PORT 263
#define PORTRANGE 264
#define LESS 265
#define GREATER 266
#define PROTO 267
#define PROTOCHAIN 268
#define CBYTE 269
#define ARP 270
#define RARP 271
#define IP 272
#define SCTP 273
#define TCP 274
#define UDP 275
#define ICMP 276
#define IGMP 277
#define IGRP 278
#define PIM 279
#define VRRP 280
#define CARP 281
#define ATALK 282
#define AARP 283
#define DECNET 284
#define LAT 285
#define SCA 286
#define MOPRC 287
#define MOPDL 288
#define TK_BROADCAST 289
#define TK_MULTICAST 290
#define NUM 291
#define INBOUND 292
#define OUTBOUND 293
#define PF_IFNAME 294
#define PF_RSET 295
#define PF_RNR 296
#define PF_SRNR 297
#define PF_REASON 298
#define PF_ACTION 299
#define TYPE 300
#define SUBTYPE 301
#define DIR 302
#define ADDR1 303
#define ADDR2 304
#define ADDR3 305
#define ADDR4 306
#define RA 307
#define TA 308
#define LINK 309
#define GEQ 310
#define LEQ 311
#define NEQ 312
#define ID 313
#define EID 314
#define HID 315
#define HID6 316
#define AID 317
#define LSH 318
#define RSH 319
#define LEN 320
#define IPV6 321
#define ICMPV6 322
#define AH 323
#define ESP 324
#define VLAN 325
#define MPLS 326
#define PPPOED 327
#define PPPOES 328
#define ISO 329
#define ESIS 330
#define CLNP 331
#define ISIS 332
#define L1 333
#define L2 334
#define IIH 335
#define LSP 336
#define SNP 337
#define CSNP 338
#define PSNP 339
#define STP 340
#define IPX 341
#define NETBEUI 342
#define LANE 343
#define LLC 344
#define METAC 345
#define BCC 346
#define SC 347
#define ILMIC 348
#define OAMF4EC 349
#define OAMF4SC 350
#define OAM 351
#define OAMF4 352
#define CONNECTMSG 353
#define METACONNECT 354
#define VPI 355
#define VCI 356
#define RADIO 357
#define FISU 358
#define LSSU 359
#define MSU 360
#define HFISU 361
#define HLSSU 362
#define HMSU 363
#define SIO 364
#define OPC 365
#define DPC 366
#define SLS 367
#define HSIO 368
#define HOPC 369
#define HDPC 370
#define HSLS 371
#define OR 372
#define AND 373
#define UMINUS 374
#define YYERRCODE 256
typedef int YYINT;
static const YYINT pcapyylhs[] = {                       -1,
    0,    0,   24,    1,    1,    1,    1,    1,   20,   21,
    2,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,   23,   22,    4,    4,    4,    7,    7,    5,
    5,    8,    8,    8,    8,    8,    8,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    9,    9,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   11,   11,   11,   11,   12,   16,   16,   16,
   16,   16,   16,   16,   16,   16,   16,   16,   16,   16,
   16,   16,   16,   16,   16,   16,   16,   16,   16,   16,
   16,   16,   16,   16,   16,   16,   16,   16,   16,   16,
   16,   16,   16,   16,   16,   16,   25,   25,   25,   25,
   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,
   25,   25,   25,   26,   26,   26,   26,   26,   26,   27,
   27,   27,   27,   42,   42,   43,   43,   44,   28,   28,
   28,   45,   45,   41,   41,   40,   18,   18,   18,   19,
   19,   19,   13,   13,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   15,
   15,   15,   15,   15,   17,   17,   29,   29,   29,   29,
   29,   29,   29,   30,   30,   30,   30,   31,   31,   33,
   33,   33,   33,   32,   34,   34,   35,   35,   35,   35,
   35,   35,   36,   36,   36,   36,   36,   36,   36,   36,
   38,   38,   38,   38,   37,   39,   39,
};
static const YYINT pcapyylen[] = {                        2,
    2,    1,    0,    1,    3,    3,    3,    3,    1,    1,
    1,    1,    3,    1,    3,    3,    1,    3,    1,    1,
    1,    2,    1,    1,    1,    3,    3,    1,    1,    1,
    2,    3,    2,    2,    2,    2,    2,    2,    3,    1,
    3,    3,    1,    1,    1,    2,    1,    2,    1,    0,
    1,    1,    3,    3,    3,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    2,    2,    2,
    4,    1,    1,    2,    1,    2,    1,    1,    2,    1,
    1,    2,    1,    2,    2,    2,    2,    2,    2,    4,
    2,    2,    2,    1,    1,    1,    1,    1,    1,    2,
    2,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    4,    6,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    3,    1,    1,
    1,    1,    1,    1,    1,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    2,    2,    3,    1,    1,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    2,    2,    3,    1,    1,    3,
};
static const YYINT pcapyydefred[] = {                     3,
    0,    0,    0,    0,    0,   70,   71,   69,   72,   73,
   74,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,   85,   87,   86,  175,  112,  113,    0,    0,    0,
    0,    0,    0,   68,  169,   88,   89,   90,   91,    0,
    0,  118,    0,   92,   93,  102,   94,   95,   96,   97,
   98,   99,  101,  100,  103,  104,  105,  177,    0,  178,
  179,  182,  183,  180,  181,  184,  185,  186,  187,  188,
  189,  106,  197,  198,  199,  200,  201,  202,  203,  204,
  205,  206,  207,  208,  209,  210,   23,    0,   24,    0,
    4,   30,    0,    0,    0,  154,    0,  153,    0,    0,
   43,  121,  123,   44,   45,    0,   47,    0,  109,  110,
    0,  124,  125,  126,  127,  144,  145,  128,  146,  129,
  114,    0,  116,  119,  141,  140,    0,    0,    0,   10,
    9,    0,    0,   14,   20,    0,    0,   21,   38,   11,
   12,    0,    0,    0,    0,   63,   67,   64,   65,   66,
   35,   36,  107,  108,    0,    0,    0,   57,   58,   59,
   60,   61,   62,    0,   34,   37,  122,  148,  150,  152,
    0,    0,    0,    0,    0,    0,    0,    0,  147,  149,
  151,    0,    0,    0,    0,    0,    0,    0,    0,   31,
  194,    0,    0,    0,  190,   46,  215,    0,    0,    0,
  211,   48,  171,  170,  173,  174,  172,    0,    0,    0,
    6,    5,    0,    0,    0,    8,    7,    0,    0,    0,
   25,    0,    0,    0,   22,    0,    0,    0,    0,  134,
  135,    0,  138,  132,  142,  143,  133,   32,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   39,  168,  176,  191,  192,  195,    0,  212,  213,
  216,    0,  111,    0,   16,   15,   18,   13,    0,    0,
   54,   56,   53,   55,    0,  155,    0,  193,    0,  214,
    0,   26,   27,  136,  137,  130,    0,  196,  217,  156,
};
static const YYINT pcapyydgoto[] = {                      1,
  187,  225,  140,  222,   91,   92,  223,   93,   94,  164,
  165,  166,   95,   96,  208,  128,   98,  184,  185,  132,
  133,  129,  143,    2,  101,  102,  167,  103,  104,  105,
  106,  195,  196,  258,  107,  108,  201,  202,  262,  120,
  118,  232,  286,  234,  237,
};
static const YYINT pcapyysindex[] = {                     0,
    0,  408, -278, -271, -265,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -282, -246, -221,
 -212, -289, -216,    0,    0,    0,    0,    0,    0,  -24,
  -24,    0,  -24,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -275,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  631,    0, -259,
    0,    0,  -21,  897,  826,    0,   14,    0,  408,  408,
    0,    0,    0,    0,    0,  153,    0,  758,    0,    0,
  219,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -24,    0,    0,    0,    0,  -14,   14,  631,    0,
    0,  299,  299,    0,    0,  -36,   61,    0,    0,    0,
    0,  -21,  -21, -244, -242,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -286, -175, -277,    0,    0,    0,
    0,    0,    0,  -86,    0,    0,    0,    0,    0,    0,
  631,  631,  631,  631,  631,  631,  631,  631,    0,    0,
    0,  631,  631,  631,  631,  631,  -37,  102,  106,    0,
    0, -141, -135, -128,    0,    0,    0, -122, -115, -102,
    0,    0,    0,    0,    0,    0,    0, -100,  106,  159,
    0,    0,    0,  299,  299,    0,    0, -149,  -96,  -91,
    0,  164, -259,  106,    0,  -46,  -33,  -35,  -28,    0,
    0,  -80,    0,    0,    0,    0,    0,    0,  325,  325,
  505,   -8,  438,  438,  -14,  -14,  159,  159,  159,  159,
  465,    0,    0,    0,    0,    0,    0,  -41,    0,    0,
    0,  -34,    0,  106,    0,    0,    0,    0,  -21,  -21,
    0,    0,    0,    0, -258,    0,  -61,    0, -128,    0,
 -102,    0,    0,    0,    0,    0,  138,    0,    0,    0,
};
static const YYINT pcapyyrindex[] = {                     0,
    0,  549,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    6,
    8,    0,   10,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   18,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  232,
    0,    0,    0,    0,    0,    0,    1,    0,  921,  921,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    0,    0,    0,
    0,  921,  921,    0,    0,   25,   28,    0,    0,    0,
    0,    0,    0,  567,  683,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  141,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  896,  942,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   15,  921,  921,    0,    0,    0,    0,    0,
    0, -227,    0, -193,    0,    0,    0,    0,    0,    0,
    0,   32,    0,    0,    0,    0,    0,    0,   30,  124,
  158,  149,   99,  110,   40,   74,  183,  194,   43,   54,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  743,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT pcapyygindex[] = {                     0,
  231,   95, -125,    0,   -7,    0,    0,    0,    0,    0,
   72,    0,  857,   23,    0,  139,  883,   -2,   12,   17,
 -151,  981,  387,    0,    0,    0,    0,    0,    0,    0,
    0, -185,    0,    0,    0,    0, -178,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1261
static const YYINT pcapyytable[] = {                    278,
   40,  116,  167,  252,  230,  115,  280,  117,  257,  120,
  219,   87,  109,  235,   12,   89,  221,  139,   89,  110,
  125,  261,  182,  117,   17,  111,  231,   19,  182,  165,
  112,  131,  284,  177,  175,  236,  176,  126,  178,  159,
  167,   40,   41,  167,  167,  167,  115,  167,  117,  167,
  120,  153,  153,   42,  285,   12,  153,  153,  139,  153,
  167,  153,  167,  167,  167,   17,  113,  165,   19,  114,
  165,  270,  131,  160,  153,  153,  153,  159,  115,  183,
  159,  159,  159,   41,  159,  183,  159,  165,  221,  165,
  165,  165,  190,  288,   42,  167,  119,  159,  157,  159,
  159,  159,  289,  192,  186,  198,  279,  220,  153,  158,
  281,  160,  130,  131,  160,  160,  160,  193,  160,  199,
  160,  188,  165,  166,  212,  217,  167,  226,  227,  228,
  229,  160,  159,  160,  160,  160,  157,  233,  153,  157,
   97,  157,  253,  157,   29,   29,  254,  158,  162,  255,
  158,  188,  158,  165,  158,  256,  157,  163,  157,  157,
  157,  166,  191,  159,  166,  265,  160,  158,  259,  158,
  158,  158,  146,   33,  148,  260,  149,  150,   28,   28,
   33,  166,  161,  166,  166,  166,  162,  139,  197,  162,
  263,  157,   89,  164,  266,  182,  174,  160,  163,  267,
  177,  175,  158,  176,  268,  178,  162,  190,  162,  162,
  162,  271,  181,  180,  179,  163,  166,  163,  163,  163,
  275,  273,  157,  161,  272,  218,  211,  216,  274,  287,
  290,    1,   90,  158,  164,  238,  188,   97,   97,  269,
  161,  162,  161,  161,  161,    0,    0,  166,    0,    0,
  163,  164,  183,  164,  164,  164,  204,   49,   49,   49,
   49,   49,    0,   49,   49,    0,   25,   49,   49,   25,
   97,   97,  162,    0,    0,  161,    0,    0,  207,  206,
  205,  163,  173,    0,    0,    0,  164,    0,    0,   49,
   49,  134,  135,  136,  137,  138,    0,    0,    0,    0,
   49,   49,   49,   49,   49,   49,   49,   49,   49,  171,
  172,    0,  167,  167,  167,    0,    0,    0,    0,    0,
  167,  167,    0,    0,  153,  153,  153,    0,    0,    0,
  130,   87,  153,  153,  130,  131,    0,  130,   89,  165,
  165,  165,  203,   88,    0,    0,    0,  165,  165,  159,
  159,  159,   97,   97,    0,    0,    0,  159,  159,    0,
    0,  182,    0,  282,  283,    0,  177,  175,    0,  176,
    0,  178,   40,   40,  167,  167,    0,  115,  115,  117,
  117,  120,  120,  160,  160,  160,   12,   12,  100,  139,
  139,  160,  160,    0,    0,    0,   17,   17,    0,   19,
   19,  165,  165,  131,  131,    0,    0,    0,  157,  157,
  157,  159,  159,    0,   41,   41,  157,  157,  183,  158,
  158,  158,    0,    0,    0,   42,   42,  158,  158,    0,
    0,   33,    0,  166,  166,  166,    0,    0,    0,    0,
   87,  166,  166,  191,    0,  160,  160,   89,    0,    0,
    0,    0,   88,   33,   33,   33,   33,   33,  162,  162,
  162,    0,  168,  169,  170,    0,    0,  163,  163,  163,
  157,  157,    0,    0,  182,    0,  171,  172,    0,  177,
    0,  158,  158,    0,  178,  100,  100,    0,    0,    0,
    0,    0,  161,  161,  161,  166,  166,    0,    0,    0,
    0,  182,  174,  164,  164,  164,  177,  175,    0,  176,
    0,  178,    0,    0,    0,    0,    0,    0,  215,  215,
  162,  162,  277,    0,    0,    0,    0,    0,    0,  163,
  163,  183,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  182,  174,    0,    0,    0,  177,  175,    2,  176,
    0,  178,    0,    0,  161,  161,    0,  276,  183,    0,
    0,    0,    0,    3,    4,  164,  164,    5,    6,    7,
    8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
   18,   19,   20,   21,   22,   23,   24,    0,  173,   25,
   26,   27,   28,   29,   30,   31,   32,   33,  183,   52,
  215,  215,    0,    0,    0,    0,   52,   34,    0,    0,
    0,  134,  135,  136,  137,  138,    0,    0,   35,   36,
   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,
   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,
   57,   58,   59,   60,   61,   62,   63,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,
   77,   78,   79,   80,   81,   82,   83,   84,   85,   86,
   89,    0,    3,    4,    0,   88,    5,    6,    7,    8,
    9,   10,   11,   12,   13,   14,   15,   16,   17,   18,
   19,   20,   21,   22,   23,   24,    0,    0,   25,   26,
   27,   28,   29,   30,   31,   32,   33,    0,    0,    0,
    0,    0,    0,    0,    0,   51,   34,    0,    0,    0,
    0,    0,   51,    0,    0,    0,    0,   35,   36,   37,
   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,
   58,   59,   60,   61,   62,   63,   64,   65,   66,   67,
   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
   78,   79,   80,   81,   82,   83,   84,   85,   86,  153,
  153,    0,  171,  172,  153,  153,    0,  153,    0,  153,
    0,    0,    0,    0,    0,    0,    0,   89,    0,    0,
    0,    0,  153,  153,  153,   50,   50,   50,   50,   50,
    0,   50,   50,    0,    0,   50,   50,  181,  180,  179,
    0,    0,  171,  172,    0,   52,    0,   52,    0,   52,
   52,    0,    0,    0,    0,    0,  153,   50,   50,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   50,   50,
   50,   50,   50,   50,   50,   50,   50,   52,    0,    0,
    0,    0,  182,  174,    0,    0,  153,  177,  175,    0,
  176,    0,  178,    0,    0,    0,    0,    0,    0,   52,
   52,   52,   52,   52,    0,  181,  180,  179,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
   16,   17,   18,   19,   20,   21,   22,   23,   24,  183,
    0,   25,  121,  123,    0,  124,    0,    0,    0,    0,
    0,    0,  154,  154,    0,    0,    0,  154,  154,   34,
  154,   51,  154,   51,  127,   51,   51,    0,    0,  173,
   35,   36,   37,   38,   39,  154,  154,  154,    0,   44,
   45,   46,   47,   48,   49,   50,   51,   52,   53,   54,
   55,   56,   57,   51,    0,  141,    0,    0,  153,  153,
    0,  189,   99,  153,  153,  210,  153,   72,  153,  154,
    0,    0,    0,    0,    0,   51,   51,   51,   51,   51,
    0,  153,  153,  153,  209,    0,    0,    0,    0,    0,
    0,  189,    0,    0,  213,  213,    0,    0,    0,  154,
  122,  122,    0,  122,  224,  141,    0,  239,  240,  241,
  242,  243,  244,  245,  246,  153,    0,    0,  247,  248,
  249,  250,  251,    0,    0,    0,    0,    0,  197,    0,
    0,    0,  153,  153,  153,    0,    0,    0,    0,    0,
  153,  153,    0,    0,    0,  153,    0,  168,  169,  170,
    0,    0,    0,  142,    0,    0,    0,    0,    0,   99,
   99,    0,    0,    0,    0,    0,  194,    0,  200,    0,
    0,    0,    0,    0,    0,    0,  264,  213,    0,    0,
    0,    0,  122,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  214,  214,   28,   28,    0,    0,    0,    0,
    0,    0,  122,  142,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  168,  169,  170,    0,    0,
    0,    0,    0,  171,  172,    0,    0,    0,    0,    0,
    0,  141,  141,  144,  145,  146,  147,  148,    0,  149,
  150,    0,    0,  151,  152,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   50,   50,   50,
   50,   50,    0,   50,   50,  153,  154,   50,   50,    0,
    0,    0,    0,    0,   99,  214,  155,  156,  157,  158,
  159,  160,  161,  162,  163,  154,  154,  154,    0,   50,
   50,    0,    0,  154,  154,    0,    0,    0,    0,    0,
   50,   50,   50,   50,   50,   50,   50,   50,   50,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  142,
  142,  153,  153,  153,    0,    0,    0,    0,    0,  153,
  153,
};
static const YYINT pcapyycheck[] = {                     41,
    0,  291,    0,   41,  291,    0,   41,    0,  194,    0,
   47,   33,  291,  291,    0,   40,  142,    0,   40,  291,
  296,  200,   37,  313,    0,  291,  313,    0,   37,    0,
  313,    0,  291,   42,   43,  313,   45,  313,   47,    0,
   38,   41,    0,   41,   42,   43,   41,   45,   41,   47,
   41,   37,   38,    0,  313,   41,   42,   43,   41,   45,
   58,   47,   60,   61,   62,   41,  313,   38,   41,  291,
   41,  223,   41,    0,   60,   61,   62,   38,  291,   94,
   41,   42,   43,   41,   45,   94,   47,   58,  214,   60,
   61,   62,  100,  279,   41,   93,  313,   58,    0,   60,
   61,   62,  281,  106,   91,  108,  258,   47,   94,    0,
  262,   38,  372,  373,   41,   42,   43,  106,   45,  108,
   47,   99,   93,    0,  132,  133,  124,  372,  373,  372,
  373,   58,   93,   60,   61,   62,   38,  313,  124,   41,
    2,   43,   41,   45,  372,  373,   41,   38,    0,  291,
   41,  129,   43,  124,   45,  291,   58,    0,   60,   61,
   62,   38,  291,  124,   41,  315,   93,   58,  291,   60,
   61,   62,  259,   33,  261,  291,  263,  264,  372,  373,
   40,   58,    0,   60,   61,   62,   38,   93,  291,   41,
  291,   93,   40,    0,  291,   37,   38,  124,   41,  291,
   42,   43,   93,   45,   41,   47,   58,  215,   60,   61,
   62,  258,   60,   61,   62,   58,   93,   60,   61,   62,
  301,  257,  124,   41,  258,  262,  132,  133,  257,  291,
   93,    0,    2,  124,   41,  164,  214,   99,  100,  223,
   58,   93,   60,   61,   62,   -1,   -1,  124,   -1,   -1,
   93,   58,   94,   60,   61,   62,   38,  257,  258,  259,
  260,  261,   -1,  263,  264,   -1,  291,  267,  268,  291,
  132,  133,  124,   -1,   -1,   93,   -1,   -1,   60,   61,
   62,  124,  124,   -1,   -1,   -1,   93,   -1,   -1,  289,
  290,  313,  314,  315,  316,  317,   -1,   -1,   -1,   -1,
  300,  301,  302,  303,  304,  305,  306,  307,  308,  318,
  319,   -1,  310,  311,  312,   -1,   -1,   -1,   -1,   -1,
  318,  319,   -1,   -1,  310,  311,  312,   -1,   -1,   -1,
  372,   33,  318,  319,  372,  373,   -1,  372,   40,  310,
  311,  312,  124,   45,   -1,   -1,   -1,  318,  319,  310,
  311,  312,  214,  215,   -1,   -1,   -1,  318,  319,   -1,
   -1,   37,   -1,  269,  270,   -1,   42,   43,   -1,   45,
   -1,   47,  372,  373,  372,  373,   -1,  372,  373,  372,
  373,  372,  373,  310,  311,  312,  372,  373,    2,  372,
  373,  318,  319,   -1,   -1,   -1,  372,  373,   -1,  372,
  373,  372,  373,  372,  373,   -1,   -1,   -1,  310,  311,
  312,  372,  373,   -1,  372,  373,  318,  319,   94,  310,
  311,  312,   -1,   -1,   -1,  372,  373,  318,  319,   -1,
   -1,  291,   -1,  310,  311,  312,   -1,   -1,   -1,   -1,
   33,  318,  319,  291,   -1,  372,  373,   40,   -1,   -1,
   -1,   -1,   45,  313,  314,  315,  316,  317,  310,  311,
  312,   -1,  310,  311,  312,   -1,   -1,  310,  311,  312,
  372,  373,   -1,   -1,   37,   -1,  318,  319,   -1,   42,
   -1,  372,  373,   -1,   47,   99,  100,   -1,   -1,   -1,
   -1,   -1,  310,  311,  312,  372,  373,   -1,   -1,   -1,
   -1,   37,   38,  310,  311,  312,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,  132,  133,
  372,  373,   58,   -1,   -1,   -1,   -1,   -1,   -1,  372,
  373,   94,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   37,   38,   -1,   -1,   -1,   42,   43,    0,   45,
   -1,   47,   -1,   -1,  372,  373,   -1,   93,   94,   -1,
   -1,   -1,   -1,  265,  266,  372,  373,  269,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  285,  286,  287,  288,   -1,  124,  291,
  292,  293,  294,  295,  296,  297,  298,  299,   94,   33,
  214,  215,   -1,   -1,   -1,   -1,   40,  309,   -1,   -1,
   -1,  313,  314,  315,  316,  317,   -1,   -1,  320,  321,
  322,  323,  324,  325,  326,  327,  328,  329,  330,  331,
  332,  333,  334,  335,  336,  337,  338,  339,  340,  341,
  342,  343,  344,  345,  346,  347,  348,  349,  350,  351,
  352,  353,  354,  355,  356,  357,  358,  359,  360,  361,
  362,  363,  364,  365,  366,  367,  368,  369,  370,  371,
   40,   -1,  265,  266,   -1,   45,  269,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  284,  285,  286,  287,  288,   -1,   -1,  291,  292,
  293,  294,  295,  296,  297,  298,  299,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   33,  309,   -1,   -1,   -1,
   -1,   -1,   40,   -1,   -1,   -1,   -1,  320,  321,  322,
  323,  324,  325,  326,  327,  328,  329,  330,  331,  332,
  333,  334,  335,  336,  337,  338,  339,  340,  341,  342,
  343,  344,  345,  346,  347,  348,  349,  350,  351,  352,
  353,  354,  355,  356,  357,  358,  359,  360,  361,  362,
  363,  364,  365,  366,  367,  368,  369,  370,  371,   37,
   38,   -1,  318,  319,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,
   -1,   -1,   60,   61,   62,  257,  258,  259,  260,  261,
   -1,  263,  264,   -1,   -1,  267,  268,   60,   61,   62,
   -1,   -1,  318,  319,   -1,  259,   -1,  261,   -1,  263,
  264,   -1,   -1,   -1,   -1,   -1,   94,  289,  290,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  300,  301,
  302,  303,  304,  305,  306,  307,  308,  291,   -1,   -1,
   -1,   -1,   37,   38,   -1,   -1,  124,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,  313,
  314,  315,  316,  317,   -1,   60,   61,   62,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  280,  281,  282,  283,  284,  285,  286,  287,  288,   94,
   -1,  291,   40,   41,   -1,   43,   -1,   -1,   -1,   -1,
   -1,   -1,   37,   38,   -1,   -1,   -1,   42,   43,  309,
   45,  259,   47,  261,   88,  263,  264,   -1,   -1,  124,
  320,  321,  322,  323,  324,   60,   61,   62,   -1,  329,
  330,  331,  332,  333,  334,  335,  336,  337,  338,  339,
  340,  341,  342,  291,   -1,   93,   -1,   -1,   37,   38,
   -1,   99,    2,   42,   43,  129,   45,  357,   47,   94,
   -1,   -1,   -1,   -1,   -1,  313,  314,  315,  316,  317,
   -1,   60,   61,   62,  122,   -1,   -1,   -1,   -1,   -1,
   -1,  129,   -1,   -1,  132,  133,   -1,   -1,   -1,  124,
   40,   41,   -1,   43,  142,  143,   -1,  171,  172,  173,
  174,  175,  176,  177,  178,   94,   -1,   -1,  182,  183,
  184,  185,  186,   -1,   -1,   -1,   -1,   -1,  291,   -1,
   -1,   -1,  310,  311,  312,   -1,   -1,   -1,   -1,   -1,
  318,  319,   -1,   -1,   -1,  124,   -1,  310,  311,  312,
   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,   99,
  100,   -1,   -1,   -1,   -1,   -1,  106,   -1,  108,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  214,  215,   -1,   -1,
   -1,   -1,  122,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  132,  133,  372,  373,   -1,   -1,   -1,   -1,
   -1,   -1,  142,  143,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  310,  311,  312,   -1,   -1,
   -1,   -1,   -1,  318,  319,   -1,   -1,   -1,   -1,   -1,
   -1,  269,  270,  257,  258,  259,  260,  261,   -1,  263,
  264,   -1,   -1,  267,  268,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,   -1,  263,  264,  289,  290,  267,  268,   -1,
   -1,   -1,   -1,   -1,  214,  215,  300,  301,  302,  303,
  304,  305,  306,  307,  308,  310,  311,  312,   -1,  289,
  290,   -1,   -1,  318,  319,   -1,   -1,   -1,   -1,   -1,
  300,  301,  302,  303,  304,  305,  306,  307,  308,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  269,
  270,  310,  311,  312,   -1,   -1,   -1,   -1,   -1,  318,
  319,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 374
#define YYUNDFTOKEN 422
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const pcapyyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,"':'",0,"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'|'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"DST","SRC","HOST","GATEWAY","NET",
"NETMASK","PORT","PORTRANGE","LESS","GREATER","PROTO","PROTOCHAIN","CBYTE",
"ARP","RARP","IP","SCTP","TCP","UDP","ICMP","IGMP","IGRP","PIM","VRRP","CARP",
"ATALK","AARP","DECNET","LAT","SCA","MOPRC","MOPDL","TK_BROADCAST",
"TK_MULTICAST","NUM","INBOUND","OUTBOUND","PF_IFNAME","PF_RSET","PF_RNR",
"PF_SRNR","PF_REASON","PF_ACTION","TYPE","SUBTYPE","DIR","ADDR1","ADDR2",
"ADDR3","ADDR4","RA","TA","LINK","GEQ","LEQ","NEQ","ID","EID","HID","HID6",
"AID","LSH","RSH","LEN","IPV6","ICMPV6","AH","ESP","VLAN","MPLS","PPPOED",
"PPPOES","ISO","ESIS","CLNP","ISIS","L1","L2","IIH","LSP","SNP","CSNP","PSNP",
"STP","IPX","NETBEUI","LANE","LLC","METAC","BCC","SC","ILMIC","OAMF4EC",
"OAMF4SC","OAM","OAMF4","CONNECTMSG","METACONNECT","VPI","VCI","RADIO","FISU",
"LSSU","MSU","HFISU","HLSSU","HMSU","SIO","OPC","DPC","SLS","HSIO","HOPC",
"HDPC","HSLS","OR","AND","UMINUS",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const pcapyyrule[] = {
"$accept : prog",
"prog : null expr",
"prog : null",
"null :",
"expr : term",
"expr : expr and term",
"expr : expr and id",
"expr : expr or term",
"expr : expr or id",
"and : AND",
"or : OR",
"id : nid",
"id : pnum",
"id : paren pid ')'",
"nid : ID",
"nid : HID '/' NUM",
"nid : HID NETMASK HID",
"nid : HID",
"nid : HID6 '/' NUM",
"nid : HID6",
"nid : EID",
"nid : AID",
"nid : not id",
"not : '!'",
"paren : '('",
"pid : nid",
"pid : qid and id",
"pid : qid or id",
"qid : pnum",
"qid : pid",
"term : rterm",
"term : not term",
"head : pqual dqual aqual",
"head : pqual dqual",
"head : pqual aqual",
"head : pqual PROTO",
"head : pqual PROTOCHAIN",
"head : pqual ndaqual",
"rterm : head id",
"rterm : paren expr ')'",
"rterm : pname",
"rterm : arth relop arth",
"rterm : arth irelop arth",
"rterm : other",
"rterm : atmtype",
"rterm : atmmultitype",
"rterm : atmfield atmvalue",
"rterm : mtp2type",
"rterm : mtp3field mtp3value",
"pqual : pname",
"pqual :",
"dqual : SRC",
"dqual : DST",
"dqual : SRC OR DST",
"dqual : DST OR SRC",
"dqual : SRC AND DST",
"dqual : DST AND SRC",
"dqual : ADDR1",
"dqual : ADDR2",
"dqual : ADDR3",
"dqual : ADDR4",
"dqual : RA",
"dqual : TA",
"aqual : HOST",
"aqual : NET",
"aqual : PORT",
"aqual : PORTRANGE",
"ndaqual : GATEWAY",
"pname : LINK",
"pname : IP",
"pname : ARP",
"pname : RARP",
"pname : SCTP",
"pname : TCP",
"pname : UDP",
"pname : ICMP",
"pname : IGMP",
"pname : IGRP",
"pname : PIM",
"pname : VRRP",
"pname : CARP",
"pname : ATALK",
"pname : AARP",
"pname : DECNET",
"pname : LAT",
"pname : SCA",
"pname : MOPDL",
"pname : MOPRC",
"pname : IPV6",
"pname : ICMPV6",
"pname : AH",
"pname : ESP",
"pname : ISO",
"pname : ESIS",
"pname : ISIS",
"pname : L1",
"pname : L2",
"pname : IIH",
"pname : LSP",
"pname : SNP",
"pname : PSNP",
"pname : CSNP",
"pname : CLNP",
"pname : STP",
"pname : IPX",
"pname : NETBEUI",
"pname : RADIO",
"other : pqual TK_BROADCAST",
"other : pqual TK_MULTICAST",
"other : LESS NUM",
"other : GREATER NUM",
"other : CBYTE NUM byteop NUM",
"other : INBOUND",
"other : OUTBOUND",
"other : VLAN pnum",
"other : VLAN",
"other : MPLS pnum",
"other : MPLS",
"other : PPPOED",
"other : PPPOES pnum",
"other : PPPOES",
"other : pfvar",
"other : pqual p80211",
"other : pllc",
"pfvar : PF_IFNAME ID",
"pfvar : PF_RSET ID",
"pfvar : PF_RNR NUM",
"pfvar : PF_SRNR NUM",
"pfvar : PF_REASON reason",
"pfvar : PF_ACTION action",
"p80211 : TYPE type SUBTYPE subtype",
"p80211 : TYPE type",
"p80211 : SUBTYPE type_subtype",
"p80211 : DIR dir",
"type : NUM",
"type : ID",
"subtype : NUM",
"subtype : ID",
"type_subtype : ID",
"pllc : LLC",
"pllc : LLC ID",
"pllc : LLC PF_RNR",
"dir : NUM",
"dir : ID",
"reason : NUM",
"reason : ID",
"action : ID",
"relop : '>'",
"relop : GEQ",
"relop : '='",
"irelop : LEQ",
"irelop : '<'",
"irelop : NEQ",
"arth : pnum",
"arth : narth",
"narth : pname '[' arth ']'",
"narth : pname '[' arth ':' NUM ']'",
"narth : arth '+' arth",
"narth : arth '-' arth",
"narth : arth '*' arth",
"narth : arth '/' arth",
"narth : arth '%' arth",
"narth : arth '&' arth",
"narth : arth '|' arth",
"narth : arth '^' arth",
"narth : arth LSH arth",
"narth : arth RSH arth",
"narth : '-' arth",
"narth : paren narth ')'",
"narth : LEN",
"byteop : '&'",
"byteop : '|'",
"byteop : '<'",
"byteop : '>'",
"byteop : '='",
"pnum : NUM",
"pnum : paren pnum ')'",
"atmtype : LANE",
"atmtype : METAC",
"atmtype : BCC",
"atmtype : OAMF4EC",
"atmtype : OAMF4SC",
"atmtype : SC",
"atmtype : ILMIC",
"atmmultitype : OAM",
"atmmultitype : OAMF4",
"atmmultitype : CONNECTMSG",
"atmmultitype : METACONNECT",
"atmfield : VPI",
"atmfield : VCI",
"atmvalue : atmfieldvalue",
"atmvalue : relop NUM",
"atmvalue : irelop NUM",
"atmvalue : paren atmlistvalue ')'",
"atmfieldvalue : NUM",
"atmlistvalue : atmfieldvalue",
"atmlistvalue : atmlistvalue or atmfieldvalue",
"mtp2type : FISU",
"mtp2type : LSSU",
"mtp2type : MSU",
"mtp2type : HFISU",
"mtp2type : HLSSU",
"mtp2type : HMSU",
"mtp3field : SIO",
"mtp3field : OPC",
"mtp3field : DPC",
"mtp3field : SLS",
"mtp3field : HSIO",
"mtp3field : HOPC",
"mtp3field : HDPC",
"mtp3field : HSLS",
"mtp3value : mtp3fieldvalue",
"mtp3value : relop NUM",
"mtp3value : irelop NUM",
"mtp3value : paren mtp3listvalue ')'",
"mtp3fieldvalue : NUM",
"mtp3listvalue : mtp3fieldvalue",
"mtp3listvalue : mtp3listvalue or mtp3fieldvalue",

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
#line 332 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{
	finish_parse(yystack.l_mark[0].blk.b);
}
break;
case 3:
#line 337 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.q = qerr; }
break;
case 5:
#line 340 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ gen_and(yystack.l_mark[-2].blk.b, yystack.l_mark[0].blk.b); yyval.blk = yystack.l_mark[0].blk; }
break;
case 6:
#line 341 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ gen_and(yystack.l_mark[-2].blk.b, yystack.l_mark[0].blk.b); yyval.blk = yystack.l_mark[0].blk; }
break;
case 7:
#line 342 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ gen_or(yystack.l_mark[-2].blk.b, yystack.l_mark[0].blk.b); yyval.blk = yystack.l_mark[0].blk; }
break;
case 8:
#line 343 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ gen_or(yystack.l_mark[-2].blk.b, yystack.l_mark[0].blk.b); yyval.blk = yystack.l_mark[0].blk; }
break;
case 9:
#line 345 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk = yystack.l_mark[-1].blk; }
break;
case 10:
#line 347 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk = yystack.l_mark[-1].blk; }
break;
case 12:
#line 350 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_ncode(NULL, (bpf_u_int32)yystack.l_mark[0].i,
						   yyval.blk.q = yystack.l_mark[-1].blk.q); }
break;
case 13:
#line 352 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk = yystack.l_mark[-1].blk; }
break;
case 14:
#line 354 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_scode(yystack.l_mark[0].s, yyval.blk.q = yystack.l_mark[-1].blk.q); }
break;
case 15:
#line 355 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_mcode(yystack.l_mark[-2].s, NULL, yystack.l_mark[0].i,
				    yyval.blk.q = yystack.l_mark[-3].blk.q); }
break;
case 16:
#line 357 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_mcode(yystack.l_mark[-2].s, yystack.l_mark[0].s, 0,
				    yyval.blk.q = yystack.l_mark[-3].blk.q); }
break;
case 17:
#line 359 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{
				  /* Decide how to parse HID based on proto */
				  yyval.blk.q = yystack.l_mark[-1].blk.q;
				  if (yyval.blk.q.addr == Q_PORT)
				  	bpf_error("'port' modifier applied to ip host");
				  else if (yyval.blk.q.addr == Q_PORTRANGE)
				  	bpf_error("'portrange' modifier applied to ip host");
				  else if (yyval.blk.q.addr == Q_PROTO)
				  	bpf_error("'proto' modifier applied to ip host");
				  else if (yyval.blk.q.addr == Q_PROTOCHAIN)
				  	bpf_error("'protochain' modifier applied to ip host");
				  yyval.blk.b = gen_ncode(yystack.l_mark[0].s, 0, yyval.blk.q);
				}
break;
case 18:
#line 372 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{
#ifdef INET6
				  yyval.blk.b = gen_mcode6(yystack.l_mark[-2].s, NULL, yystack.l_mark[0].i,
				    yyval.blk.q = yystack.l_mark[-3].blk.q);
#else
				  bpf_error("'ip6addr/prefixlen' not supported "
					"in this configuration");
#endif /*INET6*/
				}
break;
case 19:
#line 381 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{
#ifdef INET6
				  yyval.blk.b = gen_mcode6(yystack.l_mark[0].s, 0, 128,
				    yyval.blk.q = yystack.l_mark[-1].blk.q);
#else
				  bpf_error("'ip6addr' not supported "
					"in this configuration");
#endif /*INET6*/
				}
break;
case 20:
#line 390 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ 
				  yyval.blk.b = gen_ecode(yystack.l_mark[0].e, yyval.blk.q = yystack.l_mark[-1].blk.q);
				  /*
				   * $1 was allocated by "pcap_ether_aton()",
				   * so we must free it now that we're done
				   * with it.
				   */
				  free(yystack.l_mark[0].e);
				}
break;
case 21:
#line 399 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{
				  yyval.blk.b = gen_acode(yystack.l_mark[0].e, yyval.blk.q = yystack.l_mark[-1].blk.q);
				  /*
				   * $1 was allocated by "pcap_ether_aton()",
				   * so we must free it now that we're done
				   * with it.
				   */
				  free(yystack.l_mark[0].e);
				}
break;
case 22:
#line 408 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ gen_not(yystack.l_mark[0].blk.b); yyval.blk = yystack.l_mark[0].blk; }
break;
case 23:
#line 410 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk = yystack.l_mark[-1].blk; }
break;
case 24:
#line 412 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk = yystack.l_mark[-1].blk; }
break;
case 26:
#line 415 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ gen_and(yystack.l_mark[-2].blk.b, yystack.l_mark[0].blk.b); yyval.blk = yystack.l_mark[0].blk; }
break;
case 27:
#line 416 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ gen_or(yystack.l_mark[-2].blk.b, yystack.l_mark[0].blk.b); yyval.blk = yystack.l_mark[0].blk; }
break;
case 28:
#line 418 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_ncode(NULL, (bpf_u_int32)yystack.l_mark[0].i,
						   yyval.blk.q = yystack.l_mark[-1].blk.q); }
break;
case 31:
#line 423 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ gen_not(yystack.l_mark[0].blk.b); yyval.blk = yystack.l_mark[0].blk; }
break;
case 32:
#line 425 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ QSET(yyval.blk.q, yystack.l_mark[-2].i, yystack.l_mark[-1].i, yystack.l_mark[0].i); }
break;
case 33:
#line 426 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ QSET(yyval.blk.q, yystack.l_mark[-1].i, yystack.l_mark[0].i, Q_DEFAULT); }
break;
case 34:
#line 427 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ QSET(yyval.blk.q, yystack.l_mark[-1].i, Q_DEFAULT, yystack.l_mark[0].i); }
break;
case 35:
#line 428 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ QSET(yyval.blk.q, yystack.l_mark[-1].i, Q_DEFAULT, Q_PROTO); }
break;
case 36:
#line 429 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ QSET(yyval.blk.q, yystack.l_mark[-1].i, Q_DEFAULT, Q_PROTOCHAIN); }
break;
case 37:
#line 430 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ QSET(yyval.blk.q, yystack.l_mark[-1].i, Q_DEFAULT, yystack.l_mark[0].i); }
break;
case 38:
#line 432 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk = yystack.l_mark[0].blk; }
break;
case 39:
#line 433 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = yystack.l_mark[-1].blk.b; yyval.blk.q = yystack.l_mark[-2].blk.q; }
break;
case 40:
#line 434 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_proto_abbrev(yystack.l_mark[0].i); yyval.blk.q = qerr; }
break;
case 41:
#line 435 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_relation(yystack.l_mark[-1].i, yystack.l_mark[-2].a, yystack.l_mark[0].a, 0);
				  yyval.blk.q = qerr; }
break;
case 42:
#line 437 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_relation(yystack.l_mark[-1].i, yystack.l_mark[-2].a, yystack.l_mark[0].a, 1);
				  yyval.blk.q = qerr; }
break;
case 43:
#line 439 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = yystack.l_mark[0].rblk; yyval.blk.q = qerr; }
break;
case 44:
#line 440 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_atmtype_abbrev(yystack.l_mark[0].i); yyval.blk.q = qerr; }
break;
case 45:
#line 441 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_atmmulti_abbrev(yystack.l_mark[0].i); yyval.blk.q = qerr; }
break;
case 46:
#line 442 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = yystack.l_mark[0].blk.b; yyval.blk.q = qerr; }
break;
case 47:
#line 443 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_mtp2type_abbrev(yystack.l_mark[0].i); yyval.blk.q = qerr; }
break;
case 48:
#line 444 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = yystack.l_mark[0].blk.b; yyval.blk.q = qerr; }
break;
case 50:
#line 448 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_DEFAULT; }
break;
case 51:
#line 451 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_SRC; }
break;
case 52:
#line 452 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_DST; }
break;
case 53:
#line 453 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_OR; }
break;
case 54:
#line 454 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_OR; }
break;
case 55:
#line 455 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_AND; }
break;
case 56:
#line 456 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_AND; }
break;
case 57:
#line 457 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ADDR1; }
break;
case 58:
#line 458 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ADDR2; }
break;
case 59:
#line 459 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ADDR3; }
break;
case 60:
#line 460 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ADDR4; }
break;
case 61:
#line 461 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_RA; }
break;
case 62:
#line 462 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_TA; }
break;
case 63:
#line 465 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_HOST; }
break;
case 64:
#line 466 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_NET; }
break;
case 65:
#line 467 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_PORT; }
break;
case 66:
#line 468 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_PORTRANGE; }
break;
case 67:
#line 471 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_GATEWAY; }
break;
case 68:
#line 473 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_LINK; }
break;
case 69:
#line 474 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_IP; }
break;
case 70:
#line 475 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ARP; }
break;
case 71:
#line 476 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_RARP; }
break;
case 72:
#line 477 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_SCTP; }
break;
case 73:
#line 478 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_TCP; }
break;
case 74:
#line 479 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_UDP; }
break;
case 75:
#line 480 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ICMP; }
break;
case 76:
#line 481 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_IGMP; }
break;
case 77:
#line 482 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_IGRP; }
break;
case 78:
#line 483 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_PIM; }
break;
case 79:
#line 484 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_VRRP; }
break;
case 80:
#line 485 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_CARP; }
break;
case 81:
#line 486 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ATALK; }
break;
case 82:
#line 487 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_AARP; }
break;
case 83:
#line 488 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_DECNET; }
break;
case 84:
#line 489 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_LAT; }
break;
case 85:
#line 490 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_SCA; }
break;
case 86:
#line 491 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_MOPDL; }
break;
case 87:
#line 492 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_MOPRC; }
break;
case 88:
#line 493 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_IPV6; }
break;
case 89:
#line 494 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ICMPV6; }
break;
case 90:
#line 495 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_AH; }
break;
case 91:
#line 496 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ESP; }
break;
case 92:
#line 497 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ISO; }
break;
case 93:
#line 498 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ESIS; }
break;
case 94:
#line 499 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ISIS; }
break;
case 95:
#line 500 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ISIS_L1; }
break;
case 96:
#line 501 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ISIS_L2; }
break;
case 97:
#line 502 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ISIS_IIH; }
break;
case 98:
#line 503 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ISIS_LSP; }
break;
case 99:
#line 504 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ISIS_SNP; }
break;
case 100:
#line 505 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ISIS_PSNP; }
break;
case 101:
#line 506 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_ISIS_CSNP; }
break;
case 102:
#line 507 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_CLNP; }
break;
case 103:
#line 508 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_STP; }
break;
case 104:
#line 509 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_IPX; }
break;
case 105:
#line 510 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_NETBEUI; }
break;
case 106:
#line 511 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = Q_RADIO; }
break;
case 107:
#line 513 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_broadcast(yystack.l_mark[-1].i); }
break;
case 108:
#line 514 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_multicast(yystack.l_mark[-1].i); }
break;
case 109:
#line 515 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_less(yystack.l_mark[0].i); }
break;
case 110:
#line 516 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_greater(yystack.l_mark[0].i); }
break;
case 111:
#line 517 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_byteop(yystack.l_mark[-1].i, yystack.l_mark[-2].i, yystack.l_mark[0].i); }
break;
case 112:
#line 518 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_inbound(0); }
break;
case 113:
#line 519 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_inbound(1); }
break;
case 114:
#line 520 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_vlan(yystack.l_mark[0].i); }
break;
case 115:
#line 521 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_vlan(-1); }
break;
case 116:
#line 522 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_mpls(yystack.l_mark[0].i); }
break;
case 117:
#line 523 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_mpls(-1); }
break;
case 118:
#line 524 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_pppoed(); }
break;
case 119:
#line 525 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_pppoes(yystack.l_mark[0].i); }
break;
case 120:
#line 526 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_pppoes(-1); }
break;
case 121:
#line 527 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = yystack.l_mark[0].rblk; }
break;
case 122:
#line 528 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = yystack.l_mark[0].rblk; }
break;
case 123:
#line 529 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = yystack.l_mark[0].rblk; }
break;
case 124:
#line 532 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_pf_ifname(yystack.l_mark[0].s); }
break;
case 125:
#line 533 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_pf_ruleset(yystack.l_mark[0].s); }
break;
case 126:
#line 534 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_pf_rnr(yystack.l_mark[0].i); }
break;
case 127:
#line 535 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_pf_srnr(yystack.l_mark[0].i); }
break;
case 128:
#line 536 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_pf_reason(yystack.l_mark[0].i); }
break;
case 129:
#line 537 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_pf_action(yystack.l_mark[0].i); }
break;
case 130:
#line 541 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_p80211_type(yystack.l_mark[-2].i | yystack.l_mark[0].i,
					IEEE80211_FC0_TYPE_MASK |
					IEEE80211_FC0_SUBTYPE_MASK);
				}
break;
case 131:
#line 545 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_p80211_type(yystack.l_mark[0].i,
					IEEE80211_FC0_TYPE_MASK);
				}
break;
case 132:
#line 548 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_p80211_type(yystack.l_mark[0].i,
					IEEE80211_FC0_TYPE_MASK |
					IEEE80211_FC0_SUBTYPE_MASK);
				}
break;
case 133:
#line 552 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_p80211_fcdir(yystack.l_mark[0].i); }
break;
case 135:
#line 556 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = str2tok(yystack.l_mark[0].s, ieee80211_types);
				  if (yyval.i == -1)
				  	bpf_error("unknown 802.11 type name");
				}
break;
case 137:
#line 563 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ const struct tok *types = NULL;
				  int i;
				  for (i = 0;; i++) {
				  	if (ieee80211_type_subtypes[i].tok == NULL) {
				  		/* Ran out of types */
						bpf_error("unknown 802.11 type");
						break;
					}
					if (yystack.l_mark[-2].i == ieee80211_type_subtypes[i].type) {
						types = ieee80211_type_subtypes[i].tok;
						break;
					}
				  }

				  yyval.i = str2tok(yystack.l_mark[0].s, types);
				  if (yyval.i == -1)
					bpf_error("unknown 802.11 subtype name");
				}
break;
case 138:
#line 583 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ int i;
				  for (i = 0;; i++) {
				  	if (ieee80211_type_subtypes[i].tok == NULL) {
				  		/* Ran out of types */
						bpf_error("unknown 802.11 type name");
						break;
					}
					yyval.i = str2tok(yystack.l_mark[0].s, ieee80211_type_subtypes[i].tok);
					if (yyval.i != -1) {
						yyval.i |= ieee80211_type_subtypes[i].type;
						break;
					}
				  }
				}
break;
case 139:
#line 599 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_llc(); }
break;
case 140:
#line 600 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ if (pcap_strcasecmp(yystack.l_mark[0].s, "i") == 0)
					yyval.rblk = gen_llc_i();
				  else if (pcap_strcasecmp(yystack.l_mark[0].s, "s") == 0)
					yyval.rblk = gen_llc_s();
				  else if (pcap_strcasecmp(yystack.l_mark[0].s, "u") == 0)
					yyval.rblk = gen_llc_u();
				  else {
				  	u_int subtype;

					subtype = str2tok(yystack.l_mark[0].s, llc_s_subtypes);
					if (subtype != -1)
						yyval.rblk = gen_llc_s_subtype(subtype);
					else {
						subtype = str2tok(yystack.l_mark[0].s, llc_u_subtypes);
						if (subtype == -1)
					  		bpf_error("unknown LLC type name \"%s\"", yystack.l_mark[0].s);
						yyval.rblk = gen_llc_u_subtype(subtype);
					}
				  }
				}
break;
case 141:
#line 621 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.rblk = gen_llc_s_subtype(LLC_RNR); }
break;
case 143:
#line 625 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ if (pcap_strcasecmp(yystack.l_mark[0].s, "nods") == 0)
					yyval.i = IEEE80211_FC1_DIR_NODS;
				  else if (pcap_strcasecmp(yystack.l_mark[0].s, "tods") == 0)
					yyval.i = IEEE80211_FC1_DIR_TODS;
				  else if (pcap_strcasecmp(yystack.l_mark[0].s, "fromds") == 0)
					yyval.i = IEEE80211_FC1_DIR_FROMDS;
				  else if (pcap_strcasecmp(yystack.l_mark[0].s, "dstods") == 0)
					yyval.i = IEEE80211_FC1_DIR_DSTODS;
				  else
					bpf_error("unknown 802.11 direction");
				}
break;
case 144:
#line 638 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = yystack.l_mark[0].i; }
break;
case 145:
#line 639 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = pfreason_to_num(yystack.l_mark[0].s); }
break;
case 146:
#line 642 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = pfaction_to_num(yystack.l_mark[0].s); }
break;
case 147:
#line 645 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = BPF_JGT; }
break;
case 148:
#line 646 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = BPF_JGE; }
break;
case 149:
#line 647 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = BPF_JEQ; }
break;
case 150:
#line 649 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = BPF_JGT; }
break;
case 151:
#line 650 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = BPF_JGE; }
break;
case 152:
#line 651 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = BPF_JEQ; }
break;
case 153:
#line 653 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_loadi(yystack.l_mark[0].i); }
break;
case 155:
#line 656 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_load(yystack.l_mark[-3].i, yystack.l_mark[-1].a, 1); }
break;
case 156:
#line 657 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_load(yystack.l_mark[-5].i, yystack.l_mark[-3].a, yystack.l_mark[-1].i); }
break;
case 157:
#line 658 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_arth(BPF_ADD, yystack.l_mark[-2].a, yystack.l_mark[0].a); }
break;
case 158:
#line 659 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_arth(BPF_SUB, yystack.l_mark[-2].a, yystack.l_mark[0].a); }
break;
case 159:
#line 660 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_arth(BPF_MUL, yystack.l_mark[-2].a, yystack.l_mark[0].a); }
break;
case 160:
#line 661 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_arth(BPF_DIV, yystack.l_mark[-2].a, yystack.l_mark[0].a); }
break;
case 161:
#line 662 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_arth(BPF_MOD, yystack.l_mark[-2].a, yystack.l_mark[0].a); }
break;
case 162:
#line 663 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_arth(BPF_AND, yystack.l_mark[-2].a, yystack.l_mark[0].a); }
break;
case 163:
#line 664 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_arth(BPF_OR, yystack.l_mark[-2].a, yystack.l_mark[0].a); }
break;
case 164:
#line 665 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_arth(BPF_XOR, yystack.l_mark[-2].a, yystack.l_mark[0].a); }
break;
case 165:
#line 666 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_arth(BPF_LSH, yystack.l_mark[-2].a, yystack.l_mark[0].a); }
break;
case 166:
#line 667 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_arth(BPF_RSH, yystack.l_mark[-2].a, yystack.l_mark[0].a); }
break;
case 167:
#line 668 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_neg(yystack.l_mark[0].a); }
break;
case 168:
#line 669 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = yystack.l_mark[-1].a; }
break;
case 169:
#line 670 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.a = gen_loadlen(); }
break;
case 170:
#line 672 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = '&'; }
break;
case 171:
#line 673 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = '|'; }
break;
case 172:
#line 674 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = '<'; }
break;
case 173:
#line 675 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = '>'; }
break;
case 174:
#line 676 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = '='; }
break;
case 176:
#line 679 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = yystack.l_mark[-1].i; }
break;
case 177:
#line 681 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = A_LANE; }
break;
case 178:
#line 682 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = A_METAC;	}
break;
case 179:
#line 683 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = A_BCC; }
break;
case 180:
#line 684 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = A_OAMF4EC; }
break;
case 181:
#line 685 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = A_OAMF4SC; }
break;
case 182:
#line 686 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = A_SC; }
break;
case 183:
#line 687 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = A_ILMIC; }
break;
case 184:
#line 689 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = A_OAM; }
break;
case 185:
#line 690 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = A_OAMF4; }
break;
case 186:
#line 691 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = A_CONNECTMSG; }
break;
case 187:
#line 692 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = A_METACONNECT; }
break;
case 188:
#line 695 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.atmfieldtype = A_VPI; }
break;
case 189:
#line 696 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.atmfieldtype = A_VCI; }
break;
case 191:
#line 699 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_atmfield_code(yystack.l_mark[-2].blk.atmfieldtype, (bpf_int32)yystack.l_mark[0].i, (bpf_u_int32)yystack.l_mark[-1].i, 0); }
break;
case 192:
#line 700 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_atmfield_code(yystack.l_mark[-2].blk.atmfieldtype, (bpf_int32)yystack.l_mark[0].i, (bpf_u_int32)yystack.l_mark[-1].i, 1); }
break;
case 193:
#line 701 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = yystack.l_mark[-1].blk.b; yyval.blk.q = qerr; }
break;
case 194:
#line 703 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{
	yyval.blk.atmfieldtype = yystack.l_mark[-1].blk.atmfieldtype;
	if (yyval.blk.atmfieldtype == A_VPI ||
	    yyval.blk.atmfieldtype == A_VCI)
		yyval.blk.b = gen_atmfield_code(yyval.blk.atmfieldtype, (bpf_int32) yystack.l_mark[0].i, BPF_JEQ, 0);
	}
break;
case 196:
#line 711 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ gen_or(yystack.l_mark[-2].blk.b, yystack.l_mark[0].blk.b); yyval.blk = yystack.l_mark[0].blk; }
break;
case 197:
#line 714 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = M_FISU; }
break;
case 198:
#line 715 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = M_LSSU; }
break;
case 199:
#line 716 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = M_MSU; }
break;
case 200:
#line 717 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = MH_FISU; }
break;
case 201:
#line 718 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = MH_LSSU; }
break;
case 202:
#line 719 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.i = MH_MSU; }
break;
case 203:
#line 722 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.mtp3fieldtype = M_SIO; }
break;
case 204:
#line 723 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.mtp3fieldtype = M_OPC; }
break;
case 205:
#line 724 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.mtp3fieldtype = M_DPC; }
break;
case 206:
#line 725 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.mtp3fieldtype = M_SLS; }
break;
case 207:
#line 726 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.mtp3fieldtype = MH_SIO; }
break;
case 208:
#line 727 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.mtp3fieldtype = MH_OPC; }
break;
case 209:
#line 728 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.mtp3fieldtype = MH_DPC; }
break;
case 210:
#line 729 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.mtp3fieldtype = MH_SLS; }
break;
case 212:
#line 732 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_mtp3field_code(yystack.l_mark[-2].blk.mtp3fieldtype, (u_int)yystack.l_mark[0].i, (u_int)yystack.l_mark[-1].i, 0); }
break;
case 213:
#line 733 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = gen_mtp3field_code(yystack.l_mark[-2].blk.mtp3fieldtype, (u_int)yystack.l_mark[0].i, (u_int)yystack.l_mark[-1].i, 1); }
break;
case 214:
#line 734 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ yyval.blk.b = yystack.l_mark[-1].blk.b; yyval.blk.q = qerr; }
break;
case 215:
#line 736 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{
	yyval.blk.mtp3fieldtype = yystack.l_mark[-1].blk.mtp3fieldtype;
	if (yyval.blk.mtp3fieldtype == M_SIO ||
	    yyval.blk.mtp3fieldtype == M_OPC ||
	    yyval.blk.mtp3fieldtype == M_DPC ||
	    yyval.blk.mtp3fieldtype == M_SLS ||
	    yyval.blk.mtp3fieldtype == MH_SIO ||
	    yyval.blk.mtp3fieldtype == MH_OPC ||
	    yyval.blk.mtp3fieldtype == MH_DPC ||
	    yyval.blk.mtp3fieldtype == MH_SLS)
		yyval.blk.b = gen_mtp3field_code(yyval.blk.mtp3fieldtype, (u_int) yystack.l_mark[0].i, BPF_JEQ, 0);
	}
break;
case 217:
#line 750 "/usr/home/freebsd/omega/src/lib/libpcap/../../contrib/libpcap/grammar.y"
	{ gen_or(yystack.l_mark[-2].blk.b, yystack.l_mark[0].blk.b); yyval.blk = yystack.l_mark[0].blk; }
break;
#line 2376 "grammar.c"
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
