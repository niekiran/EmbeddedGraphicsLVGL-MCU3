/*
 * bsp_lcd.c
 *
 *  Created on: 30-May-2022
 *      Author: nieki
 */


#include "bsp_lcd.h"

#define MADCTL_MY 0x80  ///< Bottom to top
#define MADCTL_MX 0x40  ///< Right to left
#define MADCTL_MV 0x20  ///< Reverse Mode
#define MADCTL_ML 0x10  ///< LCD refresh Bottom to top
#define MADCTL_RGB 0x00 ///< Red-Green-Blue pixel order
#define MADCTL_BGR 0x08 ///< Blue-Green-Red pixel order
#define MADCTL_MH 0x04  ///< LCD refresh right to left

 GPIO_TypeDef *ltdc_io_ports[] = {
		 LCD_DATA_R2_PORT,
		 LCD_DATA_R3_PORT,
		 LCD_DATA_R4_PORT,
		 LCD_DATA_R5_PORT,
		 LCD_DATA_R6_PORT,
		 LCD_DATA_R7_PORT,


		 LCD_DATA_G2_PORT,
		 LCD_DATA_G3_PORT,
		 LCD_DATA_G4_PORT,
		 LCD_DATA_G5_PORT,
		 LCD_DATA_G6_PORT,
		 LCD_DATA_G7_PORT,

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
		LCD_DATA_R2_PIN,
		LCD_DATA_R3_PIN,
		LCD_DATA_R4_PIN,
		LCD_DATA_R5_PIN,
		LCD_DATA_R6_PIN,
		LCD_DATA_R7_PIN,


		LCD_DATA_G2_PIN,
		LCD_DATA_G3_PIN,
		LCD_DATA_G4_PIN,
		LCD_DATA_G5_PIN,
		LCD_DATA_G6_PIN,
		LCD_DATA_G7_PIN,

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





#define LCD_RESX_HIGH()				REG_SET_BIT(LCD_RESX_PORT->ODR,LCD_RESX_PIN)
#define LCD_RESX_LOW()				REG_CLR_BIT(LCD_RESX_PORT->ODR,LCD_RESX_PIN)


#define LCD_CSX_HIGH()				REG_SET_BIT(LCD_CSX_PORT->ODR,LCD_CSX_PIN)
#define LCD_CSX_LOW()				REG_CLR_BIT(LCD_CSX_PORT->ODR,LCD_CSX_PIN)

#define LCD_DCX_HIGH()				REG_SET_BIT(LCD_DCX_PORT->ODR,LCD_DCX_PIN)
#define LCD_DCX_LOW()				REG_CLR_BIT(LCD_DCX_PORT->ODR,LCD_DCX_PIN)


void LCD_Pin_Init(void);
void LCD_SPI_Init(void);
void LCD_Reset(void);
void LCD_Config(void);
void LCD_Write_Cmd(uint8_t cmd);
void LCD_SPI_Enable(void);
void LCD_Write_Data(uint8_t *buffer,uint32_t len);

void BSP_LCD_Init(void)
{
	LCD_Pin_Init();
	LCD_SPI_Init();
	LCD_SPI_Enable();
	LCD_Reset();
	LCD_Config();
}




void BSP_LCD_Set_Orientation(int orientation)
{
	uint8_t params[4];

	if(orientation == LANDSCAPE){

		LCD_Write_Cmd(ILI9341_RASET); //page address set
		params[0]= 0x00;
		params[1]= 0x00;
		params[2]= 0x00;
		params[3]= 0xf0; //240 rows = 0xf0
		LCD_Write_Data(params, 4);

		LCD_Write_Cmd(ILI9341_CASET);
		params[0]= 0x00;
		params[1]= 0x00;
		params[2]= 0x01;
		params[3]= 0x40; //320 columns = 0x140
		LCD_Write_Data(params, 4);

		params[0] = MADCTL_MV | MADCTL_MY | MADCTL_BGR; /*Memory Access Control <Landscape setting>*/
	}else if(orientation == PORTRAIT){

		LCD_Write_Cmd(ILI9341_RASET); //page address set
		params[0]= 0x00;
		params[1]= 0x00;
		params[2]= 0x01;
		params[3]= 0x40; //320 rows = 0x140
		LCD_Write_Data(params, 4);

		LCD_Write_Cmd(ILI9341_CASET);
		params[0]= 0x00;
		params[1]= 0x00;
		params[2]= 0x00;
		params[3]= 0xf0; //240 columns = 0xf0
		LCD_Write_Data(params, 4);

		params[0] = MADCTL_MY| MADCTL_MX| MADCTL_BGR;  /* Memory Access Control <portrait setting> */
	}

	LCD_Write_Cmd(ILI9341_MAC);    // Memory Access Control command
	LCD_Write_Data(params, 1);
}


void LCD_Pin_Init(void)
{
	RCC_TypeDef *pRCC = RCC;
	GPIO_TypeDef *pGPIOA = GPIOA;
	GPIO_TypeDef *pGPIOC = GPIOC;
	GPIO_TypeDef *pGPIOD = GPIOD;
	GPIO_TypeDef *pGPIOF = GPIOF;

	/* Enable the clock for GPIOA,C,D,F peripherals */
	REG_SET_BIT(pRCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN_Pos);
	REG_SET_BIT(pRCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN_Pos);
	REG_SET_BIT(pRCC->AHB1ENR,RCC_AHB1ENR_GPIODEN_Pos);
	REG_SET_BIT(pRCC->AHB1ENR,RCC_AHB1ENR_GPIOFEN_Pos);

	//RESX
	REG_SET_VAL(pGPIOA->MODER,0x1U,0x3,(LCD_RESX_PIN * 2U)); 		/*mode*/
	REG_CLR_BIT(pGPIOA->OTYPER,LCD_RESX_PIN); 						/*Output type*/
	REG_SET_VAL(pGPIOA->OSPEEDR,2U,0x3U,(LCD_RESX_PIN * 2U)); 		/*speed*/


	//CSX
	REG_SET_VAL(pGPIOC->MODER,0x1U,0x3,(LCD_CSX_PIN * 2U)); 		/*mode*/
	REG_CLR_BIT(pGPIOC->OTYPER,LCD_CSX_PIN); 						/*Output type*/
	REG_SET_VAL(pGPIOC->OSPEEDR,2U,0x3U,(LCD_CSX_PIN * 2U)); 		/*speed*/

	//D/CX
	REG_SET_VAL(pGPIOD->MODER,0x1U,0x3,(LCD_DCX_PIN * 2U)); 		/*mode*/
	REG_CLR_BIT(pGPIOD->OTYPER,LCD_DCX_PIN); 					/*Output type*/
	REG_SET_VAL(pGPIOD->OSPEEDR,2U,0x3U,(LCD_DCX_PIN * 2U)); 		/*speed*/

	//SPI_CLK(PF7)
	REG_SET_VAL(pGPIOF->MODER,2U,0x3U,(LCD_SCL_PIN * 2U));
	REG_CLR_BIT(pGPIOF->OTYPER,LCD_SCL_PIN);
	REG_SET_VAL(pGPIOF->OSPEEDR,2U,0x3U,(LCD_SCL_PIN * 2U));
	REG_SET_VAL(pGPIOF->AFR[0],5U,0xFU,(LCD_SCL_PIN * 4U));

	//SPI_SDA(PF9)
	REG_SET_VAL(pGPIOF->MODER,2U,0x3U,(LCD_SDA_PIN * 2U));
	REG_CLR_BIT(pGPIOF->OTYPER,LCD_SDA_PIN);
	REG_SET_VAL(pGPIOF->OSPEEDR,2U,0x3U,(LCD_SDA_PIN * 2U));
	REG_SET_VAL(pGPIOF->AFR[1],5U,0xFU,((LCD_SDA_PIN % 8) * 4U));

	//CSX = HIGH
	REG_SET_BIT(pGPIOC->ODR,LCD_CSX_PIN);
	//RESX = HIGH
	REG_SET_BIT(pGPIOA->ODR,LCD_RESX_PIN);
	//D/CX = HIGH
	REG_SET_BIT(pGPIOD->ODR,LCD_DCX_PIN);

}


void LCD_SPI_Enable(void)
{
	SPI_TypeDef *pSPI = SPI;
	REG_SET_BIT(pSPI->CR1,SPI_CR1_SPE_Pos);
}

void LCD_SPI_Init(void)
{
	SPI_TypeDef *pSPI = SPI;
	RCC_TypeDef *pRCC = RCC;

	REG_SET_BIT(pRCC->APB2ENR,RCC_APB2ENR_SPI5EN_Pos);

	REG_SET_BIT(pSPI->CR1,SPI_CR1_MSTR_Pos); 		/*Controller mode*/
	REG_SET_BIT(pSPI->CR1,SPI_CR1_BIDIMODE_Pos);    /* BIDI mode enable*/
	REG_SET_BIT(pSPI->CR1,SPI_CR1_BIDIOE_Pos);      /* Tx only*/
	REG_SET_BIT(pSPI->CR1,SPI_CR1_BIDIOE_Pos);		/* Tx only */
	REG_CLR_BIT(pSPI->CR1,SPI_CR1_DFF_Pos);			/* DFF = 8bits */
	REG_SET_BIT(pSPI->CR1,SPI_CR1_SSM_Pos);			/* SSM enable */
	REG_SET_BIT(pSPI->CR1,SPI_CR1_SSI_Pos);			/* SSI enable */
	REG_CLR_BIT(pSPI->CR1,SPI_CR1_LSBFIRST_Pos);     /* Send msb first */
	REG_SET_VAL(pSPI->CR1,0x3U,0x7U,SPI_CR1_BR_Pos); /* SPI clck = 90MHz/16 ==> 5.625 MHz */
	REG_CLR_BIT(pSPI->CR1,SPI_CR1_CPOL_Pos); 		 /* CPOL = 0 */
	REG_CLR_BIT(pSPI->CR1,SPI_CR1_CPHA_Pos); 		 /* CPHA = 0 */
	REG_CLR_BIT(pSPI->CR2,SPI_CR2_FRF_Pos);			 /* SPI Motorola frame format*/

}

void delay_50ms(void){
	for(uint32_t i = 0 ; i<(0xFFFFU * 10U);i++);
}

void LCD_Reset(void)
{
	LCD_RESX_LOW();
	for(uint32_t i = 0 ; i<(0xFFFFU * 10U);i++);
	LCD_RESX_HIGH();
	for(uint32_t i = 0 ; i<(0xFFFFU * 10U);i++);
}


void LCD_Config(void)
{
	/* array to hold the command parameters*/
	uint8_t params[15] = {0};

	LCD_Write_Cmd(ILI9341_SWRESET);
	LCD_Write_Cmd(ILI9341_POWERB);
	params[0] = 0x00;
	params[1] = 0xD9;
	params[2] = 0x30;
	LCD_Write_Data(params, 3);

	LCD_Write_Cmd(ILI9341_POWER_SEQ);
	params[0]= 0x64;
	params[1]= 0x03;
	params[2]= 0X12;
	params[3]= 0X81;
	LCD_Write_Data(params, 4);

	LCD_Write_Cmd(ILI9341_DTCA);
	params[0]= 0x85;
	params[1]= 0x10;
	params[2]= 0x7A;
	LCD_Write_Data(params, 3);

	LCD_Write_Cmd(ILI9341_POWERA);
	params[0]= 0x39;
	params[1]= 0x2C;
	params[2]= 0x00;
	params[3]= 0x34;
	params[4]= 0x02;
	LCD_Write_Data(params, 5);

	LCD_Write_Cmd(ILI9341_PRC);
	params[0]= 0x20;
	LCD_Write_Data(params, 1);

	LCD_Write_Cmd(ILI9341_DTCB);
	params[0]= 0x00;
	params[1]= 0x00;
	LCD_Write_Data(params, 2);

	LCD_Write_Cmd(ILI9341_POWER1);
	params[0]= 0x1B;
	LCD_Write_Data(params, 1);

	LCD_Write_Cmd(ILI9341_POWER2);
	params[0]= 0x12;
	LCD_Write_Data(params, 1);

	LCD_Write_Cmd(ILI9341_VCOM1);
	params[0]= 0x08;
	params[1]= 0x26;
	LCD_Write_Data(params, 2);

	LCD_Write_Cmd(ILI9341_VCOM2);
	params[0]= 0XB7;
	LCD_Write_Data(params, 1);

	uint8_t m;
	m = MADCTL_MV | MADCTL_MY| MADCTL_BGR;

	LCD_Write_Cmd(ILI9341_MAC);    // Memory Access Control <Landscape setting>
	params[0]= m;
	LCD_Write_Data(params, 1);

	LCD_Write_Cmd(ILI9341_PIXEL_FORMAT);
	params[0]= 0x55; //select RGB565
	LCD_Write_Data(params, 1);

	LCD_Write_Cmd(ILI9341_FRMCTR1);
	params[0]= 0x00;
	params[1]= 0x1B;//frame rate = 70
	LCD_Write_Data(params, 2);

	LCD_Write_Cmd(ILI9341_DFC);    // Display Function Control
	params[0]= 0x0A;
	params[1]= 0xA2;
	LCD_Write_Data(params, 2);

	LCD_Write_Cmd(ILI9341_3GAMMA_EN);    // 3Gamma Function Disable
	params[0]= 0x02;
	LCD_Write_Data(params, 1);

	LCD_Write_Cmd(ILI9341_GAMMA);
	params[0]= 0x01;
	LCD_Write_Data(params, 1);

	LCD_Write_Cmd(ILI9341_PGAMMA);    //Set Gamma
	params[0]= 0x0F;
	params[1]= 0x1D;
	params[2]= 0x1A;
	params[3]= 0x0A;
	params[4]= 0x0D;
	params[5]= 0x07;
	params[6]= 0x49;
	params[7]= 0X66;
	params[8]= 0x3B;
	params[9]= 0x07;
	params[10]= 0x11;
	params[11]= 0x01;
	params[12]= 0x09;
	params[13]= 0x05;
	params[14]= 0x04;
	LCD_Write_Data(params, 15);

	LCD_Write_Cmd(ILI9341_NGAMMA);
	params[0]= 0x00;
	params[1]= 0x18;
	params[2]= 0x1D;
	params[3]= 0x02;
	params[4]= 0x0F;
	params[5]= 0x04;
	params[6]= 0x36;
	params[7]= 0x13;
	params[8]= 0x4C;
	params[9]= 0x07;
	params[10]= 0x13;
	params[11]= 0x0F;
	params[12]= 0x2E;
	params[13]= 0x2F;
	params[14]= 0x05;
	LCD_Write_Data(params, 15);

	LCD_Write_Cmd(ILI9341_RASET); //page address set
	params[0]= 0x00;
	params[1]= 0x00;
	params[2]= 0x00;
	params[3]= 0xf0; //240 rows = 0xf0
	LCD_Write_Data(params, 4);

	LCD_Write_Cmd(ILI9341_CASET);
	params[0]= 0x00;
	params[1]= 0x00;
	params[2]= 0x01;
	params[3]= 0x40; //320 columns = 0x140
	LCD_Write_Data(params, 4);

	LCD_Write_Cmd(ILI9341_RGB_INTERFACE);
	params[0] = 0xC2; //Data is fetched during falling edge of DOTCLK
	LCD_Write_Data(params, 1);

	LCD_Write_Cmd(ILI9341_INTERFACE);
	params[0] = 0x00;
	params[1] = 0x00;
	params[2] = 0x06;
	LCD_Write_Data(params, 3);

	LCD_Write_Cmd(ILI9341_SLEEP_OUT); //Exit Sleep
	delay_50ms();
	delay_50ms();
	LCD_Write_Cmd(ILI9341_DISPLAY_ON); //display on

}
void LCD_Write_Cmd(uint8_t cmd)
{
	SPI_TypeDef *pSPI = SPI;
	LCD_CSX_LOW();
	LCD_DCX_LOW(); //DCX = 0 , for command
	while(!REG_READ_BIT(pSPI->SR,SPI_SR_TXE_Pos));
	REG_WRITE(pSPI->DR,cmd);
	while(!REG_READ_BIT(pSPI->SR,SPI_SR_TXE_Pos));
	while(REG_READ_BIT(pSPI->SR,SPI_SR_BSY_Pos));
	LCD_DCX_HIGH();
	LCD_CSX_HIGH();

}

void LCD_Write_Data(uint8_t *buffer,uint32_t len)
{
	SPI_TypeDef *pSPI = SPI;
	for(uint32_t i = 0 ; i < len ;i++){
		LCD_CSX_LOW();
		while(!REG_READ_BIT(pSPI->SR,SPI_SR_TXE_Pos));
		REG_WRITE(pSPI->DR,buffer[i]);
		while(!REG_READ_BIT(pSPI->SR,SPI_SR_TXE_Pos));
		while(REG_READ_BIT(pSPI->SR,SPI_SR_BSY_Pos));
		LCD_CSX_HIGH();
	}
}
