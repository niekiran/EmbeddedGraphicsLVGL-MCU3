
void ILI9341_CommandList(void){

	/* Use this command list with STM32F429 on-board LCD module which uses RGB interface */

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

	#define MADCTL_MY 0x80  ///< Bottom to top
	#define MADCTL_MX 0x40  ///< Right to left
	#define MADCTL_MV 0x20  ///< Reverse Mode
	#define MADCTL_ML 0x10  ///< LCD refresh Bottom to top
	#define MADCTL_RGB 0x00 ///< Red-Green-Blue pixel order
	#define MADCTL_BGR 0x08 ///< Blue-Green-Red pixel order
	#define MADCTL_MH 0x04  ///< LCD refresh right to left

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
	HAL_Delay(120);
	LCD_Write_Cmd(ILI9341_DISPLAY_ON); //display on
}
