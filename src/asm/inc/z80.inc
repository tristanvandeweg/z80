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
_ExtIndPrgm	.equ $80			;=Byte to indicate external program
_ExtIndRAM	.equ $ab			;=Byte to indicate external RAM
_ExtIndIO	.equ $10			;=Byte to indicate external IO

_StackSize 	.equ $ff			;=255
_VRAMSize	.equ $0400			;=1kiB
;--------------------------------
;Memory Locations
;--------------------------------
_RAM 		.equ $2000			;=8192
_ROM 		.equ 0				;=0
_ExtMem 	.equ $4000			;=16384

_StackTop 	.equ $4000			;Top of the stack

_VRAM 		.equ $2000			;VRAM in start of RAM
_CursorX 	.equ $2400			;1 Byte for X of screen (Bit 0-2=bit offset, Bit 3-6=byte position)
_CursorY 	.equ $2401			;1 Byte for Y of screen	(1 line=15 bytes)

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
_IO2Cmd		.equ $23			;Control Word of IO2

_ExtIO1		.equ $40			;External IO
_ExtIO2		.equ $60			;External IO
_ExtIO3		.equ $80			;External IO
_ExtIO4		.equ $a0			;External IO
_ExtIO5		.equ $c0			;External IO
_ExtIO6		.equ $e0			;External IO

_Display 	.equ $00			;IO address of display data
_DisplayCmd	.equ $01			;IO address of display command pins [0, 0, E, D/C, R/W, RST, CS2, CS1] (R and D = 1, W and C = 0)
;--------------------------------
;I/O Control Bits
;--------------------------------
_PortClInput	.equ %00000001	;Lower half of port C
_PortClOutput	.equ %00000000	;Lower half of port C
_PortBInput		.equ %00000010
_PortBOutput	.equ %00000000
_PortClBMode0	.equ %00000000	;Basic Input/Output
_PortClBMode1	.equ %00000100	;Strobed Input/Output

_PortCuInput	.equ %00001000	;Upper half of port C
_PortCuOutput	.equ %00000000	;Upper half of port C
_PortAInput		.equ %00010000
_PortAOutput	.equ %00000000
_PortCuAMode0	.equ %00000000	;Basic Input/Output
_PortCuAMode1	.equ %00100000	;Strobed Input/Output
_PortCuAMode2	.equ %01000000	;Strobed Bidirectional Bus Input/Output

_ModeSetFlag	.equ %10000000	;Use when setting I/O mode
;--------------------------------
;ROM Calls
;--------------------------------
#ifndef OSfile					;Do not define ROMcalls for OS source
.org $4000						;TODO add addresses for all subroutines
_Exit			.equ $0000
_PrintS 		.equ $0000 		;Address of string to print in hl, string must end in 0
_PrintB 		.equ $0000		;Byte to print in a TODO fix addressing
_WriteVRAM		.equ $0000
_ClearDisp		.equ $0000
_DrawSprite		.equ $0000
_DisplayInit	.equ $0000
_DisplayOn		.equ $0000
_DisplayOff		.equ $0000
#endif							;End of non-OS ROMcalls