#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"

extern keymap_config_t keymap_config;

enum custom_keycodes {
  M_AT = SAFE_RANGE,
  M_DOLLAR,
  M_PARENS,
  M_SQBRKT,
  M_CURLBT,
  M_CROCS,
  M_SQUOT,
  M_SHFUNC,
  M_EMAILD,
  M_FATARR,
  M_ACC_E,
  M_SEMCOL,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_AT:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("2"));
      }
      break;
    case M_DOLLAR:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT("4"));
      }
      break;
    case M_PARENS:
      if (record->event.pressed) {
        register_code(KC_LSFT);
        tap_code(KC_8);
        tap_code(KC_9);
        unregister_code(KC_LSFT);
        tap_code(KC_LEFT);
      }
      break;
    case M_SQBRKT:
      if (record->event.pressed) {
        register_code(KC_RALT);
        tap_code(KC_8);
        tap_code(KC_9);
        unregister_code(KC_RALT);
        tap_code(KC_LEFT);
      }
      break;
    case M_CURLBT:
      if (record->event.pressed) {
        register_code(KC_RALT);
        tap_code(KC_7);
        tap_code(KC_0);
        unregister_code(KC_RALT);
        tap_code(KC_LEFT);
      }
      break;
    case M_CROCS:
      if (record->event.pressed) {
        tap_code(NO_LESS);
        register_code(KC_LSFT);
        tap_code(NO_LESS);
        unregister_code(KC_LSFT);
        tap_code(KC_LEFT);
      }
      break;
    case M_SQUOT:
      if (record->event.pressed) {
        tap_code(NO_APOS);
        tap_code(NO_APOS);
        tap_code(KC_LEFT);
      }
      break;
    case M_SHFUNC:
      if (record->event.pressed) {
        register_code(KC_LSFT);
        tap_code(KC_8);
        tap_code(KC_9);
        unregister_code(KC_LSFT);
        tap_code(KC_SPC);
        register_code(KC_LSFT);
        tap_code(KC_0);
        tap_code(NO_LESS);
        unregister_code(KC_LSFT);
        tap_code(KC_SPC);
        register_code(KC_RALT);
        tap_code(KC_7);
        tap_code(KC_0);
        unregister_code(KC_RALT);
        tap_code(KC_LEFT);
      }
      break;
    case M_EMAILD:
      if (record->event.pressed) {
        register_code(KC_RALT);
        tap_code(KC_2);
        unregister_code(KC_RALT);
        SEND_STRING("olemartin.org");
      }
      break;
    case M_FATARR:
      if (record->event.pressed) {
        register_code(KC_LSFT);
        tap_code(KC_0);
        tap_code(NO_LESS);
        unregister_code(KC_LSFT);
      }
      break;
    case M_ACC_E:
      if (record->event.pressed) {
        register_code(KC_LSFT);
        tap_code(KC_0);
        tap_code(NO_LESS);
        unregister_code(KC_LSFT);
      }
      break;
    case M_SEMCOL:
      if (record->event.pressed) {
        register_code(KC_LSFT);
        tap_code(KC_COMM);
        unregister_code(KC_LSFT);
      }
      break;
  }
  return true;
};

// Shortcut to make keymap more readable
#define BAKSLH KC_BSLASH
#define SUPER  KC_LGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,NO_APOS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_TAB  ,                          XXXXXXX ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,NO_AA   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_DEL  ,                          KC_BSPC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,NO_OSLH ,NO_AE   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_HOME ,KC_END  ,        M_AT    ,KC_RALT ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,NO_MINS ,KC_RCTL ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     MO(2)   ,NO_LESS ,XXXXXXX ,XXXXXXX ,     KC_TAB  ,    MO(1)   ,SUPER   ,        KC_ENT  ,KC_SPC  ,    KC_TAB  ,     XXXXXXX ,NO_PLUS ,BAKSLH  ,NO_QUOT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     NO_PIPE ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_MPRV ,KC_MPLY ,KC_MNXT ,M_DOLLAR,M_SEMCOL,KC_F11  ,                          KC_F12  ,KC_PGUP ,KC_VOLD ,KC_UP   ,KC_VOLU ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,M_PARENS,M_SQBRKT,M_CURLBT,M_CROCS ,M_SQUOT ,_______ ,                          _______ ,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RIGHT,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,M_FATARR,M_SHFUNC,_______ ,_______ ,_______ ,        M_EMAILD,KC_PSCR ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,KC_KP_7 ,KC_KP_8 ,KC_KP_9 ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,KC_KP_4 ,KC_KP_5 ,KC_KP_6 ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,KC_KP_1 ,KC_KP_2 ,KC_KP_3 ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     KC_KP_0 ,KC_PDOT ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case 0:
            set_led_off;
            break;
        case 1:
            set_led_green;
            break;
        case 2:
            set_led_yellow;
            break;
        default:
            break;
    }
};
