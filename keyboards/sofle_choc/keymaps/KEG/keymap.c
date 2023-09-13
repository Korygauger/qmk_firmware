/* Copyright 2023 Brian Low
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

enum sofle_layers {
    _QWERTY,
    _COLEMAK,
    _GAME,
    _NAV,
    _SYM,
    _ADJUST,
    _NUM,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_QWERTY,
    KC_COLEMAK,
    KC_ALTAB,
    KC_CTLTAB,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LAlt |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | '  " |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * | LCtl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |ENTER |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI |  F4  |  F5  | LSFT | / Bspc  /       \Space \  | NUM  | DEL  | F12  | F11  |
 *            |      |      |      |      |/ (NAV) /         \ (SYM)\ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_EQL,
  KC_LALT,   KC_A,   KC_S,   KC_D, LSFT_T(KC_F), KC_G,                   KC_H,RSFT_T(KC_J),  KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_MPLY, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                 KC_LGUI,KC_F4,KC_F5,KC_SPC, LT(_NAV,KC_BSPC),  LT(_SYM,KC_SPC), TT(_NUM), KC_DEL, KC_F12, KC_F11
),

[_COLEMAK] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_EQL,
  KC_LALT,   KC_A,   KC_R,    KC_S, LSFT_T(KC_T),    KC_D,                KC_H, RSFT_T(KC_N),KC_E,    KC_I,    KC_O,  KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, _______,     _______,KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                 KC_LGUI,KC_F4,KC_F1, KC_SPC, LT(_NAV,KC_BSPC),      LT(_SYM,KC_SPC),  TT(_NUM), KC_DEL, KC_F12, KC_F11
),

// Game Layers
// Base Game Layout great for destiny
[_GAME] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_EQL,
  KC_LCTL,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, _______,     _______,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
            KC_M,   KC_O, MO(_NAV), KC_LALT, KC_SPC,                TG(_GAME),  TT(_NUM), LALT(KC_F4), KC_F12, KC_F11
),
/* Navigation
 * ,----------------------------------------.                     ,-----------------------------------------.
 * | CAD  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CSE  | CTAB |  UP  | ATAB | Home | Lock |                    |Setti |      | WinUp|      |      |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Alt  | LEFT | DOWN |RIGHT | END  | Caps |-------.    ,-------|Sleep | WinL | WinD | WinR |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | CTRL | Undo |  Cut | Copy | Paste| FIND |-------|    |-------| Power| Prev |  F7  | Next |CSlash|ENTER |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / TRNS  /       \ TAB  \  |CTRL  | BSPC |CShift| RGUI |
 *            |      |      |      |      |/       /         \      \ | BSPC |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  LCA(KC_DEL),     KC_F1,    KC_F2,    KC_F3,      KC_F4,   KC_F5,                              KC_F6,         KC_F7,         KC_F8,         KC_F9,        KC_F10,  KC_F11,
  RCS(KC_ESC),  KC_CTLTAB,    KC_UP,  KC_ALTAB,    _______, KC_CAPS,                       LGUI(KC_I),      KC_PRVWD,   LGUI(KC_UP),      KC_NXTWD,   LALT(KC_F4),  KC_F12,
      _______,    KC_LEFT,  KC_DOWN,  KC_RGHT,  LCTL(KC_F), KC_HOME,                       KC_PAGE_UP, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RGHT),       KC_BTN4, _______,
      _______,    KC_UNDO,   KC_CUT,  KC_COPY,    KC_PSTE, KC_END, _______,      _______, KC_PAGE_DOWN,       KC_MPRV,       KC_MPLY,       KC_MNXT, LCTL(KC_SLSH), _______,
                            MO(_SYM), KC_SLEP, _______, LGUI(KC_L), _______,            KC_TAB, KC_DLINE, LCTL(KC_LSFT),       KC_LSFT,       KC_LGUI
),
/* Symbols
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   #  |   /  |   [  |   ]  |   +  |                    |   |  |   <  |   >  |   \  |   '  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Alt  |   @  |   *  |   (  |   )  |   =  |-------.    ,-------|   &  |   ;  |   .  |   ,  |   "  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Ctrl |   $  |   %  |   {  |   }  |   -  |-------|    |-------|   ?  |   :  |   !  |   _  |   `  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \______\  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYM] = LAYOUT(
  KC_GRV, KC_EXLM , KC_AT , KC_HASH , KC_DLR , KC_PERC,                           KC_CIRC,  KC_AMPR  , KC_ASTR, _______, _______ ,_______,
  _______,  KC_HASH,  KC_SLSH,   KC_LBRC,  KC_RBRC, KC_PLUS,                        KC_PIPE, KC_LT,   KC_GT, KC_BSLS,KC_QUOT, _______,
  _______, KC_AT,  KC_ASTR,  KC_LPRN,  KC_RPRN, KC_EQL,                       KC_AMPR,  KC_SCLN, KC_PDOT, KC_COMM,  KC_DQUO, _______,
  _______,KC_DLR, KC_PERC, KC_LCBR, KC_RCBR, KC_MINS,  _______,       _______,  KC_QUES, KC_COLN, KC_EXLM, KC_UNDS,   KC_GRV, _______,
                    KC_MUTE, _______, KC_BSPC, KC_SPC, MO(_NAV),       _______, KC_LSFT, KC_F6, KC_F7, KC_F8
),
/* ADJUST  not correct
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BOOT | Spd+ | Val+ | Sat+ | Hue+ |Mode+ |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Spd- | Val- | Sat- | Hue- |Mode- |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |MacWin|      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_PWR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_GAME), XXXXXXX,                     XXXXXXX,KC_COLEMAK,KC_QWERTY, XXXXXXX, XXXXXXX, XXXXXXX,
    CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),

[_NUM] = LAYOUT(
    XXXXXXX, KC_ACL0, KC_ACL1, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_BTN4, KC_MS_U, KC_BTN5, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_P7, KC_P8, KC_P9, KC_PEQL, XXXXXXX,
    XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,                       KC_LPRN,KC_P4, KC_P5, KC_P6, KC_PPLS, KC_BSPC,
    KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_RPRN, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_PENT,
                      _______, _______, _______, KC_BTN3, KC_BTN1,     _______, _______, KC_PDOT, KC_P0, KC_PCMM
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _ADJUST);
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_ALTAB:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            } else {
                unregister_mods(mod_config(MOD_LALT));
            }
            return false;
        case KC_CTLTAB:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            return false;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            return false;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            return false;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            return false;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            return false;
        case KC_COPY:
            if (record->event.pressed) {
                // CMD-c on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                // CMD-v on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                // CMD-x on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            return false;
        case KC_UNDO:
            if (record->event.pressed) {
                // CMD-z on Mac, but we have CTL and GUI swapped
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        default:
            return true;
    }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] =   { ENCODER_CCW_CW(KC_MS_WH_RIGHT, KC_MS_WH_LEFT), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
    [_COLEMAK] =   { ENCODER_CCW_CW(KC_MS_WH_RIGHT, KC_MS_WH_LEFT), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
    [_GAME] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
    [_SYM] =  { ENCODER_CCW_CW(LCTL(KC_PPLS), LCTL(KC_PMNS)),   ENCODER_CCW_CW(LCTL(KC_PPLS), LCTL(KC_PMNS))  },
    [_NAV] =  { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),   ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [_ADJUST] = { ENCODER_CCW_CW(KC_MS_WH_RIGHT, KC_MS_WH_LEFT), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
    [_NUM] =   { ENCODER_CCW_CW(KC_MS_WH_RIGHT, KC_MS_WH_LEFT), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
};
#endif

#ifdef OLED_ENABLE

// #define FRAME_DURATION 100

// uint32_t timer = 0;
// uint8_t current_frame = 0;

/* old qmk logo image
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
*/

static void render_logo(void) {
    static const char qmk_logo [] PROGMEM = {
        // 'keyboardImage', 32x128px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0f, 0x1f, 0x3e, 0x7c, 0xf8, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x3c, 0x1e, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x30, 
        0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0xf0, 
        0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0x00, 
        0x00, 0x01, 0x03, 0x87, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xcf, 0x87, 0x03, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
        0x00, 0x06, 0x0f, 0x1f, 0x1f, 0x0f, 0x07, 0x07, 0x03, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x1f, 0x3f, 
        0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf8, 0xe0, 0xe0, 0xf8, 0xe0, 0xe0, 0xf8, 0xe0, 
        0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf8, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x09, 0x09, 0x69, 0xff, 0xff, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 
        0xc4, 0x03, 0x00, 0x40, 0x40, 0x00, 0x00, 0x00, 0xff, 0xff, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x49, 0x49, 0x4b, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x99, 
        0x80, 0x90, 0x80, 0x81, 0x89, 0x80, 0x80, 0x80, 0xff, 0xff, 0x49, 0x49, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0f, 0x01, 0x01, 0x0f, 0x01, 0x01, 0x0f, 0x01, 
        0x03, 0x03, 0x01, 0x03, 0x03, 0x01, 0x0f, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(qmk_logo, sizeof(qmk_logo));

}

// static void render_animation(void) {
//     // 'frame_0_delay-0', 32x128px
//     static const char epd_bitmap_frame_0_delay_0 [] PROGMEM = {
//         0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x09, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 
//         0x00, 0x00, 0x04, 0x80, 0x18, 0x00, 0x20, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 
//         0x00, 0x85, 0x00, 0x06, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x40, 0x00, 0x01, 0x10, 0x02, 0x01, 0x80, 0x00, 0x00, 0x0e, 0x00, 0x30, 0x08, 0x30, 0x00, 
//         0x02, 0x00, 0x00, 0x00, 0x20, 0x00, 0x80, 0x6d, 0x04, 0x00, 0x80, 0x80, 0x00, 0x02, 0x06, 0x00, 
//         0x40, 0x42, 0x00, 0x00, 0x80, 0x80, 0x20, 0x0a, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x80, 0x00, 
//         0x00, 0x21, 0x00, 0x00, 0x00, 0x02, 0x08, 0x00, 0x92, 0x00, 0x20, 0x50, 0x00, 0x04, 0x43, 0x00, 
//         0x02, 0x00, 0x84, 0x00, 0x04, 0x88, 0x00, 0x08, 0x00, 0x01, 0x10, 0x60, 0x04, 0x90, 0x00, 0x80, 
//         0x01, 0x20, 0x00, 0x00, 0x00, 0x10, 0x8c, 0x0f, 0x05, 0x24, 0x08, 0x60, 0x00, 0x01, 0x02, 0x80, 
//         0x84, 0x20, 0x26, 0x00, 0x15, 0x0b, 0x04, 0x35, 0x00, 0x20, 0x01, 0x80, 0x00, 0x5a, 0x11, 0x00, 
//         0x14, 0x00, 0x80, 0x27, 0x50, 0xaa, 0x20, 0xc0, 0x00, 0x41, 0x19, 0x00, 0xaa, 0x00, 0x42, 0x3c, 
//         0x20, 0xb5, 0x74, 0x93, 0x10, 0x02, 0x09, 0x00, 0x0c, 0x2c, 0x00, 0x1c, 0x89, 0x26, 0xa0, 0xc3, 
//         0x02, 0x89, 0x6b, 0x00, 0x01, 0x1e, 0x0c, 0x78, 0x08, 0x6a, 0xe9, 0x06, 0x04, 0x89, 0x62, 0xf0, 
//         0x8a, 0x1f, 0xdf, 0x98, 0x0b, 0x10, 0x6c, 0x04, 0x32, 0x47, 0xbf, 0xf2, 0x24, 0xcf, 0xfd, 0x89, 
//         0x94, 0xf1, 0xff, 0x64, 0x38, 0xb7, 0xff, 0xb4, 0x30, 0xb7, 0xfe, 0xd1, 0xc5, 0x3f, 0xff, 0x05, 
//         0x60, 0x3f, 0xfe, 0xad, 0x09, 0x7f, 0xfd, 0xa8, 0x6f, 0xff, 0xff, 0xc0, 0x70, 0xff, 0xff, 0x49, 
//         0x69, 0xff, 0xff, 0x6e, 0x56, 0x5f, 0xf8, 0x80, 0x85, 0x6f, 0xfa, 0x5a, 0x2a, 0xad, 0xe6, 0x1a, 
//         0x1a, 0xa0, 0xf7, 0x59, 0x28, 0xa6, 0xe0, 0x26, 0x0a, 0xee, 0xd0, 0x82, 0x72, 0x5f, 0x5e, 0x66, 
//         0x28, 0x3c, 0xc4, 0x64, 0x50, 0xc0, 0xbd, 0x02, 0x20, 0x40, 0xb0, 0x02, 0x55, 0x2a, 0xa2, 0x00, 
//         0x00, 0x88, 0x10, 0x0a, 0x2a, 0x8a, 0x84, 0x40, 0x58, 0x19, 0xe0, 0x04, 0x95, 0x6b, 0x01, 0x10, 
//         0x04, 0x48, 0x04, 0x00, 0x09, 0x10, 0x00, 0x00, 0x08, 0x08, 0x4a, 0x00, 0x10, 0x00, 0x04, 0x01, 
//         0x80, 0x04, 0x00, 0x10, 0x12, 0x00, 0x09, 0x40, 0x81, 0x00, 0x20, 0x01, 0x00, 0x00, 0x08, 0x80, 
//         0x00, 0x04, 0x04, 0x08, 0x84, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x80, 0x10, 0x00, 0x00, 0x00, 
//         0x20, 0x20, 0x10, 0x00, 0x10, 0x02, 0x04, 0x54, 0x21, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 
//         0x44, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x08, 0x00, 0x40, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x40, 
//         0x00, 0x00, 0x81, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x40, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 
//         0x80, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x04, 0x00, 0x00, 0x50, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00
//     };
//     // 'frame_1_delay-0', 32x128px
//     static const char epd_bitmap_frame_1_delay_0 [] PROGMEM = {
//         0x04, 0x00, 0x80, 0x00, 0x00, 0x04, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 
//         0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 
//         0x00, 0x00, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x41, 0x82, 0x00, 0x06, 0x00, 0x04, 0x08, 0x00, 0x84, 0x10, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x38, 0x00, 
//         0x00, 0x08, 0x20, 0x00, 0x00, 0x00, 0x00, 0x52, 0x44, 0x30, 0x80, 0xc0, 0x00, 0x00, 0x00, 0x00, 
//         0x04, 0x00, 0x10, 0x00, 0x00, 0x04, 0x20, 0x0a, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x82, 0x00, 
//         0x10, 0x10, 0x00, 0x00, 0x01, 0x02, 0x08, 0x00, 0x82, 0x20, 0x00, 0x50, 0x00, 0x0c, 0x03, 0x00, 
//         0x00, 0x40, 0x04, 0x00, 0x24, 0x80, 0x08, 0x0a, 0x00, 0x01, 0x30, 0x20, 0x00, 0x80, 0x20, 0x80, 
//         0x24, 0x02, 0x04, 0x00, 0x00, 0x00, 0xcc, 0x1f, 0x00, 0x24, 0x08, 0x40, 0x80, 0x81, 0x03, 0x00, 
//         0x05, 0x20, 0x26, 0x00, 0x04, 0x03, 0x00, 0x7f, 0x80, 0x28, 0x89, 0xe0, 0xc0, 0x1a, 0x03, 0x00, 
//         0x15, 0x04, 0x84, 0x3c, 0x50, 0x38, 0x24, 0xc0, 0x80, 0x41, 0x09, 0x80, 0x22, 0x08, 0x42, 0x2c, 
//         0x00, 0x24, 0x44, 0x83, 0x54, 0x82, 0xab, 0x80, 0x04, 0x2c, 0x08, 0x18, 0x08, 0x46, 0xf5, 0xf3, 
//         0x12, 0xc1, 0x58, 0x00, 0x05, 0x1e, 0x8c, 0xf8, 0x28, 0x63, 0xa0, 0x06, 0x40, 0xc8, 0xf2, 0x61, 
//         0x89, 0x0f, 0x5f, 0x58, 0x13, 0x31, 0x7c, 0xc6, 0x90, 0xc7, 0xbf, 0xf2, 0x20, 0x8f, 0xfd, 0x8b, 
//         0x94, 0xd9, 0xff, 0xec, 0x94, 0xb7, 0xff, 0x95, 0x06, 0xa7, 0xfe, 0x55, 0x87, 0xff, 0xff, 0x7a, 
//         0x50, 0xb7, 0xfe, 0xa9, 0x0a, 0xff, 0xfd, 0xa8, 0x2b, 0xdf, 0xfd, 0xae, 0x96, 0xff, 0xfd, 0x28, 
//         0x23, 0xff, 0xff, 0xfb, 0x52, 0x7f, 0xff, 0xc4, 0x95, 0xef, 0xfe, 0xd0, 0xa2, 0xad, 0xfe, 0x10, 
//         0x12, 0x2d, 0xb6, 0x72, 0x0a, 0xaf, 0x3c, 0x02, 0x5a, 0x5c, 0x46, 0x54, 0x62, 0xc7, 0x53, 0xc0, 
//         0x29, 0x36, 0x0e, 0x60, 0x46, 0x11, 0xa9, 0x00, 0x2a, 0x52, 0xb0, 0x96, 0x15, 0x22, 0x80, 0x02, 
//         0xa0, 0x2a, 0x11, 0x4a, 0x0a, 0x8a, 0x84, 0xc9, 0x00, 0x20, 0x22, 0x04, 0x84, 0x22, 0x02, 0x00, 
//         0xa4, 0x00, 0x84, 0x40, 0x09, 0x00, 0x23, 0x08, 0x48, 0x01, 0xb0, 0x04, 0x10, 0x62, 0x00, 0x04, 
//         0x09, 0x00, 0x80, 0x10, 0x02, 0x03, 0x28, 0x40, 0x25, 0x24, 0x80, 0x00, 0x00, 0x0a, 0x00, 0x80, 
//         0x00, 0x00, 0x00, 0x20, 0x80, 0x00, 0x00, 0x00, 0x02, 0x20, 0x48, 0x00, 0x11, 0x00, 0x00, 0x00, 
//         0x20, 0x00, 0x10, 0x81, 0x02, 0x02, 0xa0, 0x14, 0x45, 0x10, 0x40, 0x08, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x04, 0x01, 0x01, 0x00, 0x00, 0x8a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x22, 0x00, 0x00, 0x40, 0x00, 0x00, 0x48, 
//         0x04, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x80, 
//         0x04, 0xa0, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 
//         0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x04, 0x08, 0x12, 0x51, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 
//         0x00, 0x40, 0x20, 0x00, 0x08, 0x09, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02
//     };
//     // 'frame_2_delay-0', 32x128px
//     static const char epd_bitmap_frame_2_delay_0 [] PROGMEM = {
//         0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x10, 0x00, 0x01, 0x01, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x02, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x10, 
//         0x00, 0x00, 0x02, 0x00, 0x18, 0x00, 0x38, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x42, 0x84, 0x00, 0x4e, 0x00, 0x08, 0x00, 0x00, 0x80, 0x00, 0x10, 0x00, 0x08, 0x00, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x10, 0x43, 0x01, 0xc6, 0x00, 0x02, 0x0a, 0x00, 0x10, 0x08, 0x38, 0x00, 
//         0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 0x44, 0x21, 0x80, 0xa0, 0x00, 0x42, 0x02, 0x00, 
//         0x04, 0x42, 0x10, 0x00, 0x88, 0x80, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x40, 0x00, 0x01, 0x83, 0x00, 
//         0x00, 0x20, 0x00, 0x00, 0x00, 0x02, 0x08, 0x00, 0x90, 0x20, 0x00, 0x51, 0x00, 0x04, 0x01, 0x00, 
//         0x02, 0x00, 0x06, 0x00, 0x04, 0x88, 0x08, 0x02, 0x00, 0x01, 0x00, 0x00, 0x24, 0x90, 0x00, 0x80, 
//         0x21, 0x02, 0x07, 0x00, 0x00, 0x80, 0x40, 0x08, 0x04, 0x20, 0x00, 0x60, 0x00, 0x00, 0x01, 0x80, 
//         0x81, 0x20, 0x72, 0x00, 0x00, 0x08, 0x00, 0x3f, 0xc0, 0x20, 0x88, 0x80, 0x01, 0x0a, 0x18, 0x00, 
//         0x10, 0x00, 0x80, 0x2c, 0x40, 0x08, 0x64, 0x40, 0x00, 0xd0, 0x19, 0x80, 0xa2, 0x08, 0x02, 0x38, 
//         0x20, 0xb5, 0x2c, 0xc3, 0x10, 0x82, 0x21, 0x00, 0x88, 0x2c, 0x08, 0x3c, 0x09, 0x66, 0x20, 0xe3, 
//         0x12, 0x01, 0x6b, 0x00, 0x01, 0x2c, 0x6c, 0xfc, 0x28, 0x68, 0x65, 0x06, 0x40, 0xc0, 0x33, 0x61, 
//         0x0b, 0x0f, 0xcb, 0xc8, 0x10, 0x70, 0x4e, 0xc4, 0x92, 0xc7, 0xef, 0x72, 0x20, 0xcf, 0xff, 0x8b, 
//         0x95, 0xf9, 0xfe, 0xe5, 0xbc, 0xb7, 0xff, 0x84, 0x04, 0xb7, 0xfe, 0xd4, 0x01, 0xbf, 0xff, 0x71, 
//         0x28, 0xbf, 0xfe, 0xae, 0x8b, 0xff, 0xff, 0xa9, 0x2b, 0xff, 0xff, 0x0f, 0x5e, 0xef, 0xff, 0x00, 
//         0x20, 0xbf, 0xff, 0x70, 0x46, 0xdf, 0xff, 0xa0, 0x84, 0x2f, 0xff, 0x00, 0xaa, 0xaf, 0xfe, 0x82, 
//         0x2a, 0xa8, 0xa6, 0x6a, 0x4a, 0xef, 0xf9, 0x12, 0xda, 0x20, 0xc2, 0xd6, 0x58, 0x47, 0x7e, 0x78, 
//         0x21, 0x16, 0x48, 0xc1, 0x44, 0x12, 0x8d, 0x00, 0xa9, 0x52, 0x88, 0x0c, 0x01, 0x22, 0x03, 0x00, 
//         0xa4, 0x2a, 0x48, 0x00, 0x2a, 0x82, 0x00, 0x40, 0x11, 0x0a, 0xc0, 0x04, 0x04, 0x21, 0x40, 0xa4, 
//         0x08, 0x40, 0x00, 0x58, 0x29, 0x41, 0x20, 0x00, 0x00, 0x0c, 0x82, 0x04, 0x52, 0x80, 0x00, 0x05, 
//         0x89, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x11, 0x00, 0x80, 0x00, 0x84, 0x00, 0x0a, 0x84, 
//         0x00, 0x00, 0xa0, 0x22, 0x00, 0x40, 0x00, 0x80, 0x00, 0x00, 0x0a, 0x81, 0x00, 0x00, 0x01, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x10, 0x00, 0x20, 0x00, 0x00, 0x8a, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x40, 0x00, 0x00, 0x04, 
//         0x00, 0x00, 0x08, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 
//         0x00, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
//         0x00, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x20, 
//         0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 
//         0x00, 0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//     };

//     // Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1584)
//     const int epd_bitmap_allArray_LEN = 3;
//     const char* epd_bitmap_allArray[3] = {
//         epd_bitmap_frame_0_delay_0,
//         epd_bitmap_frame_1_delay_0,
//         epd_bitmap_frame_2_delay_0
//     };

//     uint16_t frame_sizes[3] = {
//         sizeof(epd_bitmap_frame_0_delay_0),
//         sizeof(epd_bitmap_frame_1_delay_0),
//         sizeof(epd_bitmap_frame_2_delay_0),
//     };

//     if (timer_elapsed(timer) > FRAME_DURATION) {
//         timer = timer_read();

//         current_frame = (current_frame + 1) % (epd_bitmap_allArray_LEN / sizeof(epd_bitmap_allArray[0]));

//         oled_write_raw_P(epd_bitmap_allArray[current_frame], frame_sizes[current_frame]);
//     };
// };

// void write_int_ln(const char* prefix, uint8_t value) {
//     oled_write_P(prefix, false);
//     oled_write(get_u8_str(value, ' '), false);
// }

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR("SofleChoc _____"), false);

    // if (get_highest_layer(layer_state) == _ADJUST) {
    //     uint8_t mode  = rgb_matrix_get_mode();
    //     HSV     hsv   = rgb_matrix_get_hsv();
    //     uint8_t speed = rgb_matrix_get_speed();

    //     if (keymap_config.swap_lctl_lgui) {
    //         oled_write_ln_P(PSTR("MAC\n"), false);
    //     } else {
    //         oled_write_ln_P(PSTR("WIN\n"), false);
    //     }

    //     oled_write_ln("RGB", false);
    //     write_int_ln(PSTR("Mo"), mode);
    //     write_int_ln(PSTR("H "), hsv.h);
    //     write_int_ln(PSTR("S "), hsv.s);
    //     write_int_ln(PSTR("V "), hsv.v);
    //     write_int_ln(PSTR("Sp"), speed);
    //     oled_write_P(PSTR("\n\n\n"), false);
    // } else {
        //oled_write_P(PSTR("\n\n\n\n\n\n\n\n\n"), false);
    //}
    //oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
        oled_write_ln_P(PSTR(" CAP "), true);
    } else {
        oled_write_ln_P(PSTR("     "), false);
    }
    //oled_write_P(PSTR("\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);

    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _GAME:
            oled_write_ln_P(PSTR("Game "), false);
            break;
        case _QWERTY:
            oled_write_ln_P(PSTR("Alpha"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Nav  "), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Sym  "), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adj  "), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Num  "), false);
            break;
        // case _MOUSE:
        //     oled_write_P(PSTR("Rat  "), false);
        //     break;
        default:
            oled_write_P(PSTR("???  "), false);
    }
    oled_write_ln_P(PSTR("_____"), false);
    //oled_write_ln_P(PSTR("Layout"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrty"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;    
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
        // render_animation();
    }

    return false;
}

#endif
