#ifndef KEYMAP_H
# define KEYMAP_H

# if defined(LINUX) || defined(ARM)
// import from keysymdef.h
#  define KEY_BACKSPACE		0xff08  /* Back space, back char */
#  define KEY_TAB			0xff09
#  define KEY_RETURN			0xff0d  /* Return, enter */
#  define KEY_ESCAPE			0xff1b
#  define KEY_DELETE			0xffff  /* Delete, rubout */
#  define KEY_SHIFT_L		0xffe1  /* Left shift */
#  define KEY _SHIFT_R		0xffe2  /* Right shift */
#  define KEY_CONTROL_L		0xffe3  /* Left control */
#  define KEY_CONTROL_R		0xffe4  /* Right control */
#  define KEY_CAPS_LOCK		0xffe5  /* Caps lock */
#  define KEY_COMMAND_L		0xffe7  /* Left meta */
#  define KEY_COMMAND_R		0xffe8  /* Right meta */
#  define KEY_OPTION			0xff7e  /* Alias for mode_switch */
#  define KEY_BRACKETLEFT	0x005b  /* U+005B LEFT SQUARE BRACKET */
#  define KEY_BACKSLASH		0x005c  /* U+005C REVERSE SOLIDUS */
#  define KEY_BRACKETRIGHT	0x005d  /* U+005D RIGHT SQUARE BRACKET */
#  define KEY_LEFT			0xff51  /* Move left, left arrow */
#  define KEY_UP				0xff52  /* Move up, up arrow */
#  define KEY_RIGHT			0xff53  /* Move right, right arrow */
#  define KEY_DOWN			0xff54  /* Move down, down arrow */
#  define KEY_SPACE			0x0020  /* Space */
#  define KEY_F1				0xffbe
#  define KEY_F2				0xffbf
#  define KEY_F3				0xffc0
#  define KEY_F4				0xffc1
#  define KEY_F5				0xffc2
#  define KEY_F6				0xffc3
#  define KEY_F7				0xffc4
#  define KEY_F8				0xffc5
#  define KEY_F9				0xffc6
#  define KEY_F10			0xffc7
#  define KEY_F11			0xffc8
#  define KEY_F12			0xffc9
#  define KEY_A				0x0061  /* U+0061 LATIN SMALL LETTER A */
#  define KEY_B				0x0062  /* U+0062 LATIN SMALL LETTER B */
#  define KEY_C				0x0063  /* U+0063 LATIN SMALL LETTER C */
#  define KEY_D				0x0064  /* U+0064 LATIN SMALL LETTER D */
#  define KEY_E				0x0065  /* U+0065 LATIN SMALL LETTER E */
#  define KEY_F				0x0066  /* U+0066 LATIN SMALL LETTER F */
#  define KEY_G				0x0067  /* U+0067 LATIN SMALL LETTER G */
#  define KEY_H				0x0068  /* U+0068 LATIN SMALL LETTER H */
#  define KEY_I				0x0069  /* U+0069 LATIN SMALL LETTER I */
#  define KEY_J				0x006a  /* U+006A LATIN SMALL LETTER J */
#  define KEY_K				0x006b  /* U+006B LATIN SMALL LETTER K */
#  define KEY_L				0x006c  /* U+006C LATIN SMALL LETTER L */
#  define KEY_M				0x006d  /* U+006D LATIN SMALL LETTER M */
#  define KEY_N				0x006e  /* U+006E LATIN SMALL LETTER N */
#  define KEY_O				0x006f  /* U+006F LATIN SMALL LETTER O */
#  define KEY_P				0x0070  /* U+0070 LATIN SMALL LETTER P */
#  define KEY_Q				0x0071  /* U+0071 LATIN SMALL LETTER Q */
#  define KEY_R				0x0072  /* U+0072 LATIN SMALL LETTER R */
#  define KEY_S				0x0073  /* U+0073 LATIN SMALL LETTER S */
#  define KEY_T				0x0074  /* U+0074 LATIN SMALL LETTER T */
#  define KEY_U				0x0075  /* U+0075 LATIN SMALL LETTER U */
#  define KEY_V				0x0076  /* U+0076 LATIN SMALL LETTER V */
#  define KEY_W				0x0077  /* U+0077 LATIN SMALL LETTER W */
#  define KEY_X				0x0078  /* U+0078 LATIN SMALL LETTER X */
#  define KEY_Y				0x0079  /* U+0079 LATIN SMALL LETTER Y */
#  define KEY_Z				0x007a  /* U+007A LATIN SMALL LETTER Z */

# else
// # if defined(OSX)
#  define KEY_BACKSPACE		0x0033
#  define KEY_TAB			0x0030
#  define KEY_RETURN			0x0024
#  define KEY_ESCAPE			0x0035
#  define KEY_DELETE			0x0075

#  define KEY_SHIFT_L		0x0101
#  define KEY_SHIFT_R		0x0102
#  define KEY_CONTROL_L		0x0100
#  define KEY_CONTROL_R		0x010d
#  define KEY_CAPSLOCK		0x0110
#  define KEY_COMMAND_L		0x0103
#  define KEY_COMMAND_R		0x0104
#  define KEY_OPTION_LEFT	0x0105

#  define KEY_BRACKETLEFT	0x0021
#  define KEY_BACKSLASH		0x002a
#  define KEY_BRACKETRIGHT	0x001e

#  define KEY_SPACE			0x0031

#  define KEY_LEFT			0x007b
#  define KEY_UP				0x007e
#  define KEY_RIGHT			0x007c
#  define KEY_DOWN			0x007d

#  define KEY_F1 			0x007a
#  define KEY_F2				0x0078
#  define KEY_F3				0x0063
#  define KEY_F4				0x0076
#  define KEY_F5				0x0060
#  define KEY_F6				0x0061
#  define KEY_F7				0x0062
#  define KEY_F8				0x0064
#  define KEY_F9				0x0065
#  define KEY_F10			0x006d
#  define KEY_F11			0x0067
#  define KEY_F12			0x006f
#  define KEY_F13			0x0069
#  define KEY_F14			0x006b
#  define KEY_F15			0x0071
#  define KEY_F16			0x006a
#  define KEY_F17			0x0040
#  define KEY_F18			0x004f
#  define KEY_F19			0x0050

#  define KEY_1				0x0012
#  define KEY_2				0x0013
#  define KEY_3				0x0014
#  define KEY_4				0x0015
#  define KEY_5				0x0017
#  define KEY_6				0x0016
#  define KEY_7				0x001a
#  define KEY_8				0x001c
#  define KEY_9				0x0019
#  define KEY_0				0x001d

#  define KEY_A				0x0000
#  define KEY_B				0x000b
#  define KEY_C				0x0008
#  define KEY_D				0x0002
#  define KEY_E				0x000e
#  define KEY_F				0x0003
#  define KEY_G				0x0005
#  define KEY_H				0x0004
#  define KEY_I				0x0022
#  define KEY_J				0x0026
#  define KEY_K				0x0028
#  define KEY_L				0x0025
#  define KEY_M				0x002e
#  define KEY_N				0x002d
#  define KEY_O				0x001f
#  define KEY_P				0x0023
#  define KEY_Q				0x000c
#  define KEY_R				0x000f
#  define KEY_S				0x0001
#  define KEY_T				0x0011
#  define KEY_U				0x0020
#  define KEY_V				0x0009
#  define KEY_W				0x000d
#  define KEY_X				0x0007
#  define KEY_Y				0x0010
#  define KEY_Z				0x0006
#  endif
# endif