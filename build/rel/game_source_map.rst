                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	map.c
                              6 	.area	.bss
                              7 	.globl	_the_map
   C8A8                       8 _the_map:	.blkb	3
                              9 	.globl	_CNT_DRAW1_LUT
                             10 	.area	.text
   039E                      11 _CNT_DRAW1_LUT:
   039E 06                   12 	.byte	6
   039F 05                   13 	.byte	5
   03A0 04                   14 	.byte	4
   03A1 04                   15 	.byte	4
   03A2 03                   16 	.byte	3
   03A3 02                   17 	.byte	2
   03A4 02                   18 	.byte	2
   03A5 02                   19 	.byte	2
   03A6 01                   20 	.byte	1
   03A7 01                   21 	.byte	1
   03A8 00                   22 	.byte	0
                             23 	.globl	_CNT_DRAW2_LUT
   03A9                      24 _CNT_DRAW2_LUT:
   03A9 06                   25 	.byte	6
   03AA 05                   26 	.byte	5
   03AB 04                   27 	.byte	4
   03AC 03                   28 	.byte	3
   03AD 02                   29 	.byte	2
   03AE 02                   30 	.byte	2
   03AF 02                   31 	.byte	2
   03B0 01                   32 	.byte	1
   03B1 01                   33 	.byte	1
   03B2 00                   34 	.byte	0
   03B3 00                   35 	.byte	0
                             36 	.globl	_CNT_DRAW3_LUT
   03B4                      37 _CNT_DRAW3_LUT:
   03B4 06                   38 	.byte	6
   03B5 05                   39 	.byte	5
   03B6 04                   40 	.byte	4
   03B7 03                   41 	.byte	3
   03B8 03                   42 	.byte	3
   03B9 02                   43 	.byte	2
   03BA 01                   44 	.byte	1
   03BB 02                   45 	.byte	2
   03BC 01                   46 	.byte	1
   03BD 01                   47 	.byte	1
   03BE 00                   48 	.byte	0
                             49 	.globl	_CNT_DRAW4_LUT
   03BF                      50 _CNT_DRAW4_LUT:
   03BF 06                   51 	.byte	6
   03C0 05                   52 	.byte	5
   03C1 04                   53 	.byte	4
   03C2 03                   54 	.byte	3
   03C3 02                   55 	.byte	2
   03C4 02                   56 	.byte	2
   03C5 02                   57 	.byte	2
   03C6 01                   58 	.byte	1
   03C7 01                   59 	.byte	1
   03C8 00                   60 	.byte	0
   03C9 00                   61 	.byte	0
                             62 	.globl	_map_init
   03CA                      63 _map_init:
   03CA F6 C8 A5      [ 5]   64 	ldb	_the_game+2
   03CD 4F            [ 2]   65 	clra		;zero_extendqihi: R:b -> R:d
   03CE 1F 01         [ 6]   66 	tfr	d,x
   03D0 E6 89 03 9E   [ 8]   67 	ldb	_CNT_DRAW1_LUT,x
   03D4 8E 05 B4      [ 3]   68 	ldx	#_draw_step1
   03D7 BF C8 A9      [ 6]   69 	stx	_the_map+1
   03DA F7 C8 A8      [ 5]   70 	stb	_the_map
   03DD 39            [ 5]   71 	rts
                             72 	.globl	_vl_map_roadline_left_1
   03DE                      73 _vl_map_roadline_left_1:
   03DE FF                   74 	.byte	-1
   03DF F0                   75 	.byte	-16
   03E0 FC                   76 	.byte	-4
   03E1 00                   77 	.byte	0
   03E2 E4                   78 	.byte	-28
   03E3 F9                   79 	.byte	-7
   03E4 FF                   80 	.byte	-1
   03E5 D8                   81 	.byte	-40
   03E6 F6                   82 	.byte	-10
   03E7 00                   83 	.byte	0
   03E8 CC                   84 	.byte	-52
   03E9 F3                   85 	.byte	-13
   03EA FF                   86 	.byte	-1
   03EB C0                   87 	.byte	-64
   03EC F0                   88 	.byte	-16
   03ED 00                   89 	.byte	0
   03EE B4                   90 	.byte	-76
   03EF ED                   91 	.byte	-19
   03F0 FF                   92 	.byte	-1
   03F1 A8                   93 	.byte	-88
   03F2 EA                   94 	.byte	-22
   03F3 00                   95 	.byte	0
   03F4 9C                   96 	.byte	-100
   03F5 E7                   97 	.byte	-25
   03F6 FF                   98 	.byte	-1
   03F7 90                   99 	.byte	-112
   03F8 E4                  100 	.byte	-28
   03F9 00                  101 	.byte	0
   03FA 84                  102 	.byte	-124
   03FB E1                  103 	.byte	-31
   03FC FF                  104 	.byte	-1
   03FD BC                  105 	.byte	-68
   03FE EF                  106 	.byte	-17
   03FF FF                  107 	.byte	-1
   0400 BC                  108 	.byte	-68
   0401 EF                  109 	.byte	-17
   0402 00                  110 	.byte	0
   0403 B6                  111 	.byte	-74
   0404 ED                  112 	.byte	-19
   0405 00                  113 	.byte	0
   0406 B6                  114 	.byte	-74
   0407 EE                  115 	.byte	-18
   0408 FF                  116 	.byte	-1
   0409 B0                  117 	.byte	-80
   040A EC                  118 	.byte	-20
   040B FF                  119 	.byte	-1
   040C B0                  120 	.byte	-80
   040D EC                  121 	.byte	-20
   040E 00                  122 	.byte	0
   040F AA                  123 	.byte	-86
   0410 EA                  124 	.byte	-22
   0411 00                  125 	.byte	0
   0412 AA                  126 	.byte	-86
   0413 EB                  127 	.byte	-21
   0414 FF                  128 	.byte	-1
   0415 84                  129 	.byte	-124
   0416 E1                  130 	.byte	-31
   0417                     131 _vl_term_0_37:
   0417 01                  132 	.byte	1
                            133 	.globl	_vl_map_roadline_left_2
   0418                     134 _vl_map_roadline_left_2:
   0418 00                  135 	.byte	0
   0419 F8                  136 	.byte	-8
   041A FE                  137 	.byte	-2
   041B FF                  138 	.byte	-1
   041C EC                  139 	.byte	-20
   041D FB                  140 	.byte	-5
   041E 00                  141 	.byte	0
   041F DC                  142 	.byte	-36
   0420 F7                  143 	.byte	-9
   0421 FF                  144 	.byte	-1
   0422 D4                  145 	.byte	-44
   0423 F5                  146 	.byte	-11
   0424 00                  147 	.byte	0
   0425 C4                  148 	.byte	-60
   0426 F1                  149 	.byte	-15
   0427 FF                  150 	.byte	-1
   0428 BC                  151 	.byte	-68
   0429 EF                  152 	.byte	-17
   042A 00                  153 	.byte	0
   042B AC                  154 	.byte	-84
   042C EB                  155 	.byte	-21
   042D FF                  156 	.byte	-1
   042E A4                  157 	.byte	-92
   042F E9                  158 	.byte	-23
   0430 00                  159 	.byte	0
   0431 94                  160 	.byte	-108
   0432 E5                  161 	.byte	-27
   0433 FF                  162 	.byte	-1
   0434 8C                  163 	.byte	-116
   0435 E3                  164 	.byte	-29
   0436 00                  165 	.byte	0
   0437 84                  166 	.byte	-124
   0438 E1                  167 	.byte	-31
   0439 00                  168 	.byte	0
   043A F8                  169 	.byte	-8
   043B FE                  170 	.byte	-2
   043C FF                  171 	.byte	-1
   043D B8                  172 	.byte	-72
   043E EE                  173 	.byte	-18
   043F FF                  174 	.byte	-1
   0440 BC                  175 	.byte	-68
   0441 EF                  176 	.byte	-17
   0442 00                  177 	.byte	0
   0443 AE                  178 	.byte	-82
   0444 EB                  179 	.byte	-21
   0445 00                  180 	.byte	0
   0446 B6                  181 	.byte	-74
   0447 EE                  182 	.byte	-18
   0448 FF                  183 	.byte	-1
   0449 AC                  184 	.byte	-84
   044A EB                  185 	.byte	-21
   044B FF                  186 	.byte	-1
   044C B0                  187 	.byte	-80
   044D EC                  188 	.byte	-20
   044E 00                  189 	.byte	0
   044F A2                  190 	.byte	-94
   0450 E8                  191 	.byte	-24
   0451 00                  192 	.byte	0
   0452 AA                  193 	.byte	-86
   0453 EB                  194 	.byte	-21
   0454 FF                  195 	.byte	-1
   0455 84                  196 	.byte	-124
   0456 E1                  197 	.byte	-31
   0457                     198 _vl_term_1_64:
   0457 01                  199 	.byte	1
                            200 	.globl	_vl_map_roadline_left_3
   0458                     201 _vl_map_roadline_left_3:
   0458 00                  202 	.byte	0
   0459 F0                  203 	.byte	-16
   045A FC                  204 	.byte	-4
   045B FF                  205 	.byte	-1
   045C E4                  206 	.byte	-28
   045D F9                  207 	.byte	-7
   045E 00                  208 	.byte	0
   045F D8                  209 	.byte	-40
   0460 F6                  210 	.byte	-10
   0461 FF                  211 	.byte	-1
   0462 CC                  212 	.byte	-52
   0463 F3                  213 	.byte	-13
   0464 00                  214 	.byte	0
   0465 C0                  215 	.byte	-64
   0466 F0                  216 	.byte	-16
   0467 FF                  217 	.byte	-1
   0468 B4                  218 	.byte	-76
   0469 ED                  219 	.byte	-19
   046A 00                  220 	.byte	0
   046B A8                  221 	.byte	-88
   046C EA                  222 	.byte	-22
   046D FF                  223 	.byte	-1
   046E 9C                  224 	.byte	-100
   046F E7                  225 	.byte	-25
   0470 00                  226 	.byte	0
   0471 90                  227 	.byte	-112
   0472 E4                  228 	.byte	-28
   0473 FF                  229 	.byte	-1
   0474 84                  230 	.byte	-124
   0475 E1                  231 	.byte	-31
   0476 00                  232 	.byte	0
   0477 84                  233 	.byte	-124
   0478 E1                  234 	.byte	-31
   0479 00                  235 	.byte	0
   047A F4                  236 	.byte	-12
   047B FD                  237 	.byte	-3
   047C FF                  238 	.byte	-1
   047D B0                  239 	.byte	-80
   047E EC                  240 	.byte	-20
   047F FF                  241 	.byte	-1
   0480 BC                  242 	.byte	-68
   0481 EF                  243 	.byte	-17
   0482 00                  244 	.byte	0
   0483 AA                  245 	.byte	-86
   0484 EA                  246 	.byte	-22
   0485 00                  247 	.byte	0
   0486 B6                  248 	.byte	-74
   0487 EE                  249 	.byte	-18
   0488 FF                  250 	.byte	-1
   0489 A4                  251 	.byte	-92
   048A E9                  252 	.byte	-23
   048B FF                  253 	.byte	-1
   048C B0                  254 	.byte	-80
   048D EC                  255 	.byte	-20
   048E                     256 _vl_term_2_88:
   048E 01                  257 	.byte	1
                            258 	.globl	_vl_map_roadline_left_4
   048F                     259 _vl_map_roadline_left_4:
   048F FF                  260 	.byte	-1
   0490 F8                  261 	.byte	-8
   0491 FE                  262 	.byte	-2
   0492 00                  263 	.byte	0
   0493 F0                  264 	.byte	-16
   0494 FC                  265 	.byte	-4
   0495 FF                  266 	.byte	-1
   0496 E0                  267 	.byte	-32
   0497 F8                  268 	.byte	-8
   0498 00                  269 	.byte	0
   0499 D0                  270 	.byte	-48
   049A F4                  271 	.byte	-12
   049B FF                  272 	.byte	-1
   049C C8                  273 	.byte	-56
   049D F2                  274 	.byte	-14
   049E 00                  275 	.byte	0
   049F B8                  276 	.byte	-72
   04A0 EE                  277 	.byte	-18
   04A1 FF                  278 	.byte	-1
   04A2 B0                  279 	.byte	-80
   04A3 EC                  280 	.byte	-20
   04A4 00                  281 	.byte	0
   04A5 A0                  282 	.byte	-96
   04A6 E8                  283 	.byte	-24
   04A7 FF                  284 	.byte	-1
   04A8 98                  285 	.byte	-104
   04A9 E6                  286 	.byte	-26
   04AA 00                  287 	.byte	0
   04AB 88                  288 	.byte	-120
   04AC E2                  289 	.byte	-30
   04AD FF                  290 	.byte	-1
   04AE 81                  291 	.byte	-127
   04AF E0                  292 	.byte	-32
   04B0 00                  293 	.byte	0
   04B1 84                  294 	.byte	-124
   04B2 E1                  295 	.byte	-31
   04B3 00                  296 	.byte	0
   04B4 EC                  297 	.byte	-20
   04B5 FB                  298 	.byte	-5
   04B6 FF                  299 	.byte	-1
   04B7 AC                  300 	.byte	-84
   04B8 EB                  301 	.byte	-21
   04B9 FF                  302 	.byte	-1
   04BA BC                  303 	.byte	-68
   04BB EF                  304 	.byte	-17
   04BC 00                  305 	.byte	0
   04BD A2                  306 	.byte	-94
   04BE E8                  307 	.byte	-24
   04BF 00                  308 	.byte	0
   04C0 B6                  309 	.byte	-74
   04C1 EE                  310 	.byte	-18
   04C2 FF                  311 	.byte	-1
   04C3 A0                  312 	.byte	-96
   04C4 E8                  313 	.byte	-24
   04C5 FF                  314 	.byte	-1
   04C6 B0                  315 	.byte	-80
   04C7 EC                  316 	.byte	-20
   04C8                     317 _vl_term_3_113:
   04C8 01                  318 	.byte	1
                            319 	.globl	_vl_map_roadline_right_1
   04C9                     320 _vl_map_roadline_right_1:
   04C9 FF                  321 	.byte	-1
   04CA F0                  322 	.byte	-16
   04CB 04                  323 	.byte	4
   04CC 00                  324 	.byte	0
   04CD E4                  325 	.byte	-28
   04CE 07                  326 	.byte	7
   04CF FF                  327 	.byte	-1
   04D0 D8                  328 	.byte	-40
   04D1 0A                  329 	.byte	10
   04D2 00                  330 	.byte	0
   04D3 CC                  331 	.byte	-52
   04D4 0D                  332 	.byte	13
   04D5 FF                  333 	.byte	-1
   04D6 C0                  334 	.byte	-64
   04D7 10                  335 	.byte	16
   04D8 00                  336 	.byte	0
   04D9 B4                  337 	.byte	-76
   04DA 13                  338 	.byte	19
   04DB FF                  339 	.byte	-1
   04DC A8                  340 	.byte	-88
   04DD 16                  341 	.byte	22
   04DE 00                  342 	.byte	0
   04DF 9C                  343 	.byte	-100
   04E0 19                  344 	.byte	25
   04E1 FF                  345 	.byte	-1
   04E2 90                  346 	.byte	-112
   04E3 1C                  347 	.byte	28
   04E4 00                  348 	.byte	0
   04E5 84                  349 	.byte	-124
   04E6 1F                  350 	.byte	31
   04E7 FF                  351 	.byte	-1
   04E8 BC                  352 	.byte	-68
   04E9 11                  353 	.byte	17
   04EA FF                  354 	.byte	-1
   04EB BC                  355 	.byte	-68
   04EC 11                  356 	.byte	17
   04ED 00                  357 	.byte	0
   04EE B6                  358 	.byte	-74
   04EF 13                  359 	.byte	19
   04F0 00                  360 	.byte	0
   04F1 B6                  361 	.byte	-74
   04F2 12                  362 	.byte	18
   04F3 FF                  363 	.byte	-1
   04F4 B0                  364 	.byte	-80
   04F5 14                  365 	.byte	20
   04F6 FF                  366 	.byte	-1
   04F7 B0                  367 	.byte	-80
   04F8 14                  368 	.byte	20
   04F9 00                  369 	.byte	0
   04FA AA                  370 	.byte	-86
   04FB 16                  371 	.byte	22
   04FC 00                  372 	.byte	0
   04FD AA                  373 	.byte	-86
   04FE 15                  374 	.byte	21
   04FF FF                  375 	.byte	-1
   0500 84                  376 	.byte	-124
   0501 1F                  377 	.byte	31
   0502                     378 _vl_term_4_145:
   0502 01                  379 	.byte	1
                            380 	.globl	_vl_map_roadline_right_2
   0503                     381 _vl_map_roadline_right_2:
   0503 00                  382 	.byte	0
   0504 F8                  383 	.byte	-8
   0505 02                  384 	.byte	2
   0506 FF                  385 	.byte	-1
   0507 EC                  386 	.byte	-20
   0508 05                  387 	.byte	5
   0509 00                  388 	.byte	0
   050A DC                  389 	.byte	-36
   050B 09                  390 	.byte	9
   050C FF                  391 	.byte	-1
   050D D4                  392 	.byte	-44
   050E 0B                  393 	.byte	11
   050F 00                  394 	.byte	0
   0510 C4                  395 	.byte	-60
   0511 0F                  396 	.byte	15
   0512 FF                  397 	.byte	-1
   0513 BC                  398 	.byte	-68
   0514 11                  399 	.byte	17
   0515 00                  400 	.byte	0
   0516 AC                  401 	.byte	-84
   0517 15                  402 	.byte	21
   0518 FF                  403 	.byte	-1
   0519 A4                  404 	.byte	-92
   051A 17                  405 	.byte	23
   051B 00                  406 	.byte	0
   051C 94                  407 	.byte	-108
   051D 1B                  408 	.byte	27
   051E FF                  409 	.byte	-1
   051F 8C                  410 	.byte	-116
   0520 1D                  411 	.byte	29
   0521 00                  412 	.byte	0
   0522 84                  413 	.byte	-124
   0523 1F                  414 	.byte	31
   0524 00                  415 	.byte	0
   0525 F8                  416 	.byte	-8
   0526 02                  417 	.byte	2
   0527 FF                  418 	.byte	-1
   0528 B8                  419 	.byte	-72
   0529 12                  420 	.byte	18
   052A FF                  421 	.byte	-1
   052B BC                  422 	.byte	-68
   052C 11                  423 	.byte	17
   052D 00                  424 	.byte	0
   052E AE                  425 	.byte	-82
   052F 15                  426 	.byte	21
   0530 00                  427 	.byte	0
   0531 B6                  428 	.byte	-74
   0532 12                  429 	.byte	18
   0533 FF                  430 	.byte	-1
   0534 AC                  431 	.byte	-84
   0535 15                  432 	.byte	21
   0536 FF                  433 	.byte	-1
   0537 B0                  434 	.byte	-80
   0538 14                  435 	.byte	20
   0539 00                  436 	.byte	0
   053A A2                  437 	.byte	-94
   053B 18                  438 	.byte	24
   053C 00                  439 	.byte	0
   053D AA                  440 	.byte	-86
   053E 15                  441 	.byte	21
   053F FF                  442 	.byte	-1
   0540 84                  443 	.byte	-124
   0541 1F                  444 	.byte	31
   0542                     445 _vl_term_5_172:
   0542 01                  446 	.byte	1
                            447 	.globl	_vl_map_roadline_right_3
   0543                     448 _vl_map_roadline_right_3:
   0543 00                  449 	.byte	0
   0544 F0                  450 	.byte	-16
   0545 04                  451 	.byte	4
   0546 FF                  452 	.byte	-1
   0547 E4                  453 	.byte	-28
   0548 07                  454 	.byte	7
   0549 00                  455 	.byte	0
   054A D8                  456 	.byte	-40
   054B 0A                  457 	.byte	10
   054C FF                  458 	.byte	-1
   054D CC                  459 	.byte	-52
   054E 0D                  460 	.byte	13
   054F 00                  461 	.byte	0
   0550 C0                  462 	.byte	-64
   0551 10                  463 	.byte	16
   0552 FF                  464 	.byte	-1
   0553 B4                  465 	.byte	-76
   0554 13                  466 	.byte	19
   0555 00                  467 	.byte	0
   0556 A8                  468 	.byte	-88
   0557 16                  469 	.byte	22
   0558 FF                  470 	.byte	-1
   0559 9C                  471 	.byte	-100
   055A 19                  472 	.byte	25
   055B 00                  473 	.byte	0
   055C 90                  474 	.byte	-112
   055D 1C                  475 	.byte	28
   055E FF                  476 	.byte	-1
   055F 84                  477 	.byte	-124
   0560 1F                  478 	.byte	31
   0561 00                  479 	.byte	0
   0562 84                  480 	.byte	-124
   0563 1F                  481 	.byte	31
   0564 00                  482 	.byte	0
   0565 F4                  483 	.byte	-12
   0566 03                  484 	.byte	3
   0567 FF                  485 	.byte	-1
   0568 B0                  486 	.byte	-80
   0569 14                  487 	.byte	20
   056A FF                  488 	.byte	-1
   056B BC                  489 	.byte	-68
   056C 11                  490 	.byte	17
   056D 00                  491 	.byte	0
   056E AA                  492 	.byte	-86
   056F 16                  493 	.byte	22
   0570 00                  494 	.byte	0
   0571 B6                  495 	.byte	-74
   0572 12                  496 	.byte	18
   0573 FF                  497 	.byte	-1
   0574 A4                  498 	.byte	-92
   0575 17                  499 	.byte	23
   0576 FF                  500 	.byte	-1
   0577 B0                  501 	.byte	-80
   0578 14                  502 	.byte	20
   0579                     503 _vl_term_6_196:
   0579 01                  504 	.byte	1
                            505 	.globl	_vl_map_roadline_right_4
   057A                     506 _vl_map_roadline_right_4:
   057A FF                  507 	.byte	-1
   057B F8                  508 	.byte	-8
   057C 02                  509 	.byte	2
   057D 00                  510 	.byte	0
   057E F0                  511 	.byte	-16
   057F 04                  512 	.byte	4
   0580 FF                  513 	.byte	-1
   0581 E0                  514 	.byte	-32
   0582 08                  515 	.byte	8
   0583 00                  516 	.byte	0
   0584 D0                  517 	.byte	-48
   0585 0C                  518 	.byte	12
   0586 FF                  519 	.byte	-1
   0587 C8                  520 	.byte	-56
   0588 0E                  521 	.byte	14
   0589 00                  522 	.byte	0
   058A B8                  523 	.byte	-72
   058B 12                  524 	.byte	18
   058C FF                  525 	.byte	-1
   058D B0                  526 	.byte	-80
   058E 14                  527 	.byte	20
   058F 00                  528 	.byte	0
   0590 A0                  529 	.byte	-96
   0591 18                  530 	.byte	24
   0592 FF                  531 	.byte	-1
   0593 98                  532 	.byte	-104
   0594 1A                  533 	.byte	26
   0595 00                  534 	.byte	0
   0596 88                  535 	.byte	-120
   0597 1E                  536 	.byte	30
   0598 FF                  537 	.byte	-1
   0599 81                  538 	.byte	-127
   059A 20                  539 	.byte	32
   059B 00                  540 	.byte	0
   059C 84                  541 	.byte	-124
   059D 1F                  542 	.byte	31
   059E 00                  543 	.byte	0
   059F EC                  544 	.byte	-20
   05A0 05                  545 	.byte	5
   05A1 FF                  546 	.byte	-1
   05A2 AC                  547 	.byte	-84
   05A3 15                  548 	.byte	21
   05A4 FF                  549 	.byte	-1
   05A5 BC                  550 	.byte	-68
   05A6 11                  551 	.byte	17
   05A7 00                  552 	.byte	0
   05A8 A2                  553 	.byte	-94
   05A9 18                  554 	.byte	24
   05AA 00                  555 	.byte	0
   05AB B6                  556 	.byte	-74
   05AC 12                  557 	.byte	18
   05AD FF                  558 	.byte	-1
   05AE A0                  559 	.byte	-96
   05AF 18                  560 	.byte	24
   05B0 FF                  561 	.byte	-1
   05B1 B0                  562 	.byte	-80
   05B2 14                  563 	.byte	20
   05B3                     564 _vl_term_7_221:
   05B3 01                  565 	.byte	1
                            566 	.globl	_draw_step1
   05B4                     567 _draw_step1:
   05B4 BD F2 A5      [ 8]  568 	jsr	___Intensity_5F
   05B7 BD F3 54      [ 8]  569 	jsr	___Reset0Ref
   05BA C6 7F         [ 2]  570 	ldb	#127
   05BC D7 04         [ 4]  571 	stb	*_dp_VIA_t1_cnt_lo
   05BE C6 24         [ 2]  572 	ldb	#36
   05C0 E7 E2         [ 6]  573 	stb	,-s
   05C2 C6 F1         [ 2]  574 	ldb	#-15
   05C4 BD 10 5E      [ 8]  575 	jsr	__Moveto_d
   05C7 C6 A8         [ 2]  576 	ldb	#-88
   05C9 D7 04         [ 4]  577 	stb	*_dp_VIA_t1_cnt_lo
   05CB C6 80         [ 2]  578 	ldb	#-128
   05CD E7 E2         [ 6]  579 	stb	,-s
   05CF CB 2E         [ 2]  580 	addb	#46
   05D1 BD 10 59      [ 8]  581 	jsr	__Draw_Line_d
   05D4 BD F3 54      [ 8]  582 	jsr	___Reset0Ref
   05D7 C6 7F         [ 2]  583 	ldb	#127
   05D9 D7 04         [ 4]  584 	stb	*_dp_VIA_t1_cnt_lo
   05DB C6 24         [ 2]  585 	ldb	#36
   05DD E7 E2         [ 6]  586 	stb	,-s
   05DF C6 FB         [ 2]  587 	ldb	#-5
   05E1 BD 10 5E      [ 8]  588 	jsr	__Moveto_d
   05E4 C6 10         [ 2]  589 	ldb	#16
   05E6 D7 04         [ 4]  590 	stb	*_dp_VIA_t1_cnt_lo
   05E8 8E 03 DE      [ 3]  591 	ldx	#_vl_map_roadline_left_1
   05EB BD F4 10      [ 8]  592 	jsr	___Draw_VLp
   05EE BD F3 54      [ 8]  593 	jsr	___Reset0Ref
   05F1 C6 7F         [ 2]  594 	ldb	#127
   05F3 D7 04         [ 4]  595 	stb	*_dp_VIA_t1_cnt_lo
   05F5 C6 24         [ 2]  596 	ldb	#36
   05F7 E7 E2         [ 6]  597 	stb	,-s
   05F9 C6 05         [ 2]  598 	ldb	#5
   05FB BD 10 5E      [ 8]  599 	jsr	__Moveto_d
   05FE C6 10         [ 2]  600 	ldb	#16
   0600 D7 04         [ 4]  601 	stb	*_dp_VIA_t1_cnt_lo
   0602 8E 04 C9      [ 3]  602 	ldx	#_vl_map_roadline_right_1
   0605 BD F4 10      [ 8]  603 	jsr	___Draw_VLp
   0608 BD F3 54      [ 8]  604 	jsr	___Reset0Ref
   060B C6 7F         [ 2]  605 	ldb	#127
   060D D7 04         [ 4]  606 	stb	*_dp_VIA_t1_cnt_lo
   060F C6 24         [ 2]  607 	ldb	#36
   0611 E7 E2         [ 6]  608 	stb	,-s
   0613 C6 0F         [ 2]  609 	ldb	#15
   0615 BD 10 5E      [ 8]  610 	jsr	__Moveto_d
   0618 C6 A8         [ 2]  611 	ldb	#-88
   061A D7 04         [ 4]  612 	stb	*_dp_VIA_t1_cnt_lo
   061C C6 80         [ 2]  613 	ldb	#-128
   061E E7 E2         [ 6]  614 	stb	,-s
   0620 C6 52         [ 2]  615 	ldb	#82
   0622 BD 10 59      [ 8]  616 	jsr	__Draw_Line_d
   0625 F6 C8 A8      [ 5]  617 	ldb	_the_map
   0628 32 66         [ 5]  618 	leas	6,s
   062A 5D            [ 2]  619 	tstb
   062B 27 05         [ 3]  620 	beq	L8
   062D 5A            [ 2]  621 	decb
   062E F7 C8 A8      [ 5]  622 	stb	_the_map
   0631 39            [ 5]  623 	rts
   0632                     624 L8:
   0632 8E 06 46      [ 3]  625 	ldx	#_draw_step2
   0635 BF C8 A9      [ 6]  626 	stx	_the_map+1
   0638 F6 C8 A5      [ 5]  627 	ldb	_the_game+2
   063B 4F            [ 2]  628 	clra		;zero_extendqihi: R:b -> R:d
   063C 1F 01         [ 6]  629 	tfr	d,x
   063E E6 89 03 A9   [ 8]  630 	ldb	_CNT_DRAW2_LUT,x
   0642 F7 C8 A8      [ 5]  631 	stb	_the_map
   0645 39            [ 5]  632 	rts
                            633 	.globl	_draw_step2
   0646                     634 _draw_step2:
   0646 BD F2 A5      [ 8]  635 	jsr	___Intensity_5F
   0649 BD F3 54      [ 8]  636 	jsr	___Reset0Ref
   064C C6 7F         [ 2]  637 	ldb	#127
   064E D7 04         [ 4]  638 	stb	*_dp_VIA_t1_cnt_lo
   0650 C6 24         [ 2]  639 	ldb	#36
   0652 E7 E2         [ 6]  640 	stb	,-s
   0654 C6 F1         [ 2]  641 	ldb	#-15
   0656 BD 10 5E      [ 8]  642 	jsr	__Moveto_d
   0659 C6 A8         [ 2]  643 	ldb	#-88
   065B D7 04         [ 4]  644 	stb	*_dp_VIA_t1_cnt_lo
   065D C6 80         [ 2]  645 	ldb	#-128
   065F E7 E2         [ 6]  646 	stb	,-s
   0661 CB 2E         [ 2]  647 	addb	#46
   0663 BD 10 59      [ 8]  648 	jsr	__Draw_Line_d
   0666 BD F3 54      [ 8]  649 	jsr	___Reset0Ref
   0669 C6 7F         [ 2]  650 	ldb	#127
   066B D7 04         [ 4]  651 	stb	*_dp_VIA_t1_cnt_lo
   066D C6 24         [ 2]  652 	ldb	#36
   066F E7 E2         [ 6]  653 	stb	,-s
   0671 C6 FB         [ 2]  654 	ldb	#-5
   0673 BD 10 5E      [ 8]  655 	jsr	__Moveto_d
   0676 C6 10         [ 2]  656 	ldb	#16
   0678 D7 04         [ 4]  657 	stb	*_dp_VIA_t1_cnt_lo
   067A 8E 04 18      [ 3]  658 	ldx	#_vl_map_roadline_left_2
   067D BD F4 10      [ 8]  659 	jsr	___Draw_VLp
   0680 BD F3 54      [ 8]  660 	jsr	___Reset0Ref
   0683 C6 7F         [ 2]  661 	ldb	#127
   0685 D7 04         [ 4]  662 	stb	*_dp_VIA_t1_cnt_lo
   0687 C6 24         [ 2]  663 	ldb	#36
   0689 E7 E2         [ 6]  664 	stb	,-s
   068B C6 05         [ 2]  665 	ldb	#5
   068D BD 10 5E      [ 8]  666 	jsr	__Moveto_d
   0690 C6 10         [ 2]  667 	ldb	#16
   0692 D7 04         [ 4]  668 	stb	*_dp_VIA_t1_cnt_lo
   0694 8E 05 03      [ 3]  669 	ldx	#_vl_map_roadline_right_2
   0697 BD F4 10      [ 8]  670 	jsr	___Draw_VLp
   069A BD F3 54      [ 8]  671 	jsr	___Reset0Ref
   069D C6 7F         [ 2]  672 	ldb	#127
   069F D7 04         [ 4]  673 	stb	*_dp_VIA_t1_cnt_lo
   06A1 C6 24         [ 2]  674 	ldb	#36
   06A3 E7 E2         [ 6]  675 	stb	,-s
   06A5 C6 0F         [ 2]  676 	ldb	#15
   06A7 BD 10 5E      [ 8]  677 	jsr	__Moveto_d
   06AA C6 A8         [ 2]  678 	ldb	#-88
   06AC D7 04         [ 4]  679 	stb	*_dp_VIA_t1_cnt_lo
   06AE C6 80         [ 2]  680 	ldb	#-128
   06B0 E7 E2         [ 6]  681 	stb	,-s
   06B2 C6 52         [ 2]  682 	ldb	#82
   06B4 BD 10 59      [ 8]  683 	jsr	__Draw_Line_d
   06B7 F6 C8 A8      [ 5]  684 	ldb	_the_map
   06BA 32 66         [ 5]  685 	leas	6,s
   06BC 5D            [ 2]  686 	tstb
   06BD 27 05         [ 3]  687 	beq	L13
   06BF 5A            [ 2]  688 	decb
   06C0 F7 C8 A8      [ 5]  689 	stb	_the_map
   06C3 39            [ 5]  690 	rts
   06C4                     691 L13:
   06C4 8E 06 D8      [ 3]  692 	ldx	#_draw_step3
   06C7 BF C8 A9      [ 6]  693 	stx	_the_map+1
   06CA F6 C8 A5      [ 5]  694 	ldb	_the_game+2
   06CD 4F            [ 2]  695 	clra		;zero_extendqihi: R:b -> R:d
   06CE 1F 01         [ 6]  696 	tfr	d,x
   06D0 E6 89 03 B4   [ 8]  697 	ldb	_CNT_DRAW3_LUT,x
   06D4 F7 C8 A8      [ 5]  698 	stb	_the_map
   06D7 39            [ 5]  699 	rts
                            700 	.globl	_draw_step3
   06D8                     701 _draw_step3:
   06D8 BD F2 A5      [ 8]  702 	jsr	___Intensity_5F
   06DB BD F3 54      [ 8]  703 	jsr	___Reset0Ref
   06DE C6 7F         [ 2]  704 	ldb	#127
   06E0 D7 04         [ 4]  705 	stb	*_dp_VIA_t1_cnt_lo
   06E2 C6 24         [ 2]  706 	ldb	#36
   06E4 E7 E2         [ 6]  707 	stb	,-s
   06E6 C6 F1         [ 2]  708 	ldb	#-15
   06E8 BD 10 5E      [ 8]  709 	jsr	__Moveto_d
   06EB C6 A8         [ 2]  710 	ldb	#-88
   06ED D7 04         [ 4]  711 	stb	*_dp_VIA_t1_cnt_lo
   06EF C6 80         [ 2]  712 	ldb	#-128
   06F1 E7 E2         [ 6]  713 	stb	,-s
   06F3 CB 2E         [ 2]  714 	addb	#46
   06F5 BD 10 59      [ 8]  715 	jsr	__Draw_Line_d
   06F8 BD F3 54      [ 8]  716 	jsr	___Reset0Ref
   06FB C6 7F         [ 2]  717 	ldb	#127
   06FD D7 04         [ 4]  718 	stb	*_dp_VIA_t1_cnt_lo
   06FF C6 24         [ 2]  719 	ldb	#36
   0701 E7 E2         [ 6]  720 	stb	,-s
   0703 C6 FB         [ 2]  721 	ldb	#-5
   0705 BD 10 5E      [ 8]  722 	jsr	__Moveto_d
   0708 C6 10         [ 2]  723 	ldb	#16
   070A D7 04         [ 4]  724 	stb	*_dp_VIA_t1_cnt_lo
   070C 8E 04 58      [ 3]  725 	ldx	#_vl_map_roadline_left_3
   070F BD F4 10      [ 8]  726 	jsr	___Draw_VLp
   0712 BD F3 54      [ 8]  727 	jsr	___Reset0Ref
   0715 C6 7F         [ 2]  728 	ldb	#127
   0717 D7 04         [ 4]  729 	stb	*_dp_VIA_t1_cnt_lo
   0719 C6 24         [ 2]  730 	ldb	#36
   071B E7 E2         [ 6]  731 	stb	,-s
   071D C6 05         [ 2]  732 	ldb	#5
   071F BD 10 5E      [ 8]  733 	jsr	__Moveto_d
   0722 C6 10         [ 2]  734 	ldb	#16
   0724 D7 04         [ 4]  735 	stb	*_dp_VIA_t1_cnt_lo
   0726 8E 05 43      [ 3]  736 	ldx	#_vl_map_roadline_right_3
   0729 BD F4 10      [ 8]  737 	jsr	___Draw_VLp
   072C BD F3 54      [ 8]  738 	jsr	___Reset0Ref
   072F C6 7F         [ 2]  739 	ldb	#127
   0731 D7 04         [ 4]  740 	stb	*_dp_VIA_t1_cnt_lo
   0733 C6 24         [ 2]  741 	ldb	#36
   0735 E7 E2         [ 6]  742 	stb	,-s
   0737 C6 0F         [ 2]  743 	ldb	#15
   0739 BD 10 5E      [ 8]  744 	jsr	__Moveto_d
   073C C6 A8         [ 2]  745 	ldb	#-88
   073E D7 04         [ 4]  746 	stb	*_dp_VIA_t1_cnt_lo
   0740 C6 80         [ 2]  747 	ldb	#-128
   0742 E7 E2         [ 6]  748 	stb	,-s
   0744 C6 52         [ 2]  749 	ldb	#82
   0746 BD 10 59      [ 8]  750 	jsr	__Draw_Line_d
   0749 F6 C8 A8      [ 5]  751 	ldb	_the_map
   074C 32 66         [ 5]  752 	leas	6,s
   074E 5D            [ 2]  753 	tstb
   074F 27 05         [ 3]  754 	beq	L18
   0751 5A            [ 2]  755 	decb
   0752 F7 C8 A8      [ 5]  756 	stb	_the_map
   0755 39            [ 5]  757 	rts
   0756                     758 L18:
   0756 8E 07 6A      [ 3]  759 	ldx	#_draw_step4
   0759 BF C8 A9      [ 6]  760 	stx	_the_map+1
   075C F6 C8 A5      [ 5]  761 	ldb	_the_game+2
   075F 4F            [ 2]  762 	clra		;zero_extendqihi: R:b -> R:d
   0760 1F 01         [ 6]  763 	tfr	d,x
   0762 E6 89 03 BF   [ 8]  764 	ldb	_CNT_DRAW4_LUT,x
   0766 F7 C8 A8      [ 5]  765 	stb	_the_map
   0769 39            [ 5]  766 	rts
                            767 	.globl	_draw_step4
   076A                     768 _draw_step4:
   076A BD F2 A5      [ 8]  769 	jsr	___Intensity_5F
   076D BD F3 54      [ 8]  770 	jsr	___Reset0Ref
   0770 C6 7F         [ 2]  771 	ldb	#127
   0772 D7 04         [ 4]  772 	stb	*_dp_VIA_t1_cnt_lo
   0774 C6 24         [ 2]  773 	ldb	#36
   0776 E7 E2         [ 6]  774 	stb	,-s
   0778 C6 F1         [ 2]  775 	ldb	#-15
   077A BD 10 5E      [ 8]  776 	jsr	__Moveto_d
   077D C6 A8         [ 2]  777 	ldb	#-88
   077F D7 04         [ 4]  778 	stb	*_dp_VIA_t1_cnt_lo
   0781 C6 80         [ 2]  779 	ldb	#-128
   0783 E7 E2         [ 6]  780 	stb	,-s
   0785 CB 2E         [ 2]  781 	addb	#46
   0787 BD 10 59      [ 8]  782 	jsr	__Draw_Line_d
   078A BD F3 54      [ 8]  783 	jsr	___Reset0Ref
   078D C6 7F         [ 2]  784 	ldb	#127
   078F D7 04         [ 4]  785 	stb	*_dp_VIA_t1_cnt_lo
   0791 C6 24         [ 2]  786 	ldb	#36
   0793 E7 E2         [ 6]  787 	stb	,-s
   0795 C6 FB         [ 2]  788 	ldb	#-5
   0797 BD 10 5E      [ 8]  789 	jsr	__Moveto_d
   079A C6 10         [ 2]  790 	ldb	#16
   079C D7 04         [ 4]  791 	stb	*_dp_VIA_t1_cnt_lo
   079E 8E 04 8F      [ 3]  792 	ldx	#_vl_map_roadline_left_4
   07A1 BD F4 10      [ 8]  793 	jsr	___Draw_VLp
   07A4 BD F3 54      [ 8]  794 	jsr	___Reset0Ref
   07A7 C6 7F         [ 2]  795 	ldb	#127
   07A9 D7 04         [ 4]  796 	stb	*_dp_VIA_t1_cnt_lo
   07AB C6 24         [ 2]  797 	ldb	#36
   07AD E7 E2         [ 6]  798 	stb	,-s
   07AF C6 05         [ 2]  799 	ldb	#5
   07B1 BD 10 5E      [ 8]  800 	jsr	__Moveto_d
   07B4 C6 10         [ 2]  801 	ldb	#16
   07B6 D7 04         [ 4]  802 	stb	*_dp_VIA_t1_cnt_lo
   07B8 8E 05 7A      [ 3]  803 	ldx	#_vl_map_roadline_right_4
   07BB BD F4 10      [ 8]  804 	jsr	___Draw_VLp
   07BE BD F3 54      [ 8]  805 	jsr	___Reset0Ref
   07C1 C6 7F         [ 2]  806 	ldb	#127
   07C3 D7 04         [ 4]  807 	stb	*_dp_VIA_t1_cnt_lo
   07C5 C6 24         [ 2]  808 	ldb	#36
   07C7 E7 E2         [ 6]  809 	stb	,-s
   07C9 C6 0F         [ 2]  810 	ldb	#15
   07CB BD 10 5E      [ 8]  811 	jsr	__Moveto_d
   07CE C6 A8         [ 2]  812 	ldb	#-88
   07D0 D7 04         [ 4]  813 	stb	*_dp_VIA_t1_cnt_lo
   07D2 C6 80         [ 2]  814 	ldb	#-128
   07D4 E7 E2         [ 6]  815 	stb	,-s
   07D6 C6 52         [ 2]  816 	ldb	#82
   07D8 BD 10 59      [ 8]  817 	jsr	__Draw_Line_d
   07DB F6 C8 A8      [ 5]  818 	ldb	_the_map
   07DE 32 66         [ 5]  819 	leas	6,s
   07E0 5D            [ 2]  820 	tstb
   07E1 27 05         [ 3]  821 	beq	L23
   07E3 5A            [ 2]  822 	decb
   07E4 F7 C8 A8      [ 5]  823 	stb	_the_map
   07E7 39            [ 5]  824 	rts
   07E8                     825 L23:
   07E8 8E 05 B4      [ 3]  826 	ldx	#_draw_step1
   07EB BF C8 A9      [ 6]  827 	stx	_the_map+1
   07EE F6 C8 A5      [ 5]  828 	ldb	_the_game+2
   07F1 4F            [ 2]  829 	clra		;zero_extendqihi: R:b -> R:d
   07F2 1F 01         [ 6]  830 	tfr	d,x
   07F4 E6 89 03 9E   [ 8]  831 	ldb	_CNT_DRAW1_LUT,x
   07F8 F7 C8 A8      [ 5]  832 	stb	_the_map
   07FB 39            [ 5]  833 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Sat Jun 14 01:03:03 2025

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
Hexadecimal [16-Bits]                                 Sat Jun 14 01:03:03 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    3   flags    0
   3 .text            size  45E   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

