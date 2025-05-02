                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	map.c
                              6 	.globl	_vl_misc_roadline_left
                              7 	.area	.text
   008D                       8 _vl_misc_roadline_left:
   008D FF                    9 	.byte	-1
   008E FC                   10 	.byte	-4
   008F FF                   11 	.byte	-1
   0090 00                   12 	.byte	0
   0091 FC                   13 	.byte	-4
   0092 FF                   14 	.byte	-1
   0093 FF                   15 	.byte	-1
   0094 FC                   16 	.byte	-4
   0095 FF                   17 	.byte	-1
   0096 00                   18 	.byte	0
   0097 FC                   19 	.byte	-4
   0098 FF                   20 	.byte	-1
   0099 FF                   21 	.byte	-1
   009A F8                   22 	.byte	-8
   009B FE                   23 	.byte	-2
   009C 00                   24 	.byte	0
   009D F8                   25 	.byte	-8
   009E FE                   26 	.byte	-2
   009F FF                   27 	.byte	-1
   00A0 F8                   28 	.byte	-8
   00A1 FE                   29 	.byte	-2
   00A2 00                   30 	.byte	0
   00A3 F8                   31 	.byte	-8
   00A4 FE                   32 	.byte	-2
   00A5 FF                   33 	.byte	-1
   00A6 F4                   34 	.byte	-12
   00A7 FD                   35 	.byte	-3
   00A8 00                   36 	.byte	0
   00A9 F4                   37 	.byte	-12
   00AA FD                   38 	.byte	-3
   00AB FF                   39 	.byte	-1
   00AC F4                   40 	.byte	-12
   00AD FD                   41 	.byte	-3
   00AE 00                   42 	.byte	0
   00AF F4                   43 	.byte	-12
   00B0 FD                   44 	.byte	-3
   00B1 FF                   45 	.byte	-1
   00B2 F0                   46 	.byte	-16
   00B3 FC                   47 	.byte	-4
   00B4 00                   48 	.byte	0
   00B5 F0                   49 	.byte	-16
   00B6 FC                   50 	.byte	-4
   00B7 FF                   51 	.byte	-1
   00B8 F0                   52 	.byte	-16
   00B9 FC                   53 	.byte	-4
   00BA 00                   54 	.byte	0
   00BB F0                   55 	.byte	-16
   00BC FC                   56 	.byte	-4
   00BD FF                   57 	.byte	-1
   00BE EC                   58 	.byte	-20
   00BF FB                   59 	.byte	-5
   00C0                      60 _vl_term_0_35:
   00C0 01                   61 	.byte	1
                             62 	.globl	_vl_misc_roadline_right
   00C1                      63 _vl_misc_roadline_right:
   00C1 FF                   64 	.byte	-1
   00C2 FC                   65 	.byte	-4
   00C3 01                   66 	.byte	1
   00C4 00                   67 	.byte	0
   00C5 FC                   68 	.byte	-4
   00C6 01                   69 	.byte	1
   00C7 FF                   70 	.byte	-1
   00C8 FC                   71 	.byte	-4
   00C9 01                   72 	.byte	1
   00CA 00                   73 	.byte	0
   00CB FC                   74 	.byte	-4
   00CC 01                   75 	.byte	1
   00CD FF                   76 	.byte	-1
   00CE F8                   77 	.byte	-8
   00CF 02                   78 	.byte	2
   00D0 00                   79 	.byte	0
   00D1 F8                   80 	.byte	-8
   00D2 02                   81 	.byte	2
   00D3 FF                   82 	.byte	-1
   00D4 F8                   83 	.byte	-8
   00D5 02                   84 	.byte	2
   00D6 00                   85 	.byte	0
   00D7 F8                   86 	.byte	-8
   00D8 02                   87 	.byte	2
   00D9 FF                   88 	.byte	-1
   00DA F4                   89 	.byte	-12
   00DB 03                   90 	.byte	3
   00DC 00                   91 	.byte	0
   00DD F4                   92 	.byte	-12
   00DE 03                   93 	.byte	3
   00DF FF                   94 	.byte	-1
   00E0 F4                   95 	.byte	-12
   00E1 03                   96 	.byte	3
   00E2 00                   97 	.byte	0
   00E3 F4                   98 	.byte	-12
   00E4 03                   99 	.byte	3
   00E5 FF                  100 	.byte	-1
   00E6 F0                  101 	.byte	-16
   00E7 04                  102 	.byte	4
   00E8 00                  103 	.byte	0
   00E9 F0                  104 	.byte	-16
   00EA 04                  105 	.byte	4
   00EB FF                  106 	.byte	-1
   00EC F0                  107 	.byte	-16
   00ED 04                  108 	.byte	4
   00EE 00                  109 	.byte	0
   00EF F0                  110 	.byte	-16
   00F0 04                  111 	.byte	4
   00F1 FF                  112 	.byte	-1
   00F2 EC                  113 	.byte	-20
   00F3 05                  114 	.byte	5
   00F4                     115 _vl_term_1_59:
   00F4 01                  116 	.byte	1
                            117 	.globl	_local_cnt
                            118 	.area	.data
   C880                     119 _local_cnt:
   C880 00                  120 	.byte	0
                            121 	.globl	_animation_step
   C881                     122 _animation_step:
   C881 00                  123 	.byte	0
                            124 	.area	.text
                            125 	.globl	_map_draw_road
   00F5                     126 _map_draw_road:
   00F5 32 74         [ 5]  127 	leas	-12,s
   00F7 BD F2 A5      [ 8]  128 	jsr	___Intensity_5F
   00FA BD F3 54      [ 8]  129 	jsr	___Reset0Ref
   00FD C6 7F         [ 2]  130 	ldb	#127
   00FF D7 04         [ 4]  131 	stb	*_dp_VIA_t1_cnt_lo
   0101 C6 24         [ 2]  132 	ldb	#36
   0103 E7 E2         [ 6]  133 	stb	,-s
   0105 C6 F1         [ 2]  134 	ldb	#-15
   0107 BD 04 21      [ 8]  135 	jsr	__Moveto_d
   010A 32 61         [ 5]  136 	leas	1,s
   010C C6 FF         [ 2]  137 	ldb	#-1
   010E D7 04         [ 4]  138 	stb	*_dp_VIA_t1_cnt_lo
   0110 C6 B0         [ 2]  139 	ldb	#-80
   0112 E7 E2         [ 6]  140 	stb	,-s
   0114 C6 CC         [ 2]  141 	ldb	#-52
   0116 BD 04 1C      [ 8]  142 	jsr	__Draw_Line_d
   0119 32 61         [ 5]  143 	leas	1,s
   011B F6 C8 86      [ 5]  144 	ldb	_lvl_speed
   011E E7 61         [ 5]  145 	stb	1,s
   0120 C6 0A         [ 2]  146 	ldb	#10
   0122 E0 61         [ 5]  147 	subb	1,s
   0124 E7 67         [ 5]  148 	stb	7,s
   0126 F6 C8 80      [ 5]  149 	ldb	_local_cnt
   0129 E1 67         [ 5]  150 	cmpb	7,s	;cmpqi:
   012B 26 18         [ 3]  151 	bne	L2
   012D F6 C8 81      [ 5]  152 	ldb	_animation_step
   0130 C1 02         [ 2]  153 	cmpb	#2	;cmpqi:
   0132 26 05         [ 3]  154 	bne	L3
   0134 7F C8 81      [ 7]  155 	clr	_animation_step
   0137 20 07         [ 3]  156 	bra	L4
   0139                     157 L3:
   0139 F6 C8 81      [ 5]  158 	ldb	_animation_step
   013C 5C            [ 2]  159 	incb
   013D F7 C8 81      [ 5]  160 	stb	_animation_step
   0140                     161 L4:
   0140 7F C8 80      [ 7]  162 	clr	_local_cnt
   0143 20 07         [ 3]  163 	bra	L5
   0145                     164 L2:
   0145 F6 C8 80      [ 5]  165 	ldb	_local_cnt
   0148 5C            [ 2]  166 	incb
   0149 F7 C8 80      [ 5]  167 	stb	_local_cnt
   014C                     168 L5:
   014C BD F3 54      [ 8]  169 	jsr	___Reset0Ref
   014F C6 7F         [ 2]  170 	ldb	#127
   0151 D7 04         [ 4]  171 	stb	*_dp_VIA_t1_cnt_lo
   0153 F6 C8 81      [ 5]  172 	ldb	_animation_step
   0156 C1 02         [ 2]  173 	cmpb	#2	;cmpqi:
   0158 26 23         [ 3]  174 	bne	L6
   015A C6 24         [ 2]  175 	ldb	#36
   015C E7 E2         [ 6]  176 	stb	,-s
   015E C6 FB         [ 2]  177 	ldb	#-5
   0160 BD 04 21      [ 8]  178 	jsr	__Moveto_d
   0163 32 61         [ 5]  179 	leas	1,s
   0165 C6 FC         [ 2]  180 	ldb	#-4
   0167 E7 E2         [ 6]  181 	stb	,-s
   0169 C6 FF         [ 2]  182 	ldb	#-1
   016B BD 04 1C      [ 8]  183 	jsr	__Draw_Line_d
   016E 32 61         [ 5]  184 	leas	1,s
   0170 C6 FC         [ 2]  185 	ldb	#-4
   0172 E7 E2         [ 6]  186 	stb	,-s
   0174 C6 FF         [ 2]  187 	ldb	#-1
   0176 BD 04 21      [ 8]  188 	jsr	__Moveto_d
   0179 32 61         [ 5]  189 	leas	1,s
   017B 20 2B         [ 3]  190 	bra	L7
   017D                     191 L6:
   017D F6 C8 81      [ 5]  192 	ldb	_animation_step
   0180 E7 62         [ 5]  193 	stb	2,s
   0182 C6 FB         [ 2]  194 	ldb	#-5
   0184 E7 E4         [ 4]  195 	stb	,s
   0186 E6 E4         [ 4]  196 	ldb	,s
   0188 E0 62         [ 5]  197 	subb	2,s
   018A E7 63         [ 5]  198 	stb	3,s
   018C F6 C8 81      [ 5]  199 	ldb	_animation_step
   018F E7 64         [ 5]  200 	stb	4,s
   0191 C6 09         [ 2]  201 	ldb	#9
   0193 E0 64         [ 5]  202 	subb	4,s
   0195 58            [ 2]  203 	aslb
   0196 58            [ 2]  204 	aslb
   0197 E7 69         [ 5]  205 	stb	9,s
   0199 E6 63         [ 5]  206 	ldb	3,s
   019B E7 68         [ 5]  207 	stb	8,s
   019D E6 69         [ 5]  208 	ldb	9,s
   019F E7 E2         [ 6]  209 	stb	,-s
   01A1 E6 69         [ 5]  210 	ldb	9,s
   01A3 BD 04 21      [ 8]  211 	jsr	__Moveto_d
   01A6 32 61         [ 5]  212 	leas	1,s
   01A8                     213 L7:
   01A8 8E 00 8D      [ 3]  214 	ldx	#_vl_misc_roadline_left
   01AB BD F4 10      [ 8]  215 	jsr	___Draw_VLp
   01AE BD F3 54      [ 8]  216 	jsr	___Reset0Ref
   01B1 C6 7F         [ 2]  217 	ldb	#127
   01B3 D7 04         [ 4]  218 	stb	*_dp_VIA_t1_cnt_lo
   01B5 F6 C8 81      [ 5]  219 	ldb	_animation_step
   01B8 C1 02         [ 2]  220 	cmpb	#2	;cmpqi:
   01BA 26 23         [ 3]  221 	bne	L8
   01BC C6 24         [ 2]  222 	ldb	#36
   01BE E7 E2         [ 6]  223 	stb	,-s
   01C0 C6 05         [ 2]  224 	ldb	#5
   01C2 BD 04 21      [ 8]  225 	jsr	__Moveto_d
   01C5 32 61         [ 5]  226 	leas	1,s
   01C7 C6 FC         [ 2]  227 	ldb	#-4
   01C9 E7 E2         [ 6]  228 	stb	,-s
   01CB C6 01         [ 2]  229 	ldb	#1
   01CD BD 04 1C      [ 8]  230 	jsr	__Draw_Line_d
   01D0 32 61         [ 5]  231 	leas	1,s
   01D2 C6 FC         [ 2]  232 	ldb	#-4
   01D4 E7 E2         [ 6]  233 	stb	,-s
   01D6 C6 01         [ 2]  234 	ldb	#1
   01D8 BD 04 21      [ 8]  235 	jsr	__Moveto_d
   01DB 32 61         [ 5]  236 	leas	1,s
   01DD 20 27         [ 3]  237 	bra	L9
   01DF                     238 L8:
   01DF F6 C8 81      [ 5]  239 	ldb	_animation_step
   01E2 E7 E4         [ 4]  240 	stb	,s
   01E4 E6 E4         [ 4]  241 	ldb	,s
   01E6 CB 05         [ 2]  242 	addb	#5
   01E8 E7 65         [ 5]  243 	stb	5,s
   01EA F6 C8 81      [ 5]  244 	ldb	_animation_step
   01ED E7 66         [ 5]  245 	stb	6,s
   01EF C6 09         [ 2]  246 	ldb	#9
   01F1 E0 66         [ 5]  247 	subb	6,s
   01F3 58            [ 2]  248 	aslb
   01F4 58            [ 2]  249 	aslb
   01F5 E7 6B         [ 5]  250 	stb	11,s
   01F7 E6 65         [ 5]  251 	ldb	5,s
   01F9 E7 6A         [ 5]  252 	stb	10,s
   01FB E6 6B         [ 5]  253 	ldb	11,s
   01FD E7 E2         [ 6]  254 	stb	,-s
   01FF E6 6B         [ 5]  255 	ldb	11,s
   0201 BD 04 21      [ 8]  256 	jsr	__Moveto_d
   0204 32 61         [ 5]  257 	leas	1,s
   0206                     258 L9:
   0206 8E 00 C1      [ 3]  259 	ldx	#_vl_misc_roadline_right
   0209 BD F4 10      [ 8]  260 	jsr	___Draw_VLp
   020C BD F3 54      [ 8]  261 	jsr	___Reset0Ref
   020F C6 7F         [ 2]  262 	ldb	#127
   0211 D7 04         [ 4]  263 	stb	*_dp_VIA_t1_cnt_lo
   0213 C6 24         [ 2]  264 	ldb	#36
   0215 E7 E2         [ 6]  265 	stb	,-s
   0217 C6 0F         [ 2]  266 	ldb	#15
   0219 BD 04 21      [ 8]  267 	jsr	__Moveto_d
   021C 32 61         [ 5]  268 	leas	1,s
   021E C6 FF         [ 2]  269 	ldb	#-1
   0220 D7 04         [ 4]  270 	stb	*_dp_VIA_t1_cnt_lo
   0222 C6 B0         [ 2]  271 	ldb	#-80
   0224 E7 E2         [ 6]  272 	stb	,-s
   0226 C6 34         [ 2]  273 	ldb	#52
   0228 BD 04 1C      [ 8]  274 	jsr	__Draw_Line_d
   022B 32 61         [ 5]  275 	leas	1,s
   022D 32 6C         [ 5]  276 	leas	12,s
   022F 39            [ 5]  277 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri May  2 18:56:42 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  2 L2                 00B8 R   |   2 L3                 00AC R
  2 L4                 00B3 R   |   2 L5                 00BF R
  2 L6                 00F0 R   |   2 L7                 011B R
  2 L8                 0152 R   |   2 L9                 0179 R
    __Draw_Line_d      **** GX  |     __Moveto_d         **** GX
    ___Draw_VLp        **** GX  |     ___Intensity_5     **** GX
    ___Reset0Ref       **** GX  |   3 _animation_ste     0001 GR
    _dp_VIA_t1_cnt     **** GX  |   3 _local_cnt         0000 GR
    _lvl_speed         **** GX  |   2 _map_draw_road     0068 GR
  2 _vl_misc_roadl     0000 GR  |   2 _vl_misc_roadl     0034 GR
  2 _vl_term_0_35      0033 R   |   2 _vl_term_1_59      0067 R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri May  2 18:56:42 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size  1A3   flags  100
   3 .data            size    2   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

