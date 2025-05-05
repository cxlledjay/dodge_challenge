                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	main.c
                              6 	.area	.text
                              7 	.globl	_run_game
   0796                       8 _run_game:
   0796 BD 00 60      [ 8]    9 	jsr	_clk_init
   0799 BD 02 07      [ 8]   10 	jsr	_lvl_init
   079C BD 02 80      [ 8]   11 	jsr	_map_init
   079F BD 06 28      [ 8]   12 	jsr	_player_init
   07A2                      13 L2:
   07A2 BD F1 92      [ 8]   14 	jsr	___Wait_Recal
   07A5 BD 00 6A      [ 8]   15 	jsr	_clk_update
   07A8 BD 02 84      [ 8]   16 	jsr	_map_calculate_animation
   07AB BD 02 C8      [ 8]   17 	jsr	_map_draw_road
   07AE BD 06 4D      [ 8]   18 	jsr	_player_handle_input
   07B1 BD 06 C6      [ 8]   19 	jsr	_player_draw
   07B4 BD 07 04      [ 8]   20 	jsr	_score_draw
   07B7 20 E9         [ 3]   21 	bra	L2
                             22 	.globl	_main
   07B9                      23 _main:
   07B9 BD 07 96      [ 8]   24 	jsr	_run_game
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Mon May  5 19:02:42 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  2 L2                 000C R   |     ___Wait_Recal      **** GX
    _clk_init          **** GX  |     _clk_update        **** GX
    _lvl_init          **** GX  |   2 _main              0023 GR
    _map_calculate     **** GX  |     _map_draw_road     **** GX
    _map_init          **** GX  |     _player_draw       **** GX
    _player_handle     **** GX  |     _player_init       **** GX
  2 _run_game          0000 GR  |     _score_draw        **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Mon May  5 19:02:42 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size   26   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

