;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	sound_init.c
	.area	.text
	.globl	_sound_init
_sound_init:
	ldx	#_music_off
	stx	_current_music
	ldx	#_explosion_off
	stx	_current_explosion
	rts
