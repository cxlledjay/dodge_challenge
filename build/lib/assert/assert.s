;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
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
	leas	-36,s
	leau	,s
	stx	2,u
	stb	9,u
	sts	5,u
	ldx	_Vec_Text_HW
	stx	16,u
	ldy	#-1968
	sty	_Vec_Text_HW
	jsr	___Clear_Sound
	ldb	9,u
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldd	2,u
	leay	d,x
	ldb	,-y
	cmpb	#92	;cmpqi:
	lbeq	L2
	cmpb	#47	;cmpqi:
	lbeq	L2
	cmpy	2,u	;cmphi:
	lbeq	L2
	leax	,y
	bra	L4
L31:
	cmpb	#47	;cmpqi:
	beq	L3
	cmpx	2,u	;cmphi:
	beq	L3
L4:
	tfr	y,d	;movlsbqihi: R:y -> R:b
	stb	4,u
	tfr	x,d	;movlsbqihi: R:x -> R:b
	stb	23,u
	ldb	4,u
	subb	23,u
	stb	24,u
	inc	4,u
	ldb	4,u
	subb	23,u
	stb	25,u
	ldb	,-x
	cmpb	#92	;cmpqi:
	bne	L31
L3:
	ldb	25,u
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,y
	tfr	s,d
	pshs	y	;subhi: R:d -= R:y
	subd	,s++
	tfr	d,s
	sts	10,u
	tst	24,u
	beq	L5
	leay	,x
L6:
	sty	2,u
L8:
	tfr	y,d	;movlsbqihi: R:y -> R:b
	stb	22,u
	ldb	3,u	;movlsbqihi: msb:2,u -> R:b
	subb	22,u
	stb	28,u
	ldx	2,u
	leax	1,x
	stx	2,u
	ldb	,x
	stb	19,u
	addb	#-97
	cmpb	#25	;cmpqi:
	bhi	L7
	ldb	19,u
	addb	#-32
	stb	19,u
L7:
	ldb	28,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	tfr	d,x
	exg	d,x
	addd	10,u; addhi3,3
	exg	d,x
	ldb	19,u
	stb	,x
	ldb	3,u	;movlsbqihi: msb:2,u -> R:b
	subb	22,u
	stb	22,u
	ldb	24,u
	cmpb	22,u	;cmpqi:
	bhi	L8
L5:
	ldb	24,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	tfr	d,x
	exg	d,x
	addd	10,u; addhi3,3
	exg	d,x
	ldb	#-128
	stb	,x
	leax	29,u
	jsr	___Clear_Score
	ldx	42,u
	cmpx	#255	;cmphi:
	bls	L9
L23:
	leax	29,u
	ldb	#-1
	jsr	__Add_Score_a
	ldd	42,u
	addd	#-255; addhi3,3
	std	42,u
	cmpd	#255	;cmphi:
	bhi	L23
L9:
	leax	29,u
	ldb	43,u	;movlsbqihi: msb:42,u -> R:b
	jsr	__Add_Score_a
	clr	18,u
	bra	L12
L32:
	ldb	4,u
	stb	18,u
L12:
	ldb	18,u
	incb
	stb	4,u
	ldb	18,u
	clra		;zero_extendqihi: R:b -> R:d
	std	7,u
	ldx	44,u
	leax	d,x
	tst	,x
	bne	L32
	ldb	4,u
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	tfr	s,d
	pshs	x	;subhi: R:d -= R:x
	subd	,s++
	tfr	d,s
	sts	12,u
	ldd	7,u
	leax	d,s
	ldb	#-128
	stb	,x
	ldb	18,u
	decb
	stb	26,u
	cmpb	#-1	;cmpqi:
	beq	L13
L22:
	ldb	26,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	ldx	44,u
	leax	d,x
	ldb	,x
	stb	20,u
	addb	#-97
	cmpb	#25	;cmpqi:
	bhi	L14
	ldb	20,u
	addb	#-32
	stb	20,u
L14:
	ldb	26,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	tfr	d,x
	exg	d,x
	addd	12,u; addhi3,3
	exg	d,x
	ldb	20,u
	stb	,x
	dec	26,u
	ldb	26,u
	cmpb	#-1	;cmpqi:
	bne	L22
L13:
	ldb	48,u
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	tfr	s,d
	pshs	x	;subhi: R:d -= R:x
	subd	,s++
	tfr	d,s
	leay	,s
	tst	48,u
	beq	L16
	ldx	#0
	stx	2,u
L19:
	ldd	2,u
	stb	27,u	;movlsbqihi: R:d -> 27,u
	ldx	46,u
	leax	d,x
	ldb	,x
	stb	21,u
	addb	#-97
	cmpb	#25	;cmpqi:
	bhi	L17
	ldb	21,u
	addb	#-32
	stb	21,u
L17:
	ldb	21,u
	addb	#-32
	cmpb	#63	;cmpqi:
	bls	L18
	ldb	#102
	stb	21,u
L18:
	ldb	27,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	leax	d,y
	ldb	21,u
	stb	,x
	ldd	2,u
	addd	#1; addhi3,3
	std	2,u
		;movlsbqihi: D->B
	cmpb	48,u	;cmpqi:(R)
	blo	L19
L16:
	dec	48,u
	ldb	48,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	leax	d,y
	ldb	#-128
	stb	,x
	sty	14,u
	ldy	10,u
	ldx	12,u
	stx	2,u
L20:
	jsr	___Wait_Recal
	jsr	___Intensity_5F
	ldx	#_yy0
	jsr	__Print_List
	ldb	#70
	stb	,-s
	ldx	14,u
	ldb	#-120
	jsr	__Print_Str_d
	ldb	#20
	stb	,-s
	leax	,y
	ldb	#-120
	jsr	__Print_Str_d
	ldb	#-30
	stb	,-s
	ldx	2,u
	ldb	#-120
	jsr	__Print_Str_d
	ldb	#-80
	stb	,-s
	leax	29,u
	ldb	#-120
	jsr	__Print_Str_d
	jsr	___Read_Btns
	leas	4,s
	ldb	_Vec_Buttons
	bitb	#1
	beq	L20
	ldx	16,u
	stx	_Vec_Text_HW
	lds	5,u
	leas	36,s
	puls	y,u,pc
L2:
	sts	10,u
	ldb	#-1
	stb	24,u
	lbra	L6
