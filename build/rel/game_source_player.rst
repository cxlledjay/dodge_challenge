                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	player.c
                              6 	.area	.bss
                              7 	.globl	_the_player
   C8AA                       8 _the_player:	.blkb	4
                              9 	.globl	_PLAYER_X_LUT
                             10 	.area	.text
   02DC                      11 _PLAYER_X_LUT:
   02DC AE                   12 	.byte	-82
   02DD 00                   13 	.byte	0
   02DE 52                   14 	.byte	82
                             15 	.globl	_PLAYER_DRAW_LUT
   02DF                      16 _PLAYER_DRAW_LUT:
   02DF 05 C7                17 	.word	__player_draw_left
   02E1 05 D1                18 	.word	__player_draw_mid
   02E3 05 DB                19 	.word	__player_draw_right
                             20 	.globl	_player_init
   02E5                      21 _player_init:
   02E5 8E 02 F4      [ 3]   22 	ldx	#_player_draw
   02E8 BF C8 AC      [ 6]   23 	stx	_the_player+2
   02EB 7F C8 AB      [ 7]   24 	clr	_the_player+1
   02EE C6 01         [ 2]   25 	ldb	#1
   02F0 F7 C8 AA      [ 5]   26 	stb	_the_player
   02F3 39            [ 5]   27 	rts
                             28 	.globl	_player_draw
   02F4                      29 _player_draw:
   02F4 32 7E         [ 5]   30 	leas	-2,s
   02F6 BD F2 A5      [ 8]   31 	jsr	___Intensity_5F
   02F9 BD F3 54      [ 8]   32 	jsr	___Reset0Ref
   02FC C6 7F         [ 2]   33 	ldb	#127
   02FE D7 04         [ 4]   34 	stb	*_dp_VIA_t1_cnt_lo
   0300 F6 C8 AA      [ 5]   35 	ldb	_the_player
   0303 4F            [ 2]   36 	clra		;zero_extendqihi: R:b -> R:d
   0304 1F 01         [ 6]   37 	tfr	d,x
   0306 C6 90         [ 2]   38 	ldb	#-112
   0308 E7 E2         [ 6]   39 	stb	,-s
   030A E6 89 02 DC   [ 8]   40 	ldb	_PLAYER_X_LUT,x
   030E BD 05 FA      [ 8]   41 	jsr	__Moveto_d
   0311 F6 C8 AA      [ 5]   42 	ldb	_the_player
   0314 4F            [ 2]   43 	clra		;zero_extendqihi: R:b -> R:d
   0315 ED 61         [ 6]   44 	std	1,s
   0317 58            [ 2]   45 	aslb
   0318 49            [ 2]   46 	rola
   0319 1F 01         [ 6]   47 	tfr	d,x
   031B AD 99 02 DF   [14]   48 	jsr	[_PLAYER_DRAW_LUT,x]
   031F 32 63         [ 5]   49 	leas	3,s
   0321 39            [ 5]   50 	rts
                             51 	.globl	_player_change_left
   0322                      52 _player_change_left:
   0322 F6 C8 AA      [ 5]   53 	ldb	_the_player
   0325 26 01         [ 3]   54 	bne	L9
   0327 39            [ 5]   55 	rts
   0328                      56 L9:
   0328 5A            [ 2]   57 	decb
   0329 F7 C8 AA      [ 5]   58 	stb	_the_player
   032C 8E 02 F4      [ 3]   59 	ldx	#_player_draw
   032F BF C8 AC      [ 6]   60 	stx	_the_player+2
   0332 7E 02 F4      [ 4]   61 	jmp	_player_draw
                             62 	.globl	_player_change_right
   0335                      63 _player_change_right:
   0335 F6 C8 AA      [ 5]   64 	ldb	_the_player
   0338 C1 02         [ 2]   65 	cmpb	#2	;cmpqi:
   033A 27 0D         [ 3]   66 	beq	L12
   033C 5C            [ 2]   67 	incb
   033D F7 C8 AA      [ 5]   68 	stb	_the_player
   0340 8E 02 F4      [ 3]   69 	ldx	#_player_draw
   0343 BF C8 AC      [ 6]   70 	stx	_the_player+2
   0346 7E 02 F4      [ 4]   71 	jmp	_player_draw
   0349                      72 L12:
   0349 39            [ 5]   73 	rts
                             74 	.globl	_check_collision
   034A                      75 _check_collision:
   034A 39            [ 5]   76 	rts
                             77 	.globl	_vl_player_mid
   034B                      78 _vl_player_mid:
   034B 00                   79 	.byte	0
   034C A0                   80 	.byte	-96
   034D B0                   81 	.byte	-80
   034E FF                   82 	.byte	-1
   034F 00                   83 	.byte	0
   0350 B0                   84 	.byte	-80
   0351 FF                   85 	.byte	-1
   0352 7F                   86 	.byte	127
   0353 00                   87 	.byte	0
   0354 FF                   88 	.byte	-1
   0355 00                   89 	.byte	0
   0356 50                   90 	.byte	80
   0357 FF                   91 	.byte	-1
   0358 80                   92 	.byte	-128
   0359 00                   93 	.byte	0
   035A 00                   94 	.byte	0
   035B 10                   95 	.byte	16
   035C 00                   96 	.byte	0
   035D FF                   97 	.byte	-1
   035E 10                   98 	.byte	16
   035F 3C                   99 	.byte	60
   0360 00                  100 	.byte	0
   0361 00                  101 	.byte	0
   0362 28                  102 	.byte	40
   0363 FF                  103 	.byte	-1
   0364 F0                  104 	.byte	-16
   0365 3C                  105 	.byte	60
   0366 00                  106 	.byte	0
   0367 F0                  107 	.byte	-16
   0368 00                  108 	.byte	0
   0369 FF                  109 	.byte	-1
   036A 00                  110 	.byte	0
   036B 50                  111 	.byte	80
   036C FF                  112 	.byte	-1
   036D 7F                  113 	.byte	127
   036E 00                  114 	.byte	0
   036F FF                  115 	.byte	-1
   0370 00                  116 	.byte	0
   0371 B0                  117 	.byte	-80
   0372 FF                  118 	.byte	-1
   0373 80                  119 	.byte	-128
   0374 00                  120 	.byte	0
   0375 00                  121 	.byte	0
   0376 20                  122 	.byte	32
   0377 00                  123 	.byte	0
   0378 FF                  124 	.byte	-1
   0379 00                  125 	.byte	0
   037A B0                  126 	.byte	-80
   037B FF                  127 	.byte	-1
   037C 00                  128 	.byte	0
   037D B0                  129 	.byte	-80
   037E 00                  130 	.byte	0
   037F 40                  131 	.byte	64
   0380 00                  132 	.byte	0
   0381 FF                  133 	.byte	-1
   0382 10                  134 	.byte	16
   0383 3C                  135 	.byte	60
   0384 FF                  136 	.byte	-1
   0385 00                  137 	.byte	0
   0386 28                  138 	.byte	40
   0387 FF                  139 	.byte	-1
   0388 F0                  140 	.byte	-16
   0389 3C                  141 	.byte	60
   038A FF                  142 	.byte	-1
   038B 70                  143 	.byte	112
   038C C0                  144 	.byte	-64
   038D FF                  145 	.byte	-1
   038E 00                  146 	.byte	0
   038F E0                  147 	.byte	-32
   0390 00                  148 	.byte	0
   0391 E4                  149 	.byte	-28
   0392 30                  150 	.byte	48
   0393 FF                  151 	.byte	-1
   0394 00                  152 	.byte	0
   0395 30                  153 	.byte	48
   0396 FF                  154 	.byte	-1
   0397 10                  155 	.byte	16
   0398 F8                  156 	.byte	-8
   0399 FF                  157 	.byte	-1
   039A 00                  158 	.byte	0
   039B D0                  159 	.byte	-48
   039C 00                  160 	.byte	0
   039D 00                  161 	.byte	0
   039E D0                  162 	.byte	-48
   039F FF                  163 	.byte	-1
   03A0 00                  164 	.byte	0
   03A1 D0                  165 	.byte	-48
   03A2 FF                  166 	.byte	-1
   03A3 F0                  167 	.byte	-16
   03A4 F8                  168 	.byte	-8
   03A5 FF                  169 	.byte	-1
   03A6 00                  170 	.byte	0
   03A7 30                  171 	.byte	48
   03A8 00                  172 	.byte	0
   03A9 1C                  173 	.byte	28
   03AA 10                  174 	.byte	16
   03AB FF                  175 	.byte	-1
   03AC 90                  176 	.byte	-112
   03AD C0                  177 	.byte	-64
   03AE 00                  178 	.byte	0
   03AF 20                  179 	.byte	32
   03B0 D8                  180 	.byte	-40
   03B1 FF                  181 	.byte	-1
   03B2 28                  182 	.byte	40
   03B3 00                  183 	.byte	0
   03B4 FF                  184 	.byte	-1
   03B5 00                  185 	.byte	0
   03B6 3C                  186 	.byte	60
   03B7 FF                  187 	.byte	-1
   03B8 DC                  188 	.byte	-36
   03B9 00                  189 	.byte	0
   03BA 00                  190 	.byte	0
   03BB 00                  191 	.byte	0
   03BC 78                  192 	.byte	120
   03BD FF                  193 	.byte	-1
   03BE 24                  194 	.byte	36
   03BF 00                  195 	.byte	0
   03C0 FF                  196 	.byte	-1
   03C1 00                  197 	.byte	0
   03C2 3C                  198 	.byte	60
   03C3 FF                  199 	.byte	-1
   03C4 D8                  200 	.byte	-40
   03C5 00                  201 	.byte	0
   03C6 00                  202 	.byte	0
   03C7 14                  203 	.byte	20
   03C8 9C                  204 	.byte	-100
   03C9 FF                  205 	.byte	-1
   03CA 10                  206 	.byte	16
   03CB F8                  207 	.byte	-8
   03CC FF                  208 	.byte	-1
   03CD 00                  209 	.byte	0
   03CE E8                  210 	.byte	-24
   03CF FF                  211 	.byte	-1
   03D0 F0                  212 	.byte	-16
   03D1 F8                  213 	.byte	-8
   03D2                     214 _vl_term_0_76:
   03D2 01                  215 	.byte	1
                            216 	.globl	_vl_player_left
   03D3                     217 _vl_player_left:
   03D3 00                  218 	.byte	0
   03D4 0C                  219 	.byte	12
   03D5 78                  220 	.byte	120
   03D6 FF                  221 	.byte	-1
   03D7 88                  222 	.byte	-120
   03D8 00                  223 	.byte	0
   03D9 FF                  224 	.byte	-1
   03DA DC                  225 	.byte	-36
   03DB 18                  226 	.byte	24
   03DC FF                  227 	.byte	-1
   03DD 00                  228 	.byte	0
   03DE 78                  229 	.byte	120
   03DF FF                  230 	.byte	-1
   03E0 24                  231 	.byte	36
   03E1 18                  232 	.byte	24
   03E2 FF                  233 	.byte	-1
   03E3 78                  234 	.byte	120
   03E4 00                  235 	.byte	0
   03E5 FF                  236 	.byte	-1
   03E6 24                  237 	.byte	36
   03E7 E8                  238 	.byte	-24
   03E8 FF                  239 	.byte	-1
   03E9 00                  240 	.byte	0
   03EA 88                  241 	.byte	-120
   03EB FF                  242 	.byte	-1
   03EC DC                  243 	.byte	-36
   03ED E8                  244 	.byte	-24
   03EE 00                  245 	.byte	0
   03EF F4                  246 	.byte	-12
   03F0 00                  247 	.byte	0
   03F1 FF                  248 	.byte	-1
   03F2 18                  249 	.byte	24
   03F3 A6                  250 	.byte	-90
   03F4 FF                  251 	.byte	-1
   03F5 00                  252 	.byte	0
   03F6 C4                  253 	.byte	-60
   03F7 FF                  254 	.byte	-1
   03F8 E8                  255 	.byte	-24
   03F9 A6                  256 	.byte	-90
   03FA 00                  257 	.byte	0
   03FB 0C                  258 	.byte	12
   03FC 00                  259 	.byte	0
   03FD FF                  260 	.byte	-1
   03FE 88                  261 	.byte	-120
   03FF 00                  262 	.byte	0
   0400 FF                  263 	.byte	-1
   0401 DC                  264 	.byte	-36
   0402 18                  265 	.byte	24
   0403 FF                  266 	.byte	-1
   0404 24                  267 	.byte	36
   0405 18                  268 	.byte	24
   0406 FF                  269 	.byte	-1
   0407 0C                  270 	.byte	12
   0408 00                  271 	.byte	0
   0409 00                  272 	.byte	0
   040A E8                  273 	.byte	-24
   040B DC                  274 	.byte	-36
   040C FF                  275 	.byte	-1
   040D 18                  276 	.byte	24
   040E 4E                  277 	.byte	78
   040F 00                  278 	.byte	0
   0410 00                  279 	.byte	0
   0411 A6                  280 	.byte	-90
   0412 FF                  281 	.byte	-1
   0413 00                  282 	.byte	0
   0414 78                  283 	.byte	120
   0415 FF                  284 	.byte	-1
   0416 00                  285 	.byte	0
   0417 78                  286 	.byte	120
   0418 00                  287 	.byte	0
   0419 00                  288 	.byte	0
   041A A6                  289 	.byte	-90
   041B FF                  290 	.byte	-1
   041C E8                  291 	.byte	-24
   041D 60                  292 	.byte	96
   041E 00                  293 	.byte	0
   041F F4                  294 	.byte	-12
   0420 45                  295 	.byte	69
   0421 00                  296 	.byte	0
   0422 F4                  297 	.byte	-12
   0423 45                  298 	.byte	69
   0424 FF                  299 	.byte	-1
   0425 24                  300 	.byte	36
   0426 E8                  301 	.byte	-24
   0427 FF                  302 	.byte	-1
   0428 78                  303 	.byte	120
   0429 00                  304 	.byte	0
   042A FF                  305 	.byte	-1
   042B 24                  306 	.byte	36
   042C 18                  307 	.byte	24
   042D 00                  308 	.byte	0
   042E D0                  309 	.byte	-48
   042F 18                  310 	.byte	24
   0430 FF                  311 	.byte	-1
   0431 00                  312 	.byte	0
   0432 1E                  313 	.byte	30
   0433 FF                  314 	.byte	-1
   0434 18                  315 	.byte	24
   0435 0C                  316 	.byte	12
   0436 FF                  317 	.byte	-1
   0437 54                  318 	.byte	84
   0438 00                  319 	.byte	0
   0439 FF                  320 	.byte	-1
   043A 18                  321 	.byte	24
   043B F4                  322 	.byte	-12
   043C FF                  323 	.byte	-1
   043D E8                  324 	.byte	-24
   043E F4                  325 	.byte	-12
   043F FF                  326 	.byte	-1
   0440 AC                  327 	.byte	-84
   0441 00                  328 	.byte	0
   0442 FF                  329 	.byte	-1
   0443 E8                  330 	.byte	-24
   0444 0C                  331 	.byte	12
   0445 00                  332 	.byte	0
   0446 45                  333 	.byte	69
   0447 00                  334 	.byte	0
   0448 00                  335 	.byte	0
   0449 45                  336 	.byte	69
   044A 00                  337 	.byte	0
   044B FF                  338 	.byte	-1
   044C 00                  339 	.byte	0
   044D 94                  340 	.byte	-108
   044E FF                  341 	.byte	-1
   044F E8                  342 	.byte	-24
   0450 F4                  343 	.byte	-12
   0451 FF                  344 	.byte	-1
   0452 C4                  345 	.byte	-60
   0453 00                  346 	.byte	0
   0454 00                  347 	.byte	0
   0455 00                  348 	.byte	0
   0456 E2                  349 	.byte	-30
   0457 FF                  350 	.byte	-1
   0458 2A                  351 	.byte	42
   0459 1E                  352 	.byte	30
   045A 00                  353 	.byte	0
   045B 2A                  354 	.byte	42
   045C 18                  355 	.byte	24
   045D FF                  356 	.byte	-1
   045E 3C                  357 	.byte	60
   045F 2A                  358 	.byte	42
   0460 00                  359 	.byte	0
   0461 F4                  360 	.byte	-12
   0462 F4                  361 	.byte	-12
   0463 FF                  362 	.byte	-1
   0464 00                  363 	.byte	0
   0465 30                  364 	.byte	48
   0466 FF                  365 	.byte	-1
   0467 E8                  366 	.byte	-24
   0468 F4                  367 	.byte	-12
   0469 FF                  368 	.byte	-1
   046A 00                  369 	.byte	0
   046B D0                  370 	.byte	-48
   046C 00                  371 	.byte	0
   046D 24                  372 	.byte	36
   046E 18                  373 	.byte	24
   046F FF                  374 	.byte	-1
   0470 00                  375 	.byte	0
   0471 C4                  376 	.byte	-60
   0472 00                  377 	.byte	0
   0473 F4                  378 	.byte	-12
   0474 EE                  379 	.byte	-18
   0475 FF                  380 	.byte	-1
   0476 00                  381 	.byte	0
   0477 D0                  382 	.byte	-48
   0478 FF                  383 	.byte	-1
   0479 E8                  384 	.byte	-24
   047A DC                  385 	.byte	-36
   047B FF                  386 	.byte	-1
   047C 00                  387 	.byte	0
   047D 2A                  388 	.byte	42
   047E 00                  389 	.byte	0
   047F 24                  390 	.byte	36
   0480 3C                  391 	.byte	60
   0481 FF                  392 	.byte	-1
   0482 C0                  393 	.byte	-64
   0483 94                  394 	.byte	-108
   0484 FF                  395 	.byte	-1
   0485 C0                  396 	.byte	-64
   0486 94                  397 	.byte	-108
   0487 FF                  398 	.byte	-1
   0488 C0                  399 	.byte	-64
   0489 94                  400 	.byte	-108
   048A 00                  401 	.byte	0
   048B 0C                  402 	.byte	12
   048C 00                  403 	.byte	0
   048D FF                  404 	.byte	-1
   048E 24                  405 	.byte	36
   048F 18                  406 	.byte	24
   0490 FF                  407 	.byte	-1
   0491 E8                  408 	.byte	-24
   0492 12                  409 	.byte	18
   0493 00                  410 	.byte	0
   0494 AC                  411 	.byte	-84
   0495 F7                  412 	.byte	-9
   0496 00                  413 	.byte	0
   0497 AC                  414 	.byte	-84
   0498 F7                  415 	.byte	-9
   0499 FF                  416 	.byte	-1
   049A 00                  417 	.byte	0
   049B 88                  418 	.byte	-120
   049C FF                  419 	.byte	-1
   049D 24                  420 	.byte	36
   049E E8                  421 	.byte	-24
   049F FF                  422 	.byte	-1
   04A0 78                  423 	.byte	120
   04A1 00                  424 	.byte	0
   04A2 FF                  425 	.byte	-1
   04A3 24                  426 	.byte	36
   04A4 18                  427 	.byte	24
   04A5 FF                  428 	.byte	-1
   04A6 00                  429 	.byte	0
   04A7 78                  430 	.byte	120
   04A8 00                  431 	.byte	0
   04A9 FA                  432 	.byte	-6
   04AA 2A                  433 	.byte	42
   04AB FF                  434 	.byte	-1
   04AC 48                  435 	.byte	72
   04AD 00                  436 	.byte	0
   04AE FF                  437 	.byte	-1
   04AF 18                  438 	.byte	24
   04B0 0C                  439 	.byte	12
   04B1 FF                  440 	.byte	-1
   04B2 00                  441 	.byte	0
   04B3 6C                  442 	.byte	108
   04B4 FF                  443 	.byte	-1
   04B5 E8                  444 	.byte	-24
   04B6 F4                  445 	.byte	-12
   04B7 FF                  446 	.byte	-1
   04B8 F4                  447 	.byte	-12
   04B9 00                  448 	.byte	0
   04BA 00                  449 	.byte	0
   04BB 24                  450 	.byte	36
   04BC 0C                  451 	.byte	12
   04BD FF                  452 	.byte	-1
   04BE EE                  453 	.byte	-18
   04BF 0C                  454 	.byte	12
   04C0 00                  455 	.byte	0
   04C1 CA                  456 	.byte	-54
   04C2 E2                  457 	.byte	-30
   04C3 FF                  458 	.byte	-1
   04C4 24                  459 	.byte	36
   04C5 42                  460 	.byte	66
   04C6 FF                  461 	.byte	-1
   04C7 00                  462 	.byte	0
   04C8 2A                  463 	.byte	42
   04C9 FF                  464 	.byte	-1
   04CA DC                  465 	.byte	-36
   04CB E8                  466 	.byte	-24
   04CC                     467 _vl_term_1_189:
   04CC 01                  468 	.byte	1
                            469 	.globl	_vl_player_right
   04CD                     470 _vl_player_right:
   04CD 00                  471 	.byte	0
   04CE 0C                  472 	.byte	12
   04CF 88                  473 	.byte	-120
   04D0 FF                  474 	.byte	-1
   04D1 88                  475 	.byte	-120
   04D2 00                  476 	.byte	0
   04D3 FF                  477 	.byte	-1
   04D4 DC                  478 	.byte	-36
   04D5 E8                  479 	.byte	-24
   04D6 FF                  480 	.byte	-1
   04D7 00                  481 	.byte	0
   04D8 88                  482 	.byte	-120
   04D9 FF                  483 	.byte	-1
   04DA 24                  484 	.byte	36
   04DB E8                  485 	.byte	-24
   04DC FF                  486 	.byte	-1
   04DD 78                  487 	.byte	120
   04DE 00                  488 	.byte	0
   04DF FF                  489 	.byte	-1
   04E0 24                  490 	.byte	36
   04E1 18                  491 	.byte	24
   04E2 FF                  492 	.byte	-1
   04E3 00                  493 	.byte	0
   04E4 78                  494 	.byte	120
   04E5 FF                  495 	.byte	-1
   04E6 DC                  496 	.byte	-36
   04E7 18                  497 	.byte	24
   04E8 00                  498 	.byte	0
   04E9 F4                  499 	.byte	-12
   04EA 00                  500 	.byte	0
   04EB FF                  501 	.byte	-1
   04EC 18                  502 	.byte	24
   04ED 5A                  503 	.byte	90
   04EE FF                  504 	.byte	-1
   04EF 00                  505 	.byte	0
   04F0 3C                  506 	.byte	60
   04F1 FF                  507 	.byte	-1
   04F2 E8                  508 	.byte	-24
   04F3 5A                  509 	.byte	90
   04F4 00                  510 	.byte	0
   04F5 0C                  511 	.byte	12
   04F6 00                  512 	.byte	0
   04F7 FF                  513 	.byte	-1
   04F8 88                  514 	.byte	-120
   04F9 00                  515 	.byte	0
   04FA FF                  516 	.byte	-1
   04FB DC                  517 	.byte	-36
   04FC E8                  518 	.byte	-24
   04FD FF                  519 	.byte	-1
   04FE 24                  520 	.byte	36
   04FF E8                  521 	.byte	-24
   0500 FF                  522 	.byte	-1
   0501 0C                  523 	.byte	12
   0502 00                  524 	.byte	0
   0503 00                  525 	.byte	0
   0504 E8                  526 	.byte	-24
   0505 24                  527 	.byte	36
   0506 FF                  528 	.byte	-1
   0507 18                  529 	.byte	24
   0508 B2                  530 	.byte	-78
   0509 00                  531 	.byte	0
   050A 00                  532 	.byte	0
   050B 5A                  533 	.byte	90
   050C FF                  534 	.byte	-1
   050D 00                  535 	.byte	0
   050E 88                  536 	.byte	-120
   050F FF                  537 	.byte	-1
   0510 00                  538 	.byte	0
   0511 88                  539 	.byte	-120
   0512 00                  540 	.byte	0
   0513 00                  541 	.byte	0
   0514 5A                  542 	.byte	90
   0515 FF                  543 	.byte	-1
   0516 E8                  544 	.byte	-24
   0517 A0                  545 	.byte	-96
   0518 00                  546 	.byte	0
   0519 F4                  547 	.byte	-12
   051A BB                  548 	.byte	-69
   051B 00                  549 	.byte	0
   051C F4                  550 	.byte	-12
   051D BB                  551 	.byte	-69
   051E FF                  552 	.byte	-1
   051F 24                  553 	.byte	36
   0520 18                  554 	.byte	24
   0521 FF                  555 	.byte	-1
   0522 78                  556 	.byte	120
   0523 00                  557 	.byte	0
   0524 FF                  558 	.byte	-1
   0525 24                  559 	.byte	36
   0526 E8                  560 	.byte	-24
   0527 00                  561 	.byte	0
   0528 D0                  562 	.byte	-48
   0529 E8                  563 	.byte	-24
   052A FF                  564 	.byte	-1
   052B 00                  565 	.byte	0
   052C E2                  566 	.byte	-30
   052D FF                  567 	.byte	-1
   052E 18                  568 	.byte	24
   052F F4                  569 	.byte	-12
   0530 FF                  570 	.byte	-1
   0531 54                  571 	.byte	84
   0532 00                  572 	.byte	0
   0533 FF                  573 	.byte	-1
   0534 18                  574 	.byte	24
   0535 0C                  575 	.byte	12
   0536 FF                  576 	.byte	-1
   0537 E8                  577 	.byte	-24
   0538 0C                  578 	.byte	12
   0539 FF                  579 	.byte	-1
   053A AC                  580 	.byte	-84
   053B 00                  581 	.byte	0
   053C FF                  582 	.byte	-1
   053D E8                  583 	.byte	-24
   053E F4                  584 	.byte	-12
   053F 00                  585 	.byte	0
   0540 45                  586 	.byte	69
   0541 00                  587 	.byte	0
   0542 00                  588 	.byte	0
   0543 45                  589 	.byte	69
   0544 00                  590 	.byte	0
   0545 FF                  591 	.byte	-1
   0546 00                  592 	.byte	0
   0547 6C                  593 	.byte	108
   0548 FF                  594 	.byte	-1
   0549 E8                  595 	.byte	-24
   054A 0C                  596 	.byte	12
   054B FF                  597 	.byte	-1
   054C C4                  598 	.byte	-60
   054D 00                  599 	.byte	0
   054E 00                  600 	.byte	0
   054F 00                  601 	.byte	0
   0550 1E                  602 	.byte	30
   0551 FF                  603 	.byte	-1
   0552 2A                  604 	.byte	42
   0553 E2                  605 	.byte	-30
   0554 00                  606 	.byte	0
   0555 2A                  607 	.byte	42
   0556 E8                  608 	.byte	-24
   0557 FF                  609 	.byte	-1
   0558 3C                  610 	.byte	60
   0559 D6                  611 	.byte	-42
   055A 00                  612 	.byte	0
   055B F4                  613 	.byte	-12
   055C 0C                  614 	.byte	12
   055D FF                  615 	.byte	-1
   055E 00                  616 	.byte	0
   055F D0                  617 	.byte	-48
   0560 FF                  618 	.byte	-1
   0561 E8                  619 	.byte	-24
   0562 0C                  620 	.byte	12
   0563 FF                  621 	.byte	-1
   0564 00                  622 	.byte	0
   0565 30                  623 	.byte	48
   0566 00                  624 	.byte	0
   0567 24                  625 	.byte	36
   0568 E8                  626 	.byte	-24
   0569 FF                  627 	.byte	-1
   056A 00                  628 	.byte	0
   056B 3C                  629 	.byte	60
   056C 00                  630 	.byte	0
   056D F4                  631 	.byte	-12
   056E 12                  632 	.byte	18
   056F FF                  633 	.byte	-1
   0570 00                  634 	.byte	0
   0571 30                  635 	.byte	48
   0572 FF                  636 	.byte	-1
   0573 E8                  637 	.byte	-24
   0574 24                  638 	.byte	36
   0575 FF                  639 	.byte	-1
   0576 00                  640 	.byte	0
   0577 D6                  641 	.byte	-42
   0578 00                  642 	.byte	0
   0579 24                  643 	.byte	36
   057A C4                  644 	.byte	-60
   057B FF                  645 	.byte	-1
   057C C0                  646 	.byte	-64
   057D 6C                  647 	.byte	108
   057E FF                  648 	.byte	-1
   057F C0                  649 	.byte	-64
   0580 6C                  650 	.byte	108
   0581 FF                  651 	.byte	-1
   0582 C0                  652 	.byte	-64
   0583 6C                  653 	.byte	108
   0584 00                  654 	.byte	0
   0585 0C                  655 	.byte	12
   0586 00                  656 	.byte	0
   0587 FF                  657 	.byte	-1
   0588 24                  658 	.byte	36
   0589 E8                  659 	.byte	-24
   058A FF                  660 	.byte	-1
   058B E8                  661 	.byte	-24
   058C EE                  662 	.byte	-18
   058D 00                  663 	.byte	0
   058E AC                  664 	.byte	-84
   058F 09                  665 	.byte	9
   0590 00                  666 	.byte	0
   0591 AC                  667 	.byte	-84
   0592 09                  668 	.byte	9
   0593 FF                  669 	.byte	-1
   0594 00                  670 	.byte	0
   0595 78                  671 	.byte	120
   0596 FF                  672 	.byte	-1
   0597 24                  673 	.byte	36
   0598 18                  674 	.byte	24
   0599 FF                  675 	.byte	-1
   059A 78                  676 	.byte	120
   059B 00                  677 	.byte	0
   059C FF                  678 	.byte	-1
   059D 24                  679 	.byte	36
   059E E8                  680 	.byte	-24
   059F FF                  681 	.byte	-1
   05A0 00                  682 	.byte	0
   05A1 88                  683 	.byte	-120
   05A2 00                  684 	.byte	0
   05A3 FA                  685 	.byte	-6
   05A4 D6                  686 	.byte	-42
   05A5 FF                  687 	.byte	-1
   05A6 48                  688 	.byte	72
   05A7 00                  689 	.byte	0
   05A8 FF                  690 	.byte	-1
   05A9 18                  691 	.byte	24
   05AA F4                  692 	.byte	-12
   05AB FF                  693 	.byte	-1
   05AC 00                  694 	.byte	0
   05AD 94                  695 	.byte	-108
   05AE FF                  696 	.byte	-1
   05AF E8                  697 	.byte	-24
   05B0 0C                  698 	.byte	12
   05B1 FF                  699 	.byte	-1
   05B2 F4                  700 	.byte	-12
   05B3 00                  701 	.byte	0
   05B4 00                  702 	.byte	0
   05B5 24                  703 	.byte	36
   05B6 F4                  704 	.byte	-12
   05B7 FF                  705 	.byte	-1
   05B8 EE                  706 	.byte	-18
   05B9 F4                  707 	.byte	-12
   05BA 00                  708 	.byte	0
   05BB CA                  709 	.byte	-54
   05BC 1E                  710 	.byte	30
   05BD FF                  711 	.byte	-1
   05BE 24                  712 	.byte	36
   05BF BE                  713 	.byte	-66
   05C0 FF                  714 	.byte	-1
   05C1 00                  715 	.byte	0
   05C2 D6                  716 	.byte	-42
   05C3 FF                  717 	.byte	-1
   05C4 DC                  718 	.byte	-36
   05C5 18                  719 	.byte	24
   05C6                     720 _vl_term_2_302:
   05C6 01                  721 	.byte	1
                            722 	.globl	__player_draw_left
   05C7                     723 __player_draw_left:
   05C7 C6 0A         [ 2]  724 	ldb	#10
   05C9 D7 04         [ 4]  725 	stb	*_dp_VIA_t1_cnt_lo
   05CB 8E 03 D3      [ 3]  726 	ldx	#_vl_player_left
   05CE 7E F4 10      [ 4]  727 	jmp	___Draw_VLp
                            728 	.globl	__player_draw_mid
   05D1                     729 __player_draw_mid:
   05D1 C6 10         [ 2]  730 	ldb	#16
   05D3 D7 04         [ 4]  731 	stb	*_dp_VIA_t1_cnt_lo
   05D5 8E 03 4B      [ 3]  732 	ldx	#_vl_player_mid
   05D8 7E F4 10      [ 4]  733 	jmp	___Draw_VLp
                            734 	.globl	__player_draw_right
   05DB                     735 __player_draw_right:
   05DB C6 0A         [ 2]  736 	ldb	#10
   05DD D7 04         [ 4]  737 	stb	*_dp_VIA_t1_cnt_lo
   05DF 8E 04 CD      [ 3]  738 	ldx	#_vl_player_right
   05E2 7E F4 10      [ 4]  739 	jmp	___Draw_VLp
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Thu Jun 12 18:40:10 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L12                006D R   |   3 L9                 004C R
  3 _PLAYER_DRAW_L     0003 GR  |   3 _PLAYER_X_LUT      0000 GR
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
  3 __player_draw_     02EB GR  |   3 __player_draw_     02F5 GR
  3 __player_draw_     02FF GR  |   3 _check_collisi     006E GR
    _dp_VIA_t1_cnt     **** GX  |   3 _player_change     0046 GR
  3 _player_change     0059 GR  |   3 _player_draw       0018 GR
  3 _player_init       0009 GR  |   2 _the_player        0000 GR
  3 _vl_player_lef     00F7 GR  |   3 _vl_player_mid     006F GR
  3 _vl_player_rig     01F1 GR  |   3 _vl_term_0_76      00F6 R
  3 _vl_term_1_189     01F0 R   |   3 _vl_term_2_302     02EA R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Thu Jun 12 18:40:10 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    4   flags    0
   3 .text            size  309   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

