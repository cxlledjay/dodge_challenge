;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	print_unsigned_int.c
	.area	.text
	.globl	_print_unsigned_int
_print_unsigned_int:
	leas	-7,s
	stb	,s
	ldb	#-128
	stb	4,s
	ldb	#48
	stb	2,s
	ldb	#48
	stb	1,s
	bra	L2
L3:
	ldb	1,s
	incb
	stb	1,s
	ldb	10,s
	addb	#-100
	stb	10,s
L2:
	ldb	10,s
	cmpb	#99	;cmpqi:
	bhi	L3
	bra	L4
L5:
	ldb	2,s
	incb
	stb	2,s
	ldb	10,s
	addb	#-10
	stb	10,s
L4:
	ldb	10,s
	cmpb	#9	;cmpqi:
	bhi	L5
	ldb	10,s
	addb	#48
	stb	3,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	,s
	stb	6,s
	ldb	9,s
	stb	5,s
	leax	1,s
	ldb	6,s
	stb	,-s
	ldb	6,s
	jsr	__Print_Str_d
	leas	1,s
	leas	7,s
	rts
