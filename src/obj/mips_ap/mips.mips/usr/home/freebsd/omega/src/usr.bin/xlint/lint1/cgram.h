#define T_LBRACE 257
#define T_RBRACE 258
#define T_LBRACK 259
#define T_RBRACK 260
#define T_LPARN 261
#define T_RPARN 262
#define T_STROP 263
#define T_UNOP 264
#define T_INCDEC 265
#define T_SIZEOF 266
#define T_MULT 267
#define T_DIVOP 268
#define T_ADDOP 269
#define T_SHFTOP 270
#define T_RELOP 271
#define T_EQOP 272
#define T_AND 273
#define T_XOR 274
#define T_OR 275
#define T_LOGAND 276
#define T_LOGOR 277
#define T_QUEST 278
#define T_COLON 279
#define T_ASSIGN 280
#define T_OPASS 281
#define T_COMMA 282
#define T_SEMI 283
#define T_ELLIPSE 284
#define T_SCLASS 285
#define T_TYPE 286
#define T_QUAL 287
#define T_SOU 288
#define T_ENUM 289
#define T_CASE 290
#define T_DEFAULT 291
#define T_IF 292
#define T_ELSE 293
#define T_SWITCH 294
#define T_DO 295
#define T_WHILE 296
#define T_FOR 297
#define T_GOTO 298
#define T_CONTINUE 299
#define T_BREAK 300
#define T_RETURN 301
#define T_ASM 302
#define T_SYMBOLRENAME 303
#define T_NAME 304
#define T_TYPENAME 305
#define T_CON 306
#define T_STRING 307
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int	y_int;
	val_t	*y_val;
	sbuf_t	*y_sb;
	sym_t	*y_sym;
	op_t	y_op;
	scl_t	y_scl;
	tspec_t	y_tspec;
	tqual_t	y_tqual;
	type_t	*y_type;
	tnode_t	*y_tnode;
	range_t	y_range;
	strg_t	*y_strg;
	pqinf_t	*y_pqinf;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
