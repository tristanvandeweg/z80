;Include file for easier assembly programming
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

;--------------------------------
;Fixed Values
;--------------------------------
_ExtPrgmInd	.equ $80			;=Byte to indicate external program
_StackSize 	.equ $ff			;=255
_VRAMSize	.equ $400			;=1kiB
;--------------------------------
;Memory Locations
;--------------------------------
_RAM 		.equ $2000			;=8192
_ROM 		.equ 0				;=0
_ExtMem 	.equ $4000			;=16384

_StackTop 	.equ $4000			;Top of the stack

_VRAM 		.equ $2000			;VRAM in start of RAM
_CursorX 	.equ $2400			;1 Byte for X of screen
_CursorY 	.equ $2401			;1 Byte for Y of screen

_UserRAM 	.equ $2402			;Start of free RAM
;--------------------------------
;I/O Locations
;--------------------------------
_IO1A		.equ $00			;Port A of IO1
_IO1B		.equ $01			;Port B of IO1
_IO1C		.equ $02			;Port C of IO1
_IO1Cmd		.equ $03			;Control Word of IO1

_IO2A		.equ $20			;Port A of IO2
_IO2B		.equ $21			;Port B of IO2
_IO2C		.equ $22			;Port C of IO2
_IO1Cmd		.equ $23			;Control Word of IO2

_ExtIO1		.equ $40			;External IO
_ExtIO2		.equ $60			;External IO
_ExtIO3		.equ $80			;External IO
_ExtIO4		.equ $a0			;External IO
_ExtIO5		.equ $c0			;External IO
_ExtIO6		.equ $e0			;External IO

_Display 	.equ $00			;IO address of display data
_DisplayCmd	.equ $01			;IO address of display command pins [CS1, CS2, RST, R/W, D/C, E, 0, 0] (R and D = 1, W and C = 0)
;--------------------------------
;ROM Calls
;--------------------------------
#ifndef OSfile					;Do not define ROMcalls for OS source
.org $4000
_PrintS 	.equ $0040 ;TODO add address			;Address of string to print in hl, string must end in 0
_PrintB 	.equ $0000			;Byte to print in a TODO fix addressing
#endif							;End of non-OS ROMcalls