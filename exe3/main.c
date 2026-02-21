#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN = 4;
const int LED_PIN2 = 6;
const int BTN_PIN = 28;
const int BTN_PIN2 = 26;
  

int main() {
  stdio_init_all();

  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  gpio_init(LED_PIN2);
  gpio_set_dir(LED_PIN2, GPIO_OUT);

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(BTN_PIN2);
  gpio_set_dir(BTN_PIN2, GPIO_IN);
  gpio_pull_up(BTN_PIN2);

  bool btn_state = true;
  bool btn_state2 = true;

  while (true) {

    bool current_btn_state = gpio_get(BTN_PIN);
    bool current_btn_state2 = gpio_get(BTN_PIN2);

    if (!current_btn_state && btn_state) {
      gpio_put(LED_PIN, !gpio_get(LED_PIN));
    } 
    if (!current_btn_state2 && btn_state2) {
      gpio_put(LED_PIN2, !gpio_get(LED_PIN2));
    }
    
    btn_state = current_btn_state;
    btn_state2 = current_btn_state2;
  }
}
