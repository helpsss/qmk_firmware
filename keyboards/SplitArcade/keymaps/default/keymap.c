/* Copyright 2019 Alan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "pointing_device.h"

// Defines the keycodes used by our macros in process_record_user
#define _QWERTY 0
#define _MEDIA 1
#define _NUM 2
#define _SYM 3
#define _MOUSE 4
#define _ACC 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  MEDIA,
  NUM,
  SYM,
  MOUSE,
  ACC
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

//Tap Dance Declarations
enum{
	SFT_CAPS = 0,
	
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
	
	};
	
	  

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |  E/è |   R  |   T  |   Y  |  U/ù |  I/ì |  O/ò |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |  A/à |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   -  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |MOUSE |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Media|  Alt |  NUM |    Space    |     Enter   | SYM  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,   	KC_Q,      	KC_W,    KC_E, 		KC_R,      KC_T,    KC_Y,    KC_U,	   KC_I,  	  KC_O, 	KC_P,    KC_BSPC, \
  KC_TAB,   	KC_A, 		KC_S,    KC_D,      KC_F,      KC_G,    KC_H,    KC_J,     KC_K,      KC_L,     KC_SLSH, KC_MINS, \
  TD(SFT_CAPS), KC_Z,     	KC_X,    KC_C,      KC_V,      KC_B,    KC_N,    KC_M,     KC_COMM,   KC_DOT,   KC_UP,   TG(_MOUSE), \
  KC_LCTRL, 	MO(_MEDIA), KC_LALT, LWIN(KC_L),   MO(_NUM),  KC_ENT,  KC_SPC,  MO(_SYM), MO(_SYM),  KC_LEFT,  KC_DOWN, KC_RGHT \
),

/* MEDIA
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |RGB1/0|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | PREV | NEXT | VOLU | VOLD | MUTE |      |      |      |      | LEDU |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | PLAY/PAUSE  |             |      | Down | LEDD |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_MEDIA] = LAYOUT( \
  _______,  _______, _______, _______, _______, _______,  RGB_M_R,  _______,   RGB_HUD, RGB_HUI,  _______, RGB_TOG, \
  _______,  _______, _______, _______, _______, _______,  _______,  _______,   _______, _______,  _______, _______, \
  _______,  KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE,  _______,  _______,   _______, _______,  RGB_VAI, _______ , \
  _______,  _______, _______, _______, KC_MPLY, _______,  _______,  _______,   _______, RGB_RMOD, RGB_VAD, RGB_MOD \
),

/* NUM
 * ,-----------------------------------------------------------------------------------.
 * |  \   |   7  |   8  |   9  |   +  |      |      |      |      |      |      | CAD  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   *   |   4  |   5  |   6  |   -  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |ENTER |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   0  |      |      =      |   LOG OFF   | ACC  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT( \
  KC_GRV,  		KC_7,   KC_8,   KC_9,   KC_PPLS, _______,  _______,  _______,     _______,  _______,  _______,   ALGR(KC_DEL), \
  S(KC_RBRC), 	KC_4,   KC_5,   KC_6,   KC_PMNS, _______,  _______,  _______,     _______,  _______,  _______,   _______, \
  _______, 		KC_1,   KC_2,   KC_3,   KC_PENT, _______,  _______,  _______,     _______,  _______,  _______,   _______, \
  _______, 		_______, KC_0,  KC_PEQL, _______, _______,  _______,  MO(_ACC),  MO(_ACC),  _______,  _______,   _______ \
),

/* SYMBOL
 * ,-----------------------------------------------------------------------------------.
 * |   |  |   !  |   "  |   €  |   $  |   %  |   &  |   /  |   (  |   )  |   =  |  ?   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
   |      |   @  |      |      |      |      |      |      |      |      |      |   #  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  ACC |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT( \
  S(KC_BSLS), 	S(KC_1), 		S(KC_2),  	ALGR(KC_E),  S(KC_4),  	S(KC_5), 	S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_MINS), \
  _______,		ALGR(KC_SCLN) , _______, 	_______,     _______, 	_______, 	_______, _______, _______, _______, _______, _______, \
  _______,		_______, 		_______, 	_______,     _______, 	_______, 	_______, _______, _______, _______, _______, _______, \
  _______, 		_______, 		_______, 	MO(_ACC),    _______, 	MO(_ACC), 	_______, _______, _______, _______, _______, _______ \
),

/* MOUSE
 * ,-----------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |        |        |        |      |      |
 * |------+------+------+------+------+-------------+--------+--------+--------+------+------|
 * |      |      |      |      |      |      |      | LCLICK | CCLICK | RCLICK |      |      |
 * |------+------+------+------+------+------|------+--------+--------+--------+------+------|
 * |      |      |      |      |      |      |      |ALT+LCLK|ALT+CCLK|ALT+RCLK|      |      |
 * |------+------+------+------+------+------+------+--------+--------+--------+------+------|
 * |      |      |      |      |             |               |        |        |      |      |
 * `-----------------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT( \
  _______, 	_______,    _______,    _______,    _______,    _______, _______, _______, 			_______, 		_______, 		_______, _______, \
  _______,  _______,    _______,    _______,    _______,    _______, _______, KC_BTN1, 			KC_BTN3, 		KC_BTN2, 		_______, _______, \
  _______,  _______,    _______,    _______,    _______,    _______, _______, KC_WH_U, 			KC_WH_D, 		_______, 		_______, _______, \
  _______,  _______,    _______,    _______,    _______,    _______, _______, _______, 			_______, 		_______, 		_______, _______ \
),

/* ACCENTI
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |   è  |      |      |      |   ù  |   ì  |   ò  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   à  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |	   |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ACC] = LAYOUT( \
  _______, 	_______,    _______,    KC_LBRC,    _______,    _______, _______, KC_BSLS, 	KC_EQL, 	KC_SCLN, _______, _______, \
  _______,  KC_QUOT,    _______,    _______,    _______,    _______, _______, _______, 	_______, 	_______, _______, _______, \
  _______,  _______,    _______,    _______,    _______,    _______, _______, _______,  _______, 	_______, _______, _______, \
  _______,  _______,    _______,    _______,    _______,    _______, _______, _______, 	_______, 	_______, _______, _______ \
),

};
/*
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);
	
    switch (layer) {
        
			
        case _MEDIA:
            rgblight_setrgb_at(RGB_TEAL, 0);		//backspace - ?	
			rgblight_setrgb_at(RGB_TEAL, 13);		//UP ARROW
			rgblight_setrgb_at(RGB_TEAL, 18);		//LEFT ARROW
			rgblight_setrgb_at(RGB_TEAL, 19);		//DOWN ARROW
			rgblight_setrgb_at(RGB_TEAL, 20);		//RIGHT ARROW
			rgblight_setrgb_at(RGB_TEAL, 36);		//Z
			rgblight_setrgb_at(RGB_TEAL, 37);		//X
			rgblight_setrgb_at(RGB_TEAL, 38);		//C
			rgblight_setrgb_at(RGB_TEAL, 39);		//V
			rgblight_setrgb_at(RGB_TEAL, 40);		//B
			rgblight_setrgb_at(RGB_TEAL, 45);		//ENTER
            break;
			
         case _NUM:
			rgblight_setrgb_at(RGB_MAGENTA, 0);		//backspace - ?
			rgblight_setrgb_at(RGB_MAGENTA, 22);		//SPACE
			rgblight_setrgb_at(RGB_MAGENTA, 23);		//ESC - ENERGY TANK
			rgblight_setrgb_at(RGB_MAGENTA, 24);		//Q
			rgblight_setrgb_at(RGB_MAGENTA, 25);		//W
			rgblight_setrgb_at(RGB_MAGENTA, 26);		//E
			rgblight_setrgb_at(RGB_MAGENTA, 27);		//R
			rgblight_setrgb_at(RGB_MAGENTA, 30);		//A
			rgblight_setrgb_at(RGB_MAGENTA, 31);		//S	
			rgblight_setrgb_at(RGB_MAGENTA, 32);		//D
			rgblight_setrgb_at(RGB_MAGENTA, 33);		//F
			rgblight_setrgb_at(RGB_MAGENTA, 36);		//Z
			rgblight_setrgb_at(RGB_MAGENTA, 37);		//X
			rgblight_setrgb_at(RGB_MAGENTA, 38);		//C
			rgblight_setrgb_at(RGB_MAGENTA, 39);		//V
			rgblight_setrgb_at(RGB_MAGENTA, 43);		//ALT-STAR
			rgblight_setrgb_at(RGB_MAGENTA, 45);		//ENTER
			break;
		
		case _SYM:
            rgblight_setrgb_at(RGB_CHARTREUSE, 0);		//backspace - ?	
			rgblight_setrgb_at(RGB_CHARTREUSE, 1);		//P
			rgblight_setrgb_at(RGB_CHARTREUSE, 2);		//O
			rgblight_setrgb_at(RGB_CHARTREUSE, 3);		//I
			rgblight_setrgb_at(RGB_CHARTREUSE, 4);		//U
			rgblight_setrgb_at(RGB_CHARTREUSE, 5);		//Y
			rgblight_setrgb_at(RGB_CHARTREUSE, 23);		//ESC - ENERGY TANK
			rgblight_setrgb_at(RGB_CHARTREUSE, 24);		//Q
			rgblight_setrgb_at(RGB_CHARTREUSE, 25);		//W
			rgblight_setrgb_at(RGB_CHARTREUSE, 26);		//E
			rgblight_setrgb_at(RGB_CHARTREUSE, 27);		//R
			rgblight_setrgb_at(RGB_CHARTREUSE, 28);		//T
            break;	
			
		case _MOUSE:
			rgblight_setrgb_at(RGB_PURPLE, 8);		//L
			rgblight_setrgb_at(RGB_PURPLE, 9);		//K
			rgblight_setrgb_at(RGB_PURPLE, 10);		//J
			rgblight_setrgb_at(RGB_PURPLE, 16);		//M
			rgblight_setrgb_at(RGB_PURPLE, 15);		//H
			break;
			
        case _QWERTY:
            rgblight_setrgb(55, 55, 55);
	        break;
    }
};	
*/

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_A);
    } else {
      tap_code(KC_Z);
    }
  } else if (index == 1) { /* Second encoder from slave */
    if (clockwise) {
      tap_code(KC_MS_WH_UP);
    } else {
      tap_code(KC_MS_WH_DOWN);
    }
  }
};