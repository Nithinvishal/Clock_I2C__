#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "lcd_i2c.h"
#include "ds1307.h"

#define I2C_SDA 4
#define I2C_SCL 5

int main() {
    stdio_init_all();
    i2c_init(i2c0, 100 * 1000); // 100 kHz
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    lcd_init();
    ds1307_init();

    while (1) {
        uint8_t hour, minute, second;
        ds1307_get_time(&hour, &minute, &second);

        char buffer[17];
        snprintf(buffer, sizeof(buffer), "Time: %02d:%02d:%02d", hour, minute, second);

        lcd_clear();
        lcd_set_cursor(0, 0);
        lcd_print(buffer);

        sleep_ms(1000);
    }

    return 0;
}
