/* 
Copyright 2023 NEO

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
#include "ansi.h"

#ifdef RGB_MATRIX_ENABLE
const is31fl3741_led_t PROGMEM g_is31fl3741_leds[IS31FL3741_LED_COUNT] = {
    {0, SW1_CS2,  SW1_CS3,  SW1_CS1},  /* RGB0-ESC ROW1*/
    {0, SW1_CS5,  SW1_CS6,  SW1_CS4},  /* RGB1-1 */
    {0, SW1_CS8,  SW1_CS9,  SW1_CS7},  /* RGB2-2 */
    {0, SW1_CS11,  SW1_CS12,  SW1_CS10},  /* RGB3-3 */
    {0, SW1_CS14,  SW1_CS15,  SW1_CS13},  /* RGB4-4 */
    {0, SW1_CS17,  SW1_CS18,  SW1_CS16},  /* RGB5-5 */
    {0, SW1_CS20,  SW1_CS21,  SW1_CS19},  /* RGB6-6 */
    {0, SW1_CS23,  SW1_CS24,  SW1_CS22},  /* RGB7-7 */
    {0, SW1_CS26,  SW1_CS27,  SW1_CS25},  /* RGB8-8 */
    {0, SW1_CS29,  SW1_CS30,  SW1_CS28},  /* RGB9-9 */
    {0, SW1_CS32,  SW1_CS33,  SW1_CS31},  /* RGB10-0 */
    {0, SW1_CS35,  SW1_CS36,  SW1_CS34},  /* RGB11--- */
    {0, SW1_CS38,  SW1_CS39,  SW1_CS37},  /* RGB12-+= */
    {0, SW3_CS38,  SW3_CS39,  SW3_CS37},  /* RGB13-|\ */
    {0, SW6_CS38,  SW6_CS39,  SW6_CS37},   /* RGB14-BS */ 
    {0, SW6_CS35,  SW6_CS36,  SW6_CS34},  /* RGB15-Delete */

    {0, SW2_CS2,  SW2_CS3,  SW2_CS1},  /* RGB16-TAB ----ROW2*/
    {0, SW2_CS5,  SW2_CS6,  SW2_CS4},  /* RGB17-Q */
    {0, SW2_CS8,  SW2_CS9,  SW2_CS7},  /* RGB18-W */
    {0, SW2_CS11,  SW2_CS12,  SW2_CS10},  /* RGB19-E */
    {0, SW2_CS14,  SW2_CS15,  SW2_CS13},  /* RGB20-R */
    {0, SW2_CS17,  SW2_CS18,  SW2_CS16},  /* RGB21-T */
    {0, SW2_CS20,  SW2_CS21,  SW2_CS19},  /* RGB22-Y */
    {0, SW2_CS23,  SW2_CS24,  SW2_CS22},  /* RGB23-U */
    {0, SW2_CS26,  SW2_CS27,  SW2_CS25},  /* RGB24-I */
    {0, SW2_CS29,  SW2_CS30,  SW2_CS28},  /* RGB25-O */
    {0, SW2_CS32,  SW2_CS33,  SW2_CS31},  /* RGB26-P */
    {0, SW2_CS35,  SW2_CS36,  SW2_CS34},  /* RGB27-[ */
    {0, SW2_CS38,  SW2_CS39,  SW2_CS37},  /* RGB28-] */
    {0, SW7_CS38,  SW7_CS39,  SW7_CS37},  /* RGB29-\ */
    {0, SW7_CS35,  SW7_CS36,  SW7_CS34},  /* RGB30-PgUp */

    {0, SW3_CS2,  SW3_CS3,  SW3_CS1},  /* RGB31-CAPS---ROW3*/
    {0, SW3_CS5,  SW3_CS6,  SW3_CS4},  /* RGB32-A-- */
    {0, SW3_CS8,  SW3_CS9,  SW3_CS7},  /* RGB33-S-- */
    {0, SW3_CS11,  SW3_CS12,  SW3_CS10}, /* RGB34-D */
    {0, SW3_CS14,  SW3_CS15,  SW3_CS13}, /* RGB35-F */
    {0, SW3_CS17,  SW3_CS18,  SW3_CS16}, /* RGB36-G */
    {0, SW3_CS20,  SW3_CS21,  SW3_CS19}, /* RGB37-H */
    {0, SW3_CS23,  SW3_CS24,  SW3_CS22}, /* RGB38-J */
    {0, SW3_CS26,  SW3_CS27,  SW3_CS25}, /* RGB39-K */
    {0, SW3_CS29,  SW3_CS30,  SW3_CS28}, /* RGB40-L */
    {0, SW3_CS32,  SW3_CS33,  SW3_CS31}, /* RGB41-;: */
    {0, SW3_CS35,  SW3_CS36,  SW3_CS34}, /* RGB42-'" */
    {0, SW8_CS38,  SW8_CS39,  SW8_CS37}, /* RGB43-ENTER */
    {0, SW8_CS35,  SW8_CS36,  SW8_CS34}, /* RGB44-Page Down */
    

    {0, SW4_CS2,  SW4_CS3,  SW4_CS1},    /* RGB45-LSF --ROW4*/
    {0, SW4_CS5,  SW4_CS6,  SW4_CS4},    /* RGB46-Z */
    {0, SW4_CS8,  SW4_CS9,  SW4_CS7},    /* RGB47-X */
    {0, SW4_CS11,  SW4_CS12,  SW4_CS10}, /* RGB48-C */ 
    {0, SW4_CS14,  SW4_CS15,  SW4_CS13},  /* RGB49-V */
    {0, SW4_CS17,  SW4_CS18,  SW4_CS16},  /* RGB50-B */
    {0, SW4_CS20,  SW4_CS21,  SW4_CS19},  /* RGB51-N */
    {0, SW4_CS23,  SW4_CS24,  SW4_CS22},  /* RGB52-M */
    {0, SW4_CS26,  SW4_CS27,  SW4_CS25},  /* RGB53-,< */
    {0, SW4_CS29,  SW4_CS30,  SW4_CS28},  /* RGB54->. */
    {0, SW4_CS32,  SW4_CS33,  SW4_CS31},  /* RGB55-?/ */
    {0, SW4_CS35,  SW4_CS36,  SW4_CS34},  /* RGB56-RSF */
    {0, SW9_CS38,  SW9_CS39,  SW9_CS37},  /* RGB57-UP */
    {0, SW9_CS35,  SW9_CS36,  SW9_CS34},  /* RGB58-End */

    {0, SW5_CS2,  SW5_CS3,  SW5_CS1},  /* RGB59-lct-- ROW5*/
    {0, SW5_CS5,  SW5_CS6,  SW5_CS4},  /* RGB60-lwin */
    {0, SW5_CS8,  SW5_CS9,  SW5_CS7},  /* RGB61-lalt */
    {0, SW5_CS17,  SW5_CS18,  SW5_CS16},  /* RGB62-sp */
    {0, SW5_CS29,  SW5_CS30,  SW5_CS28},  /* RGB63-ralt */
    {0, SW5_CS32,  SW5_CS33,  SW5_CS31},  /* RGB64- fn */
    {0, SW4_CS38,  SW4_CS39,  SW4_CS37},  /* RGB65-left */
    {0, SW5_CS38,  SW5_CS39,  SW5_CS37},  /* RGB66-down */
    {0, SW5_CS35,  SW5_CS36,  SW5_CS34}  /* RGB67-right */
};

led_config_t g_led_config = { {
    { 0,   1,   2,   3,      4,      5,   6,      7,      8,      9,   10,  11,     12,   14,   15 },    
	{ 16,  17,  18,  19,     20,     21,  22,     23,     24,     25,  26,  27,     28,   29,   30 },    
	{ 31,  32,  33,  34,     35,     36,  37,     38,     39,     40,  41,  42,     43,   13,   44 }, 
	{ 45,  46,  47,  48,     49,     50,  51,     52,     53,     54,  55,  NO_LED, 56,   57,   58 },    
	{ 59,  60,  61,  NO_LED, NO_LED, 62,  NO_LED, NO_LED, NO_LED, 63,  64,  NO_LED, 65,   66,   67 }
}, {
    // LED Index to Physical Position
    { 0, 0 },  { 15, 0 },  { 30, 0 },  { 45, 0 },  { 60, 0 },  { 75, 0 },  { 90, 0 },  { 105, 0 },  { 120, 0 }, { 135, 0 },  { 150, 0 },  { 165, 0 },  { 180, 0 },  { 195, 0 },  { 210, 0 },  { 224, 0 }, 
    { 4, 16},  { 22, 16},  { 37, 16},  { 52, 16},  { 67, 16},  { 82, 16},  { 97, 16},  { 112, 16 }, { 127, 16}, {142, 16},   {157, 16 },  { 172, 16},  { 187, 16},  { 206, 16},               { 224, 16}, 
    { 6, 32},  { 26, 32},  { 41, 32},  { 56, 32},  { 71, 32},  { 86, 32},  {101, 32},  { 116, 32},  { 131, 32}, {146, 32},   { 161, 32},  { 176, 32},  { 201, 32},                            { 224, 32},
    { 8, 48},              { 31, 48},  { 46, 48},  { 61, 48},  { 76, 48},  { 91, 48},  { 106, 48},  { 121, 48}, { 136, 48},  { 151, 48},  { 166, 48},  { 183, 48},  { 210, 48},               { 224, 48}, 
    { 2, 64},  { 21, 64},  { 39, 64},                                      { 91, 64},                                                     { 145, 64},  {163, 64},   { 195, 64},  { 210, 64 }, { 224, 64}
}, {
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1, 
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,       1, 
    1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,
    1, 1, 1,       4,          1, 1,       1, 1, 1
    }
};

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(31, 0xFF, 0xFF, 0xFF);
    }

    return true;
}

#endif
