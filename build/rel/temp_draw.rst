                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	temp_draw.c
                              6 	.globl	_vectors_man
                              7 	.area	.text
   038D                       8 _vectors_man:
   038D 00                    9 	.byte	0
   038E 30                   10 	.byte	48
   038F F0                   11 	.byte	-16
   0390 FF                   12 	.byte	-1
   0391 00                   13 	.byte	0
   0392 20                   14 	.byte	32
   0393 FF                   15 	.byte	-1
   0394 E0                   16 	.byte	-32
   0395 00                   17 	.byte	0
   0396 FF                   18 	.byte	-1
   0397 00                   19 	.byte	0
   0398 E0                   20 	.byte	-32
   0399 FF                   21 	.byte	-1
   039A 20                   22 	.byte	32
   039B 00                   23 	.byte	0
   039C 00                   24 	.byte	0
   039D E0                   25 	.byte	-32
   039E 10                   26 	.byte	16
   039F FF                   27 	.byte	-1
   03A0 E0                   28 	.byte	-32
   03A1 00                   29 	.byte	0
   03A2 00                   30 	.byte	0
   03A3 10                   31 	.byte	16
   03A4 E0                   32 	.byte	-32
   03A5 FF                   33 	.byte	-1
   03A6 00                   34 	.byte	0
   03A7 40                   35 	.byte	64
   03A8 00                   36 	.byte	0
   03A9 D0                   37 	.byte	-48
   03AA F0                   38 	.byte	-16
   03AB FF                   39 	.byte	-1
   03AC 20                   40 	.byte	32
   03AD F0                   41 	.byte	-16
   03AE FF                   42 	.byte	-1
   03AF E0                   43 	.byte	-32
   03B0 F0                   44 	.byte	-16
   03B1 01                   45 	.byte	1
   03B2 00                   46 	.byte	0
   03B3 00                   47 	.byte	0
                             48 	.globl	_vectors_balloon
   03B4                      49 _vectors_balloon:
   03B4 00                   50 	.byte	0
   03B5 19                   51 	.byte	25
   03B6 00                   52 	.byte	0
   03B7 FF                   53 	.byte	-1
   03B8 32                   54 	.byte	50
   03B9 00                   55 	.byte	0
   03BA FF                   56 	.byte	-1
   03BB 00                   57 	.byte	0
   03BC F6                   58 	.byte	-10
   03BD FF                   59 	.byte	-1
   03BE 0A                   60 	.byte	10
   03BF 0A                   61 	.byte	10
   03C0 FF                   62 	.byte	-1
   03C1 0A                   63 	.byte	10
   03C2 EC                   64 	.byte	-20
   03C3 FF                   65 	.byte	-1
   03C4 1E                   66 	.byte	30
   03C5 00                   67 	.byte	0
   03C6 FF                   68 	.byte	-1
   03C7 0A                   69 	.byte	10
   03C8 0A                   70 	.byte	10
   03C9 FF                   71 	.byte	-1
   03CA 00                   72 	.byte	0
   03CB 14                   73 	.byte	20
   03CC FF                   74 	.byte	-1
   03CD F6                   75 	.byte	-10
   03CE 0A                   76 	.byte	10
   03CF FF                   77 	.byte	-1
   03D0 E2                   78 	.byte	-30
   03D1 00                   79 	.byte	0
   03D2 FF                   80 	.byte	-1
   03D3 F6                   81 	.byte	-10
   03D4 EC                   82 	.byte	-20
   03D5 FF                   83 	.byte	-1
   03D6 F6                   84 	.byte	-10
   03D7 0A                   85 	.byte	10
   03D8 FF                   86 	.byte	-1
   03D9 00                   87 	.byte	0
   03DA F6                   88 	.byte	-10
   03DB                      89 _vl_term_0_46:
   03DB 01                   90 	.byte	1
                             91 	.globl	_vectors_player
   03DC                      92 _vectors_player:
   03DC 00                   93 	.byte	0
   03DD E8                   94 	.byte	-24
   03DE EC                   95 	.byte	-20
   03DF FF                   96 	.byte	-1
   03E0 00                   97 	.byte	0
   03E1 EC                   98 	.byte	-20
   03E2 FF                   99 	.byte	-1
   03E3 20                  100 	.byte	32
   03E4 00                  101 	.byte	0
   03E5 FF                  102 	.byte	-1
   03E6 00                  103 	.byte	0
   03E7 14                  104 	.byte	20
   03E8 FF                  105 	.byte	-1
   03E9 E0                  106 	.byte	-32
   03EA 00                  107 	.byte	0
   03EB 00                  108 	.byte	0
   03EC 04                  109 	.byte	4
   03ED 00                  110 	.byte	0
   03EE FF                  111 	.byte	-1
   03EF 04                  112 	.byte	4
   03F0 0F                  113 	.byte	15
   03F1 00                  114 	.byte	0
   03F2 00                  115 	.byte	0
   03F3 0A                  116 	.byte	10
   03F4 FF                  117 	.byte	-1
   03F5 FC                  118 	.byte	-4
   03F6 0F                  119 	.byte	15
   03F7 00                  120 	.byte	0
   03F8 FC                  121 	.byte	-4
   03F9 00                  122 	.byte	0
   03FA FF                  123 	.byte	-1
   03FB 00                  124 	.byte	0
   03FC 14                  125 	.byte	20
   03FD FF                  126 	.byte	-1
   03FE 20                  127 	.byte	32
   03FF 00                  128 	.byte	0
   0400 FF                  129 	.byte	-1
   0401 00                  130 	.byte	0
   0402 EC                  131 	.byte	-20
   0403 FF                  132 	.byte	-1
   0404 E0                  133 	.byte	-32
   0405 00                  134 	.byte	0
   0406 00                  135 	.byte	0
   0407 08                  136 	.byte	8
   0408 00                  137 	.byte	0
   0409 FF                  138 	.byte	-1
   040A 00                  139 	.byte	0
   040B D8                  140 	.byte	-40
   040C 00                  141 	.byte	0
   040D 10                  142 	.byte	16
   040E 00                  143 	.byte	0
   040F FF                  144 	.byte	-1
   0410 04                  145 	.byte	4
   0411 0F                  146 	.byte	15
   0412 FF                  147 	.byte	-1
   0413 00                  148 	.byte	0
   0414 0A                  149 	.byte	10
   0415 FF                  150 	.byte	-1
   0416 FC                  151 	.byte	-4
   0417 0F                  152 	.byte	15
   0418 FF                  153 	.byte	-1
   0419 1C                  154 	.byte	28
   041A F0                  155 	.byte	-16
   041B FF                  156 	.byte	-1
   041C 00                  157 	.byte	0
   041D F8                  158 	.byte	-8
   041E 00                  159 	.byte	0
   041F F9                  160 	.byte	-7
   0420 0C                  161 	.byte	12
   0421 FF                  162 	.byte	-1
   0422 00                  163 	.byte	0
   0423 0C                  164 	.byte	12
   0424 FF                  165 	.byte	-1
   0425 04                  166 	.byte	4
   0426 FE                  167 	.byte	-2
   0427 FF                  168 	.byte	-1
   0428 00                  169 	.byte	0
   0429 F4                  170 	.byte	-12
   042A 00                  171 	.byte	0
   042B 00                  172 	.byte	0
   042C F4                  173 	.byte	-12
   042D FF                  174 	.byte	-1
   042E 00                  175 	.byte	0
   042F F4                  176 	.byte	-12
   0430 FF                  177 	.byte	-1
   0431 FC                  178 	.byte	-4
   0432 FE                  179 	.byte	-2
   0433 FF                  180 	.byte	-1
   0434 00                  181 	.byte	0
   0435 0C                  182 	.byte	12
   0436 00                  183 	.byte	0
   0437 07                  184 	.byte	7
   0438 04                  185 	.byte	4
   0439 FF                  186 	.byte	-1
   043A E4                  187 	.byte	-28
   043B F0                  188 	.byte	-16
   043C 00                  189 	.byte	0
   043D 08                  190 	.byte	8
   043E F6                  191 	.byte	-10
   043F FF                  192 	.byte	-1
   0440 0A                  193 	.byte	10
   0441 00                  194 	.byte	0
   0442 FF                  195 	.byte	-1
   0443 00                  196 	.byte	0
   0444 0F                  197 	.byte	15
   0445 FF                  198 	.byte	-1
   0446 F7                  199 	.byte	-9
   0447 00                  200 	.byte	0
   0448 00                  201 	.byte	0
   0449 00                  202 	.byte	0
   044A 1E                  203 	.byte	30
   044B FF                  204 	.byte	-1
   044C 09                  205 	.byte	9
   044D 00                  206 	.byte	0
   044E FF                  207 	.byte	-1
   044F 00                  208 	.byte	0
   0450 0F                  209 	.byte	15
   0451 FF                  210 	.byte	-1
   0452 F6                  211 	.byte	-10
   0453 00                  212 	.byte	0
   0454 00                  213 	.byte	0
   0455 05                  214 	.byte	5
   0456 E7                  215 	.byte	-25
   0457 FF                  216 	.byte	-1
   0458 04                  217 	.byte	4
   0459 FE                  218 	.byte	-2
   045A FF                  219 	.byte	-1
   045B 00                  220 	.byte	0
   045C FA                  221 	.byte	-6
   045D FF                  222 	.byte	-1
   045E FC                  223 	.byte	-4
   045F FE                  224 	.byte	-2
   0460                     225 _vl_term_1_109:
   0460 01                  226 	.byte	1
                            227 	.globl	_vectors_horizon
   0461                     228 _vectors_horizon:
   0461 FF                  229 	.byte	-1
   0462 00                  230 	.byte	0
   0463 7F                  231 	.byte	127
   0464                     232 _vl_term_2_117:
   0464 01                  233 	.byte	1
                            234 	.globl	_vectors_road_inner_line_l
   0465                     235 _vectors_road_inner_line_l:
   0465 FF                  236 	.byte	-1
   0466 FC                  237 	.byte	-4
   0467 FF                  238 	.byte	-1
   0468 00                  239 	.byte	0
   0469 FC                  240 	.byte	-4
   046A FF                  241 	.byte	-1
   046B FF                  242 	.byte	-1
   046C FC                  243 	.byte	-4
   046D FF                  244 	.byte	-1
   046E 00                  245 	.byte	0
   046F FC                  246 	.byte	-4
   0470 FF                  247 	.byte	-1
   0471 FF                  248 	.byte	-1
   0472 F8                  249 	.byte	-8
   0473 FE                  250 	.byte	-2
   0474 00                  251 	.byte	0
   0475 F8                  252 	.byte	-8
   0476 FE                  253 	.byte	-2
   0477 FF                  254 	.byte	-1
   0478 F8                  255 	.byte	-8
   0479 FE                  256 	.byte	-2
   047A 00                  257 	.byte	0
   047B F8                  258 	.byte	-8
   047C FE                  259 	.byte	-2
   047D FF                  260 	.byte	-1
   047E F4                  261 	.byte	-12
   047F FD                  262 	.byte	-3
   0480 00                  263 	.byte	0
   0481 F4                  264 	.byte	-12
   0482 FD                  265 	.byte	-3
   0483 FF                  266 	.byte	-1
   0484 F4                  267 	.byte	-12
   0485 FD                  268 	.byte	-3
   0486 00                  269 	.byte	0
   0487 F4                  270 	.byte	-12
   0488 FD                  271 	.byte	-3
   0489 FF                  272 	.byte	-1
   048A F0                  273 	.byte	-16
   048B FC                  274 	.byte	-4
   048C 00                  275 	.byte	0
   048D F0                  276 	.byte	-16
   048E FC                  277 	.byte	-4
   048F FF                  278 	.byte	-1
   0490 F0                  279 	.byte	-16
   0491 FC                  280 	.byte	-4
   0492 00                  281 	.byte	0
   0493 F0                  282 	.byte	-16
   0494 FC                  283 	.byte	-4
   0495 FF                  284 	.byte	-1
   0496 EC                  285 	.byte	-20
   0497 FB                  286 	.byte	-5
   0498                     287 _vl_term_3_141:
   0498 01                  288 	.byte	1
                            289 	.globl	_vectors_road_inner_line_r
   0499                     290 _vectors_road_inner_line_r:
   0499 FF                  291 	.byte	-1
   049A FC                  292 	.byte	-4
   049B 01                  293 	.byte	1
   049C 00                  294 	.byte	0
   049D FC                  295 	.byte	-4
   049E 01                  296 	.byte	1
   049F FF                  297 	.byte	-1
   04A0 FC                  298 	.byte	-4
   04A1 01                  299 	.byte	1
   04A2 00                  300 	.byte	0
   04A3 FC                  301 	.byte	-4
   04A4 01                  302 	.byte	1
   04A5 FF                  303 	.byte	-1
   04A6 F8                  304 	.byte	-8
   04A7 02                  305 	.byte	2
   04A8 00                  306 	.byte	0
   04A9 F8                  307 	.byte	-8
   04AA 02                  308 	.byte	2
   04AB FF                  309 	.byte	-1
   04AC F8                  310 	.byte	-8
   04AD 02                  311 	.byte	2
   04AE 00                  312 	.byte	0
   04AF F8                  313 	.byte	-8
   04B0 02                  314 	.byte	2
   04B1 FF                  315 	.byte	-1
   04B2 F4                  316 	.byte	-12
   04B3 03                  317 	.byte	3
   04B4 00                  318 	.byte	0
   04B5 F4                  319 	.byte	-12
   04B6 03                  320 	.byte	3
   04B7 FF                  321 	.byte	-1
   04B8 F4                  322 	.byte	-12
   04B9 03                  323 	.byte	3
   04BA 00                  324 	.byte	0
   04BB F4                  325 	.byte	-12
   04BC 03                  326 	.byte	3
   04BD FF                  327 	.byte	-1
   04BE F0                  328 	.byte	-16
   04BF 04                  329 	.byte	4
   04C0 00                  330 	.byte	0
   04C1 F0                  331 	.byte	-16
   04C2 04                  332 	.byte	4
   04C3 FF                  333 	.byte	-1
   04C4 F0                  334 	.byte	-16
   04C5 04                  335 	.byte	4
   04C6 00                  336 	.byte	0
   04C7 F0                  337 	.byte	-16
   04C8 04                  338 	.byte	4
   04C9 FF                  339 	.byte	-1
   04CA EC                  340 	.byte	-20
   04CB 05                  341 	.byte	5
   04CC                     342 _vl_term_4_163:
   04CC 01                  343 	.byte	1
                            344 	.globl	_vectors_debug_car
   04CD                     345 _vectors_debug_car:
   04CD 00                  346 	.byte	0
   04CE 08                  347 	.byte	8
   04CF FA                  348 	.byte	-6
   04D0 FF                  349 	.byte	-1
   04D1 F4                  350 	.byte	-12
   04D2 00                  351 	.byte	0
   04D3 FF                  352 	.byte	-1
   04D4 00                  353 	.byte	0
   04D5 0C                  354 	.byte	12
   04D6 FF                  355 	.byte	-1
   04D7 0C                  356 	.byte	12
   04D8 00                  357 	.byte	0
   04D9 FF                  358 	.byte	-1
   04DA 00                  359 	.byte	0
   04DB F4                  360 	.byte	-12
   04DC                     361 _vl_term_5_174:
   04DC 01                  362 	.byte	1
                            363 	.globl	_vectors_obstacle_truck_s
   04DD                     364 _vectors_obstacle_truck_s:
                            365 	.globl	_temp_draw
   04DD                     366 _temp_draw:
   04DD BD F1 92      [ 8]  367 	jsr	___Wait_Recal
   04E0 BD F2 A5      [ 8]  368 	jsr	___Intensity_5F
   04E3 BD F3 54      [ 8]  369 	jsr	___Reset0Ref
   04E6 C6 7F         [ 2]  370 	ldb	#127
   04E8 D7 04         [ 4]  371 	stb	*_dp_VIA_t1_cnt_lo
   04EA 6F E2         [ 8]  372 	clr	,-s
   04EC 5F            [ 2]  373 	clrb
   04ED BD 05 5E      [ 8]  374 	jsr	__Moveto_d
   04F0 32 61         [ 5]  375 	leas	1,s
   04F2 C6 FF         [ 2]  376 	ldb	#-1
   04F4 D7 04         [ 4]  377 	stb	*_dp_VIA_t1_cnt_lo
   04F6 8E 03 DC      [ 3]  378 	ldx	#_vectors_player
   04F9 BD F4 10      [ 8]  379 	jsr	___Draw_VLp
   04FC 39            [ 5]  380 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri May  2 16:45:27 2025

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
Hexadecimal [16-Bits]                                 Fri May  2 16:45:27 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size  170   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

