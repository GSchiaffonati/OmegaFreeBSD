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

#line 45 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif /* HAVE_CONFIG_H */
#include <am_defs.h>
#include <fsi_data.h>
#include <fsinfo.h>

extern qelem *list_of_hosts, *list_of_automounts;
#line 55 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	auto_tree *a;
	disk_fs *d;
	ether_if *e;
	host *h;
	qelem *q;
	char *s;
	fsi_mount *m;
	fsmount *f;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 48 "fsi_gram.c"

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

#define tARCH 257
#define tAS 258
#define tAUTOMOUNT 259
#define tCLUSTER 260
#define tCONFIG 261
#define tDUMPSET 262
#define tEQ 263
#define tNFSEQ 264
#define tEXPORTFS 265
#define tFREQ 266
#define tFROM 267
#define tFS 268
#define tFSTYPE 269
#define tHWADDR 270
#define tINADDR 271
#define tHOST 272
#define tLOCALHOST 273
#define tLOG 274
#define tMOUNT 275
#define tNETMASK 276
#define tNETIF 277
#define tVOLNAME 278
#define tOPTS 279
#define tOS 280
#define tPASSNO 281
#define tDIRECT 282
#define tSEL 283
#define tSTR 284
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    7,    7,    8,    8,    9,    9,    9,
    9,    9,    9,    9,    3,    3,    3,    3,    1,    1,
   14,   14,   10,   10,    5,    5,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    2,    2,    2,    2,    2,
   12,   12,    4,    4,    4,    4,    4,   11,   11,   13,
   13,   13,   13,   13,   13,   13,
};
static const YYINT yylen[] = {                            2,
    0,    2,    2,    4,    5,    1,    4,    0,    6,    3,
    4,    4,    4,    4,    0,    4,    4,    4,    3,    2,
    0,    2,    0,    2,    5,    3,    0,    4,    4,    4,
    4,    3,    4,    4,    4,    0,    5,    5,    4,    6,
    0,    6,    0,    3,    3,    3,    4,    0,    4,    0,
    2,    3,    3,    3,    3,    4,
};
static const YYINT yydefred[] = {                         1,
    0,    0,    0,    0,    3,    2,    0,   20,    0,   36,
    6,    8,   23,   23,   22,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   24,    0,
    0,    0,    0,    0,    0,    0,   10,    0,    0,    7,
    0,    0,    0,   39,    0,   36,    0,   14,   11,   13,
   15,   12,   26,   27,   50,   38,    0,   37,    0,    0,
    0,   40,    0,    0,    0,    9,    0,    0,    0,    0,
    0,   41,    0,    0,   25,    0,    0,    0,    0,    0,
   51,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   52,   53,   54,   55,   18,   16,   17,
   35,   33,   31,   28,   34,    0,   29,   30,   56,   43,
    0,    0,    0,    0,    0,    0,    0,   44,   45,   46,
   42,   47,
};
static const YYINT yydgoto[] = {                          1,
    5,   16,   59,  111,   29,   60,    6,   13,   17,   18,
   30,   90,   61,   10,
};
static const YYINT yysindex[] = {                         0,
 -239, -253, -240, -118,    0,    0, -118,    0, -262,    0,
    0,    0,    0,    0,    0, -258, -104, -238, -238, -236,
  -33,  -32,  -30, -252, -248,  -17, -237, -243,    0, -230,
 -230, -235,  -61, -234, -233, -232,    0,  -77, -231,    0,
  -71,  -75, -229,    0, -228,    0, -227,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -119,    0,  -91, -107,
 -244,    0,   -3,   -2,   -1,    0,    4,    6,   10,   11,
   12,    0,   13,   14,    0,   15, -223, -221, -220, -216,
    0, -215, -214, -207, -206, -205, -204, -203, -202, -201,
 -200, -199, -198,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -36,    0,    0,    0,    0,
 -241,   27, -195, -194, -193, -115, -192,    0,    0,    0,
    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    7,    0,    2,    2,  -57,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    8,
    9,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -85,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -114,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,   47,    0,    0,    0,    0,    0,   87,    0,   81,
   77,  -14,    0,   78,
};
#define YYTABLESIZE 285
static const YYINT yytable[] = {                         47,
   21,   48,   49,   21,   12,   62,   19,    4,    5,  121,
   41,   76,   41,   77,  112,    8,    2,   75,    7,    3,
   27,   15,   78,  113,   79,   20,   32,   34,   35,   28,
   36,   37,    4,   66,   80,   38,  114,   81,    9,   32,
   42,  115,    9,   39,   43,   51,   40,   54,   44,   48,
   49,   50,   52,   53,   55,   56,   58,   82,   83,   84,
   94,   46,   95,   96,   85,   21,   86,   97,   98,   99,
   87,   88,   89,   91,   92,   93,  100,  101,  102,  103,
  104,  105,  106,  107,  108,  109,  110,  117,  118,  119,
  120,  122,   57,   14,   19,   31,  116,   33,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   67,    0,
    0,   21,   22,    0,   68,   23,   24,    0,   69,    0,
    0,   70,    0,    0,   20,   11,   71,   72,  106,   41,
   32,   73,   25,   74,    0,   26,   32,    0,   63,   64,
   32,    0,    0,   32,   65,    0,    0,    0,   32,   32,
    0,    0,    0,   32,    0,   32,    0,    0,    0,    0,
    0,    0,   45,    0,    0,    0,   21,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   48,    0,   21,
   48,   49,   19,    4,    5,   19,    4,    5,    0,    0,
    0,    0,   21,   48,   49,    0,   48,   49,   19,    4,
    5,    0,    0,    0,   21,
};
static const YYINT yycheck[] = {                         61,
    0,    0,    0,   61,  123,  125,    0,    0,    0,  125,
  125,  256,  256,  258,  256,  256,  256,  125,  272,  259,
  125,  284,  267,  265,  269,  284,  263,   61,   61,  268,
   61,  284,  272,  125,  279,  284,  278,  282,  279,  125,
  284,  283,  279,   61,  275,  123,  284,  123,  284,  284,
  284,  284,  284,  125,  284,  284,  284,   61,   61,   61,
  284,  123,  284,  284,   61,  123,   61,  284,  284,  284,
   61,   61,   61,   61,   61,   61,  284,  284,  284,  284,
  284,  284,  284,  284,  284,  284,  123,   61,  284,  284,
  284,  284,   46,    7,   14,   19,  111,   20,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  256,   -1,
   -1,  256,  257,   -1,  262,  260,  261,   -1,  266,   -1,
   -1,  269,   -1,   -1,  284,  284,  274,  275,  284,  284,
  256,  279,  277,  281,   -1,  280,  262,   -1,  270,  271,
  266,   -1,   -1,  269,  276,   -1,   -1,   -1,  274,  275,
   -1,   -1,   -1,  279,   -1,  281,   -1,   -1,   -1,   -1,
   -1,   -1,  264,   -1,   -1,   -1,  264,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  256,   -1,  259,
  259,  259,  256,  256,  256,  259,  259,  259,   -1,   -1,
   -1,   -1,  272,  272,  272,   -1,  275,  275,  272,  272,
  272,   -1,   -1,   -1,  284,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 284
#define YYUNDFTOKEN 301
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'='",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tARCH","tAS",
"tAUTOMOUNT","tCLUSTER","tCONFIG","tDUMPSET","tEQ","tNFSEQ","tEXPORTFS","tFREQ",
"tFROM","tFS","tFSTYPE","tHWADDR","tINADDR","tHOST","tLOCALHOST","tLOG",
"tMOUNT","tNETMASK","tNETIF","tVOLNAME","tOPTS","tOS","tPASSNO","tDIRECT",
"tSEL","tSTR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : list_of_hosts",
"list_of_hosts :",
"list_of_hosts : list_of_hosts host",
"list_of_hosts : list_of_hosts automount",
"host : tHOST host_attr list_of_filesystems list_of_mounts",
"host : error tHOST host_attr list_of_filesystems list_of_mounts",
"host_attr : tSTR",
"host_attr : '{' host_attr_list '}' tSTR",
"host_attr_list :",
"host_attr_list : host_attr_list tNETIF tSTR '{' ether_attr '}'",
"host_attr_list : host_attr_list tCONFIG tSTR",
"host_attr_list : host_attr_list tARCH '=' tSTR",
"host_attr_list : host_attr_list tOS '=' tSTR",
"host_attr_list : host_attr_list tCLUSTER '=' tSTR",
"host_attr_list : host_attr_list error '=' tSTR",
"ether_attr :",
"ether_attr : ether_attr tINADDR '=' tSTR",
"ether_attr : ether_attr tNETMASK '=' tSTR",
"ether_attr : ether_attr tHWADDR '=' tSTR",
"automount : tAUTOMOUNT opt_auto_opts automount_tree",
"automount : tAUTOMOUNT error",
"opt_auto_opts :",
"opt_auto_opts : tOPTS tSTR",
"list_of_filesystems :",
"list_of_filesystems : list_of_filesystems filesystem",
"filesystem : tFS tSTR '{' fs_info_list '}'",
"filesystem : tFS error '}'",
"fs_info_list :",
"fs_info_list : fs_info_list tFSTYPE '=' tSTR",
"fs_info_list : fs_info_list tOPTS '=' tSTR",
"fs_info_list : fs_info_list tPASSNO '=' tSTR",
"fs_info_list : fs_info_list tFREQ '=' tSTR",
"fs_info_list : fs_info_list tMOUNT dir_tree",
"fs_info_list : fs_info_list tDUMPSET '=' tSTR",
"fs_info_list : fs_info_list tLOG '=' tSTR",
"fs_info_list : fs_info_list error '=' tSTR",
"automount_tree :",
"automount_tree : automount_tree tSTR opt_auto_opts '=' tSTR",
"automount_tree : automount_tree tSTR opt_auto_opts tNFSEQ tSTR",
"automount_tree : automount_tree tSTR tEQ tSTR",
"automount_tree : automount_tree tSTR opt_auto_opts '{' automount_tree '}'",
"dir_tree :",
"dir_tree : dir_tree tSTR '{' dir_tree_info dir_tree '}'",
"dir_tree_info :",
"dir_tree_info : dir_tree_info tEXPORTFS tSTR",
"dir_tree_info : dir_tree_info tVOLNAME tSTR",
"dir_tree_info : dir_tree_info tSEL tSTR",
"dir_tree_info : dir_tree_info error '=' tSTR",
"list_of_mounts :",
"list_of_mounts : list_of_mounts tMOUNT tSTR localinfo_list",
"localinfo_list :",
"localinfo_list : localinfo_list tDIRECT",
"localinfo_list : localinfo_list tAS tSTR",
"localinfo_list : localinfo_list tFROM tSTR",
"localinfo_list : localinfo_list tFSTYPE tSTR",
"localinfo_list : localinfo_list tOPTS tSTR",
"localinfo_list : localinfo_list error '=' tSTR",

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
case 1:
#line 111 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.q = new_que(); }
break;
case 2:
#line 114 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ if (yystack.l_mark[0].h) ins_que((qelem *) yystack.l_mark[0].h, list_of_hosts->q_back);
	    yyval.q = yystack.l_mark[-1].q; }
break;
case 3:
#line 118 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ if (yystack.l_mark[0].a) ins_que((qelem *) yystack.l_mark[0].a, list_of_automounts->q_back);
	    yyval.q = yystack.l_mark[-1].q; }
break;
case 4:
#line 129 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.h = yystack.l_mark[-2].h; yyval.h->h_disk_fs = yystack.l_mark[-1].q; yyval.h->h_mount = yystack.l_mark[0].q; }
break;
case 5:
#line 132 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.h = yystack.l_mark[-2].h; yyval.h->h_disk_fs = yystack.l_mark[-1].q; yyval.h->h_mount = yystack.l_mark[0].q; }
break;
case 6:
#line 138 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.h = new_host(); set_host(yyval.h, HF_HOST, yystack.l_mark[0].s); }
break;
case 7:
#line 141 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.h = yystack.l_mark[-2].h; set_host(yyval.h, HF_HOST, yystack.l_mark[0].s); }
break;
case 8:
#line 147 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.h = new_host(); }
break;
case 9:
#line 150 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ if (yystack.l_mark[-1].e) {
		yystack.l_mark[-1].e->e_if = yystack.l_mark[-3].s;
		yyval.h = yystack.l_mark[-5].h; set_host(yyval.h, HF_ETHER, (char *) yystack.l_mark[-1].e); }
	  }
break;
case 10:
#line 156 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.h = yystack.l_mark[-2].h; set_host(yyval.h, HF_CONFIG, yystack.l_mark[0].s); }
break;
case 11:
#line 159 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.h = yystack.l_mark[-3].h; set_host(yyval.h, HF_ARCH, yystack.l_mark[0].s); }
break;
case 12:
#line 162 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.h = yystack.l_mark[-3].h; set_host(yyval.h, HF_OS, yystack.l_mark[0].s); }
break;
case 13:
#line 165 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.h = yystack.l_mark[-3].h; set_host(yyval.h, HF_CLUSTER, yystack.l_mark[0].s); }
break;
case 14:
#line 168 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyerror("unknown host attribute"); }
break;
case 15:
#line 173 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.e = new_ether_if(); }
break;
case 16:
#line 176 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.e = yystack.l_mark[-3].e; set_ether_if(yyval.e, EF_INADDR, yystack.l_mark[0].s); }
break;
case 17:
#line 178 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.e = yystack.l_mark[-3].e; set_ether_if(yyval.e, EF_NETMASK, yystack.l_mark[0].s); }
break;
case 18:
#line 180 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.e = yystack.l_mark[-3].e; set_ether_if(yyval.e, EF_HWADDR, yystack.l_mark[0].s); }
break;
case 19:
#line 190 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ if (yystack.l_mark[0].q) {
		yyval.a = new_auto_tree(yystack.l_mark[-1].s, yystack.l_mark[0].q);
	    } else {
		yyval.a = 0;
	    }
	  }
break;
case 20:
#line 198 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.a = 0; }
break;
case 21:
#line 203 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.s = strdup(""); }
break;
case 22:
#line 206 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.s = yystack.l_mark[0].s; }
break;
case 23:
#line 211 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.q = 0; }
break;
case 24:
#line 214 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ if (yystack.l_mark[0].d) {
		if (yystack.l_mark[-1].q)
			yyval.q = yystack.l_mark[-1].q;
		else
			yyval.q = new_que();
		ins_que(&yystack.l_mark[0].d->d_q, yyval.q->q_back);
	    } else {
		yyval.q = yystack.l_mark[-1].q;
	    }
	  }
break;
case 25:
#line 233 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yystack.l_mark[-1].d->d_dev = yystack.l_mark[-3].s; yyval.d = yystack.l_mark[-1].d; }
break;
case 26:
#line 236 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.d = (disk_fs *) 0; }
break;
case 27:
#line 252 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.d = new_disk_fs(); }
break;
case 28:
#line 255 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.d = yystack.l_mark[-3].d; set_disk_fs(yyval.d, DF_FSTYPE, yystack.l_mark[0].s); }
break;
case 29:
#line 258 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.d = yystack.l_mark[-3].d; set_disk_fs(yyval.d, DF_OPTS, yystack.l_mark[0].s); }
break;
case 30:
#line 261 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.d = yystack.l_mark[-3].d; set_disk_fs(yyval.d, DF_PASSNO, yystack.l_mark[0].s); }
break;
case 31:
#line 264 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.d = yystack.l_mark[-3].d; set_disk_fs(yyval.d, DF_FREQ, yystack.l_mark[0].s); }
break;
case 32:
#line 267 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.d = yystack.l_mark[-2].d; set_disk_fs(yyval.d, DF_MOUNT, (char *) yystack.l_mark[0].q); }
break;
case 33:
#line 270 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.d = yystack.l_mark[-3].d; set_disk_fs(yyval.d, DF_DUMPSET, yystack.l_mark[0].s); }
break;
case 34:
#line 273 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.d = yystack.l_mark[-3].d; set_disk_fs(yyval.d, DF_LOG, yystack.l_mark[0].s); }
break;
case 35:
#line 276 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyerror("unknown filesystem attribute"); }
break;
case 36:
#line 290 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.q = 0; }
break;
case 37:
#line 293 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ automount *a = new_automount(yystack.l_mark[-3].s);
	    a->a_volname = yystack.l_mark[0].s;
	    a->a_opts = yystack.l_mark[-2].s;
	    if (yystack.l_mark[-4].q)
		yyval.q = yystack.l_mark[-4].q;
	    else
		yyval.q = new_que();
	    ins_que(&a->a_q, yyval.q->q_back);
	  }
break;
case 38:
#line 303 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ automount *a = new_automount(yystack.l_mark[-3].s);
            a->a_hardwiredfs = yystack.l_mark[0].s;
            a->a_opts = yystack.l_mark[-2].s;
            if (yystack.l_mark[-4].q)
                yyval.q = yystack.l_mark[-4].q;
            else
                yyval.q = new_que();
            ins_que(&a->a_q, yyval.q->q_back);
          }
break;
case 39:
#line 314 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ automount *a = new_automount(yystack.l_mark[-2].s);
	    a->a_symlink = yystack.l_mark[0].s;
	    if (yystack.l_mark[-3].q)
		yyval.q = yystack.l_mark[-3].q;
	    else
		yyval.q = new_que();
	    ins_que(&a->a_q, yyval.q->q_back);
	  }
break;
case 40:
#line 324 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ automount *a = new_automount(yystack.l_mark[-4].s);
	    a->a_mount = yystack.l_mark[-1].q;
	    a->a_opts = yystack.l_mark[-3].s;
	    if (yystack.l_mark[-5].q)
		yyval.q = yystack.l_mark[-5].q;
	    else
		yyval.q = new_que();
	    ins_que(&a->a_q, yyval.q->q_back);
	  }
break;
case 41:
#line 337 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.q = 0; }
break;
case 42:
#line 340 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yystack.l_mark[-2].m->m_mount = yystack.l_mark[-1].q;
	    yystack.l_mark[-2].m->m_name = yystack.l_mark[-4].s;
	    if (yystack.l_mark[-4].s[0] != '/' && yystack.l_mark[-4].s[1] && strchr(yystack.l_mark[-4].s+1, '/'))
		yyerror("not allowed '/' in a directory name");
	    if (yystack.l_mark[-5].q)
		yyval.q = yystack.l_mark[-5].q;
	    else
		yyval.q = new_que();
	    ins_que(&yystack.l_mark[-2].m->m_q, yyval.q->q_back);
	  }
break;
case 43:
#line 354 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.m = new_mount(); }
break;
case 44:
#line 357 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.m = yystack.l_mark[-2].m; set_mount(yyval.m, DM_EXPORTFS, yystack.l_mark[0].s); }
break;
case 45:
#line 360 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.m = yystack.l_mark[-2].m; set_mount(yyval.m, DM_VOLNAME, yystack.l_mark[0].s); }
break;
case 46:
#line 363 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.m = yystack.l_mark[-2].m; set_mount(yyval.m, DM_SEL, yystack.l_mark[0].s); }
break;
case 47:
#line 366 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyerror("unknown directory attribute"); }
break;
case 48:
#line 376 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.q = 0; }
break;
case 49:
#line 379 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ set_fsmount(yystack.l_mark[0].f, FM_VOLNAME, yystack.l_mark[-1].s);
	    if (yystack.l_mark[-3].q)
		yyval.q = yystack.l_mark[-3].q;
	    else
		yyval.q = new_que();
	    ins_que(&yystack.l_mark[0].f->f_q, yyval.q->q_back);
	    }
break;
case 50:
#line 399 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.f = new_fsmount(); }
break;
case 51:
#line 402 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.f = yystack.l_mark[-1].f; set_fsmount(yyval.f, FM_DIRECT, ""); }
break;
case 52:
#line 405 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.f = yystack.l_mark[-2].f; set_fsmount(yyval.f, FM_LOCALNAME, yystack.l_mark[0].s); }
break;
case 53:
#line 408 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.f = yystack.l_mark[-2].f; set_fsmount(yyval.f, FM_FROM, yystack.l_mark[0].s); }
break;
case 54:
#line 411 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.f = yystack.l_mark[-2].f; set_fsmount(yyval.f, FM_FSTYPE, yystack.l_mark[0].s); }
break;
case 55:
#line 414 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyval.f = yystack.l_mark[-2].f; set_fsmount(yyval.f, FM_OPTS, yystack.l_mark[0].s); }
break;
case 56:
#line 417 "/usr/home/freebsd/omega/src/usr.sbin/amd/fsinfo/../../../contrib/amd/fsinfo/fsi_gram.y"
	{ yyerror("unknown mount attribute"); }
break;
#line 850 "fsi_gram.c"
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
