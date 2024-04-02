#include "handsdown_au.h"

const uint16_t PROGMEM F_ESC_combo[]  = { HD_LM4, HD_LM1, COMBO_END };
const uint16_t PROGMEM Htab_combo[]   = { HD_LT4, HD_LT3, COMBO_END };
const uint16_t PROGMEM Hstab_combo[]  = { HD_LT4, HD_LT3, HD_LT2, COMBO_END };
const uint16_t PROGMEM F_CAPS_combo[] = { HD_LM3, HD_LM2, HD_RM2, HD_RM3,
                                          COMBO_END };
const uint16_t PROGMEM H_CAPW_combo[] = { HD_LM1, HD_LM2, HD_RM1, HD_RM2,
                                          COMBO_END };
const uint16_t PROGMEM H_Z_combo[]    = { HD_LT3, HD_LT1, COMBO_END };
const uint16_t PROGMEM H_Q_combo[]    = { HD_LM3, HD_LM1, COMBO_END };

combo_t key_combos[] = {
	[FC_ESC]  = COMBO(F_ESC_combo, KC_ESC),
	[HC_CAPW] = COMBO_ACTION(H_CAPW_combo),
	[HC_TAB]  = COMBO(Htab_combo, KC_TAB),
	[HC_STAB] = COMBO(Hstab_combo, S(KC_TAB)),
	[HC_Z]    = COMBO(H_Z_combo, HD_Z),
	[HC_Q]    = COMBO(H_Q_combo, HD_Q),
};
