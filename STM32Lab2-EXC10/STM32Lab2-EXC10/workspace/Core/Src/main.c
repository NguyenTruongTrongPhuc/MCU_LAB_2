/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int num){
	switch(num){
		case 0:
			HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_SET ) ;
			break;
		case 1:
			HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_SET ) ;
			break;
		case 2:
			HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
			break;
		case 3:
			HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
			break;
		case 4:
			HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
			break;
		case 5:
			HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
			break;
		case 6:
			HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
			break;
		case 7:
			HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_SET ) ;
			break;
		case 8:
			HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
			break;
		case 9:
			HAL_GPIO_WritePin ( A_GPIO_Port , A_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( B_GPIO_Port , B_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( C_GPIO_Port , C_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( D_GPIO_Port , D_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( E_GPIO_Port , E_Pin , GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( F_GPIO_Port , F_Pin , GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( G_GPIO_Port , G_Pin , GPIO_PIN_RESET ) ;
			break;
		default:
			break;
	}
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  setTimer(0, 100);
  setTimer(1, 25);
  setTimer(2, 1);
  HAL_TIM_Base_Start_IT(&htim2);
const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1 , 2 , 3 , 4};
void update7SEG ( int index ) {
	display7SEG(led_buffer[index]);
	switch ( index ) {
		case 0:
			// Display the first 7 SEG with led_buffer [0]
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
			break ;
		case 1:
			// Display the second 7 SEG with led_buffer [1]
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
			break ;
		case 2:
			// Display the third 7 SEG with led_buffer [2]
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
			break ;
		case 3:
			// Display the forth 7 SEG with led_buffer [3]
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
			break ;
		default :
			break ;
	}
}
int hour = 15, minute = 8, second = 50;
void updateClockBuffer(){
	led_buffer[0] = hour/10;
	led_buffer[1] = hour%10;
	led_buffer[2] = minute/10;
	led_buffer[3] = minute%10;
}
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
int init_buffer = 0;
int current_buffer = 0;
uint8_t matrix_buffer [8] = {0x3F, 0x7F, 0xCC, 0xCC, 0x7F, 0x3F, 0x00, 0x00};
void setRow(uint8_t code){
	  if((code >> 0) & 0x01)
		  HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET);
	  if((code >> 1) & 0x01)
		  HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET);
	  if((code >> 2) & 0x01)
		  HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
	  if((code >> 3) & 0x01)
		  HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
	  if((code >> 4) & 0x01)
		  HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET);
	  if((code >> 5) & 0x01)
		  HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET);
	  if((code >> 6) & 0x01)
		  HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET);
	  if((code >> 7) & 0x01)
		  HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, RESET);
  }
void updateLEDMatrix (int index_led_matrix, int current_buffer) {
	if(current_buffer < 0) return;
	HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin|
							 ENM4_Pin|ENM5_Pin|ENM6_Pin|ENM7_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, ROW0_Pin|ROW1_Pin|ROW2_Pin|ROW3_Pin|
							 ROW4_Pin|ROW5_Pin|ROW6_Pin|ROW7_Pin, GPIO_PIN_SET);
	switch (current_buffer) {
		case 0:
			HAL_GPIO_WritePin(GPIOA, ENM0_Pin, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, ENM1_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, ENM2_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, ENM3_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOA, ENM4_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOA, ENM5_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOA, ENM6_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOA, ENM7_Pin, RESET);
			break;
		default :
			break;
	}
	setRow(matrix_buffer[index_led_matrix]);
}
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(timer_flag[0] == 1){
		  HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
		  HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
		  second++;
		  if(second >= 60){
			  second = 0;
			  minute++;
		  }
		  if(minute >= 60){
			  minute = 0;
			  hour++;
		  }
		  if(hour >= 24){
			  hour = 0;
		  }
		  updateClockBuffer();
		  setTimer(0, 100);
	  }
	  if(timer_flag[1] == 1){
		  update7SEG(index_led);
		  index_led++;
		  if(index_led > 3) index_led = 0;
		  setTimer(1, 25);
	  }
	  if(timer_flag[2] == 1){
		  updateLEDMatrix(index_led_matrix, current_buffer);
		  current_buffer++;
		  index_led_matrix++;
		  if(index_led_matrix >= MAX_LED_MATRIX){
//			  shift left
			  index_led_matrix = 0;
			  init_buffer--;
			  if(init_buffer == -8) init_buffer = 7;
			  current_buffer = init_buffer;
//			  shift right
//			  index_led_matrix = 0;
//			  init_buffer++;
//			  if(init_buffer == 8) init_buffer = -7;
//			  current_buffer = init_buffer;


	  	  }
		  setTimer(2, 1);
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 10;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN2_Pin|EN3_Pin|ENM2_Pin
                          |ENM3_Pin|ENM4_Pin|ENM5_Pin|ENM6_Pin
                          |ENM7_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|D_Pin|E_Pin|F_Pin
                          |G_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LED_RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A_Pin B_Pin C_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin D_Pin E_Pin F_Pin
                           G_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = A_Pin|B_Pin|C_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|D_Pin|E_Pin|F_Pin
                          |G_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	timerRun(0);
	timerRun(1);
	timerRun(2);
}
/* USER CODE END 4 */

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

#ifdef  USE_FULL_ASSERT
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
