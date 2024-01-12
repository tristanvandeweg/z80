;Large 2x2 sprite font for the LCD
;Copyright (C) 2024  Tristan van de Weg & Marijn Vollenberg
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

_fontLarge
_FontDim .equ $22			;Font size in 4x4 sprites (2x2)

.byte _FontDim

;--------------------------------
;Jump Table
;--------------------------------
.byte _Char_excl;!
.byte _Char_quot;"
.byte _Char_pnd	;#
.byte _Char_dolr;$
.byte _Char_pcnt;%
.byte _Char_and	;&
.byte _Char_apos;'
.byte _Char_lbra;(
.byte _Char_rbra;)
.byte _Char_ast	;*
.byte _Char_plus;+
.byte _Char_comm;,
.byte _Char_min	;-
.byte _Char_dot	;.
.byte _Char_slsh;/

.byte _Num_0	;0
.byte _Num_1	;1
.byte _Num_2	;2
.byte _Num_3	;3
.byte _Num_4	;4
.byte _Num_5	;5
.byte _Num_6	;6
.byte _Num_7	;7
.byte _Num_8	;8
.byte _Num_9	;9

.byte _Char_col	;:
.byte _Char_scol;;
.byte _Char_larr;<
.byte _Char_eql ;=
.byte _Char_rarr;>
.byte _Char_ques;?
.byte _Char_at	;@

.byte _Cap_a	;A
.byte _Cap_b	;B
.byte _Cap_c	;C
.byte _Cap_d	;D
.byte _Cap_e	;E
.byte _Cap_f	;F
.byte _Cap_g	;G
.byte _Cap_h	;H
.byte _Cap_i	;I
.byte _Cap_j	;J
.byte _Cap_k	;K
.byte _Cap_l	;L
.byte _Cap_m	;M
.byte _Cap_n	;N
.byte _Cap_o	;O
.byte _Cap_p	;P
.byte _Cap_q	;Q
.byte _Cap_r	;R
.byte _Cap_s	;S
.byte _Cap_t	;T
.byte _Cap_u	;U
.byte _Cap_v	;V
.byte _Cap_w	;W
.byte _Cap_x	;X
.byte _Cap_y	;Y
.byte _Cap_z	;Z

.byte _Char_lsbr;[
.byte _Char_bsl	;\
.byte _Char_rsbr;]
.byte _Char_uarr;^
.byte _Char_lmin;_
.byte _Char_gve	;`

;--------------------------------
;Capital Letters
;--------------------------------

;a
_Cap_a:
.byte %00000011	;....
.byte %01000100	;..%%
				;.%..
				;.%..

.byte %00001100	;....
.byte %00100010	;%%..
				;..%.
				;..%.

.byte %01110100	;.%%%
.byte %01000100	;.%..
				;.%..
				;.%..

.byte %11100010	;%%%.
.byte %00100010	;..%.
				;..%.
				;..%.

;........
;..%%%%..
;.%....%.
;.%....%.
;.%%%%%%.
;.%....%.
;.%....%.
;.%....%.

;B
_Cap_b:
.byte %00000111	;....
.byte %01000100	;.%%%
				;.%..
				;.%..

.byte %00001100	;....
.byte %00100010	;%%..
				;..%.
				;..%.

.byte %01110100	;.%%%
.byte %01000111	;.%..
				;.%..
				;.%%%

.byte %11000010	;%%..
.byte %00101100	;..%.
				;..%.
				;%%..

;........
;.%%%%%..
;.%....%.
;.%....%.
;.%%%%%..
;.%....%.
;.%....%.
;.%%%%%..

;C TODO:
_Cap_c:
.byte %00000111	;....
.byte %01000100	;.%%%
				;.%..
				;.%..

.byte %00001100	;....
.byte %00100010	;%%..
				;..%.
				;..%.

.byte %01110100	;.%%%
.byte %01000111	;.%..
				;.%..
				;.%%%

.byte %11000010	;%%..
.byte %00101100	;..%.
				;..%.
				;%%..

;........
;..%%%%..
;.%......
;.%......
;.%......
;.%......
;.%......
;..%%%%..

;D TODO:
.byte %00000111	;....
.byte %01000100	;.%%%
				;.%..
				;.%..

.byte %00001100	;....
.byte %00100010	;%%..
				;..%.
				;..%.

.byte %01110100	;.%%%
.byte %01000111	;.%..
				;.%..
				;.%%%

.byte %11000010	;%%..
.byte %00101100	;..%.
				;..%.
				;%%..

;........
;.%%%%%..
;.%....%.
;.%....%.
;.%....%.
;.%....%.
;.%....%.
;.%%%%%..

;E TODO:
.byte %00000111	;....
.byte %01000100	;.%%%
				;.%..
				;.%..

.byte %00001100	;....
.byte %00100010	;%%..
				;..%.
				;..%.

.byte %01110100	;.%%%
.byte %01000111	;.%..
				;.%..
				;.%%%

.byte %11000010	;%%..
.byte %00101100	;..%.
				;..%.
				;%%..

;........
;.%%%%%..
;.%......
;.%......
;.%%%%%..
;.%......
;.%......
;.%%%%%..

;F TODO:
.byte %00000111	;....
.byte %01000100	;.%%%
				;.%..
				;.%..

.byte %00001100	;....
.byte %00100010	;%%..
				;..%.
				;..%.

.byte %01110100	;.%%%
.byte %01000111	;.%..
				;.%..
				;.%%%

.byte %11000010	;%%..
.byte %00101100	;..%.
				;..%.
				;%%..

;........
;.%%%%%..
;.%......
;.%......
;.%%%%%..
;.%......
;.%......
;.%......

;G TODO:
.byte %00000111	;....
.byte %01000100	;.%%%
				;.%..
				;.%..

.byte %00001100	;....
.byte %00100010	;%%..
				;..%.
				;..%.

.byte %01110100	;.%%%
.byte %01000111	;.%..
				;.%..
				;.%%%

.byte %11000010	;%%..
.byte %00101100	;..%.
				;..%.
				;%%..

;........
;..%%%%..
;.%......
;.%......
;.%...%%.
;.%....%.
;.%....%.
;..%%%%%.

;H TODO:
.byte %00000111	;....
.byte %01000100	;.%%%
				;.%..
				;.%..

.byte %00001100	;....
.byte %00100010	;%%..
				;..%.
				;..%.

.byte %01110100	;.%%%
.byte %01000111	;.%..
				;.%..
				;.%%%

.byte %11000010	;%%..
.byte %00101100	;..%.
				;..%.
				;%%..

;........
;.%....%.
;.%....%.
;.%....%.
;.%%%%%%.
;.%....%.
;.%....%.
;.%....%.

;I TODO:
.byte %00000111	;....
.byte %01000100	;.%%%
				;.%..
				;.%..

.byte %00001100	;....
.byte %00100010	;%%..
				;..%.
				;..%.

.byte %01110100	;.%%%
.byte %01000111	;.%..
				;.%..
				;.%%%

.byte %11000010	;%%..
.byte %00101100	;..%.
				;..%.
				;%%..

;........
;.%%%%%..
;...%....
;...%....
;...%....
;...%....
;...%....
;.%%%%%..

;J TODO:
.byte %00000111	;....
.byte %01000100	;.%%%
				;.%..
				;.%..

.byte %00001100	;....
.byte %00100010	;%%..
				;..%.
				;..%.

.byte %01110100	;.%%%
.byte %01000111	;.%..
				;.%..
				;.%%%

.byte %11000010	;%%..
.byte %00101100	;..%.
				;..%.
				;%%..

;........
;..%%%%%.
;....%...
;....%...
;....%...
;....%...
;....%...
;..%%%...

;K TODO:
.byte %00000111	;....
.byte %01000100	;.%%%
				;.%..
				;.%..

.byte %00001100	;....
.byte %00100010	;%%..
				;..%.
				;..%.

.byte %01110100	;.%%%
.byte %01000111	;.%..
				;.%..
				;.%%%

.byte %11000010	;%%..
.byte %00101100	;..%.
				;..%.
				;%%..

;........
;.%...%..
;.%..%...
;.%.%....
;.%%.....
;.%.%....
;.%..%...
;.%...%..

;L TODO:
.byte %00000111	;....
.byte %01000100	;.%%%
				;.%..
				;.%..

.byte %00001100	;....
.byte %00100010	;%%..
				;..%.
				;..%.

.byte %01110100	;.%%%
.byte %01000111	;.%..
				;.%..
				;.%%%

.byte %11000010	;%%..
.byte %00101100	;..%.
				;..%.
				;%%..

;........
;.%......
;.%......
;.%......
;.%......
;.%......
;.%......
;.%%%%%%.