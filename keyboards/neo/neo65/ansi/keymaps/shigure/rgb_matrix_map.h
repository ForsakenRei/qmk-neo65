/* Copyright 2022 Shigure
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

#ifdef RGB_MATRIX_ENABLE

// RGB LED locations
enum led_location_map
{
    LED_ESC, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_0, LED_MINS, LED_EQL, LED_BS1, LED_BS2, LED_DEL,
    LED_TAB, LED_Q, LED_W, LED_E, LED_R, LED_T, LED_Y, LED_U, LED_I, LED_O, LED_P, LED_LBRC, LED_RBRC, LED_BSLS, LED_PGUP,
    LED_CAPS, LED_A, LED_S, LED_D, LED_F, LED_G, LED_H, LED_J, LED_K, LED_L, LED_SCLN, LED_QUOT, LED_ENT, LED_PGDN,
    LED_LSHIFT, LED_Z, LED_X, LED_C, LED_V, LED_B, LED_N, LED_M, LED_COMM, LED_DOT, LED_SLS, LED_RSHIFT, LED_UP, LED_END,
    LED_LCTRL, LED_LGUI, LED_LALT, LED_SP, LED_FN, LED_RALT, LED_LEFT, LED_DOWN, LED_RIGHT
};

const uint8_t LED_LAYER[] = {
                            LED_ESC, LED_DEL,
                            LED_LCTRL, LED_SP, LED_RIGHT
                            };
#endif
