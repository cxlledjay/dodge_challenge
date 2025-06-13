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
   0751 0A 6C                17 	.word	__player_draw_left
   0753 0A 90                18 	.word	__player_draw_mid
   0755 0A D6                19 	.word	__player_draw_right
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
   07E4 00                  135 	.byte	0
   07E5 50                  136 	.byte	80
   07E6 FF                  137 	.byte	-1
   07E7 70                  138 	.byte	112
   07E8 C0                  139 	.byte	-64
   07E9 FF                  140 	.byte	-1
   07EA 00                  141 	.byte	0
   07EB E0                  142 	.byte	-32
   07EC 00                  143 	.byte	0
   07ED E4                  144 	.byte	-28
   07EE 30                  145 	.byte	48
   07EF FF                  146 	.byte	-1
   07F0 00                  147 	.byte	0
   07F1 30                  148 	.byte	48
   07F2 FF                  149 	.byte	-1
   07F3 10                  150 	.byte	16
   07F4 F8                  151 	.byte	-8
   07F5 FF                  152 	.byte	-1
   07F6 00                  153 	.byte	0
   07F7 D0                  154 	.byte	-48
   07F8 00                  155 	.byte	0
   07F9 00                  156 	.byte	0
   07FA D0                  157 	.byte	-48
   07FB FF                  158 	.byte	-1
   07FC 00                  159 	.byte	0
   07FD D0                  160 	.byte	-48
   07FE FF                  161 	.byte	-1
   07FF F0                  162 	.byte	-16
   0800 F8                  163 	.byte	-8
   0801 FF                  164 	.byte	-1
   0802 00                  165 	.byte	0
   0803 30                  166 	.byte	48
   0804 00                  167 	.byte	0
   0805 1C                  168 	.byte	28
   0806 10                  169 	.byte	16
   0807 FF                  170 	.byte	-1
   0808 90                  171 	.byte	-112
   0809 C0                  172 	.byte	-64
   080A 00                  173 	.byte	0
   080B 20                  174 	.byte	32
   080C D8                  175 	.byte	-40
   080D FF                  176 	.byte	-1
   080E 28                  177 	.byte	40
   080F 00                  178 	.byte	0
   0810 FF                  179 	.byte	-1
   0811 00                  180 	.byte	0
   0812 3C                  181 	.byte	60
   0813 FF                  182 	.byte	-1
   0814 DC                  183 	.byte	-36
   0815 00                  184 	.byte	0
   0816 00                  185 	.byte	0
   0817 00                  186 	.byte	0
   0818 78                  187 	.byte	120
   0819 FF                  188 	.byte	-1
   081A 24                  189 	.byte	36
   081B 00                  190 	.byte	0
   081C FF                  191 	.byte	-1
   081D 00                  192 	.byte	0
   081E 3C                  193 	.byte	60
   081F FF                  194 	.byte	-1
   0820 D8                  195 	.byte	-40
   0821 00                  196 	.byte	0
   0822 00                  197 	.byte	0
   0823 14                  198 	.byte	20
   0824 9C                  199 	.byte	-100
   0825 FF                  200 	.byte	-1
   0826 10                  201 	.byte	16
   0827 F8                  202 	.byte	-8
   0828 FF                  203 	.byte	-1
   0829 00                  204 	.byte	0
   082A E8                  205 	.byte	-24
   082B FF                  206 	.byte	-1
   082C F0                  207 	.byte	-16
   082D F8                  208 	.byte	-8
   082E                     209 _vl_term_1_85:
   082E 01                  210 	.byte	1
                            211 	.globl	_vl_player_mid2_enhanced
   082F                     212 _vl_player_mid2_enhanced:
   082F 00                  213 	.byte	0
   0830 20                  214 	.byte	32
   0831 88                  215 	.byte	-120
   0832 FF                  216 	.byte	-1
   0833 28                  217 	.byte	40
   0834 00                  218 	.byte	0
   0835 FF                  219 	.byte	-1
   0836 00                  220 	.byte	0
   0837 3C                  221 	.byte	60
   0838 FF                  222 	.byte	-1
   0839 DC                  223 	.byte	-36
   083A 00                  224 	.byte	0
   083B 00                  225 	.byte	0
   083C E0                  226 	.byte	-32
   083D EC                  227 	.byte	-20
   083E FF                  228 	.byte	-1
   083F 70                  229 	.byte	112
   0840 40                  230 	.byte	64
   0841 FF                  231 	.byte	-1
   0842 00                  232 	.byte	0
   0843 20                  233 	.byte	32
   0844 FF                  234 	.byte	-1
   0845 90                  235 	.byte	-112
   0846 40                  236 	.byte	64
   0847 00                  237 	.byte	0
   0848 20                  238 	.byte	32
   0849 28                  239 	.byte	40
   084A FF                  240 	.byte	-1
   084B 28                  241 	.byte	40
   084C 00                  242 	.byte	0
   084D FF                  243 	.byte	-1
   084E 00                  244 	.byte	0
   084F C4                  245 	.byte	-60
   0850 FF                  246 	.byte	-1
   0851 DC                  247 	.byte	-36
   0852 00                  248 	.byte	0
   0853 00                  249 	.byte	0
   0854 2D                  250 	.byte	45
   0855 E4                  251 	.byte	-28
   0856 FF                  252 	.byte	-1
   0857 00                  253 	.byte	0
   0858 30                  254 	.byte	48
   0859 FF                  255 	.byte	-1
   085A 10                  256 	.byte	16
   085B F8                  257 	.byte	-8
   085C FF                  258 	.byte	-1
   085D 00                  259 	.byte	0
   085E D0                  260 	.byte	-48
   085F 00                  261 	.byte	0
   0860 00                  262 	.byte	0
   0861 D0                  263 	.byte	-48
   0862 FF                  264 	.byte	-1
   0863 00                  265 	.byte	0
   0864 D0                  266 	.byte	-48
   0865 FF                  267 	.byte	-1
   0866 F0                  268 	.byte	-16
   0867 F8                  269 	.byte	-8
   0868 FF                  270 	.byte	-1
   0869 00                  271 	.byte	0
   086A 30                  272 	.byte	48
   086B 00                  273 	.byte	0
   086C E4                  274 	.byte	-28
   086D 0C                  275 	.byte	12
   086E FF                  276 	.byte	-1
   086F 10                  277 	.byte	16
   0870 08                  278 	.byte	8
   0871 FF                  279 	.byte	-1
   0872 00                  280 	.byte	0
   0873 18                  281 	.byte	24
   0874 FF                  282 	.byte	-1
   0875 F0                  283 	.byte	-16
   0876 08                  284 	.byte	8
   0877                     285 _vl_term_2_123:
   0877 01                  286 	.byte	1
                            287 	.globl	_vl_player_left
   0878                     288 _vl_player_left:
   0878 00                  289 	.byte	0
   0879 0C                  290 	.byte	12
   087A 78                  291 	.byte	120
   087B FF                  292 	.byte	-1
   087C 88                  293 	.byte	-120
   087D 00                  294 	.byte	0
   087E FF                  295 	.byte	-1
   087F DC                  296 	.byte	-36
   0880 18                  297 	.byte	24
   0881 FF                  298 	.byte	-1
   0882 00                  299 	.byte	0
   0883 78                  300 	.byte	120
   0884 FF                  301 	.byte	-1
   0885 24                  302 	.byte	36
   0886 18                  303 	.byte	24
   0887 FF                  304 	.byte	-1
   0888 78                  305 	.byte	120
   0889 00                  306 	.byte	0
   088A FF                  307 	.byte	-1
   088B 24                  308 	.byte	36
   088C E8                  309 	.byte	-24
   088D FF                  310 	.byte	-1
   088E 00                  311 	.byte	0
   088F 88                  312 	.byte	-120
   0890 FF                  313 	.byte	-1
   0891 DC                  314 	.byte	-36
   0892 E8                  315 	.byte	-24
   0893 00                  316 	.byte	0
   0894 F4                  317 	.byte	-12
   0895 00                  318 	.byte	0
   0896 FF                  319 	.byte	-1
   0897 18                  320 	.byte	24
   0898 A6                  321 	.byte	-90
   0899 FF                  322 	.byte	-1
   089A 00                  323 	.byte	0
   089B C4                  324 	.byte	-60
   089C FF                  325 	.byte	-1
   089D E8                  326 	.byte	-24
   089E A6                  327 	.byte	-90
   089F 00                  328 	.byte	0
   08A0 0C                  329 	.byte	12
   08A1 00                  330 	.byte	0
   08A2 FF                  331 	.byte	-1
   08A3 88                  332 	.byte	-120
   08A4 00                  333 	.byte	0
   08A5 FF                  334 	.byte	-1
   08A6 DC                  335 	.byte	-36
   08A7 18                  336 	.byte	24
   08A8 FF                  337 	.byte	-1
   08A9 24                  338 	.byte	36
   08AA 18                  339 	.byte	24
   08AB FF                  340 	.byte	-1
   08AC 0C                  341 	.byte	12
   08AD 00                  342 	.byte	0
   08AE 00                  343 	.byte	0
   08AF E8                  344 	.byte	-24
   08B0 DC                  345 	.byte	-36
   08B1 FF                  346 	.byte	-1
   08B2 18                  347 	.byte	24
   08B3 4E                  348 	.byte	78
   08B4 00                  349 	.byte	0
   08B5 00                  350 	.byte	0
   08B6 A6                  351 	.byte	-90
   08B7 FF                  352 	.byte	-1
   08B8 00                  353 	.byte	0
   08B9 78                  354 	.byte	120
   08BA FF                  355 	.byte	-1
   08BB 00                  356 	.byte	0
   08BC 78                  357 	.byte	120
   08BD 00                  358 	.byte	0
   08BE 00                  359 	.byte	0
   08BF A6                  360 	.byte	-90
   08C0 FF                  361 	.byte	-1
   08C1 E8                  362 	.byte	-24
   08C2 60                  363 	.byte	96
   08C3 00                  364 	.byte	0
   08C4 F4                  365 	.byte	-12
   08C5 45                  366 	.byte	69
   08C6 00                  367 	.byte	0
   08C7 F4                  368 	.byte	-12
   08C8 45                  369 	.byte	69
   08C9 FF                  370 	.byte	-1
   08CA 24                  371 	.byte	36
   08CB E8                  372 	.byte	-24
   08CC FF                  373 	.byte	-1
   08CD 78                  374 	.byte	120
   08CE 00                  375 	.byte	0
   08CF FF                  376 	.byte	-1
   08D0 24                  377 	.byte	36
   08D1 18                  378 	.byte	24
   08D2 00                  379 	.byte	0
   08D3 D0                  380 	.byte	-48
   08D4 18                  381 	.byte	24
   08D5 FF                  382 	.byte	-1
   08D6 00                  383 	.byte	0
   08D7 1E                  384 	.byte	30
   08D8 FF                  385 	.byte	-1
   08D9 18                  386 	.byte	24
   08DA 0C                  387 	.byte	12
   08DB FF                  388 	.byte	-1
   08DC 54                  389 	.byte	84
   08DD 00                  390 	.byte	0
   08DE FF                  391 	.byte	-1
   08DF 18                  392 	.byte	24
   08E0 F4                  393 	.byte	-12
   08E1 FF                  394 	.byte	-1
   08E2 E8                  395 	.byte	-24
   08E3 F4                  396 	.byte	-12
   08E4 FF                  397 	.byte	-1
   08E5 AC                  398 	.byte	-84
   08E6 00                  399 	.byte	0
   08E7 FF                  400 	.byte	-1
   08E8 E8                  401 	.byte	-24
   08E9 0C                  402 	.byte	12
   08EA 00                  403 	.byte	0
   08EB 45                  404 	.byte	69
   08EC 00                  405 	.byte	0
   08ED 00                  406 	.byte	0
   08EE 45                  407 	.byte	69
   08EF 00                  408 	.byte	0
   08F0 FF                  409 	.byte	-1
   08F1 00                  410 	.byte	0
   08F2 94                  411 	.byte	-108
   08F3 FF                  412 	.byte	-1
   08F4 E8                  413 	.byte	-24
   08F5 F4                  414 	.byte	-12
   08F6 FF                  415 	.byte	-1
   08F7 C4                  416 	.byte	-60
   08F8 00                  417 	.byte	0
   08F9 00                  418 	.byte	0
   08FA 00                  419 	.byte	0
   08FB E2                  420 	.byte	-30
   08FC FF                  421 	.byte	-1
   08FD 2A                  422 	.byte	42
   08FE 1E                  423 	.byte	30
   08FF 00                  424 	.byte	0
   0900 2A                  425 	.byte	42
   0901 18                  426 	.byte	24
   0902 FF                  427 	.byte	-1
   0903 3C                  428 	.byte	60
   0904 2A                  429 	.byte	42
   0905 00                  430 	.byte	0
   0906 F4                  431 	.byte	-12
   0907 F4                  432 	.byte	-12
   0908 FF                  433 	.byte	-1
   0909 00                  434 	.byte	0
   090A 30                  435 	.byte	48
   090B FF                  436 	.byte	-1
   090C E8                  437 	.byte	-24
   090D F4                  438 	.byte	-12
   090E FF                  439 	.byte	-1
   090F 00                  440 	.byte	0
   0910 D0                  441 	.byte	-48
   0911 00                  442 	.byte	0
   0912 24                  443 	.byte	36
   0913 18                  444 	.byte	24
   0914 FF                  445 	.byte	-1
   0915 00                  446 	.byte	0
   0916 C4                  447 	.byte	-60
   0917 00                  448 	.byte	0
   0918 F4                  449 	.byte	-12
   0919 EE                  450 	.byte	-18
   091A FF                  451 	.byte	-1
   091B 00                  452 	.byte	0
   091C D0                  453 	.byte	-48
   091D FF                  454 	.byte	-1
   091E E8                  455 	.byte	-24
   091F DC                  456 	.byte	-36
   0920 FF                  457 	.byte	-1
   0921 00                  458 	.byte	0
   0922 2A                  459 	.byte	42
   0923 00                  460 	.byte	0
   0924 24                  461 	.byte	36
   0925 3C                  462 	.byte	60
   0926 FF                  463 	.byte	-1
   0927 C0                  464 	.byte	-64
   0928 94                  465 	.byte	-108
   0929 FF                  466 	.byte	-1
   092A C0                  467 	.byte	-64
   092B 94                  468 	.byte	-108
   092C FF                  469 	.byte	-1
   092D C0                  470 	.byte	-64
   092E 94                  471 	.byte	-108
   092F 00                  472 	.byte	0
   0930 0C                  473 	.byte	12
   0931 00                  474 	.byte	0
   0932 FF                  475 	.byte	-1
   0933 24                  476 	.byte	36
   0934 18                  477 	.byte	24
   0935 FF                  478 	.byte	-1
   0936 E8                  479 	.byte	-24
   0937 12                  480 	.byte	18
   0938 00                  481 	.byte	0
   0939 AC                  482 	.byte	-84
   093A F7                  483 	.byte	-9
   093B 00                  484 	.byte	0
   093C AC                  485 	.byte	-84
   093D F7                  486 	.byte	-9
   093E FF                  487 	.byte	-1
   093F 00                  488 	.byte	0
   0940 88                  489 	.byte	-120
   0941 FF                  490 	.byte	-1
   0942 24                  491 	.byte	36
   0943 E8                  492 	.byte	-24
   0944 FF                  493 	.byte	-1
   0945 78                  494 	.byte	120
   0946 00                  495 	.byte	0
   0947 FF                  496 	.byte	-1
   0948 24                  497 	.byte	36
   0949 18                  498 	.byte	24
   094A FF                  499 	.byte	-1
   094B 00                  500 	.byte	0
   094C 78                  501 	.byte	120
   094D 00                  502 	.byte	0
   094E FA                  503 	.byte	-6
   094F 2A                  504 	.byte	42
   0950 FF                  505 	.byte	-1
   0951 48                  506 	.byte	72
   0952 00                  507 	.byte	0
   0953 FF                  508 	.byte	-1
   0954 18                  509 	.byte	24
   0955 0C                  510 	.byte	12
   0956 FF                  511 	.byte	-1
   0957 00                  512 	.byte	0
   0958 6C                  513 	.byte	108
   0959 FF                  514 	.byte	-1
   095A E8                  515 	.byte	-24
   095B F4                  516 	.byte	-12
   095C FF                  517 	.byte	-1
   095D F4                  518 	.byte	-12
   095E 00                  519 	.byte	0
   095F 00                  520 	.byte	0
   0960 24                  521 	.byte	36
   0961 0C                  522 	.byte	12
   0962 FF                  523 	.byte	-1
   0963 EE                  524 	.byte	-18
   0964 0C                  525 	.byte	12
   0965 00                  526 	.byte	0
   0966 CA                  527 	.byte	-54
   0967 E2                  528 	.byte	-30
   0968 FF                  529 	.byte	-1
   0969 24                  530 	.byte	36
   096A 42                  531 	.byte	66
   096B FF                  532 	.byte	-1
   096C 00                  533 	.byte	0
   096D 2A                  534 	.byte	42
   096E FF                  535 	.byte	-1
   096F DC                  536 	.byte	-36
   0970 E8                  537 	.byte	-24
   0971                     538 _vl_term_3_236:
   0971 01                  539 	.byte	1
                            540 	.globl	_vl_player_right
   0972                     541 _vl_player_right:
   0972 00                  542 	.byte	0
   0973 0C                  543 	.byte	12
   0974 88                  544 	.byte	-120
   0975 FF                  545 	.byte	-1
   0976 88                  546 	.byte	-120
   0977 00                  547 	.byte	0
   0978 FF                  548 	.byte	-1
   0979 DC                  549 	.byte	-36
   097A E8                  550 	.byte	-24
   097B FF                  551 	.byte	-1
   097C 00                  552 	.byte	0
   097D 88                  553 	.byte	-120
   097E FF                  554 	.byte	-1
   097F 24                  555 	.byte	36
   0980 E8                  556 	.byte	-24
   0981 FF                  557 	.byte	-1
   0982 78                  558 	.byte	120
   0983 00                  559 	.byte	0
   0984 FF                  560 	.byte	-1
   0985 24                  561 	.byte	36
   0986 18                  562 	.byte	24
   0987 FF                  563 	.byte	-1
   0988 00                  564 	.byte	0
   0989 78                  565 	.byte	120
   098A FF                  566 	.byte	-1
   098B DC                  567 	.byte	-36
   098C 18                  568 	.byte	24
   098D 00                  569 	.byte	0
   098E F4                  570 	.byte	-12
   098F 00                  571 	.byte	0
   0990 FF                  572 	.byte	-1
   0991 18                  573 	.byte	24
   0992 5A                  574 	.byte	90
   0993 FF                  575 	.byte	-1
   0994 00                  576 	.byte	0
   0995 3C                  577 	.byte	60
   0996 FF                  578 	.byte	-1
   0997 E8                  579 	.byte	-24
   0998 5A                  580 	.byte	90
   0999 00                  581 	.byte	0
   099A 0C                  582 	.byte	12
   099B 00                  583 	.byte	0
   099C FF                  584 	.byte	-1
   099D 88                  585 	.byte	-120
   099E 00                  586 	.byte	0
   099F FF                  587 	.byte	-1
   09A0 DC                  588 	.byte	-36
   09A1 E8                  589 	.byte	-24
   09A2 FF                  590 	.byte	-1
   09A3 24                  591 	.byte	36
   09A4 E8                  592 	.byte	-24
   09A5 FF                  593 	.byte	-1
   09A6 0C                  594 	.byte	12
   09A7 00                  595 	.byte	0
   09A8 00                  596 	.byte	0
   09A9 E8                  597 	.byte	-24
   09AA 24                  598 	.byte	36
   09AB FF                  599 	.byte	-1
   09AC 18                  600 	.byte	24
   09AD B2                  601 	.byte	-78
   09AE 00                  602 	.byte	0
   09AF 00                  603 	.byte	0
   09B0 5A                  604 	.byte	90
   09B1 FF                  605 	.byte	-1
   09B2 00                  606 	.byte	0
   09B3 88                  607 	.byte	-120
   09B4 FF                  608 	.byte	-1
   09B5 00                  609 	.byte	0
   09B6 88                  610 	.byte	-120
   09B7 00                  611 	.byte	0
   09B8 00                  612 	.byte	0
   09B9 5A                  613 	.byte	90
   09BA FF                  614 	.byte	-1
   09BB E8                  615 	.byte	-24
   09BC A0                  616 	.byte	-96
   09BD 00                  617 	.byte	0
   09BE F4                  618 	.byte	-12
   09BF BB                  619 	.byte	-69
   09C0 00                  620 	.byte	0
   09C1 F4                  621 	.byte	-12
   09C2 BB                  622 	.byte	-69
   09C3 FF                  623 	.byte	-1
   09C4 24                  624 	.byte	36
   09C5 18                  625 	.byte	24
   09C6 FF                  626 	.byte	-1
   09C7 78                  627 	.byte	120
   09C8 00                  628 	.byte	0
   09C9 FF                  629 	.byte	-1
   09CA 24                  630 	.byte	36
   09CB E8                  631 	.byte	-24
   09CC 00                  632 	.byte	0
   09CD D0                  633 	.byte	-48
   09CE E8                  634 	.byte	-24
   09CF FF                  635 	.byte	-1
   09D0 00                  636 	.byte	0
   09D1 E2                  637 	.byte	-30
   09D2 FF                  638 	.byte	-1
   09D3 18                  639 	.byte	24
   09D4 F4                  640 	.byte	-12
   09D5 FF                  641 	.byte	-1
   09D6 54                  642 	.byte	84
   09D7 00                  643 	.byte	0
   09D8 FF                  644 	.byte	-1
   09D9 18                  645 	.byte	24
   09DA 0C                  646 	.byte	12
   09DB FF                  647 	.byte	-1
   09DC E8                  648 	.byte	-24
   09DD 0C                  649 	.byte	12
   09DE FF                  650 	.byte	-1
   09DF AC                  651 	.byte	-84
   09E0 00                  652 	.byte	0
   09E1 FF                  653 	.byte	-1
   09E2 E8                  654 	.byte	-24
   09E3 F4                  655 	.byte	-12
   09E4 00                  656 	.byte	0
   09E5 45                  657 	.byte	69
   09E6 00                  658 	.byte	0
   09E7 00                  659 	.byte	0
   09E8 45                  660 	.byte	69
   09E9 00                  661 	.byte	0
   09EA FF                  662 	.byte	-1
   09EB 00                  663 	.byte	0
   09EC 6C                  664 	.byte	108
   09ED FF                  665 	.byte	-1
   09EE E8                  666 	.byte	-24
   09EF 0C                  667 	.byte	12
   09F0 FF                  668 	.byte	-1
   09F1 C4                  669 	.byte	-60
   09F2 00                  670 	.byte	0
   09F3 00                  671 	.byte	0
   09F4 00                  672 	.byte	0
   09F5 1E                  673 	.byte	30
   09F6 FF                  674 	.byte	-1
   09F7 2A                  675 	.byte	42
   09F8 E2                  676 	.byte	-30
   09F9 00                  677 	.byte	0
   09FA 2A                  678 	.byte	42
   09FB E8                  679 	.byte	-24
   09FC FF                  680 	.byte	-1
   09FD 3C                  681 	.byte	60
   09FE D6                  682 	.byte	-42
   09FF 00                  683 	.byte	0
   0A00 F4                  684 	.byte	-12
   0A01 0C                  685 	.byte	12
   0A02 FF                  686 	.byte	-1
   0A03 00                  687 	.byte	0
   0A04 D0                  688 	.byte	-48
   0A05 FF                  689 	.byte	-1
   0A06 E8                  690 	.byte	-24
   0A07 0C                  691 	.byte	12
   0A08 FF                  692 	.byte	-1
   0A09 00                  693 	.byte	0
   0A0A 30                  694 	.byte	48
   0A0B 00                  695 	.byte	0
   0A0C 24                  696 	.byte	36
   0A0D E8                  697 	.byte	-24
   0A0E FF                  698 	.byte	-1
   0A0F 00                  699 	.byte	0
   0A10 3C                  700 	.byte	60
   0A11 00                  701 	.byte	0
   0A12 F4                  702 	.byte	-12
   0A13 12                  703 	.byte	18
   0A14 FF                  704 	.byte	-1
   0A15 00                  705 	.byte	0
   0A16 30                  706 	.byte	48
   0A17 FF                  707 	.byte	-1
   0A18 E8                  708 	.byte	-24
   0A19 24                  709 	.byte	36
   0A1A FF                  710 	.byte	-1
   0A1B 00                  711 	.byte	0
   0A1C D6                  712 	.byte	-42
   0A1D 00                  713 	.byte	0
   0A1E 24                  714 	.byte	36
   0A1F C4                  715 	.byte	-60
   0A20 FF                  716 	.byte	-1
   0A21 C0                  717 	.byte	-64
   0A22 6C                  718 	.byte	108
   0A23 FF                  719 	.byte	-1
   0A24 C0                  720 	.byte	-64
   0A25 6C                  721 	.byte	108
   0A26 FF                  722 	.byte	-1
   0A27 C0                  723 	.byte	-64
   0A28 6C                  724 	.byte	108
   0A29 00                  725 	.byte	0
   0A2A 0C                  726 	.byte	12
   0A2B 00                  727 	.byte	0
   0A2C FF                  728 	.byte	-1
   0A2D 24                  729 	.byte	36
   0A2E E8                  730 	.byte	-24
   0A2F FF                  731 	.byte	-1
   0A30 E8                  732 	.byte	-24
   0A31 EE                  733 	.byte	-18
   0A32 00                  734 	.byte	0
   0A33 AC                  735 	.byte	-84
   0A34 09                  736 	.byte	9
   0A35 00                  737 	.byte	0
   0A36 AC                  738 	.byte	-84
   0A37 09                  739 	.byte	9
   0A38 FF                  740 	.byte	-1
   0A39 00                  741 	.byte	0
   0A3A 78                  742 	.byte	120
   0A3B FF                  743 	.byte	-1
   0A3C 24                  744 	.byte	36
   0A3D 18                  745 	.byte	24
   0A3E FF                  746 	.byte	-1
   0A3F 78                  747 	.byte	120
   0A40 00                  748 	.byte	0
   0A41 FF                  749 	.byte	-1
   0A42 24                  750 	.byte	36
   0A43 E8                  751 	.byte	-24
   0A44 FF                  752 	.byte	-1
   0A45 00                  753 	.byte	0
   0A46 88                  754 	.byte	-120
   0A47 00                  755 	.byte	0
   0A48 FA                  756 	.byte	-6
   0A49 D6                  757 	.byte	-42
   0A4A FF                  758 	.byte	-1
   0A4B 48                  759 	.byte	72
   0A4C 00                  760 	.byte	0
   0A4D FF                  761 	.byte	-1
   0A4E 18                  762 	.byte	24
   0A4F F4                  763 	.byte	-12
   0A50 FF                  764 	.byte	-1
   0A51 00                  765 	.byte	0
   0A52 94                  766 	.byte	-108
   0A53 FF                  767 	.byte	-1
   0A54 E8                  768 	.byte	-24
   0A55 0C                  769 	.byte	12
   0A56 FF                  770 	.byte	-1
   0A57 F4                  771 	.byte	-12
   0A58 00                  772 	.byte	0
   0A59 00                  773 	.byte	0
   0A5A 24                  774 	.byte	36
   0A5B F4                  775 	.byte	-12
   0A5C FF                  776 	.byte	-1
   0A5D EE                  777 	.byte	-18
   0A5E F4                  778 	.byte	-12
   0A5F 00                  779 	.byte	0
   0A60 CA                  780 	.byte	-54
   0A61 1E                  781 	.byte	30
   0A62 FF                  782 	.byte	-1
   0A63 24                  783 	.byte	36
   0A64 BE                  784 	.byte	-66
   0A65 FF                  785 	.byte	-1
   0A66 00                  786 	.byte	0
   0A67 D6                  787 	.byte	-42
   0A68 FF                  788 	.byte	-1
   0A69 DC                  789 	.byte	-36
   0A6A 18                  790 	.byte	24
   0A6B                     791 _vl_term_4_349:
   0A6B 01                  792 	.byte	1
                            793 	.globl	__player_draw_left
   0A6C                     794 __player_draw_left:
   0A6C BD F3 54      [ 8]  795 	jsr	___Reset0Ref
   0A6F C6 7F         [ 2]  796 	ldb	#127
   0A71 D7 04         [ 4]  797 	stb	*_dp_VIA_t1_cnt_lo
   0A73 F6 C8 AA      [ 5]  798 	ldb	_the_player
   0A76 4F            [ 2]  799 	clra		;zero_extendqihi: R:b -> R:d
   0A77 1F 01         [ 6]  800 	tfr	d,x
   0A79 C6 90         [ 2]  801 	ldb	#-112
   0A7B E7 E2         [ 6]  802 	stb	,-s
   0A7D E6 89 07 4E   [ 8]  803 	ldb	_PLAYER_X_LUT,x
   0A81 BD 0B 66      [ 8]  804 	jsr	__Moveto_d
   0A84 C6 0A         [ 2]  805 	ldb	#10
   0A86 D7 04         [ 4]  806 	stb	*_dp_VIA_t1_cnt_lo
   0A88 32 61         [ 5]  807 	leas	1,s
   0A8A 8E 08 78      [ 3]  808 	ldx	#_vl_player_left
   0A8D 7E F4 10      [ 4]  809 	jmp	___Draw_VLp
                            810 	.globl	__player_draw_mid
   0A90                     811 __player_draw_mid:
   0A90 BD F3 54      [ 8]  812 	jsr	___Reset0Ref
   0A93 C6 7F         [ 2]  813 	ldb	#127
   0A95 D7 04         [ 4]  814 	stb	*_dp_VIA_t1_cnt_lo
   0A97 F6 C8 AA      [ 5]  815 	ldb	_the_player
   0A9A 4F            [ 2]  816 	clra		;zero_extendqihi: R:b -> R:d
   0A9B 1F 01         [ 6]  817 	tfr	d,x
   0A9D C6 90         [ 2]  818 	ldb	#-112
   0A9F E7 E2         [ 6]  819 	stb	,-s
   0AA1 E6 89 07 4E   [ 8]  820 	ldb	_PLAYER_X_LUT,x
   0AA5 BD 0B 66      [ 8]  821 	jsr	__Moveto_d
   0AA8 C6 10         [ 2]  822 	ldb	#16
   0AAA D7 04         [ 4]  823 	stb	*_dp_VIA_t1_cnt_lo
   0AAC 8E 07 A3      [ 3]  824 	ldx	#_vl_player_mid1
   0AAF BD F4 10      [ 8]  825 	jsr	___Draw_VLp
   0AB2 BD F3 54      [ 8]  826 	jsr	___Reset0Ref
   0AB5 C6 7F         [ 2]  827 	ldb	#127
   0AB7 D7 04         [ 4]  828 	stb	*_dp_VIA_t1_cnt_lo
   0AB9 F6 C8 AA      [ 5]  829 	ldb	_the_player
   0ABC 4F            [ 2]  830 	clra		;zero_extendqihi: R:b -> R:d
   0ABD 1F 01         [ 6]  831 	tfr	d,x
   0ABF C6 90         [ 2]  832 	ldb	#-112
   0AC1 E7 E2         [ 6]  833 	stb	,-s
   0AC3 E6 89 07 4E   [ 8]  834 	ldb	_PLAYER_X_LUT,x
   0AC7 BD 0B 66      [ 8]  835 	jsr	__Moveto_d
   0ACA C6 10         [ 2]  836 	ldb	#16
   0ACC D7 04         [ 4]  837 	stb	*_dp_VIA_t1_cnt_lo
   0ACE 32 62         [ 5]  838 	leas	2,s
   0AD0 8E 08 2F      [ 3]  839 	ldx	#_vl_player_mid2_enhanced
   0AD3 7E F4 10      [ 4]  840 	jmp	___Draw_VLp
                            841 	.globl	__player_draw_right
   0AD6                     842 __player_draw_right:
   0AD6 BD F3 54      [ 8]  843 	jsr	___Reset0Ref
   0AD9 C6 7F         [ 2]  844 	ldb	#127
   0ADB D7 04         [ 4]  845 	stb	*_dp_VIA_t1_cnt_lo
   0ADD F6 C8 AA      [ 5]  846 	ldb	_the_player
   0AE0 4F            [ 2]  847 	clra		;zero_extendqihi: R:b -> R:d
   0AE1 1F 01         [ 6]  848 	tfr	d,x
   0AE3 C6 90         [ 2]  849 	ldb	#-112
   0AE5 E7 E2         [ 6]  850 	stb	,-s
   0AE7 E6 89 07 4E   [ 8]  851 	ldb	_PLAYER_X_LUT,x
   0AEB BD 0B 66      [ 8]  852 	jsr	__Moveto_d
   0AEE C6 0A         [ 2]  853 	ldb	#10
   0AF0 D7 04         [ 4]  854 	stb	*_dp_VIA_t1_cnt_lo
   0AF2 32 61         [ 5]  855 	leas	1,s
   0AF4 8E 09 72      [ 3]  856 	ldx	#_vl_player_right
   0AF7 7E F4 10      [ 4]  857 	jmp	___Draw_VLp
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Jun 13 21:12:40 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                004B R   |   3 L6                 0037 R
  3 _PLAYER_DRAW_L     0003 GR  |   3 _PLAYER_X_LUT      0000 GR
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
  3 __player_draw_     031E GR  |   3 __player_draw_     0342 GR
  3 __player_draw_     0388 GR  |   3 _check_collisi     0054 GR
    _dp_VIA_t1_cnt     **** GX  |   3 _player_change     002E GR
  3 _player_change     0040 GR  |   3 _player_draw       0018 GR
  3 _player_init       0009 GR  |   2 _the_player        0000 GR
  3 _vl_player_lef     012A GR  |   3 _vl_player_mid     0055 GR
  3 _vl_player_mid     0095 GR  |   3 _vl_player_mid     00E1 GR
  3 _vl_player_rig     0224 GR  |   3 _vl_term_0_46      0094 R
  3 _vl_term_1_85      00E0 R   |   3 _vl_term_2_123     0129 R
  3 _vl_term_3_236     0223 R   |   3 _vl_term_4_349     031D R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri Jun 13 21:12:40 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    4   flags    0
   3 .text            size  3AC   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

