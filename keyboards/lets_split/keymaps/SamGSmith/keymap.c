#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _SCROLL,
  _NUMPAD,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NUMPAD MO(_NUMPAD)
#define KC_CMDTB LGUI_T(KC_TAB)
#define KC_SHEN  RSFT_T(KC_ENT)
#define KC_SHBS  LSFT_T(KC_BSPC)
#define KC_OPEN RALT_T(KC_ENT)
#define KC_GUIL  LGUI(KC_LEFT)
#define KC_GUIR  LGUI(KC_RGHT)
#define KC_CTLL  LCTL(KC_LEFT)
#define KC_CTLR  LCTL(KC_RGHT)
#define KC_ALTL  LALT(KC_LEFT)
#define KC_ALTR  LALT(KC_RGHT)
#define KC_CCLN  LSFT(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Cmd/Tab   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift/Enter
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Numpad| Opt  | Cmd  |Lower |Space |ShfBksp Raise|Opt/En| Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_CMDTB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SHEN, \
    KC_LCTL,  NUMPAD,  KC_LALT, KC_LGUI, LOWER, KC_SPC,  KC_SHBS,   RAISE,   KC_OPEN, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Cmd/Tab   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift/Enter
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Numpad| Opt  | Cmd  |Lower | Space| Bksp |RaisEntOpt/En| Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
    KC_ESC,     KC_Q,    KC_W,    KC_F,  KC_P,   KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
    KC_CMDTB,   KC_A,    KC_R,    KC_S,  KC_T,   KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SHEN, \
    KC_LCTL,  NUMPAD, KC_LALT, KC_LGUI, LOWER, KC_SPC,  KC_SHBS,   RAISE,   KC_OPEN, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Cmd/Tab   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift/Enter
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Numpad| Opt  | Cmd  |Lower | Space| Bksp |RaisEntOpt/En| Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
    KC_ESC,  KC_QUOT, KC_COMM,  KC_DOT,  KC_P,   KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,  KC_L, KC_BSPC, \
    KC_CMDTB,   KC_A,    KC_O,    KC_E,  KC_U,   KC_I,    KC_D,    KC_H,    KC_T,    KC_N,  KC_S, KC_SLSH, \
    KC_LSFT, KC_SCLN,    KC_Q,    KC_J,  KC_K,   KC_X,    KC_B,    KC_M,    KC_W,    KC_V,  KC_Z, KC_SHEN, \
    KC_LCTL,  NUMPAD, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SHBS,   RAISE, KC_OPEN, KC_DOWN, KC_UP, KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Del  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ctr/Tab Vol- | Vol+ | Mous2| Mous1|ScrolU|AltLft| Left | Down |  Up  |Right |AltRgt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Sleep |ScrolL|ScrolR| Mous3|ScrolD|CmdLft| Home |Pg Dn |Pg Up | End  |CmdRgt|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
     KC_DEL,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC, \
    KC_CMDTB, KC_VOLD, KC_VOLU, KC_BTN2, KC_BTN1, KC_WH_U, KC_ALTL, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_ALTR, \
    _______,  KC_SLEP, KC_WH_L, KC_WH_R, KC_BTN3, KC_WH_D, KC_GUIL, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_GUIR, \
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |ISO # |ISO \ |ISO | |   -  |   =  |  \   |   [  |   ]  |  `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CapsLock     |      |      |      |ISO ~ |   _  |   +  |  |   |   {  |   }  |  ~   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR,    KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
    _______, _______, _______, KC_NUHS, KC_NUBS, S(KC_NUBS), KC_MINS,  KC_EQL, KC_BSLS, KC_LBRC, KC_RBRC,  KC_GRV, \
    KC_CAPS, _______, _______, _______, _______, S(KC_NUHS), KC_UNDS, KC_PLUS, KC_PIPE, KC_LCBR, KC_RCBR, KC_TILD, \
    _______, _______, _______, _______, _______,    _______, _______, _______, KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Boot |      |CGnorm|CGswap|AGnorm|AGswap|      |  F1  |  F2  |  F3  |  F4  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Debug|Qwerty|Colemk|Dvorak|      |      |      |  F5  |  F6  |  F7  |  F8  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F9  |  F10 |  F11 |  F12 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
    QK_BOOT, _______, CG_NORM, CG_SWAP, AG_NORM, AG_SWAP, _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______, \
    DB_TOGG,  QWERTY, COLEMAK,  DVORAK, _______, _______, _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______, \
    _______, _______, _______, _______, _______, _______, _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |   K  |      |      |      |      |      |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ctr/Tab   J  |   M  |   V  |   1  |      |   /  |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Down |   :  |   =  |   (  |   )  |      |   1  |   2  |   3  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   0  |   .  | =Rtn |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12(
    _______,    KC_K, _______, _______,  _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, _______, \
    _______,    KC_J,    KC_M,    KC_V,     KC_1, _______, KC_PSLS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, _______, \
    _______, KC_DOWN, KC_CCLN,  KC_EQL,  KC_LPRN, KC_RPRN, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, _______, \
    _______, _______, _______, _______,  _______, _______, _______, KC_KP_0, KC_KP_0, KC_PDOT, KC_PENT, _______  \
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
  }
  return true;
}