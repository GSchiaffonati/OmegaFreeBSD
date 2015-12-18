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
extern YYSTYPE yylval;
