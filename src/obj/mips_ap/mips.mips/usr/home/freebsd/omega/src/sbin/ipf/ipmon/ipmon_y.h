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
extern YYSTYPE ipmon_yylval;
