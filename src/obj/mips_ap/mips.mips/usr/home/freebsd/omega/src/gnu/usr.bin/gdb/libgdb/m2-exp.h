#define INT 257
#define HEX 258
#define ERROR 259
#define UINT 260
#define M2_TRUE 261
#define M2_FALSE 262
#define CHAR 263
#define FLOAT 264
#define STRING 265
#define NAME 266
#define BLOCKNAME 267
#define IDENT 268
#define VARNAME 269
#define TYPENAME 270
#define SIZE 271
#define CAP 272
#define ORD 273
#define HIGH 274
#define ABS 275
#define MIN_FUNC 276
#define MAX_FUNC 277
#define FLOAT_FUNC 278
#define VAL 279
#define CHR 280
#define ODD 281
#define TRUNC 282
#define INC 283
#define DEC 284
#define INCL 285
#define EXCL 286
#define COLONCOLON 287
#define INTERNAL_VAR 288
#define ABOVE_COMMA 289
#define ASSIGN 290
#define LEQ 291
#define GEQ 292
#define NOTEQUAL 293
#define IN 294
#define OROR 295
#define LOGICAL_AND 296
#define DIV 297
#define MOD 298
#define UNARY 299
#define DOT 300
#define NOT 301
#define QID 302
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
  {
    LONGEST lval;
    ULONGEST ulval;
    DOUBLEST dval;
    struct symbol *sym;
    struct type *tval;
    struct stoken sval;
    int voidval;
    struct block *bval;
    enum exp_opcode opcode;
    struct internalvar *ivar;

    struct type **tvec;
    int *ivec;
  } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
