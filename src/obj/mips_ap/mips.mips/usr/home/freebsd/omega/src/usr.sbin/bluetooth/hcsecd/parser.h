#define T_BDADDRSTRING 257
#define T_HEXSTRING 258
#define T_STRING 259
#define T_DEVICE 260
#define T_BDADDR 261
#define T_NAME 262
#define T_KEY 263
#define T_PIN 264
#define T_NOKEY 265
#define T_NOPIN 266
#define T_JUNK 267
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char	*string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
