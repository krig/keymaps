/*
 * Kristoffer Gronlund, 2023
 */
#pragma once

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_KNIGHT
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_DEFAULT_HUE 222 // rose


#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(MINOR_SOUND)
#endif
