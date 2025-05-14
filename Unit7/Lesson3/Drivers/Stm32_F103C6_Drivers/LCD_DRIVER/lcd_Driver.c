/*
 * lcd_Driver.c
 *
 *  Created on: ١٦‏/٠٥‏/٢٠٢٥
 *      Author: Mohamed Elhenawy
 */

#include "lcd_driver.h"

GPIO_PinConfig_t PinCfg;

extern void wait_ms(uint32_t time);
void LCD_GPIO_init() {
	PinCfg.GPIO_PinNumber = Rs_Switch;
	PinCfg.GPIO_MODE = GPIO_MODE_OUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = ReadWrite;
	PinCfg.GPIO_MODE = GPIO_MODE_OUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = EN_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	//============================
	// SET THE NEXT 8 PINS AS INPUT
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_OUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_OUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_OUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	//	DataDir_LCD_CTRL |= (1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_Reset);
	MCAL_GPIO_WritePin(LCD_CTRL, Rs_Switch, GPIO_PIN_Reset);
	MCAL_GPIO_WritePin(LCD_CTRL, ReadWrite, GPIO_PIN_Reset);

}

void LCD_init(void)
{
	wait_ms(20);
	LCD_GPIO_init();
	wait_ms(15);
	LCD_clear_screen();
	LCD_Write_Command(LCD_Function_8bit_2lines);
	LCD_Write_Command(LCD_Entry_MODE);
	LCD_Write_Command(LCD_BEGIN_AT_FIRST_RAW);
	LCD_Write_Command(LCD_DISP_ON_Cursor_BLINK);
}

void LCD_clear_screen(void)
{
	LCD_Write_Command(LCD_Clear_Screen);
}

void LCD_GotoXY(unsigned char line, unsigned char position)
{
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_Write_Command(LCD_BEGIN_AT_FIRST_RAW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_Write_Command(LCD_BEGIN_AT_Second_RAW + position);
		}
	}
}

void LCD_check_lcd_isbusy(void)
{
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_IN_FLO;
	MCAL_GPIO_Init(LCD_Port, &PinCfg);

	MCAL_GPIO_WritePin(LCD_Port, ReadWrite, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_Port, Rs_Switch, GPIO_PIN_Reset);
	LCD_lcd_kick();
	MCAL_GPIO_WritePin(LCD_Port, ReadWrite, GPIO_PIN_Reset);
}

void LCD_Write_Command(unsigned char command)
{
	MCAL_GPIO_WritePort(LCD_CTRL, command);
	MCAL_GPIO_WritePin(LCD_CTRL, ReadWrite, GPIO_PIN_Reset);
	MCAL_GPIO_WritePin(LCD_CTRL, Rs_Switch, GPIO_PIN_Reset);
	wait_ms(1);
	LCD_lcd_kick();
}
void LCD_Write_Char(unsigned char character)
{
	MCAL_GPIO_WritePort(LCD_CTRL, character);
	MCAL_GPIO_WritePin(LCD_CTRL, ReadWrite, GPIO_PIN_Reset);
	MCAL_GPIO_WritePin(LCD_CTRL, Rs_Switch, GPIO_PIN_SET);
	wait_ms(1);
	LCD_lcd_kick();
}
void LCD_lcd_kick(void)
{
	MCAL_GPIO_WritePin(LCD_Port, EN_SWITCH, GPIO_PIN_SET);
	wait_ms(50);
	MCAL_GPIO_WritePin(LCD_Port, EN_SWITCH, GPIO_PIN_Reset);
}

void LCD_Write_String(char* string)
{
	int count = 0;
	while (*string > 0) {
		count++;
		LCD_Write_Char(*string++);
		if (count == 16) {
			LCD_GotoXY(2, 0);
		} else if (count == 32) {
			LCD_clear_screen();
			LCD_GotoXY(1, 0);
			count = 0;
		}
	}
}
