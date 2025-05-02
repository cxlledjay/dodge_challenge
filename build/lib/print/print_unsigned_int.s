;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	print_unsigned_int.c
	.area	.text
	.globl	_print_unsigned_int
_print_unsigned_int:
	leas	-5,s
	stb	,s
	ldb	#-128
	stb	4,s
	ldb	#48
	stb	2,s
	stb	1,s
	ldb	8,s
	cmpb	#99	;cmpqi:
	bls	L2
L8:
	inc	1,s
	ldb	1,s
	ldb	8,s
	addb	#-100
	stb	8,s
	cmpb	#99	;cmpqi:
	bhi	L8
L2:
	ldb	8,s
	cmpb	#9	;cmpqi:
	bls	L4
L7:
	inc	2,s
	ldb	2,s
	ldb	8,s
	addb	#-10
	stb	8,s
	cmpb	#9	;cmpqi:
	bhi	L7
L4:
	ldb	8,s
	addb	#48
	stb	3,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	,s
	pshs	b
	leax	2,s
	ldb	8,s
	jsr	__Print_Str_d
	leas	6,s
	rts
