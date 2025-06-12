;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	main.c
	.area	.text
	.globl	_main
_main:
	clr	_the_game+2
	ldd	#0
	std	_the_game
	ldx	#_game_init
	stx	_the_game+3
L2:
	jsr	[_the_game+3]
	bra	L2
