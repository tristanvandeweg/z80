;Characters for the LCD
;Copyright (C) 2023  Tristan van de Weg & Marijn Vollenberg
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
.align _FontStart+130

.equ _fontWidth, 4			;Font width in bits

;A
.byte %0110100111111001
;.%%.
;%..%
;%%%%
;%..%

;B
.byte %1111110110111111
;%%%%
;%%.%
;%.%%
;%%%%

;C
.byte %1111100010001111
;%%%%
;%...
;%...
;%%%%

;D
.byte %1110100110011110
;%%%.
;%..%
;%..%
;%%%.

;E
.byte %1111110010001111
;%%%%
;%%..
;%...
;%%%%

;F
.byte %1111100011101000
;%%%%
;%...
;%%%.
;%...

;G
.byte %1111100010011111
;%%%%
;%...
;%..%
;%%%%

;H
.byte %1001111110011001
;%..%
;%%%%
;%..%
;%..%

;I
.byte %1111011001101111
;%%%%
;.%%.
;.%%.
;%%%%

;J
.byte %1111011001101110
;%%%%
;.%%.
;.%%.
;%%%.

;K
.byte %1101111011101101
;%%.%
;%%%.
;%%%.
;%%.%

;L
.byte %1000100010001111
;%...
;%...
;%...
;%%%%

;M
.byte %1011111111011001
;%.%%
;%%%%
;%%.%
;%..%

;N
.byte %1001110110111001
;%..%
;%%.%
;%.%%
;%..%

;O
.byte %1111100110011111
;%%%%
;%..%
;%..%
;%%%%

;P
.byte %1111100111111000
;%%%%
;%..%
;%%%%
;%...

;Q
.byte %1111100110111111
;%%%%
;%..%
;%.%%
;%%%%

;R
.byte %1111100110101001
;%%%%
;%..%
;%.%.
;%..%

;S
.byte %1111110000111111
;%%%%
;%%..
;..%%
;%%%%

;T
.byte %1111011001100110
;%%%%
;.%%.
;.%%.
;.%%.

;U
.byte %1001100110011111
;%..%
;%..%
;%..%
;%%%%

;V
.byte %1001100110010110
;%..%
;%..%
;%..%
;.%%.

;W
.byte %1001101111111101
;%..%
;%.%%
;%%%%
;%%.%

;X
.byte %1001011001101001
;%..%
;.%%.
;.%%.
;%..%

;Y
.byte %1001111101100110
;%..%
;%%%%
;.%%.
;.%%.

;Z
.byte %1111001001001111
;%%%%
;..%.
;.%..
;%%%%