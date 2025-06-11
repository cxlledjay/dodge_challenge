;;; gcc for m6809 : Mar 17 2019 13:25:32
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
	.module	enemy.c
	.area	.bss
	.globl	_enemy_list
_enemy_list:	.blkb	25
	.globl	_queue_ptr
_queue_ptr:	.blkb	2
	.area	.text
	.globl	_enemy_init
_enemy_init:
	pshs	u
	ldx	#_enemy_list+2
L2:
	clr	,x
	clr	-1,x
	clr	-2,x
	ldu	#_idle
	stu	1,x
	leax	5,x
	cmpx	#_enemy_list+27	;cmphi:
	bne	L2
	ldx	#_enemy_list
	stx	_queue_ptr
	puls	u,pc
	.globl	_enemy_try_spawn
_enemy_try_spawn:
	pshs	u
	pshs	b
	ldx	_queue_ptr
	ldb	#-1
	ldu	3,x
	cmpu	#_idle	;cmphi:
	beq	L10
	leas	1,s
	puls	u,pc
L10:
	ldu	#_tick_dummy
	stu	3,x
	clr	2,x
	ldb	#30
	stb	1,x
	ldb	,s
	stb	,x
	clrb
	leas	1,s
	puls	u,pc
	.globl	_idle
_idle:
	rts
	.globl	_tick_dummy
_tick_dummy:
	rts
