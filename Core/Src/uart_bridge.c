#include "main.h"

void reset_UART()
  {
	  HAL_GPIO_WritePin(UART_RESET__GPIO_Port, UART_RESET__Pin,0);
	  HAL_Delay(50);
	  HAL_GPIO_WritePin(UART_RESET__GPIO_Port, UART_RESET__Pin,1 );
  }



