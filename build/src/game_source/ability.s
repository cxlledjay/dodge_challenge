;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	ability.c
	.area	.bss
	.globl	_the_ability
_the_ability:	.blkb	4
	.area	.text
	.globl	_dummy_tick
_dummy_tick:
	rts
	.globl	_ability_init
_ability_init:
	ldx	#_dummy_tick
	stx	_the_ability+2
	clr	_the_ability+1
	clr	_the_ability
	rts
