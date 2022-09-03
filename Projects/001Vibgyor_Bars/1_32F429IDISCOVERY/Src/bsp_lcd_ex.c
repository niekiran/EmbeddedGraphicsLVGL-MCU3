/*
 * bsp_lcd_ex.c
 *
 *  Created on: 06-Jun-2022
 *      Author: nieki
 */

#include "bsp_lcd.h"

#if BSP_LCD_PIXEL_FMT == BSP_LCD_PIXEL_FMT_RGB565
	#define FB_SIZE (BSP_FB_WIDTH * BSP_FB_HEIGHT * 2)
#elif BSP_LCD_PIXEL_FMT == BSP_LCD_PIXEL_FMT_RGB666
	#define FB_SIZE ((BSP_FB_WIDTH * BSP_FB_HEIGHT * 2) + ((BSP_FB_WIDTH * BSP_FB_HEIGHT *2)/8U)+1U)
#elif BSP_LCD_PIXEL_FMT == BSP_LCD_PIXEL_FMT_RGB888
	#define FB_SIZE (BSP_FB_WIDTH * BSP_FB_HEIGHT * 3)
#else
	#error"Select pixel format"
#endif

uint8_t bsp_fb[FB_SIZE];


uint32_t bsp_lcd_get_fb_address(void)
{
	return (uint32_t)&bsp_fb[0];
}



uint16_t Convert_RGB888_to_RGB565(uint32_t rgb888)
{
    uint16_t r,g,b;
	r = (rgb888 >> 19) & 0x1FU;
	g = (rgb888 >> 10) & 0x3FU;
	b = (rgb888 >> 3)  & 0x1FU;
	return (uint16_t)((r << 11) | (g << 5) | b);
}
/*
 * Disc: Writes given rgb565 value into the frame buffer
 * fb_ptr : valid frame buffer pointer
 * n_pixels : number of pixels to write
 * rgb565 : value of the pixel
 */
void write_to_fb_rgb565(uint16_t *fb_ptr,uint32_t n_pixels, uint16_t rgb565)
{
	while(n_pixels--){
		*fb_ptr = rgb565;
		 fb_ptr++;
	}
}

void write_to_fb_rgb888(uint32_t rgb888)
{
	//TODO
}

void write_to_fb_rgb666(uint32_t rgb666)
{
	//TODO
}

void bsp_lcd_set_fb_background_color(uint32_t rgb888)
{
#if(BSP_LCD_PIXEL_FMT == BSP_LCD_PIXEL_FMT_RGB565)
	write_to_fb_rgb565((uint16_t*)bsp_fb,(FB_SIZE/2U),Convert_RGB888_to_RGB565(rgb888));
#elif(BSP_LCD_PIXEL_FMT == BSP_LCD_PIXEL_FMT_RGB666)
	write_to_fb_rgb666(Convert_RGB888_to_RGB666(rgb888));
#elif(BSP_LCD_PIXEL_FMT == BSP_LCD_PIXEL_FMT_RGB888)
	write_to_fb_rgb888(rgb888);
#else
	#error"Select pixel format"
#endif
}



/*
 * Disc: Creates a rectangle and fills color
 * rgb888: Color value in RGB888 format
 * x_start : Horizontal start position of the rectangle ( 0 <= x_start < BSP_FB_WIDTH)
 * x_width : Width of the rectangle in number of pixels ( 1 <= x_width <= BSP_FB_WIDTH )
 * y_start : Vertical start position of the rectangle ( 0 <= y_start < BSP_FB_HEIGHT)
 * y_height : Height of the rectangle in number of pixels ( 1 <= y_height <= BSP_FB_HEIGHT )
 */
void bsp_lcd_fill_rect(uint32_t rgb888, uint32_t x_start, uint32_t x_width,uint32_t y_start,uint32_t y_height)
{
	void *fb_ptr;

	if((x_start+x_width) > BSP_FB_WIDTH) return;
	if((y_start+y_height) > BSP_FB_HEIGHT) return;

	while(y_height--){
#if(BSP_LCD_PIXEL_FMT == BSP_LCD_PIXEL_FMT_RGB565)
		 #define BYTES_PER_PIXEL 2
		 uint32_t fb_offset = (BSP_FB_WIDTH * BYTES_PER_PIXEL * y_start) + (x_start * BYTES_PER_PIXEL);
		 fb_ptr = (uint16_t*)&bsp_fb[fb_offset];
		 write_to_fb_rgb565(fb_ptr,x_width,Convert_RGB888_to_RGB565(rgb888));
#endif
		 y_start++;
	}
}
