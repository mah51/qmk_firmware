/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _COLEMAK_DH = 0,
    _QWERTY,
    _DVORAK,
    _RAISE,
    _LOWER,
    _FUNCTION,
    _ADJUST,
};

enum custom_keycodes {
   KC_LOWER,
   KC_RAISE,
   KC_MTPLY,
};


// Aliases for readability
#define COLEMAK  DF(_COLEMAK_DH)
#define QWERTY   DF(_QWERTY)

#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)
// #define LOWER    MO(_LOWER)
// #define RAISE    MO(_RAISE)

#define SCRNI  LSFT(LWIN(KC_S))
#define WINLT  LGUI(LSFT(KC_LEFT))
#define WINRT  LGUI(LSFT(KC_RIGHT))
#define NXTWD  LCTL(KC_RIGHT)
#define PRVWD  LCTL(KC_LEFT)
#define DLINE  LCTL(KC_BSPC)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | Play  | ENC |  |  ENC |RAISE |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ALT  | CTRL | SPC  | LWR  | ENT  |  |  SPC |  LWR | AltGr| FKEYS | WIN |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  , KC_Q,  KC_W,  KC_F   ,   KC_P ,   KC_B ,                                  KC_J    , KC_L    , KC_U , KC_Y   ,  KC_SCLN, KC_BSPC,
     KC_RAISE, KC_A,  KC_R,  KC_S   ,   KC_T ,   KC_G ,                                  KC_M    , KC_N    , KC_E , KC_I   ,  KC_O   , KC_QUOT,
     KC_LSFT , KC_Z,  KC_X,  KC_C   ,   KC_D ,   KC_V , KC_RAISE, KC_MTPLY,    XXXXXXX , KC_RAISE, KC_K    , KC_H , KC_COMM,  KC_DOT , KC_SLSH, KC_RSFT,
                             KC_LALT, KC_SPC,  KC_LCTL, KC_ENT  , KC_LOWER,    KC_LOWER, KC_SPC  , KC_RAISE, FKEYS, KC_RGUI
    ),
/*
 * Base Layer: QWERTYvvvdvvv
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Raise  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | '      |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ALT  | SPCE | CTRL | LWR  | ENT  |  | SPCE |  LWR | AltGr| RGUI | Menu |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R , KC_T   ,                                          KC_Y   , KC_U ,   KC_I ,   KC_O ,  KC_P , KC_BSPC,
     KC_RAISE, KC_A ,  KC_S   ,  KC_D  ,   KC_F , KC_G   ,                                          KC_H   , KC_J ,   KC_K ,   KC_L ,KC_SCLN, KC_QUOT,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V , KC_B   , KC_LBRC, KC_CAPS ,      FKEYS   , KC_RBRC, KC_N   , KC_M ,   KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                KC_LALT,  KC_SPC, KC_LCTL, KC_ENT , KC_LOWER,      KC_LOWER, KC_SPC , KC_RALT, KC_RGUI, KC_APP
    ),


/*
 * Raise Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      | HOME | END  |                              | PgUp | PRWD |   ↑  | NXWD | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | CAPS |      | SCRN | WNLT | WNRT |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
       KC_ESC, _______, _______, _______, KC_HOME, KC_END,                                      KC_PGUP, PRVWD  , KC_UP  ,   NXTWD,  DLINE , KC_DEL,
      _______, KC_CAPS, XXXXXXX, SCRNI  , WINLT  , WINRT ,                                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F13 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 ADJUST , _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Lower Layer: Numbers and symbol
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  $   |  +   |  (   |   )  |  @   |                              |   !  |  =   |  -   |  _   |  |   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |  |   *  |   #  |   {   |   }  |  ~   |      |      |  |      |      |   &  |  [   |   ]  |  %   |  /   |       |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT(
     KC_ESC , KC_1   , KC_2   ,   KC_3 , KC_4   , KC_5    ,                                     KC_6   , KC_7   , KC_8   , KC_9 ,   KC_0   , _______,
     _______, KC_DLR , KC_PLUS, KC_LPRN, KC_RPRN, KC_AT   ,                                     KC_EXLM, KC_EQL , KC_MINS, KC_UNDS, KC_PIPE, KC_GRV ,
     _______, KC_ASTR, KC_HASH, KC_LCBR, KC_RCBR, KC_TILDE, _______, _______, _______, _______, KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_BSLS, _______,
                                 _______, _______, _______ , _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, QWERTY , _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, COLEMAK, _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool shift_held = false;
bool ctrl_held = false;
bool fn_held = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LOWER:
            fn_held = record->event.pressed;
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case KC_RAISE:
            fn_held = record->event.pressed;
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case KC_RSFT:
        case KC_LSFT:
            shift_held = record->event.pressed;
            break;
        case KC_LCTL:
        case KC_RCTL:
            ctrl_held = record->event.pressed;
            ctrl_held = record->event.pressed;
            break;
        case KC_MTPLY:
          if (record->event.pressed) {
            if (fn_held) {
              tap_code(KC_MUTE);
            } else {
              tap_code(KC_MPLY);
            }
          }
          break;
    }  return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) {
		if (clockwise) {
            if (ctrl_held) {
                tap_code(KC_VOLD);
            } else if (fn_held) {
                tap_code(KC_MPRV);
            } else {
			    tap_code(KC_UP);
            }
		} else {
        if (ctrl_held) {
                tap_code(KC_VOLU);
        } else if (fn_held) {
                tap_code(KC_MNXT);
            } else {
			    tap_code(KC_DOWN);
            }
		}
	}
	else if (index == 1) {
 if (clockwise) {
			tap_code(KC_LEFT);
		} else {
			tap_code(KC_RIGHT);
		}
	}
    return false;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}




char wpm_str[10];
// WPM-responsive animation stuff here

bool wpm_keycode_user(uint16_t keycode) {
	return true;
}


bool oled_task_user(void) {
	if (is_keyboard_master()) {
        static const char PROGMEM spidey_1[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,240,156,  6,  2,243,225,193,193,  3,195,230,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192, 64, 39, 60,  0,  1,  1,  3,  3,  1,  1, 99,159,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,112,  8,124,244,  6,  2,  3,  1,  8, 24, 48, 96,192,128,  0,  0,  0,  0,  0,  0,  0,  7,  4,  8, 24, 16, 32,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 63,224,  0,  0,  1, 98,100, 76,200,152,144, 48, 32, 32, 96, 65, 67, 67,194,194,244,252,  4,  4,  4,  6,  2, 10, 10, 15, 12,  4,  4, 12,  4, 12,  8,  8, 12, 12,  4, 12,172,108,232,104, 56, 32, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,128,  0,  0,  0,  0,  0,192,255,  1,  3,  2,  2,  2,  6,  6,  6, 14,  6,  2,  2,  3,131,225,241, 15,  7,  6,  6, 14, 30, 18, 34, 66,194,131,130,  6,132,226, 99,224, 96, 96, 96, 64,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15,255,240,128,128,192,112, 63,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,252, 15,  3,  3,  3,  3, 14, 16, 96, 64, 64, 80, 32, 32, 48, 33, 33, 35, 33, 33, 40, 50, 52, 49, 24, 28, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224, 96,248,141,  7,  6,  8,  8, 24, 16, 16, 16, 16, 16, 48, 48, 48, 16, 16, 16, 24,127,225,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        };

		// render_anim();
		oled_set_cursor(0,1);
        oled_write_raw_P(spidey_1, sizeof(spidey_1));
        oled_set_cursor(0,0);
        uint8_t n = get_current_wpm();
        wpm_str[3] = '\0';
        wpm_str[2] = '0' + n % 10;
        wpm_str[1] = '0' + (n /= 10) % 10;
        wpm_str[0] = '0' + n / 10 ;
        oled_write_P(PSTR("WPM: "), false);
        oled_write(wpm_str, false);
        oled_write_P(PSTR("       "), false);
    		switch (get_highest_layer(layer_state)) {
            case _COLEMAK_DH:
                oled_write_ln_P(PSTR("COLMK"), false);
                break;
			case _QWERTY:
				oled_write_ln_P(PSTR("QWRTY"), false);
				break;
			case _LOWER:
				oled_write_ln_P(PSTR("LOWER"), false);
				break;
			case _RAISE:
				oled_write_ln_P(PSTR("RAISE"), false);
				break;
			case _ADJUST:
				oled_write_ln_P(PSTR("ADJST"), false);
				break;
            case _FUNCTION:
                oled_write_ln_P(PSTR("F-KEY"), false);
                break;
			default:
				oled_write_ln_P(PSTR("UNDEF"), false);
		}
        oled_set_cursor(0,7);
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.caps_lock ? PSTR("CPSLK") : PSTR("     "), false);
	} else {
		  static const char PROGMEM kyria_logo[] = {
                    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 96, 48, 24, 24, 12, 12, 12, 28, 12, 28, 56,240,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,127,255,124,126, 15,  1,  0,  0,  0,  0,  0,  0,  0,  1,255,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15, 24, 48, 96,192,128,  0,  0,  0,  0,  0,  0,  0,  1, 31, 48, 96,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,224, 56, 12,132,198, 99, 51, 17, 24,  8, 12, 12,204,196,228,116, 20, 20, 20, 52, 52,228,197, 13, 31,246,  6, 12, 24,240,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24,104,200,200,184,204, 68,196,140, 56, 56,240,240,224,192,128,128,128,128,128,128,128,128,128,128,192,192, 96, 32,184,220,102, 51, 25, 12, 14,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,240,221,199,193,  0,  0,  0,  0,  0,  0,  3, 14,252,225, 15,120,224,131,127,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 31, 53,123, 96, 66, 96, 96,111,106,197,192,200,136,136,136,248,124,204,132,134,  2,  3,  1,129,128,192, 96, 48, 16, 24, 12,  4,  6, 30,249,  0,  0,  0,  0,  0,  0,  0,  0, 15,  8, 12, 12, 12,  4,  4,  4, 12, 15,  7,  4,  0,  0,  3, 14, 63,254,240,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  3,  3,  3,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 31,120,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 32,252,140,188, 48,224, 64, 96, 63,  1,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, 14, 12, 12, 14, 10, 10, 11, 11, 11, 11, 11, 11, 15, 15, 15, 15, 15, 14,  4,  6,  6,  3,  3,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        };
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
	}
    return false;
}
#endif
