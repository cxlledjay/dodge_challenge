;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	play_tune.c
	.area	.text
	.globl	_play_tune
_play_tune:
	leas	-5,s
	stb	3,s
	stx	1,s
	ldb	7,s
	stb	,s
	ldb	3,s
	aslb
	stb	4,s
	pshs	b
	ldb	3,s	;movlsbqihi: msb:2,s -> R:b
	jsr	__Sound_Byte
	ldd	2,s
	tfr	a,b
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	5,s
	incb
	pshs	b
	tfr	x,d	;movlsbqihi: R:x -> R:b
	jsr	__Sound_Byte
	ldb	5,s
	addb	#8
	pshs	b
	ldb	3,s
	jsr	__Sound_Byte
	ldb	#7
	stb	10,s
	ldb	#-8
	leas	8,s
	jmp	__Sound_Byte
