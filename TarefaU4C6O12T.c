#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"
#include "pico/binary_info.h"

#define BUTTON_A 5
#define BUTTON_B 6
#define LED_R 11
#define LED_G 12
#define LED_B 13
#define WS2812_PIN 7
#define I2C_SDA 14
#define I2C_SCL 15
#define UART_ID uart0
#define BAUD_RATE 115200

volatile bool led_green_state = true;
volatile bool led_blue_state = true;

void button_a_isr(uint gpio, uint32_t events) {
    led_green_state = !led_green_state;
    gpio_put(LED_G, led_green_state);
    printf("Botão A pressionado. LED Verde: %s\n", led_green_state ? "ON" : "OFF");
}

void button_b_isr(uint gpio, uint32_t events) {
    led_blue_state = !led_blue_state;
    gpio_put(LED_B, led_blue_state);
    printf("Botão B pressionado. LED Azul: %s\n", led_blue_state ? "ON" : "OFF");
}

void setup() {
    stdio_init_all();
    
    gpio_init(LED_R);
    gpio_init(LED_G);
    gpio_init(LED_B);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);
    
    gpio_init(BUTTON_A);
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_A);
    gpio_pull_up(BUTTON_B);
    
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &button_a_isr);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &button_b_isr);
    
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);
    
    printf("Sistema Inicializado.\n");
}

int main() {
    setup();
    while (1) {
        tight_loop_contents();
    }
    return 0;
}
