#define ARCH 257
#define COMMA 258
#define CONFIG 259
#define CPU 260
#define NOCPU 261
#define DEVICE 262
#define NODEVICE 263
#define ENV 264
#define EQUALS 265
#define PLUSEQUALS 266
#define HINTS 267
#define IDENT 268
#define MAXUSERS 269
#define PROFILE 270
#define OPTIONS 271
#define NOOPTION 272
#define MAKEOPTIONS 273
#define NOMAKEOPTION 274
#define SEMICOLON 275
#define INCLUDE 276
#define FILES 277
#define ID 278
#define NUMBER 279
#define PATH 280
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char	*str;
	int	val;
	struct	file_list *file;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
