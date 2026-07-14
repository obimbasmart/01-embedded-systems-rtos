## FreeRTOS Tasks
Most basic Arduino programs rely entirely on the main loop() function. 
The code runs straight from top to bottom, over and over. This works f
.ine until you introduce something that takes time, like a delay. 
If you try to blink an LED using a standard delay(1000) statement
while also trying to read a potentiometer to spin a servo, your 
microcontroller completely freezes during that one-second delay.
Your servo becomes unresponsive and laggy because it has to wait
its turn in line. To build responsive machines, 
we need a way to run these operations at the same time.

-----------------------------

The goal of this project is to run three hardware operations completely in parallel 
without using any code-blocking loops:
- control a 9g servo 9g servo motor's angle based on a potentiometer input.
- blinking a single status LED at a fixed 1-second interval.
- blink-rotating through three separate LEDs consecutively in an infinite running pattern

------------------------------

### Notes
* **Tasks:** Splitting routines into concurrent loops via `xTaskCreate`.
* **vTaskDelay:** Using OS scheduler ticks to prevent CPU freezes.
* **Struct Injection:** Packaging pin maps into a single data type to kill
