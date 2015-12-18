#define INTEGER_LITERAL 257
#define FLOATING_POINT_LITERAL 258
#define IDENTIFIER 259
#define STRING_LITERAL 260
#define BOOLEAN_LITERAL 261
#define TYPENAME 262
#define NAME_OR_INT 263
#define ERROR 264
#define LONG 265
#define SHORT 266
#define BYTE 267
#define INT 268
#define CHAR 269
#define BOOLEAN 270
#define DOUBLE 271
#define FLOAT 272
#define VARIABLE 273
#define ASSIGN_MODIFY 274
#define SUPER 275
#define NEW 276
#define OROR 277
#define ANDAND 278
#define EQUAL 279
#define NOTEQUAL 280
#define LEQ 281
#define GEQ 282
#define LSH 283
#define RSH 284
#define INCREMENT 285
#define DECREMENT 286
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
    } typed_val_int;
    struct {
      DOUBLEST dval;
      struct type *type;
    } typed_val_float;
    struct symbol *sym;
    struct type *tval;
    struct stoken sval;
    struct ttype tsym;
    struct symtoken ssym;
    struct block *bval;
    enum exp_opcode opcode;
    struct internalvar *ivar;
    int *ivec;
  } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
