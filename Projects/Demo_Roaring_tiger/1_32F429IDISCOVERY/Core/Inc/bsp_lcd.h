/*
 * bsp_lcd.h
 *
 *  Created on: 30-May-2022
 *      Author: nieki
 */

#ifndef BSP_LCD_H_
#define BSP_LCD_H_

#include"stm32f429xx.h"
#include "reg_util.h"
#include "ili9341_reg.h"
#include "board.h"

#define BSP_LCD_WIDTH  		240
#define BSP_LCD_HEIGHT 		320


/*Select orientation*/
#define PORTRAIT  0
#define LANDSCAPE 1
#define BSP_LCD_ORIENTATION   LANDSCAPE

#if(BSP_LCD_ORIENTATION == PORTRAIT)
	#define  BSP_LCD_ACTIVE_WIDTH 			BSP_LCD_WIDTH
	#define  BSP_LCD_ACTIVE_HEIGHT  		BSP_LCD_HEIGHT
#elif(BSP_LCD_ORIENTATION == LANDSCAPE)
	#define  BSP_LCD_ACTIVE_WIDTH 			BSP_LCD_HEIGHT
	#define  BSP_LCD_ACTIVE_HEIGHT 			BSP_LCD_WIDTH
#endif


/*Set layer width and height */
#define BSP_LTDC_LAYER_WIDTH				BSP_LCD_ACTIVE_WIDTH
#define BSP_LTDC_LAYER_HEIGHT				BSP_LCD_ACTIVE_HEIGHT
#define BSP_LTDC_LAYER_H_START				0
#define BSP_LTDC_LAYER_H_STOP				BSP_LCD_ACTIVE_WIDTH
#define BSP_LTDC_LAYER_V_START				0
#define BSP_LTDC_LAYER_V_STOP				BSP_LCD_ACTIVE_HEIGHT


/*Select pixel format */
#define	BSP_LCD_PIXEL_FMT_L8 		1
#define	BSP_LCD_PIXEL_FMT_RGB565	2
#define BSP_LCD_PIXEL_FMT_RGB666    3
#define	BSP_LCD_PIXEL_FMT_RGB888	4
#define BSP_LCD_PIXEL_FMT 			BSP_LCD_PIXEL_FMT_RGB565


#define BSP_LCD_HSW 		10
#define BSP_LCD_HBP			20
#define BSP_LCD_HFP			10
#define BSP_LCD_VSW			2
#define BSP_LCD_VBP			2
#define BSP_LCD_VFP			4

#define BSP_FB_WIDTH		BSP_LTDC_LAYER_WIDTH
#define BSP_FB_HEIGHT		BSP_LTDC_LAYER_HEIGHT

extern  GPIO_TypeDef *ltdc_io_ports[];
extern const uint8_t ltdc_pins[];
extern const uint8_t total_ltdc_pins;


void BSP_LCD_Init(void);
void BSP_LCD_Set_Orientation(int orientation);

#endif /* BSP_LCD_H_ */
