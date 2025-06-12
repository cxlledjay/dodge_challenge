                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	map.c
                              6 	.area	.bss
                              7 	.globl	_the_map
   C8A8                       8 _the_map:	.blkb	3
                              9 	.area	.text
                             10 	.globl	_dummy_tick
   02D1                      11 _dummy_tick:
   02D1 39            [ 5]   12 	rts
                             13 	.globl	_map_init
   02D2                      14 _map_init:
   02D2 8E 04 B2      [ 3]   15 	ldx	#_draw_step1
   02D5 BF C8 A9      [ 6]   16 	stx	_the_map+1
   02D8 7F C8 A8      [ 7]   17 	clr	_the_map
   02DB 39            [ 5]   18 	rts
                             19 	.globl	_vl_map_roadline_left_1
   02DC                      20 _vl_map_roadline_left_1:
   02DC FF                   21 	.byte	-1
   02DD F0                   22 	.byte	-16
   02DE FC                   23 	.byte	-4
   02DF 00                   24 	.byte	0
   02E0 E4                   25 	.byte	-28
   02E1 F9                   26 	.byte	-7
   02E2 FF                   27 	.byte	-1
   02E3 D8                   28 	.byte	-40
   02E4 F6                   29 	.byte	-10
   02E5 00                   30 	.byte	0
   02E6 CC                   31 	.byte	-52
   02E7 F3                   32 	.byte	-13
   02E8 FF                   33 	.byte	-1
   02E9 C0                   34 	.byte	-64
   02EA F0                   35 	.byte	-16
   02EB 00                   36 	.byte	0
   02EC B4                   37 	.byte	-76
   02ED ED                   38 	.byte	-19
   02EE FF                   39 	.byte	-1
   02EF A8                   40 	.byte	-88
   02F0 EA                   41 	.byte	-22
   02F1 00                   42 	.byte	0
   02F2 9C                   43 	.byte	-100
   02F3 E7                   44 	.byte	-25
   02F4 FF                   45 	.byte	-1
   02F5 90                   46 	.byte	-112
   02F6 E4                   47 	.byte	-28
   02F7 00                   48 	.byte	0
   02F8 84                   49 	.byte	-124
   02F9 E1                   50 	.byte	-31
   02FA FF                   51 	.byte	-1
   02FB BC                   52 	.byte	-68
   02FC EF                   53 	.byte	-17
   02FD FF                   54 	.byte	-1
   02FE BC                   55 	.byte	-68
   02FF EF                   56 	.byte	-17
   0300 00                   57 	.byte	0
   0301 B6                   58 	.byte	-74
   0302 ED                   59 	.byte	-19
   0303 00                   60 	.byte	0
   0304 B6                   61 	.byte	-74
   0305 EE                   62 	.byte	-18
   0306 FF                   63 	.byte	-1
   0307 B0                   64 	.byte	-80
   0308 EC                   65 	.byte	-20
   0309 FF                   66 	.byte	-1
   030A B0                   67 	.byte	-80
   030B EC                   68 	.byte	-20
   030C 00                   69 	.byte	0
   030D AA                   70 	.byte	-86
   030E EA                   71 	.byte	-22
   030F 00                   72 	.byte	0
   0310 AA                   73 	.byte	-86
   0311 EB                   74 	.byte	-21
   0312 FF                   75 	.byte	-1
   0313 84                   76 	.byte	-124
   0314 E1                   77 	.byte	-31
   0315                      78 _vl_term_0_37:
   0315 01                   79 	.byte	1
                             80 	.globl	_vl_map_roadline_left_2
   0316                      81 _vl_map_roadline_left_2:
   0316 00                   82 	.byte	0
   0317 F8                   83 	.byte	-8
   0318 FE                   84 	.byte	-2
   0319 FF                   85 	.byte	-1
   031A EC                   86 	.byte	-20
   031B FB                   87 	.byte	-5
   031C 00                   88 	.byte	0
   031D DC                   89 	.byte	-36
   031E F7                   90 	.byte	-9
   031F FF                   91 	.byte	-1
   0320 D4                   92 	.byte	-44
   0321 F5                   93 	.byte	-11
   0322 00                   94 	.byte	0
   0323 C4                   95 	.byte	-60
   0324 F1                   96 	.byte	-15
   0325 FF                   97 	.byte	-1
   0326 BC                   98 	.byte	-68
   0327 EF                   99 	.byte	-17
   0328 00                  100 	.byte	0
   0329 AC                  101 	.byte	-84
   032A EB                  102 	.byte	-21
   032B FF                  103 	.byte	-1
   032C A4                  104 	.byte	-92
   032D E9                  105 	.byte	-23
   032E 00                  106 	.byte	0
   032F 94                  107 	.byte	-108
   0330 E5                  108 	.byte	-27
   0331 FF                  109 	.byte	-1
   0332 8C                  110 	.byte	-116
   0333 E3                  111 	.byte	-29
   0334 00                  112 	.byte	0
   0335 84                  113 	.byte	-124
   0336 E1                  114 	.byte	-31
   0337 00                  115 	.byte	0
   0338 F8                  116 	.byte	-8
   0339 FE                  117 	.byte	-2
   033A FF                  118 	.byte	-1
   033B B8                  119 	.byte	-72
   033C EE                  120 	.byte	-18
   033D FF                  121 	.byte	-1
   033E BC                  122 	.byte	-68
   033F EF                  123 	.byte	-17
   0340 00                  124 	.byte	0
   0341 AE                  125 	.byte	-82
   0342 EB                  126 	.byte	-21
   0343 00                  127 	.byte	0
   0344 B6                  128 	.byte	-74
   0345 EE                  129 	.byte	-18
   0346 FF                  130 	.byte	-1
   0347 AC                  131 	.byte	-84
   0348 EB                  132 	.byte	-21
   0349 FF                  133 	.byte	-1
   034A B0                  134 	.byte	-80
   034B EC                  135 	.byte	-20
   034C 00                  136 	.byte	0
   034D A2                  137 	.byte	-94
   034E E8                  138 	.byte	-24
   034F 00                  139 	.byte	0
   0350 AA                  140 	.byte	-86
   0351 EB                  141 	.byte	-21
   0352 FF                  142 	.byte	-1
   0353 84                  143 	.byte	-124
   0354 E1                  144 	.byte	-31
   0355                     145 _vl_term_1_64:
   0355 01                  146 	.byte	1
                            147 	.globl	_vl_map_roadline_left_3
   0356                     148 _vl_map_roadline_left_3:
   0356 00                  149 	.byte	0
   0357 F0                  150 	.byte	-16
   0358 FC                  151 	.byte	-4
   0359 FF                  152 	.byte	-1
   035A E4                  153 	.byte	-28
   035B F9                  154 	.byte	-7
   035C 00                  155 	.byte	0
   035D D8                  156 	.byte	-40
   035E F6                  157 	.byte	-10
   035F FF                  158 	.byte	-1
   0360 CC                  159 	.byte	-52
   0361 F3                  160 	.byte	-13
   0362 00                  161 	.byte	0
   0363 C0                  162 	.byte	-64
   0364 F0                  163 	.byte	-16
   0365 FF                  164 	.byte	-1
   0366 B4                  165 	.byte	-76
   0367 ED                  166 	.byte	-19
   0368 00                  167 	.byte	0
   0369 A8                  168 	.byte	-88
   036A EA                  169 	.byte	-22
   036B FF                  170 	.byte	-1
   036C 9C                  171 	.byte	-100
   036D E7                  172 	.byte	-25
   036E 00                  173 	.byte	0
   036F 90                  174 	.byte	-112
   0370 E4                  175 	.byte	-28
   0371 FF                  176 	.byte	-1
   0372 84                  177 	.byte	-124
   0373 E1                  178 	.byte	-31
   0374 00                  179 	.byte	0
   0375 84                  180 	.byte	-124
   0376 E1                  181 	.byte	-31
   0377 00                  182 	.byte	0
   0378 F4                  183 	.byte	-12
   0379 FD                  184 	.byte	-3
   037A FF                  185 	.byte	-1
   037B B0                  186 	.byte	-80
   037C EC                  187 	.byte	-20
   037D FF                  188 	.byte	-1
   037E BC                  189 	.byte	-68
   037F EF                  190 	.byte	-17
   0380 00                  191 	.byte	0
   0381 AA                  192 	.byte	-86
   0382 EA                  193 	.byte	-22
   0383 00                  194 	.byte	0
   0384 B6                  195 	.byte	-74
   0385 EE                  196 	.byte	-18
   0386 FF                  197 	.byte	-1
   0387 A4                  198 	.byte	-92
   0388 E9                  199 	.byte	-23
   0389 FF                  200 	.byte	-1
   038A B0                  201 	.byte	-80
   038B EC                  202 	.byte	-20
   038C                     203 _vl_term_2_88:
   038C 01                  204 	.byte	1
                            205 	.globl	_vl_map_roadline_left_4
   038D                     206 _vl_map_roadline_left_4:
   038D FF                  207 	.byte	-1
   038E F8                  208 	.byte	-8
   038F FE                  209 	.byte	-2
   0390 00                  210 	.byte	0
   0391 F0                  211 	.byte	-16
   0392 FC                  212 	.byte	-4
   0393 FF                  213 	.byte	-1
   0394 E0                  214 	.byte	-32
   0395 F8                  215 	.byte	-8
   0396 00                  216 	.byte	0
   0397 D0                  217 	.byte	-48
   0398 F4                  218 	.byte	-12
   0399 FF                  219 	.byte	-1
   039A C8                  220 	.byte	-56
   039B F2                  221 	.byte	-14
   039C 00                  222 	.byte	0
   039D B8                  223 	.byte	-72
   039E EE                  224 	.byte	-18
   039F FF                  225 	.byte	-1
   03A0 B0                  226 	.byte	-80
   03A1 EC                  227 	.byte	-20
   03A2 00                  228 	.byte	0
   03A3 A0                  229 	.byte	-96
   03A4 E8                  230 	.byte	-24
   03A5 FF                  231 	.byte	-1
   03A6 98                  232 	.byte	-104
   03A7 E6                  233 	.byte	-26
   03A8 00                  234 	.byte	0
   03A9 88                  235 	.byte	-120
   03AA E2                  236 	.byte	-30
   03AB FF                  237 	.byte	-1
   03AC 81                  238 	.byte	-127
   03AD E0                  239 	.byte	-32
   03AE 00                  240 	.byte	0
   03AF 84                  241 	.byte	-124
   03B0 E1                  242 	.byte	-31
   03B1 00                  243 	.byte	0
   03B2 EC                  244 	.byte	-20
   03B3 FB                  245 	.byte	-5
   03B4 FF                  246 	.byte	-1
   03B5 AC                  247 	.byte	-84
   03B6 EB                  248 	.byte	-21
   03B7 FF                  249 	.byte	-1
   03B8 BC                  250 	.byte	-68
   03B9 EF                  251 	.byte	-17
   03BA 00                  252 	.byte	0
   03BB A2                  253 	.byte	-94
   03BC E8                  254 	.byte	-24
   03BD 00                  255 	.byte	0
   03BE B6                  256 	.byte	-74
   03BF EE                  257 	.byte	-18
   03C0 FF                  258 	.byte	-1
   03C1 A0                  259 	.byte	-96
   03C2 E8                  260 	.byte	-24
   03C3 FF                  261 	.byte	-1
   03C4 B0                  262 	.byte	-80
   03C5 EC                  263 	.byte	-20
   03C6                     264 _vl_term_3_113:
   03C6 01                  265 	.byte	1
                            266 	.globl	_vl_map_roadline_right_1
   03C7                     267 _vl_map_roadline_right_1:
   03C7 FF                  268 	.byte	-1
   03C8 F0                  269 	.byte	-16
   03C9 04                  270 	.byte	4
   03CA 00                  271 	.byte	0
   03CB E4                  272 	.byte	-28
   03CC 07                  273 	.byte	7
   03CD FF                  274 	.byte	-1
   03CE D8                  275 	.byte	-40
   03CF 0A                  276 	.byte	10
   03D0 00                  277 	.byte	0
   03D1 CC                  278 	.byte	-52
   03D2 0D                  279 	.byte	13
   03D3 FF                  280 	.byte	-1
   03D4 C0                  281 	.byte	-64
   03D5 10                  282 	.byte	16
   03D6 00                  283 	.byte	0
   03D7 B4                  284 	.byte	-76
   03D8 13                  285 	.byte	19
   03D9 FF                  286 	.byte	-1
   03DA A8                  287 	.byte	-88
   03DB 16                  288 	.byte	22
   03DC 00                  289 	.byte	0
   03DD 9C                  290 	.byte	-100
   03DE 19                  291 	.byte	25
   03DF FF                  292 	.byte	-1
   03E0 90                  293 	.byte	-112
   03E1 1C                  294 	.byte	28
   03E2 00                  295 	.byte	0
   03E3 84                  296 	.byte	-124
   03E4 1F                  297 	.byte	31
   03E5 FF                  298 	.byte	-1
   03E6 BC                  299 	.byte	-68
   03E7 11                  300 	.byte	17
   03E8 FF                  301 	.byte	-1
   03E9 BC                  302 	.byte	-68
   03EA 11                  303 	.byte	17
   03EB 00                  304 	.byte	0
   03EC B6                  305 	.byte	-74
   03ED 13                  306 	.byte	19
   03EE 00                  307 	.byte	0
   03EF B6                  308 	.byte	-74
   03F0 12                  309 	.byte	18
   03F1 FF                  310 	.byte	-1
   03F2 B0                  311 	.byte	-80
   03F3 14                  312 	.byte	20
   03F4 FF                  313 	.byte	-1
   03F5 B0                  314 	.byte	-80
   03F6 14                  315 	.byte	20
   03F7 00                  316 	.byte	0
   03F8 AA                  317 	.byte	-86
   03F9 16                  318 	.byte	22
   03FA 00                  319 	.byte	0
   03FB AA                  320 	.byte	-86
   03FC 15                  321 	.byte	21
   03FD FF                  322 	.byte	-1
   03FE 84                  323 	.byte	-124
   03FF 1F                  324 	.byte	31
   0400                     325 _vl_term_4_145:
   0400 01                  326 	.byte	1
                            327 	.globl	_vl_map_roadline_right_2
   0401                     328 _vl_map_roadline_right_2:
   0401 00                  329 	.byte	0
   0402 F8                  330 	.byte	-8
   0403 02                  331 	.byte	2
   0404 FF                  332 	.byte	-1
   0405 EC                  333 	.byte	-20
   0406 05                  334 	.byte	5
   0407 00                  335 	.byte	0
   0408 DC                  336 	.byte	-36
   0409 09                  337 	.byte	9
   040A FF                  338 	.byte	-1
   040B D4                  339 	.byte	-44
   040C 0B                  340 	.byte	11
   040D 00                  341 	.byte	0
   040E C4                  342 	.byte	-60
   040F 0F                  343 	.byte	15
   0410 FF                  344 	.byte	-1
   0411 BC                  345 	.byte	-68
   0412 11                  346 	.byte	17
   0413 00                  347 	.byte	0
   0414 AC                  348 	.byte	-84
   0415 15                  349 	.byte	21
   0416 FF                  350 	.byte	-1
   0417 A4                  351 	.byte	-92
   0418 17                  352 	.byte	23
   0419 00                  353 	.byte	0
   041A 94                  354 	.byte	-108
   041B 1B                  355 	.byte	27
   041C FF                  356 	.byte	-1
   041D 8C                  357 	.byte	-116
   041E 1D                  358 	.byte	29
   041F 00                  359 	.byte	0
   0420 84                  360 	.byte	-124
   0421 1F                  361 	.byte	31
   0422 00                  362 	.byte	0
   0423 F8                  363 	.byte	-8
   0424 02                  364 	.byte	2
   0425 FF                  365 	.byte	-1
   0426 B8                  366 	.byte	-72
   0427 12                  367 	.byte	18
   0428 FF                  368 	.byte	-1
   0429 BC                  369 	.byte	-68
   042A 11                  370 	.byte	17
   042B 00                  371 	.byte	0
   042C AE                  372 	.byte	-82
   042D 15                  373 	.byte	21
   042E 00                  374 	.byte	0
   042F B6                  375 	.byte	-74
   0430 12                  376 	.byte	18
   0431 FF                  377 	.byte	-1
   0432 AC                  378 	.byte	-84
   0433 15                  379 	.byte	21
   0434 FF                  380 	.byte	-1
   0435 B0                  381 	.byte	-80
   0436 14                  382 	.byte	20
   0437 00                  383 	.byte	0
   0438 A2                  384 	.byte	-94
   0439 18                  385 	.byte	24
   043A 00                  386 	.byte	0
   043B AA                  387 	.byte	-86
   043C 15                  388 	.byte	21
   043D FF                  389 	.byte	-1
   043E 84                  390 	.byte	-124
   043F 1F                  391 	.byte	31
   0440                     392 _vl_term_5_172:
   0440 01                  393 	.byte	1
                            394 	.globl	_vl_map_roadline_right_3
   0441                     395 _vl_map_roadline_right_3:
   0441 00                  396 	.byte	0
   0442 F0                  397 	.byte	-16
   0443 04                  398 	.byte	4
   0444 FF                  399 	.byte	-1
   0445 E4                  400 	.byte	-28
   0446 07                  401 	.byte	7
   0447 00                  402 	.byte	0
   0448 D8                  403 	.byte	-40
   0449 0A                  404 	.byte	10
   044A FF                  405 	.byte	-1
   044B CC                  406 	.byte	-52
   044C 0D                  407 	.byte	13
   044D 00                  408 	.byte	0
   044E C0                  409 	.byte	-64
   044F 10                  410 	.byte	16
   0450 FF                  411 	.byte	-1
   0451 B4                  412 	.byte	-76
   0452 13                  413 	.byte	19
   0453 00                  414 	.byte	0
   0454 A8                  415 	.byte	-88
   0455 16                  416 	.byte	22
   0456 FF                  417 	.byte	-1
   0457 9C                  418 	.byte	-100
   0458 19                  419 	.byte	25
   0459 00                  420 	.byte	0
   045A 90                  421 	.byte	-112
   045B 1C                  422 	.byte	28
   045C FF                  423 	.byte	-1
   045D 84                  424 	.byte	-124
   045E 1F                  425 	.byte	31
   045F 00                  426 	.byte	0
   0460 84                  427 	.byte	-124
   0461 1F                  428 	.byte	31
   0462 00                  429 	.byte	0
   0463 F4                  430 	.byte	-12
   0464 03                  431 	.byte	3
   0465 FF                  432 	.byte	-1
   0466 B0                  433 	.byte	-80
   0467 14                  434 	.byte	20
   0468 FF                  435 	.byte	-1
   0469 BC                  436 	.byte	-68
   046A 11                  437 	.byte	17
   046B 00                  438 	.byte	0
   046C AA                  439 	.byte	-86
   046D 16                  440 	.byte	22
   046E 00                  441 	.byte	0
   046F B6                  442 	.byte	-74
   0470 12                  443 	.byte	18
   0471 FF                  444 	.byte	-1
   0472 A4                  445 	.byte	-92
   0473 17                  446 	.byte	23
   0474 FF                  447 	.byte	-1
   0475 B0                  448 	.byte	-80
   0476 14                  449 	.byte	20
   0477                     450 _vl_term_6_196:
   0477 01                  451 	.byte	1
                            452 	.globl	_vl_map_roadline_right_4
   0478                     453 _vl_map_roadline_right_4:
   0478 FF                  454 	.byte	-1
   0479 F8                  455 	.byte	-8
   047A 02                  456 	.byte	2
   047B 00                  457 	.byte	0
   047C F0                  458 	.byte	-16
   047D 04                  459 	.byte	4
   047E FF                  460 	.byte	-1
   047F E0                  461 	.byte	-32
   0480 08                  462 	.byte	8
   0481 00                  463 	.byte	0
   0482 D0                  464 	.byte	-48
   0483 0C                  465 	.byte	12
   0484 FF                  466 	.byte	-1
   0485 C8                  467 	.byte	-56
   0486 0E                  468 	.byte	14
   0487 00                  469 	.byte	0
   0488 B8                  470 	.byte	-72
   0489 12                  471 	.byte	18
   048A FF                  472 	.byte	-1
   048B B0                  473 	.byte	-80
   048C 14                  474 	.byte	20
   048D 00                  475 	.byte	0
   048E A0                  476 	.byte	-96
   048F 18                  477 	.byte	24
   0490 FF                  478 	.byte	-1
   0491 98                  479 	.byte	-104
   0492 1A                  480 	.byte	26
   0493 00                  481 	.byte	0
   0494 88                  482 	.byte	-120
   0495 1E                  483 	.byte	30
   0496 FF                  484 	.byte	-1
   0497 81                  485 	.byte	-127
   0498 20                  486 	.byte	32
   0499 00                  487 	.byte	0
   049A 84                  488 	.byte	-124
   049B 1F                  489 	.byte	31
   049C 00                  490 	.byte	0
   049D EC                  491 	.byte	-20
   049E 05                  492 	.byte	5
   049F FF                  493 	.byte	-1
   04A0 AC                  494 	.byte	-84
   04A1 15                  495 	.byte	21
   04A2 FF                  496 	.byte	-1
   04A3 BC                  497 	.byte	-68
   04A4 11                  498 	.byte	17
   04A5 00                  499 	.byte	0
   04A6 A2                  500 	.byte	-94
   04A7 18                  501 	.byte	24
   04A8 00                  502 	.byte	0
   04A9 B6                  503 	.byte	-74
   04AA 12                  504 	.byte	18
   04AB FF                  505 	.byte	-1
   04AC A0                  506 	.byte	-96
   04AD 18                  507 	.byte	24
   04AE FF                  508 	.byte	-1
   04AF B0                  509 	.byte	-80
   04B0 14                  510 	.byte	20
   04B1                     511 _vl_term_7_221:
   04B1 01                  512 	.byte	1
                            513 	.globl	_step
                            514 	.area	.data
   C880                     515 _step:
   C880 00                  516 	.byte	0
                            517 	.area	.text
                            518 	.globl	_draw_step1
   04B2                     519 _draw_step1:
   04B2 BD F2 A5      [ 8]  520 	jsr	___Intensity_5F
   04B5 BD 05 75      [ 8]  521 	jsr	_draw_left
   04B8 7D C8 A8      [ 7]  522 	tst	_the_map
   04BB 26 12         [ 3]  523 	bne	L6
   04BD F6 C8 80      [ 5]  524 	ldb	_step
   04C0 C1 02         [ 2]  525 	cmpb	#2	;cmpqi:
   04C2 10 22 00 6B   [ 6]  526 	lbhi	L21
   04C6 5C            [ 2]  527 	incb
   04C7 F7 C8 80      [ 5]  528 	stb	_step
   04CA                     529 L8:
   04CA C6 0A         [ 2]  530 	ldb	#10
   04CC F7 C8 A8      [ 5]  531 	stb	_the_map
   04CF                     532 L6:
   04CF BD F3 54      [ 8]  533 	jsr	___Reset0Ref
   04D2 C6 7F         [ 2]  534 	ldb	#127
   04D4 D7 04         [ 4]  535 	stb	*_dp_VIA_t1_cnt_lo
   04D6 C6 24         [ 2]  536 	ldb	#36
   04D8 E7 E2         [ 6]  537 	stb	,-s
   04DA C6 FB         [ 2]  538 	ldb	#-5
   04DC BD 08 DD      [ 8]  539 	jsr	__Moveto_d
   04DF C6 10         [ 2]  540 	ldb	#16
   04E1 D7 04         [ 4]  541 	stb	*_dp_VIA_t1_cnt_lo
   04E3 32 61         [ 5]  542 	leas	1,s
   04E5 F6 C8 80      [ 5]  543 	ldb	_step
   04E8 C1 01         [ 2]  544 	cmpb	#1	;cmpqi:
   04EA 10 27 00 75   [ 6]  545 	lbeq	L11
   04EE 24 31         [ 3]  546 	bhs	L22
   04F0 8E 02 DC      [ 3]  547 	ldx	#_vl_map_roadline_left_1
   04F3 BD F4 10      [ 8]  548 	jsr	___Draw_VLp
   04F6                     549 L9:
   04F6 BD F3 54      [ 8]  550 	jsr	___Reset0Ref
   04F9 C6 7F         [ 2]  551 	ldb	#127
   04FB D7 04         [ 4]  552 	stb	*_dp_VIA_t1_cnt_lo
   04FD C6 24         [ 2]  553 	ldb	#36
   04FF E7 E2         [ 6]  554 	stb	,-s
   0501 C6 05         [ 2]  555 	ldb	#5
   0503 BD 08 DD      [ 8]  556 	jsr	__Moveto_d
   0506 C6 10         [ 2]  557 	ldb	#16
   0508 D7 04         [ 4]  558 	stb	*_dp_VIA_t1_cnt_lo
   050A 32 61         [ 5]  559 	leas	1,s
   050C F6 C8 80      [ 5]  560 	ldb	_step
   050F C1 01         [ 2]  561 	cmpb	#1	;cmpqi:
   0511 27 44         [ 3]  562 	beq	L16
   0513 24 22         [ 3]  563 	bhs	L23
   0515 8E 03 C7      [ 3]  564 	ldx	#_vl_map_roadline_right_1
   0518 BD F4 10      [ 8]  565 	jsr	___Draw_VLp
   051B                     566 L14:
   051B 7A C8 A8      [ 7]  567 	dec	_the_map
   051E 7E 05 95      [ 4]  568 	jmp	_draw_right
   0521                     569 L22:
   0521 C1 02         [ 2]  570 	cmpb	#2	;cmpqi:
   0523 27 47         [ 3]  571 	beq	L12
   0525 C1 03         [ 2]  572 	cmpb	#3	;cmpqi:
   0527 26 CD         [ 3]  573 	bne	L9
   0529 8E 03 8D      [ 3]  574 	ldx	#_vl_map_roadline_left_4
   052C BD F4 10      [ 8]  575 	jsr	___Draw_VLp
   052F 20 C5         [ 3]  576 	bra	L9
   0531                     577 L21:
   0531 7F C8 80      [ 7]  578 	clr	_step
   0534 16 FF 93      [ 5]  579 	lbra	L8
   0537                     580 L23:
   0537 C1 02         [ 2]  581 	cmpb	#2	;cmpqi:
   0539 27 10         [ 3]  582 	beq	L17
   053B C1 03         [ 2]  583 	cmpb	#3	;cmpqi:
   053D 26 DC         [ 3]  584 	bne	L14
   053F 8E 04 78      [ 3]  585 	ldx	#_vl_map_roadline_right_4
   0542 BD F4 10      [ 8]  586 	jsr	___Draw_VLp
   0545 7A C8 A8      [ 7]  587 	dec	_the_map
   0548 7E 05 95      [ 4]  588 	jmp	_draw_right
   054B                     589 L17:
   054B 8E 04 41      [ 3]  590 	ldx	#_vl_map_roadline_right_3
   054E BD F4 10      [ 8]  591 	jsr	___Draw_VLp
   0551 7A C8 A8      [ 7]  592 	dec	_the_map
   0554 7E 05 95      [ 4]  593 	jmp	_draw_right
   0557                     594 L16:
   0557 8E 04 01      [ 3]  595 	ldx	#_vl_map_roadline_right_2
   055A BD F4 10      [ 8]  596 	jsr	___Draw_VLp
   055D 7A C8 A8      [ 7]  597 	dec	_the_map
   0560 7E 05 95      [ 4]  598 	jmp	_draw_right
   0563                     599 L11:
   0563 8E 03 16      [ 3]  600 	ldx	#_vl_map_roadline_left_2
   0566 BD F4 10      [ 8]  601 	jsr	___Draw_VLp
   0569 16 FF 8A      [ 5]  602 	lbra	L9
   056C                     603 L12:
   056C 8E 03 56      [ 3]  604 	ldx	#_vl_map_roadline_left_3
   056F BD F4 10      [ 8]  605 	jsr	___Draw_VLp
   0572 16 FF 81      [ 5]  606 	lbra	L9
                            607 	.globl	_draw_left
   0575                     608 _draw_left:
   0575 BD F3 54      [ 8]  609 	jsr	___Reset0Ref
   0578 C6 7F         [ 2]  610 	ldb	#127
   057A D7 04         [ 4]  611 	stb	*_dp_VIA_t1_cnt_lo
   057C C6 24         [ 2]  612 	ldb	#36
   057E E7 E2         [ 6]  613 	stb	,-s
   0580 C6 F1         [ 2]  614 	ldb	#-15
   0582 BD 08 DD      [ 8]  615 	jsr	__Moveto_d
   0585 C6 A8         [ 2]  616 	ldb	#-88
   0587 D7 04         [ 4]  617 	stb	*_dp_VIA_t1_cnt_lo
   0589 C6 80         [ 2]  618 	ldb	#-128
   058B E7 E2         [ 6]  619 	stb	,-s
   058D CB 2E         [ 2]  620 	addb	#46
   058F BD 08 D8      [ 8]  621 	jsr	__Draw_Line_d
   0592 32 62         [ 5]  622 	leas	2,s
   0594 39            [ 5]  623 	rts
                            624 	.globl	_draw_right
   0595                     625 _draw_right:
   0595 BD F3 54      [ 8]  626 	jsr	___Reset0Ref
   0598 C6 7F         [ 2]  627 	ldb	#127
   059A D7 04         [ 4]  628 	stb	*_dp_VIA_t1_cnt_lo
   059C C6 24         [ 2]  629 	ldb	#36
   059E E7 E2         [ 6]  630 	stb	,-s
   05A0 C6 0F         [ 2]  631 	ldb	#15
   05A2 BD 08 DD      [ 8]  632 	jsr	__Moveto_d
   05A5 C6 A8         [ 2]  633 	ldb	#-88
   05A7 D7 04         [ 4]  634 	stb	*_dp_VIA_t1_cnt_lo
   05A9 C6 80         [ 2]  635 	ldb	#-128
   05AB E7 E2         [ 6]  636 	stb	,-s
   05AD C6 52         [ 2]  637 	ldb	#82
   05AF BD 08 D8      [ 8]  638 	jsr	__Draw_Line_d
   05B2 32 62         [ 5]  639 	leas	2,s
   05B4 39            [ 5]  640 	rts
                            641 	.globl	_CNT_SPEED_LUT
   05B5                     642 _CNT_SPEED_LUT:
   05B5 00 00 00 00 00 00   643 	.word	0,0,0
   05BB 00                  644 	.byte	0
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Thu Jun 12 23:11:43 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L11                0292 R   |   3 L12                029B R
  3 L14                024A R   |   3 L16                0286 R
  3 L17                027A R   |   3 L21                0260 R
  3 L22                0250 R   |   3 L23                0266 R
  3 L6                 01FE R   |   3 L8                 01F9 R
  3 L9                 0225 R   |   3 _CNT_SPEED_LUT     02E4 GR
    __Draw_Line_d      **** GX  |     __Moveto_d         **** GX
    ___Draw_VLp        **** GX  |     ___Intensity_5     **** GX
    ___Reset0Ref       **** GX  |     _dp_VIA_t1_cnt     **** GX
  3 _draw_left         02A4 GR  |   3 _draw_right        02C4 GR
  3 _draw_step1        01E1 GR  |   3 _dummy_tick        0000 GR
  3 _map_init          0001 GR  |   4 _step              0000 GR
  2 _the_map           0000 GR  |   3 _vl_map_roadli     000B GR
  3 _vl_map_roadli     0045 GR  |   3 _vl_map_roadli     0085 GR
  3 _vl_map_roadli     00BC GR  |   3 _vl_map_roadli     00F6 GR
  3 _vl_map_roadli     0130 GR  |   3 _vl_map_roadli     0170 GR
  3 _vl_map_roadli     01A7 GR  |   3 _vl_term_0_37      0044 R
  3 _vl_term_1_64      0084 R   |   3 _vl_term_2_88      00BB R
  3 _vl_term_3_113     00F5 R   |   3 _vl_term_4_145     012F R
  3 _vl_term_5_172     016F R   |   3 _vl_term_6_196     01A6 R
  3 _vl_term_7_221     01E0 R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Thu Jun 12 23:11:43 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    3   flags    0
   3 .text            size  2EB   flags  100
   4 .data            size    1   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

