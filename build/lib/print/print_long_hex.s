;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	print_long_hex.c
	.area	.text
	.globl	_print_long_hex
_print_long_hex:
	leas	-15,s
	stb	6,s
	stx	,s
	ldb	#-128
	stb	14,s
	tfr	x,d
	stb	7,s	;movlsbqihi: R:d -> 7,s
	tfr	a,b
	clra		;zero_extendqihi: R:b -> R:d
	stb	9,s
	ldb	#15
	andb	7,s
	stb	5,s
	addb	#48
	stb	13,s
	cmpb	#57	;cmpqi:
	bls	L2
	ldb	5,s
	addb	#55
	stb	13,s
L2:
	ldb	7,s
	lsrb
	lsrb
	lsrb
	lsrb
	stb	4,s
	addb	#48
	stb	12,s
	cmpb	#57	;cmpqi:
	bls	L3
	ldb	4,s
	addb	#55
	stb	12,s
L3:
	ldb	#15
	andb	9,s
	stb	3,s
	addb	#48
	stb	11,s
	cmpb	#57	;cmpqi:
	bls	L4
	ldb	3,s
	addb	#55
	stb	11,s
L4:
	ldb	9,s
	lsrb
	lsrb
	lsrb
	lsrb
	stb	2,s
	addb	#48
	stb	10,s
	cmpb	#57	;cmpqi:
	bls	L5
	ldb	2,s
	addb	#55
	stb	10,s
L5:
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	6,s
	pshs	b
	leax	11,s
	ldb	18,s
	jsr	__Print_Str_d
	leas	16,s
	rts
