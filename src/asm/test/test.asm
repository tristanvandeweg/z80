 LD A,0b10000000
 OUT (0x04),A       ; Set ports A,B and C to mode 0 output
 
 loop:

 LD A,0x55
 OUT (0x00),A

 LD A,0xAA
 OUT (0x00),A
 
 JP loop