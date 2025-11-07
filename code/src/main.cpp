#include <Arduino.h>
#include <conf.h>

#define RANDOM_SEED_AIN				A0
#define PWM_OUT								0

uint8_t map_perc_to_pwm(uint8_t perc);

uint32_t last_update_ms = 0;
int16_t noise_accumulator = 0;

uint8_t brightness_target;
uint8_t brightness_current;

void setup() {
	pinMode(PWM_OUT, OUTPUT);
	randomSeed(analogRead(RANDOM_SEED_AIN));
	brightness_current = map_perc_to_pwm(BASE_BRIGHTNESS_PERC);
}

void loop() {
	uint32_t now = millis();

	if(now - last_update_ms >= UPDATE_INTERVAL_MS){
		last_update_ms = now;

		noise_accumulator += random(-RANDOM_SHIFT_MAX, RANDOM_SHIFT_MAX + 1);
		noise_accumulator = constrain(noise_accumulator, -NOISE_SCALE, NOISE_SCALE);

		int16_t flicker = (noise_accumulator * FLICKER_DEPTH_PERC) / NOISE_SCALE;
		int16_t target_perc = BASE_BRIGHTNESS_PERC + flicker;
		target_perc = constrain(target_perc, MIN_BRIGHTNESS_PERC, MAX_BRIGHTNESS_PERC);
		brightness_target = map_perc_to_pwm(target_perc);

		if (brightness_current < brightness_target)
			brightness_current++;

		else if (brightness_current > brightness_target)
			brightness_current--;

		analogWrite(PWM_OUT, brightness_current);
	}
}

uint8_t map_perc_to_pwm(uint8_t perc){
	if(perc > 100)
		perc = 100;

	return (perc * 255u) / 100u;
}
