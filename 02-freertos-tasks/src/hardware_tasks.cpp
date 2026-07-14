#include "hardware_tasks.h"
#include "task.h"

void  task_blink_led(void *pv_params) {
    const auto* h_pins = static_cast<hardware_pins_t *> (pv_params);
    pinMode(h_pins->led_pin, OUTPUT);

    for (;;) {
        digitalWrite(h_pins->led_pin, HIGH);
        delay(1000);
        digitalWrite(h_pins->led_pin, LOW);
        delay(1000);
    }
}
void task_servo_control(void *pv_params) {
    const auto* h_pins = static_cast<hardware_pins_t *> (pv_params);

    Servo my_servo;
    my_servo.attach(h_pins->servo_pin);

    for (;;) {
        const int pot_value = analogRead(h_pins->pot_pin);
        const int angle = map(pot_value, 0, 1023, 0, 180);

        my_servo.write(angle);

        vTaskDelay(pdMS_TO_TICKS(20));
    }


}
void task_blink_consecutive_leds(void *pv_params) {
    const auto*  h_pins = static_cast<hardware_pins_t *> (pv_params);

    for (int i = 0; i < 3; i++) {
        pinMode(h_pins->ioctl_led_pins[i], OUTPUT);
        digitalWrite(h_pins->ioctl_led_pins[i], LOW);
    }

    int current_index = 0;

    for (;;) {
        digitalWrite(h_pins->ioctl_led_pins[current_index], LOW);
        current_index = (current_index + 1) % 3;
        digitalWrite(h_pins->ioctl_led_pins[current_index], HIGH);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
