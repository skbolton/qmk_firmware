// custom keycodes
#define NUM_TAB LT(_NUMPAD, KC_TAB)
#define CODE LT(_CODE, KC_BSPC)
#define WINDOW OSL(_WINDOW_PAD)
#define ARROWS LT(_ARROWS, KC_A)
#define CTRLF LCTL_T(KC_F)
#define CTRLJ RCTL_T(KC_J)
#define ALTD LALT_T(KC_D)
#define ALTK RALT_T(KC_K)
#define SUPER RGUI_T(KC_SPC)
#define TMUX RCTL(KC_B)
#ifdef TAP_DANCE_ENABLE
#     define CAPS TD(TD_CAPS_ATTACK)
#else
#     define CAPS(KC_LSFT)
#endif

#ifdef TAP_DANCE_ENABLE
//Tap Dance Declarations
enum {
  TD_CAPS_ATTACK = 0,
  TD_SLASHES = 1
};
#endif

