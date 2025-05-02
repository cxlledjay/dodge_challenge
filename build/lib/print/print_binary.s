;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	print_binary.c
	.area	.text
	.globl	_print_binary
_print_binary:
	pshs	u
	leas	-14,s
	stb	3,s
	ldb	#-128
	stb	13,s
	ldb	#7
	stb	4,s
L2:
	ldb	#1
	andb	19,s
	addb	#48
	stb	,s
	ldb	4,s
	clra		;zero_extendqihi: R:b -> R:d
	std	1,s
	leau	5,s
	leax	d,u
	ldb	,s
	stb	,x
	dec	4,s
	lsr	19,s
	ldb	4,s
	cmpb	#-1	;cmpqi:
	bne	L2
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	3,s
	pshs	b
	leax	,u
	ldb	19,s
	jsr	__Print_Str_d
	leas	15,s
	puls	u,pc
