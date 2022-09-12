/* For STM32F429 microcontroller */
static void LTDC_Clock_Init(void)
{
	RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

	/*
	 * Configures LTDC clock to 6.25MHz
	 */
	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
	PeriphClkInitStruct.PLLSAI.PLLSAIN = 50;
	PeriphClkInitStruct.PLLSAI.PLLSAIR = 2;
	PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_8;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
	{
	  Error_Handler();
	}
}