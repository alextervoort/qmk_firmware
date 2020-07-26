/* Copyright 2020 Alex Tervoort
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _CM = 0,   //Colemak layer
  	_QW = 1,	 //Qwerty layer
    _FN = 2    //Function layer
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_CM] = LAYOUT( /* Colemak */
/* Colemak
 * .-----------------------------------------------------------------------.  .--------------------------------------------------------------.
 * | GESC   | 1      | 2      | 3      | 4      | 5      | -      |   F1   |  |  =     | 6      | 7      | 8      | 9      | 0      | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | F      | P      | G      | HOME   |   [    |  |  PG UP | J      | L      | U      | Y      | ;      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+-----------------+--------|
 * | BACKSP | A      | R      | S      | T      | D      | END    |   ]    |  |  PG DN | H      | N      | E      | I      | O      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | F5     |   F4   |  |   UP   | K      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------|  |--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | RIGHT  |  |  DOWN  | ENTER  | ENTER  | FN     | RALT   | RGUI   | RCTRL  |
 * '-----------------------------------------------------------------------'  '--------------------------------------------------------------'
 */

   KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_F1,   KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
   KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_HOME, KC_LBRC, KC_PGUP, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS, \
   KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_END,  KC_RBRC, KC_PGDN, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F5,   KC_F4,   KC_UP,   KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
   KC_LCTL, KC_LGUI, KC_LALT, LT(_FN, KC_SPC),  KC_SPC,  KC_SPC,  KC_LEFT, KC_RGHT, KC_DOWN, KC_ENT,  KC_ENT,  LT(_FN, KC_ENT),  KC_RALT, KC_RGUI, KC_RCTL \
  ),

  [_QW] = LAYOUT( /* QWERTY keymap */
/* QWERTY
* .-----------------------------------------------------------------------.  .--------------------------------------------------------------.
* | GESC   | 1      | 2      | 3      | 4      | 5      | -      |  F1    |  |  =     | 6      | 7      | 8      | 9      | 0      | DEL    |
* |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+-----------------|
* | TAB    | Q      | W      | E      | R      | T      | HOME   |  [     |  |  PG UP | Y      | U      | I      | O      | P      | \      |
* |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+-----------------+--------|
* | BACKSP | A      | S      | D      | F      | G      | END    |  ]     |  |  PG DN | H      | J      | K      | L      | :      | '      |
* |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------------------------+--------|
* | LSHIFT | Z      | X      | C      | V      | B      | F5     | F4     |  |  UP    | N      | M      | ,      | .      | /      | RSHIFT |
* |--------+--------+--------+--------+--------+-----------------+--------|  |--------+--------+--------+-----------------+--------+--------|
* | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | RIGHT  |  |  DOWN  | ENTER  | ENTER  | FN     | RALT   | RGUI   | RCTRL  |
* '-----------------------------------------------------------------------'  '--------------------------------------------------------------'
*/

   KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_F1,            KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_HOME, KC_LBRC,          KC_PGUP, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,  \
   KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_END,  KC_RBRC,          KC_PGDN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,   \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F5,   KC_F4,            KC_UP,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  \
   KC_LCTL, KC_LGUI, KC_LALT, LT(_FN, KC_SPC),  KC_SPC,  KC_SPC,  KC_LEFT, KC_RGHT, KC_DOWN, KC_ENT,  KC_ENT,  LT(_FN, KC_ENT),  KC_RALT, KC_RGUI, KC_RCTL   \
  ),


  [_FN] = LAYOUT( /* FUNCTION */
/* FUNCTION
 * .-----------------------------------------------------------------------.  .--------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | NUM LK | P/     |  | P*     | F6     | F7     | F8     | F9     | F10    | F11    |
 * |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   |        |        | P7     | P8     |  | P9     | P-     |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | RESET  |        |        | P4     | P5     |  | P6     | P+     |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    |        |        | P1     | P2     |  | P3     | PENT   |        | _CM    |        |        | RSHIFT |
 * |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | FN     |        |        | P0     |        |  | P.     | PENT   |        | FN     |        |        | RCTRL  |
 * '-----------------------------------------------------------------------'  '--------------------------------------------------------------'
 */

    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NLCK, KC_PSLS,     KC_PAST, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, _______, KC_ASRP, KC_P7,   KC_P8,       KC_P9,   KC_PMNS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, \
    KC_MPRV, KC_MPLY, KC_MNXT, RESET,   _______, KC_ASUP, KC_P4,   KC_P5,       KC_P6,   KC_PPLS, _______, RESET,   _______, _______, _______, \
    KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  _______, KC_ASDN, KC_P1,   KC_P2,       KC_P3,   KC_PENT, _______, TO(_CM), TO(_QW), _______, KC_RSFT, \
    _______, _______, _______, KC_TRNS, _______, KC_ASTG, KC_P0,   _______,     KC_PDOT, KC_PENT, _______, KC_TRNS, _______, _______, KC_RCTL  \
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
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
