;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	assert.c
	.globl	_yy0
	.area	.text
_yy0:
	.byte	90
	.globl	_xx0
_xx0:
	.byte	-120
	.globl	_mm0
_mm0:
	.byte	65,83,83,69,82,84,32,70
	.byte	65,73,76,69,68,58,-128,0
;----- asm -----
	. = . - 1
	
;--- end asm ---
	.globl	_yy1
_yy1:
	.byte	40
	.globl	_xx1
_xx1:
	.byte	-120
	.globl	_mm1
_mm1:
	.byte	70,73,76,69,58,-128,0
;----- asm -----
	. = . - 1
	
;--- end asm ---
	.globl	_yy2
_yy2:
	.byte	-10
	.globl	_xx2
_xx2:
	.byte	-120
	.globl	_mm2
_mm2:
	.byte	70,85,78,67,84,73,79,78
	.byte	58,-128,0
;----- asm -----
	. = . - 1
	
;--- end asm ---
	.globl	_yy3
_yy3:
	.byte	-60
	.globl	_xx3
_xx3:
	.byte	-120
	.globl	_mm3
_mm3:
	.byte	76,73,78,69,58,-128,0
	.globl	__f_assert_failed
__f_assert_failed:
	pshs	y,u
	leas	-44,s
	leau	,s
	stx	14,u
	stb	13,u
	sts	2,u
	leax	,s
	stx	11,u
	ldx	_Vec_Text_HW
	stx	29,u
	ldx	#-1968
	stx	_Vec_Text_HW
	jsr	___Clear_Sound
	ldb	13,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	ldd	,u
	addd	14,u; addhi3,3
	std	31,u
	clr	13,u
	bra	L2
L4:
	inc	13,u
L2:
	ldd	31,u
	addd	#-1; addhi3,3
	std	31,u
	ldb	[31,u]
	cmpb	#92	;cmpqi:
	beq	L3
	ldb	[31,u]
	cmpb	#47	;cmpqi:
	beq	L3
	ldx	31,u
	cmpx	14,u	;cmphi:
	bne	L4
L3:
	ldb	13,u
	dec	13,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	tfr	s,d
	subd	,u	;subhi: R:d -= ,u
	tfr	d,s
	sts	5,u
	ldx	#0
	exg	d,x
	addd	5,u; addhi3,3
	exg	d,x
	stx	5,u
	ldx	5,u
	stx	23,u
	clr	33,u
	bra	L5
L7:
	ldd	31,u
	addd	#1; addhi3,3
	std	31,u
	ldb	[31,u]
	stb	34,u
	ldb	34,u
	cmpb	#96	;cmpqi:
	bls	L6
	ldb	34,u
	cmpb	#122	;cmpqi:
	bhi	L6
	ldb	34,u
	addb	#-32
	stb	34,u
L6:
	ldb	33,u
	clra		;zero_extendqihi: R:b -> R:d
	ldy	23,u
	leax	d,y
	ldb	34,u
	stb	,x
	inc	33,u
L5:
	ldb	33,u
	cmpb	13,u	;cmpqi:
	blo	L7
	ldb	13,u
	clra		;zero_extendqihi: R:b -> R:d
	ldy	23,u
	leax	d,y
	ldb	#-128
	stb	,x
	leax	16,u
	jsr	___Clear_Score
	bra	L8
L9:
	leax	16,u
	ldb	#-1
	jsr	__Add_Score_a
	ldd	50,u
	addd	#-255; addhi3,3
	std	50,u
L8:
	ldx	50,u
	cmpx	#255	;cmphi:
	bhi	L9
	ldx	50,u
	tfr	x,d	;movlsbqihi: R:x -> R:b
	stb	37,u
	leax	16,u
	ldb	37,u
	jsr	__Add_Score_a
	clr	33,u
L11:
	ldb	33,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	ldx	,u
	exg	d,x
	addd	52,u; addhi3,3
	exg	d,x
	ldb	,x
	stb	4,u
	tst	4,u
	beq	L10
	ldb	#1
	stb	4,u
L10:
	ldb	4,u
	inc	33,u
	tstb
	bne	L11
	ldb	33,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	tfr	s,d
	subd	,u	;subhi: R:d -= ,u
	tfr	d,s
	sts	7,u
	ldx	#0
	exg	d,x
	addd	7,u; addhi3,3
	exg	d,x
	stx	7,u
	ldx	7,u
	stx	25,u
	dec	33,u
	ldb	33,u
	clra		;zero_extendqihi: R:b -> R:d
	ldy	25,u
	leax	d,y
	ldb	#-128
	stb	,x
	bra	L12
L14:
	ldb	33,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	ldx	,u
	exg	d,x
	addd	52,u; addhi3,3
	exg	d,x
	ldb	,x
	stb	35,u
	ldb	35,u
	cmpb	#96	;cmpqi:
	bls	L13
	ldb	35,u
	cmpb	#122	;cmpqi:
	bhi	L13
	ldb	35,u
	addb	#-32
	stb	35,u
L13:
	ldb	33,u
	clra		;zero_extendqihi: R:b -> R:d
	ldy	25,u
	leax	d,y
	ldb	35,u
	stb	,x
L12:
	dec	33,u
	ldb	33,u
	cmpb	#-1	;cmpqi:
	bne	L14
	ldb	56,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	tfr	s,d
	subd	,u	;subhi: R:d -= ,u
	tfr	d,s
	sts	9,u
	ldx	#0
	exg	d,x
	addd	9,u; addhi3,3
	exg	d,x
	stx	9,u
	ldx	9,u
	stx	27,u
	clr	33,u
	bra	L15
L19:
	ldb	33,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	ldx	,u
	exg	d,x
	addd	54,u; addhi3,3
	exg	d,x
	ldb	,x
	stb	36,u
	ldb	36,u
	cmpb	#96	;cmpqi:
	bls	L16
	ldb	36,u
	cmpb	#122	;cmpqi:
	bhi	L16
	ldb	36,u
	addb	#-32
	stb	36,u
L16:
	ldb	36,u
	cmpb	#31	;cmpqi:
	bls	L17
	ldb	36,u
	cmpb	#95	;cmpqi:
	bls	L18
L17:
	ldb	#102
	stb	36,u
L18:
	ldb	33,u
	clra		;zero_extendqihi: R:b -> R:d
	ldy	27,u
	leax	d,y
	ldb	36,u
	stb	,x
	inc	33,u
L15:
	ldb	33,u
	cmpb	56,u	;cmpqi:
	blo	L19
	ldb	56,u
	decb
	clra		;zero_extendqihi: R:b -> R:d
	ldy	27,u
	leax	d,y
	ldb	#-128
	stb	,x
L20:
	jsr	___Wait_Recal
	jsr	___Intensity_5F
	ldx	#_yy0
	jsr	__Print_List
	ldx	27,u
	stx	38,u
	ldb	#70
	stb	,-s
	ldx	38,u
	ldb	#-120
	jsr	__Print_Str_d
	leas	1,s
	ldx	23,u
	stx	40,u
	ldb	#20
	stb	,-s
	ldx	40,u
	ldb	#-120
	jsr	__Print_Str_d
	leas	1,s
	ldx	25,u
	stx	42,u
	ldb	#-30
	stb	,-s
	ldx	42,u
	ldb	#-120
	jsr	__Print_Str_d
	leas	1,s
	leax	16,u
	ldb	#-80
	stb	,-s
	ldb	#-120
	jsr	__Print_Str_d
	leas	1,s
	jsr	___Read_Btns
	ldb	_Vec_Buttons
	andb	#1
	tstb
	lbeq	L20
	ldx	29,u
	stx	_Vec_Text_HW
	lds	11,u
	lds	2,u
	leas	44,s
	puls	y,u,pc
