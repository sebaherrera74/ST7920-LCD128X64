/*=====[Nombre del programa]===================================================
 * Copyright YYYY Nombre completo del autor <author@mail.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Fecha de creacion: YYYY/MM/DD
 */




/*=====[Inclusiones de dependencias de funciones]============================*/

#include "sapi.h"
#include "st7920_lcd128x64.h"
#include "spi.h"

/*=====[Macros de definición de constantes privadas]=========================*/


/*=====[Definiciones de variables globales externas]=========================*/


/*=====[Definiciones de variables globales publicas]=========================*/


/*=====[Definiciones de variables globales privadas]=========================*/



/*=====[Funcion principal, punto de entrada al programa luegp de encender]===*/

int main (void)
{


	// ----- Configuraciones -------------------------
   boardInit();
   st7920_lcd128x64_init();

   char buff[50]={"HOLAA como estas\0 "};
   uint16_t star1[] = { 0xa1ee, 0 };
   uint16_t star2[] = { 0xa1ef, 0 };
   uint16_t signs[] = { 0xa170,0xa171,0xa173,0xa174,0xa175,0xa176,0 };
   uint16_t signs1[] = { 0xa170,0xa171,0 };
   uint16_t signs2[] = { 0xa173,0xa174,0 };
   uint16_t roman[] = { 0xa271,0xa271+11,0 };
   uint16_t fnt16x16[] = { 0xa300+'F', 0xa300+'n',0xa300+'t',0xa331,0xa336, 0xa141,0xa331,0xa336,0 };
   uint16_t date[] = { 0xa161, 0xa300+'1', 0xa300+'5', 0xa270+8, 0xa300+'1', 0xa300+'4', 0xa300+'1', 0xa300+'0',0 };
   uint16_t  temp[] = { 0xa300+'+', 0xa300+'2', 0xa300+'7', 0xa166,0 };

   st7920_lcd128x64_setGfxMode(0);

   	   st7920_lcd128x64_printTxt2(LCD_LINE0+0,star1);
   	   st7920_lcd128x64_printTxt2(LCD_LINE0+7,star2);
   	   st7920_lcd128x64_printTxt(LCD_LINE0+2,"Font16x8");
   	   st7920_lcd128x64_printTxt2(LCD_LINE1,fnt16x16);
   	   st7920_lcd128x64_printTxt2(LCD_LINE2+2,temp);
   	   st7920_lcd128x64_printTxt2(LCD_LINE2+0,signs1);

   	 st7920_lcd128x64_printTxt2(LCD_LINE2+6,signs2);
   	 st7920_lcd128x64_printTxt2(LCD_LINE3,date);
   	st7920_lcd128x64_displayclear();
   	st7920_lcd128x64_printTxt2(LCD_LINE0+0,signs);
   	st7920_lcd128x64_printTxt2(LCD_LINE2+0,roman);
    st7920_lcd128x64_displayclear();
   uint8_t x=0;
   uint8_t y=1;
   uint8_t col=1;

   // ----- Repetir por siempre ---------------------
   while(TRUE) {

	    //st7920_lcd128x64_drawPixel(10,10,2);
	   //st7920_lcd128x64_setGfxMode(1);
	     st7920_lcd128x64_printTxt(2, buff);
	   //st7920_lcd128x64_SendString(2, 1, buff);



	   delay(100);







	   //st7920_lcd128x64_ReadRam();
	   //st7920_lcd128x64_sleep(1);

	   //delay(3000);

	   //st7920_lcd128x64_sleep(0);




    }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontrolador y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}























