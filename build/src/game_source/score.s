;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	score.c
	.area	.bss
	.globl	_score
_score:	.blkb	5
	.area	.text
	.globl	_score_init
_score_init:
	clr	_score
	clr	_score+1
	clr	_score+2
	clr	_score+3
	clr	_score+4
	rts
	.globl	_local_lu_score_addition
_local_lu_score_addition:
	.byte	1
	.byte	2
	.byte	3
	.byte	4
	.byte	5
	.byte	6
	.byte	7
	.globl	_score_update
_score_update:
	leas	-10,s
	ldb	_lvl_speed
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_local_lu_score_addition,x
	addb	_score
	stb	6,s
	cmpb	#9	;cmpqi:
	lble	L10
	ldb	6,s
	lda	#103	;mulqihi3
	mul
	std	,s
	tfr	a,b
	clra		;zero_extendqihi: R:b -> R:d
	asrb
	asrb
	stb	5,s
	ldb	6,s
	rolb
	rolb
	andb	#1
	negb
	stb	2,s
	ldb	5,s
	subb	2,s
	stb	2,s
	addb	_score+1
	stb	7,s
	ldb	2,s
	lda	#10	;mulqihi3
	mul
	tfr	d,x
	tfr	x,d	;movlsbqihi: R:x -> R:b
	subb	6,s
	negb
	stb	_score
	ldb	7,s
	cmpb	#9	;cmpqi:
	lble	L11
	ldb	7,s
	lda	#103	;mulqihi3
	mul
	std	,s
	tfr	a,b
	clra		;zero_extendqihi: R:b -> R:d
	asrb
	asrb
	stb	4,s
	ldb	7,s
	rolb
	rolb
	andb	#1
	negb
	stb	,s
	ldb	4,s
	subb	,s
	stb	,s
	addb	_score+2
	stb	8,s
	ldb	,s
	lda	#10	;mulqihi3
	mul
	tfr	d,x
	tfr	x,d	;movlsbqihi: R:x -> R:b
	subb	7,s
	negb
	stb	_score+1
	ldb	8,s
	cmpb	#9	;cmpqi:
	ble	L12
	ldb	8,s
	lda	#103	;mulqihi3
	mul
	std	,s
	tfr	a,b
	clra		;zero_extendqihi: R:b -> R:d
	asrb
	asrb
	stb	,s
	ldb	8,s
	rolb
	rolb
	andb	#1
	negb
	stb	9,s
	ldb	,s
	subb	9,s
	addb	_score+3
	stb	9,s
	lda	#103	;mulqihi3
	mul
	std	,s
	tfr	a,b
	clra		;zero_extendqihi: R:b -> R:d
	asrb
	asrb
	stb	3,s
	ldb	9,s
	rolb
	rolb
	andb	#1
	negb
	subb	3,s
	negb
	lda	#10	;mulqihi3
	mul
		;movlsbqihi: D->B
	subb	9,s
	negb
	stb	_score+2
	ldb	9,s
	cmpb	#9	;cmpqi:
	bgt	L8
	stb	_score+3
	bra	L8
L11:
	stb	_score+1
L8:
	leas	10,s
	rts
L10:
	stb	_score
	leas	10,s
	rts
L12:
	stb	_score+2
	leas	10,s
	rts
	.globl	_local_lu_speed_digit_1
_local_lu_speed_digit_1:
	.byte	1
	.byte	1
	.byte	2
	.byte	2
	.byte	3
	.byte	3
	.byte	4
	.globl	_local_lu_speed_digit_2
_local_lu_speed_digit_2:
	.byte	0
	.byte	5
	.byte	0
	.byte	5
	.byte	0
	.byte	5
	.byte	0
	.globl	_score_draw
_score_draw:
	leas	-2,s
	jsr	___Intensity_5F
	jsr	___Reset0Ref
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#110
	stb	,-s
	addb	#46
	jsr	__Moveto_d
	ldb	#9
	stb	*_dp_VIA_t1_cnt_lo
	ldb	_score+3
	sex		;extendqihi2: R:b -> R:d
	aslb
	rola
	tfr	d,x
	ldx	_vl_digits,x
	jsr	___Draw_VLp
	clr	,-s
	ldb	#127
	jsr	__Moveto_d
	ldb	_score+2
	sex		;extendqihi2: R:b -> R:d
	aslb
	rola
	tfr	d,x
	ldx	_vl_digits,x
	jsr	___Draw_VLp
	clr	,-s
	ldb	#127
	jsr	__Moveto_d
	ldb	_score+1
	sex		;extendqihi2: R:b -> R:d
	aslb
	rola
	tfr	d,x
	ldx	_vl_digits,x
	jsr	___Draw_VLp
	clr	,-s
	ldb	#127
	jsr	__Moveto_d
	ldb	_score
	sex		;extendqihi2: R:b -> R:d
	std	4,s
	aslb
	rola
	tfr	d,x
	ldx	_vl_digits,x
	jsr	___Draw_VLp
	clr	,-s
	ldb	#127
	jsr	__Moveto_d
	ldx	_vl_digits
	jsr	___Draw_VLp
	ldb	#66
	stb	*_dp_VIA_t1_cnt_lo
	ldb	#-44
	stb	,-s
	ldb	#-127
	jsr	__Moveto_d
	ldb	#6
	stb	*_dp_VIA_t1_cnt_lo
	ldx	#_vl_speed_display
	jsr	___Draw_VLp
	ldb	#6
	stb	*_dp_VIA_t1_cnt_lo
	leas	8,s
	rts
