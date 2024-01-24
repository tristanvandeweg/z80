;Logo sprite
;Copyright (C) 2024  Tristan van de Weg
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

_imgLogo
.echo ""
.echo "Logo starting address: ",_imgLogo

il_FontDim .equ $44			;Font size in 4x4 sprites (4x4)

.byte il_FontDim

;Jump table
.dw il_logo

;logo
il_logo:
.byte %00000111	;.... 0000
.byte %01100101	;.%%% 0111
				;.%%. 0110
				;.%.% 0101

.byte %00001111	;.... 0000
.byte %11000010	;%%%% 1111
				;%%.. 1100
				;..%. 0010

.byte %00001111	;.... 0000
.byte %00000000	;%%%% 1111
				;.... 0000
				;.... 0000

.byte %00001000	;.... 0000
.byte %01001000	;%%%. 1110
				;.%.. 0100
				;%... 1000

;Second line

.byte %00010000	;...% 0001
.byte %00010001	;.... 0000
				;...% 0001
				;...% 0001

.byte %00001100	;..%. 0010
.byte %00100010	;%%.. 1100
				;..%. 0010
				;..%. 0010

.byte %00010010	;...% 0001
.byte %01001011	;..%. 0010
				;.%.. 0100
				;%.%% 1011

.byte %00000000	;.... 0000
.byte %00000000	;.... 0000
				;.... 0000
				;.... 0000

;Third line

.byte %00000000	;.... 0000
.byte %00000000	;.... 0000
				;.... 0000
				;.... 0000

.byte %11010010	;%%.% 1101
.byte %01001000	;..%. 0010
				;.%.. 0100
				;%... 1000

.byte %01000100	;.%.. 0100
.byte %01000100	;.%.. 0100
				;.%.. 0100
				;.%.. 0100

.byte %10001000	;%... 1000
.byte %10001000	;%... 1000
				;%... 1000
				;%... 1000

;Fourth line

.byte %00010010	;...% 0001
.byte %01110000	;..%. 0010
				;.%%% 0111
				;.... 0000

.byte %00000000	;.... 0000
.byte %11110000	;.... 0000
				;%%%% 1111
				;.... 0000

.byte %01000011	;.%.. 0100
.byte %11110000	;..%% 0011
				;%%%% 1111
				;.... 0000

.byte %10100110	;%.%. 1010
.byte %11100000	;.%%. 0110
				;%%%. 1110
				;.... 0000

;................
;.%%%%%%%%%%%%%%.
;.%%.%%.......%..
;.%.%..%.....%...
;...%..%....%....
;....%%....%.....
;...%..%..%......
;...%..%.%.%%....
;....%%.%.%..%...
;......%..%..%...
;.....%...%..%...
;....%....%..%...
;...%.....%..%.%.
;..%.......%%.%%.
;.%%%%%%%%%%%%%%.
;................