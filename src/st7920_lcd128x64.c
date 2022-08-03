/*=====[Module Name]===========================================================
 * Copyright YYYY Author Compelte Name <author@mail.com>
 * All rights reserved.
 * License: license text or at least name and link 
         (example: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Creation Date: YYYY/MM/DD
 */

/*=====[Inclusion of own header]=============================================*/

#include "st7920_lcd128x64.h"
#include "spi.h"
#include "sapi.h"

/*Driver para display de 128x64 que tiene el controlador
 * ST 7920
-------CONEXIONES CON EDU-CIAA------
  lcd pin          lcd pin name   edu-ciaa
   #1                  GND         GND
   #2                  VCC         VCC (5V)
   #3                  NC
   #4                  RS         GPIO1
   #5                  R/W        SPI_MOSI
   #6                  E          SPI_SCK (CLOCK)
   #15                 PSB        GND(0V) PARA MODO EN SPI
   #19                 BLA        VCC
   #20                 BLK        GND
 */



/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/



/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

uint8_t scrWd = 128/8;
uint8_t scrHt = 64;
uint8_t scr[SCR_WD*SCR_HT/8];
/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/




void st7920_lcd128x64_init(void){


	gpioConfig(GPIO0,GPIO_OUTPUT);
	spiInit( SPI0);                           //Inicializo SPi

	st7920_lcd128x64_sendcmd (LCD_BASIC);
	delay(1);

	st7920_lcd128x64_sendcmd (LCD_BASIC);
	delay(1);

	st7920_lcd128x64_sendcmd (LCD_DISPLAYOFFST);
	delay(1);
	st7920_lcd128x64_sendcmd (LCD_CLS );
	delay(2);
	st7920_lcd128x64_sendcmd (LCD_ADDRINC);
	delay(1);
	st7920_lcd128x64_sendcmd (LCD_DISPLAYONST);
	delay(1);
	st7920_lcd128x64_sendcmd (LCD_HOME );
	delay(1);
	st7920_lcd128x64_setGfxMode(1);



}

void st7920_lcd128x64_sendcmd (uint8_t cmd)
{

	gpioWrite(GPIO0,HIGH);
	write_spi_XXh(LPC_SSP,0xF8);  // send the SYNC + RS(0));
	write_spi_XXh(LPC_SSP,cmd & 0xF0);   // send the higher nibble first
	write_spi_XXh(LPC_SSP,(cmd << 4));// send the lower nibble
	gpioWrite(GPIO0,LOW);


}

void st7920_lcd128x64_sendData (uint8_t cmd)
{

	gpioWrite(GPIO0,HIGH);
	write_spi_XXh(LPC_SSP,0xFA);  // send the SYNC + RS(1));
	write_spi_XXh(LPC_SSP,cmd & 0xF0);  // send the higher nibble first
	write_spi_XXh(LPC_SSP,(cmd << 4));// send the lower nibble
	gpioWrite(GPIO0,LOW);

}

void st7920_lcd128x64_drawPixel(uint8_t x, uint8_t y, uint8_t col)
{
	if(x>=SCR_WD || y>=SCR_HT) return;
	switch(col) {
	case 1: scr[y*scrWd+x/8] |=   (0x80 >> (x&7)); break;
	case 0: scr[y*scrWd+x/8] &=  ~(0x80 >> (x&7)); break;
	case 2: scr[y*scrWd+x/8] ^=   (0x80 >> (x&7)); break;
	}
}

void st7920_lcd128x64_printTxt(uint8_t pos, char *str)
{
	st7920_lcd128x64_sendcmd(LCD_BASIC);
	st7920_lcd128x64_sendcmd(pos);
	while(*str) {
		st7920_lcd128x64_sendData(*str++);
	}
}
void st7920_lcd128x64_printTxt2(uint8_t pos, uint16_t *signs)
{
	st7920_lcd128x64_sendcmd(LCD_BASIC);
	st7920_lcd128x64_sendcmd(pos);
	while(*signs) {
		st7920_lcd128x64_sendData(*signs>>8);
		st7920_lcd128x64_sendData(*signs&0xFF);
		signs++;
	}
}



void st7920_lcd128x64_SendString(int row, int col, char *string)
{
	switch (row)
	{
	case 0:
		col |= 0x80;
		break;
	case 1:
		col |= 0x90;
		break;
	case 2:
		col |= 0x88;
		break;
	case 3:
		col |= 0x98;
		break;
	default:
		col |= 0x80;
		break;
	}

	st7920_lcd128x64_sendcmd(col);

	while (*string)
	{
		st7920_lcd128x64_sendData(*string++);
	}
}

void st7920_lcd128x64_sleep(bool_t mode)
{
	//sendCmd(mode?LCD_STANDBY:LCD_EXTEND);
	if(mode) 	st7920_lcd128x64_sendcmd(LCD_STANDBY);
	else {
		st7920_lcd128x64_sendcmd(LCD_BASIC);
		st7920_lcd128x64_sendcmd(LCD_EXTEND);
		st7920_lcd128x64_sendcmd(LCD_GFXMODE); }
}

void st7920_lcd128x64_displayclear(void){
	st7920_lcd128x64_sendcmd (LCD_CLS );
}

void st7920_lcd128x64_setGfxMode(bool_t mode)
{
  if(mode) {
	  st7920_lcd128x64_sendcmd(LCD_EXTEND);
	  st7920_lcd128x64_sendcmd(LCD_GFXMODE);
  } else {
	  st7920_lcd128x64_sendcmd(LCD_EXTEND);
	  st7920_lcd128x64_sendcmd(LCD_TXTMODE);
  }
}

void st7920_lcd128x64_ReadRam(void){
	gpioWrite(GPIO0,HIGH);
	write_spi_XXh(LPC_SSP,0xFE);  // send the SYNC + RS(1) + RW(1));
	write_spi_XXh(LPC_SSP, 0X00 & 0xF0);   // send the higher nibble first
	write_spi_XXh(LPC_SSP,0X01);// send the lower nibble
	gpioWrite(GPIO0,LOW);

}

/*void setFont(const uint8_t* font)
{
  cfont.font = font;
  cfont.xSize = fontbyte(0);
  cfont.ySize = fontbyte(1);
  cfont.firstCh = fontbyte(2);
  cfont.lastCh  = fontbyte(3);
  cfont.minDigitWd = 0;
  cfont.minCharWd = 0;
  isNumberFun = &isNumber;
  spacing = 1;
  cr = 0;
  invertCh = 0;
}*/

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/
