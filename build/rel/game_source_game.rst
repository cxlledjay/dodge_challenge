                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	game.c
                              6 	.area	.bss
                              7 	.globl	_the_game
   C8A2                       8 _the_game:	.blkb	5
                              9 	.area	.text
                             10 	.globl	_game_init
   00DD                      11 _game_init:
   00DD CC 00 00      [ 3]   12 	ldd	#0
   00E0 FD C8 A2      [ 6]   13 	std	_the_game
   00E3 7F C8 A4      [ 7]   14 	clr	_the_game+2
   00E6 BD 00 6E      [ 8]   15 	jsr	_clock_init
   00E9 BD 03 1C      [ 8]   16 	jsr	_map_init
   00EC BD 07 57      [ 8]   17 	jsr	_player_init
   00EF BD 00 61      [ 8]   18 	jsr	_ability_init
   00F2 BD 00 93      [ 8]   19 	jsr	_enemy_init
   00F5 8E 00 FC      [ 3]   20 	ldx	#_start_menu
   00F8 BF C8 A5      [ 6]   21 	stx	_the_game+3
   00FB 39            [ 5]   22 	rts
                             23 	.globl	_start_menu
   00FC                      24 _start_menu:
   00FC 8E 01 03      [ 3]   25 	ldx	#_play_start_animation
   00FF BF C8 A5      [ 6]   26 	stx	_the_game+3
   0102 39            [ 5]   27 	rts
                             28 	.globl	_play_start_animation
   0103                      29 _play_start_animation:
   0103 8E 01 0A      [ 3]   30 	ldx	#_game_run
   0106 BF C8 A5      [ 6]   31 	stx	_the_game+3
   0109 39            [ 5]   32 	rts
                             33 	.globl	_game_run
   010A                      34 _game_run:
   010A 32 7F         [ 5]   35 	leas	-1,s
   010C BD F1 92      [ 8]   36 	jsr	___Wait_Recal
   010F F6 C8 A4      [ 5]   37 	ldb	_the_game+2
   0112 E7 E2         [ 6]   38 	stb	,-s
   0114 C6 EC         [ 2]   39 	ldb	#-20
   0116 E7 E2         [ 6]   40 	stb	,-s
   0118 C6 64         [ 2]   41 	ldb	#100
   011A BD 0B 0F      [ 8]   42 	jsr	_print_unsigned_int
   011D BD F1 BA      [ 8]   43 	jsr	___Read_Btns
   0120 F6 C8 11      [ 5]   44 	ldb	_Vec_Buttons
   0123 E7 62         [ 5]   45 	stb	2,s
   0125 32 62         [ 5]   46 	leas	2,s
   0127 C5 01         [ 2]   47 	bitb	#1
   0129 26 31         [ 3]   48 	bne	L15
   012B C6 08         [ 2]   49 	ldb	#8
   012D E4 E4         [ 4]   50 	andb	,s
   012F 27 03         [ 3]   51 	beq	L10
   0131 7A C8 A4      [ 7]   52 	dec	_the_game+2
   0134                      53 L10:
   0134 C6 06         [ 2]   54 	ldb	#6
   0136 E4 E4         [ 4]   55 	andb	,s
   0138 C1 06         [ 2]   56 	cmpb	#6	;cmpqi:
   013A 27 12         [ 3]   57 	beq	L11
   013C C6 02         [ 2]   58 	ldb	#2
   013E E4 E4         [ 4]   59 	andb	,s
   0140 26 20         [ 3]   60 	bne	L16
   0142 C6 04         [ 2]   61 	ldb	#4
   0144 E4 E4         [ 4]   62 	andb	,s
   0146 27 06         [ 3]   63 	beq	L11
   0148 8E 07 8E      [ 3]   64 	ldx	#_player_change_right
   014B BF C8 AC      [ 6]   65 	stx	_the_player+2
   014E                      66 L11:
   014E BD 00 7A      [ 8]   67 	jsr	_clock_tick
   0151 AD 9F C8 A8   [12]   68 	jsr	[_the_map+1]
   0155 AD 9F C8 AC   [12]   69 	jsr	[_the_player+2]
   0159 32 61         [ 5]   70 	leas	1,s
   015B 39            [ 5]   71 	rts
   015C                      72 L15:
   015C 7C C8 A4      [ 7]   73 	inc	_the_game+2
   015F 32 61         [ 5]   74 	leas	1,s
   0161 39            [ 5]   75 	rts
   0162                      76 L16:
   0162 8E 07 7C      [ 3]   77 	ldx	#_player_change_left
   0165 BF C8 AC      [ 6]   78 	stx	_the_player+2
   0168 20 E4         [ 3]   79 	bra	L11
                             80 	.globl	_pause_menu
   016A                      81 _pause_menu:
   016A 39            [ 5]   82 	rts
                             83 	.globl	_game_over
   016B                      84 _game_over:
   016B 39            [ 5]   85 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Jun 13 21:12:40 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                0057 R   |   3 L11                0071 R
  3 L15                007F R   |   3 L16                0085 R
    _Vec_Buttons       **** GX  |     ___Read_Btns       **** GX
    ___Wait_Recal      **** GX  |     _ability_init      **** GX
    _clock_init        **** GX  |     _clock_tick        **** GX
    _enemy_init        **** GX  |   3 _game_init         0000 GR
  3 _game_over         008E GR  |   3 _game_run          002D GR
    _map_init          **** GX  |   3 _pause_menu        008D GR
  3 _play_start_an     0026 GR  |     _player_change     **** GX
    _player_change     **** GX  |     _player_init       **** GX
    _print_unsigne     **** GX  |   3 _start_menu        001F GR
  2 _the_game          0000 GR  |     _the_map           **** GX
    _the_player        **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri Jun 13 21:12:40 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    5   flags    0
   3 .text            size   8F   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

