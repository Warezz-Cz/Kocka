#include <stdbool.h>
#include <stm8s.h>
#include "main.h"
#include "milis.h"
//#include "delay.h"
//#include "uart1.h"
#include <stdio.h>
#include "daughterboard.h"

// Discovery Board
#ifdef STM8S003
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_0
#define BTN_PORT GPIOB
#define BTN_PIN  GPIO_PIN_7
#endif
// Dero Board
#ifdef STM8S103
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_4
#endif
// Discovery Board
#ifdef STM8S105
#define LED_PORT GPIOD
#define LED_PIN  GPIO_PIN_0
#endif
// Nucleo Kit
#ifdef STM8S208
#define LED_PORT GPIOC
#define LED_PIN  GPIO_PIN_5
#define BTN_PORT GPIOE
#define BTN_PIN  GPIO_PIN_4
#endif


void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    init_milis();
    //init_uart1();

    GPIO_Init(DB_LED1_PORT, DB_LED1_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(DB_LED2_PORT, DB_LED2_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(DB_LED4_PORT, DB_LED4_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(DB_LED5_PORT, DB_LED5_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(DB_LED6_PORT, DB_LED6_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(DB_LED7_PORT, DB_LED7_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(DB_LED8_PORT, DB_LED8_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    GPIO_Init(DB_S1_PORT, DB_S1_PIN, GPIO_MODE_IN_PU_NO_IT);

}

void show_num(uint8_t num) {
    /*
    * LED7 - A
    * LED5 - B
    * LED8 - C
    * LED6 - D
    * LED1 - E
    * LED4 - F
    * LED2 - G
    *   0001000 -- 1
    *   0010100 -- 2
    *   1001001 -- 3
    *   1010101 -- 4
    *   1011101 -- 5
    *   1110111 -- 6
    * ---------------
    *   ABCDEFG
    */

    uint8_t cube[6] = {
        0b0001000,//1
        0b0010100,//2
        0b1001001,//3
        0b1010101,//4
        0b1011101,//5
        0b1110111,//6
    };

    if (0b1000000 & cube[num])
        HIGH(DB_LED7);
    else
        LOW(DB_LED7);
    if (0b0100000 & cube[num])
        HIGH(DB_LED5);
    else
        LOW(DB_LED5);
    if (0b0010000 & cube[num])
        HIGH(DB_LED8);
    else
        LOW(DB_LED8);
    if (0b0001000 & cube[num])
        HIGH(DB_LED6);
    else
        LOW(DB_LED6);
    if (0b0000100 & cube[num])
        HIGH(DB_LED1);
    else
        LOW(DB_LED1);
    if (0b0000010 & cube[num])
        HIGH(DB_LED4);
    else
        LOW(DB_LED4);
    if (0b0000001 & cube[num])
        HIGH(DB_LED2);
    else
        LOW(DB_LED2);    

}

int main(void)
{
    uint32_t num = 0;
    uint8_t cube[6] = {
        0b00100000, //1
        0b10000001, //2
        0b01100010, //3
        0b11000011, //4
        0b11100011, //5
        0b11011011, //6
    };

    init();

    while (1) {
        if (PUSH(DB_S1)) {
            num++;
            GPIO_Write(GPIOG, 0b00000000); //všechno zhasnu
        } else {
            //GPIO_Write(GPIOG, cube[num % 6]);
            show_num(num % 6);
        }
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
