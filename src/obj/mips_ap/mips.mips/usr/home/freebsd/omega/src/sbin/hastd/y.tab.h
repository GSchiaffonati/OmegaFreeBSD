#define CONTROL 257
#define PIDFILE 258
#define LISTEN 259
#define REPLICATION 260
#define CHECKSUM 261
#define COMPRESSION 262
#define METAFLUSH 263
#define TIMEOUT 264
#define EXEC 265
#define RESOURCE 266
#define NAME 267
#define LOCAL 268
#define REMOTE 269
#define SOURCE 270
#define ON 271
#define OFF 272
#define FULLSYNC 273
#define MEMSYNC 274
#define ASYNC 275
#define NONE 276
#define CRC32 277
#define SHA256 278
#define HOLE 279
#define LZF 280
#define NUM 281
#define STR 282
#define OB 283
#define CB 284
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
	int num;
	char *str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
