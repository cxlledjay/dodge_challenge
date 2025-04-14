;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	print_binary.c
	.area	.text
	.globl	_print_binary
_print_binary:
	leas	-18,s
	stb	5,s
	ldb	#-128
	stb	14,s
	ldb	#7
	stb	15,s
L2:
	ldb	15,s
	stb	3,s
	ldb	21,s
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
	leax	6,s
	exg	d,x
	addd	,s; addhi3,3
	exg	d,x
	ldb	4,s
	stb	,x
	dec	15,s
	lsr	21,s
	ldb	15,s
	cmpb	#-1	;cmpqi:
	bne	L2
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	5,s
	stb	17,s
	ldb	20,s
	stb	16,s
	leax	6,s
	ldb	17,s
	stb	,-s
	ldb	17,s
	jsr	__Print_Str_d
	leas	1,s
	leas	18,s
	rts
