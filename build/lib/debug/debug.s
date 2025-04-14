;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
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
	leas	-20,s
	leau	,s
	stx	9,u
	stb	8,u
	sts	2,u
	leax	,s
	stx	6,u
	jsr	___Clear_Sound
	ldx	_Vec_Text_HW
	stx	13,u
	ldx	#-1968
	stx	_Vec_Text_HW
	ldd	28,u
	addd	30,u; addhi3,3
	std	15,u
	ldx	#0
	stx	30,u
	bra	L2
L4:
	ldd	30,u
	addd	#1; addhi3,3
	std	30,u
L2:
	ldd	15,u
	addd	#-1; addhi3,3
	std	15,u
	ldb	[15,u]
	cmpb	#92	;cmpqi:
	beq	L3
	ldx	15,u
	cmpx	28,u	;cmphi:
	bne	L4
L3:
	ldx	30,u
	ldd	30,u
	addd	#-1; addhi3,3
	std	30,u
	tfr	s,d
	pshs	x	;subhi: R:d -= R:x
	subd	,s++
	tfr	d,s
	sts	4,u
	ldx	#0
	exg	d,x
	addd	4,u; addhi3,3
	exg	d,x
	stx	4,u
	ldx	4,u
	stx	11,u
	ldx	#0
	stx	17,u
	bra	L5
L7:
	ldd	15,u
	addd	#1; addhi3,3
	std	15,u
	ldb	[15,u]
	stb	19,u
	ldb	19,u
	cmpb	#96	;cmpqi:
	bls	L6
	ldb	19,u
	cmpb	#122	;cmpqi:
	bhi	L6
	ldb	19,u
	addb	#-32
	stb	19,u
L6:
	ldx	17,u
	exg	d,x
	addd	11,u; addhi3,3
	exg	d,x
	ldb	19,u
	stb	,x
	ldd	17,u
	addd	#1; addhi3,3
	std	17,u
L5:
	ldx	17,u
	cmpx	30,u	;cmphi:
	blo	L7
	ldx	30,u
	exg	d,x
	addd	11,u; addhi3,3
	exg	d,x
	ldb	#-128
	stb	,x
L20:
	jsr	___DP_to_C8
	jsr	___Wait_Recal
	jsr	___Intensity_5F
	ldb	#-120
	stb	,-s
	ldx	9,u
	ldb	#90
	jsr	_print_string
	leas	1,s
	ldb	#-120
	stb	,-s
	ldx	#LC0
	ldb	#50
	jsr	_print_string
	leas	1,s
	ldx	11,u
	ldb	#-120
	stb	,-s
	ldb	#30
	jsr	_print_string
	leas	1,s
	ldb	#-120
	stb	,-s
	ldx	#LC1
	clrb
	jsr	_print_string
	leas	1,s
	ldb	#-120
	stb	,-s
	ldx	32,u
	ldb	#-20
	jsr	_print_long_unsigned_int
	leas	1,s
	ldb	#-120
	stb	,-s
	ldx	#LC2
	ldb	#-50
	jsr	_print_string
	leas	1,s
	ldb	8,u
	cmpb	#9	;cmpqi:
	lbhi	L8
	ldb	8,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	ldd	,u
	aslb
	rola
	ldy	#L19
	leax	d,y
	ldx	,x
	jmp	,x
L19:
	.word	L9
	.word	L10
	.word	L11
	.word	L12
	.word	L13
	.word	L14
	.word	L15
	.word	L16
	.word	L17
	.word	L18
L9:
	ldx	26,u
	ldb	,x
	pshs	b
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	_print_unsigned_int
	leas	2,s
	lbra	L8
L10:
	ldx	26,u
	ldb	,x
	pshs	b
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	_print_signed_int
	leas	2,s
	lbra	L8
L11:
	ldx	26,u
	ldx	,x
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	_print_long_unsigned_int
	leas	1,s
	lbra	L8
L12:
	ldx	26,u
	ldx	,x
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	_print_long_signed_int
	leas	1,s
	lbra	L8
L13:
	ldx	26,u
	ldb	,x
	pshs	b
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	_print_char
	leas	2,s
	lbra	L8
L14:
	ldx	26,u
	ldx	,x
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	_print_long_hex
	leas	1,s
	bra	L8
L15:
	ldx	26,u
	ldb	,x
	pshs	b
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	_print_hex
	leas	2,s
	bra	L8
L16:
	ldx	26,u
	ldx	,x
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	_print_long_hex
	leas	1,s
	bra	L8
L17:
	ldx	26,u
	ldb	,x
	pshs	b
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	_print_binary
	leas	2,s
	bra	L8
L18:
	ldx	26,u
	ldx	,x
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	_print_long_binary
	leas	1,s
L8:
	jsr	___Read_Btns
	ldb	_Vec_Buttons
	andb	#1
	tstb
	lbeq	L20
	ldx	13,u
	stx	_Vec_Text_HW
	lds	6,u
	lds	2,u
	leas	20,s
	puls	y,u,pc
