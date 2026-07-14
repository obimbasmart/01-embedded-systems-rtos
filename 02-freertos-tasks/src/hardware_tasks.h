#ifndef HARDWARE_TASKS_H
#define HARDWARE_TASKS_H

#include <Arduino.h>
#include "Servo.h"
#include <Arduino_FreeRTOS.h>
#include "queue.h"
#include "semphr.h"

struct hardware_pins_t {
    uint8_t pot_pin;
    uint8_t servo_pin;
    uint8_t led_pin;
    uint8_t ioctl_led_pins[3];
};

void task_servo_control(void *pv_params);
void task_blink_led(void *pv_params);
void task_blink_consecutive_leds(void *pv_params);

#endif // HARDWARE_TASKS_H
