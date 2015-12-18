#define YY_NUMBER 257
#define YY_HEX 258
#define YY_STR 259
#define YY_COMMENT 260
#define YY_CMP_EQ 261
#define YY_CMP_NE 262
#define YY_CMP_LE 263
#define YY_CMP_GE 264
#define YY_CMP_LT 265
#define YY_CMP_GT 266
#define YY_RANGE_OUT 267
#define YY_RANGE_IN 268
#define YY_IPV6 269
#define IPNY_MAPBLOCK 270
#define IPNY_RDR 271
#define IPNY_PORT 272
#define IPNY_PORTS 273
#define IPNY_AUTO 274
#define IPNY_RANGE 275
#define IPNY_MAP 276
#define IPNY_BIMAP 277
#define IPNY_FROM 278
#define IPNY_TO 279
#define IPNY_MASK 280
#define IPNY_PORTMAP 281
#define IPNY_ANY 282
#define IPNY_ROUNDROBIN 283
#define IPNY_FRAG 284
#define IPNY_AGE 285
#define IPNY_ICMPIDMAP 286
#define IPNY_PROXY 287
#define IPNY_TCP 288
#define IPNY_UDP 289
#define IPNY_TCPUDP 290
#define IPNY_STICKY 291
#define IPNY_MSSCLAMP 292
#define IPNY_TAG 293
#define IPNY_TLATE 294
#define IPNY_POOL 295
#define IPNY_HASH 296
#define IPNY_NO 297
#define IPNY_REWRITE 298
#define IPNY_PROTO 299
#define IPNY_ON 300
#define IPNY_SRC 301
#define IPNY_DST 302
#define IPNY_IN 303
#define IPNY_OUT 304
#define IPNY_DIVERT 305
#define IPNY_CONFIG 306
#define IPNY_ALLOW 307
#define IPNY_DENY 308
#define IPNY_DNS 309
#define IPNY_INET 310
#define IPNY_INET6 311
#define IPNY_SEQUENTIAL 312
#define IPNY_DSTLIST 313
#define IPNY_PURGE 314
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union	{
	char	*str;
	u_32_t	num;
	struct {
		i6addr_t	a;
		int		f;
	} ipa;
	frentry_t	fr;
	frtuc_t	*frt;
	u_short	port;
	struct	{
		int	p1;
		int	p2;
		int	pc;
	} pc;
	struct	{
		i6addr_t	a;
		i6addr_t	m;
		int	t;		/* Address type */
		int	u;
		int	f;		/* Family */
		int	v;		/* IP version */
		int	s;		/* 0 = number, 1 = text */
		int	n;		/* number */
	} ipp;
	union	i6addr	ip6;
	namelist_t	*names;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
