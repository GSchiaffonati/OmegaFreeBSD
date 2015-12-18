#define COMMA 257
#define SEMICOLON 258
#define LPAR 259
#define RPAR 260
#define LBRACE 261
#define RBRACE 262
#define LBRACKET 263
#define RBRACKET 264
#define DOT 265
#define NEWLINE 266
#define LETTER 267
#define NUMBER 268
#define STRING 269
#define DEFINE 270
#define BREAK 271
#define QUIT 272
#define LENGTH 273
#define RETURN 274
#define FOR 275
#define IF 276
#define WHILE 277
#define SQRT 278
#define SCALE 279
#define IBASE 280
#define OBASE 281
#define AUTO 282
#define CONTINUE 283
#define ELSE 284
#define PRINT 285
#define BOOL_OR 286
#define BOOL_AND 287
#define BOOL_NOT 288
#define EQUALS 289
#define LESS_EQ 290
#define GREATER_EQ 291
#define UNEQUALS 292
#define LESS 293
#define GREATER 294
#define ASSIGN_OP 295
#define PLUS 296
#define MINUS 297
#define MULTIPLY 298
#define DIVIDE 299
#define REMAINDER 300
#define EXPONENT 301
#define UMINUS 302
#define INCR 303
#define DECR 304
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct lvalue	 lvalue;
	const char	*str;
	char		*astr;
	ssize_t		 node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
