#define INT 257
#define NAME 258
#define LNAME 259
#define PLUSEQ 260
#define MINUSEQ 261
#define MULTEQ 262
#define DIVEQ 263
#define LSHIFTEQ 264
#define RSHIFTEQ 265
#define ANDEQ 266
#define OREQ 267
#define OROR 268
#define ANDAND 269
#define EQ 270
#define NE 271
#define LE 272
#define GE 273
#define LSHIFT 274
#define RSHIFT 275
#define UNARY 276
#define END 277
#define ALIGN_K 278
#define BLOCK 279
#define BIND 280
#define QUAD 281
#define SQUAD 282
#define LONG 283
#define SHORT 284
#define BYTE 285
#define SECTIONS 286
#define PHDRS 287
#define DATA_SEGMENT_ALIGN 288
#define DATA_SEGMENT_RELRO_END 289
#define DATA_SEGMENT_END 290
#define SORT_BY_NAME 291
#define SORT_BY_ALIGNMENT 292
#define SIZEOF_HEADERS 293
#define OUTPUT_FORMAT 294
#define FORCE_COMMON_ALLOCATION 295
#define OUTPUT_ARCH 296
#define INHIBIT_COMMON_ALLOCATION 297
#define SEGMENT_START 298
#define INCLUDE 299
#define MEMORY 300
#define NOLOAD 301
#define DSECT 302
#define COPY 303
#define INFO 304
#define OVERLAY 305
#define DEFINED 306
#define TARGET_K 307
#define SEARCH_DIR 308
#define MAP 309
#define ENTRY 310
#define NEXT 311
#define SIZEOF 312
#define ALIGNOF 313
#define ADDR 314
#define LOADADDR 315
#define MAX_K 316
#define MIN_K 317
#define STARTUP 318
#define HLL 319
#define SYSLIB 320
#define FLOAT 321
#define NOFLOAT 322
#define NOCROSSREFS 323
#define ORIGIN 324
#define FILL 325
#define LENGTH 326
#define CREATE_OBJECT_SYMBOLS 327
#define INPUT 328
#define GROUP 329
#define OUTPUT 330
#define CONSTRUCTORS 331
#define ALIGNMOD 332
#define AT 333
#define SUBALIGN 334
#define PROVIDE 335
#define PROVIDE_HIDDEN 336
#define AS_NEEDED 337
#define CHIP 338
#define LIST 339
#define SECT 340
#define ABSOLUTE 341
#define LOAD 342
#define NEWLINE 343
#define ENDWORD 344
#define ORDER 345
#define NAMEWORD 346
#define ASSERT_K 347
#define FORMAT 348
#define PUBLIC 349
#define DEFSYMEND 350
#define BASE 351
#define ALIAS 352
#define TRUNCATE 353
#define REL 354
#define INPUT_SCRIPT 355
#define INPUT_MRI_SCRIPT 356
#define INPUT_DEFSYM 357
#define CASE 358
#define EXTERN 359
#define START 360
#define VERS_TAG 361
#define VERS_IDENTIFIER 362
#define GLOBAL 363
#define LOCAL 364
#define VERSIONK 365
#define INPUT_VERSION_SCRIPT 366
#define KEEP 367
#define ONLY_IF_RO 368
#define ONLY_IF_RW 369
#define SPECIAL 370
#define EXCLUDE_FILE 371
#define CONSTANT 372
#define INPUT_DYNAMIC_LIST 373
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  bfd_vma integer;
  struct big_int
    {
      bfd_vma integer;
      char *str;
    } bigint;
  fill_type *fill;
  char *name;
  const char *cname;
  struct wildcard_spec wildcard;
  struct wildcard_list *wildcard_list;
  struct name_list *name_list;
  int token;
  union etree_union *etree;
  struct phdr_info
    {
      bfd_boolean filehdr;
      bfd_boolean phdrs;
      union etree_union *at;
      union etree_union *flags;
    } phdr;
  struct lang_nocrossref *nocrossref;
  struct lang_output_section_phdr_list *section_phdr;
  struct bfd_elf_version_deps *deflist;
  struct bfd_elf_version_expr *versyms;
  struct bfd_elf_version_tree *versnode;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
