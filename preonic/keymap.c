/*
 * Kristoffer Gronlund, 2023
 */
#include QMK_KEYBOARD_H


enum custom_keycodes {
    DBLCOLN = SAFE_RANGE, // ::
    HEXPFIX // 0x
};


enum preonic_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAME,
    _NUMERIC
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_preonic_grid(
      QK_GESC,        KC_1,            KC_2,    KC_3,    KC_4,       KC_5,     KC_6,     KC_7,       KC_8,     KC_9,       KC_0,       KC_DEL,
      KC_TAB,         KC_Q,            KC_W,    KC_E,    KC_R,       KC_T,     KC_Y,     KC_U,       KC_I,     KC_O,       KC_P,       KC_BSPC,
      LCTL_T(KC_ESC), KC_A,            KC_S,    KC_D,    KC_F,       KC_G,     KC_H,     KC_J,       KC_K,     KC_L,       KC_SCLN,    KC_ENTER,
      KC_LSFT,        KC_Z,            KC_X,    KC_C,    KC_V,       KC_B,     KC_N,     KC_M,       KC_COMMA, KC_DOT,     KC_SLASH,   KC_QUOTE,
      MO(_NUMERIC),   LCTL(KC_LSFT),   KC_LALT, KC_LGUI, MO(_LOWER), KC_SPACE, KC_SPACE, MO(_RAISE), KC_LEFT,  KC_DOWN,    KC_UP,      KC_RIGHT
    ),
    [_LOWER] = LAYOUT_preonic_grid(
       KC_GRV,        KC_EXLM,           KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,  KC_CIRC, KC_AMPR,    KC_ASTR,     KC_LPRN,    KC_RPRN,  KC_INS,
      _______,           KC_1,            KC_2,       KC_3,    KC_4,       KC_5,     KC_6,    KC_7,       KC_8,        KC_9,       KC_0, HEXPFIX,
      _______,        _______,         _______,    _______, _______,    _______,  _______, KC_UNDS, RALT(KC_P),  RALT(KC_Q), RALT(KC_W), _______,
      _______,        _______,         _______,    _______, _______,    _______,  _______, _______,LCTL_T(KC_MINS),LCTL_T(KC_PLUS),KC_BSLS,  KC_GRV,
      _______,        _______,         _______,    _______, _______,    _______,  _______, _______,    KC_HOME,     KC_PGDN,    KC_PGUP,  KC_END
    ),
    [_RAISE] = LAYOUT_preonic_grid(
      KC_TILD,        _______,         _______, _______, _______,    _______,  _______,  _______,    _______,  _______,    _______,    _______,
      _______,        KC_QUOT,           KC_LT,      KC_GT, KC_DQUO,      KC_AT,  KC_AMPR, DBLCOLN,    KC_LBRC,  KC_RBRC,    KC_PERC,    KC_DEL,
      _______,        KC_EXLM,         KC_MINS,    KC_PLUS,  KC_EQL,    KC_HASH,  KC_PIPE, KC_COLN,    KC_LPRN,  KC_RPRN,    KC_QUES,    KC_INS,
      _______,        KC_CIRC,         KC_SLSH,    KC_ASTR, KC_BSLS,    KC_UNDS,  KC_TILD,  KC_DLR,    KC_LCBR,  KC_RCBR,    _______,   _______,
      _______,        _______,         _______,    _______, _______,    _______,  _______, _______,    KC_HOME,  KC_PGDN,    KC_PGUP,    KC_END
    ),
    [_ADJUST] = LAYOUT_preonic_grid(
      KC_SCRL,        KC_F1,           KC_F2,   KC_F3,   KC_F4,      KC_F5,    KC_F6,    KC_F7,      KC_F8,    KC_F9,      KC_F10,     KC_F11,
      KC_CAPS,        KC_F12,          KC_PSCR, _______, _______,    _______,  _______,  _______,    _______,  KC_MUTE,    KC_VOLD,    KC_VOLU,
      _______,        _______,         _______, _______, _______,    _______,  _______,  _______,    RGB_MOD,  RGB_TOG,    RGB_VAD,    RGB_VAI,
      _______,        _______,         _______, _______, _______,    _______,  _______,  _______,    BL_BRTG,  BL_TOGG,    BL_STEP,    _______,
      _______,        _______,         _______, _______, _______,    _______,  _______,  _______,    _______,  BL_DEC,     BL_INC,     _______
    ),
    [_GAME] = LAYOUT_preonic_grid(
      _______,        _______,         _______, _______, _______,    _______,  _______,  _______,    _______,  _______,    _______,    KC_F9,
      _______,        _______,         _______, _______, _______,    _______,  _______,  _______,    _______,  _______,    _______,    _______,
      KC_LCTL,        _______,         _______, _______, _______,    _______,  _______,  _______,    _______,  _______,    _______,    _______,
      _______,        _______,         _______, _______, _______,    _______,  _______,  _______,    _______,  _______,    _______,    _______,
      _______,        _______,         _______, _______, _______,    _______,  _______,  _______,    _______,  _______,    _______,    _______
    ),
    [_NUMERIC] = LAYOUT_preonic_grid(
      TG(_GAME),        _______,         _______, _______, _______,    _______,  _______,  _______,    _______,  _______,    _______,    _______,
      _______,        _______,         _______, _______, _______,    _______,  _______,  _______,    _______,  KC_1,       KC_2,       KC_3,
      _______,        _______,         _______, _______, _______,    _______,  _______,  _______,    _______,  KC_4,       KC_5,       KC_6,
      _______,        _______,         _______, _______, _______,    _______,  _______,  _______,    _______,  KC_7,       KC_8,       KC_9,
      _______,        _______,         _______, _______, _______,    _______,  _______,  _______,    HEXPFIX,  KC_DOT,     KC_0,       KC_COMMA
    )
};

#define HSV_ORANGE2 18, 255, 255

const rgblight_segment_t PROGMEM krig_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_RED}
);
const rgblight_segment_t PROGMEM krig_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(

    {0, RGBLED_NUM, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM krig_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_BLUE}
);
const rgblight_segment_t PROGMEM krig_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_GREEN}
);
const rgblight_segment_t PROGMEM krig_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM krig_game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_ORANGE2}
);
const rgblight_segment_t PROGMEM krig_numeric_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_SPRINGGREEN}
);

enum light_layers {
    _L_BASE,
    _L_CAPS,
    _L_LOWER,
    _L_RAISE,
    _L_GAME,
    _L_NUMERIC,
    _L_ADJUST
};

const rgblight_segment_t* const PROGMEM krig_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    krig_base_layer,
    krig_capslock_layer,
    krig_lower_layer,
    krig_raise_layer,
    krig_game_layer,
    krig_numeric_layer,
    krig_adjust_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = krig_rgb_layers;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case DBLCOLN:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            return false;
        case HEXPFIX:
            if (record->event.pressed) {
                SEND_STRING("0x");
            }
            return false;
    }
    return true;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(_L_CAPS, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_L_BASE, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    rgblight_set_layer_state(_L_LOWER, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(_L_RAISE, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(_L_GAME, layer_state_cmp(state, _GAME));
    rgblight_set_layer_state(_L_NUMERIC, layer_state_cmp(state, _NUMERIC));
    rgblight_set_layer_state(_L_ADJUST, layer_state_cmp(state, _ADJUST));
    return state;
}
