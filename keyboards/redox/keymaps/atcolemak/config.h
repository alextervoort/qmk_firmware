/*
Copyright 2019 Alex Tervoort, based on original from [Mattia Dal Ben](https://github.com/mattdibi/redox-keyboard).
and [jeherve](https://github.com/qmk/qmk_firmware/tree/master/keyboards/redox/keymaps/jeherve).

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//QMK-DFU parameters
#define QMK_ESC_OUTPUT D4 // ESC COL
#define QMK_ESC_INPUT F5 // ESC ROW
#define QMK_LED B0 // Rx led
#define QMK_SPEAKER C6 

/* Change the default tapping toggle value (normally 5) */
//#define TAPPING_TOGGLE 2

/* Use I2C or Serial, not both */
#define USE_SERIAL
//#define USE_I2C

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#undef RGBLED_NUM
//#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 14
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP
