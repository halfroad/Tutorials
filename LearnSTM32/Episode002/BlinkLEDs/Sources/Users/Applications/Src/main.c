/* Includes ------------------------------------------------------------------*/
#include <stm32h5xx.h>

#include "../../Applications/Inc/Miscellaneous.h"

#define GREEN_LED_GPIO_PORT  GPIOB
#define GREEN_LED_GPIO_PIN   GPIO_PIN_0

void SystemClock_Config(void);
void Error_Handler(void);

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    
    __HAL_RCC_GPIOB_CLK_ENABLE();
    
    GPIO_InitTypeDef GPIO_InitType = { 0 };
    
    GPIO_InitType.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitType.Pin = GREEN_LED_GPIO_PIN;
    
    HAL_GPIO_Init (GREEN_LED_GPIO_PORT, &GPIO_InitType);
    

    while (1)
    {
        HAL_GPIO_TogglePin(GREEN_LED_GPIO_PORT, GREEN_LED_GPIO_PIN);
        
        HAL_Delay(500);
    }
}