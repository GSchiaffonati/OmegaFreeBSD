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
extern YYSTYPE ippool_yylval;
