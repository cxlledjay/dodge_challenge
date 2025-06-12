                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	player.c
                              6 	.area	.bss
                              7 	.globl	_the_player
   C8AB                       8 _the_player:	.blkb	4
                              9 	.globl	_PLAYER_X_LUT
                             10 	.area	.text
   04F3                      11 _PLAYER_X_LUT:
   04F3 AE                   12 	.byte	-82
   04F4 00                   13 	.byte	0
   04F5 52                   14 	.byte	82
                             15 	.globl	_PLAYER_DRAW_LUT
   04F6                      16 _PLAYER_DRAW_LUT:
   04F6 07 DC                17 	.word	__player_draw_left
   04F8 07 E6                18 	.word	__player_draw_mid
   04FA 07 F0                19 	.word	__player_draw_right
                             20 	.globl	_player_init
   04FC                      21 _player_init:
   04FC 8E 05 0B      [ 3]   22 	ldx	#_player_draw
   04FF BF C8 AD      [ 6]   23 	stx	_the_player+2
   0502 7F C8 AC      [ 7]   24 	clr	_the_player+1
   0505 C6 01         [ 2]   25 	ldb	#1
   0507 F7 C8 AB      [ 5]   26 	stb	_the_player
   050A 39            [ 5]   27 	rts
                             28 	.globl	_player_draw
   050B                      29 _player_draw:
   050B 32 7E         [ 5]   30 	leas	-2,s
   050D BD F2 A5      [ 8]   31 	jsr	___Intensity_5F
   0510 BD F3 54      [ 8]   32 	jsr	___Reset0Ref
   0513 C6 7F         [ 2]   33 	ldb	#127
   0515 D7 04         [ 4]   34 	stb	*_dp_VIA_t1_cnt_lo
   0517 F6 C8 AB      [ 5]   35 	ldb	_the_player
   051A 4F            [ 2]   36 	clra		;zero_extendqihi: R:b -> R:d
   051B 1F 01         [ 6]   37 	tfr	d,x
   051D C6 90         [ 2]   38 	ldb	#-112
   051F E7 E2         [ 6]   39 	stb	,-s
   0521 E6 89 04 F3   [ 8]   40 	ldb	_PLAYER_X_LUT,x
   0525 BD 08 14      [ 8]   41 	jsr	__Moveto_d
   0528 F6 C8 AB      [ 5]   42 	ldb	_the_player
   052B 4F            [ 2]   43 	clra		;zero_extendqihi: R:b -> R:d
   052C ED 61         [ 6]   44 	std	1,s
   052E 58            [ 2]   45 	aslb
   052F 49            [ 2]   46 	rola
   0530 1F 01         [ 6]   47 	tfr	d,x
   0532 AD 99 04 F6   [14]   48 	jsr	[_PLAYER_DRAW_LUT,x]
   0536 32 63         [ 5]   49 	leas	3,s
   0538 39            [ 5]   50 	rts
                             51 	.globl	_player_change_left
   0539                      52 _player_change_left:
   0539 F6 C8 AB      [ 5]   53 	ldb	_the_player
   053C 27 04         [ 3]   54 	beq	L6
   053E 5A            [ 2]   55 	decb
   053F F7 C8 AB      [ 5]   56 	stb	_the_player
   0542                      57 L6:
   0542 8E 05 0B      [ 3]   58 	ldx	#_player_draw
   0545 BF C8 AD      [ 6]   59 	stx	_the_player+2
   0548 7E 05 0B      [ 4]   60 	jmp	_player_draw
                             61 	.globl	_player_change_right
   054B                      62 _player_change_right:
   054B F6 C8 AB      [ 5]   63 	ldb	_the_player
   054E C1 02         [ 2]   64 	cmpb	#2	;cmpqi:
   0550 27 04         [ 3]   65 	beq	L10
   0552 5C            [ 2]   66 	incb
   0553 F7 C8 AB      [ 5]   67 	stb	_the_player
   0556                      68 L10:
   0556 8E 05 0B      [ 3]   69 	ldx	#_player_draw
   0559 BF C8 AD      [ 6]   70 	stx	_the_player+2
   055C 7E 05 0B      [ 4]   71 	jmp	_player_draw
                             72 	.globl	_check_collision
   055F                      73 _check_collision:
   055F 39            [ 5]   74 	rts
                             75 	.globl	_vl_player_mid
   0560                      76 _vl_player_mid:
   0560 00                   77 	.byte	0
   0561 A0                   78 	.byte	-96
   0562 B0                   79 	.byte	-80
   0563 FF                   80 	.byte	-1
   0564 00                   81 	.byte	0
   0565 B0                   82 	.byte	-80
   0566 FF                   83 	.byte	-1
   0567 7F                   84 	.byte	127
   0568 00                   85 	.byte	0
   0569 FF                   86 	.byte	-1
   056A 00                   87 	.byte	0
   056B 50                   88 	.byte	80
   056C FF                   89 	.byte	-1
   056D 80                   90 	.byte	-128
   056E 00                   91 	.byte	0
   056F 00                   92 	.byte	0
   0570 10                   93 	.byte	16
   0571 00                   94 	.byte	0
   0572 FF                   95 	.byte	-1
   0573 10                   96 	.byte	16
   0574 3C                   97 	.byte	60
   0575 00                   98 	.byte	0
   0576 00                   99 	.byte	0
   0577 28                  100 	.byte	40
   0578 FF                  101 	.byte	-1
   0579 F0                  102 	.byte	-16
   057A 3C                  103 	.byte	60
   057B 00                  104 	.byte	0
   057C F0                  105 	.byte	-16
   057D 00                  106 	.byte	0
   057E FF                  107 	.byte	-1
   057F 00                  108 	.byte	0
   0580 50                  109 	.byte	80
   0581 FF                  110 	.byte	-1
   0582 7F                  111 	.byte	127
   0583 00                  112 	.byte	0
   0584 FF                  113 	.byte	-1
   0585 00                  114 	.byte	0
   0586 B0                  115 	.byte	-80
   0587 FF                  116 	.byte	-1
   0588 80                  117 	.byte	-128
   0589 00                  118 	.byte	0
   058A 00                  119 	.byte	0
   058B 20                  120 	.byte	32
   058C 00                  121 	.byte	0
   058D FF                  122 	.byte	-1
   058E 00                  123 	.byte	0
   058F B0                  124 	.byte	-80
   0590 FF                  125 	.byte	-1
   0591 00                  126 	.byte	0
   0592 B0                  127 	.byte	-80
   0593 00                  128 	.byte	0
   0594 40                  129 	.byte	64
   0595 00                  130 	.byte	0
   0596 FF                  131 	.byte	-1
   0597 10                  132 	.byte	16
   0598 3C                  133 	.byte	60
   0599 FF                  134 	.byte	-1
   059A 00                  135 	.byte	0
   059B 28                  136 	.byte	40
   059C FF                  137 	.byte	-1
   059D F0                  138 	.byte	-16
   059E 3C                  139 	.byte	60
   059F FF                  140 	.byte	-1
   05A0 70                  141 	.byte	112
   05A1 C0                  142 	.byte	-64
   05A2 FF                  143 	.byte	-1
   05A3 00                  144 	.byte	0
   05A4 E0                  145 	.byte	-32
   05A5 00                  146 	.byte	0
   05A6 E4                  147 	.byte	-28
   05A7 30                  148 	.byte	48
   05A8 FF                  149 	.byte	-1
   05A9 00                  150 	.byte	0
   05AA 30                  151 	.byte	48
   05AB FF                  152 	.byte	-1
   05AC 10                  153 	.byte	16
   05AD F8                  154 	.byte	-8
   05AE FF                  155 	.byte	-1
   05AF 00                  156 	.byte	0
   05B0 D0                  157 	.byte	-48
   05B1 00                  158 	.byte	0
   05B2 00                  159 	.byte	0
   05B3 D0                  160 	.byte	-48
   05B4 FF                  161 	.byte	-1
   05B5 00                  162 	.byte	0
   05B6 D0                  163 	.byte	-48
   05B7 FF                  164 	.byte	-1
   05B8 F0                  165 	.byte	-16
   05B9 F8                  166 	.byte	-8
   05BA FF                  167 	.byte	-1
   05BB 00                  168 	.byte	0
   05BC 30                  169 	.byte	48
   05BD 00                  170 	.byte	0
   05BE 1C                  171 	.byte	28
   05BF 10                  172 	.byte	16
   05C0 FF                  173 	.byte	-1
   05C1 90                  174 	.byte	-112
   05C2 C0                  175 	.byte	-64
   05C3 00                  176 	.byte	0
   05C4 20                  177 	.byte	32
   05C5 D8                  178 	.byte	-40
   05C6 FF                  179 	.byte	-1
   05C7 28                  180 	.byte	40
   05C8 00                  181 	.byte	0
   05C9 FF                  182 	.byte	-1
   05CA 00                  183 	.byte	0
   05CB 3C                  184 	.byte	60
   05CC FF                  185 	.byte	-1
   05CD DC                  186 	.byte	-36
   05CE 00                  187 	.byte	0
   05CF 00                  188 	.byte	0
   05D0 00                  189 	.byte	0
   05D1 78                  190 	.byte	120
   05D2 FF                  191 	.byte	-1
   05D3 24                  192 	.byte	36
   05D4 00                  193 	.byte	0
   05D5 FF                  194 	.byte	-1
   05D6 00                  195 	.byte	0
   05D7 3C                  196 	.byte	60
   05D8 FF                  197 	.byte	-1
   05D9 D8                  198 	.byte	-40
   05DA 00                  199 	.byte	0
   05DB 00                  200 	.byte	0
   05DC 14                  201 	.byte	20
   05DD 9C                  202 	.byte	-100
   05DE FF                  203 	.byte	-1
   05DF 10                  204 	.byte	16
   05E0 F8                  205 	.byte	-8
   05E1 FF                  206 	.byte	-1
   05E2 00                  207 	.byte	0
   05E3 E8                  208 	.byte	-24
   05E4 FF                  209 	.byte	-1
   05E5 F0                  210 	.byte	-16
   05E6 F8                  211 	.byte	-8
   05E7                     212 _vl_term_0_76:
   05E7 01                  213 	.byte	1
                            214 	.globl	_vl_player_left
   05E8                     215 _vl_player_left:
   05E8 00                  216 	.byte	0
   05E9 0C                  217 	.byte	12
   05EA 78                  218 	.byte	120
   05EB FF                  219 	.byte	-1
   05EC 88                  220 	.byte	-120
   05ED 00                  221 	.byte	0
   05EE FF                  222 	.byte	-1
   05EF DC                  223 	.byte	-36
   05F0 18                  224 	.byte	24
   05F1 FF                  225 	.byte	-1
   05F2 00                  226 	.byte	0
   05F3 78                  227 	.byte	120
   05F4 FF                  228 	.byte	-1
   05F5 24                  229 	.byte	36
   05F6 18                  230 	.byte	24
   05F7 FF                  231 	.byte	-1
   05F8 78                  232 	.byte	120
   05F9 00                  233 	.byte	0
   05FA FF                  234 	.byte	-1
   05FB 24                  235 	.byte	36
   05FC E8                  236 	.byte	-24
   05FD FF                  237 	.byte	-1
   05FE 00                  238 	.byte	0
   05FF 88                  239 	.byte	-120
   0600 FF                  240 	.byte	-1
   0601 DC                  241 	.byte	-36
   0602 E8                  242 	.byte	-24
   0603 00                  243 	.byte	0
   0604 F4                  244 	.byte	-12
   0605 00                  245 	.byte	0
   0606 FF                  246 	.byte	-1
   0607 18                  247 	.byte	24
   0608 A6                  248 	.byte	-90
   0609 FF                  249 	.byte	-1
   060A 00                  250 	.byte	0
   060B C4                  251 	.byte	-60
   060C FF                  252 	.byte	-1
   060D E8                  253 	.byte	-24
   060E A6                  254 	.byte	-90
   060F 00                  255 	.byte	0
   0610 0C                  256 	.byte	12
   0611 00                  257 	.byte	0
   0612 FF                  258 	.byte	-1
   0613 88                  259 	.byte	-120
   0614 00                  260 	.byte	0
   0615 FF                  261 	.byte	-1
   0616 DC                  262 	.byte	-36
   0617 18                  263 	.byte	24
   0618 FF                  264 	.byte	-1
   0619 24                  265 	.byte	36
   061A 18                  266 	.byte	24
   061B FF                  267 	.byte	-1
   061C 0C                  268 	.byte	12
   061D 00                  269 	.byte	0
   061E 00                  270 	.byte	0
   061F E8                  271 	.byte	-24
   0620 DC                  272 	.byte	-36
   0621 FF                  273 	.byte	-1
   0622 18                  274 	.byte	24
   0623 4E                  275 	.byte	78
   0624 00                  276 	.byte	0
   0625 00                  277 	.byte	0
   0626 A6                  278 	.byte	-90
   0627 FF                  279 	.byte	-1
   0628 00                  280 	.byte	0
   0629 78                  281 	.byte	120
   062A FF                  282 	.byte	-1
   062B 00                  283 	.byte	0
   062C 78                  284 	.byte	120
   062D 00                  285 	.byte	0
   062E 00                  286 	.byte	0
   062F A6                  287 	.byte	-90
   0630 FF                  288 	.byte	-1
   0631 E8                  289 	.byte	-24
   0632 60                  290 	.byte	96
   0633 00                  291 	.byte	0
   0634 F4                  292 	.byte	-12
   0635 45                  293 	.byte	69
   0636 00                  294 	.byte	0
   0637 F4                  295 	.byte	-12
   0638 45                  296 	.byte	69
   0639 FF                  297 	.byte	-1
   063A 24                  298 	.byte	36
   063B E8                  299 	.byte	-24
   063C FF                  300 	.byte	-1
   063D 78                  301 	.byte	120
   063E 00                  302 	.byte	0
   063F FF                  303 	.byte	-1
   0640 24                  304 	.byte	36
   0641 18                  305 	.byte	24
   0642 00                  306 	.byte	0
   0643 D0                  307 	.byte	-48
   0644 18                  308 	.byte	24
   0645 FF                  309 	.byte	-1
   0646 00                  310 	.byte	0
   0647 1E                  311 	.byte	30
   0648 FF                  312 	.byte	-1
   0649 18                  313 	.byte	24
   064A 0C                  314 	.byte	12
   064B FF                  315 	.byte	-1
   064C 54                  316 	.byte	84
   064D 00                  317 	.byte	0
   064E FF                  318 	.byte	-1
   064F 18                  319 	.byte	24
   0650 F4                  320 	.byte	-12
   0651 FF                  321 	.byte	-1
   0652 E8                  322 	.byte	-24
   0653 F4                  323 	.byte	-12
   0654 FF                  324 	.byte	-1
   0655 AC                  325 	.byte	-84
   0656 00                  326 	.byte	0
   0657 FF                  327 	.byte	-1
   0658 E8                  328 	.byte	-24
   0659 0C                  329 	.byte	12
   065A 00                  330 	.byte	0
   065B 45                  331 	.byte	69
   065C 00                  332 	.byte	0
   065D 00                  333 	.byte	0
   065E 45                  334 	.byte	69
   065F 00                  335 	.byte	0
   0660 FF                  336 	.byte	-1
   0661 00                  337 	.byte	0
   0662 94                  338 	.byte	-108
   0663 FF                  339 	.byte	-1
   0664 E8                  340 	.byte	-24
   0665 F4                  341 	.byte	-12
   0666 FF                  342 	.byte	-1
   0667 C4                  343 	.byte	-60
   0668 00                  344 	.byte	0
   0669 00                  345 	.byte	0
   066A 00                  346 	.byte	0
   066B E2                  347 	.byte	-30
   066C FF                  348 	.byte	-1
   066D 2A                  349 	.byte	42
   066E 1E                  350 	.byte	30
   066F 00                  351 	.byte	0
   0670 2A                  352 	.byte	42
   0671 18                  353 	.byte	24
   0672 FF                  354 	.byte	-1
   0673 3C                  355 	.byte	60
   0674 2A                  356 	.byte	42
   0675 00                  357 	.byte	0
   0676 F4                  358 	.byte	-12
   0677 F4                  359 	.byte	-12
   0678 FF                  360 	.byte	-1
   0679 00                  361 	.byte	0
   067A 30                  362 	.byte	48
   067B FF                  363 	.byte	-1
   067C E8                  364 	.byte	-24
   067D F4                  365 	.byte	-12
   067E FF                  366 	.byte	-1
   067F 00                  367 	.byte	0
   0680 D0                  368 	.byte	-48
   0681 00                  369 	.byte	0
   0682 24                  370 	.byte	36
   0683 18                  371 	.byte	24
   0684 FF                  372 	.byte	-1
   0685 00                  373 	.byte	0
   0686 C4                  374 	.byte	-60
   0687 00                  375 	.byte	0
   0688 F4                  376 	.byte	-12
   0689 EE                  377 	.byte	-18
   068A FF                  378 	.byte	-1
   068B 00                  379 	.byte	0
   068C D0                  380 	.byte	-48
   068D FF                  381 	.byte	-1
   068E E8                  382 	.byte	-24
   068F DC                  383 	.byte	-36
   0690 FF                  384 	.byte	-1
   0691 00                  385 	.byte	0
   0692 2A                  386 	.byte	42
   0693 00                  387 	.byte	0
   0694 24                  388 	.byte	36
   0695 3C                  389 	.byte	60
   0696 FF                  390 	.byte	-1
   0697 C0                  391 	.byte	-64
   0698 94                  392 	.byte	-108
   0699 FF                  393 	.byte	-1
   069A C0                  394 	.byte	-64
   069B 94                  395 	.byte	-108
   069C FF                  396 	.byte	-1
   069D C0                  397 	.byte	-64
   069E 94                  398 	.byte	-108
   069F 00                  399 	.byte	0
   06A0 0C                  400 	.byte	12
   06A1 00                  401 	.byte	0
   06A2 FF                  402 	.byte	-1
   06A3 24                  403 	.byte	36
   06A4 18                  404 	.byte	24
   06A5 FF                  405 	.byte	-1
   06A6 E8                  406 	.byte	-24
   06A7 12                  407 	.byte	18
   06A8 00                  408 	.byte	0
   06A9 AC                  409 	.byte	-84
   06AA F7                  410 	.byte	-9
   06AB 00                  411 	.byte	0
   06AC AC                  412 	.byte	-84
   06AD F7                  413 	.byte	-9
   06AE FF                  414 	.byte	-1
   06AF 00                  415 	.byte	0
   06B0 88                  416 	.byte	-120
   06B1 FF                  417 	.byte	-1
   06B2 24                  418 	.byte	36
   06B3 E8                  419 	.byte	-24
   06B4 FF                  420 	.byte	-1
   06B5 78                  421 	.byte	120
   06B6 00                  422 	.byte	0
   06B7 FF                  423 	.byte	-1
   06B8 24                  424 	.byte	36
   06B9 18                  425 	.byte	24
   06BA FF                  426 	.byte	-1
   06BB 00                  427 	.byte	0
   06BC 78                  428 	.byte	120
   06BD 00                  429 	.byte	0
   06BE FA                  430 	.byte	-6
   06BF 2A                  431 	.byte	42
   06C0 FF                  432 	.byte	-1
   06C1 48                  433 	.byte	72
   06C2 00                  434 	.byte	0
   06C3 FF                  435 	.byte	-1
   06C4 18                  436 	.byte	24
   06C5 0C                  437 	.byte	12
   06C6 FF                  438 	.byte	-1
   06C7 00                  439 	.byte	0
   06C8 6C                  440 	.byte	108
   06C9 FF                  441 	.byte	-1
   06CA E8                  442 	.byte	-24
   06CB F4                  443 	.byte	-12
   06CC FF                  444 	.byte	-1
   06CD F4                  445 	.byte	-12
   06CE 00                  446 	.byte	0
   06CF 00                  447 	.byte	0
   06D0 24                  448 	.byte	36
   06D1 0C                  449 	.byte	12
   06D2 FF                  450 	.byte	-1
   06D3 EE                  451 	.byte	-18
   06D4 0C                  452 	.byte	12
   06D5 00                  453 	.byte	0
   06D6 CA                  454 	.byte	-54
   06D7 E2                  455 	.byte	-30
   06D8 FF                  456 	.byte	-1
   06D9 24                  457 	.byte	36
   06DA 42                  458 	.byte	66
   06DB FF                  459 	.byte	-1
   06DC 00                  460 	.byte	0
   06DD 2A                  461 	.byte	42
   06DE FF                  462 	.byte	-1
   06DF DC                  463 	.byte	-36
   06E0 E8                  464 	.byte	-24
   06E1                     465 _vl_term_1_189:
   06E1 01                  466 	.byte	1
                            467 	.globl	_vl_player_right
   06E2                     468 _vl_player_right:
   06E2 00                  469 	.byte	0
   06E3 0C                  470 	.byte	12
   06E4 88                  471 	.byte	-120
   06E5 FF                  472 	.byte	-1
   06E6 88                  473 	.byte	-120
   06E7 00                  474 	.byte	0
   06E8 FF                  475 	.byte	-1
   06E9 DC                  476 	.byte	-36
   06EA E8                  477 	.byte	-24
   06EB FF                  478 	.byte	-1
   06EC 00                  479 	.byte	0
   06ED 88                  480 	.byte	-120
   06EE FF                  481 	.byte	-1
   06EF 24                  482 	.byte	36
   06F0 E8                  483 	.byte	-24
   06F1 FF                  484 	.byte	-1
   06F2 78                  485 	.byte	120
   06F3 00                  486 	.byte	0
   06F4 FF                  487 	.byte	-1
   06F5 24                  488 	.byte	36
   06F6 18                  489 	.byte	24
   06F7 FF                  490 	.byte	-1
   06F8 00                  491 	.byte	0
   06F9 78                  492 	.byte	120
   06FA FF                  493 	.byte	-1
   06FB DC                  494 	.byte	-36
   06FC 18                  495 	.byte	24
   06FD 00                  496 	.byte	0
   06FE F4                  497 	.byte	-12
   06FF 00                  498 	.byte	0
   0700 FF                  499 	.byte	-1
   0701 18                  500 	.byte	24
   0702 5A                  501 	.byte	90
   0703 FF                  502 	.byte	-1
   0704 00                  503 	.byte	0
   0705 3C                  504 	.byte	60
   0706 FF                  505 	.byte	-1
   0707 E8                  506 	.byte	-24
   0708 5A                  507 	.byte	90
   0709 00                  508 	.byte	0
   070A 0C                  509 	.byte	12
   070B 00                  510 	.byte	0
   070C FF                  511 	.byte	-1
   070D 88                  512 	.byte	-120
   070E 00                  513 	.byte	0
   070F FF                  514 	.byte	-1
   0710 DC                  515 	.byte	-36
   0711 E8                  516 	.byte	-24
   0712 FF                  517 	.byte	-1
   0713 24                  518 	.byte	36
   0714 E8                  519 	.byte	-24
   0715 FF                  520 	.byte	-1
   0716 0C                  521 	.byte	12
   0717 00                  522 	.byte	0
   0718 00                  523 	.byte	0
   0719 E8                  524 	.byte	-24
   071A 24                  525 	.byte	36
   071B FF                  526 	.byte	-1
   071C 18                  527 	.byte	24
   071D B2                  528 	.byte	-78
   071E 00                  529 	.byte	0
   071F 00                  530 	.byte	0
   0720 5A                  531 	.byte	90
   0721 FF                  532 	.byte	-1
   0722 00                  533 	.byte	0
   0723 88                  534 	.byte	-120
   0724 FF                  535 	.byte	-1
   0725 00                  536 	.byte	0
   0726 88                  537 	.byte	-120
   0727 00                  538 	.byte	0
   0728 00                  539 	.byte	0
   0729 5A                  540 	.byte	90
   072A FF                  541 	.byte	-1
   072B E8                  542 	.byte	-24
   072C A0                  543 	.byte	-96
   072D 00                  544 	.byte	0
   072E F4                  545 	.byte	-12
   072F BB                  546 	.byte	-69
   0730 00                  547 	.byte	0
   0731 F4                  548 	.byte	-12
   0732 BB                  549 	.byte	-69
   0733 FF                  550 	.byte	-1
   0734 24                  551 	.byte	36
   0735 18                  552 	.byte	24
   0736 FF                  553 	.byte	-1
   0737 78                  554 	.byte	120
   0738 00                  555 	.byte	0
   0739 FF                  556 	.byte	-1
   073A 24                  557 	.byte	36
   073B E8                  558 	.byte	-24
   073C 00                  559 	.byte	0
   073D D0                  560 	.byte	-48
   073E E8                  561 	.byte	-24
   073F FF                  562 	.byte	-1
   0740 00                  563 	.byte	0
   0741 E2                  564 	.byte	-30
   0742 FF                  565 	.byte	-1
   0743 18                  566 	.byte	24
   0744 F4                  567 	.byte	-12
   0745 FF                  568 	.byte	-1
   0746 54                  569 	.byte	84
   0747 00                  570 	.byte	0
   0748 FF                  571 	.byte	-1
   0749 18                  572 	.byte	24
   074A 0C                  573 	.byte	12
   074B FF                  574 	.byte	-1
   074C E8                  575 	.byte	-24
   074D 0C                  576 	.byte	12
   074E FF                  577 	.byte	-1
   074F AC                  578 	.byte	-84
   0750 00                  579 	.byte	0
   0751 FF                  580 	.byte	-1
   0752 E8                  581 	.byte	-24
   0753 F4                  582 	.byte	-12
   0754 00                  583 	.byte	0
   0755 45                  584 	.byte	69
   0756 00                  585 	.byte	0
   0757 00                  586 	.byte	0
   0758 45                  587 	.byte	69
   0759 00                  588 	.byte	0
   075A FF                  589 	.byte	-1
   075B 00                  590 	.byte	0
   075C 6C                  591 	.byte	108
   075D FF                  592 	.byte	-1
   075E E8                  593 	.byte	-24
   075F 0C                  594 	.byte	12
   0760 FF                  595 	.byte	-1
   0761 C4                  596 	.byte	-60
   0762 00                  597 	.byte	0
   0763 00                  598 	.byte	0
   0764 00                  599 	.byte	0
   0765 1E                  600 	.byte	30
   0766 FF                  601 	.byte	-1
   0767 2A                  602 	.byte	42
   0768 E2                  603 	.byte	-30
   0769 00                  604 	.byte	0
   076A 2A                  605 	.byte	42
   076B E8                  606 	.byte	-24
   076C FF                  607 	.byte	-1
   076D 3C                  608 	.byte	60
   076E D6                  609 	.byte	-42
   076F 00                  610 	.byte	0
   0770 F4                  611 	.byte	-12
   0771 0C                  612 	.byte	12
   0772 FF                  613 	.byte	-1
   0773 00                  614 	.byte	0
   0774 D0                  615 	.byte	-48
   0775 FF                  616 	.byte	-1
   0776 E8                  617 	.byte	-24
   0777 0C                  618 	.byte	12
   0778 FF                  619 	.byte	-1
   0779 00                  620 	.byte	0
   077A 30                  621 	.byte	48
   077B 00                  622 	.byte	0
   077C 24                  623 	.byte	36
   077D E8                  624 	.byte	-24
   077E FF                  625 	.byte	-1
   077F 00                  626 	.byte	0
   0780 3C                  627 	.byte	60
   0781 00                  628 	.byte	0
   0782 F4                  629 	.byte	-12
   0783 12                  630 	.byte	18
   0784 FF                  631 	.byte	-1
   0785 00                  632 	.byte	0
   0786 30                  633 	.byte	48
   0787 FF                  634 	.byte	-1
   0788 E8                  635 	.byte	-24
   0789 24                  636 	.byte	36
   078A FF                  637 	.byte	-1
   078B 00                  638 	.byte	0
   078C D6                  639 	.byte	-42
   078D 00                  640 	.byte	0
   078E 24                  641 	.byte	36
   078F C4                  642 	.byte	-60
   0790 FF                  643 	.byte	-1
   0791 C0                  644 	.byte	-64
   0792 6C                  645 	.byte	108
   0793 FF                  646 	.byte	-1
   0794 C0                  647 	.byte	-64
   0795 6C                  648 	.byte	108
   0796 FF                  649 	.byte	-1
   0797 C0                  650 	.byte	-64
   0798 6C                  651 	.byte	108
   0799 00                  652 	.byte	0
   079A 0C                  653 	.byte	12
   079B 00                  654 	.byte	0
   079C FF                  655 	.byte	-1
   079D 24                  656 	.byte	36
   079E E8                  657 	.byte	-24
   079F FF                  658 	.byte	-1
   07A0 E8                  659 	.byte	-24
   07A1 EE                  660 	.byte	-18
   07A2 00                  661 	.byte	0
   07A3 AC                  662 	.byte	-84
   07A4 09                  663 	.byte	9
   07A5 00                  664 	.byte	0
   07A6 AC                  665 	.byte	-84
   07A7 09                  666 	.byte	9
   07A8 FF                  667 	.byte	-1
   07A9 00                  668 	.byte	0
   07AA 78                  669 	.byte	120
   07AB FF                  670 	.byte	-1
   07AC 24                  671 	.byte	36
   07AD 18                  672 	.byte	24
   07AE FF                  673 	.byte	-1
   07AF 78                  674 	.byte	120
   07B0 00                  675 	.byte	0
   07B1 FF                  676 	.byte	-1
   07B2 24                  677 	.byte	36
   07B3 E8                  678 	.byte	-24
   07B4 FF                  679 	.byte	-1
   07B5 00                  680 	.byte	0
   07B6 88                  681 	.byte	-120
   07B7 00                  682 	.byte	0
   07B8 FA                  683 	.byte	-6
   07B9 D6                  684 	.byte	-42
   07BA FF                  685 	.byte	-1
   07BB 48                  686 	.byte	72
   07BC 00                  687 	.byte	0
   07BD FF                  688 	.byte	-1
   07BE 18                  689 	.byte	24
   07BF F4                  690 	.byte	-12
   07C0 FF                  691 	.byte	-1
   07C1 00                  692 	.byte	0
   07C2 94                  693 	.byte	-108
   07C3 FF                  694 	.byte	-1
   07C4 E8                  695 	.byte	-24
   07C5 0C                  696 	.byte	12
   07C6 FF                  697 	.byte	-1
   07C7 F4                  698 	.byte	-12
   07C8 00                  699 	.byte	0
   07C9 00                  700 	.byte	0
   07CA 24                  701 	.byte	36
   07CB F4                  702 	.byte	-12
   07CC FF                  703 	.byte	-1
   07CD EE                  704 	.byte	-18
   07CE F4                  705 	.byte	-12
   07CF 00                  706 	.byte	0
   07D0 CA                  707 	.byte	-54
   07D1 1E                  708 	.byte	30
   07D2 FF                  709 	.byte	-1
   07D3 24                  710 	.byte	36
   07D4 BE                  711 	.byte	-66
   07D5 FF                  712 	.byte	-1
   07D6 00                  713 	.byte	0
   07D7 D6                  714 	.byte	-42
   07D8 FF                  715 	.byte	-1
   07D9 DC                  716 	.byte	-36
   07DA 18                  717 	.byte	24
   07DB                     718 _vl_term_2_302:
   07DB 01                  719 	.byte	1
                            720 	.globl	__player_draw_left
   07DC                     721 __player_draw_left:
   07DC C6 0A         [ 2]  722 	ldb	#10
   07DE D7 04         [ 4]  723 	stb	*_dp_VIA_t1_cnt_lo
   07E0 8E 05 E8      [ 3]  724 	ldx	#_vl_player_left
   07E3 7E F4 10      [ 4]  725 	jmp	___Draw_VLp
                            726 	.globl	__player_draw_mid
   07E6                     727 __player_draw_mid:
   07E6 C6 10         [ 2]  728 	ldb	#16
   07E8 D7 04         [ 4]  729 	stb	*_dp_VIA_t1_cnt_lo
   07EA 8E 05 60      [ 3]  730 	ldx	#_vl_player_mid
   07ED 7E F4 10      [ 4]  731 	jmp	___Draw_VLp
                            732 	.globl	__player_draw_right
   07F0                     733 __player_draw_right:
   07F0 C6 0A         [ 2]  734 	ldb	#10
   07F2 D7 04         [ 4]  735 	stb	*_dp_VIA_t1_cnt_lo
   07F4 8E 06 E2      [ 3]  736 	ldx	#_vl_player_right
   07F7 7E F4 10      [ 4]  737 	jmp	___Draw_VLp
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Thu Jun 12 22:57:40 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                0063 R   |   3 L6                 004F R
  3 _PLAYER_DRAW_L     0003 GR  |   3 _PLAYER_X_LUT      0000 GR
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
  3 __player_draw_     02E9 GR  |   3 __player_draw_     02F3 GR
  3 __player_draw_     02FD GR  |   3 _check_collisi     006C GR
    _dp_VIA_t1_cnt     **** GX  |   3 _player_change     0046 GR
  3 _player_change     0058 GR  |   3 _player_draw       0018 GR
  3 _player_init       0009 GR  |   2 _the_player        0000 GR
  3 _vl_player_lef     00F5 GR  |   3 _vl_player_mid     006D GR
  3 _vl_player_rig     01EF GR  |   3 _vl_term_0_76      00F4 R
  3 _vl_term_1_189     01EE R   |   3 _vl_term_2_302     02E8 R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Thu Jun 12 22:57:40 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    4   flags    0
   3 .text            size  307   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

