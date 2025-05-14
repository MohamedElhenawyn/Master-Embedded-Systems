/*
 * lcd_driver.h
 *
 *  Created on: ١٦‏/٠٥‏/٢٠٢٥
 *      Author: Mohamed Elhenawy
 */

#ifndef LCD_DRIVER_LCD_DRIVER_H_
#define LCD_DRIVER_LCD_DRIVER_H_
#include "Stm32_F103C6_gpio_driver.h"
#include "stm32f103x6.h"
#include "stdlib.h"
#include "stdio.h"

#define EIGHT_BIT_MODE
#define LCD_Port	GPIOA
#define LCD_CTRL	GPIOA
#define Rs_Switch	GPIO_PIN_8
#define ReadWrite	GPIO_PIN_9
#define EN_SWITCH	GPIO_PIN_10


#define LCD_Function_8bit_2lines	(0x38)
#define LCD_Function_4bit_2lines	(0x28)
#define LCD_MOVE_DISP_RIGHT			(0x1C)
#define LCD_MOVE_DISP_LEFT			(0x18)
#define LCD_Move_Cursor_right		(0x14)
#define LCD_Move_Cursor_left		(0x10)
#define LCD_DISP_OFF				(0x08)
#define LCD_DISP_ON_Cursor			(0x0E)
#define LCD_DISP_ON_Cursor_BLINK	(0x0F)
#define LCD_DISP_ON_BLINK			(0x0D)
#define LCD_DISP_ON					(0x0C)
#define LCD_ENTRY_DEC				(0x04)
#define LCD_ENTRY_DEC_SHIFT			(0x05)
#define LCD_ENTRY_INC				(0x06)
#define LCD_ENTRY_INC_SHIFT			(0x07)
#define LCD_BEGIN_AT_FIRST_RAW		(0x80)
#define LCD_BEGIN_AT_Second_RAW		(0xC0)
#define LCD_Clear_Screen			(0x01)
#define LCD_Entry_MODE				(0x06)

void LCD_check_lcd_isbusy(void);
void LCD_lcd_kick(void);
void LCD_Write_Command(unsigned char command);
void LCD_Write_Char(unsigned char character);
void LCD_Write_String(char* string);
void LCD_init(void);
void LCD_clear_screen(void);
void LCD_GotoXY(unsigned char line, unsigned char position);




#endif /* LCD_DRIVER_LCD_DRIVER_H_ */
