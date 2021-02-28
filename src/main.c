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


   // ----- Repetir por siempre ---------------------
   while(TRUE) {

	   //st7920_lcd128x64_drawPixel(10,10,2);
	   st7920_lcd128x64_printTxt(2, buff);
	   //st7920_lcd128x64_SendString(2, 1, buff);

	   delay(1000);
	   //st7920_lcd128x64_displayclear();


	   //st7920_lcd128x64_sleep(1);

	   delay(1000);

	   //st7920_lcd128x64_sleep(0);




    }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontrolador y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}























