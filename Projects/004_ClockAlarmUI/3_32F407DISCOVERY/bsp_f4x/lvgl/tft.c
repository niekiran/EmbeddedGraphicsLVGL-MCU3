/**
 * @file disp.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_conf.h"
#include "lvgl/lvgl.h"
#include <string.h>

#include "tft.h"
#include "stm32f4xx.h"
#include "bsp_lcd.h"


extern  bsp_lcd_t lcd_handle;

/*********************
 *      DEFINES
 *********************/


/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/*These 3 functions are needed by LittlevGL*/
static void tft_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_p);

/*LCD*/



static void Error_Handler(void);
/**********************
 *  STATIC VARIABLES
 **********************/


static lv_disp_drv_t disp_drv;

static int32_t x1_flush;
static int32_t y1_flush;
static int32_t x2_flush;
static int32_t y2_fill;
static int32_t y_fill_act;
static const lv_color_t * buf_to_flush;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

static volatile uint32_t t_saved = 0;
void monitor_cb(lv_disp_drv_t * d, uint32_t t, uint32_t p)
{
	t_saved = t;
}

/**
 * Initialize your display here
 */
void tft_init(void)
{
	//static lv_color_t disp_buf1[TFT_HOR_RES * 32];
	//static lv_color_t disp_buf2[TFT_HOR_RES * 32];
	static lv_disp_draw_buf_t buf;
	lv_color_t *draw_buf1;
	lv_color_t *draw_buf2;

	bsp_lcd_init();
	draw_buf1 = (lv_color_t*)bsp_lcd_get_draw_buffer1_addr();
	draw_buf2 = (lv_color_t*)bsp_lcd_get_draw_buffer2_addr();
	lv_disp_draw_buf_init(&buf,draw_buf1, draw_buf2, (10UL * 1024UL)/2);
	lv_disp_drv_init(&disp_drv);

	disp_drv.draw_buf = &buf;
	disp_drv.flush_cb = tft_flush;
	disp_drv.monitor_cb = monitor_cb;
	disp_drv.hor_res = TFT_HOR_RES;
	disp_drv.ver_res = TFT_VER_RES;
	disp_drv.sw_rotate = 1;
	disp_drv.user_data = (void*)&lcd_handle;
	lv_disp_drv_register(&disp_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Flush a color buffer
 * @param x1 left coordinate of the rectangle
 * @param x2 right coordinate of the rectangle
 * @param y1 top coordinate of the rectangle
 * @param y2 bottom coordinate of the rectangle
 * @param color_p pointer to an array of colors
 */
static void tft_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_p)
{
  if(area->x2 < 0 || area->y2 < 0 || area->x1 > (TFT_HOR_RES  - 1) || area->y1 > (TFT_VER_RES  - 1)) {
		lv_disp_flush_ready(drv);
		return;
	}

	bsp_lcd_t *hlcd = (bsp_lcd_t*)drv->user_data;

	/*Return if the area is out the screen*/
	if(area->x2 < 0) return;
	if(area->y2 < 0) return;
	if(area->x1 > TFT_HOR_RES - 1) return;
	if(area->y1 > TFT_VER_RES - 1) return;

	/*Truncate the area to the screen*/
	int32_t act_x1 = area->x1 < 0 ? 0 : area->x1;
	int32_t act_y1 = area->y1 < 0 ? 0 : area->y1;
	int32_t act_x2 = area->x2 > TFT_HOR_RES - 1 ? TFT_HOR_RES - 1 : area->x2;
	int32_t act_y2 = area->y2 > TFT_VER_RES - 1 ? TFT_VER_RES - 1 : area->y2;

	lv_coord_t w = (area->x2 - area->x1) + 1;

	bsp_lcd_set_display_area(act_x1,act_x2,act_y1,act_y2);
	uint32_t len = (act_x2 - act_x1 + 1) * 2ul;

#if USE_DMA
	x1_flush = act_x1;
	y1_flush = act_y1;
	x2_flush = act_x2;
	y2_fill = act_y2;
	y_fill_act = act_y1;
	buf_to_flush = color_p;
	  /*##-7- Start the DMA transfer using the interrupt mode #*/
	  /* Configure the source, destination and buffer size DMA fields and Start DMA Stream transfer */
	  /* Enable All the DMA interrupts */
	len = len * ((act_y2 - act_y1) + 1);
	bsp_lcd_send_cmd_mem_write();
	bsp_lcd_write_dma((uint32_t)buf_to_flush, len);
#else
	//bsp_lcd_write_dma((uint32_t)buf_to_flush,nbytes);
	 bsp_lcd_send_cmd_mem_write();
	for(uint32_t y = act_y1; y <= act_y2; y++) {
			bsp_lcd_write((uint8_t*)color_p,len);
	        color_p += w;
	    }

	lv_disp_flush_ready(&disp_drv);
#endif
}



/**
  * @brief  DMA conversion complete callback
  * @note   This function is executed when the transfer complete interrupt
  *         is generated
  * @retval None
  */
 void DMA_TransferComplete(bsp_lcd_t *hlcd)
{
	 lv_disp_flush_ready(&disp_drv);
#if 0
	y_fill_act ++;

	if(y_fill_act > y2_fill) {
		  lv_disp_flush_ready(&disp_drv);
	} else {
	  buf_to_flush += x2_flush - x1_flush + 1;
#if 0
	  /*##-7- Start the DMA transfer using the interrupt mode ####################*/
	  /* Configure the source, destination and buffer size DMA fields and Start DMA Stream transfer */
	  /* Enable All the DMA interrupts */
	  if(HAL_DMA_Start_IT(han,(uint32_t)buf_to_flush, (uint32_t)&my_fb[y_fill_act * TFT_HOR_RES + x1_flush],
						  (x2_flush - x1_flush + 1)) != HAL_OK)
	  {
	    while(1);	/*Halt on error*/
	  }
#endif
	  uint32_t nbytes = (x2_flush - x1_flush + 1) * 2UL;
	  bsp_lcd_write_dma((uint32_t)buf_to_flush,nbytes);
	}
#endif
}

/**
  * @brief  DMA conversion error callback
  * @note   This function is executed when the transfer error interrupt
  *         is generated during DMA transfer
  * @retval None
  */
 void DMA_TransferError(bsp_lcd_t *hlcd)
{

}



/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  while(1)
  {
  }
}
