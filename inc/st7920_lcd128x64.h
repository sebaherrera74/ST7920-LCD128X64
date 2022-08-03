/*=====[Module Name]===========================================================
 * Copyright YYYY Author Compelte Name <author@mail.com>
 * All rights reserved.
 * License: license text or at least name and link 
         (example: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Creation Date: YYYY/MM/DD
 */

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _ST7920_LCD128X64_H_
#define _ST7920_LCD128X64_H_

/*=====[Inclusions of public function dependencies]==========================*/

#include "sapi.h"


/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

// ST7920 Commands

#define LCD_CLS         0x01            //
#define LCD_HOME        0x02
#define LCD_ADDRINC     0x06
#define LCD_DISPLAYONST   0x0C
#define LCD_DISPLAYOFFST  0x08
#define LCD_CURSORON    0x0E
#define LCD_CURSORBLINK 0x0F
#define LCD_BASIC       0x30
#define LCD_EXTEND      0x34
#define LCD_GFXMODE     0x36
#define LCD_TXTMODE     0x34
#define LCD_STANDBY     0x01
#define LCD_SCROLL      0x03
#define LCD_SCROLLADDR  0x40
#define LCD_ADDR        0x80
#define LCD_LINE0       0x80
#define LCD_LINE1       0x90
#define LCD_LINE2       0x88
#define LCD_LINE3       0x98


#define SCR_WD  128
#define SCR_HT  64

/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/

void st7920_lcd128x64_init(void );
void st7920_lcd128x64_sendcmd (uint8_t cmd);
void st7920_lcd128x64_sendData (uint8_t cmd);
void st7920_lcd128x64_drawPixel(uint8_t x, uint8_t y, uint8_t col);
void st7920_lcd128x64_printTxt(uint8_t pos, char *str);
void st7920_lcd128x64_printTxt2(uint8_t pos, uint16_t *signs);
void st7920_lcd128x64_SendString(int row, int col, char* string);
void st7920_lcd128x64_sleep(bool_t mode);
void st7920_lcd128x64_displayclear(void);
void st7920_lcd128x64_setGfxMode(bool_t mode);
void st7920_lcd128x64_ReadRam(void);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _MODULE_NAME_H_ */
