#define SEMICOLON 257
#define BEGINBLOCK 258
#define ENDBLOCK 259
#define COMMA 260
#define NUMBER 261
#define STRING 262
#define ID 263
#define OPTIONS 264
#define SET 265
#define DIRECTORY 266
#define PID_FILE 267
#define DEVICE_NAME 268
#define ACTION 269
#define MATCH 270
#define ATTACH 271
#define DETACH 272
#define NOMATCH 273
#define NOTIFY 274
#define MEDIA_TYPE 275
#define CLASS 276
#define SUBDEVICE 277
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char *str;
	int i;
	struct eps *eps;	/* EventProcStatement */
	struct event_proc *eventproc;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
