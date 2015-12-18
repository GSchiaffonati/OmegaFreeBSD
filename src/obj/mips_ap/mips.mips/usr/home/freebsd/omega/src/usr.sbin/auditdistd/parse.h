#define CB 257
#define CERTFILE 258
#define DIRECTORY 259
#define FINGERPRINT 260
#define HOST 261
#define KEYFILE 262
#define LISTEN 263
#define NAME 264
#define OB 265
#define PASSWORD 266
#define PIDFILE 267
#define RECEIVER 268
#define REMOTE 269
#define SENDER 270
#define SOURCE 271
#define TIMEOUT 272
#define NUM 273
#define STR 274
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
