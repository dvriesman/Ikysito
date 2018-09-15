#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include <util.h>
#include <crt.h>

#define KEY_ENTER_VALUE	'\n'
#define KEY_TAB_VALUE 	'\t'
#define KEY_HOME_VALUE 0
#define KEY_END_VALUE 0
#define KEY_UP_VALUE 0
#define KEY_PGUP_VALUE 0
#define KEY_LF_VALUE 0
#define KEY_RT_VALUE 0
#define KEY_DN_VALUE 0
#define KEY_END_VALUE 0
#define KEY_PGDN_VALUE 0
#define KEY_INS_VALUE 0
#define KEY_DEL_VALUE 0
#define KEY_CAPS_LOCK_VALUE 0
#define F1_VALUE 0
#define F2_VALUE 0
#define F3_VALUE 0
#define F4_VALUE 0
#define F5_VALUE 0
#define F6_VALUE 0
#define F7_VALUE 0
#define F8_VALUE 0
#define F9_VALUE 0
#define F10_VALUE 0
#define F11_VALUE 0
#define F12_VALUE 0
#define SCROLL_LOCK_VALUE 0
#define NULL_LOCK_VALUE 0
#define KEY_ESC_VALUE 27
#define KEY_CTRL_VALUE 0

#define KEY_NUM_LOCK_VALUE 0
#define KEY_ALT_VALUE 0
#define KEY_SHIFT_LEFT_VALUE 0
#define KEY_SHIFT_RIGHT_VALUE 0
#define KEY_BACKSPACE_VALUE	'\b'


//Teclas especiais
#define L_SHIFT_PRESS 0x2A
#define L_SHIFT_RELEASE 0xAA
#define R_SHIFT_PRESS 0x36
#define R_SHIFT_RELEASE 0xB6



unsigned char default_map[256];
unsigned char shift_map[256];



void init_keyboard();
void keyboard_handler();

unsigned char getChar();



#endif
