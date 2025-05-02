;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	clock.c
	.area	.bss
	.globl	_clk_frames
_clk_frames:	.blkb	1
	.globl	_clk_seconds
_clk_seconds:	.blkb	2
	.area	.text
	.globl	_clk_init
_clk_init:
	clr	_clk_frames
	ldx	#0
	stx	_clk_seconds
	rts
	.globl	_clk_update
_clk_update:
	ldb	_clk_frames
	cmpb	#49	;cmpqi:
	bne	L4
	clr	_clk_frames
	ldx	_clk_seconds
	leax	1,x
	stx	_clk_seconds
	bra	L6
L4:
	ldb	_clk_frames
	incb
	stb	_clk_frames
L6:
	rts
