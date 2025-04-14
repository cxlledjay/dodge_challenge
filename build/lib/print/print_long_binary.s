;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	print_long_binary.c
	.area	.text
	.globl	_print_long_binary
_print_long_binary:
	leas	-28,s
	stb	7,s
	stx	5,s
	ldb	#-128
	stb	24,s
	ldb	#15
	stb	25,s
L2:
	ldb	25,s
	stb	3,s
	ldx	5,s
	tfr	x,d	;movlsbqihi: R:x -> R:b
	stb	,s
	ldb	#1
	andb	,s
	stb	2,s
	ldb	2,s
	addb	#48
	stb	4,s
	ldb	3,s
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	leax	8,s
	exg	d,x
	addd	,s; addhi3,3
	exg	d,x
	ldb	4,s
	stb	,x
	dec	25,s
	lsr	5,s
	ror	6,s
	ldb	25,s
	cmpb	#-1	;cmpqi:
	bne	L2
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	7,s
	stb	27,s
	ldb	30,s
	stb	26,s
	leax	8,s
	ldb	27,s
	stb	,-s
	ldb	27,s
	jsr	__Print_Str_d
	leas	1,s
	leas	28,s
	rts
