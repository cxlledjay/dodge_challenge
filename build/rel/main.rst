                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	main.c
                              6 	.globl	_player_lane
                              7 	.area	.data
   C880                       8 _player_lane:
   C880 01                    9 	.byte	1
                             10 	.area	.text
                             11 	.globl	_change_lane
   0061                      12 _change_lane:
   0061 32 7F         [ 5]   13 	leas	-1,s
   0063 E7 E4         [ 4]   14 	stb	,s
   0065 E6 E4         [ 4]   15 	ldb	,s
   0067 C1 01         [ 2]   16 	cmpb	#1	;cmpqi:
   0069 26 10         [ 3]   17 	bne	L2
   006B F6 C8 80      [ 5]   18 	ldb	_player_lane
   006E C1 02         [ 2]   19 	cmpb	#2	;cmpqi:
   0070 27 1C         [ 3]   20 	beq	L4
   0072 F6 C8 80      [ 5]   21 	ldb	_player_lane
   0075 5C            [ 2]   22 	incb
   0076 F7 C8 80      [ 5]   23 	stb	_player_lane
   0079 20 13         [ 3]   24 	bra	L4
   007B                      25 L2:
   007B E6 E4         [ 4]   26 	ldb	,s
   007D C1 FF         [ 2]   27 	cmpb	#-1	;cmpqi:
   007F 26 0D         [ 3]   28 	bne	L4
   0081 F6 C8 80      [ 5]   29 	ldb	_player_lane
   0084 5D            [ 2]   30 	tstb
   0085 27 07         [ 3]   31 	beq	L4
   0087 F6 C8 80      [ 5]   32 	ldb	_player_lane
   008A 5A            [ 2]   33 	decb
   008B F7 C8 80      [ 5]   34 	stb	_player_lane
   008E                      35 L4:
   008E 32 61         [ 5]   36 	leas	1,s
   0090 39            [ 5]   37 	rts
                             38 	.globl	_lookup_player_lane_x_pos
   0091                      39 _lookup_player_lane_x_pos:
   0091 D0                   40 	.byte	-48
   0092 00                   41 	.byte	0
   0093 30                   42 	.byte	48
                             43 	.globl	_main
   0094                      44 _main:
   0094 32 7F         [ 5]   45 	leas	-1,s
   0096                      46 L8:
   0096 BD F1 92      [ 8]   47 	jsr	___Wait_Recal
   0099 BD F1 BA      [ 8]   48 	jsr	___Read_Btns
   009C F6 C8 11      [ 5]   49 	ldb	_Vec_Buttons
   009F C4 01         [ 2]   50 	andb	#1
   00A1 5D            [ 2]   51 	tstb
   00A2 27 07         [ 3]   52 	beq	L6
   00A4 C6 FF         [ 2]   53 	ldb	#-1
   00A6 BD 00 61      [ 8]   54 	jsr	_change_lane
   00A9 20 0D         [ 3]   55 	bra	L7
   00AB                      56 L6:
   00AB F6 C8 11      [ 5]   57 	ldb	_Vec_Buttons
   00AE C4 04         [ 2]   58 	andb	#4
   00B0 5D            [ 2]   59 	tstb
   00B1 27 05         [ 3]   60 	beq	L7
   00B3 C6 01         [ 2]   61 	ldb	#1
   00B5 BD 00 61      [ 8]   62 	jsr	_change_lane
   00B8                      63 L7:
   00B8 F6 C8 80      [ 5]   64 	ldb	_player_lane
   00BB 34 04         [ 6]   65 	pshs	b
   00BD C6 B0         [ 2]   66 	ldb	#-80
   00BF E7 E2         [ 6]   67 	stb	,-s
   00C1 C6 78         [ 2]   68 	ldb	#120
   00C3 BD 01 EA      [ 8]   69 	jsr	_print_unsigned_int
   00C6 32 62         [ 5]   70 	leas	2,s
   00C8 BD F2 A5      [ 8]   71 	jsr	___Intensity_5F
   00CB BD F3 54      [ 8]   72 	jsr	___Reset0Ref
   00CE C6 7F         [ 2]   73 	ldb	#127
   00D0 D7 04         [ 4]   74 	stb	*_dp_VIA_t1_cnt_lo
   00D2 F6 C8 80      [ 5]   75 	ldb	_player_lane
   00D5 4F            [ 2]   76 	clra		;zero_extendqihi: R:b -> R:d
   00D6 1F 01         [ 6]   77 	tfr	d,x
   00D8 E6 89 00 91   [ 8]   78 	ldb	_lookup_player_lane_x_pos,x
   00DC E7 E4         [ 4]   79 	stb	,s
   00DE C6 9C         [ 2]   80 	ldb	#-100
   00E0 E7 E2         [ 6]   81 	stb	,-s
   00E2 E6 61         [ 5]   82 	ldb	1,s
   00E4 BD 02 46      [ 8]   83 	jsr	__Moveto_d
   00E7 32 61         [ 5]   84 	leas	1,s
   00E9 C6 40         [ 2]   85 	ldb	#64
   00EB D7 04         [ 4]   86 	stb	*_dp_VIA_t1_cnt_lo
   00ED 8E 01 45      [ 3]   87 	ldx	#_vectors_player
   00F0 BD F4 10      [ 8]   88 	jsr	___Draw_VLp
   00F3 16 FF A0      [ 5]   89 	lbra	L8
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Apr 25 17:08:29 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L2                 001A R   |   3 L4                 002D R
  3 L6                 004A R   |   3 L7                 0057 R
  3 L8                 0035 R   |     _Vec_Buttons       **** GX
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Read_Btns       **** GX
    ___Reset0Ref       **** GX  |     ___Wait_Recal      **** GX
  3 _change_lane       0000 GR  |     _dp_VIA_t1_cnt     **** GX
  3 _lookup_player     0030 GR  |   3 _main              0033 GR
  2 _player_lane       0000 GR  |     _print_unsigne     **** GX
    _vectors_playe     **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri Apr 25 17:08:29 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .data            size    1   flags  100
   3 .text            size   95   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

