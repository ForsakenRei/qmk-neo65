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

#pragma once

/* RGB matrix */
#ifdef RGB_MATRIX_ENABLE
// i2c setting
#define I2C1_CLOCK_SPEED 400000  
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2 
#define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#define RGB_MATRIX_SLEEP  // turn off effects when suspended
#define RGB_MATRIX_LED_PROCESS_LIMIT  4
#define RGB_MATRIX_LED_FLUSH_LIMIT    16
#define RGB_MATRIX_STARTUP_VAL        200
#define IS31FL3741_I2C_ADDRESS_1 IS31FL3741_I2C_ADDRESS_GND
#define RGB_MATRIX_DISABLE_SHARED_KEYCODES
#endif
