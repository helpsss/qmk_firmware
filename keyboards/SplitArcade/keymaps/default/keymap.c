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
#include "trackball.h"

// Defines the keycodes used by our macros in process_record_user
#define _QWERTY 0
#define _MEDIA 1
#define _NUM 2
#define _SYM 3
#define _MOUSE 4
#define _ACC 5
#define _EMOJI 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  MEDIA,
  NUM,
  SYM,
  MOUSE,
  DPI_DOWN,
  DPI_UP
};

// Fillers to make layering more clear
#define _______ 	KC_TRNS
#define XXXXXXX 	KC_NO


int8_t RES_hue = 95;



//Tap Dance Declarations
enum{
	SFT_CAPS = 0,
	
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
	
	};
	
	
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT( \
 
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+//
	   KC_ESC,       KC_Q,        KC_W,    	   KC_E, 	    KC_R,        KC_T,    							                                    KC_Y,        KC_U,	      KC_I,        KC_O, 	    KC_P,      KC_BSPC, \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+//
	   KC_TAB,   	 KC_A, 		  KC_S,    	   KC_D,        KC_F,        KC_G,    							                                    KC_H,        KC_J,        KC_K,        KC_L,       KC_SLSH,      KC_ENT,   \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+//   
    TD(SFT_CAPS),    KC_Z,     	  KC_X,    	   KC_C,        KC_V,        KC_B,    							                                    KC_N,        KC_M,       KC_COMM,     KC_DOT,      KC_MINS,     TG(_MOUSE), \
 //+------------+------------+------------+------------+------------+------------+------------+------------+     +------------+------------+------------+------------+------------+------------+------------+------------+//				
				                KC_LCTRL, 	MO(_MEDIA),    KC_LALT,    MO(_NUM),   MO(_EMOJI),    KC_SPC,  		     XXXXXXX,    XXXXXXX,     XXXXXXX,     MO(_SYM),   TG(_MOUSE),   KC_RGHT   \
                           //+------------+------------+------------+------------+------------+------------+     +------------+------------+------------+------------+------------+------------+//	
),

[_MEDIA] = LAYOUT( \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+//
     LWIN(KC_L),   _______,     _______,     _______,     _______,     _______,                                                               RGB_M_R,      _______,     RGB_HUD,    RGB_HUI,      _______,     RGB_TOG, \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+// 
      _______,     _______,     _______,     _______,     _______,     _______,                                                               _______,      _______,     _______,    _______,      _______,     _______, \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+//  
      _______,     KC_MPRV,     KC_MNXT,     KC_VOLD,     KC_VOLU,     KC_MUTE,                                                               _______,      _______,     _______,    _______,      RGB_VAI,     _______, \
 //+------------+------------+------------+------------+------------+------------+------------+------------+     +------------+------------+------------+------------+------------+------------+------------+------------+//
                                _______,     _______,     _______,     _______,     KC_MPLY,     _______,           _______,     _______,    _______,      RGB_RMOD,     RGB_VAD,     RGB_MOD  \
                           //+------------+------------+------------+------------+------------+------------+     +------------+------------+------------+------------+------------+------------+//	
),

[_NUM] = LAYOUT( \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+// 
      _______,      KC_GRV,       KC_7,        KC_8,        KC_9,      KC_PPLS,                                                               _______,      _______,     _______,     _______,    _______,   ALGR(KC_DEL), \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+// 
      _______,    S(KC_RBRC), 	  KC_4,        KC_5,        KC_6,      KC_PMNS,                                                               _______,      _______,     _______,     _______,    _______,     _______,  \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+//
      _______, 	   _______,       KC_1,        KC_2,        KC_3,      KC_PENT,                                                               _______,      _______,     _______,     _______,    _______,     _______,  \
 //+------------+------------+------------+------------+------------+------------+------------+------------+     +------------+------------+------------+------------+------------+------------+------------+------------+// 
                                _______,       KC_0,       KC_PEQL,    _______,     _______,      _______,          _______,     _______,     _______,     MO(_SYM),     _______,     _______  \
                           //+------------+------------+------------+------------+------------+------------+     +------------+------------+------------+------------+------------+------------+//	
),

[_SYM] = LAYOUT( \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+//   
     S(KC_BSLS),   S(KC_1), 	S(KC_2),  	ALGR(KC_E),   S(KC_4),     S(KC_5), 	                                                           S(KC_6),     S(KC_7),     S(KC_8),     S(KC_9),     S(KC_0),   S(KC_MINS), \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+//  
      _______,	 ALGR(KC_SCLN), _______, 	 _______,     _______, 	   _______, 	                                                           _______,     _______,     _______,     _______,     _______,     _______, \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+// 
      _______,	   _______,     _______, 	 _______,     _______, 	   _______, 	                                                           _______,     _______,     _______,     _______,     _______,     _______, \
 //+------------+------------+------------+------------+------------+------------+------------+------------+     +------------+------------+------------+------------+------------+------------+------------+------------+//  
                                _______,     _______, 	  _______, 	   _______,     MO(_NUM), 	 _______, 	        _______,      _______,     _______,     _______,     _______,     _______  \
                           //+------------+------------+------------+------------+------------+------------+     +------------+------------+------------+------------+------------+------------+//	
),

[_MOUSE] = LAYOUT( \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+//   
      _______, 	    _______,     _______,     _______,     _______,     _______,                                                              DPI_UP, 	   _______,      KC_WH_U, 	  _______, 	   _______,    _______,  \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+//   
      _______,      _______,     _______,     _______,     _______,     _______,                                                              DPI_DOWN,    KC_BTN1,      KC_BTN3, 	 KC_BTN2, 	   _______,    _______,  \
 //+------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+//     
      _______,      _______,     _______,     _______,     _______,     _______,                                                              _______, 	   _______, 	 KC_WH_D, 	 _______, 	   _______,    _______,  \
 //+------------+------------+------------+------------+------------+------------+------------+------------+     +------------+------------+------------+------------+------------+------------+------------+------------+//    
                                 _______,     _______,     _______,     _______,    _______,     _______,           _______,     _______,     _______, 	   _______, 	 _______,    _______   \
                           //+------------+------------+------------+------------+------------+------------+     +------------+------------+------------+------------+------------+------------+//	
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    
	case DPI_DOWN:
		if (record->event.pressed) {
			RES_DOWN();
			rgblight_sethsv_at((RES_hue-5),128, 128, 9);
			rgblight_sethsv_at((RES_hue-5),128, 128, 20);
		}else{
		}
		break;
		case DPI_UP:
		if (record->event.pressed) {
			RES_UP();
			rgblight_sethsv_at((RES_hue+5),128, 128, 9);
			rgblight_sethsv_at((RES_hue+5),128, 128, 20);
		}else{
		}
		break;  
  } 
   
    return true;
}

/* LED ORDER

   +------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+   
   |   26/ESC 	|    25/Q    |    24/W    |    23/E    |    22/R    |    21/T    |                                                         |    20/Y    |    19/U 	 |    18/I 	  |    17/O    |    16/P    |  15/BKSP   |
   +------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+   
   |   27/TAB   |    28/A    |    29/S    |    30/D    |    31/F    |    32/G    |                                                         |     9/H    |    10/J 	 |    11/K 	  |    12/L    |   13/SLSH  |   14/ENT   |
   +------------+------------+------------+------------+------------+------------+                                                         +------------+------------+------------+------------+------------+------------+   
   |  38/SHIFT  |    37/Z    |    36/X    |    35/C    |    34/V    |    33/B    |                                                         |     8/N    |     7/M    |   6/COMMA  |    5/DOT   |   4/DASH   |   3/MOUSE  |
   +------------+------------+------------+------------+------------+------------+------------+------------+     +------------+------------+------------+------------+------------+------------+------------+------------+    
                             |  39/CTRL   |     40     |   41/ALT   |     42     |     43     |     44     |     |  XXXXXXXX  |   XXXXXXX  |  XXXXXXXX  |      0     |      1     |      2     |
                             +------------+------------+------------+------------+------------+------------+     +------------+------------+------------+------------+------------+------------+	

*/


void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        rgblight_setrgb_at(RGB_GREEN, 38);
    } else {
    }
}
