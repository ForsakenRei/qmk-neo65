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

#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"

#define ARRAYSIZE(arr) sizeof(arr) / sizeof(arr[0])

#define _BASE 0
#define _L1 1
#define _L2 2
#define _L3 3

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes
{
    TSK_MGR = SAFE_RANGE,
    RSFT_L3,
    CTL_APP,
};

enum td_keycodes
{
    CAPS_LAYR,
    RSFT_LAY3,
    KCFN_L2,
    HOME_PAGEUP,
    END_PAGEDOWN,
};

#define CAP_L1 TD(CAPS_LAYR)
#define FN_L2 TD(KCFN_L2)
#define RSFT_L3 TD(RSFT_LAY3)
#define DC_MUTE C(S(KC_M)) // used for mute/unmute
#define TSK_MGR C(S(KC_ESC))
#define CTL_APP CTL_T(KC_APP)
#define SERACH G(S(KC_N))
#define SFT_DEL S(KC_DEL)
#define HOME_PU TD(HOME_PAGEUP)
#define END_PD TD(END_PAGEDOWN)
#define SCR_LFT G(S(KC_LEFT))
#define SCR_RHT G(S(KC_RGHT))
#define VD_LEFT G(C(KC_LEFT))
#define VD_RGHT G(C(KC_RIGHT))

bool _isWinKeyDisabled = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_hot(
        QK_GESC, KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC, KC_DEL,   
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, HOME_PU,
        CAP_L1,  KC_A,    KC_S,    KC_D,   KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           END_PD,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   RSFT_L3,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             FN_L2,   KC_RCTL,          KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [1] = LAYOUT_hot(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL,  KC_INS,
        _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, VD_LEFT, SCR_LFT, SCR_RHT, VD_RGHT, _______, _______, _______,          _______,
        _______, KC_WBAK, KC_BSPC, KC_WFWD, _______, _______, SERACH,  TSK_MGR, _______, _______, _______, _______,          _______, KC_MUTE,
        _______, _______, _______,                   KC_DEL,                             _______, CTL_APP,          _______, _______, _______
    ),
    [2] = LAYOUT_hot(
        _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SFT_DEL, KC_SLEP,
        _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_7,    KC_8,    KC_9,    _______, _______, VD_LEFT, SCR_LFT, SCR_RHT, VD_RGHT, _______, _______, _______,          _______,
        _______, KC_0,    _______, KC_CALC, _______, _______, _______, TSK_MGR, _______, _______, _______, _______,          KC_BSPC, _______,
        _______, GU_TOGG, _______,                   KC_DEL,                             _______, _______,          KC_WBAK, KC_F5,   KC_WFWD
    ),
    [3] = LAYOUT_hot(
        RGB_TOG, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE, _______, _______, KC_F13,  KC_F14,  QK_BOOT, _______, RGB_SAI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, RGB_SAD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, EE_CLR,           RGB_HUI,
        _______, _______, _______, _______, _______, _______, _______, DC_MUTE, _______, _______, _______, QK_RBT,           RGB_MOD, RGB_HUD,
        _______, _______, _______,                   _______,                            TO(0),   _______,          RGB_VAD, RGB_RMOD,RGB_VAI
    )
};

// RGB matrix
#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
    if (keymap_config.no_gui)
    {
        rgb_matrix_set_color(LED_LGUI, RGB_RED); // light up Win key when disabled
    }
    switch (get_highest_layer(layer_state))
    {
    case _BASE:
        if (host_keyboard_led_state().caps_lock)
        {
            rgb_matrix_set_color_all(0, 0, 0);
            for (uint8_t i = 0; i < ARRAYSIZE(LED_LAYER); i++)
            {
                rgb_matrix_set_color(LED_LAYER[i], RGB_CYAN);
            }
        }
        else
        {
            rgb_matrix_set_color_all(0, 0, 0);
        }
        break;
    case _L1:
        rgb_matrix_set_color_all(0, 0, 0);
        for (uint8_t i = 0; i < ARRAYSIZE(LED_LAYER); i++)
        {
            rgb_matrix_set_color(LED_LAYER[i], RGB_GOLDENROD);
        }
        break;
    case _L2:
        rgb_matrix_set_color_all(0, 0, 0);
        for (uint8_t i = 0; i < ARRAYSIZE(LED_LAYER); i++)
        {
            rgb_matrix_set_color(LED_LAYER[i], RGB_CHARTREUSE);
        }
        break;
    case _L3:
        rgb_matrix_set_color_all(0, 0, 0);
        for (uint8_t i = 0; i < ARRAYSIZE(LED_LAYER); i++)
        {
            rgb_matrix_set_color(LED_LAYER[i], RGB_CORAL);
        }
        break;
    default:
        break;
    }
    return false;
};
#endif

// tap dance
typedef enum
{ // quad function tap-dance
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct
{
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void caps_finished(tap_dance_state_t *state, void *user_data);
void caps_reset(tap_dance_state_t *state, void *user_data);
void fn_finished(tap_dance_state_t *state, void *user_data);
void fn_reset(tap_dance_state_t *state, void *user_data);
void sft_finished(tap_dance_state_t *state, void *user_data);
void sft_reset(tap_dance_state_t *state, void *user_data);

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state)
{
    if (state->count == 1)
    {
        if (!state->pressed)
            return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    }
    else if (state->count == 2)
        return TD_DOUBLE_TAP;
    else
        return TD_UNKNOWN;
}

static td_tap_t caps_tap_state = {
    .is_press_action = true,
    .state = TD_NONE};
static td_tap_t fn_tap_state = {
    .is_press_action = true,
    .state = TD_NONE};
static td_tap_t sft_tap_state = {
    .is_press_action = true,
    .state = TD_NONE};

// Functions that control what our tap dance key does
void caps_finished(tap_dance_state_t *state, void *user_data)
{
    caps_tap_state.state = cur_dance(state);
    switch (caps_tap_state.state)
    {
    case TD_SINGLE_TAP:
        tap_code(KC_CAPS);
        break;
    case TD_SINGLE_HOLD:
        layer_on(_L1);
        break;
    case TD_DOUBLE_TAP:
        // Check to see if the layer is already set
        if (layer_state_is(_L1))
        {
            // If already set, then switch it off
            layer_off(_L1);
        }
        else
        {
            // If not already set, then switch the layer on
            layer_on(_L1);
        }
        break;
    default:
        break;
    }
};

void caps_reset(tap_dance_state_t *state, void *user_data)
{
    // If the key was held down and now is released then switch off the layer
    if (caps_tap_state.state == TD_SINGLE_HOLD)
    {
        layer_off(_L1);
    }
    caps_tap_state.state = TD_NONE;
};

// tap dance for Fn
void fn_finished(tap_dance_state_t *state, void *user_data)
{
    fn_tap_state.state = cur_dance(state);
    switch (fn_tap_state.state)
    {
    case TD_SINGLE_TAP:
        set_oneshot_layer(_L2, ONESHOT_START);
        clear_oneshot_layer_state(ONESHOT_PRESSED);
        break;
    case TD_SINGLE_HOLD:
        layer_on(_L2);
        break;
    case TD_DOUBLE_TAP:
        if (layer_state_is(_L2))
        {
            layer_off(_L2);
        }
        else
        {
            layer_on(_L2);
        }
        break;
    default:
        break;
    }
};

void fn_reset(tap_dance_state_t *state, void *user_data)
{
    switch (fn_tap_state.state)
    {
    case TD_SINGLE_HOLD:
        layer_off(_L2);
        break;
    default:
        break;
    }
};

void sft_finished(tap_dance_state_t *state, void *user_data)
{
    sft_tap_state.state = cur_dance(state);
    switch (sft_tap_state.state)
    {
    case TD_SINGLE_TAP:
        // register_code(KC_RSFT);
        set_oneshot_layer(_L3, ONESHOT_START);
        clear_oneshot_layer_state(ONESHOT_PRESSED);
        break;
    case TD_SINGLE_HOLD:
        layer_on(_L3);
        break;
    case TD_DOUBLE_TAP:
        if (layer_state_is(_L3))
        {
            layer_off(_L3);
        }
        else
        {
            layer_on(_L3);
        }
        break;
    default:
        break;
    }
};

void sft_reset(tap_dance_state_t *state, void *user_data)
{
    switch (sft_tap_state.state)
    {
    // case TD_SINGLE_TAP:
    //   unregister_code(KC_RSFT);
    case TD_SINGLE_HOLD:
        layer_off(_L3);
        break;
    default:
        break;
    }
};

tap_dance_action_t tap_dance_actions[] = {
    [CAPS_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps_finished, caps_reset),
    [KCFN_L2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_finished, fn_reset),
    [RSFT_LAY3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_finished, sft_reset),
    [HOME_PAGEUP] = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, KC_HOME),
    [END_PAGEDOWN] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_END),
};

// key override
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t lalt_f12_override = ko_make_basic(MOD_BIT(KC_LALT), KC_EQL, A(KC_F12));
const key_override_t rshift_f12_override = ko_make_basic(MOD_BIT(KC_RCTL), KC_MINS, S(KC_F12));
const key_override_t rctrl_tilde_override = ko_make_basic(MOD_BIT(KC_RCTL), QK_GESC, C(KC_GRV));

const key_override_t *key_overrides[] = {
    &delete_key_override,
    &lalt_f12_override,
    &rshift_f12_override,
    &rctrl_tilde_override,
    NULL};
