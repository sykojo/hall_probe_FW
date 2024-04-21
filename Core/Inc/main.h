/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OE_Pin GPIO_PIN_4
#define OE_GPIO_Port GPIOC
#define SCLR_Pin GPIO_PIN_5
#define SCLR_GPIO_Port GPIOC
#define LED_MEASURING_Pin GPIO_PIN_2
#define LED_MEASURING_GPIO_Port GPIOB
#define LED_ERROR_Pin GPIO_PIN_10
#define LED_ERROR_GPIO_Port GPIOB
#define LED_STATUS_Pin GPIO_PIN_12
#define LED_STATUS_GPIO_Port GPIOB
#define SCK_SHREG_Pin GPIO_PIN_13
#define SCK_SHREG_GPIO_Port GPIOB
#define MISO_SHREG_Pin GPIO_PIN_14
#define MISO_SHREG_GPIO_Port GPIOB
#define MOSI_SHREG_Pin GPIO_PIN_15
#define MOSI_SHREG_GPIO_Port GPIOB
#define SEN_V_ENABLE_Pin GPIO_PIN_6
#define SEN_V_ENABLE_GPIO_Port GPIOC
#define NCTS_Pin GPIO_PIN_7
#define NCTS_GPIO_Port GPIOC
#define NRTS_Pin GPIO_PIN_8
#define NRTS_GPIO_Port GPIOC
#define UART_RESET__Pin GPIO_PIN_9
#define UART_RESET__GPIO_Port GPIOC
#define RI__Pin GPIO_PIN_12
#define RI__GPIO_Port GPIOA
#define BUTTON_Pin GPIO_PIN_8
#define BUTTON_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
