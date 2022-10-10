/*
 * bsp_lcd.h
 *
 *  Created on: 30-May-2022
 *      Author: nieki
 */

#ifndef BSP_LCD_H_
#define BSP_LCD_H_

#include "arm_cm4.h"
#include "stm32f407xx.h"
#include "reg_util.h"
#include "ili9341_reg.h"
#include "board.h"



#define BSP_LCD_WIDTH  		240
#define BSP_LCD_HEIGHT 		320

#define BSP_LCD_HSW 		10
#define BSP_LCD_HBP			20
#define BSP_LCD_HFP			10
#define BSP_LCD_VSW			2
#define BSP_LCD_VBP			2
#define BSP_LCD_VFP			4


/*Select pixel format */
#define	BSP_LCD_PIXEL_FMT_L8 		1
#define	BSP_LCD_PIXEL_FMT_RGB565	2
#define BSP_LCD_PIXEL_FMT_RGB666    3
#define	BSP_LCD_PIXEL_FMT_RGB888	4
#define BSP_LCD_PIXEL_FMT 			BSP_LCD_PIXEL_FMT_RGB565


/*Select orientation*/
#define PORTRAIT  0
#define LANDSCAPE 1
#define BSP_LCD_ORIENTATION   PORTRAIT

#if(BSP_LCD_ORIENTATION == PORTRAIT)
	#define  BSP_LCD_ACTIVE_WIDTH 			BSP_LCD_WIDTH
	#define  BSP_LCD_ACTIVE_HEIGHT  		BSP_LCD_HEIGHT
#elif(BSP_LCD_ORIENTATION == LANDSCAPE)
	#define  BSP_LCD_ACTIVE_WIDTH 			BSP_LCD_HEIGHT
	#define  BSP_LCD_ACTIVE_HEIGHT 			BSP_LCD_WIDTH
#endif


#define AUTO				 1
#define MANUAL				 0
#define BSP_LCD_CS_MANAGE    MANUAL

#define USE_DMA 0

 typedef struct{
 	uint16_t x1;
 	uint16_t x2;
 	uint16_t y1;
 	uint16_t y2;
 }lcd_area_t;

 struct bsp_lcd;

 typedef void (*bsp_lcd_dma_cplt_cb_t)(struct bsp_lcd*);
 typedef void (*bsp_lcd_dma_err_cb_t)(struct bsp_lcd*);

 typedef struct{
 	uint8_t orientation;
 	uint8_t pixel_format;
 	uint8_t * draw_buffer1;
 	uint8_t * draw_buffer2;
 	uint32_t write_length;
 	uint8_t *buff_to_draw;
 	uint8_t *buff_to_flush;
 	lcd_area_t area;
 	bsp_lcd_dma_cplt_cb_t dma_cplt_cb;
 	bsp_lcd_dma_err_cb_t dma_err_cb;
 }bsp_lcd_t;





void bsp_lcd_init();
void bsp_lcd_set_orientation(int orientation);
void bsp_lcd_write(uint8_t *buffer, uint32_t nbytes);
void bsp_lcd_set_background_color(uint32_t rgb888);
void bsp_lcd_fill_rect(uint32_t rgb888, uint32_t x_start, uint32_t x_width,uint32_t y_start,uint32_t y_height);
void bsp_lcd_write_dma(uint32_t src_addr, uint32_t nbytes);
void bsp_lcd_set_display_area(uint16_t x1, uint16_t x2, uint16_t y1 , uint16_t y2);
void bsp_lcd_send_cmd_mem_write(void);
uint16_t bsp_lcd_convert_rgb888_to_rgb565(uint32_t rgb888);
void *bsp_lcd_get_draw_buffer1_addr(void);
void *bsp_lcd_get_draw_buffer2_addr(void);
#endif /* BSP_LCD_H_ */
