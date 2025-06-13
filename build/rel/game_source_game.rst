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
   00E9 BD 03 40      [ 8]   16 	jsr	_map_init
   00EC BD 07 C5      [ 8]   17 	jsr	_player_init
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
   011A BD 0E BC      [ 8]   42 	jsr	_print_unsigned_int
   011D BD F1 BA      [ 8]   43 	jsr	___Read_Btns
   0120 F6 C8 11      [ 5]   44 	ldb	_Vec_Buttons
   0123 E7 62         [ 5]   45 	stb	2,s
   0125 32 62         [ 5]   46 	leas	2,s
   0127 C5 01         [ 2]   47 	bitb	#1
   0129 26 3D         [ 3]   48 	bne	L15
   012B C6 08         [ 2]   49 	ldb	#8
   012D E4 E4         [ 4]   50 	andb	,s
   012F 27 03         [ 3]   51 	beq	L10
   0131 7A C8 A4      [ 7]   52 	dec	_the_game+2
   0134                      53 L10:
   0134 C6 06         [ 2]   54 	ldb	#6
   0136 E4 E4         [ 4]   55 	andb	,s
   0138 C1 06         [ 2]   56 	cmpb	#6	;cmpqi:
   013A 27 1E         [ 3]   57 	beq	L11
   013C C6 02         [ 2]   58 	ldb	#2
   013E E4 E4         [ 4]   59 	andb	,s
   0140 27 2C         [ 3]   60 	beq	L12
   0142 7D C8 AB      [ 7]   61 	tst	_the_player+1
   0145 26 13         [ 3]   62 	bne	L11
   0147 F6 C8 A4      [ 5]   63 	ldb	_the_game+2
   014A 4F            [ 2]   64 	clra		;zero_extendqihi: R:b -> R:d
   014B 1F 01         [ 6]   65 	tfr	d,x
   014D E6 89 07 72   [ 8]   66 	ldb	_PLAYER_ANIMATION_FRAME_CNT_LUT,x
   0151 F7 C8 AB      [ 5]   67 	stb	_the_player+1
   0154 8E 0A 53      [ 3]   68 	ldx	#_player_change_left
   0157 BF C8 AC      [ 6]   69 	stx	_the_player+2
   015A                      70 L11:
   015A BD 00 7A      [ 8]   71 	jsr	_clock_tick
   015D AD 9F C8 A8   [12]   72 	jsr	[_the_map+1]
   0161 AD 9F C8 AC   [12]   73 	jsr	[_the_player+2]
   0165 32 61         [ 5]   74 	leas	1,s
   0167 39            [ 5]   75 	rts
   0168                      76 L15:
   0168 7C C8 A4      [ 7]   77 	inc	_the_game+2
   016B 32 61         [ 5]   78 	leas	1,s
   016D 39            [ 5]   79 	rts
   016E                      80 L12:
   016E C6 04         [ 2]   81 	ldb	#4
   0170 E4 E4         [ 4]   82 	andb	,s
   0172 27 E6         [ 3]   83 	beq	L11
   0174 7D C8 AB      [ 7]   84 	tst	_the_player+1
   0177 26 E1         [ 3]   85 	bne	L11
   0179 F6 C8 A4      [ 5]   86 	ldb	_the_game+2
   017C 4F            [ 2]   87 	clra		;zero_extendqihi: R:b -> R:d
   017D 1F 01         [ 6]   88 	tfr	d,x
   017F E6 89 07 72   [ 8]   89 	ldb	_PLAYER_ANIMATION_FRAME_CNT_LUT,x
   0183 F7 C8 AB      [ 5]   90 	stb	_the_player+1
   0186 8E 0B F2      [ 3]   91 	ldx	#_player_change_right
   0189 BF C8 AC      [ 6]   92 	stx	_the_player+2
   018C 20 CC         [ 3]   93 	bra	L11
                             94 	.globl	_pause_menu
   018E                      95 _pause_menu:
   018E 39            [ 5]   96 	rts
                             97 	.globl	_game_over
   018F                      98 _game_over:
   018F 39            [ 5]   99 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Jun 13 23:47:53 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                0057 R   |   3 L11                007D R
  3 L12                0091 R   |   3 L15                008B R
    _PLAYER_ANIMAT     **** GX  |     _Vec_Buttons       **** GX
    ___Read_Btns       **** GX  |     ___Wait_Recal      **** GX
    _ability_init      **** GX  |     _clock_init        **** GX
    _clock_tick        **** GX  |     _enemy_init        **** GX
  3 _game_init         0000 GR  |   3 _game_over         00B2 GR
  3 _game_run          002D GR  |     _map_init          **** GX
  3 _pause_menu        00B1 GR  |   3 _play_start_an     0026 GR
    _player_change     **** GX  |     _player_change     **** GX
    _player_init       **** GX  |     _print_unsigne     **** GX
  3 _start_menu        001F GR  |   2 _the_game          0000 GR
    _the_map           **** GX  |     _the_player        **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri Jun 13 23:47:53 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    5   flags    0
   3 .text            size   B3   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

