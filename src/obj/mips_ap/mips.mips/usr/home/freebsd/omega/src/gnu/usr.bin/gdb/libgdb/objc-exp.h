#define INT 257
#define FLOAT 258
#define STRING 259
#define NSSTRING 260
#define SELECTOR 261
#define NAME 262
#define TYPENAME 263
#define CLASSNAME 264
#define NAME_OR_INT 265
#define STRUCT 266
#define CLASS 267
#define UNION 268
#define ENUM 269
#define SIZEOF 270
#define UNSIGNED 271
#define COLONCOLON 272
#define TEMPLATE 273
#define ERROR 274
#define SIGNED_KEYWORD 275
#define LONG 276
#define SHORT 277
#define INT_KEYWORD 278
#define CONST_KEYWORD 279
#define VOLATILE_KEYWORD 280
#define DOUBLE_KEYWORD 281
#define VARIABLE 282
#define ASSIGN_MODIFY 283
#define ABOVE_COMMA 284
#define OROR 285
#define ANDAND 286
#define EQUAL 287
#define NOTEQUAL 288
#define LEQ 289
#define GEQ 290
#define LSH 291
#define RSH 292
#define UNARY 293
#define INCREMENT 294
#define DECREMENT 295
#define ARROW 296
#define BLOCKNAME 297
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
    struct objc_class_str class;

    struct type **tvec;
    int *ivec;
  } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
