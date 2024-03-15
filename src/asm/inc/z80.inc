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
;TODO: change all subroutine names to exclude the _
;--------------------------------
;Fixed Values
;--------------------------------
_ExtIndPrgm	.equ $80			;=Byte to indicate large external program
_ExtIndPrg2	.equ $81			;=Byte to indicate small external program
_ExtIndRAM	.equ $a0			;=Byte to indicate large external RAM
_ExtIndRAM2	.equ $a1			;=Byte to indicate small external RAM
_ExtIndIO	.equ $10			;=Byte to indicate external IO

_StackSize 	.equ $ff			;=255
_VRAMSize	.equ $0400			;=1kiB
;--------------------------------
;Memory Locations
;--------------------------------
_ROM 		.equ 0				;=0		($0000-$1fff)
_RAM 		.equ $2000			;=8192	($2000-$4000)
_ExtMem2	.equ $4000			;=16384	($4000-$7fff)
_ExtMem 	.equ $8000			;=32768	($8000-$ffff)

_StackTop 	.equ $4000			;Top of the stack

_VRAM 		.equ $2000			;VRAM in start of RAM
_CursorX 	.equ $2400			;1 Byte for X of screen (Bit 0=byte half, Bit 2-4=byte position)
_CursorY 	.equ $2401			;1 Byte for Y of screen	(1 line=15 bytes)
_CurFont	.equ $2402			;2 Bytes for the start of the current ASCII font table (First byte of the font is the font dimensions)
_DrawCount	.equ $2404			;1 Byte used for the _DrawSprite subroutine
_CursorXb	.equ $2405			;1 Byte to store a copy of _CursorX
_CursorYb	.equ $2406			;1 Byte to store a copy of _CursorY

_ExtSlot1	.equ $2407			;1 Byte to store what is installed in slot 1
_ExtSlot1S	.equ $2408			;1 Byte to store the amount of banks in slot 1

_ExtSlot2	.equ $2409			;1 Byte to store what is installed in slot 2
_ExtSlot2S	.equ $240a			;1 Byte to store what is installed in slot 2

_UserRAM 	.equ $2410			;Start of free RAM	($2410-$3f00)
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
.org $4000						;TODO: add addresses for all subroutines
Exit			.equ 51			;Print exit message and halt
;Input: HL
;
;Output: None
;
;Prints the 0-terminated string at HL to VRAM
_PrintS 		.equ 99
;Input: A
;
;Output: None
;
;Prints the ASCII byte in A to VRAM using the current font
PrintB 		.equ 111
;Input: None
;
;Output: None
;
;Moves the cursor to the next position with the current font size
_MoveToNextChar	.equ 232
;Input: None
;
;Output: None
;
;Clears VRAM
_ClearVRAM		.equ 285
;Input: None
;
;Output: HL, Z
;
;Returns the address in VRAM of the current cursor position, also returns the half of the byte in Z
_GetDisplayPosition	.equ 310
;Input: HL
;
;Output: None
;
;Puts the 4x4 sprite at HL in VRAM at _CursorX,_CursorY
_DrawSprite		.equ 0
;Input: None
;
;Output: None
;
;Copy VRAM contents to the display
_WriteVRAM		.equ 428
;Input: A, D
;
;Output: None
;
;Writes A and the commands spedified in D to the display
_WriteDisplay	.equ 495
;Input: None
;
;Output: None
;
;Sets the correct pins for the display, resets cursor to 0,0
_DisplayInit	.equ 510
;Input: None
;
;Output: None
;
;Turn the display on
_DisplayOn		.equ 524
;Input: None
;
;Output: None
;
;Turn the display off
_DisplayOff		.equ 529
;Input: A
;
;Output: A
;
;Flips the contents of the A register
_FlipA			.equ 0
;Input: A, B
;
;Output: HL = A * B
;
;Multiplies A by B (Unsigned)
_MultAB			.equ 0
;--------------------------------
;Font Addresses
;--------------------------------
_fontSmall		.equ 0			;Small 1x1 font
_fontLarge		.equ 0			;Large 2x2 font
_logo			.equ 0			;4x4 Logo


#endif							;End of non-OS ROMcalls