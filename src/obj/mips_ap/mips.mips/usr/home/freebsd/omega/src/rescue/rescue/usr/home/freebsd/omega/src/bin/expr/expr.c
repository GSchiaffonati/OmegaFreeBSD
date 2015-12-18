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

#line 2 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
/*-
 * Written by Pace Willisson (pace@blitz.com)
 * and placed in the public domain.
 *
 * Largely rewritten by J.T. Conklin (jtc@wimsey.com)
 *
 * $FreeBSD$
 */

#include <sys/types.h>

#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <unistd.h>

/*
 * POSIX specifies a specific error code for syntax errors.  We exit
 * with this code for all errors.
 */
#define	ERR_EXIT	2

enum valtype {
	integer, numeric_string, string
} ;

struct val {
	enum valtype type;
	union {
		char *s;
		intmax_t i;
	} u;
} ;

char		**av;
int		nonposix;
struct val	*result;

void		assert_to_integer(struct val *);
void		assert_div(intmax_t, intmax_t);
void		assert_minus(intmax_t, intmax_t, intmax_t);
void		assert_plus(intmax_t, intmax_t, intmax_t);
void		assert_times(intmax_t, intmax_t, intmax_t);
int		compare_vals(struct val *, struct val *);
void		free_value(struct val *);
int		is_integer(const char *);
int		is_string(struct val *);
int		is_zero_or_null(struct val *);
struct val	*make_integer(intmax_t);
struct val	*make_str(const char *);
struct val	*op_and(struct val *, struct val *);
struct val	*op_colon(struct val *, struct val *);
struct val	*op_div(struct val *, struct val *);
struct val	*op_eq(struct val *, struct val *);
struct val	*op_ge(struct val *, struct val *);
struct val	*op_gt(struct val *, struct val *);
struct val	*op_le(struct val *, struct val *);
struct val	*op_lt(struct val *, struct val *);
struct val	*op_minus(struct val *, struct val *);
struct val	*op_ne(struct val *, struct val *);
struct val	*op_or(struct val *, struct val *);
struct val	*op_plus(struct val *, struct val *);
struct val	*op_rem(struct val *, struct val *);
struct val	*op_times(struct val *, struct val *);
int		to_integer(struct val *);
void		to_string(struct val *);
int		yyerror(const char *);
int		yylex(void);

#line 80 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
	struct val *val;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 110 "expr.c"

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

#define GE 257
#define LE 258
#define NE 259
#define TOKEN 260
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    1,    1,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,
};
static const YYINT yydefred[] = {                         0,
    2,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   17,
};
static const YYINT yydgoto[] = {                          3,
    4,
};
static const YYINT yysindex[] = {                       -40,
    0,  -40,    0,  149,  -34,  -40,  -40,  -40,  -40,  -40,
  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,    0,
  189,  219,  -27,  -27,  -27,  -27,  -27,  -27,   28,   28,
  -56,  -56,  -56,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    5,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6,   30,   66,   91,   97,  105,  109,  144,   51,   79,
    1,   12,   40,    0,
};
static const YYINT yygindex[] = {                         0,
  276,
};
#define YYTABLESIZE 478
static const YYINT yytable[] = {                          2,
   14,   19,   18,    7,    1,    4,   20,   16,   14,   18,
   15,   15,   17,    0,   16,   14,    0,   15,    0,   17,
    0,    0,    0,   19,    0,   10,    8,    9,    0,    5,
   19,    0,    0,    0,    0,    0,    0,   14,   14,   16,
    0,   14,   14,   14,    0,   14,    4,   14,   15,   15,
   12,    0,   15,   15,   15,    0,   15,    0,   15,    0,
   14,   14,   14,    0,   18,    6,    0,    5,    0,   16,
    5,   15,   15,   15,   17,    0,   16,   16,   13,    0,
   16,   16,   16,    0,   16,   19,   16,    0,   12,    6,
    7,   12,    0,   12,    0,   12,    8,    0,    0,   16,
   16,   16,    0,    6,    9,    0,    6,    0,   10,    0,
   12,   12,   12,    0,    0,    0,   13,    0,    0,   13,
    0,   13,    0,   13,   14,    6,    6,    6,    7,    4,
    0,    7,    0,    0,    8,   15,    0,    8,   13,   13,
   13,    0,    9,   11,    0,    9,   10,    0,    0,   10,
    7,    7,    7,    5,    0,    0,    8,    8,    8,    0,
    0,    0,    0,   16,    9,    9,    9,    0,   10,   10,
   10,    0,    0,    0,   12,    0,    0,    0,    0,    0,
    0,   11,    0,    0,   11,   18,    7,    0,    0,    6,
   16,   14,    0,   15,    0,   17,    0,    0,    0,    0,
    0,    0,   13,   11,   11,   11,   19,    0,   10,    8,
    9,    0,    0,    0,    7,    0,    0,    0,    0,    1,
    8,    0,   11,   12,   13,   18,    7,    0,    9,    0,
   16,   14,   10,   15,    0,   17,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   19,    0,   10,    8,
    9,    0,    0,    0,    0,   18,    0,   14,   14,   14,
   16,   14,    0,   15,    0,   17,    0,   11,   15,   15,
   15,    0,    6,    0,    0,    0,   19,    5,   10,    8,
    9,   21,   22,   23,   24,   25,   26,   27,   28,   29,
   30,   31,   32,   33,   34,    0,   16,   16,   16,    0,
    0,    0,    0,    0,    0,    0,    0,   12,   12,   12,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    6,    6,    6,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   13,   13,   13,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    7,    7,    7,
    0,    0,    0,    8,    8,    8,    0,    0,    0,    0,
    0,    9,    9,    9,    0,   10,   10,   10,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   11,   11,   11,    0,    0,   11,   12,   13,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   11,   12,   13,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   11,   12,   13,
};
static const YYINT yycheck[] = {                         40,
    0,   58,   37,   38,    0,    0,   41,   42,   43,   37,
   45,    0,   47,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   58,   -1,   60,   61,   62,   -1,    0,
   58,   -1,   -1,   -1,   -1,   -1,   -1,   37,   38,    0,
   -1,   41,   42,   43,   -1,   45,   41,   47,   37,   38,
    0,   -1,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   60,   61,   62,   -1,   37,    0,   -1,   38,   -1,   42,
   41,   60,   61,   62,   47,   -1,   37,   38,    0,   -1,
   41,   42,   43,   -1,   45,   58,   47,   -1,   38,  124,
    0,   41,   -1,   43,   -1,   45,    0,   -1,   -1,   60,
   61,   62,   -1,   38,    0,   -1,   41,   -1,    0,   -1,
   60,   61,   62,   -1,   -1,   -1,   38,   -1,   -1,   41,
   -1,   43,   -1,   45,  124,   60,   61,   62,   38,  124,
   -1,   41,   -1,   -1,   38,  124,   -1,   41,   60,   61,
   62,   -1,   38,    0,   -1,   41,   38,   -1,   -1,   41,
   60,   61,   62,  124,   -1,   -1,   60,   61,   62,   -1,
   -1,   -1,   -1,  124,   60,   61,   62,   -1,   60,   61,
   62,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   38,   -1,   -1,   41,   37,   38,   -1,   -1,  124,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,   -1,  124,   60,   61,   62,   58,   -1,   60,   61,
   62,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,  260,
  124,   -1,  257,  258,  259,   37,   38,   -1,  124,   -1,
   42,   43,  124,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   58,   -1,   60,   61,
   62,   -1,   -1,   -1,   -1,   37,   -1,  257,  258,  259,
   42,   43,   -1,   45,   -1,   47,   -1,  124,  257,  258,
  259,   -1,  124,   -1,   -1,   -1,   58,    2,   60,   61,
   62,    6,    7,    8,    9,   10,   11,   12,   13,   14,
   15,   16,   17,   18,   19,   -1,  257,  258,  259,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
   -1,   -1,   -1,  257,  258,  259,   -1,   -1,   -1,   -1,
   -1,  257,  258,  259,   -1,  257,  258,  259,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,   -1,   -1,  257,  258,  259,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 260
#define YYUNDFTOKEN 264
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'",0,"'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"GE","LE","NE","TOKEN",0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : expr",
"expr : TOKEN",
"expr : '(' expr ')'",
"expr : expr '|' expr",
"expr : expr '&' expr",
"expr : expr '=' expr",
"expr : expr '>' expr",
"expr : expr '<' expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr NE expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr ':' expr",

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
#line 118 "/usr/home/freebsd/omega/src/bin/expr/expr.y"

struct val *
make_integer(intmax_t i)
{
	struct val *vp;

	vp = (struct val *)malloc(sizeof(*vp));
	if (vp == NULL)
		errx(ERR_EXIT, "malloc() failed");

	vp->type = integer;
	vp->u.i  = i;
	return (vp);
}

struct val *
make_str(const char *s)
{
	struct val *vp;

	vp = (struct val *)malloc(sizeof(*vp));
	if (vp == NULL || ((vp->u.s = strdup(s)) == NULL))
		errx(ERR_EXIT, "malloc() failed");

	if (is_integer(s))
		vp->type = numeric_string;
	else
		vp->type = string;

	return (vp);
}

void
free_value(struct val *vp)
{
	if (vp->type == string || vp->type == numeric_string)
		free(vp->u.s);
}

int
to_integer(struct val *vp)
{
	intmax_t i;

	/* we can only convert numeric_string to integer, here */
	if (vp->type == numeric_string) {
		errno = 0;
		i  = strtoimax(vp->u.s, (char **)NULL, 10);
		/* just keep as numeric_string, if the conversion fails */
		if (errno != ERANGE) {
			free(vp->u.s);
			vp->u.i = i;
			vp->type = integer;
		}
	}
	return (vp->type == integer);
}

void
assert_to_integer(struct val *vp)
{
	if (vp->type == string)
		errx(ERR_EXIT, "not a decimal number: '%s'", vp->u.s);
	if (!to_integer(vp))
		errx(ERR_EXIT, "operand too large: '%s'", vp->u.s);
}

void
to_string(struct val *vp)
{
	char *tmp;

	if (vp->type == string || vp->type == numeric_string)
		return;

	/*
	 * log_10(x) ~= 0.3 * log_2(x).  Rounding up gives the number
	 * of digits; add one each for the sign and terminating null
	 * character, respectively.
	 */
#define	NDIGITS(x) (3 * (sizeof(x) * CHAR_BIT) / 10 + 1 + 1 + 1)
	tmp = malloc(NDIGITS(vp->u.i));
	if (tmp == NULL)
		errx(ERR_EXIT, "malloc() failed");

	sprintf(tmp, "%jd", vp->u.i);
	vp->type = string;
	vp->u.s  = tmp;
}

int
is_integer(const char *s)
{
	if (nonposix) {
		if (*s == '\0')
			return (1);
		while (isspace((unsigned char)*s))
			s++;
	}
	if (*s == '-' || (nonposix && *s == '+'))
		s++;
	if (*s == '\0')
		return (0);
	while (isdigit((unsigned char)*s))
		s++;
	return (*s == '\0');
}

int
is_string(struct val *vp)
{
	/* only TRUE if this string is not a valid integer */
	return (vp->type == string);
}

int
yylex(void)
{
	char *p;

	if (*av == NULL)
		return (0);

	p = *av++;

	if (strlen(p) == 1) {
		if (strchr("|&=<>+-*/%:()", *p))
			return (*p);
	} else if (strlen(p) == 2 && p[1] == '=') {
		switch (*p) {
		case '>': return (GE);
		case '<': return (LE);
		case '!': return (NE);
		}
	}

	yylval.val = make_str(p);
	return (TOKEN);
}

int
is_zero_or_null(struct val *vp)
{
	if (vp->type == integer)
		return (vp->u.i == 0);

	return (*vp->u.s == 0 || (to_integer(vp) && vp->u.i == 0));
}

int
main(int argc, char *argv[])
{
	int c;

	setlocale(LC_ALL, "");
	if (getenv("EXPR_COMPAT") != NULL
	    || check_utility_compat("expr")) {
		av = argv + 1;
		nonposix = 1;
	} else {
		while ((c = getopt(argc, argv, "e")) != -1) {
			switch (c) {
			case 'e':
				nonposix = 1;
				break;
			default:
				errx(ERR_EXIT,
				    "usage: expr [-e] expression\n");
			}
		}
		av = argv + optind;
	}

	yyparse();

	if (result->type == integer)
		printf("%jd\n", result->u.i);
	else
		printf("%s\n", result->u.s);

	return (is_zero_or_null(result));
}

int
yyerror(const char *s __unused)
{
	errx(ERR_EXIT, "syntax error");
}

struct val *
op_or(struct val *a, struct val *b)
{
	if (!is_zero_or_null(a)) {
		free_value(b);
		return (a);
	}
	free_value(a);
	if (!is_zero_or_null(b))
		return (b);
	free_value(b);
	return (make_integer((intmax_t)0));
}

struct val *
op_and(struct val *a, struct val *b)
{
	if (is_zero_or_null(a) || is_zero_or_null(b)) {
		free_value(a);
		free_value(b);
		return (make_integer((intmax_t)0));
	} else {
		free_value(b);
		return (a);
	}
}

int
compare_vals(struct val *a, struct val *b)
{
	int r;

	if (is_string(a) || is_string(b)) {
		to_string(a);
		to_string(b);
		r = strcoll(a->u.s, b->u.s);
	} else {
		assert_to_integer(a);
		assert_to_integer(b);
		if (a->u.i > b->u.i)
			r = 1;
		else if (a->u.i < b->u.i)
			r = -1;
		else
			r = 0;
	}

	free_value(a);
	free_value(b);
	return (r);
}

struct val *
op_eq(struct val *a, struct val *b)
{
	return (make_integer((intmax_t)(compare_vals(a, b) == 0)));
}

struct val *
op_gt(struct val *a, struct val *b)
{
	return (make_integer((intmax_t)(compare_vals(a, b) > 0)));
}

struct val *
op_lt(struct val *a, struct val *b)
{
	return (make_integer((intmax_t)(compare_vals(a, b) < 0)));
}

struct val *
op_ge(struct val *a, struct val *b)
{
	return (make_integer((intmax_t)(compare_vals(a, b) >= 0)));
}

struct val *
op_le(struct val *a, struct val *b)
{
	return (make_integer((intmax_t)(compare_vals(a, b) <= 0)));
}

struct val *
op_ne(struct val *a, struct val *b)
{
	return (make_integer((intmax_t)(compare_vals(a, b) != 0)));
}

void
assert_plus(intmax_t a, intmax_t b, intmax_t r)
{
	/*
	 * sum of two positive numbers must be positive,
	 * sum of two negative numbers must be negative
	 */
	if ((a > 0 && b > 0 && r <= 0) ||
	    (a < 0 && b < 0 && r >= 0))
		errx(ERR_EXIT, "overflow");
}

struct val *
op_plus(struct val *a, struct val *b)
{
	struct val *r;

	assert_to_integer(a);
	assert_to_integer(b);
	r = make_integer(a->u.i + b->u.i);
	assert_plus(a->u.i, b->u.i, r->u.i);

	free_value(a);
	free_value(b);
	return (r);
}

void
assert_minus(intmax_t a, intmax_t b, intmax_t r)
{
	/* special case subtraction of INTMAX_MIN */
	if (b == INTMAX_MIN && a < 0)
		errx(ERR_EXIT, "overflow");
	/* check addition of negative subtrahend */
	assert_plus(a, -b, r);
}

struct val *
op_minus(struct val *a, struct val *b)
{
	struct val *r;

	assert_to_integer(a);
	assert_to_integer(b);
	r = make_integer(a->u.i - b->u.i);
	assert_minus(a->u.i, b->u.i, r->u.i);

	free_value(a);
	free_value(b);
	return (r);
}

/*
 * We depend on undefined behaviour giving a result (in r).
 * To test this result, pass it as volatile.  This prevents
 * optimizing away of the test based on the undefined behaviour.
 */
void
assert_times(intmax_t a, intmax_t b, volatile intmax_t r)
{
	/*
	 * If the first operand is 0, no overflow is possible, 
	 * else the result of the division test must match the
	 * second operand.
	 *
	 * Be careful to avoid overflow in the overflow test, as
	 * in assert_div().  Overflow in division would kill us
	 * with a SIGFPE before getting the test wrong.  In old
	 * buggy versions, optimization used to give a null test
	 * instead of a SIGFPE.
	 */
	if ((a == -1 && b == INTMAX_MIN) || (a != 0 && r / a != b))
		errx(ERR_EXIT, "overflow");
}

struct val *
op_times(struct val *a, struct val *b)
{
	struct val *r;

	assert_to_integer(a);
	assert_to_integer(b);
	r = make_integer(a->u.i * b->u.i);
	assert_times(a->u.i, b->u.i, r->u.i);

	free_value(a);
	free_value(b);
	return (r);
}

void
assert_div(intmax_t a, intmax_t b)
{
	if (b == 0)
		errx(ERR_EXIT, "division by zero");
	/* only INTMAX_MIN / -1 causes overflow */
	if (a == INTMAX_MIN && b == -1)
		errx(ERR_EXIT, "overflow");
}

struct val *
op_div(struct val *a, struct val *b)
{
	struct val *r;

	assert_to_integer(a);
	assert_to_integer(b);
	/* assert based on operands only, not on result */
	assert_div(a->u.i, b->u.i);
	r = make_integer(a->u.i / b->u.i);

	free_value(a);
	free_value(b);
	return (r);
}

struct val *
op_rem(struct val *a, struct val *b)
{
	struct val *r;

	assert_to_integer(a);
	assert_to_integer(b);
	/* pass a=1 to only check for div by zero */
	assert_div(1, b->u.i);
	r = make_integer(a->u.i % b->u.i);

	free_value(a);
	free_value(b);
	return (r);
}

struct val *
op_colon(struct val *a, struct val *b)
{
	regex_t rp;
	regmatch_t rm[2];
	char errbuf[256];
	int eval;
	struct val *v;

	/* coerce both arguments to strings */
	to_string(a);
	to_string(b);

	/* compile regular expression */
	if ((eval = regcomp(&rp, b->u.s, 0)) != 0) {
		regerror(eval, &rp, errbuf, sizeof(errbuf));
		errx(ERR_EXIT, "%s", errbuf);
	}

	/* compare string against pattern */
	/* remember that patterns are anchored to the beginning of the line */
	if (regexec(&rp, a->u.s, (size_t)2, rm, 0) == 0 && rm[0].rm_so == 0)
		if (rm[1].rm_so >= 0) {
			*(a->u.s + rm[1].rm_eo) = '\0';
			v = make_str(a->u.s + rm[1].rm_so);

		} else
			v = make_integer((intmax_t)(rm[0].rm_eo));
	else
		if (rp.re_nsub == 0)
			v = make_integer((intmax_t)0);
		else
			v = make_str("");

	/* free arguments and pattern buffer */
	free_value(a);
	free_value(b);
	regfree(&rp);

	return (v);
}
#line 808 "expr.c"

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
#line 97 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ result = yyval.val; }
break;
case 3:
#line 100 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = yystack.l_mark[-1].val; }
break;
case 4:
#line 101 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_or(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 5:
#line 102 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_and(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 6:
#line 103 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_eq(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 7:
#line 104 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_gt(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 8:
#line 105 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_lt(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 9:
#line 106 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_ge(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 10:
#line 107 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_le(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 11:
#line 108 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_ne(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 12:
#line 109 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_plus(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 13:
#line 110 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_minus(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 14:
#line 111 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_times(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 15:
#line 112 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_div(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 16:
#line 113 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_rem(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
case 17:
#line 114 "/usr/home/freebsd/omega/src/bin/expr/expr.y"
	{ yyval.val = op_colon(yystack.l_mark[-2].val, yystack.l_mark[0].val); }
break;
#line 1074 "expr.c"
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
