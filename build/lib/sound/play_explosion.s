;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	play_explosion.c
	.area	.text
	.globl	_play_explosion
_play_explosion:
	pshs	y
	leay	,x
	jsr	___Stop_Sound
	jsr	_stop_music
	sty	_current_explosion
	ldb	#-128
	stb	_Vec_Expl_Flag
	puls	y,pc
