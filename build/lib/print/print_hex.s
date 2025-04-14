;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	print_hex.c
	.area	.text
	.globl	_print_hex
_print_hex:
	leas	-6,s
	stb	,s
	ldb	#-128
	stb	3,s
	ldb	9,s
	andb	#15
	addb	#48
	stb	2,s
	ldb	2,s
	cmpb	#57	;cmpqi:
	bls	L2
	ldb	2,s
	addb	#7
	stb	2,s
L2:
	lsr	9,s
	lsr	9,s
	lsr	9,s
	lsr	9,s
	ldb	9,s
	addb	#48
	stb	1,s
	ldb	1,s
	cmpb	#57	;cmpqi:
	bls	L3
	ldb	1,s
	addb	#7
	stb	1,s
L3:
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	,s
	stb	5,s
	ldb	8,s
	stb	4,s
	leax	1,s
	ldb	5,s
	stb	,-s
	ldb	5,s
	jsr	__Print_Str_d
	leas	1,s
	leas	6,s
	rts
