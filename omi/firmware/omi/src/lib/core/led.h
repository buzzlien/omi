#ifndef LED_H
#define LED_H

#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

// LED color enum for PWM control
typedef enum {
    LED_RED,
    LED_GREEN,
    LED_BLUE
} led_color_t;

/**
 * @brief Initialize the LEDs
 *
 * Initializes the LEDs
 *
 * @return 0 if successful, negative errno code if error
 */
int led_start();
void set_led_red(bool on);
void set_led_green(bool on);
void set_led_blue(bool on);
void set_led_pwm(led_color_t color, uint8_t level);
void led_off(void);

/**
 * @brief Custom user-selected LED color (BLE-controlled), overriding the
 * automatic state-driven LED behavior (connection/charging/battery colors).
 *
 * When active, set_led_state() in main.c short-circuits to this color instead
 * of running its usual state machine. Not persisted across reboot — the
 * device returns to automatic LED behavior on power cycle.
 */
void set_led_custom_color(uint8_t r, uint8_t g, uint8_t b);
void clear_led_custom_color(void);
bool led_has_custom_color(void);
void get_led_custom_color(uint8_t *r, uint8_t *g, uint8_t *b);

#endif
