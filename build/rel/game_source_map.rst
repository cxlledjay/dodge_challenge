                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	map.c
                              6 	.area	.bss
                              7 	.globl	_the_map
   C8A7                       8 _the_map:	.blkb	3
                              9 	.globl	_CNT_DRAW1_LUT
                             10 	.area	.text
   037B                      11 _CNT_DRAW1_LUT:
   037B 06                   12 	.byte	6
   037C 05                   13 	.byte	5
   037D 04                   14 	.byte	4
   037E 04                   15 	.byte	4
   037F 03                   16 	.byte	3
   0380 02                   17 	.byte	2
   0381 02                   18 	.byte	2
   0382 02                   19 	.byte	2
   0383 01                   20 	.byte	1
   0384 01                   21 	.byte	1
   0385 00                   22 	.byte	0
                             23 	.globl	_CNT_DRAW2_LUT
   0386                      24 _CNT_DRAW2_LUT:
   0386 06                   25 	.byte	6
   0387 05                   26 	.byte	5
   0388 04                   27 	.byte	4
   0389 03                   28 	.byte	3
   038A 02                   29 	.byte	2
   038B 02                   30 	.byte	2
   038C 02                   31 	.byte	2
   038D 01                   32 	.byte	1
   038E 01                   33 	.byte	1
   038F 00                   34 	.byte	0
   0390 00                   35 	.byte	0
                             36 	.globl	_CNT_DRAW3_LUT
   0391                      37 _CNT_DRAW3_LUT:
   0391 06                   38 	.byte	6
   0392 05                   39 	.byte	5
   0393 04                   40 	.byte	4
   0394 03                   41 	.byte	3
   0395 03                   42 	.byte	3
   0396 02                   43 	.byte	2
   0397 01                   44 	.byte	1
   0398 02                   45 	.byte	2
   0399 01                   46 	.byte	1
   039A 01                   47 	.byte	1
   039B 00                   48 	.byte	0
                             49 	.globl	_CNT_DRAW4_LUT
   039C                      50 _CNT_DRAW4_LUT:
   039C 06                   51 	.byte	6
   039D 05                   52 	.byte	5
   039E 04                   53 	.byte	4
   039F 03                   54 	.byte	3
   03A0 02                   55 	.byte	2
   03A1 02                   56 	.byte	2
   03A2 02                   57 	.byte	2
   03A3 01                   58 	.byte	1
   03A4 01                   59 	.byte	1
   03A5 00                   60 	.byte	0
   03A6 00                   61 	.byte	0
                             62 	.globl	_map_init
   03A7                      63 _map_init:
   03A7 F6 C8 A4      [ 5]   64 	ldb	_the_game+2
   03AA 4F            [ 2]   65 	clra		;zero_extendqihi: R:b -> R:d
   03AB 1F 01         [ 6]   66 	tfr	d,x
   03AD E6 89 03 7B   [ 8]   67 	ldb	_CNT_DRAW1_LUT,x
   03B1 8E 05 91      [ 3]   68 	ldx	#_draw_step1
   03B4 BF C8 A8      [ 6]   69 	stx	_the_map+1
   03B7 F7 C8 A7      [ 5]   70 	stb	_the_map
   03BA 39            [ 5]   71 	rts
                             72 	.globl	_vl_map_roadline_left_1
   03BB                      73 _vl_map_roadline_left_1:
   03BB FF                   74 	.byte	-1
   03BC F0                   75 	.byte	-16
   03BD FC                   76 	.byte	-4
   03BE 00                   77 	.byte	0
   03BF E4                   78 	.byte	-28
   03C0 F9                   79 	.byte	-7
   03C1 FF                   80 	.byte	-1
   03C2 D8                   81 	.byte	-40
   03C3 F6                   82 	.byte	-10
   03C4 00                   83 	.byte	0
   03C5 CC                   84 	.byte	-52
   03C6 F3                   85 	.byte	-13
   03C7 FF                   86 	.byte	-1
   03C8 C0                   87 	.byte	-64
   03C9 F0                   88 	.byte	-16
   03CA 00                   89 	.byte	0
   03CB B4                   90 	.byte	-76
   03CC ED                   91 	.byte	-19
   03CD FF                   92 	.byte	-1
   03CE A8                   93 	.byte	-88
   03CF EA                   94 	.byte	-22
   03D0 00                   95 	.byte	0
   03D1 9C                   96 	.byte	-100
   03D2 E7                   97 	.byte	-25
   03D3 FF                   98 	.byte	-1
   03D4 90                   99 	.byte	-112
   03D5 E4                  100 	.byte	-28
   03D6 00                  101 	.byte	0
   03D7 84                  102 	.byte	-124
   03D8 E1                  103 	.byte	-31
   03D9 FF                  104 	.byte	-1
   03DA BC                  105 	.byte	-68
   03DB EF                  106 	.byte	-17
   03DC FF                  107 	.byte	-1
   03DD BC                  108 	.byte	-68
   03DE EF                  109 	.byte	-17
   03DF 00                  110 	.byte	0
   03E0 B6                  111 	.byte	-74
   03E1 ED                  112 	.byte	-19
   03E2 00                  113 	.byte	0
   03E3 B6                  114 	.byte	-74
   03E4 EE                  115 	.byte	-18
   03E5 FF                  116 	.byte	-1
   03E6 B0                  117 	.byte	-80
   03E7 EC                  118 	.byte	-20
   03E8 FF                  119 	.byte	-1
   03E9 B0                  120 	.byte	-80
   03EA EC                  121 	.byte	-20
   03EB 00                  122 	.byte	0
   03EC AA                  123 	.byte	-86
   03ED EA                  124 	.byte	-22
   03EE 00                  125 	.byte	0
   03EF AA                  126 	.byte	-86
   03F0 EB                  127 	.byte	-21
   03F1 FF                  128 	.byte	-1
   03F2 84                  129 	.byte	-124
   03F3 E1                  130 	.byte	-31
   03F4                     131 _vl_term_0_37:
   03F4 01                  132 	.byte	1
                            133 	.globl	_vl_map_roadline_left_2
   03F5                     134 _vl_map_roadline_left_2:
   03F5 00                  135 	.byte	0
   03F6 F8                  136 	.byte	-8
   03F7 FE                  137 	.byte	-2
   03F8 FF                  138 	.byte	-1
   03F9 EC                  139 	.byte	-20
   03FA FB                  140 	.byte	-5
   03FB 00                  141 	.byte	0
   03FC DC                  142 	.byte	-36
   03FD F7                  143 	.byte	-9
   03FE FF                  144 	.byte	-1
   03FF D4                  145 	.byte	-44
   0400 F5                  146 	.byte	-11
   0401 00                  147 	.byte	0
   0402 C4                  148 	.byte	-60
   0403 F1                  149 	.byte	-15
   0404 FF                  150 	.byte	-1
   0405 BC                  151 	.byte	-68
   0406 EF                  152 	.byte	-17
   0407 00                  153 	.byte	0
   0408 AC                  154 	.byte	-84
   0409 EB                  155 	.byte	-21
   040A FF                  156 	.byte	-1
   040B A4                  157 	.byte	-92
   040C E9                  158 	.byte	-23
   040D 00                  159 	.byte	0
   040E 94                  160 	.byte	-108
   040F E5                  161 	.byte	-27
   0410 FF                  162 	.byte	-1
   0411 8C                  163 	.byte	-116
   0412 E3                  164 	.byte	-29
   0413 00                  165 	.byte	0
   0414 84                  166 	.byte	-124
   0415 E1                  167 	.byte	-31
   0416 00                  168 	.byte	0
   0417 F8                  169 	.byte	-8
   0418 FE                  170 	.byte	-2
   0419 FF                  171 	.byte	-1
   041A B8                  172 	.byte	-72
   041B EE                  173 	.byte	-18
   041C FF                  174 	.byte	-1
   041D BC                  175 	.byte	-68
   041E EF                  176 	.byte	-17
   041F 00                  177 	.byte	0
   0420 AE                  178 	.byte	-82
   0421 EB                  179 	.byte	-21
   0422 00                  180 	.byte	0
   0423 B6                  181 	.byte	-74
   0424 EE                  182 	.byte	-18
   0425 FF                  183 	.byte	-1
   0426 AC                  184 	.byte	-84
   0427 EB                  185 	.byte	-21
   0428 FF                  186 	.byte	-1
   0429 B0                  187 	.byte	-80
   042A EC                  188 	.byte	-20
   042B 00                  189 	.byte	0
   042C A2                  190 	.byte	-94
   042D E8                  191 	.byte	-24
   042E 00                  192 	.byte	0
   042F AA                  193 	.byte	-86
   0430 EB                  194 	.byte	-21
   0431 FF                  195 	.byte	-1
   0432 84                  196 	.byte	-124
   0433 E1                  197 	.byte	-31
   0434                     198 _vl_term_1_64:
   0434 01                  199 	.byte	1
                            200 	.globl	_vl_map_roadline_left_3
   0435                     201 _vl_map_roadline_left_3:
   0435 00                  202 	.byte	0
   0436 F0                  203 	.byte	-16
   0437 FC                  204 	.byte	-4
   0438 FF                  205 	.byte	-1
   0439 E4                  206 	.byte	-28
   043A F9                  207 	.byte	-7
   043B 00                  208 	.byte	0
   043C D8                  209 	.byte	-40
   043D F6                  210 	.byte	-10
   043E FF                  211 	.byte	-1
   043F CC                  212 	.byte	-52
   0440 F3                  213 	.byte	-13
   0441 00                  214 	.byte	0
   0442 C0                  215 	.byte	-64
   0443 F0                  216 	.byte	-16
   0444 FF                  217 	.byte	-1
   0445 B4                  218 	.byte	-76
   0446 ED                  219 	.byte	-19
   0447 00                  220 	.byte	0
   0448 A8                  221 	.byte	-88
   0449 EA                  222 	.byte	-22
   044A FF                  223 	.byte	-1
   044B 9C                  224 	.byte	-100
   044C E7                  225 	.byte	-25
   044D 00                  226 	.byte	0
   044E 90                  227 	.byte	-112
   044F E4                  228 	.byte	-28
   0450 FF                  229 	.byte	-1
   0451 84                  230 	.byte	-124
   0452 E1                  231 	.byte	-31
   0453 00                  232 	.byte	0
   0454 84                  233 	.byte	-124
   0455 E1                  234 	.byte	-31
   0456 00                  235 	.byte	0
   0457 F4                  236 	.byte	-12
   0458 FD                  237 	.byte	-3
   0459 FF                  238 	.byte	-1
   045A B0                  239 	.byte	-80
   045B EC                  240 	.byte	-20
   045C FF                  241 	.byte	-1
   045D BC                  242 	.byte	-68
   045E EF                  243 	.byte	-17
   045F 00                  244 	.byte	0
   0460 AA                  245 	.byte	-86
   0461 EA                  246 	.byte	-22
   0462 00                  247 	.byte	0
   0463 B6                  248 	.byte	-74
   0464 EE                  249 	.byte	-18
   0465 FF                  250 	.byte	-1
   0466 A4                  251 	.byte	-92
   0467 E9                  252 	.byte	-23
   0468 FF                  253 	.byte	-1
   0469 B0                  254 	.byte	-80
   046A EC                  255 	.byte	-20
   046B                     256 _vl_term_2_88:
   046B 01                  257 	.byte	1
                            258 	.globl	_vl_map_roadline_left_4
   046C                     259 _vl_map_roadline_left_4:
   046C FF                  260 	.byte	-1
   046D F8                  261 	.byte	-8
   046E FE                  262 	.byte	-2
   046F 00                  263 	.byte	0
   0470 F0                  264 	.byte	-16
   0471 FC                  265 	.byte	-4
   0472 FF                  266 	.byte	-1
   0473 E0                  267 	.byte	-32
   0474 F8                  268 	.byte	-8
   0475 00                  269 	.byte	0
   0476 D0                  270 	.byte	-48
   0477 F4                  271 	.byte	-12
   0478 FF                  272 	.byte	-1
   0479 C8                  273 	.byte	-56
   047A F2                  274 	.byte	-14
   047B 00                  275 	.byte	0
   047C B8                  276 	.byte	-72
   047D EE                  277 	.byte	-18
   047E FF                  278 	.byte	-1
   047F B0                  279 	.byte	-80
   0480 EC                  280 	.byte	-20
   0481 00                  281 	.byte	0
   0482 A0                  282 	.byte	-96
   0483 E8                  283 	.byte	-24
   0484 FF                  284 	.byte	-1
   0485 98                  285 	.byte	-104
   0486 E6                  286 	.byte	-26
   0487 00                  287 	.byte	0
   0488 88                  288 	.byte	-120
   0489 E2                  289 	.byte	-30
   048A FF                  290 	.byte	-1
   048B 81                  291 	.byte	-127
   048C E0                  292 	.byte	-32
   048D 00                  293 	.byte	0
   048E 84                  294 	.byte	-124
   048F E1                  295 	.byte	-31
   0490 00                  296 	.byte	0
   0491 EC                  297 	.byte	-20
   0492 FB                  298 	.byte	-5
   0493 FF                  299 	.byte	-1
   0494 AC                  300 	.byte	-84
   0495 EB                  301 	.byte	-21
   0496 FF                  302 	.byte	-1
   0497 BC                  303 	.byte	-68
   0498 EF                  304 	.byte	-17
   0499 00                  305 	.byte	0
   049A A2                  306 	.byte	-94
   049B E8                  307 	.byte	-24
   049C 00                  308 	.byte	0
   049D B6                  309 	.byte	-74
   049E EE                  310 	.byte	-18
   049F FF                  311 	.byte	-1
   04A0 A0                  312 	.byte	-96
   04A1 E8                  313 	.byte	-24
   04A2 FF                  314 	.byte	-1
   04A3 B0                  315 	.byte	-80
   04A4 EC                  316 	.byte	-20
   04A5                     317 _vl_term_3_113:
   04A5 01                  318 	.byte	1
                            319 	.globl	_vl_map_roadline_right_1
   04A6                     320 _vl_map_roadline_right_1:
   04A6 FF                  321 	.byte	-1
   04A7 F0                  322 	.byte	-16
   04A8 04                  323 	.byte	4
   04A9 00                  324 	.byte	0
   04AA E4                  325 	.byte	-28
   04AB 07                  326 	.byte	7
   04AC FF                  327 	.byte	-1
   04AD D8                  328 	.byte	-40
   04AE 0A                  329 	.byte	10
   04AF 00                  330 	.byte	0
   04B0 CC                  331 	.byte	-52
   04B1 0D                  332 	.byte	13
   04B2 FF                  333 	.byte	-1
   04B3 C0                  334 	.byte	-64
   04B4 10                  335 	.byte	16
   04B5 00                  336 	.byte	0
   04B6 B4                  337 	.byte	-76
   04B7 13                  338 	.byte	19
   04B8 FF                  339 	.byte	-1
   04B9 A8                  340 	.byte	-88
   04BA 16                  341 	.byte	22
   04BB 00                  342 	.byte	0
   04BC 9C                  343 	.byte	-100
   04BD 19                  344 	.byte	25
   04BE FF                  345 	.byte	-1
   04BF 90                  346 	.byte	-112
   04C0 1C                  347 	.byte	28
   04C1 00                  348 	.byte	0
   04C2 84                  349 	.byte	-124
   04C3 1F                  350 	.byte	31
   04C4 FF                  351 	.byte	-1
   04C5 BC                  352 	.byte	-68
   04C6 11                  353 	.byte	17
   04C7 FF                  354 	.byte	-1
   04C8 BC                  355 	.byte	-68
   04C9 11                  356 	.byte	17
   04CA 00                  357 	.byte	0
   04CB B6                  358 	.byte	-74
   04CC 13                  359 	.byte	19
   04CD 00                  360 	.byte	0
   04CE B6                  361 	.byte	-74
   04CF 12                  362 	.byte	18
   04D0 FF                  363 	.byte	-1
   04D1 B0                  364 	.byte	-80
   04D2 14                  365 	.byte	20
   04D3 FF                  366 	.byte	-1
   04D4 B0                  367 	.byte	-80
   04D5 14                  368 	.byte	20
   04D6 00                  369 	.byte	0
   04D7 AA                  370 	.byte	-86
   04D8 16                  371 	.byte	22
   04D9 00                  372 	.byte	0
   04DA AA                  373 	.byte	-86
   04DB 15                  374 	.byte	21
   04DC FF                  375 	.byte	-1
   04DD 84                  376 	.byte	-124
   04DE 1F                  377 	.byte	31
   04DF                     378 _vl_term_4_145:
   04DF 01                  379 	.byte	1
                            380 	.globl	_vl_map_roadline_right_2
   04E0                     381 _vl_map_roadline_right_2:
   04E0 00                  382 	.byte	0
   04E1 F8                  383 	.byte	-8
   04E2 02                  384 	.byte	2
   04E3 FF                  385 	.byte	-1
   04E4 EC                  386 	.byte	-20
   04E5 05                  387 	.byte	5
   04E6 00                  388 	.byte	0
   04E7 DC                  389 	.byte	-36
   04E8 09                  390 	.byte	9
   04E9 FF                  391 	.byte	-1
   04EA D4                  392 	.byte	-44
   04EB 0B                  393 	.byte	11
   04EC 00                  394 	.byte	0
   04ED C4                  395 	.byte	-60
   04EE 0F                  396 	.byte	15
   04EF FF                  397 	.byte	-1
   04F0 BC                  398 	.byte	-68
   04F1 11                  399 	.byte	17
   04F2 00                  400 	.byte	0
   04F3 AC                  401 	.byte	-84
   04F4 15                  402 	.byte	21
   04F5 FF                  403 	.byte	-1
   04F6 A4                  404 	.byte	-92
   04F7 17                  405 	.byte	23
   04F8 00                  406 	.byte	0
   04F9 94                  407 	.byte	-108
   04FA 1B                  408 	.byte	27
   04FB FF                  409 	.byte	-1
   04FC 8C                  410 	.byte	-116
   04FD 1D                  411 	.byte	29
   04FE 00                  412 	.byte	0
   04FF 84                  413 	.byte	-124
   0500 1F                  414 	.byte	31
   0501 00                  415 	.byte	0
   0502 F8                  416 	.byte	-8
   0503 02                  417 	.byte	2
   0504 FF                  418 	.byte	-1
   0505 B8                  419 	.byte	-72
   0506 12                  420 	.byte	18
   0507 FF                  421 	.byte	-1
   0508 BC                  422 	.byte	-68
   0509 11                  423 	.byte	17
   050A 00                  424 	.byte	0
   050B AE                  425 	.byte	-82
   050C 15                  426 	.byte	21
   050D 00                  427 	.byte	0
   050E B6                  428 	.byte	-74
   050F 12                  429 	.byte	18
   0510 FF                  430 	.byte	-1
   0511 AC                  431 	.byte	-84
   0512 15                  432 	.byte	21
   0513 FF                  433 	.byte	-1
   0514 B0                  434 	.byte	-80
   0515 14                  435 	.byte	20
   0516 00                  436 	.byte	0
   0517 A2                  437 	.byte	-94
   0518 18                  438 	.byte	24
   0519 00                  439 	.byte	0
   051A AA                  440 	.byte	-86
   051B 15                  441 	.byte	21
   051C FF                  442 	.byte	-1
   051D 84                  443 	.byte	-124
   051E 1F                  444 	.byte	31
   051F                     445 _vl_term_5_172:
   051F 01                  446 	.byte	1
                            447 	.globl	_vl_map_roadline_right_3
   0520                     448 _vl_map_roadline_right_3:
   0520 00                  449 	.byte	0
   0521 F0                  450 	.byte	-16
   0522 04                  451 	.byte	4
   0523 FF                  452 	.byte	-1
   0524 E4                  453 	.byte	-28
   0525 07                  454 	.byte	7
   0526 00                  455 	.byte	0
   0527 D8                  456 	.byte	-40
   0528 0A                  457 	.byte	10
   0529 FF                  458 	.byte	-1
   052A CC                  459 	.byte	-52
   052B 0D                  460 	.byte	13
   052C 00                  461 	.byte	0
   052D C0                  462 	.byte	-64
   052E 10                  463 	.byte	16
   052F FF                  464 	.byte	-1
   0530 B4                  465 	.byte	-76
   0531 13                  466 	.byte	19
   0532 00                  467 	.byte	0
   0533 A8                  468 	.byte	-88
   0534 16                  469 	.byte	22
   0535 FF                  470 	.byte	-1
   0536 9C                  471 	.byte	-100
   0537 19                  472 	.byte	25
   0538 00                  473 	.byte	0
   0539 90                  474 	.byte	-112
   053A 1C                  475 	.byte	28
   053B FF                  476 	.byte	-1
   053C 84                  477 	.byte	-124
   053D 1F                  478 	.byte	31
   053E 00                  479 	.byte	0
   053F 84                  480 	.byte	-124
   0540 1F                  481 	.byte	31
   0541 00                  482 	.byte	0
   0542 F4                  483 	.byte	-12
   0543 03                  484 	.byte	3
   0544 FF                  485 	.byte	-1
   0545 B0                  486 	.byte	-80
   0546 14                  487 	.byte	20
   0547 FF                  488 	.byte	-1
   0548 BC                  489 	.byte	-68
   0549 11                  490 	.byte	17
   054A 00                  491 	.byte	0
   054B AA                  492 	.byte	-86
   054C 16                  493 	.byte	22
   054D 00                  494 	.byte	0
   054E B6                  495 	.byte	-74
   054F 12                  496 	.byte	18
   0550 FF                  497 	.byte	-1
   0551 A4                  498 	.byte	-92
   0552 17                  499 	.byte	23
   0553 FF                  500 	.byte	-1
   0554 B0                  501 	.byte	-80
   0555 14                  502 	.byte	20
   0556                     503 _vl_term_6_196:
   0556 01                  504 	.byte	1
                            505 	.globl	_vl_map_roadline_right_4
   0557                     506 _vl_map_roadline_right_4:
   0557 FF                  507 	.byte	-1
   0558 F8                  508 	.byte	-8
   0559 02                  509 	.byte	2
   055A 00                  510 	.byte	0
   055B F0                  511 	.byte	-16
   055C 04                  512 	.byte	4
   055D FF                  513 	.byte	-1
   055E E0                  514 	.byte	-32
   055F 08                  515 	.byte	8
   0560 00                  516 	.byte	0
   0561 D0                  517 	.byte	-48
   0562 0C                  518 	.byte	12
   0563 FF                  519 	.byte	-1
   0564 C8                  520 	.byte	-56
   0565 0E                  521 	.byte	14
   0566 00                  522 	.byte	0
   0567 B8                  523 	.byte	-72
   0568 12                  524 	.byte	18
   0569 FF                  525 	.byte	-1
   056A B0                  526 	.byte	-80
   056B 14                  527 	.byte	20
   056C 00                  528 	.byte	0
   056D A0                  529 	.byte	-96
   056E 18                  530 	.byte	24
   056F FF                  531 	.byte	-1
   0570 98                  532 	.byte	-104
   0571 1A                  533 	.byte	26
   0572 00                  534 	.byte	0
   0573 88                  535 	.byte	-120
   0574 1E                  536 	.byte	30
   0575 FF                  537 	.byte	-1
   0576 81                  538 	.byte	-127
   0577 20                  539 	.byte	32
   0578 00                  540 	.byte	0
   0579 84                  541 	.byte	-124
   057A 1F                  542 	.byte	31
   057B 00                  543 	.byte	0
   057C EC                  544 	.byte	-20
   057D 05                  545 	.byte	5
   057E FF                  546 	.byte	-1
   057F AC                  547 	.byte	-84
   0580 15                  548 	.byte	21
   0581 FF                  549 	.byte	-1
   0582 BC                  550 	.byte	-68
   0583 11                  551 	.byte	17
   0584 00                  552 	.byte	0
   0585 A2                  553 	.byte	-94
   0586 18                  554 	.byte	24
   0587 00                  555 	.byte	0
   0588 B6                  556 	.byte	-74
   0589 12                  557 	.byte	18
   058A FF                  558 	.byte	-1
   058B A0                  559 	.byte	-96
   058C 18                  560 	.byte	24
   058D FF                  561 	.byte	-1
   058E B0                  562 	.byte	-80
   058F 14                  563 	.byte	20
   0590                     564 _vl_term_7_221:
   0590 01                  565 	.byte	1
                            566 	.globl	_draw_step1
   0591                     567 _draw_step1:
   0591 BD F2 A5      [ 8]  568 	jsr	___Intensity_5F
   0594 BD F3 54      [ 8]  569 	jsr	___Reset0Ref
   0597 C6 7F         [ 2]  570 	ldb	#127
   0599 D7 04         [ 4]  571 	stb	*_dp_VIA_t1_cnt_lo
   059B C6 24         [ 2]  572 	ldb	#36
   059D E7 E2         [ 6]  573 	stb	,-s
   059F C6 F1         [ 2]  574 	ldb	#-15
   05A1 BD 0F 6E      [ 8]  575 	jsr	__Moveto_d
   05A4 C6 A8         [ 2]  576 	ldb	#-88
   05A6 D7 04         [ 4]  577 	stb	*_dp_VIA_t1_cnt_lo
   05A8 C6 80         [ 2]  578 	ldb	#-128
   05AA E7 E2         [ 6]  579 	stb	,-s
   05AC CB 2E         [ 2]  580 	addb	#46
   05AE BD 0F 69      [ 8]  581 	jsr	__Draw_Line_d
   05B1 BD F3 54      [ 8]  582 	jsr	___Reset0Ref
   05B4 C6 7F         [ 2]  583 	ldb	#127
   05B6 D7 04         [ 4]  584 	stb	*_dp_VIA_t1_cnt_lo
   05B8 C6 24         [ 2]  585 	ldb	#36
   05BA E7 E2         [ 6]  586 	stb	,-s
   05BC C6 FB         [ 2]  587 	ldb	#-5
   05BE BD 0F 6E      [ 8]  588 	jsr	__Moveto_d
   05C1 C6 10         [ 2]  589 	ldb	#16
   05C3 D7 04         [ 4]  590 	stb	*_dp_VIA_t1_cnt_lo
   05C5 8E 03 BB      [ 3]  591 	ldx	#_vl_map_roadline_left_1
   05C8 BD F4 10      [ 8]  592 	jsr	___Draw_VLp
   05CB BD F3 54      [ 8]  593 	jsr	___Reset0Ref
   05CE C6 7F         [ 2]  594 	ldb	#127
   05D0 D7 04         [ 4]  595 	stb	*_dp_VIA_t1_cnt_lo
   05D2 C6 24         [ 2]  596 	ldb	#36
   05D4 E7 E2         [ 6]  597 	stb	,-s
   05D6 C6 05         [ 2]  598 	ldb	#5
   05D8 BD 0F 6E      [ 8]  599 	jsr	__Moveto_d
   05DB C6 10         [ 2]  600 	ldb	#16
   05DD D7 04         [ 4]  601 	stb	*_dp_VIA_t1_cnt_lo
   05DF 8E 04 A6      [ 3]  602 	ldx	#_vl_map_roadline_right_1
   05E2 BD F4 10      [ 8]  603 	jsr	___Draw_VLp
   05E5 BD F3 54      [ 8]  604 	jsr	___Reset0Ref
   05E8 C6 7F         [ 2]  605 	ldb	#127
   05EA D7 04         [ 4]  606 	stb	*_dp_VIA_t1_cnt_lo
   05EC C6 24         [ 2]  607 	ldb	#36
   05EE E7 E2         [ 6]  608 	stb	,-s
   05F0 C6 0F         [ 2]  609 	ldb	#15
   05F2 BD 0F 6E      [ 8]  610 	jsr	__Moveto_d
   05F5 C6 A8         [ 2]  611 	ldb	#-88
   05F7 D7 04         [ 4]  612 	stb	*_dp_VIA_t1_cnt_lo
   05F9 C6 80         [ 2]  613 	ldb	#-128
   05FB E7 E2         [ 6]  614 	stb	,-s
   05FD C6 52         [ 2]  615 	ldb	#82
   05FF BD 0F 69      [ 8]  616 	jsr	__Draw_Line_d
   0602 F6 C8 A7      [ 5]  617 	ldb	_the_map
   0605 32 66         [ 5]  618 	leas	6,s
   0607 5D            [ 2]  619 	tstb
   0608 27 05         [ 3]  620 	beq	L8
   060A 5A            [ 2]  621 	decb
   060B F7 C8 A7      [ 5]  622 	stb	_the_map
   060E 39            [ 5]  623 	rts
   060F                     624 L8:
   060F 8E 06 23      [ 3]  625 	ldx	#_draw_step2
   0612 BF C8 A8      [ 6]  626 	stx	_the_map+1
   0615 F6 C8 A4      [ 5]  627 	ldb	_the_game+2
   0618 4F            [ 2]  628 	clra		;zero_extendqihi: R:b -> R:d
   0619 1F 01         [ 6]  629 	tfr	d,x
   061B E6 89 03 86   [ 8]  630 	ldb	_CNT_DRAW2_LUT,x
   061F F7 C8 A7      [ 5]  631 	stb	_the_map
   0622 39            [ 5]  632 	rts
                            633 	.globl	_draw_step2
   0623                     634 _draw_step2:
   0623 BD F2 A5      [ 8]  635 	jsr	___Intensity_5F
   0626 BD F3 54      [ 8]  636 	jsr	___Reset0Ref
   0629 C6 7F         [ 2]  637 	ldb	#127
   062B D7 04         [ 4]  638 	stb	*_dp_VIA_t1_cnt_lo
   062D C6 24         [ 2]  639 	ldb	#36
   062F E7 E2         [ 6]  640 	stb	,-s
   0631 C6 F1         [ 2]  641 	ldb	#-15
   0633 BD 0F 6E      [ 8]  642 	jsr	__Moveto_d
   0636 C6 A8         [ 2]  643 	ldb	#-88
   0638 D7 04         [ 4]  644 	stb	*_dp_VIA_t1_cnt_lo
   063A C6 80         [ 2]  645 	ldb	#-128
   063C E7 E2         [ 6]  646 	stb	,-s
   063E CB 2E         [ 2]  647 	addb	#46
   0640 BD 0F 69      [ 8]  648 	jsr	__Draw_Line_d
   0643 BD F3 54      [ 8]  649 	jsr	___Reset0Ref
   0646 C6 7F         [ 2]  650 	ldb	#127
   0648 D7 04         [ 4]  651 	stb	*_dp_VIA_t1_cnt_lo
   064A C6 24         [ 2]  652 	ldb	#36
   064C E7 E2         [ 6]  653 	stb	,-s
   064E C6 FB         [ 2]  654 	ldb	#-5
   0650 BD 0F 6E      [ 8]  655 	jsr	__Moveto_d
   0653 C6 10         [ 2]  656 	ldb	#16
   0655 D7 04         [ 4]  657 	stb	*_dp_VIA_t1_cnt_lo
   0657 8E 03 F5      [ 3]  658 	ldx	#_vl_map_roadline_left_2
   065A BD F4 10      [ 8]  659 	jsr	___Draw_VLp
   065D BD F3 54      [ 8]  660 	jsr	___Reset0Ref
   0660 C6 7F         [ 2]  661 	ldb	#127
   0662 D7 04         [ 4]  662 	stb	*_dp_VIA_t1_cnt_lo
   0664 C6 24         [ 2]  663 	ldb	#36
   0666 E7 E2         [ 6]  664 	stb	,-s
   0668 C6 05         [ 2]  665 	ldb	#5
   066A BD 0F 6E      [ 8]  666 	jsr	__Moveto_d
   066D C6 10         [ 2]  667 	ldb	#16
   066F D7 04         [ 4]  668 	stb	*_dp_VIA_t1_cnt_lo
   0671 8E 04 E0      [ 3]  669 	ldx	#_vl_map_roadline_right_2
   0674 BD F4 10      [ 8]  670 	jsr	___Draw_VLp
   0677 BD F3 54      [ 8]  671 	jsr	___Reset0Ref
   067A C6 7F         [ 2]  672 	ldb	#127
   067C D7 04         [ 4]  673 	stb	*_dp_VIA_t1_cnt_lo
   067E C6 24         [ 2]  674 	ldb	#36
   0680 E7 E2         [ 6]  675 	stb	,-s
   0682 C6 0F         [ 2]  676 	ldb	#15
   0684 BD 0F 6E      [ 8]  677 	jsr	__Moveto_d
   0687 C6 A8         [ 2]  678 	ldb	#-88
   0689 D7 04         [ 4]  679 	stb	*_dp_VIA_t1_cnt_lo
   068B C6 80         [ 2]  680 	ldb	#-128
   068D E7 E2         [ 6]  681 	stb	,-s
   068F C6 52         [ 2]  682 	ldb	#82
   0691 BD 0F 69      [ 8]  683 	jsr	__Draw_Line_d
   0694 F6 C8 A7      [ 5]  684 	ldb	_the_map
   0697 32 66         [ 5]  685 	leas	6,s
   0699 5D            [ 2]  686 	tstb
   069A 27 05         [ 3]  687 	beq	L13
   069C 5A            [ 2]  688 	decb
   069D F7 C8 A7      [ 5]  689 	stb	_the_map
   06A0 39            [ 5]  690 	rts
   06A1                     691 L13:
   06A1 8E 06 B5      [ 3]  692 	ldx	#_draw_step3
   06A4 BF C8 A8      [ 6]  693 	stx	_the_map+1
   06A7 F6 C8 A4      [ 5]  694 	ldb	_the_game+2
   06AA 4F            [ 2]  695 	clra		;zero_extendqihi: R:b -> R:d
   06AB 1F 01         [ 6]  696 	tfr	d,x
   06AD E6 89 03 91   [ 8]  697 	ldb	_CNT_DRAW3_LUT,x
   06B1 F7 C8 A7      [ 5]  698 	stb	_the_map
   06B4 39            [ 5]  699 	rts
                            700 	.globl	_draw_step3
   06B5                     701 _draw_step3:
   06B5 BD F2 A5      [ 8]  702 	jsr	___Intensity_5F
   06B8 BD F3 54      [ 8]  703 	jsr	___Reset0Ref
   06BB C6 7F         [ 2]  704 	ldb	#127
   06BD D7 04         [ 4]  705 	stb	*_dp_VIA_t1_cnt_lo
   06BF C6 24         [ 2]  706 	ldb	#36
   06C1 E7 E2         [ 6]  707 	stb	,-s
   06C3 C6 F1         [ 2]  708 	ldb	#-15
   06C5 BD 0F 6E      [ 8]  709 	jsr	__Moveto_d
   06C8 C6 A8         [ 2]  710 	ldb	#-88
   06CA D7 04         [ 4]  711 	stb	*_dp_VIA_t1_cnt_lo
   06CC C6 80         [ 2]  712 	ldb	#-128
   06CE E7 E2         [ 6]  713 	stb	,-s
   06D0 CB 2E         [ 2]  714 	addb	#46
   06D2 BD 0F 69      [ 8]  715 	jsr	__Draw_Line_d
   06D5 BD F3 54      [ 8]  716 	jsr	___Reset0Ref
   06D8 C6 7F         [ 2]  717 	ldb	#127
   06DA D7 04         [ 4]  718 	stb	*_dp_VIA_t1_cnt_lo
   06DC C6 24         [ 2]  719 	ldb	#36
   06DE E7 E2         [ 6]  720 	stb	,-s
   06E0 C6 FB         [ 2]  721 	ldb	#-5
   06E2 BD 0F 6E      [ 8]  722 	jsr	__Moveto_d
   06E5 C6 10         [ 2]  723 	ldb	#16
   06E7 D7 04         [ 4]  724 	stb	*_dp_VIA_t1_cnt_lo
   06E9 8E 04 35      [ 3]  725 	ldx	#_vl_map_roadline_left_3
   06EC BD F4 10      [ 8]  726 	jsr	___Draw_VLp
   06EF BD F3 54      [ 8]  727 	jsr	___Reset0Ref
   06F2 C6 7F         [ 2]  728 	ldb	#127
   06F4 D7 04         [ 4]  729 	stb	*_dp_VIA_t1_cnt_lo
   06F6 C6 24         [ 2]  730 	ldb	#36
   06F8 E7 E2         [ 6]  731 	stb	,-s
   06FA C6 05         [ 2]  732 	ldb	#5
   06FC BD 0F 6E      [ 8]  733 	jsr	__Moveto_d
   06FF C6 10         [ 2]  734 	ldb	#16
   0701 D7 04         [ 4]  735 	stb	*_dp_VIA_t1_cnt_lo
   0703 8E 05 20      [ 3]  736 	ldx	#_vl_map_roadline_right_3
   0706 BD F4 10      [ 8]  737 	jsr	___Draw_VLp
   0709 BD F3 54      [ 8]  738 	jsr	___Reset0Ref
   070C C6 7F         [ 2]  739 	ldb	#127
   070E D7 04         [ 4]  740 	stb	*_dp_VIA_t1_cnt_lo
   0710 C6 24         [ 2]  741 	ldb	#36
   0712 E7 E2         [ 6]  742 	stb	,-s
   0714 C6 0F         [ 2]  743 	ldb	#15
   0716 BD 0F 6E      [ 8]  744 	jsr	__Moveto_d
   0719 C6 A8         [ 2]  745 	ldb	#-88
   071B D7 04         [ 4]  746 	stb	*_dp_VIA_t1_cnt_lo
   071D C6 80         [ 2]  747 	ldb	#-128
   071F E7 E2         [ 6]  748 	stb	,-s
   0721 C6 52         [ 2]  749 	ldb	#82
   0723 BD 0F 69      [ 8]  750 	jsr	__Draw_Line_d
   0726 F6 C8 A7      [ 5]  751 	ldb	_the_map
   0729 32 66         [ 5]  752 	leas	6,s
   072B 5D            [ 2]  753 	tstb
   072C 27 05         [ 3]  754 	beq	L18
   072E 5A            [ 2]  755 	decb
   072F F7 C8 A7      [ 5]  756 	stb	_the_map
   0732 39            [ 5]  757 	rts
   0733                     758 L18:
   0733 8E 07 47      [ 3]  759 	ldx	#_draw_step4
   0736 BF C8 A8      [ 6]  760 	stx	_the_map+1
   0739 F6 C8 A4      [ 5]  761 	ldb	_the_game+2
   073C 4F            [ 2]  762 	clra		;zero_extendqihi: R:b -> R:d
   073D 1F 01         [ 6]  763 	tfr	d,x
   073F E6 89 03 9C   [ 8]  764 	ldb	_CNT_DRAW4_LUT,x
   0743 F7 C8 A7      [ 5]  765 	stb	_the_map
   0746 39            [ 5]  766 	rts
                            767 	.globl	_draw_step4
   0747                     768 _draw_step4:
   0747 BD F2 A5      [ 8]  769 	jsr	___Intensity_5F
   074A BD F3 54      [ 8]  770 	jsr	___Reset0Ref
   074D C6 7F         [ 2]  771 	ldb	#127
   074F D7 04         [ 4]  772 	stb	*_dp_VIA_t1_cnt_lo
   0751 C6 24         [ 2]  773 	ldb	#36
   0753 E7 E2         [ 6]  774 	stb	,-s
   0755 C6 F1         [ 2]  775 	ldb	#-15
   0757 BD 0F 6E      [ 8]  776 	jsr	__Moveto_d
   075A C6 A8         [ 2]  777 	ldb	#-88
   075C D7 04         [ 4]  778 	stb	*_dp_VIA_t1_cnt_lo
   075E C6 80         [ 2]  779 	ldb	#-128
   0760 E7 E2         [ 6]  780 	stb	,-s
   0762 CB 2E         [ 2]  781 	addb	#46
   0764 BD 0F 69      [ 8]  782 	jsr	__Draw_Line_d
   0767 BD F3 54      [ 8]  783 	jsr	___Reset0Ref
   076A C6 7F         [ 2]  784 	ldb	#127
   076C D7 04         [ 4]  785 	stb	*_dp_VIA_t1_cnt_lo
   076E C6 24         [ 2]  786 	ldb	#36
   0770 E7 E2         [ 6]  787 	stb	,-s
   0772 C6 FB         [ 2]  788 	ldb	#-5
   0774 BD 0F 6E      [ 8]  789 	jsr	__Moveto_d
   0777 C6 10         [ 2]  790 	ldb	#16
   0779 D7 04         [ 4]  791 	stb	*_dp_VIA_t1_cnt_lo
   077B 8E 04 6C      [ 3]  792 	ldx	#_vl_map_roadline_left_4
   077E BD F4 10      [ 8]  793 	jsr	___Draw_VLp
   0781 BD F3 54      [ 8]  794 	jsr	___Reset0Ref
   0784 C6 7F         [ 2]  795 	ldb	#127
   0786 D7 04         [ 4]  796 	stb	*_dp_VIA_t1_cnt_lo
   0788 C6 24         [ 2]  797 	ldb	#36
   078A E7 E2         [ 6]  798 	stb	,-s
   078C C6 05         [ 2]  799 	ldb	#5
   078E BD 0F 6E      [ 8]  800 	jsr	__Moveto_d
   0791 C6 10         [ 2]  801 	ldb	#16
   0793 D7 04         [ 4]  802 	stb	*_dp_VIA_t1_cnt_lo
   0795 8E 05 57      [ 3]  803 	ldx	#_vl_map_roadline_right_4
   0798 BD F4 10      [ 8]  804 	jsr	___Draw_VLp
   079B BD F3 54      [ 8]  805 	jsr	___Reset0Ref
   079E C6 7F         [ 2]  806 	ldb	#127
   07A0 D7 04         [ 4]  807 	stb	*_dp_VIA_t1_cnt_lo
   07A2 C6 24         [ 2]  808 	ldb	#36
   07A4 E7 E2         [ 6]  809 	stb	,-s
   07A6 C6 0F         [ 2]  810 	ldb	#15
   07A8 BD 0F 6E      [ 8]  811 	jsr	__Moveto_d
   07AB C6 A8         [ 2]  812 	ldb	#-88
   07AD D7 04         [ 4]  813 	stb	*_dp_VIA_t1_cnt_lo
   07AF C6 80         [ 2]  814 	ldb	#-128
   07B1 E7 E2         [ 6]  815 	stb	,-s
   07B3 C6 52         [ 2]  816 	ldb	#82
   07B5 BD 0F 69      [ 8]  817 	jsr	__Draw_Line_d
   07B8 F6 C8 A7      [ 5]  818 	ldb	_the_map
   07BB 32 66         [ 5]  819 	leas	6,s
   07BD 5D            [ 2]  820 	tstb
   07BE 27 05         [ 3]  821 	beq	L23
   07C0 5A            [ 2]  822 	decb
   07C1 F7 C8 A7      [ 5]  823 	stb	_the_map
   07C4 39            [ 5]  824 	rts
   07C5                     825 L23:
   07C5 8E 05 91      [ 3]  826 	ldx	#_draw_step1
   07C8 BF C8 A8      [ 6]  827 	stx	_the_map+1
   07CB F6 C8 A4      [ 5]  828 	ldb	_the_game+2
   07CE 4F            [ 2]  829 	clra		;zero_extendqihi: R:b -> R:d
   07CF 1F 01         [ 6]  830 	tfr	d,x
   07D1 E6 89 03 7B   [ 8]  831 	ldb	_CNT_DRAW1_LUT,x
   07D5 F7 C8 A7      [ 5]  832 	stb	_the_map
   07D8 39            [ 5]  833 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Sat Jun 14 01:20:49 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L13                0326 R   |   3 L18                03B8 R
  3 L23                044A R   |   3 L8                 0294 R
  3 _CNT_DRAW1_LUT     0000 GR  |   3 _CNT_DRAW2_LUT     000B GR
  3 _CNT_DRAW3_LUT     0016 GR  |   3 _CNT_DRAW4_LUT     0021 GR
    __Draw_Line_d      **** GX  |     __Moveto_d         **** GX
    ___Draw_VLp        **** GX  |     ___Intensity_5     **** GX
    ___Reset0Ref       **** GX  |     _dp_VIA_t1_cnt     **** GX
  3 _draw_step1        0216 GR  |   3 _draw_step2        02A8 GR
  3 _draw_step3        033A GR  |   3 _draw_step4        03CC GR
  3 _map_init          002C GR  |     _the_game          **** GX
  2 _the_map           0000 GR  |   3 _vl_map_roadli     0040 GR
  3 _vl_map_roadli     007A GR  |   3 _vl_map_roadli     00BA GR
  3 _vl_map_roadli     00F1 GR  |   3 _vl_map_roadli     012B GR
  3 _vl_map_roadli     0165 GR  |   3 _vl_map_roadli     01A5 GR
  3 _vl_map_roadli     01DC GR  |   3 _vl_term_0_37      0079 R
  3 _vl_term_1_64      00B9 R   |   3 _vl_term_2_88      00F0 R
  3 _vl_term_3_113     012A R   |   3 _vl_term_4_145     0164 R
  3 _vl_term_5_172     01A4 R   |   3 _vl_term_6_196     01DB R
  3 _vl_term_7_221     0215 R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Sat Jun 14 01:20:49 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    3   flags    0
   3 .text            size  45E   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

