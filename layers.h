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
  L_SYM Symbols and punctuation.
  ╭─────────────────╮                 ╭─────────────────╮
  │  Z  Q  ¶  §  ‡  │                 │  ¢  $  €  £  ¥  │
  │  <  [  (  {  †  │                 │  ¡  *  =  +  /  │
  │  >  ]  )  }  •  │                 │  _  |  &  ^  %  │
  ╰────────────╮ D_WordL  D_WordR │   │  ª  °  ╭────────╯
	       ╰──────────────-───╯   ╰────────╯
 */

#define LS_LT4 KC_GRV
#define LS_LT3 KC_COLN
#define LS_LT2 KC_QUES
#define LS_LT1 KC_BSLS
#define LS_LT0 KC_CIRC
#define LS_RT0 KC_AMPR
#define LS_RT1 KC_TILD
#define LS_RT2 KC_PERC
#define LS_RT3 KC_AT
#define LS_RT4 SK_EURO

#define LS_LM4 KC_LT
#define LS_LM3 KC_LBRC
#define LS_LM2 KC_LPRN
#define LS_LM1 KC_LCBR
#define LS_LM0 KC_HASH
#define LS_RM0 KC_PIPE
#define LS_RM1 KC_EQL
#define LS_RM2 KC_PLUS
#define LS_RM3 KC_MINS
#define LS_RM4 KC_EXLM

#define LS_LB4 KC_GT
#define LS_LB3 KC_RBRC
#define LS_LB2 KC_RPRN
#define LS_LB1 KC_RCBR
#define LS_LB0 SK_MDSH
#define LS_RB0 KC_UNDS
#define LS_RB1 KC_DLR
#define LS_RB2 KC_ASTR
#define LS_RB3 KC_SLSH
#define LS_RB4 SK_ELPS

#define LS_LH2 SK_DELWDL
#define LS_LH1 SK_DELWDR
#define LS_RH1 LALT(KC_9)    // ª
#define LS_RH2 LSA(KC_8)     // °

/*
  L_FUN layer Fn-key row (left) and Num row (right).
  ╭─────────────────────╮        ╭───────────────╮
  │ F9  F10 F11 F12 F13 │        │ /  7  8  9  - │
  │ F5  F6  F7  F8  F14 │        │ *  1  2  3  + │
  │ F1  F2  F3  F4  INS │        │ ,  4  5  6  = │
  ╰────────────╮ ;  L_NUM │   │ 0  . ╭───────────╯
	       ╰──────-───╯   ╰──────╯
*/

#define LF_LT4 KC_F9
#define LF_LT3 KC_F10
#define LF_LT2 KC_F11
#define LF_LT1 KC_F12
#define LF_LT0 KC_F13
#define LF_RT0 KC_SLSH
#define LF_RT1 KC_7
#define LF_RT2 KC_8
#define LF_RT3 KC_9
#define LF_RT4 KC_MINS

#define LF_LM4 LGUI_T(KC_F5)
#define LF_LM3 LALT_T(KC_F6)
#define LF_LM2 LCTL_T(KC_F7)
#define LF_LM1 LSFT_T(KC_F8)
#define LF_LM0 KC_F14
#define LF_RM0 KC_ASTR
#define LF_RM1 RSFT_T(KC_1)
#define LF_RM2 RCTL_T(KC_2)
#define LF_RM3 RALT_T(KC_3)
#define LF_RM4 RGUI_T(KC_PPLS)

#define LF_LB4 KC_F1
#define LF_LB3 KC_F2
#define LF_LB2 KC_F3
#define LF_LB1 KC_F4
#define LF_LB0 KC_INS
#define LF_RB0 KC_COMM
#define LF_RB1 KC_4
#define LF_RB2 KC_5
#define LF_RB3 KC_6
#define LF_RB4 KC_EQL

#define LF_LH2 KC_SCLN
#define LF_LH1 TG(L_NUM)
#define LF_RH1 KC_0
#define LF_RH2 KC_DOT

/*
  L_NUM Navigation (left) NUMPad Layer (right) (LN).
   ╭──────────────────────────────────────────╮ ╭──────────────────────────────────────────╮
__ │ NUM_LK   PGUP    UP      PGDN      TAB   │ │  PSLS      P7 P8 P9      PMNS │ __
__ │ W_LEFT   LEFT    DOWN    RGHT     W_RGHT | |  PAST      P4 P5 P6      PPLS │ __
__ │ UNDO     CUT     COPY    PSTE      SPC   │ │  PCMM      P1 P2 P3      PEQL │ __
   ╰────────────────╮  __   G_T(BSP)  C_T(ENT)│ __         __ │ P0        PDOT    __   ╭────────────────╯
	__      __  ╰─────────────────────────╯ ╰─────────────────────────╯ __
__
*/

#define LN_LT4 KC_PSLS
#define LN_LT3 KC_P7
#define LN_LT2 KC_P8
#define LN_LT1 KC_P9
#define LN_LT0 KC_PMNS
#define LN_RT0 KC_NUM
#define LN_RT1 KC_HOME
#define LN_RT2 KC_PGUP
#define LN_RT3 KC_PGDN
#define LN_RT4 KC_END

#define LN_LM4 LGUI_T(KC_PAST)
#define LN_LM3 LALT_T(KC_P4)
#define LN_LM2 LCTL_T(KC_P5)
#define LN_LM1 LSFT_T(KC_P6)
#define LN_LM0 KC_PPLS
#define LN_RM0 SK_WORDPRV
#define LN_RM1 KC_LEFT
#define LN_RM2 KC_UP
#define LN_RM3 KC_DOWN
#define LN_RM4 KC_RIGHT

#define LN_LB4 KC_PCMM
#define LN_LB3 KC_P1
#define LN_LB2 KC_P2
#define LN_LB1 KC_P3
#define LN_LB0 KC_PEQL
#define LN_RB0 SK_UNDO
#define LN_RB1 SK_CUT
#define LN_RB2 SK_COPY
#define LN_RB3 SK_PSTE
#define LN_RB4 KC_SPC

#define LN_LH2 LCTL_T(KC_BSPC)
#define LN_LH1 LSFT_T(KC_ENT)
#define LN_RH1 KC_P0
#define LN_RH2 KC_PDOT

/*
  L_NAV THE NAVIGATION (right hand) LAYER w/ edit & mods on left.
   ╭──────────────────────────────────────────╮
╭───────────────────────────────────────────────╮
__ │   QUIT     CLOZ    SCAP    SCLP    PSTM  │                  │  DOCBEG HOME
UP      PGUP    PARAPRV   │ KC_NUM
__ │   LCTL     LALT    LGUI    LSFT    FIND  |                  |  WORDPRV LEFT
DOWN    RGHT    WORDNXT   │ __
__ │   UNDO     CUT     COPY    PSTE    FAGN  │ __  __    __  __ │  DOCEND END
DOWN    PGDN    PARANXT   │ __ ╰──────────────────╮  __   S(MENU)   MENU  │ __
__  │  HISTPRV  HISTNXT    __    ╭──────────────────╯ ZOOMRST ZOOMOUT
╰───────────────────────╯                  ╰────────────────────────────╯
HISTPRV HISTNXT
*/

#define LV_LT4 SK_QUIT
#define LV_LT3 SK_CLOZ
#define LV_LT2 SK_SCAP
#define LV_LT1 SK_SCLP
#define LV_LT0 SK_PSTM
#define LV_RT0 SK_DOCBEG
#define LV_RT1 KC_HOME
#define LV_RT2 KC_UP
#define LV_RT3 KC_PGUP
#define LV_RT4 SK_PARAPRV

#define LV_LM4 KC_LCTL
#define LV_LM3 KC_LALT
#define LV_LM2 KC_LGUI
#define LV_LM1 KC_LSFT
#define LV_LM0 SK_FIND
#define LV_RM0 SK_WORDPRV
#define LV_RM1 KC_LEFT
#define LV_RM2 KC_DOWN
#define LV_RM3 KC_RGHT
#define LV_RM4 SK_WORDNXT

#define LV_LB4 SK_UNDO
#define LV_LB3 SK_CUT
#define LV_LB2 SK_COPY
#define LV_LB1 SK_PSTE
#define LV_LB0 SK_FAGN
#define LV_RB0 SK_DOCEND
#define LV_RB1 KC_END
#define LV_RB2 KC_DOWN
#define LV_RB3 KC_PGDN
#define LV_RB4 SK_PARANXT

#define LV_LH2 S(KC_APP)    // APPMENU
#define LV_LH1 KC_APP	    // APPMENU
#define LV_RH1 SK_HISTPRV
#define LV_RH2 SK_HISTNXT

/*
  L_CFG Keyboard Configuration (left) and Media Settings (right).
	 ╭──────────────────────────────────────────╮
 ╭───────────────────────────────────────────────╮
      __ │  SK_Lux  SK_Win  SK_Mac  QK_RBT  SK_KILL │ │ (C(A(del)))KC_NUM
 KC_EJCT KC_NO   SK_ZOOMRST │ RGB_MOD RGB_VAI │  HD_AKTg L_0     L_1     KC_VOLU
 KC_BRIU |                            | KC_NO     KC_MPRV  KC_MUTE KC_MNXT
 SK_ZOOMOUT │ RGB_SAI RGB_HUI │  QK_BOOT AG_SWAP AG_NORM KC_VOLD KC_BRID │
 RGB_VAD  __    __  RGB_SAD │ KC_NO     KC_MRWD  KC_MPLY KC_MFFD SK_ZOOMIN  │
 RGB_HUD ╰──────────────────╮   __     __   EE_CLR  │ __                     __
 │   __       __       __     ╭──────────────────╯
		    __   __ ╰───────────────────────╯
 ╰────────────────────────────╯   __     __
*/

#define LC_LT4 SK_Lux
#define LC_LT3 SK_Win
#define LC_LT2 SK_Mac
#define LC_LT1 QK_RBT
#define LC_LT0 SK_KILL
#define LC_RT0 LCA(KC_DEL)
#define LC_RT1 KC_NUM
#define LC_RT2 KC_EJCT
#define LC_RT3 KC_NO
#define LC_RT4 SK_ZOOMRST

#define LC_LM4 HD_AdaptKeyToggle
#define LC_LM3 HD_L_QWERTY
#define LC_LM2 HD_L_ALPHA
#define LC_LM1 KC_VOLU
#define LC_LM0 KC_BRIU
#define LC_RM0 KC_NO
#define LC_RM1 KC_MPRV
#define LC_RM2 KC_MUTE
#define LC_RM3 KC_MNXT
#define LC_RM4 SK_ZOOMOUT

#define LC_LB4 QK_BOOT
#define LC_LB3 AG_SWAP
#define LC_LB2 AG_NORM
#define LC_LB1 KC_VOLD
#define LC_LB0 KC_BRID
#define LC_RB0 KC_NO
#define LC_RB1 KC_MRWD
#define LC_RB2 KC_MPLY
#define LC_RB3 KC_MFFD
#define LC_RB4 SK_ZOOMIN

#define LC_LH2 KC_VOLD
#define LC_LH1 KC_VOLU
#define LC_RH1 KC_NO
#define LC_RH2 KC_NO

#endif
