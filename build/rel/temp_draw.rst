                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	temp_draw.c
                              6 	.globl	_vectors_man
                              7 	.area	.text
   03A8                       8 _vectors_man:
   03A8 00                    9 	.byte	0
   03A9 30                   10 	.byte	48
   03AA F0                   11 	.byte	-16
   03AB FF                   12 	.byte	-1
   03AC 00                   13 	.byte	0
   03AD 20                   14 	.byte	32
   03AE FF                   15 	.byte	-1
   03AF E0                   16 	.byte	-32
   03B0 00                   17 	.byte	0
   03B1 FF                   18 	.byte	-1
   03B2 00                   19 	.byte	0
   03B3 E0                   20 	.byte	-32
   03B4 FF                   21 	.byte	-1
   03B5 20                   22 	.byte	32
   03B6 00                   23 	.byte	0
   03B7 00                   24 	.byte	0
   03B8 E0                   25 	.byte	-32
   03B9 10                   26 	.byte	16
   03BA FF                   27 	.byte	-1
   03BB E0                   28 	.byte	-32
   03BC 00                   29 	.byte	0
   03BD 00                   30 	.byte	0
   03BE 10                   31 	.byte	16
   03BF E0                   32 	.byte	-32
   03C0 FF                   33 	.byte	-1
   03C1 00                   34 	.byte	0
   03C2 40                   35 	.byte	64
   03C3 00                   36 	.byte	0
   03C4 D0                   37 	.byte	-48
   03C5 F0                   38 	.byte	-16
   03C6 FF                   39 	.byte	-1
   03C7 20                   40 	.byte	32
   03C8 F0                   41 	.byte	-16
   03C9 FF                   42 	.byte	-1
   03CA E0                   43 	.byte	-32
   03CB F0                   44 	.byte	-16
   03CC 01                   45 	.byte	1
   03CD 00                   46 	.byte	0
   03CE 00                   47 	.byte	0
                             48 	.globl	_vectors_balloon
   03CF                      49 _vectors_balloon:
   03CF 00                   50 	.byte	0
   03D0 19                   51 	.byte	25
   03D1 00                   52 	.byte	0
   03D2 FF                   53 	.byte	-1
   03D3 32                   54 	.byte	50
   03D4 00                   55 	.byte	0
   03D5 FF                   56 	.byte	-1
   03D6 00                   57 	.byte	0
   03D7 F6                   58 	.byte	-10
   03D8 FF                   59 	.byte	-1
   03D9 0A                   60 	.byte	10
   03DA 0A                   61 	.byte	10
   03DB FF                   62 	.byte	-1
   03DC 0A                   63 	.byte	10
   03DD EC                   64 	.byte	-20
   03DE FF                   65 	.byte	-1
   03DF 1E                   66 	.byte	30
   03E0 00                   67 	.byte	0
   03E1 FF                   68 	.byte	-1
   03E2 0A                   69 	.byte	10
   03E3 0A                   70 	.byte	10
   03E4 FF                   71 	.byte	-1
   03E5 00                   72 	.byte	0
   03E6 14                   73 	.byte	20
   03E7 FF                   74 	.byte	-1
   03E8 F6                   75 	.byte	-10
   03E9 0A                   76 	.byte	10
   03EA FF                   77 	.byte	-1
   03EB E2                   78 	.byte	-30
   03EC 00                   79 	.byte	0
   03ED FF                   80 	.byte	-1
   03EE F6                   81 	.byte	-10
   03EF EC                   82 	.byte	-20
   03F0 FF                   83 	.byte	-1
   03F1 F6                   84 	.byte	-10
   03F2 0A                   85 	.byte	10
   03F3 FF                   86 	.byte	-1
   03F4 00                   87 	.byte	0
   03F5 F6                   88 	.byte	-10
   03F6                      89 _vl_term_0_46:
   03F6 01                   90 	.byte	1
                             91 	.globl	_vectors_player
   03F7                      92 _vectors_player:
   03F7 00                   93 	.byte	0
   03F8 E8                   94 	.byte	-24
   03F9 EC                   95 	.byte	-20
   03FA FF                   96 	.byte	-1
   03FB 00                   97 	.byte	0
   03FC EC                   98 	.byte	-20
   03FD FF                   99 	.byte	-1
   03FE 20                  100 	.byte	32
   03FF 00                  101 	.byte	0
   0400 FF                  102 	.byte	-1
   0401 00                  103 	.byte	0
   0402 14                  104 	.byte	20
   0403 FF                  105 	.byte	-1
   0404 E0                  106 	.byte	-32
   0405 00                  107 	.byte	0
   0406 00                  108 	.byte	0
   0407 04                  109 	.byte	4
   0408 00                  110 	.byte	0
   0409 FF                  111 	.byte	-1
   040A 04                  112 	.byte	4
   040B 0F                  113 	.byte	15
   040C 00                  114 	.byte	0
   040D 00                  115 	.byte	0
   040E 0A                  116 	.byte	10
   040F FF                  117 	.byte	-1
   0410 FC                  118 	.byte	-4
   0411 0F                  119 	.byte	15
   0412 00                  120 	.byte	0
   0413 FC                  121 	.byte	-4
   0414 00                  122 	.byte	0
   0415 FF                  123 	.byte	-1
   0416 00                  124 	.byte	0
   0417 14                  125 	.byte	20
   0418 FF                  126 	.byte	-1
   0419 20                  127 	.byte	32
   041A 00                  128 	.byte	0
   041B FF                  129 	.byte	-1
   041C 00                  130 	.byte	0
   041D EC                  131 	.byte	-20
   041E FF                  132 	.byte	-1
   041F E0                  133 	.byte	-32
   0420 00                  134 	.byte	0
   0421 00                  135 	.byte	0
   0422 08                  136 	.byte	8
   0423 00                  137 	.byte	0
   0424 FF                  138 	.byte	-1
   0425 00                  139 	.byte	0
   0426 D8                  140 	.byte	-40
   0427 00                  141 	.byte	0
   0428 10                  142 	.byte	16
   0429 00                  143 	.byte	0
   042A FF                  144 	.byte	-1
   042B 04                  145 	.byte	4
   042C 0F                  146 	.byte	15
   042D FF                  147 	.byte	-1
   042E 00                  148 	.byte	0
   042F 0A                  149 	.byte	10
   0430 FF                  150 	.byte	-1
   0431 FC                  151 	.byte	-4
   0432 0F                  152 	.byte	15
   0433 FF                  153 	.byte	-1
   0434 1C                  154 	.byte	28
   0435 F0                  155 	.byte	-16
   0436 FF                  156 	.byte	-1
   0437 00                  157 	.byte	0
   0438 F8                  158 	.byte	-8
   0439 00                  159 	.byte	0
   043A F9                  160 	.byte	-7
   043B 0C                  161 	.byte	12
   043C FF                  162 	.byte	-1
   043D 00                  163 	.byte	0
   043E 0C                  164 	.byte	12
   043F FF                  165 	.byte	-1
   0440 04                  166 	.byte	4
   0441 FE                  167 	.byte	-2
   0442 FF                  168 	.byte	-1
   0443 00                  169 	.byte	0
   0444 F4                  170 	.byte	-12
   0445 00                  171 	.byte	0
   0446 00                  172 	.byte	0
   0447 F4                  173 	.byte	-12
   0448 FF                  174 	.byte	-1
   0449 00                  175 	.byte	0
   044A F4                  176 	.byte	-12
   044B FF                  177 	.byte	-1
   044C FC                  178 	.byte	-4
   044D FE                  179 	.byte	-2
   044E FF                  180 	.byte	-1
   044F 00                  181 	.byte	0
   0450 0C                  182 	.byte	12
   0451 00                  183 	.byte	0
   0452 07                  184 	.byte	7
   0453 04                  185 	.byte	4
   0454 FF                  186 	.byte	-1
   0455 E4                  187 	.byte	-28
   0456 F0                  188 	.byte	-16
   0457 00                  189 	.byte	0
   0458 08                  190 	.byte	8
   0459 F6                  191 	.byte	-10
   045A FF                  192 	.byte	-1
   045B 0A                  193 	.byte	10
   045C 00                  194 	.byte	0
   045D FF                  195 	.byte	-1
   045E 00                  196 	.byte	0
   045F 0F                  197 	.byte	15
   0460 FF                  198 	.byte	-1
   0461 F7                  199 	.byte	-9
   0462 00                  200 	.byte	0
   0463 00                  201 	.byte	0
   0464 00                  202 	.byte	0
   0465 1E                  203 	.byte	30
   0466 FF                  204 	.byte	-1
   0467 09                  205 	.byte	9
   0468 00                  206 	.byte	0
   0469 FF                  207 	.byte	-1
   046A 00                  208 	.byte	0
   046B 0F                  209 	.byte	15
   046C FF                  210 	.byte	-1
   046D F6                  211 	.byte	-10
   046E 00                  212 	.byte	0
   046F 00                  213 	.byte	0
   0470 05                  214 	.byte	5
   0471 E7                  215 	.byte	-25
   0472 FF                  216 	.byte	-1
   0473 04                  217 	.byte	4
   0474 FE                  218 	.byte	-2
   0475 FF                  219 	.byte	-1
   0476 00                  220 	.byte	0
   0477 FA                  221 	.byte	-6
   0478 FF                  222 	.byte	-1
   0479 FC                  223 	.byte	-4
   047A FE                  224 	.byte	-2
   047B                     225 _vl_term_1_109:
   047B 01                  226 	.byte	1
                            227 	.globl	_vectors_horizon
   047C                     228 _vectors_horizon:
   047C FF                  229 	.byte	-1
   047D 00                  230 	.byte	0
   047E 7F                  231 	.byte	127
   047F                     232 _vl_term_2_117:
   047F 01                  233 	.byte	1
                            234 	.globl	_vectors_road_inner_line_l
   0480                     235 _vectors_road_inner_line_l:
   0480 FF                  236 	.byte	-1
   0481 FC                  237 	.byte	-4
   0482 FF                  238 	.byte	-1
   0483 00                  239 	.byte	0
   0484 FC                  240 	.byte	-4
   0485 FF                  241 	.byte	-1
   0486 FF                  242 	.byte	-1
   0487 FC                  243 	.byte	-4
   0488 FF                  244 	.byte	-1
   0489 00                  245 	.byte	0
   048A FC                  246 	.byte	-4
   048B FF                  247 	.byte	-1
   048C FF                  248 	.byte	-1
   048D F8                  249 	.byte	-8
   048E FE                  250 	.byte	-2
   048F 00                  251 	.byte	0
   0490 F8                  252 	.byte	-8
   0491 FE                  253 	.byte	-2
   0492 FF                  254 	.byte	-1
   0493 F8                  255 	.byte	-8
   0494 FE                  256 	.byte	-2
   0495 00                  257 	.byte	0
   0496 F8                  258 	.byte	-8
   0497 FE                  259 	.byte	-2
   0498 FF                  260 	.byte	-1
   0499 F4                  261 	.byte	-12
   049A FD                  262 	.byte	-3
   049B 00                  263 	.byte	0
   049C F4                  264 	.byte	-12
   049D FD                  265 	.byte	-3
   049E FF                  266 	.byte	-1
   049F F4                  267 	.byte	-12
   04A0 FD                  268 	.byte	-3
   04A1 00                  269 	.byte	0
   04A2 F4                  270 	.byte	-12
   04A3 FD                  271 	.byte	-3
   04A4 FF                  272 	.byte	-1
   04A5 F0                  273 	.byte	-16
   04A6 FC                  274 	.byte	-4
   04A7 00                  275 	.byte	0
   04A8 F0                  276 	.byte	-16
   04A9 FC                  277 	.byte	-4
   04AA FF                  278 	.byte	-1
   04AB F0                  279 	.byte	-16
   04AC FC                  280 	.byte	-4
   04AD 00                  281 	.byte	0
   04AE F0                  282 	.byte	-16
   04AF FC                  283 	.byte	-4
   04B0 FF                  284 	.byte	-1
   04B1 EC                  285 	.byte	-20
   04B2 FB                  286 	.byte	-5
   04B3                     287 _vl_term_3_141:
   04B3 01                  288 	.byte	1
                            289 	.globl	_vectors_road_inner_line_r
   04B4                     290 _vectors_road_inner_line_r:
   04B4 FF                  291 	.byte	-1
   04B5 FC                  292 	.byte	-4
   04B6 01                  293 	.byte	1
   04B7 00                  294 	.byte	0
   04B8 FC                  295 	.byte	-4
   04B9 01                  296 	.byte	1
   04BA FF                  297 	.byte	-1
   04BB FC                  298 	.byte	-4
   04BC 01                  299 	.byte	1
   04BD 00                  300 	.byte	0
   04BE FC                  301 	.byte	-4
   04BF 01                  302 	.byte	1
   04C0 FF                  303 	.byte	-1
   04C1 F8                  304 	.byte	-8
   04C2 02                  305 	.byte	2
   04C3 00                  306 	.byte	0
   04C4 F8                  307 	.byte	-8
   04C5 02                  308 	.byte	2
   04C6 FF                  309 	.byte	-1
   04C7 F8                  310 	.byte	-8
   04C8 02                  311 	.byte	2
   04C9 00                  312 	.byte	0
   04CA F8                  313 	.byte	-8
   04CB 02                  314 	.byte	2
   04CC FF                  315 	.byte	-1
   04CD F4                  316 	.byte	-12
   04CE 03                  317 	.byte	3
   04CF 00                  318 	.byte	0
   04D0 F4                  319 	.byte	-12
   04D1 03                  320 	.byte	3
   04D2 FF                  321 	.byte	-1
   04D3 F4                  322 	.byte	-12
   04D4 03                  323 	.byte	3
   04D5 00                  324 	.byte	0
   04D6 F4                  325 	.byte	-12
   04D7 03                  326 	.byte	3
   04D8 FF                  327 	.byte	-1
   04D9 F0                  328 	.byte	-16
   04DA 04                  329 	.byte	4
   04DB 00                  330 	.byte	0
   04DC F0                  331 	.byte	-16
   04DD 04                  332 	.byte	4
   04DE FF                  333 	.byte	-1
   04DF F0                  334 	.byte	-16
   04E0 04                  335 	.byte	4
   04E1 00                  336 	.byte	0
   04E2 F0                  337 	.byte	-16
   04E3 04                  338 	.byte	4
   04E4 FF                  339 	.byte	-1
   04E5 EC                  340 	.byte	-20
   04E6 05                  341 	.byte	5
   04E7                     342 _vl_term_4_163:
   04E7 01                  343 	.byte	1
                            344 	.globl	_vectors_debug_car
   04E8                     345 _vectors_debug_car:
   04E8 00                  346 	.byte	0
   04E9 08                  347 	.byte	8
   04EA FA                  348 	.byte	-6
   04EB FF                  349 	.byte	-1
   04EC F4                  350 	.byte	-12
   04ED 00                  351 	.byte	0
   04EE FF                  352 	.byte	-1
   04EF 00                  353 	.byte	0
   04F0 0C                  354 	.byte	12
   04F1 FF                  355 	.byte	-1
   04F2 0C                  356 	.byte	12
   04F3 00                  357 	.byte	0
   04F4 FF                  358 	.byte	-1
   04F5 00                  359 	.byte	0
   04F6 F4                  360 	.byte	-12
   04F7                     361 _vl_term_5_174:
   04F7 01                  362 	.byte	1
                            363 	.globl	_vectors_obstacle_truck_s
   04F8                     364 _vectors_obstacle_truck_s:
                            365 	.globl	_temp_draw
   04F8                     366 _temp_draw:
   04F8 BD F1 92      [ 8]  367 	jsr	___Wait_Recal
   04FB BD F2 A5      [ 8]  368 	jsr	___Intensity_5F
   04FE BD F3 54      [ 8]  369 	jsr	___Reset0Ref
   0501 C6 7F         [ 2]  370 	ldb	#127
   0503 D7 04         [ 4]  371 	stb	*_dp_VIA_t1_cnt_lo
   0505 6F E2         [ 8]  372 	clr	,-s
   0507 5F            [ 2]  373 	clrb
   0508 BD 05 79      [ 8]  374 	jsr	__Moveto_d
   050B 32 61         [ 5]  375 	leas	1,s
   050D C6 FF         [ 2]  376 	ldb	#-1
   050F D7 04         [ 4]  377 	stb	*_dp_VIA_t1_cnt_lo
   0511 8E 03 F7      [ 3]  378 	ldx	#_vectors_player
   0514 BD F4 10      [ 8]  379 	jsr	___Draw_VLp
   0517 39            [ 5]  380 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri May  2 16:28:44 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
    ___Wait_Recal      **** GX  |     _dp_VIA_t1_cnt     **** GX
  2 _temp_draw         0150 GR  |   2 _vectors_ballo     0027 GR
  2 _vectors_debug     0140 GR  |   2 _vectors_horiz     00D4 GR
  2 _vectors_man       0000 GR  |   2 _vectors_obsta     0150 GR
  2 _vectors_playe     004F GR  |   2 _vectors_road_     00D8 GR
  2 _vectors_road_     010C GR  |   2 _vl_term_0_46      004E R
  2 _vl_term_1_109     00D3 R   |   2 _vl_term_2_117     00D7 R
  2 _vl_term_3_141     010B R   |   2 _vl_term_4_163     013F R
  2 _vl_term_5_174     014F R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri May  2 16:28:44 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size  170   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

