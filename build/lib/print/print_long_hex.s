;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	print_long_hex.c
	.area	.text
	.globl	_print_long_hex
_print_long_hex:
	leas	-12,s
	stb	2,s
	stx	,s
	ldb	#-128
	stb	7,s
	ldd	,s
	stb	8,s	;movlsbqihi: R:d -> 8,s
	ldd	,s
	tfr	a,b
	clra		;zero_extendqihi: R:b -> R:d
	stb	9,s	;movlsbqihi: R:d -> 9,s
	ldb	8,s
	andb	#15
	addb	#48
	stb	6,s
	ldb	6,s
	cmpb	#57	;cmpqi:
	bls	L2
	ldb	6,s
	addb	#7
	stb	6,s
L2:
	lsr	8,s
	lsr	8,s
	lsr	8,s
	lsr	8,s
	ldb	8,s
	andb	#15
	addb	#48
	stb	5,s
	ldb	5,s
	cmpb	#57	;cmpqi:
	bls	L3
	ldb	5,s
	addb	#7
	stb	5,s
L3:
	ldb	9,s
	andb	#15
	addb	#48
	stb	4,s
	ldb	4,s
	cmpb	#57	;cmpqi:
	bls	L4
	ldb	4,s
	addb	#7
	stb	4,s
L4:
	lsr	9,s
	lsr	9,s
	lsr	9,s
	lsr	9,s
	ldb	9,s
	andb	#15
	addb	#48
	stb	3,s
	ldb	3,s
	cmpb	#57	;cmpqi:
	bls	L5
	ldb	3,s
	addb	#7
	stb	3,s
L5:
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
