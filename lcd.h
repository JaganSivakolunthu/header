#ifndef LCD_H
#define LCD_H

#include "header.h"

#define DATA_PINS 0x000000FF   // P0.0 to P0.7
#define RS (1 << 8)            // P0.8
#define EN (1 << 9)            // P0.9

// LCD functions
void LCD_INIT(void);
void LCD_COMMAND(u8 CMD);
void LCD_DATA(u8 DATA);
void LCD_STRING(const u8 *ptr);
void LCD_INTEGER(s32 num);
void LCD_FLOAT(f32 num);
void LCD_BINARY(s32 num);

#endif
