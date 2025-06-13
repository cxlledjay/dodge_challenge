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
   00E9 BD 03 CA      [ 8]   16 	jsr	_map_init
   00EC BD 08 33      [ 8]   17 	jsr	_player_init
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
                             33 	.globl	_temp
                             34 	.area	.data
   C880                      35 _temp:
   C880 00                   36 	.byte	0
                             37 	.area	.text
                             38 	.globl	_game_run
   010A                      39 _game_run:
   010A 32 7F         [ 5]   40 	leas	-1,s
   010C BD F1 92      [ 8]   41 	jsr	___Wait_Recal
   010F F6 C8 80      [ 5]   42 	ldb	_temp
   0112 27 07         [ 3]   43 	beq	L22
   0114 5A            [ 2]   44 	decb
   0115 F7 C8 80      [ 5]   45 	stb	_temp
   0118 32 61         [ 5]   46 	leas	1,s
   011A 39            [ 5]   47 	rts
   011B                      48 L22:
   011B C6 0A         [ 2]   49 	ldb	#10
   011D F7 C8 80      [ 5]   50 	stb	_temp
   0120 F6 C8 AC      [ 5]   51 	ldb	_the_player+1
   0123 E7 E2         [ 6]   52 	stb	,-s
   0125 C6 EC         [ 2]   53 	ldb	#-20
   0127 E7 E2         [ 6]   54 	stb	,-s
   0129 C6 64         [ 2]   55 	ldb	#100
   012B BD 0F EC      [ 8]   56 	jsr	_print_signed_int
   012E BD F1 BA      [ 8]   57 	jsr	___Read_Btns
   0131 F6 C8 11      [ 5]   58 	ldb	_Vec_Buttons
   0134 E7 62         [ 5]   59 	stb	2,s
   0136 32 62         [ 5]   60 	leas	2,s
   0138 C5 01         [ 2]   61 	bitb	#1
   013A 26 2D         [ 3]   62 	bne	L23
   013C C6 08         [ 2]   63 	ldb	#8
   013E E4 E4         [ 4]   64 	andb	,s
   0140 27 03         [ 3]   65 	beq	L12
   0142 7A C8 A5      [ 7]   66 	dec	_the_game+2
   0145                      67 L12:
   0145 C6 06         [ 2]   68 	ldb	#6
   0147 E4 E4         [ 4]   69 	andb	,s
   0149 C1 06         [ 2]   70 	cmpb	#6	;cmpqi:
   014B 27 0E         [ 3]   71 	beq	L13
   014D C6 02         [ 2]   72 	ldb	#2
   014F E4 E4         [ 4]   73 	andb	,s
   0151 27 1C         [ 3]   74 	beq	L14
   0153 BE C8 B0      [ 6]   75 	ldx	_the_player+5
   0156 8C 08 4B      [ 4]   76 	cmpx	#_player_draw	;cmphi:
   0159 27 49         [ 3]   77 	beq	L24
   015B                      78 L13:
   015B BD 00 7A      [ 8]   79 	jsr	_clock_tick
   015E AD 9F C8 A9   [12]   80 	jsr	[_the_map+1]
   0162 AD 9F C8 B0   [12]   81 	jsr	[_the_player+5]
   0166 32 61         [ 5]   82 	leas	1,s
   0168 39            [ 5]   83 	rts
   0169                      84 L23:
   0169 7C C8 A5      [ 7]   85 	inc	_the_game+2
   016C 32 61         [ 5]   86 	leas	1,s
   016E 39            [ 5]   87 	rts
   016F                      88 L14:
   016F C6 04         [ 2]   89 	ldb	#4
   0171 E4 E4         [ 4]   90 	andb	,s
   0173 27 E6         [ 3]   91 	beq	L13
   0175 BE C8 B0      [ 6]   92 	ldx	_the_player+5
   0178 8C 08 4B      [ 4]   93 	cmpx	#_player_draw	;cmphi:
   017B 26 DE         [ 3]   94 	bne	L13
   017D F6 C8 AB      [ 5]   95 	ldb	_the_player
   0180 10 26 00 6D   [ 6]   96 	lbne	L25
   0184 8E 0A CA      [ 3]   97 	ldx	#_player_change_left_to_mid_step1
   0187 BF C8 B0      [ 6]   98 	stx	_the_player+5
   018A F6 C8 A5      [ 5]   99 	ldb	_the_game+2
   018D 4F            [ 2]  100 	clra		;zero_extendqihi: R:b -> R:d
   018E 1F 01         [ 6]  101 	tfr	d,x
   0190 E6 89 07 FC   [ 8]  102 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT,x
   0194 F7 C8 AF      [ 5]  103 	stb	_the_player+4
   0197 8E 0F BB      [ 3]  104 	ldx	#__SP1_LEFT_MID_X_LUT_1
   019A BF C8 AD      [ 6]  105 	stx	_the_player+2
   019D C6 03         [ 2]  106 	ldb	#3
   019F F7 C8 AB      [ 5]  107 	stb	_the_player
   01A2 20 B7         [ 3]  108 	bra	L13
   01A4                     109 L24:
   01A4 F6 C8 AB      [ 5]  110 	ldb	_the_player
   01A7 C1 01         [ 2]  111 	cmpb	#1	;cmpqi:
   01A9 27 25         [ 3]  112 	beq	L15
   01AB C1 02         [ 2]  113 	cmpb	#2	;cmpqi:
   01AD 26 AC         [ 3]  114 	bne	L13
   01AF 8E 0C D4      [ 3]  115 	ldx	#_player_change_right_to_mid_step1
   01B2 BF C8 B0      [ 6]  116 	stx	_the_player+5
   01B5 F6 C8 A5      [ 5]  117 	ldb	_the_game+2
   01B8 4F            [ 2]  118 	clra		;zero_extendqihi: R:b -> R:d
   01B9 1F 01         [ 6]  119 	tfr	d,x
   01BB E6 89 07 FC   [ 8]  120 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT,x
   01BF F7 C8 AF      [ 5]  121 	stb	_the_player+4
   01C2 8E 0F C9      [ 3]  122 	ldx	#__SP1_RIGHT_MID_X_LUT_1
   01C5 BF C8 AD      [ 6]  123 	stx	_the_player+2
   01C8 C6 03         [ 2]  124 	ldb	#3
   01CA F7 C8 AB      [ 5]  125 	stb	_the_player
   01CD 16 FF 8B      [ 5]  126 	lbra	L13
   01D0                     127 L15:
   01D0 8E 0D D8      [ 3]  128 	ldx	#_player_change_mid_to_left_step1
   01D3 BF C8 B0      [ 6]  129 	stx	_the_player+5
   01D6 F6 C8 A5      [ 5]  130 	ldb	_the_game+2
   01D9 4F            [ 2]  131 	clra		;zero_extendqihi: R:b -> R:d
   01DA 1F 01         [ 6]  132 	tfr	d,x
   01DC E6 89 07 FC   [ 8]  133 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT,x
   01E0 F7 C8 AF      [ 5]  134 	stb	_the_player+4
   01E3 8E 0F D0      [ 3]  135 	ldx	#__SP1_MID_LEFT_X_LUT_1
   01E6 BF C8 AD      [ 6]  136 	stx	_the_player+2
   01E9 C6 03         [ 2]  137 	ldb	#3
   01EB F7 C8 AB      [ 5]  138 	stb	_the_player
   01EE 16 FF 6A      [ 5]  139 	lbra	L13
   01F1                     140 L25:
   01F1 C1 01         [ 2]  141 	cmpb	#1	;cmpqi:
   01F3 10 26 FF 64   [ 6]  142 	lbne	L13
   01F7 8E 0B CE      [ 3]  143 	ldx	#_player_change_mid_to_right_step1
   01FA BF C8 B0      [ 6]  144 	stx	_the_player+5
   01FD F6 C8 A5      [ 5]  145 	ldb	_the_game+2
   0200 4F            [ 2]  146 	clra		;zero_extendqihi: R:b -> R:d
   0201 1F 01         [ 6]  147 	tfr	d,x
   0203 E6 89 07 FC   [ 8]  148 	ldb	_PLAYER_ANIMATION_FRAME_CNT_STAGE1_LUT,x
   0207 F7 C8 AF      [ 5]  149 	stb	_the_player+4
   020A 8E 0F C2      [ 3]  150 	ldx	#__SP1_MID_RIGHT_X_LUT_1
   020D BF C8 AD      [ 6]  151 	stx	_the_player+2
   0210 C6 03         [ 2]  152 	ldb	#3
   0212 F7 C8 AB      [ 5]  153 	stb	_the_player
   0215 16 FF 43      [ 5]  154 	lbra	L13
                            155 	.globl	_pause_menu
   0218                     156 _pause_menu:
   0218 39            [ 5]  157 	rts
                            158 	.globl	_game_over
   0219                     159 _game_over:
   0219 39            [ 5]  160 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Sat Jun 14 01:03:03 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L12                0068 R   |   3 L13                007E R
  3 L14                0092 R   |   3 L15                00F3 R
  3 L22                003E R   |   3 L23                008C R
  3 L24                00C7 R   |   3 L25                0114 R
    _PLAYER_ANIMAT     **** GX  |     _Vec_Buttons       **** GX
    __SP1_LEFT_MID     **** GX  |     __SP1_MID_LEFT     **** GX
    __SP1_MID_RIGH     **** GX  |     __SP1_RIGHT_MI     **** GX
    ___Read_Btns       **** GX  |     ___Wait_Recal      **** GX
    _ability_init      **** GX  |     _clock_init        **** GX
    _clock_tick        **** GX  |     _enemy_init        **** GX
  3 _game_init         0000 GR  |   3 _game_over         013C GR
  3 _game_run          002D GR  |     _map_init          **** GX
  3 _pause_menu        013B GR  |   3 _play_start_an     0026 GR
    _player_change     **** GX  |     _player_change     **** GX
    _player_change     **** GX  |     _player_change     **** GX
    _player_draw       **** GX  |     _player_init       **** GX
    _print_signed_     **** GX  |   3 _start_menu        001F GR
  4 _temp              0000 GR  |   2 _the_game          0000 GR
    _the_map           **** GX  |     _the_player        **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Sat Jun 14 01:03:03 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    5   flags    0
   3 .text            size  13D   flags  100
   4 .data            size    1   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

