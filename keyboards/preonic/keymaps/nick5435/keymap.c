#include QMK_KEYBOARD_H
#include "muse.h"


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  BSPCDEL,
  ALIGN,
  ARRAY,
  DISPMATH,
  DCLICK,
  ENUMERATE,
  ITEM,
  ITEMIZE,
  LEFTRIGHT,
  LEMMA,
  LINEMATH,
  SECTION,
  THEOREM,
  PROBLEM,
  PROOF,
  NEW_SAFE_RANGE,
};

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Removed Itemize, KC_MUTE from layer 1 as they were getting in the way of some things.

#define KC_BSDEL BSPCDEL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_preonic_grid(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSDEL,
									KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
									KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
									KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_ENT,
									RGB_TOG, KC_LCTL, KC_LGUI, KC_LALT, MO(1), KC_SPC, KC_SPC, MO(2), KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT),
	[_LOWER] = LAYOUT_preonic_grid(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
								   KC_TRNS, ALIGN, ENUMERATE, PROOF, DISPMATH, THEOREM, LEMMA, PROBLEM, KC_NO, KC_LBRC, KC_RBRC, KC_TRNS,
								   KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_PSCR, KC_INS, KC_LBRC, KC_RBRC, KC_TRNS,
								   KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_MINS, KC_EQL, KC_VOLU, KC_TRNS,
								   KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_BSLS, KC_HOME, KC_VOLD, KC_END),
	[_RAISE] = LAYOUT_preonic_grid(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
								   KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
								   KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_TRNS,
								   KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MUTE, KC_NO, KC_NO, KC_PGUP, KC_TRNS,
								   KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_VOLD, KC_PGDN, KC_VOLU),
	[_ADJUST] = LAYOUT_preonic_grid(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
									KC_NO, RESET, DEBUG, KC_NO, KC_NO, KC_NO, KC_NO, TERM_ON, TERM_OFF, RGB_HUI, RGB_HUD, KC_NO,
									KC_EJCT, KC_NO, MU_MOD, AU_ON, AU_OFF, KC_NO, KC_NO, RGB_MOD, RGB_RMOD, RGB_SAI, RGB_SAD, KC_NO,
									KC_CAPS, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, RGB_SPI, RGB_SPD, RGB_VAI, RGB_VAD, KC_NO,
									KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO)
};


// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// [_QWERTY] = LAYOUT_preonic_1x2uC(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSDEL,
							// KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
							// KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
							// KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_ENT,
							// RGB_TOG, KC_LCTL, KC_LGUI, KC_LALT, MO(1), KC_SPC, MO(2), KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT),
	// [_LOWER] = LAYOUT_preonic_1x2uC(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
							// KC_TRNS, ALIGN, ENUMERATE, PROOF, DISPMATH, THEOREM, LEMMA, PROBLEM, KC_NO, KC_LBRC, KC_RBRC, KC_TRNS,
							// KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_PSCR, KC_INS, KC_LBRC, KC_RBRC, KC_TRNS,
							// KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_MINS, KC_EQL, KC_VOLU, KC_TRNS,
							// KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, KC_TRNS, KC_TRNS, MO(3), KC_BSLS, KC_HOME, KC_VOLD, KC_END),
	// [_RAISE] = LAYOUT_preonic_1x2uC(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
							// KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
							// KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_TRNS,
							// KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MUTE, KC_NO, KC_NO, KC_PGUP, KC_TRNS,
							// KC_TRNS, KC_TRNS, KC_TRNS, KC_APP, MO(3), KC_TRNS, KC_TRNS, KC_NO, KC_VOLD, KC_PGDN, KC_VOLU),
	// [_ADJUST] = LAYOUT_preonic_1x2uC(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
							// KC_NO, RESET, DEBUG, EEP_RST, KC_NO, KC_NO, KC_NO, TERM_ON, TERM_OFF, RGB_HUI, RGB_HUD, KC_NO,
							// KC_EJCT, KC_NO, MU_MOD, AU_ON, AU_OFF, KC_NO, KC_NO, RGB_MOD, RGB_RMOD, RGB_SAI, RGB_SAD, KC_NO,
							// KC_CAPS, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, RGB_SPI, RGB_SPD, RGB_VAI, RGB_VAD, KC_NO,
							// KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO)
// };


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	static uint8_t saved_mods   = 0;  switch (keycode) {
    case BSPCDEL:
            if (record->event.pressed) {
                saved_mods = get_mods() & MOD_MASK_SHIFT;

                if (saved_mods == MOD_MASK_SHIFT) {  // Both shifts pressed
                    register_code(KC_DEL);
                } else if (saved_mods) {   // One shift pressed
                    del_mods(saved_mods);  // Remove any Shifts present
                    register_code(KC_DEL);
                    add_mods(saved_mods);  // Add shifts again
                } else {
                    register_code(KC_BSPC);
                }
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
            }
            return false;
			break;
  // Latex specific keycodes
        case ALIGN:
            if (record->event.pressed) {
                SEND_STRING("\\begin{align*}" SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{align*}" SS_TAP(X_UP) SS_TAP(X_TAB));
            }
            break;
        case DISPMATH:
            if (record->event.pressed) {
                SEND_STRING("\\[\\]" SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_TAP(X_UP));
                tap_code(KC_TAB);
            }
            break;
        case ENUMERATE:
            if (record->event.pressed) {
                SEND_STRING("\\begin{enumerate}[]" SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{enumerate}" SS_TAP(X_UP) SS_TAP(X_TAB) "\\item ");
            }
            break;
        case ITEM:
            if (record->event.pressed) {
                SEND_STRING("\\item");
            }
            break;
        case ITEMIZE:
            if (record->event.pressed) {
                SEND_STRING("\\begin{itemize}"SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{itemize}" SS_TAP(X_UP) SS_TAP(X_TAB) "\\item ");
            }
            break;
        case LEMMA:
            if (record->event.pressed) {
                SEND_STRING("\\begin{xlem}[]"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"\\end{xlem}"SS_TAP(X_UP)SS_TAP(X_TAB));
            }
            break;
        case LINEMATH:
            if (record->event.pressed) {
                SEND_STRING("\\(\\)" SS_TAP(X_LEFT) SS_TAP(X_LEFT) "  " SS_TAP(X_LEFT));
            }
            break;
        case THEOREM:
            if (record->event.pressed) {
                SEND_STRING("\\begin{xthm}[]"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"\\end{xthm}"SS_TAP(X_UP)SS_TAP(X_TAB));
            }
            break;
		case PROBLEM:
            if (record->event.pressed) {
                SEND_STRING("\\begin{problem}"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"\\end{problem}"SS_TAP(X_UP)SS_TAP(X_TAB));
            }
            break;
		case PROOF:
            if (record->event.pressed) {
                SEND_STRING("\\begin{proof}[]"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"\\end{proof}"SS_TAP(X_UP)SS_TAP(X_TAB));
            }
            break;
    }
  return true;
}
