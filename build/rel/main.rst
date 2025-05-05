                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	main.c
                              6 	.area	.text
                              7 	.globl	_run_game
   08AC                       8 _run_game:
   08AC BD 00 60      [ 8]    9 	jsr	_clk_init
   08AF BD 02 20      [ 8]   10 	jsr	_lvl_init
   08B2 BD 02 99      [ 8]   11 	jsr	_map_init
   08B5 BD 06 41      [ 8]   12 	jsr	_player_init
   08B8                      13 L2:
   08B8 BD F1 92      [ 8]   14 	jsr	___Wait_Recal
   08BB BD 00 6A      [ 8]   15 	jsr	_clk_update
   08BE BD 02 9D      [ 8]   16 	jsr	_map_calculate_animation
   08C1 BD 02 E1      [ 8]   17 	jsr	_map_draw_road
   08C4 BD 06 66      [ 8]   18 	jsr	_player_handle_input
   08C7 BD 06 DF      [ 8]   19 	jsr	_player_draw
   08CA BD 08 15      [ 8]   20 	jsr	_score_draw
   08CD 20 E9         [ 3]   21 	bra	L2
                             22 	.globl	_main
   08CF                      23 _main:
   08CF BD 08 AC      [ 8]   24 	jsr	_run_game
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Mon May  5 19:48:08 2025

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
Hexadecimal [16-Bits]                                 Mon May  5 19:48:08 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size   26   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

