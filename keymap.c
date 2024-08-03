/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_spanish.h"
#define BT_CAPS LSFT_T(KC_CAPS)
enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    //	_NUMERICO,
};

// Custom keycodes for layer keys
// Dual function escape with left command

enum custom_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE, ADJUST, NUMERICO, MACRO1, MACRO2 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
        /*|-----------------------------------------------------|                    |-----------------------------------------------------|
               TAB,       Q,      	W,        E,      R,      T,                              Y,      U,       I,       O,       P,     BSPC,
       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               (CAP)SHIFT, A,     	S,        D,      F,      G,                              H,      J,       K,       L,       Ñ,      ´ ,
       //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               CNTRRL,     Z,       X,    		C,      V,      B,                              N,      M,        ,   ,   . ,      -,     ENTER,
       //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                                       WIN,    LOWER,     SPC,        SPC,     RAISE,	ALT
       //                                    |--------------------------|  |--------------------------|*/
        KC_TAB, ES_Q, ES_W, ES_E, ES_R, ES_T, ES_Y, ES_U, ES_I, ES_O, ES_P, KC_BSPC,
        BT_CAPS, ES_A, ES_S, ES_D, ES_F, ES_G, ES_H, ES_J, ES_K, ES_L, ES_NTIL, ES_ACUT,
        KC_LCTL, ES_Z, ES_X, ES_C, ES_V, ES_B, ES_N, ES_M, ES_COMM, ES_DOT, ES_MINS, KC_SFTENT,
        KC_LGUI, MO(1), KC_SPC, KC_SPC, MO(2), KC_RALT
        ),

    [_LOWER] = LAYOUT_split_3x6_3(
        /*
        //|-----------------------------------------------------|                    |-----------------------------------------------------|
                ESC,      1,      2,       3,       4,       5,                            6,       7,      8,       9,       0,      SUPR,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                F1,      F2,     F3,      F4,      F5,      F6,                          LEFT,    DOWN,      UP,    RGHT,     ^   ,    *   ,
        //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                F7,      F8,     F9,      F10,     F11,    F12,                        	{, 		    [, 		], 		},		 \, 	_______,
        //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              L_ALT,    LOWER,     SPC,        SPC,   RAISE,    R_ALT
        //                               	  |--------------------------|  |--------------------------|
        */

        KC_GESC, ES_1, ES_2, ES_3, ES_4, ES_5, ES_6, ES_7, ES_8, ES_9, ES_0, KC_DEL,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ES_CIRC, ES_ASTR,
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ES_LCBR, ES_LBRC, ES_RBRC, ES_RCBR, ES_BSLS, XXXXXXX,
        KC_LGUI, _______, KC_SPC, KC_ENT, MO(3), KC_RALT
        ),

    [_RAISE] = LAYOUT_split_3x6_3(

        /*|-----------------------------------------------------|                    |-----------------------------------------------------|
                    ª,     !,        "",       ·,       $,       %,                       		   &,       /,      (,       ),       =,     SUPR,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                _______, _______, _______, _______, VOL +,  _______,                       _______, _______, _______, _______,    |,     ,
        //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                CNTRR, 			>,	  _______, _______, VOL -,  _______,                          Ç,       +,       /,      	¿,       ?,    	 ª,
        //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                                        L_ALT,    LOWER,     SPC,        SPC,     RAISE, R_ALT
        //									 									|--------------------------|  |--------------------------|*/


        ES_MORD, ES_EXLM, ES_DQUO, ES_BULT, ES_DLR, ES_PERC, ES_AMPR, ES_SLSH, ES_LPRN, ES_RPRN, ES_EQL, KC_DEL,
        _______, _______, _______, _______, KC_VOLU, _______, _______, _______, _______, _______, ES_PIPE, ES_ACUT,
        KC_RCTL, ES_RABK, _______, _______, KC_VOLD, KC_MUTE, ES_CCED, ES_PLUS, ES_SLSH, ES_IQUE, ES_QUES, ES_FORD,
        KC_LALT, MO(3), KC_SPC, KC_ENT, _______, KC_RALT
        ),

    [_ADJUST] = LAYOUT_split_3x6_3(
        /*|-----------------------------------------------------|                    |-----------------------------------------------------|
                _______, _______, _______, _______, _______,RGB ON/OFF,                    _______, _______, _______, _______, _______,KC_POWER,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                RGB_TOG, RGB_HUI,RGB SAT+, RGB_VAI, _______, RGB_MOD,                      _______, _______, _______, _______, _______,  RESET,
        //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                RGB_MOD, RGB_HUD,RGB SAT-, RGB_VAD, _______,RGB_RMOD,					   _______, _______, _______, _______, _______, _______,
        //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                                        WIN,    LOWER,     SPC,        SPC,     RAISE, 	RALT
        //									  								|--------------------------|  |--------------------------|*/

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_POWER,
        XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        MO(4), KC_TRNS, KC_SPC, KC_SPC, KC_TRNS, KC_RALT
        )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

/*int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
    if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
        layer_on(layer3);
    } else {
        layer_off(layer3);
    }
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
#endif
}
*/
void rgb_matrix_indicators_user(void)  // Hace que cambie de color dependiendo del nivel en el que este.
{
#ifdef RGB_MATRIX_ENABLE
    switch (biton32(layer_state)) {
        case _RAISE:
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
                rgb_matrix_set_color(i, 255, 0, 0);  // rojo
            }
            break;

        case _LOWER:
            for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
                rgb_matrix_set_color(i, 0, 0, 255);  // azul
            }
            break;
        default:
            if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
                for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
                    rgb_matrix_set_color(i, 0, 255, 0);  // verde
                }
            }
            break;
    }
#endif
}