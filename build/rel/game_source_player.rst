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
   0751 0A 37                17 	.word	__player_draw_left
   0753 0A 41                18 	.word	__player_draw_mid
   0755 0A 4B                19 	.word	__player_draw_right
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
   076B BD F3 54      [ 8]   32 	jsr	___Reset0Ref
   076E C6 7F         [ 2]   33 	ldb	#127
   0770 D7 04         [ 4]   34 	stb	*_dp_VIA_t1_cnt_lo
   0772 F6 C8 AA      [ 5]   35 	ldb	_the_player
   0775 4F            [ 2]   36 	clra		;zero_extendqihi: R:b -> R:d
   0776 1F 01         [ 6]   37 	tfr	d,x
   0778 C6 90         [ 2]   38 	ldb	#-112
   077A E7 E2         [ 6]   39 	stb	,-s
   077C E6 89 07 4E   [ 8]   40 	ldb	_PLAYER_X_LUT,x
   0780 BD 0A C1      [ 8]   41 	jsr	__Moveto_d
   0783 F6 C8 AA      [ 5]   42 	ldb	_the_player
   0786 4F            [ 2]   43 	clra		;zero_extendqihi: R:b -> R:d
   0787 ED 61         [ 6]   44 	std	1,s
   0789 58            [ 2]   45 	aslb
   078A 49            [ 2]   46 	rola
   078B 1F 01         [ 6]   47 	tfr	d,x
   078D AD 99 07 51   [14]   48 	jsr	[_PLAYER_DRAW_LUT,x]
   0791 32 63         [ 5]   49 	leas	3,s
   0793 39            [ 5]   50 	rts
                             51 	.globl	_player_change_left
   0794                      52 _player_change_left:
   0794 F6 C8 AA      [ 5]   53 	ldb	_the_player
   0797 27 04         [ 3]   54 	beq	L6
   0799 5A            [ 2]   55 	decb
   079A F7 C8 AA      [ 5]   56 	stb	_the_player
   079D                      57 L6:
   079D 8E 07 66      [ 3]   58 	ldx	#_player_draw
   07A0 BF C8 AC      [ 6]   59 	stx	_the_player+2
   07A3 7E 07 66      [ 4]   60 	jmp	_player_draw
                             61 	.globl	_player_change_right
   07A6                      62 _player_change_right:
   07A6 F6 C8 AA      [ 5]   63 	ldb	_the_player
   07A9 C1 02         [ 2]   64 	cmpb	#2	;cmpqi:
   07AB 27 04         [ 3]   65 	beq	L10
   07AD 5C            [ 2]   66 	incb
   07AE F7 C8 AA      [ 5]   67 	stb	_the_player
   07B1                      68 L10:
   07B1 8E 07 66      [ 3]   69 	ldx	#_player_draw
   07B4 BF C8 AC      [ 6]   70 	stx	_the_player+2
   07B7 7E 07 66      [ 4]   71 	jmp	_player_draw
                             72 	.globl	_check_collision
   07BA                      73 _check_collision:
   07BA 39            [ 5]   74 	rts
                             75 	.globl	_vl_player_mid
   07BB                      76 _vl_player_mid:
   07BB 00                   77 	.byte	0
   07BC A0                   78 	.byte	-96
   07BD B0                   79 	.byte	-80
   07BE FF                   80 	.byte	-1
   07BF 00                   81 	.byte	0
   07C0 B0                   82 	.byte	-80
   07C1 FF                   83 	.byte	-1
   07C2 7F                   84 	.byte	127
   07C3 00                   85 	.byte	0
   07C4 FF                   86 	.byte	-1
   07C5 00                   87 	.byte	0
   07C6 50                   88 	.byte	80
   07C7 FF                   89 	.byte	-1
   07C8 80                   90 	.byte	-128
   07C9 00                   91 	.byte	0
   07CA 00                   92 	.byte	0
   07CB 10                   93 	.byte	16
   07CC 00                   94 	.byte	0
   07CD FF                   95 	.byte	-1
   07CE 10                   96 	.byte	16
   07CF 3C                   97 	.byte	60
   07D0 00                   98 	.byte	0
   07D1 00                   99 	.byte	0
   07D2 28                  100 	.byte	40
   07D3 FF                  101 	.byte	-1
   07D4 F0                  102 	.byte	-16
   07D5 3C                  103 	.byte	60
   07D6 00                  104 	.byte	0
   07D7 F0                  105 	.byte	-16
   07D8 00                  106 	.byte	0
   07D9 FF                  107 	.byte	-1
   07DA 00                  108 	.byte	0
   07DB 50                  109 	.byte	80
   07DC FF                  110 	.byte	-1
   07DD 7F                  111 	.byte	127
   07DE 00                  112 	.byte	0
   07DF FF                  113 	.byte	-1
   07E0 00                  114 	.byte	0
   07E1 B0                  115 	.byte	-80
   07E2 FF                  116 	.byte	-1
   07E3 80                  117 	.byte	-128
   07E4 00                  118 	.byte	0
   07E5 00                  119 	.byte	0
   07E6 20                  120 	.byte	32
   07E7 00                  121 	.byte	0
   07E8 FF                  122 	.byte	-1
   07E9 00                  123 	.byte	0
   07EA B0                  124 	.byte	-80
   07EB FF                  125 	.byte	-1
   07EC 00                  126 	.byte	0
   07ED B0                  127 	.byte	-80
   07EE 00                  128 	.byte	0
   07EF 40                  129 	.byte	64
   07F0 00                  130 	.byte	0
   07F1 FF                  131 	.byte	-1
   07F2 10                  132 	.byte	16
   07F3 3C                  133 	.byte	60
   07F4 FF                  134 	.byte	-1
   07F5 00                  135 	.byte	0
   07F6 28                  136 	.byte	40
   07F7 FF                  137 	.byte	-1
   07F8 F0                  138 	.byte	-16
   07F9 3C                  139 	.byte	60
   07FA FF                  140 	.byte	-1
   07FB 70                  141 	.byte	112
   07FC C0                  142 	.byte	-64
   07FD FF                  143 	.byte	-1
   07FE 00                  144 	.byte	0
   07FF E0                  145 	.byte	-32
   0800 00                  146 	.byte	0
   0801 E4                  147 	.byte	-28
   0802 30                  148 	.byte	48
   0803 FF                  149 	.byte	-1
   0804 00                  150 	.byte	0
   0805 30                  151 	.byte	48
   0806 FF                  152 	.byte	-1
   0807 10                  153 	.byte	16
   0808 F8                  154 	.byte	-8
   0809 FF                  155 	.byte	-1
   080A 00                  156 	.byte	0
   080B D0                  157 	.byte	-48
   080C 00                  158 	.byte	0
   080D 00                  159 	.byte	0
   080E D0                  160 	.byte	-48
   080F FF                  161 	.byte	-1
   0810 00                  162 	.byte	0
   0811 D0                  163 	.byte	-48
   0812 FF                  164 	.byte	-1
   0813 F0                  165 	.byte	-16
   0814 F8                  166 	.byte	-8
   0815 FF                  167 	.byte	-1
   0816 00                  168 	.byte	0
   0817 30                  169 	.byte	48
   0818 00                  170 	.byte	0
   0819 1C                  171 	.byte	28
   081A 10                  172 	.byte	16
   081B FF                  173 	.byte	-1
   081C 90                  174 	.byte	-112
   081D C0                  175 	.byte	-64
   081E 00                  176 	.byte	0
   081F 20                  177 	.byte	32
   0820 D8                  178 	.byte	-40
   0821 FF                  179 	.byte	-1
   0822 28                  180 	.byte	40
   0823 00                  181 	.byte	0
   0824 FF                  182 	.byte	-1
   0825 00                  183 	.byte	0
   0826 3C                  184 	.byte	60
   0827 FF                  185 	.byte	-1
   0828 DC                  186 	.byte	-36
   0829 00                  187 	.byte	0
   082A 00                  188 	.byte	0
   082B 00                  189 	.byte	0
   082C 78                  190 	.byte	120
   082D FF                  191 	.byte	-1
   082E 24                  192 	.byte	36
   082F 00                  193 	.byte	0
   0830 FF                  194 	.byte	-1
   0831 00                  195 	.byte	0
   0832 3C                  196 	.byte	60
   0833 FF                  197 	.byte	-1
   0834 D8                  198 	.byte	-40
   0835 00                  199 	.byte	0
   0836 00                  200 	.byte	0
   0837 14                  201 	.byte	20
   0838 9C                  202 	.byte	-100
   0839 FF                  203 	.byte	-1
   083A 10                  204 	.byte	16
   083B F8                  205 	.byte	-8
   083C FF                  206 	.byte	-1
   083D 00                  207 	.byte	0
   083E E8                  208 	.byte	-24
   083F FF                  209 	.byte	-1
   0840 F0                  210 	.byte	-16
   0841 F8                  211 	.byte	-8
   0842                     212 _vl_term_0_76:
   0842 01                  213 	.byte	1
                            214 	.globl	_vl_player_left
   0843                     215 _vl_player_left:
   0843 00                  216 	.byte	0
   0844 0C                  217 	.byte	12
   0845 78                  218 	.byte	120
   0846 FF                  219 	.byte	-1
   0847 88                  220 	.byte	-120
   0848 00                  221 	.byte	0
   0849 FF                  222 	.byte	-1
   084A DC                  223 	.byte	-36
   084B 18                  224 	.byte	24
   084C FF                  225 	.byte	-1
   084D 00                  226 	.byte	0
   084E 78                  227 	.byte	120
   084F FF                  228 	.byte	-1
   0850 24                  229 	.byte	36
   0851 18                  230 	.byte	24
   0852 FF                  231 	.byte	-1
   0853 78                  232 	.byte	120
   0854 00                  233 	.byte	0
   0855 FF                  234 	.byte	-1
   0856 24                  235 	.byte	36
   0857 E8                  236 	.byte	-24
   0858 FF                  237 	.byte	-1
   0859 00                  238 	.byte	0
   085A 88                  239 	.byte	-120
   085B FF                  240 	.byte	-1
   085C DC                  241 	.byte	-36
   085D E8                  242 	.byte	-24
   085E 00                  243 	.byte	0
   085F F4                  244 	.byte	-12
   0860 00                  245 	.byte	0
   0861 FF                  246 	.byte	-1
   0862 18                  247 	.byte	24
   0863 A6                  248 	.byte	-90
   0864 FF                  249 	.byte	-1
   0865 00                  250 	.byte	0
   0866 C4                  251 	.byte	-60
   0867 FF                  252 	.byte	-1
   0868 E8                  253 	.byte	-24
   0869 A6                  254 	.byte	-90
   086A 00                  255 	.byte	0
   086B 0C                  256 	.byte	12
   086C 00                  257 	.byte	0
   086D FF                  258 	.byte	-1
   086E 88                  259 	.byte	-120
   086F 00                  260 	.byte	0
   0870 FF                  261 	.byte	-1
   0871 DC                  262 	.byte	-36
   0872 18                  263 	.byte	24
   0873 FF                  264 	.byte	-1
   0874 24                  265 	.byte	36
   0875 18                  266 	.byte	24
   0876 FF                  267 	.byte	-1
   0877 0C                  268 	.byte	12
   0878 00                  269 	.byte	0
   0879 00                  270 	.byte	0
   087A E8                  271 	.byte	-24
   087B DC                  272 	.byte	-36
   087C FF                  273 	.byte	-1
   087D 18                  274 	.byte	24
   087E 4E                  275 	.byte	78
   087F 00                  276 	.byte	0
   0880 00                  277 	.byte	0
   0881 A6                  278 	.byte	-90
   0882 FF                  279 	.byte	-1
   0883 00                  280 	.byte	0
   0884 78                  281 	.byte	120
   0885 FF                  282 	.byte	-1
   0886 00                  283 	.byte	0
   0887 78                  284 	.byte	120
   0888 00                  285 	.byte	0
   0889 00                  286 	.byte	0
   088A A6                  287 	.byte	-90
   088B FF                  288 	.byte	-1
   088C E8                  289 	.byte	-24
   088D 60                  290 	.byte	96
   088E 00                  291 	.byte	0
   088F F4                  292 	.byte	-12
   0890 45                  293 	.byte	69
   0891 00                  294 	.byte	0
   0892 F4                  295 	.byte	-12
   0893 45                  296 	.byte	69
   0894 FF                  297 	.byte	-1
   0895 24                  298 	.byte	36
   0896 E8                  299 	.byte	-24
   0897 FF                  300 	.byte	-1
   0898 78                  301 	.byte	120
   0899 00                  302 	.byte	0
   089A FF                  303 	.byte	-1
   089B 24                  304 	.byte	36
   089C 18                  305 	.byte	24
   089D 00                  306 	.byte	0
   089E D0                  307 	.byte	-48
   089F 18                  308 	.byte	24
   08A0 FF                  309 	.byte	-1
   08A1 00                  310 	.byte	0
   08A2 1E                  311 	.byte	30
   08A3 FF                  312 	.byte	-1
   08A4 18                  313 	.byte	24
   08A5 0C                  314 	.byte	12
   08A6 FF                  315 	.byte	-1
   08A7 54                  316 	.byte	84
   08A8 00                  317 	.byte	0
   08A9 FF                  318 	.byte	-1
   08AA 18                  319 	.byte	24
   08AB F4                  320 	.byte	-12
   08AC FF                  321 	.byte	-1
   08AD E8                  322 	.byte	-24
   08AE F4                  323 	.byte	-12
   08AF FF                  324 	.byte	-1
   08B0 AC                  325 	.byte	-84
   08B1 00                  326 	.byte	0
   08B2 FF                  327 	.byte	-1
   08B3 E8                  328 	.byte	-24
   08B4 0C                  329 	.byte	12
   08B5 00                  330 	.byte	0
   08B6 45                  331 	.byte	69
   08B7 00                  332 	.byte	0
   08B8 00                  333 	.byte	0
   08B9 45                  334 	.byte	69
   08BA 00                  335 	.byte	0
   08BB FF                  336 	.byte	-1
   08BC 00                  337 	.byte	0
   08BD 94                  338 	.byte	-108
   08BE FF                  339 	.byte	-1
   08BF E8                  340 	.byte	-24
   08C0 F4                  341 	.byte	-12
   08C1 FF                  342 	.byte	-1
   08C2 C4                  343 	.byte	-60
   08C3 00                  344 	.byte	0
   08C4 00                  345 	.byte	0
   08C5 00                  346 	.byte	0
   08C6 E2                  347 	.byte	-30
   08C7 FF                  348 	.byte	-1
   08C8 2A                  349 	.byte	42
   08C9 1E                  350 	.byte	30
   08CA 00                  351 	.byte	0
   08CB 2A                  352 	.byte	42
   08CC 18                  353 	.byte	24
   08CD FF                  354 	.byte	-1
   08CE 3C                  355 	.byte	60
   08CF 2A                  356 	.byte	42
   08D0 00                  357 	.byte	0
   08D1 F4                  358 	.byte	-12
   08D2 F4                  359 	.byte	-12
   08D3 FF                  360 	.byte	-1
   08D4 00                  361 	.byte	0
   08D5 30                  362 	.byte	48
   08D6 FF                  363 	.byte	-1
   08D7 E8                  364 	.byte	-24
   08D8 F4                  365 	.byte	-12
   08D9 FF                  366 	.byte	-1
   08DA 00                  367 	.byte	0
   08DB D0                  368 	.byte	-48
   08DC 00                  369 	.byte	0
   08DD 24                  370 	.byte	36
   08DE 18                  371 	.byte	24
   08DF FF                  372 	.byte	-1
   08E0 00                  373 	.byte	0
   08E1 C4                  374 	.byte	-60
   08E2 00                  375 	.byte	0
   08E3 F4                  376 	.byte	-12
   08E4 EE                  377 	.byte	-18
   08E5 FF                  378 	.byte	-1
   08E6 00                  379 	.byte	0
   08E7 D0                  380 	.byte	-48
   08E8 FF                  381 	.byte	-1
   08E9 E8                  382 	.byte	-24
   08EA DC                  383 	.byte	-36
   08EB FF                  384 	.byte	-1
   08EC 00                  385 	.byte	0
   08ED 2A                  386 	.byte	42
   08EE 00                  387 	.byte	0
   08EF 24                  388 	.byte	36
   08F0 3C                  389 	.byte	60
   08F1 FF                  390 	.byte	-1
   08F2 C0                  391 	.byte	-64
   08F3 94                  392 	.byte	-108
   08F4 FF                  393 	.byte	-1
   08F5 C0                  394 	.byte	-64
   08F6 94                  395 	.byte	-108
   08F7 FF                  396 	.byte	-1
   08F8 C0                  397 	.byte	-64
   08F9 94                  398 	.byte	-108
   08FA 00                  399 	.byte	0
   08FB 0C                  400 	.byte	12
   08FC 00                  401 	.byte	0
   08FD FF                  402 	.byte	-1
   08FE 24                  403 	.byte	36
   08FF 18                  404 	.byte	24
   0900 FF                  405 	.byte	-1
   0901 E8                  406 	.byte	-24
   0902 12                  407 	.byte	18
   0903 00                  408 	.byte	0
   0904 AC                  409 	.byte	-84
   0905 F7                  410 	.byte	-9
   0906 00                  411 	.byte	0
   0907 AC                  412 	.byte	-84
   0908 F7                  413 	.byte	-9
   0909 FF                  414 	.byte	-1
   090A 00                  415 	.byte	0
   090B 88                  416 	.byte	-120
   090C FF                  417 	.byte	-1
   090D 24                  418 	.byte	36
   090E E8                  419 	.byte	-24
   090F FF                  420 	.byte	-1
   0910 78                  421 	.byte	120
   0911 00                  422 	.byte	0
   0912 FF                  423 	.byte	-1
   0913 24                  424 	.byte	36
   0914 18                  425 	.byte	24
   0915 FF                  426 	.byte	-1
   0916 00                  427 	.byte	0
   0917 78                  428 	.byte	120
   0918 00                  429 	.byte	0
   0919 FA                  430 	.byte	-6
   091A 2A                  431 	.byte	42
   091B FF                  432 	.byte	-1
   091C 48                  433 	.byte	72
   091D 00                  434 	.byte	0
   091E FF                  435 	.byte	-1
   091F 18                  436 	.byte	24
   0920 0C                  437 	.byte	12
   0921 FF                  438 	.byte	-1
   0922 00                  439 	.byte	0
   0923 6C                  440 	.byte	108
   0924 FF                  441 	.byte	-1
   0925 E8                  442 	.byte	-24
   0926 F4                  443 	.byte	-12
   0927 FF                  444 	.byte	-1
   0928 F4                  445 	.byte	-12
   0929 00                  446 	.byte	0
   092A 00                  447 	.byte	0
   092B 24                  448 	.byte	36
   092C 0C                  449 	.byte	12
   092D FF                  450 	.byte	-1
   092E EE                  451 	.byte	-18
   092F 0C                  452 	.byte	12
   0930 00                  453 	.byte	0
   0931 CA                  454 	.byte	-54
   0932 E2                  455 	.byte	-30
   0933 FF                  456 	.byte	-1
   0934 24                  457 	.byte	36
   0935 42                  458 	.byte	66
   0936 FF                  459 	.byte	-1
   0937 00                  460 	.byte	0
   0938 2A                  461 	.byte	42
   0939 FF                  462 	.byte	-1
   093A DC                  463 	.byte	-36
   093B E8                  464 	.byte	-24
   093C                     465 _vl_term_1_189:
   093C 01                  466 	.byte	1
                            467 	.globl	_vl_player_right
   093D                     468 _vl_player_right:
   093D 00                  469 	.byte	0
   093E 0C                  470 	.byte	12
   093F 88                  471 	.byte	-120
   0940 FF                  472 	.byte	-1
   0941 88                  473 	.byte	-120
   0942 00                  474 	.byte	0
   0943 FF                  475 	.byte	-1
   0944 DC                  476 	.byte	-36
   0945 E8                  477 	.byte	-24
   0946 FF                  478 	.byte	-1
   0947 00                  479 	.byte	0
   0948 88                  480 	.byte	-120
   0949 FF                  481 	.byte	-1
   094A 24                  482 	.byte	36
   094B E8                  483 	.byte	-24
   094C FF                  484 	.byte	-1
   094D 78                  485 	.byte	120
   094E 00                  486 	.byte	0
   094F FF                  487 	.byte	-1
   0950 24                  488 	.byte	36
   0951 18                  489 	.byte	24
   0952 FF                  490 	.byte	-1
   0953 00                  491 	.byte	0
   0954 78                  492 	.byte	120
   0955 FF                  493 	.byte	-1
   0956 DC                  494 	.byte	-36
   0957 18                  495 	.byte	24
   0958 00                  496 	.byte	0
   0959 F4                  497 	.byte	-12
   095A 00                  498 	.byte	0
   095B FF                  499 	.byte	-1
   095C 18                  500 	.byte	24
   095D 5A                  501 	.byte	90
   095E FF                  502 	.byte	-1
   095F 00                  503 	.byte	0
   0960 3C                  504 	.byte	60
   0961 FF                  505 	.byte	-1
   0962 E8                  506 	.byte	-24
   0963 5A                  507 	.byte	90
   0964 00                  508 	.byte	0
   0965 0C                  509 	.byte	12
   0966 00                  510 	.byte	0
   0967 FF                  511 	.byte	-1
   0968 88                  512 	.byte	-120
   0969 00                  513 	.byte	0
   096A FF                  514 	.byte	-1
   096B DC                  515 	.byte	-36
   096C E8                  516 	.byte	-24
   096D FF                  517 	.byte	-1
   096E 24                  518 	.byte	36
   096F E8                  519 	.byte	-24
   0970 FF                  520 	.byte	-1
   0971 0C                  521 	.byte	12
   0972 00                  522 	.byte	0
   0973 00                  523 	.byte	0
   0974 E8                  524 	.byte	-24
   0975 24                  525 	.byte	36
   0976 FF                  526 	.byte	-1
   0977 18                  527 	.byte	24
   0978 B2                  528 	.byte	-78
   0979 00                  529 	.byte	0
   097A 00                  530 	.byte	0
   097B 5A                  531 	.byte	90
   097C FF                  532 	.byte	-1
   097D 00                  533 	.byte	0
   097E 88                  534 	.byte	-120
   097F FF                  535 	.byte	-1
   0980 00                  536 	.byte	0
   0981 88                  537 	.byte	-120
   0982 00                  538 	.byte	0
   0983 00                  539 	.byte	0
   0984 5A                  540 	.byte	90
   0985 FF                  541 	.byte	-1
   0986 E8                  542 	.byte	-24
   0987 A0                  543 	.byte	-96
   0988 00                  544 	.byte	0
   0989 F4                  545 	.byte	-12
   098A BB                  546 	.byte	-69
   098B 00                  547 	.byte	0
   098C F4                  548 	.byte	-12
   098D BB                  549 	.byte	-69
   098E FF                  550 	.byte	-1
   098F 24                  551 	.byte	36
   0990 18                  552 	.byte	24
   0991 FF                  553 	.byte	-1
   0992 78                  554 	.byte	120
   0993 00                  555 	.byte	0
   0994 FF                  556 	.byte	-1
   0995 24                  557 	.byte	36
   0996 E8                  558 	.byte	-24
   0997 00                  559 	.byte	0
   0998 D0                  560 	.byte	-48
   0999 E8                  561 	.byte	-24
   099A FF                  562 	.byte	-1
   099B 00                  563 	.byte	0
   099C E2                  564 	.byte	-30
   099D FF                  565 	.byte	-1
   099E 18                  566 	.byte	24
   099F F4                  567 	.byte	-12
   09A0 FF                  568 	.byte	-1
   09A1 54                  569 	.byte	84
   09A2 00                  570 	.byte	0
   09A3 FF                  571 	.byte	-1
   09A4 18                  572 	.byte	24
   09A5 0C                  573 	.byte	12
   09A6 FF                  574 	.byte	-1
   09A7 E8                  575 	.byte	-24
   09A8 0C                  576 	.byte	12
   09A9 FF                  577 	.byte	-1
   09AA AC                  578 	.byte	-84
   09AB 00                  579 	.byte	0
   09AC FF                  580 	.byte	-1
   09AD E8                  581 	.byte	-24
   09AE F4                  582 	.byte	-12
   09AF 00                  583 	.byte	0
   09B0 45                  584 	.byte	69
   09B1 00                  585 	.byte	0
   09B2 00                  586 	.byte	0
   09B3 45                  587 	.byte	69
   09B4 00                  588 	.byte	0
   09B5 FF                  589 	.byte	-1
   09B6 00                  590 	.byte	0
   09B7 6C                  591 	.byte	108
   09B8 FF                  592 	.byte	-1
   09B9 E8                  593 	.byte	-24
   09BA 0C                  594 	.byte	12
   09BB FF                  595 	.byte	-1
   09BC C4                  596 	.byte	-60
   09BD 00                  597 	.byte	0
   09BE 00                  598 	.byte	0
   09BF 00                  599 	.byte	0
   09C0 1E                  600 	.byte	30
   09C1 FF                  601 	.byte	-1
   09C2 2A                  602 	.byte	42
   09C3 E2                  603 	.byte	-30
   09C4 00                  604 	.byte	0
   09C5 2A                  605 	.byte	42
   09C6 E8                  606 	.byte	-24
   09C7 FF                  607 	.byte	-1
   09C8 3C                  608 	.byte	60
   09C9 D6                  609 	.byte	-42
   09CA 00                  610 	.byte	0
   09CB F4                  611 	.byte	-12
   09CC 0C                  612 	.byte	12
   09CD FF                  613 	.byte	-1
   09CE 00                  614 	.byte	0
   09CF D0                  615 	.byte	-48
   09D0 FF                  616 	.byte	-1
   09D1 E8                  617 	.byte	-24
   09D2 0C                  618 	.byte	12
   09D3 FF                  619 	.byte	-1
   09D4 00                  620 	.byte	0
   09D5 30                  621 	.byte	48
   09D6 00                  622 	.byte	0
   09D7 24                  623 	.byte	36
   09D8 E8                  624 	.byte	-24
   09D9 FF                  625 	.byte	-1
   09DA 00                  626 	.byte	0
   09DB 3C                  627 	.byte	60
   09DC 00                  628 	.byte	0
   09DD F4                  629 	.byte	-12
   09DE 12                  630 	.byte	18
   09DF FF                  631 	.byte	-1
   09E0 00                  632 	.byte	0
   09E1 30                  633 	.byte	48
   09E2 FF                  634 	.byte	-1
   09E3 E8                  635 	.byte	-24
   09E4 24                  636 	.byte	36
   09E5 FF                  637 	.byte	-1
   09E6 00                  638 	.byte	0
   09E7 D6                  639 	.byte	-42
   09E8 00                  640 	.byte	0
   09E9 24                  641 	.byte	36
   09EA C4                  642 	.byte	-60
   09EB FF                  643 	.byte	-1
   09EC C0                  644 	.byte	-64
   09ED 6C                  645 	.byte	108
   09EE FF                  646 	.byte	-1
   09EF C0                  647 	.byte	-64
   09F0 6C                  648 	.byte	108
   09F1 FF                  649 	.byte	-1
   09F2 C0                  650 	.byte	-64
   09F3 6C                  651 	.byte	108
   09F4 00                  652 	.byte	0
   09F5 0C                  653 	.byte	12
   09F6 00                  654 	.byte	0
   09F7 FF                  655 	.byte	-1
   09F8 24                  656 	.byte	36
   09F9 E8                  657 	.byte	-24
   09FA FF                  658 	.byte	-1
   09FB E8                  659 	.byte	-24
   09FC EE                  660 	.byte	-18
   09FD 00                  661 	.byte	0
   09FE AC                  662 	.byte	-84
   09FF 09                  663 	.byte	9
   0A00 00                  664 	.byte	0
   0A01 AC                  665 	.byte	-84
   0A02 09                  666 	.byte	9
   0A03 FF                  667 	.byte	-1
   0A04 00                  668 	.byte	0
   0A05 78                  669 	.byte	120
   0A06 FF                  670 	.byte	-1
   0A07 24                  671 	.byte	36
   0A08 18                  672 	.byte	24
   0A09 FF                  673 	.byte	-1
   0A0A 78                  674 	.byte	120
   0A0B 00                  675 	.byte	0
   0A0C FF                  676 	.byte	-1
   0A0D 24                  677 	.byte	36
   0A0E E8                  678 	.byte	-24
   0A0F FF                  679 	.byte	-1
   0A10 00                  680 	.byte	0
   0A11 88                  681 	.byte	-120
   0A12 00                  682 	.byte	0
   0A13 FA                  683 	.byte	-6
   0A14 D6                  684 	.byte	-42
   0A15 FF                  685 	.byte	-1
   0A16 48                  686 	.byte	72
   0A17 00                  687 	.byte	0
   0A18 FF                  688 	.byte	-1
   0A19 18                  689 	.byte	24
   0A1A F4                  690 	.byte	-12
   0A1B FF                  691 	.byte	-1
   0A1C 00                  692 	.byte	0
   0A1D 94                  693 	.byte	-108
   0A1E FF                  694 	.byte	-1
   0A1F E8                  695 	.byte	-24
   0A20 0C                  696 	.byte	12
   0A21 FF                  697 	.byte	-1
   0A22 F4                  698 	.byte	-12
   0A23 00                  699 	.byte	0
   0A24 00                  700 	.byte	0
   0A25 24                  701 	.byte	36
   0A26 F4                  702 	.byte	-12
   0A27 FF                  703 	.byte	-1
   0A28 EE                  704 	.byte	-18
   0A29 F4                  705 	.byte	-12
   0A2A 00                  706 	.byte	0
   0A2B CA                  707 	.byte	-54
   0A2C 1E                  708 	.byte	30
   0A2D FF                  709 	.byte	-1
   0A2E 24                  710 	.byte	36
   0A2F BE                  711 	.byte	-66
   0A30 FF                  712 	.byte	-1
   0A31 00                  713 	.byte	0
   0A32 D6                  714 	.byte	-42
   0A33 FF                  715 	.byte	-1
   0A34 DC                  716 	.byte	-36
   0A35 18                  717 	.byte	24
   0A36                     718 _vl_term_2_302:
   0A36 01                  719 	.byte	1
                            720 	.globl	__player_draw_left
   0A37                     721 __player_draw_left:
   0A37 C6 0A         [ 2]  722 	ldb	#10
   0A39 D7 04         [ 4]  723 	stb	*_dp_VIA_t1_cnt_lo
   0A3B 8E 08 43      [ 3]  724 	ldx	#_vl_player_left
   0A3E 7E F4 10      [ 4]  725 	jmp	___Draw_VLp
                            726 	.globl	__player_draw_mid
   0A41                     727 __player_draw_mid:
   0A41 C6 10         [ 2]  728 	ldb	#16
   0A43 D7 04         [ 4]  729 	stb	*_dp_VIA_t1_cnt_lo
   0A45 8E 07 BB      [ 3]  730 	ldx	#_vl_player_mid
   0A48 7E F4 10      [ 4]  731 	jmp	___Draw_VLp
                            732 	.globl	__player_draw_right
   0A4B                     733 __player_draw_right:
   0A4B C6 0A         [ 2]  734 	ldb	#10
   0A4D D7 04         [ 4]  735 	stb	*_dp_VIA_t1_cnt_lo
   0A4F 8E 09 3D      [ 3]  736 	ldx	#_vl_player_right
   0A52 7E F4 10      [ 4]  737 	jmp	___Draw_VLp
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Jun 13 20:17:37 2025

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
Hexadecimal [16-Bits]                                 Fri Jun 13 20:17:37 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    4   flags    0
   3 .text            size  307   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

