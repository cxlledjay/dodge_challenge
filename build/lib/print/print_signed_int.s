;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	print_signed_int.c
	.area	.text
	.globl	_print_signed_int
_print_signed_int:
	leas	-8,s
	stb	,s
	ldb	#-128
	stb	5,s
	ldb	#48
	stb	3,s
	tst	11,s
	blt	L2
	ldb	#43
	stb	1,s
	bra	L3
L2:
	ldb	#45
	stb	1,s
	neg	11,s
L3:
	ldb	11,s
	cmpb	#99	;cmpqi:
	bhi	L4
	ldb	#48
	stb	2,s
	bra	L6
L4:
	ldb	#49
	stb	2,s
	ldb	11,s
	addb	#-100
	stb	11,s
	bra	L6
L7:
	ldb	3,s
	incb
	stb	3,s
	ldb	11,s
	addb	#-10
	stb	11,s
L6:
	ldb	11,s
	cmpb	#9	;cmpqi:
	bgt	L7
	ldb	11,s
	addb	#48
	stb	4,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	,s
	stb	7,s
	ldb	10,s
	stb	6,s
	leax	1,s
	ldb	7,s
	stb	,-s
	ldb	7,s
	jsr	__Print_Str_d
	leas	1,s
	leas	8,s
	rts
