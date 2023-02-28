/* Copyright 2020 Jason Williams (Wilba)
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


#define LOWER FN_MO13
#define RAISE FN_MO23


enum custom_keycodes {
    DBLCOLN = SAFE_RANGE // ::
};


enum keyboard_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAME,
    _NUMERIC
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        LCTL(KC_UP),           KC_TAB,      KC_Q,             KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        LCTL(KC_LEFT), LCTL_T(KC_ESC),  KC_A,             KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        LCTL(KC_RGHT),        KC_LSFT,  KC_Z,             KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_QUOTE) ,
        TG(_GAME),       MO(_NUMERIC),  LCTL(KC_LSFT), KC_LALT, KC_LGUI,   LOWER,  KC_SPC,            RAISE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),


    [_LOWER] = LAYOUT(
        _______,   KC_ESC,           KC_1,            KC_2,       KC_3,    KC_4,       KC_5,     KC_6,    KC_7,       KC_8,        KC_9,       KC_0, _______,
        _______,  _______,        _______,         _______,    _______, _______,    _______,  _______, KC_UNDS, RALT(KC_P),  RALT(KC_Q), RALT(KC_W), _______,
        _______,  _______,        _______,         _______,    _______, _______,    _______,  _______, _______,    _______,     _______,    KC_BSLS,  KC_GRV,
        _______,  _______,        _______,         _______,    _______, _______,    _______,           _______,    KC_HOME,     KC_PGDN,    KC_PGUP,  KC_END
    ),
    [_RAISE] = LAYOUT(
        _______,  _______,        KC_QUOT,           KC_LT,      KC_GT, KC_DQUO,      KC_AT,  KC_AMPR, DBLCOLN,    KC_LBRC,  KC_RBRC,    KC_PERC,    KC_DEL,
        _______,  _______,        KC_EXLM,         KC_MINS,    KC_PLUS,  KC_EQL,    KC_HASH,  KC_PIPE, KC_COLN,    KC_LPRN,  KC_RPRN,    KC_QUES,    KC_INS,
        _______,  _______,        KC_CIRC,         KC_SLSH,    KC_ASTR, KC_BSLS,    KC_UNDS,  KC_TILD,  KC_DLR,    KC_LCBR,  KC_RCBR,    _______,   _______,
        _______,  _______,        _______,         _______,    _______, _______,    _______,           _______,    KC_HOME,  KC_PGDN,    KC_PGUP,    KC_END
    ),

    [_ADJUST] = LAYOUT(
        QK_BOOTLOADER,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,
              _______, KC_CAPS,  KC_F12,  KC_PSCR,  _______,   BR_INC,   EF_INC,  ES_INC,  H1_INC,   S1_INC,   H2_INC,   S2_INC,  _______,
              _______, _______, _______,  _______,  _______,   BR_DEC,   EF_DEC,  ES_DEC,  H1_DEC,   S1_DEC,   H2_DEC,   S2_DEC,  _______,
              _______, _______, _______,  _______,  _______,  _______,  _______,          _______,  _______,  KC_VOLD,  KC_VOLU,  _______
    ),

    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
    ),

    [_NUMERIC] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_4, KC_5, KC_6,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_DOT, KC_0, KC_COMMA
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case DBLCOLN:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            return false;
    }
    return true;
}
