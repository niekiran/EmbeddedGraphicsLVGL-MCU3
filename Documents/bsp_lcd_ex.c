/*
 * bsp_lcd_ex.c
 *
 *  Created on: 06-Jun-2022
 *      Author: nieki
 */

#include "bsp_lcd.h"

#if BSP_LCD_PIXEL_FMT == BSP_LCD_PIXEL_FMT_L8
	#define FB_SIZE (BSP_LCD_WIDTH * BSP_LCD_HEIGHT * 1)
#elif BSP_LCD_PIXEL_FMT == BSP_LCD_PIXEL_FMT_RGB565
	#define FB_SIZE (BSP_LCD_WIDTH * BSP_LCD_HEIGHT * 2)
#elif BSP_LCD_PIXEL_FMT == BSP_LCD_PIXEL_FMT_RGB666
	#define FB_SIZE ((BSP_LCD_WIDTH * BSP_LCD_HEIGHT * 2) + 19200UL)
#elif BSP_LCD_PIXEL_FMT == BSP_LCD_PIXEL_FMT_RGB888
	#define FB_SIZE (BSP_LCD_WIDTH * BSP_LCD_HEIGHT * 3)
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




#if 0
void bsp_lcd_set_fb_background_color_rgb666(uint32_t color_24bit)
{
	uint32_t rgb666 = convert_RGB888_to_RGB666(color_24bit);
	for(uint32_t i = 0 ; i < FB_SIZE ;){
		buf[0] = ask8[x];
		buf[1] = ask8[x];
		buf[2] = ask2(x); //x over 6 left ALIGN_R_2(ask2(x))
		buf[2+3] = ask14(x1); //buf[3] = ALIGN_L_6(ask6(ask14(x1))) , buf[4] = ask8(ask14(x1))
		buf[4] = ask4(x1); //x1 over align_r_4(ask4(x1))
		buf[4 + 5] = ask12(x2); //buf[5] = align_l_4(ask4(ask12(x2))) , buf[6] = ask8(ask12(x2))
		buf[6] = ask6(x2);//x2over , space 2 left
		buf[6+7] = ask10(x3);// buf[2] = ask2(ask10(x3) , buf[8] = ask8(ask10(x3)
		buf[8]= ask8(x3)//x3 over
	}
}
#endif


void bsp_lcd_fill_rect(uint32_t rgb888, uint32_t x_start, uint32_t x_width,uint32_t y_start,uint32_t y_width)
{
	void *fb_ptr;

	if((x_start+x_width) > BSP_LCD_ACTIVE_WIDTH) return;
	if((y_start+y_width) > BSP_LCD_ACTIVE_HEIGHT) return;

	while(y_width--){
#if(BSP_LCD_PIXEL_FMT == BSP_LCD_PIXEL_FMT_RGB565)
		 uint8_t bytes_per_pixel = 2;
		 uint32_t fb_offset = (BSP_LCD_ACTIVE_WIDTH * bytes_per_pixel * y_start) + (x_start * bytes_per_pixel);
		 fb_ptr = (uint16_t*)&bsp_fb[fb_offset];
		 write_to_fb_rgb565(fb_ptr,x_width,Convert_RGB888_to_RGB565(rgb888));
#endif
		 y_start++;
	}
}
