#include <stdio.h>
#include <driver/gpio.h>
#include <freeRTOS/freeRTOS.h>
#include <freeRTOS/Task.h>

void app_main(void)
{
    // สร้างตัวแปรเพื่อเก็บสถานะของสวิตช์ และ LED
    int SW1_Status=0;
    int LED1_Status=0;
    int SW2_Status=0;
    int LED2_Status=0;

    //1. gpio_set_directoion pin 16 to Output
    gpio_set_direction(16, GPIO_MODE_OUTPUT);

    //2. gpio_set_directoion pin 15 to Iutput
    gpio_set_level(15, GPIO_MODE_INPUT);

    gpio_set_level(17, GPIO_MODE_INPUT);
    gpio_set_direction(18, GPIO_MODE_OUTPUT);

    while (1)
    {
        // Read level of gpio 15 และเก็บค่าไว้ที่ตัวแปร SW1_Status
        SW1_Status = gpio_get_level(15);
        SW2_Status = gpio_get_level(17);

        LED1_Status = !SW1_Status;
        LED2_Status = !SW2_Status;

        gpio_set_level(16, LED1_Status); 
        gpio_set_level(18, LED2_Status);

        // DELAY 1 second
        vTaskDelay(pdMS_TO_TICKS(100)); 
    }
    
}
