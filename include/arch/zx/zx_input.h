#ifndef __ARCH_ZX_INPUT_H__
#define __ARCH_ZX_INPUT_H__

#include <sys/compiler.h>
#include <sys/types.h>

///////////
// keyboard
///////////

#define IN_KEY_SCANCODE_DISABLE  0xffff
#define IN_KEY_SCANCODE_ANYKEY   0x1f00

#define IN_KEY_SCANCODE_CAPS   0x01fe
#define IN_KEY_SCANCODE_SYM    0x027f

#define IN_KEY_SCANCODE_ENTER  0x01bf
#define IN_KEY_SCANCODE_SPACE  0x017f

#define IN_KEY_SCANCODE_a      0x01fd
#define IN_KEY_SCANCODE_b      0x107f
#define IN_KEY_SCANCODE_c      0x08fe
#define IN_KEY_SCANCODE_d      0x04fd
#define IN_KEY_SCANCODE_e      0x04fb
#define IN_KEY_SCANCODE_f      0x08fd
#define IN_KEY_SCANCODE_g      0x10fd
#define IN_KEY_SCANCODE_h      0x10bf
#define IN_KEY_SCANCODE_i      0x04df
#define IN_KEY_SCANCODE_j      0x08bf
#define IN_KEY_SCANCODE_k      0x04bf
#define IN_KEY_SCANCODE_l      0x02bf
#define IN_KEY_SCANCODE_m      0x047f
#define IN_KEY_SCANCODE_n      0x087f
#define IN_KEY_SCANCODE_o      0x02df
#define IN_KEY_SCANCODE_p      0x01df
#define IN_KEY_SCANCODE_q      0x01fb
#define IN_KEY_SCANCODE_r      0x08fb
#define IN_KEY_SCANCODE_s      0x02fd
#define IN_KEY_SCANCODE_t      0x10fb
#define IN_KEY_SCANCODE_u      0x08df
#define IN_KEY_SCANCODE_v      0x10fe
#define IN_KEY_SCANCODE_w      0x02fb
#define IN_KEY_SCANCODE_x      0x04fe
#define IN_KEY_SCANCODE_y      0x10df
#define IN_KEY_SCANCODE_z      0x02fe

#define IN_KEY_SCANCODE_0      0x01ef
#define IN_KEY_SCANCODE_1      0x01f7
#define IN_KEY_SCANCODE_2      0x02f7
#define IN_KEY_SCANCODE_3      0x04f7
#define IN_KEY_SCANCODE_4      0x08f7
#define IN_KEY_SCANCODE_5      0x10f7
#define IN_KEY_SCANCODE_6      0x10ef
#define IN_KEY_SCANCODE_7      0x08ef
#define IN_KEY_SCANCODE_8      0x04ef
#define IN_KEY_SCANCODE_9      0x02ef

/////////////////////////////////////////////////////////////////
// INPUT DEVICES: KEYBOARD, JOYSTICK AND MICE (SEE ALSO INPUT.H)
/////////////////////////////////////////////////////////////////

// Joystick Functions
// These are actually in_*(void)
extern unsigned int  __LIB__ in_JoyFuller();
extern unsigned int  __LIB__ in_JoyKempston();
extern unsigned int  __LIB__ in_JoySinclair1();
extern unsigned int  __LIB__ in_JoySinclair2();
extern unsigned int  __LIB__ in_JoyTimex1();
extern unsigned int  __LIB__ in_JoyTimex2();

// AMX Mouse
//
// To use you must declare the following global variables
// uint in_AMXcoordX, in_AMXcoordY, in_AMXdeltaX, in_AMXdeltaY;

extern void __LIB__             in_MouseAMXInit(uchar xvector, uchar yvector) __smallc;
extern void __LIB__             in_MouseAMX(uchar *buttons, uint *xcoord, uint *ycoord) __smallc;
extern void __LIB__             in_MouseAMXSetPos(uint xcoord, uint ycoord) __smallc;

extern void __LIB__   in_MouseAMXInit_callee(uchar xvector, uchar yvector) __smallc __z88dk_callee;
extern void __LIB__   in_MouseAMX_callee(uchar *buttons, uint *xcoord, uint *ycoord) __smallc __z88dk_callee;
extern void __LIB__   in_MouseAMXSetPos_callee(uint xcoord, uint ycoord) __smallc __z88dk_callee;

#define in_MouseAMXInit(a,b)    in_MouseAMXInit_callee(a,b)
#define in_MouseAMX(a,b,c)      in_MouseAMX_callee(a,b,c)
#define in_MouseAMXSetPos(a,b)  in_MouseAMXSetPos_callee(a,b)

// Kempston Mouse
//
// To use you must declare the following global variables
// uchar in_KempcoordX, in_KempcoordY, in_KemprawX, in_KemprawY;

extern void __LIB__             in_MouseKempInit(void);
extern void __LIB__             in_MouseKemp(uchar *buttons, uint *xcoord, uint *ycoord) __smallc;
extern void __LIB__             in_MouseKempSetPos(uint xcoord, uint ycoord) __smallc;

extern void __LIB__   in_MouseKemp_callee(uchar *buttons, uint *xcoord, uint *ycoord) __smallc __z88dk_callee;
extern void __LIB__   in_MouseKempSetPos_callee(uint xcoord, uint ycoord) __smallc __z88dk_callee;

#define in_MouseKemp(a,b,c)     in_MouseKemp_callee(a,b,c)
#define in_MouseKempSetPos(a,b) in_MouseKempSetPos_callee(a,b)



#endif
