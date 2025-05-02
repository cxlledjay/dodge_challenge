                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O0
                              5 	.module	temp_draw.c
                              6 	.globl	_vectors_man
                              7 	.area	.text
   02FA                       8 _vectors_man:
   02FA 00                    9 	.byte	0
   02FB 30                   10 	.byte	48
   02FC F0                   11 	.byte	-16
   02FD FF                   12 	.byte	-1
   02FE 00                   13 	.byte	0
   02FF 20                   14 	.byte	32
   0300 FF                   15 	.byte	-1
   0301 E0                   16 	.byte	-32
   0302 00                   17 	.byte	0
   0303 FF                   18 	.byte	-1
   0304 00                   19 	.byte	0
   0305 E0                   20 	.byte	-32
   0306 FF                   21 	.byte	-1
   0307 20                   22 	.byte	32
   0308 00                   23 	.byte	0
   0309 00                   24 	.byte	0
   030A E0                   25 	.byte	-32
   030B 10                   26 	.byte	16
   030C FF                   27 	.byte	-1
   030D E0                   28 	.byte	-32
   030E 00                   29 	.byte	0
   030F 00                   30 	.byte	0
   0310 10                   31 	.byte	16
   0311 E0                   32 	.byte	-32
   0312 FF                   33 	.byte	-1
   0313 00                   34 	.byte	0
   0314 40                   35 	.byte	64
   0315 00                   36 	.byte	0
   0316 D0                   37 	.byte	-48
   0317 F0                   38 	.byte	-16
   0318 FF                   39 	.byte	-1
   0319 20                   40 	.byte	32
   031A F0                   41 	.byte	-16
   031B FF                   42 	.byte	-1
   031C E0                   43 	.byte	-32
   031D F0                   44 	.byte	-16
   031E 01                   45 	.byte	1
   031F 00                   46 	.byte	0
   0320 00                   47 	.byte	0
                             48 	.globl	_vectors_balloon
   0321                      49 _vectors_balloon:
   0321 00                   50 	.byte	0
   0322 19                   51 	.byte	25
   0323 00                   52 	.byte	0
   0324 FF                   53 	.byte	-1
   0325 32                   54 	.byte	50
   0326 00                   55 	.byte	0
   0327 FF                   56 	.byte	-1
   0328 00                   57 	.byte	0
   0329 F6                   58 	.byte	-10
   032A FF                   59 	.byte	-1
   032B 0A                   60 	.byte	10
   032C 0A                   61 	.byte	10
   032D FF                   62 	.byte	-1
   032E 0A                   63 	.byte	10
   032F EC                   64 	.byte	-20
   0330 FF                   65 	.byte	-1
   0331 1E                   66 	.byte	30
   0332 00                   67 	.byte	0
   0333 FF                   68 	.byte	-1
   0334 0A                   69 	.byte	10
   0335 0A                   70 	.byte	10
   0336 FF                   71 	.byte	-1
   0337 00                   72 	.byte	0
   0338 14                   73 	.byte	20
   0339 FF                   74 	.byte	-1
   033A F6                   75 	.byte	-10
   033B 0A                   76 	.byte	10
   033C FF                   77 	.byte	-1
   033D E2                   78 	.byte	-30
   033E 00                   79 	.byte	0
   033F FF                   80 	.byte	-1
   0340 F6                   81 	.byte	-10
   0341 EC                   82 	.byte	-20
   0342 FF                   83 	.byte	-1
   0343 F6                   84 	.byte	-10
   0344 0A                   85 	.byte	10
   0345 FF                   86 	.byte	-1
   0346 00                   87 	.byte	0
   0347 F6                   88 	.byte	-10
   0348                      89 _vl_term_0_46:
   0348 01                   90 	.byte	1
                             91 	.globl	_vectors_player
   0349                      92 _vectors_player:
   0349 00                   93 	.byte	0
   034A E8                   94 	.byte	-24
   034B EC                   95 	.byte	-20
   034C FF                   96 	.byte	-1
   034D 00                   97 	.byte	0
   034E EC                   98 	.byte	-20
   034F FF                   99 	.byte	-1
   0350 20                  100 	.byte	32
   0351 00                  101 	.byte	0
   0352 FF                  102 	.byte	-1
   0353 00                  103 	.byte	0
   0354 14                  104 	.byte	20
   0355 FF                  105 	.byte	-1
   0356 E0                  106 	.byte	-32
   0357 00                  107 	.byte	0
   0358 00                  108 	.byte	0
   0359 04                  109 	.byte	4
   035A 00                  110 	.byte	0
   035B FF                  111 	.byte	-1
   035C 04                  112 	.byte	4
   035D 0F                  113 	.byte	15
   035E 00                  114 	.byte	0
   035F 00                  115 	.byte	0
   0360 0A                  116 	.byte	10
   0361 FF                  117 	.byte	-1
   0362 FC                  118 	.byte	-4
   0363 0F                  119 	.byte	15
   0364 00                  120 	.byte	0
   0365 FC                  121 	.byte	-4
   0366 00                  122 	.byte	0
   0367 FF                  123 	.byte	-1
   0368 00                  124 	.byte	0
   0369 14                  125 	.byte	20
   036A FF                  126 	.byte	-1
   036B 20                  127 	.byte	32
   036C 00                  128 	.byte	0
   036D FF                  129 	.byte	-1
   036E 00                  130 	.byte	0
   036F EC                  131 	.byte	-20
   0370 FF                  132 	.byte	-1
   0371 E0                  133 	.byte	-32
   0372 00                  134 	.byte	0
   0373 00                  135 	.byte	0
   0374 08                  136 	.byte	8
   0375 00                  137 	.byte	0
   0376 FF                  138 	.byte	-1
   0377 00                  139 	.byte	0
   0378 D8                  140 	.byte	-40
   0379 00                  141 	.byte	0
   037A 10                  142 	.byte	16
   037B 00                  143 	.byte	0
   037C FF                  144 	.byte	-1
   037D 04                  145 	.byte	4
   037E 0F                  146 	.byte	15
   037F FF                  147 	.byte	-1
   0380 00                  148 	.byte	0
   0381 0A                  149 	.byte	10
   0382 FF                  150 	.byte	-1
   0383 FC                  151 	.byte	-4
   0384 0F                  152 	.byte	15
   0385 FF                  153 	.byte	-1
   0386 1C                  154 	.byte	28
   0387 F0                  155 	.byte	-16
   0388 FF                  156 	.byte	-1
   0389 00                  157 	.byte	0
   038A F8                  158 	.byte	-8
   038B 00                  159 	.byte	0
   038C F9                  160 	.byte	-7
   038D 0C                  161 	.byte	12
   038E FF                  162 	.byte	-1
   038F 00                  163 	.byte	0
   0390 0C                  164 	.byte	12
   0391 FF                  165 	.byte	-1
   0392 04                  166 	.byte	4
   0393 FE                  167 	.byte	-2
   0394 FF                  168 	.byte	-1
   0395 00                  169 	.byte	0
   0396 F4                  170 	.byte	-12
   0397 00                  171 	.byte	0
   0398 00                  172 	.byte	0
   0399 F4                  173 	.byte	-12
   039A FF                  174 	.byte	-1
   039B 00                  175 	.byte	0
   039C F4                  176 	.byte	-12
   039D FF                  177 	.byte	-1
   039E FC                  178 	.byte	-4
   039F FE                  179 	.byte	-2
   03A0 FF                  180 	.byte	-1
   03A1 00                  181 	.byte	0
   03A2 0C                  182 	.byte	12
   03A3 00                  183 	.byte	0
   03A4 07                  184 	.byte	7
   03A5 04                  185 	.byte	4
   03A6 FF                  186 	.byte	-1
   03A7 E4                  187 	.byte	-28
   03A8 F0                  188 	.byte	-16
   03A9 00                  189 	.byte	0
   03AA 08                  190 	.byte	8
   03AB F6                  191 	.byte	-10
   03AC FF                  192 	.byte	-1
   03AD 0A                  193 	.byte	10
   03AE 00                  194 	.byte	0
   03AF FF                  195 	.byte	-1
   03B0 00                  196 	.byte	0
   03B1 0F                  197 	.byte	15
   03B2 FF                  198 	.byte	-1
   03B3 F7                  199 	.byte	-9
   03B4 00                  200 	.byte	0
   03B5 00                  201 	.byte	0
   03B6 00                  202 	.byte	0
   03B7 1E                  203 	.byte	30
   03B8 FF                  204 	.byte	-1
   03B9 09                  205 	.byte	9
   03BA 00                  206 	.byte	0
   03BB FF                  207 	.byte	-1
   03BC 00                  208 	.byte	0
   03BD 0F                  209 	.byte	15
   03BE FF                  210 	.byte	-1
   03BF F6                  211 	.byte	-10
   03C0 00                  212 	.byte	0
   03C1 00                  213 	.byte	0
   03C2 05                  214 	.byte	5
   03C3 E7                  215 	.byte	-25
   03C4 FF                  216 	.byte	-1
   03C5 04                  217 	.byte	4
   03C6 FE                  218 	.byte	-2
   03C7 FF                  219 	.byte	-1
   03C8 00                  220 	.byte	0
   03C9 FA                  221 	.byte	-6
   03CA FF                  222 	.byte	-1
   03CB FC                  223 	.byte	-4
   03CC FE                  224 	.byte	-2
   03CD                     225 _vl_term_1_109:
   03CD 01                  226 	.byte	1
                            227 	.globl	_vectors_horizon
   03CE                     228 _vectors_horizon:
   03CE FF                  229 	.byte	-1
   03CF 00                  230 	.byte	0
   03D0 7F                  231 	.byte	127
   03D1                     232 _vl_term_2_117:
   03D1 01                  233 	.byte	1
                            234 	.globl	_vectors_road_inner_line_l
   03D2                     235 _vectors_road_inner_line_l:
   03D2 FF                  236 	.byte	-1
   03D3 FC                  237 	.byte	-4
   03D4 FF                  238 	.byte	-1
   03D5 00                  239 	.byte	0
   03D6 FC                  240 	.byte	-4
   03D7 FF                  241 	.byte	-1
   03D8 FF                  242 	.byte	-1
   03D9 FC                  243 	.byte	-4
   03DA FF                  244 	.byte	-1
   03DB 00                  245 	.byte	0
   03DC FC                  246 	.byte	-4
   03DD FF                  247 	.byte	-1
   03DE FF                  248 	.byte	-1
   03DF F8                  249 	.byte	-8
   03E0 FE                  250 	.byte	-2
   03E1 00                  251 	.byte	0
   03E2 F8                  252 	.byte	-8
   03E3 FE                  253 	.byte	-2
   03E4 FF                  254 	.byte	-1
   03E5 F8                  255 	.byte	-8
   03E6 FE                  256 	.byte	-2
   03E7 00                  257 	.byte	0
   03E8 F8                  258 	.byte	-8
   03E9 FE                  259 	.byte	-2
   03EA FF                  260 	.byte	-1
   03EB F4                  261 	.byte	-12
   03EC FD                  262 	.byte	-3
   03ED 00                  263 	.byte	0
   03EE F4                  264 	.byte	-12
   03EF FD                  265 	.byte	-3
   03F0 FF                  266 	.byte	-1
   03F1 F4                  267 	.byte	-12
   03F2 FD                  268 	.byte	-3
   03F3 00                  269 	.byte	0
   03F4 F4                  270 	.byte	-12
   03F5 FD                  271 	.byte	-3
   03F6 FF                  272 	.byte	-1
   03F7 F0                  273 	.byte	-16
   03F8 FC                  274 	.byte	-4
   03F9 00                  275 	.byte	0
   03FA F0                  276 	.byte	-16
   03FB FC                  277 	.byte	-4
   03FC FF                  278 	.byte	-1
   03FD F0                  279 	.byte	-16
   03FE FC                  280 	.byte	-4
   03FF 00                  281 	.byte	0
   0400 F0                  282 	.byte	-16
   0401 FC                  283 	.byte	-4
   0402 FF                  284 	.byte	-1
   0403 EC                  285 	.byte	-20
   0404 FB                  286 	.byte	-5
   0405                     287 _vl_term_3_141:
   0405 01                  288 	.byte	1
                            289 	.globl	_vectors_road_inner_line_r
   0406                     290 _vectors_road_inner_line_r:
   0406 FF                  291 	.byte	-1
   0407 FC                  292 	.byte	-4
   0408 01                  293 	.byte	1
   0409 00                  294 	.byte	0
   040A FC                  295 	.byte	-4
   040B 01                  296 	.byte	1
   040C FF                  297 	.byte	-1
   040D FC                  298 	.byte	-4
   040E 01                  299 	.byte	1
   040F 00                  300 	.byte	0
   0410 FC                  301 	.byte	-4
   0411 01                  302 	.byte	1
   0412 FF                  303 	.byte	-1
   0413 F8                  304 	.byte	-8
   0414 02                  305 	.byte	2
   0415 00                  306 	.byte	0
   0416 F8                  307 	.byte	-8
   0417 02                  308 	.byte	2
   0418 FF                  309 	.byte	-1
   0419 F8                  310 	.byte	-8
   041A 02                  311 	.byte	2
   041B 00                  312 	.byte	0
   041C F8                  313 	.byte	-8
   041D 02                  314 	.byte	2
   041E FF                  315 	.byte	-1
   041F F4                  316 	.byte	-12
   0420 03                  317 	.byte	3
   0421 00                  318 	.byte	0
   0422 F4                  319 	.byte	-12
   0423 03                  320 	.byte	3
   0424 FF                  321 	.byte	-1
   0425 F4                  322 	.byte	-12
   0426 03                  323 	.byte	3
   0427 00                  324 	.byte	0
   0428 F4                  325 	.byte	-12
   0429 03                  326 	.byte	3
   042A FF                  327 	.byte	-1
   042B F0                  328 	.byte	-16
   042C 04                  329 	.byte	4
   042D 00                  330 	.byte	0
   042E F0                  331 	.byte	-16
   042F 04                  332 	.byte	4
   0430 FF                  333 	.byte	-1
   0431 F0                  334 	.byte	-16
   0432 04                  335 	.byte	4
   0433 00                  336 	.byte	0
   0434 F0                  337 	.byte	-16
   0435 04                  338 	.byte	4
   0436 FF                  339 	.byte	-1
   0437 EC                  340 	.byte	-20
   0438 05                  341 	.byte	5
   0439                     342 _vl_term_4_163:
   0439 01                  343 	.byte	1
                            344 	.globl	_vectors_debug_car
   043A                     345 _vectors_debug_car:
   043A 00                  346 	.byte	0
   043B 08                  347 	.byte	8
   043C FA                  348 	.byte	-6
   043D FF                  349 	.byte	-1
   043E F4                  350 	.byte	-12
   043F 00                  351 	.byte	0
   0440 FF                  352 	.byte	-1
   0441 00                  353 	.byte	0
   0442 0C                  354 	.byte	12
   0443 FF                  355 	.byte	-1
   0444 0C                  356 	.byte	12
   0445 00                  357 	.byte	0
   0446 FF                  358 	.byte	-1
   0447 00                  359 	.byte	0
   0448 F4                  360 	.byte	-12
   0449                     361 _vl_term_5_174:
   0449 01                  362 	.byte	1
                            363 	.globl	_vectors_obstacle_truck_s
   044A                     364 _vectors_obstacle_truck_s:
                            365 	.globl	_temp_draw
   044A                     366 _temp_draw:
   044A BD F1 92      [ 8]  367 	jsr	___Wait_Recal
   044D BD F2 A5      [ 8]  368 	jsr	___Intensity_5F
   0450 BD F3 54      [ 8]  369 	jsr	___Reset0Ref
   0453 C6 7F         [ 2]  370 	ldb	#127
   0455 D7 04         [ 4]  371 	stb	*_dp_VIA_t1_cnt_lo
   0457 6F E2         [ 8]  372 	clr	,-s
   0459 5F            [ 2]  373 	clrb
   045A BD 04 6F      [ 8]  374 	jsr	__Moveto_d
   045D 32 61         [ 5]  375 	leas	1,s
   045F C6 FF         [ 2]  376 	ldb	#-1
   0461 D7 04         [ 4]  377 	stb	*_dp_VIA_t1_cnt_lo
   0463 8E 03 49      [ 3]  378 	ldx	#_vectors_player
   0466 BD F4 10      [ 8]  379 	jsr	___Draw_VLp
   0469 39            [ 5]  380 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri May  2 15:00:18 2025

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
Hexadecimal [16-Bits]                                 Fri May  2 15:00:18 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size  170   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

