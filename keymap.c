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

enum layers { BASE, SYM, NAV, NUM, WM, ADJ };

enum custom_keycodes {
	QU = SAFE_RANGE,
	SW_TAB, // Switch to next window (cmd-tab)
};

// Home row mods.
#define HOME_R LGUI_T(KC_R)
#define HOME_S LALT_T(KC_S)
#define HOME_N LSFT_T(KC_N)
#define HOME_D LCTL_T(KC_D)
#define HOME_A RCTL_T(KC_A)
#define HOME_E RSFT_T(KC_E)
#define HOME_I RALT_T(KC_I)
#define HOME_H RGUI_T(KC_H)

#define L_NAV MO(NAV)
#define L_SYM MO(SYM)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │  J   │  G   │  M   │  P   │  V   │                  │ ; :  │ . !  │repeat│  /   │ ' "  │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │HOME_R│HOME_S│HOME_N│HOME_D│  B   │                  │ , ?  │HOME_A│HOME_E│HOME_I│HOME_H│
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  X   │  F   │  L   │  C   │  W   │                  │  -   │  U   │  O   │  Y   │  K   │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │L_NAV │  T   │    │  T   │L_SYM │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
[BASE] = LAYOUT(
    KC_J,   KC_G,   KC_M,   KC_P,   KC_V,         KC_SCLN, KC_DOT, QK_REP, KC_SLSH, KC_QUOT,
    HOME_R, HOME_S, HOME_N, HOME_D, KC_B,         KC_COMM, HOME_A, HOME_E, HOME_I,  HOME_H,
    KC_X,   KC_F,   KC_L,   KC_C,   KC_W,         KC_MINS, KC_U,   KC_O,   KC_Y,    KC_K,
				L_NAV, KC_T,   KC_SPC, L_SYM),


/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │  `   │  <   │  >   │  @   │  ^   │                  │  &   │  $   │  [   │  ]   │      │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  !   │  -   │  +   │  =   │  :   │                  │  |   │  _   │  (   │  )   │  %   │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │ APP  │      │  *   │  \   │  ~   │                  │      │  #   │  {   │  }   │      │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │      │      │    │      │      │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
[SYM] = LAYOUT(
    KC_GRV,  KC_LT,   KC_GT,   KC_AT,   KC_CIRC,       KC_AMPR, KC_DLR,  KC_LBRC, KC_RBRC, _______,
    KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_COLN,       KC_PIPE, KC_UNDS, KC_LPRN, KC_RPRN, KC_PERC,
    KC_APP,  XXXXXXX, KC_ASTR, KC_BSLS, KC_TILD,       _______, KC_HASH, KC_LCBR, KC_RCBR, XXXXXXX,
                               _______,   _______,   _______ ,   _______),

/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │      │ back │ stab │ fwd  │      │                  │ esc  │ pgup │  up  │ pgdn │ caps │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │      │ LALT │ LSFT │ LCTL │      │                  │ home │ left │ down │right │ end  │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │                  │      │ tab  │ del  │      │      │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │      │      │    │      │      │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
[NAV] = LAYOUT(
    XXXXXXX, KC_WBAK, SW_TAB,  KC_WFWD, XXXXXXX,       KC_ESC,  KC_PGUP, KC_UP,   KC_PGDN, KC_CAPS,
    XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,       KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, KC_TAB,  KC_DEL,  XXXXXXX, XXXXXXX,
				 _______, _______,   G(KC_SPC), _______),

/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │  F6  │  F4  │  F2  │ F10  │  F8  │                  │  F9  │  F1  │  F3  │  F5  │  F7  │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  6   │  4   │  2   │  0   │  8   │                  │  9   │  1   │  3   │  5   │  7   │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │                  │      │      │      │      │      │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │      │      │    │      │      │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
[NUM] = LAYOUT(
    KC_F6,   KC_F4,   KC_F2,   KC_F10,  KC_F8,          KC_F9,   KC_F1,   KC_F3,   KC_F5,   KC_F7,
    KC_6,    KC_4,    KC_2,    KC_0,    KC_8,           KC_9,    KC_1,    KC_3,    KC_5,    KC_7,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
				 _______, _______,   _______, _______),

/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │ esc  │ back │ stab │ fwd  │      │                  │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │G(KC_T│G(KC_K│G(KC_J│ win  │      │                  │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │                  │      │      │      │      │      │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │      │      │    │      │      │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
[WM] = LAYOUT(
    KC_ESC,    KC_WBAK, SW_TAB,  KC_WFWD,       XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    G(KC_TAB), G(KC_K), G(KC_J), OSM(MOD_LGUI), XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
					 _______, _______,   G(KC_SPC), _______),

/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │      │      │ play │      │bri up│                  │      │      │vol up│      │scrlk │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │ win  │ alt  │shift │ ctrl │bri dn│                  │      │      │vol dn│      │      │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │QK_BOO│      │      │      │      │                  │      │      │ mute │      │      │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │      │      │    │      │      │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
[ADJ] = LAYOUT(
    XXXXXXX,         XXXXXXX,         KC_MPLY,         XXXXXXX,         KC_BRIU,         XXXXXXX,   XXXXXXX,    KC_VOLU,    XXXXXXX,    KC_SCRL,
    OSM(MOD_LGUI),   OSM(MOD_LALT),   OSM(MOD_LSFT),   OSM(MOD_LCTL),   KC_BRID,         XXXXXXX,   XXXXXXX,    KC_VOLD,    XXXXXXX,    XXXXXXX,
    QK_BOOT,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,   XXXXXXX,    KC_MUTE,    XXXXXXX,    XXXXXXX,
								_______,   _______,   _______,   _______),

};

// clang-format on

/*
 * Custom shift keys.
 */
const custom_shift_key_t custom_shift_keys[] = {
	{ KC_SCLN, KC_COLN },
	{ KC_DOT, KC_EXLM },
	{ KC_COMM, KC_QUES },
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
	sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

/*
 * Tri-state layers.
 */

layer_state_t layer_state_set_user(layer_state_t state)
{
	return update_tri_layer_state(state, SYM, NAV, NUM);
}

/*
 * Combos.
 */

// clang-format off

// Left top row
const uint16_t PROGMEM combo_j_g[]        = { KC_J,   KC_G,    COMBO_END };
const uint16_t PROGMEM combo_g_m[]        = { KC_G,   KC_M,    COMBO_END };
const uint16_t PROGMEM combo_m_p[]        = { KC_M,   KC_P,    COMBO_END };
// Right top row
const uint16_t PROGMEM combo_rep_sl[]     = { QK_REP, KC_SLSH, COMBO_END };
const uint16_t PROGMEM combo_dot_rep_sl[] = { KC_DOT, QK_REP,  KC_SLSH, COMBO_END };

// Left home row
const uint16_t PROGMEM combo_n_d[]        = { HOME_N, HOME_D,  COMBO_END };
const uint16_t PROGMEM combo_s_n_d[]      = { HOME_S, HOME_N,  HOME_D,  COMBO_END };
const uint16_t PROGMEM combo_d_b[]        = { HOME_D, KC_B,    COMBO_END };
// Right home row
const uint16_t PROGMEM combo_a_e_i[]      = { HOME_A, HOME_E,  HOME_I,  COMBO_END };
// Mixed
const uint16_t PROGMEM combo_n_e[]        = { HOME_N, HOME_E,  COMBO_END };

// Left bottom row
// Right bottom row

// Thumbs
const uint16_t PROGMEM combo_t_sym[]      = { KC_T,   L_SYM,   COMBO_END };

combo_t key_combos[] = {
	COMBO(combo_j_g,        KC_Q),
	COMBO(combo_g_m,        QU),
	COMBO(combo_m_p,        KC_Z),
	COMBO(combo_rep_sl,     KC_BSPC),
	COMBO(combo_dot_rep_sl, C(KC_BSPC)),

	COMBO(combo_n_d,        KC_TAB),
	COMBO(combo_s_n_d,      KC_ESC),
	COMBO(combo_d_b,        KC_DEL),
	COMBO(combo_a_e_i,      KC_ENT),
	COMBO(combo_n_e,        CW_TOGG),    // Caps Word

	COMBO(combo_t_sym,      MO(ADJ)),
};

// clang-format on

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
	case HOME_R:
	case HOME_S:
	case HOME_N:
	case HOME_D:
		if (other_keycode == L_NAV || other_keycode == KC_ENT ||
		    other_keycode == KC_Q)
			return true;
		break;
	case HOME_A:
	case HOME_E:
	case HOME_I:
	case HOME_H:
		if (other_keycode == L_SYM || other_keycode == KC_SPC)
			return true;
		break;
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
	case QU:
		if (record->event.pressed)
			SEND_STRING("qu");
		break;
	}

	return true;
}

void matrix_scan_user(void)
{
	achordion_task();
}
