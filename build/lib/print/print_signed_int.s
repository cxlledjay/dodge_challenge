;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	print_signed_int.c
	.area	.text
	.globl	_print_signed_int
_print_signed_int:
	leas	-6,s
	stb	,s
	ldb	#-128
	stb	5,s
	ldb	#48
	stb	3,s
	tst	9,s
	blt	L2
	ldb	#43
	stb	1,s
L3:
	ldb	9,s
	cmpb	#99	;cmpqi:
	bhi	L4
	ldb	#48
	stb	2,s
L5:
	ldb	9,s
	cmpb	#9	;cmpqi:
	ble	L6
L9:
	inc	3,s
	ldb	3,s
	ldb	9,s
	addb	#-10
	stb	9,s
	cmpb	#9	;cmpqi:
	bgt	L9
L6:
	ldb	9,s
	addb	#48
	stb	4,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	,s
	pshs	b
	leax	2,s
	ldb	9,s
	jsr	__Print_Str_d
	leas	7,s
	rts
L4:
	ldb	#49
	stb	2,s
	ldb	9,s
	addb	#-100
	stb	9,s
	bra	L5
L2:
	ldb	#45
	stb	1,s
	neg	9,s
	bra	L3
