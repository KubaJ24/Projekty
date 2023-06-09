/*
Naciśnięcie przycisku neguje stan diody
Przycisk D18
Dioda D19
*/

#include <stdio.h>
#include <stdlib.h>

#include "driver/gpio.h"
#include "freertos/freeRTOS.h"
#include "freertos/task.h"

#define przycisk 18
#define led 19

void app_main(void)
{
    //Konfiguracja portów
    gpio_config_t io_conf;

    //Wyjście na led
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = 1<<19;
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);

    //Wejście
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = 1<<18;
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);

    //Początkowy stan diody - zgaszona
    gpio_set_level(led, 0);

    //Zmienna przechowująca stan diody
    char stan = 0;

    //Pętla główna programu
    while(1){
        if(gpio_get_level(przycisk) == 1) {
            stan = !stan;
        }
        gpio_set_level(led, stan);
        vTaskDelay(30);
    }
}
