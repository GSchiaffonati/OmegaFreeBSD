#define DREG 257
#define CREG 258
#define GREG 259
#define IMMED 260
#define ADDR 261
#define INSN 262
#define NUM 263
#define ID 264
#define NL 265
#define PNUM 266
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union 
  {
    char *str;
    int num;
    int processor;
    unsigned long val;
  } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
