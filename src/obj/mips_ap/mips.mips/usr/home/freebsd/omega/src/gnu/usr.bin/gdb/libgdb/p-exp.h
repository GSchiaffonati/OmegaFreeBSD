#define INT 257
#define FLOAT 258
#define STRING 259
#define FIELDNAME 260
#define NAME 261
#define TYPENAME 262
#define NAME_OR_INT 263
#define STRUCT 264
#define CLASS 265
#define SIZEOF 266
#define COLONCOLON 267
#define ERROR 268
#define VARIABLE 269
#define THIS 270
#define TRUEKEYWORD 271
#define FALSEKEYWORD 272
#define ABOVE_COMMA 273
#define ASSIGN 274
#define NOT 275
#define OR 276
#define XOR 277
#define ANDAND 278
#define NOTEQUAL 279
#define LEQ 280
#define GEQ 281
#define LSH 282
#define RSH 283
#define DIV 284
#define MOD 285
#define UNARY 286
#define INCREMENT 287
#define DECREMENT 288
#define ARROW 289
#define BLOCKNAME 290
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
    int voidval;
    struct block *bval;
    enum exp_opcode opcode;
    struct internalvar *ivar;

    struct type **tvec;
    int *ivec;
  } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
