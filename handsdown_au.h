#ifndef HANDSDOWN_AU_H
#define HANDSDOWN_AU_H

/*
  First, define HD alpha keycodes with any hold-taps/custom keycodes.
*/
#define HD_A RSFT_T(KC_A)
#define HD_B KC_B
#define HD_C KC_C
#define HD_D LSFT_T(KC_D)
#define HD_E RCTL_T(KC_E)
#define HD_F KC_F
#define HD_G KC_G
#define HD_H RGUI_T(KC_H)
#define HD_I RALT_T(KC_I)
#define HD_J KC_J
#define HD_K KC_K
#define HD_L KC_L
#define HD_M KC_M
#define HD_N LCTL_T(KC_N)
#define HD_O KC_O
#define HD_P KC_P
#define HD_Q KC_Q
#define HD_R LGUI_T(KC_R)
#define HD_S LALT_T(KC_S)
#define HD_T LT(L_FUN, KC_T)
#define HD_U KC_U
#define HD_V KC_V
#define HD_W KC_W
#define HD_X KC_X
#define HD_Y KC_Y
#define HD_Z KC_Z

#define HD_SCLN KC_SCLN
#define HD_DOT	KC_DOT
#define HD_SLSH KC_SLSH
#define HD_DQUO KC_DQUO
#define HD_QUOT KC_QUOT
#define HD_COMM KC_COMM
#define HD_MINS KC_MINS
#define HD_SPC	LT(L_SYM, KC_SPC)
#define HD_BSPC LT(L_NUM, KC_BSPC)
#define HD_ENT	LT(L_CFG, KC_ENT)

/*
  Place these HD keycodes on the keymap for variation independent spatial
  referencing by key position.

  Base (alpha) layer Hands Down Gold (HRMs + thumb mods):
  ╭─────────────────────╮   ╭─────────────────────╮
  │  J   G   M   P   V  │   │  #$  .:  / * "[  '] │
  │  R   S   N   D   B  │   │  ,;   A   E   I   H │
  │  X   F   L   C   W  │   │  -+   U   O   Y   K │
  ╰───────────╮ bsp  T  │   │ spc  ret ╭──────────╯
	      ╰─────────╯   ╰──────────╯

  Q & Z are on the sym layer and accessible combos (defined below).
 */

#define HD_LT4 HD_J
#define HD_LT3 HD_G
#define HD_LT2 HD_M
#define HD_LT1 HD_P
#define HD_LT0 HD_V
#define HD_RT0 HD_SCLN
#define HD_RT1 HD_DOT
#define HD_RT2 HD_SLSH
#define HD_RT3 HD_DQUO
#define HD_RT4 HD_QUOT

#define HD_LM4 HD_R
#define HD_LM3 HD_S
#define HD_LM2 HD_N
#define HD_LM1 HD_D
#define HD_LM0 HD_B
#define HD_RM0 HD_COMM
#define HD_RM1 HD_A
#define HD_RM2 HD_E
#define HD_RM3 HD_I
#define HD_RM4 HD_H

#define HD_LB4 HD_X
#define HD_LB3 HD_F
#define HD_LB2 HD_L
#define HD_LB1 HD_C
#define HD_LB0 HD_W
#define HD_RB0 HD_MINS
#define HD_RB1 HD_U
#define HD_RB2 HD_O
#define HD_RB3 HD_Y
#define HD_RB4 HD_K

#define HD_LH2 HD_BSPC
#define HD_LH1 HD_T
#define HD_RH1 HD_SPC
#define HD_RH2 HD_ENT

#endif
