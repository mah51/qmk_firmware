#include QMK_KEYBOARD_H
#include "raw_hid.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK_DH,
    _NUMPAD,
    _EMOJITXT,
    _MACRO,
    _LOWER,
    _RAISE,
    _ADJUST,

};

enum custom_keycodes {
    KC_COLEMAK_DH = SAFE_RANGE,
    KC_QWERTY,
    KC_SWCH_LYT,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_BSPC_DEL,
    KC_WINLT,
    KC_WINRT,
    KC_LIGHTS,
    KC_MUTEPLAY,
    KC_XD,
    KC_E_0,
    KC_E_1,
    KC_E_2,
    KC_E_3,
    KC_E_4,
    KC_E_5,
    KC_E_6,
    KC_E_7,
    KC_E_8,
    KC_E_9,
    KC_E_STAR,
    KC_E_HASH,
};

enum unicode_names {
  GRIN, // grinning face 😊
  TJOY, // tears of joy 😂
  SMILE, // grining face with smiling eyes 😁
  HEART, // heart ❤
  EYERT, // smiling face with heart shaped eyes 😍
  CRY, // crying face 😭
  SMEYE, // smiling face with smiling eyes 😊
  UNAMU, // unamused 😒
  KISS, // kiss 😘
  HART2, // two hearts 💕
  WEARY, // weary 😩
  OKHND, // ok hand sign 👌
  PENSV, // pensive 😔
  SMIRK, // smirk 😏
  RECYC, // recycle ♻
  WINK, // wink 😉
  THMUP, // thumb up 👍
  THMDN, // thumb down 👎
  PRAY, // pray 🙏
  PHEW, // relieved 😌
  MUSIC, // musical notes
  FLUSH, // flushed 😳
  CELEB, // celebration 🙌
  CRY2, // crying face 😢
  COOL, // smile with sunglasses 😎
  NOEVS, // see no evil
  NOEVH, // hear no evil
  NOEVK, // speak no evil
  POO, // pile of poo
  EYES, // eyes
  VIC, // victory hand
  BHART, // broken heart
  SLEEP, // sleeping face
  SMIL2, // smiling face with open mouth & sweat
  HUNRD, // 100
  CONFU, // confused
  TONGU, // face with tongue & winking eye
  DISAP, // disappointed
  YUMMY, // face savoring delicious food
  CLAP, // hand clapping
  FEAR, // face screaming in fear
  HORNS, // smiling face with horns
  HALO, // smiling face with halo
  BYE, // waving hand
  SUN, // sun
  MOON, // moon
  SKULL, // skull
  YEHAW,

  EMOJI_A,
  EMOJI_B,
  EMOJI_C,
  EMOJI_D,
  EMOJI_E,
  EMOJI_F,
  EMOJI_G,
  EMOJI_H,
  EMOJI_I,
  EMOJI_J,
  EMOJI_K,
  EMOJI_L,
  EMOJI_M,
  EMOJI_N,
  EMOJI_O,
  EMOJI_P,
  EMOJI_Q,
  EMOJI_R,
  EMOJI_S,
  EMOJI_T,
  EMOJI_U,
  EMOJI_V,
  EMOJI_W,
  EMOJI_X,
  EMOJI_Y,
  EMOJI_Z,

  PND
};

const uint32_t PROGMEM unicode_map[] = {
  [GRIN] = 0x1F600,
  [TJOY] = 0x1F602,
  [SMILE] = 0x1F601,
  [HEART] = 0x2764,
  [EYERT] = 0x1f60d,
  [CRY] = 0x1f62d,
  [SMEYE] = 0x1F60A,
  [UNAMU] = 0x1F612,
  [KISS] = 0x1F618,
  [HART2] = 0x1F495,
  [WEARY] = 0x1F629,
  [OKHND] = 0x1F44C,
  [PENSV] = 0x1F614,
  [SMIRK] = 0x1F60F,
  [RECYC] = 0x267B,
  [WINK] = 0x1F609,
  [THMUP] = 0x1F44D,
  [THMDN] = 0x1F44E,
  [PRAY] = 0x1F64F,
  [PHEW] = 0x1F60C,
  [MUSIC] = 0x1F3B6,
  [FLUSH] = 0x1F633,
  [CELEB] = 0x1F64C,
  [CRY2] = 0x1F622,
  [COOL] = 0x1F60E,
  [NOEVS] = 0x1F648,
  [NOEVH] = 0x1F649,
  [NOEVK] = 0x1F64A,
  [POO] = 0x1F4A9,
  [EYES] = 0x1F440,
  [VIC] = 0x270C,
  [BHART] = 0x1F494,
  [SLEEP] = 0x1F634,
  [SMIL2] = 0x1F605,
  [HUNRD] = 0x1F4AF,
  [CONFU] = 0x1F615,
  [TONGU] = 0x1F61C,
  [DISAP] = 0x1F61E,
  [YUMMY] = 0x1F60B,
  [CLAP] = 0x1F44F,
  [FEAR] = 0x1F631,
  [HORNS] = 0x1F608,
  [HALO] = 0x1F607,
  [BYE] = 0x1F44B,
  [SUN] = 0x2600,
  [MOON] = 0x1F314,
  [SKULL] = 0x1F480,
  [YEHAW] = 0x1F920,

  [EMOJI_A] = 0x1F1E6,
  [EMOJI_B] = 0x1F1E7,
  [EMOJI_C] = 0x1F1E8,
  [EMOJI_D] = 0x1F1E9,
  [EMOJI_E] = 0x1F1EA,
  [EMOJI_F] = 0x1F1EB,
  [EMOJI_G] = 0x1F1EC,
  [EMOJI_H] = 0x1F1ED,
  [EMOJI_I] = 0x1F1EE,
  [EMOJI_J] = 0x1F1EF,
  [EMOJI_K] = 0x1F1F0,
  [EMOJI_L] = 0x1F1F1,
  [EMOJI_M] = 0x1F1F2,
  [EMOJI_N] = 0x1F1F3,
  [EMOJI_O] = 0x1F1F4,
  [EMOJI_P] = 0x1F1F5,
  [EMOJI_Q] = 0x1F1F6,
  [EMOJI_R] = 0x1F1F7,
  [EMOJI_S] = 0x1F1F8,
  [EMOJI_T] = 0x1F1F9,
  [EMOJI_U] = 0x1F1FA,
  [EMOJI_V] = 0x1F1FB,
  [EMOJI_W] = 0x1F1FC,
  [EMOJI_X] = 0x1F1FD,
  [EMOJI_Y] = 0x1F1FE,
  [EMOJI_Z] = 0x1F1FF,

  [PND] = 0x00A3,

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * COLEMAK_DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RAISE|   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK_DH] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,     KC_5,                                    KC_6,       KC_7,    KC_8,    KC_9,   KC_0,  KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,     KC_B,                                    KC_J,       KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_BSPC,
  KC_RAISE, KC_A,   KC_R,    KC_S,    KC_T,     KC_G,                                    KC_M,       KC_N,    KC_E,    KC_I,   KC_O,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,     KC_V,   KC_MPLY,     KC_MPLY,   KC_K,       KC_H,       KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                    KC_LALT, KC_SPC,  KC_LCTL,  KC_ENT, KC_LOWER,    KC_LOWER,   KC_SPC,     KC_RCTL, KC_RALT, KC_RGUI
),

/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   `  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  BS  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LAYER |   A  |   S  |   D  |   F  |   G  |-------.    ,------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|mute/pla|   | Lights|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  \   |
 * `-----------------------------------------/       /    \      \-----------------------------------------'
 *            | LAlt | CTRL  | SPC  | LOWER | Enter/     \Space \ |RAISE|CTRL| ALT  |  WIN   |
 *            |      |       |      |      |/      /      \      \|     |    |      |        |
 *            `----------------------------------'        '------''--------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC  , KC_1, KC_2   , KC_3  , KC_4   , KC_5  ,                          KC_6  , KC_7   , KC_8    , KC_9  , KC_0   , KC_GRV,
  KC_TAB  , KC_Q, KC_W   , KC_E  , KC_R   , KC_T  ,                          KC_Y  , KC_U   , KC_I    , KC_O  , KC_P   , KC_BSPC,
  KC_RAISE, KC_A, KC_S   , KC_D  , KC_F   , KC_G  ,                          KC_H  , KC_J   , KC_K    , KC_L  , KC_SCLN, KC_QUOT,
  KC_LSFT , KC_Z, KC_X   , KC_C  , KC_V   , KC_B  , KC_MUTEPLAY,  KC_LIGHTS, KC_N  , KC_M   , KC_COMM , KC_DOT, KC_SLSH, KC_RSFT,
                  KC_LALT, KC_SPC, KC_LCTL, KC_ENT, KC_LOWER   ,  KC_LOWER , KC_SPC, KC_RCTL, KC_RAISE, KC_RGUI
),
    /* EMOJI TEXT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  1️⃣  |  2️⃣  |  3️⃣  |  4️⃣  |  5️⃣ |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  🇶  |  🇼  |    |    |    |                    |      |    |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |    |    |    |    |    |-------.    ,-------|     |      |      |      |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |    |   |    |    |    |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

  [_EMOJITXT] = LAYOUT(
  _______,  KC_E_1,     KC_E_2,     KC_E_3,                 KC_E_4,      KC_E_5,                         KC_E_6,       KC_E_7,       KC_E_8,        KC_E_9,      KC_E_0,     XXXXXXX,
  _______,  X(EMOJI_Q), X(EMOJI_W), X(EMOJI_F),             X(EMOJI_P),  X(EMOJI_B),                     X(EMOJI_J),   X(EMOJI_L),   X(EMOJI_U),    X(EMOJI_Y),  XXXXXXX,    _______,
  _______,  X(EMOJI_A), X(EMOJI_R), X(EMOJI_S),             X(EMOJI_T),  X(EMOJI_G),                     X(EMOJI_M),   X(EMOJI_N),   X(EMOJI_E),    X(EMOJI_I),  X(EMOJI_O), XXXXXXX,
  _______,  X(EMOJI_Z), X(EMOJI_X), X(EMOJI_C),             X(EMOJI_D),  X(EMOJI_V),  XXXXXXX,  XXXXXXX, X(EMOJI_K),   X(EMOJI_H),   XXXXXXX,       XXXXXXX,     XXXXXXX,    _______,
                      _______,   _______,  _______,  _______,  _______,     _______, _______, _______, _______, _______
  ),
    /* MACRO
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  👏  |  👋  |  💩  |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  ❤  |  😍  |  😂  |  😏  |  😉  |                    |      |  XD  |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  🤠  |  😎  |  😳  |  😭  |  😊  |-------.    ,-------|     |      |      |      |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |  💀  |  😈 |  😇  |  😞  |  😋  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

 [_MACRO] = LAYOUT(
  _______,  X(CLAP),    X(BYE),     X(POO),     X(EYES),    XXXXXXX,                        XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,  X(HEART),   X(EYERT),   X(TJOY),    X(SMIRK),   X(WINK),                        XXXXXXX,    KC_XD,      XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______,  X(YEHAW),   X(COOL),    X(FLUSH),   X(CRY),     X(SMEYE),                       XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,  X(SKULL),   X(HORNS),   X(HALO),    X(DISAP),   X(YUMMY), XXXXXXX,    XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______,   _______,  _______,  _______,  _______,     _______, _______, _______, _______, _______
  ),
/* LOWER
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+-------|
 * | TAB  |   0  |   1  |   2  |  3   |  4   |                    |   5  |   6  |   7  |  8   |   9  |  DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RAISE|  $   |   +  |   (  |   )  |   @  |--------.   .-------|   |  |   =  |   -  |   _  |   *  |  £   |
 * |------+------+------+------+------+------|mute/pl |   |LIGHTS |------+------+------+------+------+------|
 * |Shift |   !  |  #   |  {   |  }  |   ~  |------- |   |-------|   &   |   [  |   ]  |   %  |   \  |     |
 * `-----------------------------------------/      /    \      \-----------------------------------------'
 *            | LAlt  | SPC  | CTRL | LOWER |Enter /     \Space \  | RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/      /      \      \ |       |      |      |      |
 *            `----------------------------------'       '------''----------------------------'
 */

[_LOWER] = LAYOUT(
KC_F12,  KC_F1,     KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,
_______, KC_1,      KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,      KC_8,      KC_9,      KC_0,      KC_DEL,
_______, KC_DLR,    KC_PLUS,    KC_LPRN,    KC_RPRN,    KC_AT,                              KC_EXLM,    KC_EQL,    KC_MINS,   KC_UNDS,   KC_PIPE,   KC_GRV,
_______, KC_ASTR,   KC_HASH,    KC_LCBR,    KC_RCBR,    KC_TILDE,  _______,     _______,    KC_AMPR,    KC_LBRC,   KC_RBRC,   KC_PERC,   KC_BSLS,   X(PND),
                    _______,    _______,    _______,    _______,   _______,     _______,    _______,  _______,  _______,  _______
),
/* RAISE
 * ,----------------------------------------.                          ,-----------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |                        |  F6  |  F7 |  F8  |  F9  |  F10  | F11  |
 * |------+------+------+------+------+------|                       |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu | HOME |  END |                      | PGUP | PWrd |  Up  | NWrd | DLine| DEL |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * |Raise | WINLT|  XXX | WINRT| XXX  | Caps |-------.    ,-------| PGDN | Left | Down | Right|   |  |
 * |------+------+------+------+------+------|  MUTE |   | LIGHTS|------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste| XXX  |-------|  |-------|  F13 | F14  |  F15 |  XXX |  /   | Shift|
 * `-----------------------------------------/      /   \      \-----------------------------------------'
 *            | LAlt  | LCTRL| SPC  | LOWER | Enter/    \ Space\  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/      /     \      \ |      |      |      |      |
 *            `----------------------------------'      '------''---------------------------'
 */

[_RAISE] = LAYOUT(
  KC_F12,   KC_F1 ,   KC_F2 ,   KC_F3 ,   KC_F4 ,   KC_F5,                            KC_F6,      KC_F7  ,    KC_F8,    KC_F9 ,     KC_F10 ,  KC_F11,
  _______,  KC_INS,   KC_PSCR,  KC_APP,   KC_HOME, KC_END,                            KC_PGUP,    KC_PRVWD,   KC_UP,    KC_NXTWD,   KC_DLINE, KC_DEL,
  _______,  KC_CAPS,  XXXXXXX,  LSFT(LWIN(KC_S)), KC_WINLT,  KC_WINRT,                KC_PGDN,   KC_LEFT,    KC_DOWN,  KC_RGHT,    XXXXXXX,   XXXXXXX,
  _______,  KC_ADJUST,  KC_CUT,   KC_COPY,  KC_PASTE, XXXXXXX, _______,      _______,KC_F13,   OSL(_MACRO),TG(_EMOJITXT),   XXXXXXX,    _______,  _______,
                      _______,  _______,  _______,  _______, _______,       _______,  _______,    _______,    _______,  _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

  [_ADJUST] = LAYOUT(
  XXXXXXX,  XXXXXXX,  XXXXXXX ,   XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX,  KC_QWERTY,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX,  CG_TOGG,    XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______,    _______,  _______,  _______,  _______,     _______, _______, _______, _______, _______
  ),
  /* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | N LOCK| /   |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

  [_NUMPAD] = LAYOUT(
  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                         KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  KC_WSCH,  XXXXXXX,                        KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, XXXXXXX, KC_BSPC,
  _______,  XXXXXXX,  XXXXXXX,    XXXXXXX,  KC_CALC,  XXXXXXX,                        KC_KP_4, KC_KP_5, KC_KP_6, KC_EQL,  XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  KC_MYCM,  TG(_NUMPAD),  XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, XXXXXXX, XXXXXXX,
                      _______,    _______,  _______,  _______,  _______,     _______, _______, KC_KP_0, KC_KP_DOT, KC_BSPC
  ),
};

#ifdef OLED_DRIVER_ENABLE
/* Smart Backspace Delete */

bool shift_held = false;
static uint16_t held_shift = 0;
bool ctrl_held = false;
static uint16_t held_ctrl = 0;
bool fn_held = false;
const char* spam_macro = false;

/* KEYBOARD PET START */

/* settings */
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 40

/* advanced settings */
#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
#define ANIM_SIZE 96 // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping = false;
bool showedJump = true;
/* 32 * 32 logo */
static void render_logo(void) {
    static const char PROGMEM hell_logo[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x08, 0x08, 0x08, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xf8, 0x1c, 0x04, 0x24, 0x24, 0xec,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x02, 0x02, 0x03,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0x3e, 0xf8, 0xc0, 0xf0,
0x1e, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00,
0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x3e, 0x23, 0x27, 0x7e, 0xf0,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

    oled_write_raw_P(hell_logo, sizeof(hell_logo));
}

/* 32 * 14 os logos */
static const char PROGMEM windows_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00,
    0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00,
    0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM mac_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8,
    0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f,
    0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};



/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {

    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {
        /* 'sit1', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
            0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
            0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'sit2', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
            0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
            0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {
        /* 'walk1', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80,
            0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03,
            0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'walk2', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
            0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e,
            0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {
        /* 'run1', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
            0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01,
            0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'run2', 32x22px */
        {
            0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
            0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37,
            0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {
        /* 'bark1', 32x22px */
        {
            0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
            0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
            0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'bark2', 32x22px */
        {
            0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
            0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
            0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {
        /* 'sneak1', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04,
            0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06,
            0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'sneak2', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04,
            0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04,
            0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* animation */
    void animate_luna(void) {

        /* jump */
        if (isJumping || !showedJump) {

            /* clear */
            oled_set_cursor(LUNA_X,LUNA_Y +2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X,LUNA_Y -1);

            showedJump = true;
        } else {

            /* clear */
            oled_set_cursor(LUNA_X,LUNA_Y -1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X,LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if(led_usb_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if(isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if(current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if(current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION && timer_elapsed32(anim_sleep) < 30000 ) {
        anim_timer = timer_read32();
        animate_luna();
    }

    //this fixes the screen on and off bug
    if (current_wpm > 0) {
        oled_on();
        anim_sleep = timer_read32();
    } else if(timer_elapsed32(anim_sleep) > 30000) {
        oled_off();
    }

}

/* KEYBOARD PET END */

static void print_logo_narrow(void) {
    render_logo();

    /* wpm counter */
    uint8_t n = get_current_wpm();
    char wpm_str[4];
    oled_set_cursor(0,14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + ( n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0,15);
    oled_write(" wpm", false);
}

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0,0);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_raw_P(mac_logo, sizeof(mac_logo));
    } else {
        oled_write_raw_P(windows_logo, sizeof(windows_logo));
    }

    oled_set_cursor(0,3);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write("QWRTY", false);
            break;
        case _COLEMAK_DH:
            oled_write("COLMK", false);
            break;
        case _NUMPAD:
            oled_write("NUMPD  ", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

    oled_set_cursor(0,5);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0,6);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write("Base ", false);
            break;
        case _COLEMAK_DH:
            oled_write("Base", false);
            break;
        case _RAISE:
            oled_write("Raise", false);
            break;
        case _LOWER:
            oled_write("Lower", false);
            break;
        case _MACRO:
            oled_write("Macro", false);
            break;
        case _EMOJITXT:
            oled_write("Emoji", false);
            break;
        case _ADJUST:
            oled_write("Adj  ", false);
            break;
        case _NUMPAD:
            oled_write("Num  ", false);
            break;
        default:
            oled_write("Undef", false);
    }

    /* caps lock */
    oled_set_cursor(0,8);
    oled_write("CPSLK", led_usb_state.caps_lock);

    /* KEYBOARD PET RENDER START */

    render_luna(0,13);

    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {

    /* KEYBOARD PET VARIABLES START */

    current_wpm = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

#endif

void matrix_scan_user(void) {
    if (spam_macro != false) {
        send_string(spam_macro);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK_DH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_DH);
            }
            return false;
        case KC_SWCH_LYT:
            if (record->event.pressed) {
                if (get_highest_layer(default_layer_state) == _QWERTY) {
                    set_single_persistent_default_layer(_COLEMAK_DH);

                } else if(get_highest_layer(default_layer_state) == _COLEMAK_DH) {
                    set_single_persistent_default_layer(_QWERTY);

                }
            }
            return false;
        case KC_XD:
            if (record->event.pressed) {
                spam_macro = "xd" SS_TAP(X_ENT);
            } else {
                spam_macro = false;
            }
            return false;
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
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
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
            break;
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
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     /* CMD-arrow on Mac, but we have CTL and GUI swapped */
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
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    /* CMD-arrow on Mac, but we have CTL and GUI swapped */
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
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;

        /* Smart Backspace Delete */

        case KC_RSFT:
        // case KC_RSPC:
        case KC_LSFT:
        // case KC_LSPO:
            shift_held = record->event.pressed;
            held_shift = keycode;
            break;
        case KC_BSPC_DEL:
            if (record->event.pressed) {
                if (shift_held) {
                    unregister_code(held_shift);
                    register_code(KC_DEL);
                } else {
                    register_code(KC_BSPC);
                }
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
                if (shift_held) {
                    register_code(held_shift);
                }
            }
            return false;

        /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
            ctrl_held = record->event.pressed;
            held_ctrl = keycode;
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
        case KC_LIGHTS:
          if (record->event.pressed) {
             uint8_t send_data[32] = {0};
                send_data[0] = 10;
                raw_hid_send(send_data, sizeof(send_data));
          }
          break;
        case KC_MUTEPLAY:
          if (record->event.pressed) {
            if (fn_held) {
              tap_code(KC_MUTE);
            } else {
              tap_code(KC_MPLY);
            }
          }
          break;
        case KC_WINLT:
            if (record->event.pressed) {
              register_mods(mod_config(MOD_LGUI));
              register_mods(mod_config(MOD_LSFT));
              register_code(KC_LEFT);
            } else {
               unregister_mods(mod_config(MOD_LGUI));
              unregister_mods(mod_config(MOD_LSFT));
              unregister_code(KC_LEFT);
            }
            break;
        case KC_WINRT:
            if (record->event.pressed) {
              register_mods(mod_config(MOD_LGUI));
              register_mods(mod_config(MOD_LSFT));
              register_code(KC_RIGHT);
            } else {
               unregister_mods(mod_config(MOD_LGUI));
              unregister_mods(mod_config(MOD_LSFT));
              unregister_code(KC_RIGHT);
            }
            break;
        case KC_E_0:
            if (record->event.pressed) {
                send_unicode_string("0️⃣");
            }
            break;
        case KC_E_1:
            if (record->event.pressed) {
                send_unicode_string("1️⃣");
            }
            break;
        case KC_E_2:
            if (record->event.pressed) {
                send_unicode_string("2️⃣");
            }
            break;
        case KC_E_3:
            if (record->event.pressed) {
                send_unicode_string("3️⃣");
            }
            break;
        case KC_E_4:
            if (record->event.pressed) {
                send_unicode_string("4️⃣");
            }
            break;
        case KC_E_5:
            if (record->event.pressed) {
                send_unicode_string("5️⃣");
            }
            break;
        case KC_E_6:
            if (record->event.pressed) {
                send_unicode_string("6️⃣");
            }
            break;
        case KC_E_7:
            if (record->event.pressed) {
                send_unicode_string("7️⃣");
            }
            break;
        case KC_E_8:
            if (record->event.pressed) {
                send_unicode_string("8️⃣");
            }
            break;
        case KC_E_9:
            if (record->event.pressed) {
                send_unicode_string("9️⃣");
            }
            break;
    }
    return true;
}





#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            if(shift_held) {
                uint8_t send_data[32] = {0};
                send_data[0] = 15;
                raw_hid_send(send_data, sizeof(send_data));
            } else if(fn_held) {
               uint8_t send_data[32] = {0};
                send_data[0] = 13;
                raw_hid_send(send_data, sizeof(send_data));
            } else {

                tap_code(KC_UP);
            }
        } else {
            if(shift_held) {
                uint8_t send_data[32] = {0};
                send_data[0] = 14;
                raw_hid_send(send_data, sizeof(send_data));
            } else if(fn_held) {
                uint8_t send_data[32] = {0};
                send_data[0] = 12;
                raw_hid_send(send_data, sizeof(send_data));
            } else {

                tap_code(KC_DOWN);

            }
        }
        //left encoder
    } else if (index == 1) {
            if (clockwise) {
                if(ctrl_held) {
                tap_code(KC_PGDN);
                } else if(fn_held || layer_state_is(_LOWER)) {
                tap_code(KC_MPRV);
                } else {
                    tap_code(KC_LEFT);

                }
            } else {
                if(ctrl_held) {
                tap_code(KC_PGUP);
                } else if(fn_held || layer_state_is(_LOWER)) {
                tap_code(KC_MNXT);
                } else {
                    tap_code(KC_RGHT);

                }
            }
        }
    return true;
}

#endif
