#define INT 257
#define FLOAT 258
#define STRING_LITERAL 259
#define BOOLEAN_LITERAL 260
#define NAME 261
#define TYPENAME 262
#define NAME_OR_INT 263
#define SIZEOF 264
#define ERROR 265
#define INT_KEYWORD 266
#define INT_S2_KEYWORD 267
#define LOGICAL_S1_KEYWORD 268
#define LOGICAL_S2_KEYWORD 269
#define LOGICAL_KEYWORD 270
#define REAL_KEYWORD 271
#define REAL_S8_KEYWORD 272
#define REAL_S16_KEYWORD 273
#define COMPLEX_S8_KEYWORD 274
#define COMPLEX_S16_KEYWORD 275
#define COMPLEX_S32_KEYWORD 276
#define BOOL_AND 277
#define BOOL_OR 278
#define BOOL_NOT 279
#define CHARACTER 280
#define VARIABLE 281
#define ASSIGN_MODIFY 282
#define ABOVE_COMMA 283
#define EQUAL 284
#define NOTEQUAL 285
#define LESSTHAN 286
#define GREATERTHAN 287
#define LEQ 288
#define GEQ 289
#define LSH 290
#define RSH 291
#define UNARY 292
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
  {
    LONGEST lval;
    struct {
      LONGEST val;
      struct type *type;
    } typed_val;
    DOUBLEST dval;
    struct symbol *sym;
    struct type *tval;
    struct stoken sval;
    struct ttype tsym;
    struct symtoken ssym;
    int voidval;
    struct block *bval;
    enum exp_opcode opcode;
    struct internalvar *ivar;

    struct type **tvec;
    int *ivec;
  } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
