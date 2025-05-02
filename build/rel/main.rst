                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	main.c
                              6 	.area	.text
                              7 	.globl	_run_game
   0377                       8 _run_game:
   0377 BD 00 61      [ 8]    9 	jsr	_clk_init
   037A BD 00 7A      [ 8]   10 	jsr	_lvl_init
   037D                      11 L2:
   037D BD F1 92      [ 8]   12 	jsr	___Wait_Recal
   0380 BD 00 65      [ 8]   13 	jsr	_clk_update
   0383 BD 00 ED      [ 8]   14 	jsr	_map_draw_road
   0386 BD 02 EB      [ 8]   15 	jsr	_player_handle_input
   0389 F6 C8 82      [ 5]   16 	ldb	_lvl_speed
   038C 34 04         [ 6]   17 	pshs	b
   038E C6 3C         [ 2]   18 	ldb	#60
   0390 E7 E2         [ 6]   19 	stb	,-s
   0392 C6 78         [ 2]   20 	ldb	#120
   0394 BD 03 C0      [ 8]   21 	jsr	_print_unsigned_int
   0397 32 62         [ 5]   22 	leas	2,s
   0399 BD 03 47      [ 8]   23 	jsr	_player_draw
   039C 20 DF         [ 3]   24 	bra	L2
                             25 	.globl	_main
   039E                      26 _main:
   039E BD 03 77      [ 8]   27 	jsr	_run_game
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri May  2 21:41:29 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  2 L2                 0006 R   |     ___Wait_Recal      **** GX
    _clk_init          **** GX  |     _clk_update        **** GX
    _lvl_init          **** GX  |     _lvl_speed         **** GX
  2 _main              0027 GR  |     _map_draw_road     **** GX
    _player_draw       **** GX  |     _player_handle     **** GX
    _print_unsigne     **** GX  |   2 _run_game          0000 GR

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri May  2 21:41:29 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size   2A   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

