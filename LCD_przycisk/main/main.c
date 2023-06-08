/*
Naciśnięcie przycisku powoduje wyświetlenie komunikatu na LCD
Przycisk D19
LCD SCL
LCD SDA
*/

#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "esp_log.h"
#include "i2c-lcd1602.h"
#include "smbus.h"

//Definicje
#define TAG "app"

#define LCD_NUM_ROWS               2
#define LCD_NUM_COLUMNS            32
#define LCD_NUM_VISIBLE_COLUMNS    16

#define USE_STDIN  1

#define I2C_MASTER_NUM           I2C_NUM_0
#define I2C_MASTER_TX_BUF_LEN    0                     // disabled
#define I2C_MASTER_RX_BUF_LEN    0                     // disabled
#define I2C_MASTER_FREQ_HZ       100000
#define I2C_MASTER_SDA_IO        CONFIG_I2C_MASTER_SDA
#define I2C_MASTER_SCL_IO        CONFIG_I2C_MASTER_SCL

//Funkcje
void i2c_konfiguracja();
void i2c_init();
void lcd_konfiguracja();
void SMBus_init();
void lcd_wyswietl_znak(char znak);
void lcd_clear();
void lcd_kursor_poz(char kol, char wier);
void lcd_home();

void app_main(void)
{
    i2c_konfiguracja();
    i2c_init();
    SMBus_init();
    lcd_konfiguracja();

    char a = 'a';
    char b = 'b';

    lcd_wyswietl_znak(a);

    //Główna pętla programu
    while(1){
        
    }
}

/*
- wyświetlić napis
- napis, clear, delay, napis, ...
- przycisk, napis, delay, ...
*/

i2c_konfiguracja(){
    static void i2c_master_init(void)
{
    int i2c_master_port = I2C_MASTER_NUM;
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = I2C_MASTER_SDA_IO;
    conf.sda_pullup_en = GPIO_PULLUP_DISABLE;  // GY-2561 provides 10kΩ pullups
    conf.scl_io_num = I2C_MASTER_SCL_IO;
    conf.scl_pullup_en = GPIO_PULLUP_DISABLE;  // GY-2561 provides 10kΩ pullups
    conf.master.clk_speed = I2C_MASTER_FREQ_HZ;
    i2c_param_config(i2c_master_port, &conf);
    i2c_driver_install(i2c_master_port, conf.mode,
                       I2C_MASTER_RX_BUF_LEN,
                       I2C_MASTER_TX_BUF_LEN, 0);
}
}

i2c_init(){
    i2c_master_init();
    i2c_port_t i2c_num = I2C_MASTER_NUM;
    uint8_t address = CONFIG_LCD1602_I2C_ADDRESS;
}

lcd_konfiguracja(){
    //Włączanie LCD
    i2c_lcd1602_info_t * i2c_lcd1602_info = i2c_lcd1602_malloc();
    ESP_ERROR_CHECK(i2c_lcd1602_init(i2c_lcd1602_info, smbus_info, true,
                                     LCD_NUM_ROWS, LCD_NUM_COLUMNS, LCD_NUM_VISIBLE_COLUMNS));
    ESP_ERROR_CHECK(i2c_lcd1602_reset(i2c_lcd1602_info));

    //LCD clear
    i2c_lcd1602_clear(i2c_lcd1602_info);
    
    //Konfiguracja LCD
    i2c_lcd1602_set_backlight(i2c_lcd1602_info, true);      //Tło włączone
    i2c_lcd1602_set_display(i2c_lcd1602_info, true);        //Display włączony
    i2c_lcd1602_set_cursor(i2c_lcd1602_info, true);         //Kursor włączony
    i2c_lcd1602_move_cursor(i2c_lcd1602_info, 0, 0);        //Kursor na pozycji (0, 0)
    i2c_lcd1602_set_left_to_right(i2c_lcd1602_info);        //Kierunek przesuwania lewo - prawo
}

SMBus_init(){
    smbus_info_t * smbus_info = smbus_malloc();
    ESP_ERROR_CHECK(smbus_init(smbus_info, i2c_num, address));
    ESP_ERROR_CHECK(smbus_set_timeout(smbus_info, 1000));
}

lcd_wyswietl_znak(char znak){
    i2c_lcd1602_write_char(i2c_lcd1602_info, znak); 
}

lcd_clear(){
    i2c_lcd1602_clear(i2c_lcd1602_info);
}

lcd_kursor_poz(char kol, char wier){
    i2c_lcd1602_move_cursor(i2c_lcd1602_info, kol, wier);
}

lcd_home(){
    i2c_lcd1602_move_cursor(i2c_lcd1602_info, 0, 0);
}