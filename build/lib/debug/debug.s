;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	debug.c
	.area	.text
LC0:
	.byte	70,73,76,69,58,-128,0
LC1:
	.byte	76,73,78,69,58,-128,0
LC2:
	.byte	86,65,76,85,69,58,-128,0
	.globl	__f_debug
__f_debug:
	pshs	y,u
	leas	-18,s
	leau	,s
	stx	9,u
	stb	8,u
	sts	6,u
	jsr	___Clear_Sound
	ldx	_Vec_Text_HW
	stx	13,u
	ldy	#-1968
	sty	_Vec_Text_HW
	ldd	26,u
	ldx	28,u
	leay	d,x
	ldb	,-y
	cmpb	#92	;cmpqi:
	lbeq	L2
	cmpy	26,u	;cmphi:
	lbeq	L2
	ldx	#0
	bra	L26
L28:
	cmpy	26,u	;cmphi:
	beq	L3
L26:
	stx	16,u
	leax	1,x
	stx	4,u
	ldb	,-y
	cmpb	#92	;cmpqi:
	bne	L28
L3:
	tfr	s,d
	subd	4,u	;subhi: R:d -= 4,u
	tfr	d,s
	sts	11,u
	ldx	16,u
	beq	L7
L6:
	ldd	#0
	std	2,u
L9:
	leay	1,y
	ldb	,y
	stb	15,u
	addb	#-97
	cmpb	#25	;cmpqi:
	bhi	L8
	ldb	15,u
	addb	#-32
	stb	15,u
L8:
	ldx	11,u
	exg	d,x
	addd	2,u; addhi3,3
	exg	d,x
	ldb	15,u
	stb	,x
	ldd	2,u
	addd	#1; addhi3,3
	std	2,u
	cmpd	16,u	;cmphi:
	blo	L9
L7:
	ldx	11,u
	exg	d,x
	addd	16,u; addhi3,3
	exg	d,x
	ldb	#-128
	stb	,x
	ldx	11,u
	stx	2,u
L22:
	jsr	___DP_to_C8
	jsr	___Wait_Recal
	jsr	___Intensity_5F
	ldb	#-120
	stb	,-s
	ldx	9,u
	ldb	#90
	jsr	_print_string
	ldb	#-120
	stb	,-s
	ldx	#LC0
	ldb	#50
	jsr	_print_string
	ldb	#-120
	stb	,-s
	ldx	2,u
	ldb	#30
	jsr	_print_string
	ldb	#-120
	stb	,-s
	ldx	#LC1
	clrb
	jsr	_print_string
	ldb	#-120
	stb	,-s
	ldx	30,u
	ldb	#-20
	jsr	_print_long_unsigned_int
	ldb	#-120
	stb	,-s
	ldx	#LC2
	ldb	#-50
	jsr	_print_string
	leas	6,s
	ldb	8,u
	cmpb	#9	;cmpqi:
	bhi	L10
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	aslb
	rola
	tfr	d,x
	jmp	[L21,x]
L21:
	.word	L11
	.word	L12
	.word	L13
	.word	L14
	.word	L15
	.word	L18
	.word	L17
	.word	L18
	.word	L19
	.word	L20
L18:
	ldb	#-120
	stb	,-s
	ldy	24,u
	ldx	,y
	addb	#50
	jsr	_print_long_hex
	leas	1,s
L10:
	jsr	___Read_Btns
	ldb	_Vec_Buttons
	bitb	#1
	lbeq	L22
	ldx	13,u
	stx	_Vec_Text_HW
	lds	6,u
	leas	18,s
	puls	y,u,pc
L17:
	ldx	24,u
	ldb	,x
	stb	,-s
	ldb	#-120
	stb	,-s
	addb	#50
	jsr	_print_hex
	leas	2,s
	bra	L10
L20:
	ldb	#-120
	stb	,-s
	ldy	24,u
	ldx	,y
	addb	#50
	jsr	_print_long_binary
	leas	1,s
	bra	L10
L15:
	ldx	24,u
	ldb	,x
	stb	,-s
	ldb	#-120
	stb	,-s
	addb	#50
	jsr	_print_char
	leas	2,s
	bra	L10
L14:
	ldb	#-120
	stb	,-s
	ldy	24,u
	ldx	,y
	addb	#50
	jsr	_print_long_signed_int
	leas	1,s
	lbra	L10
L13:
	ldb	#-120
	stb	,-s
	ldy	24,u
	ldx	,y
	addb	#50
	jsr	_print_long_unsigned_int
	leas	1,s
	lbra	L10
L12:
	ldx	24,u
	ldb	,x
	stb	,-s
	ldb	#-120
	stb	,-s
	addb	#50
	jsr	_print_signed_int
	leas	2,s
	lbra	L10
L19:
	ldx	24,u
	ldb	,x
	stb	,-s
	ldb	#-120
	stb	,-s
	addb	#50
	jsr	_print_binary
	leas	2,s
	lbra	L10
L11:
	ldx	24,u
	ldb	,x
	stb	,-s
	ldb	#-120
	stb	,-s
	addb	#50
	jsr	_print_unsigned_int
	leas	2,s
	lbra	L10
L2:
	sts	11,u
	ldx	#-1
	stx	16,u
	lbra	L6
