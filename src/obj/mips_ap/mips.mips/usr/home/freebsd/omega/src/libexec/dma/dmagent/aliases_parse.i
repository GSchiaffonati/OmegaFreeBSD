#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "/usr/home/freebsd/omega/src/libexec/dma/dmagent/../../../contrib/dma/aliases_parse.y"

#include <err.h>
#include <string.h>
#include <syslog.h>
#include "dma.h"

extern int yylineno;
static void yyerror(const char *);

static void
yyerror(const char *msg)
{
	/**
	 * Because we do error '\n' below, we need to report the error
	 * one line above of what yylineno points to.
	 */
	syslog(LOG_CRIT, "aliases line %d: %s", yylineno - 1, msg);
	fprintf(stderr, "aliases line %d: %s\n", yylineno - 1, msg);
}

int
yywrap(void)
{
	return (1);
}

#line 30 "/usr/home/freebsd/omega/src/libexec/dma/dmagent/../../../contrib/dma/aliases_parse.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char *ident;
	struct stritem *strit;
	struct alias *alias;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */

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

extern	int      yydebug;
extern	int      yynerrs;

extern	int      yyerrflag;
extern	int      yychar;
extern	YYSTYPE  yyval;
extern	YYSTYPE  yylval;
