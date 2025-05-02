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
   0152                      12 _change_lane:
   0152 32 7F         [ 5]   13 	leas	-1,s
   0154 E7 E4         [ 4]   14 	stb	,s
   0156 E6 E4         [ 4]   15 	ldb	,s
   0158 C1 01         [ 2]   16 	cmpb	#1	;cmpqi:
   015A 26 10         [ 3]   17 	bne	L2
   015C F6 C8 80      [ 5]   18 	ldb	_player_lane
   015F C1 02         [ 2]   19 	cmpb	#2	;cmpqi:
   0161 27 1C         [ 3]   20 	beq	L4
   0163 F6 C8 80      [ 5]   21 	ldb	_player_lane
   0166 5C            [ 2]   22 	incb
   0167 F7 C8 80      [ 5]   23 	stb	_player_lane
   016A 20 13         [ 3]   24 	bra	L4
   016C                      25 L2:
   016C E6 E4         [ 4]   26 	ldb	,s
   016E C1 FF         [ 2]   27 	cmpb	#-1	;cmpqi:
   0170 26 0D         [ 3]   28 	bne	L4
   0172 F6 C8 80      [ 5]   29 	ldb	_player_lane
   0175 5D            [ 2]   30 	tstb
   0176 27 07         [ 3]   31 	beq	L4
   0178 F6 C8 80      [ 5]   32 	ldb	_player_lane
   017B 5A            [ 2]   33 	decb
   017C F7 C8 80      [ 5]   34 	stb	_player_lane
   017F                      35 L4:
   017F 32 61         [ 5]   36 	leas	1,s
   0181 39            [ 5]   37 	rts
                             38 	.globl	_temp_steps
                             39 	.area	.data
   C881                      40 _temp_steps:
   C881 00                   41 	.byte	0
                             42 	.globl	_temp_speed
   C882                      43 _temp_speed:
   C882 0A                   44 	.byte	10
                             45 	.globl	_temp_time
   C883                      46 _temp_time:
   C883 0A                   47 	.byte	10
                             48 	.area	.text
                             49 	.globl	_calculate_animation
   0182                      50 _calculate_animation:
   0182 F6 C8 83      [ 5]   51 	ldb	_temp_time
   0185 5D            [ 2]   52 	tstb
   0186 26 19         [ 3]   53 	bne	L6
   0188 F6 C8 81      [ 5]   54 	ldb	_temp_steps
   018B 5C            [ 2]   55 	incb
   018C F7 C8 81      [ 5]   56 	stb	_temp_steps
   018F F6 C8 81      [ 5]   57 	ldb	_temp_steps
   0192 C1 03         [ 2]   58 	cmpb	#3	;cmpqi:
   0194 26 03         [ 3]   59 	bne	L7
   0196 7F C8 81      [ 7]   60 	clr	_temp_steps
   0199                      61 L7:
   0199 F6 C8 82      [ 5]   62 	ldb	_temp_speed
   019C F7 C8 83      [ 5]   63 	stb	_temp_time
   019F 20 07         [ 3]   64 	bra	L9
   01A1                      65 L6:
   01A1 F6 C8 83      [ 5]   66 	ldb	_temp_time
   01A4 5A            [ 2]   67 	decb
   01A5 F7 C8 83      [ 5]   68 	stb	_temp_time
   01A8                      69 L9:
   01A8 39            [ 5]   70 	rts
                             71 	.globl	_draw_road
   01A9                      72 _draw_road:
   01A9 32 76         [ 5]   73 	leas	-10,s
   01AB BD F2 A5      [ 8]   74 	jsr	___Intensity_5F
   01AE BD 01 82      [ 8]   75 	jsr	_calculate_animation
   01B1 BD F3 54      [ 8]   76 	jsr	___Reset0Ref
   01B4 C6 7F         [ 2]   77 	ldb	#127
   01B6 D7 04         [ 4]   78 	stb	*_dp_VIA_t1_cnt_lo
   01B8 C6 24         [ 2]   79 	ldb	#36
   01BA E7 E2         [ 6]   80 	stb	,-s
   01BC C6 F1         [ 2]   81 	ldb	#-15
   01BE BD 04 6F      [ 8]   82 	jsr	__Moveto_d
   01C1 32 61         [ 5]   83 	leas	1,s
   01C3 C6 FF         [ 2]   84 	ldb	#-1
   01C5 D7 04         [ 4]   85 	stb	*_dp_VIA_t1_cnt_lo
   01C7 C6 B0         [ 2]   86 	ldb	#-80
   01C9 E7 E2         [ 6]   87 	stb	,-s
   01CB C6 CC         [ 2]   88 	ldb	#-52
   01CD BD 04 6A      [ 8]   89 	jsr	__Draw_Line_d
   01D0 32 61         [ 5]   90 	leas	1,s
   01D2 BD F3 54      [ 8]   91 	jsr	___Reset0Ref
   01D5 C6 7F         [ 2]   92 	ldb	#127
   01D7 D7 04         [ 4]   93 	stb	*_dp_VIA_t1_cnt_lo
   01D9 F6 C8 81      [ 5]   94 	ldb	_temp_steps
   01DC C1 02         [ 2]   95 	cmpb	#2	;cmpqi:
   01DE 26 23         [ 3]   96 	bne	L11
   01E0 C6 24         [ 2]   97 	ldb	#36
   01E2 E7 E2         [ 6]   98 	stb	,-s
   01E4 C6 FB         [ 2]   99 	ldb	#-5
   01E6 BD 04 6F      [ 8]  100 	jsr	__Moveto_d
   01E9 32 61         [ 5]  101 	leas	1,s
   01EB C6 FC         [ 2]  102 	ldb	#-4
   01ED E7 E2         [ 6]  103 	stb	,-s
   01EF C6 FF         [ 2]  104 	ldb	#-1
   01F1 BD 04 6A      [ 8]  105 	jsr	__Draw_Line_d
   01F4 32 61         [ 5]  106 	leas	1,s
   01F6 C6 FC         [ 2]  107 	ldb	#-4
   01F8 E7 E2         [ 6]  108 	stb	,-s
   01FA C6 FF         [ 2]  109 	ldb	#-1
   01FC BD 04 6F      [ 8]  110 	jsr	__Moveto_d
   01FF 32 61         [ 5]  111 	leas	1,s
   0201 20 2B         [ 3]  112 	bra	L12
   0203                     113 L11:
   0203 F6 C8 81      [ 5]  114 	ldb	_temp_steps
   0206 E7 61         [ 5]  115 	stb	1,s
   0208 C6 FB         [ 2]  116 	ldb	#-5
   020A E7 E4         [ 4]  117 	stb	,s
   020C E6 E4         [ 4]  118 	ldb	,s
   020E E0 61         [ 5]  119 	subb	1,s
   0210 E7 62         [ 5]  120 	stb	2,s
   0212 F6 C8 81      [ 5]  121 	ldb	_temp_steps
   0215 E7 63         [ 5]  122 	stb	3,s
   0217 C6 09         [ 2]  123 	ldb	#9
   0219 E0 63         [ 5]  124 	subb	3,s
   021B 58            [ 2]  125 	aslb
   021C 58            [ 2]  126 	aslb
   021D E7 67         [ 5]  127 	stb	7,s
   021F E6 62         [ 5]  128 	ldb	2,s
   0221 E7 66         [ 5]  129 	stb	6,s
   0223 E6 67         [ 5]  130 	ldb	7,s
   0225 E7 E2         [ 6]  131 	stb	,-s
   0227 E6 67         [ 5]  132 	ldb	7,s
   0229 BD 04 6F      [ 8]  133 	jsr	__Moveto_d
   022C 32 61         [ 5]  134 	leas	1,s
   022E                     135 L12:
   022E 8E 03 D2      [ 3]  136 	ldx	#_vectors_road_inner_line_l
   0231 BD F4 10      [ 8]  137 	jsr	___Draw_VLp
   0234 BD F3 54      [ 8]  138 	jsr	___Reset0Ref
   0237 C6 7F         [ 2]  139 	ldb	#127
   0239 D7 04         [ 4]  140 	stb	*_dp_VIA_t1_cnt_lo
   023B F6 C8 81      [ 5]  141 	ldb	_temp_steps
   023E C1 02         [ 2]  142 	cmpb	#2	;cmpqi:
   0240 26 23         [ 3]  143 	bne	L13
   0242 C6 24         [ 2]  144 	ldb	#36
   0244 E7 E2         [ 6]  145 	stb	,-s
   0246 C6 05         [ 2]  146 	ldb	#5
   0248 BD 04 6F      [ 8]  147 	jsr	__Moveto_d
   024B 32 61         [ 5]  148 	leas	1,s
   024D C6 FC         [ 2]  149 	ldb	#-4
   024F E7 E2         [ 6]  150 	stb	,-s
   0251 C6 01         [ 2]  151 	ldb	#1
   0253 BD 04 6A      [ 8]  152 	jsr	__Draw_Line_d
   0256 32 61         [ 5]  153 	leas	1,s
   0258 C6 FC         [ 2]  154 	ldb	#-4
   025A E7 E2         [ 6]  155 	stb	,-s
   025C C6 01         [ 2]  156 	ldb	#1
   025E BD 04 6F      [ 8]  157 	jsr	__Moveto_d
   0261 32 61         [ 5]  158 	leas	1,s
   0263 20 27         [ 3]  159 	bra	L14
   0265                     160 L13:
   0265 F6 C8 81      [ 5]  161 	ldb	_temp_steps
   0268 E7 E4         [ 4]  162 	stb	,s
   026A E6 E4         [ 4]  163 	ldb	,s
   026C CB 05         [ 2]  164 	addb	#5
   026E E7 64         [ 5]  165 	stb	4,s
   0270 F6 C8 81      [ 5]  166 	ldb	_temp_steps
   0273 E7 65         [ 5]  167 	stb	5,s
   0275 C6 09         [ 2]  168 	ldb	#9
   0277 E0 65         [ 5]  169 	subb	5,s
   0279 58            [ 2]  170 	aslb
   027A 58            [ 2]  171 	aslb
   027B E7 69         [ 5]  172 	stb	9,s
   027D E6 64         [ 5]  173 	ldb	4,s
   027F E7 68         [ 5]  174 	stb	8,s
   0281 E6 69         [ 5]  175 	ldb	9,s
   0283 E7 E2         [ 6]  176 	stb	,-s
   0285 E6 69         [ 5]  177 	ldb	9,s
   0287 BD 04 6F      [ 8]  178 	jsr	__Moveto_d
   028A 32 61         [ 5]  179 	leas	1,s
   028C                     180 L14:
   028C 8E 04 06      [ 3]  181 	ldx	#_vectors_road_inner_line_r
   028F BD F4 10      [ 8]  182 	jsr	___Draw_VLp
   0292 BD F3 54      [ 8]  183 	jsr	___Reset0Ref
   0295 C6 7F         [ 2]  184 	ldb	#127
   0297 D7 04         [ 4]  185 	stb	*_dp_VIA_t1_cnt_lo
   0299 C6 24         [ 2]  186 	ldb	#36
   029B E7 E2         [ 6]  187 	stb	,-s
   029D C6 0F         [ 2]  188 	ldb	#15
   029F BD 04 6F      [ 8]  189 	jsr	__Moveto_d
   02A2 32 61         [ 5]  190 	leas	1,s
   02A4 C6 FF         [ 2]  191 	ldb	#-1
   02A6 D7 04         [ 4]  192 	stb	*_dp_VIA_t1_cnt_lo
   02A8 C6 B0         [ 2]  193 	ldb	#-80
   02AA E7 E2         [ 6]  194 	stb	,-s
   02AC C6 34         [ 2]  195 	ldb	#52
   02AE BD 04 6A      [ 8]  196 	jsr	__Draw_Line_d
   02B1 32 61         [ 5]  197 	leas	1,s
   02B3 32 6A         [ 5]  198 	leas	10,s
   02B5 39            [ 5]  199 	rts
                            200 	.globl	_draw_debug_car
   02B6                     201 _draw_debug_car:
   02B6 BD F3 54      [ 8]  202 	jsr	___Reset0Ref
   02B9 C6 7F         [ 2]  203 	ldb	#127
   02BB D7 04         [ 4]  204 	stb	*_dp_VIA_t1_cnt_lo
   02BD 6F E2         [ 8]  205 	clr	,-s
   02BF 5F            [ 2]  206 	clrb
   02C0 BD 04 6F      [ 8]  207 	jsr	__Moveto_d
   02C3 32 61         [ 5]  208 	leas	1,s
   02C5 F6 C8 82      [ 5]  209 	ldb	_temp_speed
   02C8 86 0A         [ 2]  210 	lda	#10	;umulqihi3
   02CA 3D            [11]  211 	mul
                            212 		;movlsbqihi: D->B
   02CB CB 32         [ 2]  213 	addb	#50
   02CD D7 04         [ 4]  214 	stb	*_dp_VIA_t1_cnt_lo
   02CF 8E 04 3A      [ 3]  215 	ldx	#_vectors_debug_car
   02D2 BD F4 10      [ 8]  216 	jsr	___Draw_VLp
   02D5 39            [ 5]  217 	rts
                            218 	.globl	_lookup_player_lane_x_pos
   02D6                     219 _lookup_player_lane_x_pos:
   02D6 B9                  220 	.byte	-71
   02D7 00                  221 	.byte	0
   02D8 47                  222 	.byte	71
                            223 	.globl	_debug_sprites
   02D9                     224 _debug_sprites:
   02D9                     225 L19:
   02D9 BD F2 A5      [ 8]  226 	jsr	___Intensity_5F
   02DC BD F3 54      [ 8]  227 	jsr	___Reset0Ref
   02DF C6 7F         [ 2]  228 	ldb	#127
   02E1 D7 04         [ 4]  229 	stb	*_dp_VIA_t1_cnt_lo
   02E3 6F E2         [ 8]  230 	clr	,-s
   02E5 5F            [ 2]  231 	clrb
   02E6 BD 04 6F      [ 8]  232 	jsr	__Moveto_d
   02E9 32 61         [ 5]  233 	leas	1,s
   02EB C6 FF         [ 2]  234 	ldb	#-1
   02ED D7 04         [ 4]  235 	stb	*_dp_VIA_t1_cnt_lo
   02EF 8E 00 C9      [ 3]  236 	ldx	#_vl_player_mid
   02F2 BD F4 10      [ 8]  237 	jsr	___Draw_VLp
   02F5 20 E2         [ 3]  238 	bra	L19
                            239 	.globl	_main
   02F7                     240 _main:
   02F7 BD 02 D9      [ 8]  241 	jsr	_debug_sprites
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri May  2 15:00:18 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L11                00B1 R   |   3 L12                00DC R
  3 L13                0113 R   |   3 L14                013A R
  3 L19                0187 R   |   3 L2                 001A R
  3 L4                 002D R   |   3 L6                 004F R
  3 L7                 0047 R   |   3 L9                 0056 R
    __Draw_Line_d      **** GX  |     __Moveto_d         **** GX
    ___Draw_VLp        **** GX  |     ___Intensity_5     **** GX
    ___Reset0Ref       **** GX  |   3 _calculate_ani     0030 GR
  3 _change_lane       0000 GR  |   3 _debug_sprites     0187 GR
    _dp_VIA_t1_cnt     **** GX  |   3 _draw_debug_ca     0164 GR
  3 _draw_road         0057 GR  |   3 _lookup_player     0184 GR
  3 _main              01A5 GR  |   2 _player_lane       0000 GR
  2 _temp_speed        0002 GR  |   2 _temp_steps        0001 GR
  2 _temp_time         0003 GR  |     _vectors_debug     **** GX
    _vectors_road_     **** GX  |     _vectors_road_     **** GX
    _vl_player_mid     **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri May  2 15:00:18 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .data            size    4   flags  100
   3 .text            size  1A8   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

