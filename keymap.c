/* Copyright 2023 David Porter <david@daporter.net>
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

#include "features/achordion.h"
#include "features/custom_shift_keys.h"
#include "features/swapper.h"

enum layers { BASE, NAV, SYM, NUM, FN, ADJ };

enum custom_keycodes {
	SW_TAB = SAFE_RANGE,	// Switch to next window (C-TAB)
};

// Home row mods.
#define GUI_R LGUI_T(KC_R)
#define ALT_S LALT_T(KC_S)
#define SFT_N LSFT_T(KC_N)
#define CTL_D LCTL_T(KC_D)
#define CTL_A RCTL_T(KC_A)
#define SFT_E RSFT_T(KC_E)
#define ALT_I RALT_T(KC_I)
#define GUI_H RGUI_T(KC_H)

// Hyper keys.
#define C_APP LT(0, KC_C)
#define U_APP LT(0, KC_U)

// Thumb keys.
#define L_NAV LT(NAV, KC_BSPC)
#define L_SYM LT(SYM, KC_T)
#define L_NUM LT(NUM, KC_SPC)
#define L_FN  LT(FN,  KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │  J   │  G   │  M   │  P   │  V   │                  │  Z   │ , ;  │ . :  │ - _  │ ' "  │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  R   │  S   │  N   │  D   │  B   │                  │ / *  │  A   │  E   │  I   │  H   │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  X   │  F   │  L   │  C   │  W   │                  │  Q   │  U   │  O   │  Y   │  K   │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │ BSPC │  T   │    │  T   │ ENT  │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
[BASE] = LAYOUT(
    KC_J,  KC_G,  KC_M,  KC_P,  KC_V,         KC_Z,    KC_COMM, KC_DOT, KC_MINS, KC_QUOT,
    GUI_R, ALT_S, SFT_N, CTL_D, KC_B,         KC_SLSH, CTL_A,   SFT_E,  ALT_I,   GUI_H,
    KC_X,  KC_F,  KC_L,  C_APP, KC_W,         KC_Q,    U_APP,   KC_O,   KC_Y,    KC_K,
			   L_NAV, L_SYM,   L_NUM, L_FN),

/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │                  │ NUM  │ home │  up  │ end  │ pgup │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │                  │ caps │ left │ down │right │ pgdn │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │                  │      │      │      │      │      │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │      │      │    │      │      │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
[NAV] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_NUM,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
				 _______, _______,   _______, _______),

/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │  `   │      │  &   │  \   │      │                  │  ^   │  <   │  [   │  ]   │  >   │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  !   │ - _  │  +   │  =   │  #   │                  │  |   │ ? !  │  (   │  )   │  %   │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │                  │  ~   │  $   │  {   │  }   │  @   │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │      │      │    │      │      │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
[SYM] = LAYOUT(
    KC_GRV,  XXXXXXX, KC_AMPR, KC_BSLS, XXXXXXX,     KC_CIRC, KC_LT,   KC_LBRC, KC_RBRC, KC_GT,
    KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH,     KC_PIPE, KC_QUES, KC_LPRN, KC_RPRN, KC_PERC,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_TILD, KC_DLR,  KC_LCBR, KC_RCBR, KC_AT,
			      _______,   _______,   _______, _______),

/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │  +   │  7   │  8   │  9   │  *   │                  │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  0   │  4   │  5   │  6   │ . :  │                  │      │  =   │  %   │      │      │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │ - _  │  1   │  2   │  3   │ / *  │                  │      │      │      │      │      │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │      │      │    │      │      │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
[NUM] = LAYOUT(
    KC_PLUS, KC_7, KC_8, KC_9, KC_ASTR,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_0,    KC_4, KC_5, KC_6, KC_DOT,         XXXXXXX, KC_EQL,  KC_PERC, XXXXXXX, XXXXXXX,
    KC_MINS, KC_1, KC_2, KC_3, KC_SLSH,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			_______, _______,   _______, _______),

/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │ F12  │  F7  │  F8  │  F9  │      │                  │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │ F11  │  F4  │  F5  │  F6  │      │                  │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │ F10  │  F1  │  F2  │  F3  │      │                  │      │      │      │      │      │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │      │      │    │      │      │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
[FN] = LAYOUT(
    KC_F12, KC_F7, KC_F8, KC_F9, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F11, KC_F4, KC_F5, KC_F6, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F10, KC_F1, KC_F2, KC_F3, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			    _______, _______,   _______, _______),

/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │QK_BOO│      │bri up│      │      │                  │      │      │vol up│      │      │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │      │      │bri dn│      │      │                  │      │      │vol dn│      │ mute │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │                  │      │      │      │      │      │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │      │      │    │      │      │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
[ADJ] = LAYOUT(
    QK_BOOT, XXXXXXX, KC_BRIU, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_BRID, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, KC_MUTE,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
				_______,   _______,   _______,   _______),
};

// clang-format on

/*
 * Custom shift keys.
 */
const custom_shift_key_t custom_shift_keys[] = {
	{ KC_DOT,  KC_COLN },
	{ KC_COMM, KC_SCLN },
	{ KC_QUES, KC_EXLM },
	{ KC_QUOT, KC_DQUO },
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
	sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

/*
 * Tri-state layers.
 */

layer_state_t layer_state_set_user(layer_state_t state)
{
	// When the SYM and NUM layer-activate keys are both held, activate the
	// ADJ layer.
	return update_tri_layer_state(state, SYM, NUM, ADJ);
}

/*
 * Combos.
 */

const uint16_t PROGMEM combo_s_n[] = { ALT_S, SFT_N, COMBO_END };
const uint16_t PROGMEM combo_n_d[] = { SFT_N, CTL_D, COMBO_END };
const uint16_t PROGMEM combo_d_b[] = { CTL_D, KC_B,  COMBO_END };
const uint16_t PROGMEM combo_n_e[] = { SFT_N, SFT_E, COMBO_END };

combo_t key_combos[] = {
	COMBO(combo_s_n, KC_ESC),
	COMBO(combo_n_d, KC_TAB),
	COMBO(combo_d_b, KC_DEL),
	COMBO(combo_n_e, CW_TOGG),	// Caps Word
};

bool get_combo_must_tap(uint16_t index, combo_t *combo)
{
	// Make every combo that has Mod-Tap/Layer-Tap/Momentary keys in its
	// chord tap-only.
	uint16_t key;
	uint8_t idx = 0;
	while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
		switch (key) {
		case QK_MOD_TAP ... QK_MOD_TAP_MAX:
		case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
		case QK_MOMENTARY ... QK_MOMENTARY_MAX:
			return true;
		}
		idx += 1;
	}
	return false;
}

/*
 * Achordion.
 */

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
		     uint16_t other_keycode, keyrecord_t *other_record)
{
	// Consider the following chords as holds, even though they’re
	// on the same hand in the Hands Down layout.
	switch (tap_hold_keycode) {
	case L_SYM:
	case L_NUM:
		return true;
	}

	// Otherwise, follow the opposite hands rule.
	return achordion_opposite_hands(tap_hold_record, other_record);
}

/*
 * Swapper.
 */

bool sw_win_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	if (!process_achordion(keycode, record)) {
		return false;
	}
	if (!process_custom_shift_keys(keycode, record)) {
		return false;
	}
	update_swapper(&sw_win_active, KC_LCTL, KC_TAB, SW_TAB, keycode,
		       record);

	switch (keycode) {
		/* Make ‘c’ and ‘u’ to act as Hyper modifiers when they are
		   held.  This requires two steps:

		   1. In QMK, when c and u are held, send the the App key
		   (called "Menu" in Xorg).

		   2. In Xorg, map the Menu key (called "App" in QMK) to the
		   .Hyper modifier. */

	case C_APP:
	case U_APP:
		if (record->tap.count)
			break;

		if (record->event.pressed)
			register_code(KC_APP);
		else
			unregister_code(KC_APP);

		return false;
	}

	return true;
}

void matrix_scan_user(void)
{
	achordion_task();
}
