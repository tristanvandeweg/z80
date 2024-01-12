;Small 1x1 sprite font
;Copyright (C) 2023-2024  Tristan van de Weg & Marijn Vollenberg
;
;    This program is free software; you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation; either version 2 of the License, or
;    (at your option) any later version.
;
;    This program is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License along
;    with this program; if not, write to the Free Software Foundation, Inc.,
;    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

_fontSmall ;.equ $1F00		;At the last part of ROM
.echo ""
.echo "Small font starting address: ",_fontSmall

_FontDim .equ $11			;Font size in 4x4 sprites (1x1)

.byte _FontDim

;--------------------------------
;Jump Table
;--------------------------------
.dw _Char_excl;!
.dw _Char_quot;"
.dw _Char_pnd	;#
.dw _Char_dolr;$
.dw _Char_pcnt;%
.dw _Char_and	;&
.dw _Char_apos;'
.dw _Char_lbra;(
.dw _Char_rbra;)
.dw _Char_ast	;*
.dw _Char_plus;+
.dw _Char_comm;,
.dw _Char_min	;-
.dw _Char_dot	;.
.dw _Char_slsh;/

.dw _Num_0	;0
.dw _Num_1	;1
.dw _Num_2	;2
.dw _Num_3	;3
.dw _Num_4	;4
.dw _Num_5	;5
.dw _Num_6	;6
.dw _Num_7	;7
.dw _Num_8	;8
.dw _Num_9	;9

.dw _Char_col	;:
.dw _Char_scol;;
.dw _Char_larr;<
.dw _Char_eql ;=
.dw _Char_rarr;>
.dw _Char_ques;?
.dw _Char_at	;@

.dw _Cap_a	;A
.dw _Cap_b	;B
.dw _Cap_c	;C
.dw _Cap_d	;D
.dw _Cap_e	;E
.dw _Cap_f	;F
.dw _Cap_g	;G
.dw _Cap_h	;H
.dw _Cap_i	;I
.dw _Cap_j	;J
.dw _Cap_k	;K
.dw _Cap_l	;L
.dw _Cap_m	;M
.dw _Cap_n	;N
.dw _Cap_o	;O
.dw _Cap_p	;P
.dw _Cap_q	;Q
.dw _Cap_r	;R
.dw _Cap_s	;S
.dw _Cap_t	;T
.dw _Cap_u	;U
.dw _Cap_v	;V
.dw _Cap_w	;W
.dw _Cap_x	;X
.dw _Cap_y	;Y
.dw _Cap_z	;Z

.dw _Char_lsbr;[
.dw _Char_bsl	;\
.dw _Char_rsbr;]
.dw _Char_uarr;^
.dw _Char_lmin;_
.dw _Char_gve	;`

.dw _Low_a	;a
.dw _Low_b	;b
.dw _Low_c	;c
.dw _Low_d	;d
.dw _Low_e	;e
.dw _Low_f	;f
.dw _Low_g	;g
.dw _Low_h	;h
.dw _Low_i	;i
.dw _Low_j	;j
.dw _Low_k	;k
.dw _Low_l	;l
.dw _Low_m	;m
.dw _Low_n	;n
.dw _Low_o	;o
.dw _Low_p	;p
.dw _Low_q	;q
.dw _Low_r	;r
.dw _Low_s	;s
.dw _Low_t	;t
.dw _Low_u	;u
.dw _Low_v	;v
.dw _Low_w	;w
.dw _Low_x	;x
.dw _Low_y	;y
.dw _Low_z	;z

_Char_lsbr .equ 0
_Char_bsl .equ 0
_Char_rsbr .equ 0
_Char_uarr .equ 0
_Char_lmin .equ 0
_Char_gve .equ 0

__CharStart
.echo "Start of characters: ",__CharStart

;--------------------------------
;Special Characters
;--------------------------------
;.seek _fontSmall+66

;!
_Char_excl:
.byte %01000100
.byte %00000100
;.%..
;.%..
;....
;.%..

;"
_Char_quot:
.byte %10101010
.byte %00000000
;%.%.
;%.%.
;....
;....

;# TODO:
_Char_pnd:
.byte %00000000
.byte %00000000
;
;
;
;

;$
_Char_dolr:
.byte %0110110
.byte %00110110
;.%%.
;%%..
;.%%.
;%%..

;%
_Char_pcnt:
.byte %10010010
.byte %01001001
;%..%
;..%.
;.%..
;%..%

;& TODO:
_Char_and:
.byte %01000100
.byte %00000100
;.%%.
;.%%.
;%..%
;.%%%

;'
_Char_apos:
.byte %01000100
.byte %00000000
;.%..
;.%..
;....
;....

;(
_Char_lbra:
.byte %01001000
.byte %10000100
;.%..
;%...
;%...
;.%..

;)
_Char_rbra:
.byte %00100001
.byte %00010010
;..%.
;...%
;...%
;..%.

;*
_Char_ast:
.byte %00001000
.byte %00000000
;....
;.%..
;....
;....

;+
_Char_plus:
.byte %00000100
.byte %11100100
;....
;.%..
;%%%.
;.%..

;,
_Char_comm:
.byte %00000000
.byte %01001000
;....
;....
;.%..
;%...

;-
_Char_min:
.byte %00000000
.byte %11100000
;....
;....
;%%%.
;....

;.
_Char_dot:
.byte %00000000
.byte %00001000
;....
;....
;....
;%...

;/
_Char_slsh:
.byte %00010010
.byte %01001000
;...%
;..%.
;.%..
;%...

;--------------------------------
;Special Characters (2)
;--------------------------------
;.seek _fontSmall+116

;:
_Char_col:
.byte %00000100
.byte %00000100
;....
;.%..
;....
;.%..

;;
_Char_scol:
.byte %01000000
.byte %01001000
;.%..
;....
;.%..
;%...

;<
_Char_larr:
.byte %00000110
.byte %10000110
;....
;.%%.
;%...
;.%%.

;=
_Char_eql:
.byte %00001111
.byte %00001111
;....
;%%%%
;....
;%%%%

;>
_Char_rarr:
.byte %00000110
.byte %00010110
;....
;.%%.
;...%
;.%%.

;? TODO:
_Char_ques:
.byte %01100110
.byte %00000100
;.%%.
;.%..
;....
;.%..

;@ TODO:
_Char_at:
.byte %01101001
.byte %10001110
;.%%.
;%..%
;%...
;%%%.

;--------------------------------
;Special Characters (3)
;--------------------------------
;.seek _fontSmall+246

;{
.byte %00100100
.byte %11000010
;..%.
;.%..
;%%..
;..%.

;|
.byte %01100110
.byte %01100110
;.%%.
;.%%.
;.%%.
;.%%.

;}
.byte %01000010
.byte %00110100
;.%..
;..%.
;..%%
;.%..

;~
.byte %00000101
.byte %10100000
;....
;.%.%
;%.%.
;....

;--------------------------------
;Numbers
;--------------------------------
;.seek _fontSmall+96

;0
_Num_0:
.byte %01101011
.byte %11010110
;.%%.
;%.%%
;%%.%
;.%%.

;1
_Num_1:
.byte %01100010
.byte %00100111
;.%%.
;..%.
;..%.
;.%%%

;2
_Num_2:
.byte %01101001
.byte %00101111
;.%%.
;%..%
;..%.
;%%%%

;3
_Num_3:
.byte %01110001
.byte %01110111
;.%%%
;...%
;.%%%
;.%%%

;4
_Num_4:
.byte %01101010
.byte %11110010
;.%%.
;%.%.
;%%%%
;..%.

;5
_Num_5:
.byte %11111110
.byte %00011110
;%%%%
;%%%.
;...%
;%%%.

;6
_Num_6:
.byte %00010110
.byte %10011111
;...%
;.%%.
;%..%
;%%%%

;7
_Num_7:
.byte %11110010
.byte %01001000
;%%%%
;..%.
;.%..
;%...

;8 TODO:
_Num_8:
.byte %10010110
.byte %10010110
;%..%
;.%%.
;%..%
;.%%.

;9
_Num_9:
.byte %01110111
.byte %00100100
;.%%%
;.%%%
;..%.
;.%..



;--------------------------------
;Capital Font
;--------------------------------
;.seek _fontSmall+130

;A
_Cap_a:
.byte %01101001
.byte %11111001
;.%%.
;%..%
;%%%%
;%..%

;B TODO:
_Cap_b:
.byte %11111101
.byte %10111111
;%%%%
;%%.%
;%.%%
;%%%%

;C
_Cap_c:
.byte %11111000
.byte %10001111
;%%%%
;%...
;%...
;%%%%

;D
_Cap_d:
.byte %11101001
.byte %10011110
;%%%.
;%..%
;%..%
;%%%.

;E
_Cap_e:
.byte %11111100
.byte %10001111
;%%%%
;%%..
;%...
;%%%%

;F
_Cap_f:
.byte %11111000
.byte %11101000
;%%%%
;%...
;%%%.
;%...

;G
_Cap_g:
.byte %11111000
.byte %10011111
;%%%%
;%...
;%..%
;%%%%

;H
_Cap_h:
.byte %10011111
.byte %10011001
;%..%
;%%%%
;%..%
;%..%

;I
_Cap_i:
.byte %11110110
.byte %01101111
;%%%%
;.%%.
;.%%.
;%%%%

;J
_Cap_j:
.byte %11110110
.byte %01101110
;%%%%
;.%%.
;.%%.
;%%%.

;K
_Cap_k:
.byte %11011110
.byte %11101101
;%%.%
;%%%.
;%%%.
;%%.%

;L
_Cap_l:
.byte %10001000
.byte %10001111
;%...
;%...
;%...
;%%%%

;M
_Cap_m:
.byte %10111111
.byte %11011001
;%.%%
;%%%%
;%%.%
;%..%

;N
_Cap_n:
.byte %10011101
.byte %10111001
;%..%
;%%.%
;%.%%
;%..%

;O
_Cap_o:
.byte %11111001
.byte %10011111
;%%%%
;%..%
;%..%
;%%%%

;P
_Cap_p:
.byte %11111001
.byte %11111000
;%%%%
;%..%
;%%%%
;%...

;Q
_Cap_q:
.byte %11111001
.byte %10111111
;%%%%
;%..%
;%.%%
;%%%%

;R
_Cap_r:
.byte %11111001
.byte %10101001
;%%%%
;%..%
;%.%.
;%..%

;S
_Cap_s:
.byte %11111100
.byte %00111111
;%%%%
;%%..
;..%%
;%%%%

;T
_Cap_t:
.byte %11110110
.byte %01100110
;%%%%
;.%%.
;.%%.
;.%%.

;U
_Cap_u:
.byte %10011001
.byte %10011111
;%..%
;%..%
;%..%
;%%%%

;V
_Cap_v:
.byte %10011001
.byte %10010110
;%..%
;%..%
;%..%
;.%%.

;W
_Cap_w:
.byte %10011011
.byte %11111101
;%..%
;%.%%
;%%%%
;%%.%

;X
_Cap_x:
.byte %10010110
.byte %01101001
;%..%
;.%%.
;.%%.
;%..%

;Y
_Cap_y:
.byte %10011111
.byte %01100110
;%..%
;%%%%
;.%%.
;.%%.

;Z
_Cap_z:
.byte %11110010
.byte %01001111
;%%%%
;..%.
;.%..
;%%%%

;--------------------------------
;Lowercase Font
;--------------------------------
;.seek _fontSmall+194

;A TODO:
_Low_a:
.byte %01101001
.byte %11111001
;.%%.
;%..%
;%%%%
;%..%

;b
_Low_b:
.byte %10001110
.byte %10101110
;%...
;%%%.
;%.%.
;%%%.

;c
_Low_c:
.byte %00001110
.byte %10001110
;....
;%%%.
;%...
;%%%.

;d
_Low_d:
.byte %00010111
.byte %01010111
;...%
;.%%%
;.%.%
;.%%%

;e
_Low_e:
.byte %01101111
.byte %10000110
;.%%.
;%%%%
;%...
;.%%.

;f
_Low_f:
.byte %01101000
.byte %11101000
;.%%.
;%...
;%%%.
;%...

;g
_Low_g:
.byte %11111111
.byte %00010111
;%%%%
;%%%%
;...%
;.%%%

;h
_Low_h:
.byte %10001000
.byte %11111001
;%...
;%...
;%%%%
;%..%

;i
_Low_i:
.byte %01000000
.byte %01000100
;.%..
;....
;.%..
;.%..

;j
_Low_j:
.byte %00100000
.byte %00101110
;..%.
;....
;..%.
;%%%.

;k
_Low_k:
.byte %10001010
.byte %11001010
;%...
;%.%.
;%%..
;%.%.

;l
_Low_l:
.byte %01000100
.byte %01000100
;.%..
;.%..
;.%..
;.%..

;M TODO:
_Low_m:
.byte %10111111
.byte %11011001
;%.%%
;%%%%
;%%.%
;%..%

;n
_Low_n:
.byte %00001110
.byte %10011001
;....
;%%%.
;%..%
;%..%

;o
_Low_o:
.byte %00001110
.byte %10101110
;....
;%%%.
;%.%.
;%%%.

;p
_Low_p:
.byte %11101010
.byte %11001000
;%%%.
;%.%.
;%%..
;%...

;q
_Low_q:
.byte %01110101
.byte %00110001
;.%%%
;.%.%
;..%%
;...%

;r
_Low_r:
.byte %00001110
.byte %10001000
;....
;%%%.
;%...
;%...

;s
_Low_s:
.byte %00110100
.byte %00101100
;..%%
;.%..
;..%.
;%%..

;t
_Low_t:
.byte %01001110
.byte %01000110
;.%..
;%%%.
;.%..
;.%%.

;u
_Low_u:
.byte %00001001
.byte %10010111
;....
;%..%
;%..%
;.%%%

;v
_Low_v:
.byte %00001001
.byte %10010110
;....
;%..%
;%..%
;.%%.

;W TODO:
_Low_w:
.byte %10011011
.byte %11111101
;%..%
;%.%%
;%%%%
;%%.%

;x
_Low_x:
.byte %00001010
.byte %01001010
;....
;%.%.
;.%..
;%.%.

;y
_Low_y:
.byte %01010111
.byte %00100100
;.%.%
;.%%%
;..%.
;.%..

;z
_Low_z:
.byte %00001110
.byte %01101110
;....
;%%%.
;.%..
;%%%.

__FontEnd
.echo "Small font jump table size: ",__CharStart-_fontSmall
.echo "Small font sprite size: ",__FontEnd-__CharStart
.echo "Small font total size: ",__FontEnd-_fontSmall

.echo ""