#include QMK_KEYBOARD_H
#include "skbolton.h"

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN 1
#define _NUMPAD 2
#define _CODE 3
#define _ARROWS 4
#define _WINDOW_PAD 5

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CAPS_ATTACK]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [TD_SLASHES]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_NUBS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      TT(_FN),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,  KC_P,   KC_BSLS,   \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      WINDOW, ARROWS,  KC_S,    ALTD,    CTRLF,   KC_G,                           KC_H,  CTRLJ,   ALTK,    KC_L,   KC_SCLN, KC_QUOT, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CAPS,    KC_Z    ,KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SLSH, CAPS,    \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ESC, NUM_TAB, CODE,        KC_ENT,  SUPER,   TMUX                                        \
                                      //`--------------------------'  `--------------------------'
  ),

  [_FN] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      KC_F12, KC_F7,    KC_F8,   KC_F9, _______, RESET,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_F11, KC_F4,    KC_F5,   KC_F6, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_F10, KC_F1,    KC_F2,   KC_F3, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______,  _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_CODE] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            KC_LT,   KC_ASTR, KC_LPRN, KC_RPRN, KC_HASH, KC_PLUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_AMPR, KC_EXLM, _______,                            KC_GT,   KC_EQL,  KC_LCBR, KC_RCBR, KC_AT, KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼                          ┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_TILD,  KC_GRV, KC_LBRC, KC_RBRC, KC_PIPE, KC_PERC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,  KC_CIRC,  KC_DLR, KC_UNDS \
                                      //`--------------------------'  `--------------------------'
  ),
  [_ARROWS] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            _______,  _______,    _______,    _______,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_LEFT,  KC_DOWN, KC_UP,  KC_RIGHT,    _______,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼                          ┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______,  _______,    _______,    _______,    _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   _______,  _______,     _______,   _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),
  [_NUMPAD] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            _______,  KC_7,    KC_8,    KC_9,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, MO(_FN), _______,                            _______,  KC_4,    KC_5,    KC_6,    _______,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼                          ┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______,  KC_1,    KC_2,    KC_3,    _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   _______,  _______,     _______,   KC_0, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_WINDOW_PAD] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            _______,  RGUI(KC_7),    RGUI(KC_8),    RGUI(KC_9),    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______,  RGUI(KC_4),    RGUI(KC_5),    RGUI(KC_6),    _______,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼                          ┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, RGUI(KC_1),RGUI(KC_2),RGUI(KC_3),    _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   _______,  _______,     _______,   _______, _______ \
                                      //`--------------------------'  `--------------------------'
  )
};
