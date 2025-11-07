// #define CONF_1	// Small candle
// #define CONF_2	// Lively flame (fireplace or torch)
#define CONF_3	// Old light bulb (electrical flicker)
// #define CONF_4	// Embers / glowing charcoal
// #define CONF_5	// Campfire
// #define CONF_6	// Faulty neon lamp

#ifdef CONF_1
	#define UPDATE_INTERVAL_MS    30
	#define BASE_BRIGHTNESS_PERC  70
	#define FLICKER_DEPTH_PERC    25
	#define MIN_BRIGHTNESS_PERC   40
	#define MAX_BRIGHTNESS_PERC   90
	#define NOISE_SCALE           200
	#define RANDOM_SHIFT_MAX      8

#elif defined CONF_2
	#define UPDATE_INTERVAL_MS    20
	#define BASE_BRIGHTNESS_PERC  85
	#define FLICKER_DEPTH_PERC    45
	#define MIN_BRIGHTNESS_PERC   30
	#define MAX_BRIGHTNESS_PERC   100
	#define NOISE_SCALE           100
	#define RANDOM_SHIFT_MAX      20

#elif defined CONF_3
	#define UPDATE_INTERVAL_MS    15
	#define BASE_BRIGHTNESS_PERC  90
	#define FLICKER_DEPTH_PERC    15
	#define MIN_BRIGHTNESS_PERC   60
	#define MAX_BRIGHTNESS_PERC   100
	#define NOISE_SCALE           60
	#define RANDOM_SHIFT_MAX      25

#elif defined CONF_4
	#define UPDATE_INTERVAL_MS    50
	#define BASE_BRIGHTNESS_PERC  60
	#define FLICKER_DEPTH_PERC    30
	#define MIN_BRIGHTNESS_PERC   30
	#define MAX_BRIGHTNESS_PERC   80
	#define NOISE_SCALE           250
	#define RANDOM_SHIFT_MAX      6

#elif defined CONF_5
	#define UPDATE_INTERVAL_MS    25
	#define BASE_BRIGHTNESS_PERC  80
	#define FLICKER_DEPTH_PERC    40
	#define MIN_BRIGHTNESS_PERC   35
	#define MAX_BRIGHTNESS_PERC   100
	#define NOISE_SCALE           128
	#define RANDOM_SHIFT_MAX      16

#elif defined CONF_6
	#define UPDATE_INTERVAL_MS    10
	#define BASE_BRIGHTNESS_PERC  80
	#define FLICKER_DEPTH_PERC    60
	#define MIN_BRIGHTNESS_PERC   20
	#define MAX_BRIGHTNESS_PERC   100
	#define NOISE_SCALE           40
	#define RANDOM_SHIFT_MAX      30

#endif
