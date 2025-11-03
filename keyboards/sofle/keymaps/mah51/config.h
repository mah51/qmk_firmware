#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
// #define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE
#define SPLIT_OLED_ENABLE true
#define SPLIT_WPM_ENABLE true
#define OLED_DRIVER_ENABLE true
#define FORCED_SYNC_THROTTLE_MS 100
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define OLED_TIMEOUT 0
#define OLED_BRIGHTNESS 120
#define MEDIA_KEY_DELAY 2
#define TAPPING_TOGGLE 3
