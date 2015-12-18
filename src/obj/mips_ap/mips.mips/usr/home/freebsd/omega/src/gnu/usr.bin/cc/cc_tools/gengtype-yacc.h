#define ENT_TYPEDEF_STRUCT 257
#define ENT_STRUCT 258
#define ENT_EXTERNSTATIC 259
#define ENT_YACCUNION 260
#define GTY_TOKEN 261
#define UNION 262
#define STRUCT 263
#define ENUM 264
#define ALIAS 265
#define NESTED_PTR 266
#define PARAM_IS 267
#define NUM 268
#define PERCENTPERCENT 269
#define SCALAR 271
#define ID 272
#define STRING 273
#define ARRAY 274
#define PERCENT_ID 275
#define CHAR 276
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  type_p t;
  pair_p p;
  options_p o;
  const char *s;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
