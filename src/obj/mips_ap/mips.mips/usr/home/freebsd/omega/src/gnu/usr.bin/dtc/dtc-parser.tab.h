#define DT_V1 257
#define DT_MEMRESERVE 258
#define DT_LSHIFT 259
#define DT_RSHIFT 260
#define DT_LE 261
#define DT_GE 262
#define DT_EQ 263
#define DT_NE 264
#define DT_AND 265
#define DT_OR 266
#define DT_BITS 267
#define DT_DEL_PROP 268
#define DT_DEL_NODE 269
#define DT_PROPNODENAME 270
#define DT_LITERAL 271
#define DT_CHAR_LITERAL 272
#define DT_BASE 273
#define DT_BYTE 274
#define DT_STRING 275
#define DT_LABEL 276
#define DT_REF 277
#define DT_INCBIN 278
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char *propnodename;
	char *labelref;
	unsigned int cbase;
	uint8_t byte;
	struct data data;

	struct {
		struct data	data;
		int		bits;
	} array;

	struct property *prop;
	struct property *proplist;
	struct node *node;
	struct node *nodelist;
	struct reserve_info *re;
	uint64_t integer;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
