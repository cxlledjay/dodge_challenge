                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	game.c
                              6 	.area	.bss
                              7 	.globl	_the_game
   C8A3                       8 _the_game:	.blkb	5
                              9 	.area	.text
                             10 	.globl	_game_init
   00DD                      11 _game_init:
   00DD CC 00 00      [ 3]   12 	ldd	#0
   00E0 FD C8 A3      [ 6]   13 	std	_the_game
   00E3 7F C8 A5      [ 7]   14 	clr	_the_game+2
   00E6 BD 00 6E      [ 8]   15 	jsr	_clock_init
   00E9 BD 02 D2      [ 8]   16 	jsr	_map_init
   00EC BD 05 C5      [ 8]   17 	jsr	_player_init
   00EF BD 00 61      [ 8]   18 	jsr	_ability_init
   00F2 BD 00 93      [ 8]   19 	jsr	_enemy_init
   00F5 8E 00 FC      [ 3]   20 	ldx	#_start_menu
   00F8 BF C8 A6      [ 6]   21 	stx	_the_game+3
   00FB 39            [ 5]   22 	rts
                             23 	.globl	_start_menu
   00FC                      24 _start_menu:
   00FC 8E 01 03      [ 3]   25 	ldx	#_play_start_animation
   00FF BF C8 A6      [ 6]   26 	stx	_the_game+3
   0102 39            [ 5]   27 	rts
                             28 	.globl	_play_start_animation
   0103                      29 _play_start_animation:
   0103 8E 01 0A      [ 3]   30 	ldx	#_game_run
   0106 BF C8 A6      [ 6]   31 	stx	_the_game+3
   0109 39            [ 5]   32 	rts
                             33 	.globl	_game_run
   010A                      34 _game_run:
   010A 32 7F         [ 5]   35 	leas	-1,s
   010C BD F1 92      [ 8]   36 	jsr	___Wait_Recal
   010F BD F1 BA      [ 8]   37 	jsr	___Read_Btns
   0112 F6 C8 11      [ 5]   38 	ldb	_Vec_Buttons
   0115 E7 E4         [ 4]   39 	stb	,s
   0117 C5 01         [ 2]   40 	bitb	#1
   0119 26 25         [ 3]   41 	bne	L11
   011B C6 06         [ 2]   42 	ldb	#6
   011D E4 E4         [ 4]   43 	andb	,s
   011F C1 06         [ 2]   44 	cmpb	#6	;cmpqi:
   0121 27 12         [ 3]   45 	beq	L9
   0123 C6 02         [ 2]   46 	ldb	#2
   0125 E4 E4         [ 4]   47 	andb	,s
   0127 26 1A         [ 3]   48 	bne	L13
   0129 C6 04         [ 2]   49 	ldb	#4
   012B E4 E4         [ 4]   50 	andb	,s
   012D 27 06         [ 3]   51 	beq	L9
   012F 8E 06 14      [ 3]   52 	ldx	#_player_change_right
   0132 BF C8 AD      [ 6]   53 	stx	_the_player+2
   0135                      54 L9:
   0135 BD 00 7A      [ 8]   55 	jsr	_clock_tick
   0138 AD 9F C8 A9   [12]   56 	jsr	[_the_map+1]
   013C AD 9F C8 AD   [12]   57 	jsr	[_the_player+2]
   0140                      58 L11:
   0140 32 61         [ 5]   59 	leas	1,s
   0142 39            [ 5]   60 	rts
   0143                      61 L13:
   0143 8E 06 02      [ 3]   62 	ldx	#_player_change_left
   0146 BF C8 AD      [ 6]   63 	stx	_the_player+2
   0149 20 EA         [ 3]   64 	bra	L9
                             65 	.globl	_pause_menu
   014B                      66 _pause_menu:
   014B 39            [ 5]   67 	rts
                             68 	.globl	_game_over
   014C                      69 _game_over:
   014C 39            [ 5]   70 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Thu Jun 12 23:11:43 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L11                0063 R   |   3 L13                0066 R
  3 L9                 0058 R   |     _Vec_Buttons       **** GX
    ___Read_Btns       **** GX  |     ___Wait_Recal      **** GX
    _ability_init      **** GX  |     _clock_init        **** GX
    _clock_tick        **** GX  |     _enemy_init        **** GX
  3 _game_init         0000 GR  |   3 _game_over         006F GR
  3 _game_run          002D GR  |     _map_init          **** GX
  3 _pause_menu        006E GR  |   3 _play_start_an     0026 GR
    _player_change     **** GX  |     _player_change     **** GX
    _player_init       **** GX  |   3 _start_menu        001F GR
  2 _the_game          0000 GR  |     _the_map           **** GX
    _the_player        **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Thu Jun 12 23:11:43 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    5   flags    0
   3 .text            size   70   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

