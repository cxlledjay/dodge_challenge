;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
	.module	play_music.c
	.area	.text
	.globl	_play_music
_play_music:
	leas	-2,s
	stx	,s
	jsr	_stop_explosion
	ldx	,s
	stx	_current_music
	ldb	#1
	stb	_Vec_Music_Flag
	leas	2,s
	rts
