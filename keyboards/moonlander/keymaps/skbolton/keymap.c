/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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
#include "version.h"
#include "skbolton.h"

#define _QWERTY 0
#define _FN 1
#define _NUMPAD 2
#define _CODE 3
#define _ARROWS 4
#define _WINDOW_PAD 5
#define _GAMING 6
#define _GAMING_ALT 7
#define _GAMING_FN 8

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for shift, twice for Caps Lock
  [TD_CAPS_ATTACK]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_moonlander(
  LALT(KC_DOT),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TG(_GAMING),       KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,           _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        WINDOW,    ARROWS,  KC_S,    ALTD,    CTRLF,   KC_G,    KC_HYPR,        KC_MEH,  KC_H,   CTRLJ, ALTK,    KC_L,    KC_SCLN, LGUI_T(KC_QUOT),
        CAPS,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH),   CAPS,
        KC_GRV, SGUI(KC_TAB),RGUI(KC_TAB),KC_LEFT, KC_RGHT,  LGUI(KC_1),     RALT(KC_D),   KC_DOWN,   KC_UP, KC_LBRC, KC_RBRC, _______,
                                            NUM_TAB, CODE, KC_ESC,           TMUX,  KC_ENT,  SUPER
    ),

    [_ARROWS] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, RGB_SAI,           RGB_HUI, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, RGB_SAD,           RGB_HUD, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,           _______,          _______,          _______, _______, _______, _______, _______,
                                            _______, _______,  RGB_TOG,          _______, RGB_RMOD, RGB_MOD
    ),

    [_GAMING] = LAYOUT_moonlander(
   LALT(KC_TAB), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,          _______, _______, _______, _______, _______, _______, _______,
        KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,           _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,           _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               _______, _______, _______, _______, _______, _______,
      MO(_GAMING_ALT), KC_DOWN, KC_UP, KC_LEFT, KC_RGHT,          KC_SPC,            _______,         _______, _______, _______, _______, _______,
                                            KC_TAB, KC_BSPC,  KC_ESC,            _______, _______, _______
    ),

    [_GAMING_ALT] = LAYOUT_moonlander(
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_G,             _______, _______, _______, _______, _______, _______, _______,
 MO(_GAMING_FN), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                            _______, _______, _______, _______, _______, _______,
        _______, KC_DOWN, KC_UP, KC_LEFT, KC_RGHT,            KC_SPC,           _______,          _______, _______, _______, _______, _______,
                                            KC_TAB, KC_BSPC,  KC_ESC,           _______, _______, _______
    ),

    [_GAMING_FN] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,         _______,            _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [_CODE] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, EEP_RST, RESET,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_LT,   KC_ASTR, KC_LPRN, KC_RPRN, KC_HASH, KC_PLUS,
        _______, _______, _______, KC_AMPR, KC_EXLM, _______, _______,           _______, KC_GT,   KC_EQL,  KC_LCBR, KC_RCBR, KC_AT,   KC_MINS,
        _______, _______, _______, _______, _______, _______,                             KC_TILD, KC_GRV,  KC_LBRC, KC_RBRC, KC_PIPE, KC_PERC,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           KC_CIRC, KC_DLR, KC_UNDS
    ),

    [_NUMPAD] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, KC_1,    KC_2,    KC_3,    _______, _______,
        _______, _______, _______, _______, _______,         _______,            _______,          KC_0,    _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [_WINDOW_PAD] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

void keyboard_post_init_user(void) {
  rgb_matrix_sethsv(HSV_PURPLE);
  rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  if (IS_LAYER_ON_STATE(state, _GAMING)) {
    rgb_matrix_mode(RGB_MATRIX_JELLYBEAN_RAINDROPS);
  }
  else {
    rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE);
  }

  return state;
}
