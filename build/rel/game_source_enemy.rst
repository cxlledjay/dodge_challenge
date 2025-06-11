                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	enemy.c
                              6 	.area	.bss
                              7 	.globl	_enemy_list
   C883                       8 _enemy_list:	.blkb	25
                              9 	.globl	_queue_ptr
   C89C                      10 _queue_ptr:	.blkb	2
                             11 	.area	.text
                             12 	.globl	_enemy_init
   009C                      13 _enemy_init:
   009C 34 40         [ 6]   14 	pshs	u
   009E 8E C8 85      [ 3]   15 	ldx	#_enemy_list+2
   00A1                      16 L2:
   00A1 6F 84         [ 6]   17 	clr	,x
   00A3 6F 1F         [ 7]   18 	clr	-1,x
   00A5 6F 1E         [ 7]   19 	clr	-2,x
   00A7 CE 00 E4      [ 3]   20 	ldu	#_idle
   00AA EF 01         [ 6]   21 	stu	1,x
   00AC 30 05         [ 5]   22 	leax	5,x
   00AE 8C C8 9E      [ 4]   23 	cmpx	#_enemy_list+27	;cmphi:
   00B1 26 EE         [ 3]   24 	bne	L2
   00B3 8E C8 83      [ 3]   25 	ldx	#_enemy_list
   00B6 BF C8 9C      [ 6]   26 	stx	_queue_ptr
   00B9 35 C0         [ 7]   27 	puls	u,pc
                             28 	.globl	_enemy_try_spawn
   00BB                      29 _enemy_try_spawn:
   00BB 34 40         [ 6]   30 	pshs	u
   00BD 34 04         [ 6]   31 	pshs	b
   00BF BE C8 9C      [ 6]   32 	ldx	_queue_ptr
   00C2 C6 FF         [ 2]   33 	ldb	#-1
   00C4 EE 03         [ 6]   34 	ldu	3,x
   00C6 11 83 00 E4   [ 5]   35 	cmpu	#_idle	;cmphi:
   00CA 27 04         [ 3]   36 	beq	L10
   00CC 32 61         [ 5]   37 	leas	1,s
   00CE 35 C0         [ 7]   38 	puls	u,pc
   00D0                      39 L10:
   00D0 CE 00 E5      [ 3]   40 	ldu	#_tick_dummy
   00D3 EF 03         [ 6]   41 	stu	3,x
   00D5 6F 02         [ 7]   42 	clr	2,x
   00D7 C6 1E         [ 2]   43 	ldb	#30
   00D9 E7 01         [ 5]   44 	stb	1,x
   00DB E6 E4         [ 4]   45 	ldb	,s
   00DD E7 84         [ 4]   46 	stb	,x
   00DF 5F            [ 2]   47 	clrb
   00E0 32 61         [ 5]   48 	leas	1,s
   00E2 35 C0         [ 7]   49 	puls	u,pc
                             50 	.globl	_idle
   00E4                      51 _idle:
   00E4 39            [ 5]   52 	rts
                             53 	.globl	_tick_dummy
   00E5                      54 _tick_dummy:
   00E5 39            [ 5]   55 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Wed Jun 11 20:47:46 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                0034 R   |   3 L2                 0005 R
  3 _enemy_init        0000 GR  |   2 _enemy_list        0000 GR
  3 _enemy_try_spa     001F GR  |   3 _idle              0048 GR
  2 _queue_ptr         0019 GR  |   3 _tick_dummy        0049 GR

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Wed Jun 11 20:47:46 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size   1B   flags    0
   3 .text            size   4A   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

