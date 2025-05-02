                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	main.c
                              6 	.area	.text
                              7 	.globl	_run_game
   03E4                       8 _run_game:
   03E4 BD 00 60      [ 8]    9 	jsr	_clk_init
   03E7 BD 00 75      [ 8]   10 	jsr	_lvl_init
   03EA BD 00 E8      [ 8]   11 	jsr	_map_init
   03ED BD 03 1D      [ 8]   12 	jsr	_player_init
   03F0                      13 L2:
   03F0 BD F1 92      [ 8]   14 	jsr	___Wait_Recal
   03F3 BD 00 64      [ 8]   15 	jsr	_clk_update
   03F6 BD 00 EC      [ 8]   16 	jsr	_map_calculate_animation
   03F9 BD 01 30      [ 8]   17 	jsr	_map_draw_road
   03FC BD 03 42      [ 8]   18 	jsr	_player_handle_input
   03FF BD 03 B5      [ 8]   19 	jsr	_player_draw
   0402 20 EC         [ 3]   20 	bra	L2
                             21 	.globl	_main
   0404                      22 _main:
   0404 BD 03 E4      [ 8]   23 	jsr	_run_game
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri May  2 23:13:12 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  2 L2                 000C R   |     ___Wait_Recal      **** GX
    _clk_init          **** GX  |     _clk_update        **** GX
    _lvl_init          **** GX  |   2 _main              0020 GR
    _map_calculate     **** GX  |     _map_draw_road     **** GX
    _map_init          **** GX  |     _player_draw       **** GX
    _player_handle     **** GX  |     _player_init       **** GX
  2 _run_game          0000 GR

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri May  2 23:13:12 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size   23   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

