/**
 * @file XPT2046.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "XPT2046.h"
#include "stm32f4xx.h"
#include "tft.h"

#if USE_XPT2046

#include <stddef.h>
#include LV_DRV_INDEV_INCLUDE
#include LV_DRV_DELAY_INCLUDE

/*********************
 *      DEFINES
 *********************/
#define CMD_X_READ  0b10010000
#define CMD_Y_READ  0b11010000

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void xpt2046_corr(int16_t * x, int16_t * y);
static void xpt2046_avg(int16_t * x, int16_t * y);

/**********************
 *  STATIC VARIABLES
 **********************/
int16_t avg_buf_x[XPT2046_AVG];
int16_t avg_buf_y[XPT2046_AVG];
uint8_t avg_last;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
static SPI_HandleTypeDef hspi1;

#define XPT2046_SPI1_SCK_Pin 			GPIO_PIN_5
#define XPT2046_SPI1_SCK_GPIO_Port 		GPIOA
#define XPT2046_SPI1_MISO_Pin 			GPIO_PIN_6
#define XPT2046_SPI1_MISO_GPIO_Port 	GPIOA
#define XPT2046_SPI1_MOSI_Pin 			GPIO_PIN_7
#define XPT2046_PI1_MOSI_GPIO_Port 		GPIOA

uint8_t xpt2046_xchg_value(uint8_t val)
{
	uint8_t rcv_data;
	HAL_SPI_TransmitReceive(&hspi1, &val, &rcv_data, 1, HAL_MAX_DELAY);
	return rcv_data;
}

void xpt2046_cs(uint8_t val)
{
	if(val){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	}else{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	}
}


void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hspi->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspInit 0 */

  /* USER CODE END SPI1_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_SPI1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**SPI1 GPIO Configuration
    PA5     ------> SPI1_SCK
    PA6     ------> SPI1_MISO
    PA7     ------> SPI1_MOSI
    PA15     ------> SPI1_NSS
    */
    GPIO_InitStruct.Pin = XPT2046_SPI1_SCK_Pin|XPT2046_SPI1_MISO_Pin|XPT2046_SPI1_MOSI_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN SPI1_MspInit 1 */

  /* USER CODE END SPI1_MspInit 1 */
  }

}

static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_HARD_OUTPUT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    while(1);
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
 * Initialize the XPT2046
 */
void xpt2046_init(void)
{

    GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();


  /*Configure GPIO pin : PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	MX_SPI1_Init();

	LV_DRV_INDEV_SPI_CS(0);
	LV_DRV_INDEV_SPI_XCHG_BYTE(0x80);
	LV_DRV_INDEV_SPI_XCHG_BYTE(0);
	LV_DRV_INDEV_SPI_XCHG_BYTE(0);
	LV_DRV_INDEV_SPI_CS(1);
}


uint8_t xpt2046_irq_pin_read(void)
{
	return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);
}


/**
 * Get the current position and state of the touchpad
 * @param data store the read data here
 * @return false: because no ore data to be read
 */
void xpt2046_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static int16_t last_x = 0;
    static int16_t last_y = 0;
    uint8_t buf;

    int16_t x = 0;
    int16_t y = 0;

    uint8_t irq = LV_DRV_INDEV_IRQ_READ;

    if(irq == 0) {
        LV_DRV_INDEV_SPI_CS(0);

        LV_DRV_INDEV_SPI_XCHG_BYTE(CMD_X_READ);         /*Start x read*/

        buf = LV_DRV_INDEV_SPI_XCHG_BYTE(0);           /*Read x MSB*/
        x = buf << 8;
        buf = LV_DRV_INDEV_SPI_XCHG_BYTE(CMD_Y_READ);  /*Until x LSB converted y command can be sent*/
        x += buf;

        buf =  LV_DRV_INDEV_SPI_XCHG_BYTE(0);   /*Read y MSB*/
        y = buf << 8;

        buf =  LV_DRV_INDEV_SPI_XCHG_BYTE(0);   /*Read y LSB*/
        y += buf;

        /*Normalize Data*/
        x = x >> 3;
        y = y >> 3;
        xpt2046_corr(&x, &y);
       // touchpad_get_xy(&x, &y);
        xpt2046_avg(&x, &y);

        last_x = x;
        last_y = y;
		data->state = LV_INDEV_STATE_PR;

        LV_DRV_INDEV_SPI_CS(1);
    } else {
        x = last_x;
        y = last_y;
        avg_last = 0;
		data->state = LV_INDEV_STATE_REL;
    }

    data->point.x = x;
    data->point.y = y;

}


/**********************
 *   STATIC FUNCTIONS
 **********************/
static void xpt2046_corr(int16_t * x, int16_t * y)
{
#if XPT2046_XY_SWAP != 0
    int16_t swap_tmp;
    swap_tmp = *x;
    *x = *y;
    *y = swap_tmp;
#endif

    if((*x) > XPT2046_X_MIN)
    	(*x) -= XPT2046_X_MIN;
    else(*x) = 0;

    if((*y) > XPT2046_Y_MIN)
    	(*y) -= XPT2046_Y_MIN;
    else
    	(*y) = 0;

    (*x) = (uint32_t)((uint32_t)(*x) * XPT2046_HOR_RES) /
           (XPT2046_X_MAX - XPT2046_X_MIN);

    (*y) = (uint32_t)((uint32_t)(*y) * XPT2046_VER_RES) /
           (XPT2046_Y_MAX - XPT2046_Y_MIN);

#if XPT2046_X_INV != 0
    (*x) =  XPT2046_HOR_RES - (*x);
#endif

#if XPT2046_Y_INV != 0
    (*y) =  XPT2046_VER_RES - (*y);
#endif



}


static void xpt2046_avg(int16_t * x, int16_t * y)
{
    /*Shift out the oldest data*/
    uint8_t i;
    for(i = XPT2046_AVG - 1; i > 0 ; i--) {
        avg_buf_x[i] = avg_buf_x[i - 1];
        avg_buf_y[i] = avg_buf_y[i - 1];
    }

    /*Insert the new point*/
    avg_buf_x[0] = *x;
    avg_buf_y[0] = *y;
    if(avg_last < XPT2046_AVG) avg_last++;

    /*Sum the x and y coordinates*/
    int32_t x_sum = 0;
    int32_t y_sum = 0;
    for(i = 0; i < avg_last ; i++) {
        x_sum += avg_buf_x[i];
        y_sum += avg_buf_y[i];
    }

    /*Normalize the sums*/
    (*x) = (int32_t)x_sum / avg_last;
    (*y) = (int32_t)y_sum / avg_last;
}

#endif
