;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	map.c
	.area	.bss
	.globl	_the_map
_the_map:	.blkb	3
	.area	.text
	.globl	_dummy_tick
_dummy_tick:
	rts
	.globl	_map_init
_map_init:
	ldx	#_dummy_tick
	stx	_the_map+1
	clr	_the_map
	rts
