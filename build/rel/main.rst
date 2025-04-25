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
                             38 	.globl	_draw_road
   0091                      39 _draw_road:
   0091 BD F2 A5      [ 8]   40 	jsr	___Intensity_5F
   0094 BD F3 54      [ 8]   41 	jsr	___Reset0Ref
   0097 C6 7F         [ 2]   42 	ldb	#127
   0099 D7 04         [ 4]   43 	stb	*_dp_VIA_t1_cnt_lo
   009B C6 24         [ 2]   44 	ldb	#36
   009D E7 E2         [ 6]   45 	stb	,-s
   009F C6 80         [ 2]   46 	ldb	#-128
   00A1 BD 02 ED      [ 8]   47 	jsr	__Moveto_d
   00A4 32 61         [ 5]   48 	leas	1,s
   00A6 C6 FF         [ 2]   49 	ldb	#-1
   00A8 D7 04         [ 4]   50 	stb	*_dp_VIA_t1_cnt_lo
   00AA 8E 02 5D      [ 3]   51 	ldx	#_vectors_horizon
   00AD BD F4 10      [ 8]   52 	jsr	___Draw_VLp
   00B0 BD F3 54      [ 8]   53 	jsr	___Reset0Ref
   00B3 C6 7F         [ 2]   54 	ldb	#127
   00B5 D7 04         [ 4]   55 	stb	*_dp_VIA_t1_cnt_lo
   00B7 C6 24         [ 2]   56 	ldb	#36
   00B9 E7 E2         [ 6]   57 	stb	,-s
   00BB C6 F1         [ 2]   58 	ldb	#-15
   00BD BD 02 ED      [ 8]   59 	jsr	__Moveto_d
   00C0 32 61         [ 5]   60 	leas	1,s
   00C2 C6 FF         [ 2]   61 	ldb	#-1
   00C4 D7 04         [ 4]   62 	stb	*_dp_VIA_t1_cnt_lo
   00C6 8E 02 61      [ 3]   63 	ldx	#_vectors_road_outer_line_l
   00C9 BD F4 10      [ 8]   64 	jsr	___Draw_VLp
   00CC BD F3 54      [ 8]   65 	jsr	___Reset0Ref
   00CF C6 7F         [ 2]   66 	ldb	#127
   00D1 D7 04         [ 4]   67 	stb	*_dp_VIA_t1_cnt_lo
   00D3 C6 24         [ 2]   68 	ldb	#36
   00D5 E7 E2         [ 6]   69 	stb	,-s
   00D7 C6 FB         [ 2]   70 	ldb	#-5
   00D9 BD 02 ED      [ 8]   71 	jsr	__Moveto_d
   00DC 32 61         [ 5]   72 	leas	1,s
   00DE C6 FF         [ 2]   73 	ldb	#-1
   00E0 D7 04         [ 4]   74 	stb	*_dp_VIA_t1_cnt_lo
   00E2 8E 02 65      [ 3]   75 	ldx	#_vectors_road_inner_line_l
   00E5 BD F4 10      [ 8]   76 	jsr	___Draw_VLp
   00E8 BD F3 54      [ 8]   77 	jsr	___Reset0Ref
   00EB C6 7F         [ 2]   78 	ldb	#127
   00ED D7 04         [ 4]   79 	stb	*_dp_VIA_t1_cnt_lo
   00EF C6 24         [ 2]   80 	ldb	#36
   00F1 E7 E2         [ 6]   81 	stb	,-s
   00F3 C6 05         [ 2]   82 	ldb	#5
   00F5 BD 02 ED      [ 8]   83 	jsr	__Moveto_d
   00F8 32 61         [ 5]   84 	leas	1,s
   00FA C6 FF         [ 2]   85 	ldb	#-1
   00FC D7 04         [ 4]   86 	stb	*_dp_VIA_t1_cnt_lo
   00FE 8E 02 69      [ 3]   87 	ldx	#_vectors_road_inner_line_r
   0101 BD F4 10      [ 8]   88 	jsr	___Draw_VLp
   0104 BD F3 54      [ 8]   89 	jsr	___Reset0Ref
   0107 C6 7F         [ 2]   90 	ldb	#127
   0109 D7 04         [ 4]   91 	stb	*_dp_VIA_t1_cnt_lo
   010B C6 24         [ 2]   92 	ldb	#36
   010D E7 E2         [ 6]   93 	stb	,-s
   010F C6 0F         [ 2]   94 	ldb	#15
   0111 BD 02 ED      [ 8]   95 	jsr	__Moveto_d
   0114 32 61         [ 5]   96 	leas	1,s
   0116 C6 FF         [ 2]   97 	ldb	#-1
   0118 D7 04         [ 4]   98 	stb	*_dp_VIA_t1_cnt_lo
   011A 8E 02 6D      [ 3]   99 	ldx	#_vectors_road_outer_line_r
   011D BD F4 10      [ 8]  100 	jsr	___Draw_VLp
   0120 39            [ 5]  101 	rts
                            102 	.globl	_lookup_player_lane_x_pos
   0121                     103 _lookup_player_lane_x_pos:
   0121 B9                  104 	.byte	-71
   0122 00                  105 	.byte	0
   0123 47                  106 	.byte	71
                            107 	.globl	_main
   0124                     108 _main:
   0124 32 7F         [ 5]  109 	leas	-1,s
   0126                     110 L10:
   0126 BD F1 92      [ 8]  111 	jsr	___Wait_Recal
   0129 BD 00 91      [ 8]  112 	jsr	_draw_road
   012C BD F1 BA      [ 8]  113 	jsr	___Read_Btns
   012F F6 C8 11      [ 5]  114 	ldb	_Vec_Buttons
   0132 C4 01         [ 2]  115 	andb	#1
   0134 5D            [ 2]  116 	tstb
   0135 27 07         [ 3]  117 	beq	L8
   0137 C6 FF         [ 2]  118 	ldb	#-1
   0139 BD 00 61      [ 8]  119 	jsr	_change_lane
   013C 20 0D         [ 3]  120 	bra	L9
   013E                     121 L8:
   013E F6 C8 11      [ 5]  122 	ldb	_Vec_Buttons
   0141 C4 04         [ 2]  123 	andb	#4
   0143 5D            [ 2]  124 	tstb
   0144 27 05         [ 3]  125 	beq	L9
   0146 C6 01         [ 2]  126 	ldb	#1
   0148 BD 00 61      [ 8]  127 	jsr	_change_lane
   014B                     128 L9:
   014B F6 C8 80      [ 5]  129 	ldb	_player_lane
   014E 34 04         [ 6]  130 	pshs	b
   0150 C6 B0         [ 2]  131 	ldb	#-80
   0152 E7 E2         [ 6]  132 	stb	,-s
   0154 C6 78         [ 2]  133 	ldb	#120
   0156 BD 02 91      [ 8]  134 	jsr	_print_unsigned_int
   0159 32 62         [ 5]  135 	leas	2,s
   015B BD F2 A5      [ 8]  136 	jsr	___Intensity_5F
   015E BD F3 54      [ 8]  137 	jsr	___Reset0Ref
   0161 C6 7F         [ 2]  138 	ldb	#127
   0163 D7 04         [ 4]  139 	stb	*_dp_VIA_t1_cnt_lo
   0165 F6 C8 80      [ 5]  140 	ldb	_player_lane
   0168 4F            [ 2]  141 	clra		;zero_extendqihi: R:b -> R:d
   0169 1F 01         [ 6]  142 	tfr	d,x
   016B E6 89 01 21   [ 8]  143 	ldb	_lookup_player_lane_x_pos,x
   016F E7 E4         [ 4]  144 	stb	,s
   0171 C6 90         [ 2]  145 	ldb	#-112
   0173 E7 E2         [ 6]  146 	stb	,-s
   0175 E6 61         [ 5]  147 	ldb	1,s
   0177 BD 02 ED      [ 8]  148 	jsr	__Moveto_d
   017A 32 61         [ 5]  149 	leas	1,s
   017C C6 40         [ 2]  150 	ldb	#64
   017E D7 04         [ 4]  151 	stb	*_dp_VIA_t1_cnt_lo
   0180 8E 01 D8      [ 3]  152 	ldx	#_vectors_player
   0183 BD F4 10      [ 8]  153 	jsr	___Draw_VLp
   0186 16 FF 9D      [ 5]  154 	lbra	L10
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Apr 25 23:10:58 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                00C5 R   |   3 L2                 001A R
  3 L4                 002D R   |   3 L8                 00DD R
  3 L9                 00EA R   |     _Vec_Buttons       **** GX
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Read_Btns       **** GX
    ___Reset0Ref       **** GX  |     ___Wait_Recal      **** GX
  3 _change_lane       0000 GR  |     _dp_VIA_t1_cnt     **** GX
  3 _draw_road         0030 GR  |   3 _lookup_player     00C0 GR
  3 _main              00C3 GR  |   2 _player_lane       0000 GR
    _print_unsigne     **** GX  |     _vectors_horiz     **** GX
    _vectors_playe     **** GX  |     _vectors_road_     **** GX
    _vectors_road_     **** GX  |     _vectors_road_     **** GX
    _vectors_road_     **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri Apr 25 23:10:58 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .data            size    1   flags  100
   3 .text            size  128   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

