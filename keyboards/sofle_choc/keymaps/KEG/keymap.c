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
    _GAMEH,
    _NAV,
    _SYM,
    _ADJUST,
    _NUM,
    _SDOKU,
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
  KC_LALT,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_EQL,
  KC_LCTL,  LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F), KC_G,            KC_H,RSFT_T(KC_J),RCTL_T(KC_K),RALT_T(KC_L),  LGUI_T(KC_SCLN),  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MPLY,     KC_MUTE, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                 KC_LGUI,KC_F4,KC_F5,KC_SPC, LT(_NAV,KC_BSPC),  LT(_SYM,KC_SPC), TT(_NUM), KC_DEL, KC_F12, KC_F11
),

[_COLEMAK] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_EQL,
  KC_LALT,  KC_A,LALT_T(KC_R),LCTL_T(KC_S),LSFT_T(KC_T),KC_D,             KC_H,RSFT_T(KC_N),RCTL_T(KC_E),RALT_T(KC_I),KC_O,  KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, _______,     _______,KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                 KC_LGUI,KC_F4,KC_F1, KC_SPC, LT(_NAV,KC_BSPC),      LT(_SYM,KC_SPC),  TT(_NUM), KC_DEL, KC_F12, KC_F11
),

// Game Layers
// Base Game Layout great for destiny
[_GAME] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,     KC_3,    KC_4,   KC_5,                          KC_6,        KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
    KC_TAB,  KC_Q,   KC_W,     KC_E,    KC_R,   KC_T,                          KC_Y,     KC_U, KC_I, KC_O,    KC_P,  KC_EQL,
    KC_LCTL, KC_A,   KC_S,     KC_D,    KC_F,   KC_G,                          KC_H,     KC_J, KC_K, KC_L, KC_SCLN,  KC_QUOT,
    KC_LSFT, KC_Z,   KC_X,     KC_C,    KC_V,   KC_B, _______,     _______,    KC_N,        KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                     KC_M,   KC_O, MO(_GAMEH), KC_LALT, KC_SPC,    KC_SPC, TG(_GAME), LALT(KC_F4),  KC_F12,  KC_F11
),

[_GAMEH] = LAYOUT(
  KC_ESC,   KC_F1,   KC_F2,     KC_F3,    KC_F4,   KC_F5,                          KC_F6,        KC_F7,    KC_F8,    KC_F9,    KC_0,  KC_MINS,
    KC_TAB,  KC_CTLTAB,   KC_UP,     KC_ALTAB,    KC_R,   KC_T,                          KC_Y,     KC_BTN5, KC_MS_U, KC_BTN4,    KC_P,  KC_EQL,
    KC_LCTL, KC_LEFT,   KC_DOWN, KC_RGHT,    KC_J,   KC_G,                          KC_H,     KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2,  KC_QUOT,
    KC_LSFT, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,     _______,    KC_N,        KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                     KC_M,   KC_O, _______, KC_LALT, KC_SPC,    TG(_GAME), KC_BTN1, LALT(KC_F4),  KC_F12,  KC_F11
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
  LCA(KC_DEL),         KC_F1,     KC_F2,    KC_F3,    KC_F4,   KC_F5,                                  KC_F6,         KC_F7,         KC_F8,         KC_F9,        KC_F10,  LALT(KC_F4),
  RCS(KC_ESC), LCTL(KC_LALT), KC_CTLTAB,    KC_UP, KC_ALTAB, KC_CAPS,                             LGUI(KC_I),      KC_PRVWD,   LGUI(KC_UP),      KC_NXTWD,   LCTL(KC_W),  KC_F12,
      KC_LALT,       KC_LSFT,   KC_LEFT,  KC_DOWN,  KC_RGHT, KC_HOME,                             KC_PAGE_UP, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RGHT),       KC_LSFT, _______,
      KC_LCTL,       KC_UNDO,    KC_CUT,  KC_COPY,  KC_PSTE,  KC_END, _______,         _______, KC_PAGE_DOWN,       KC_MPRV,       KC_MPLY,       KC_MNXT, LCTL(KC_SLSH), _______,
                            MO(_SYM),  KC_SLEP,  _______, LGUI(KC_L), _______,          KC_TAB,     KC_DLINE, LCTL(KC_LSFT),       KC_LSFT,       KC_LGUI
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
   KC_GRV,KC_EXLM,           KC_AT,         KC_HASH,          KC_DLR, KC_PERC,                          KC_CIRC,         KC_AMPR,         KC_ASTR,         _______, _______, _______,
  _______,KC_HASH,         KC_SLSH,         KC_LBRC,         KC_RBRC, KC_PLUS,                          KC_PIPE,           KC_LT,           KC_GT,         KC_BSLS, KC_QUOT, _______,
  _______,  LT(_QWERTY,KC_AT), LALT_T(KC_ASTR), LCTL_T(KC_LPRN), LSFT_T(KC_RPRN),  KC_EQL,                          KC_AMPR, RSFT_T(KC_SCLN), RCTL_T(KC_PDOT), RALT_T(KC_COMM), LT(_QWERTY,KC_DQUO), KC_TILD,
  _______, KC_DLR,         KC_PERC,         KC_LCBR,         KC_RCBR, KC_MINS,  _______,       _______, KC_QUES,         KC_COLN,         KC_EXLM,         KC_UNDS,  KC_GRV, _______,
                           KC_MUTE,         _______,         KC_BSPC,  KC_SPC, MO(_NAV),       _______, KC_LSFT,           KC_F6,           KC_F7,           KC_F8
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
    XXXXXXX, XXXXXXX, XXXXXXX, TG(_SDOKU), TG(_GAME), XXXXXXX,                     XXXXXXX,KC_COLEMAK,KC_QWERTY, XXXXXXX, XXXXXXX, XXXXXXX,
    CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),

[_NUM] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_BTN4, KC_MS_U, KC_BTN5, XXXXXXX,                       XXXXXXX, KC_P7, KC_P8, KC_P9, KC_PEQL, XXXXXXX,
    KC_ACL0, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                       KC_LPRN,KC_P4, KC_P5, KC_P6, KC_PPLS, KC_BSPC,
    KC_ACL1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_RPRN, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_PENT,
                      _______, _______, _______, KC_BTN2, KC_BTN1,     _______, _______, KC_PDOT, KC_P0, KC_PCMM
),

[_SDOKU] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_C,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LALT,    KC_4,    KC_5,    KC_6,    KC_Z,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_BSPC, KC_LCTL,    KC_7,    KC_8,    KC_9,    KC_V, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______,    KC_0, _______, KC_LALT, KC_LCTL,     TG(_SDOKU), _______, _______, _______, _______
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
    [_GAME] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
    [_GAMEH] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
    [_SYM] =  { ENCODER_CCW_CW(LCTL(KC_PPLS), LCTL(KC_PMNS)),   ENCODER_CCW_CW(LCTL(KC_PPLS), LCTL(KC_PMNS))  },
    [_NAV] =  { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),   ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [_ADJUST] = { ENCODER_CCW_CW(KC_MS_WH_RIGHT, KC_MS_WH_LEFT), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP) },
    [_NUM] =   { ENCODER_CCW_CW(KC_MS_WH_RIGHT, KC_MS_WH_LEFT), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
    [_SDOKU] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
};
#endif

#ifdef OLED_ENABLE

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
        case _GAMEH:
            oled_write_ln_P(PSTR("GHelp"), false);
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
        case _SDOKU:
            oled_write_ln_P(PSTR("SDoku"), false);
        break;
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
            }

    return false;
}

#endif
