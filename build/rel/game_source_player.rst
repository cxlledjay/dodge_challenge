                              1 ;;; gcc for m6809 : Mar 17 2019 13:25:32
                              2 ;;; 4.3.6 (gcc6809)
                              3 ;;; ABI version 1
                              4 ;;; -mabi=bx -mint8 -fomit-frame-pointer -O2
                              5 	.module	player.c
                              6 	.area	.bss
                              7 	.globl	_the_player
   C8AA                       8 _the_player:	.blkb	4
                              9 	.globl	_PLAYER_ANIMATION_FRAME_CNT_LUT
                             10 	.area	.text
   0772                      11 _PLAYER_ANIMATION_FRAME_CNT_LUT:
   0772 0E                   12 	.byte	14
   0773 0E                   13 	.byte	14
   0774 0E                   14 	.byte	14
   0775 0B                   15 	.byte	11
   0776 0B                   16 	.byte	11
   0777 0B                   17 	.byte	11
   0778 08                   18 	.byte	8
   0779 08                   19 	.byte	8
   077A 05                   20 	.byte	5
   077B 05                   21 	.byte	5
   077C 02                   22 	.byte	2
                             23 	.globl	_PLAYER_ANIMATION_FRAME_CNT_HALFED_LUT
   077D                      24 _PLAYER_ANIMATION_FRAME_CNT_HALFED_LUT:
   077D 07                   25 	.byte	7
   077E 07                   26 	.byte	7
   077F 07                   27 	.byte	7
   0780 06                   28 	.byte	6
   0781 06                   29 	.byte	6
   0782 06                   30 	.byte	6
   0783 04                   31 	.byte	4
   0784 04                   32 	.byte	4
   0785 03                   33 	.byte	3
   0786 03                   34 	.byte	3
   0787 01                   35 	.byte	1
                             36 	.globl	_PLAYER_STATIC_X_LUT
   0788                      37 _PLAYER_STATIC_X_LUT:
   0788 AE                   38 	.byte	-82
   0789 00                   39 	.byte	0
   078A 52                   40 	.byte	82
                             41 	.globl	_PLAYER_DRAW_LUT
   078B                      42 _PLAYER_DRAW_LUT:
   078B 0D D6                43 	.word	__player_draw_left
   078D 0D 90                44 	.word	__player_draw_mid
   078F 0E 3E                45 	.word	__player_draw_right
                             46 	.globl	_SP1_MID_LEFT_X_LUT
   0791                      47 _SP1_MID_LEFT_X_LUT:
   0791 B4                   48 	.byte	-76
   0792 BA                   49 	.byte	-70
   0793 C0                   50 	.byte	-64
   0794 C5                   51 	.byte	-59
   0795 CB                   52 	.byte	-53
   0796 D1                   53 	.byte	-47
   0797 D7                   54 	.byte	-41
   0798 DD                   55 	.byte	-35
   0799 E3                   56 	.byte	-29
   079A E9                   57 	.byte	-23
   079B EE                   58 	.byte	-18
   079C F4                   59 	.byte	-12
   079D FA                   60 	.byte	-6
                             61 	.globl	_SP1_RIGHT_MID_X_LUT
   079E                      62 _SP1_RIGHT_MID_X_LUT:
   079E 06                   63 	.byte	6
   079F 0C                   64 	.byte	12
   07A0 12                   65 	.byte	18
   07A1 17                   66 	.byte	23
   07A2 1D                   67 	.byte	29
   07A3 23                   68 	.byte	35
   07A4 29                   69 	.byte	41
   07A5 2F                   70 	.byte	47
   07A6 35                   71 	.byte	53
   07A7 3B                   72 	.byte	59
   07A8 40                   73 	.byte	64
   07A9 46                   74 	.byte	70
   07AA 4C                   75 	.byte	76
                             76 	.globl	_SP1_MID_RIGHT_X_LUT
   07AB                      77 _SP1_MID_RIGHT_X_LUT:
   07AB 4C                   78 	.byte	76
   07AC 46                   79 	.byte	70
   07AD 40                   80 	.byte	64
   07AE 3B                   81 	.byte	59
   07AF 35                   82 	.byte	53
   07B0 2F                   83 	.byte	47
   07B1 29                   84 	.byte	41
   07B2 23                   85 	.byte	35
   07B3 1D                   86 	.byte	29
   07B4 17                   87 	.byte	23
   07B5 12                   88 	.byte	18
   07B6 0C                   89 	.byte	12
   07B7 06                   90 	.byte	6
                             91 	.globl	_SP1_LEFT_MID_X_LUT
   07B8                      92 _SP1_LEFT_MID_X_LUT:
   07B8 FA                   93 	.byte	-6
   07B9 F4                   94 	.byte	-12
   07BA EE                   95 	.byte	-18
   07BB E9                   96 	.byte	-23
   07BC E3                   97 	.byte	-29
   07BD DD                   98 	.byte	-35
   07BE D7                   99 	.byte	-41
   07BF D1                  100 	.byte	-47
   07C0 CB                  101 	.byte	-53
   07C1 C5                  102 	.byte	-59
   07C2 C0                  103 	.byte	-64
   07C3 BA                  104 	.byte	-70
   07C4 B4                  105 	.byte	-76
                            106 	.globl	_player_init
   07C5                     107 _player_init:
   07C5 8E 07 D4      [ 3]  108 	ldx	#_player_draw
   07C8 BF C8 AC      [ 6]  109 	stx	_the_player+2
   07CB 7F C8 AB      [ 7]  110 	clr	_the_player+1
   07CE C6 01         [ 2]  111 	ldb	#1
   07D0 F7 C8 AA      [ 5]  112 	stb	_the_player
   07D3 39            [ 5]  113 	rts
                            114 	.globl	_player_draw
   07D4                     115 _player_draw:
   07D4 32 7E         [ 5]  116 	leas	-2,s
   07D6 BD F2 A5      [ 8]  117 	jsr	___Intensity_5F
   07D9 F6 C8 AA      [ 5]  118 	ldb	_the_player
   07DC 4F            [ 2]  119 	clra		;zero_extendqihi: R:b -> R:d
   07DD ED E4         [ 5]  120 	std	,s
   07DF 58            [ 2]  121 	aslb
   07E0 49            [ 2]  122 	rola
   07E1 1F 01         [ 6]  123 	tfr	d,x
   07E3 AD 99 07 8B   [14]  124 	jsr	[_PLAYER_DRAW_LUT,x]
   07E7 32 62         [ 5]  125 	leas	2,s
   07E9 39            [ 5]  126 	rts
                            127 	.globl	_vl_player_mid1
   07EA                     128 _vl_player_mid1:
   07EA 00                  129 	.byte	0
   07EB A0                  130 	.byte	-96
   07EC B0                  131 	.byte	-80
   07ED FF                  132 	.byte	-1
   07EE 00                  133 	.byte	0
   07EF B0                  134 	.byte	-80
   07F0 FF                  135 	.byte	-1
   07F1 7F                  136 	.byte	127
   07F2 00                  137 	.byte	0
   07F3 FF                  138 	.byte	-1
   07F4 00                  139 	.byte	0
   07F5 50                  140 	.byte	80
   07F6 FF                  141 	.byte	-1
   07F7 80                  142 	.byte	-128
   07F8 00                  143 	.byte	0
   07F9 00                  144 	.byte	0
   07FA 10                  145 	.byte	16
   07FB 00                  146 	.byte	0
   07FC FF                  147 	.byte	-1
   07FD 10                  148 	.byte	16
   07FE 3C                  149 	.byte	60
   07FF 00                  150 	.byte	0
   0800 00                  151 	.byte	0
   0801 28                  152 	.byte	40
   0802 FF                  153 	.byte	-1
   0803 F0                  154 	.byte	-16
   0804 3C                  155 	.byte	60
   0805 00                  156 	.byte	0
   0806 F0                  157 	.byte	-16
   0807 00                  158 	.byte	0
   0808 FF                  159 	.byte	-1
   0809 00                  160 	.byte	0
   080A 50                  161 	.byte	80
   080B FF                  162 	.byte	-1
   080C 7F                  163 	.byte	127
   080D 00                  164 	.byte	0
   080E FF                  165 	.byte	-1
   080F 00                  166 	.byte	0
   0810 B0                  167 	.byte	-80
   0811 FF                  168 	.byte	-1
   0812 80                  169 	.byte	-128
   0813 00                  170 	.byte	0
   0814 00                  171 	.byte	0
   0815 20                  172 	.byte	32
   0816 00                  173 	.byte	0
   0817 FF                  174 	.byte	-1
   0818 00                  175 	.byte	0
   0819 B0                  176 	.byte	-80
   081A FF                  177 	.byte	-1
   081B 00                  178 	.byte	0
   081C B0                  179 	.byte	-80
   081D 00                  180 	.byte	0
   081E 40                  181 	.byte	64
   081F 00                  182 	.byte	0
   0820 FF                  183 	.byte	-1
   0821 10                  184 	.byte	16
   0822 3C                  185 	.byte	60
   0823 FF                  186 	.byte	-1
   0824 00                  187 	.byte	0
   0825 28                  188 	.byte	40
   0826 FF                  189 	.byte	-1
   0827 F0                  190 	.byte	-16
   0828 3C                  191 	.byte	60
   0829                     192 _vl_term_0_46:
   0829 01                  193 	.byte	1
                            194 	.globl	_vl_player_mid2
   082A                     195 _vl_player_mid2:
   082A 00                  196 	.byte	0
   082B 20                  197 	.byte	32
   082C 88                  198 	.byte	-120
   082D FF                  199 	.byte	-1
   082E 28                  200 	.byte	40
   082F 00                  201 	.byte	0
   0830 FF                  202 	.byte	-1
   0831 00                  203 	.byte	0
   0832 3C                  204 	.byte	60
   0833 FF                  205 	.byte	-1
   0834 DC                  206 	.byte	-36
   0835 00                  207 	.byte	0
   0836 00                  208 	.byte	0
   0837 E0                  209 	.byte	-32
   0838 EC                  210 	.byte	-20
   0839 FF                  211 	.byte	-1
   083A 70                  212 	.byte	112
   083B 40                  213 	.byte	64
   083C FF                  214 	.byte	-1
   083D 00                  215 	.byte	0
   083E 20                  216 	.byte	32
   083F FF                  217 	.byte	-1
   0840 90                  218 	.byte	-112
   0841 40                  219 	.byte	64
   0842 00                  220 	.byte	0
   0843 20                  221 	.byte	32
   0844 28                  222 	.byte	40
   0845 FF                  223 	.byte	-1
   0846 28                  224 	.byte	40
   0847 00                  225 	.byte	0
   0848 FF                  226 	.byte	-1
   0849 00                  227 	.byte	0
   084A C4                  228 	.byte	-60
   084B FF                  229 	.byte	-1
   084C DC                  230 	.byte	-36
   084D 00                  231 	.byte	0
   084E 00                  232 	.byte	0
   084F 2D                  233 	.byte	45
   0850 E4                  234 	.byte	-28
   0851 FF                  235 	.byte	-1
   0852 00                  236 	.byte	0
   0853 30                  237 	.byte	48
   0854 FF                  238 	.byte	-1
   0855 10                  239 	.byte	16
   0856 F8                  240 	.byte	-8
   0857 FF                  241 	.byte	-1
   0858 00                  242 	.byte	0
   0859 D0                  243 	.byte	-48
   085A 00                  244 	.byte	0
   085B 00                  245 	.byte	0
   085C D0                  246 	.byte	-48
   085D FF                  247 	.byte	-1
   085E 00                  248 	.byte	0
   085F D0                  249 	.byte	-48
   0860 FF                  250 	.byte	-1
   0861 F0                  251 	.byte	-16
   0862 F8                  252 	.byte	-8
   0863 FF                  253 	.byte	-1
   0864 00                  254 	.byte	0
   0865 30                  255 	.byte	48
   0866 00                  256 	.byte	0
   0867 E4                  257 	.byte	-28
   0868 0C                  258 	.byte	12
   0869 FF                  259 	.byte	-1
   086A 10                  260 	.byte	16
   086B 08                  261 	.byte	8
   086C FF                  262 	.byte	-1
   086D 00                  263 	.byte	0
   086E 18                  264 	.byte	24
   086F FF                  265 	.byte	-1
   0870 F0                  266 	.byte	-16
   0871 08                  267 	.byte	8
   0872                     268 _vl_term_1_83:
   0872 01                  269 	.byte	1
                            270 	.globl	_vl_player_left1
   0873                     271 _vl_player_left1:
   0873 00                  272 	.byte	0
   0874 08                  273 	.byte	8
   0875 50                  274 	.byte	80
   0876 FF                  275 	.byte	-1
   0877 B0                  276 	.byte	-80
   0878 00                  277 	.byte	0
   0879 FF                  278 	.byte	-1
   087A E8                  279 	.byte	-24
   087B 10                  280 	.byte	16
   087C FF                  281 	.byte	-1
   087D 00                  282 	.byte	0
   087E 50                  283 	.byte	80
   087F FF                  284 	.byte	-1
   0880 18                  285 	.byte	24
   0881 10                  286 	.byte	16
   0882 FF                  287 	.byte	-1
   0883 50                  288 	.byte	80
   0884 00                  289 	.byte	0
   0885 FF                  290 	.byte	-1
   0886 18                  291 	.byte	24
   0887 F0                  292 	.byte	-16
   0888 FF                  293 	.byte	-1
   0889 00                  294 	.byte	0
   088A B0                  295 	.byte	-80
   088B FF                  296 	.byte	-1
   088C E8                  297 	.byte	-24
   088D F0                  298 	.byte	-16
   088E 00                  299 	.byte	0
   088F F8                  300 	.byte	-8
   0890 00                  301 	.byte	0
   0891 FF                  302 	.byte	-1
   0892 10                  303 	.byte	16
   0893 C4                  304 	.byte	-60
   0894 FF                  305 	.byte	-1
   0895 00                  306 	.byte	0
   0896 D8                  307 	.byte	-40
   0897 FF                  308 	.byte	-1
   0898 F0                  309 	.byte	-16
   0899 C4                  310 	.byte	-60
   089A 00                  311 	.byte	0
   089B 08                  312 	.byte	8
   089C 00                  313 	.byte	0
   089D FF                  314 	.byte	-1
   089E B0                  315 	.byte	-80
   089F 00                  316 	.byte	0
   08A0 FF                  317 	.byte	-1
   08A1 E8                  318 	.byte	-24
   08A2 10                  319 	.byte	16
   08A3 FF                  320 	.byte	-1
   08A4 18                  321 	.byte	24
   08A5 10                  322 	.byte	16
   08A6 FF                  323 	.byte	-1
   08A7 08                  324 	.byte	8
   08A8 00                  325 	.byte	0
   08A9 00                  326 	.byte	0
   08AA F0                  327 	.byte	-16
   08AB E8                  328 	.byte	-24
   08AC FF                  329 	.byte	-1
   08AD 10                  330 	.byte	16
   08AE 34                  331 	.byte	52
   08AF 00                  332 	.byte	0
   08B0 00                  333 	.byte	0
   08B1 C4                  334 	.byte	-60
   08B2 FF                  335 	.byte	-1
   08B3 00                  336 	.byte	0
   08B4 50                  337 	.byte	80
   08B5 FF                  338 	.byte	-1
   08B6 00                  339 	.byte	0
   08B7 50                  340 	.byte	80
   08B8 00                  341 	.byte	0
   08B9 00                  342 	.byte	0
   08BA C4                  343 	.byte	-60
   08BB FF                  344 	.byte	-1
   08BC F0                  345 	.byte	-16
   08BD 40                  346 	.byte	64
   08BE                     347 _vl_term_2_123:
   08BE 01                  348 	.byte	1
                            349 	.globl	_vl_player_left2
   08BF                     350 _vl_player_left2:
   08BF 00                  351 	.byte	0
   08C0 D0                  352 	.byte	-48
   08C1 58                  353 	.byte	88
   08C2 00                  354 	.byte	0
   08C3 D0                  355 	.byte	-48
   08C4 58                  356 	.byte	88
   08C5 FF                  357 	.byte	-1
   08C6 18                  358 	.byte	24
   08C7 F0                  359 	.byte	-16
   08C8 FF                  360 	.byte	-1
   08C9 50                  361 	.byte	80
   08CA 00                  362 	.byte	0
   08CB FF                  363 	.byte	-1
   08CC 18                  364 	.byte	24
   08CD 10                  365 	.byte	16
   08CE 00                  366 	.byte	0
   08CF E0                  367 	.byte	-32
   08D0 10                  368 	.byte	16
   08D1 FF                  369 	.byte	-1
   08D2 00                  370 	.byte	0
   08D3 14                  371 	.byte	20
   08D4 FF                  372 	.byte	-1
   08D5 10                  373 	.byte	16
   08D6 08                  374 	.byte	8
   08D7 FF                  375 	.byte	-1
   08D8 38                  376 	.byte	56
   08D9 00                  377 	.byte	0
   08DA FF                  378 	.byte	-1
   08DB 10                  379 	.byte	16
   08DC F8                  380 	.byte	-8
   08DD FF                  381 	.byte	-1
   08DE F0                  382 	.byte	-16
   08DF F8                  383 	.byte	-8
   08E0 FF                  384 	.byte	-1
   08E1 C8                  385 	.byte	-56
   08E2 00                  386 	.byte	0
   08E3 FF                  387 	.byte	-1
   08E4 F0                  388 	.byte	-16
   08E5 08                  389 	.byte	8
   08E6 00                  390 	.byte	0
   08E7 58                  391 	.byte	88
   08E8 00                  392 	.byte	0
   08E9 FF                  393 	.byte	-1
   08EA 00                  394 	.byte	0
   08EB B8                  395 	.byte	-72
   08EC FF                  396 	.byte	-1
   08ED F0                  397 	.byte	-16
   08EE F8                  398 	.byte	-8
   08EF FF                  399 	.byte	-1
   08F0 D8                  400 	.byte	-40
   08F1 00                  401 	.byte	0
   08F2 00                  402 	.byte	0
   08F3 00                  403 	.byte	0
   08F4 EC                  404 	.byte	-20
   08F5 FF                  405 	.byte	-1
   08F6 1C                  406 	.byte	28
   08F7 14                  407 	.byte	20
   08F8 00                  408 	.byte	0
   08F9 1C                  409 	.byte	28
   08FA 10                  410 	.byte	16
   08FB FF                  411 	.byte	-1
   08FC 28                  412 	.byte	40
   08FD 1C                  413 	.byte	28
   08FE FF                  414 	.byte	-1
   08FF 00                  415 	.byte	0
   0900 D8                  416 	.byte	-40
   0901 FF                  417 	.byte	-1
   0902 C0                  418 	.byte	-64
   0903 94                  419 	.byte	-108
   0904 FF                  420 	.byte	-1
   0905 C0                  421 	.byte	-64
   0906 94                  422 	.byte	-108
   0907 00                  423 	.byte	0
   0908 34                  424 	.byte	52
   0909 58                  425 	.byte	88
   090A 00                  426 	.byte	0
   090B 34                  427 	.byte	52
   090C 58                  428 	.byte	88
   090D FF                  429 	.byte	-1
   090E 00                  430 	.byte	0
   090F E4                  431 	.byte	-28
   0910 FF                  432 	.byte	-1
   0911 10                  433 	.byte	16
   0912 18                  434 	.byte	24
   0913 FF                  435 	.byte	-1
   0914 00                  436 	.byte	0
   0915 20                  437 	.byte	32
   0916 00                  438 	.byte	0
   0917 00                  439 	.byte	0
   0918 2E                  440 	.byte	46
   0919 FF                  441 	.byte	-1
   091A 00                  442 	.byte	0
   091B 20                  443 	.byte	32
   091C FF                  444 	.byte	-1
   091D F0                  445 	.byte	-16
   091E F8                  446 	.byte	-8
   091F FF                  447 	.byte	-1
   0920 00                  448 	.byte	0
   0921 E0                  449 	.byte	-32
   0922                     450 _vl_term_3_170:
   0922 01                  451 	.byte	1
                            452 	.globl	_vl_player_left3
   0923                     453 _vl_player_left3:
   0923 00                  454 	.byte	0
   0924 08                  455 	.byte	8
   0925 B0                  456 	.byte	-80
   0926 FF                  457 	.byte	-1
   0927 18                  458 	.byte	24
   0928 10                  459 	.byte	16
   0929 FF                  460 	.byte	-1
   092A F0                  461 	.byte	-16
   092B 0C                  462 	.byte	12
   092C 00                  463 	.byte	0
   092D 90                  464 	.byte	-112
   092E F4                  465 	.byte	-12
   092F FF                  466 	.byte	-1
   0930 00                  467 	.byte	0
   0931 B0                  468 	.byte	-80
   0932 FF                  469 	.byte	-1
   0933 18                  470 	.byte	24
   0934 F0                  471 	.byte	-16
   0935 FF                  472 	.byte	-1
   0936 50                  473 	.byte	80
   0937 00                  474 	.byte	0
   0938 FF                  475 	.byte	-1
   0939 18                  476 	.byte	24
   093A 10                  477 	.byte	16
   093B FF                  478 	.byte	-1
   093C 00                  479 	.byte	0
   093D 50                  480 	.byte	80
   093E 00                  481 	.byte	0
   093F FC                  482 	.byte	-4
   0940 1C                  483 	.byte	28
   0941 FF                  484 	.byte	-1
   0942 30                  485 	.byte	48
   0943 00                  486 	.byte	0
   0944 FF                  487 	.byte	-1
   0945 10                  488 	.byte	16
   0946 08                  489 	.byte	8
   0947 FF                  490 	.byte	-1
   0948 00                  491 	.byte	0
   0949 48                  492 	.byte	72
   094A FF                  493 	.byte	-1
   094B F0                  494 	.byte	-16
   094C F8                  495 	.byte	-8
   094D FF                  496 	.byte	-1
   094E F8                  497 	.byte	-8
   094F 00                  498 	.byte	0
   0950 00                  499 	.byte	0
   0951 18                  500 	.byte	24
   0952 08                  501 	.byte	8
   0953 FF                  502 	.byte	-1
   0954 F4                  503 	.byte	-12
   0955 08                  504 	.byte	8
   0956 00                  505 	.byte	0
   0957 DC                  506 	.byte	-36
   0958 EC                  507 	.byte	-20
   0959 FF                  508 	.byte	-1
   095A 18                  509 	.byte	24
   095B 2C                  510 	.byte	44
   095C FF                  511 	.byte	-1
   095D 00                  512 	.byte	0
   095E 1C                  513 	.byte	28
   095F FF                  514 	.byte	-1
   0960 E8                  515 	.byte	-24
   0961 F0                  516 	.byte	-16
   0962                     517 _vl_term_4_203:
   0962 01                  518 	.byte	1
                            519 	.globl	_vl_player_right1
   0963                     520 _vl_player_right1:
   0963 00                  521 	.byte	0
   0964 08                  522 	.byte	8
   0965 B0                  523 	.byte	-80
   0966 FF                  524 	.byte	-1
   0967 B0                  525 	.byte	-80
   0968 00                  526 	.byte	0
   0969 FF                  527 	.byte	-1
   096A E8                  528 	.byte	-24
   096B F0                  529 	.byte	-16
   096C FF                  530 	.byte	-1
   096D 00                  531 	.byte	0
   096E B0                  532 	.byte	-80
   096F FF                  533 	.byte	-1
   0970 18                  534 	.byte	24
   0971 F0                  535 	.byte	-16
   0972 FF                  536 	.byte	-1
   0973 50                  537 	.byte	80
   0974 00                  538 	.byte	0
   0975 FF                  539 	.byte	-1
   0976 18                  540 	.byte	24
   0977 10                  541 	.byte	16
   0978 FF                  542 	.byte	-1
   0979 00                  543 	.byte	0
   097A 50                  544 	.byte	80
   097B FF                  545 	.byte	-1
   097C E8                  546 	.byte	-24
   097D 10                  547 	.byte	16
   097E 00                  548 	.byte	0
   097F F8                  549 	.byte	-8
   0980 00                  550 	.byte	0
   0981 FF                  551 	.byte	-1
   0982 10                  552 	.byte	16
   0983 3C                  553 	.byte	60
   0984 FF                  554 	.byte	-1
   0985 00                  555 	.byte	0
   0986 28                  556 	.byte	40
   0987 FF                  557 	.byte	-1
   0988 F0                  558 	.byte	-16
   0989 3C                  559 	.byte	60
   098A 00                  560 	.byte	0
   098B 08                  561 	.byte	8
   098C 00                  562 	.byte	0
   098D FF                  563 	.byte	-1
   098E B0                  564 	.byte	-80
   098F 00                  565 	.byte	0
   0990 FF                  566 	.byte	-1
   0991 E8                  567 	.byte	-24
   0992 F0                  568 	.byte	-16
   0993 FF                  569 	.byte	-1
   0994 18                  570 	.byte	24
   0995 F0                  571 	.byte	-16
   0996 FF                  572 	.byte	-1
   0997 08                  573 	.byte	8
   0998 00                  574 	.byte	0
   0999 00                  575 	.byte	0
   099A F0                  576 	.byte	-16
   099B 18                  577 	.byte	24
   099C FF                  578 	.byte	-1
   099D 10                  579 	.byte	16
   099E CC                  580 	.byte	-52
   099F 00                  581 	.byte	0
   09A0 00                  582 	.byte	0
   09A1 3C                  583 	.byte	60
   09A2 FF                  584 	.byte	-1
   09A3 00                  585 	.byte	0
   09A4 B0                  586 	.byte	-80
   09A5 FF                  587 	.byte	-1
   09A6 00                  588 	.byte	0
   09A7 B0                  589 	.byte	-80
   09A8 00                  590 	.byte	0
   09A9 00                  591 	.byte	0
   09AA 3C                  592 	.byte	60
   09AB FF                  593 	.byte	-1
   09AC F0                  594 	.byte	-16
   09AD C0                  595 	.byte	-64
   09AE                     596 _vl_term_5_243:
   09AE 01                  597 	.byte	1
                            598 	.globl	_vl_player_right2
   09AF                     599 _vl_player_right2:
   09AF 00                  600 	.byte	0
   09B0 D0                  601 	.byte	-48
   09B1 A8                  602 	.byte	-88
   09B2 00                  603 	.byte	0
   09B3 D0                  604 	.byte	-48
   09B4 A8                  605 	.byte	-88
   09B5 FF                  606 	.byte	-1
   09B6 18                  607 	.byte	24
   09B7 10                  608 	.byte	16
   09B8 FF                  609 	.byte	-1
   09B9 50                  610 	.byte	80
   09BA 00                  611 	.byte	0
   09BB FF                  612 	.byte	-1
   09BC 18                  613 	.byte	24
   09BD F0                  614 	.byte	-16
   09BE 00                  615 	.byte	0
   09BF E0                  616 	.byte	-32
   09C0 F0                  617 	.byte	-16
   09C1 FF                  618 	.byte	-1
   09C2 00                  619 	.byte	0
   09C3 EC                  620 	.byte	-20
   09C4 FF                  621 	.byte	-1
   09C5 10                  622 	.byte	16
   09C6 F8                  623 	.byte	-8
   09C7 FF                  624 	.byte	-1
   09C8 38                  625 	.byte	56
   09C9 00                  626 	.byte	0
   09CA FF                  627 	.byte	-1
   09CB 10                  628 	.byte	16
   09CC 08                  629 	.byte	8
   09CD FF                  630 	.byte	-1
   09CE F0                  631 	.byte	-16
   09CF 08                  632 	.byte	8
   09D0 FF                  633 	.byte	-1
   09D1 C8                  634 	.byte	-56
   09D2 00                  635 	.byte	0
   09D3 FF                  636 	.byte	-1
   09D4 F0                  637 	.byte	-16
   09D5 F8                  638 	.byte	-8
   09D6 00                  639 	.byte	0
   09D7 58                  640 	.byte	88
   09D8 00                  641 	.byte	0
   09D9 FF                  642 	.byte	-1
   09DA 00                  643 	.byte	0
   09DB 48                  644 	.byte	72
   09DC FF                  645 	.byte	-1
   09DD F0                  646 	.byte	-16
   09DE 08                  647 	.byte	8
   09DF FF                  648 	.byte	-1
   09E0 D8                  649 	.byte	-40
   09E1 00                  650 	.byte	0
   09E2 00                  651 	.byte	0
   09E3 00                  652 	.byte	0
   09E4 14                  653 	.byte	20
   09E5 FF                  654 	.byte	-1
   09E6 1C                  655 	.byte	28
   09E7 EC                  656 	.byte	-20
   09E8 00                  657 	.byte	0
   09E9 1C                  658 	.byte	28
   09EA F0                  659 	.byte	-16
   09EB FF                  660 	.byte	-1
   09EC 28                  661 	.byte	40
   09ED E4                  662 	.byte	-28
   09EE FF                  663 	.byte	-1
   09EF 00                  664 	.byte	0
   09F0 28                  665 	.byte	40
   09F1 FF                  666 	.byte	-1
   09F2 C0                  667 	.byte	-64
   09F3 6C                  668 	.byte	108
   09F4 FF                  669 	.byte	-1
   09F5 C0                  670 	.byte	-64
   09F6 6C                  671 	.byte	108
   09F7 00                  672 	.byte	0
   09F8 34                  673 	.byte	52
   09F9 A8                  674 	.byte	-88
   09FA 00                  675 	.byte	0
   09FB 34                  676 	.byte	52
   09FC A8                  677 	.byte	-88
   09FD FF                  678 	.byte	-1
   09FE 00                  679 	.byte	0
   09FF 1C                  680 	.byte	28
   0A00 FF                  681 	.byte	-1
   0A01 10                  682 	.byte	16
   0A02 E8                  683 	.byte	-24
   0A03 FF                  684 	.byte	-1
   0A04 00                  685 	.byte	0
   0A05 E0                  686 	.byte	-32
   0A06 00                  687 	.byte	0
   0A07 00                  688 	.byte	0
   0A08 D2                  689 	.byte	-46
   0A09 FF                  690 	.byte	-1
   0A0A 00                  691 	.byte	0
   0A0B E0                  692 	.byte	-32
   0A0C FF                  693 	.byte	-1
   0A0D F0                  694 	.byte	-16
   0A0E 08                  695 	.byte	8
   0A0F FF                  696 	.byte	-1
   0A10 00                  697 	.byte	0
   0A11 20                  698 	.byte	32
   0A12                     699 _vl_term_6_290:
   0A12 01                  700 	.byte	1
                            701 	.globl	_vl_player_right3
   0A13                     702 _vl_player_right3:
   0A13 00                  703 	.byte	0
   0A14 08                  704 	.byte	8
   0A15 50                  705 	.byte	80
   0A16 FF                  706 	.byte	-1
   0A17 18                  707 	.byte	24
   0A18 F0                  708 	.byte	-16
   0A19 FF                  709 	.byte	-1
   0A1A F0                  710 	.byte	-16
   0A1B F4                  711 	.byte	-12
   0A1C 00                  712 	.byte	0
   0A1D 90                  713 	.byte	-112
   0A1E 0C                  714 	.byte	12
   0A1F FF                  715 	.byte	-1
   0A20 00                  716 	.byte	0
   0A21 50                  717 	.byte	80
   0A22 FF                  718 	.byte	-1
   0A23 18                  719 	.byte	24
   0A24 10                  720 	.byte	16
   0A25 FF                  721 	.byte	-1
   0A26 50                  722 	.byte	80
   0A27 00                  723 	.byte	0
   0A28 FF                  724 	.byte	-1
   0A29 18                  725 	.byte	24
   0A2A F0                  726 	.byte	-16
   0A2B FF                  727 	.byte	-1
   0A2C 00                  728 	.byte	0
   0A2D B0                  729 	.byte	-80
   0A2E 00                  730 	.byte	0
   0A2F FC                  731 	.byte	-4
   0A30 E4                  732 	.byte	-28
   0A31 FF                  733 	.byte	-1
   0A32 30                  734 	.byte	48
   0A33 00                  735 	.byte	0
   0A34 FF                  736 	.byte	-1
   0A35 10                  737 	.byte	16
   0A36 F8                  738 	.byte	-8
   0A37 FF                  739 	.byte	-1
   0A38 00                  740 	.byte	0
   0A39 B8                  741 	.byte	-72
   0A3A FF                  742 	.byte	-1
   0A3B F0                  743 	.byte	-16
   0A3C 08                  744 	.byte	8
   0A3D FF                  745 	.byte	-1
   0A3E F8                  746 	.byte	-8
   0A3F 00                  747 	.byte	0
   0A40 00                  748 	.byte	0
   0A41 18                  749 	.byte	24
   0A42 F8                  750 	.byte	-8
   0A43 FF                  751 	.byte	-1
   0A44 F4                  752 	.byte	-12
   0A45 F8                  753 	.byte	-8
   0A46 00                  754 	.byte	0
   0A47 DC                  755 	.byte	-36
   0A48 14                  756 	.byte	20
   0A49 FF                  757 	.byte	-1
   0A4A 18                  758 	.byte	24
   0A4B D4                  759 	.byte	-44
   0A4C FF                  760 	.byte	-1
   0A4D 00                  761 	.byte	0
   0A4E E4                  762 	.byte	-28
   0A4F FF                  763 	.byte	-1
   0A50 E8                  764 	.byte	-24
   0A51 10                  765 	.byte	16
   0A52                     766 _vl_term_7_323:
   0A52 01                  767 	.byte	1
                            768 	.globl	_player_change_left
   0A53                     769 _player_change_left:
   0A53 F6 C8 AA      [ 5]  770 	ldb	_the_player
   0A56 10 27 00 DB   [ 6]  771 	lbeq	L15
   0A5A C1 01         [ 2]  772 	cmpb	#1	;cmpqi:
   0A5C 10 27 00 8B   [ 6]  773 	lbeq	L16
   0A60 F6 C8 A4      [ 5]  774 	ldb	_the_game+2
   0A63 4F            [ 2]  775 	clra		;zero_extendqihi: R:b -> R:d
   0A64 1F 01         [ 6]  776 	tfr	d,x
   0A66 F6 C8 AB      [ 5]  777 	ldb	_the_player+1
   0A69 E1 89 07 7D   [ 8]  778 	cmpb	_PLAYER_ANIMATION_FRAME_CNT_HALFED_LUT,x	;cmpqi:
   0A6D 10 23 00 CD   [ 6]  779 	lbls	L10
   0A71 BD F3 54      [ 8]  780 	jsr	___Reset0Ref
   0A74 C6 7F         [ 2]  781 	ldb	#127
   0A76 D7 04         [ 4]  782 	stb	*_dp_VIA_t1_cnt_lo
   0A78 F6 C8 AB      [ 5]  783 	ldb	_the_player+1
   0A7B 4F            [ 2]  784 	clra		;zero_extendqihi: R:b -> R:d
   0A7C 1F 01         [ 6]  785 	tfr	d,x
   0A7E C6 90         [ 2]  786 	ldb	#-112
   0A80 E7 E2         [ 6]  787 	stb	,-s
   0A82 E6 89 07 9E   [ 8]  788 	ldb	_SP1_RIGHT_MID_X_LUT,x
   0A86 BD 0F 13      [ 8]  789 	jsr	__Moveto_d
   0A89 C6 10         [ 2]  790 	ldb	#16
   0A8B D7 04         [ 4]  791 	stb	*_dp_VIA_t1_cnt_lo
   0A8D 8E 09 63      [ 3]  792 	ldx	#_vl_player_right1
   0A90 BD F4 10      [ 8]  793 	jsr	___Draw_VLp
   0A93 BD F3 54      [ 8]  794 	jsr	___Reset0Ref
   0A96 C6 7F         [ 2]  795 	ldb	#127
   0A98 D7 04         [ 4]  796 	stb	*_dp_VIA_t1_cnt_lo
   0A9A F6 C8 AB      [ 5]  797 	ldb	_the_player+1
   0A9D 4F            [ 2]  798 	clra		;zero_extendqihi: R:b -> R:d
   0A9E 1F 01         [ 6]  799 	tfr	d,x
   0AA0 C6 90         [ 2]  800 	ldb	#-112
   0AA2 E7 E2         [ 6]  801 	stb	,-s
   0AA4 E6 89 07 9E   [ 8]  802 	ldb	_SP1_RIGHT_MID_X_LUT,x
   0AA8 BD 0F 13      [ 8]  803 	jsr	__Moveto_d
   0AAB C6 10         [ 2]  804 	ldb	#16
   0AAD D7 04         [ 4]  805 	stb	*_dp_VIA_t1_cnt_lo
   0AAF 8E 09 AF      [ 3]  806 	ldx	#_vl_player_right2
   0AB2 BD F4 10      [ 8]  807 	jsr	___Draw_VLp
   0AB5 BD F3 54      [ 8]  808 	jsr	___Reset0Ref
   0AB8 C6 7F         [ 2]  809 	ldb	#127
   0ABA D7 04         [ 4]  810 	stb	*_dp_VIA_t1_cnt_lo
   0ABC F6 C8 AB      [ 5]  811 	ldb	_the_player+1
   0ABF 4F            [ 2]  812 	clra		;zero_extendqihi: R:b -> R:d
   0AC0 1F 01         [ 6]  813 	tfr	d,x
   0AC2 C6 90         [ 2]  814 	ldb	#-112
   0AC4 E7 E2         [ 6]  815 	stb	,-s
   0AC6 E6 89 07 9E   [ 8]  816 	ldb	_SP1_RIGHT_MID_X_LUT,x
   0ACA BD 0F 13      [ 8]  817 	jsr	__Moveto_d
   0ACD C6 10         [ 2]  818 	ldb	#16
   0ACF D7 04         [ 4]  819 	stb	*_dp_VIA_t1_cnt_lo
   0AD1 8E 0A 13      [ 3]  820 	ldx	#_vl_player_right3
   0AD4 BD F4 10      [ 8]  821 	jsr	___Draw_VLp
   0AD7 32 63         [ 5]  822 	leas	3,s
   0AD9                     823 L9:
   0AD9 7A C8 AB      [ 7]  824 	dec	_the_player+1
   0ADC F6 C8 AB      [ 5]  825 	ldb	_the_player+1
   0ADF 26 09         [ 3]  826 	bne	L12
   0AE1 7A C8 AA      [ 7]  827 	dec	_the_player
   0AE4 8E 07 D4      [ 3]  828 	ldx	#_player_draw
   0AE7 BF C8 AC      [ 6]  829 	stx	_the_player+2
   0AEA                     830 L12:
   0AEA 39            [ 5]  831 	rts
   0AEB                     832 L16:
   0AEB F6 C8 A4      [ 5]  833 	ldb	_the_game+2
   0AEE 4F            [ 2]  834 	clra		;zero_extendqihi: R:b -> R:d
   0AEF 1F 01         [ 6]  835 	tfr	d,x
   0AF1 F6 C8 AB      [ 5]  836 	ldb	_the_player+1
   0AF4 E1 89 07 7D   [ 8]  837 	cmpb	_PLAYER_ANIMATION_FRAME_CNT_HALFED_LUT,x	;cmpqi:
   0AF8 10 23 00 8B   [ 6]  838 	lbls	L8
   0AFC BD F3 54      [ 8]  839 	jsr	___Reset0Ref
   0AFF C6 7F         [ 2]  840 	ldb	#127
   0B01 D7 04         [ 4]  841 	stb	*_dp_VIA_t1_cnt_lo
   0B03 F6 C8 AB      [ 5]  842 	ldb	_the_player+1
   0B06 4F            [ 2]  843 	clra		;zero_extendqihi: R:b -> R:d
   0B07 1F 01         [ 6]  844 	tfr	d,x
   0B09 C6 90         [ 2]  845 	ldb	#-112
   0B0B E7 E2         [ 6]  846 	stb	,-s
   0B0D E6 89 07 91   [ 8]  847 	ldb	_SP1_MID_LEFT_X_LUT,x
   0B11 BD 0F 13      [ 8]  848 	jsr	__Moveto_d
   0B14 C6 10         [ 2]  849 	ldb	#16
   0B16 D7 04         [ 4]  850 	stb	*_dp_VIA_t1_cnt_lo
   0B18 8E 07 EA      [ 3]  851 	ldx	#_vl_player_mid1
   0B1B BD F4 10      [ 8]  852 	jsr	___Draw_VLp
   0B1E BD F3 54      [ 8]  853 	jsr	___Reset0Ref
   0B21 C6 7F         [ 2]  854 	ldb	#127
   0B23 D7 04         [ 4]  855 	stb	*_dp_VIA_t1_cnt_lo
   0B25 F6 C8 AB      [ 5]  856 	ldb	_the_player+1
   0B28 4F            [ 2]  857 	clra		;zero_extendqihi: R:b -> R:d
   0B29 1F 01         [ 6]  858 	tfr	d,x
   0B2B C6 90         [ 2]  859 	ldb	#-112
   0B2D E7 E2         [ 6]  860 	stb	,-s
   0B2F E6 89 07 91   [ 8]  861 	ldb	_SP1_MID_LEFT_X_LUT,x
   0B33 20 40         [ 3]  862 	bra	L13
   0B35                     863 L15:
   0B35 8E 07 D4      [ 3]  864 	ldx	#_player_draw
   0B38 BF C8 AC      [ 6]  865 	stx	_the_player+2
   0B3B 7E 07 D4      [ 4]  866 	jmp	_player_draw
   0B3E                     867 L10:
   0B3E BD F3 54      [ 8]  868 	jsr	___Reset0Ref
   0B41 C6 7F         [ 2]  869 	ldb	#127
   0B43 D7 04         [ 4]  870 	stb	*_dp_VIA_t1_cnt_lo
   0B45 F6 C8 AB      [ 5]  871 	ldb	_the_player+1
   0B48 4F            [ 2]  872 	clra		;zero_extendqihi: R:b -> R:d
   0B49 1F 01         [ 6]  873 	tfr	d,x
   0B4B C6 90         [ 2]  874 	ldb	#-112
   0B4D E7 E2         [ 6]  875 	stb	,-s
   0B4F E6 89 07 9E   [ 8]  876 	ldb	_SP1_RIGHT_MID_X_LUT,x
   0B53 BD 0F 13      [ 8]  877 	jsr	__Moveto_d
   0B56 C6 10         [ 2]  878 	ldb	#16
   0B58 D7 04         [ 4]  879 	stb	*_dp_VIA_t1_cnt_lo
   0B5A 8E 07 EA      [ 3]  880 	ldx	#_vl_player_mid1
   0B5D BD F4 10      [ 8]  881 	jsr	___Draw_VLp
   0B60 BD F3 54      [ 8]  882 	jsr	___Reset0Ref
   0B63 C6 7F         [ 2]  883 	ldb	#127
   0B65 D7 04         [ 4]  884 	stb	*_dp_VIA_t1_cnt_lo
   0B67 F6 C8 AB      [ 5]  885 	ldb	_the_player+1
   0B6A 4F            [ 2]  886 	clra		;zero_extendqihi: R:b -> R:d
   0B6B 1F 01         [ 6]  887 	tfr	d,x
   0B6D C6 90         [ 2]  888 	ldb	#-112
   0B6F E7 E2         [ 6]  889 	stb	,-s
   0B71 E6 89 07 9E   [ 8]  890 	ldb	_SP1_RIGHT_MID_X_LUT,x
   0B75                     891 L13:
   0B75 BD 0F 13      [ 8]  892 	jsr	__Moveto_d
   0B78 C6 10         [ 2]  893 	ldb	#16
   0B7A D7 04         [ 4]  894 	stb	*_dp_VIA_t1_cnt_lo
   0B7C 8E 08 2A      [ 3]  895 	ldx	#_vl_player_mid2
   0B7F BD F4 10      [ 8]  896 	jsr	___Draw_VLp
   0B82 32 62         [ 5]  897 	leas	2,s
   0B84 16 FF 52      [ 5]  898 	lbra	L9
   0B87                     899 L8:
   0B87 BD F3 54      [ 8]  900 	jsr	___Reset0Ref
   0B8A C6 7F         [ 2]  901 	ldb	#127
   0B8C D7 04         [ 4]  902 	stb	*_dp_VIA_t1_cnt_lo
   0B8E F6 C8 AB      [ 5]  903 	ldb	_the_player+1
   0B91 4F            [ 2]  904 	clra		;zero_extendqihi: R:b -> R:d
   0B92 1F 01         [ 6]  905 	tfr	d,x
   0B94 C6 90         [ 2]  906 	ldb	#-112
   0B96 E7 E2         [ 6]  907 	stb	,-s
   0B98 E6 89 07 91   [ 8]  908 	ldb	_SP1_MID_LEFT_X_LUT,x
   0B9C BD 0F 13      [ 8]  909 	jsr	__Moveto_d
   0B9F C6 10         [ 2]  910 	ldb	#16
   0BA1 D7 04         [ 4]  911 	stb	*_dp_VIA_t1_cnt_lo
   0BA3 8E 08 73      [ 3]  912 	ldx	#_vl_player_left1
   0BA6 BD F4 10      [ 8]  913 	jsr	___Draw_VLp
   0BA9 BD F3 54      [ 8]  914 	jsr	___Reset0Ref
   0BAC C6 7F         [ 2]  915 	ldb	#127
   0BAE D7 04         [ 4]  916 	stb	*_dp_VIA_t1_cnt_lo
   0BB0 F6 C8 AB      [ 5]  917 	ldb	_the_player+1
   0BB3 4F            [ 2]  918 	clra		;zero_extendqihi: R:b -> R:d
   0BB4 1F 01         [ 6]  919 	tfr	d,x
   0BB6 C6 90         [ 2]  920 	ldb	#-112
   0BB8 E7 E2         [ 6]  921 	stb	,-s
   0BBA E6 89 07 91   [ 8]  922 	ldb	_SP1_MID_LEFT_X_LUT,x
   0BBE BD 0F 13      [ 8]  923 	jsr	__Moveto_d
   0BC1 C6 10         [ 2]  924 	ldb	#16
   0BC3 D7 04         [ 4]  925 	stb	*_dp_VIA_t1_cnt_lo
   0BC5 8E 08 BF      [ 3]  926 	ldx	#_vl_player_left2
   0BC8 BD F4 10      [ 8]  927 	jsr	___Draw_VLp
   0BCB BD F3 54      [ 8]  928 	jsr	___Reset0Ref
   0BCE C6 7F         [ 2]  929 	ldb	#127
   0BD0 D7 04         [ 4]  930 	stb	*_dp_VIA_t1_cnt_lo
   0BD2 F6 C8 AB      [ 5]  931 	ldb	_the_player+1
   0BD5 4F            [ 2]  932 	clra		;zero_extendqihi: R:b -> R:d
   0BD6 1F 01         [ 6]  933 	tfr	d,x
   0BD8 C6 90         [ 2]  934 	ldb	#-112
   0BDA E7 E2         [ 6]  935 	stb	,-s
   0BDC E6 89 07 91   [ 8]  936 	ldb	_SP1_MID_LEFT_X_LUT,x
   0BE0 BD 0F 13      [ 8]  937 	jsr	__Moveto_d
   0BE3 C6 10         [ 2]  938 	ldb	#16
   0BE5 D7 04         [ 4]  939 	stb	*_dp_VIA_t1_cnt_lo
   0BE7 8E 09 23      [ 3]  940 	ldx	#_vl_player_left3
   0BEA BD F4 10      [ 8]  941 	jsr	___Draw_VLp
   0BED 32 63         [ 5]  942 	leas	3,s
   0BEF 16 FE E7      [ 5]  943 	lbra	L9
                            944 	.globl	_player_change_right
   0BF2                     945 _player_change_right:
   0BF2 F6 C8 AA      [ 5]  946 	ldb	_the_player
   0BF5 C1 02         [ 2]  947 	cmpb	#2	;cmpqi:
   0BF7 10 27 01 8C   [ 6]  948 	lbeq	L26
   0BFB C1 01         [ 2]  949 	cmpb	#1	;cmpqi:
   0BFD 10 27 00 D2   [ 6]  950 	lbeq	L27
   0C01 F6 C8 A4      [ 5]  951 	ldb	_the_game+2
   0C04 4F            [ 2]  952 	clra		;zero_extendqihi: R:b -> R:d
   0C05 1F 01         [ 6]  953 	tfr	d,x
   0C07 F6 C8 AB      [ 5]  954 	ldb	_the_player+1
   0C0A E1 89 07 7D   [ 8]  955 	cmpb	_PLAYER_ANIMATION_FRAME_CNT_HALFED_LUT,x	;cmpqi:
   0C0E 22 58         [ 3]  956 	bhi	L28
   0C10 BD F3 54      [ 8]  957 	jsr	___Reset0Ref
   0C13 C6 7F         [ 2]  958 	ldb	#127
   0C15 D7 04         [ 4]  959 	stb	*_dp_VIA_t1_cnt_lo
   0C17 F6 C8 AB      [ 5]  960 	ldb	_the_player+1
   0C1A 4F            [ 2]  961 	clra		;zero_extendqihi: R:b -> R:d
   0C1B 1F 01         [ 6]  962 	tfr	d,x
   0C1D C6 90         [ 2]  963 	ldb	#-112
   0C1F E7 E2         [ 6]  964 	stb	,-s
   0C21 E6 89 07 B8   [ 8]  965 	ldb	_SP1_LEFT_MID_X_LUT,x
   0C25 BD 0F 13      [ 8]  966 	jsr	__Moveto_d
   0C28 C6 10         [ 2]  967 	ldb	#16
   0C2A D7 04         [ 4]  968 	stb	*_dp_VIA_t1_cnt_lo
   0C2C 8E 07 EA      [ 3]  969 	ldx	#_vl_player_mid1
   0C2F BD F4 10      [ 8]  970 	jsr	___Draw_VLp
   0C32 BD F3 54      [ 8]  971 	jsr	___Reset0Ref
   0C35 C6 7F         [ 2]  972 	ldb	#127
   0C37 D7 04         [ 4]  973 	stb	*_dp_VIA_t1_cnt_lo
   0C39 F6 C8 AB      [ 5]  974 	ldb	_the_player+1
   0C3C 4F            [ 2]  975 	clra		;zero_extendqihi: R:b -> R:d
   0C3D 1F 01         [ 6]  976 	tfr	d,x
   0C3F C6 90         [ 2]  977 	ldb	#-112
   0C41 E7 E2         [ 6]  978 	stb	,-s
   0C43 E6 89 07 B8   [ 8]  979 	ldb	_SP1_LEFT_MID_X_LUT,x
   0C47                     980 L25:
   0C47 BD 0F 13      [ 8]  981 	jsr	__Moveto_d
   0C4A C6 10         [ 2]  982 	ldb	#16
   0C4C D7 04         [ 4]  983 	stb	*_dp_VIA_t1_cnt_lo
   0C4E 8E 08 2A      [ 3]  984 	ldx	#_vl_player_mid2
   0C51 BD F4 10      [ 8]  985 	jsr	___Draw_VLp
   0C54 32 62         [ 5]  986 	leas	2,s
   0C56                     987 L21:
   0C56 7A C8 AB      [ 7]  988 	dec	_the_player+1
   0C59 F6 C8 AB      [ 5]  989 	ldb	_the_player+1
   0C5C 26 09         [ 3]  990 	bne	L24
   0C5E 7C C8 AA      [ 7]  991 	inc	_the_player
   0C61 8E 07 D4      [ 3]  992 	ldx	#_player_draw
   0C64 BF C8 AC      [ 6]  993 	stx	_the_player+2
   0C67                     994 L24:
   0C67 39            [ 5]  995 	rts
   0C68                     996 L28:
   0C68 BD F3 54      [ 8]  997 	jsr	___Reset0Ref
   0C6B C6 7F         [ 2]  998 	ldb	#127
   0C6D D7 04         [ 4]  999 	stb	*_dp_VIA_t1_cnt_lo
   0C6F F6 C8 AB      [ 5] 1000 	ldb	_the_player+1
   0C72 4F            [ 2] 1001 	clra		;zero_extendqihi: R:b -> R:d
   0C73 1F 01         [ 6] 1002 	tfr	d,x
   0C75 C6 90         [ 2] 1003 	ldb	#-112
   0C77 E7 E2         [ 6] 1004 	stb	,-s
   0C79 E6 89 07 B8   [ 8] 1005 	ldb	_SP1_LEFT_MID_X_LUT,x
   0C7D BD 0F 13      [ 8] 1006 	jsr	__Moveto_d
   0C80 C6 10         [ 2] 1007 	ldb	#16
   0C82 D7 04         [ 4] 1008 	stb	*_dp_VIA_t1_cnt_lo
   0C84 8E 08 73      [ 3] 1009 	ldx	#_vl_player_left1
   0C87 BD F4 10      [ 8] 1010 	jsr	___Draw_VLp
   0C8A BD F3 54      [ 8] 1011 	jsr	___Reset0Ref
   0C8D C6 7F         [ 2] 1012 	ldb	#127
   0C8F D7 04         [ 4] 1013 	stb	*_dp_VIA_t1_cnt_lo
   0C91 F6 C8 AB      [ 5] 1014 	ldb	_the_player+1
   0C94 4F            [ 2] 1015 	clra		;zero_extendqihi: R:b -> R:d
   0C95 1F 01         [ 6] 1016 	tfr	d,x
   0C97 C6 90         [ 2] 1017 	ldb	#-112
   0C99 E7 E2         [ 6] 1018 	stb	,-s
   0C9B E6 89 07 B8   [ 8] 1019 	ldb	_SP1_LEFT_MID_X_LUT,x
   0C9F BD 0F 13      [ 8] 1020 	jsr	__Moveto_d
   0CA2 C6 10         [ 2] 1021 	ldb	#16
   0CA4 D7 04         [ 4] 1022 	stb	*_dp_VIA_t1_cnt_lo
   0CA6 8E 08 BF      [ 3] 1023 	ldx	#_vl_player_left2
   0CA9 BD F4 10      [ 8] 1024 	jsr	___Draw_VLp
   0CAC BD F3 54      [ 8] 1025 	jsr	___Reset0Ref
   0CAF C6 7F         [ 2] 1026 	ldb	#127
   0CB1 D7 04         [ 4] 1027 	stb	*_dp_VIA_t1_cnt_lo
   0CB3 F6 C8 AB      [ 5] 1028 	ldb	_the_player+1
   0CB6 4F            [ 2] 1029 	clra		;zero_extendqihi: R:b -> R:d
   0CB7 1F 01         [ 6] 1030 	tfr	d,x
   0CB9 C6 90         [ 2] 1031 	ldb	#-112
   0CBB E7 E2         [ 6] 1032 	stb	,-s
   0CBD E6 89 07 B8   [ 8] 1033 	ldb	_SP1_LEFT_MID_X_LUT,x
   0CC1 BD 0F 13      [ 8] 1034 	jsr	__Moveto_d
   0CC4 C6 10         [ 2] 1035 	ldb	#16
   0CC6 D7 04         [ 4] 1036 	stb	*_dp_VIA_t1_cnt_lo
   0CC8 8E 09 23      [ 3] 1037 	ldx	#_vl_player_left3
   0CCB BD F4 10      [ 8] 1038 	jsr	___Draw_VLp
   0CCE 32 63         [ 5] 1039 	leas	3,s
   0CD0 16 FF 83      [ 5] 1040 	lbra	L21
   0CD3                    1041 L27:
   0CD3 F6 C8 A4      [ 5] 1042 	ldb	_the_game+2
   0CD6 4F            [ 2] 1043 	clra		;zero_extendqihi: R:b -> R:d
   0CD7 1F 01         [ 6] 1044 	tfr	d,x
   0CD9 F6 C8 AB      [ 5] 1045 	ldb	_the_player+1
   0CDC E1 89 07 7D   [ 8] 1046 	cmpb	_PLAYER_ANIMATION_FRAME_CNT_HALFED_LUT,x	;cmpqi:
   0CE0 23 3A         [ 3] 1047 	bls	L20
   0CE2 BD F3 54      [ 8] 1048 	jsr	___Reset0Ref
   0CE5 C6 7F         [ 2] 1049 	ldb	#127
   0CE7 D7 04         [ 4] 1050 	stb	*_dp_VIA_t1_cnt_lo
   0CE9 F6 C8 AB      [ 5] 1051 	ldb	_the_player+1
   0CEC 4F            [ 2] 1052 	clra		;zero_extendqihi: R:b -> R:d
   0CED 1F 01         [ 6] 1053 	tfr	d,x
   0CEF C6 90         [ 2] 1054 	ldb	#-112
   0CF1 E7 E2         [ 6] 1055 	stb	,-s
   0CF3 E6 89 07 AB   [ 8] 1056 	ldb	_SP1_MID_RIGHT_X_LUT,x
   0CF7 BD 0F 13      [ 8] 1057 	jsr	__Moveto_d
   0CFA C6 10         [ 2] 1058 	ldb	#16
   0CFC D7 04         [ 4] 1059 	stb	*_dp_VIA_t1_cnt_lo
   0CFE 8E 07 EA      [ 3] 1060 	ldx	#_vl_player_mid1
   0D01 BD F4 10      [ 8] 1061 	jsr	___Draw_VLp
   0D04 BD F3 54      [ 8] 1062 	jsr	___Reset0Ref
   0D07 C6 7F         [ 2] 1063 	ldb	#127
   0D09 D7 04         [ 4] 1064 	stb	*_dp_VIA_t1_cnt_lo
   0D0B F6 C8 AB      [ 5] 1065 	ldb	_the_player+1
   0D0E 4F            [ 2] 1066 	clra		;zero_extendqihi: R:b -> R:d
   0D0F 1F 01         [ 6] 1067 	tfr	d,x
   0D11 C6 90         [ 2] 1068 	ldb	#-112
   0D13 E7 E2         [ 6] 1069 	stb	,-s
   0D15 E6 89 07 AB   [ 8] 1070 	ldb	_SP1_MID_RIGHT_X_LUT,x
   0D19 16 FF 2B      [ 5] 1071 	lbra	L25
   0D1C                    1072 L20:
   0D1C BD F3 54      [ 8] 1073 	jsr	___Reset0Ref
   0D1F C6 7F         [ 2] 1074 	ldb	#127
   0D21 D7 04         [ 4] 1075 	stb	*_dp_VIA_t1_cnt_lo
   0D23 F6 C8 AB      [ 5] 1076 	ldb	_the_player+1
   0D26 4F            [ 2] 1077 	clra		;zero_extendqihi: R:b -> R:d
   0D27 1F 01         [ 6] 1078 	tfr	d,x
   0D29 C6 90         [ 2] 1079 	ldb	#-112
   0D2B E7 E2         [ 6] 1080 	stb	,-s
   0D2D E6 89 07 AB   [ 8] 1081 	ldb	_SP1_MID_RIGHT_X_LUT,x
   0D31 BD 0F 13      [ 8] 1082 	jsr	__Moveto_d
   0D34 C6 10         [ 2] 1083 	ldb	#16
   0D36 D7 04         [ 4] 1084 	stb	*_dp_VIA_t1_cnt_lo
   0D38 8E 09 63      [ 3] 1085 	ldx	#_vl_player_right1
   0D3B BD F4 10      [ 8] 1086 	jsr	___Draw_VLp
   0D3E BD F3 54      [ 8] 1087 	jsr	___Reset0Ref
   0D41 C6 7F         [ 2] 1088 	ldb	#127
   0D43 D7 04         [ 4] 1089 	stb	*_dp_VIA_t1_cnt_lo
   0D45 F6 C8 AB      [ 5] 1090 	ldb	_the_player+1
   0D48 4F            [ 2] 1091 	clra		;zero_extendqihi: R:b -> R:d
   0D49 1F 01         [ 6] 1092 	tfr	d,x
   0D4B C6 90         [ 2] 1093 	ldb	#-112
   0D4D E7 E2         [ 6] 1094 	stb	,-s
   0D4F E6 89 07 AB   [ 8] 1095 	ldb	_SP1_MID_RIGHT_X_LUT,x
   0D53 BD 0F 13      [ 8] 1096 	jsr	__Moveto_d
   0D56 C6 10         [ 2] 1097 	ldb	#16
   0D58 D7 04         [ 4] 1098 	stb	*_dp_VIA_t1_cnt_lo
   0D5A 8E 09 AF      [ 3] 1099 	ldx	#_vl_player_right2
   0D5D BD F4 10      [ 8] 1100 	jsr	___Draw_VLp
   0D60 BD F3 54      [ 8] 1101 	jsr	___Reset0Ref
   0D63 C6 7F         [ 2] 1102 	ldb	#127
   0D65 D7 04         [ 4] 1103 	stb	*_dp_VIA_t1_cnt_lo
   0D67 F6 C8 AB      [ 5] 1104 	ldb	_the_player+1
   0D6A 4F            [ 2] 1105 	clra		;zero_extendqihi: R:b -> R:d
   0D6B 1F 01         [ 6] 1106 	tfr	d,x
   0D6D C6 90         [ 2] 1107 	ldb	#-112
   0D6F E7 E2         [ 6] 1108 	stb	,-s
   0D71 E6 89 07 AB   [ 8] 1109 	ldb	_SP1_MID_RIGHT_X_LUT,x
   0D75 BD 0F 13      [ 8] 1110 	jsr	__Moveto_d
   0D78 C6 10         [ 2] 1111 	ldb	#16
   0D7A D7 04         [ 4] 1112 	stb	*_dp_VIA_t1_cnt_lo
   0D7C 8E 0A 13      [ 3] 1113 	ldx	#_vl_player_right3
   0D7F BD F4 10      [ 8] 1114 	jsr	___Draw_VLp
   0D82 32 63         [ 5] 1115 	leas	3,s
   0D84 16 FE CF      [ 5] 1116 	lbra	L21
   0D87                    1117 L26:
   0D87 8E 07 D4      [ 3] 1118 	ldx	#_player_draw
   0D8A BF C8 AC      [ 6] 1119 	stx	_the_player+2
   0D8D 7E 07 D4      [ 4] 1120 	jmp	_player_draw
                           1121 	.globl	__player_draw_mid
   0D90                    1122 __player_draw_mid:
   0D90 BD F3 54      [ 8] 1123 	jsr	___Reset0Ref
   0D93 C6 7F         [ 2] 1124 	ldb	#127
   0D95 D7 04         [ 4] 1125 	stb	*_dp_VIA_t1_cnt_lo
   0D97 F6 C8 AA      [ 5] 1126 	ldb	_the_player
   0D9A 4F            [ 2] 1127 	clra		;zero_extendqihi: R:b -> R:d
   0D9B 1F 01         [ 6] 1128 	tfr	d,x
   0D9D C6 90         [ 2] 1129 	ldb	#-112
   0D9F E7 E2         [ 6] 1130 	stb	,-s
   0DA1 E6 89 07 88   [ 8] 1131 	ldb	_PLAYER_STATIC_X_LUT,x
   0DA5 BD 0F 13      [ 8] 1132 	jsr	__Moveto_d
   0DA8 C6 10         [ 2] 1133 	ldb	#16
   0DAA D7 04         [ 4] 1134 	stb	*_dp_VIA_t1_cnt_lo
   0DAC 8E 07 EA      [ 3] 1135 	ldx	#_vl_player_mid1
   0DAF BD F4 10      [ 8] 1136 	jsr	___Draw_VLp
   0DB2 BD F3 54      [ 8] 1137 	jsr	___Reset0Ref
   0DB5 C6 7F         [ 2] 1138 	ldb	#127
   0DB7 D7 04         [ 4] 1139 	stb	*_dp_VIA_t1_cnt_lo
   0DB9 F6 C8 AA      [ 5] 1140 	ldb	_the_player
   0DBC 4F            [ 2] 1141 	clra		;zero_extendqihi: R:b -> R:d
   0DBD 1F 01         [ 6] 1142 	tfr	d,x
   0DBF C6 90         [ 2] 1143 	ldb	#-112
   0DC1 E7 E2         [ 6] 1144 	stb	,-s
   0DC3 E6 89 07 88   [ 8] 1145 	ldb	_PLAYER_STATIC_X_LUT,x
   0DC7 BD 0F 13      [ 8] 1146 	jsr	__Moveto_d
   0DCA C6 10         [ 2] 1147 	ldb	#16
   0DCC D7 04         [ 4] 1148 	stb	*_dp_VIA_t1_cnt_lo
   0DCE 32 62         [ 5] 1149 	leas	2,s
   0DD0 8E 08 2A      [ 3] 1150 	ldx	#_vl_player_mid2
   0DD3 7E F4 10      [ 4] 1151 	jmp	___Draw_VLp
                           1152 	.globl	__player_draw_left
   0DD6                    1153 __player_draw_left:
   0DD6 BD F3 54      [ 8] 1154 	jsr	___Reset0Ref
   0DD9 C6 7F         [ 2] 1155 	ldb	#127
   0DDB D7 04         [ 4] 1156 	stb	*_dp_VIA_t1_cnt_lo
   0DDD F6 C8 AA      [ 5] 1157 	ldb	_the_player
   0DE0 4F            [ 2] 1158 	clra		;zero_extendqihi: R:b -> R:d
   0DE1 1F 01         [ 6] 1159 	tfr	d,x
   0DE3 C6 90         [ 2] 1160 	ldb	#-112
   0DE5 E7 E2         [ 6] 1161 	stb	,-s
   0DE7 E6 89 07 88   [ 8] 1162 	ldb	_PLAYER_STATIC_X_LUT,x
   0DEB BD 0F 13      [ 8] 1163 	jsr	__Moveto_d
   0DEE C6 10         [ 2] 1164 	ldb	#16
   0DF0 D7 04         [ 4] 1165 	stb	*_dp_VIA_t1_cnt_lo
   0DF2 8E 08 73      [ 3] 1166 	ldx	#_vl_player_left1
   0DF5 BD F4 10      [ 8] 1167 	jsr	___Draw_VLp
   0DF8 BD F3 54      [ 8] 1168 	jsr	___Reset0Ref
   0DFB C6 7F         [ 2] 1169 	ldb	#127
   0DFD D7 04         [ 4] 1170 	stb	*_dp_VIA_t1_cnt_lo
   0DFF F6 C8 AA      [ 5] 1171 	ldb	_the_player
   0E02 4F            [ 2] 1172 	clra		;zero_extendqihi: R:b -> R:d
   0E03 1F 01         [ 6] 1173 	tfr	d,x
   0E05 C6 90         [ 2] 1174 	ldb	#-112
   0E07 E7 E2         [ 6] 1175 	stb	,-s
   0E09 E6 89 07 88   [ 8] 1176 	ldb	_PLAYER_STATIC_X_LUT,x
   0E0D BD 0F 13      [ 8] 1177 	jsr	__Moveto_d
   0E10 C6 10         [ 2] 1178 	ldb	#16
   0E12 D7 04         [ 4] 1179 	stb	*_dp_VIA_t1_cnt_lo
   0E14 8E 08 BF      [ 3] 1180 	ldx	#_vl_player_left2
   0E17 BD F4 10      [ 8] 1181 	jsr	___Draw_VLp
   0E1A BD F3 54      [ 8] 1182 	jsr	___Reset0Ref
   0E1D C6 7F         [ 2] 1183 	ldb	#127
   0E1F D7 04         [ 4] 1184 	stb	*_dp_VIA_t1_cnt_lo
   0E21 F6 C8 AA      [ 5] 1185 	ldb	_the_player
   0E24 4F            [ 2] 1186 	clra		;zero_extendqihi: R:b -> R:d
   0E25 1F 01         [ 6] 1187 	tfr	d,x
   0E27 C6 90         [ 2] 1188 	ldb	#-112
   0E29 E7 E2         [ 6] 1189 	stb	,-s
   0E2B E6 89 07 88   [ 8] 1190 	ldb	_PLAYER_STATIC_X_LUT,x
   0E2F BD 0F 13      [ 8] 1191 	jsr	__Moveto_d
   0E32 C6 10         [ 2] 1192 	ldb	#16
   0E34 D7 04         [ 4] 1193 	stb	*_dp_VIA_t1_cnt_lo
   0E36 32 63         [ 5] 1194 	leas	3,s
   0E38 8E 09 23      [ 3] 1195 	ldx	#_vl_player_left3
   0E3B 7E F4 10      [ 4] 1196 	jmp	___Draw_VLp
                           1197 	.globl	__player_draw_right
   0E3E                    1198 __player_draw_right:
   0E3E BD F3 54      [ 8] 1199 	jsr	___Reset0Ref
   0E41 C6 7F         [ 2] 1200 	ldb	#127
   0E43 D7 04         [ 4] 1201 	stb	*_dp_VIA_t1_cnt_lo
   0E45 F6 C8 AA      [ 5] 1202 	ldb	_the_player
   0E48 4F            [ 2] 1203 	clra		;zero_extendqihi: R:b -> R:d
   0E49 1F 01         [ 6] 1204 	tfr	d,x
   0E4B C6 90         [ 2] 1205 	ldb	#-112
   0E4D E7 E2         [ 6] 1206 	stb	,-s
   0E4F E6 89 07 88   [ 8] 1207 	ldb	_PLAYER_STATIC_X_LUT,x
   0E53 BD 0F 13      [ 8] 1208 	jsr	__Moveto_d
   0E56 C6 10         [ 2] 1209 	ldb	#16
   0E58 D7 04         [ 4] 1210 	stb	*_dp_VIA_t1_cnt_lo
   0E5A 8E 09 63      [ 3] 1211 	ldx	#_vl_player_right1
   0E5D BD F4 10      [ 8] 1212 	jsr	___Draw_VLp
   0E60 BD F3 54      [ 8] 1213 	jsr	___Reset0Ref
   0E63 C6 7F         [ 2] 1214 	ldb	#127
   0E65 D7 04         [ 4] 1215 	stb	*_dp_VIA_t1_cnt_lo
   0E67 F6 C8 AA      [ 5] 1216 	ldb	_the_player
   0E6A 4F            [ 2] 1217 	clra		;zero_extendqihi: R:b -> R:d
   0E6B 1F 01         [ 6] 1218 	tfr	d,x
   0E6D C6 90         [ 2] 1219 	ldb	#-112
   0E6F E7 E2         [ 6] 1220 	stb	,-s
   0E71 E6 89 07 88   [ 8] 1221 	ldb	_PLAYER_STATIC_X_LUT,x
   0E75 BD 0F 13      [ 8] 1222 	jsr	__Moveto_d
   0E78 C6 10         [ 2] 1223 	ldb	#16
   0E7A D7 04         [ 4] 1224 	stb	*_dp_VIA_t1_cnt_lo
   0E7C 8E 09 AF      [ 3] 1225 	ldx	#_vl_player_right2
   0E7F BD F4 10      [ 8] 1226 	jsr	___Draw_VLp
   0E82 BD F3 54      [ 8] 1227 	jsr	___Reset0Ref
   0E85 C6 7F         [ 2] 1228 	ldb	#127
   0E87 D7 04         [ 4] 1229 	stb	*_dp_VIA_t1_cnt_lo
   0E89 F6 C8 AA      [ 5] 1230 	ldb	_the_player
   0E8C 4F            [ 2] 1231 	clra		;zero_extendqihi: R:b -> R:d
   0E8D 1F 01         [ 6] 1232 	tfr	d,x
   0E8F C6 90         [ 2] 1233 	ldb	#-112
   0E91 E7 E2         [ 6] 1234 	stb	,-s
   0E93 E6 89 07 88   [ 8] 1235 	ldb	_PLAYER_STATIC_X_LUT,x
   0E97 BD 0F 13      [ 8] 1236 	jsr	__Moveto_d
   0E9A C6 10         [ 2] 1237 	ldb	#16
   0E9C D7 04         [ 4] 1238 	stb	*_dp_VIA_t1_cnt_lo
   0E9E 32 63         [ 5] 1239 	leas	3,s
   0EA0 8E 0A 13      [ 3] 1240 	ldx	#_vl_player_right3
   0EA3 7E F4 10      [ 4] 1241 	jmp	___Draw_VLp
                           1242 	.globl	_check_collision
   0EA6                    1243 _check_collision:
   0EA6 39            [ 5] 1244 	rts
ASxxxx Assembler V05.50  (Motorola 6809)                                Page 1
Hexadecimal [16-Bits]                                 Fri Jun 13 23:47:53 2025

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L10                03CC R   |   3 L12                0378 R
  3 L13                0403 R   |   3 L15                03C3 R
  3 L16                0379 R   |   3 L20                05AA R
  3 L21                04E4 R   |   3 L24                04F5 R
  3 L25                04D5 R   |   3 L26                0615 R
  3 L27                0561 R   |   3 L28                04F6 R
  3 L8                 0415 R   |   3 L9                 0367 R
  3 _PLAYER_ANIMAT     000B GR  |   3 _PLAYER_ANIMAT     0000 GR
  3 _PLAYER_DRAW_L     0019 GR  |   3 _PLAYER_STATIC     0016 GR
  3 _SP1_LEFT_MID_     0046 GR  |   3 _SP1_MID_LEFT_     001F GR
  3 _SP1_MID_RIGHT     0039 GR  |   3 _SP1_RIGHT_MID     002C GR
    __Moveto_d         **** GX  |     ___Draw_VLp        **** GX
    ___Intensity_5     **** GX  |     ___Reset0Ref       **** GX
  3 __player_draw_     0664 GR  |   3 __player_draw_     061E GR
  3 __player_draw_     06CC GR  |   3 _check_collisi     0734 GR
    _dp_VIA_t1_cnt     **** GX  |   3 _player_change     02E1 GR
  3 _player_change     0480 GR  |   3 _player_draw       0062 GR
  3 _player_init       0053 GR  |     _the_game          **** GX
  2 _the_player        0000 GR  |   3 _vl_player_lef     0101 GR
  3 _vl_player_lef     014D GR  |   3 _vl_player_lef     01B1 GR
  3 _vl_player_mid     0078 GR  |   3 _vl_player_mid     00B8 GR
  3 _vl_player_rig     01F1 GR  |   3 _vl_player_rig     023D GR
  3 _vl_player_rig     02A1 GR  |   3 _vl_term_0_46      00B7 R
  3 _vl_term_1_83      0100 R   |   3 _vl_term_2_123     014C R
  3 _vl_term_3_170     01B0 R   |   3 _vl_term_4_203     01F0 R
  3 _vl_term_5_243     023C R   |   3 _vl_term_6_290     02A0 R
  3 _vl_term_7_323     02E0 R

ASxxxx Assembler V05.50  (Motorola 6809)                                Page 2
Hexadecimal [16-Bits]                                 Fri Jun 13 23:47:53 2025

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .bss             size    4   flags    0
   3 .text            size  735   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

