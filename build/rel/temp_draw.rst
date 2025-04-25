                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	temp_draw.c
                              6 	.globl	_vectors_man
                              7 	.area	.text
   0189                       8 _vectors_man:
   0189 00                    9 	.byte	0
   018A 30                   10 	.byte	48
   018B F0                   11 	.byte	-16
   018C FF                   12 	.byte	-1
   018D 00                   13 	.byte	0
   018E 20                   14 	.byte	32
   018F FF                   15 	.byte	-1
   0190 E0                   16 	.byte	-32
   0191 00                   17 	.byte	0
   0192 FF                   18 	.byte	-1
   0193 00                   19 	.byte	0
   0194 E0                   20 	.byte	-32
   0195 FF                   21 	.byte	-1
   0196 20                   22 	.byte	32
   0197 00                   23 	.byte	0
   0198 00                   24 	.byte	0
   0199 E0                   25 	.byte	-32
   019A 10                   26 	.byte	16
   019B FF                   27 	.byte	-1
   019C E0                   28 	.byte	-32
   019D 00                   29 	.byte	0
   019E 00                   30 	.byte	0
   019F 10                   31 	.byte	16
   01A0 E0                   32 	.byte	-32
   01A1 FF                   33 	.byte	-1
   01A2 00                   34 	.byte	0
   01A3 40                   35 	.byte	64
   01A4 00                   36 	.byte	0
   01A5 D0                   37 	.byte	-48
   01A6 F0                   38 	.byte	-16
   01A7 FF                   39 	.byte	-1
   01A8 20                   40 	.byte	32
   01A9 F0                   41 	.byte	-16
   01AA FF                   42 	.byte	-1
   01AB E0                   43 	.byte	-32
   01AC F0                   44 	.byte	-16
   01AD 01                   45 	.byte	1
   01AE 00                   46 	.byte	0
   01AF 00                   47 	.byte	0
                             48 	.globl	_vectors_balloon
   01B0                      49 _vectors_balloon:
   01B0 00                   50 	.byte	0
   01B1 19                   51 	.byte	25
   01B2 00                   52 	.byte	0
   01B3 FF                   53 	.byte	-1
   01B4 32                   54 	.byte	50
   01B5 00                   55 	.byte	0
   01B6 FF                   56 	.byte	-1
   01B7 00                   57 	.byte	0
   01B8 F6                   58 	.byte	-10
   01B9 FF                   59 	.byte	-1
   01BA 0A                   60 	.byte	10
   01BB 0A                   61 	.byte	10
   01BC FF                   62 	.byte	-1
   01BD 0A                   63 	.byte	10
   01BE EC                   64 	.byte	-20
   01BF FF                   65 	.byte	-1
   01C0 1E                   66 	.byte	30
   01C1 00                   67 	.byte	0
   01C2 FF                   68 	.byte	-1
   01C3 0A                   69 	.byte	10
   01C4 0A                   70 	.byte	10
   01C5 FF                   71 	.byte	-1
   01C6 00                   72 	.byte	0
   01C7 14                   73 	.byte	20
   01C8 FF                   74 	.byte	-1
   01C9 F6                   75 	.byte	-10
   01CA 0A                   76 	.byte	10
   01CB FF                   77 	.byte	-1
   01CC E2                   78 	.byte	-30
   01CD 00                   79 	.byte	0
   01CE FF                   80 	.byte	-1
   01CF F6                   81 	.byte	-10
   01D0 EC                   82 	.byte	-20
   01D1 FF                   83 	.byte	-1
   01D2 F6                   84 	.byte	-10
   01D3 0A                   85 	.byte	10
   01D4 FF                   86 	.byte	-1
   01D5 00                   87 	.byte	0
   01D6 F6                   88 	.byte	-10
   01D7                      89 _vl_term_0_46:
   01D7 01                   90 	.byte	1
                             91 	.globl	_vectors_player
   01D8                      92 _vectors_player:
   01D8 00                   93 	.byte	0
   01D9 E8                   94 	.byte	-24
   01DA EC                   95 	.byte	-20
   01DB FF                   96 	.byte	-1
   01DC 00                   97 	.byte	0
   01DD EC                   98 	.byte	-20
   01DE FF                   99 	.byte	-1
   01DF 20                  100 	.byte	32
   01E0 00                  101 	.byte	0
   01E1 FF                  102 	.byte	-1
   01E2 00                  103 	.byte	0
   01E3 14                  104 	.byte	20
   01E4 FF                  105 	.byte	-1
   01E5 E0                  106 	.byte	-32
   01E6 00                  107 	.byte	0
   01E7 00                  108 	.byte	0
   01E8 04                  109 	.byte	4
   01E9 00                  110 	.byte	0
   01EA FF                  111 	.byte	-1
   01EB 04                  112 	.byte	4
   01EC 0F                  113 	.byte	15
   01ED 00                  114 	.byte	0
   01EE 00                  115 	.byte	0
   01EF 0A                  116 	.byte	10
   01F0 FF                  117 	.byte	-1
   01F1 FC                  118 	.byte	-4
   01F2 0F                  119 	.byte	15
   01F3 00                  120 	.byte	0
   01F4 FC                  121 	.byte	-4
   01F5 00                  122 	.byte	0
   01F6 FF                  123 	.byte	-1
   01F7 00                  124 	.byte	0
   01F8 14                  125 	.byte	20
   01F9 FF                  126 	.byte	-1
   01FA 20                  127 	.byte	32
   01FB 00                  128 	.byte	0
   01FC FF                  129 	.byte	-1
   01FD 00                  130 	.byte	0
   01FE EC                  131 	.byte	-20
   01FF FF                  132 	.byte	-1
   0200 E0                  133 	.byte	-32
   0201 00                  134 	.byte	0
   0202 00                  135 	.byte	0
   0203 08                  136 	.byte	8
   0204 00                  137 	.byte	0
   0205 FF                  138 	.byte	-1
   0206 00                  139 	.byte	0
   0207 D8                  140 	.byte	-40
   0208 00                  141 	.byte	0
   0209 10                  142 	.byte	16
   020A 00                  143 	.byte	0
   020B FF                  144 	.byte	-1
   020C 04                  145 	.byte	4
   020D 0F                  146 	.byte	15
   020E FF                  147 	.byte	-1
   020F 00                  148 	.byte	0
   0210 0A                  149 	.byte	10
   0211 FF                  150 	.byte	-1
   0212 FC                  151 	.byte	-4
   0213 0F                  152 	.byte	15
   0214 FF                  153 	.byte	-1
   0215 1C                  154 	.byte	28
   0216 F0                  155 	.byte	-16
   0217 FF                  156 	.byte	-1
   0218 00                  157 	.byte	0
   0219 F8                  158 	.byte	-8
   021A 00                  159 	.byte	0
   021B F9                  160 	.byte	-7
   021C 0C                  161 	.byte	12
   021D FF                  162 	.byte	-1
   021E 00                  163 	.byte	0
   021F 0C                  164 	.byte	12
   0220 FF                  165 	.byte	-1
   0221 04                  166 	.byte	4
   0222 FE                  167 	.byte	-2
   0223 FF                  168 	.byte	-1
   0224 00                  169 	.byte	0
   0225 F4                  170 	.byte	-12
   0226 00                  171 	.byte	0
   0227 00                  172 	.byte	0
   0228 F4                  173 	.byte	-12
   0229 FF                  174 	.byte	-1
   022A 00                  175 	.byte	0
   022B F4                  176 	.byte	-12
   022C FF                  177 	.byte	-1
   022D FC                  178 	.byte	-4
   022E FE                  179 	.byte	-2
   022F FF                  180 	.byte	-1
   0230 00                  181 	.byte	0
   0231 0C                  182 	.byte	12
   0232 00                  183 	.byte	0
   0233 07                  184 	.byte	7
   0234 04                  185 	.byte	4
   0235 FF                  186 	.byte	-1
   0236 E4                  187 	.byte	-28
   0237 F0                  188 	.byte	-16
   0238 00                  189 	.byte	0
   0239 08                  190 	.byte	8
   023A F6                  191 	.byte	-10
   023B FF                  192 	.byte	-1
   023C 0A                  193 	.byte	10
   023D 00                  194 	.byte	0
   023E FF                  195 	.byte	-1
   023F 00                  196 	.byte	0
   0240 0F                  197 	.byte	15
   0241 FF                  198 	.byte	-1
   0242 F7                  199 	.byte	-9
   0243 00                  200 	.byte	0
   0244 00                  201 	.byte	0
   0245 00                  202 	.byte	0
   0246 1E                  203 	.byte	30
   0247 FF                  204 	.byte	-1
   0248 09                  205 	.byte	9
   0249 00                  206 	.byte	0
   024A FF                  207 	.byte	-1
   024B 00                  208 	.byte	0
   024C 0F                  209 	.byte	15
   024D FF                  210 	.byte	-1
   024E F6                  211 	.byte	-10
   024F 00                  212 	.byte	0
   0250 00                  213 	.byte	0
   0251 05                  214 	.byte	5
   0252 E7                  215 	.byte	-25
   0253 FF                  216 	.byte	-1
   0254 04                  217 	.byte	4
   0255 FE                  218 	.byte	-2
   0256 FF                  219 	.byte	-1
   0257 00                  220 	.byte	0
   0258 FA                  221 	.byte	-6
   0259 FF                  222 	.byte	-1
   025A FC                  223 	.byte	-4
   025B FE                  224 	.byte	-2
   025C                     225 _vl_term_1_109:
   025C 01                  226 	.byte	1
                            227 	.globl	_vectors_horizon
   025D                     228 _vectors_horizon:
   025D FF                  229 	.byte	-1
   025E 00                  230 	.byte	0
   025F 7F                  231 	.byte	127
   0260                     232 _vl_term_2_117:
   0260 01                  233 	.byte	1
                            234 	.globl	_vectors_road_outer_line_l
   0261                     235 _vectors_road_outer_line_l:
   0261 FF                  236 	.byte	-1
   0262 B0                  237 	.byte	-80
   0263 CB                  238 	.byte	-53
   0264                     239 _vl_term_3_125:
   0264 01                  240 	.byte	1
                            241 	.globl	_vectors_road_inner_line_l
   0265                     242 _vectors_road_inner_line_l:
   0265 FF                  243 	.byte	-1
   0266 A6                  244 	.byte	-90
   0267 EC                  245 	.byte	-20
   0268                     246 _vl_term_4_131:
   0268 01                  247 	.byte	1
                            248 	.globl	_vectors_road_inner_line_r
   0269                     249 _vectors_road_inner_line_r:
   0269 FF                  250 	.byte	-1
   026A A6                  251 	.byte	-90
   026B 14                  252 	.byte	20
   026C                     253 _vl_term_5_137:
   026C 01                  254 	.byte	1
                            255 	.globl	_vectors_road_outer_line_r
   026D                     256 _vectors_road_outer_line_r:
   026D FF                  257 	.byte	-1
   026E B0                  258 	.byte	-80
   026F 35                  259 	.byte	53
   0270                     260 _vl_term_6_143:
   0270 01                  261 	.byte	1
                            262 	.globl	_vectors_obstacle_truck_s
   0271                     263 _vectors_obstacle_truck_s:
                            264 	.globl	_temp_draw
   0271                     265 _temp_draw:
   0271 BD F1 92      [ 8]  266 	jsr	___Wait_Recal
   0274 BD F2 A5      [ 8]  267 	jsr	___Intensity_5F
   0277 BD F3 54      [ 8]  268 	jsr	___Reset0Ref
   027A C6 7F         [ 2]  269 	ldb	#127
   027C D7 04         [ 4]  270 	stb	*_dp_VIA_t1_cnt_lo
   027E 6F E2         [ 8]  271 	clr	,-s
   0280 5F            [ 2]  272 	clrb
   0281 BD 02 ED      [ 8]  273 	jsr	__Moveto_d
   0284 32 61         [ 5]  274 	leas	1,s
   0286 C6 FF         [ 2]  275 	ldb	#-1
   0288 D7 04         [ 4]  276 	stb	*_dp_VIA_t1_cnt_lo
   028A 8E 01 D8      [ 3]  277 	ldx	#_vectors_player
   028D BD F4 10      [ 8]  278 	jsr	___Draw_VLp
   0290 39            [ 5]  279 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Apr 25 23:10:58 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
    ___Wait_Recal      **** GX  |     _dp_VIA_t1_cnt     **** GX
  2 _temp_draw         00E8 GR  |   2 _vectors_ballo     0027 GR
  2 _vectors_horiz     00D4 GR  |   2 _vectors_man       0000 GR
  2 _vectors_obsta     00E8 GR  |   2 _vectors_playe     004F GR
  2 _vectors_road_     00DC GR  |   2 _vectors_road_     00E0 GR
  2 _vectors_road_     00D8 GR  |   2 _vectors_road_     00E4 GR
  2 _vl_term_0_46      004E R   |   2 _vl_term_1_109     00D3 R
  2 _vl_term_2_117     00D7 R   |   2 _vl_term_3_125     00DB R
  2 _vl_term_4_131     00DF R   |   2 _vl_term_5_137     00E3 R
  2 _vl_term_6_143     00E7 R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri Apr 25 23:10:58 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size  108   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

