/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

#include "cmsis_gcc.h"
#include "stm32l476xx.h"

#include "../../App/Inc/UART_driver.h"

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  // USART com
  USARTHandler_t Com1Handler =
  {
    .USARTMap.USARTx = USART2,
    .GPIOPort = GPIOA,
    .USARTMap.DMAx = DMA1,
    .GPIO_Pin_RX = 2,
    .GPIO_Pin_TX = 3,
    .BaudRate = 115200,
};

  UART_init(&Com1Handler);
  SendString("Startup...\r\n", &Com1Handler);

  /* Infinite loop */
  while (1)
  {

  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
