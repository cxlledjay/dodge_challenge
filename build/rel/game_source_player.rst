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
   074E                      11 _PLAYER_X_LUT:
   074E AE                   12 	.byte	-82
   074F 00                   13 	.byte	0
   0750 52                   14 	.byte	82
                             15 	.globl	_PLAYER_DRAW_LUT
   0751                      16 _PLAYER_DRAW_LUT:
   0751 0A 52                17 	.word	__player_draw_left
   0753 0A 0C                18 	.word	__player_draw_mid
   0755 0A BA                19 	.word	__player_draw_right
                             20 	.globl	_player_init
   0757                      21 _player_init:
   0757 8E 07 66      [ 3]   22 	ldx	#_player_draw
   075A BF C8 AC      [ 6]   23 	stx	_the_player+2
   075D 7F C8 AB      [ 7]   24 	clr	_the_player+1
   0760 C6 01         [ 2]   25 	ldb	#1
   0762 F7 C8 AA      [ 5]   26 	stb	_the_player
   0765 39            [ 5]   27 	rts
                             28 	.globl	_player_draw
   0766                      29 _player_draw:
   0766 32 7E         [ 5]   30 	leas	-2,s
   0768 BD F2 A5      [ 8]   31 	jsr	___Intensity_5F
   076B F6 C8 AA      [ 5]   32 	ldb	_the_player
   076E 4F            [ 2]   33 	clra		;zero_extendqihi: R:b -> R:d
   076F ED E4         [ 5]   34 	std	,s
   0771 58            [ 2]   35 	aslb
   0772 49            [ 2]   36 	rola
   0773 1F 01         [ 6]   37 	tfr	d,x
   0775 AD 99 07 51   [14]   38 	jsr	[_PLAYER_DRAW_LUT,x]
   0779 32 62         [ 5]   39 	leas	2,s
   077B 39            [ 5]   40 	rts
                             41 	.globl	_player_change_left
   077C                      42 _player_change_left:
   077C F6 C8 AA      [ 5]   43 	ldb	_the_player
   077F 27 04         [ 3]   44 	beq	L6
   0781 5A            [ 2]   45 	decb
   0782 F7 C8 AA      [ 5]   46 	stb	_the_player
   0785                      47 L6:
   0785 8E 07 66      [ 3]   48 	ldx	#_player_draw
   0788 BF C8 AC      [ 6]   49 	stx	_the_player+2
   078B 7E 07 66      [ 4]   50 	jmp	_player_draw
                             51 	.globl	_player_change_right
   078E                      52 _player_change_right:
   078E F6 C8 AA      [ 5]   53 	ldb	_the_player
   0791 C1 02         [ 2]   54 	cmpb	#2	;cmpqi:
   0793 27 04         [ 3]   55 	beq	L10
   0795 5C            [ 2]   56 	incb
   0796 F7 C8 AA      [ 5]   57 	stb	_the_player
   0799                      58 L10:
   0799 8E 07 66      [ 3]   59 	ldx	#_player_draw
   079C BF C8 AC      [ 6]   60 	stx	_the_player+2
   079F 7E 07 66      [ 4]   61 	jmp	_player_draw
                             62 	.globl	_check_collision
   07A2                      63 _check_collision:
   07A2 39            [ 5]   64 	rts
                             65 	.globl	_vl_player_mid1
   07A3                      66 _vl_player_mid1:
   07A3 00                   67 	.byte	0
   07A4 A0                   68 	.byte	-96
   07A5 B0                   69 	.byte	-80
   07A6 FF                   70 	.byte	-1
   07A7 00                   71 	.byte	0
   07A8 B0                   72 	.byte	-80
   07A9 FF                   73 	.byte	-1
   07AA 7F                   74 	.byte	127
   07AB 00                   75 	.byte	0
   07AC FF                   76 	.byte	-1
   07AD 00                   77 	.byte	0
   07AE 50                   78 	.byte	80
   07AF FF                   79 	.byte	-1
   07B0 80                   80 	.byte	-128
   07B1 00                   81 	.byte	0
   07B2 00                   82 	.byte	0
   07B3 10                   83 	.byte	16
   07B4 00                   84 	.byte	0
   07B5 FF                   85 	.byte	-1
   07B6 10                   86 	.byte	16
   07B7 3C                   87 	.byte	60
   07B8 00                   88 	.byte	0
   07B9 00                   89 	.byte	0
   07BA 28                   90 	.byte	40
   07BB FF                   91 	.byte	-1
   07BC F0                   92 	.byte	-16
   07BD 3C                   93 	.byte	60
   07BE 00                   94 	.byte	0
   07BF F0                   95 	.byte	-16
   07C0 00                   96 	.byte	0
   07C1 FF                   97 	.byte	-1
   07C2 00                   98 	.byte	0
   07C3 50                   99 	.byte	80
   07C4 FF                  100 	.byte	-1
   07C5 7F                  101 	.byte	127
   07C6 00                  102 	.byte	0
   07C7 FF                  103 	.byte	-1
   07C8 00                  104 	.byte	0
   07C9 B0                  105 	.byte	-80
   07CA FF                  106 	.byte	-1
   07CB 80                  107 	.byte	-128
   07CC 00                  108 	.byte	0
   07CD 00                  109 	.byte	0
   07CE 20                  110 	.byte	32
   07CF 00                  111 	.byte	0
   07D0 FF                  112 	.byte	-1
   07D1 00                  113 	.byte	0
   07D2 B0                  114 	.byte	-80
   07D3 FF                  115 	.byte	-1
   07D4 00                  116 	.byte	0
   07D5 B0                  117 	.byte	-80
   07D6 00                  118 	.byte	0
   07D7 40                  119 	.byte	64
   07D8 00                  120 	.byte	0
   07D9 FF                  121 	.byte	-1
   07DA 10                  122 	.byte	16
   07DB 3C                  123 	.byte	60
   07DC FF                  124 	.byte	-1
   07DD 00                  125 	.byte	0
   07DE 28                  126 	.byte	40
   07DF FF                  127 	.byte	-1
   07E0 F0                  128 	.byte	-16
   07E1 3C                  129 	.byte	60
   07E2                     130 _vl_term_0_46:
   07E2 01                  131 	.byte	1
                            132 	.globl	_vl_player_mid2
   07E3                     133 _vl_player_mid2:
   07E3 00                  134 	.byte	0
   07E4 20                  135 	.byte	32
   07E5 88                  136 	.byte	-120
   07E6 FF                  137 	.byte	-1
   07E7 28                  138 	.byte	40
   07E8 00                  139 	.byte	0
   07E9 FF                  140 	.byte	-1
   07EA 00                  141 	.byte	0
   07EB 3C                  142 	.byte	60
   07EC FF                  143 	.byte	-1
   07ED DC                  144 	.byte	-36
   07EE 00                  145 	.byte	0
   07EF 00                  146 	.byte	0
   07F0 E0                  147 	.byte	-32
   07F1 EC                  148 	.byte	-20
   07F2 FF                  149 	.byte	-1
   07F3 70                  150 	.byte	112
   07F4 40                  151 	.byte	64
   07F5 FF                  152 	.byte	-1
   07F6 00                  153 	.byte	0
   07F7 20                  154 	.byte	32
   07F8 FF                  155 	.byte	-1
   07F9 90                  156 	.byte	-112
   07FA 40                  157 	.byte	64
   07FB 00                  158 	.byte	0
   07FC 20                  159 	.byte	32
   07FD 28                  160 	.byte	40
   07FE FF                  161 	.byte	-1
   07FF 28                  162 	.byte	40
   0800 00                  163 	.byte	0
   0801 FF                  164 	.byte	-1
   0802 00                  165 	.byte	0
   0803 C4                  166 	.byte	-60
   0804 FF                  167 	.byte	-1
   0805 DC                  168 	.byte	-36
   0806 00                  169 	.byte	0
   0807 00                  170 	.byte	0
   0808 2D                  171 	.byte	45
   0809 E4                  172 	.byte	-28
   080A FF                  173 	.byte	-1
   080B 00                  174 	.byte	0
   080C 30                  175 	.byte	48
   080D FF                  176 	.byte	-1
   080E 10                  177 	.byte	16
   080F F8                  178 	.byte	-8
   0810 FF                  179 	.byte	-1
   0811 00                  180 	.byte	0
   0812 D0                  181 	.byte	-48
   0813 00                  182 	.byte	0
   0814 00                  183 	.byte	0
   0815 D0                  184 	.byte	-48
   0816 FF                  185 	.byte	-1
   0817 00                  186 	.byte	0
   0818 D0                  187 	.byte	-48
   0819 FF                  188 	.byte	-1
   081A F0                  189 	.byte	-16
   081B F8                  190 	.byte	-8
   081C FF                  191 	.byte	-1
   081D 00                  192 	.byte	0
   081E 30                  193 	.byte	48
   081F 00                  194 	.byte	0
   0820 E4                  195 	.byte	-28
   0821 0C                  196 	.byte	12
   0822 FF                  197 	.byte	-1
   0823 10                  198 	.byte	16
   0824 08                  199 	.byte	8
   0825 FF                  200 	.byte	-1
   0826 00                  201 	.byte	0
   0827 18                  202 	.byte	24
   0828 FF                  203 	.byte	-1
   0829 F0                  204 	.byte	-16
   082A 08                  205 	.byte	8
   082B                     206 _vl_term_1_83:
   082B 01                  207 	.byte	1
                            208 	.globl	_vl_player_left1
   082C                     209 _vl_player_left1:
   082C 00                  210 	.byte	0
   082D 08                  211 	.byte	8
   082E 50                  212 	.byte	80
   082F FF                  213 	.byte	-1
   0830 B0                  214 	.byte	-80
   0831 00                  215 	.byte	0
   0832 FF                  216 	.byte	-1
   0833 E8                  217 	.byte	-24
   0834 10                  218 	.byte	16
   0835 FF                  219 	.byte	-1
   0836 00                  220 	.byte	0
   0837 50                  221 	.byte	80
   0838 FF                  222 	.byte	-1
   0839 18                  223 	.byte	24
   083A 10                  224 	.byte	16
   083B FF                  225 	.byte	-1
   083C 50                  226 	.byte	80
   083D 00                  227 	.byte	0
   083E FF                  228 	.byte	-1
   083F 18                  229 	.byte	24
   0840 F0                  230 	.byte	-16
   0841 FF                  231 	.byte	-1
   0842 00                  232 	.byte	0
   0843 B0                  233 	.byte	-80
   0844 FF                  234 	.byte	-1
   0845 E8                  235 	.byte	-24
   0846 F0                  236 	.byte	-16
   0847 00                  237 	.byte	0
   0848 F8                  238 	.byte	-8
   0849 00                  239 	.byte	0
   084A FF                  240 	.byte	-1
   084B 10                  241 	.byte	16
   084C C4                  242 	.byte	-60
   084D FF                  243 	.byte	-1
   084E 00                  244 	.byte	0
   084F D8                  245 	.byte	-40
   0850 FF                  246 	.byte	-1
   0851 F0                  247 	.byte	-16
   0852 C4                  248 	.byte	-60
   0853 00                  249 	.byte	0
   0854 08                  250 	.byte	8
   0855 00                  251 	.byte	0
   0856 FF                  252 	.byte	-1
   0857 B0                  253 	.byte	-80
   0858 00                  254 	.byte	0
   0859 FF                  255 	.byte	-1
   085A E8                  256 	.byte	-24
   085B 10                  257 	.byte	16
   085C FF                  258 	.byte	-1
   085D 18                  259 	.byte	24
   085E 10                  260 	.byte	16
   085F FF                  261 	.byte	-1
   0860 08                  262 	.byte	8
   0861 00                  263 	.byte	0
   0862 00                  264 	.byte	0
   0863 F0                  265 	.byte	-16
   0864 E8                  266 	.byte	-24
   0865 FF                  267 	.byte	-1
   0866 10                  268 	.byte	16
   0867 34                  269 	.byte	52
   0868 00                  270 	.byte	0
   0869 00                  271 	.byte	0
   086A C4                  272 	.byte	-60
   086B FF                  273 	.byte	-1
   086C 00                  274 	.byte	0
   086D 50                  275 	.byte	80
   086E FF                  276 	.byte	-1
   086F 00                  277 	.byte	0
   0870 50                  278 	.byte	80
   0871 00                  279 	.byte	0
   0872 00                  280 	.byte	0
   0873 C4                  281 	.byte	-60
   0874 FF                  282 	.byte	-1
   0875 F0                  283 	.byte	-16
   0876 40                  284 	.byte	64
   0877                     285 _vl_term_2_123:
   0877 01                  286 	.byte	1
                            287 	.globl	_vl_player_left2
   0878                     288 _vl_player_left2:
   0878 00                  289 	.byte	0
   0879 D0                  290 	.byte	-48
   087A 58                  291 	.byte	88
   087B 00                  292 	.byte	0
   087C D0                  293 	.byte	-48
   087D 58                  294 	.byte	88
   087E FF                  295 	.byte	-1
   087F 18                  296 	.byte	24
   0880 F0                  297 	.byte	-16
   0881 FF                  298 	.byte	-1
   0882 50                  299 	.byte	80
   0883 00                  300 	.byte	0
   0884 FF                  301 	.byte	-1
   0885 18                  302 	.byte	24
   0886 10                  303 	.byte	16
   0887 00                  304 	.byte	0
   0888 E0                  305 	.byte	-32
   0889 10                  306 	.byte	16
   088A FF                  307 	.byte	-1
   088B 00                  308 	.byte	0
   088C 14                  309 	.byte	20
   088D FF                  310 	.byte	-1
   088E 10                  311 	.byte	16
   088F 08                  312 	.byte	8
   0890 FF                  313 	.byte	-1
   0891 38                  314 	.byte	56
   0892 00                  315 	.byte	0
   0893 FF                  316 	.byte	-1
   0894 10                  317 	.byte	16
   0895 F8                  318 	.byte	-8
   0896 FF                  319 	.byte	-1
   0897 F0                  320 	.byte	-16
   0898 F8                  321 	.byte	-8
   0899 FF                  322 	.byte	-1
   089A C8                  323 	.byte	-56
   089B 00                  324 	.byte	0
   089C FF                  325 	.byte	-1
   089D F0                  326 	.byte	-16
   089E 08                  327 	.byte	8
   089F 00                  328 	.byte	0
   08A0 58                  329 	.byte	88
   08A1 00                  330 	.byte	0
   08A2 FF                  331 	.byte	-1
   08A3 00                  332 	.byte	0
   08A4 B8                  333 	.byte	-72
   08A5 FF                  334 	.byte	-1
   08A6 F0                  335 	.byte	-16
   08A7 F8                  336 	.byte	-8
   08A8 FF                  337 	.byte	-1
   08A9 D8                  338 	.byte	-40
   08AA 00                  339 	.byte	0
   08AB 00                  340 	.byte	0
   08AC 00                  341 	.byte	0
   08AD EC                  342 	.byte	-20
   08AE FF                  343 	.byte	-1
   08AF 1C                  344 	.byte	28
   08B0 14                  345 	.byte	20
   08B1 00                  346 	.byte	0
   08B2 1C                  347 	.byte	28
   08B3 10                  348 	.byte	16
   08B4 FF                  349 	.byte	-1
   08B5 28                  350 	.byte	40
   08B6 1C                  351 	.byte	28
   08B7 FF                  352 	.byte	-1
   08B8 00                  353 	.byte	0
   08B9 D8                  354 	.byte	-40
   08BA FF                  355 	.byte	-1
   08BB C0                  356 	.byte	-64
   08BC 94                  357 	.byte	-108
   08BD FF                  358 	.byte	-1
   08BE C0                  359 	.byte	-64
   08BF 94                  360 	.byte	-108
   08C0 00                  361 	.byte	0
   08C1 34                  362 	.byte	52
   08C2 58                  363 	.byte	88
   08C3 00                  364 	.byte	0
   08C4 34                  365 	.byte	52
   08C5 58                  366 	.byte	88
   08C6 FF                  367 	.byte	-1
   08C7 00                  368 	.byte	0
   08C8 E4                  369 	.byte	-28
   08C9 FF                  370 	.byte	-1
   08CA 10                  371 	.byte	16
   08CB 18                  372 	.byte	24
   08CC FF                  373 	.byte	-1
   08CD 00                  374 	.byte	0
   08CE 20                  375 	.byte	32
   08CF 00                  376 	.byte	0
   08D0 00                  377 	.byte	0
   08D1 2E                  378 	.byte	46
   08D2 FF                  379 	.byte	-1
   08D3 00                  380 	.byte	0
   08D4 20                  381 	.byte	32
   08D5 FF                  382 	.byte	-1
   08D6 F0                  383 	.byte	-16
   08D7 F8                  384 	.byte	-8
   08D8 FF                  385 	.byte	-1
   08D9 00                  386 	.byte	0
   08DA E0                  387 	.byte	-32
   08DB                     388 _vl_term_3_170:
   08DB 01                  389 	.byte	1
                            390 	.globl	_vl_player_left3
   08DC                     391 _vl_player_left3:
   08DC 00                  392 	.byte	0
   08DD 08                  393 	.byte	8
   08DE B0                  394 	.byte	-80
   08DF FF                  395 	.byte	-1
   08E0 18                  396 	.byte	24
   08E1 10                  397 	.byte	16
   08E2 FF                  398 	.byte	-1
   08E3 F0                  399 	.byte	-16
   08E4 0C                  400 	.byte	12
   08E5 00                  401 	.byte	0
   08E6 90                  402 	.byte	-112
   08E7 F4                  403 	.byte	-12
   08E8 FF                  404 	.byte	-1
   08E9 00                  405 	.byte	0
   08EA B0                  406 	.byte	-80
   08EB FF                  407 	.byte	-1
   08EC 18                  408 	.byte	24
   08ED F0                  409 	.byte	-16
   08EE FF                  410 	.byte	-1
   08EF 50                  411 	.byte	80
   08F0 00                  412 	.byte	0
   08F1 FF                  413 	.byte	-1
   08F2 18                  414 	.byte	24
   08F3 10                  415 	.byte	16
   08F4 FF                  416 	.byte	-1
   08F5 00                  417 	.byte	0
   08F6 50                  418 	.byte	80
   08F7 00                  419 	.byte	0
   08F8 FC                  420 	.byte	-4
   08F9 1C                  421 	.byte	28
   08FA FF                  422 	.byte	-1
   08FB 30                  423 	.byte	48
   08FC 00                  424 	.byte	0
   08FD FF                  425 	.byte	-1
   08FE 10                  426 	.byte	16
   08FF 08                  427 	.byte	8
   0900 FF                  428 	.byte	-1
   0901 00                  429 	.byte	0
   0902 48                  430 	.byte	72
   0903 FF                  431 	.byte	-1
   0904 F0                  432 	.byte	-16
   0905 F8                  433 	.byte	-8
   0906 FF                  434 	.byte	-1
   0907 F8                  435 	.byte	-8
   0908 00                  436 	.byte	0
   0909 00                  437 	.byte	0
   090A 18                  438 	.byte	24
   090B 08                  439 	.byte	8
   090C FF                  440 	.byte	-1
   090D F4                  441 	.byte	-12
   090E 08                  442 	.byte	8
   090F 00                  443 	.byte	0
   0910 DC                  444 	.byte	-36
   0911 EC                  445 	.byte	-20
   0912 FF                  446 	.byte	-1
   0913 18                  447 	.byte	24
   0914 2C                  448 	.byte	44
   0915 FF                  449 	.byte	-1
   0916 00                  450 	.byte	0
   0917 1C                  451 	.byte	28
   0918 FF                  452 	.byte	-1
   0919 E8                  453 	.byte	-24
   091A F0                  454 	.byte	-16
   091B                     455 _vl_term_4_203:
   091B 01                  456 	.byte	1
                            457 	.globl	_vl_player_right1
   091C                     458 _vl_player_right1:
   091C 00                  459 	.byte	0
   091D 08                  460 	.byte	8
   091E B0                  461 	.byte	-80
   091F FF                  462 	.byte	-1
   0920 B0                  463 	.byte	-80
   0921 00                  464 	.byte	0
   0922 FF                  465 	.byte	-1
   0923 E8                  466 	.byte	-24
   0924 F0                  467 	.byte	-16
   0925 FF                  468 	.byte	-1
   0926 00                  469 	.byte	0
   0927 B0                  470 	.byte	-80
   0928 FF                  471 	.byte	-1
   0929 18                  472 	.byte	24
   092A F0                  473 	.byte	-16
   092B FF                  474 	.byte	-1
   092C 50                  475 	.byte	80
   092D 00                  476 	.byte	0
   092E FF                  477 	.byte	-1
   092F 18                  478 	.byte	24
   0930 10                  479 	.byte	16
   0931 FF                  480 	.byte	-1
   0932 00                  481 	.byte	0
   0933 50                  482 	.byte	80
   0934 FF                  483 	.byte	-1
   0935 E8                  484 	.byte	-24
   0936 10                  485 	.byte	16
   0937 00                  486 	.byte	0
   0938 F8                  487 	.byte	-8
   0939 00                  488 	.byte	0
   093A FF                  489 	.byte	-1
   093B 10                  490 	.byte	16
   093C 3C                  491 	.byte	60
   093D FF                  492 	.byte	-1
   093E 00                  493 	.byte	0
   093F 28                  494 	.byte	40
   0940 FF                  495 	.byte	-1
   0941 F0                  496 	.byte	-16
   0942 3C                  497 	.byte	60
   0943 00                  498 	.byte	0
   0944 08                  499 	.byte	8
   0945 00                  500 	.byte	0
   0946 FF                  501 	.byte	-1
   0947 B0                  502 	.byte	-80
   0948 00                  503 	.byte	0
   0949 FF                  504 	.byte	-1
   094A E8                  505 	.byte	-24
   094B F0                  506 	.byte	-16
   094C FF                  507 	.byte	-1
   094D 18                  508 	.byte	24
   094E F0                  509 	.byte	-16
   094F FF                  510 	.byte	-1
   0950 08                  511 	.byte	8
   0951 00                  512 	.byte	0
   0952 00                  513 	.byte	0
   0953 F0                  514 	.byte	-16
   0954 18                  515 	.byte	24
   0955 FF                  516 	.byte	-1
   0956 10                  517 	.byte	16
   0957 CC                  518 	.byte	-52
   0958 00                  519 	.byte	0
   0959 00                  520 	.byte	0
   095A 3C                  521 	.byte	60
   095B FF                  522 	.byte	-1
   095C 00                  523 	.byte	0
   095D B0                  524 	.byte	-80
   095E FF                  525 	.byte	-1
   095F 00                  526 	.byte	0
   0960 B0                  527 	.byte	-80
   0961 00                  528 	.byte	0
   0962 00                  529 	.byte	0
   0963 3C                  530 	.byte	60
   0964 FF                  531 	.byte	-1
   0965 F0                  532 	.byte	-16
   0966 C0                  533 	.byte	-64
   0967                     534 _vl_term_5_243:
   0967 01                  535 	.byte	1
                            536 	.globl	_vl_player_right2
   0968                     537 _vl_player_right2:
   0968 00                  538 	.byte	0
   0969 D0                  539 	.byte	-48
   096A A8                  540 	.byte	-88
   096B 00                  541 	.byte	0
   096C D0                  542 	.byte	-48
   096D A8                  543 	.byte	-88
   096E FF                  544 	.byte	-1
   096F 18                  545 	.byte	24
   0970 10                  546 	.byte	16
   0971 FF                  547 	.byte	-1
   0972 50                  548 	.byte	80
   0973 00                  549 	.byte	0
   0974 FF                  550 	.byte	-1
   0975 18                  551 	.byte	24
   0976 F0                  552 	.byte	-16
   0977 00                  553 	.byte	0
   0978 E0                  554 	.byte	-32
   0979 F0                  555 	.byte	-16
   097A FF                  556 	.byte	-1
   097B 00                  557 	.byte	0
   097C EC                  558 	.byte	-20
   097D FF                  559 	.byte	-1
   097E 10                  560 	.byte	16
   097F F8                  561 	.byte	-8
   0980 FF                  562 	.byte	-1
   0981 38                  563 	.byte	56
   0982 00                  564 	.byte	0
   0983 FF                  565 	.byte	-1
   0984 10                  566 	.byte	16
   0985 08                  567 	.byte	8
   0986 FF                  568 	.byte	-1
   0987 F0                  569 	.byte	-16
   0988 08                  570 	.byte	8
   0989 FF                  571 	.byte	-1
   098A C8                  572 	.byte	-56
   098B 00                  573 	.byte	0
   098C FF                  574 	.byte	-1
   098D F0                  575 	.byte	-16
   098E F8                  576 	.byte	-8
   098F 00                  577 	.byte	0
   0990 58                  578 	.byte	88
   0991 00                  579 	.byte	0
   0992 FF                  580 	.byte	-1
   0993 00                  581 	.byte	0
   0994 48                  582 	.byte	72
   0995 FF                  583 	.byte	-1
   0996 F0                  584 	.byte	-16
   0997 08                  585 	.byte	8
   0998 FF                  586 	.byte	-1
   0999 D8                  587 	.byte	-40
   099A 00                  588 	.byte	0
   099B 00                  589 	.byte	0
   099C 00                  590 	.byte	0
   099D 14                  591 	.byte	20
   099E FF                  592 	.byte	-1
   099F 1C                  593 	.byte	28
   09A0 EC                  594 	.byte	-20
   09A1 00                  595 	.byte	0
   09A2 1C                  596 	.byte	28
   09A3 F0                  597 	.byte	-16
   09A4 FF                  598 	.byte	-1
   09A5 28                  599 	.byte	40
   09A6 E4                  600 	.byte	-28
   09A7 FF                  601 	.byte	-1
   09A8 00                  602 	.byte	0
   09A9 28                  603 	.byte	40
   09AA FF                  604 	.byte	-1
   09AB C0                  605 	.byte	-64
   09AC 6C                  606 	.byte	108
   09AD FF                  607 	.byte	-1
   09AE C0                  608 	.byte	-64
   09AF 6C                  609 	.byte	108
   09B0 00                  610 	.byte	0
   09B1 34                  611 	.byte	52
   09B2 A8                  612 	.byte	-88
   09B3 00                  613 	.byte	0
   09B4 34                  614 	.byte	52
   09B5 A8                  615 	.byte	-88
   09B6 FF                  616 	.byte	-1
   09B7 00                  617 	.byte	0
   09B8 1C                  618 	.byte	28
   09B9 FF                  619 	.byte	-1
   09BA 10                  620 	.byte	16
   09BB E8                  621 	.byte	-24
   09BC FF                  622 	.byte	-1
   09BD 00                  623 	.byte	0
   09BE E0                  624 	.byte	-32
   09BF 00                  625 	.byte	0
   09C0 00                  626 	.byte	0
   09C1 D2                  627 	.byte	-46
   09C2 FF                  628 	.byte	-1
   09C3 00                  629 	.byte	0
   09C4 E0                  630 	.byte	-32
   09C5 FF                  631 	.byte	-1
   09C6 F0                  632 	.byte	-16
   09C7 08                  633 	.byte	8
   09C8 FF                  634 	.byte	-1
   09C9 00                  635 	.byte	0
   09CA 20                  636 	.byte	32
   09CB                     637 _vl_term_6_290:
   09CB 01                  638 	.byte	1
                            639 	.globl	_vl_player_right3
   09CC                     640 _vl_player_right3:
   09CC 00                  641 	.byte	0
   09CD 08                  642 	.byte	8
   09CE 50                  643 	.byte	80
   09CF FF                  644 	.byte	-1
   09D0 18                  645 	.byte	24
   09D1 F0                  646 	.byte	-16
   09D2 FF                  647 	.byte	-1
   09D3 F0                  648 	.byte	-16
   09D4 F4                  649 	.byte	-12
   09D5 00                  650 	.byte	0
   09D6 90                  651 	.byte	-112
   09D7 0C                  652 	.byte	12
   09D8 FF                  653 	.byte	-1
   09D9 00                  654 	.byte	0
   09DA 50                  655 	.byte	80
   09DB FF                  656 	.byte	-1
   09DC 18                  657 	.byte	24
   09DD 10                  658 	.byte	16
   09DE FF                  659 	.byte	-1
   09DF 50                  660 	.byte	80
   09E0 00                  661 	.byte	0
   09E1 FF                  662 	.byte	-1
   09E2 18                  663 	.byte	24
   09E3 F0                  664 	.byte	-16
   09E4 FF                  665 	.byte	-1
   09E5 00                  666 	.byte	0
   09E6 B0                  667 	.byte	-80
   09E7 00                  668 	.byte	0
   09E8 FC                  669 	.byte	-4
   09E9 E4                  670 	.byte	-28
   09EA FF                  671 	.byte	-1
   09EB 30                  672 	.byte	48
   09EC 00                  673 	.byte	0
   09ED FF                  674 	.byte	-1
   09EE 10                  675 	.byte	16
   09EF F8                  676 	.byte	-8
   09F0 FF                  677 	.byte	-1
   09F1 00                  678 	.byte	0
   09F2 B8                  679 	.byte	-72
   09F3 FF                  680 	.byte	-1
   09F4 F0                  681 	.byte	-16
   09F5 08                  682 	.byte	8
   09F6 FF                  683 	.byte	-1
   09F7 F8                  684 	.byte	-8
   09F8 00                  685 	.byte	0
   09F9 00                  686 	.byte	0
   09FA 18                  687 	.byte	24
   09FB F8                  688 	.byte	-8
   09FC FF                  689 	.byte	-1
   09FD F4                  690 	.byte	-12
   09FE F8                  691 	.byte	-8
   09FF 00                  692 	.byte	0
   0A00 DC                  693 	.byte	-36
   0A01 14                  694 	.byte	20
   0A02 FF                  695 	.byte	-1
   0A03 18                  696 	.byte	24
   0A04 D4                  697 	.byte	-44
   0A05 FF                  698 	.byte	-1
   0A06 00                  699 	.byte	0
   0A07 E4                  700 	.byte	-28
   0A08 FF                  701 	.byte	-1
   0A09 E8                  702 	.byte	-24
   0A0A 10                  703 	.byte	16
   0A0B                     704 _vl_term_7_323:
   0A0B 01                  705 	.byte	1
                            706 	.globl	__player_draw_mid
   0A0C                     707 __player_draw_mid:
   0A0C BD F3 54      [ 8]  708 	jsr	___Reset0Ref
   0A0F C6 7F         [ 2]  709 	ldb	#127
   0A11 D7 04         [ 4]  710 	stb	*_dp_VIA_t1_cnt_lo
   0A13 F6 C8 AA      [ 5]  711 	ldb	_the_player
   0A16 4F            [ 2]  712 	clra		;zero_extendqihi: R:b -> R:d
   0A17 1F 01         [ 6]  713 	tfr	d,x
   0A19 C6 90         [ 2]  714 	ldb	#-112
   0A1B E7 E2         [ 6]  715 	stb	,-s
   0A1D E6 89 07 4E   [ 8]  716 	ldb	_PLAYER_X_LUT,x
   0A21 BD 0B 8E      [ 8]  717 	jsr	__Moveto_d
   0A24 C6 10         [ 2]  718 	ldb	#16
   0A26 D7 04         [ 4]  719 	stb	*_dp_VIA_t1_cnt_lo
   0A28 8E 07 A3      [ 3]  720 	ldx	#_vl_player_mid1
   0A2B BD F4 10      [ 8]  721 	jsr	___Draw_VLp
   0A2E BD F3 54      [ 8]  722 	jsr	___Reset0Ref
   0A31 C6 7F         [ 2]  723 	ldb	#127
   0A33 D7 04         [ 4]  724 	stb	*_dp_VIA_t1_cnt_lo
   0A35 F6 C8 AA      [ 5]  725 	ldb	_the_player
   0A38 4F            [ 2]  726 	clra		;zero_extendqihi: R:b -> R:d
   0A39 1F 01         [ 6]  727 	tfr	d,x
   0A3B C6 90         [ 2]  728 	ldb	#-112
   0A3D E7 E2         [ 6]  729 	stb	,-s
   0A3F E6 89 07 4E   [ 8]  730 	ldb	_PLAYER_X_LUT,x
   0A43 BD 0B 8E      [ 8]  731 	jsr	__Moveto_d
   0A46 C6 10         [ 2]  732 	ldb	#16
   0A48 D7 04         [ 4]  733 	stb	*_dp_VIA_t1_cnt_lo
   0A4A 32 62         [ 5]  734 	leas	2,s
   0A4C 8E 07 E3      [ 3]  735 	ldx	#_vl_player_mid2
   0A4F 7E F4 10      [ 4]  736 	jmp	___Draw_VLp
                            737 	.globl	__player_draw_left
   0A52                     738 __player_draw_left:
   0A52 BD F3 54      [ 8]  739 	jsr	___Reset0Ref
   0A55 C6 7F         [ 2]  740 	ldb	#127
   0A57 D7 04         [ 4]  741 	stb	*_dp_VIA_t1_cnt_lo
   0A59 F6 C8 AA      [ 5]  742 	ldb	_the_player
   0A5C 4F            [ 2]  743 	clra		;zero_extendqihi: R:b -> R:d
   0A5D 1F 01         [ 6]  744 	tfr	d,x
   0A5F C6 90         [ 2]  745 	ldb	#-112
   0A61 E7 E2         [ 6]  746 	stb	,-s
   0A63 E6 89 07 4E   [ 8]  747 	ldb	_PLAYER_X_LUT,x
   0A67 BD 0B 8E      [ 8]  748 	jsr	__Moveto_d
   0A6A C6 10         [ 2]  749 	ldb	#16
   0A6C D7 04         [ 4]  750 	stb	*_dp_VIA_t1_cnt_lo
   0A6E 8E 08 2C      [ 3]  751 	ldx	#_vl_player_left1
   0A71 BD F4 10      [ 8]  752 	jsr	___Draw_VLp
   0A74 BD F3 54      [ 8]  753 	jsr	___Reset0Ref
   0A77 C6 7F         [ 2]  754 	ldb	#127
   0A79 D7 04         [ 4]  755 	stb	*_dp_VIA_t1_cnt_lo
   0A7B F6 C8 AA      [ 5]  756 	ldb	_the_player
   0A7E 4F            [ 2]  757 	clra		;zero_extendqihi: R:b -> R:d
   0A7F 1F 01         [ 6]  758 	tfr	d,x
   0A81 C6 90         [ 2]  759 	ldb	#-112
   0A83 E7 E2         [ 6]  760 	stb	,-s
   0A85 E6 89 07 4E   [ 8]  761 	ldb	_PLAYER_X_LUT,x
   0A89 BD 0B 8E      [ 8]  762 	jsr	__Moveto_d
   0A8C C6 10         [ 2]  763 	ldb	#16
   0A8E D7 04         [ 4]  764 	stb	*_dp_VIA_t1_cnt_lo
   0A90 8E 08 78      [ 3]  765 	ldx	#_vl_player_left2
   0A93 BD F4 10      [ 8]  766 	jsr	___Draw_VLp
   0A96 BD F3 54      [ 8]  767 	jsr	___Reset0Ref
   0A99 C6 7F         [ 2]  768 	ldb	#127
   0A9B D7 04         [ 4]  769 	stb	*_dp_VIA_t1_cnt_lo
   0A9D F6 C8 AA      [ 5]  770 	ldb	_the_player
   0AA0 4F            [ 2]  771 	clra		;zero_extendqihi: R:b -> R:d
   0AA1 1F 01         [ 6]  772 	tfr	d,x
   0AA3 C6 90         [ 2]  773 	ldb	#-112
   0AA5 E7 E2         [ 6]  774 	stb	,-s
   0AA7 E6 89 07 4E   [ 8]  775 	ldb	_PLAYER_X_LUT,x
   0AAB BD 0B 8E      [ 8]  776 	jsr	__Moveto_d
   0AAE C6 10         [ 2]  777 	ldb	#16
   0AB0 D7 04         [ 4]  778 	stb	*_dp_VIA_t1_cnt_lo
   0AB2 32 63         [ 5]  779 	leas	3,s
   0AB4 8E 08 DC      [ 3]  780 	ldx	#_vl_player_left3
   0AB7 7E F4 10      [ 4]  781 	jmp	___Draw_VLp
                            782 	.globl	__player_draw_right
   0ABA                     783 __player_draw_right:
   0ABA BD F3 54      [ 8]  784 	jsr	___Reset0Ref
   0ABD C6 7F         [ 2]  785 	ldb	#127
   0ABF D7 04         [ 4]  786 	stb	*_dp_VIA_t1_cnt_lo
   0AC1 F6 C8 AA      [ 5]  787 	ldb	_the_player
   0AC4 4F            [ 2]  788 	clra		;zero_extendqihi: R:b -> R:d
   0AC5 1F 01         [ 6]  789 	tfr	d,x
   0AC7 C6 90         [ 2]  790 	ldb	#-112
   0AC9 E7 E2         [ 6]  791 	stb	,-s
   0ACB E6 89 07 4E   [ 8]  792 	ldb	_PLAYER_X_LUT,x
   0ACF BD 0B 8E      [ 8]  793 	jsr	__Moveto_d
   0AD2 C6 10         [ 2]  794 	ldb	#16
   0AD4 D7 04         [ 4]  795 	stb	*_dp_VIA_t1_cnt_lo
   0AD6 8E 09 1C      [ 3]  796 	ldx	#_vl_player_right1
   0AD9 BD F4 10      [ 8]  797 	jsr	___Draw_VLp
   0ADC BD F3 54      [ 8]  798 	jsr	___Reset0Ref
   0ADF C6 7F         [ 2]  799 	ldb	#127
   0AE1 D7 04         [ 4]  800 	stb	*_dp_VIA_t1_cnt_lo
   0AE3 F6 C8 AA      [ 5]  801 	ldb	_the_player
   0AE6 4F            [ 2]  802 	clra		;zero_extendqihi: R:b -> R:d
   0AE7 1F 01         [ 6]  803 	tfr	d,x
   0AE9 C6 90         [ 2]  804 	ldb	#-112
   0AEB E7 E2         [ 6]  805 	stb	,-s
   0AED E6 89 07 4E   [ 8]  806 	ldb	_PLAYER_X_LUT,x
   0AF1 BD 0B 8E      [ 8]  807 	jsr	__Moveto_d
   0AF4 C6 10         [ 2]  808 	ldb	#16
   0AF6 D7 04         [ 4]  809 	stb	*_dp_VIA_t1_cnt_lo
   0AF8 8E 09 68      [ 3]  810 	ldx	#_vl_player_right2
   0AFB BD F4 10      [ 8]  811 	jsr	___Draw_VLp
   0AFE BD F3 54      [ 8]  812 	jsr	___Reset0Ref
   0B01 C6 7F         [ 2]  813 	ldb	#127
   0B03 D7 04         [ 4]  814 	stb	*_dp_VIA_t1_cnt_lo
   0B05 F6 C8 AA      [ 5]  815 	ldb	_the_player
   0B08 4F            [ 2]  816 	clra		;zero_extendqihi: R:b -> R:d
   0B09 1F 01         [ 6]  817 	tfr	d,x
   0B0B C6 90         [ 2]  818 	ldb	#-112
   0B0D E7 E2         [ 6]  819 	stb	,-s
   0B0F E6 89 07 4E   [ 8]  820 	ldb	_PLAYER_X_LUT,x
   0B13 BD 0B 8E      [ 8]  821 	jsr	__Moveto_d
   0B16 C6 10         [ 2]  822 	ldb	#16
   0B18 D7 04         [ 4]  823 	stb	*_dp_VIA_t1_cnt_lo
   0B1A 32 63         [ 5]  824 	leas	3,s
   0B1C 8E 09 CC      [ 3]  825 	ldx	#_vl_player_right3
   0B1F 7E F4 10      [ 4]  826 	jmp	___Draw_VLp
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Jun 13 22:19:59 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                004B R   |   3 L6                 0037 R
  3 _PLAYER_DRAW_L     0003 GR  |   3 _PLAYER_X_LUT      0000 GR
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
  3 __player_draw_     0304 GR  |   3 __player_draw_     02BE GR
  3 __player_draw_     036C GR  |   3 _check_collisi     0054 GR
    _dp_VIA_t1_cnt     **** GX  |   3 _player_change     002E GR
  3 _player_change     0040 GR  |   3 _player_draw       0018 GR
  3 _player_init       0009 GR  |   2 _the_player        0000 GR
  3 _vl_player_lef     00DE GR  |   3 _vl_player_lef     012A GR
  3 _vl_player_lef     018E GR  |   3 _vl_player_mid     0055 GR
  3 _vl_player_mid     0095 GR  |   3 _vl_player_rig     01CE GR
  3 _vl_player_rig     021A GR  |   3 _vl_player_rig     027E GR
  3 _vl_term_0_46      0094 R   |   3 _vl_term_1_83      00DD R
  3 _vl_term_2_123     0129 R   |   3 _vl_term_3_170     018D R
  3 _vl_term_4_203     01CD R   |   3 _vl_term_5_243     0219 R
  3 _vl_term_6_290     027D R   |   3 _vl_term_7_323     02BD R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri Jun 13 22:19:59 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    4   flags    0
   3 .text            size  3D4   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

