;Include file for easier assembly programming
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

;--------------------------------
;Memory Locations
;--------------------------------
.equ _RAM, $2000					;=8192
.equ _ROM, 0						;=0
.equ _ExtMem, $4000				;=16384
.equ _StackSize, 255				;=$ff
.equ _StackTop, $3fff			;Top of the stack
;--------------------------------
;I/O Locations
;--------------------------------
.equ _Display, $00
.equ _DisplayCmd, $01
;--------------------------------
;ROM Calls
;--------------------------------
.ifndef OSfile					;Do not define ROMcalls for OS source
.org $4000
.equ _PrintS, $0040				;Address of string to print in hl, string must end in 0
.equ _PrintB, $0000				;Byte to print in a TODO fix addressing
.endif							;End of non-OS ROMcalls