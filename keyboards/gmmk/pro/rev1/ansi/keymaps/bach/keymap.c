/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2021 Andre Brait <andrebrait@gmail.com>

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

#ifdef RGB_MATRIX_ENABLE
void set_layer_rgb(void);

    #ifndef RGB_CONFIRMATION_BLINKING_TIME
        #define RGB_CONFIRMATION_BLINKING_TIME 2000 // 2 seconds
    #endif

#endif // RGB_MATRIX_ENABLE

typedef enum
{
    _DEFAULT = 0,
    _FN,
    _CAPS,
    _VIA
} layer;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del               Rotary_Push Rotary_CCW Rotary_CW
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Home
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [_DEFAULT] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        MO(2),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FN] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_INS,           _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, KC_UP,   _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, RGB_VAD, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, RGB_HUI, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),
    [_CAPS] = LAYOUT(
        _______,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,   KC_F22, KC_F23, KC_F24,  _______,          KC_BTN1,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______,    KC_LEFT,    KC_DOWN,    KC_UP,   KC_RGHT, _______, _______, _______,          _______,
        _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,             _______, KC_MS_U, _______,
        _______, _______, _______,                            _______,                          _______, _______,   _______, KC_MS_L, KC_MS_D, KC_MS_R
    ),

    [_VIA] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
};
// clang-format on

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_DEFAULT] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_CAPS] = { ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [_VIA] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case KC_VOLD:
    case KC_VOLU:
    {
        if (record->event.pressed)
        {
            if (get_mods() & (MOD_MASK_CTRL | MOD_MASK_ALT))
            {
                if (keycode == KC_VOLD)
                    tap_code16(S(KC_TAB));
                else
                    tap_code(KC_TAB);
            }
            else
            {
                tap_code(keycode);
            }
        }
        return false;
    }
    default:
        return true;
    }
    return true;
}
#endif // ENCODER_MAP_ENABLE

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    set_layer_rgb();
    return false;
}

void set_layer_rgb(void)
{
    if (layer_state_is(1) || layer_state_is(2)) rgb_matrix_set_color_all(0, 0, 0);

    if (layer_state_is(1))
    {
        rgb_matrix_set_color(6, 0, 255, 0);  // f1
        rgb_matrix_set_color(12, 0, 255, 0); // f2
        rgb_matrix_set_color(18, 0, 255, 0); // f3
        rgb_matrix_set_color(23, 0, 255, 0); // f4
        rgb_matrix_set_color(28, 0, 255, 0); // f5
        rgb_matrix_set_color(34, 0, 255, 0); // f6
        rgb_matrix_set_color(39, 0, 255, 0); // f7
        rgb_matrix_set_color(44, 0, 255, 0); // f8
        rgb_matrix_set_color(50, 0, 255, 0); // f9
        rgb_matrix_set_color(56, 0, 255, 0); // f10
        rgb_matrix_set_color(61, 0, 255, 0); // f11
        rgb_matrix_set_color(72, 0, 255, 0); // del
        rgb_matrix_set_color(7, 255, 0, 255); // 1
        rgb_matrix_set_color(14, 255, 128, 0); // w
        rgb_matrix_set_color(25, 255, 0, 255); // r
        rgb_matrix_set_color(93, 255, 0, 0); // |
        rgb_matrix_set_color(9, 255, 128, 0); // a
        rgb_matrix_set_color(15, 255, 128, 0); // s
        rgb_matrix_set_color(21, 255, 128, 0); // d
        rgb_matrix_set_color(26, 255, 0, 255); // f
        rgb_matrix_set_color(22, 255, 0, 255); // c
        rgb_matrix_set_color(38, 255, 153, 153); // n
        rgb_matrix_set_color(94, 255, 0, 255); // up
        rgb_matrix_set_color(97, 255, 0, 255); // down
        rgb_matrix_set_color(95, 255, 0, 255); // left
        rgb_matrix_set_color(79, 255, 0, 255); // right
    }

    if (layer_state_is(2))
    {
        rgb_matrix_set_color(6, 0, 255, 0);  // f1
        rgb_matrix_set_color(12, 0, 255, 0); // f2
        rgb_matrix_set_color(18, 0, 255, 0); // f3
        rgb_matrix_set_color(23, 0, 255, 0); // f4
        rgb_matrix_set_color(28, 0, 255, 0); // f5
        rgb_matrix_set_color(34, 0, 255, 0); // f6
        rgb_matrix_set_color(39, 0, 255, 0); // f7
        rgb_matrix_set_color(44, 0, 255, 0); // f8
        rgb_matrix_set_color(50, 0, 255, 0); // f9
        rgb_matrix_set_color(56, 0, 255, 0); // f10
        rgb_matrix_set_color(61, 0, 255, 0); // f11
        rgb_matrix_set_color(66, 0, 255, 0); // f12
        rgb_matrix_set_color(37, 255, 128, 0); // h
        rgb_matrix_set_color(42, 255, 128, 0); // j
        rgb_matrix_set_color(47, 255, 128, 0); // k
        rgb_matrix_set_color(53, 255, 128, 0); // l
        rgb_matrix_set_color(94, 255, 102, 255); // up
        rgb_matrix_set_color(97, 255, 102, 255); // down
        rgb_matrix_set_color(95, 255, 102, 255); // left
        rgb_matrix_set_color(79, 255, 102, 255); // right

    }
}
#endif // RGB_MATRIX_ENABLE
