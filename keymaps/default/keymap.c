#include "kb.h"
#define CTL_DEL  CTL_T(KC_DEL)

//Definiciones RGB
#define  RGB_PLAN 	RGB_MODE_PLAIN
#define  RGB_BRTH 	RGB_MODE_BREATHE
#define  RGB_SWRL 	RGB_MODE_SWIRL
#define  RGB_GRAD 	RGB_MODE_GRADIENT
#define  RGB_RNBW 	RGB_MODE_RAINBOW
#define  RGB_XMAS 	RGB_MODE_XMAS
#define  RGB_SNAK 	RGB_MODE_SNAKE
#define  RGB_KNGT 	RGB_MODE_KNIGHT

#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_ESC, KC_B, KC_Y, KC_P, KC_E,
		KC_LSFT, LCTL(KC_Z), KC_V, KC_A, KC_Q, 
		CTL_DEL, KC_F5, KC_F6, KC_F7, 
		         MO(5), MO(2)),

	KEYMAP(
		____, KC_P, KC_C, KC_T, KC_S, 
		____, LCTL(KC_Z), ____, ____, ____, 
		____, ____, ____, ____, 
		      ____, ____),

	KEYMAP(
		____, KC_2, KC_HOME, KC_PGUP, ____, 
		____, KC_DEL, KC_END, KC_PGDN, ____, 
		____, ____, ____, ____, 
		      ____, ____),

	KEYMAP(
		____, KC_3, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, 
		      ____, ____),
 
	KEYMAP(
		RGB_TOG, RGB_BRTH, RGB_SWRL, RGB_SNAK, RGB_VAD, 
		RGB_VAI, RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD, 
		____, ____, ____, ____, 
		      ____, ____),

	KEYMAP(
		TO(0), TO(1), TO(2), TO(3), TO(4), 
		RESET, ____, ____, ____, ____, 
		____, KC_LEFT, KC_DOWN, KC_RGHT, 
		      ____, ____),

	KEYMAP(
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, 
		____, ____),

	KEYMAP(
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, 
		____, ____),

	KEYMAP(
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, 
		____, ____),

	KEYMAP(
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, 
		____, ____),

	KEYMAP(
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, 
		____, ____),

	KEYMAP(
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, 
		____, ____),

	KEYMAP(
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, 
		____, ____),

	KEYMAP(
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, 
		____, ____),

	KEYMAP(
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, 
		____, ____),

	KEYMAP(
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, ____, 
		____, ____, ____, ____, 
		____, ____)

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    } else if (index == 2) { /* Third encoder */
		if (IS_LAYER_ON(0)) {
			if (clockwise) {
				tap_code(KC_LEFT);
			} else {
				tap_code(KC_RIGHT);
			}
		} else if (IS_LAYER_ON(1)) {
			if (clockwise) {
				tap_code(KC_MINS);
			} else {
				tap_code(KC_PPLS);
			}
		}
    }
}

// Light LEDs 14 & 15 in cyan when keyboard layer 0 is active
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {14, 2, HSV_CYAN}
);

// Light LEDs 11 & 12 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_CYAN}
);
// Light LEDs 7 & 8 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 2, HSV_CYAN}
);
// Light LEDs 3 & 4 in purple when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_CYAN}
);
// Light LEDs 0 & 1 in purple when keyboard layer 4 is active
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_CYAN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	my_layer0_layer,
    my_layer1_layer,
	my_layer2_layer,
	my_layer3_layer,
	my_layer4_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
	rgblight_set_layer_state(2, layer_state_cmp(state, 2));
	rgblight_set_layer_state(3, layer_state_cmp(state, 3));
	rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    return state;
}