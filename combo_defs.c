#include "handsdown_au.h"

// clang-format off
const uint16_t PROGMEM H_Q_combo[]    = { HD_LT3, HD_LT2, COMBO_END };
const uint16_t PROGMEM H_Z_combo[]    = { HD_LT2, HD_LT1, COMBO_END };
const uint16_t PROGMEM F_ESC_combo[]  = { HD_LM3, HD_LM2, COMBO_END };
const uint16_t PROGMEM Hstab_combo[]  = { HD_LM3, HD_LM2, HD_LM1, COMBO_END };
const uint16_t PROGMEM Htab_combo[]   = { HD_LM2, HD_LM1, COMBO_END };
const uint16_t PROGMEM F_CAPS_combo[] = { HD_LM2, HD_RM2, COMBO_END };
const uint16_t PROGMEM H_CAPW_combo[] = { HD_LM1, HD_RM1, COMBO_END };
const uint16_t PROGMEM H_EQL_combo[]  = { HD_RT1, HD_RT2, COMBO_END };
// clang-format on

combo_t key_combos[] = {
	// clang-format off
	[HC_Q]    = COMBO(H_Q_combo,    HD_Q),
	[HC_Z]    = COMBO(H_Z_combo,    HD_Z),
	[FC_ESC]  = COMBO(F_ESC_combo,  KC_ESC),
	[HC_STAB] = COMBO(Hstab_combo,  S(KC_TAB)),
	[HC_TAB]  = COMBO(Htab_combo,   KC_TAB),
	[FC_CAPS] = COMBO(F_CAPS_combo, KC_CAPS),
	[HC_CAPW] = COMBO(H_CAPW_combo, CW_TOGG),
	[HC_EQL]  = COMBO(H_EQL_combo,  KC_EQL),
	// clang-format on
};
