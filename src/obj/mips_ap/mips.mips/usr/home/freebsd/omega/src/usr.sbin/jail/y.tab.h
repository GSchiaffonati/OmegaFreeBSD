#define PLEQ 257
#define STR 258
#define STR1 259
#define VAR 260
#define VAR1 261
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct cfjail		*j;
	struct cfparams		*pp;
	struct cfparam		*p;
	struct cfstrings	*ss;
	struct cfstring		*s;
	char			*cs;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
