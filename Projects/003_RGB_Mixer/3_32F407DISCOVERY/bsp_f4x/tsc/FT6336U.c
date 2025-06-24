/**
 * @file FT6336U.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "FT6336U.h"
#include "stm32f4xx.h"
#include "tft.h"

#if USE_FT6336U

#include <stddef.h>
#include <string.h>
#include LV_DRV_INDEV_INCLUDE
#include LV_DRV_DELAY_INCLUDE

/*********************
 *      DEFINES
 *********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void ft6336u_corr(int16_t *x, int16_t *y);
static void ft6336u_avg(int16_t *x, int16_t *y);

/**********************
 *  STATIC VARIABLES
 **********************/
static I2C_HandleTypeDef hi2c1;
static ft6336u_handle_t hft6336u;
static int16_t avg_buf_x[FT6336U_AVG];
static int16_t avg_buf_y[FT6336U_AVG];
static uint8_t avg_last;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * I2C MSP Initialization
 */
/**
  * @brief I2C MSP Initialization
  * This function configures the hardware resources used in this example
  * @param hi2c: I2C handle pointer
  * @retval None
  */
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hi2c->Instance==I2C1)
  {
    /* USER CODE BEGIN I2C1_MspInit 0 */

    /* USER CODE END I2C1_MspInit 0 */

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**I2C1 GPIO Configuration
    PB6     ------> I2C1_SCL
    PB9     ------> I2C1_SDA
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Peripheral clock enable */
    __HAL_RCC_I2C1_CLK_ENABLE();
    /* USER CODE BEGIN I2C1_MspInit 1 */

    /* USER CODE END I2C1_MspInit 1 */

  }

}

/**
 * I2C MSP De-Initialization
 */
/**
  * @brief I2C MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param hi2c: I2C handle pointer
  * @retval None
  */
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c)
{
  if(hi2c->Instance==I2C1)
  {
    /* USER CODE BEGIN I2C1_MspDeInit 0 */

    /* USER CODE END I2C1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C1_CLK_DISABLE();

    /**I2C1 GPIO Configuration
    PB6     ------> I2C1_SCL
    PB9     ------> I2C1_SDA
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_9);

    /* USER CODE BEGIN I2C1_MspDeInit 1 */

    /* USER CODE END I2C1_MspDeInit 1 */
  }

}
/**
 * I2C1 Initialization
 */
static void MX_I2C1_Init(void)
{
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 400000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    if (HAL_I2C_Init(&hi2c1) != HAL_OK)
    {
        while (1);
    }
}

/**
 * Initialize the FT6336U
 */
void ft6336u_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /*Configure GPIO pin : PB7 */
    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Initialize I2C */
    MX_I2C1_Init();

    /* Initialize FT6336U */
    if (ft6336u_config(&hft6336u, &hi2c1, NULL, 0, GPIOB, GPIO_PIN_7) != HAL_OK)
    {
        while (1);
    }
}

/**
 * Read the IRQ pin state
 */
uint8_t ft6336u_irq_pin_read(void)
{
    uint8_t irq = 0;
    irq=  HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7);
    return irq;
}

/**
 * Write reg
 */
static HAL_StatusTypeDef ft6336u_write_reg(ft6336u_handle_t *hft, uint8_t reg, uint8_t value)
{
    return HAL_I2C_Mem_Write(hft->hi2c, FT6336U_I2C_ADDRESS << 1, reg, 1, &value, 1, HAL_MAX_DELAY);
}

/**
 * Initialize FT6336U hardware
 */
HAL_StatusTypeDef ft6336u_config(ft6336u_handle_t *hft, I2C_HandleTypeDef *hi2c,
                               GPIO_TypeDef *rst_port, uint16_t rst_pin,
                               GPIO_TypeDef *int_port, uint16_t int_pin)
{
    uint8_t chip_id;

    /* Initialize handle */
    hft->hi2c = hi2c;
    hft->rst_port = rst_port;
    hft->rst_pin = rst_pin;
    hft->int_port = int_port;
    hft->int_pin = int_pin;

    /* Perform hardware reset if reset pin is provided */
    if (hft->rst_port != NULL)
    {
        HAL_GPIO_WritePin(hft->rst_port, hft->rst_pin, GPIO_PIN_RESET);
        HAL_Delay(10);
        HAL_GPIO_WritePin(hft->rst_port, hft->rst_pin, GPIO_PIN_SET);
        HAL_Delay(50);
    }

    /* Check device presence by reading chip ID */
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(hft->hi2c, FT6336U_I2C_ADDRESS << 1,
                                                REG_ID_G_CIPHER_LOW, 1, &chip_id, 1, HAL_MAX_DELAY);
    if (status != HAL_OK || chip_id != CHIP_CODE_FT6336U)
    {
        return HAL_ERROR;
    }

    /* Set sampling rate */
    if (ft6336u_write_reg(hft, REG_PERIOD_ACTIVE, 0x06) != HAL_OK)
		return HAL_ERROR;

	/* Set touch sensitivity */
	if (ft6336u_write_reg(hft, REG_TH_GROUP, 0x28) != HAL_OK)
		return HAL_ERROR;

    /* Enable interrupt polling mode */
	if (ft6336u_write_reg(hft, REG_G_MODE, 0x00) != HAL_OK)
		return HAL_ERROR;

    /* Set to working mode */
	if (ft6336u_write_reg(hft, REG_MODE_SWITCH, 0x00) != HAL_OK)
		return HAL_ERROR;

	return HAL_OK;
}

/**
 * Read touch data from FT6336U
 */
HAL_StatusTypeDef ft6336u_read_touch(ft6336u_handle_t *hft, touch_point_t *points, uint8_t max_points)
{
    uint8_t buffer[12];
    uint8_t touch_count;

    /* Initialize points array */
    memset(points, 0, max_points * sizeof(touch_point_t));

    /* Read touch status */
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(hft->hi2c, FT6336U_I2C_ADDRESS << 1,
                                                REG_TD_STATUS, 1, buffer, 1, 100);
    if (status != HAL_OK)
    {
        return status;
    }

    touch_count = buffer[0] & 0x0F;
    if (touch_count == 0 || touch_count > max_points)
    {
        return HAL_OK;
    }

    /* Read touch data (up to 2 points, 6 bytes per point) */
    status = HAL_I2C_Mem_Read(hft->hi2c, FT6336U_I2C_ADDRESS << 1, REG_P1_XH, 1, buffer, touch_count * 6, 100);
    if (status != HAL_OK)
    {
        return status;
    }

    /* Parse touch points */
    for (uint8_t i = 0; i < touch_count; i++)
    {
        uint8_t offset = i * 6;
        points[i].x = ((buffer[offset] & 0x0F) << 8) | buffer[offset + 1];
        points[i].y = ((buffer[offset + 2] & 0x0F) << 8) | buffer[offset + 3];
        points[i].valid = 1;
    }

    return HAL_OK;
}

/**
 * Get the current position and state of the touchpad
 */
void ft6336u_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
	static int16_t last_x = 0;
	static int16_t last_y = 0;
	touch_point_t points[FT6336U_MAX_POINTS];

	/* Check if touch is detected (IRQ pin low) */
	uint8_t irq = ft6336u_irq_pin_read();

	if (irq == 0)
	{
		/* Read touch data */
		if (ft6336u_read_touch(&hft6336u, points, FT6336U_MAX_POINTS) == HAL_OK)
		{
			/* Use the first valid touch point */
			for (uint8_t i = 0; i < FT6336U_MAX_POINTS; i++)
			{
				if (points[i].valid)
				{
//					int16_t x = points[i].x;
//					int16_t y = points[i].y;
					int16_t x =  TFT_HOR_RES - (points[i].x + 20) ;
					int16_t y =  TFT_VER_RES - (points[i].y + 20) ;


					/* Apply coordinate correction */
					ft6336u_corr(&x, &y);
					ft6336u_avg(&x, &y);

					last_x = x;
					last_y = y;
					data->state = LV_INDEV_STATE_PR;
					data->point.x = x;
					data->point.y = y;
					return;
				}
			}
		}
		/* No valid points found */
		data->state = LV_INDEV_STATE_REL;
		data->point.x = last_x;
		data->point.y = last_y;
	}
	else
	{
		/* No touch detected */
		last_x = last_x;
		last_y = last_y;
		avg_last = 0;
		data->state = LV_INDEV_STATE_REL;
		data->point.x = last_x;
		data->point.y = last_y;
	}
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Correct touch coordinates
 */
static void ft6336u_corr(int16_t *x, int16_t *y)
{
#if FT6336U_XY_SWAP != 0
    int16_t swap_tmp = *x;
    *x = *y;
    *y = swap_tmp;
#endif

    if ((*x) > FT6336U_X_MIN)
        (*x) -= FT6336U_X_MIN;
    else
        (*x) = 0;

    if ((*y) > FT6336U_Y_MIN)
        (*y) -= FT6336U_Y_MIN;
    else
        (*y) = 0;

    (*x) = (uint32_t)((uint32_t)(*x) * FT6336U_HOR_RES) /
           (FT6336U_X_MAX - FT6336U_X_MIN);

    (*y) = (uint32_t)((uint32_t)(*y) * FT6336U_VER_RES) /
           (FT6336U_Y_MAX - FT6336U_Y_MIN);

#if FT6336U_X_INV != 0
    (*x) = FT6336U_HOR_RES - (*x);
#endif

#if FT6336U_Y_INV != 0
    (*y) = FT6336U_VER_RES - (*y);
#endif
}

/**
 * Average touch coordinates to reduce noise
 */
static void ft6336u_avg(int16_t *x, int16_t *y)
{
    /* Shift out the oldest data */
    uint8_t i;
    for (i = FT6336U_AVG - 1; i > 0; i--)
    {
        avg_buf_x[i] = avg_buf_x[i - 1];
        avg_buf_y[i] = avg_buf_y[i - 1];
    }

    /* Insert the new point */
    avg_buf_x[0] = *x;
    avg_buf_y[0] = *y;
    if (avg_last < FT6336U_AVG)
        avg_last++;

    /* Sum the x and y coordinates */
    int32_t x_sum = 0;
    int32_t y_sum = 0;
    for (i = 0; i < avg_last; i++)
    {
        x_sum += avg_buf_x[i];
        y_sum += avg_buf_y[i];
    }

    /* Normalize the sums */
    (*x) = (int32_t)x_sum / avg_last;
    (*y) = (int32_t)y_sum / avg_last;
}

#endif

