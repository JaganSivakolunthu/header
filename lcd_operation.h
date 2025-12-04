//#include <stdio.h>	//if sprintf() is included
#include "header.h"
#include "lcd.h"

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
    s32 r, rev=0, N;
    if(num==0)
    {
        LCD_DATA(0);
        return;
    }
    if(num<0)
    {
        LCD_DATA('-');
        num = -num;
    }
    while(num != 0)
    {
        r = num%10;
        num = num/10;
        rev = (rev*10) + r;
    }
    while(rev != 0)
    {
        N = rev%10;
        LCD_DATA(N + 48); // LCD_DATA(N + '0');
        rev = rev/10;
    }
}

void LCD_FLOAT(f32 num)
{
    f32 rem;
    s32 n1,n2;
    n1 = num;
    LCD_INTEGER(n1);
    DATA('.');
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

void LCD_BINARY(u32 num)
{
    u32 i;
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
    }
}
