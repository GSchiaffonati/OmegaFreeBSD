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
extern YYSTYPE yylval;
