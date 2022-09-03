/*
 * bsp_lcd.c
 *
 *  Created on: 30-May-2022
 *      Author: nieki
 */


#include "bsp_lcd.h"


 GPIO_TypeDef *ltdc_io_ports[] = {
		 LCD_DATA_R0_PORT,
		 LCD_DATA_R1_PORT,
		 LCD_DATA_R2_PORT,
		 LCD_DATA_R3_PORT,
		 LCD_DATA_R4_PORT,
		 LCD_DATA_R5_PORT,
		 LCD_DATA_R6_PORT,
		 LCD_DATA_R7_PORT,

		 LCD_DATA_G0_PORT,
		 LCD_DATA_G1_PORT,
		 LCD_DATA_G2_PORT,
		 LCD_DATA_G3_PORT,
		 LCD_DATA_G4_PORT,
		 LCD_DATA_G5_PORT,
		 LCD_DATA_G6_PORT,
		 LCD_DATA_G7_PORT,

		 LCD_DATA_B0_PORT,
		 LCD_DATA_B1_PORT,
		 LCD_DATA_B2_PORT,
		 LCD_DATA_B3_PORT,
		 LCD_DATA_B4_PORT,
		 LCD_DATA_B5_PORT,
		 LCD_DATA_B6_PORT,
		 LCD_DATA_B7_PORT,

		 LCD_HSYNC_PORT,
		 LCD_VSYNC_PORT,
		 LCD_DE_PORT,
		 LCD_DOTCLK_PORT
};


const uint8_t ltdc_pins[] = {
		LCD_DATA_R0_PIN,
		LCD_DATA_R1_PIN,
		LCD_DATA_R2_PIN,
		LCD_DATA_R3_PIN,
		LCD_DATA_R4_PIN,
		LCD_DATA_R5_PIN,
		LCD_DATA_R6_PIN,
		LCD_DATA_R7_PIN,


		LCD_DATA_G0_PIN,
		LCD_DATA_G1_PIN,
		LCD_DATA_G2_PIN,
		LCD_DATA_G3_PIN,
		LCD_DATA_G4_PIN,
		LCD_DATA_G5_PIN,
		LCD_DATA_G6_PIN,
		LCD_DATA_G7_PIN,

		LCD_DATA_B0_PIN,
		LCD_DATA_B1_PIN,
		LCD_DATA_B2_PIN,
		LCD_DATA_B3_PIN,
		LCD_DATA_B4_PIN,
		LCD_DATA_B5_PIN,
		LCD_DATA_B6_PIN,
		LCD_DATA_B7_PIN,

		LCD_HSYNC_PIN,
		LCD_VSYNC_PIN,
		LCD_DE_PIN,
		LCD_DOTCLK_PIN
};

#define LCD_TOTAL_PINS  (sizeof(ltdc_pins)/sizeof(ltdc_pins[0]))

const uint8_t total_ltdc_pins = LCD_TOTAL_PINS;



void BSP_LCD_Init(void)
{

}



void delay_50ms(void){
	for(uint32_t i = 0 ; i<(0xFFFFU * 10U);i++);
}

void LCD_Reset(void)
{

}























