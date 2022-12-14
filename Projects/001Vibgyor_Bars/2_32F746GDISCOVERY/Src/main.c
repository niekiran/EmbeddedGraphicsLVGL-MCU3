/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "bsp_lcd.h"

#define RGB888(r,g,b)  (((r) << 16) | ((g) << 8) | (b))

#define VIOLET   	RGB888(148,0,211)
#define INDIGO   	RGB888(75,0,130)
#define BLUE   		RGB888(0,0,255)
#define GREEN   	RGB888(0,255,0)
#define YELLOW   	RGB888(255,255,0)
#define ORANGE   	RGB888(255,127,0)
#define RED   		RGB888(255,0,0)
#define WHITE   	RGB888(255,255,255)
#define BLACK		RGB888(0,0,0)

void SystemClock_Setup(void);
void LTDC_Pin_Init(void);
void LTDC_Init(void);
void LTDC_Layer_Init(LTDC_Layer_TypeDef *pLayer);
int main(void)
{
	SystemClock_Setup();
	LTDC_Pin_Init();
	LTDC_Init();
	LTDC_Layer_Init(LTDC_Layer1);
	bsp_lcd_set_fb_background_color(BLACK);
#if(BSP_LCD_ORIENTATION == LANDSCAPE)
	bsp_lcd_fill_rect(VIOLET, 0, BSP_LCD_ACTIVE_WIDTH-1, 38*0, 38);
	bsp_lcd_fill_rect(INDIGO, 0,  BSP_LCD_ACTIVE_WIDTH-1, 38*1, 38);
	bsp_lcd_fill_rect(BLUE,   0,  BSP_LCD_ACTIVE_WIDTH-1, 38*2, 38);
	bsp_lcd_fill_rect(GREEN,  0,  BSP_LCD_ACTIVE_WIDTH-1, 38*3, 38);
	bsp_lcd_fill_rect(YELLOW, 0,  BSP_LCD_ACTIVE_WIDTH-1, 38*4, 38);
	bsp_lcd_fill_rect(ORANGE, 0,  BSP_LCD_ACTIVE_WIDTH-1, 38*5, 38);
	bsp_lcd_fill_rect(RED, 	  0,  BSP_LCD_ACTIVE_WIDTH-1, 38*6, 38);
#elif(BSP_LCD_ORIENTATION == PORTRAIT)
	bsp_lcd_fill_rect(VIOLET, 0, BSP_LCD_ACTIVE_WIDTH-1, 68*0, 68);
	bsp_lcd_fill_rect(INDIGO, 0, BSP_LCD_ACTIVE_WIDTH-1, 68*1, 68);
	bsp_lcd_fill_rect(BLUE,   0, BSP_LCD_ACTIVE_WIDTH-1, 68*2, 68);
	bsp_lcd_fill_rect(GREEN,  0, BSP_LCD_ACTIVE_WIDTH-1, 68*3, 68);
	bsp_lcd_fill_rect(YELLOW, 0, BSP_LCD_ACTIVE_WIDTH-1, 68*4, 68);
	bsp_lcd_fill_rect(ORANGE, 0, BSP_LCD_ACTIVE_WIDTH-1, 68*5, 68);
	bsp_lcd_fill_rect(RED, 	  0, BSP_LCD_ACTIVE_WIDTH-1, 68*6, 68);
#endif
    /* Loop forever */
	for(;;);
}

void LTDC_Pin_Init(void)
{
	//enable the peripheral clock for GPIO ports involved in LTDC interface
	REG_SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOGEN_Pos);
	REG_SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOIEN_Pos);
	REG_SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOJEN_Pos);
	REG_SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOKEN_Pos);
	REG_SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOEEN_Pos);

	for(int i = 0 ; i < total_ltdc_pins ;i++){
		REG_SET_VAL(ltdc_io_ports[i]->MODER,2U,0x3U,(ltdc_pins[i] * 2U));
		REG_CLR_BIT(ltdc_io_ports[i]->OTYPER,ltdc_pins[i]);
		REG_SET_VAL(ltdc_io_ports[i]->OSPEEDR,2U,0x3U,(ltdc_pins[i] * 2U));
		if(ltdc_pins[i] < 8)
			REG_SET_VAL(ltdc_io_ports[i]->AFR[0],14U,0xFU,(ltdc_pins[i] * 4U));
		else
			REG_SET_VAL(ltdc_io_ports[i]->AFR[1],14U,0xFU,((ltdc_pins[i] % 8) * 4U));
	}

	 //LCD_DISP
	REG_SET_VAL(GPIOI->MODER,1,0x3,12*2);
	REG_CLR_BIT(GPIOI->OTYPER,12);
	REG_SET_VAL(GPIOI->OSPEEDR,1,0x3,12*2);
	REG_CLR_VAL(GPIOI->PUPDR,0x3,12*2);
	REG_SET_BIT(GPIOI->ODR,12);

	//LCD_BL
	REG_SET_VAL(GPIOK->MODER,1,0x3,3*2);
	REG_CLR_BIT(GPIOK->OTYPER,3);
	REG_SET_VAL(GPIOK->OSPEEDR,1,0x3,3*2);
	REG_CLR_VAL(GPIOK->PUPDR,0x3,3*2);
	REG_SET_BIT(GPIOK->ODR,3);
}

void LTDC_Init(void)
{
	LTDC_TypeDef *pLTDC = LTDC;

	REG_SET_BIT(RCC->APB2ENR,RCC_APB2ENR_LTDCEN_Pos);

	//Configure horizontal synchronization timings
	REG_SET_VAL(pLTDC->SSCR,(BSP_LCD_HSW-1),0xFFFU,LTDC_SSCR_HSW_Pos);
	REG_SET_VAL(pLTDC->BPCR,(BSP_LCD_HSW+BSP_LCD_HBP-1),0xFFFU,LTDC_BPCR_AHBP_Pos);
	REG_SET_VAL(pLTDC->AWCR,(BSP_LCD_HSW+BSP_LCD_HBP+BSP_LCD_ACTIVE_WIDTH-1),0xFFFU,LTDC_AWCR_AAW_Pos);
	uint32_t total_width = BSP_LCD_HSW+BSP_LCD_HBP+BSP_LCD_ACTIVE_WIDTH+BSP_LCD_HFP-1;
	REG_SET_VAL(pLTDC->TWCR,total_width,0xFFFU,LTDC_TWCR_TOTALW_Pos);

	//configure the vertical synchronization timings
	REG_SET_VAL(pLTDC->SSCR,(BSP_LCD_VSW-1),0x7FFU,LTDC_SSCR_VSH_Pos);
	REG_SET_VAL(pLTDC->BPCR,(BSP_LCD_VSW+BSP_LCD_VBP-1),0x7FFU,LTDC_BPCR_AVBP_Pos);
	REG_SET_VAL(pLTDC->AWCR,(BSP_LCD_VSW+BSP_LCD_VBP+BSP_LCD_ACTIVE_HEIGHT-1),0x7FFU,LTDC_AWCR_AAH_Pos);
	uint32_t total_height = BSP_LCD_VSW+BSP_LCD_VBP+BSP_LCD_ACTIVE_HEIGHT+BSP_LCD_VFP-1;
	REG_SET_VAL(pLTDC->TWCR,total_height,0x7FFU,LTDC_TWCR_TOTALH_Pos);

	//Configure the background color(BLUE)
	REG_SET_VAL(pLTDC->BCCR,0x0000FFU,0xFFFFFFU,LTDC_BCCR_BCBLUE_Pos);

	//default polarity for hsync, vsync, ltdc_clk, DE
	//TODO

	//enable the LTDC peripheral
	REG_SET_BIT(pLTDC->GCR,LTDC_GCR_LTDCEN_Pos);

}

void LTDC_Layer_Init(LTDC_Layer_TypeDef *pLayer)
{
	LTDC_TypeDef *pLTDC = LTDC;
	uint32_t tmp = 0;

	//1. configure the pixel format of the layer's framebuffer
	REG_SET_VAL(pLayer->PFCR,0x2U,0x7U,LTDC_LxPFCR_PF_Pos);

	//2. configure the constant alpha and blending factors
	REG_SET_VAL(pLayer->CACR,255U,0xFFU,LTDC_LxCACR_CONSTA_Pos);
	tmp = 0;
	REG_SET_VAL(tmp,0x4U,0x7U,LTDC_LxBFCR_BF1_Pos);
	REG_SET_VAL(tmp,0x5U,0x7U,LTDC_LxBFCR_BF2_Pos);
	REG_WRITE(pLayer->BFCR,tmp);


	//3. Configure layer position (Windowing)
	uint32_t AHBP =  REG_READ_VAL(pLTDC->BPCR,0xFFFU,LTDC_BPCR_AHBP_Pos);
	uint32_t WHSTART = AHBP+BSP_LTDC_LAYER_H_START +1;
	REG_SET_VAL(tmp,WHSTART,0xFFFU,LTDC_LxWHPCR_WHSTPOS_Pos);

	uint32_t WHSTOP = AHBP+BSP_LTDC_LAYER_H_START+BSP_LTDC_LAYER_WIDTH+1;
	uint32_t AAW =   REG_READ_VAL(pLTDC->AWCR,0xFFFU,LTDC_AWCR_AAW_Pos);
	WHSTOP = (WHSTOP > AAW)?AAW:WHSTOP;
	REG_SET_VAL(tmp,WHSTOP,0xFFFU,LTDC_LxWHPCR_WHSPPOS_Pos);

	REG_WRITE(pLayer->WHPCR,tmp);

	tmp = 0;
	uint32_t AVBP = REG_READ_VAL(pLTDC->BPCR,0x7FFU,LTDC_BPCR_AVBP_Pos);
	uint32_t WVSTART = AVBP+BSP_LTDC_LAYER_V_START+1;
	REG_SET_VAL(tmp,WVSTART,0x7FFU,LTDC_LxWVPCR_WVSTPOS_Pos);

	uint32_t AAH = REG_READ_VAL(pLTDC->AWCR,0x7FFU,LTDC_AWCR_AAH_Pos);
	uint32_t WVSTOP = AVBP+BSP_LTDC_LAYER_V_START+BSP_LTDC_LAYER_HEIGHT+1;
	WVSTOP = (WVSTOP > AAH)?AAH:WVSTOP;
	REG_SET_VAL(tmp,WVSTOP,0x7FFU,LTDC_LxWVPCR_WVSPPOS_Pos);

	REG_WRITE(pLayer->WVPCR,tmp);

	//4. Configure Frame buffer address
	REG_WRITE(pLayer->CFBAR,bsp_lcd_get_fb_address());

	//5. Configure the default color of the layer (optional)
	REG_WRITE(pLayer->DCCR,YELLOW);

	//6 . Configure pitch, line length and total lines of the frame buffer
	tmp = 0;
	uint32_t pitch =  BSP_LTDC_LAYER_WIDTH * 2;
	uint32_t line_len = pitch + 3;
	REG_SET_VAL(tmp,pitch,0x1FFFU,LTDC_LxCFBLR_CFBP_Pos);
	REG_SET_VAL(tmp,line_len,0x1FFFU,LTDC_LxCFBLR_CFBLL_Pos);
	REG_WRITE(pLayer->CFBLR,tmp);

	REG_SET_VAL(pLayer->CFBLNR,BSP_LTDC_LAYER_HEIGHT,0x7FFU,LTDC_LxCFBLNR_CFBLNBR_Pos);

	//7. Activate immediate reload
	REG_SET_BIT(LTDC->SRCR,LTDC_SRCR_IMR);

	//8. Enable the layer
	REG_SET_BIT(pLayer->CR,LTDC_LxCR_LEN_Pos);

}
void SystemClock_Setup(void)
{
	RCC_TypeDef *pRCC = RCC;
	FLASH_TypeDef *pFlash = FLASH;
	PWR_TypeDef *pPWR = PWR;

	//1. Program flash wait states
	REG_SET_VAL(pFlash->ACR,0x7U,0xFU,FLASH_ACR_LATENCY_Pos);

	//2. Over drive settings
	REG_SET_BIT(pRCC->APB1ENR,RCC_APB1ENR_PWREN_Pos); 	/*Enable clock for PWR register access*/
	REG_SET_VAL(pPWR->CR1,0x3,0x3,PWR_CR1_VOS_Pos); 		/*VOS = 0b11*/
	REG_SET_BIT(pPWR->CR1,PWR_CR1_ODEN_Pos);       		/* Activate over drive mode */
	while(! REG_READ_BIT(pPWR->CSR1,PWR_CSR1_ODRDY_Pos)); /* wait for overdrive ready*/
	REG_SET_BIT(pPWR->CR1,PWR_CR1_ODSWEN_Pos);     		/* Over drive switch enable*/

	//3. Setting up main PLL
	REG_SET_VAL(pRCC->PLLCFGR,0x8U,0x3FU,RCC_PLLCFGR_PLLM_Pos); /*PLL_M*/
	REG_SET_VAL(pRCC->PLLCFGR,216U,0x1FFU,RCC_PLLCFGR_PLLN_Pos); /*PLL_N*/
	REG_SET_VAL(pRCC->PLLCFGR,0x00U,0x3U,RCC_PLLCFGR_PLLP_Pos); /*PLL_P*/

	/////////////////This step is only required if you are using RGB interface ////////////
	//4. Setting up LCD_CLK using PLLSAI block
	REG_SET_VAL(pRCC->PLLSAICFGR,50U,0x1FFU,RCC_PLLSAICFGR_PLLSAIN_Pos); /*PLLSAI_N*/
	REG_SET_VAL(pRCC->PLLSAICFGR,0x02U,0x7U,RCC_PLLSAICFGR_PLLSAIR_Pos); /*PLLSAI_R*/
	REG_SET_VAL(pRCC->DCKCFGR1,0x00u,0x3U,RCC_DCKCFGR1_PLLSAIDIVR_Pos); /*DIV*/
	REG_SET_BIT(pRCC->CR,RCC_CR_PLLSAION_Pos);
	while(!REG_READ_BIT(pRCC->CR,RCC_CR_PLLSAIRDY_Pos));
	///////////////////////////////////////////////////////////////////////////////////////

	//5. Setting up AHB and APBx clocks
	REG_SET_VAL(pRCC->CFGR,0U,0xFU,RCC_CFGR_HPRE_Pos); /*AHB prescaler*/
	REG_SET_VAL(pRCC->CFGR,0x5U,0x7U,RCC_CFGR_PPRE1_Pos); /*APB1 prescaler*/
	REG_SET_VAL(pRCC->CFGR,0x4U,0x7U,RCC_CFGR_PPRE2_Pos); /*APB2 prescaler*/

	//6. Turn on PLL and wait for PLLCLK ready
	REG_SET_BIT(pRCC->CR,RCC_CR_PLLON_Pos);
	while(!REG_READ_BIT(pRCC->CR,RCC_CR_PLLRDY_Pos));

	//7. Switch PLLCLK as SYSCLK
	REG_SET_VAL(pRCC->CFGR,0x2U,0x3U,RCC_CFGR_SW_Pos);
	while(!(REG_READ_VAL(pRCC->CFGR,0x3U,RCC_CFGR_SWS_Pos) == 0x2U));

}










