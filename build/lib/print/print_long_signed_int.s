;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	print_long_signed_int.c
	.area	.text
	.globl	_print_long_signed_int
_print_long_signed_int:
	leas	-12,s
	stb	2,s
	stx	,s
	ldb	#-128
	stb	9,s
	ldb	#48
	stb	7,s
	ldb	#48
	stb	6,s
	ldb	#48
	stb	5,s
	ldb	#48
	stb	4,s
	ldx	,s
	cmpx	#0
	blt	L2
	ldb	#43
	stb	3,s
	bra	L4
L2:
	ldb	#45
	stb	3,s
	ldd	,s
	nega
	negb
	sbca	#0
	std	,s
	bra	L4
L5:
	ldb	4,s
	incb
	stb	4,s
	ldd	,s
	addd	#-10000; addhi3,3
	std	,s
L4:
	ldx	,s
	cmpx	#9999	;cmphi:
	bhi	L5
	bra	L6
L7:
	ldb	5,s
	incb
	stb	5,s
	ldd	,s
	addd	#-1000; addhi3,3
	std	,s
L6:
	ldx	,s
	cmpx	#999	;cmphi:
	bgt	L7
	bra	L8
L9:
	ldb	6,s
	incb
	stb	6,s
	ldd	,s
	addd	#-100; addhi3,3
	std	,s
L8:
	ldx	,s
	cmpx	#99	;cmphi:
	bgt	L9
	bra	L10
L11:
	ldb	7,s
	incb
	stb	7,s
	ldd	,s
	addd	#-10; addhi3,3
	std	,s
L10:
	ldx	,s
	cmpx	#9	;cmphi:
	bgt	L11
	ldx	,s
	tfr	x,d	;movlsbqihi: R:x -> R:b
	addb	#48
	stb	8,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	2,s
	stb	11,s
	ldb	14,s
	stb	10,s
	leax	3,s
	ldb	11,s
	stb	,-s
	ldb	11,s
	jsr	__Print_Str_d
	leas	1,s
	leas	12,s
	rts
