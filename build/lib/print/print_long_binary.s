;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	print_long_binary.c
	.area	.text
	.globl	_print_long_binary
_print_long_binary:
	pshs	u
	leas	-24,s
	stb	5,s
	stx	3,s
	ldb	#-128
	stb	23,s
	ldb	#15
	stb	6,s
L2:
	ldd	3,s
	stb	,s	;movlsbqihi: R:d -> ,s
	ldb	#1
	andb	,s
	addb	#48
	stb	,s
	ldb	6,s
	clra		;zero_extendqihi: R:b -> R:d
	std	1,s
	leau	7,s
	leax	d,u
	ldb	,s
	stb	,x
	dec	6,s
	lsr	3,s
	ror	4,s
	ldb	6,s
	cmpb	#-1	;cmpqi:
	bne	L2
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	5,s
	pshs	b
	leax	,u
	ldb	29,s
	jsr	__Print_Str_d
	leas	25,s
	puls	u,pc
