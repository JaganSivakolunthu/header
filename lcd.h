#include"header.h"
#include"delay_ms.h"

void LCD_INIT(void)
{
	IODIR0 |= DATA_PINS|RS|EN;
	LCD_COMMAND(0x01);	//clr the display
	LCD_COMMAND(0x02);	//return cursor to home
	LCD_COMMAND(0x0c);	//display ON, cursor OFF
	LCD_COMMAND(0x38);	//8bit interfacing mode
}

void LCD_COMMAND(u8 CMD)
{
	IOCLR0 = DATA_PINS;
	IOSET0 = CMD;
	IOCLR0 = RS;
	IOSET0 = EN;
	delay_ms(5);
	IOCLR0 = EN;
}

void LCD_DATA(u8 DATA)
{
	IOCLR0 = DATA_PINS;
	IOSET0 = DATA;
	IOSET0 = RS;
	IOSET0 = EN;
	delay_ms(5);
	IOCLR0 = EN;
}
