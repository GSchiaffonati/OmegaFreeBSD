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
extern YYSTYPE yylval;
