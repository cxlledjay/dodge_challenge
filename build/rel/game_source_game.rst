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
   00DB                      11 _game_init:
   00DB CC 00 00      [ 3]   12 	ldd	#0
   00DE FD C8 A2      [ 6]   13 	std	_the_game
   00E1 7F C8 A4      [ 7]   14 	clr	_the_game+2
   00E4 BD 00 6E      [ 8]   15 	jsr	_clk_init
   00E7 BD 02 D2      [ 8]   16 	jsr	_map_init
   00EA BD 02 E5      [ 8]   17 	jsr	_player_init
   00ED BD 00 61      [ 8]   18 	jsr	_ability_init
   00F0 BD 00 91      [ 8]   19 	jsr	_enemy_init
   00F3 8E 00 FA      [ 3]   20 	ldx	#_start_menu
   00F6 BF C8 A5      [ 6]   21 	stx	_the_game+3
   00F9 39            [ 5]   22 	rts
                             23 	.globl	_start_menu
   00FA                      24 _start_menu:
   00FA 8E 01 01      [ 3]   25 	ldx	#_play_start_animation
   00FD BF C8 A5      [ 6]   26 	stx	_the_game+3
   0100 39            [ 5]   27 	rts
                             28 	.globl	_play_start_animation
   0101                      29 _play_start_animation:
   0101 8E 01 08      [ 3]   30 	ldx	#_game_run
   0104 BF C8 A5      [ 6]   31 	stx	_the_game+3
   0107 39            [ 5]   32 	rts
                             33 	.globl	_game_run
   0108                      34 _game_run:
   0108 32 7E         [ 5]   35 	leas	-2,s
   010A BD F1 92      [ 8]   36 	jsr	___Wait_Recal
   010D BD F1 BA      [ 8]   37 	jsr	___Read_Btns
   0110 F6 C8 11      [ 5]   38 	ldb	_Vec_Buttons
   0113 E7 E4         [ 4]   39 	stb	,s
   0115 C5 01         [ 2]   40 	bitb	#1
   0117 26 22         [ 3]   41 	bne	L15
   0119 E6 E4         [ 4]   42 	ldb	,s
   011B C5 06         [ 2]   43 	bitb	#6
   011D 27 0E         [ 3]   44 	beq	L16
   011F                      45 L10:
   011F BD 00 78      [ 8]   46 	jsr	_clk_update
   0122 AD 9F C8 A8   [12]   47 	jsr	[_the_map+1]
   0126 AD 9F C8 AC   [12]   48 	jsr	[_the_player+2]
   012A 32 62         [ 5]   49 	leas	2,s
   012C 39            [ 5]   50 	rts
   012D                      51 L16:
   012D C6 02         [ 2]   52 	ldb	#2
   012F E4 E4         [ 4]   53 	andb	,s
   0131 27 11         [ 3]   54 	beq	L11
   0133                      55 L13:
   0133 8E 03 22      [ 3]   56 	ldx	#_player_change_left
   0136 BF C8 AC      [ 6]   57 	stx	_the_player+2
   0139 20 E4         [ 3]   58 	bra	L10
   013B                      59 L15:
   013B 8E 01 4C      [ 3]   60 	ldx	#_pause_menu
   013E BF C8 A5      [ 6]   61 	stx	_the_game+3
   0141 32 62         [ 5]   62 	leas	2,s
   0143 39            [ 5]   63 	rts
   0144                      64 L11:
   0144 C6 04         [ 2]   65 	ldb	#4
   0146 E4 E4         [ 4]   66 	andb	,s
   0148 27 D5         [ 3]   67 	beq	L10
   014A 20 E7         [ 3]   68 	bra	L13
                             69 	.globl	_pause_menu
   014C                      70 _pause_menu:
   014C 39            [ 5]   71 	rts
                             72 	.globl	_game_over
   014D                      73 _game_over:
   014D 39            [ 5]   74 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Thu Jun 12 18:40:10 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                0044 R   |   3 L11                0069 R
  3 L13                0058 R   |   3 L15                0060 R
  3 L16                0052 R   |     _Vec_Buttons       **** GX
    ___Read_Btns       **** GX  |     ___Wait_Recal      **** GX
    _ability_init      **** GX  |     _clk_init          **** GX
    _clk_update        **** GX  |     _enemy_init        **** GX
  3 _game_init         0000 GR  |   3 _game_over         0072 GR
  3 _game_run          002D GR  |     _map_init          **** GX
  3 _pause_menu        0071 GR  |   3 _play_start_an     0026 GR
    _player_change     **** GX  |     _player_init       **** GX
  3 _start_menu        001F GR  |   2 _the_game          0000 GR
    _the_map           **** GX  |     _the_player        **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Thu Jun 12 18:40:10 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    5   flags    0
   3 .text            size   73   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

