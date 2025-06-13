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
   00E9 BD 03 A7      [ 8]   16 	jsr	_map_init
   00EC BD 08 10      [ 8]   17 	jsr	_player_init
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
   010F BD F1 BA      [ 8]   37 	jsr	___Read_Btns
   0112 F6 C8 11      [ 5]   38 	ldb	_Vec_Buttons
   0115 E7 E4         [ 4]   39 	stb	,s
   0117 C5 01         [ 2]   40 	bitb	#1
   0119 26 33         [ 3]   41 	bne	L19
   011B C6 08         [ 2]   42 	ldb	#8
   011D E4 E4         [ 4]   43 	andb	,s
   011F 27 03         [ 3]   44 	beq	L10
   0121 7A C8 A4      [ 7]   45 	dec	_the_game+2
   0124                      46 L10:
   0124 C6 06         [ 2]   47 	ldb	#6
   0126 E4 E4         [ 4]   48 	andb	,s
   0128 C1 06         [ 2]   49 	cmpb	#6	;cmpqi:
   012A 27 14         [ 3]   50 	beq	L11
   012C C6 02         [ 2]   51 	ldb	#2
   012E E4 E4         [ 4]   52 	andb	,s
   0130 26 22         [ 3]   53 	bne	L20
   0132 C6 04         [ 2]   54 	ldb	#4
   0134 E4 E4         [ 4]   55 	andb	,s
   0136 27 08         [ 3]   56 	beq	L11
   0138 BE C8 AF      [ 6]   57 	ldx	_the_player+5
   013B 8C 08 28      [ 4]   58 	cmpx	#_player_draw	;cmphi:
   013E 27 47         [ 3]   59 	beq	L21
   0140                      60 L11:
   0140 BD 00 7A      [ 8]   61 	jsr	_clock_tick
   0143 AD 9F C8 A8   [12]   62 	jsr	[_the_map+1]
   0147 AD 9F C8 AF   [12]   63 	jsr	[_the_player+5]
   014B 32 61         [ 5]   64 	leas	1,s
   014D 39            [ 5]   65 	rts
   014E                      66 L19:
   014E 7C C8 A4      [ 7]   67 	inc	_the_game+2
   0151 32 61         [ 5]   68 	leas	1,s
   0153 39            [ 5]   69 	rts
   0154                      70 L20:
   0154 BE C8 AF      [ 6]   71 	ldx	_the_player+5
   0157 8C 08 28      [ 4]   72 	cmpx	#_player_draw	;cmphi:
   015A 26 E4         [ 3]   73 	bne	L11
   015C F6 C8 AA      [ 5]   74 	ldb	_the_player
   015F C1 01         [ 2]   75 	cmpb	#1	;cmpqi:
   0161 27 4A         [ 3]   76 	beq	L13
   0163 C1 02         [ 2]   77 	cmpb	#2	;cmpqi:
   0165 26 D9         [ 3]   78 	bne	L11
   0167 8E 0C 81      [ 3]   79 	ldx	#_player_change_right_to_mid_step1
   016A BF C8 AF      [ 6]   80 	stx	_the_player+5
   016D F6 C8 A4      [ 5]   81 	ldb	_the_game+2
   0170 4F            [ 2]   82 	clra		;zero_extendqihi: R:b -> R:d
   0171 1F 01         [ 6]   83 	tfr	d,x
   0173 E6 89 07 D9   [ 8]   84 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT,x
   0177 F7 C8 AE      [ 5]   85 	stb	_the_player+4
   017A 8E 0F 46      [ 3]   86 	ldx	#__SP1_RIGHT_MID_X_LUT_1
   017D BF C8 AC      [ 6]   87 	stx	_the_player+2
   0180 C6 03         [ 2]   88 	ldb	#3
   0182 F7 C8 AA      [ 5]   89 	stb	_the_player
   0185 20 B9         [ 3]   90 	bra	L11
   0187                      91 L21:
   0187 F6 C8 AA      [ 5]   92 	ldb	_the_player
   018A 26 42         [ 3]   93 	bne	L22
   018C 8E 0A A7      [ 3]   94 	ldx	#_player_change_left_to_mid_step1
   018F BF C8 AF      [ 6]   95 	stx	_the_player+5
   0192 F6 C8 A4      [ 5]   96 	ldb	_the_game+2
   0195 4F            [ 2]   97 	clra		;zero_extendqihi: R:b -> R:d
   0196 1F 01         [ 6]   98 	tfr	d,x
   0198 E6 89 07 D9   [ 8]   99 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT,x
   019C F7 C8 AE      [ 5]  100 	stb	_the_player+4
   019F 8E 0F 38      [ 3]  101 	ldx	#__SP1_LEFT_MID_X_LUT_1
   01A2 BF C8 AC      [ 6]  102 	stx	_the_player+2
   01A5 C6 03         [ 2]  103 	ldb	#3
   01A7 F7 C8 AA      [ 5]  104 	stb	_the_player
   01AA 16 FF 93      [ 5]  105 	lbra	L11
   01AD                     106 L13:
   01AD 8E 0D 6D      [ 3]  107 	ldx	#_player_change_mid_to_left_step1
   01B0 BF C8 AF      [ 6]  108 	stx	_the_player+5
   01B3 F6 C8 A4      [ 5]  109 	ldb	_the_game+2
   01B6 4F            [ 2]  110 	clra		;zero_extendqihi: R:b -> R:d
   01B7 1F 01         [ 6]  111 	tfr	d,x
   01B9 E6 89 07 D9   [ 8]  112 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT,x
   01BD F7 C8 AE      [ 5]  113 	stb	_the_player+4
   01C0 8E 0F 4D      [ 3]  114 	ldx	#__SP1_MID_LEFT_X_LUT_1
   01C3 BF C8 AC      [ 6]  115 	stx	_the_player+2
   01C6 C6 03         [ 2]  116 	ldb	#3
   01C8 F7 C8 AA      [ 5]  117 	stb	_the_player
   01CB 16 FF 72      [ 5]  118 	lbra	L11
   01CE                     119 L22:
   01CE C1 01         [ 2]  120 	cmpb	#1	;cmpqi:
   01D0 10 26 FF 6C   [ 6]  121 	lbne	L11
   01D4 8E 0B 93      [ 3]  122 	ldx	#_player_change_mid_to_right_step1
   01D7 BF C8 AF      [ 6]  123 	stx	_the_player+5
   01DA F6 C8 A4      [ 5]  124 	ldb	_the_game+2
   01DD 4F            [ 2]  125 	clra		;zero_extendqihi: R:b -> R:d
   01DE 1F 01         [ 6]  126 	tfr	d,x
   01E0 E6 89 07 D9   [ 8]  127 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT,x
   01E4 F7 C8 AE      [ 5]  128 	stb	_the_player+4
   01E7 8E 0F 3F      [ 3]  129 	ldx	#__SP1_MID_RIGHT_X_LUT_1
   01EA BF C8 AC      [ 6]  130 	stx	_the_player+2
   01ED C6 03         [ 2]  131 	ldb	#3
   01EF F7 C8 AA      [ 5]  132 	stb	_the_player
   01F2 16 FF 4B      [ 5]  133 	lbra	L11
                            134 	.globl	_pause_menu
   01F5                     135 _pause_menu:
   01F5 39            [ 5]  136 	rts
                            137 	.globl	_game_over
   01F6                     138 _game_over:
   01F6 39            [ 5]  139 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Sat Jun 14 01:20:49 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                0047 R   |   3 L11                0063 R
  3 L13                00D0 R   |   3 L19                0071 R
  3 L20                0077 R   |   3 L21                00AA R
  3 L22                00F1 R   |     _PLAYER_ANIMAT     **** GX
    _Vec_Buttons       **** GX  |     __SP1_LEFT_MID     **** GX
    __SP1_MID_LEFT     **** GX  |     __SP1_MID_RIGH     **** GX
    __SP1_RIGHT_MI     **** GX  |     ___Read_Btns       **** GX
    ___Wait_Recal      **** GX  |     _ability_init      **** GX
    _clock_init        **** GX  |     _clock_tick        **** GX
    _enemy_init        **** GX  |   3 _game_init         0000 GR
  3 _game_over         0119 GR  |   3 _game_run          002D GR
    _map_init          **** GX  |   3 _pause_menu        0118 GR
  3 _play_start_an     0026 GR  |     _player_change     **** GX
    _player_change     **** GX  |     _player_change     **** GX
    _player_change     **** GX  |     _player_draw       **** GX
    _player_init       **** GX  |   3 _start_menu        001F GR
  2 _the_game          0000 GR  |     _the_map           **** GX
    _the_player        **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Sat Jun 14 01:20:49 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    5   flags    0
   3 .text            size  11A   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

