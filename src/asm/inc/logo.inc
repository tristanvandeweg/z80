;Logo sprite
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

_SpriteWidth	.equ 16
_SpriteLength	.equ 15

;Z
.byte %0111111111111110
.byte %0110000000001100
.byte %0100000000110000
.byte %0000000011000000
.byte %0000001100000000
.byte %0000110000000010
.byte %0011000000000110
.byte %0111111111111110
;.%%%%%%%%%%%%%%.
;.%%.........%%..
;.%........%%....
;........%%......
;......%%........
;....%%........%.
;..%%.........%%.
;.%%%%%%%%%%%%%%.

;80
.byte %0000000000000000
.byte %0111000111000000
.byte %1000101000100000
.byte %1000101000100000
.byte %0111001000100000
.byte %1000101000100000
.byte %1000101000100000
.byte %0111000111000000
;................
;.%%%...%%%......
;%...%.%...%.....
;%...%.%...%.....
;.%%%..%...%.....
;%...%.%...%.....
;%...%.%...%.....
;.%%%...%%%......