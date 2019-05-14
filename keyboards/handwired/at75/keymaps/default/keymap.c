/* Copyright 2019 REPLACE_WITH_YOUR_NAME
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};


//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0,
  TD_LSFT_CAPS,
  TD_2FN2
};

// Layer Declarations
enum {
    _QW = 0,//Querty default layer
	_CM,	//Colemak layer
    _FN 	//Function layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Copied from XD75 default QUERTY keymap */
/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | GESC   | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | BACKSP | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | SFTCAP | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

   KC_GESC,  KC_1,    TD(TD_2FN2),    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,  \
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,  \
   KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,   \
   TD(TD_LSFT_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  \
   KC_LCTL, KC_LGUI, KC_LALT, LT(_FN, KC_SPC),  KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  KC_SPC,  LT(_FN, KC_SPC),  KC_RALT, KC_RGUI, KC_RCTL   \
  ),

  [_CM] = LAYOUT( /* Colemak */
/* Colemak
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | GESC   | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | _QW    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | F      | P      | G      | [      | \      | ]      | J      | L      | U      | Y      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | BACKSP | A      | R      | S      | T      | D      | HOME   | DEL    | PG UP  | H      | N      | E      | I      | O      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | SFTCAP | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | K      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

   KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TO(_QW),  \
   KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRC, KC_BSLS, KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,  \
   KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,   \
   TD(TD_LSFT_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  \
   KC_LCTL, KC_LGUI, KC_LALT, LT(_FN, KC_SPC),  KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  KC_SPC,  LT(_FN, KC_SPC),  KC_RALT, KC_RGUI, KC_RCTL   \
  ),

  [_FN] = LAYOUT( /* FUNCTION */
/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   |        |        | P7     | P8     | P9     | P-     |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   |        |        | P4     | P5     | P6     | P+     |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    |        |        | P1     | P2     | P3     | PENT   |        | _CM    |        |        | RSHIFT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | FN     |        |        | P0     |        | P.     | PENT   |        | FN     |        |        | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_PSLS, KC_PAST, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, \
    KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, RESET,   _______, _______, _______, \
    KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, TO(_CM), _______, _______, KC_RSFT, \
    _______, _______, _______, KC_TRNS, _______,_______, KC_P0,   _______, KC_PDOT, KC_PENT, _______, KC_TRNS, _______, _______, KC_RCTL  \
 ),
 
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  DDRB |= (1 << 0); //set Rx LED pin as output for layer_state    
    PORTB |= (1 << 0);// turn off led

  switch (layer) {
    case _QW:  //Layer LED off
      PORTB |= (1 << 0);
      break;
    case _FN: //Layer LED on
      PORTB &= ~(1 << 0); 
      break;
  }
};

void led_set_user(uint8_t usb_led) {

}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),			//Tap once for Esc, twice for Caps Lock
  [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),			//Double tap left shift for Caps Lock
  [TD_2FN2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2)						//Double tap 2 for F2 (rename)
};


