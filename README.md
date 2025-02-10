# TarefaU4C6O12T
## Descrição

Este projeto implementa a comunicação serial (UART e I2C) no Raspberry Pi Pico W, utilizando:

Display SSD1306 via I2C

Matriz de LEDs WS2812

LED RGB (GPIOs 11, 12 e 13)

Botões com interrupções e debounce (GPIOs 5 e 6)

O código foi desenvolvido em C e pode ser compilado usando o SDK do RP2040.

## Funcionalidades

Display SSD1306

Exibe mensagens enviadas pela UART

Indica o estado dos LEDs

Botões com Interrupções

Pressionar o Botão A alterna o LED verde e atualiza o display

Pressionar o Botão B alterna o LED azul e atualiza o display

Matriz WS2812

Exibe números recebidos via UART

Comunicação UART

Permite entrada de caracteres via Serial Monitor do VSCode
