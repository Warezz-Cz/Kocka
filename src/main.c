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


int main(void)
{
    uint8_t num = 0;
    uint8_t cube[6] = {
        0b00100000, //1
        0b10000001, //2
        
    };

    init();

    while (1) {
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
