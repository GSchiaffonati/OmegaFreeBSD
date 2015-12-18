#define ADDLIB 257
#define ADDMOD 258
#define CLEAR 259
#define CREATE 260
#define DELETE 261
#define DIRECTORY 262
#define END 263
#define EXTRACT 264
#define LIST 265
#define OPEN 266
#define REPLACE 267
#define VERBOSE 268
#define SAVE 269
#define LP 270
#define RP 271
#define COMMA 272
#define EOL 273
#define FNAME 274
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char		*str;
	struct list	*list;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
