/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20141006

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
/*
 * Copyright 2010 Nexenta Systems, Inc.  All rights reserved.
 * Copyright 2015 John Marino <draco@marino.st>
 *
 * This source code is derived from the illumos localedef command, and
 * provided under BSD-style license terms by Nexenta Systems, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * POSIX localedef grammar.
 */

#include <wchar.h>
#include <stdio.h>
#include <limits.h>
#include "localedef.h"

#line 42 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int		num;
	wchar_t		wc;
	char		*token;
	collsym_t	*collsym;
	collelem_t	*collelem;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 76 "parser.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define T_CODE_SET 257
#define T_MB_CUR_MAX 258
#define T_MB_CUR_MIN 259
#define T_COM_CHAR 260
#define T_ESC_CHAR 261
#define T_LT 262
#define T_GT 263
#define T_NL 264
#define T_SEMI 265
#define T_COMMA 266
#define T_ELLIPSIS 267
#define T_RPAREN 268
#define T_LPAREN 269
#define T_QUOTE 270
#define T_NULL 271
#define T_WS 272
#define T_END 273
#define T_COPY 274
#define T_CHARMAP 275
#define T_WIDTH 276
#define T_CTYPE 277
#define T_ISUPPER 278
#define T_ISLOWER 279
#define T_ISALPHA 280
#define T_ISDIGIT 281
#define T_ISPUNCT 282
#define T_ISXDIGIT 283
#define T_ISSPACE 284
#define T_ISPRINT 285
#define T_ISGRAPH 286
#define T_ISBLANK 287
#define T_ISCNTRL 288
#define T_ISALNUM 289
#define T_ISSPECIAL 290
#define T_ISPHONOGRAM 291
#define T_ISIDEOGRAM 292
#define T_ISENGLISH 293
#define T_ISNUMBER 294
#define T_TOUPPER 295
#define T_TOLOWER 296
#define T_COLLATE 297
#define T_COLLATING_SYMBOL 298
#define T_COLLATING_ELEMENT 299
#define T_ORDER_START 300
#define T_ORDER_END 301
#define T_FORWARD 302
#define T_BACKWARD 303
#define T_POSITION 304
#define T_FROM 305
#define T_UNDEFINED 306
#define T_IGNORE 307
#define T_MESSAGES 308
#define T_YESSTR 309
#define T_NOSTR 310
#define T_YESEXPR 311
#define T_NOEXPR 312
#define T_MONETARY 313
#define T_INT_CURR_SYMBOL 314
#define T_CURRENCY_SYMBOL 315
#define T_MON_DECIMAL_POINT 316
#define T_MON_THOUSANDS_SEP 317
#define T_POSITIVE_SIGN 318
#define T_NEGATIVE_SIGN 319
#define T_MON_GROUPING 320
#define T_INT_FRAC_DIGITS 321
#define T_FRAC_DIGITS 322
#define T_P_CS_PRECEDES 323
#define T_P_SEP_BY_SPACE 324
#define T_N_CS_PRECEDES 325
#define T_N_SEP_BY_SPACE 326
#define T_P_SIGN_POSN 327
#define T_N_SIGN_POSN 328
#define T_INT_P_CS_PRECEDES 329
#define T_INT_N_CS_PRECEDES 330
#define T_INT_P_SEP_BY_SPACE 331
#define T_INT_N_SEP_BY_SPACE 332
#define T_INT_P_SIGN_POSN 333
#define T_INT_N_SIGN_POSN 334
#define T_NUMERIC 335
#define T_DECIMAL_POINT 336
#define T_THOUSANDS_SEP 337
#define T_GROUPING 338
#define T_TIME 339
#define T_ABDAY 340
#define T_DAY 341
#define T_ABMON 342
#define T_MON 343
#define T_ERA 344
#define T_ERA_D_FMT 345
#define T_ERA_T_FMT 346
#define T_ERA_D_T_FMT 347
#define T_ALT_DIGITS 348
#define T_D_T_FMT 349
#define T_D_FMT 350
#define T_T_FMT 351
#define T_AM_PM 352
#define T_T_FMT_AMPM 353
#define T_DATE_FMT 354
#define T_CHAR 355
#define T_NAME 356
#define T_NUMBER 357
#define T_SYMBOL 358
#define T_COLLSYM 359
#define T_COLLELEM 360
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    3,    3,    4,    4,    1,    1,    5,    5,
    5,    5,    5,    5,    6,    6,    2,    2,    7,    7,
    7,    7,    7,    7,    7,    8,    8,   15,   15,   17,
   17,   17,   16,   16,   18,   18,   18,   18,   18,   18,
   18,   11,   11,   19,   19,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   21,   21,   21,   21,   21,   22,
   22,   23,   23,   23,   23,   12,   12,   12,   25,   25,
   25,   25,   26,   27,   24,   24,   29,   29,   30,   30,
   31,   31,   31,   28,   28,   32,   32,   32,   33,   33,
   33,   33,   33,   34,   34,   34,   35,   35,   35,   35,
   35,   35,   35,   36,   36,   37,   37,   37,   37,    9,
    9,   38,   38,   40,   40,   40,   40,   39,   10,   10,
   41,   41,   43,   43,   43,   43,   43,   43,   44,   44,
   44,   44,   44,   44,   44,   44,   44,   44,   44,   44,
   44,   44,   42,   42,   42,   45,   45,   13,   13,   46,
   46,   47,   47,   48,   48,   49,   49,   14,   14,   50,
   50,   51,   51,   53,   53,   53,   53,   53,   53,   53,
   52,   52,   52,   52,   52,   52,   52,   52,   54,   54,
};
static const YYINT yylen[] = {                            2,
    2,    1,    3,    2,    2,    1,    2,    1,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    6,    6,    2,    1,    2,
    4,    1,    2,    1,    3,    3,    5,    5,    5,    5,
    1,    6,    6,    2,    1,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    5,    1,    1,    3,
    1,    5,    5,    5,    5,    6,    7,    6,    2,    2,
    1,    1,    3,    5,    5,    6,    3,    1,    3,    1,
    1,    1,    1,    2,    1,    2,    2,    3,    1,    1,
    1,    1,    1,    3,    2,    1,    1,    1,    1,    1,
    1,    1,    3,    2,    1,    1,    1,    1,    1,    6,
    6,    2,    1,    1,    1,    1,    1,    3,    6,    6,
    2,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    3,    3,    3,    1,    3,    6,    6,    2,
    1,    3,    3,    1,    1,    1,    3,    6,    6,    2,
    1,    3,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    8,   18,   19,   20,
   21,   22,   23,   24,   25,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    7,   17,    4,    6,    0,   14,   13,   11,   12,
    9,   10,   32,    0,    0,   29,   41,    0,    0,    0,
   34,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   45,    0,    0,    0,    0,    0,    0,
   81,   82,  124,  125,  126,  127,    0,    0,  123,    0,
  133,  134,  135,  136,  137,  138,    0,  139,  140,  141,
  142,  143,  144,  145,  146,  147,  148,  149,  150,  151,
  152,    0,    0,  132,    0,    0,  164,  165,    0,    0,
    0,  161,    0,  174,  175,  176,  177,  178,  183,  182,
  181,  179,  184,  185,  186,  180,  187,  188,    0,    0,
  171,    0,    0,    3,    5,    0,   30,    0,   28,    0,
    0,    0,    0,    0,   33,    0,    0,   68,   69,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   71,    0,
    0,    0,   44,    0,    0,    0,   91,   92,   93,    0,
    0,   90,    0,    0,    0,   79,   80,    0,    0,  122,
    0,  156,    0,    0,    0,  131,    0,    0,  166,    0,
    0,    0,  160,    0,    0,    0,  170,    0,  190,    0,
    0,    0,    0,    0,   35,    0,    0,   36,    0,   15,
   16,   46,    0,   47,   48,   49,   50,   51,   52,   53,
   54,   55,   56,   57,   58,   62,   61,   59,   60,    0,
    0,   63,    0,   64,    0,    0,   83,    0,  100,  102,
   99,  103,    0,  101,    0,   95,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  128,  155,    0,    0,    0,
  153,  154,  163,    0,    0,    0,  162,    0,    0,  172,
  173,    0,   31,   26,    0,    0,    0,    0,   27,    0,
   65,   66,    0,    0,   70,   43,   42,    0,   96,    0,
   94,   97,  110,    0,  111,  109,  112,  108,  107,    0,
  106,    0,    0,   89,   78,   76,    0,  121,  120,  157,
  130,  129,  167,  159,  158,  169,  168,  189,   37,   39,
   40,   38,    0,    0,    0,    0,    0,   84,   85,  116,
  119,  117,  118,    0,  115,   98,    0,    0,   77,   67,
   72,   75,   73,   74,  113,  114,  104,   86,
};
static const YYINT yydgoto[] = {                         14,
   15,   16,   28,   46,   17,   82,   18,   19,   20,   21,
   22,   23,   24,   25,   55,   60,   56,   61,   83,   84,
  170,  188,  189,   89,   90,   91,   92,  275,  200,  201,
  202,  276,  277,  330,  331,  364,  365,   98,   99,  100,
  123,  124,  125,  126,  213,  131,  132,  133,  220,  150,
  151,  152,  153,  230,
};
static const YYINT yysindex[] = {                      -118,
 -268, -343, -337, -334, -329, -237, -230, -223, -221, -211,
 -204, -198, -182,    0, -118, -131,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -248, -177, -175, -163, -136,
 -116,  -90, -253, -255,   49, -244, -160,  -36, -269,  -99,
 -131,    0,    0,    0,    0, -247,    0,    0,    0,    0,
    0,    0,    0, -261, -254,    0,    0, -264, -238, -256,
    0, -258, -327, -327, -327, -327, -327, -327, -327, -327,
 -327, -327, -327, -327, -327, -327, -327, -327, -327, -122,
 -122, -108,   26,    0, -180, -169, -227,  -97,  -70, -145,
    0,    0,    0,    0,    0,    0,  -57, -226,    0,  -65,
    0,    0,    0,    0,    0,    0, -155,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -34,  -58,    0,  -65, -150,    0,    0, -137,    4,
 -257,    0,  -65,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   53, -117,
    0,  -65,  -65,    0,    0,   16,    0,  101,    0, -322,
  -42, -313,  111,  103,    0,  113,  114,    0,    0, -191,
 -143, -130,  -94,  -92,  -84,  -81,  -79,  -77,  -73,  -71,
  -68,  -66,  -64,  -55,  -53,  -51, -297,  -46,    0,   36,
  105,  107,    0,  116,   76, -228,    0,    0,    0,   38,
  117,    0,   88,   89,  115,    0,    0,   79,   81,    0,
  126,    0,   60,   78,   80,    0,  128,  130,    0,   98,
   61,   62,    0,  131,   63,   64,    0,  135,    0,  100,
   45,  137,   47,   48,    0,   50,   51,    0,  138,    0,
    0,    0, -243,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  140,
  143,    0, -122,    0,  146,  147,    0,  -65,    0,    0,
    0,    0,  148,    0, -249,    0, -263, -228, -135, -135,
  149,  150,  118,  152,  153,    0,    0,   65,  154,  155,
    0,    0,    0,   66,  156,  157,    0,  160,  161,    0,
    0,  -65,    0,    0,  162,  163,  164,  165,    0,  166,
    0,    0, -293, -229,    0,    0,    0,  168,    0,  169,
    0,    0,    0, -309,    0,    0,    0,    0,    0,  102,
    0, -242,  117,    0,    0,    0,  170,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   75,  167,  171,  172,  173,    0,    0,    0,
    0,    0,    0, -222,    0,    0, -235,  174,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  436,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  437,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  104,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  106,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  108,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  427,  -62,    0,  428,  124,   -1,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  389,  385,    0,  363,
  282,  366,  185,  359,    0,  360,  361,  175,    0,  176,
  177, -262,    0,    0,   85,    0,   90,    0,  358,    0,
    0,  335,    0,    0,    0,    0,  328,    0,    0,    0,
  310,    0,    0,    0,
};
#define YYTABLESIZE 460
static const YYINT yytable[] = {                        167,
  322,   26,  160,  323,   62,  156,  324,   57,   57,   53,
   53,   26,  321,   29,   43,  222,  164,  269,  158,   30,
   31,   44,  154,  310,  269,   32,   33,  168,  162,   62,
  169,  323,  233,   34,  324,  234,  196,  211,  269,   43,
   35,  236,   36,  325,  237,  360,  209,  375,  361,  362,
  363,  320,   37,   85,   86,   87,  270,  260,  368,   38,
  261,  354,  217,  270,  355,   39,  127,  128,  129,  321,
  224,  325,  242,  243,  197,  198,  199,  270,  127,  128,
  129,   40,   93,   94,   95,   96,   47,   27,   48,  228,
  229,  326,  161,  157,  327,  328,  329,  166,   58,   58,
   49,   59,   59,   54,   54,  271,   45,  155,  272,  273,
  274,  311,  271,   62,  312,  272,  273,  274,  163,  326,
  244,  243,  327,  328,  329,  356,  271,   50,  357,  272,
  273,  274,  360,  245,  243,  361,  362,  363,    1,    2,
    3,    4,    5,    6,    7,    8,  187,   51,   93,   94,
   95,   96,   85,   86,   87,  226,    6,    7,    8,   88,
   97,  122,  130,  149,  191,    9,  197,  198,  199,  246,
  243,  247,  243,   52,   62,  203,   10,  194,    9,  248,
  243,   11,  249,  243,  250,  243,  251,  243,  195,   10,
  252,  243,  253,  243,   11,  254,  243,  255,  243,  256,
  243,  212,  204,   12,   26,  318,  218,   13,  257,  243,
  258,  243,  259,  243,  215,  208,   12,  262,  263,  219,
   13,  235,  134,  135,  136,  137,  138,  139,  140,  141,
  142,  143,  144,  145,  146,  147,  148,   62,  214,  348,
  134,  135,  136,  137,  138,  139,  140,  141,  142,  143,
  144,  145,  146,  147,  148,  101,  102,  103,  104,  105,
  106,  107,  108,  109,  110,  111,  112,  113,  114,  115,
  116,  117,  118,  119,  120,  121,  221,  101,  102,  103,
  104,  105,  106,  107,  108,  109,  110,  111,  112,  113,
  114,  115,  116,  117,  118,  119,  120,  121,  192,  264,
  263,  278,  279,   63,   64,   65,   66,   67,   68,   69,
   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   62,  287,  288,  225,   63,   64,   65,   66,
   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,
   77,   78,   79,   80,   81,  171,  172,  173,  174,  175,
  176,  177,  178,  179,  180,  181,  182,  183,  184,  185,
  186,  293,  294,  301,  302,  366,  367,   88,   88,   87,
   87,  105,  105,  231,  238,  232,  240,  241,  239,  267,
  268,  265,  280,  266,  281,  282,  284,  283,  285,  286,
  289,  291,  290,  292,  297,  295,  296,  298,  300,  303,
  304,  309,  299,  305,  306,  313,  307,  308,  314,  316,
  317,  319,  335,  336,  337,  338,  339,  341,  342,  344,
  345,  340,  343,  346,  347,  349,  350,  351,  352,  370,
  353,  358,  359,  369,  371,    2,    1,  378,  372,  373,
  374,   41,   42,  159,  165,  193,  190,  315,  205,  206,
  207,  377,  332,  376,  333,  210,  334,  216,  223,  227,
};
static const YYINT yycheck[] = {                         62,
  264,  270,  267,  267,  274,  267,  270,  264,  264,  264,
  264,  270,  275,  357,   16,  273,  273,  267,  273,  357,
  355,  270,  270,  267,  267,  355,  264,  355,  267,  274,
  358,  267,  355,  264,  270,  358,  264,  100,  267,   41,
  264,  355,  264,  307,  358,  355,  273,  270,  358,  359,
  360,  301,  264,  298,  299,  300,  306,  355,  301,  264,
  358,  355,  125,  306,  358,  264,  336,  337,  338,  332,
  133,  307,  264,  265,  302,  303,  304,  306,  336,  337,
  338,  264,  309,  310,  311,  312,  264,  356,  264,  152,
  153,  355,  357,  355,  358,  359,  360,  356,  355,  355,
  264,  358,  358,  358,  358,  355,  355,  355,  358,  359,
  360,  355,  355,  274,  358,  358,  359,  360,  357,  355,
  264,  265,  358,  359,  360,  355,  355,  264,  358,  358,
  359,  360,  355,  264,  265,  358,  359,  360,  257,  258,
  259,  260,  261,  275,  276,  277,  269,  264,  309,  310,
  311,  312,  298,  299,  300,  273,  275,  276,  277,   36,
   37,   38,   39,   40,  273,  297,  302,  303,  304,  264,
  265,  264,  265,  264,  274,  273,  308,  358,  297,  264,
  265,  313,  264,  265,  264,  265,  264,  265,  358,  308,
  264,  265,  264,  265,  313,  264,  265,  264,  265,  264,
  265,  357,  273,  335,  270,  268,  357,  339,  264,  265,
  264,  265,  264,  265,  273,  273,  335,  264,  265,  357,
  339,  264,  340,  341,  342,  343,  344,  345,  346,  347,
  348,  349,  350,  351,  352,  353,  354,  274,  273,  302,
  340,  341,  342,  343,  344,  345,  346,  347,  348,  349,
  350,  351,  352,  353,  354,  314,  315,  316,  317,  318,
  319,  320,  321,  322,  323,  324,  325,  326,  327,  328,
  329,  330,  331,  332,  333,  334,  273,  314,  315,  316,
  317,  318,  319,  320,  321,  322,  323,  324,  325,  326,
  327,  328,  329,  330,  331,  332,  333,  334,  273,  264,
  265,  264,  265,  278,  279,  280,  281,  282,  283,  284,
  285,  286,  287,  288,  289,  290,  291,  292,  293,  294,
  295,  296,  274,  264,  265,  273,  278,  279,  280,  281,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
  292,  293,  294,  295,  296,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
   79,  264,  265,  264,  265,  264,  265,  264,  265,  264,
  265,  264,  265,  358,  264,  275,  264,  264,  276,  264,
  305,  277,  266,  277,  297,  297,  308,  273,  308,  264,
  313,  264,  313,  264,  264,  335,  335,  335,  264,  355,
  264,  264,  339,  357,  357,  266,  357,  357,  266,  264,
  264,  264,  264,  264,  297,  264,  264,  264,  264,  264,
  264,  357,  357,  264,  264,  264,  264,  264,  264,  355,
  265,  264,  264,  264,  268,    0,    0,  264,  268,  268,
  268,   15,   15,   55,   60,   83,   81,  263,   90,   90,
   90,  367,  278,  364,  279,   98,  280,  123,  131,  150,
};
#define YYFINAL 14
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 360
#define YYUNDFTOKEN 417
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_CODE_SET","T_MB_CUR_MAX",
"T_MB_CUR_MIN","T_COM_CHAR","T_ESC_CHAR","T_LT","T_GT","T_NL","T_SEMI",
"T_COMMA","T_ELLIPSIS","T_RPAREN","T_LPAREN","T_QUOTE","T_NULL","T_WS","T_END",
"T_COPY","T_CHARMAP","T_WIDTH","T_CTYPE","T_ISUPPER","T_ISLOWER","T_ISALPHA",
"T_ISDIGIT","T_ISPUNCT","T_ISXDIGIT","T_ISSPACE","T_ISPRINT","T_ISGRAPH",
"T_ISBLANK","T_ISCNTRL","T_ISALNUM","T_ISSPECIAL","T_ISPHONOGRAM",
"T_ISIDEOGRAM","T_ISENGLISH","T_ISNUMBER","T_TOUPPER","T_TOLOWER","T_COLLATE",
"T_COLLATING_SYMBOL","T_COLLATING_ELEMENT","T_ORDER_START","T_ORDER_END",
"T_FORWARD","T_BACKWARD","T_POSITION","T_FROM","T_UNDEFINED","T_IGNORE",
"T_MESSAGES","T_YESSTR","T_NOSTR","T_YESEXPR","T_NOEXPR","T_MONETARY",
"T_INT_CURR_SYMBOL","T_CURRENCY_SYMBOL","T_MON_DECIMAL_POINT",
"T_MON_THOUSANDS_SEP","T_POSITIVE_SIGN","T_NEGATIVE_SIGN","T_MON_GROUPING",
"T_INT_FRAC_DIGITS","T_FRAC_DIGITS","T_P_CS_PRECEDES","T_P_SEP_BY_SPACE",
"T_N_CS_PRECEDES","T_N_SEP_BY_SPACE","T_P_SIGN_POSN","T_N_SIGN_POSN",
"T_INT_P_CS_PRECEDES","T_INT_N_CS_PRECEDES","T_INT_P_SEP_BY_SPACE",
"T_INT_N_SEP_BY_SPACE","T_INT_P_SIGN_POSN","T_INT_N_SIGN_POSN","T_NUMERIC",
"T_DECIMAL_POINT","T_THOUSANDS_SEP","T_GROUPING","T_TIME","T_ABDAY","T_DAY",
"T_ABMON","T_MON","T_ERA","T_ERA_D_FMT","T_ERA_T_FMT","T_ERA_D_T_FMT",
"T_ALT_DIGITS","T_D_T_FMT","T_D_FMT","T_T_FMT","T_AM_PM","T_T_FMT_AMPM",
"T_DATE_FMT","T_CHAR","T_NAME","T_NUMBER","T_SYMBOL","T_COLLSYM","T_COLLELEM",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : localedef",
"localedef : setting_list categories",
"localedef : categories",
"string : T_QUOTE charlist T_QUOTE",
"string : T_QUOTE T_QUOTE",
"charlist : charlist T_CHAR",
"charlist : T_CHAR",
"setting_list : setting_list setting",
"setting_list : setting",
"setting : T_COM_CHAR T_CHAR T_NL",
"setting : T_ESC_CHAR T_CHAR T_NL",
"setting : T_MB_CUR_MAX T_NUMBER T_NL",
"setting : T_MB_CUR_MIN T_NUMBER T_NL",
"setting : T_CODE_SET string T_NL",
"setting : T_CODE_SET T_NAME T_NL",
"copycat : T_COPY T_NAME T_NL",
"copycat : T_COPY string T_NL",
"categories : categories category",
"categories : category",
"category : charmap",
"category : messages",
"category : monetary",
"category : ctype",
"category : collate",
"category : numeric",
"category : time",
"charmap : T_CHARMAP T_NL charmap_list T_END T_CHARMAP T_NL",
"charmap : T_WIDTH T_NL width_list T_END T_WIDTH T_NL",
"charmap_list : charmap_list charmap_entry",
"charmap_list : charmap_entry",
"charmap_entry : T_SYMBOL T_CHAR",
"charmap_entry : T_SYMBOL T_ELLIPSIS T_SYMBOL T_CHAR",
"charmap_entry : T_NL",
"width_list : width_list width_entry",
"width_list : width_entry",
"width_entry : T_CHAR T_NUMBER T_NL",
"width_entry : T_SYMBOL T_NUMBER T_NL",
"width_entry : T_CHAR T_ELLIPSIS T_CHAR T_NUMBER T_NL",
"width_entry : T_SYMBOL T_ELLIPSIS T_SYMBOL T_NUMBER T_NL",
"width_entry : T_CHAR T_ELLIPSIS T_SYMBOL T_NUMBER T_NL",
"width_entry : T_SYMBOL T_ELLIPSIS T_CHAR T_NUMBER T_NL",
"width_entry : T_NL",
"ctype : T_CTYPE T_NL ctype_list T_END T_CTYPE T_NL",
"ctype : T_CTYPE T_NL copycat T_END T_CTYPE T_NL",
"ctype_list : ctype_list ctype_kw",
"ctype_list : ctype_kw",
"ctype_kw : T_ISUPPER cc_list T_NL",
"ctype_kw : T_ISLOWER cc_list T_NL",
"ctype_kw : T_ISALPHA cc_list T_NL",
"ctype_kw : T_ISDIGIT cc_list T_NL",
"ctype_kw : T_ISPUNCT cc_list T_NL",
"ctype_kw : T_ISXDIGIT cc_list T_NL",
"ctype_kw : T_ISSPACE cc_list T_NL",
"ctype_kw : T_ISPRINT cc_list T_NL",
"ctype_kw : T_ISGRAPH cc_list T_NL",
"ctype_kw : T_ISBLANK cc_list T_NL",
"ctype_kw : T_ISCNTRL cc_list T_NL",
"ctype_kw : T_ISALNUM cc_list T_NL",
"ctype_kw : T_ISSPECIAL cc_list T_NL",
"ctype_kw : T_ISENGLISH cc_list T_NL",
"ctype_kw : T_ISNUMBER cc_list T_NL",
"ctype_kw : T_ISIDEOGRAM cc_list T_NL",
"ctype_kw : T_ISPHONOGRAM cc_list T_NL",
"ctype_kw : T_TOUPPER conv_list T_NL",
"ctype_kw : T_TOLOWER conv_list T_NL",
"cc_list : cc_list T_SEMI T_CHAR",
"cc_list : cc_list T_SEMI T_SYMBOL",
"cc_list : cc_list T_SEMI T_ELLIPSIS T_SEMI T_CHAR",
"cc_list : T_CHAR",
"cc_list : T_SYMBOL",
"conv_list : conv_list T_SEMI conv_pair",
"conv_list : conv_pair",
"conv_pair : T_LPAREN T_CHAR T_COMMA T_CHAR T_RPAREN",
"conv_pair : T_LPAREN T_SYMBOL T_COMMA T_CHAR T_RPAREN",
"conv_pair : T_LPAREN T_SYMBOL T_COMMA T_SYMBOL T_RPAREN",
"conv_pair : T_LPAREN T_CHAR T_COMMA T_SYMBOL T_RPAREN",
"collate : T_COLLATE T_NL coll_order T_END T_COLLATE T_NL",
"collate : T_COLLATE T_NL coll_optional coll_order T_END T_COLLATE T_NL",
"collate : T_COLLATE T_NL copycat T_END T_COLLATE T_NL",
"coll_optional : coll_optional coll_symbols",
"coll_optional : coll_optional coll_elements",
"coll_optional : coll_symbols",
"coll_optional : coll_elements",
"coll_symbols : T_COLLATING_SYMBOL T_SYMBOL T_NL",
"coll_elements : T_COLLATING_ELEMENT T_SYMBOL T_FROM string T_NL",
"coll_order : T_ORDER_START T_NL order_list T_ORDER_END T_NL",
"coll_order : T_ORDER_START order_args T_NL order_list T_ORDER_END T_NL",
"order_args : order_args T_SEMI order_arg",
"order_args : order_arg",
"order_arg : order_arg T_COMMA order_dir",
"order_arg : order_dir",
"order_dir : T_FORWARD",
"order_dir : T_BACKWARD",
"order_dir : T_POSITION",
"order_list : order_list order_item",
"order_list : order_item",
"order_item : T_COLLSYM T_NL",
"order_item : order_itemkw T_NL",
"order_item : order_itemkw order_weights T_NL",
"order_itemkw : T_CHAR",
"order_itemkw : T_ELLIPSIS",
"order_itemkw : T_COLLELEM",
"order_itemkw : T_UNDEFINED",
"order_itemkw : T_SYMBOL",
"order_weights : order_weights T_SEMI order_weight",
"order_weights : order_weights T_SEMI",
"order_weights : order_weight",
"order_weight : T_COLLELEM",
"order_weight : T_COLLSYM",
"order_weight : T_CHAR",
"order_weight : T_ELLIPSIS",
"order_weight : T_IGNORE",
"order_weight : T_SYMBOL",
"order_weight : T_QUOTE order_str T_QUOTE",
"order_str : order_str order_stritem",
"order_str : order_stritem",
"order_stritem : T_CHAR",
"order_stritem : T_COLLSYM",
"order_stritem : T_COLLELEM",
"order_stritem : T_SYMBOL",
"messages : T_MESSAGES T_NL messages_list T_END T_MESSAGES T_NL",
"messages : T_MESSAGES T_NL copycat T_END T_MESSAGES T_NL",
"messages_list : messages_list messages_item",
"messages_list : messages_item",
"messages_kw : T_YESSTR",
"messages_kw : T_NOSTR",
"messages_kw : T_YESEXPR",
"messages_kw : T_NOEXPR",
"messages_item : messages_kw string T_NL",
"monetary : T_MONETARY T_NL monetary_list T_END T_MONETARY T_NL",
"monetary : T_MONETARY T_NL copycat T_END T_MONETARY T_NL",
"monetary_list : monetary_list monetary_kw",
"monetary_list : monetary_kw",
"monetary_strkw : T_INT_CURR_SYMBOL",
"monetary_strkw : T_CURRENCY_SYMBOL",
"monetary_strkw : T_MON_DECIMAL_POINT",
"monetary_strkw : T_MON_THOUSANDS_SEP",
"monetary_strkw : T_POSITIVE_SIGN",
"monetary_strkw : T_NEGATIVE_SIGN",
"monetary_numkw : T_INT_FRAC_DIGITS",
"monetary_numkw : T_FRAC_DIGITS",
"monetary_numkw : T_P_CS_PRECEDES",
"monetary_numkw : T_P_SEP_BY_SPACE",
"monetary_numkw : T_N_CS_PRECEDES",
"monetary_numkw : T_N_SEP_BY_SPACE",
"monetary_numkw : T_P_SIGN_POSN",
"monetary_numkw : T_N_SIGN_POSN",
"monetary_numkw : T_INT_P_CS_PRECEDES",
"monetary_numkw : T_INT_N_CS_PRECEDES",
"monetary_numkw : T_INT_P_SEP_BY_SPACE",
"monetary_numkw : T_INT_N_SEP_BY_SPACE",
"monetary_numkw : T_INT_P_SIGN_POSN",
"monetary_numkw : T_INT_N_SIGN_POSN",
"monetary_kw : monetary_strkw string T_NL",
"monetary_kw : monetary_numkw T_NUMBER T_NL",
"monetary_kw : T_MON_GROUPING mon_group_list T_NL",
"mon_group_list : T_NUMBER",
"mon_group_list : mon_group_list T_SEMI T_NUMBER",
"numeric : T_NUMERIC T_NL numeric_list T_END T_NUMERIC T_NL",
"numeric : T_NUMERIC T_NL copycat T_END T_NUMERIC T_NL",
"numeric_list : numeric_list numeric_item",
"numeric_list : numeric_item",
"numeric_item : numeric_strkw string T_NL",
"numeric_item : T_GROUPING group_list T_NL",
"numeric_strkw : T_DECIMAL_POINT",
"numeric_strkw : T_THOUSANDS_SEP",
"group_list : T_NUMBER",
"group_list : group_list T_SEMI T_NUMBER",
"time : T_TIME T_NL time_kwlist T_END T_TIME T_NL",
"time : T_TIME T_NL copycat T_END T_NUMERIC T_NL",
"time_kwlist : time_kwlist time_kw",
"time_kwlist : time_kw",
"time_kw : time_strkw string T_NL",
"time_kw : time_listkw time_list T_NL",
"time_listkw : T_ABDAY",
"time_listkw : T_DAY",
"time_listkw : T_ABMON",
"time_listkw : T_MON",
"time_listkw : T_ERA",
"time_listkw : T_ALT_DIGITS",
"time_listkw : T_AM_PM",
"time_strkw : T_ERA_D_T_FMT",
"time_strkw : T_ERA_T_FMT",
"time_strkw : T_ERA_D_FMT",
"time_strkw : T_D_T_FMT",
"time_strkw : T_D_FMT",
"time_strkw : T_T_FMT",
"time_strkw : T_T_FMT_AMPM",
"time_strkw : T_DATE_FMT",
"time_list : time_list T_SEMI string",
"time_list : string",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 5:
#line 166 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_wcs(yystack.l_mark[0].wc);
		}
break;
case 6:
#line 170 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_wcs(yystack.l_mark[0].wc);
		}
break;
case 9:
#line 181 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			com_char = yystack.l_mark[-1].wc;
		}
break;
case 10:
#line 185 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			esc_char = yystack.l_mark[-1].wc;
		}
break;
case 11:
#line 189 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			mb_cur_max = yystack.l_mark[-1].num;
		}
break;
case 12:
#line 193 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			mb_cur_min = yystack.l_mark[-1].num;
		}
break;
case 13:
#line 197 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			wchar_t *w = get_wcs();
			set_wide_encoding(to_mb_string(w));
			free(w);
		}
break;
case 14:
#line 203 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			set_wide_encoding(yystack.l_mark[-1].token);
		}
break;
case 15:
#line 209 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			copy_category(yystack.l_mark[-1].token);
		}
break;
case 16:
#line 213 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			wchar_t *w = get_wcs();
			copy_category(to_mb_string(w));
			free(w);
		}
break;
case 30:
#line 246 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_charmap(yystack.l_mark[-1].token, yystack.l_mark[0].wc);
			scan_to_eol();
		}
break;
case 31:
#line 251 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_charmap_range(yystack.l_mark[-3].token, yystack.l_mark[-1].token, yystack.l_mark[0].wc);
			scan_to_eol();
		}
break;
case 35:
#line 263 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_width(yystack.l_mark[-2].wc, yystack.l_mark[-1].num);
		}
break;
case 36:
#line 267 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_charmap_undefined(yystack.l_mark[-2].token);
		}
break;
case 37:
#line 271 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_width_range(yystack.l_mark[-4].wc, yystack.l_mark[-2].wc, yystack.l_mark[-1].num);
		}
break;
case 38:
#line 275 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_charmap_undefined(yystack.l_mark[-4].token);
			add_charmap_undefined(yystack.l_mark[-2].token);
		}
break;
case 39:
#line 280 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_width(yystack.l_mark[-4].wc, yystack.l_mark[-1].num);
			add_charmap_undefined(yystack.l_mark[-2].token);
		}
break;
case 40:
#line 285 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_width(yystack.l_mark[-2].wc, yystack.l_mark[-1].num);
			add_charmap_undefined(yystack.l_mark[-4].token);
		}
break;
case 42:
#line 293 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			dump_ctype();
		}
break;
case 65:
#line 326 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_ctype(yystack.l_mark[0].wc);
		}
break;
case 66:
#line 330 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_charmap_undefined(yystack.l_mark[0].token);
		}
break;
case 67:
#line 334 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			/* note that the endpoints *must* be characters */
			add_ctype_range(yystack.l_mark[0].wc);
		}
break;
case 68:
#line 339 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_ctype(yystack.l_mark[0].wc);
		}
break;
case 69:
#line 343 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_charmap_undefined(yystack.l_mark[0].token);
		}
break;
case 72:
#line 354 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_caseconv(yystack.l_mark[-3].wc, yystack.l_mark[-1].wc);
		}
break;
case 73:
#line 358 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_charmap_undefined(yystack.l_mark[-3].token);
		}
break;
case 74:
#line 362 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_charmap_undefined(yystack.l_mark[-3].token);
			add_charmap_undefined(yystack.l_mark[-1].token);
		}
break;
case 75:
#line 367 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_charmap_undefined(yystack.l_mark[-1].token);
		}
break;
case 76:
#line 373 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			dump_collate();
		}
break;
case 77:
#line 377 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			dump_collate();
		}
break;
case 83:
#line 392 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			define_collsym(yystack.l_mark[-1].token);
		}
break;
case 84:
#line 399 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			define_collelem(yystack.l_mark[-3].token, get_wcs());
		}
break;
case 85:
#line 405 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			/* If no order list supplied default to one forward */
			add_order_bit(T_FORWARD);
			add_order_directive();
		}
break;
case 87:
#line 415 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_order_directive();
		}
break;
case 88:
#line 419 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_order_directive();
		}
break;
case 91:
#line 429 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_order_bit(T_FORWARD);
		}
break;
case 92:
#line 433 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_order_bit(T_BACKWARD);
		}
break;
case 93:
#line 437 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_order_bit(T_POSITION);
		}
break;
case 96:
#line 447 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			end_order_collsym(yystack.l_mark[-1].collsym);
		}
break;
case 97:
#line 451 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			end_order();
		}
break;
case 98:
#line 455 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			end_order();
		}
break;
case 99:
#line 461 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			start_order_char(yystack.l_mark[0].wc);
		}
break;
case 100:
#line 465 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			start_order_ellipsis();
		}
break;
case 101:
#line 469 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			start_order_collelem(yystack.l_mark[0].collelem);
		}
break;
case 102:
#line 473 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			start_order_undefined();
		}
break;
case 103:
#line 477 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			start_order_symbol(yystack.l_mark[0].token);
		}
break;
case 107:
#line 488 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_order_collelem(yystack.l_mark[0].collelem);
		}
break;
case 108:
#line 492 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_order_collsym(yystack.l_mark[0].collsym);
		}
break;
case 109:
#line 496 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_order_char(yystack.l_mark[0].wc);
		}
break;
case 110:
#line 500 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_order_ellipsis();
		}
break;
case 111:
#line 504 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_order_ignore();
		}
break;
case 112:
#line 508 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_order_symbol(yystack.l_mark[0].token);
		}
break;
case 113:
#line 512 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_order_subst();
		}
break;
case 116:
#line 522 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_subst_char(yystack.l_mark[0].wc);
		}
break;
case 117:
#line 526 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_subst_collsym(yystack.l_mark[0].collsym);
		}
break;
case 118:
#line 530 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_subst_collelem(yystack.l_mark[0].collelem);
		}
break;
case 119:
#line 534 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_subst_symbol(yystack.l_mark[0].token);
		}
break;
case 120:
#line 540 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			dump_messages();
		}
break;
case 128:
#line 557 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_message(get_wcs());
		}
break;
case 129:
#line 563 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			dump_monetary();
		}
break;
case 153:
#line 598 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_monetary_str(get_wcs());
		}
break;
case 154:
#line 602 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_monetary_num(yystack.l_mark[-1].num);
		}
break;
case 156:
#line 609 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			reset_monetary_group();
			add_monetary_group(yystack.l_mark[0].num);
		}
break;
case 157:
#line 614 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_monetary_group(yystack.l_mark[0].num);
		}
break;
case 158:
#line 621 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			dump_numeric();
		}
break;
case 162:
#line 634 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_numeric_str(get_wcs());
		}
break;
case 166:
#line 646 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			reset_numeric_group();
			add_numeric_group(yystack.l_mark[0].num);
		}
break;
case 167:
#line 651 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_numeric_group(yystack.l_mark[0].num);
		}
break;
case 168:
#line 658 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			dump_time();
		}
break;
case 172:
#line 669 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_time_str(get_wcs());
		}
break;
case 173:
#line 673 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			check_time_list();
		}
break;
case 189:
#line 698 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			add_time_list(get_wcs());
		}
break;
case 190:
#line 702 "/usr/home/freebsd/omega/src/usr.bin/localedef/parser.y"
	{
			reset_time_list();
			add_time_list(get_wcs());
		}
break;
#line 1413 "parser.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
