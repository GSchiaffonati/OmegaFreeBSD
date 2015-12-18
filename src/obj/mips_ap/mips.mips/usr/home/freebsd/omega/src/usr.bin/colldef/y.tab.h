#define SUBSTITUTE 257
#define WITH 258
#define ORDER 259
#define RANGE 260
#define STRING 261
#define DEFN 262
#define CHAR 263
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	u_char ch;
	u_char str[BUFSIZE];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
