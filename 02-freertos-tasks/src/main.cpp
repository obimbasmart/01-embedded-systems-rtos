#include "hardware_tasks.h"

hardware_pins_t h_pins =  {
    .pot_pin = A0,
    .servo_pin = 8,
    .led_pin = 7,
    .ioctl_led_pins = {2, 3,4}
};

void setup() {

    xTaskCreate(task_servo_control, "__servo__", 128, (void *)&h_pins, 2, nullptr);
    xTaskCreate(task_blink_led, "__blink__", 128, (void *)&h_pins, 1, nullptr);
    xTaskCreate(task_blink_consecutive_leds, "__cons_blinks__", 128, (void *)&h_pins, 3, nullptr);
}

void loop() {}

