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

#line 2 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
/*-
 * Copyright (c) 2012 The FreeBSD Foundation
 * All rights reserved.
 *
 * This software was developed by Edward Tomasz Napierala under sponsorship
 * from the FreeBSD Foundation.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#include <sys/queue.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ctld.h"

extern FILE *yyin;
extern char *yytext;
extern int lineno;

static struct conf *conf = NULL;
static struct auth_group *auth_group = NULL;
static struct portal_group *portal_group = NULL;
static struct target *target = NULL;
static struct lun *lun = NULL;

extern void	yyerror(const char *);
extern int	yylex(void);
extern void	yyrestart(FILE *);

#line 67 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
	char *str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 89 "y.tab.c"

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

#define ALIAS 257
#define AUTH_GROUP 258
#define AUTH_TYPE 259
#define BACKEND 260
#define BLOCKSIZE 261
#define CHAP 262
#define CHAP_MUTUAL 263
#define CLOSING_BRACKET 264
#define CTL_LUN 265
#define DEBUG 266
#define DEVICE_ID 267
#define DEVICE_TYPE 268
#define DISCOVERY_AUTH_GROUP 269
#define DISCOVERY_FILTER 270
#define FOREIGN 271
#define INITIATOR_NAME 272
#define INITIATOR_PORTAL 273
#define ISNS_SERVER 274
#define ISNS_PERIOD 275
#define ISNS_TIMEOUT 276
#define LISTEN 277
#define LISTEN_ISER 278
#define LUN 279
#define MAXPROC 280
#define OFFLOAD 281
#define OPENING_BRACKET 282
#define OPTION 283
#define PATH 284
#define PIDFILE 285
#define PORT 286
#define PORTAL_GROUP 287
#define REDIRECT 288
#define SEMICOLON 289
#define SERIAL 290
#define SIZE 291
#define STR 292
#define TAG 293
#define TARGET 294
#define TIMEOUT 295
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    3,    4,    5,    6,    7,
    8,    9,   13,   14,   14,   14,   15,   15,   15,   15,
   15,   16,   17,   18,   19,   20,   10,   21,   22,   22,
   22,   23,   23,   23,   23,   23,   23,   23,   23,   23,
   24,   25,   26,   27,   28,   29,   30,   31,   32,   11,
   33,   12,   35,   36,   36,   36,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   45,   46,   47,   48,
   50,   49,   34,   34,   34,   51,   51,   51,   51,   51,
   51,   51,   51,   51,   52,   53,   54,   55,   56,   57,
   58,   59,   60,
};
static const YYINT yylen[] = {                            2,
    0,    2,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    5,    1,    0,    2,    3,    1,    1,    1,    1,
    1,    2,    3,    5,    2,    2,    5,    1,    0,    2,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    2,    2,    1,    2,    2,    2,    3,    2,    2,    5,
    1,    5,    1,    0,    2,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    2,    2,
    2,    3,    5,    2,    2,    3,    2,    2,    2,    5,
    1,    3,    0,    2,    3,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    2,    2,    2,    2,    3,
    2,    2,    2,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    4,    5,    6,    7,    8,    9,   10,
   11,   12,   13,   14,   23,    0,   15,   19,   20,   21,
   61,    0,   17,   18,   38,    0,   63,    0,   16,    3,
   24,   93,   39,   64,    0,    0,    0,    0,    0,    0,
    0,   22,    0,    0,    0,   27,   28,   29,   30,   31,
    0,    0,   60,    0,    0,    0,    0,    0,    0,    0,
    0,   96,   97,   98,   99,  100,  101,  102,  103,  104,
   37,    0,    0,   53,    0,    0,    0,    0,    0,    0,
    0,   42,   43,   44,   45,   46,   47,   48,   49,   50,
    0,    0,    0,    0,    0,   62,    0,    0,    0,    0,
    0,    0,    0,   67,   68,   69,   70,   71,   72,   73,
   74,   75,   76,   77,   78,   32,    0,    0,   35,   36,
   26,  105,  106,  109,  107,  108,    0,  111,  112,  113,
   95,   51,   52,   54,   55,   56,    0,   58,   59,   41,
   79,   80,   81,    0,    0,   84,   85,    0,    0,   88,
    0,   89,   66,   33,    0,  110,   57,   82,    0,   92,
   93,   86,    0,    0,    0,   34,   83,   90,
};
static const YYINT yydgoto[] = {                          1,
   13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
   23,   24,   26,   45,   55,   56,   57,   58,   59,   60,
   36,   47,   91,   92,   93,   94,   95,   96,   97,   98,
   99,  100,   32,   46,   38,   48,  113,  114,  115,  116,
  117,  118,  119,  120,  121,  122,  123,  124,  125,  159,
   71,   72,   73,   74,   75,   76,   77,   78,   79,   80,
};
static const YYINT yysindex[] = {                         0,
 -258, -290, -289, -288, -287, -285, -280, -279, -278, -277,
 -269, -268, -264,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -256,    0,    0,    0,    0,
    0, -254,    0,    0,    0, -252,    0, -251,    0,    0,
    0,    0,    0,    0, -253, -170, -121, -212, -260, -250,
 -249,    0, -248, -239, -235,    0,    0,    0,    0,    0,
 -236, -234,    0, -233, -226, -223, -222, -221, -220, -219,
 -232,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -211, -207,    0, -206, -205, -204, -203, -196, -192,
 -209,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -191, -190, -189, -188, -187,    0, -183, -182, -175, -168,
 -167, -164, -158,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -160, -159,    0,    0,
    0,    0,    0,    0,    0,    0, -156,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -155,    0,    0,    0,
    0,    0,    0, -154, -153,    0,    0, -152, -241,    0,
 -148,    0,    0,    0, -145,    0,    0,    0, -141,    0,
    0,    0, -137, -134, -149,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -98,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -138,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -101,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -180,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -214,    0,    0,
 -224,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -17,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 296
static const YYINT yytable[] = {                          2,
    2,   25,   27,   28,   29,   49,   30,    3,   50,   51,
   52,   31,   33,   34,   35,    4,    5,    6,   53,   54,
    7,    8,   37,   39,   40,   41,    9,   42,   10,   43,
   44,  126,   87,   87,   87,   11,   12,   87,   87,   87,
  171,  127,  128,  129,  101,  102,  103,   87,   87,  104,
  105,  106,  130,  131,   87,  132,  141,  133,  134,  107,
  108,   87,   87,   87,   87,  135,  109,   91,  136,  137,
  138,  139,  140,  110,  111,  112,   65,   65,   65,  150,
  142,   65,   65,   65,  143,  144,  145,  146,  147,   61,
   62,   65,   65,   63,   64,  148,   65,   66,   65,  149,
  151,  152,  153,  154,  155,   65,   65,   65,  156,  157,
   61,   62,   67,   68,  178,   64,  158,   65,   66,   69,
   70,   94,   94,  160,  161,   94,   94,  162,   94,   94,
  163,  164,  165,   67,   68,  166,  167,  168,  169,  170,
   69,   70,   81,  172,   94,   94,  173,   82,   83,   84,
  174,   94,   94,  175,  176,   85,   86,  177,    0,   87,
   25,   88,   40,   25,   25,   25,   89,   40,   40,   40,
    0,   90,    0,   25,   25,   40,   40,    0,    0,   40,
    0,   40,    0,    0,    0,    0,   40,    0,    0,    0,
    0,   40,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    2,    0,
    0,    0,    0,    0,    0,    0,    2,    0,    0,    0,
    0,    0,    0,    0,    2,    2,    2,    0,    0,    2,
    2,    0,    0,    0,    0,    2,    0,    2,    0,    0,
    0,    0,    0,    0,    2,    2,
};
static const YYINT yycheck[] = {                        258,
    0,  292,  292,  292,  292,  259,  292,  266,  262,  263,
  264,  292,  292,  292,  292,  274,  275,  276,  272,  273,
  279,  280,  292,  292,  289,  282,  285,  282,  287,  282,
  282,  292,  257,  258,  259,  294,  295,  262,  263,  264,
  282,  292,  292,  292,  257,  258,  259,  272,  273,  262,
  263,  264,  292,  289,  279,  292,  289,  292,  292,  272,
  273,  286,  287,  288,  289,  292,  279,  282,  292,  292,
  292,  292,  292,  286,  287,  288,  257,  258,  259,  289,
  292,  262,  263,  264,  292,  292,  292,  292,  292,  260,
  261,  272,  273,  264,  265,  292,  267,  268,  279,  292,
  292,  292,  292,  292,  292,  286,  287,  288,  292,  292,
  260,  261,  283,  284,  264,  265,  292,  267,  268,  290,
  291,  260,  261,  292,  292,  264,  265,  292,  267,  268,
  289,  292,  292,  283,  284,  292,  292,  292,  292,  292,
  290,  291,  264,  292,  283,  284,  292,  269,  270,  271,
  292,  290,  291,  171,  292,  277,  278,  292,   -1,  281,
  259,  283,  264,  262,  263,  264,  288,  269,  270,  271,
   -1,  293,   -1,  272,  273,  277,  278,   -1,   -1,  281,
   -1,  283,   -1,   -1,   -1,   -1,  288,   -1,   -1,   -1,
   -1,  293,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  266,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  274,  275,  276,   -1,   -1,  279,
  280,   -1,   -1,   -1,   -1,  285,   -1,  287,   -1,   -1,
   -1,   -1,   -1,   -1,  294,  295,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 295
#define YYUNDFTOKEN 358
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ALIAS","AUTH_GROUP","AUTH_TYPE",
"BACKEND","BLOCKSIZE","CHAP","CHAP_MUTUAL","CLOSING_BRACKET","CTL_LUN","DEBUG",
"DEVICE_ID","DEVICE_TYPE","DISCOVERY_AUTH_GROUP","DISCOVERY_FILTER","FOREIGN",
"INITIATOR_NAME","INITIATOR_PORTAL","ISNS_SERVER","ISNS_PERIOD","ISNS_TIMEOUT",
"LISTEN","LISTEN_ISER","LUN","MAXPROC","OFFLOAD","OPENING_BRACKET","OPTION",
"PATH","PIDFILE","PORT","PORTAL_GROUP","REDIRECT","SEMICOLON","SERIAL","SIZE",
"STR","TAG","TARGET","TIMEOUT",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : statements",
"statements :",
"statements : statements statement",
"statements : statements statement SEMICOLON",
"statement : debug",
"statement : timeout",
"statement : maxproc",
"statement : pidfile",
"statement : isns_server",
"statement : isns_period",
"statement : isns_timeout",
"statement : auth_group",
"statement : portal_group",
"statement : lun",
"statement : target",
"debug : DEBUG STR",
"timeout : TIMEOUT STR",
"maxproc : MAXPROC STR",
"pidfile : PIDFILE STR",
"isns_server : ISNS_SERVER STR",
"isns_period : ISNS_PERIOD STR",
"isns_timeout : ISNS_TIMEOUT STR",
"auth_group : AUTH_GROUP auth_group_name OPENING_BRACKET auth_group_entries CLOSING_BRACKET",
"auth_group_name : STR",
"auth_group_entries :",
"auth_group_entries : auth_group_entries auth_group_entry",
"auth_group_entries : auth_group_entries auth_group_entry SEMICOLON",
"auth_group_entry : auth_group_auth_type",
"auth_group_entry : auth_group_chap",
"auth_group_entry : auth_group_chap_mutual",
"auth_group_entry : auth_group_initiator_name",
"auth_group_entry : auth_group_initiator_portal",
"auth_group_auth_type : AUTH_TYPE STR",
"auth_group_chap : CHAP STR STR",
"auth_group_chap_mutual : CHAP_MUTUAL STR STR STR STR",
"auth_group_initiator_name : INITIATOR_NAME STR",
"auth_group_initiator_portal : INITIATOR_PORTAL STR",
"portal_group : PORTAL_GROUP portal_group_name OPENING_BRACKET portal_group_entries CLOSING_BRACKET",
"portal_group_name : STR",
"portal_group_entries :",
"portal_group_entries : portal_group_entries portal_group_entry",
"portal_group_entries : portal_group_entries portal_group_entry SEMICOLON",
"portal_group_entry : portal_group_discovery_auth_group",
"portal_group_entry : portal_group_discovery_filter",
"portal_group_entry : portal_group_foreign",
"portal_group_entry : portal_group_listen",
"portal_group_entry : portal_group_listen_iser",
"portal_group_entry : portal_group_offload",
"portal_group_entry : portal_group_option",
"portal_group_entry : portal_group_redirect",
"portal_group_entry : portal_group_tag",
"portal_group_discovery_auth_group : DISCOVERY_AUTH_GROUP STR",
"portal_group_discovery_filter : DISCOVERY_FILTER STR",
"portal_group_foreign : FOREIGN",
"portal_group_listen : LISTEN STR",
"portal_group_listen_iser : LISTEN_ISER STR",
"portal_group_offload : OFFLOAD STR",
"portal_group_option : OPTION STR STR",
"portal_group_redirect : REDIRECT STR",
"portal_group_tag : TAG STR",
"lun : LUN lun_name OPENING_BRACKET lun_entries CLOSING_BRACKET",
"lun_name : STR",
"target : TARGET target_name OPENING_BRACKET target_entries CLOSING_BRACKET",
"target_name : STR",
"target_entries :",
"target_entries : target_entries target_entry",
"target_entries : target_entries target_entry SEMICOLON",
"target_entry : target_alias",
"target_entry : target_auth_group",
"target_entry : target_auth_type",
"target_entry : target_chap",
"target_entry : target_chap_mutual",
"target_entry : target_initiator_name",
"target_entry : target_initiator_portal",
"target_entry : target_portal_group",
"target_entry : target_port",
"target_entry : target_redirect",
"target_entry : target_lun",
"target_entry : target_lun_ref",
"target_alias : ALIAS STR",
"target_auth_group : AUTH_GROUP STR",
"target_auth_type : AUTH_TYPE STR",
"target_chap : CHAP STR STR",
"target_chap_mutual : CHAP_MUTUAL STR STR STR STR",
"target_initiator_name : INITIATOR_NAME STR",
"target_initiator_portal : INITIATOR_PORTAL STR",
"target_portal_group : PORTAL_GROUP STR STR",
"target_portal_group : PORTAL_GROUP STR",
"target_port : PORT STR",
"target_redirect : REDIRECT STR",
"target_lun : LUN lun_number OPENING_BRACKET lun_entries CLOSING_BRACKET",
"lun_number : STR",
"target_lun_ref : LUN STR STR",
"lun_entries :",
"lun_entries : lun_entries lun_entry",
"lun_entries : lun_entries lun_entry SEMICOLON",
"lun_entry : lun_backend",
"lun_entry : lun_blocksize",
"lun_entry : lun_device_id",
"lun_entry : lun_device_type",
"lun_entry : lun_ctl_lun",
"lun_entry : lun_option",
"lun_entry : lun_path",
"lun_entry : lun_serial",
"lun_entry : lun_size",
"lun_backend : BACKEND STR",
"lun_blocksize : BLOCKSIZE STR",
"lun_device_id : DEVICE_ID STR",
"lun_device_type : DEVICE_TYPE STR",
"lun_ctl_lun : CTL_LUN STR",
"lun_option : OPTION STR STR",
"lun_path : PATH STR",
"lun_serial : SERIAL STR",
"lun_size : SIZE STR",

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
#line 1038 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"

void
yyerror(const char *str)
{

	log_warnx("error in configuration file at line %d near '%s': %s",
	    lineno, yytext, str);
}

static void
check_perms(const char *path)
{
	struct stat sb;
	int error;

	error = stat(path, &sb);
	if (error != 0) {
		log_warn("stat");
		return;
	}
	if (sb.st_mode & S_IWOTH) {
		log_warnx("%s is world-writable", path);
	} else if (sb.st_mode & S_IROTH) {
		log_warnx("%s is world-readable", path);
	} else if (sb.st_mode & S_IXOTH) {
		/*
		 * Ok, this one doesn't matter, but still do it,
		 * just for consistency.
		 */
		log_warnx("%s is world-executable", path);
	}

	/*
	 * XXX: Should we also check for owner != 0?
	 */
}

struct conf *
conf_new_from_file(const char *path, struct conf *oldconf)
{
	struct auth_group *ag;
	struct portal_group *pg;
	struct pport *pp;
	int error;

	log_debugx("obtaining configuration from %s", path);

	conf = conf_new();

	TAILQ_FOREACH(pp, &oldconf->conf_pports, pp_next)
		pport_copy(pp, conf);

	ag = auth_group_new(conf, "default");
	assert(ag != NULL);

	ag = auth_group_new(conf, "no-authentication");
	assert(ag != NULL);
	ag->ag_type = AG_TYPE_NO_AUTHENTICATION;

	ag = auth_group_new(conf, "no-access");
	assert(ag != NULL);
	ag->ag_type = AG_TYPE_DENY;

	pg = portal_group_new(conf, "default");
	assert(pg != NULL);

	yyin = fopen(path, "r");
	if (yyin == NULL) {
		log_warn("unable to open configuration file %s", path);
		conf_delete(conf);
		return (NULL);
	}
	check_perms(path);
	lineno = 1;
	yyrestart(yyin);
	error = yyparse();
	auth_group = NULL;
	portal_group = NULL;
	target = NULL;
	lun = NULL;
	fclose(yyin);
	if (error != 0) {
		conf_delete(conf);
		return (NULL);
	}

	if (conf->conf_default_ag_defined == false) {
		log_debugx("auth-group \"default\" not defined; "
		    "going with defaults");
		ag = auth_group_find(conf, "default");
		assert(ag != NULL);
		ag->ag_type = AG_TYPE_DENY;
	}

	if (conf->conf_default_pg_defined == false) {
		log_debugx("portal-group \"default\" not defined; "
		    "going with defaults");
		pg = portal_group_find(conf, "default");
		assert(pg != NULL);
		portal_group_add_listen(pg, "0.0.0.0:3260", false);
		portal_group_add_listen(pg, "[::]:3260", false);
	}

	conf->conf_kernel_port_on = true;

	error = conf_verify(conf);
	if (error != 0) {
		conf_delete(conf);
		return (NULL);
	}

	return (conf);
}
#line 624 "y.tab.c"

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
case 15:
#line 108 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		uint64_t tmp;

		if (expand_number(yystack.l_mark[0].str, &tmp) != 0) {
			yyerror("invalid numeric value");
			free(yystack.l_mark[0].str);
			return (1);
		}
			
		conf->conf_debug = tmp;
	}
break;
case 16:
#line 122 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		uint64_t tmp;

		if (expand_number(yystack.l_mark[0].str, &tmp) != 0) {
			yyerror("invalid numeric value");
			free(yystack.l_mark[0].str);
			return (1);
		}

		conf->conf_timeout = tmp;
	}
break;
case 17:
#line 136 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		uint64_t tmp;

		if (expand_number(yystack.l_mark[0].str, &tmp) != 0) {
			yyerror("invalid numeric value");
			free(yystack.l_mark[0].str);
			return (1);
		}

		conf->conf_maxproc = tmp;
	}
break;
case 18:
#line 150 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		if (conf->conf_pidfile_path != NULL) {
			log_warnx("pidfile specified more than once");
			free(yystack.l_mark[0].str);
			return (1);
		}
		conf->conf_pidfile_path = yystack.l_mark[0].str;
	}
break;
case 19:
#line 161 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		int error;

		error = isns_new(conf, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (error != 0)
			return (1);
	}
break;
case 20:
#line 172 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		uint64_t tmp;

		if (expand_number(yystack.l_mark[0].str, &tmp) != 0) {
			yyerror("invalid numeric value");
			free(yystack.l_mark[0].str);
			return (1);
		}

		conf->conf_isns_period = tmp;
	}
break;
case 21:
#line 186 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		uint64_t tmp;

		if (expand_number(yystack.l_mark[0].str, &tmp) != 0) {
			yyerror("invalid numeric value");
			free(yystack.l_mark[0].str);
			return (1);
		}

		conf->conf_isns_timeout = tmp;
	}
break;
case 22:
#line 201 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		auth_group = NULL;
	}
break;
case 23:
#line 207 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		/*
		 * Make it possible to redefine default
		 * auth-group. but only once.
		 */
		if (strcmp(yystack.l_mark[0].str, "default") == 0 &&
		    conf->conf_default_ag_defined == false) {
			auth_group = auth_group_find(conf, yystack.l_mark[0].str);
			conf->conf_default_ag_defined = true;
		} else {
			auth_group = auth_group_new(conf, yystack.l_mark[0].str);
		}
		free(yystack.l_mark[0].str);
		if (auth_group == NULL)
			return (1);
	}
break;
case 32:
#line 245 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		int error;

		error = auth_group_set_type(auth_group, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (error != 0)
			return (1);
	}
break;
case 33:
#line 256 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		const struct auth *ca;

		ca = auth_new_chap(auth_group, yystack.l_mark[-1].str, yystack.l_mark[0].str);
		free(yystack.l_mark[-1].str);
		free(yystack.l_mark[0].str);
		if (ca == NULL)
			return (1);
	}
break;
case 34:
#line 268 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		const struct auth *ca;

		ca = auth_new_chap_mutual(auth_group, yystack.l_mark[-3].str, yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str);
		free(yystack.l_mark[-3].str);
		free(yystack.l_mark[-2].str);
		free(yystack.l_mark[-1].str);
		free(yystack.l_mark[0].str);
		if (ca == NULL)
			return (1);
	}
break;
case 35:
#line 282 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		const struct auth_name *an;

		an = auth_name_new(auth_group, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (an == NULL)
			return (1);
	}
break;
case 36:
#line 293 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		const struct auth_portal *ap;

		ap = auth_portal_new(auth_group, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (ap == NULL)
			return (1);
	}
break;
case 37:
#line 305 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		portal_group = NULL;
	}
break;
case 38:
#line 311 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		/*
		 * Make it possible to redefine default
		 * portal-group. but only once.
		 */
		if (strcmp(yystack.l_mark[0].str, "default") == 0 &&
		    conf->conf_default_pg_defined == false) {
			portal_group = portal_group_find(conf, yystack.l_mark[0].str);
			conf->conf_default_pg_defined = true;
		} else {
			portal_group = portal_group_new(conf, yystack.l_mark[0].str);
		}
		free(yystack.l_mark[0].str);
		if (portal_group == NULL)
			return (1);
	}
break;
case 51:
#line 357 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		if (portal_group->pg_discovery_auth_group != NULL) {
			log_warnx("discovery-auth-group for portal-group "
			    "\"%s\" specified more than once",
			    portal_group->pg_name);
			return (1);
		}
		portal_group->pg_discovery_auth_group =
		    auth_group_find(conf, yystack.l_mark[0].str);
		if (portal_group->pg_discovery_auth_group == NULL) {
			log_warnx("unknown discovery-auth-group \"%s\" "
			    "for portal-group \"%s\"",
			    yystack.l_mark[0].str, portal_group->pg_name);
			return (1);
		}
		free(yystack.l_mark[0].str);
	}
break;
case 52:
#line 377 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		int error;

		error = portal_group_set_filter(portal_group, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (error != 0)
			return (1);
	}
break;
case 53:
#line 388 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{

		portal_group->pg_foreign = 1;
	}
break;
case 54:
#line 395 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		int error;

		error = portal_group_add_listen(portal_group, yystack.l_mark[0].str, false);
		free(yystack.l_mark[0].str);
		if (error != 0)
			return (1);
	}
break;
case 55:
#line 406 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		int error;

		error = portal_group_add_listen(portal_group, yystack.l_mark[0].str, true);
		free(yystack.l_mark[0].str);
		if (error != 0)
			return (1);
	}
break;
case 56:
#line 417 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		int error;

		error = portal_group_set_offload(portal_group, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (error != 0)
			return (1);
	}
break;
case 57:
#line 428 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		struct option *o;

		o = option_new(&portal_group->pg_options, yystack.l_mark[-1].str, yystack.l_mark[0].str);
		free(yystack.l_mark[-1].str);
		free(yystack.l_mark[0].str);
		if (o == NULL)
			return (1);
	}
break;
case 58:
#line 440 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		int error;

		error = portal_group_set_redirection(portal_group, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (error != 0)
			return (1);
	}
break;
case 59:
#line 451 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		uint64_t tmp;

		if (expand_number(yystack.l_mark[0].str, &tmp) != 0) {
			yyerror("invalid numeric value");
			free(yystack.l_mark[0].str);
			return (1);
		}

		portal_group->pg_tag = tmp;
	}
break;
case 60:
#line 466 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		lun = NULL;
	}
break;
case 61:
#line 472 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		lun = lun_new(conf, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (lun == NULL)
			return (1);
	}
break;
case 62:
#line 482 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		target = NULL;
	}
break;
case 63:
#line 488 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		target = target_new(conf, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (target == NULL)
			return (1);
	}
break;
case 79:
#line 530 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		if (target->t_alias != NULL) {
			log_warnx("alias for target \"%s\" "
			    "specified more than once", target->t_name);
			return (1);
		}
		target->t_alias = yystack.l_mark[0].str;
	}
break;
case 80:
#line 541 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		if (target->t_auth_group != NULL) {
			if (target->t_auth_group->ag_name != NULL)
				log_warnx("auth-group for target \"%s\" "
				    "specified more than once", target->t_name);
			else
				log_warnx("cannot use both auth-group and explicit "
				    "authorisations for target \"%s\"",
				    target->t_name);
			return (1);
		}
		target->t_auth_group = auth_group_find(conf, yystack.l_mark[0].str);
		if (target->t_auth_group == NULL) {
			log_warnx("unknown auth-group \"%s\" for target "
			    "\"%s\"", yystack.l_mark[0].str, target->t_name);
			return (1);
		}
		free(yystack.l_mark[0].str);
	}
break;
case 81:
#line 563 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		int error;

		if (target->t_auth_group != NULL) {
			if (target->t_auth_group->ag_name != NULL) {
				log_warnx("cannot use both auth-group and "
				    "auth-type for target \"%s\"",
				    target->t_name);
				return (1);
			}
		} else {
			target->t_auth_group = auth_group_new(conf, NULL);
			if (target->t_auth_group == NULL) {
				free(yystack.l_mark[0].str);
				return (1);
			}
			target->t_auth_group->ag_target = target;
		}
		error = auth_group_set_type(target->t_auth_group, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (error != 0)
			return (1);
	}
break;
case 82:
#line 589 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		const struct auth *ca;

		if (target->t_auth_group != NULL) {
			if (target->t_auth_group->ag_name != NULL) {
				log_warnx("cannot use both auth-group and "
				    "chap for target \"%s\"",
				    target->t_name);
				free(yystack.l_mark[-1].str);
				free(yystack.l_mark[0].str);
				return (1);
			}
		} else {
			target->t_auth_group = auth_group_new(conf, NULL);
			if (target->t_auth_group == NULL) {
				free(yystack.l_mark[-1].str);
				free(yystack.l_mark[0].str);
				return (1);
			}
			target->t_auth_group->ag_target = target;
		}
		ca = auth_new_chap(target->t_auth_group, yystack.l_mark[-1].str, yystack.l_mark[0].str);
		free(yystack.l_mark[-1].str);
		free(yystack.l_mark[0].str);
		if (ca == NULL)
			return (1);
	}
break;
case 83:
#line 619 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		const struct auth *ca;

		if (target->t_auth_group != NULL) {
			if (target->t_auth_group->ag_name != NULL) {
				log_warnx("cannot use both auth-group and "
				    "chap-mutual for target \"%s\"",
				    target->t_name);
				free(yystack.l_mark[-3].str);
				free(yystack.l_mark[-2].str);
				free(yystack.l_mark[-1].str);
				free(yystack.l_mark[0].str);
				return (1);
			}
		} else {
			target->t_auth_group = auth_group_new(conf, NULL);
			if (target->t_auth_group == NULL) {
				free(yystack.l_mark[-3].str);
				free(yystack.l_mark[-2].str);
				free(yystack.l_mark[-1].str);
				free(yystack.l_mark[0].str);
				return (1);
			}
			target->t_auth_group->ag_target = target;
		}
		ca = auth_new_chap_mutual(target->t_auth_group,
		    yystack.l_mark[-3].str, yystack.l_mark[-2].str, yystack.l_mark[-1].str, yystack.l_mark[0].str);
		free(yystack.l_mark[-3].str);
		free(yystack.l_mark[-2].str);
		free(yystack.l_mark[-1].str);
		free(yystack.l_mark[0].str);
		if (ca == NULL)
			return (1);
	}
break;
case 84:
#line 656 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		const struct auth_name *an;

		if (target->t_auth_group != NULL) {
			if (target->t_auth_group->ag_name != NULL) {
				log_warnx("cannot use both auth-group and "
				    "initiator-name for target \"%s\"",
				    target->t_name);
				free(yystack.l_mark[0].str);
				return (1);
			}
		} else {
			target->t_auth_group = auth_group_new(conf, NULL);
			if (target->t_auth_group == NULL) {
				free(yystack.l_mark[0].str);
				return (1);
			}
			target->t_auth_group->ag_target = target;
		}
		an = auth_name_new(target->t_auth_group, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (an == NULL)
			return (1);
	}
break;
case 85:
#line 683 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		const struct auth_portal *ap;

		if (target->t_auth_group != NULL) {
			if (target->t_auth_group->ag_name != NULL) {
				log_warnx("cannot use both auth-group and "
				    "initiator-portal for target \"%s\"",
				    target->t_name);
				free(yystack.l_mark[0].str);
				return (1);
			}
		} else {
			target->t_auth_group = auth_group_new(conf, NULL);
			if (target->t_auth_group == NULL) {
				free(yystack.l_mark[0].str);
				return (1);
			}
			target->t_auth_group->ag_target = target;
		}
		ap = auth_portal_new(target->t_auth_group, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (ap == NULL)
			return (1);
	}
break;
case 86:
#line 710 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		struct portal_group *tpg;
		struct auth_group *tag;
		struct port *tp;

		tpg = portal_group_find(conf, yystack.l_mark[-1].str);
		if (tpg == NULL) {
			log_warnx("unknown portal-group \"%s\" for target "
			    "\"%s\"", yystack.l_mark[-1].str, target->t_name);
			free(yystack.l_mark[-1].str);
			free(yystack.l_mark[0].str);
			return (1);
		}
		tag = auth_group_find(conf, yystack.l_mark[0].str);
		if (tag == NULL) {
			log_warnx("unknown auth-group \"%s\" for target "
			    "\"%s\"", yystack.l_mark[0].str, target->t_name);
			free(yystack.l_mark[-1].str);
			free(yystack.l_mark[0].str);
			return (1);
		}
		tp = port_new(conf, target, tpg);
		if (tp == NULL) {
			log_warnx("can't link portal-group \"%s\" to target "
			    "\"%s\"", yystack.l_mark[-1].str, target->t_name);
			free(yystack.l_mark[-1].str);
			return (1);
		}
		tp->p_auth_group = tag;
		free(yystack.l_mark[-1].str);
		free(yystack.l_mark[0].str);
	}
break;
case 87:
#line 743 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		struct portal_group *tpg;
		struct port *tp;

		tpg = portal_group_find(conf, yystack.l_mark[0].str);
		if (tpg == NULL) {
			log_warnx("unknown portal-group \"%s\" for target "
			    "\"%s\"", yystack.l_mark[0].str, target->t_name);
			free(yystack.l_mark[0].str);
			return (1);
		}
		tp = port_new(conf, target, tpg);
		if (tp == NULL) {
			log_warnx("can't link portal-group \"%s\" to target "
			    "\"%s\"", yystack.l_mark[0].str, target->t_name);
			free(yystack.l_mark[0].str);
			return (1);
		}
		free(yystack.l_mark[0].str);
	}
break;
case 88:
#line 766 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		struct pport *pp;
		struct port *tp;

		pp = pport_find(conf, yystack.l_mark[0].str);
		if (pp == NULL) {
			log_warnx("unknown port \"%s\" for target \"%s\"",
			    yystack.l_mark[0].str, target->t_name);
			free(yystack.l_mark[0].str);
			return (1);
		}
		if (!TAILQ_EMPTY(&pp->pp_ports)) {
			log_warnx("can't link port \"%s\" to target \"%s\", "
			    "port already linked to some target",
			    yystack.l_mark[0].str, target->t_name);
			free(yystack.l_mark[0].str);
			return (1);
		}
		tp = port_new_pp(conf, target, pp);
		if (tp == NULL) {
			log_warnx("can't link port \"%s\" to target \"%s\"",
			    yystack.l_mark[0].str, target->t_name);
			free(yystack.l_mark[0].str);
			return (1);
		}
		free(yystack.l_mark[0].str);
	}
break;
case 89:
#line 796 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		int error;

		error = target_set_redirection(target, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (error != 0)
			return (1);
	}
break;
case 90:
#line 808 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		lun = NULL;
	}
break;
case 91:
#line 814 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		uint64_t tmp;
		int ret;
		char *name;

		if (expand_number(yystack.l_mark[0].str, &tmp) != 0) {
			yyerror("invalid numeric value");
			free(yystack.l_mark[0].str);
			return (1);
		}

		ret = asprintf(&name, "%s,lun,%ju", target->t_name, tmp);
		if (ret <= 0)
			log_err(1, "asprintf");
		lun = lun_new(conf, name);
		if (lun == NULL)
			return (1);

		lun_set_scsiname(lun, name);
		target->t_luns[tmp] = lun;
	}
break;
case 92:
#line 838 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		uint64_t tmp;

		if (expand_number(yystack.l_mark[-1].str, &tmp) != 0) {
			yyerror("invalid numeric value");
			free(yystack.l_mark[-1].str);
			free(yystack.l_mark[0].str);
			return (1);
		}
		free(yystack.l_mark[-1].str);

		lun = lun_find(conf, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
		if (lun == NULL)
			return (1);

		target->t_luns[tmp] = lun;
	}
break;
case 105:
#line 886 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		if (lun->l_backend != NULL) {
			log_warnx("backend for lun \"%s\" "
			    "specified more than once",
			    lun->l_name);
			free(yystack.l_mark[0].str);
			return (1);
		}
		lun_set_backend(lun, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 106:
#line 900 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		uint64_t tmp;

		if (expand_number(yystack.l_mark[0].str, &tmp) != 0) {
			yyerror("invalid numeric value");
			free(yystack.l_mark[0].str);
			return (1);
		}

		if (lun->l_blocksize != 0) {
			log_warnx("blocksize for lun \"%s\" "
			    "specified more than once",
			    lun->l_name);
			return (1);
		}
		lun_set_blocksize(lun, tmp);
	}
break;
case 107:
#line 920 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		if (lun->l_device_id != NULL) {
			log_warnx("device_id for lun \"%s\" "
			    "specified more than once",
			    lun->l_name);
			free(yystack.l_mark[0].str);
			return (1);
		}
		lun_set_device_id(lun, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 108:
#line 934 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		uint64_t tmp;

		if (strcasecmp(yystack.l_mark[0].str, "disk") == 0 ||
		    strcasecmp(yystack.l_mark[0].str, "direct") == 0)
			tmp = 0;
		else if (strcasecmp(yystack.l_mark[0].str, "processor") == 0)
			tmp = 3;
		else if (strcasecmp(yystack.l_mark[0].str, "cd") == 0 ||
		    strcasecmp(yystack.l_mark[0].str, "cdrom") == 0 ||
		    strcasecmp(yystack.l_mark[0].str, "dvd") == 0 ||
		    strcasecmp(yystack.l_mark[0].str, "dvdrom") == 0)
			tmp = 5;
		else if (expand_number(yystack.l_mark[0].str, &tmp) != 0 ||
		    tmp > 15) {
			yyerror("invalid numeric value");
			free(yystack.l_mark[0].str);
			return (1);
		}

		lun_set_device_type(lun, tmp);
	}
break;
case 109:
#line 959 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		uint64_t tmp;

		if (expand_number(yystack.l_mark[0].str, &tmp) != 0) {
			yyerror("invalid numeric value");
			free(yystack.l_mark[0].str);
			return (1);
		}

		if (lun->l_ctl_lun >= 0) {
			log_warnx("ctl_lun for lun \"%s\" "
			    "specified more than once",
			    lun->l_name);
			return (1);
		}
		lun_set_ctl_lun(lun, tmp);
	}
break;
case 110:
#line 979 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		struct option *o;

		o = option_new(&lun->l_options, yystack.l_mark[-1].str, yystack.l_mark[0].str);
		free(yystack.l_mark[-1].str);
		free(yystack.l_mark[0].str);
		if (o == NULL)
			return (1);
	}
break;
case 111:
#line 991 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		if (lun->l_path != NULL) {
			log_warnx("path for lun \"%s\" "
			    "specified more than once",
			    lun->l_name);
			free(yystack.l_mark[0].str);
			return (1);
		}
		lun_set_path(lun, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 112:
#line 1005 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		if (lun->l_serial != NULL) {
			log_warnx("serial for lun \"%s\" "
			    "specified more than once",
			    lun->l_name);
			free(yystack.l_mark[0].str);
			return (1);
		}
		lun_set_serial(lun, yystack.l_mark[0].str);
		free(yystack.l_mark[0].str);
	}
break;
case 113:
#line 1019 "/usr/home/freebsd/omega/src/usr.sbin/ctld/parse.y"
	{
		uint64_t tmp;

		if (expand_number(yystack.l_mark[0].str, &tmp) != 0) {
			yyerror("invalid numeric value");
			free(yystack.l_mark[0].str);
			return (1);
		}

		if (lun->l_size != 0) {
			log_warnx("size for lun \"%s\" "
			    "specified more than once",
			    lun->l_name);
			return (1);
		}
		lun_set_size(lun, tmp);
	}
break;
#line 1648 "y.tab.c"
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
