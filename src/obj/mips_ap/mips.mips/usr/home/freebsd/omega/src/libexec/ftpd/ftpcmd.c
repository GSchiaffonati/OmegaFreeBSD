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

#line 38 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"

#ifndef lint
#if 0
static char sccsid[] = "@(#)ftpcmd.y	8.3 (Berkeley) 4/6/94";
#endif
#endif /* not lint */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/param.h>
#include <sys/socket.h>
#include <sys/stat.h>

#include <netinet/in.h>
#include <arpa/ftp.h>

#include <ctype.h>
#include <errno.h>
#include <glob.h>
#include <libutil.h>
#include <limits.h>
#include <md5.h>
#include <netdb.h>
#include <pwd.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>

#include "extern.h"
#include "pathnames.h"

off_t	restart_point;

static	int cmd_type;
static	int cmd_form;
static	int cmd_bytesz;
static	int state;
char	cbuf[512];
char	*fromname = NULL;

#line 86 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct {
		off_t	o;
		int	i;
	} u;
	char   *s;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 83 "ftpcmd.c"

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

#define A 257
#define B 258
#define C 259
#define E 260
#define F 261
#define I 262
#define L 263
#define N 264
#define P 265
#define R 266
#define S 267
#define T 268
#define ALL 269
#define SP 270
#define CRLF 271
#define COMMA 272
#define USER 273
#define PASS 274
#define ACCT 275
#define REIN 276
#define QUIT 277
#define PORT 278
#define PASV 279
#define TYPE 280
#define STRU 281
#define MODE 282
#define RETR 283
#define STOR 284
#define APPE 285
#define MLFL 286
#define MAIL 287
#define MSND 288
#define MSOM 289
#define MSAM 290
#define MRSQ 291
#define MRCP 292
#define ALLO 293
#define REST 294
#define RNFR 295
#define RNTO 296
#define ABOR 297
#define DELE 298
#define CWD 299
#define LIST 300
#define NLST 301
#define SITE 302
#define STAT 303
#define HELP 304
#define NOOP 305
#define MKD 306
#define RMD 307
#define PWD 308
#define CDUP 309
#define STOU 310
#define SMNT 311
#define SYST 312
#define SIZE 313
#define MDTM 314
#define LPRT 315
#define LPSV 316
#define EPRT 317
#define EPSV 318
#define FEAT 319
#define UMASK 320
#define IDLE 321
#define CHMOD 322
#define MDFIVE 323
#define LEXERR 324
#define NOTIMPL 325
#define STRING 326
#define NUMBER 327
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   15,   15,   13,   12,
   12,    3,   16,   17,   17,    9,    9,    9,    8,    8,
    8,    8,    8,    8,    8,    8,    6,    6,    6,    7,
    7,    7,   11,   10,    2,    1,    5,    4,
};
static const YYINT yylen[] = {                            2,
    0,    2,    2,    4,    4,    2,    5,    5,    5,    3,
    3,    5,    5,    3,    5,    5,    5,    5,    9,    5,
    5,    5,    3,    5,    3,    5,    5,    3,    5,    5,
    3,    3,    5,    2,    4,    2,    5,    5,    3,    3,
    4,    6,    7,    5,    7,    9,    5,    7,    5,    2,
    3,    5,    5,    2,    1,    1,    5,    5,    1,    0,
    1,    1,   11,   41,   17,    1,    1,    1,    1,    3,
    1,    3,    1,    1,    3,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    0,    0,    0,
};
static const YYINT yydefred[] = {                         1,
    0,   56,    0,    0,    0,   86,   86,   86,   86,   86,
   86,   88,   88,   86,   86,   88,   88,   86,   88,   86,
   86,   86,    0,   86,    0,    0,   88,   88,   86,   86,
   88,   86,   86,   86,   86,   86,   86,   87,    0,   55,
    2,    3,    0,    0,    6,   54,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   34,   36,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   50,   59,    0,   61,    0,    0,   10,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   31,    0,    0,
   32,    0,   25,    0,   23,    0,   86,   88,   86,    0,
    0,   28,    0,    0,    0,   39,   40,    0,   51,    0,
    0,    0,   11,    0,    0,   14,    4,    5,    0,    0,
    0,    0,   73,    0,    0,   77,   79,   78,    0,   81,
   82,   80,    0,   84,   83,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   41,    0,    0,
    0,    0,    0,   35,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    7,    0,    0,    0,   62,
   76,   15,   16,   17,   20,   21,   22,    0,   18,   58,
   57,   30,   29,   33,   26,   24,    0,    0,   44,    0,
    0,    0,   47,   27,   37,   38,   49,   52,   53,    0,
    8,    9,   13,   12,    0,   68,   66,   67,   70,   72,
   75,    0,   42,   85,    0,    0,    0,    0,    0,    0,
    0,   45,    0,   43,   48,    0,    0,    0,    0,    0,
    0,   19,   46,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   63,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   64,
};
static const YYINT yydgoto[] = {                          1,
   47,  225,  181,   53,   80,  139,  143,  135,  219,  145,
  146,   85,   83,   41,   42,  130,  171,
};
static const YYINT yysindex[] = {                         0,
 -135,    0, -268, -222, -257,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -252,    0, -220, -244,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -235,    0,
    0,    0, -284, -272,    0,    0, -207, -202, -196, -174,
 -173, -172, -171, -170, -168, -167, -166, -165, -191, -164,
 -194, -192, -189, -258, -187, -219,    0,    0, -162, -160,
 -159, -158, -156, -155, -153, -152, -151, -149, -150, -185,
    0,    0, -148,    0, -147, -216,    0, -190, -226, -242,
 -211, -211, -211, -201, -200, -211, -211,    0, -211, -211,
    0, -211,    0, -211,    0, -182,    0,    0,    0, -188,
 -211,    0, -146, -211, -211,    0,    0, -211,    0, -211,
 -211, -199,    0, -197, -266,    0,    0,    0, -141, -137,
 -134, -133,    0, -259, -136,    0,    0,    0, -131,    0,
    0,    0, -120,    0,    0, -119, -118, -117, -180, -116,
 -115, -114,  -95,  -86,  -85,  -84, -138,    0, -178,  -81,
  -79, -176,  -78,    0,  -77,  -76,  -75,  -74,  -73,  -80,
  -72,  -71,  -70,  -69, -124,    0, -193, -193, -123,    0,
    0,    0,    0,    0,    0,    0,    0,  -61,    0,    0,
    0,    0,    0,    0,    0,    0,  -65, -113,    0, -113,
 -211, -112,    0,    0,    0,    0,    0,    0,    0, -111,
    0,    0,    0,    0,  -64,    0,    0,    0,    0,    0,
    0,  -63,    0,    0,  -62,  -60,  -59,  -58,  -55, -109,
 -108,    0, -211,    0,    0, -107,  -51,  -49,  -48,  -47,
 -103,    0,    0, -101,  -45,  -44,  -98,  -97,  -41,  -40,
  -94,  -93,    0,  -37,  -91,  -35,  -88,  -34,  -87,  -31,
  -83,  -30,  -82,  -29,  -68,  -26,  -67,  -25,  -66,  -24,
  -57,  -23,  -56,  -22,  -54,  -21,  -53,  -20,  -52,  -19,
  -50,  -18,  -46,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -16,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -110,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -15,  -14,    0,  -13,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,   -9,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   23,   63,   85,   -7,    0,    0,    0,    0,   87,  -89,
  -92,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 281
static const YYINT yytable[] = {                        147,
  148,   43,  173,  151,  152,   54,  153,  154,   57,   58,
  179,   60,  155,   46,  156,  140,  141,   64,  163,   69,
   70,  165,  166,   73,  142,  167,   68,  168,  169,   48,
   49,   50,   51,   52,  136,   81,   55,   56,  137,  138,
   59,   82,   61,   62,   63,  106,   65,   44,   45,   66,
   67,   71,   72,   84,   74,   75,   76,   77,   78,   79,
  174,  107,   86,  108,  109,  216,  131,  180,   87,  132,
  217,  133,  134,   88,  218,  100,  101,  102,  103,   98,
  104,  105,  111,  112,  125,  126,  110,  157,  158,  188,
  189,  198,  199,  202,  203,   89,   90,   91,   92,   93,
  160,   94,   95,   96,   97,   99,  113,  114,  227,  115,
  129,  116,  117,  118,  144,  119,  120,  121,  122,  124,
    2,  123,  127,  128,  164,  149,  150,  170,  172,  159,
  175,  161,  162,  176,  182,  177,  178,    3,    4,  183,
  239,    5,    6,    7,    8,    9,   10,   11,   12,   13,
  184,  185,  186,  187,  190,  191,  192,   14,   15,   16,
   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,
   27,   28,   29,   30,   31,  193,   32,   33,   34,   35,
   36,   37,   38,   39,  194,  195,  196,  197,  200,   40,
  201,  210,  204,  205,  206,  207,  208,  209,  211,  212,
  213,  214,  215,  180,  222,  223,  231,  230,  232,  233,
   86,  234,  235,  224,  228,  229,  236,  237,  238,  240,
  241,  242,  243,  245,  244,  246,  247,  248,  249,  250,
  251,  252,  253,  254,  255,  256,  257,  259,  258,  260,
  261,  263,  265,  262,  264,  267,  269,  271,  273,  275,
  277,  279,  281,  283,   60,   69,   71,   74,  266,  268,
  270,   65,  226,  221,  220,    0,    0,    0,    0,  272,
  274,    0,  276,  278,  280,    0,  282,    0,    0,    0,
  284,
};
static const YYINT yycheck[] = {                         92,
   93,  270,  269,   96,   97,   13,   99,  100,   16,   17,
  270,   19,  102,  271,  104,  258,  259,  270,  111,   27,
   28,  114,  115,   31,  267,  118,  271,  120,  121,    7,
    8,    9,   10,   11,  261,  271,   14,   15,  265,  266,
   18,  326,   20,   21,   22,  304,   24,  270,  271,  270,
  271,   29,   30,  326,   32,   33,   34,   35,   36,   37,
  327,  320,  270,  322,  323,  259,  257,  327,  271,  260,
  264,  262,  263,  270,  268,  270,  271,  270,  271,  271,
  270,  271,  270,  271,  270,  271,   64,  270,  271,  270,
  271,  270,  271,  270,  271,  270,  270,  270,  270,  270,
  108,  270,  270,  270,  270,  270,  326,  270,  201,  270,
  327,  271,  271,  270,  326,  271,  270,  270,  270,  270,
  256,  271,  271,  271,  271,  327,  327,  327,  326,  107,
  272,  109,  321,  271,  271,  270,  270,  273,  274,  271,
  233,  277,  278,  279,  280,  281,  282,  283,  284,  285,
  271,  271,  271,  271,  271,  271,  271,  293,  294,  295,
  296,  297,  298,  299,  300,  301,  302,  303,  304,  305,
  306,  307,  308,  309,  310,  271,  312,  313,  314,  315,
  316,  317,  318,  319,  271,  271,  271,  326,  270,  325,
  270,  272,  271,  271,  271,  271,  271,  271,  271,  271,
  271,  271,  327,  327,  266,  271,  270,  272,  271,  270,
  321,  271,  271,  327,  327,  327,  272,  327,  327,  327,
  272,  271,  271,  327,  272,  327,  272,  272,  327,  327,
  272,  272,  327,  327,  272,  327,  272,  272,  327,  327,
  272,  272,  272,  327,  327,  272,  272,  272,  272,  272,
  272,  272,  272,  272,  271,  271,  271,  271,  327,  327,
  327,  271,  200,  179,  178,   -1,   -1,   -1,   -1,  327,
  327,   -1,  327,  327,  327,   -1,  327,   -1,   -1,   -1,
  327,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 327
#define YYUNDFTOKEN 347
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"A","B","C","E","F","I","L","N",
"P","R","S","T","ALL","SP","CRLF","COMMA","USER","PASS","ACCT","REIN","QUIT",
"PORT","PASV","TYPE","STRU","MODE","RETR","STOR","APPE","MLFL","MAIL","MSND",
"MSOM","MSAM","MRSQ","MRCP","ALLO","REST","RNFR","RNTO","ABOR","DELE","CWD",
"LIST","NLST","SITE","STAT","HELP","NOOP","MKD","RMD","PWD","CDUP","STOU",
"SMNT","SYST","SIZE","MDTM","LPRT","LPSV","EPRT","EPSV","FEAT","UMASK","IDLE",
"CHMOD","MDFIVE","LEXERR","NOTIMPL","STRING","NUMBER",0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : cmd_list",
"cmd_list :",
"cmd_list : cmd_list cmd",
"cmd_list : cmd_list rcmd",
"cmd : USER SP username CRLF",
"cmd : PASS SP password CRLF",
"cmd : PASS CRLF",
"cmd : PORT check_login SP host_port CRLF",
"cmd : LPRT check_login SP host_long_port CRLF",
"cmd : EPRT check_login SP STRING CRLF",
"cmd : PASV check_login CRLF",
"cmd : LPSV check_login CRLF",
"cmd : EPSV check_login_epsv SP NUMBER CRLF",
"cmd : EPSV check_login_epsv SP ALL CRLF",
"cmd : EPSV check_login_epsv CRLF",
"cmd : TYPE check_login SP type_code CRLF",
"cmd : STRU check_login SP struct_code CRLF",
"cmd : MODE check_login SP mode_code CRLF",
"cmd : ALLO check_login SP NUMBER CRLF",
"cmd : ALLO check_login SP NUMBER SP R SP NUMBER CRLF",
"cmd : RETR check_login SP pathname CRLF",
"cmd : STOR check_login_ro SP pathname CRLF",
"cmd : APPE check_login_ro SP pathname CRLF",
"cmd : NLST check_login CRLF",
"cmd : NLST check_login SP pathstring CRLF",
"cmd : LIST check_login CRLF",
"cmd : LIST check_login SP pathstring CRLF",
"cmd : STAT check_login SP pathname CRLF",
"cmd : STAT check_login CRLF",
"cmd : DELE check_login_ro SP pathname CRLF",
"cmd : RNTO check_login_ro SP pathname CRLF",
"cmd : ABOR check_login CRLF",
"cmd : CWD check_login CRLF",
"cmd : CWD check_login SP pathname CRLF",
"cmd : HELP CRLF",
"cmd : HELP SP STRING CRLF",
"cmd : NOOP CRLF",
"cmd : MKD check_login_ro SP pathname CRLF",
"cmd : RMD check_login_ro SP pathname CRLF",
"cmd : PWD check_login CRLF",
"cmd : CDUP check_login CRLF",
"cmd : SITE SP HELP CRLF",
"cmd : SITE SP HELP SP STRING CRLF",
"cmd : SITE SP MDFIVE check_login SP pathname CRLF",
"cmd : SITE SP UMASK check_login CRLF",
"cmd : SITE SP UMASK check_login SP octal_number CRLF",
"cmd : SITE SP CHMOD check_login_ro SP octal_number SP pathname CRLF",
"cmd : SITE SP check_login IDLE CRLF",
"cmd : SITE SP check_login IDLE SP NUMBER CRLF",
"cmd : STOU check_login_ro SP pathname CRLF",
"cmd : FEAT CRLF",
"cmd : SYST check_login CRLF",
"cmd : SIZE check_login SP pathname CRLF",
"cmd : MDTM check_login SP pathname CRLF",
"cmd : QUIT CRLF",
"cmd : NOTIMPL",
"cmd : error",
"rcmd : RNFR check_login_ro SP pathname CRLF",
"rcmd : REST check_login SP NUMBER CRLF",
"username : STRING",
"password :",
"password : STRING",
"byte_size : NUMBER",
"host_port : NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER",
"host_long_port : NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER",
"host_long_port : NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER COMMA NUMBER",
"form_code : N",
"form_code : T",
"form_code : C",
"type_code : A",
"type_code : A SP form_code",
"type_code : E",
"type_code : E SP form_code",
"type_code : I",
"type_code : L",
"type_code : L SP byte_size",
"type_code : L byte_size",
"struct_code : F",
"struct_code : R",
"struct_code : P",
"mode_code : S",
"mode_code : B",
"mode_code : C",
"pathname : pathstring",
"pathstring : STRING",
"octal_number : NUMBER",
"check_login :",
"check_login_epsv :",
"check_login_ro :",

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
#line 1043 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"

#define	CMD	0	/* beginning of command */
#define	ARGS	1	/* expect miscellaneous arguments */
#define	STR1	2	/* expect SP followed by STRING */
#define	STR2	3	/* expect STRING */
#define	OSTR	4	/* optional SP then STRING */
#define	ZSTR1	5	/* optional SP then optional STRING */
#define	ZSTR2	6	/* optional STRING after SP */
#define	SITECMD	7	/* SITE command */
#define	NSTR	8	/* Number followed by a string */

#define	MAXGLOBARGS	1000

#define	MAXASIZE	10240	/* Deny ASCII SIZE on files larger than that */

struct tab {
	char	*name;
	short	token;
	short	state;
	short	implemented;	/* 1 if command is implemented */
	char	*help;
};

struct tab cmdtab[] = {		/* In order defined in RFC 765 */
	{ "USER", USER, STR1, 1,	"<sp> username" },
	{ "PASS", PASS, ZSTR1, 1,	"[<sp> [password]]" },
	{ "ACCT", ACCT, STR1, 0,	"(specify account)" },
	{ "SMNT", SMNT, ARGS, 0,	"(structure mount)" },
	{ "REIN", REIN, ARGS, 0,	"(reinitialize server state)" },
	{ "QUIT", QUIT, ARGS, 1,	"(terminate service)", },
	{ "PORT", PORT, ARGS, 1,	"<sp> b0, b1, b2, b3, b4, b5" },
	{ "LPRT", LPRT, ARGS, 1,	"<sp> af, hal, h1, h2, h3,..., pal, p1, p2..." },
	{ "EPRT", EPRT, STR1, 1,	"<sp> |af|addr|port|" },
	{ "PASV", PASV, ARGS, 1,	"(set server in passive mode)" },
	{ "LPSV", LPSV, ARGS, 1,	"(set server in passive mode)" },
	{ "EPSV", EPSV, ARGS, 1,	"[<sp> af|ALL]" },
	{ "TYPE", TYPE, ARGS, 1,	"<sp> { A | E | I | L }" },
	{ "STRU", STRU, ARGS, 1,	"(specify file structure)" },
	{ "MODE", MODE, ARGS, 1,	"(specify transfer mode)" },
	{ "RETR", RETR, STR1, 1,	"<sp> file-name" },
	{ "STOR", STOR, STR1, 1,	"<sp> file-name" },
	{ "APPE", APPE, STR1, 1,	"<sp> file-name" },
	{ "MLFL", MLFL, OSTR, 0,	"(mail file)" },
	{ "MAIL", MAIL, OSTR, 0,	"(mail to user)" },
	{ "MSND", MSND, OSTR, 0,	"(mail send to terminal)" },
	{ "MSOM", MSOM, OSTR, 0,	"(mail send to terminal or mailbox)" },
	{ "MSAM", MSAM, OSTR, 0,	"(mail send to terminal and mailbox)" },
	{ "MRSQ", MRSQ, OSTR, 0,	"(mail recipient scheme question)" },
	{ "MRCP", MRCP, STR1, 0,	"(mail recipient)" },
	{ "ALLO", ALLO, ARGS, 1,	"allocate storage (vacuously)" },
	{ "REST", REST, ARGS, 1,	"<sp> offset (restart command)" },
	{ "RNFR", RNFR, STR1, 1,	"<sp> file-name" },
	{ "RNTO", RNTO, STR1, 1,	"<sp> file-name" },
	{ "ABOR", ABOR, ARGS, 1,	"(abort operation)" },
	{ "DELE", DELE, STR1, 1,	"<sp> file-name" },
	{ "CWD",  CWD,  OSTR, 1,	"[ <sp> directory-name ]" },
	{ "XCWD", CWD,	OSTR, 1,	"[ <sp> directory-name ]" },
	{ "LIST", LIST, OSTR, 1,	"[ <sp> path-name ]" },
	{ "NLST", NLST, OSTR, 1,	"[ <sp> path-name ]" },
	{ "SITE", SITE, SITECMD, 1,	"site-cmd [ <sp> arguments ]" },
	{ "SYST", SYST, ARGS, 1,	"(get type of operating system)" },
	{ "FEAT", FEAT, ARGS, 1,	"(get extended features)" },
	{ "STAT", STAT, OSTR, 1,	"[ <sp> path-name ]" },
	{ "HELP", HELP, OSTR, 1,	"[ <sp> <string> ]" },
	{ "NOOP", NOOP, ARGS, 1,	"" },
	{ "MKD",  MKD,  STR1, 1,	"<sp> path-name" },
	{ "XMKD", MKD,  STR1, 1,	"<sp> path-name" },
	{ "RMD",  RMD,  STR1, 1,	"<sp> path-name" },
	{ "XRMD", RMD,  STR1, 1,	"<sp> path-name" },
	{ "PWD",  PWD,  ARGS, 1,	"(return current directory)" },
	{ "XPWD", PWD,  ARGS, 1,	"(return current directory)" },
	{ "CDUP", CDUP, ARGS, 1,	"(change to parent directory)" },
	{ "XCUP", CDUP, ARGS, 1,	"(change to parent directory)" },
	{ "STOU", STOU, STR1, 1,	"<sp> file-name" },
	{ "SIZE", SIZE, OSTR, 1,	"<sp> path-name" },
	{ "MDTM", MDTM, OSTR, 1,	"<sp> path-name" },
	{ NULL,   0,    0,    0,	0 }
};

struct tab sitetab[] = {
	{ "MD5", MDFIVE, STR1, 1,	"[ <sp> file-name ]" },
	{ "UMASK", UMASK, ARGS, 1,	"[ <sp> umask ]" },
	{ "IDLE", IDLE, ARGS, 1,	"[ <sp> maximum-idle-time ]" },
	{ "CHMOD", CHMOD, NSTR, 1,	"<sp> mode <sp> file-name" },
	{ "HELP", HELP, OSTR, 1,	"[ <sp> <string> ]" },
	{ NULL,   0,    0,    0,	0 }
};

static char	*copy(char *);
static char	*expglob(char *);
static char	*exptilde(char *);
static void	 help(struct tab *, char *);
static struct tab *
		 lookup(struct tab *, char *);
static int	 port_check(const char *);
#ifdef INET6
static int	 port_check_v6(const char *);
#endif
static void	 sizecmd(char *);
static void	 toolong(int);
#ifdef INET6
static void	 v4map_data_dest(void);
#endif
static int	 yylex(void);

static struct tab *
lookup(struct tab *p, char *cmd)
{

	for (; p->name != NULL; p++)
		if (strcmp(cmd, p->name) == 0)
			return (p);
	return (0);
}

#include <arpa/telnet.h>

/*
 * getline - a hacked up version of fgets to ignore TELNET escape codes.
 */
int
getline(char *s, int n, FILE *iop)
{
	int c;
	register char *cs;
	sigset_t sset, osset;

	cs = s;
/* tmpline may contain saved command from urgent mode interruption */
	for (c = 0; tmpline[c] != '\0' && --n > 0; ++c) {
		*cs++ = tmpline[c];
		if (tmpline[c] == '\n') {
			*cs++ = '\0';
			if (ftpdebug)
				syslog(LOG_DEBUG, "command: %s", s);
			tmpline[0] = '\0';
			return(0);
		}
		if (c == 0)
			tmpline[0] = '\0';
	}
	/* SIGURG would interrupt stdio if not blocked during the read loop */
	sigemptyset(&sset);
	sigaddset(&sset, SIGURG);
	sigprocmask(SIG_BLOCK, &sset, &osset);
	while ((c = getc(iop)) != EOF) {
		c &= 0377;
		if (c == IAC) {
			if ((c = getc(iop)) == EOF)
				goto got_eof;
			c &= 0377;
			switch (c) {
			case WILL:
			case WONT:
				if ((c = getc(iop)) == EOF)
					goto got_eof;
				printf("%c%c%c", IAC, DONT, 0377&c);
				(void) fflush(stdout);
				continue;
			case DO:
			case DONT:
				if ((c = getc(iop)) == EOF)
					goto got_eof;
				printf("%c%c%c", IAC, WONT, 0377&c);
				(void) fflush(stdout);
				continue;
			case IAC:
				break;
			default:
				continue;	/* ignore command */
			}
		}
		*cs++ = c;
		if (--n <= 0) {
			/*
			 * If command doesn't fit into buffer, discard the
			 * rest of the command and indicate truncation.
			 * This prevents the command to be split up into
			 * multiple commands.
			 */
			while (c != '\n' && (c = getc(iop)) != EOF)
				;
			return (-2);
		}
		if (c == '\n')
			break;
	}
got_eof:
	sigprocmask(SIG_SETMASK, &osset, NULL);
	if (c == EOF && cs == s)
		return (-1);
	*cs++ = '\0';
	if (ftpdebug) {
		if (!guest && strncasecmp("pass ", s, 5) == 0) {
			/* Don't syslog passwords */
			syslog(LOG_DEBUG, "command: %.5s ???", s);
		} else {
			register char *cp;
			register int len;

			/* Don't syslog trailing CR-LF */
			len = strlen(s);
			cp = s + len - 1;
			while (cp >= s && (*cp == '\n' || *cp == '\r')) {
				--cp;
				--len;
			}
			syslog(LOG_DEBUG, "command: %.*s", len, s);
		}
	}
	return (0);
}

static void
toolong(int signo)
{

	reply(421,
	    "Timeout (%d seconds): closing control connection.", timeout);
	if (logging)
		syslog(LOG_INFO, "User %s timed out after %d seconds",
		    (pw ? pw -> pw_name : "unknown"), timeout);
	dologout(1);
}

static int
yylex(void)
{
	static int cpos;
	char *cp, *cp2;
	struct tab *p;
	int n;
	char c;

	for (;;) {
		switch (state) {

		case CMD:
			(void) signal(SIGALRM, toolong);
			(void) alarm(timeout);
			n = getline(cbuf, sizeof(cbuf)-1, stdin);
			if (n == -1) {
				reply(221, "You could at least say goodbye.");
				dologout(0);
			} else if (n == -2) {
				reply(500, "Command too long.");
				(void) alarm(0);
				continue;
			}
			(void) alarm(0);
#ifdef SETPROCTITLE
			if (strncasecmp(cbuf, "PASS", 4) != 0)
				setproctitle("%s: %s", proctitle, cbuf);
#endif /* SETPROCTITLE */
			if ((cp = strchr(cbuf, '\r'))) {
				*cp++ = '\n';
				*cp = '\0';
			}
			if ((cp = strpbrk(cbuf, " \n")))
				cpos = cp - cbuf;
			if (cpos == 0)
				cpos = 4;
			c = cbuf[cpos];
			cbuf[cpos] = '\0';
			upper(cbuf);
			p = lookup(cmdtab, cbuf);
			cbuf[cpos] = c;
			if (p != 0) {
				yylval.s = p->name;
				if (!p->implemented)
					return (NOTIMPL); /* state remains CMD */
				state = p->state;
				return (p->token);
			}
			break;

		case SITECMD:
			if (cbuf[cpos] == ' ') {
				cpos++;
				return (SP);
			}
			cp = &cbuf[cpos];
			if ((cp2 = strpbrk(cp, " \n")))
				cpos = cp2 - cbuf;
			c = cbuf[cpos];
			cbuf[cpos] = '\0';
			upper(cp);
			p = lookup(sitetab, cp);
			cbuf[cpos] = c;
			if (guest == 0 && p != 0) {
				yylval.s = p->name;
				if (!p->implemented) {
					state = CMD;
					return (NOTIMPL);
				}
				state = p->state;
				return (p->token);
			}
			state = CMD;
			break;

		case ZSTR1:
		case OSTR:
			if (cbuf[cpos] == '\n') {
				state = CMD;
				return (CRLF);
			}
			/* FALLTHROUGH */

		case STR1:
		dostr1:
			if (cbuf[cpos] == ' ') {
				cpos++;
				state = state == OSTR ? STR2 : state+1;
				return (SP);
			}
			break;

		case ZSTR2:
			if (cbuf[cpos] == '\n') {
				state = CMD;
				return (CRLF);
			}
			/* FALLTHROUGH */

		case STR2:
			cp = &cbuf[cpos];
			n = strlen(cp);
			cpos += n - 1;
			/*
			 * Make sure the string is nonempty and \n terminated.
			 */
			if (n > 1 && cbuf[cpos] == '\n') {
				cbuf[cpos] = '\0';
				yylval.s = copy(cp);
				cbuf[cpos] = '\n';
				state = ARGS;
				return (STRING);
			}
			break;

		case NSTR:
			if (cbuf[cpos] == ' ') {
				cpos++;
				return (SP);
			}
			if (isdigit(cbuf[cpos])) {
				cp = &cbuf[cpos];
				while (isdigit(cbuf[++cpos]))
					;
				c = cbuf[cpos];
				cbuf[cpos] = '\0';
				yylval.u.i = atoi(cp);
				cbuf[cpos] = c;
				state = STR1;
				return (NUMBER);
			}
			state = STR1;
			goto dostr1;

		case ARGS:
			if (isdigit(cbuf[cpos])) {
				cp = &cbuf[cpos];
				while (isdigit(cbuf[++cpos]))
					;
				c = cbuf[cpos];
				cbuf[cpos] = '\0';
				yylval.u.i = atoi(cp);
				yylval.u.o = strtoull(cp, NULL, 10);
				cbuf[cpos] = c;
				return (NUMBER);
			}
			if (strncasecmp(&cbuf[cpos], "ALL", 3) == 0
			 && !isalnum(cbuf[cpos + 3])) {
				cpos += 3;
				return ALL;
			}
			switch (cbuf[cpos++]) {

			case '\n':
				state = CMD;
				return (CRLF);

			case ' ':
				return (SP);

			case ',':
				return (COMMA);

			case 'A':
			case 'a':
				return (A);

			case 'B':
			case 'b':
				return (B);

			case 'C':
			case 'c':
				return (C);

			case 'E':
			case 'e':
				return (E);

			case 'F':
			case 'f':
				return (F);

			case 'I':
			case 'i':
				return (I);

			case 'L':
			case 'l':
				return (L);

			case 'N':
			case 'n':
				return (N);

			case 'P':
			case 'p':
				return (P);

			case 'R':
			case 'r':
				return (R);

			case 'S':
			case 's':
				return (S);

			case 'T':
			case 't':
				return (T);

			}
			break;

		default:
			fatalerror("Unknown state in scanner.");
		}
		state = CMD;
		return (LEXERR);
	}
}

void
upper(char *s)
{
	while (*s != '\0') {
		if (islower(*s))
			*s = toupper(*s);
		s++;
	}
}

static char *
copy(char *s)
{
	char *p;

	p = malloc(strlen(s) + 1);
	if (p == NULL)
		fatalerror("Ran out of memory.");
	(void) strcpy(p, s);
	return (p);
}

static void
help(struct tab *ctab, char *s)
{
	struct tab *c;
	int width, NCMDS;
	char *type;

	if (ctab == sitetab)
		type = "SITE ";
	else
		type = "";
	width = 0, NCMDS = 0;
	for (c = ctab; c->name != NULL; c++) {
		int len = strlen(c->name);

		if (len > width)
			width = len;
		NCMDS++;
	}
	width = (width + 8) &~ 7;
	if (s == 0) {
		int i, j, w;
		int columns, lines;

		lreply(214, "The following %scommands are recognized %s.",
		    type, "(* =>'s unimplemented)");
		columns = 76 / width;
		if (columns == 0)
			columns = 1;
		lines = (NCMDS + columns - 1) / columns;
		for (i = 0; i < lines; i++) {
			printf("   ");
			for (j = 0; j < columns; j++) {
				c = ctab + j * lines + i;
				printf("%s%c", c->name,
					c->implemented ? ' ' : '*');
				if (c + lines >= &ctab[NCMDS])
					break;
				w = strlen(c->name) + 1;
				while (w < width) {
					putchar(' ');
					w++;
				}
			}
			printf("\r\n");
		}
		(void) fflush(stdout);
		if (hostinfo)
			reply(214, "Direct comments to ftp-bugs@%s.", hostname);
		else
			reply(214, "End.");
		return;
	}
	upper(s);
	c = lookup(ctab, s);
	if (c == NULL) {
		reply(502, "Unknown command %s.", s);
		return;
	}
	if (c->implemented)
		reply(214, "Syntax: %s%s %s", type, c->name, c->help);
	else
		reply(214, "%s%-*s\t%s; unimplemented.", type, width,
		    c->name, c->help);
}

static void
sizecmd(char *filename)
{
	switch (type) {
	case TYPE_L:
	case TYPE_I: {
		struct stat stbuf;
		if (stat(filename, &stbuf) < 0)
			perror_reply(550, filename);
		else if (!S_ISREG(stbuf.st_mode))
			reply(550, "%s: not a plain file.", filename);
		else
			reply(213, "%jd", (intmax_t)stbuf.st_size);
		break; }
	case TYPE_A: {
		FILE *fin;
		int c;
		off_t count;
		struct stat stbuf;
		fin = fopen(filename, "r");
		if (fin == NULL) {
			perror_reply(550, filename);
			return;
		}
		if (fstat(fileno(fin), &stbuf) < 0) {
			perror_reply(550, filename);
			(void) fclose(fin);
			return;
		} else if (!S_ISREG(stbuf.st_mode)) {
			reply(550, "%s: not a plain file.", filename);
			(void) fclose(fin);
			return;
		} else if (stbuf.st_size > MAXASIZE) {
			reply(550, "%s: too large for type A SIZE.", filename);
			(void) fclose(fin);
			return;
		}

		count = 0;
		while((c=getc(fin)) != EOF) {
			if (c == '\n')	/* will get expanded to \r\n */
				count++;
			count++;
		}
		(void) fclose(fin);

		reply(213, "%jd", (intmax_t)count);
		break; }
	default:
		reply(504, "SIZE not implemented for type %s.",
		           typenames[type]);
	}
}

/* Return 1, if port check is done. Return 0, if not yet. */
static int
port_check(const char *pcmd)
{
	if (his_addr.su_family == AF_INET) {
		if (data_dest.su_family != AF_INET) {
			usedefault = 1;
			reply(500, "Invalid address rejected.");
			return 1;
		}
		if (paranoid &&
		    ((ntohs(data_dest.su_port) < IPPORT_RESERVED) ||
		     memcmp(&data_dest.su_sin.sin_addr,
			    &his_addr.su_sin.sin_addr,
			    sizeof(data_dest.su_sin.sin_addr)))) {
			usedefault = 1;
			reply(500, "Illegal PORT range rejected.");
		} else {
			usedefault = 0;
			if (pdata >= 0) {
				(void) close(pdata);
				pdata = -1;
			}
			reply(200, "%s command successful.", pcmd);
		}
		return 1;
	}
	return 0;
}

static int
check_login1(void)
{
	if (logged_in)
		return 1;
	else {
		reply(530, "Please login with USER and PASS.");
		return 0;
	}
}

/*
 * Replace leading "~user" in a pathname by the user's login directory.
 * Returned string will be in a freshly malloced buffer unless it's NULL.
 */
static char *
exptilde(char *s)
{
	char *p, *q;
	char *path, *user;
	struct passwd *ppw;

	if ((p = strdup(s)) == NULL)
		return (NULL);
	if (*p != '~')
		return (p);

	user = p + 1;	/* skip tilde */
	if ((path = strchr(p, '/')) != NULL)
		*(path++) = '\0'; /* separate ~user from the rest of path */
	if (*user == '\0') /* no user specified, use the current user */
		user = pw->pw_name;
	/* read passwd even for the current user since we may be chrooted */
	if ((ppw = getpwnam(user)) != NULL) {
		/* user found, substitute login directory for ~user */
		if (path)
			asprintf(&q, "%s/%s", ppw->pw_dir, path);
		else
			q = strdup(ppw->pw_dir);
		free(p);
		p = q;
	} else {
		/* user not found, undo the damage */
		if (path)
			path[-1] = '/';
	}
	return (p);
}

/*
 * Expand glob(3) patterns possibly present in a pathname.
 * Avoid expanding to a pathname including '\r' or '\n' in order to
 * not disrupt the FTP protocol.
 * The expansion found must be unique.
 * Return the result as a malloced string, or NULL if an error occurred.
 *
 * Problem: this production is used for all pathname
 * processing, but only gives a 550 error reply.
 * This is a valid reply in some cases but not in others.
 */
static char *
expglob(char *s)
{
	char *p, **pp, *rval;
	int flags = GLOB_BRACE | GLOB_NOCHECK;
	int n;
	glob_t gl;

	memset(&gl, 0, sizeof(gl));
	flags |= GLOB_LIMIT;
	gl.gl_matchc = MAXGLOBARGS;
	if (glob(s, flags, NULL, &gl) == 0 && gl.gl_pathc != 0) {
		for (pp = gl.gl_pathv, p = NULL, n = 0; *pp; pp++)
			if (*(*pp + strcspn(*pp, "\r\n")) == '\0') {
				p = *pp;
				n++;
			}
		if (n == 0)
			rval = strdup(s);
		else if (n == 1)
			rval = strdup(p);
		else {
			reply(550, "Wildcard is ambiguous.");
			rval = NULL;
		}
	} else {
		reply(550, "Wildcard expansion error.");
		rval = NULL;
	}
	globfree(&gl);
	return (rval);
}

#ifdef INET6
/* Return 1, if port check is done. Return 0, if not yet. */
static int
port_check_v6(const char *pcmd)
{
	if (his_addr.su_family == AF_INET6) {
		if (IN6_IS_ADDR_V4MAPPED(&his_addr.su_sin6.sin6_addr))
			/* Convert data_dest into v4 mapped sockaddr.*/
			v4map_data_dest();
		if (data_dest.su_family != AF_INET6) {
			usedefault = 1;
			reply(500, "Invalid address rejected.");
			return 1;
		}
		if (paranoid &&
		    ((ntohs(data_dest.su_port) < IPPORT_RESERVED) ||
		     memcmp(&data_dest.su_sin6.sin6_addr,
			    &his_addr.su_sin6.sin6_addr,
			    sizeof(data_dest.su_sin6.sin6_addr)))) {
			usedefault = 1;
			reply(500, "Illegal PORT range rejected.");
		} else {
			usedefault = 0;
			if (pdata >= 0) {
				(void) close(pdata);
				pdata = -1;
			}
			reply(200, "%s command successful.", pcmd);
		}
		return 1;
	}
	return 0;
}

static void
v4map_data_dest(void)
{
	struct in_addr savedaddr;
	int savedport;

	if (data_dest.su_family != AF_INET) {
		usedefault = 1;
		reply(500, "Invalid address rejected.");
		return;
	}

	savedaddr = data_dest.su_sin.sin_addr;
	savedport = data_dest.su_port;

	memset(&data_dest, 0, sizeof(data_dest));
	data_dest.su_sin6.sin6_len = sizeof(struct sockaddr_in6);
	data_dest.su_sin6.sin6_family = AF_INET6;
	data_dest.su_sin6.sin6_port = savedport;
	memset((caddr_t)&data_dest.su_sin6.sin6_addr.s6_addr[10], 0xff, 2);
	memcpy((caddr_t)&data_dest.su_sin6.sin6_addr.s6_addr[12],
	       (caddr_t)&savedaddr, sizeof(savedaddr));
}
#endif
#line 1299 "ftpcmd.c"

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
case 2:
#line 130 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (fromname)
				free(fromname);
			fromname = NULL;
			restart_point = 0;
		}
break;
case 4:
#line 141 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			user(yystack.l_mark[-1].s);
			free(yystack.l_mark[-1].s);
		}
break;
case 5:
#line 146 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			pass(yystack.l_mark[-1].s);
			free(yystack.l_mark[-1].s);
		}
break;
case 6:
#line 151 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			pass("");
		}
break;
case 7:
#line 155 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (epsvall) {
				reply(501, "No PORT allowed after EPSV ALL.");
				goto port_done;
			}
			if (!yystack.l_mark[-3].u.i)
				goto port_done;
			if (port_check("PORT") == 1)
				goto port_done;
#ifdef INET6
			if ((his_addr.su_family != AF_INET6 ||
			     !IN6_IS_ADDR_V4MAPPED(&his_addr.su_sin6.sin6_addr))) {
				/* shoud never happen */
				usedefault = 1;
				reply(500, "Invalid address rejected.");
				goto port_done;
			}
			port_check_v6("pcmd");
#endif
		port_done:
			;
		}
break;
case 8:
#line 178 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (epsvall) {
				reply(501, "No LPRT allowed after EPSV ALL.");
				goto lprt_done;
			}
			if (!yystack.l_mark[-3].u.i)
				goto lprt_done;
			if (port_check("LPRT") == 1)
				goto lprt_done;
#ifdef INET6
			if (his_addr.su_family != AF_INET6) {
				usedefault = 1;
				reply(500, "Invalid address rejected.");
				goto lprt_done;
			}
			if (port_check_v6("LPRT") == 1)
				goto lprt_done;
#endif
		lprt_done:
			;
		}
break;
case 9:
#line 200 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			char delim;
			char *tmp = NULL;
			char *p, *q;
			char *result[3];
			struct addrinfo hints;
			struct addrinfo *res;
			int i;

			if (epsvall) {
				reply(501, "No EPRT allowed after EPSV ALL.");
				goto eprt_done;
			}
			if (!yystack.l_mark[-3].u.i)
				goto eprt_done;

			memset(&data_dest, 0, sizeof(data_dest));
			tmp = strdup(yystack.l_mark[-1].s);
			if (ftpdebug)
				syslog(LOG_DEBUG, "%s", tmp);
			if (!tmp) {
				fatalerror("not enough core");
				/*NOTREACHED*/
			}
			p = tmp;
			delim = p[0];
			p++;
			memset(result, 0, sizeof(result));
			for (i = 0; i < 3; i++) {
				q = strchr(p, delim);
				if (!q || *q != delim) {
		parsefail:
					reply(500,
						"Invalid argument, rejected.");
					if (tmp)
						free(tmp);
					usedefault = 1;
					goto eprt_done;
				}
				*q++ = '\0';
				result[i] = p;
				if (ftpdebug)
					syslog(LOG_DEBUG, "%d: %s", i, p);
				p = q;
			}

			/* some more sanity check */
			p = result[0];
			while (*p) {
				if (!isdigit(*p))
					goto parsefail;
				p++;
			}
			p = result[2];
			while (*p) {
				if (!isdigit(*p))
					goto parsefail;
				p++;
			}

			/* grab address */
			memset(&hints, 0, sizeof(hints));
			if (atoi(result[0]) == 1)
				hints.ai_family = PF_INET;
#ifdef INET6
			else if (atoi(result[0]) == 2)
				hints.ai_family = PF_INET6;
#endif
			else
				hints.ai_family = PF_UNSPEC;	/*XXX*/
			hints.ai_socktype = SOCK_STREAM;
			i = getaddrinfo(result[1], result[2], &hints, &res);
			if (i)
				goto parsefail;
			memcpy(&data_dest, res->ai_addr, res->ai_addrlen);
#ifdef INET6
			if (his_addr.su_family == AF_INET6
			    && data_dest.su_family == AF_INET6) {
				/* XXX more sanity checks! */
				data_dest.su_sin6.sin6_scope_id =
					his_addr.su_sin6.sin6_scope_id;
			}
#endif
			free(tmp);
			tmp = NULL;

			if (port_check("EPRT") == 1)
				goto eprt_done;
#ifdef INET6
			if (his_addr.su_family != AF_INET6) {
				usedefault = 1;
				reply(500, "Invalid address rejected.");
				goto eprt_done;
			}
			if (port_check_v6("EPRT") == 1)
				goto eprt_done;
#endif
		eprt_done:
			free(yystack.l_mark[-1].s);
		}
break;
case 10:
#line 301 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (epsvall)
				reply(501, "No PASV allowed after EPSV ALL.");
			else if (yystack.l_mark[-1].u.i)
				passive();
		}
break;
case 11:
#line 308 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (epsvall)
				reply(501, "No LPSV allowed after EPSV ALL.");
			else if (yystack.l_mark[-1].u.i)
				long_passive("LPSV", PF_UNSPEC);
		}
break;
case 12:
#line 315 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i) {
				int pf;
				switch (yystack.l_mark[-1].u.i) {
				case 1:
					pf = PF_INET;
					break;
#ifdef INET6
				case 2:
					pf = PF_INET6;
					break;
#endif
				default:
					pf = -1;	/*junk value*/
					break;
				}
				long_passive("EPSV", pf);
			}
		}
break;
case 13:
#line 335 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i) {
				reply(200, "EPSV ALL command successful.");
				epsvall++;
			}
		}
break;
case 14:
#line 342 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-1].u.i)
				long_passive("EPSV", PF_UNSPEC);
		}
break;
case 15:
#line 347 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i) {
				switch (cmd_type) {

				case TYPE_A:
					if (cmd_form == FORM_N) {
						reply(200, "Type set to A.");
						type = cmd_type;
						form = cmd_form;
					} else
						reply(504, "Form must be N.");
					break;

				case TYPE_E:
					reply(504, "Type E not implemented.");
					break;

				case TYPE_I:
					reply(200, "Type set to I.");
					type = cmd_type;
					break;

				case TYPE_L:
#if CHAR_BIT == 8
					if (cmd_bytesz == 8) {
						reply(200,
						    "Type set to L (byte size 8).");
						type = cmd_type;
					} else
						reply(504, "Byte size must be 8.");
#else /* CHAR_BIT == 8 */
					UNIMPLEMENTED for CHAR_BIT != 8
#endif /* CHAR_BIT == 8 */
				}
			}
		}
break;
case 16:
#line 384 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i) {
				switch (yystack.l_mark[-1].u.i) {

				case STRU_F:
					reply(200, "STRU F accepted.");
					break;

				default:
					reply(504, "Unimplemented STRU type.");
				}
			}
		}
break;
case 17:
#line 398 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i) {
				switch (yystack.l_mark[-1].u.i) {

				case MODE_S:
					reply(200, "MODE S accepted.");
					break;
	
				default:
					reply(502, "Unimplemented MODE type.");
				}
			}
		}
break;
case 18:
#line 412 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i) {
				reply(202, "ALLO command ignored.");
			}
		}
break;
case 19:
#line 418 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-7].u.i) {
				reply(202, "ALLO command ignored.");
			}
		}
break;
case 20:
#line 424 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (noretr || (guest && noguestretr))
				reply(500, "RETR command disabled.");
			else if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s != NULL)
				retrieve(NULL, yystack.l_mark[-1].s);

			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 21:
#line 434 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s != NULL)
				store(yystack.l_mark[-1].s, "w", 0);
			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 22:
#line 441 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s != NULL)
				store(yystack.l_mark[-1].s, "a", 0);
			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 23:
#line 448 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-1].u.i)
				send_file_list(".");
		}
break;
case 24:
#line 453 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i)
				send_file_list(yystack.l_mark[-1].s);
			free(yystack.l_mark[-1].s);
		}
break;
case 25:
#line 459 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-1].u.i)
				retrieve(_PATH_LS " -lgA", "");
		}
break;
case 26:
#line 464 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i)
				retrieve(_PATH_LS " -lgA %s", yystack.l_mark[-1].s);
			free(yystack.l_mark[-1].s);
		}
break;
case 27:
#line 470 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s != NULL)
				statfilecmd(yystack.l_mark[-1].s);
			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 28:
#line 477 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-1].u.i) {
				statcmd();
			}
		}
break;
case 29:
#line 483 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s != NULL)
				delete(yystack.l_mark[-1].s);
			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 30:
#line 490 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s != NULL) {
				if (fromname) {
					renamecmd(fromname, yystack.l_mark[-1].s);
					free(fromname);
					fromname = NULL;
				} else {
					reply(503, "Bad sequence of commands.");
				}
			}
			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 31:
#line 504 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-1].u.i)
				reply(225, "ABOR command successful.");
		}
break;
case 32:
#line 509 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-1].u.i) {
				cwd(homedir);
			}
		}
break;
case 33:
#line 515 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s != NULL)
				cwd(yystack.l_mark[-1].s);
			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 34:
#line 522 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			help(cmdtab, NULL);
		}
break;
case 35:
#line 526 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			char *cp = yystack.l_mark[-1].s;

			if (strncasecmp(cp, "SITE", 4) == 0) {
				cp = yystack.l_mark[-1].s + 4;
				if (*cp == ' ')
					cp++;
				if (*cp)
					help(sitetab, cp);
				else
					help(sitetab, NULL);
			} else
				help(cmdtab, yystack.l_mark[-1].s);
			free(yystack.l_mark[-1].s);
		}
break;
case 36:
#line 542 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			reply(200, "NOOP command successful.");
		}
break;
case 37:
#line 546 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s != NULL)
				makedir(yystack.l_mark[-1].s);
			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 38:
#line 553 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s != NULL)
				removedir(yystack.l_mark[-1].s);
			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 39:
#line 560 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-1].u.i)
				pwd();
		}
break;
case 40:
#line 565 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-1].u.i)
				cwd("..");
		}
break;
case 41:
#line 570 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			help(sitetab, NULL);
		}
break;
case 42:
#line 574 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			help(sitetab, yystack.l_mark[-1].s);
			free(yystack.l_mark[-1].s);
		}
break;
case 43:
#line 579 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			char p[64], *q;

			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s) {
				q = MD5File(yystack.l_mark[-1].s, p);
				if (q != NULL)
					reply(200, "MD5(%s) = %s", yystack.l_mark[-1].s, p);
				else
					perror_reply(550, yystack.l_mark[-1].s);
			}
			if (yystack.l_mark[-1].s)
				free(yystack.l_mark[-1].s);
		}
break;
case 44:
#line 593 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			int oldmask;

			if (yystack.l_mark[-1].u.i) {
				oldmask = umask(0);
				(void) umask(oldmask);
				reply(200, "Current UMASK is %03o.", oldmask);
			}
		}
break;
case 45:
#line 603 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			int oldmask;

			if (yystack.l_mark[-3].u.i) {
				if ((yystack.l_mark[-1].u.i == -1) || (yystack.l_mark[-1].u.i > 0777)) {
					reply(501, "Bad UMASK value.");
				} else {
					oldmask = umask(yystack.l_mark[-1].u.i);
					reply(200,
					    "UMASK set to %03o (was %03o).",
					    yystack.l_mark[-1].u.i, oldmask);
				}
			}
		}
break;
case 46:
#line 618 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-5].u.i && (yystack.l_mark[-1].s != NULL)) {
				if ((yystack.l_mark[-3].u.i == -1 ) || (yystack.l_mark[-3].u.i > 0777))
					reply(501, "Bad mode value.");
				else if (chmod(yystack.l_mark[-1].s, yystack.l_mark[-3].u.i) < 0)
					perror_reply(550, yystack.l_mark[-1].s);
				else
					reply(200, "CHMOD command successful.");
			}
			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 47:
#line 631 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-2].u.i)
				reply(200,
			    	    "Current IDLE time limit is %d seconds; max %d.",
				    timeout, maxtimeout);
		}
break;
case 48:
#line 638 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-4].u.i) {
				if (yystack.l_mark[-1].u.i < 30 || yystack.l_mark[-1].u.i > maxtimeout) {
					reply(501,
					    "Maximum IDLE time must be between 30 and %d seconds.",
					    maxtimeout);
				} else {
					timeout = yystack.l_mark[-1].u.i;
					(void) alarm(timeout);
					reply(200,
					    "Maximum IDLE time set to %d seconds.",
					    timeout);
				}
			}
		}
break;
case 49:
#line 654 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s != NULL)
				store(yystack.l_mark[-1].s, "w", 1);
			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 50:
#line 661 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			lreply(211, "Extensions supported:");
#if 0
			/* XXX these two keywords are non-standard */
			printf(" EPRT\r\n");
			if (!noepsv)
				printf(" EPSV\r\n");
#endif
			printf(" MDTM\r\n");
			printf(" REST STREAM\r\n");
			printf(" SIZE\r\n");
			if (assumeutf8) {
				/* TVFS requires UTF8, see RFC 3659 */
				printf(" TVFS\r\n");
				printf(" UTF8\r\n");
			}
			reply(211, "End.");
		}
break;
case 51:
#line 680 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-1].u.i) {
				if (hostinfo)
#ifdef BSD
					reply(215, "UNIX Type: L%d Version: BSD-%d",
					      CHAR_BIT, BSD);
#else /* BSD */
					reply(215, "UNIX Type: L%d", CHAR_BIT);
#endif /* BSD */
				else
					reply(215, "UNKNOWN Type: L%d", CHAR_BIT);
			}
		}
break;
case 52:
#line 702 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s != NULL)
				sizecmd(yystack.l_mark[-1].s);
			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 53:
#line 719 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s != NULL) {
				struct stat stbuf;
				if (stat(yystack.l_mark[-1].s, &stbuf) < 0)
					perror_reply(550, yystack.l_mark[-1].s);
				else if (!S_ISREG(stbuf.st_mode)) {
					reply(550, "%s: not a plain file.", yystack.l_mark[-1].s);
				} else {
					struct tm *t;
					t = gmtime(&stbuf.st_mtime);
					reply(213,
					    "%04d%02d%02d%02d%02d%02d",
					    1900 + t->tm_year,
					    t->tm_mon+1, t->tm_mday,
					    t->tm_hour, t->tm_min, t->tm_sec);
				}
			}
			if (yystack.l_mark[-1].s != NULL)
				free(yystack.l_mark[-1].s);
		}
break;
case 54:
#line 740 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			reply(221, "Goodbye.");
			dologout(0);
		}
break;
case 55:
#line 745 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			nack(yystack.l_mark[0].s);
		}
break;
case 56:
#line 749 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			yyclearin;		/* discard lookahead data */
			yyerrok;		/* clear error condition */
			state = CMD;		/* reset lexer state */
		}
break;
case 57:
#line 757 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			restart_point = 0;
			if (yystack.l_mark[-3].u.i && yystack.l_mark[-1].s) {
				if (fromname)
					free(fromname);
				fromname = NULL;
				if (renamefrom(yystack.l_mark[-1].s))
					fromname = yystack.l_mark[-1].s;
				else
					free(yystack.l_mark[-1].s);
			} else if (yystack.l_mark[-1].s) {
				free(yystack.l_mark[-1].s);
			}
		}
break;
case 58:
#line 772 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (yystack.l_mark[-3].u.i) {
				if (fromname)
					free(fromname);
				fromname = NULL;
				restart_point = yystack.l_mark[-1].u.o;
				reply(350, "Restarting at %jd. %s",
				    (intmax_t)restart_point,
				    "Send STORE or RETRIEVE to initiate transfer.");
			}
		}
break;
case 60:
#line 791 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			yyval.s = (char *)calloc(1, sizeof(char));
		}
break;
case 62:
#line 799 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			yyval.u.i = yystack.l_mark[0].u.i;
		}
break;
case 63:
#line 807 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			char *a, *p;

			data_dest.su_len = sizeof(struct sockaddr_in);
			data_dest.su_family = AF_INET;
			p = (char *)&data_dest.su_sin.sin_port;
			p[0] = yystack.l_mark[-2].u.i; p[1] = yystack.l_mark[0].u.i;
			a = (char *)&data_dest.su_sin.sin_addr;
			a[0] = yystack.l_mark[-10].u.i; a[1] = yystack.l_mark[-8].u.i; a[2] = yystack.l_mark[-6].u.i; a[3] = yystack.l_mark[-4].u.i;
		}
break;
case 64:
#line 826 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			char *a, *p;

			memset(&data_dest, 0, sizeof(data_dest));
			data_dest.su_len = sizeof(struct sockaddr_in6);
			data_dest.su_family = AF_INET6;
			p = (char *)&data_dest.su_port;
			p[0] = yystack.l_mark[-2].u.i; p[1] = yystack.l_mark[0].u.i;
			a = (char *)&data_dest.su_sin6.sin6_addr;
			a[0] = yystack.l_mark[-36].u.i; a[1] = yystack.l_mark[-34].u.i; a[2] = yystack.l_mark[-32].u.i; a[3] = yystack.l_mark[-30].u.i;
			a[4] = yystack.l_mark[-28].u.i; a[5] = yystack.l_mark[-26].u.i; a[6] = yystack.l_mark[-24].u.i; a[7] = yystack.l_mark[-22].u.i;
			a[8] = yystack.l_mark[-20].u.i; a[9] = yystack.l_mark[-18].u.i; a[10] = yystack.l_mark[-16].u.i; a[11] = yystack.l_mark[-14].u.i;
			a[12] = yystack.l_mark[-12].u.i; a[13] = yystack.l_mark[-10].u.i; a[14] = yystack.l_mark[-8].u.i; a[15] = yystack.l_mark[-6].u.i;
			if (his_addr.su_family == AF_INET6) {
				/* XXX more sanity checks! */
				data_dest.su_sin6.sin6_scope_id =
					his_addr.su_sin6.sin6_scope_id;
			}
			if (yystack.l_mark[-40].u.i != 6 || yystack.l_mark[-38].u.i != 16 || yystack.l_mark[-4].u.i != 2)
				memset(&data_dest, 0, sizeof(data_dest));
		}
break;
case 65:
#line 850 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			char *a, *p;

			memset(&data_dest, 0, sizeof(data_dest));
			data_dest.su_sin.sin_len = sizeof(struct sockaddr_in);
			data_dest.su_family = AF_INET;
			p = (char *)&data_dest.su_port;
			p[0] = yystack.l_mark[-2].u.i; p[1] = yystack.l_mark[0].u.i;
			a = (char *)&data_dest.su_sin.sin_addr;
			a[0] =  yystack.l_mark[-12].u.i; a[1] = yystack.l_mark[-10].u.i; a[2] = yystack.l_mark[-8].u.i; a[3] = yystack.l_mark[-6].u.i;
			if (yystack.l_mark[-16].u.i != 4 || yystack.l_mark[-14].u.i != 4 || yystack.l_mark[-4].u.i != 2)
				memset(&data_dest, 0, sizeof(data_dest));
		}
break;
case 66:
#line 867 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			yyval.u.i = FORM_N;
		}
break;
case 67:
#line 871 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			yyval.u.i = FORM_T;
		}
break;
case 68:
#line 875 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			yyval.u.i = FORM_C;
		}
break;
case 69:
#line 882 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			cmd_type = TYPE_A;
			cmd_form = FORM_N;
		}
break;
case 70:
#line 887 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			cmd_type = TYPE_A;
			cmd_form = yystack.l_mark[0].u.i;
		}
break;
case 71:
#line 892 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			cmd_type = TYPE_E;
			cmd_form = FORM_N;
		}
break;
case 72:
#line 897 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			cmd_type = TYPE_E;
			cmd_form = yystack.l_mark[0].u.i;
		}
break;
case 73:
#line 902 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			cmd_type = TYPE_I;
		}
break;
case 74:
#line 906 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			cmd_type = TYPE_L;
			cmd_bytesz = CHAR_BIT;
		}
break;
case 75:
#line 911 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			cmd_type = TYPE_L;
			cmd_bytesz = yystack.l_mark[0].u.i;
		}
break;
case 76:
#line 917 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			cmd_type = TYPE_L;
			cmd_bytesz = yystack.l_mark[0].u.i;
		}
break;
case 77:
#line 925 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			yyval.u.i = STRU_F;
		}
break;
case 78:
#line 929 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			yyval.u.i = STRU_R;
		}
break;
case 79:
#line 933 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			yyval.u.i = STRU_P;
		}
break;
case 80:
#line 940 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			yyval.u.i = MODE_S;
		}
break;
case 81:
#line 944 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			yyval.u.i = MODE_B;
		}
break;
case 82:
#line 948 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			yyval.u.i = MODE_C;
		}
break;
case 83:
#line 955 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			if (logged_in && yystack.l_mark[0].s) {
				char *p;

				/*
				 * Expand ~user manually since glob(3)
				 * will return the unexpanded pathname
				 * if the corresponding file/directory
				 * doesn't exist yet.  Using sole glob(3)
				 * would break natural commands like
				 * MKD ~user/newdir
				 * or
				 * RNTO ~/newfile
				 */
				if ((p = exptilde(yystack.l_mark[0].s)) != NULL) {
					yyval.s = expglob(p);
					free(p);
				} else
					yyval.s = NULL;
				free(yystack.l_mark[0].s);
			} else
				yyval.s = yystack.l_mark[0].s;
		}
break;
case 85:
#line 986 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
			int ret, dec, multby, digit;

			/*
			 * Convert a number that was read as decimal number
			 * to what it would be if it had been read as octal.
			 */
			dec = yystack.l_mark[0].u.i;
			multby = 1;
			ret = 0;
			while (dec) {
				digit = dec%10;
				if (digit > 7) {
					ret = -1;
					break;
				}
				ret += digit * multby;
				multby *= 8;
				dec /= 10;
			}
			yyval.u.i = ret;
		}
break;
case 86:
#line 1013 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
		yyval.u.i = check_login1();
		}
break;
case 87:
#line 1020 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
		if (noepsv) {
			reply(500, "EPSV command disabled.");
			yyval.u.i = 0;
		}
		else
			yyval.u.i = check_login1();
		}
break;
case 88:
#line 1032 "/usr/home/freebsd/omega/src/libexec/ftpd/ftpcmd.y"
	{
		if (readonly) {
			reply(550, "Permission denied.");
			yyval.u.i = 0;
		}
		else
			yyval.u.i = check_login1();
		}
break;
#line 2496 "ftpcmd.c"
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
