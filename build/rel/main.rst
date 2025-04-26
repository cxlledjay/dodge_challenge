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
   0091                      50 _calculate_animation:
   0091 F6 C8 83      [ 5]   51 	ldb	_temp_time
   0094 5D            [ 2]   52 	tstb
   0095 26 19         [ 3]   53 	bne	L6
   0097 F6 C8 81      [ 5]   54 	ldb	_temp_steps
   009A 5C            [ 2]   55 	incb
   009B F7 C8 81      [ 5]   56 	stb	_temp_steps
   009E F6 C8 81      [ 5]   57 	ldb	_temp_steps
   00A1 C1 03         [ 2]   58 	cmpb	#3	;cmpqi:
   00A3 26 03         [ 3]   59 	bne	L7
   00A5 7F C8 81      [ 7]   60 	clr	_temp_steps
   00A8                      61 L7:
   00A8 F6 C8 82      [ 5]   62 	ldb	_temp_speed
   00AB F7 C8 83      [ 5]   63 	stb	_temp_time
   00AE 20 07         [ 3]   64 	bra	L9
   00B0                      65 L6:
   00B0 F6 C8 83      [ 5]   66 	ldb	_temp_time
   00B3 5A            [ 2]   67 	decb
   00B4 F7 C8 83      [ 5]   68 	stb	_temp_time
   00B7                      69 L9:
   00B7 39            [ 5]   70 	rts
                             71 	.globl	_draw_road
   00B8                      72 _draw_road:
   00B8 32 76         [ 5]   73 	leas	-10,s
   00BA BD F2 A5      [ 8]   74 	jsr	___Intensity_5F
   00BD BD 00 91      [ 8]   75 	jsr	_calculate_animation
   00C0 BD F3 54      [ 8]   76 	jsr	___Reset0Ref
   00C3 C6 7F         [ 2]   77 	ldb	#127
   00C5 D7 04         [ 4]   78 	stb	*_dp_VIA_t1_cnt_lo
   00C7 C6 24         [ 2]   79 	ldb	#36
   00C9 E7 E2         [ 6]   80 	stb	,-s
   00CB C6 F1         [ 2]   81 	ldb	#-15
   00CD BD 04 6A      [ 8]   82 	jsr	__Moveto_d
   00D0 32 61         [ 5]   83 	leas	1,s
   00D2 C6 FF         [ 2]   84 	ldb	#-1
   00D4 D7 04         [ 4]   85 	stb	*_dp_VIA_t1_cnt_lo
   00D6 C6 B0         [ 2]   86 	ldb	#-80
   00D8 E7 E2         [ 6]   87 	stb	,-s
   00DA C6 CC         [ 2]   88 	ldb	#-52
   00DC BD 04 65      [ 8]   89 	jsr	__Draw_Line_d
   00DF 32 61         [ 5]   90 	leas	1,s
   00E1 BD F3 54      [ 8]   91 	jsr	___Reset0Ref
   00E4 C6 7F         [ 2]   92 	ldb	#127
   00E6 D7 04         [ 4]   93 	stb	*_dp_VIA_t1_cnt_lo
   00E8 F6 C8 81      [ 5]   94 	ldb	_temp_steps
   00EB C1 02         [ 2]   95 	cmpb	#2	;cmpqi:
   00ED 26 23         [ 3]   96 	bne	L11
   00EF C6 24         [ 2]   97 	ldb	#36
   00F1 E7 E2         [ 6]   98 	stb	,-s
   00F3 C6 FB         [ 2]   99 	ldb	#-5
   00F5 BD 04 6A      [ 8]  100 	jsr	__Moveto_d
   00F8 32 61         [ 5]  101 	leas	1,s
   00FA C6 FC         [ 2]  102 	ldb	#-4
   00FC E7 E2         [ 6]  103 	stb	,-s
   00FE C6 FF         [ 2]  104 	ldb	#-1
   0100 BD 04 65      [ 8]  105 	jsr	__Draw_Line_d
   0103 32 61         [ 5]  106 	leas	1,s
   0105 C6 FC         [ 2]  107 	ldb	#-4
   0107 E7 E2         [ 6]  108 	stb	,-s
   0109 C6 FF         [ 2]  109 	ldb	#-1
   010B BD 04 6A      [ 8]  110 	jsr	__Moveto_d
   010E 32 61         [ 5]  111 	leas	1,s
   0110 20 2B         [ 3]  112 	bra	L12
   0112                     113 L11:
   0112 F6 C8 81      [ 5]  114 	ldb	_temp_steps
   0115 E7 61         [ 5]  115 	stb	1,s
   0117 C6 FB         [ 2]  116 	ldb	#-5
   0119 E7 E4         [ 4]  117 	stb	,s
   011B E6 E4         [ 4]  118 	ldb	,s
   011D E0 61         [ 5]  119 	subb	1,s
   011F E7 62         [ 5]  120 	stb	2,s
   0121 F6 C8 81      [ 5]  121 	ldb	_temp_steps
   0124 E7 63         [ 5]  122 	stb	3,s
   0126 C6 09         [ 2]  123 	ldb	#9
   0128 E0 63         [ 5]  124 	subb	3,s
   012A 58            [ 2]  125 	aslb
   012B 58            [ 2]  126 	aslb
   012C E7 67         [ 5]  127 	stb	7,s
   012E E6 62         [ 5]  128 	ldb	2,s
   0130 E7 66         [ 5]  129 	stb	6,s
   0132 E6 67         [ 5]  130 	ldb	7,s
   0134 E7 E2         [ 6]  131 	stb	,-s
   0136 E6 67         [ 5]  132 	ldb	7,s
   0138 BD 04 6A      [ 8]  133 	jsr	__Moveto_d
   013B 32 61         [ 5]  134 	leas	1,s
   013D                     135 L12:
   013D 8E 03 71      [ 3]  136 	ldx	#_vectors_road_inner_line_l
   0140 BD F4 10      [ 8]  137 	jsr	___Draw_VLp
   0143 BD F3 54      [ 8]  138 	jsr	___Reset0Ref
   0146 C6 7F         [ 2]  139 	ldb	#127
   0148 D7 04         [ 4]  140 	stb	*_dp_VIA_t1_cnt_lo
   014A F6 C8 81      [ 5]  141 	ldb	_temp_steps
   014D C1 02         [ 2]  142 	cmpb	#2	;cmpqi:
   014F 26 23         [ 3]  143 	bne	L13
   0151 C6 24         [ 2]  144 	ldb	#36
   0153 E7 E2         [ 6]  145 	stb	,-s
   0155 C6 05         [ 2]  146 	ldb	#5
   0157 BD 04 6A      [ 8]  147 	jsr	__Moveto_d
   015A 32 61         [ 5]  148 	leas	1,s
   015C C6 FC         [ 2]  149 	ldb	#-4
   015E E7 E2         [ 6]  150 	stb	,-s
   0160 C6 01         [ 2]  151 	ldb	#1
   0162 BD 04 65      [ 8]  152 	jsr	__Draw_Line_d
   0165 32 61         [ 5]  153 	leas	1,s
   0167 C6 FC         [ 2]  154 	ldb	#-4
   0169 E7 E2         [ 6]  155 	stb	,-s
   016B C6 01         [ 2]  156 	ldb	#1
   016D BD 04 6A      [ 8]  157 	jsr	__Moveto_d
   0170 32 61         [ 5]  158 	leas	1,s
   0172 20 27         [ 3]  159 	bra	L14
   0174                     160 L13:
   0174 F6 C8 81      [ 5]  161 	ldb	_temp_steps
   0177 E7 E4         [ 4]  162 	stb	,s
   0179 E6 E4         [ 4]  163 	ldb	,s
   017B CB 05         [ 2]  164 	addb	#5
   017D E7 64         [ 5]  165 	stb	4,s
   017F F6 C8 81      [ 5]  166 	ldb	_temp_steps
   0182 E7 65         [ 5]  167 	stb	5,s
   0184 C6 09         [ 2]  168 	ldb	#9
   0186 E0 65         [ 5]  169 	subb	5,s
   0188 58            [ 2]  170 	aslb
   0189 58            [ 2]  171 	aslb
   018A E7 69         [ 5]  172 	stb	9,s
   018C E6 64         [ 5]  173 	ldb	4,s
   018E E7 68         [ 5]  174 	stb	8,s
   0190 E6 69         [ 5]  175 	ldb	9,s
   0192 E7 E2         [ 6]  176 	stb	,-s
   0194 E6 69         [ 5]  177 	ldb	9,s
   0196 BD 04 6A      [ 8]  178 	jsr	__Moveto_d
   0199 32 61         [ 5]  179 	leas	1,s
   019B                     180 L14:
   019B 8E 03 A5      [ 3]  181 	ldx	#_vectors_road_inner_line_r
   019E BD F4 10      [ 8]  182 	jsr	___Draw_VLp
   01A1 BD F3 54      [ 8]  183 	jsr	___Reset0Ref
   01A4 C6 7F         [ 2]  184 	ldb	#127
   01A6 D7 04         [ 4]  185 	stb	*_dp_VIA_t1_cnt_lo
   01A8 C6 24         [ 2]  186 	ldb	#36
   01AA E7 E2         [ 6]  187 	stb	,-s
   01AC C6 0F         [ 2]  188 	ldb	#15
   01AE BD 04 6A      [ 8]  189 	jsr	__Moveto_d
   01B1 32 61         [ 5]  190 	leas	1,s
   01B3 C6 FF         [ 2]  191 	ldb	#-1
   01B5 D7 04         [ 4]  192 	stb	*_dp_VIA_t1_cnt_lo
   01B7 C6 B0         [ 2]  193 	ldb	#-80
   01B9 E7 E2         [ 6]  194 	stb	,-s
   01BB C6 34         [ 2]  195 	ldb	#52
   01BD BD 04 65      [ 8]  196 	jsr	__Draw_Line_d
   01C0 32 61         [ 5]  197 	leas	1,s
   01C2 32 6A         [ 5]  198 	leas	10,s
   01C4 39            [ 5]  199 	rts
                            200 	.globl	_draw_debug_car
   01C5                     201 _draw_debug_car:
   01C5 BD F3 54      [ 8]  202 	jsr	___Reset0Ref
   01C8 C6 7F         [ 2]  203 	ldb	#127
   01CA D7 04         [ 4]  204 	stb	*_dp_VIA_t1_cnt_lo
   01CC 6F E2         [ 8]  205 	clr	,-s
   01CE 5F            [ 2]  206 	clrb
   01CF BD 04 6A      [ 8]  207 	jsr	__Moveto_d
   01D2 32 61         [ 5]  208 	leas	1,s
   01D4 F6 C8 82      [ 5]  209 	ldb	_temp_speed
   01D7 86 0A         [ 2]  210 	lda	#10	;umulqihi3
   01D9 3D            [11]  211 	mul
                            212 		;movlsbqihi: D->B
   01DA CB 32         [ 2]  213 	addb	#50
   01DC D7 04         [ 4]  214 	stb	*_dp_VIA_t1_cnt_lo
   01DE 8E 03 D9      [ 3]  215 	ldx	#_vectors_debug_car
   01E1 BD F4 10      [ 8]  216 	jsr	___Draw_VLp
   01E4 39            [ 5]  217 	rts
                            218 	.globl	_lookup_player_lane_x_pos
   01E5                     219 _lookup_player_lane_x_pos:
   01E5 B9                  220 	.byte	-71
   01E6 00                  221 	.byte	0
   01E7 47                  222 	.byte	71
                            223 	.globl	_main
   01E8                     224 _main:
   01E8 32 7F         [ 5]  225 	leas	-1,s
   01EA                     226 L26:
   01EA BD F1 92      [ 8]  227 	jsr	___Wait_Recal
   01ED BD 00 B8      [ 8]  228 	jsr	_draw_road
   01F0 BD F1 BA      [ 8]  229 	jsr	___Read_Btns
   01F3 F6 C8 11      [ 5]  230 	ldb	_Vec_Buttons
   01F6 C4 01         [ 2]  231 	andb	#1
   01F8 5D            [ 2]  232 	tstb
   01F9 27 07         [ 3]  233 	beq	L19
   01FB C6 FF         [ 2]  234 	ldb	#-1
   01FD BD 00 61      [ 8]  235 	jsr	_change_lane
   0200 20 0D         [ 3]  236 	bra	L20
   0202                     237 L19:
   0202 F6 C8 11      [ 5]  238 	ldb	_Vec_Buttons
   0205 C4 04         [ 2]  239 	andb	#4
   0207 5D            [ 2]  240 	tstb
   0208 27 05         [ 3]  241 	beq	L20
   020A C6 01         [ 2]  242 	ldb	#1
   020C BD 00 61      [ 8]  243 	jsr	_change_lane
   020F                     244 L20:
   020F F6 C8 11      [ 5]  245 	ldb	_Vec_Buttons
   0212 C4 02         [ 2]  246 	andb	#2
   0214 5D            [ 2]  247 	tstb
   0215 27 17         [ 3]  248 	beq	L21
   0217 F6 C8 82      [ 5]  249 	ldb	_temp_speed
   021A C1 01         [ 2]  250 	cmpb	#1	;cmpqi:
   021C 26 07         [ 3]  251 	bne	L22
   021E C6 32         [ 2]  252 	ldb	#50
   0220 F7 C8 82      [ 5]  253 	stb	_temp_speed
   0223 20 26         [ 3]  254 	bra	L24
   0225                     255 L22:
   0225 F6 C8 82      [ 5]  256 	ldb	_temp_speed
   0228 5A            [ 2]  257 	decb
   0229 F7 C8 82      [ 5]  258 	stb	_temp_speed
   022C 20 1D         [ 3]  259 	bra	L24
   022E                     260 L21:
   022E F6 C8 11      [ 5]  261 	ldb	_Vec_Buttons
   0231 C4 08         [ 2]  262 	andb	#8
   0233 5D            [ 2]  263 	tstb
   0234 27 15         [ 3]  264 	beq	L24
   0236 F6 C8 82      [ 5]  265 	ldb	_temp_speed
   0239 C1 32         [ 2]  266 	cmpb	#50	;cmpqi:
   023B 26 07         [ 3]  267 	bne	L25
   023D C6 01         [ 2]  268 	ldb	#1
   023F F7 C8 82      [ 5]  269 	stb	_temp_speed
   0242 20 07         [ 3]  270 	bra	L24
   0244                     271 L25:
   0244 F6 C8 82      [ 5]  272 	ldb	_temp_speed
   0247 5C            [ 2]  273 	incb
   0248 F7 C8 82      [ 5]  274 	stb	_temp_speed
   024B                     275 L24:
   024B F6 C8 80      [ 5]  276 	ldb	_player_lane
   024E 34 04         [ 6]  277 	pshs	b
   0250 C6 B0         [ 2]  278 	ldb	#-80
   0252 E7 E2         [ 6]  279 	stb	,-s
   0254 C6 78         [ 2]  280 	ldb	#120
   0256 BD 04 09      [ 8]  281 	jsr	_print_unsigned_int
   0259 32 62         [ 5]  282 	leas	2,s
   025B F6 C8 82      [ 5]  283 	ldb	_temp_speed
   025E 34 04         [ 6]  284 	pshs	b
   0260 C6 3C         [ 2]  285 	ldb	#60
   0262 E7 E2         [ 6]  286 	stb	,-s
   0264 C6 78         [ 2]  287 	ldb	#120
   0266 BD 04 09      [ 8]  288 	jsr	_print_unsigned_int
   0269 32 62         [ 5]  289 	leas	2,s
   026B BD F2 A5      [ 8]  290 	jsr	___Intensity_5F
   026E BD F3 54      [ 8]  291 	jsr	___Reset0Ref
   0271 C6 7F         [ 2]  292 	ldb	#127
   0273 D7 04         [ 4]  293 	stb	*_dp_VIA_t1_cnt_lo
   0275 F6 C8 80      [ 5]  294 	ldb	_player_lane
   0278 4F            [ 2]  295 	clra		;zero_extendqihi: R:b -> R:d
   0279 1F 01         [ 6]  296 	tfr	d,x
   027B E6 89 01 E5   [ 8]  297 	ldb	_lookup_player_lane_x_pos,x
   027F E7 E4         [ 4]  298 	stb	,s
   0281 C6 90         [ 2]  299 	ldb	#-112
   0283 E7 E2         [ 6]  300 	stb	,-s
   0285 E6 61         [ 5]  301 	ldb	1,s
   0287 BD 04 6A      [ 8]  302 	jsr	__Moveto_d
   028A 32 61         [ 5]  303 	leas	1,s
   028C C6 40         [ 2]  304 	ldb	#64
   028E D7 04         [ 4]  305 	stb	*_dp_VIA_t1_cnt_lo
   0290 8E 02 E8      [ 3]  306 	ldx	#_vectors_player
   0293 BD F4 10      [ 8]  307 	jsr	___Draw_VLp
   0296 16 FF 51      [ 5]  308 	lbra	L26
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Sat Apr 26 23:41:18 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L11                00B1 R   |   3 L12                00DC R
  3 L13                0113 R   |   3 L14                013A R
  3 L19                01A1 R   |   3 L2                 001A R
  3 L20                01AE R   |   3 L21                01CD R
  3 L22                01C4 R   |   3 L24                01EA R
  3 L25                01E3 R   |   3 L26                0189 R
  3 L4                 002D R   |   3 L6                 004F R
  3 L7                 0047 R   |   3 L9                 0056 R
    _Vec_Buttons       **** GX  |     __Draw_Line_d      **** GX
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Read_Btns       **** GX
    ___Reset0Ref       **** GX  |     ___Wait_Recal      **** GX
  3 _calculate_ani     0030 GR  |   3 _change_lane       0000 GR
    _dp_VIA_t1_cnt     **** GX  |   3 _draw_debug_ca     0164 GR
  3 _draw_road         0057 GR  |   3 _lookup_player     0184 GR
  3 _main              0187 GR  |   2 _player_lane       0000 GR
    _print_unsigne     **** GX  |   2 _temp_speed        0002 GR
  2 _temp_steps        0001 GR  |   2 _temp_time         0003 GR
    _vectors_debug     **** GX  |     _vectors_playe     **** GX
    _vectors_road_     **** GX  |     _vectors_road_     **** GX

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Sat Apr 26 23:41:18 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .data            size    4   flags  100
   3 .text            size  238   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

