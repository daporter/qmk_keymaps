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

#ifndef LAYERS_H
#define LAYERS_H

/*
  L_SYM: Symbols and punctuation.
  ╭─────────────────╮   ╭─────────────────╮
  │  `  <  >  @  .  │   │  &  _  $  ?     │
  │  !  -  +  =  #  │   │  |  {  (  [  %  │
  │  :  /  *  ^  \  │   │  ~  }  )  ]     │
  ╰──────────╮      │   │      ╭──────────╯
	     ╰──-───╯   ╰──────╯
 */

#define LS_LT4 KC_GRV
#define LS_LT3 KC_LABK
#define LS_LT2 KC_RABK
#define LS_LT1 KC_AT
#define LS_LT0 KC_DOT
#define LS_RT0 KC_AMPR
#define LS_RT1 KC_UNDS
#define LS_RT2 KC_DLR
#define LS_RT3 KC_QUES
#define LS_RT4 KC_NO

#define LS_LM4 KC_EXLM
#define LS_LM3 KC_MINS
#define LS_LM2 KC_PLUS
#define LS_LM1 KC_EQL
#define LS_LM0 KC_HASH
#define LS_RM0 KC_PIPE
#define LS_RM1 KC_LCBR
#define LS_RM2 KC_LPRN
#define LS_RM3 KC_LBRC
#define LS_RM4 KC_PERC

#define LS_LB4 KC_COLN
#define LS_LB3 KC_SLSH
#define LS_LB2 KC_ASTR
#define LS_LB1 KC_CIRC
#define LS_LB0 KC_BSLS
#define LS_RB0 KC_TILD
#define LS_RB1 KC_RCBR
#define LS_RB2 KC_RPRN
#define LS_RB3 KC_RBRC
#define LS_RB4 KC_NO

#define LS_LH2 KC_NO
#define LS_LH1 KC_NO
#define LS_RH1 KC_NO
#define LS_RH2 KC_NO

/*
  L_NUM: Function keys and numbers.
  ╭───────────────────────╮   ╭─────────────────────╮
  │  F9  F10 F11 F12 F13  │   │  /   7   8   9   -  │
  │  F5  F6  F7  F8  F14  │   │  *   1   2   3   +  │
  │  F1  F2  F3  F4  INS  │   │  ,   4   5   6   =  │
  ╰────────────╮ ;  L_NAV │   │  0   . ╭────────────╯
	       ╰──────-───╯   ╰────────╯
*/

#define LN_LT4 KC_F9
#define LN_LT3 KC_F10
#define LN_LT2 KC_F11
#define LN_LT1 KC_F12
#define LN_LT0 KC_F13
#define LN_RT0 KC_SLSH
#define LN_RT1 KC_7
#define LN_RT2 KC_8
#define LN_RT3 KC_9
#define LN_RT4 KC_MINS

#define LN_LM4 LGUI_T(KC_F5)
#define LN_LM3 LALT_T(KC_F6)
#define LN_LM2 LCTL_T(KC_F7)
#define LN_LM1 LSFT_T(KC_F8)
#define LN_LM0 KC_F14
#define LN_RM0 KC_ASTR
#define LN_RM1 RSFT_T(KC_1)
#define LN_RM2 RCTL_T(KC_2)
#define LN_RM3 RALT_T(KC_3)
#define LN_RM4 RGUI_T(KC_PLUS)

#define LN_LB4 KC_F1
#define LN_LB3 KC_F2
#define LN_LB2 KC_F3
#define LN_LB1 KC_F4
#define LN_LB0 KC_INS
#define LN_RB0 KC_COMM
#define LN_RB1 KC_4
#define LN_RB2 KC_5
#define LN_RB3 KC_6
#define LN_RB4 KC_EQL

#define LN_LH2 KC_SCLN
#define LN_LH1 TG(L_NAV)
#define LN_RH1 KC_0
#define LN_RH2 KC_DOT

/*
  L_NAV: Mouse and keyboard navigation.
 ╭──────────────────────────────────╮   ╭──────────────────────────────╮
 │ MB4    MB3   MB2    MB1    ←Win │   │ MAcc0   ⇱    ⇞    ⇟    ⇲  │
 │ ←M    ↑M    M↓    M→    Win→ │   │ MAcc1  ←    ↑    ↓    →   │
 │ ←MWh  ↑MWh  MWh↓  MWh→  redo  │   │ MAcc2  cut  copy  pste  undo │
 ╰────────────────────────╮         │   │           ╭──────────────────╯
                          ╰─────────╯   ╰───────────╯
*/

#define LV_LT4 KC_BTN4
#define LV_LT3 KC_BTN2
#define LV_LT2 KC_BTN3
#define LV_LT1 KC_BTN1
#define LV_LT0 C(S(KC_TAB))
#define LV_RT0 KC_ACL0
#define LV_RT1 KC_HOME
#define LV_RT2 KC_PGUP
#define LV_RT3 KC_PGDN
#define LV_RT4 KC_END

#define LV_LM4 KC_MS_L
#define LV_LM3 KC_MS_U
#define LV_LM2 KC_MS_D
#define LV_LM1 KC_MS_R
#define LV_LM0 C(KC_TAB)
#define LV_RM0 KC_ACL1
#define LV_RM1 KC_LEFT
#define LV_RM2 KC_UP
#define LV_RM3 KC_DOWN
#define LV_RM4 KC_RIGHT

#define LV_LB4 KC_WH_L
#define LV_LB3 KC_WH_U
#define LV_LB2 KC_WH_D
#define LV_LB1 KC_WH_R
#define LV_LB0 C(S(KC_Z))
#define LV_RB0 KC_ACL2
#define LV_RB1 C(KC_X)
#define LV_RB2 C(KC_C)
#define LV_RB3 C(KC_V)
#define LV_RB4 C(KC_Z)

#define LV_LH2 LCTL_T(KC_BSPC)
#define LV_LH1 LSFT_T(KC_ENT)
#define LV_RH1 KC_0
#define LV_RH2 KC_DOT

/*
  L_CFG: Keyboard configuration and media settings.
  ╭─────────────────────────╮   ╭─────────────────────╮
  │             RBT         │   │                     │
  │             vol↑ bri↑ │   │         mute        │
  │  BOOT       vol↓ bri↓ │   │                     │
  ╰──────────────╮          │   │         ╭───────────╯
		 ╰──────────╯   ╰─────────╯
*/

#define LC_LT4 KC_NO
#define LC_LT3 KC_NO
#define LC_LT2 KC_NO
#define LC_LT1 QK_RBT
#define LC_LT0 KC_NO
#define LC_RT0 LCA(KC_DEL)
#define LC_RT1 KC_NUM
#define LC_RT2 KC_EJCT
#define LC_RT3 KC_NO
#define LC_RT4 KC_NO

#define LC_LM4 KC_NO
#define LC_LM3 KC_NO
#define LC_LM2 KC_NO
#define LC_LM1 KC_VOLU
#define LC_LM0 KC_BRIU
#define LC_RM0 KC_NO
#define LC_RM1 KC_MPRV
#define LC_RM2 KC_MUTE
#define LC_RM3 KC_MNXT
#define LC_RM4 KC_NO

#define LC_LB4 QK_BOOT
#define LC_LB3 AG_SWAP
#define LC_LB2 AG_NORM
#define LC_LB1 KC_VOLD
#define LC_LB0 KC_BRID
#define LC_RB0 KC_NO
#define LC_RB1 KC_MRWD
#define LC_RB2 KC_MPLY
#define LC_RB3 KC_MFFD
#define LC_RB4 KC_NO

#define LC_LH2 KC_VOLD
#define LC_LH1 KC_VOLU
#define LC_RH1 KC_NO
#define LC_RH2 KC_NO

#endif
