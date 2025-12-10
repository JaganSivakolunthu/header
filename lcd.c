
//#include <stdio.h>	//if sprintf() is included
#include <lpc21xx.h>
#include "lcd.h"
#include "delay.h"

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

void LCD_STRING(const u8 *ptr)
{
    while(*ptr)
    {
        LCD_DATA(*ptr);
        ptr++;
    }
}

void LCD_INTEGER(s32 num)
{
    s8 buf[12];   // enough for 32-bit int
    s32 i = 0;

    if (num == 0)
    {
        LCD_DATA('0');
        return;
    }

    if (num < 0)
    {
        LCD_DATA('-');
        num = -num;
    }

    // Extract digits into buffer (backwards)
    while (num > 0)
    {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }

    // Print digits in correct order
    while (i > 0)
    {
        LCD_DATA(buf[--i]);
    }
}


void LCD_FLOAT(f32 num)
{
    f32 rem;
    s32 n1,n2;
    n1 = num;
    LCD_INTEGER(n1);
    LCD_DATA('.');
    rem = num - n1;
    n2 = rem * 1000000;
    LCD_INTEGER(n2);
}
/*
void LCD_FLOAT(f32 num)
{
    s8 buf[20];
    sprintf(buf, "%.3f", num);  // Change precision here
    STR(buf);
}
*/

void LCD_BINARY(s32 num)
{
    s32 i;
    for(i= sizeof( num )*8 -1; i>=0; i--)
    {
        if((num>>i)&1)
        {
            LCD_DATA('1');
        }
        else
        {
            LCD_DATA('0');
        }
				if(i == 16)	LCD_COMMAND(0xc0);
    } 
}


