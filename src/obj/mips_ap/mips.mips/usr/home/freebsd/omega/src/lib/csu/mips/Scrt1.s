	.file	1 "crt1.c"
	.section .mdebug.abi32
	.previous
	.abicalls
 #APP
	.ident	"$FreeBSD$"
	.ident	"$FreeBSD$"
	.ident	"$FreeBSD$"
 #NO_APP
	.text
	.align	2
	.globl	__start
	.ent	__start
__start:
	.frame	$sp,56,$31		# vars= 0, regs= 7/0, args= 16, gp= 8
	.mask	0x803f0000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	reorder
	addiu	$sp,$sp,-56
	sw	$31,48($sp)
	sw	$21,44($sp)
	sw	$20,40($sp)
	sw	$19,36($sp)
	sw	$18,32($sp)
	sw	$17,28($sp)
	sw	$16,24($sp)
	.cprestore	16
	lw	$16,0($4)
	addiu	$17,$4,4
	addiu	$4,$4,8
	sll	$2,$16,2
	addu	$18,$4,$2
	la	$3,environ
	lw	$2,0($3)
	bne	$2,$0,.L2
	sw	$18,0($3)
.L2:
	blez	$16,.L4
	lw	$3,0($17)
	beq	$3,$0,.L4
	la	$2,__progname
	sw	$3,0($2)
	lb	$4,0($3)
	.set	noreorder
	.set	nomacro
	beq	$4,$0,.L4
	addiu	$3,$3,1
	.set	macro
	.set	reorder

	move	$6,$2
.L8:
	li	$2,47			# 0x2f
	bne	$4,$2,.L9
	sw	$3,0($6)
.L9:
	lb	$4,0($3)
	.set	noreorder
	.set	nomacro
	bne	$4,$0,.L8
	addiu	$3,$3,1
	.set	macro
	.set	reorder

.L4:
	la	$2,_DYNAMIC
	.set	noreorder
	.set	nomacro
	beq	$2,$0,.L11
	move	$4,$5
	.set	macro
	.set	reorder

	jal	atexit
	.set	noreorder
	.set	nomacro
	b	.L27
	move	$4,$16
	.set	macro
	.set	reorder

.L11:
	jal	_init_tls
	la	$4,finalizer
	jal	atexit
	la	$3,__preinit_array_start
	la	$2,__preinit_array_end
	subu	$2,$2,$3
	sra	$21,$2,2
	beq	$21,$0,.L14
	move	$20,$3
	move	$19,$0
.L16:
	lw	$25,0($20)
	sltu	$2,$25,2
	.set	noreorder
	.set	nomacro
	bne	$2,$0,.L17
	move	$4,$16
	.set	macro
	.set	reorder

	move	$5,$17
	move	$6,$18
	jal	$25
.L17:
	addiu	$19,$19,1
	.set	noreorder
	.set	nomacro
	bne	$21,$19,.L16
	addiu	$20,$20,4
	.set	macro
	.set	reorder

.L14:
	jal	_init
	la	$3,__init_array_start
	la	$2,__init_array_end
	subu	$2,$2,$3
	sra	$21,$2,2
	.set	noreorder
	.set	nomacro
	beq	$21,$0,.L27
	move	$4,$16
	.set	macro
	.set	reorder

	move	$20,$3
	move	$19,$0
.L20:
	lw	$25,0($20)
	sltu	$2,$25,2
	.set	noreorder
	.set	nomacro
	bne	$2,$0,.L21
	move	$4,$16
	.set	macro
	.set	reorder

	move	$5,$17
	move	$6,$18
	jal	$25
.L21:
	addiu	$19,$19,1
	.set	noreorder
	.set	nomacro
	bne	$21,$19,.L20
	addiu	$20,$20,4
	.set	macro
	.set	reorder

	move	$4,$16
.L27:
	move	$5,$17
	move	$6,$18
	jal	main
	move	$4,$2
	jal	exit
	.end	__start
	.size	__start, .-__start
	.align	2
	.ent	finalizer
finalizer:
	.frame	$sp,40,$31		# vars= 0, regs= 3/0, args= 16, gp= 8
	.mask	0x80030000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	reorder
	addiu	$sp,$sp,-40
	sw	$31,32($sp)
	sw	$17,28($sp)
	sw	$16,24($sp)
	.cprestore	16
	la	$4,__fini_array_start
	la	$2,__fini_array_end
	subu	$2,$2,$4
	sra	$3,$2,2
	.set	noreorder
	.set	nomacro
	beq	$3,$0,.L29
	sll	$2,$3,2
	.set	macro
	.set	reorder

	addu	$17,$2,$4
	move	$16,$3
.L31:
	lw	$25,-4($17)
	sltu	$2,$25,2
	.set	noreorder
	.set	nomacro
	bne	$2,$0,.L32
	addiu	$16,$16,-1
	.set	macro
	.set	reorder

	jal	$25
.L32:
	.set	noreorder
	.set	nomacro
	bne	$16,$0,.L31
	addiu	$17,$17,-4
	.set	macro
	.set	reorder

.L29:
	jal	_fini
	lw	$31,32($sp)
	lw	$17,28($sp)
	lw	$16,24($sp)
	.set	noreorder
	.set	nomacro
	j	$31
	addiu	$sp,$sp,40
	.set	macro
	.set	reorder

	.end	finalizer
	.size	finalizer, .-finalizer
	.globl	__progname
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align	2
.LC0:
	.string	""
	.section	.data.rel.local,"aw",@progbits
	.align	2
	.type	__progname, @object
	.size	__progname, 4
__progname:
	.word	.LC0
	.section	.note.tag,"a",@note
	.align	2
	.type	crt_noinit_tag, @object
	.size	crt_noinit_tag, 24
crt_noinit_tag:
	.word	8
	.word	4
	.word	2
	.string	"FreeBSD"
	.word	0
	.align	2
	.type	abitag, @object
	.size	abitag, 24
abitag:
	.word	8
	.word	4
	.word	1
	.string	"FreeBSD"
	.word	1100091

	.comm	environ,4,4
	.weak	_DYNAMIC
	.ident	"GCC: (GNU) 4.2.1 20070831 patched [FreeBSD]"
