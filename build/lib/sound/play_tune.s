;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	play_tune.c
	.area	.text
	.globl	_play_tune
_play_tune:
	leas	-13,s
	stb	2,s
	stx	,s
	ldb	2,s
	aslb
	stb	3,s
	ldd	,s
	stb	4,s	;movlsbqihi: R:d -> 4,s
	ldb	3,s
	inc	3,s
	stb	8,s
	ldb	4,s
	stb	7,s
	ldb	8,s
	stb	,-s
	ldb	8,s
	jsr	__Sound_Byte
	leas	1,s
	ldd	,s
	tfr	a,b
	clra		;zero_extendqihi: R:b -> R:d
	stb	5,s	;movlsbqihi: R:d -> 5,s
	ldb	3,s
	stb	10,s
	ldb	5,s
	stb	9,s
	ldb	10,s
	stb	,-s
	ldb	10,s
	jsr	__Sound_Byte
	leas	1,s
	ldb	2,s
	addb	#8
	stb	6,s
	ldb	6,s
	stb	12,s
	ldb	15,s
	stb	11,s
	ldb	12,s
	stb	,-s
	ldb	12,s
	jsr	__Sound_Byte
	leas	1,s
	ldb	#7
	stb	,-s
	ldb	#-8
	jsr	__Sound_Byte
	leas	1,s
	leas	13,s
	rts
