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

#line 2 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
/*
 * parser.y
 */

/*-
 * Copyright (c) 2006 Maksim Yevmenkin <m_evmenkin@yahoo.com>
 * All rights reserved.
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
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id: parser.y,v 1.7 2006/09/07 21:06:53 max Exp $
 * $FreeBSD$
 */

#include <sys/queue.h>
#define L2CAP_SOCKET_CHECKED
#include <bluetooth.h>
#include <dev/usb/usb.h>
#include <dev/usb/usbhid.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <usbhid.h>

#ifndef BTHIDCONTROL
#include <stdarg.h>
#include <syslog.h>
#define	SYSLOG		syslog
#define	LOGCRIT		LOG_CRIT
#define	LOGERR		LOG_ERR
#define	LOGWARNING	LOG_WARNING
#define	EOL
#else
#define	SYSLOG		fprintf
#define	LOGCRIT		stderr
#define	LOGERR		stderr
#define	LOGWARNING	stderr
#define	EOL	"\n"
#endif /* ndef BTHIDCONTROL */

#include "bthid_config.h"

	int	yylex		(void);
	void	yyerror		(char const *);
static	int32_t	check_hid_device(hid_device_p hid_device);
static	void	free_hid_device	(hid_device_p hid_device);

extern	FILE			*yyin;
extern	int			 yylineno;
	char const		*config_file = BTHIDD_CONFFILE;
	char const		*hids_file   = BTHIDD_HIDSFILE;

static	char			 buffer[1024];
static	int32_t			 hid_descriptor_size;
static	hid_device_t		*hid_device = NULL;
static	LIST_HEAD(, hid_device)	 hid_devices;

#line 83 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	bdaddr_t	bdaddr;
	int32_t		num;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 113 "parser.c"

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

#define T_BDADDRSTRING 257
#define T_HEXBYTE 258
#define T_DEVICE 259
#define T_BDADDR 260
#define T_CONTROL_PSM 261
#define T_INTERRUPT_PSM 262
#define T_RECONNECT_INITIATE 263
#define T_BATTERY_POWER 264
#define T_NORMALLY_CONNECTABLE 265
#define T_HID_DESCRIPTOR 266
#define T_TRUE 267
#define T_FALSE 268
#define T_ERROR 269
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    2,    1,    3,    3,    4,    4,    4,    4,
    4,    4,    4,    4,    5,    6,    7,    8,    8,    9,
    9,   10,   10,   13,   11,   14,   14,   15,   12,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    5,    2,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    0,    5,    1,    2,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    3,    0,    1,    0,    2,    0,    0,    0,    0,    0,
    0,    0,   24,   29,    0,    0,    7,    8,    9,   10,
   11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
   21,   22,   23,    0,    4,    0,    5,    0,    6,   28,
    0,   26,   25,   27,
};
static const YYINT yydgoto[] = {                          2,
    3,    4,   15,   16,   17,   18,   19,   20,   21,   22,
   23,   24,   34,   41,   42,
};
static const YYINT yysindex[] = {                      -250,
    0, -250,    0, -113,    0, -258, -239, -238, -237, -255,
 -253, -251,    0,    0, -125,  -40,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -101,    0,  -36,    0, -234,    0,    0,
 -124,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   23,    0,    0,   11,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -14,
};
#define YYTABLESIZE 144
static const YYINT yytable[] = {                         35,
   43,    7,    8,    9,   10,   11,   12,   13,    1,    6,
   14,   28,   29,   30,   31,   32,   33,   25,   37,   26,
   27,   38,   39,   40,    5,   36,   44,    0,    0,    0,
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
    0,    0,    0,   40,    7,    8,    9,   10,   11,   12,
   13,    0,    0,   14,
};
static const YYINT yycheck[] = {                        125,
  125,  260,  261,  262,  263,  264,  265,  266,  259,  123,
  269,  267,  268,  267,  268,  267,  268,  257,   59,  258,
  258,  123,   59,  258,    2,   15,   41,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  258,  260,  261,  262,  263,  264,  265,
  266,   -1,   -1,  269,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#define YYUNDFTOKEN 287
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_BDADDRSTRING",
"T_HEXBYTE","T_DEVICE","T_BDADDR","T_CONTROL_PSM","T_INTERRUPT_PSM",
"T_RECONNECT_INITIATE","T_BATTERY_POWER","T_NORMALLY_CONNECTABLE",
"T_HID_DESCRIPTOR","T_TRUE","T_FALSE","T_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : config",
"config : line",
"config : config line",
"$$1 :",
"line : T_DEVICE $$1 '{' options '}'",
"options : option ';'",
"options : options option ';'",
"option : bdaddr",
"option : control_psm",
"option : interrupt_psm",
"option : reconnect_initiate",
"option : battery_power",
"option : normally_connectable",
"option : hid_descriptor",
"option : parser_error",
"bdaddr : T_BDADDR T_BDADDRSTRING",
"control_psm : T_CONTROL_PSM T_HEXBYTE",
"interrupt_psm : T_INTERRUPT_PSM T_HEXBYTE",
"reconnect_initiate : T_RECONNECT_INITIATE T_TRUE",
"reconnect_initiate : T_RECONNECT_INITIATE T_FALSE",
"battery_power : T_BATTERY_POWER T_TRUE",
"battery_power : T_BATTERY_POWER T_FALSE",
"normally_connectable : T_NORMALLY_CONNECTABLE T_TRUE",
"normally_connectable : T_NORMALLY_CONNECTABLE T_FALSE",
"$$2 :",
"hid_descriptor : T_HID_DESCRIPTOR $$2 '{' hid_descriptor_bytes '}'",
"hid_descriptor_bytes : hid_descriptor_byte",
"hid_descriptor_bytes : hid_descriptor_bytes hid_descriptor_byte",
"hid_descriptor_byte : T_HEXBYTE",
"parser_error : T_ERROR",

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
#line 222 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"

/* Display parser error message */
void
yyerror(char const *message)
{
	SYSLOG(LOGERR, "%s in line %d" EOL, message, yylineno); 
}

/* Re-read config file */
int32_t
read_config_file(void)
{
	int32_t	e;

	if (config_file == NULL) {
		SYSLOG(LOGERR, "Unknown config file name!" EOL);
		return (-1);
	}

	if ((yyin = fopen(config_file, "r")) == NULL) {
		SYSLOG(LOGERR, "Could not open config file '%s'. %s (%d)" EOL,
				config_file, strerror(errno), errno);
		return (-1);
	}

	clean_config();
	if (yyparse() < 0) {
		SYSLOG(LOGERR, "Could not parse config file '%s'" EOL,
				config_file);
		e = -1;
	} else
		e = 0;

	fclose(yyin);
	yyin = NULL;

	return (e);
}

/* Clean config */
void
clean_config(void)
{
	while (!LIST_EMPTY(&hid_devices)) {
		hid_device_p	d = LIST_FIRST(&hid_devices);

		LIST_REMOVE(d, next);
		free_hid_device(d);
	}
}

/* Lookup config entry */
hid_device_p
get_hid_device(bdaddr_p bdaddr)
{
	hid_device_p	d;

	LIST_FOREACH(d, &hid_devices, next)
		if (memcmp(&d->bdaddr, bdaddr, sizeof(bdaddr_t)) == 0)
			break;

	return (d);
}

/* Get next config entry */
hid_device_p
get_next_hid_device(hid_device_p d)
{
	return ((d == NULL)? LIST_FIRST(&hid_devices) : LIST_NEXT(d, next));
}

/* Print config entry */
void
print_hid_device(hid_device_p d, FILE *f)
{
	/* XXX FIXME hack! */
	struct report_desc {
		unsigned int	size;
		unsigned char	data[1];
	};
	/* XXX FIXME hack! */

	struct report_desc	*desc = (struct report_desc *) d->desc;
	uint32_t		 i;

	fprintf(f,
"device {\n"					\
"	bdaddr			%s;\n"		\
"	control_psm		0x%x;\n"	\
"	interrupt_psm		0x%x;\n"	\
"	reconnect_initiate	%s;\n"		\
"	battery_power		%s;\n"		\
"	normally_connectable	%s;\n"		\
"	hid_descriptor		{",
		bt_ntoa(&d->bdaddr, NULL),
		d->control_psm, d->interrupt_psm,
                d->reconnect_initiate? "true" : "false",
                d->battery_power? "true" : "false",
                d->normally_connectable? "true" : "false");
 
	for (i = 0; i < desc->size; i ++) {
			if ((i % 8) == 0)
				fprintf(f, "\n		");
 
			fprintf(f, "0x%2.2x ", desc->data[i]);
	}
                
	fprintf(f,
"\n"		\
"	};\n"	\
"}\n");
}

/* Check config entry */
static int32_t
check_hid_device(hid_device_p d)
{
	hid_data_t	hd;
	hid_item_t	hi;
	int32_t		page;

	if (get_hid_device(&d->bdaddr) != NULL) {
		SYSLOG(LOGERR, "Ignoring duplicated entry for bdaddr %s" EOL,
				bt_ntoa(&d->bdaddr, NULL));
		return (0);
	}

	if (d->control_psm == 0) {
		SYSLOG(LOGERR, "Ignoring entry with invalid control PSM" EOL);
		return (0);
	}

	if (d->interrupt_psm == 0) {
		SYSLOG(LOGERR, "Ignoring entry with invalid interrupt PSM" EOL);
		return (0);
	}

	if (d->desc == NULL) {
		SYSLOG(LOGERR, "Ignoring entry without HID descriptor" EOL);
		return (0);
	}

	/* XXX somehow need to make sure descriptor is valid */
	for (hd = hid_start_parse(d->desc, ~0, -1); hid_get_item(hd, &hi) > 0; ) {
		switch (hi.kind) {
		case hid_collection:
		case hid_endcollection:
		case hid_output:
		case hid_feature:
			break;

		case hid_input:
			/* Check if the device may send keystrokes */
			page = HID_PAGE(hi.usage);
			if (page == HUP_KEYBOARD)
				d->keyboard = 1;
			break;
		}
	}
	hid_end_parse(hd);

	return (1);
}

/* Free config entry */
static void
free_hid_device(hid_device_p d)
{
	if (d->desc != NULL)
		hid_dispose_report_desc(d->desc);

	memset(d, 0, sizeof(*d));
	free(d);
}

/* Re-read hids file */
int32_t
read_hids_file(void)
{
	FILE		*f;
	hid_device_t	*d;
	char		*line;
	bdaddr_t	 bdaddr;
	int32_t		 lineno;

	if (hids_file == NULL) {
		SYSLOG(LOGERR, "Unknown HIDs file name!" EOL);
		return (-1);
	}

	if ((f = fopen(hids_file, "r")) == NULL) {
		if (errno == ENOENT)
			return (0);

		SYSLOG(LOGERR, "Could not open HIDs file '%s'. %s (%d)" EOL,
			hids_file, strerror(errno), errno);
		return (-1);
	}

	for (lineno = 1; fgets(buffer, sizeof(buffer), f) != NULL; lineno ++) {
		if ((line = strtok(buffer, "\r\n\t ")) == NULL)
			continue; /* ignore empty lines */

		if (!bt_aton(line, &bdaddr)) {
			SYSLOG(LOGWARNING, "Ignoring unparseable BD_ADDR in " \
				"%s:%d" EOL, hids_file, lineno);
			continue;
		}

		if ((d = get_hid_device(&bdaddr)) != NULL)
			d->new_device = 0;
	}

	fclose(f);

	return (0);
}

/* Write hids file */
int32_t
write_hids_file(void)
{
	char		 path[PATH_MAX];
	FILE		*f;
	hid_device_t	*d;

	if (hids_file == NULL) {
		SYSLOG(LOGERR, "Unknown HIDs file name!" EOL);
		return (-1);
	}

	snprintf(path, sizeof(path), "%s.new", hids_file);

	if ((f = fopen(path, "w")) == NULL) {
		SYSLOG(LOGERR, "Could not open HIDs file '%s'. %s (%d)" EOL,
			path, strerror(errno), errno);
		return (-1);
	}

	LIST_FOREACH(d, &hid_devices, next)
		if (!d->new_device)
			fprintf(f, "%s\n", bt_ntoa(&d->bdaddr, NULL));

	fclose(f);

	if (rename(path, hids_file) < 0) {
		SYSLOG(LOGERR, "Could not rename new HIDs file '%s' to '%s'. " \
			"%s (%d)" EOL, path, hids_file, strerror(errno), errno);
		unlink(path);
		return (-1);
	}

	return (0);
}

#line 581 "parser.c"

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
case 3:
#line 101 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			hid_device = (hid_device_t *) calloc(1, sizeof(*hid_device));
			if (hid_device == NULL) {
				SYSLOG(LOGCRIT, "Could not allocate new " \
						"config entry" EOL);
				YYABORT;
			}

			hid_device->new_device = 1;
			}
break;
case 4:
#line 112 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			if (check_hid_device(hid_device))
				LIST_INSERT_HEAD(&hid_devices,hid_device,next);
			else
				free_hid_device(hid_device);

			hid_device = NULL;
			}
break;
case 15:
#line 137 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			memcpy(&hid_device->bdaddr, &yystack.l_mark[0].bdaddr, sizeof(hid_device->bdaddr));
			}
break;
case 16:
#line 143 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			hid_device->control_psm = yystack.l_mark[0].num;
			}
break;
case 17:
#line 149 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			hid_device->interrupt_psm = yystack.l_mark[0].num;
			}
break;
case 18:
#line 155 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			hid_device->reconnect_initiate = 1;
			}
break;
case 19:
#line 159 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			hid_device->reconnect_initiate = 0;
			}
break;
case 20:
#line 165 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			hid_device->battery_power = 1;
			}
break;
case 21:
#line 169 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			hid_device->battery_power = 0;
			}
break;
case 22:
#line 175 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			hid_device->normally_connectable = 1;
			}
break;
case 23:
#line 179 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			hid_device->normally_connectable = 0;
			}
break;
case 24:
#line 185 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			hid_descriptor_size = 0;
			}
break;
case 25:
#line 189 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			if (hid_device->desc != NULL)
				hid_dispose_report_desc(hid_device->desc);

			hid_device->desc = hid_use_report_desc((unsigned char *) buffer, hid_descriptor_size);
			if (hid_device->desc == NULL) {
				SYSLOG(LOGCRIT, "Could not use HID descriptor" EOL);
				YYABORT;
			}
			}
break;
case 28:
#line 206 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
			if (hid_descriptor_size >= (int32_t) sizeof(buffer)) {
				SYSLOG(LOGCRIT, "HID descriptor is too big" EOL);
				YYABORT;
			}

			buffer[hid_descriptor_size ++] = yystack.l_mark[0].num;
			}
break;
case 29:
#line 217 "/usr/home/freebsd/omega/src/usr.sbin/bluetooth/bthidd/parser.y"
	{
				YYABORT;
			}
break;
#line 897 "parser.c"
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
