#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/timer.h"

//1 sekunda
#define TIMER_SCALE (TIMER_BASE_CLK / 16)

#define led GPIO_NUM_18
#define przycisk GPIO_NUM_19

bool stan = false;

bool przerwanie(void * arg)
{
  stan != stan;
  gpio_set_level(led, stan);
}

void gpio_config();
void timer_config();

void setup() {}

void loop() {
  gpio_config();
  timer_config();

  while(1){
    
  }
}

void gpio_config(){
  //Led
  gpio_set_direction(led, GPIO_MODE_OUTPUT);
  gpio_set_level(led, 0);

  //Przycisk
  gpio_set_direction(przycisk, GPIO_MODE_INPUT);
  gpio_pullup_en(przycisk);
}

void timer_config(){
  timer_config_t t_conf;
    t_conf.divider = 16;
    t_conf.counter_dir = TIMER_COUNT_UP;
    t_conf.counter_en = TIMER_PAUSE;
    t_conf.alarm_en = TIMER_ALARM_EN;
    t_conf.auto_reload = TIMER_AUTORELOAD_EN;

  timer_init(TIMER_GROUP_0, TIMER_0, &t_conf);
  timer_set_counter_value(TIMER_GROUP_0, TIMER_0, 0);
  timer_set_alarm_value(TIMER_GROUP_0, TIMER_0, TIMER_SCALE);
  timer_enable_intr(TIMER_GROUP_0, TIMER_0);
  timer_isr_callback_add(TIMER_GROUP_0, TIMER_0, przerwanie, NULL, 0);
  timer_start(TIMER_GROUP_0, TIMER_0);
}