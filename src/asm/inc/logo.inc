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

.byte fl_FontDim

;Jump table
.dw il_logo

;logo
il_logo:
.byte



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