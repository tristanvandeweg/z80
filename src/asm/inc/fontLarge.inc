;Large 5*8 font for the LCD
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

_FontWidth	.equ 5			;Font width in bits
_FontLength	.equ 5			;Font length in bytes

;--------------------------------
;Capital Letters
;--------------------------------

;A
.byte %00000011
.byte %10100011
.byte %00011111
.byte %11000110
.byte %00110001
;.....
;.%%%.
;%...%
;%...%
;%%%%%
;%...%
;%...%
;%...%

;B
.byte %00000111
.byte %10100011
.byte %00011111
.byte %01000110
.byte %00111110
;.....	5
;%%%%.	3 2
;%...%	  5
;%...%	  1 4
;%%%%.	    4 1
;%...%	      5
;%...%	      2 3
;%%%%.	        5
;		8 8 8 8 8